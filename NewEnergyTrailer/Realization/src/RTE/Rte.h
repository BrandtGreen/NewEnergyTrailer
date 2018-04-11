/*============================================================================*/
/*                            CIDI SOFTWARE                                   */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
  * $Source: Rte.h $
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
#ifndef RTE_H
#define RTE_H

/* Include Data type definition */
#include "Std_Types.h"

#include "HardwareLib.h"

//SwcCELCmgr
#include "Rte_SwcCELCmgr.h"

/* External variables declare  */
extern struct Rte_common_s Rte_Com;

/* External Functions declare  */
extern void Rte_init(void);
extern void Rte_Task_10ms(void);
extern void Rte_Task_20ms(void);
extern void Rte_Task_100ms(void)
;

/* External RTE interface */
extern UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void);
extern Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts(void);
extern UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void);
extern Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn(void);
extern UInt16 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void);
extern Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes(void);
extern UInt8 Rte_IRead_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void);
extern Std_ReturnType Rte_IStatus_SwcCELCmgr_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod(void);
extern void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(UInt8 u);
extern UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(void);
extern void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(UInt16 u);
extern UInt16* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima(void);
extern void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(UInt8 u);
extern UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(void);
extern void Rte_IWrite_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(UInt8 u);
extern UInt8* Rte_IWriteRef_SwcCELCmgr_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq(void);


/* Structure type definition */

// Digital Input
struct Rte_DI_Status_s
{
	uint8 CC2:1;
	uint8 Brake_SW:1;
};

//Analog Input
struct Rte_AI_Status_s
{
	uint16 BrakePeddal_1;
	uint16 Throttle_1;
};

//Digital Outputs
struct Rte_DO_Status_s
{
	uint8 PreChargeContactor:1;
	uint8 WarningLamp:1;
};

//PWM Output
struct Rte_PWMO_Status_s
{
	uint16 ElecFan;
	uint16 WaterPump;
};

//Common signals
struct Rte_common_s
{
	struct Rte_DI_Status_s DI_Status;
	struct Rte_AI_Status_s ADC_Status;
	struct Rte_DO_Status_s DO_Status;
	struct Rte_PWMO_Status_s PWMO_Status;
};


/* Functions Definition */
void Rte_WriteIO(uint8 idxChanUB, uint8 bLvlUB);
void Rte_UpdateIOStatus(void);
void Rte_init(void);
void Rte_Task_10ms(void);
void Rte_Task_20ms(void);
void Rte_Task_100ms(void);

uint8 Rte_ReadIO(uint8 ID);
uint16 Rte_ReadADC(uint8 idxChanUB);


#endif //RTE_H

