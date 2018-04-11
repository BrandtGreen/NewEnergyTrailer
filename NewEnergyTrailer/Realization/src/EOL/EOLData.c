/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2005~2017 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：底层驱动_内存资源管理
* 文件名： EOLData.c
* 功能描述 ： EOL数据
* 引用记录：
* 发布记录：
* 备注：
* 修订记录：
*       日期            版本          作者        描述
*   2017.09.05   00.01.00    李中               第一版
*******************************************************************************/

#include "EOLData.h"


/******************************************************************************************************
 * EOL数据
 ******************************************************************************************************/

#define EOL_START_SEC_VAR
#include "MemMap.h"
    uint8 K2REI_VMVINUB_CA[_EOL_LEN_K2REI_VMVIN]="";  //整车编号（VIN）
    uint8 K2REI_VMVehModelUB_CA[_EOL_LEN_K2REI_VMVIN]="";  //整车型号
    uint8 K2REI_VMECUSWVERUB_CA[_EOL_LEN_K2REI_VMECUSWVER]="P036V100";  //客户定义的ECU软件版本
    uint8 K2REI_VMECUHWNRUB_CA[_EOL_LEN_K2REI_VMECUHWNR]="EC6301V";  //ECU硬件号
    uint8 K2REI_VMTESTERSNUB_CA[_EOL_LEN_K2REI_VMTESTERSN]="";  //Vehicle Manufacturer Repair Shop Code or Tester Serial Number
    uint8 K2REI_VMPMDATEUB_CA[_EOL_LEN_K2REI_VMPMDATE]="";  //Vehicle Manufacturer Program Data
    uint8 K2REI_VMEGTSTDATEUB_CA[_EOL_LEN_K2REI_VMEGTSTDATE]="";  //Vehicle Manufacturer Engine Test Date
    uint8 K2REI_VMDSIDUB_CA[_EOL_LEN_K2REI_VMDSID]="";  //Vehicle Manufacturer Dataset Identification
#define EOL_STOP_SEC_VAR
#include "MemMap.h"

/******************************************************************************************************/

