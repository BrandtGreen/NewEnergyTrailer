/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车管理
* 文件名： UDSInterface.h
* 功能描述 ： UDS管理头文件
* 引用记录：
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2017.07.03          00.01.00      李中     第一版
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

    #define _UDS_DID_MASK_RDEF  0x0001  //Default模式下的读权限
    #define _UDS_DID_MASK_REXT  0x0002  //ExtDiag模式下的读权限
    #define _UDS_DID_MASK_RPRO  0x0004  //Program模式下的读权限
    #define _UDS_DID_MASK_WDEF  0x0010  //Default模式下的写权限
    #define _UDS_DID_MASK_WEXT  0x0020  //ExtDiag模式下的写权限
    #define _UDS_DID_MASK_WPRO  0x0040  //Program模式下的写权限
    #define _UDS_DID_MASK_LTBO  0x8000  //是否按LittleEndian方式处理数据, 数组应按BigEndian方式处理


    typedef struct
    {
    	uint16 idxDataIDUW;
    	uint32 addrDataUI;
    	uint16 numSizeUW;
    	uint16 infoMaskU;
    } UDSInterface_infoEnvDataS_TYPE; /*环境信息*/

    typedef struct
    {
        uint16 numDIDUW;
        const UDSInterface_infoEnvDataS_TYPE * addrEnvDataSP;
    } UDSInterface_infoEnvDIDConfS_TYPE;

    extern const UDSInterface_infoEnvDIDConfS_TYPE UDSInterface_infoEnvDIDConfS;
    
    
#endif
