/*============================================================================*/
/*                            CIDI SOFTWARE                                   */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
  * $Source: Rte.c $
  * $Revision: 1.0 $
  * $Author: Xiao Tao $
  * $Date: 2018/04/10 $
  */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Implementation of functions RTE.
*/
/*============================================================================*/
/* COPYRIGHT (C) CIDI 2018                                                    */
/* New Energy                                                                 */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*                            OBJECT HISTORY                                  */
/*============================================================================*/
/* Version            |     date                |      owner                  */
/* 1.0                |   04/09/2018            |     Xiao Tao                */
/* init version for RTE component                                             */
/*============================================================================*/

#include "Rte.h"

struct Rte_common_s Rte_Com;

typedef enum
{
I_S_BAK1=0,
I_S_BAK2,
I_S_BAK3,
I_S_BAK5,
I_S_BAK6,
I_S_MaxNumber,
}DI_Channel_Index;

/**************************************************************
 *  Name                 :  Rte_ReadIO
 *  Description          :  Read IO function
 *  Parameters           :  uint8 ID - IO port index
 *  Return               :  uint8 :  IO status
 *  Critical/explanation :  NONE
 **************************************************************/
uint8 Rte_ReadIO(uint8 ID)
{
    uint8 retval=0;
    retval = DINDrv_GetChanState(ID);
    return retval;
}

/**************************************************************
 *  Name                 :  Rte_ReadADC
 *  Description          :  Read  function
 *  Parameters           :  uint8 idxChanUB - ADC Channel index
 *  Return               :  uint16 :  ADC Channel value
 *  Critical/explanation :  NONE
 **************************************************************/
uint16 Rte_ReadADC(uint8 idxChanUB)
{
    uint16 retval=0;
    retval = ATDDrv_GetChanResult(idxChanUB);
    return retval;
}

/**************************************************************
 *  Name                 :  Rte_WriteIO
 *  Description          :  Write IO function
 *  Parameters           :  uint8 idxChanUB - DO Channel index
 *                          uint8 bLvlUB - Digital Output Voltage Level,
 *                          0 - Low level, 1 - High level
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_WriteIO(uint8 idxChanUB, uint8 bLvlUB)
{
    //write for test purpose only!!
    DODrv_SetChanState(idxChanUB, bLvlUB);
}

/**************************************************************
 *  Name                 :  Rte_UpdateSignalStatus
 *  Description          :  Update all input and output signals
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_UpdateSignalStatus(void)
{
    //DI low-level read
	Rte_Com.DI_Status.Brake_SW = Rte_ReadIO(0);

    //read ADC Status and copy to internal struct low-level read!
	Rte_Com.ADC_Status.BrakePeddal_1 = Rte_ReadADC(0);

	Rte_WriteIO(0,0);






}

/**************************************************************
 *  Name                 :  Rte_init
 *  Description          :  Rte init function
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_init(void)
{
	CELCmgr_Init();
}

/**************************************************************
 *  Name                 :  Rte_Task_10ms
 *  Description          :  Rte cyclic task, period is 10ms
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_Task_10ms(void)
{
	Rte_UpdateSignalStatus();
}

/**************************************************************
 *  Name                 :  Rte_Task_20ms
 *  Description          :  Rte cyclic task, period is 20ms
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_Task_20ms(void)
{
	CELCmgr_CyclicTask();
}

/**************************************************************
 *  Name                 :  Rte_Task_100ms
 *  Description          :  Rte cyclic task, period is 100ms
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NONE
 **************************************************************/
void Rte_Task_100ms(void)
{

}

UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void);
UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void)
{
	return 1;
}

Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void);
Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void)
{
	return 1;
}

UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void);
UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void)
{
	return 1;
}

Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void);
Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void)
{
	return 1;
}

UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void);
UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void)
{
	return 1;
}

Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void);
Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void)
{
	return 1;
}

UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void);
UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void)
{
	return 1;
}

Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void);
Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void)
{
	return 1;
}

void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(UInt8 u);
void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(UInt8 u)
{
	Rte_Com.DO_Status.WarningLamp = u;
}

UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(void);
UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(void)
{
	UInt8 *p = NULL;
	//p = malloc(sizeof(UInt8));
	if(p!=NULL)
	{
		*p = 10;
	}
	return p;
}

void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(UInt16 u);
void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(UInt16 u)
{
	Rte_Com.DO_Status.WarningLamp = u;
}

UInt16* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(void);
UInt16* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(void)
{
	UInt16 *p = NULL;
	//p = malloc(sizeof(UInt16));
	if(p!=NULL)
	{
		*p = 10;
	}
	return p;
}

void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(UInt8 u);
void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(UInt8 u)
{
	Rte_Com.DO_Status.WarningLamp = u;
}

UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(void);
UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(void)
{
	UInt8 *p = NULL;
	//p = malloc(sizeof(UInt8));
	if(p!=NULL)
	{
		*p = 10;
	}
	return p;
}

void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(UInt8 u);
void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(UInt8 u)
{
	Rte_Com.DO_Status.WarningLamp = u;
}

UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(void);
UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(void)
{
	UInt8 *p = NULL;
	//p = malloc(sizeof(UInt8));
	if(p!=NULL)
	{
		*p = 10;
	}
	return p;
}
