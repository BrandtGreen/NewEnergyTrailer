/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2009-2015 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：全局定义
* 文件名： Std_Types.h
* 功能描述 ： 基本类型定义及全局宏定义头文件
* 引用记录：该文件被各个.h文件包含
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2009.02.22           00.01.00     方成     第一版
*******************************************************************************/

#ifndef __TYPEDEF_H
    #define __TYPEDEF_H


    #include "SysConf.h"
    
    /*******************************************************************************************
                                  基本变量类型定义
    ********************************************************************************************/
		typedef unsigned char boolean; 

		typedef signed char sint8; 
		typedef unsigned char uint8;
		typedef signed short sint16; 
		typedef unsigned short uint16; 
		typedef signed long sint32;
		typedef unsigned long uint32; 

		typedef unsigned long uint8_least; 
		typedef unsigned long uint16_least;
		typedef unsigned long uint32_least; 

		typedef signed long sint8_least; 
		typedef signed long sint16_least;
		typedef signed long sint32_least;

		typedef float float32; 
		typedef double float64; 
		
		#ifndef NULL
			#define NULL    (0)
		#endif
		
		#ifndef NULL_PTR
            #define NULL_PTR ((void *)0)
        #endif

		#ifndef TRUE
			#define TRUE 1
		#endif

		#ifndef FALSE
			#define FALSE 0
		#endif
                     
		/* From AUTOSAR define Std_ReturnType */
		typedef uint8 Std_ReturnType;

#endif 
