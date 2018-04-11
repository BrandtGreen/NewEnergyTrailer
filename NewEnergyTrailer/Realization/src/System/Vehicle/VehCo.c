/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： VehCo.c
* 功能描述 ： 整车管理协调
* 引用记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2011.07.14          00.01.00      李中     第一版
*******************************************************************************/

#include "VehCo.h"
#include "HardwareLib.h"
#include "CANNet.h"


#define APPLAYERVER_START_SEC_VAR
#include "MemMap.h"

    const uint8 AppLayer_idxVerUBA[64]="P036V100"; //应用层软件版本信息，可通过UDS接口读取

#define APPLAYERVER_STOP_SEC_VAR
#include "MemMap.h"

uint8 VehCo_stAfterrunUB; //关机准备状态

uint8 VehCo_tiMonitorUB;

uint32 VehCo_fTestUI;
uint16 VehCo_rTestUW;

uint32 VehCo_fInputUIA[4];
uint16 VehCo_rInputUWA[4];

RTCDrv_infoDateTimeS_TYPE VehCo_infoDateTimeS;
uint16 VehCo_ct1sUW;

uint16 VehCo_uADChanUWA[_ATD_NUM_CHAN];
uint8 VehCo_bDINChanUBA[_DIN_NUM_CHAN];

float32 VehCo_uBattF;


#define EEPDATA_START_SEC_VAR
#include "MemMap.h"

    uint8 VehCo_ctEEPTestUB=10;
    uint32 VehCo_ctEEPTestUI=1000; //在定义时给EEPROM里的变量赋初值

#define EEPDATA_STOP_SEC_VAR
#include "MemMap.h"

/*************************************************************/
/*标定数据区开始（请不要在该区域加入非标定数据相关的内容）                                                                                 */

    #define MAPDATA_START_SEC_VAR_CONST
    #include "MemMap.h"

    /*VehCo*/
    PRAGMA_MAPDATA const uint16 VehCo_bTestCANWuFinUW_C=0; /*测试模式下控制CAN唤醒状态结束*/
    PRAGMA_MAPDATA const uint16 VehCo_bTestCPCtrlUW_C=0; /*Afterrun模式完成测试接口*/

    #define MAPDATA_STOP_SEC_VAR_CONST
    #include "MemMap.h"

/*标定数据区结束                                                                                                                                                                               */
/*************************************************************/


//整车管理初始化
void VehCo_Init(void)
{
    VehCo_tiMonitorUB=0;
    
    VehCo_stAfterrunUB=_VEHCO_AFTERRUN_STATUS_INIT;

    CANNet_Init();

    VehCo_fTestUI = 5000;
    VehCo_rTestUW = 5000;

#if 0
    //设置RTC时名样例
    VehCo_infoDateTimeS.datYearUB = 17;
    VehCo_infoDateTimeS.datMonthUB = 8;
    VehCo_infoDateTimeS.datDateUB = 4;
    VehCo_infoDateTimeS.datHourUB = 16;
    VehCo_infoDateTimeS.datMinUB = 19;
    VehCo_infoDateTimeS.datSecUB = 0;

    RTCDrv_SetDateTime(VehCo_infoDateTimeS);
#endif
}

