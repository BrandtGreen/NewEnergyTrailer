/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2005~2017 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：HardwareLib
* 文件名： MemMap.h
* 功能描述 ： 内存映射设置
* 引用记录：
* 发布记录：
* 备注：
* 代码段
*   Prefix_START(STOP)_SEC_CODE
*   Prefix_START(STOP)_SEC_CALLOUT_CODE
*   Prefix_START(STOP)_SEC_CODE_FAST_<NUM>
*   Prefix_START(STOP)_SEC_CODE_SLOW
*   Prefix_START(STOP)_SEC_CODE_LIB
* 变量段
*   Prefix_START(STOP)_SEC_VAR_NOINIT_<SIZE>
*   Prefix_START(STOP)_SEC_VAR_POWER_ON_INIT_<SIZE>
*   Prefix_START(STOP)_SEC_VAR_FAST_<SIZE>
*   Prefix_START(STOP)_SEC__INTERNAL_VAR_<SIZE>
*   Prefix_START(STOP)_SEC_VAR_SAVED_ZONE_<SIZE>
*   Prefix_START(STOP)_SEC_VAR_SAVED_RECOVERY_<SIZE>
*   Prefix_START(STOP)_SEC_VAR_<SIZE>
* 常数段
*   Prefix_START(STOP)_SEC_CONST_<SIZE>
*   Prefix_START(STOP)_SEC_CALIB_<SIZE>
*   Prefix_START(STOP)_SEC_CARTO_<SIZE>
* 配置段
*   Prefix_START(STOP)_SEC_CONFIG_DATA_<SIZE>
* 修订记录：
*       日期            版本          作者        描述
*       2014.12.21        01.00.00    方成      第一版
*******************************************************************************/


/***********************AUTOSAR用户定义*************************/

#if !defined(MEM_VENDOR_ID)
    #define MEM_VENDOR_ID 1U /* 3SOFT GmbH */
#endif



/***********************以下为版本定义*************************/

#if !defined(MEM_AR_RELEASE_MAJOR_VERSION)
    #define MEM_AR_RELEASE_MAJOR_VERSION 4U
#endif

#if !defined(MEM_AR_RELEASE_MINOR_VERSION)
    #define MEM_AR_RELEASE_MINOR_VERSION 0U
#endif

#if !defined(MEM_AR_RELEASE_REVISION_VERSION)
    #define MEM_AR_RELEASE_REVISION_VERSION 0U
#endif



/***********************以下为软件版本定义*************************/
#if !defined(MEM_SW_MAJOR_VERSION)
    #define MEM_SW_MAJOR_VERSION 1U
#endif

#if !defined(MEM_SW_MINOR_VERSION)
    #define MEM_SW_MINOR_VERSION 0U
#endif

#if !defined(MEM_SW_PATCH_VERSION)
    #define MEM_SW_PATCH_VERSION 0U
#endif



/***********************以下为MEMMAP_ERROR定义*************************/
#if defined(MEMMAP_ERROR)
    #error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif

#define MEMMAP_ERROR


/***********************以下为对开发环境的定义*************************/
#ifndef _HIGHTEC_TC2XX_
    #define _HIGHTEC_TC2XX_
#endif


/***********************以下为各模块内存映射定义*************************/

/*CODE*/
/*CODE_FAST*/
/*代码段*/
#if defined ADC_START_SEC_CODE
    #undef ADC_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CODE
    #undef ADC_STOP_SEC_CODE
    #undef MEMMAP_ERROR


#elif defined ADC_START_SEC_CODE_FAST
    #undef ADC_START_SEC_CODE_FAST
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CODE_FAST
    #undef ADC_STOP_SEC_CODE_FAST
    #undef MEMMAP_ERROR


