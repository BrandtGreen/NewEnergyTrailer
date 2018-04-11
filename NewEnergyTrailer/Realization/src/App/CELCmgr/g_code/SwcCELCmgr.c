/*
 * File: SwcCELCmgr.c
 *
 * Code generated for Simulink model 'SwcCELCmgr'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Apr 10 09:26:53 2018
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SwcCELCmgr.h"
#include "SwcCELCmgr_private.h"

/* Named constants for Chart: '<S2>/CELC_Logic' */
#define SwcCELCmg_IN_CELC_ACTV_USG_MODE ((uint8)3U)
#define SwcCELCmgr_IN_CELC_ACTUATOR_OFF ((uint8)1U)
#define SwcCELCmgr_IN_CELC_ACTUATOR_ON ((uint8)2U)
#define SwcCELCmgr_IN_CELC_EGY_CHECK   ((uint8)4U)
#define SwcCELCmgr_IN_CELC_SYS_EGY_CALC ((uint8)5U)

/* Exported data definition */

/* Definition for custom storage class: Default */
VAR(uint8, SwcCELCmgr_VAR) CELCmgr_EgyClimaAllwdFac = 80U;
VAR(uint8, SwcCELCmgr_VAR) CELCmgr_EgyCnsAllwdForClimaMax = 127U;
VAR(uint16, SwcCELCmgr_VAR) CELCmgr_TEgyChkTime_5min = 30000U;
VAR(uint8, SwcCELCmgr_VAR) CELCmgr_TclimaMax = 12U;

/* Block signals (auto storage) */
VAR(B_SwcCELCmgr_T, SwcCELCmgr_VAR) SwcCELCmgr_B;

/* Block states (auto storage) */
VAR(DW_SwcCELCmgr_T, SwcCELCmgr_VAR) SwcCELCmgr_DW;

/* Forward declaration for local functions */
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

static void SwcCELCmgr_InactiveUsageMode(void);

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

static void SwcCELCmgr_SystemEgyCalc(void);

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

/* Function for Chart: '<S2>/CELC_Logic' */
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

static void SwcCELCmgr_InactiveUsageMode(void)
{
  /* Graphical Function 'InactiveUsageMode': '<S4>:144' */
  /* Transition: '<S4>:200' */
  SwcCELCmgr_B.out_CELCmgr_TclimaCnt = 0U;

  /* Stop actuator work */
  SwcCELCmgr_B.out_SysCmd = 0U;

  /* Stop energy level check */
  SwcCELCmgr_B.out_EgyLvlChk = 0U;

  /* Climate finished working */
  if (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts() != 0) {
    /* Transition: '<S4>:131' */
    /* Transition: '<S4>:147' */
    /* Inactive energy load usage mode */
    SwcCELCmgr_B.out_EgyLoadFctReq = 0U;
  }
}

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

/* Function for Chart: '<S2>/CELC_Logic' */
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

static void SwcCELCmgr_SystemEgyCalc(void)
{
  int32_T tmp;

  /* Graphical Function 'SystemEgyCalc': '<S4>:171' */
  /* Transition: '<S4>:170' */
  tmp = Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn() * 12 *
    CELCmgr_EgyClimaAllwdFac;
  if (tmp > 65535) {
    tmp = 65535;
  }

  SwcCELCmgr_B.out_EgyCnsAllwdForClima = (uint16)tmp;
  if (SwcCELCmgr_B.out_EgyCnsAllwdForClima > CELCmgr_EgyCnsAllwdForClimaMax) {
    /* Transition: '<S4>:169' */
    /* Transition: '<S4>:172' */
    SwcCELCmgr_B.out_EgyCnsAllwdForClima = CELCmgr_EgyCnsAllwdForClimaMax;
  }
}

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

/* Model step function */
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

