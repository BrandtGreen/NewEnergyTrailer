/********************************************************************************
* �����׿������������޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ���������
* �ļ����� CANNet.h
* �������� �� CAN���߹���ͷ�ļ�
* ���ü�¼��
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2011.07.14          00.01.00      ����     ��һ��                                           
*******************************************************************************/

#ifndef __CANNET_H
    #define __CANNET_H

    #include "Std_Types.h"
    #include "HardwareLib.h"
    
    #define _CAN_INDEX_CAN0     0
    #define _CAN_INDEX_CAN1     1
    #define _CAN_INDEX_CAN2     2
    #define _CAN_INDEX_CAN3     3
    #define _CAN_INDEX_CAN4     4
    #define _CAN_INDEX_CAN5     5

    
    void CANNet_Init(void);

    //����CAN��Ϣ�����ӿ�
    void CANNet_RecvMsgCAN0(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN1(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN2(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN3(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN4(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN5(MCANDrv_infoMsgS_TYPE infoMsgS);
    
    //������Ϣ����
    void CANNet_Manage1ms(void);
    
    
#endif
