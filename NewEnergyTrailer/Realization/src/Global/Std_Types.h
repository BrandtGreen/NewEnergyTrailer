/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2009-2015 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ�ȫ�ֶ���
* �ļ����� Std_Types.h
* �������� �� �������Ͷ��弰ȫ�ֺ궨��ͷ�ļ�
* ���ü�¼�����ļ�������.h�ļ�����
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2009.02.22           00.01.00     ����     ��һ��
*******************************************************************************/

#ifndef __TYPEDEF_H
    #define __TYPEDEF_H


    #include "SysConf.h"
    
    /*******************************************************************************************
                                  �����������Ͷ���
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
