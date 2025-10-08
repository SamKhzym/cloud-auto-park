/*
 * BMSCurrPowerLimCalc_types.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "BMSCurrPowerLimCalc".
 *
 * Model version              : 6.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:27:52 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BMSCurrPowerLimCalc_types_h_
#define RTW_HEADER_BMSCurrPowerLimCalc_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_MinCellVoltDchrgCurrentLimTable_
#define DEFINED_TYPEDEF_FOR_MinCellVoltDchrgCurrentLimTable_

struct MinCellVoltDchrgCurrentLimTable
{
  real32_T MinCellVoltage[3];
  real32_T DischargeCurrentRate[3];
};

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_BMSCurrPowerLimCalc_T RT_MODEL_BMSCurrPowerLimCalc_T;

#endif                             /* RTW_HEADER_BMSCurrPowerLimCalc_types_h_ */
