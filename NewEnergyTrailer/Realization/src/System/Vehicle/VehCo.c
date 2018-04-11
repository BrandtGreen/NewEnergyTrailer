/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ���������
* �ļ����� VehCo.c
* �������� �� ��������Э��
* ���ü�¼��
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2011.07.14          00.01.00      ����     ��һ��
*******************************************************************************/

#include "VehCo.h"
#include "HardwareLib.h"
#include "CANNet.h"


#define APPLAYERVER_START_SEC_VAR
#include "MemMap.h"

    const uint8 AppLayer_idxVerUBA[64]="P036V100"; //Ӧ�ò�����汾��Ϣ����ͨ��UDS�ӿڶ�ȡ

#define APPLAYERVER_STOP_SEC_VAR
#include "MemMap.h"

uint8 VehCo_stAfterrunUB; //�ػ�׼��״̬

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
    uint32 VehCo_ctEEPTestUI=1000; //�ڶ���ʱ��EEPROM��ı�������ֵ

#define EEPDATA_STOP_SEC_VAR
#include "MemMap.h"

/*************************************************************/
/*�궨��������ʼ���벻Ҫ�ڸ��������Ǳ궨������ص����ݣ�                                                                                 */

    #define MAPDATA_START_SEC_VAR_CONST
    #include "MemMap.h"

    /*VehCo*/
    PRAGMA_MAPDATA const uint16 VehCo_bTestCANWuFinUW_C=0; /*����ģʽ�¿���CAN����״̬����*/
    PRAGMA_MAPDATA const uint16 VehCo_bTestCPCtrlUW_C=0; /*Afterrunģʽ��ɲ��Խӿ�*/

    #define MAPDATA_STOP_SEC_VAR_CONST
    #include "MemMap.h"

/*�궨����������                                                                                                                                                                               */
/*************************************************************/


//���������ʼ��
void VehCo_Init(void)
{
    VehCo_tiMonitorUB=0;
    
    VehCo_stAfterrunUB=_VEHCO_AFTERRUN_STATUS_INIT;

    CANNet_Init();

    VehCo_fTestUI = 5000;
    VehCo_rTestUW = 5000;

#if 0
    //����RTCʱ������
    VehCo_infoDateTimeS.datYearUB = 17;
    VehCo_infoDateTimeS.datMonthUB = 8;
    VehCo_infoDateTimeS.datDateUB = 4;
    VehCo_infoDateTimeS.datHourUB = 16;
    VehCo_infoDateTimeS.datMinUB = 19;
    VehCo_infoDateTimeS.datSecUB = 0;

    RTCDrv_SetDateTime(VehCo_infoDateTimeS);
#endif
}

//��������10ms��׼��������
void VehCo_Manage10ms(void)
{
    uint8 idxIncUB;

    VehCo_UpdateSig();
    
    VehCo_tiMonitorUB=(uint8)((VehCo_tiMonitorUB+1)%_VEHCO_TIME_MONITOR_PERIOD);
    if(VehCo_tiMonitorUB==0)
    {
        VehCo_Monitor();
    }
    
    VehCo_StateMachine(); //��������״̬��
    
    VehCo_Afterrun(); //�ػ�׼��

    /*��������*/
    VehCo_fTestUI = 5000;
    VehCo_rTestUW = (VehCo_rTestUW+10)%_PWM_DUTYCYCLE_FULL;
    PPWMDrv_Interface(_PPWM_INDEX_FBAK1_CHAN, VehCo_fTestUI, VehCo_rTestUW);
    PPWMDrv_Interface(_PPWM_INDEX_FHBAK1_CHAN, VehCo_fTestUI, VehCo_rTestUW);

    for(idxIncUB=0; idxIncUB<4; idxIncUB++)
    {
        PulseAcqDrv_GetChanFreq(idxIncUB, &VehCo_fInputUIA[idxIncUB], &VehCo_rInputUWA[idxIncUB]);
    }

    DODrv_SetChanState(_DO_INDEX_CPCTL_CHAN,(uint8)VehCo_bTestCPCtrlUW_C);

    /*��CAN���ѵ�����£����ϲ��㷨����CAN���ѹ��̽���*/
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

//��������1ms��׼��������
void VehCo_Manage1ms(void)
{
    CANNet_Manage1ms();
}

//���²����ź�
void VehCo_UpdateSig(void)
{
    //ÿ10ms����һ�Σ����ڻ�ȡģ����������������״̬
	VehCo_uBattF=(float32)BattCD_uFltUW/100.0F;
}

//����״̬���
void VehCo_Monitor(void)
{
    //ÿ50ms���һ��
}

//��������״̬��
void VehCo_StateMachine(void)
{
    //ÿ10ms����һ��
    
    //VehCo_stNewUB����4��״̬��Init, Running, Afterrun, Finish
    //����Init��Finish����״̬�Ĳ����ɵײ����
    
    switch(VehCo_stNewUB)
    {
        case _VEHCO_INDEX_STATUS_RUNNING:
            if(BattCD_stWakeupU.U == 0)
            {
                //�߼��翪�ضϿ������뵽�ػ�׼��״̬
                VehCo_stNewUB=_VEHCO_INDEX_STATUS_AFTERRUN;
            }
            break;
            
        case _VEHCO_INDEX_STATUS_AFTERRUN:
            if(BattCD_stWakeupU.U > 0)
            {
                //�߼��翪�رպϣ����½�������״̬
                VehCo_Init(); //���³�ʼ��
                
                VehCo_stNewUB=_VEHCO_INDEX_STATUS_RUNNING; //�ָ�����״̬
            }
            else
            {
                if(_VEHCO_AFTERRUN_STATUS_FINISH==VehCo_stAfterrunUB)
                {
                    //�ػ�׼��������ɣ�����ͣ��״̬
                    VehCo_stNewUB=_VEHCO_INDEX_STATUS_FINISH;
                }
            }
            break;
            
        default:
            break;
    }
}

//ͣ��׼��״̬����
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
            //�ڴ˴���ӹػ�׼��״̬�µĲ���

            if(HardwareDrv_bBootloaderReqUB == 1)
            {
                //����Bootloader��д״̬׼������ϵͳ���ڰ�ȫ״̬
            }
            else
            {
                //����ͣ���ص�׼��
            }

            //������ɺ����״̬��ת
            VehCo_stAfterrunUB=_VEHCO_AFTERRUN_STATUS_FINISH;
            break;
            
        case _VEHCO_AFTERRUN_STATUS_FINISH:
            break;
            
        default:
            break;
    }
}





