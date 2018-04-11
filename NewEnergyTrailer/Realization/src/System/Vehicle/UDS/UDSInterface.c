/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ���������
* �ļ����� UDSInterface.h
* �������� �� UDS����
* ���ü�¼��
* ��ע�� 
* �޶���¼��
*       ����            �汾          ����        ����
*   2017.07.03          00.01.00      ����     ��һ��
*******************************************************************************/

#include "UDSInterface.h"
#include "HardwareLib.h"
#include "VehCo.h"
#include "EOLData.h"

/*������Ϣ����*/
#define _UDSINTERFACE_NUM_ENVDATA 9

const UDSInterface_infoEnvDataS_TYPE UDSInterface_infoEnvDataSA[_UDSINTERFACE_NUM_ENVDATA]=
{
	{
	        _UDS_INDEX_IDENT_VEHNANUFECUSWNO, //Ӧ�ò�����汾��
	        (uint32)&AppLayer_idxVerUBA,
	        64,
	        0x0007, //ֻ�ܶ�������д
	},
	{
	        _UDS_INDEX_IDENT_VIN, //������ţ�VIN��
	        (uint32)&K2REI_VMVINUB_CA,
	        _EOL_LEN_K2REI_VMVIN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_SYSNAMEORENGTYPE, //�����ͺ�
	        (uint32)&K2REI_VMVehModelUB_CA,
	        _EOL_LEN_K2REI_VMVIN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_VEHMANUFECUSWVERNO, //�ͻ������ECU����汾
	        (uint32)&K2REI_VMECUSWVERUB_CA,
	        _EOL_LEN_K2REI_VMECUSWVER,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_VEHMANUFECUHWNO, //�ͻ������ECUӲ����
	        (uint32)&K2REI_VMECUHWNRUB_CA,
	        _EOL_LEN_K2REI_VMECUHWNR,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_REPAIRSHOPCODE, //���߻�������������豸���
	        (uint32)&K2REI_VMTESTERSNUB_CA,
	        _EOL_LEN_K2REI_VMTESTERSN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_PROGAMMINGDATE, //���߻������������
	        (uint32)&K2REI_VMPMDATEUB_CA,
	        _EOL_LEN_K2REI_VMPMDATE,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_ECUINSTALLDATE, //Vehicle Manufacturer Engine Test Date
	        (uint32)&K2REI_VMEGTSTDATEUB_CA,
	        _EOL_LEN_K2REI_VMEGTSTDATE,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_CALIBRATIONEQSWNO, //Vehicle Manufacturer Dataset Identification
	        (uint32)&K2REI_VMDSIDUB_CA,
	        _EOL_LEN_K2REI_VMDSID,
	        0x0067,
	},
};

const UDSInterface_infoEnvDIDConfS_TYPE UDSInterface_infoEnvDIDConfS=
{
    _UDSINTERFACE_NUM_ENVDATA,
    &(UDSInterface_infoEnvDataSA[0]),
};