/*VAR_NOINIT,不需要初始化的变量*/
#elif defined ADC_START_SEC_VAR_NOINIT_8BIT
    #undef ADC_START_SEC_VAR_NOINIT_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_NOINIT_8BIT
    #undef ADC_STOP_SEC_VAR_NOINIT_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_NOINIT_16BIT
    #undef ADC_START_SEC_VAR_NOINIT_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_NOINIT_16BIT
    #undef ADC_STOP_SEC_VAR_NOINIT_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_NOINIT_32BIT
    #undef ADC_START_SEC_VAR_NOINIT_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_NOINIT_32BIT
    #undef ADC_STOP_SEC_VAR_NOINIT_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR_POWER_ON_INIT 上电后初始化的变量*/
#elif defined ADC_START_SEC_VAR_POWER_ON_INIT_8BIT
    #undef ADC_START_SEC_VAR_POWER_ON_INIT_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #undef ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_POWER_ON_INIT_16BIT
    #undef ADC_START_SEC_VAR_POWER_ON_INIT_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #undef ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_POWER_ON_INIT_32BIT
    #undef ADC_START_SEC_VAR_POWER_ON_INIT_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #undef ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR_FAST，经常使用的变量*/
#elif defined ADC_START_SEC_VAR_FAST_8BIT
    #undef ADC_START_SEC_VAR_FAST_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_FAST_8BIT
    #undef ADC_STOP_SEC_VAR_FAST_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_FAST_16BIT
    #undef ADC_START_SEC_VAR_FAST_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_FAST_16BIT
    #undef ADC_STOP_SEC_VAR_FAST_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_FAST_32BIT
    #undef ADC_START_SEC_VAR_FAST_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_FAST_32BIT
    #undef ADC_STOP_SEC_VAR_FAST_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_FAST_UNSPECIFIED
    #undef ADC_START_SEC_VAR_FAST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR，每次复位都初始化的变量*/
#elif defined ADC_START_SEC_VAR_8BIT
    #undef ADC_START_SEC_VAR_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_8BIT
    #undef ADC_STOP_SEC_VAR_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_16BIT
    #undef ADC_START_SEC_VAR_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_16BIT
    #undef ADC_STOP_SEC_VAR_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_32BIT
    #undef ADC_START_SEC_VAR_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_32BIT
    #undef ADC_STOP_SEC_VAR_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_VAR_UNSPECIFIED
    #undef ADC_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_VAR_UNSPECIFIED
    #undef ADC_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/*CONST，常数*/
#elif defined ADC_START_SEC_CONST_8BIT
    #undef ADC_START_SEC_CONST_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CONST_8BIT
    #undef ADC_STOP_SEC_CONST_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_CONST_16BIT
    #undef ADC_START_SEC_CONST_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CONST_16BIT
    #undef ADC_STOP_SEC_CONST_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_CONST_32BIT
    #undef ADC_START_SEC_CONST_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CONST_32BIT
    #undef ADC_STOP_SEC_CONST_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_SEC_CONST_UNSPECIFIED
    #undef ADC_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_SEC_CONST_UNSPECIFIED
    #undef ADC_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR


/*CONFIG_DATA，配置数据*/
#elif defined ADC_START_CONFIG_DATA_8BIT
    #undef ADC_START_CONFIG_DATA_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_CONFIG_DATA_8BIT
    #undef ADC_STOP_CONFIG_DATA_8BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_CONFIG_DATA_16BIT
    #undef ADC_START_CONFIG_DATA_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_CONFIG_DATA_16BIT
    #undef ADC_STOP_CONFIG_DATA_16BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_CONFIG_DATA_32BIT
    #undef ADC_START_CONFIG_DATA_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_CONFIG_DATA_32BIT
    #undef ADC_STOP_CONFIG_DATA_32BIT
    #undef MEMMAP_ERROR

#elif defined ADC_START_CONFIG_DATA_UNSPECIFIED
    #undef ADC_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ADC_STOP_CONFIG_DATA_UNSPECIFIED
    #undef ADC_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为Os模块内存映射定义*************************/


/*CODE*/
/*CODE_FAST*/
/*代码段*/
#elif defined OS_START_SEC_CODE
    #undef OS_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CODE
    #undef OS_STOP_SEC_CODE
    #undef MEMMAP_ERROR


