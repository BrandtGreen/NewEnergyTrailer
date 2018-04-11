/********************************************************************************
* 常州易控汽车电子有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： CANNet.c
* 功能描述 ： CAN总线管理
* 引用记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2011.07.14          00.01.00      李中     第一版                                           
*******************************************************************************/

#include "CANNet.h"


MCANDrv_infoMsgConfS_TYPE CANNet_infoMsgRxConfS[128];
uint8 CANNet_datMsgBufUBA[1152];

MCANDrv_infoMsgConfS_TYPE CANNet_infoMsgTxConfS[32];

uint8 CANNet_idxSchedUB;


void CANNet_Init(void)
{
    /*示例代码*/

    /*各个CAN节点初始化*/
    MCANDrv_SetBaudrate(_CAN_INDEX_CAN0, 250000);
    MCANDrv_SetCANMode(_CAN_INDEX_CAN0, MCAN_NODEMODE_MO);
    //MCANDrv_SetCallbackFunc(_CAN_INDEX_CAN0, (pFunc_RxMsgCallback)CANNet_RecvMsgCAN0, NULL_PTR);

    MCANDrv_SetBaudrate(_CAN_INDEX_CAN1, 250000);
    MCANDrv_SetCANMode(_CAN_INDEX_CAN1, MCAN_NODEMODE_MO);
    //MCANDrv_SetCallbackFunc(_CAN_INDEX_CAN1, (pFunc_RxMsgCallback)CANNet_RecvMsgCAN1, NULL_PTR);

    MCANDrv_SetBaudrate(_CAN_INDEX_CAN2, 250000);
    MCANDrv_SetCANMode(_CAN_INDEX_CAN2, MCAN_NODEMODE_MO);
    //MCANDrv_SetCallbackFunc(_CAN_INDEX_CAN2, (pFunc_RxMsgCallback)CANNet_RecvMsgCAN2, NULL_PTR);

    MCANDrv_SetBaudrate(_CAN_INDEX_CAN3, 250000);
    MCANDrv_SetCANMode(_CAN_INDEX_CAN3, MCAN_NODEMODE_MO);
    //MCANDrv_SetCallbackFunc(_CAN_INDEX_CAN3, (pFunc_RxMsgCallback)CANNet_RecvMsgCAN3, NULL_PTR);

    MCANDrv_SetBaudrate(_CAN_INDEX_CAN4, 250000);
    MCANDrv_SetCANMode(_CAN_INDEX_CAN4, MCAN_NODEMODE_MO);
    //MCANDrv_SetCallbackFunc(_CAN_INDEX_CAN4, (pFunc_RxMsgCallback)CANNet_RecvMsgCAN4, NULL_PTR);

    /*第5路CAN用于CCP、UDS协议，由底层配置*/

    /*接收报文初始化*/
    CANNet_infoMsgRxConfS[0].infoMsgIDUI = 0x1F000000UL;
    CANNet_infoMsgRxConfS[0].infoMsgParU.B.CAN = 0;
    CANNet_infoMsgRxConfS[0].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[0].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[0].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[0].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[0], CANNet_RecvMsgCAN0);

    CANNet_infoMsgRxConfS[1].infoMsgIDUI = 0x1F000010UL;
    CANNet_infoMsgRxConfS[1].infoMsgParU.B.CAN = 1;
    CANNet_infoMsgRxConfS[1].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[1].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[1].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[1].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[1], CANNet_RecvMsgCAN1);

    CANNet_infoMsgRxConfS[2].infoMsgIDUI = 0x1F000020UL;
    CANNet_infoMsgRxConfS[2].infoMsgParU.B.CAN = 2;
    CANNet_infoMsgRxConfS[2].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[2].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[2].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[2].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[2], CANNet_RecvMsgCAN2);

    CANNet_infoMsgRxConfS[3].infoMsgIDUI = 0x1F000030UL;
    CANNet_infoMsgRxConfS[3].infoMsgParU.B.CAN = 3;
    CANNet_infoMsgRxConfS[3].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[3].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[3].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[3].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[3], CANNet_RecvMsgCAN3);

    CANNet_infoMsgRxConfS[4].infoMsgIDUI = 0x1F000040UL;
    CANNet_infoMsgRxConfS[4].infoMsgParU.B.CAN = 4;
    CANNet_infoMsgRxConfS[4].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[4].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[4].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[4].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[4], CANNet_RecvMsgCAN4);

    CANNet_infoMsgRxConfS[5].infoMsgIDUI = 0x1F000050UL;
    CANNet_infoMsgRxConfS[5].infoMsgParU.B.CAN = 5;
    CANNet_infoMsgRxConfS[5].infoMsgParU.B.MO = 0;
    CANNet_infoMsgRxConfS[5].infoMsgParU.B.DIR = _MCAN_DIR_RX;
    CANNet_infoMsgRxConfS[5].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgRxConfS[5].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgRxConfS[5], CANNet_RecvMsgCAN5);

    /*发送报文初始化*/
    CANNet_infoMsgTxConfS[0].infoMsgIDUI = 0x1F000000UL;
    CANNet_infoMsgTxConfS[0].infoMsgParU.B.CAN = 0;
    CANNet_infoMsgTxConfS[0].infoMsgParU.B.MO = 1;
    CANNet_infoMsgTxConfS[0].infoMsgParU.B.DIR = _MCAN_DIR_TX;
    CANNet_infoMsgTxConfS[0].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgTxConfS[0].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgTxConfS[0], NULL_PTR);

    CANNet_infoMsgTxConfS[1].infoMsgIDUI = 0x1F000010UL;
    CANNet_infoMsgTxConfS[1].infoMsgParU.B.CAN = 1;
    CANNet_infoMsgTxConfS[1].infoMsgParU.B.MO = 1;
    CANNet_infoMsgTxConfS[1].infoMsgParU.B.DIR = _MCAN_DIR_TX;
    CANNet_infoMsgTxConfS[1].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgTxConfS[1].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgTxConfS[1], NULL_PTR);

    CANNet_infoMsgTxConfS[2].infoMsgIDUI = 0x1F000020UL;
    CANNet_infoMsgTxConfS[2].infoMsgParU.B.CAN = 2;
    CANNet_infoMsgTxConfS[2].infoMsgParU.B.MO = 1;
    CANNet_infoMsgTxConfS[2].infoMsgParU.B.DIR = _MCAN_DIR_TX;
    CANNet_infoMsgTxConfS[2].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgTxConfS[2].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgTxConfS[2], NULL_PTR);

    CANNet_infoMsgTxConfS[3].infoMsgIDUI = 0x1F000030UL;
    CANNet_infoMsgTxConfS[3].infoMsgParU.B.CAN = 3;
    CANNet_infoMsgTxConfS[3].infoMsgParU.B.MO = 1;
    CANNet_infoMsgTxConfS[3].infoMsgParU.B.DIR = _MCAN_DIR_TX;
    CANNet_infoMsgTxConfS[3].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgTxConfS[3].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgTxConfS[3], NULL_PTR);

    CANNet_infoMsgTxConfS[4].infoMsgIDUI = 0x1F000040UL;
    CANNet_infoMsgTxConfS[4].infoMsgParU.B.CAN = 4;
    CANNet_infoMsgTxConfS[4].infoMsgParU.B.MO = 1;
    CANNet_infoMsgTxConfS[4].infoMsgParU.B.DIR = _MCAN_DIR_TX;
    CANNet_infoMsgTxConfS[4].infoMsgParU.B.DLC = 8;
    CANNet_infoMsgTxConfS[4].infoMsgParU.B.IDE = _MCAN_IDE_EXT;
    MCANDrv_SetMsgObj(CANNet_infoMsgTxConfS[4], NULL_PTR);
}

