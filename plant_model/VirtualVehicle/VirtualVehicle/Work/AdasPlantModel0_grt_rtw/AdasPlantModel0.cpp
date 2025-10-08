/*
 * AdasPlantModel0.cpp
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "AdasPlantModel0".
 *
 * Model version              : 6.83
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Wed Oct  8 00:15:24 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AdasPlantModel0.h"
#include "rtwtypes.h"
#include <cstring>
#include "AdasPlantModel0_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

static void rate_scheduler(RT_MODEL_AdasPlantModel0_T *const AdasPlantModel0_M);
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
static void rate_scheduler(RT_MODEL_AdasPlantModel0_T *const AdasPlantModel0_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AdasPlantModel0_M->Timing.TaskCounters.TID[2])++;
  if ((AdasPlantModel0_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    AdasPlantModel0_M->Timing.TaskCounters.TID[2] = 0;
  }

  (AdasPlantModel0_M->Timing.TaskCounters.TID[3])++;
  if ((AdasPlantModel0_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.1s, 0.0s] */
    AdasPlantModel0_M->Timing.TaskCounters.TID[3] = 0;
  }

  (AdasPlantModel0_M->Timing.TaskCounters.TID[4])++;
  if ((AdasPlantModel0_M->Timing.TaskCounters.TID[4]) > 49999) {/* Sample time: [5.0s, 0.0s] */
    AdasPlantModel0_M->Timing.TaskCounters.TID[4] = 0;
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
void AdasPlantModel0::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
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
  int_T nXc { 111 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AdasPlantModel0_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  AdasPlantModel0_derivatives();

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
  AdasPlantModel0_derivatives();

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
void AdasPlantModel0::step()
{
  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_Omega_at[4];
  real_T rtb_ImpAsg_InsertedFor_y_at_inp[3];
  int32_T i;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M))) {
    /* set solver stop time */
    if (!((&AdasPlantModel0_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&AdasPlantModel0_M)->solverInfo,
                            (((&AdasPlantModel0_M)->Timing.clockTickH0 + 1) *
        (&AdasPlantModel0_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&AdasPlantModel0_M)->solverInfo,
                            (((&AdasPlantModel0_M)->Timing.clockTick0 + 1) *
        (&AdasPlantModel0_M)->Timing.stepSize0 + (&AdasPlantModel0_M)
        ->Timing.clockTickH0 * (&AdasPlantModel0_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&AdasPlantModel0_M))) {
    (&AdasPlantModel0_M)->Timing.t[0] = rtsiGetT(&(&AdasPlantModel0_M)
      ->solverInfo);
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
  AdasPlantModel0_AdasPlantModel(AdasPlantModel0_U.DriverSteerCmd,
    AdasPlantModel0_U.DriverAccelCmd, AdasPlantModel0_U.DriverBrakeCmd,
    AdasPlantModel0_U.DriverGearCmd, AdasPlantModel0_U.AdasEnable,
    AdasPlantModel0_U.AdasSteerCmd, AdasPlantModel0_U.AdasLongTrq,
    AdasPlantModel0_U.AdasGearCmd, rtb_ImpAsg_InsertedFor_y_at_inp,
    rtb_ImpAsg_InsertedFor_Omega_at, &AdasPlantModel0_B.AdasPlantModel,
    &AdasPlantModel0_DW.AdasPlantModel, &AdasPlantModel0_P.AdasPlantModel,
    &AdasPlantModel0_P, &AdasPlantModel0_X.AdasPlantModel,
    &AdasPlantModel0_PrevZCX.AdasPlantModel);

  /* End of Outputs for SubSystem: '<Root>/AdasPlantModel' */

  /* Outport: '<Root>/SteerFdbk' */
  AdasPlantModel0_Y.SteerFdbk = AdasPlantModel0_B.AdasPlantModel.DeadZone3;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/AccelFdbk' */
    AdasPlantModel0_Y.AccelFdbk = AdasPlantModel0_B.AdasPlantModel.DeadZone2;

    /* Outport: '<Root>/DecelFdbk' */
    AdasPlantModel0_Y.DecelFdbk = AdasPlantModel0_B.AdasPlantModel.DeadZone1;

    /* Outport: '<Root>/IgnFdbk' */
    AdasPlantModel0_Y.IgnFdbk = AdasPlantModel0_B.AdasPlantModel.IgnSwtch;
  }

  /* Outport: '<Root>/GearFdbk' */
  AdasPlantModel0_Y.GearFdbk = AdasPlantModel0_B.AdasPlantModel.GearCmd;

  /* Outport: '<Root>/X' */
  AdasPlantModel0_Y.X = AdasPlantModel0_B.AdasPlantModel.xeyeze[0];

  /* Outport: '<Root>/Y' */
  AdasPlantModel0_Y.Y = AdasPlantModel0_B.AdasPlantModel.xeyeze[1];

  /* Outport: '<Root>/Z' */
  AdasPlantModel0_Y.Z = AdasPlantModel0_B.AdasPlantModel.xeyeze[2];

  /* Outport: '<Root>/Xdot' */
  AdasPlantModel0_Y.Xdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion_i[0];

  /* Outport: '<Root>/Ydot' */
  AdasPlantModel0_Y.Ydot = AdasPlantModel0_B.AdasPlantModel.UnitConversion_i[1];

  /* Outport: '<Root>/Zdot' */
  AdasPlantModel0_Y.Zdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion_i[2];

  /* Outport: '<Root>/phi' */
  AdasPlantModel0_Y.phi = rtb_ImpAsg_InsertedFor_y_at_inp[0];

  /* Outport: '<Root>/theta' */
  AdasPlantModel0_Y.theta = rtb_ImpAsg_InsertedFor_y_at_inp[1];

  /* Outport: '<Root>/psi' */
  AdasPlantModel0_Y.psi = rtb_ImpAsg_InsertedFor_y_at_inp[2];

  /* Outport: '<Root>/Xb' */
  AdasPlantModel0_Y.Xb = AdasPlantModel0_B.AdasPlantModel.Add[0];

  /* Outport: '<Root>/Yb' */
  AdasPlantModel0_Y.Yb = AdasPlantModel0_B.AdasPlantModel.Add[1];

  /* Outport: '<Root>/Zb' */
  AdasPlantModel0_Y.Zb = AdasPlantModel0_B.AdasPlantModel.Add[2];

  /* Outport: '<Root>/Xdotb' */
  AdasPlantModel0_Y.Xdotb = AdasPlantModel0_B.AdasPlantModel.V_wb[0];

  /* Outport: '<Root>/Ydotb' */
  AdasPlantModel0_Y.Ydotb = AdasPlantModel0_B.AdasPlantModel.V_wb[1];

  /* Outport: '<Root>/Zdotb' */
  AdasPlantModel0_Y.Zdotb = AdasPlantModel0_B.AdasPlantModel.V_wb[2];

  /* Outport: '<Root>/Xa' */
  AdasPlantModel0_Y.Xa = AdasPlantModel0_B.AdasPlantModel.Add_n[0];

  /* Outport: '<Root>/Ya' */
  AdasPlantModel0_Y.Ya = AdasPlantModel0_B.AdasPlantModel.Add_n[1];

  /* Outport: '<Root>/Za' */
  AdasPlantModel0_Y.Za = AdasPlantModel0_B.AdasPlantModel.Add_n[2];

  /* Outport: '<Root>/Xdota' */
  AdasPlantModel0_Y.Xdota = AdasPlantModel0_B.AdasPlantModel.V_wb_d[0];

  /* Outport: '<Root>/Ydota' */
  AdasPlantModel0_Y.Ydota = AdasPlantModel0_B.AdasPlantModel.V_wb_d[1];

  /* Outport: '<Root>/Zdota' */
  AdasPlantModel0_Y.Zdota = AdasPlantModel0_B.AdasPlantModel.V_wb_d[2];

  /* Outport: '<Root>/Xc' */
  AdasPlantModel0_Y.Xc = AdasPlantModel0_B.AdasPlantModel.Add_b[0];

  /* Outport: '<Root>/Yc' */
  AdasPlantModel0_Y.Yc = AdasPlantModel0_B.AdasPlantModel.Add_b[1];

  /* Outport: '<Root>/Zc' */
  AdasPlantModel0_Y.Zc = AdasPlantModel0_B.AdasPlantModel.Add_b[2];

  /* Outport: '<Root>/Xdotc' */
  AdasPlantModel0_Y.Xdotc = AdasPlantModel0_B.AdasPlantModel.V_wb_h[0];

  /* Outport: '<Root>/Ydotc' */
  AdasPlantModel0_Y.Ydotc = AdasPlantModel0_B.AdasPlantModel.V_wb_h[1];

  /* Outport: '<Root>/Zdotc' */
  AdasPlantModel0_Y.Zdotc = AdasPlantModel0_B.AdasPlantModel.V_wb_h[2];

  /* Outport: '<Root>/Xd' */
  AdasPlantModel0_Y.Xd = AdasPlantModel0_B.AdasPlantModel.Add_a[0];

  /* Outport: '<Root>/Yd' */
  AdasPlantModel0_Y.Yd = AdasPlantModel0_B.AdasPlantModel.Add_a[1];

  /* Outport: '<Root>/Zd' */
  AdasPlantModel0_Y.Zd = AdasPlantModel0_B.AdasPlantModel.Add_a[2];

  /* Outport: '<Root>/Xdotd' */
  AdasPlantModel0_Y.Xdotd = AdasPlantModel0_B.AdasPlantModel.V_wb_j[0];

  /* Outport: '<Root>/Ydotd' */
  AdasPlantModel0_Y.Ydotd = AdasPlantModel0_B.AdasPlantModel.V_wb_j[1];

  /* Outport: '<Root>/Zdotd' */
  AdasPlantModel0_Y.Zdotd = AdasPlantModel0_B.AdasPlantModel.V_wb_j[2];

  /* Outport: '<Root>/Xe' */
  AdasPlantModel0_Y.Xe = AdasPlantModel0_B.AdasPlantModel.Add_k[0];

  /* Outport: '<Root>/Ye' */
  AdasPlantModel0_Y.Ye = AdasPlantModel0_B.AdasPlantModel.Add_k[1];

  /* Outport: '<Root>/Ze' */
  AdasPlantModel0_Y.Ze = AdasPlantModel0_B.AdasPlantModel.Add_k[2];

  /* Outport: '<Root>/Xdote' */
  AdasPlantModel0_Y.Xdote = AdasPlantModel0_B.AdasPlantModel.V_wb_jq[0];

  /* Outport: '<Root>/Ydote' */
  AdasPlantModel0_Y.Ydote = AdasPlantModel0_B.AdasPlantModel.V_wb_jq[1];

  /* Outport: '<Root>/Zdote' */
  AdasPlantModel0_Y.Zdote = AdasPlantModel0_B.AdasPlantModel.V_wb_jq[2];

  /* Outport: '<Root>/Xf' */
  AdasPlantModel0_Y.Xf = AdasPlantModel0_B.AdasPlantModel.Add_o[0];

  /* Outport: '<Root>/Yf' */
  AdasPlantModel0_Y.Yf = AdasPlantModel0_B.AdasPlantModel.Add_o[1];

  /* Outport: '<Root>/Zf' */
  AdasPlantModel0_Y.Zf = AdasPlantModel0_B.AdasPlantModel.Add_o[2];

  /* Outport: '<Root>/Xdotf' */
  AdasPlantModel0_Y.Xdotf = AdasPlantModel0_B.AdasPlantModel.V_wb_k[0];

  /* Outport: '<Root>/Ydotf' */
  AdasPlantModel0_Y.Ydotf = AdasPlantModel0_B.AdasPlantModel.V_wb_k[1];

  /* Outport: '<Root>/Zdotf' */
  AdasPlantModel0_Y.Zdotf = AdasPlantModel0_B.AdasPlantModel.V_wb_k[2];

  /* Outport: '<Root>/xdot' */
  AdasPlantModel0_Y.xdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion[0];

  /* Outport: '<Root>/ydot' */
  AdasPlantModel0_Y.ydot = AdasPlantModel0_B.AdasPlantModel.UnitConversion[1];

  /* Outport: '<Root>/zdot' */
  AdasPlantModel0_Y.zdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion[2];

  /* Outport: '<Root>/Beta' */
  AdasPlantModel0_Y.Beta = AdasPlantModel0_B.AdasPlantModel.Beta;

  /* Outport: '<Root>/p' */
  AdasPlantModel0_Y.p = AdasPlantModel0_B.AdasPlantModel.pqr[0];

  /* Outport: '<Root>/q' */
  AdasPlantModel0_Y.q = AdasPlantModel0_B.AdasPlantModel.pqr[1];

  /* Outport: '<Root>/r' */
  AdasPlantModel0_Y.r = AdasPlantModel0_B.AdasPlantModel.pqr[2];

  /* Outport: '<Root>/ax' */
  AdasPlantModel0_Y.ax = AdasPlantModel0_B.AdasPlantModel.UnitConversion3[0];

  /* Outport: '<Root>/ay' */
  AdasPlantModel0_Y.ay = AdasPlantModel0_B.AdasPlantModel.UnitConversion3[1];

  /* Outport: '<Root>/az' */
  AdasPlantModel0_Y.az = AdasPlantModel0_B.AdasPlantModel.UnitConversion3[2];

  /* Outport: '<Root>/xddot' */
  AdasPlantModel0_Y.xddot = AdasPlantModel0_B.AdasPlantModel.UnitConversion1[0];

  /* Outport: '<Root>/yddot' */
  AdasPlantModel0_Y.yddot = AdasPlantModel0_B.AdasPlantModel.UnitConversion1[1];

  /* Outport: '<Root>/zddot' */
  AdasPlantModel0_Y.zddot = AdasPlantModel0_B.AdasPlantModel.UnitConversion1[2];

  /* Outport: '<Root>/pdot' */
  AdasPlantModel0_Y.pdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion2[0];

  /* Outport: '<Root>/qdot' */
  AdasPlantModel0_Y.qdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion2[1];

  /* Outport: '<Root>/rdot' */
  AdasPlantModel0_Y.rdot = AdasPlantModel0_B.AdasPlantModel.UnitConversion2[2];

  /* Outport: '<Root>/DCM' incorporates:
   *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
   */
  std::memcpy(&AdasPlantModel0_Y.DCM[0],
              &AdasPlantModel0_B.AdasPlantModel.Reshape9to3x3columnmajor[0], 9U *
              sizeof(real_T));

  /* Outport: '<Root>/Fx' */
  AdasPlantModel0_Y.Fx = AdasPlantModel0_B.AdasPlantModel.Sum[0];

  /* Outport: '<Root>/Fy' */
  AdasPlantModel0_Y.Fy = AdasPlantModel0_B.AdasPlantModel.Sum[1];

  /* Outport: '<Root>/Fz' */
  AdasPlantModel0_Y.Fz = AdasPlantModel0_B.AdasPlantModel.Sum[2];

  /* Outport: '<Root>/Fxb' */
  AdasPlantModel0_Y.Fxb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_j[0];

  /* Outport: '<Root>/Fyb' */
  AdasPlantModel0_Y.Fyb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_j[1];

  /* Outport: '<Root>/Fzb' */
  AdasPlantModel0_Y.Fzb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_j[2];

  /* Outport: '<Root>/Fxa' */
  AdasPlantModel0_Y.Fxa = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[0];

  /* Outport: '<Root>/Fya' */
  AdasPlantModel0_Y.Fya = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[1];

  /* Outport: '<Root>/Fza' */
  AdasPlantModel0_Y.Fza = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[2];

  /* Outport: '<Root>/Fxc' */
  AdasPlantModel0_Y.Fxc = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[3];

  /* Outport: '<Root>/Fyc' */
  AdasPlantModel0_Y.Fyc = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[4];

  /* Outport: '<Root>/Fzc' */
  AdasPlantModel0_Y.Fzc = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[5];

  /* Outport: '<Root>/Fxd' */
  AdasPlantModel0_Y.Fxd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[6];

  /* Outport: '<Root>/Fyd' */
  AdasPlantModel0_Y.Fyd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[7];

  /* Outport: '<Root>/Fzd' */
  AdasPlantModel0_Y.Fzd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[8];

  /* Outport: '<Root>/Fxe' */
  AdasPlantModel0_Y.Fxe = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[9];

  /* Outport: '<Root>/Fye' */
  AdasPlantModel0_Y.Fye = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[10];

  /* Outport: '<Root>/Fze' */
  AdasPlantModel0_Y.Fze = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate2[11];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Fxf' */
    AdasPlantModel0_Y.Fxf = AdasPlantModel0_B.AdasPlantModel.Hitch[0];

    /* Outport: '<Root>/Fyf' */
    AdasPlantModel0_Y.Fyf = AdasPlantModel0_B.AdasPlantModel.Hitch[1];

    /* Outport: '<Root>/Fzf' */
    AdasPlantModel0_Y.Fzf = AdasPlantModel0_B.AdasPlantModel.Hitch[2];

    /* Outport: '<Root>/Fxg' */
    AdasPlantModel0_Y.Fxg = AdasPlantModel0_B.AdasPlantModel.Constant[0];

    /* Outport: '<Root>/Fyg' */
    AdasPlantModel0_Y.Fyg = AdasPlantModel0_B.AdasPlantModel.Constant[1];

    /* Outport: '<Root>/Fzg' */
    AdasPlantModel0_Y.Fzg = AdasPlantModel0_B.AdasPlantModel.Constant[2];

    /* Outport: '<Root>/Fxh' */
    AdasPlantModel0_Y.Fxh = AdasPlantModel0_B.AdasPlantModel.Constant[3];

    /* Outport: '<Root>/Fyh' */
    AdasPlantModel0_Y.Fyh = AdasPlantModel0_B.AdasPlantModel.Constant[4];

    /* Outport: '<Root>/Fzh' */
    AdasPlantModel0_Y.Fzh = AdasPlantModel0_B.AdasPlantModel.Constant[5];

    /* Outport: '<Root>/Fxi' */
    AdasPlantModel0_Y.Fxi = AdasPlantModel0_B.AdasPlantModel.Constant[6];

    /* Outport: '<Root>/Fyi' */
    AdasPlantModel0_Y.Fyi = AdasPlantModel0_B.AdasPlantModel.Constant[7];

    /* Outport: '<Root>/Fzi' */
    AdasPlantModel0_Y.Fzi = AdasPlantModel0_B.AdasPlantModel.Constant[8];

    /* Outport: '<Root>/Fxj' */
    AdasPlantModel0_Y.Fxj = AdasPlantModel0_B.AdasPlantModel.Constant[9];

    /* Outport: '<Root>/Fyj' */
    AdasPlantModel0_Y.Fyj = AdasPlantModel0_B.AdasPlantModel.Constant[10];

    /* Outport: '<Root>/Fzj' */
    AdasPlantModel0_Y.Fzj = AdasPlantModel0_B.AdasPlantModel.Constant[11];

    /* Outport: '<Root>/Mxa' */
    AdasPlantModel0_Y.Mxa = AdasPlantModel0_B.AdasPlantModel.Constant1[0];

    /* Outport: '<Root>/Mya' */
    AdasPlantModel0_Y.Mya = AdasPlantModel0_B.AdasPlantModel.Constant1[1];

    /* Outport: '<Root>/Mza' */
    AdasPlantModel0_Y.Mza = AdasPlantModel0_B.AdasPlantModel.Constant1[2];

    /* Outport: '<Root>/Mxc' */
    AdasPlantModel0_Y.Mxc = AdasPlantModel0_B.AdasPlantModel.Hitch[3];

    /* Outport: '<Root>/Myc' */
    AdasPlantModel0_Y.Myc = AdasPlantModel0_B.AdasPlantModel.Hitch[4];

    /* Outport: '<Root>/Mzc' */
    AdasPlantModel0_Y.Mzc = AdasPlantModel0_B.AdasPlantModel.Hitch[5];

    /* Outport: '<Root>/x' */
    AdasPlantModel0_Y.x = AdasPlantModel0_B.AdasPlantModel.Selector1[0];

    /* Outport: '<Root>/y' */
    AdasPlantModel0_Y.y = AdasPlantModel0_B.AdasPlantModel.Selector1[1];

    /* Outport: '<Root>/z' */
    AdasPlantModel0_Y.z = AdasPlantModel0_B.AdasPlantModel.Selector1[2];
  }

  /* Outport: '<Root>/Fxk' */
  AdasPlantModel0_Y.Fxk = AdasPlantModel0_B.AdasPlantModel.UnaryMinus1_o[0];

  /* Outport: '<Root>/Fyk' */
  AdasPlantModel0_Y.Fyk = AdasPlantModel0_B.AdasPlantModel.UnaryMinus1_o[1];

  /* Outport: '<Root>/Fzk' */
  AdasPlantModel0_Y.Fzk = AdasPlantModel0_B.AdasPlantModel.UnaryMinus1_o[2];

  /* Outport: '<Root>/Fxl' */
  AdasPlantModel0_Y.Fxl = AdasPlantModel0_B.AdasPlantModel.Fg_B[0];

  /* Outport: '<Root>/Fyl' */
  AdasPlantModel0_Y.Fyl = AdasPlantModel0_B.AdasPlantModel.Fg_B[1];

  /* Outport: '<Root>/Fzl' */
  AdasPlantModel0_Y.Fzl = AdasPlantModel0_B.AdasPlantModel.Fg_B[2];

  /* Outport: '<Root>/Mx' */
  AdasPlantModel0_Y.Mx = AdasPlantModel0_B.AdasPlantModel.Add_np[0];

  /* Outport: '<Root>/My' */
  AdasPlantModel0_Y.My = AdasPlantModel0_B.AdasPlantModel.Add_np[1];

  /* Outport: '<Root>/Mz' */
  AdasPlantModel0_Y.Mz = AdasPlantModel0_B.AdasPlantModel.Add_np[2];

  /* Outport: '<Root>/Mxb' */
  AdasPlantModel0_Y.Mxb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_k[0];

  /* Outport: '<Root>/Myb' */
  AdasPlantModel0_Y.Myb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_k[1];

  /* Outport: '<Root>/Mzb' */
  AdasPlantModel0_Y.Mzb = AdasPlantModel0_B.AdasPlantModel.UnaryMinus_k[2];

  /* Outport: '<Root>/xdotb' */
  AdasPlantModel0_Y.xdotb = AdasPlantModel0_B.AdasPlantModel.Add1_h[0];

  /* Outport: '<Root>/ydotb' */
  AdasPlantModel0_Y.ydotb = AdasPlantModel0_B.AdasPlantModel.Add1_h[1];

  /* Outport: '<Root>/zdotb' */
  AdasPlantModel0_Y.zdotb = AdasPlantModel0_B.AdasPlantModel.Add1_h[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/xb' */
    AdasPlantModel0_Y.xb = AdasPlantModel0_B.AdasPlantModel.Selector1_h[0];

    /* Outport: '<Root>/yb' */
    AdasPlantModel0_Y.yb = AdasPlantModel0_B.AdasPlantModel.Selector1_h[1];

    /* Outport: '<Root>/zb' */
    AdasPlantModel0_Y.zb = AdasPlantModel0_B.AdasPlantModel.Selector1_h[2];

    /* Outport: '<Root>/xa' */
    AdasPlantModel0_Y.xa = AdasPlantModel0_B.AdasPlantModel.Selector1_p[0];

    /* Outport: '<Root>/ya' */
    AdasPlantModel0_Y.ya = AdasPlantModel0_B.AdasPlantModel.Selector1_p[1];

    /* Outport: '<Root>/za' */
    AdasPlantModel0_Y.za = AdasPlantModel0_B.AdasPlantModel.Selector1_p[2];
  }

  /* Outport: '<Root>/xdota' */
  AdasPlantModel0_Y.xdota = AdasPlantModel0_B.AdasPlantModel.Add1_d[0];

  /* Outport: '<Root>/ydota' */
  AdasPlantModel0_Y.ydota = AdasPlantModel0_B.AdasPlantModel.Add1_d[1];

  /* Outport: '<Root>/zdota' */
  AdasPlantModel0_Y.zdota = AdasPlantModel0_B.AdasPlantModel.Add1_d[2];

  /* Outport: '<Root>/xdotc' */
  AdasPlantModel0_Y.xdotc = AdasPlantModel0_B.AdasPlantModel.Add1_b[0];

  /* Outport: '<Root>/ydotc' */
  AdasPlantModel0_Y.ydotc = AdasPlantModel0_B.AdasPlantModel.Add1_b[1];

  /* Outport: '<Root>/zdotc' */
  AdasPlantModel0_Y.zdotc = AdasPlantModel0_B.AdasPlantModel.Add1_b[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/xc' */
    AdasPlantModel0_Y.xc = AdasPlantModel0_B.AdasPlantModel.Selector1_f[0];

    /* Outport: '<Root>/yc' */
    AdasPlantModel0_Y.yc = AdasPlantModel0_B.AdasPlantModel.Selector1_f[1];

    /* Outport: '<Root>/zc' */
    AdasPlantModel0_Y.zc = AdasPlantModel0_B.AdasPlantModel.Selector1_f[2];

    /* Outport: '<Root>/xd' */
    AdasPlantModel0_Y.xd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate_o
      [0];

    /* Outport: '<Root>/yd' */
    AdasPlantModel0_Y.yd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate_o
      [1];

    /* Outport: '<Root>/zd' */
    AdasPlantModel0_Y.zd = AdasPlantModel0_B.AdasPlantModel.VectorConcatenate_o
      [2];
  }

  /* Outport: '<Root>/xdotd' */
  AdasPlantModel0_Y.xdotd = AdasPlantModel0_B.AdasPlantModel.Add1_j[0];

  /* Outport: '<Root>/ydotd' */
  AdasPlantModel0_Y.ydotd = AdasPlantModel0_B.AdasPlantModel.Add1_j[1];

  /* Outport: '<Root>/zdotd' */
  AdasPlantModel0_Y.zdotd = AdasPlantModel0_B.AdasPlantModel.Add1_j[2];

  /* Outport: '<Root>/xdote' */
  AdasPlantModel0_Y.xdote = AdasPlantModel0_B.AdasPlantModel.Add1_k[0];

  /* Outport: '<Root>/ydote' */
  AdasPlantModel0_Y.ydote = AdasPlantModel0_B.AdasPlantModel.Add1_k[1];

  /* Outport: '<Root>/zdote' */
  AdasPlantModel0_Y.zdote = AdasPlantModel0_B.AdasPlantModel.Add1_k[2];

  /* Outport: '<Root>/PwrExt' */
  AdasPlantModel0_Y.PwrExt = AdasPlantModel0_B.AdasPlantModel.SumofElements_o;

  /* Outport: '<Root>/Drag' */
  AdasPlantModel0_Y.Drag = AdasPlantModel0_B.AdasPlantModel.SumofElements1;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/xe' */
    AdasPlantModel0_Y.xe = AdasPlantModel0_B.AdasPlantModel.Subtract[0];

    /* Outport: '<Root>/ye' */
    AdasPlantModel0_Y.ye = AdasPlantModel0_B.AdasPlantModel.Subtract[1];

    /* Outport: '<Root>/ze' */
    AdasPlantModel0_Y.ze = AdasPlantModel0_B.AdasPlantModel.Subtract[2];

    /* Outport: '<Root>/Gnd' */
    AdasPlantModel0_Y.Gnd[0] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[0];
    AdasPlantModel0_Y.Gnd[1] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[1];
    AdasPlantModel0_Y.Gnd[2] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[2];
    AdasPlantModel0_Y.Gnd[3] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[3];
  }

  /* Outport: '<Root>/xdotf' */
  AdasPlantModel0_Y.xdotf = AdasPlantModel0_B.AdasPlantModel.Add1_f[0];

  /* Outport: '<Root>/ydotf' */
  AdasPlantModel0_Y.ydotf = AdasPlantModel0_B.AdasPlantModel.Add1_f[1];

  /* Outport: '<Root>/zdotf' */
  AdasPlantModel0_Y.zdotf = AdasPlantModel0_B.AdasPlantModel.Add1_f[2];

  /* Outport: '<Root>/Betab' */
  AdasPlantModel0_Y.Betab = AdasPlantModel0_B.AdasPlantModel.Beta_b;

  /* Outport: '<Root>/AxlTrq' */
  AdasPlantModel0_Y.AxlTrq[0] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[0];
  AdasPlantModel0_Y.AxlTrq[1] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[1];
  AdasPlantModel0_Y.AxlTrq[2] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[2];
  AdasPlantModel0_Y.AxlTrq[3] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[3];

  /* Outport: '<Root>/Omega' */
  AdasPlantModel0_Y.Omega[0] = rtb_ImpAsg_InsertedFor_Omega_at[0];
  AdasPlantModel0_Y.Omega[1] = rtb_ImpAsg_InsertedFor_Omega_at[1];
  AdasPlantModel0_Y.Omega[2] = rtb_ImpAsg_InsertedFor_Omega_at[2];
  AdasPlantModel0_Y.Omega[3] = rtb_ImpAsg_InsertedFor_Omega_at[3];

  /* Outport: '<Root>/Fxm' */
  AdasPlantModel0_Y.Fxm[0] = AdasPlantModel0_B.AdasPlantModel.Integrator[0];
  AdasPlantModel0_Y.Fxm[1] = AdasPlantModel0_B.AdasPlantModel.Integrator[1];
  AdasPlantModel0_Y.Fxm[2] = AdasPlantModel0_B.AdasPlantModel.Integrator[2];
  AdasPlantModel0_Y.Fxm[3] = AdasPlantModel0_B.AdasPlantModel.Integrator[3];

  /* Outport: '<Root>/Fym' */
  AdasPlantModel0_Y.Fym[0] = AdasPlantModel0_B.AdasPlantModel.Integrator_i[0];
  AdasPlantModel0_Y.Fym[1] = AdasPlantModel0_B.AdasPlantModel.Integrator_i[1];
  AdasPlantModel0_Y.Fym[2] = AdasPlantModel0_B.AdasPlantModel.Integrator_i[2];
  AdasPlantModel0_Y.Fym[3] = AdasPlantModel0_B.AdasPlantModel.Integrator_i[3];

  /* Outport: '<Root>/Fzm' */
  AdasPlantModel0_Y.Fzm[0] = AdasPlantModel0_B.AdasPlantModel.Saturation[0];
  AdasPlantModel0_Y.Fzm[1] = AdasPlantModel0_B.AdasPlantModel.Saturation[1];
  AdasPlantModel0_Y.Fzm[2] = AdasPlantModel0_B.AdasPlantModel.Saturation[2];
  AdasPlantModel0_Y.Fzm[3] = AdasPlantModel0_B.AdasPlantModel.Saturation[3];

  /* Outport: '<Root>/Mxd' */
  AdasPlantModel0_Y.Mxd[0] = AdasPlantModel0_B.AdasPlantModel.Mx_c[0];
  AdasPlantModel0_Y.Mxd[1] = AdasPlantModel0_B.AdasPlantModel.Mx_c[1];
  AdasPlantModel0_Y.Mxd[2] = AdasPlantModel0_B.AdasPlantModel.Mx_c[2];
  AdasPlantModel0_Y.Mxd[3] = AdasPlantModel0_B.AdasPlantModel.Mx_c[3];

  /* Outport: '<Root>/Myd' */
  AdasPlantModel0_Y.Myd[0] = AdasPlantModel0_B.AdasPlantModel.Integrator_e[0];
  AdasPlantModel0_Y.Myd[1] = AdasPlantModel0_B.AdasPlantModel.Integrator_e[1];
  AdasPlantModel0_Y.Myd[2] = AdasPlantModel0_B.AdasPlantModel.Integrator_e[2];
  AdasPlantModel0_Y.Myd[3] = AdasPlantModel0_B.AdasPlantModel.Integrator_e[3];

  /* Outport: '<Root>/Mzd' */
  AdasPlantModel0_Y.Mzd[0] = AdasPlantModel0_B.AdasPlantModel.Mz_j[0];
  AdasPlantModel0_Y.Mzd[1] = AdasPlantModel0_B.AdasPlantModel.Mz_j[1];
  AdasPlantModel0_Y.Mzd[2] = AdasPlantModel0_B.AdasPlantModel.Mz_j[2];
  AdasPlantModel0_Y.Mzd[3] = AdasPlantModel0_B.AdasPlantModel.Mz_j[3];

  /* Outport: '<Root>/Vx' */
  AdasPlantModel0_Y.Vx[0] = AdasPlantModel0_B.AdasPlantModel.Reshape1[0];
  AdasPlantModel0_Y.Vx[1] = AdasPlantModel0_B.AdasPlantModel.Reshape1[1];
  AdasPlantModel0_Y.Vx[2] = AdasPlantModel0_B.AdasPlantModel.Reshape1[2];
  AdasPlantModel0_Y.Vx[3] = AdasPlantModel0_B.AdasPlantModel.Reshape1[3];

  /* Outport: '<Root>/Vy' */
  AdasPlantModel0_Y.Vy[0] = AdasPlantModel0_B.AdasPlantModel.Reshape2[0];
  AdasPlantModel0_Y.Vy[1] = AdasPlantModel0_B.AdasPlantModel.Reshape2[1];
  AdasPlantModel0_Y.Vy[2] = AdasPlantModel0_B.AdasPlantModel.Reshape2[2];
  AdasPlantModel0_Y.Vy[3] = AdasPlantModel0_B.AdasPlantModel.Reshape2[3];

  /* Outport: '<Root>/Re' */
  AdasPlantModel0_Y.Re[0] = AdasPlantModel0_B.AdasPlantModel.Re[0];
  AdasPlantModel0_Y.Re[1] = AdasPlantModel0_B.AdasPlantModel.Re[1];
  AdasPlantModel0_Y.Re[2] = AdasPlantModel0_B.AdasPlantModel.Re[2];
  AdasPlantModel0_Y.Re[3] = AdasPlantModel0_B.AdasPlantModel.Re[3];

  /* Outport: '<Root>/Kappa' */
  AdasPlantModel0_Y.Kappa[0] = AdasPlantModel0_B.AdasPlantModel.Kappa[0];
  AdasPlantModel0_Y.Kappa[1] = AdasPlantModel0_B.AdasPlantModel.Kappa[1];
  AdasPlantModel0_Y.Kappa[2] = AdasPlantModel0_B.AdasPlantModel.Kappa[2];
  AdasPlantModel0_Y.Kappa[3] = AdasPlantModel0_B.AdasPlantModel.Kappa[3];

  /* Outport: '<Root>/Alpha' */
  AdasPlantModel0_Y.Alpha[0] = AdasPlantModel0_B.AdasPlantModel.Alpha[0];
  AdasPlantModel0_Y.Alpha[1] = AdasPlantModel0_B.AdasPlantModel.Alpha[1];
  AdasPlantModel0_Y.Alpha[2] = AdasPlantModel0_B.AdasPlantModel.Alpha[2];
  AdasPlantModel0_Y.Alpha[3] = AdasPlantModel0_B.AdasPlantModel.Alpha[3];

  /* Outport: '<Root>/a' */
  AdasPlantModel0_Y.a[0] = AdasPlantModel0_B.AdasPlantModel.a[0];
  AdasPlantModel0_Y.a[1] = AdasPlantModel0_B.AdasPlantModel.a[1];
  AdasPlantModel0_Y.a[2] = AdasPlantModel0_B.AdasPlantModel.a[2];
  AdasPlantModel0_Y.a[3] = AdasPlantModel0_B.AdasPlantModel.a[3];

  /* Outport: '<Root>/b' */
  AdasPlantModel0_Y.b[0] = AdasPlantModel0_B.AdasPlantModel.b[0];
  AdasPlantModel0_Y.b[1] = AdasPlantModel0_B.AdasPlantModel.b[1];
  AdasPlantModel0_Y.b[2] = AdasPlantModel0_B.AdasPlantModel.b[2];
  AdasPlantModel0_Y.b[3] = AdasPlantModel0_B.AdasPlantModel.b[3];

  /* Outport: '<Root>/Gamma' */
  AdasPlantModel0_Y.Gamma[0] = AdasPlantModel0_B.AdasPlantModel.Reshape[0];
  AdasPlantModel0_Y.Gamma[1] = AdasPlantModel0_B.AdasPlantModel.Reshape[1];
  AdasPlantModel0_Y.Gamma[2] = AdasPlantModel0_B.AdasPlantModel.Reshape[2];
  AdasPlantModel0_Y.Gamma[3] = AdasPlantModel0_B.AdasPlantModel.Reshape[3];

  /* Outport: '<Root>/psidot' */
  AdasPlantModel0_Y.psidot[0] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[0];
  AdasPlantModel0_Y.psidot[1] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[1];
  AdasPlantModel0_Y.psidot[2] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[2];
  AdasPlantModel0_Y.psidot[3] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[3];

  /* Outport: '<Root>/BrkTrq' */
  AdasPlantModel0_Y.BrkTrq[0] =
    AdasPlantModel0_B.AdasPlantModel.TorqueConversion[0];
  AdasPlantModel0_Y.BrkTrq[1] =
    AdasPlantModel0_B.AdasPlantModel.TorqueConversion[1];
  AdasPlantModel0_Y.BrkTrq[2] =
    AdasPlantModel0_B.AdasPlantModel.TorqueConversion[2];
  AdasPlantModel0_Y.BrkTrq[3] =
    AdasPlantModel0_B.AdasPlantModel.TorqueConversion[3];

  /* Outport: '<Root>/BrkPrs' */
  AdasPlantModel0_Y.BrkPrs[0] = AdasPlantModel0_B.AdasPlantModel.Gain4[0];
  AdasPlantModel0_Y.BrkPrs[1] = AdasPlantModel0_B.AdasPlantModel.Gain4[1];
  AdasPlantModel0_Y.BrkPrs[2] = AdasPlantModel0_B.AdasPlantModel.Gain4[2];
  AdasPlantModel0_Y.BrkPrs[3] = AdasPlantModel0_B.AdasPlantModel.Gain4[3];

  /* Outport: '<Root>/zf' */
  AdasPlantModel0_Y.zf[0] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o1[0];
  AdasPlantModel0_Y.zf[1] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o1[1];
  AdasPlantModel0_Y.zf[2] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o1[2];
  AdasPlantModel0_Y.zf[3] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o1[3];

  /* Outport: '<Root>/zdotg' */
  AdasPlantModel0_Y.zdotg[0] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o2[0];
  AdasPlantModel0_Y.zdotg[1] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o2[1];
  AdasPlantModel0_Y.zdotg[2] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o2[2];
  AdasPlantModel0_Y.zdotg[3] =
    AdasPlantModel0_B.AdasPlantModel.IntegratorSecondOrder_o2[3];

  /* Outport: '<Root>/GndFz' */
  AdasPlantModel0_Y.GndFz[0] = AdasPlantModel0_B.AdasPlantModel.SignalCopy[0];
  AdasPlantModel0_Y.GndFz[1] = AdasPlantModel0_B.AdasPlantModel.SignalCopy[1];
  AdasPlantModel0_Y.GndFz[2] = AdasPlantModel0_B.AdasPlantModel.SignalCopy[2];
  AdasPlantModel0_Y.GndFz[3] = AdasPlantModel0_B.AdasPlantModel.SignalCopy[3];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Prs' */
    AdasPlantModel0_Y.Prs[0] = AdasPlantModel0_B.AdasPlantModel.FrontPressure[0];
    AdasPlantModel0_Y.Prs[1] = AdasPlantModel0_B.AdasPlantModel.FrontPressure[1];
    AdasPlantModel0_Y.Prs[2] = AdasPlantModel0_B.AdasPlantModel.RearPressure[0];
    AdasPlantModel0_Y.Prs[3] = AdasPlantModel0_B.AdasPlantModel.RearPressure[1];

    /* Outport: '<Root>/mu' */
    AdasPlantModel0_Y.mu[0] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate[0];
    AdasPlantModel0_Y.mu[1] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate[1];
    AdasPlantModel0_Y.mu[2] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate[2];
    AdasPlantModel0_Y.mu[3] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate[3];

    /* Outport: '<Root>/zg' */
    AdasPlantModel0_Y.zg[0] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[0];
    AdasPlantModel0_Y.zg[1] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[1];
    AdasPlantModel0_Y.zg[2] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[2];
    AdasPlantModel0_Y.zg[3] =
      AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1[3];

    /* Outport: '<Root>/DCMb' incorporates:
     *  Constant: '<S73>/Constant2'
     */
    std::memcpy(&AdasPlantModel0_Y.DCMb[0],
                &AdasPlantModel0_B.AdasPlantModel.DCM[0], 36U * sizeof(real_T));

    /* Outport: '<Root>/Cltch1State' */
    AdasPlantModel0_Y.Cltch1State = AdasPlantModel0_B.AdasPlantModel.Cltch1State;

    /* Outport: '<Root>/Cltch2State' */
    AdasPlantModel0_Y.Cltch2State = AdasPlantModel0_B.AdasPlantModel.Cltch2State;

    /* Outport: '<Root>/EngTrq' */
    AdasPlantModel0_Y.EngTrq = AdasPlantModel0_B.AdasPlantModel.EngTrq;

    /* Outport: '<Root>/EngSpdb' */
    AdasPlantModel0_Y.EngSpdb = AdasPlantModel0_B.AdasPlantModel.EngSpd;

    /* Outport: '<Root>/DiffTrq' */
    AdasPlantModel0_Y.DiffTrq = AdasPlantModel0_B.AdasPlantModel.DiffTrq;

    /* Outport: '<Root>/DiffSpd' */
    AdasPlantModel0_Y.DiffSpd = AdasPlantModel0_B.AdasPlantModel.DiffSpd;

    /* Outport: '<Root>/TransSpdRatio' */
    AdasPlantModel0_Y.TransSpdRatio =
      AdasPlantModel0_B.AdasPlantModel.TransSpdRatio;

    /* Outport: '<Root>/TransEta' */
    AdasPlantModel0_Y.TransEta = AdasPlantModel0_B.AdasPlantModel.TransEta;

    /* Outport: '<Root>/TransGearCmd' */
    AdasPlantModel0_Y.TransGearCmd =
      AdasPlantModel0_B.AdasPlantModel.TransGearCmd;

    /* Outport: '<Root>/TransGear' */
    AdasPlantModel0_Y.TransGear = AdasPlantModel0_B.AdasPlantModel.TransGear;

    /* Outport: '<Root>/PwrEng' */
    AdasPlantModel0_Y.PwrEng = AdasPlantModel0_B.AdasPlantModel.PwrEng;

    /* Outport: '<Root>/PwrDiffrntl' */
    AdasPlantModel0_Y.PwrDiffrntl = AdasPlantModel0_B.AdasPlantModel.PwrDiffrntl;

    /* Outport: '<Root>/PwrEffLoss' */
    AdasPlantModel0_Y.PwrEffLoss = AdasPlantModel0_B.AdasPlantModel.PwrEffLoss;

    /* Outport: '<Root>/PwrDampLoss' */
    AdasPlantModel0_Y.PwrDampLoss = AdasPlantModel0_B.AdasPlantModel.PwrDampLoss;

    /* Outport: '<Root>/PwrStoredTrans' */
    AdasPlantModel0_Y.PwrStoredTrans =
      AdasPlantModel0_B.AdasPlantModel.PwrStoredTrans;
  }

  /* Outport: '<Root>/AxlTrqb' */
  AdasPlantModel0_Y.AxlTrqb[0] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[0];
  AdasPlantModel0_Y.AxlTrqb[1] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[1];
  AdasPlantModel0_Y.AxlTrqb[2] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[2];
  AdasPlantModel0_Y.AxlTrqb[3] =
    AdasPlantModel0_B.AdasPlantModel.VectorConcatenate1_h[3];

  /* Outport: '<Root>/DriveshftSpd' */
  AdasPlantModel0_Y.DriveshftSpd =
    AdasPlantModel0_B.AdasPlantModel.SumofElements_m;

  /* Outport: '<Root>/EMSpd' */
  AdasPlantModel0_Y.EMSpd = AdasPlantModel0_B.AdasPlantModel.Spd;

  /* Outport: '<Root>/FL' */
  AdasPlantModel0_Y.FL = AdasPlantModel0_B.AdasPlantModel.Switch;

  /* Outport: '<Root>/FR' */
  AdasPlantModel0_Y.FR = AdasPlantModel0_B.AdasPlantModel.Switch1;

  /* Outport: '<Root>/RL' */
  AdasPlantModel0_Y.RL = AdasPlantModel0_B.AdasPlantModel.RL;

  /* Outport: '<Root>/RR' */
  AdasPlantModel0_Y.RR = AdasPlantModel0_B.AdasPlantModel.RR;

  /* Outport: '<Root>/BattSoc' */
  AdasPlantModel0_Y.BattSoc = AdasPlantModel0_B.AdasPlantModel.SOCRatioto;

  /* Outport: '<Root>/BattCurr' */
  AdasPlantModel0_Y.BattCurr = AdasPlantModel0_B.AdasPlantModel.Divide_pf;

  /* Outport: '<Root>/BattPwr' */
  AdasPlantModel0_Y.BattPwr = AdasPlantModel0_B.AdasPlantModel.BattPwr;

  /* Outport: '<Root>/BattVolt' */
  AdasPlantModel0_Y.BattVolt = AdasPlantModel0_B.AdasPlantModel.Gain1;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* Outport: '<Root>/CellVoltages' */
    std::memcpy(&AdasPlantModel0_Y.CellVoltages[0],
                &AdasPlantModel0_B.AdasPlantModel.CellVoltages_e[0], 96U *
                sizeof(real32_T));

    /* Outport: '<Root>/PackVoltage' */
    AdasPlantModel0_Y.PackVoltage =
      AdasPlantModel0_B.AdasPlantModel.PackVoltage_i;

    /* Outport: '<Root>/PackCurrent' */
    AdasPlantModel0_Y.PackCurrent =
      AdasPlantModel0_B.AdasPlantModel.PackCurrent_j;

    /* Outport: '<Root>/CellTemperatures' */
    std::memcpy(&AdasPlantModel0_Y.CellTemperatures[0],
                &AdasPlantModel0_B.AdasPlantModel.CellTemperatures[0], 96U *
                sizeof(real32_T));

    /* Outport: '<Root>/VoutChgr' */
    AdasPlantModel0_Y.VoutChgr = AdasPlantModel0_B.AdasPlantModel.VoutChgr_k;

    /* Outport: '<Root>/VoutInvtr' */
    AdasPlantModel0_Y.VoutInvtr = AdasPlantModel0_B.AdasPlantModel.VoutInvtr_km;
  }

  /* Outport: '<Root>/EMTrq' */
  AdasPlantModel0_Y.EMTrq = AdasPlantModel0_B.AdasPlantModel.EMTrq;

  /* Outport: '<Root>/EMPwrElec' */
  AdasPlantModel0_Y.EMPwrElec = AdasPlantModel0_B.AdasPlantModel.EMPwrElec;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/FuelCellVolt' */
    AdasPlantModel0_Y.FuelCellVolt =
      AdasPlantModel0_B.AdasPlantModel.FuelCellVolt;

    /* Outport: '<Root>/FuelCellCurr' */
    AdasPlantModel0_Y.FuelCellCurr =
      AdasPlantModel0_B.AdasPlantModel.FuelCellCurr;

    /* Outport: '<Root>/H2Flw' */
    AdasPlantModel0_Y.H2Flw = AdasPlantModel0_B.AdasPlantModel.H2Flw;

    /* Outport: '<Root>/Xg' */
    AdasPlantModel0_Y.Xg = AdasPlantModel0_B.AdasPlantModel.X;

    /* Outport: '<Root>/Yg' */
    AdasPlantModel0_Y.Yg = AdasPlantModel0_B.AdasPlantModel.Y_j;

    /* Outport: '<Root>/Xh' */
    AdasPlantModel0_Y.Xh = AdasPlantModel0_B.AdasPlantModel.X_o;

    /* Outport: '<Root>/Yh' */
    AdasPlantModel0_Y.Yh = AdasPlantModel0_B.AdasPlantModel.Y_l;

    /* Outport: '<Root>/Xi' */
    AdasPlantModel0_Y.Xi = AdasPlantModel0_B.AdasPlantModel.X_f;

    /* Outport: '<Root>/Yi' */
    AdasPlantModel0_Y.Yi = AdasPlantModel0_B.AdasPlantModel.Y_e;

    /* Outport: '<Root>/Xj' */
    AdasPlantModel0_Y.Xj = AdasPlantModel0_B.AdasPlantModel.X_k;

    /* Outport: '<Root>/Yj' */
    AdasPlantModel0_Y.Yj = AdasPlantModel0_B.AdasPlantModel.Y_d;

    /* Outport: '<Root>/Xk' */
    AdasPlantModel0_Y.Xk = AdasPlantModel0_B.AdasPlantModel.X_e;

    /* Outport: '<Root>/Yk' */
    AdasPlantModel0_Y.Yk = AdasPlantModel0_B.AdasPlantModel.Y;

    /* Outport: '<Root>/Xl' */
    AdasPlantModel0_Y.Xl = AdasPlantModel0_B.AdasPlantModel.X_c;

    /* Outport: '<Root>/Yl' */
    AdasPlantModel0_Y.Yl = AdasPlantModel0_B.AdasPlantModel.Y_a;

    /* Outport: '<Root>/Xm' */
    AdasPlantModel0_Y.Xm = AdasPlantModel0_B.AdasPlantModel.X_j;

    /* Outport: '<Root>/Ym' */
    AdasPlantModel0_Y.Ym = AdasPlantModel0_B.AdasPlantModel.Y_h;

    /* Outport: '<Root>/Hitch' */
    for (i = 0; i < 6; i++) {
      AdasPlantModel0_Y.Hitch[i] = AdasPlantModel0_B.AdasPlantModel.Hitch[i];
    }

    /* End of Outport: '<Root>/Hitch' */

    /* Outport: '<Root>/Wheels' */
    AdasPlantModel0_Y.Wheels = AdasPlantModel0_B.AdasPlantModel.Wheels;

    /* Outport: '<Root>/EngTrqb' */
    AdasPlantModel0_Y.EngTrqb = AdasPlantModel0_B.AdasPlantModel.EngTrq_c;

    /* Outport: '<Root>/EngSpdOut' */
    AdasPlantModel0_Y.EngSpdOut = AdasPlantModel0_B.AdasPlantModel.EngSpd_b;

    /* Outport: '<Root>/Map' */
    AdasPlantModel0_Y.Map = AdasPlantModel0_B.AdasPlantModel.Map;

    /* Outport: '<Root>/Mat' */
    AdasPlantModel0_Y.Mat = AdasPlantModel0_B.AdasPlantModel.Mat;

    /* Outport: '<Root>/ThrPosPct' */
    AdasPlantModel0_Y.ThrPosPct = AdasPlantModel0_B.AdasPlantModel.ThrPosPct;

    /* Outport: '<Root>/WgAreaPct' */
    AdasPlantModel0_Y.WgAreaPct = AdasPlantModel0_B.AdasPlantModel.WgAreaPct;

    /* Outport: '<Root>/IntkCamPhase' */
    AdasPlantModel0_Y.IntkCamPhase =
      AdasPlantModel0_B.AdasPlantModel.IntkCamPhase;

    /* Outport: '<Root>/ExhCamPhase' */
    AdasPlantModel0_Y.ExhCamPhase = AdasPlantModel0_B.AdasPlantModel.ExhCamPhase;

    /* Outport: '<Root>/TurboRackPos' */
    AdasPlantModel0_Y.TurboRackPos =
      AdasPlantModel0_B.AdasPlantModel.TurboRackPos;

    /* Outport: '<Root>/EgrVlvAreaPct' */
    AdasPlantModel0_Y.EgrVlvAreaPct =
      AdasPlantModel0_B.AdasPlantModel.EgrVlvAreaPct;

    /* Outport: '<Root>/VarCompRatioPos' */
    AdasPlantModel0_Y.VarCompRatioPos =
      AdasPlantModel0_B.AdasPlantModel.VarCompRatioPos;

    /* Outport: '<Root>/IntkVlvLift' */
    AdasPlantModel0_Y.IntkVlvLift = AdasPlantModel0_B.AdasPlantModel.IntkVlvLift;

    /* Outport: '<Root>/VarIntkRunLen' */
    AdasPlantModel0_Y.VarIntkRunLen =
      AdasPlantModel0_B.AdasPlantModel.VarIntkRunLen;

    /* Outport: '<Root>/IntkSwirlVlvPos' */
    AdasPlantModel0_Y.IntkSwirlVlvPos =
      AdasPlantModel0_B.AdasPlantModel.IntkSwirlVlvPos;

    /* Outport: '<Root>/FuelFlw' */
    AdasPlantModel0_Y.FuelFlw = AdasPlantModel0_B.AdasPlantModel.Product_a;

    /* Outport: '<Root>/FuelVolFlw' */
    AdasPlantModel0_Y.FuelVolFlw = AdasPlantModel0_B.AdasPlantModel.Product2_e;

    /* Outport: '<Root>/IntkPortFlw' */
    AdasPlantModel0_Y.IntkPortFlw =
      AdasPlantModel0_B.AdasPlantModel.IntkGasMassFlw;

    /* Outport: '<Root>/NormAirChrg' */
    AdasPlantModel0_Y.NormAirChrg =
      AdasPlantModel0_B.AdasPlantModel.NrmlzdAirChrg;

    /* Outport: '<Root>/ExhManGasTemp' */
    AdasPlantModel0_Y.ExhManGasTemp =
      AdasPlantModel0_B.AdasPlantModel.ExhManGasTemp;

    /* Outport: '<Root>/Afr' */
    AdasPlantModel0_Y.Afr = AdasPlantModel0_B.AdasPlantModel.Product1_a;

    /* Outport: '<Root>/TurboSpd' */
    AdasPlantModel0_Y.TurboSpd = AdasPlantModel0_B.AdasPlantModel.TurboSpd;

    /* Outport: '<Root>/TurbPrsRatio' */
    AdasPlantModel0_Y.TurbPrsRatio = AdasPlantModel0_B.AdasPlantModel.Map1;

    /* Outport: '<Root>/CompPrsRatio' */
    AdasPlantModel0_Y.CompPrsRatio = AdasPlantModel0_B.AdasPlantModel.Map2;

    /* Outport: '<Root>/TurbTempOut' */
    AdasPlantModel0_Y.TurbTempOut = AdasPlantModel0_B.AdasPlantModel.Mat1;

    /* Outport: '<Root>/CompTempOut' */
    AdasPlantModel0_Y.CompTempOut = AdasPlantModel0_B.AdasPlantModel.TurboSpd1;

    /* Outport: '<Root>/EgrPct' */
    AdasPlantModel0_Y.EgrPct = AdasPlantModel0_B.AdasPlantModel.Map3;

    /* Outport: '<Root>/EgrMassFlwRate' */
    AdasPlantModel0_Y.EgrMassFlwRate = AdasPlantModel0_B.AdasPlantModel.Map4;

    /* Outport: '<Root>/EgrCoolerTempOut' */
    AdasPlantModel0_Y.EgrCoolerTempOut = AdasPlantModel0_B.AdasPlantModel.Mat2;

    /* Outport: '<Root>/IntercoolerTempOut' */
    AdasPlantModel0_Y.IntercoolerTempOut =
      AdasPlantModel0_B.AdasPlantModel.TurboSpd2;

    /* Outport: '<Root>/BSFC' */
    AdasPlantModel0_Y.BSFC = AdasPlantModel0_B.AdasPlantModel.Bsfc;

    /* Outport: '<Root>/TPHC' */
    AdasPlantModel0_Y.TPHC = AdasPlantModel0_B.AdasPlantModel.TPHC;

    /* Outport: '<Root>/TPCO' */
    AdasPlantModel0_Y.TPCO = AdasPlantModel0_B.AdasPlantModel.TPCO;

    /* Outport: '<Root>/TPNOx' */
    AdasPlantModel0_Y.TPNOx = AdasPlantModel0_B.AdasPlantModel.TPNOx;

    /* Outport: '<Root>/TPCO2' */
    AdasPlantModel0_Y.TPCO2 = AdasPlantModel0_B.AdasPlantModel.TPCO2;

    /* Outport: '<Root>/Iat' */
    AdasPlantModel0_Y.Iat = AdasPlantModel0_B.AdasPlantModel.Map5;

    /* Outport: '<Root>/Ect' */
    AdasPlantModel0_Y.Ect = AdasPlantModel0_B.AdasPlantModel.Map6;

    /* Outport: '<Root>/EgrVlvDeltaPrs' */
    AdasPlantModel0_Y.EgrVlvDeltaPrs = AdasPlantModel0_B.AdasPlantModel.Mat3;

    /* Outport: '<Root>/EgrVlvInTemp' */
    AdasPlantModel0_Y.EgrVlvInTemp = AdasPlantModel0_B.AdasPlantModel.TurboSpd3;

    /* Outport: '<Root>/CylPrs' */
    AdasPlantModel0_Y.CylPrs = AdasPlantModel0_B.AdasPlantModel.CylPrs;

    /* Outport: '<Root>/EngTrqCrk' */
    AdasPlantModel0_Y.EngTrqCrk = AdasPlantModel0_B.AdasPlantModel.EngTrqCrk;

    /* Outport: '<Root>/CrkAng' */
    AdasPlantModel0_Y.CrkAng = AdasPlantModel0_B.AdasPlantModel.CrkAng;
  }

  /* Outport: '<Root>/F' incorporates:
   *  Concatenate: '<S291>/Matrix Concatenate'
   */
  std::memcpy(&AdasPlantModel0_Y.F[0],
              &AdasPlantModel0_B.AdasPlantModel.MatrixConcatenate_f[0], 12U *
              sizeof(real_T));

  /* Outport: '<Root>/M' incorporates:
   *  Reshape: '<S291>/Reshape14'
   */
  std::memcpy(&AdasPlantModel0_Y.M[0],
              &AdasPlantModel0_B.AdasPlantModel.Reshape14[0], 12U * sizeof
              (real_T));

  /* Outport: '<Root>/Fb' incorporates:
   *  Concatenate: '<S291>/Matrix Concatenate1'
   */
  std::memcpy(&AdasPlantModel0_Y.Fb[0],
              &AdasPlantModel0_B.AdasPlantModel.MatrixConcatenate1_p[0], 12U *
              sizeof(real_T));

  /* Outport: '<Root>/xdotg' incorporates:
   *  Selector: '<S285>/Selector1'
   */
  AdasPlantModel0_Y.xdotg[0] = AdasPlantModel0_B.AdasPlantModel.xdot[0];
  AdasPlantModel0_Y.xdotg[1] = AdasPlantModel0_B.AdasPlantModel.xdot[1];
  AdasPlantModel0_Y.xdotg[2] = AdasPlantModel0_B.AdasPlantModel.xdot[2];
  AdasPlantModel0_Y.xdotg[3] = AdasPlantModel0_B.AdasPlantModel.xdot[3];

  /* Outport: '<Root>/ydotg' incorporates:
   *  Selector: '<S285>/Selector2'
   */
  AdasPlantModel0_Y.ydotg[0] = AdasPlantModel0_B.AdasPlantModel.ydot[0];
  AdasPlantModel0_Y.ydotg[1] = AdasPlantModel0_B.AdasPlantModel.ydot[1];
  AdasPlantModel0_Y.ydotg[2] = AdasPlantModel0_B.AdasPlantModel.ydot[2];
  AdasPlantModel0_Y.ydotg[3] = AdasPlantModel0_B.AdasPlantModel.ydot[3];

  /* Outport: '<Root>/Ang' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  std::memcpy(&AdasPlantModel0_Y.Ang[0],
              &AdasPlantModel0_B.AdasPlantModel.Reshape5[0], 12U * sizeof(real_T));

  /* Outport: '<Root>/zh' */
  AdasPlantModel0_Y.zh[0] = AdasPlantModel0_B.AdasPlantModel.z[0];
  AdasPlantModel0_Y.zh[1] = AdasPlantModel0_B.AdasPlantModel.z[1];
  AdasPlantModel0_Y.zh[2] = AdasPlantModel0_B.AdasPlantModel.z[2];
  AdasPlantModel0_Y.zh[3] = AdasPlantModel0_B.AdasPlantModel.z[3];

  /* Outport: '<Root>/AngVel' incorporates:
   *  Sum: '<S292>/Add'
   */
  std::memcpy(&AdasPlantModel0_Y.AngVel[0],
              &AdasPlantModel0_B.AdasPlantModel.AngVel[0], 12U * sizeof(real_T));

  /* Outport: '<Root>/WhlAng' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate3'
   */
  std::memcpy(&AdasPlantModel0_Y.WhlAng[0],
              &AdasPlantModel0_B.AdasPlantModel.VectorConcatenate3[0], 12U *
              sizeof(real_T));

  /* Outport: '<Root>/YawRate' */
  AdasPlantModel0_Y.YawRate[0] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[0];
  AdasPlantModel0_Y.YawRate[1] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[1];
  AdasPlantModel0_Y.YawRate[2] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[2];
  AdasPlantModel0_Y.YawRate[3] = AdasPlantModel0_B.AdasPlantModel.UnaryMinus[3];

  /* Outport: '<Root>/Vxb' */
  AdasPlantModel0_Y.Vxb[0] = AdasPlantModel0_B.AdasPlantModel.Reshape1[0];
  AdasPlantModel0_Y.Vxb[1] = AdasPlantModel0_B.AdasPlantModel.Reshape1[1];
  AdasPlantModel0_Y.Vxb[2] = AdasPlantModel0_B.AdasPlantModel.Reshape1[2];
  AdasPlantModel0_Y.Vxb[3] = AdasPlantModel0_B.AdasPlantModel.Reshape1[3];

  /* Outport: '<Root>/Vyb' */
  AdasPlantModel0_Y.Vyb[0] = AdasPlantModel0_B.AdasPlantModel.Reshape2[0];
  AdasPlantModel0_Y.Vyb[1] = AdasPlantModel0_B.AdasPlantModel.Reshape2[1];
  AdasPlantModel0_Y.Vyb[2] = AdasPlantModel0_B.AdasPlantModel.Reshape2[2];
  AdasPlantModel0_Y.Vyb[3] = AdasPlantModel0_B.AdasPlantModel.Reshape2[3];

  /* Outport: '<Root>/Vz' */
  AdasPlantModel0_Y.Vz[0] = AdasPlantModel0_B.AdasPlantModel.Reshape5_d[0];
  AdasPlantModel0_Y.Vz[1] = AdasPlantModel0_B.AdasPlantModel.Reshape5_d[1];
  AdasPlantModel0_Y.Vz[2] = AdasPlantModel0_B.AdasPlantModel.Reshape5_d[2];
  AdasPlantModel0_Y.Vz[3] = AdasPlantModel0_B.AdasPlantModel.Reshape5_d[3];

  /* Outport: '<Root>/Fext' */
  AdasPlantModel0_Y.Fext[0] = AdasPlantModel0_B.AdasPlantModel.Saturation[0];
  AdasPlantModel0_Y.Fext[1] = AdasPlantModel0_B.AdasPlantModel.Saturation[1];
  AdasPlantModel0_Y.Fext[2] = AdasPlantModel0_B.AdasPlantModel.Saturation[2];
  AdasPlantModel0_Y.Fext[3] = AdasPlantModel0_B.AdasPlantModel.Saturation[3];

  /* Outport: '<Root>/dz' */
  AdasPlantModel0_Y.dz[0] = AdasPlantModel0_B.AdasPlantModel.dz[0];
  AdasPlantModel0_Y.dz[1] = AdasPlantModel0_B.AdasPlantModel.dz[1];
  AdasPlantModel0_Y.dz[2] = AdasPlantModel0_B.AdasPlantModel.dz[2];
  AdasPlantModel0_Y.dz[3] = AdasPlantModel0_B.AdasPlantModel.dz[3];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M))) {
    /* Update for Atomic SubSystem: '<Root>/AdasPlantModel' */
    AdasPlant_AdasPlantModel_Update(&AdasPlantModel0_B.AdasPlantModel,
      &AdasPlantModel0_DW.AdasPlantModel, &AdasPlantModel0_P.AdasPlantModel);

    /* End of Update for SubSystem: '<Root>/AdasPlantModel' */

    /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M))) {
      if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&AdasPlantModel0_M)->solverInfo)) {
        rtsiSetSimTimeStep(&(&AdasPlantModel0_M)->solverInfo,MINOR_TIME_STEP);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&AdasPlantModel0_M)->solverInfo, false);
        AdasPlantModel0::step();
        rtsiSetSimTimeStep(&(&AdasPlantModel0_M)->solverInfo, MAJOR_TIME_STEP);
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M))) {
    rt_ertODEUpdateContinuousStates(&(&AdasPlantModel0_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&AdasPlantModel0_M)->Timing.clockTick0)) {
      ++(&AdasPlantModel0_M)->Timing.clockTickH0;
    }

    (&AdasPlantModel0_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&AdasPlantModel0_M)->solverInfo);

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
      (&AdasPlantModel0_M)->Timing.clockTick1++;
      if (!(&AdasPlantModel0_M)->Timing.clockTick1) {
        (&AdasPlantModel0_M)->Timing.clockTickH1++;
      }
    }

    rate_scheduler((&AdasPlantModel0_M));
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void AdasPlantModel0::AdasPlantModel0_derivatives()
{
  XDot_AdasPlantModel0_T *_rtXdot;
  _rtXdot = ((XDot_AdasPlantModel0_T *) (&AdasPlantModel0_M)->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/AdasPlantModel' */
  AdasPlantM_AdasPlantModel_Deriv(&AdasPlantModel0_B.AdasPlantModel,
    &AdasPlantModel0_DW.AdasPlantModel, &AdasPlantModel0_P.AdasPlantModel,
    &AdasPlantModel0_P, &AdasPlantModel0_X.AdasPlantModel,
    &_rtXdot->AdasPlantModel);

  /* End of Derivatives for SubSystem: '<Root>/AdasPlantModel' */
}

/* Model initialize function */
void AdasPlantModel0::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  AdasPlantModel0_P.AdasPlantModel.Saturation_LowerSat = rtMinusInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_e = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Negative5_UpperSat = rtInf;
  AdasPlantModel0_P.AdasPlantModel.FirstOrderHold_ErrTol = rtInf;
  AdasPlantModel0_P.AdasPlantModel.DeadZone_Start = rtMinusInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_c = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_g = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_n = rtInf;
  AdasPlantModel0_P.AdasPlantModel.DisallowNegativeBrakeTorque_Upp = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation1_UpperSat = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_k = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation1_UpperSat_j = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_h = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation1_UpperSat_f = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_f = rtInf;
  AdasPlantModel0_P.AdasPlantModel.Saturation_UpperSat_a = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&AdasPlantModel0_M)->solverInfo,
                          &(&AdasPlantModel0_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&AdasPlantModel0_M)->solverInfo, &rtmGetTPtr
                ((&AdasPlantModel0_M)));
    rtsiSetStepSizePtr(&(&AdasPlantModel0_M)->solverInfo, &(&AdasPlantModel0_M
                       )->Timing.stepSize0);
    rtsiSetdXPtr(&(&AdasPlantModel0_M)->solverInfo, &(&AdasPlantModel0_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&AdasPlantModel0_M)->solverInfo, (real_T **)
                         &(&AdasPlantModel0_M)->contStates);
    rtsiSetNumContStatesPtr(&(&AdasPlantModel0_M)->solverInfo,
      &(&AdasPlantModel0_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&AdasPlantModel0_M)->solverInfo,
      &(&AdasPlantModel0_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&AdasPlantModel0_M)->solverInfo,
      &(&AdasPlantModel0_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&AdasPlantModel0_M)->solverInfo,
      &(&AdasPlantModel0_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&AdasPlantModel0_M)->solverInfo, (&rtmGetErrorStatus
      ((&AdasPlantModel0_M))));
    rtsiSetRTModelPtr(&(&AdasPlantModel0_M)->solverInfo, (&AdasPlantModel0_M));
  }

  rtsiSetSimTimeStep(&(&AdasPlantModel0_M)->solverInfo, MAJOR_TIME_STEP);
  (&AdasPlantModel0_M)->intgData.y = (&AdasPlantModel0_M)->odeY;
  (&AdasPlantModel0_M)->intgData.f[0] = (&AdasPlantModel0_M)->odeF[0];
  (&AdasPlantModel0_M)->intgData.f[1] = (&AdasPlantModel0_M)->odeF[1];
  (&AdasPlantModel0_M)->intgData.f[2] = (&AdasPlantModel0_M)->odeF[2];
  (&AdasPlantModel0_M)->contStates = ((X_AdasPlantModel0_T *) &AdasPlantModel0_X);
  (&AdasPlantModel0_M)->periodicContStateIndices = ((int_T*)
    AdasPlantModel0_PeriodicIndX);
  (&AdasPlantModel0_M)->periodicContStateRanges = ((real_T*)
    AdasPlantModel0_PeriodicRngX);
  rtsiSetSolverData(&(&AdasPlantModel0_M)->solverInfo, static_cast<void *>
                    (&(&AdasPlantModel0_M)->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&(&AdasPlantModel0_M)->solverInfo, false);
  rtsiSetSolverName(&(&AdasPlantModel0_M)->solverInfo,"ode3");
  rtmSetTPtr((&AdasPlantModel0_M), &(&AdasPlantModel0_M)->Timing.tArray[0]);
  (&AdasPlantModel0_M)->Timing.stepSize0 = 0.0001;
  rtmSetFirstInitCond((&AdasPlantModel0_M), 1);
  AdasPlantModel0_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE_i =
    UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.Integrator_Reset_ZCE_d =
    UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.TriggeredSubsystem_e.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.TriggeredSubsystem_f.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.TriggeredSubsystem_d.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;
  AdasPlantModel0_PrevZCX.AdasPlantModel.TriggeredSubsystem.TriggeredSubsystem_Trig_ZCE
    = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/AdasPlantModel' */
  AdasPlantMo_AdasPlantModel_Init(&AdasPlantModel0_B.AdasPlantModel,
    &AdasPlantModel0_DW.AdasPlantModel, &AdasPlantModel0_P.AdasPlantModel,
    &AdasPlantModel0_P, &AdasPlantModel0_X.AdasPlantModel,
    &AdasPlantModel0_PrevZCX.AdasPlantModel);

  /* End of SystemInitialize for SubSystem: '<Root>/AdasPlantModel' */

  /* ConstCode for Outport: '<Root>/EngSpd' */
  AdasPlantModel0_Y.EngSpd = 0.0;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[3]{ 55, 56, 57 };

    real_T rootPeriodicContStateRanges[6]{ -3.1415926535897931,
      3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
      -3.1415926535897931, 3.1415926535897931 };

    (void) std::memcpy((void*)AdasPlantModel0_PeriodicIndX,
                       rootPeriodicContStateIndices,
                       3*sizeof(int_T));
    (void) std::memcpy((void*)AdasPlantModel0_PeriodicRngX,
                       rootPeriodicContStateRanges,
                       6*sizeof(real_T));
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond((&AdasPlantModel0_M))) {
    rtmSetFirstInitCond((&AdasPlantModel0_M), 0);
  }
}

/* Model terminate function */
void AdasPlantModel0::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
AdasPlantModel0::AdasPlantModel0() :
  AdasPlantModel0_U(),
  AdasPlantModel0_Y(),
  AdasPlantModel0_B(),
  AdasPlantModel0_DW(),
  AdasPlantModel0_X(),
  AdasPlantModel0_PrevZCX(),
  AdasPlantModel0_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
AdasPlantModel0::~AdasPlantModel0() = default;

/* Real-Time Model get method */
RT_MODEL_AdasPlantModel0_T * AdasPlantModel0::getRTM()
{
  return (&AdasPlantModel0_M);
}
