/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ���������
* �ļ����� UDSInterface.h
* �������� �� UDS����ͷ�ļ�
* ���ü�¼��
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2017.07.03          00.01.00      ����     ��һ��
*******************************************************************************/

#ifndef __UDSINTERFACE_H
    #define __UDSINTERFACE_H

    #include "Std_Types.h"
    
    #define _UDS_INDEX_IDENT_VEHNANUFECUSWNO        0xF188U
    #define _UDS_INDEX_IDENT_VEHMANUFECUSWVERNO     0xF189U
    #define _UDS_INDEX_IDENT_VIN                    0xF190U
    #define _UDS_INDEX_IDENT_VEHMANUFECUHWNO        0xF191U
    #define _UDS_INDEX_IDENT_SYSNAMEORENGTYPE       0xF197U
    #define _UDS_INDEX_IDENT_REPAIRSHOPCODE         0xF198U
    #define _UDS_INDEX_IDENT_PROGAMMINGDATE         0xF199U
    #define _UDS_INDEX_IDENT_CALIBRATIONEQSWNO      0xF19CU
    #define _UDS_INDEX_IDENT_ECUINSTALLDATE         0xF19DU

    #define _UDS_DID_MASK_RDEF  0x0001  //Defaultģʽ�µĶ�Ȩ��
    #define _UDS_DID_MASK_REXT  0x0002  //ExtDiagģʽ�µĶ�Ȩ��
    #define _UDS_DID_MASK_RPRO  0x0004  //Programģʽ�µĶ�Ȩ��
    #define _UDS_DID_MASK_WDEF  0x0010  //Defaultģʽ�µ�дȨ��
    #define _UDS_DID_MASK_WEXT  0x0020  //ExtDiagģʽ�µ�дȨ��
    #define _UDS_DID_MASK_WPRO  0x0040  //Programģʽ�µ�дȨ��
    #define _UDS_DID_MASK_LTBO  0x8000  //�Ƿ�LittleEndian��ʽ��������, ����Ӧ��BigEndian��ʽ����


    typedef struct
    {
    	uint16 idxDataIDUW;
    	uint32 addrDataUI;
    	uint16 numSizeUW;
    	uint16 infoMaskU;
    } UDSInterface_infoEnvDataS_TYPE; /*������Ϣ*/

    typedef struct
    {
        uint16 numDIDUW;
        const UDSInterface_infoEnvDataS_TYPE * addrEnvDataSP;
    } UDSInterface_infoEnvDIDConfS_TYPE;

    extern const UDSInterface_infoEnvDIDConfS_TYPE UDSInterface_infoEnvDIDConfS;
    
    
#endif