//CAN0接收消息处理函数
void CANNet_RecvMsgCAN0(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    //CAN接收样例
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[0].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[idxIncUB]++;
    }
}

//CAN1接收消息处理函数
void CANNet_RecvMsgCAN1(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    //CAN接收样例
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[1].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[9+idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[9+idxIncUB]++;
    }
}

//CAN2接收消息处理函数
void CANNet_RecvMsgCAN2(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    //CAN接收样例
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[2].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[18+idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[18+idxIncUB]++;
    }
}

//CAN3接收消息处理函数
void CANNet_RecvMsgCAN3(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    //CAN接收样例
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[3].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[27+idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[27+idxIncUB]++;
    }
}

//CAN4接收消息处理函数
void CANNet_RecvMsgCAN4(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    //CAN接收样例
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[4].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[36+idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[36+idxIncUB]++;
    }
}

//CAN5接收消息处理函数
void CANNet_RecvMsgCAN5(MCANDrv_infoMsgS_TYPE infoMsgS)
{
    uint8 idxIncUB;

    if(infoMsgS.infoConfS.infoMsgIDUI == CANNet_infoMsgRxConfS[5].infoMsgIDUI)
    {
        for(idxIncUB=0; idxIncUB<8; idxIncUB++)
        {
            CANNet_datMsgBufUBA[45+idxIncUB] = infoMsgS.datMsgUBA[idxIncUB];
        }

        CANNet_datMsgBufUBA[45+idxIncUB]++;
    }
}

