/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2005~2017 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ��ײ�����_�ڴ���Դ����
* �ļ����� EOLData.c
* �������� �� EOL����
* ���ü�¼��
* ������¼��
* ��ע��
* �޶���¼��
*       ����            �汾          ����        ����
*   2017.09.05   00.01.00    ����               ��һ��
*******************************************************************************/

#include "EOLData.h"


/******************************************************************************************************
 * EOL����
 ******************************************************************************************************/

#define EOL_START_SEC_VAR
#include "MemMap.h"
    uint8 K2REI_VMVINUB_CA[_EOL_LEN_K2REI_VMVIN]="";  //������ţ�VIN��
    uint8 K2REI_VMVehModelUB_CA[_EOL_LEN_K2REI_VMVIN]="";  //�����ͺ�
    uint8 K2REI_VMECUSWVERUB_CA[_EOL_LEN_K2REI_VMECUSWVER]="P036V100";  //�ͻ������ECU����汾
    uint8 K2REI_VMECUHWNRUB_CA[_EOL_LEN_K2REI_VMECUHWNR]="EC6301V";  //ECUӲ����
    uint8 K2REI_VMTESTERSNUB_CA[_EOL_LEN_K2REI_VMTESTERSN]="";  //Vehicle Manufacturer Repair Shop Code or Tester Serial Number
    uint8 K2REI_VMPMDATEUB_CA[_EOL_LEN_K2REI_VMPMDATE]="";  //Vehicle Manufacturer Program Data
    uint8 K2REI_VMEGTSTDATEUB_CA[_EOL_LEN_K2REI_VMEGTSTDATE]="";  //Vehicle Manufacturer Engine Test Date
    uint8 K2REI_VMDSIDUB_CA[_EOL_LEN_K2REI_VMDSID]="";  //Vehicle Manufacturer Dataset Identification
#define EOL_STOP_SEC_VAR
#include "MemMap.h"

/******************************************************************************************************/