#elif defined OS_START_SEC_CODE_FAST
    #undef OS_START_SEC_CODE_FAST
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CODE_FAST
    #undef OS_STOP_SEC_CODE_FAST
    #undef MEMMAP_ERROR


/*VAR_NOINIT,不需要初始化的变量*/
#elif defined OS_START_SEC_VAR_NOINIT_8BIT
    #undef OS_START_SEC_VAR_NOINIT_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_NOINIT_8BIT
    #undef OS_STOP_SEC_VAR_NOINIT_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_NOINIT_16BIT
    #undef OS_START_SEC_VAR_NOINIT_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_NOINIT_16BIT
    #undef OS_STOP_SEC_VAR_NOINIT_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_NOINIT_32BIT
    #undef OS_START_SEC_VAR_NOINIT_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_NOINIT_32BIT
    #undef OS_STOP_SEC_VAR_NOINIT_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR_POWER_ON_INIT 上电后初始化的变量*/
#elif defined OS_START_SEC_VAR_POWER_ON_INIT_8BIT
    #undef OS_START_SEC_VAR_POWER_ON_INIT_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #undef OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_POWER_ON_INIT_16BIT
    #undef OS_START_SEC_VAR_POWER_ON_INIT_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #undef OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_POWER_ON_INIT_32BIT
    #undef OS_START_SEC_VAR_POWER_ON_INIT_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #undef OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR_FAST，经常使用的变量*/
#elif defined OS_START_SEC_VAR_FAST_8BIT
    #undef OS_START_SEC_VAR_FAST_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_FAST_8BIT
    #undef OS_STOP_SEC_VAR_FAST_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_FAST_16BIT
    #undef OS_START_SEC_VAR_FAST_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_FAST_16BIT
    #undef OS_STOP_SEC_VAR_FAST_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_FAST_32BIT
    #undef OS_START_SEC_VAR_FAST_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_FAST_32BIT
    #undef OS_STOP_SEC_VAR_FAST_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_FAST_UNSPECIFIED
    #undef OS_START_SEC_VAR_FAST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef OS_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef MEMMAP_ERROR


/*VAR，每次复位都初始化的变量*/
#elif defined OS_START_SEC_VAR_8BIT
    #undef OS_START_SEC_VAR_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_8BIT
    #undef OS_STOP_SEC_VAR_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_16BIT
    #undef OS_START_SEC_VAR_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_16BIT
    #undef OS_STOP_SEC_VAR_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_32BIT
    #undef OS_START_SEC_VAR_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_32BIT
    #undef OS_STOP_SEC_VAR_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_VAR_UNSPECIFIED
    #undef OS_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_VAR_UNSPECIFIED
    #undef OS_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/*CONST，常数*/
#elif defined OS_START_SEC_CONST_8BIT
    #undef OS_START_SEC_CONST_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CONST_8BIT
    #undef OS_STOP_SEC_CONST_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_CONST_16BIT
    #undef OS_START_SEC_CONST_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CONST_16BIT
    #undef OS_STOP_SEC_CONST_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_CONST_32BIT
    #undef OS_START_SEC_CONST_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CONST_32BIT
    #undef OS_STOP_SEC_CONST_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_SEC_CONST_UNSPECIFIED   
    #undef OS_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_SEC_CONST_UNSPECIFIED
    #undef OS_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR


/*CONFIG_DATA，配置数据*/
#elif defined OS_START_CONFIG_DATA_8BIT
    #undef OS_START_CONFIG_DATA_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_CONFIG_DATA_8BIT
    #undef OS_STOP_CONFIG_DATA_8BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_CONFIG_DATA_16BIT
    #undef OS_START_CONFIG_DATA_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_CONFIG_DATA_16BIT
    #undef OS_STOP_CONFIG_DATA_16BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_CONFIG_DATA_32BIT
    #undef OS_START_CONFIG_DATA_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_STOP_CONFIG_DATA_32BIT
    #undef OS_STOP_CONFIG_DATA_32BIT
    #undef MEMMAP_ERROR

#elif defined OS_START_CONFIG_DATA_UNSPECIFIED
    #undef OS_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined OS_STOP_CONFIG_DATA_UNSPECIFIED
    #undef OS_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

