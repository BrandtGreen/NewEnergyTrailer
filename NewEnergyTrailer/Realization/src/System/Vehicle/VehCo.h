/********************************************************************************
* 常州易控汽车电子有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： VehCo.h
* 功能描述 ： 整车管理协调头文件
* 引用记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2011.07.14          00.01.00      李中     第一版                                           
*******************************************************************************/

#ifndef __VEHCO_H
    #define __VEHCO_H

    #include "Std_Types.h"
    
    
    #define _VEHCO_TIME_MONITOR_PERIOD  5
    
    
    #define _VEHCO_AFTERRUN_STATUS_INIT     0
    #define _VEHCO_AFTERRUN_STATUS_BEGIN    1
    #define _VEHCO_AFTERRUN_STATUS_FINISH   2    
    

    void VehCo_Init(void);
    
    //基础管理循环
    void VehCo_Manage10ms(void);
    void VehCo_Manage1ms(void);
    
    //具体操作
    void VehCo_UpdateSig(void);
    void VehCo_Monitor(void);
    
    //状态管理
    void VehCo_StateMachine(void);
    void VehCo_Afterrun(void);
    
    #define APPLAYERVER_START_SEC_VAR
    #include "MemMap.h"

        extern const uint8 AppLayer_idxVerUBA[64]; //应用层软件版本信息，可通过UDS接口读取
    
    #define APPLAYERVER_STOP_SEC_VAR
    #include "MemMap.h"


    #define EEPDATA_START_SEC_VAR
    #include "MemMap.h"

        extern uint32 VehCo_ctEEPTestUI; //在定义时给EEPROM里的变量赋初值

    #define EEPDATA_STOP_SEC_VAR
    #include "MemMap.h"


    /*************************************************************/
    /*标定数据区开始（请不要在该区域加入非标定数据相关的内容）                                                                                 */

    #define MAPDATA_START_SEC_VAR_CONST
    #include "MemMap.h"

    /*VehCo*/
    extern PRAGMA_MAPDATA const uint16 VehCo_bTestCANWuFinUW_C;  /*测试模式下控制CAN唤醒状态结束*/
    extern PRAGMA_MAPDATA const uint16 VehCo_bTestCPCtrlUW_C;  /*Afterrun模式完成测试接口*/

    #define MAPDATA_STOP_SEC_VAR_CONST
    #include "MemMap.h"

    /*标定数据区结束                                                                                                                                                                               */
    /*************************************************************/


#endif    
