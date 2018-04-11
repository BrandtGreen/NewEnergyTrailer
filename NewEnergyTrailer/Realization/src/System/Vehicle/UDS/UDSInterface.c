/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： UDSInterface.h
* 功能描述 ： UDS管理
* 引用记录：
* 备注： 
* 修订记录：
*       日期            版本          作者        描述
*   2017.07.03          00.01.00      李中     第一版
*******************************************************************************/

#include "UDSInterface.h"
#include "HardwareLib.h"
#include "VehCo.h"
#include "EOLData.h"

/*环境信息配置*/
#define _UDSINTERFACE_NUM_ENVDATA 9

const UDSInterface_infoEnvDataS_TYPE UDSInterface_infoEnvDataSA[_UDSINTERFACE_NUM_ENVDATA]=
{
	{
	        _UDS_INDEX_IDENT_VEHNANUFECUSWNO, //应用层软件版本号
	        (uint32)&AppLayer_idxVerUBA,
	        64,
	        0x0007, //只能读，不可写
	},
	{
	        _UDS_INDEX_IDENT_VIN, //整车编号（VIN）
	        (uint32)&K2REI_VMVINUB_CA,
	        _EOL_LEN_K2REI_VMVIN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_SYSNAMEORENGTYPE, //整车型号
	        (uint32)&K2REI_VMVehModelUB_CA,
	        _EOL_LEN_K2REI_VMVIN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_VEHMANUFECUSWVERNO, //客户定义的ECU软件版本
	        (uint32)&K2REI_VMECUSWVERUB_CA,
	        _EOL_LEN_K2REI_VMECUSWVER,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_VEHMANUFECUHWNO, //客户定义的ECU硬件号
	        (uint32)&K2REI_VMECUHWNRUB_CA,
	        _EOL_LEN_K2REI_VMECUHWNR,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_REPAIRSHOPCODE, //下线或检修生产厂或设备编号
	        (uint32)&K2REI_VMTESTERSNUB_CA,
	        _EOL_LEN_K2REI_VMTESTERSN,
	        0x0067,
	},
	{
	        _UDS_INDEX_IDENT_PROGAMMINGDATE, //下线或检修生产日期
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