//整车管理10ms基准运行任务
void VehCo_Manage10ms(void)
{
    uint8 idxIncUB;

    VehCo_UpdateSig();
    
    VehCo_tiMonitorUB=(uint8)((VehCo_tiMonitorUB+1)%_VEHCO_TIME_MONITOR_PERIOD);
    if(VehCo_tiMonitorUB==0)
    {
        VehCo_Monitor();
    }
    
    VehCo_StateMachine(); //整车控制状态机
    
    VehCo_Afterrun(); //关机准备

    /*样例代码*/
    VehCo_fTestUI = 5000;
    VehCo_rTestUW = (VehCo_rTestUW+10)%_PWM_DUTYCYCLE_FULL;
    PPWMDrv_Interface(_PPWM_INDEX_FBAK1_CHAN, VehCo_fTestUI, VehCo_rTestUW);
    PPWMDrv_Interface(_PPWM_INDEX_FHBAK1_CHAN, VehCo_fTestUI, VehCo_rTestUW);

    for(idxIncUB=0; idxIncUB<4; idxIncUB++)
    {
        PulseAcqDrv_GetChanFreq(idxIncUB, &VehCo_fInputUIA[idxIncUB], &VehCo_rInputUWA[idxIncUB]);
    }

    DODrv_SetChanState(_DO_INDEX_CPCTL_CHAN,(uint8)VehCo_bTestCPCtrlUW_C);

    /*在CAN唤醒的情况下，由上层算法决定CAN唤醒过程结束*/
    if(BattCD_stWakeupU.B.bCAN == 1)
    {
        if(VehCo_bTestCANWuFinUW_C==1)
        {
            BattCD_stWakeupU.B.bCAN = 0;
        }
    }

    VehCo_ct1sUW = (VehCo_ct1sUW+1)%1;
    if(VehCo_ct1sUW == 0)
    {
        RTCDrv_GetDateTime(&VehCo_infoDateTimeS);
    }

    VehCo_ctEEPTestUI++;
    VehCo_ctEEPTestUB++;
}

//整车管理1ms基准运行任务
void VehCo_Manage1ms(void)
{
    CANNet_Manage1ms();
}

//更新部件信号
void VehCo_UpdateSig(void)
{
    //每10ms更新一次，用于获取模拟量和数字量输入状态
	VehCo_uBattF=(float32)BattCD_uFltUW/100.0F;
}

//部件状态监控
void VehCo_Monitor(void)
{
    //每50ms监控一次
}

//整车管理状态机
void VehCo_StateMachine(void)
{
    //每10ms运行一次
    
    //VehCo_stNewUB包含4个状态：Init, Running, Afterrun, Finish
    //其中Init和Finish两个状态的操作由底层管理
    
    switch(VehCo_stNewUB)
    {
        case _VEHCO_INDEX_STATUS_RUNNING:
            if(BattCD_stWakeupU.U == 0)
            {
                //逻辑电开关断开，进入到关机准备状态
                VehCo_stNewUB=_VEHCO_INDEX_STATUS_AFTERRUN;
            }
            break;
            
        case _VEHCO_INDEX_STATUS_AFTERRUN:
            if(BattCD_stWakeupU.U > 0)
            {
                //逻辑电开关闭合，重新进入运行状态
                VehCo_Init(); //重新初始化
                
                VehCo_stNewUB=_VEHCO_INDEX_STATUS_RUNNING; //恢复运行状态
            }
            else
            {
                if(_VEHCO_AFTERRUN_STATUS_FINISH==VehCo_stAfterrunUB)
                {
                    //关机准备操作完成，进入停机状态
                    VehCo_stNewUB=_VEHCO_INDEX_STATUS_FINISH;
                }
            }
            break;
            
        default:
            break;
    }
}

//停机准备状态操作
void VehCo_Afterrun(void)
{
    switch(VehCo_stAfterrunUB)
    {
        case _VEHCO_AFTERRUN_STATUS_INIT:
            if(VehCo_stNewUB==_VEHCO_INDEX_STATUS_AFTERRUN)
            {
                VehCo_stAfterrunUB=_VEHCO_AFTERRUN_STATUS_BEGIN;
            }
            break;
            
        case _VEHCO_AFTERRUN_STATUS_BEGIN:
            //在此处添加关机准备状态下的操作

            if(HardwareDrv_bBootloaderReqUB == 1)
            {
                //进入Bootloader烧写状态准备，将系统置于安全状态
            }
            else
            {
                //进入停机关电准备
            }

            //操作完成后进行状态跳转
            VehCo_stAfterrunUB=_VEHCO_AFTERRUN_STATUS_FINISH;
            break;
            
        case _VEHCO_AFTERRUN_STATUS_FINISH:
            break;
            
        default:
            break;
    }
}