/***********************以下为PORT模块内存映射定义*************************/

#elif defined PORT_START_CONFIG_DATA_UNSPECIFIED
    #undef PORT_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PORT_STOP_CONFIG_DATA_UNSPECIFIED
    #undef PORT_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PORT_START_SEC_CODE
    #undef PORT_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_CODE
    #undef PORT_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PORT_START_SEC_VAR_UNSPECIFIED
    #undef PORT_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_VAR_UNSPECIFIED
    #undef PORT_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为DIO模块内存映射定义*************************/

#elif defined DIO_START_CONFIG_DATA_UNSPECIFIED
    #undef DIO_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined DIO_STOP_CONFIG_DATA_UNSPECIFIED
    #undef DIO_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined DIO_START_SEC_CODE
    #undef DIO_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined DIO_STOP_SEC_CODE
    #undef DIO_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined DIO_START_SEC_VAR_UNSPECIFIED
    #undef DIO_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined DIO_STOP_SEC_VAR_UNSPECIFIED
    #undef DIO_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR



/***********************以下为PWM模块内存映射定义*************************/

#elif defined PWM_START_CONFIG_DATA_UNSPECIFIED
    #undef PWM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PWM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef PWM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PWM_START_SEC_CODE
    #undef PWM_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PWM_STOP_SEC_CODE
    #undef PWM_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PWM_START_SEC_VAR_UNSPECIFIED
    #undef PWM_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PWM_STOP_SEC_VAR_UNSPECIFIED
    #undef PWM_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为ICU模块内存映射定义*************************/

#elif defined ICU_START_CONFIG_DATA_UNSPECIFIED
    #undef ICU_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ICU_STOP_CONFIG_DATA_UNSPECIFIED
    #undef ICU_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ICU_START_SEC_CODE
    #undef ICU_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined ICU_STOP_SEC_CODE
    #undef ICU_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined ICU_START_SEC_VAR_UNSPECIFIED
    #undef ICU_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined ICU_STOP_SEC_VAR_UNSPECIFIED
    #undef ICU_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

/***********************以下为CAN模块内存映射定义*************************/

#elif defined CAN_START_CONFIG_DATA_UNSPECIFIED
    #undef CAN_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CAN_STOP_CONFIG_DATA_UNSPECIFIED
    #undef CAN_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CAN_START_SEC_CODE
    #undef CAN_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CAN_STOP_SEC_CODE
    #undef CAN_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CAN_START_SEC_VAR_UNSPECIFIED
    #undef CAN_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CAN_STOP_SEC_VAR_UNSPECIFIED
    #undef CAN_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为SPI模块内存映射定义*************************/

#elif defined SPI_START_CONFIG_DATA_UNSPECIFIED
    #undef SPI_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined SPI_STOP_CONFIG_DATA_UNSPECIFIED
    #undef SPI_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CODE
    #undef SPI_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_CODE
    #undef SPI_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_UNSPECIFIED
    #undef SPI_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_VAR_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

/***********************以下为MCU模块内存映射定义*************************/

#elif defined MCU_START_CONFIG_DATA_UNSPECIFIED
    #undef MCU_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined MCU_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MCU_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_CODE
    #undef MCU_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined MCU_START_SEC_VAR_UNSPECIFIED
    #undef MCU_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_VAR_UNSPECIFIED
    #undef MCU_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为IoHwAb模块内存映射定义*************************/
#elif defined IOHWAB_START_CONFIG_DATA_UNSPECIFIED
    #undef IOHWAB_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined IOHWAB_STOP_CONFIG_DATA_UNSPECIFIED
    #undef IOHWAB_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined IOHWAB_START_SEC_VAR_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined IOHWAB_STOP_SEC_VAR_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

/***********************以下为CANIF模块内存映射定义*************************/