FUNC(void, SwcCELCmgr_CODE) CELCmgr_CyclicTask(void)
{
  int32_T tmp;

  /* S-Function (fcncallgen): '<Root>/Function Call Trigger Source' incorporates:
   *  SubSystem: '<S1>/CyclicTask'
   *
   * Block description for '<S1>/CyclicTask':
   *  Centralized energy load control function period task,T=10ms
   */
  /* Chart: '<S2>/CELC_Logic' incorporates:
   *  Inport: '<Root>/ip_CELCmgr_ClimaSts'
   *  Inport: '<Root>/ip_CELCmgr_EgyAvlToWarn'
   *  Inport: '<Root>/ip_CELCmgr_EgyClimaDes'
   *  Inport: '<Root>/ip_CELCmgr_UsageMod'
   */
  /* Gateway: CELC */
  if (SwcCELCmgr_DW.temporalCounter_i1 < 65535U) {
    SwcCELCmgr_DW.temporalCounter_i1++;
  }

  /* During: CELC */
  if (SwcCELCmgr_DW.bitsForTID0.is_active_c21_CELCmgrLogicLib == 0U) {
    /* Entry: CELC */
    SwcCELCmgr_DW.bitsForTID0.is_active_c21_CELCmgrLogicLib = 1U;

    /* Entry Internal: CELC */
    /* Transition: '<S4>:46' */
    SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
      SwcCELCmgr_IN_CELC_ACTUATOR_OFF;

    /* Entry 'CELC_ACTUATOR_OFF': '<S4>:161' */
    SwcCELCmgr_InactiveUsageMode();
  } else {
    switch (SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib) {
     case SwcCELCmgr_IN_CELC_ACTUATOR_OFF:
      /* During 'CELC_ACTUATOR_OFF': '<S4>:161' */
      /* REQPROD_216018
         Usage mode is  abandoned and reveive energy consumption request */
      if ((Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod() == 0) &&
          (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes() > 0))
      {
        /* Transition: '<S4>:95' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmgr_IN_CELC_EGY_CHECK;

        /* Entry 'CELC_EGY_CHECK': '<S4>:11' */
        tmp = SwcCELCmgr_B.out_CELCmgr_TclimaCnt + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SwcCELCmgr_B.out_CELCmgr_TclimaCnt = (uint8)tmp;
        SwcCELCmgr_B.out_EgyLvlChk = 1U;
      } else {
        SwcCELCmgr_InactiveUsageMode();
      }
      break;

     case SwcCELCmgr_IN_CELC_ACTUATOR_ON:
      /* During 'CELC_ACTUATOR_ON': '<S4>:69' */
      /* REQPROD_216018
         Send check engergy level request every 5min  */
      if (SwcCELCmgr_DW.temporalCounter_i1 >= CELCmgr_TEgyChkTime_5min) {
        /* Transition: '<S4>:98' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmgr_IN_CELC_EGY_CHECK;

        /* Entry 'CELC_EGY_CHECK': '<S4>:11' */
        tmp = SwcCELCmgr_B.out_CELCmgr_TclimaCnt + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SwcCELCmgr_B.out_CELCmgr_TclimaCnt = (uint8)tmp;
        SwcCELCmgr_B.out_EgyLvlChk = 1U;
      } else {
        /* REQPROD_216020
           Usage mode is abandoned or no energy consuption request
           or clima worked more than 60min */
        if ((Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod() == 0) ||
            (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrEgyClimaDes_EgyClimaDes() ==
             0) || (SwcCELCmgr_B.out_CELCmgr_TclimaCnt >= CELCmgr_TclimaMax + 1))
        {
          /* Transition: '<S4>:191' */
          /* Transition: '<S4>:192' */
          SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
            SwcCELCmgr_IN_CELC_ACTUATOR_OFF;

          /* Entry 'CELC_ACTUATOR_OFF': '<S4>:161' */
          SwcCELCmgr_InactiveUsageMode();
        } else {
          /* Start actuator working */
          SwcCELCmgr_B.out_SysCmd = 1U;
        }
      }
      break;

     case SwcCELCmg_IN_CELC_ACTV_USG_MODE:
      /* During 'CELC_ACTV_USG_MODE': '<S4>:195' */
      /* Usage mode is not abandoned */
      if (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrUsageMod_UsageMod() != 0) {
        /* Transition: '<S4>:198' */
        /* Transition: '<S4>:189' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmgr_IN_CELC_ACTUATOR_ON;
        SwcCELCmgr_DW.temporalCounter_i1 = 0U;

        /* Entry 'CELC_ACTUATOR_ON': '<S4>:69' */
        /* Start actuator working */
        SwcCELCmgr_B.out_SysCmd = 1U;
      } else {
        /* Disable energy level check */
        SwcCELCmgr_B.out_EgyLvlChk = 0U;

        /* Active energy load usage mode */
        SwcCELCmgr_B.out_EgyLoadFctReq = 1U;
      }
      break;

     case SwcCELCmgr_IN_CELC_EGY_CHECK:
      /* During 'CELC_EGY_CHECK': '<S4>:11' */
      if (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrEgyAvltoWarn_EgyAvltoWarn() > 0)
      {
        /* Transition: '<S4>:96' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmgr_IN_CELC_SYS_EGY_CALC;

        /* Entry 'CELC_SYS_EGY_CALC': '<S4>:94' */
        /* REQPROD_216022 */
        SwcCELCmgr_SystemEgyCalc();
      } else {
        SwcCELCmgr_B.out_EgyLvlChk = 1U;
      }
      break;

     default:
      /* During 'CELC_SYS_EGY_CALC': '<S4>:94' */
      /* Climate allowed to work */
      if (Rte_IRead_CELCmgr_CyclicTask_rpCELCmgrClimaSts_ClimaSts() == 0) {
        /* Transition: '<S4>:187' */
        /* Transition: '<S4>:196' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmg_IN_CELC_ACTV_USG_MODE;

        /* Entry 'CELC_ACTV_USG_MODE': '<S4>:195' */
        /* Disable energy level check */
        SwcCELCmgr_B.out_EgyLvlChk = 0U;

        /* Active energy load usage mode */
        SwcCELCmgr_B.out_EgyLoadFctReq = 1U;
      } else {
        /* Transition: '<S4>:194' */
        /* Transition: '<S4>:184' */
        SwcCELCmgr_DW.bitsForTID0.is_c21_CELCmgrLogicLib =
          SwcCELCmgr_IN_CELC_ACTUATOR_OFF;

        /* Entry 'CELC_ACTUATOR_OFF': '<S4>:161' */
        SwcCELCmgr_InactiveUsageMode();
      }
      break;
    }
  }

  /* End of Chart: '<S2>/CELC_Logic' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function Call Trigger Source' */

  /* Outport: '<Root>/op_CELCmgr_EgyLvlChk' */
  Rte_IWrite_CELCmgr_CyclicTask_spEgyLvlChk_EgyLvlChk(SwcCELCmgr_B.out_EgyLvlChk);

  /* Outport: '<Root>/op_CELCmgr_EgyCnsAllwdForClima' */
  Rte_IWrite_CELCmgr_CyclicTask_spEgyCnsAllwdForClima_EgyCnsAllwdForClima
    (SwcCELCmgr_B.out_EgyCnsAllwdForClima);

  /* Outport: '<Root>/op_CELCmgr_EgySysCmd' */
  Rte_IWrite_CELCmgr_CyclicTask_spEgySysCmd_EgySysCmd(SwcCELCmgr_B.out_SysCmd);

  /* Outport: '<Root>/op_CELCmgr_EgyLoadFctReq' */
  Rte_IWrite_CELCmgr_CyclicTask_spEgyLoadFctReq_EgyLoadFctReq
    (SwcCELCmgr_B.out_EgyLoadFctReq);
}

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

/* Model initialize function */
#define SwcCELCmgr_START_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

FUNC(void, SwcCELCmgr_CODE) CELCmgr_Init(void)
{
  /* (no initialization code required) */
}

#define SwcCELCmgr_STOP_SEC_SwAddrMethod
#include "SwcCELCmgr_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
