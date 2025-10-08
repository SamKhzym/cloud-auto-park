/*
 * BMSCurrPowerLimCalc_private.h
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

#ifndef RTW_HEADER_BMSCurrPowerLimCalc_private_h_
#define RTW_HEADER_BMSCurrPowerLimCalc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "BMSCurrPowerLimCalc_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_EYGa4XB6ekUg[3];
extern const real32_T rtCP_pooled_6Wcb3g0AZTnK[3];
extern const real32_T rtCP_pooled_12O7UBw07U5F[4];
extern const real32_T rtCP_pooled_Xj1JCoFUhnkj[4];
extern const real32_T rtCP_pooled_J5sdRJeqZiBS[7];
extern const real32_T rtCP_pooled_e0wIDjZt6Urv[7];
extern const real32_T rtCP_pooled_3W24v0lXToU2[7];
extern const real32_T rtCP_pooled_s5rUphJfji0l[7];
extern const real32_T rtCP_pooled_anuF7lKpzdk3[5];
extern const real32_T rtCP_pooled_WuWO42JhBkWO[5];
extern const real32_T rtCP_pooled_vCR3z8dNZaqv[4];
extern const real32_T rtCP_pooled_LMtXYP9Wax70[4];

#define rtCP_MinCellVoltDchrgCurrentLim_tableData rtCP_pooled_EYGa4XB6ekUg/* Expression: MinCellVoltDchrgCurrentLimTable.Table
                                                                      * Referenced by: '<S3>/MinCellVoltDchrgCurrentLim'
                                                                      */
#define rtCP_MinCellVoltDchrgCurrentLim_bp01Data rtCP_pooled_6Wcb3g0AZTnK/* Expression: MinCellVoltDchrgCurrentLimTable.Breakpoints(0)
                                                                      * Referenced by: '<S3>/MinCellVoltDchrgCurrentLim'
                                                                      */
#define rtCP_HighTempDchrgCurrentLim_tableData rtCP_pooled_12O7UBw07U5F/* Expression: single([1, 0.5, 0.3, 0])
                                                                      * Referenced by: '<S3>/HighTempDchrgCurrentLim'
                                                                      */
#define rtCP_HighTempDchrgCurrentLim_bp01Data rtCP_pooled_Xj1JCoFUhnkj/* Expression: single([40, 45, 50, 60])
                                                                      * Referenced by: '<S3>/HighTempDchrgCurrentLim'
                                                                      */
#define rtCP_LowTempDchrgCurrentLim_tableData rtCP_pooled_J5sdRJeqZiBS/* Expression: single([0,  0.2, 0.3, 0.5, 0.75, 1, 1])
                                                                      * Referenced by: '<S3>/LowTempDchrgCurrentLim'
                                                                      */
#define rtCP_LowTempDchrgCurrentLim_bp01Data rtCP_pooled_e0wIDjZt6Urv/* Expression: single([-10, -5,    0,   5, 10, 15, 20])
                                                                      * Referenced by: '<S3>/LowTempDchrgCurrentLim'
                                                                      */
#define rtCP_LowTempChrgCurrentLim_tableData rtCP_pooled_3W24v0lXToU2/* Expression: single([0.1 0.2  0.3 0.3 0.5 1.0 1.0])
                                                                      * Referenced by: '<S2>/LowTempChrgCurrentLim'
                                                                      */
#define rtCP_LowTempChrgCurrentLim_bp01Data rtCP_pooled_s5rUphJfji0l/* Expression: single([-15 -10 -5.0 0.0 5.0 10 15.0])
                                                                     * Referenced by: '<S2>/LowTempChrgCurrentLim'
                                                                     */
#define rtCP_HighTempChrgCurrentLim_tableData rtCP_pooled_anuF7lKpzdk3/* Expression: single([1.0 0.8 0.5 0.3 0])
                                                                      * Referenced by: '<S2>/HighTempChrgCurrentLim'
                                                                      */
#define rtCP_HighTempChrgCurrentLim_bp01Data rtCP_pooled_WuWO42JhBkWO/* Expression: single([40  45  50  55 60])
                                                                      * Referenced by: '<S2>/HighTempChrgCurrentLim'
                                                                      */
#define rtCP_MaxCellVoltChrgCurrentLim_tableData rtCP_pooled_vCR3z8dNZaqv/* Expression: single([1.0 0.8 0.3  0.3])
                                                                      * Referenced by: '<S2>/MaxCellVoltChrgCurrentLim'
                                                                      */
#define rtCP_MaxCellVoltChrgCurrentLim_bp01Data rtCP_pooled_LMtXYP9Wax70/* Expression: single([3.9 4.0 4.15 4.2])
                                                                      * Referenced by: '<S2>/MaxCellVoltChrgCurrentLim'
                                                                      */
#endif                           /* RTW_HEADER_BMSCurrPowerLimCalc_private_h_ */
