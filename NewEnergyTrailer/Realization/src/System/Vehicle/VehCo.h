/********************************************************************************
* �����׿������������޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ���������
* �ļ����� VehCo.h
* �������� �� ��������Э��ͷ�ļ�
* ���ü�¼��
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2011.07.14          00.01.00      ����     ��һ��                                           
*******************************************************************************/

#ifndef __VEHCO_H
    #define __VEHCO_H

    #include "Std_Types.h"
    
    
    #define _VEHCO_TIME_MONITOR_PERIOD  5
    
    
    #define _VEHCO_AFTERRUN_STATUS_INIT     0
    #define _VEHCO_AFTERRUN_STATUS_BEGIN    1
    #define _VEHCO_AFTERRUN_STATUS_FINISH   2    
    

    void VehCo_Init(void);
    
    //��������ѭ��
    void VehCo_Manage10ms(void);
    void VehCo_Manage1ms(void);
    
    //�������
    void VehCo_UpdateSig(void);
    void VehCo_Monitor(void);
    
    //״̬����
    void VehCo_StateMachine(void);
    void VehCo_Afterrun(void);
    
    #define APPLAYERVER_START_SEC_VAR
    #include "MemMap.h"

        extern const uint8 AppLayer_idxVerUBA[64]; //Ӧ�ò�����汾��Ϣ����ͨ��UDS�ӿڶ�ȡ
    
    #define APPLAYERVER_STOP_SEC_VAR
    #include "MemMap.h"


    #define EEPDATA_START_SEC_VAR
    #include "MemMap.h"

        extern uint32 VehCo_ctEEPTestUI; //�ڶ���ʱ��EEPROM��ı�������ֵ

    #define EEPDATA_STOP_SEC_VAR
    #include "MemMap.h"


    /*************************************************************/
    /*�궨��������ʼ���벻Ҫ�ڸ��������Ǳ궨������ص����ݣ�                                                                                 */

    #define MAPDATA_START_SEC_VAR_CONST
    #include "MemMap.h"

    /*VehCo*/
    extern PRAGMA_MAPDATA const uint16 VehCo_bTestCANWuFinUW_C;  /*����ģʽ�¿���CAN����״̬����*/
    extern PRAGMA_MAPDATA const uint16 VehCo_bTestCPCtrlUW_C;  /*Afterrunģʽ��ɲ��Խӿ�*/

    #define MAPDATA_STOP_SEC_VAR_CONST
    #include "MemMap.h"

    /*�궨����������                                                                                                                                                                               */
    /*************************************************************/


#endif    
