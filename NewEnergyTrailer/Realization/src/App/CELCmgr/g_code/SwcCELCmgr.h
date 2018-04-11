/*
 * File: SwcCELCmgr.h
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

#ifndef RTW_HEADER_SwcCELCmgr_h_
#define RTW_HEADER_SwcCELCmgr_h_
#ifndef SwcCELCmgr_COMMON_INCLUDES_
# define SwcCELCmgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SwcCELCmgr.h"
#endif                                 /* SwcCELCmgr_COMMON_INCLUDES_ */

#include "SwcCELCmgr_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct tag_B_SwcCELCmgr_T {
  uint16 out_EgyCnsAllwdForClima;      /* '<S2>/CELC_Logic' */
  uint8 out_EgyLvlChk;                 /* '<S2>/CELC_Logic' */
  uint8 out_SysCmd;                    /* '<S2>/CELC_Logic' */
  uint8 out_EgyLoadFctReq;             /* '<S2>/CELC_Logic' */
  uint8 out_CELCmgr_TclimaCnt;         /* '<S2>/CELC_Logic' */
} B_SwcCELCmgr_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct tag_DW_SwcCELCmgr_T {
  struct {
    uint_T is_c21_CELCmgrLogicLib:3;   /* '<S2>/CELC_Logic' */
    uint_T is_active_c21_CELCmgrLogicLib:1;/* '<S2>/CELC_Logic' */
  } bitsForTID0;

  uint16 temporalCounter_i1;           /* '<S2>/CELC_Logic' */
} DW_SwcCELCmgr_T;

/* Block signals (auto storage) */
extern VAR(B_SwcCELCmgr_T, SwcCELCmgr_VAR) SwcCELCmgr_B;

/* Block states (auto storage) */
extern VAR(DW_SwcCELCmgr_T, SwcCELCmgr_VAR) SwcCELCmgr_DW;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SwcCELCmgr'
 * '<S1>'   : 'SwcCELCmgr/SwcCELCmgr'
 * '<S2>'   : 'SwcCELCmgr/SwcCELCmgr/CyclicTask'
 * '<S3>'   : 'SwcCELCmgr/SwcCELCmgr/Init'
 * '<S4>'   : 'SwcCELCmgr/SwcCELCmgr/CyclicTask/CELC_Logic'
 */

/*-
 * Requirements for '<Root>': SwcCELCmgr
 */
#endif                                 /* RTW_HEADER_SwcCELCmgr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