//发送消息管理
void CANNet_Manage1ms(void)
{
    MCANDrv_infoMsgS_TYPE infoMsgS;
    
    switch(CANNet_idxSchedUB)
    {
        case 0:
            //CAN发送样例
            infoMsgS.infoConfS = CANNet_infoMsgTxConfS[0];

            infoMsgS.datMsgUBA[0] = (uint8)SysCon_tiRunLowUI;
            infoMsgS.datMsgUBA[1] = (uint8)(SysCon_tiRunLowUI>>8);
            infoMsgS.datMsgUBA[2] = (uint8)(SysCon_tiRunLowUI>>16);
            infoMsgS.datMsgUBA[3] = (uint8)(SysCon_tiRunLowUI>>24);
            infoMsgS.datMsgUBA[4] = 0xB2;
            infoMsgS.datMsgUBA[5] = 0xE8;
            infoMsgS.datMsgUBA[6] = 0x7F;
            infoMsgS.datMsgUBA[7] = 0xE1;
            
            MCANDrv_SendMsg(infoMsgS);
            
            break;

        case 2:
            infoMsgS.infoConfS = CANNet_infoMsgTxConfS[1];

            infoMsgS.datMsgUBA[0] = 0xB2;
            infoMsgS.datMsgUBA[1] = (uint8)SysCon_tiRunLowUI;
            infoMsgS.datMsgUBA[2] = (uint8)(SysCon_tiRunLowUI>>8);
            infoMsgS.datMsgUBA[3] = (uint8)(SysCon_tiRunLowUI>>16);
            infoMsgS.datMsgUBA[4] = (uint8)(SysCon_tiRunLowUI>>24);
            infoMsgS.datMsgUBA[5] = 0xE8;
            infoMsgS.datMsgUBA[6] = 0x7F;
            infoMsgS.datMsgUBA[7] = 0xE1;

            MCANDrv_SendMsg(infoMsgS);

            break;

        case 4:
            infoMsgS.infoConfS = CANNet_infoMsgTxConfS[2];

            infoMsgS.datMsgUBA[0] = 0xB2;
            infoMsgS.datMsgUBA[1] = 0xE8;
            infoMsgS.datMsgUBA[2] = (uint8)SysCon_tiRunLowUI;
            infoMsgS.datMsgUBA[3] = (uint8)(SysCon_tiRunLowUI>>8);
            infoMsgS.datMsgUBA[4] = (uint8)(SysCon_tiRunLowUI>>16);
            infoMsgS.datMsgUBA[5] = (uint8)(SysCon_tiRunLowUI>>24);
            infoMsgS.datMsgUBA[6] = 0x7F;
            infoMsgS.datMsgUBA[7] = 0xE1;

            MCANDrv_SendMsg(infoMsgS);

            break;
    
        case 6:
            infoMsgS.infoConfS = CANNet_infoMsgTxConfS[3];

            infoMsgS.datMsgUBA[0] = 0xB2;
            infoMsgS.datMsgUBA[1] = 0xE8;
            infoMsgS.datMsgUBA[2] = 0x7F;
            infoMsgS.datMsgUBA[3] = (uint8)SysCon_tiRunLowUI;
            infoMsgS.datMsgUBA[4] = (uint8)(SysCon_tiRunLowUI>>8);
            infoMsgS.datMsgUBA[5] = (uint8)(SysCon_tiRunLowUI>>16);
            infoMsgS.datMsgUBA[6] = (uint8)(SysCon_tiRunLowUI>>24);
            infoMsgS.datMsgUBA[7] = 0xE1;

            MCANDrv_SendMsg(infoMsgS);

            break;

        case 8:
            infoMsgS.infoConfS = CANNet_infoMsgTxConfS[4];

            infoMsgS.datMsgUBA[0] = 0xB2;
            infoMsgS.datMsgUBA[1] = 0xE8;
            infoMsgS.datMsgUBA[2] = 0x7F;
            infoMsgS.datMsgUBA[3] = 0xE1;
            infoMsgS.datMsgUBA[4] = (uint8)SysCon_tiRunLowUI;
            infoMsgS.datMsgUBA[5] = (uint8)(SysCon_tiRunLowUI>>8);
            infoMsgS.datMsgUBA[6] = (uint8)(SysCon_tiRunLowUI>>16);
            infoMsgS.datMsgUBA[7] = (uint8)(SysCon_tiRunLowUI>>24);

            MCANDrv_SendMsg(infoMsgS);

            break;
            
        default:
            break;
    }
    
    CANNet_idxSchedUB=(uint8)((CANNet_idxSchedUB+1)%10); //10ms一个完整循环
}