#elif defined CANIF_START_CONFIG_DATA_UNSPECIFIED
    #undef CANIF_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANIF_STOP_CONFIG_DATA_UNSPECIFIED
    #undef CANIF_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANIF_START_SEC_CODE
    #undef CANIF_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CANIF_STOP_SEC_CODE
    #undef CANIF_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CANIF_START_SEC_VAR_UNSPECIFIED
    #undef CANIF_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANIF_STOP_SEC_VAR_UNSPECIFIED
    #undef CANIF_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为CANTP模块内存映射定义*************************/

#elif defined CANTP_START_CONFIG_DATA_UNSPECIFIED
    #undef CANTP_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANTP_STOP_CONFIG_DATA_UNSPECIFIED
    #undef CANTP_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANTP_START_SEC_CODE
    #undef CANTP_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CANTP_STOP_SEC_CODE
    #undef CANTP_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined CANTP_START_SEC_VAR_UNSPECIFIED
    #undef CANTP_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANTP_STOP_SEC_VAR_UNSPECIFIED
    #undef CANTP_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR



/***********************以下为J1939TP模块内存映射定义*************************/

#elif defined J1939TP_START_CONFIG_DATA_UNSPECIFIED
    #undef J1939TP_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined J1939TP_STOP_CONFIG_DATA_UNSPECIFIED
    #undef J1939TP_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined J1939TP_START_SEC_CODE
    #undef J1939TP_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined J1939TP_STOP_SEC_CODE
    #undef J1939TP_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined J1939TP_START_SEC_VAR_UNSPECIFIED
    #undef J1939TP_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined J1939TP_STOP_SEC_VAR_UNSPECIFIED
    #undef J1939TP_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR


/***********************以下为PDUR模块内存映射定义*************************/

#elif defined PDUR_START_CONFIG_DATA_UNSPECIFIED
    #undef PDUR_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PDUR_STOP_CONFIG_DATA_UNSPECIFIED
    #undef PDUR_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PDUR_START_SEC_CODE
    #undef PDUR_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PDUR_STOP_SEC_CODE
    #undef PDUR_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined PDUR_START_SEC_VAR_UNSPECIFIED
    #undef PDUR_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined PDUR_STOP_SEC_VAR_UNSPECIFIED
    #undef PDUR_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

/***********************以下为COM模块内存映射定义*************************/

#elif defined COM_START_CONFIG_DATA_UNSPECIFIED
    #undef COM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined COM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef COM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined COM_START_SEC_CODE
    #undef COM_START_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined COM_STOP_SEC_CODE
    #undef COM_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined COM_START_SEC_VAR_UNSPECIFIED
    #undef COM_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined COM_STOP_SEC_VAR_UNSPECIFIED
    #undef COM_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined MAPDATA_START_SEC_VAR_CONST
    #undef MAPDATA_START_SEC_VAR_CONST
    #undef MEMMAP_ERROR

    #define PRAGMA_MAPDATA volatile

    #if defined MAPVER_SEC_VAR_CONST
        #pragma section ".cal_data_ver"
    #else
        #pragma section ".cal_data"
    #endif

#elif defined MAPDATA_STOP_SEC_VAR_CONST
    #undef MAPDATA_STOP_SEC_VAR_CONST
    #undef MEMMAP_ERROR

    #pragma section

    #undef PRAGMA_MAPDATA

#elif defined EEPDATA_START_SEC_VAR
    #undef EEPDATA_START_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section ".runinfo_data" aw

#elif defined EEPDATA_STOP_SEC_VAR
    #undef EEPDATA_STOP_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section

#elif defined APPLAYERVER_START_SEC_VAR
    #undef APPLAYERVER_START_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section ".applayer_info" a

#elif defined APPLAYERVER_STOP_SEC_VAR
    #undef APPLAYERVER_STOP_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section

#elif defined EOL_START_SEC_VAR
    #undef EOL_START_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section ".eol_data" aw

#elif defined EOL_STOP_SEC_VAR
    #undef EOL_STOP_SEC_VAR
    #undef MEMMAP_ERROR

    #pragma section

#endif





#if defined(MEMMAP_ERROR)
    #error MEMMAP_ERROR defined,wrong Memory class defined!
#endif
