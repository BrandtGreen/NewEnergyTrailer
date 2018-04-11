/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2005~2017 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：底层驱动_内存资源管理
* 文件名： EOLData.h
* 功能描述 ： EOL数据
* 引用记录：
* 发布记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2017.09.05   00.01.00    李中               第一版
*******************************************************************************/


#ifndef __EOLDATA_H

    #define __EOLDATA_H
    
    
    #include "Std_Types.h"
    
    
    #define _EOL_LEN_K2REI_VMVIN 34     //Vehicle Manufacturer Vehicle Identification Number
    #define _EOL_LEN_K2REI_VMECUSWVER 64   //Vehicle Manufacturer ECU Software  Version
    #define _EOL_LEN_K2REI_VMECUHWNR 16   //Vehicle Manufacturer ECU Hardware Number
    #define _EOL_LEN_K2REI_VMTESTERSN 16 //Vehicle Manufacturer Repair Shop Code or Tester Serial Number
    #define _EOL_LEN_K2REI_VMPMDATE 10  //Vehicle Manufacturer Program Data
    #define _EOL_LEN_K2REI_VMEGTSTDATE 10  //Vehicle Manufacturer Engine Test Date
    #define _EOL_LEN_K2REI_VMDSID 66  //Vehicle Manufacturer Dataset Identification

    /******************************************************************************************************
     * EOL数据
     ******************************************************************************************************/

    #define EOL_START_SEC_VAR
    #include "MemMap.h"
        extern uint8 K2REI_VMVINUB_CA[_EOL_LEN_K2REI_VMVIN];  //整车编号（VIN）
        extern uint8 K2REI_VMVehModelUB_CA[_EOL_LEN_K2REI_VMVIN];  //整车型号
        extern uint8 K2REI_VMECUSWVERUB_CA[_EOL_LEN_K2REI_VMECUSWVER];  //客户定义的ECU软件版本
        extern uint8 K2REI_VMECUHWNRUB_CA[_EOL_LEN_K2REI_VMECUHWNR];  //ECU硬件号
        extern uint8 K2REI_VMTESTERSNUB_CA[_EOL_LEN_K2REI_VMTESTERSN];  //Vehicle Manufacturer Repair Shop Code or Tester Serial Number
        extern uint8 K2REI_VMPMDATEUB_CA[_EOL_LEN_K2REI_VMPMDATE];  //Vehicle Manufacturer Program Data
        extern uint8 K2REI_VMEGTSTDATEUB_CA[_EOL_LEN_K2REI_VMEGTSTDATE];  //Vehicle Manufacturer Engine Test Date
        extern uint8 K2REI_VMDSIDUB_CA[_EOL_LEN_K2REI_VMDSID];  //Vehicle Manufacturer Dataset Identification
    #define EOL_STOP_SEC_VAR
    #include "MemMap.h"

    /******************************************************************************************************/

#endif
