/********************************************************************************
* 常州易控汽车电子有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： CANNet.h
* 功能描述 ： CAN总线管理头文件
* 引用记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2011.07.14          00.01.00      李中     第一版                                           
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

    //接收CAN消息函数接口
    void CANNet_RecvMsgCAN0(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN1(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN2(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN3(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN4(MCANDrv_infoMsgS_TYPE infoMsgS);
    void CANNet_RecvMsgCAN5(MCANDrv_infoMsgS_TYPE infoMsgS);
    
    //发送消息管理
    void CANNet_Manage1ms(void);
    
    
#endif
