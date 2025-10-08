/*
 * ConfiguredVirtualVehicleModel.cpp
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "ConfiguredVirtualVehicleModel".
 *
 * Model version              : 6.83
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Wed Oct  8 00:11:54 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ConfiguredVirtualVehicleModel.h"
#include <cmath>
#include "rtwtypes.h"
#include "ConfiguredVirtualVehicleModel_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

static void rate_scheduler(RT_MODEL_ConfiguredVirtualVeh_T *const
  ConfiguredVirtualVehicleMode_M);
real32_T look1_iflf_binlcpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    real_T yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], const uint32_T maxIndex[],
                      uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T y;
  real_T yL_0d0;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL_ConfiguredVirtualVeh_T *const
  ConfiguredVirtualVehicleMode_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[2])++;
  if ((ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[3])++;
  if ((ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.1s, 0.0s] */
    ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[3] = 0;
  }

  (ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[4])++;
  if ((ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[4]) > 49999) {/* Sample time: [5.0s, 0.0s] */
    ConfiguredVirtualVehicleMode_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k{ p[i] };

    real_T lb{ r[j++] };

    real_T xk{ x[k]-lb };

    real_T rk{ r[j]-lb };

    int_T q{ (int_T) std::floor(xk/rk) };

    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void ConfiguredVirtualVehicleModel::rt_ertODEUpdateContinuousStates
  (RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 118 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ConfiguredVirtualVehicleModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  ConfiguredVirtualVehicleModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  ConfiguredVirtualVehicleModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       3,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ConfiguredVirtualVehicleModel::step()
{
  real_T rtb_DataTypeConversion[2];
  real_T UnitConversion5_tmp;
  int32_T i;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M))) {
    /* set solver stop time */
    if (!((&ConfiguredVirtualVehicleMode_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                            (((&ConfiguredVirtualVehicleMode_M)
        ->Timing.clockTickH0 + 1) * (&ConfiguredVirtualVehicleMode_M)
        ->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                            (((&ConfiguredVirtualVehicleMode_M)
        ->Timing.clockTick0 + 1) * (&ConfiguredVirtualVehicleMode_M)
        ->Timing.stepSize0 + (&ConfiguredVirtualVehicleMode_M)
        ->Timing.clockTickH0 * (&ConfiguredVirtualVehicleMode_M)
        ->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&ConfiguredVirtualVehicleMode_M))) {
    (&ConfiguredVirtualVehicleMode_M)->Timing.t[0] = rtsiGetT
      (&(&ConfiguredVirtualVehicleMode_M)->solverInfo);
  }

  /* Outputs for Atomic SubSystem: '<Root>/AdasPlantModel' */
  /* Inport: '<Root>/DriverSteerCmd' incorporates:
   *  Inport: '<Root>/AdasEnable'
   *  Inport: '<Root>/AdasGearCmd'
   *  Inport: '<Root>/AdasLongTrq'
   *  Inport: '<Root>/AdasSteerCmd'
   *  Inport: '<Root>/DriverAccelCmd'
   *  Inport: '<Root>/DriverBrakeCmd'
   *  Inport: '<Root>/DriverGearCmd'
   */
  ConfiguredVirtua_AdasPlantModel(ConfiguredVirtualVehicleModel_U.DriverSteerCmd,
    ConfiguredVirtualVehicleModel_U.DriverAccelCmd,
    ConfiguredVirtualVehicleModel_U.DriverBrakeCmd,
    ConfiguredVirtualVehicleModel_U.DriverGearCmd,
    ConfiguredVirtualVehicleModel_U.AdasEnable,
    ConfiguredVirtualVehicleModel_U.AdasSteerCmd,
    ConfiguredVirtualVehicleModel_U.AdasLongTrq,
    ConfiguredVirtualVehicleModel_U.AdasGearCmd,
    ConfiguredVirtualVehicleModel_B.ImpAsg_InsertedFor_y_at_inport_,
    &ConfiguredVirtualVehicleModel_B.AdasPlantModel,
    &ConfiguredVirtualVehicleMode_DW.AdasPlantModel,
    &ConfiguredVirtualVehicleModel_P.AdasPlantModel,
    &ConfiguredVirtualVehicleModel_P,
    &ConfiguredVirtualVehicleModel_X.AdasPlantModel,
    &ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel);

  /* End of Outputs for SubSystem: '<Root>/AdasPlantModel' */

  /* RateTransition: '<S707>/Rate Transition1' incorporates:
   *  RateTransition: '<S707>/Rate Transition2'
   */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    if (ConfiguredVirtualVehicleMode_DW.RateTransition1_semaphoreTaken == 0) {
      ConfiguredVirtualVehicleMode_DW.RateTransition1_Buffer0[0] =
        ConfiguredVirtualVehicleModel_B.AdasPlantModel.Add_n[0];
      ConfiguredVirtualVehicleMode_DW.RateTransition1_Buffer0[1] =
        ConfiguredVirtualVehicleModel_B.AdasPlantModel.Add_n[1];
      ConfiguredVirtualVehicleMode_DW.RateTransition1_Buffer0[2] =
        ConfiguredVirtualVehicleModel_B.AdasPlantModel.Add_n[2];
    }

    if (ConfiguredVirtualVehicleMode_DW.RateTransition2_semaphoreTaken == 0) {
      ConfiguredVirtualVehicleMode_DW.RateTransition2_Buffer0[0] =
        ConfiguredVirtualVehicleModel_B.ImpAsg_InsertedFor_y_at_inport_[0];
      ConfiguredVirtualVehicleMode_DW.RateTransition2_Buffer0[1] =
        ConfiguredVirtualVehicleModel_B.ImpAsg_InsertedFor_y_at_inport_[1];
      ConfiguredVirtualVehicleMode_DW.RateTransition2_Buffer0[2] =
        ConfiguredVirtualVehicleModel_B.ImpAsg_InsertedFor_y_at_inport_[2];
    }
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition1_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition1_semaphoreTaken = 0;
  }

  /* End of RateTransition: '<S707>/Rate Transition1' */

  /* RateTransition: '<S707>/Rate Transition4' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (ConfiguredVirtualVehicleMode_DW.RateTransition4_semaphoreTaken == 0)) {
    ConfiguredVirtualVehicleMode_DW.RateTransition4_Buffer0[0] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.V_wb[0];
    ConfiguredVirtualVehicleMode_DW.RateTransition4_Buffer0[1] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.V_wb[1];
    ConfiguredVirtualVehicleMode_DW.RateTransition4_Buffer0[2] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.V_wb[2];
  }

  /* RateTransition: '<S707>/Rate Transition2' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition2_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition2_semaphoreTaken = 0;
  }

  /* RateTransition: '<S707>/Rate Transition5' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (ConfiguredVirtualVehicleMode_DW.RateTransition5_semaphoreTaken == 0)) {
    ConfiguredVirtualVehicleMode_DW.RateTransition5_Buffer0[0] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.Switch;
    ConfiguredVirtualVehicleMode_DW.RateTransition5_Buffer0[1] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.Switch1;
    ConfiguredVirtualVehicleMode_DW.RateTransition5_Buffer0[2] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.RL;
    ConfiguredVirtualVehicleMode_DW.RateTransition5_Buffer0[3] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.RR;
  }

  /* RateTransition: '<S707>/Rate Transition4' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition4_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition4_semaphoreTaken = 0;
  }

  /* RateTransition: '<S707>/Rate Transition3' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (ConfiguredVirtualVehicleMode_DW.RateTransition3_semaphoreTaken == 0)) {
    ConfiguredVirtualVehicleMode_DW.RateTransition3_Buffer0[0] = 0.0;
    ConfiguredVirtualVehicleMode_DW.RateTransition3_Buffer0[1] = 0.0;
    ConfiguredVirtualVehicleMode_DW.RateTransition3_Buffer0[2] = 0.0;
  }

  /* RateTransition: '<S707>/Rate Transition5' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition5_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition5_semaphoreTaken = 0;
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S707>/Data Type Conversion' */
    rtb_DataTypeConversion[0] = 0.0;
    rtb_DataTypeConversion[1] =
      ConfiguredVirtualVehicleModel_B.AdasPlantModel.TransGear;

    /* RateTransition: '<S707>/Rate Transition6' incorporates:
     *  DataTypeConversion: '<S707>/Data Type Conversion'
     */
    if (ConfiguredVirtualVehicleMode_DW.RateTransition6_semaphoreTaken == 0) {
      ConfiguredVirtualVehicleMode_DW.RateTransition6_Buffer0[0] =
        rtb_DataTypeConversion[0];
      ConfiguredVirtualVehicleMode_DW.RateTransition6_Buffer0[1] =
        rtb_DataTypeConversion[1];
    }
  }

  /* RateTransition: '<S707>/Rate Transition3' incorporates:
   *  RateTransition: '<S707>/Rate Transition6'
   */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition3_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition3_semaphoreTaken = 0;
    ConfiguredVirtualVehicleMode_DW.RateTransition6_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition6_semaphoreTaken = 0;
  }

  /* Concatenate: '<S707>/Vector Concatenate' incorporates:
   *  Integrator: '<S517>/Integrator'
   *  Integrator: '<S518>/Integrator'
   */
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[0] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator[0];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[2] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator[1];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[4] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator[2];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[6] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator[3];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[1] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator_h[0];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[3] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator_h[1];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[5] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator_h[2];
  ConfiguredVirtualVehicleModel_B.VectorConcatenate[7] =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Integrator_h[3];

  /* RateTransition: '<S707>/Rate Transition7' incorporates:
   *  Concatenate: '<S707>/Vector Concatenate'
   */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (ConfiguredVirtualVehicleMode_DW.RateTransition7_semaphoreTaken == 0)) {
    for (i = 0; i < 8; i++) {
      ConfiguredVirtualVehicleMode_DW.RateTransition7_Buffer0[i] =
        ConfiguredVirtualVehicleModel_B.VectorConcatenate[i];
    }
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    ConfiguredVirtualVehicleMode_DW.RateTransition7_semaphoreTaken = 1;
    ConfiguredVirtualVehicleMode_DW.RateTransition7_semaphoreTaken = 0;
  }

  /* End of RateTransition: '<S707>/Rate Transition7' */

  /* UnitConversion: '<S699>/Unit Conversion5' incorporates:
   *  UnitConversion: '<S2>/Unit Conversion6'
   *  UnitConversion: '<S701>/Unit Conversion5'
   */
  /* Unit Conversion - from: m/s to: mph
     Expression: output = (2.23694*input) + (0) */
  /* Unit Conversion - from: mph to: m/s
     Expression: output = (0.44704*input) + (0) */
  UnitConversion5_tmp = 2.236936292054402 *
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.UnitConversion[0] *
    0.44704000000000005;

  /* UnitConversion: '<S699>/Unit Conversion5' */
  ConfiguredVirtualVehicleModel_B.UnitConversion5 = UnitConversion5_tmp;

  /* Sqrt: '<S701>/Sqrt' incorporates:
   *  Product: '<S701>/Product'
   */
  /* Unit Conversion - from: mph to: m/s
     Expression: output = (0.44704*input) + (0) */
  ConfiguredVirtualVehicleModel_B.Sqrt = std::sqrt(UnitConversion5_tmp *
    UnitConversion5_tmp);

  /* Sum: '<S701>/Add' incorporates:
   *  Constant: '<S701>/US EPA kwh//USgal equivalent'
   *  Constant: '<S701>/s per h'
   *  Constant: '<S701>/w per kw'
   *  Gain: '<S701>/m^3 per gal'
   *  Product: '<S701>/Divide'
   *  Product: '<S701>/Divide1'
   *  Product: '<S701>/Divide2'
   */
  ConfiguredVirtualVehicleModel_B.Add =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.BattPwr /
    ConfiguredVirtualVehicleModel_P.wperkw_Value /
    ConfiguredVirtualVehicleModel_P.USEPAkwhUSgalequivalent_Value /
    ConfiguredVirtualVehicleModel_P.sperh_Value *
    ConfiguredVirtualVehicleModel_P.m3pergal_Gain +
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.Product2_o;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M))) {
    /* Update for Atomic SubSystem: '<Root>/AdasPlantModel' */
    Configure_AdasPlantModel_Update
      (&ConfiguredVirtualVehicleModel_B.AdasPlantModel,
       &ConfiguredVirtualVehicleMode_DW.AdasPlantModel,
       &ConfiguredVirtualVehicleModel_P.AdasPlantModel);

    /* End of Update for SubSystem: '<Root>/AdasPlantModel' */

    /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M))) {
      if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&ConfiguredVirtualVehicleMode_M)->solverInfo)) {
        rtsiSetSimTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                           MINOR_TIME_STEP);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, false);
        ConfiguredVirtualVehicleModel::step();
        rtsiSetSimTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                           MAJOR_TIME_STEP);
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M))) {
    rt_ertODEUpdateContinuousStates(&(&ConfiguredVirtualVehicleMode_M)
      ->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&ConfiguredVirtualVehicleMode_M)->Timing.clockTick0)) {
      ++(&ConfiguredVirtualVehicleMode_M)->Timing.clockTickH0;
    }

    (&ConfiguredVirtualVehicleMode_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&ConfiguredVirtualVehicleMode_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&ConfiguredVirtualVehicleMode_M)->Timing.clockTick1++;
      if (!(&ConfiguredVirtualVehicleMode_M)->Timing.clockTick1) {
        (&ConfiguredVirtualVehicleMode_M)->Timing.clockTickH1++;
      }
    }

    rate_scheduler((&ConfiguredVirtualVehicleMode_M));
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleModel_derivatives()
{
  XDot_ConfiguredVirtualVehicle_T *_rtXdot;
  _rtXdot = ((XDot_ConfiguredVirtualVehicle_T *)
             (&ConfiguredVirtualVehicleMode_M)->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/AdasPlantModel' */
  Configured_AdasPlantModel_Deriv
    (&ConfiguredVirtualVehicleModel_B.AdasPlantModel,
     &ConfiguredVirtualVehicleMode_DW.AdasPlantModel,
     &ConfiguredVirtualVehicleModel_P.AdasPlantModel,
     &ConfiguredVirtualVehicleModel_P,
     &ConfiguredVirtualVehicleModel_X.AdasPlantModel, &_rtXdot->AdasPlantModel);

  /* End of Derivatives for SubSystem: '<Root>/AdasPlantModel' */

  /* Derivatives for Integrator: '<S699>/Integrator' */
  _rtXdot->Integrator_CSTATE = ConfiguredVirtualVehicleModel_B.UnitConversion5;

  /* Derivatives for Integrator: '<S699>/Integrator1' */
  _rtXdot->Integrator1_CSTATE =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.TPHC;

  /* Derivatives for Integrator: '<S699>/Integrator2' */
  _rtXdot->Integrator2_CSTATE =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.TPCO;

  /* Derivatives for Integrator: '<S699>/Integrator3' */
  _rtXdot->Integrator3_CSTATE =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.TPNOx;

  /* Derivatives for Integrator: '<S699>/Integrator4' */
  _rtXdot->Integrator4_CSTATE =
    ConfiguredVirtualVehicleModel_B.AdasPlantModel.TPCO2;

  /* Derivatives for Integrator: '<S701>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = ConfiguredVirtualVehicleModel_B.Sqrt;

  /* Derivatives for Integrator: '<S701>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = ConfiguredVirtualVehicleModel_B.Add;
}

/* Model initialize function */
void ConfiguredVirtualVehicleModel::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_LowerSat =
    rtMinusInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_d = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Negative5_UpperSat = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.FirstOrderHold_ErrTol = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.DeadZone_Start = rtMinusInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_e = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_i = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_do = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.DisallowNegativeBrakeTorque_Upp
    = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation1_UpperSat = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_n = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation1_UpperSat_e = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_o = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation1_UpperSat_i = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_m = rtInf;
  ConfiguredVirtualVehicleModel_P.AdasPlantModel.Saturation_UpperSat_h = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                          &(&ConfiguredVirtualVehicleMode_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo, &rtmGetTPtr
                ((&ConfiguredVirtualVehicleMode_M)));
    rtsiSetStepSizePtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                       &(&ConfiguredVirtualVehicleMode_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                 &(&ConfiguredVirtualVehicleMode_M)->derivs);
    rtsiSetContStatesPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo, (real_T
      **) &(&ConfiguredVirtualVehicleMode_M)->contStates);
    rtsiSetNumContStatesPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
      &(&ConfiguredVirtualVehicleMode_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&ConfiguredVirtualVehicleMode_M)
      ->solverInfo, &(&ConfiguredVirtualVehicleMode_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&ConfiguredVirtualVehicleMode_M)
      ->solverInfo, &(&ConfiguredVirtualVehicleMode_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&ConfiguredVirtualVehicleMode_M)
      ->solverInfo, &(&ConfiguredVirtualVehicleMode_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                          (&rtmGetErrorStatus((&ConfiguredVirtualVehicleMode_M))));
    rtsiSetRTModelPtr(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                      (&ConfiguredVirtualVehicleMode_M));
  }

  rtsiSetSimTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,
                     MAJOR_TIME_STEP);
  (&ConfiguredVirtualVehicleMode_M)->intgData.y =
    (&ConfiguredVirtualVehicleMode_M)->odeY;
  (&ConfiguredVirtualVehicleMode_M)->intgData.f[0] =
    (&ConfiguredVirtualVehicleMode_M)->odeF[0];
  (&ConfiguredVirtualVehicleMode_M)->intgData.f[1] =
    (&ConfiguredVirtualVehicleMode_M)->odeF[1];
  (&ConfiguredVirtualVehicleMode_M)->intgData.f[2] =
    (&ConfiguredVirtualVehicleMode_M)->odeF[2];
  (&ConfiguredVirtualVehicleMode_M)->contStates =
    ((X_ConfiguredVirtualVehicleMod_T *) &ConfiguredVirtualVehicleModel_X);
  (&ConfiguredVirtualVehicleMode_M)->periodicContStateIndices = ((int_T*)
    ConfiguredVirtualV_PeriodicIndX);
  (&ConfiguredVirtualVehicleMode_M)->periodicContStateRanges = ((real_T*)
    ConfiguredVirtualV_PeriodicRngX);
  rtsiSetSolverData(&(&ConfiguredVirtualVehicleMode_M)->solverInfo, static_cast<
                    void *>(&(&ConfiguredVirtualVehicleMode_M)->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&(&ConfiguredVirtualVehicleMode_M)
    ->solverInfo, false);
  rtsiSetSolverName(&(&ConfiguredVirtualVehicleMode_M)->solverInfo,"ode3");
  rtmSetTPtr((&ConfiguredVirtualVehicleMode_M),
             &(&ConfiguredVirtualVehicleMode_M)->Timing.tArray[0]);
  (&ConfiguredVirtualVehicleMode_M)->Timing.stepSize0 = 0.0001;
  rtmSetFirstInitCond((&ConfiguredVirtualVehicleMode_M), 1);
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE_j =
    UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE_d =
    UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.TriggeredSubsystem_l.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.TriggeredSubsystem_e.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.TriggeredSubsystem_k.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel.TriggeredSubsystem.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S699>/Integrator' */
  ConfiguredVirtualVehicleModel_X.Integrator_CSTATE =
    ConfiguredVirtualVehicleModel_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S699>/Integrator1' */
  ConfiguredVirtualVehicleModel_X.Integrator1_CSTATE =
    ConfiguredVirtualVehicleModel_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S699>/Integrator2' */
  ConfiguredVirtualVehicleModel_X.Integrator2_CSTATE =
    ConfiguredVirtualVehicleModel_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S699>/Integrator3' */
  ConfiguredVirtualVehicleModel_X.Integrator3_CSTATE =
    ConfiguredVirtualVehicleModel_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S699>/Integrator4' */
  ConfiguredVirtualVehicleModel_X.Integrator4_CSTATE =
    ConfiguredVirtualVehicleModel_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S701>/Integrator' */
  ConfiguredVirtualVehicleModel_X.Integrator_CSTATE_b =
    ConfiguredVirtualVehicleModel_P.Integrator_IC_m;

  /* InitializeConditions for Integrator: '<S701>/Integrator1' */
  ConfiguredVirtualVehicleModel_X.Integrator1_CSTATE_p =
    ConfiguredVirtualVehicleModel_P.Integrator1_IC_o;

  /* SystemInitialize for Atomic SubSystem: '<Root>/AdasPlantModel' */
  ConfiguredV_AdasPlantModel_Init
    (&ConfiguredVirtualVehicleModel_B.AdasPlantModel,
     &ConfiguredVirtualVehicleMode_DW.AdasPlantModel,
     &ConfiguredVirtualVehicleModel_P.AdasPlantModel,
     &ConfiguredVirtualVehicleModel_P,
     &ConfiguredVirtualVehicleModel_X.AdasPlantModel,
     &ConfiguredVirtualVehicl_PrevZCX.AdasPlantModel);

  /* End of SystemInitialize for SubSystem: '<Root>/AdasPlantModel' */

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[3]{ 62, 63, 64 };

    real_T rootPeriodicContStateRanges[6]{ -3.1415926535897931,
      3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
      -3.1415926535897931, 3.1415926535897931 };

    (void) std::memcpy((void*)ConfiguredVirtualV_PeriodicIndX,
                       rootPeriodicContStateIndices,
                       3*sizeof(int_T));
    (void) std::memcpy((void*)ConfiguredVirtualV_PeriodicRngX,
                       rootPeriodicContStateRanges,
                       6*sizeof(real_T));
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond((&ConfiguredVirtualVehicleMode_M))) {
    rtmSetFirstInitCond((&ConfiguredVirtualVehicleMode_M), 0);
  }
}

/* Model terminate function */
void ConfiguredVirtualVehicleModel::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleModel() :
  ConfiguredVirtualVehicleModel_U(),
  ConfiguredVirtualVehicleModel_B(),
  ConfiguredVirtualVehicleMode_DW(),
  ConfiguredVirtualVehicleModel_X(),
  ConfiguredVirtualVehicl_PrevZCX(),
  ConfiguredVirtualVehicleMode_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
ConfiguredVirtualVehicleModel::~ConfiguredVirtualVehicleModel() = default;

/* Real-Time Model get method */
RT_MODEL_ConfiguredVirtualVeh_T * ConfiguredVirtualVehicleModel::getRTM()
{
  return (&ConfiguredVirtualVehicleMode_M);
}
