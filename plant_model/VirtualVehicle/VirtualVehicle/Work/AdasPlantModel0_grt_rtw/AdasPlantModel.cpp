/*
 * Code generation for system system '<Root>/AdasPlantModel'
 *
 * Model                      : AdasPlantModel0
 * Model version              : 6.83
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Wed Oct  8 00:15:24 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "rtwtypes.h"
#include "AdasPlantModel.h"
#include "AdasPlantModel0_types.h"
#include "AdasPlantModel0.h"
#include <cmath>
#include "AdasPlantModel0_private.h"
#include <cstring>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S526>/Clutch' */
const uint8_T AdasPlantModel0_IN_Locked{ 1U };

const uint8_T AdasPlantModel0_IN_Slipping{ 2U };

/* Named constants for Chart: '<S26>/Balancing' */
const uint8_T AdasPlantMod_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T AdasPlantModel0_IN_BalActive{ 1U };

const uint8_T AdasPlantModel0_IN_BalNotActive{ 2U };

const uint8_T AdasPlantModel0_IN_BalancingOFF{ 1U };

const uint8_T AdasPlantModel0_IN_BalancingON{ 2U };

/* Named constants for Chart: '<S30>/State_Machine' */
const uint8_T AdasPla_IN_CloseInvtrContactors{ 1U };

const uint8_T AdasPlan_IN_CloseChgrContactors{ 1U };

const uint8_T AdasPlan_IN_OpenInvtrContactors{ 2U };

const uint8_T AdasPlantM_IN_ClosePreChrgRly_l{ 1U };

const uint8_T AdasPlantMod_IN_ClosePreChrgRly{ 3U };

const uint8_T AdasPlantMode_IN_OpenPreChrgRly{ 4U };

const uint8_T AdasPlantModel0_IN_CC_Mode{ 1U };

const uint8_T AdasPlantModel0_IN_CV_Mode{ 2U };

const uint8_T AdasPlantModel0_IN_Charging{ 1U };

const uint8_T AdasPlantModel0_IN_Driving{ 2U };

const uint8_T AdasPlantModel0_IN_Fault{ 3U };

const uint8_T AdasPlantModel0_IN_Init_Mode{ 3U };

const uint8_T AdasPlantModel0_IN_OpenNegCntct{ 2U };

const uint8_T AdasPlantModel0_IN_OpenPosCntct{ 3U };

const uint8_T AdasPlantModel0_IN_PreChrgFlt{ 5U };

const uint8_T AdasPlantModel0_IN_Standby{ 4U };

const uint8_T AdasPlantModel_IN_CloseNegCntct{ 1U };

const uint8_T AdasPlantModel_IN_ClosePosCntct{ 2U };

const uint8_T AdasPlant_IN_OpenChgrContactors{ 2U };

/*
 * Output and update for iterator system:
 *    '<S108>/Kinpin axle moment and tie rod force'
 *    '<S109>/Kinpin axle moment and tie rod force'
 */
void AdasPlantModel0::Kinpinaxlemomentandtierodforce(const real_T rtu_Fy[2],
  const real_T rtu_Fz[2], const real_T rtu_Mz[2], const real_T rtu_nu[2], const
  real_T rtu_delta[2], real_T rtu_RackGain, real_T rty_Fsa_y[2], real_T
  rtp_HbLead, real_T rtp_KngpnOfst, real_T rtp_Lambda, real_T rtp_OvrlStrRatio,
  real_T rtp_StcLdRadius)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S108>/Kinpin axle moment and tie rod force' incorporates:
   *  ForEach: '<S112>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    real_T r_s;
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;

    /* MATLAB Function: '<S112>/MATLAB Function' incorporates:
     *  ForEachSliceSelector generated from: '<S112>/delta'
     *  ForEachSliceSelector generated from: '<S112>/nu'
     */
    r_s = rtp_KngpnOfst - rtp_StcLdRadius * std::tan(rtp_Lambda);
    tmp = std::cos(rtu_delta[ForEach_itr]);
    tmp_0 = std::cos(rtu_nu[ForEach_itr]);
    tmp_1 = std::cos(rtp_Lambda);

    /* ForEachSliceAssignment generated from: '<S112>/Fsa_y' incorporates:
     *  ForEachSliceSelector generated from: '<S112>/Fy'
     *  ForEachSliceSelector generated from: '<S112>/Fz'
     *  ForEachSliceSelector generated from: '<S112>/Mz'
     *  ForEachSliceSelector generated from: '<S112>/delta'
     *  ForEachSliceSelector generated from: '<S112>/nu'
     *  MATLAB Function: '<S112>/MATLAB Function'
     */
    rty_Fsa_y[ForEach_itr] = (((rtp_StcLdRadius * std::tan(rtu_nu[ForEach_itr])
      + rtp_HbLead) * tmp_0 * -rtu_Fy[ForEach_itr] * tmp + (-(rtu_Fz[ForEach_itr]
      * std::sin(rtp_Lambda) * r_s * std::sin(rtu_delta[ForEach_itr])) +
      rtu_Fz[ForEach_itr] * std::sin(rtu_nu[ForEach_itr]) * r_s * tmp)) + std::
      cos(std::sqrt(rtp_Lambda * rtp_Lambda + rtu_nu[ForEach_itr] *
                    rtu_nu[ForEach_itr])) * rtu_Mz[ForEach_itr]) /
      (0.15915494309189535 * rtp_OvrlStrRatio * rtu_RackGain * tmp_1 * tmp_0 *
       tmp_1 * tmp);
  }

  /* End of Outputs for SubSystem: '<S108>/Kinpin axle moment and tie rod force' */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/*
 * System initialize for enable system:
 *    '<S132>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 *    '<S219>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 */
void AdasPlantModel0::AdasPlant_EnabledSubsystem_Init
  (B_EnabledSubsystem_AdasPlantM_T *localB, P_EnabledSubsystem_AdasPlantM_T
   *localP)
{
  /* SystemInitialize for Outport: '<S140>/Fright' */
  localB->y = localP->Fright_Y0;
}

/*
 * Disable for enable system:
 *    '<S132>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 *    '<S219>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 */
void AdasPlantModel0::AdasPl_EnabledSubsystem_Disable
  (DW_EnabledSubsystem_AdasPlant_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S132>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 *    '<S219>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 */
void AdasPlantModel0::AdasPlantModel_EnabledSubsystem(real_T rtu_Enable, real_T
  rtu_In, real_T rtp_Frup, real_T rtp_k, B_EnabledSubsystem_AdasPlantM_T *localB,
  DW_EnabledSubsystem_AdasPlant_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S132>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S140>/Enable'
   */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->EnabledSubsystem_MODE = true;
    } else if (localDW->EnabledSubsystem_MODE) {
      AdasPl_EnabledSubsystem_Disable(localDW);
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* MATLAB Function: '<S140>/MATLAB Function' */
    localB->y = rt_powd_snf(rtp_Frup, 1.0 - std::exp(-rt_powd_snf(rtp_k, rtu_In)));
  }

  /* End of Outputs for SubSystem: '<S132>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S132>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 *    '<S219>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 */
void AdasPlantModel0::AdasPlan_EnabledSubsystem1_Init
  (B_EnabledSubsystem1_AdasPlant_T *localB, P_EnabledSubsystem1_AdasPlant_T
   *localP)
{
  /* SystemInitialize for Outport: '<S141>/Fleft' */
  localB->y = localP->Fleft_Y0;
}

/*
 * Disable for enable system:
 *    '<S132>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 *    '<S219>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 */
void AdasPlantModel0::AdasP_EnabledSubsystem1_Disable
  (DW_EnabledSubsystem1_AdasPlan_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S132>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 *    '<S219>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 */
void AdasPlantModel0::AdasPlantMode_EnabledSubsystem1(real_T rtu_Enable, real_T
  rtu_In, real_T rtp_Frup, real_T rtp_k, B_EnabledSubsystem1_AdasPlant_T *localB,
  DW_EnabledSubsystem1_AdasPlan_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S132>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S141>/Enable'
   */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->EnabledSubsystem1_MODE = true;
    } else if (localDW->EnabledSubsystem1_MODE) {
      AdasP_EnabledSubsystem1_Disable(localDW);
    }
  }

  if (localDW->EnabledSubsystem1_MODE) {
    /* MATLAB Function: '<S141>/MATLAB Function' */
    localB->y = -rt_powd_snf(rtp_Frup, 1.0 - std::exp(rt_powd_snf(rtp_k, rtu_In)));
  }

  /* End of Outputs for SubSystem: '<S132>/Enabled Subsystem1' */
}

/*
 * System initialize for trigger system:
 *    '<S132>/Triggered Subsystem'
 *    '<S133>/Triggered Subsystem'
 *    '<S219>/Triggered Subsystem'
 *    '<S220>/Triggered Subsystem'
 */
void AdasPlantModel0::AdasPla_TriggeredSubsystem_Init
  (B_TriggeredSubsystem_AdasPlan_T *localB, P_TriggeredSubsystem_AdasPlan_T
   *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S142>/In' incorporates:
   *  Outport: '<S142>/Out'
   */
  localB->In = localP->Out_Y0;

  /* SystemInitialize for Outport: '<S142>/xleft' */
  localB->y_a = localP->xleft_Y0;

  /* SystemInitialize for Outport: '<S142>/xright' */
  localB->y = localP->xright_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S132>/Triggered Subsystem'
 *    '<S133>/Triggered Subsystem'
 *    '<S219>/Triggered Subsystem'
 *    '<S220>/Triggered Subsystem'
 */
void AdasPlantModel0::AdasPlantMod_TriggeredSubsystem(real_T rtu_Trigger, real_T
  rtu_In, real_T rtu_Fright, real_T rtu_Fleft, real_T rtp_Frup, real_T rtp_k,
  B_TriggeredSubsystem_AdasPlan_T *localB, ZCE_TriggeredSubsystem_AdasPl_T
  *localZCE)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<S132>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S142>/Trigger'
   */
  if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&localZCE->TriggeredSubsystem_Trig_ZCE,
                       (rtu_Trigger));
    if (zcEvent != NO_ZCEVENT) {
      /* SignalConversion generated from: '<S142>/In' */
      localB->In = rtu_In;

      /* MATLAB Function: '<S142>/MATLAB Function' */
      localB->y_a = std::log(rtu_Fright / rtp_Frup + 1.0) * (1.0 / rtp_k);

      /* MATLAB Function: '<S142>/MATLAB Function1' */
      localB->y = std::log(1.0 - rtu_Fleft / rtp_Frup) * (-1.0 / rtp_k);
    }
  }

  /* End of Outputs for SubSystem: '<S132>/Triggered Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S154>/MATLAB Function1'
 *    '<S241>/MATLAB Function1'
 */
void AdasPlantModel0::AdasPlantModel0_MATLABFunction1(real_T rtu_u, real_T
  rtp_SptlAng, B_MATLABFunction1_AdasPlantMo_T *localB)
{
  real_T a;
  real_T b_a;
  a = std::sin(3.1415926535897931 - rtp_SptlAng);
  b_a = std::sin(rtu_u);
  localB->y = std::cos(3.1415926535897931 - rtp_SptlAng) / (1.0 - a * a * (b_a *
    b_a));
}

/* Function for Chart: '<S526>/Clutch' */
boolean_T AdasPlantModel0::AdasPlantModel0_detectSlip(real_T Tout, real_T Tfmaxs,
  B_Clutch_AdasPlantModel0_T *localB)
{
  localB->Tout = Tout;
  localB->Tfmaxs = Tfmaxs;

  /* Outputs for Function Call SubSystem: '<S527>/detectSlip' */
  /* RelationalOperator: '<S539>/Relational Operator' incorporates:
   *  Abs: '<S539>/Abs'
   */
  localB->RelationalOperator = (std::abs(localB->Tout) >= localB->Tfmaxs);

  /* End of Outputs for SubSystem: '<S527>/detectSlip' */
  return localB->RelationalOperator;
}

/* Function for Chart: '<S526>/Clutch' */
boolean_T AdasPlantModel0::AdasPlantModel0_detectLockup(real_T Tout, real_T
  Tfmaxs, real_T rtp_br, B_Clutch_AdasPlantModel0_T *localB,
  DW_Clutch_AdasPlantModel0_T *localDW, P_Clutch_AdasPlantModel0_T *localP)
{
  real_T rtb_Abs_d;
  localB->Tout_p = Tout;
  localB->Tfmaxs_p = Tfmaxs;

  /* Outputs for Function Call SubSystem: '<S527>/detectLockup' */
  /* Gain: '<S536>/Output Damping' incorporates:
   *  Constant: '<S530>/Constant'
   */
  rtb_Abs_d = rtp_br * localP->Constant_Value;

  /* CombinatorialLogic: '<S535>/Combinatorial  Logic' incorporates:
   *  Abs: '<S533>/Abs'
   *  Abs: '<S538>/Abs'
   *  RelationalOperator: '<S533>/Relational Operator'
   *  RelationalOperator: '<S538>/Relational Operator'
   *  Sum: '<S536>/Sum1'
   *  Sum: '<S536>/Sum2'
   *  UnaryMinus: '<S537>/Unary Minus'
   *  UnitDelay: '<S535>/Unit Delay'
   */
  localB->CombinatorialLogic = localP->CombinatorialLogic_table[(((std::abs
    (((0.0 - localB->Tout_p) - rtb_Abs_d) + rtb_Abs_d) >= localB->Tfmaxs_p) + (
    static_cast<uint32_T>(std::abs(-localB->Tout_p) <= localB->Tfmaxs_p) << 1)) <<
    1) + localDW->UnitDelay_DSTATE];

  /* Update for UnitDelay: '<S535>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->CombinatorialLogic;

  /* End of Outputs for SubSystem: '<S527>/detectLockup' */
  return localB->CombinatorialLogic;
}

/* System initialize for atomic system: '<S526>/Clutch' */
void AdasPlantModel0::AdasPlantModel0_Clutch_Init(real_T rtp_omegao,
  B_Clutch_AdasPlantModel0_T *localB, DW_Clutch_AdasPlantModel0_T *localDW,
  P_Clutch_AdasPlantModel0_T *localP, X_Clutch_AdasPlantModel0_T *localX)
{
  /* SystemInitialize for Function Call SubSystem: '<S527>/detectSlip' */
  /* SystemInitialize for RelationalOperator: '<S539>/Relational Operator' incorporates:
   *  Outport: '<S531>/yn'
   */
  localB->RelationalOperator = localP->yn_Y0;

  /* End of SystemInitialize for SubSystem: '<S527>/detectSlip' */

  /* SystemInitialize for Function Call SubSystem: '<S527>/detectLockup' */
  /* InitializeConditions for UnitDelay: '<S535>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for CombinatorialLogic: '<S535>/Combinatorial  Logic' incorporates:
   *  Outport: '<S530>/yn'
   */
  localB->CombinatorialLogic = localP->yn_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S527>/detectLockup' */

  /* SystemInitialize for IfAction SubSystem: '<S527>/Slipping' */
  /* InitializeConditions for Integrator: '<S529>/omega wheel' */
  localX->omegaWheel = rtp_omegao;

  /* End of SystemInitialize for SubSystem: '<S527>/Slipping' */
}

/* Outputs for atomic system: '<S526>/Clutch' */
void AdasPlantModel0::AdasPlantModel0_Clutch(real_T rtu_Tout, real_T rtu_Tfmaxs,
  real_T rtu_Tfmaxk, real_T rtp_omegao, real_T rtp_br, real_T rtp_Iyy, real_T
  rtp_OmegaTol, B_Clutch_AdasPlantModel0_T *localB, DW_Clutch_AdasPlantModel0_T *
  localDW, P_Clutch_AdasPlantModel0_T *localP, X_Clutch_AdasPlantModel0_T
  *localX)
{
  real_T rtb_OutputSum;
  if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    localDW->lastMajorTime = (&AdasPlantModel0_M)->Timing.t[0];

    /* Chart: '<S526>/Clutch' */
    if (localDW->is_active_c8_autolibshared == 0U) {
      localDW->is_active_c8_autolibshared = 1U;
      localX->omegaWheel = rtp_omegao;
      localDW->is_c8_autolibshared = AdasPlantModel0_IN_Slipping;

      /* Gain: '<S529>/Output Damping' incorporates:
       *  Integrator: '<S529>/omega wheel'
       */
      rtb_OutputSum = rtp_br * localX->omegaWheel;

      /* Merge: '<S527>/ Merge 3' incorporates:
       *  SignalConversion generated from: '<S529>/Myb'
       */
      localB->Myb = rtb_OutputSum;

      /* Merge: '<S527>/ Merge ' incorporates:
       *  Integrator: '<S529>/omega wheel'
       *  SignalConversion generated from: '<S529>/Omega'
       */
      localB->Omega = localX->omegaWheel;

      /* Gain: '<S529>/Output Inertia' incorporates:
       *  Gain: '<S529>/-4'
       *  Integrator: '<S529>/omega wheel'
       *  Product: '<S529>/Max Dynamic Friction Torque1'
       *  Sum: '<S529>/Output Sum'
       *  Trigonometry: '<S529>/Trigonometric Function'
       */
      localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel) *
        rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

      /* Merge: '<S527>/ Merge 1' incorporates:
       *  SignalConversion generated from: '<S529>/Omegadot'
       */
      localB->Omegadot = localB->OutputInertia;
      localDW->Slipping_entered = true;
      rtsiSetBlockStateForSolverChangedAtMajorStep(&(&AdasPlantModel0_M)
        ->solverInfo, true);
    } else if (localDW->is_c8_autolibshared == AdasPlantModel0_IN_Locked) {
      if (AdasPlantModel0_detectSlip(rtu_Tout, rtu_Tfmaxs, localB)) {
        localX->omegaWheel = 0.0;
        localDW->Locked_entered = false;
        localDW->is_c8_autolibshared = AdasPlantModel0_IN_Slipping;

        /* Gain: '<S529>/Output Damping' incorporates:
         *  Integrator: '<S529>/omega wheel'
         */
        rtb_OutputSum = rtp_br * localX->omegaWheel;

        /* Merge: '<S527>/ Merge 3' incorporates:
         *  SignalConversion generated from: '<S529>/Myb'
         */
        localB->Myb = rtb_OutputSum;

        /* Merge: '<S527>/ Merge ' incorporates:
         *  Integrator: '<S529>/omega wheel'
         *  SignalConversion generated from: '<S529>/Omega'
         */
        localB->Omega = localX->omegaWheel;

        /* Gain: '<S529>/Output Inertia' incorporates:
         *  Gain: '<S529>/-4'
         *  Integrator: '<S529>/omega wheel'
         *  Product: '<S529>/Max Dynamic Friction Torque1'
         *  Sum: '<S529>/Output Sum'
         *  Trigonometry: '<S529>/Trigonometric Function'
         */
        localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel)
          * rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

        /* Merge: '<S527>/ Merge 1' incorporates:
         *  SignalConversion generated from: '<S529>/Omegadot'
         */
        localB->Omegadot = localB->OutputInertia;
        localDW->Slipping_entered = true;
        rtsiSetBlockStateForSolverChangedAtMajorStep(&(&AdasPlantModel0_M)
          ->solverInfo, true);
      }

      /* case IN_Slipping: */
    } else if (AdasPlantModel0_detectLockup(rtu_Tout, rtu_Tfmaxs, rtp_br, localB,
                localDW, localP) && (std::abs(localB->Omega) <= rtp_OmegaTol)) {
      localDW->Slipping_entered = false;
      localDW->is_c8_autolibshared = AdasPlantModel0_IN_Locked;
      if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
          (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
        /* Merge: '<S527>/ Merge ' incorporates:
         *  Constant: '<S528>/Constant'
         *  SignalConversion generated from: '<S528>/Omega'
         */
        localB->Omega = localP->Constant_Value_p;

        /* Merge: '<S527>/ Merge 1' incorporates:
         *  Constant: '<S528>/Constant1'
         *  SignalConversion generated from: '<S528>/Omegadot'
         */
        localB->Omegadot = localP->Constant1_Value;

        /* Merge: '<S527>/ Merge 3' incorporates:
         *  Constant: '<S528>/Constant2'
         *  SignalConversion generated from: '<S528>/Myb'
         */
        localB->Myb = localP->Constant2_Value;
      }

      localDW->Locked_entered = true;
      rtsiSetBlockStateForSolverChangedAtMajorStep(&(&AdasPlantModel0_M)
        ->solverInfo, true);
    }

    /* End of Chart: '<S526>/Clutch' */
  }

  if (localDW->is_c8_autolibshared == AdasPlantModel0_IN_Locked) {
    if (!localDW->Locked_entered) {
      if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
          (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
        /* Merge: '<S527>/ Merge ' incorporates:
         *  Constant: '<S528>/Constant'
         *  SignalConversion generated from: '<S528>/Omega'
         */
        localB->Omega = localP->Constant_Value_p;

        /* Merge: '<S527>/ Merge 1' incorporates:
         *  Constant: '<S528>/Constant1'
         *  SignalConversion generated from: '<S528>/Omegadot'
         */
        localB->Omegadot = localP->Constant1_Value;

        /* Merge: '<S527>/ Merge 3' incorporates:
         *  Constant: '<S528>/Constant2'
         *  SignalConversion generated from: '<S528>/Myb'
         */
        localB->Myb = localP->Constant2_Value;
      }
    } else {
      localDW->Locked_entered = false;
    }

    /* case IN_Slipping: */
  } else if (!localDW->Slipping_entered) {
    /* Gain: '<S529>/Output Damping' incorporates:
     *  Integrator: '<S529>/omega wheel'
     */
    rtb_OutputSum = rtp_br * localX->omegaWheel;

    /* Merge: '<S527>/ Merge 3' incorporates:
     *  SignalConversion generated from: '<S529>/Myb'
     */
    localB->Myb = rtb_OutputSum;

    /* Merge: '<S527>/ Merge ' incorporates:
     *  Integrator: '<S529>/omega wheel'
     *  SignalConversion generated from: '<S529>/Omega'
     */
    localB->Omega = localX->omegaWheel;

    /* Gain: '<S529>/Output Inertia' incorporates:
     *  Gain: '<S529>/-4'
     *  Integrator: '<S529>/omega wheel'
     *  Product: '<S529>/Max Dynamic Friction Torque1'
     *  Sum: '<S529>/Output Sum'
     *  Trigonometry: '<S529>/Trigonometric Function'
     */
    localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel) *
      rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

    /* Merge: '<S527>/ Merge 1' incorporates:
     *  SignalConversion generated from: '<S529>/Omegadot'
     */
    localB->Omegadot = localB->OutputInertia;
  } else {
    localDW->Slipping_entered = false;
  }
}

/* Derivatives for atomic system: '<S526>/Clutch' */
void AdasPlantModel0::AdasPlantModel0_Clutch_Deriv(B_Clutch_AdasPlantModel0_T
  *localB, DW_Clutch_AdasPlantModel0_T *localDW, XDot_Clutch_AdasPlantModel0_T
  *localXdot)
{
  localXdot->omegaWheel = 0.0;
  if (localDW->is_c8_autolibshared == AdasPlantModel0_IN_Slipping) {
    /* Derivatives for Integrator: '<S529>/omega wheel' */
    localXdot->omegaWheel = localB->OutputInertia;
  }

  if (localDW->is_c8_autolibshared == AdasPlantModel0_IN_Locked) {
    if (localDW->Locked_entered) {
      localDW->Locked_entered = false;
    }

    /* case IN_Slipping: */
  } else if (localDW->Slipping_entered) {
    localDW->Slipping_entered = false;
  }
}

/* Function for Chart: '<S30>/State_Machine' */
void AdasPlantModel0::AdasPlantModel_MainStateMachine
  (B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
   *localDW, P_AdasPlantModel_AdasPlantMod_T *localP)
{
  switch (localDW->is_MainStateMachine) {
   case AdasPlantModel0_IN_Charging:
    if (localDW->FaultPresent) {
      localB->ChargeCurrentReq = 0.0F;
      localDW->is_Charging = AdasPlantMod_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_c2 == 2.0F) && (localDW->InvtrCntctState ==
                Contact::Close)) {
      localDW->is_Charging = AdasPlantMod_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Driving;
      localB->BMSState = 2.0F;
    } else if ((localP->Constant_Value_c2 != 1.0F) && (localDW->ChrgCntctState ==
                Contact::Init)) {
      localDW->is_Charging = AdasPlantMod_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Standby;
      localB->BMSState = 0.0F;
    } else {
      switch (localDW->is_Charging) {
       case AdasPlantModel0_IN_CC_Mode:
        /* Constant: '<S25>/Constant' */
        if (localP->Constant_Value_c2 != 1.0F) {
          localDW->is_Charging = AdasPlantModel0_IN_Init_Mode;
          localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
        } else if (localB->MaxCellVolt >=
                   localP->State_Machine_MaxCellVoltThrsld) {
          localDW->is_Charging = AdasPlantModel0_IN_CV_Mode;
        } else {
          localB->ChargeCurrentReq = std::fmin(localP->State_Machine_I_cc,
            localB->ChargeCurrentLimit);
        }
        break;

       case AdasPlantModel0_IN_CV_Mode:
        /* Constant: '<S25>/Constant' */
        if ((localP->Constant_Value_c2 != 1.0F) || (localB->ChargeCurrentReq <=
             localP->State_Machine_I_cc / localP->State_Machine_currentFactor))
        {
          localDW->is_Charging = AdasPlantModel0_IN_Init_Mode;
          localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
        } else {
          localB->ChargeCurrentReq -= (localB->MaxCellVolt -
            localP->State_Machine_MaxCellVoltThrsld) *
            localP->State_Machine_CV_Gain;
          localB->ChargeCurrentReq = std::fmin(localB->ChargeCurrentReq,
            localB->ChargeCurrentLimit);
        }
        break;

       default:
        /* Constant: '<S25>/Constant' */
        /* case IN_Init_Mode: */
        if ((localP->Constant_Value_c2 == 1.0F) && (localB->MaxCellVolt <
             localP->State_Machine_voltThreshold)) {
          localDW->is_Charging = AdasPlantModel0_IN_CC_Mode;
        }
        break;
      }
    }
    break;

   case AdasPlantModel0_IN_Driving:
    if (localDW->FaultPresent) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_c2 == 1.0F) && (localDW->ChrgCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Charging;
      localB->BMSState = 1.0F;
      localDW->is_Charging = AdasPlantModel0_IN_Init_Mode;
      localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
    } else if ((localP->Constant_Value_c2 != 2.0F) && (localDW->InvtrCntctState ==
                Contact::Init)) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Standby;
      localB->BMSState = 0.0F;
    }
    break;

   case AdasPlantModel0_IN_Fault:
    localB->BMSState = 3.0F;
    break;

   default:
    /* case IN_Standby: */
    if (localDW->FaultPresent) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_c2 == 1.0F) && (localDW->ChrgCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Charging;
      localB->BMSState = 1.0F;
      localDW->is_Charging = AdasPlantModel0_IN_Init_Mode;
      localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
    } else if ((localP->Constant_Value_c2 == 2.0F) && (localDW->InvtrCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Driving;
      localB->BMSState = 2.0F;
    }
    break;
  }
}

/* Function for Chart: '<S30>/State_Machine' */
void AdasPlantModel0::AdasPlan_InverterContactorState
  (B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
   *localDW, P_AdasPlantModel_AdasPlantMod_T *localP)
{
  if (localDW->is_InverterContactorState == AdasPla_IN_CloseInvtrContactors) {
    /* Constant: '<S25>/Constant' */
    if ((localP->Constant_Value_c2 != 2.0F) || localDW->FaultPresent) {
      localDW->is_CloseInvtrContactors = AdasPlantMod_IN_NO_ACTIVE_CHILD;
      localDW->is_InverterContactorState = AdasPlan_IN_OpenInvtrContactors;
      localDW->InvtrCntctState = Contact::Init;
      localDW->is_OpenInvtrContactors = AdasPlantM_IN_ClosePreChrgRly_l;
      localDW->temporalCounter_i3 = 0U;
    } else {
      switch (localDW->is_CloseInvtrContactors) {
       case AdasPlantModel_IN_CloseNegCntct:
        if (localDW->temporalCounter_i3 * 100 >=
            localP->State_Machine_contactorTime) {
          localDW->is_CloseInvtrContactors = AdasPlantMod_IN_ClosePreChrgRly;
          localDW->temporalCounter_i3 = 0U;
        }
        break;

       case AdasPlantModel_IN_ClosePosCntct:
        if (localDW->temporalCounter_i3 * 100 >=
            localP->State_Machine_contactorTime) {
          localDW->is_CloseInvtrContactors = AdasPlantMode_IN_OpenPreChrgRly;
          localDW->InvtrCntctState = Contact::Close;
        }
        break;

       case AdasPlantMod_IN_ClosePreChrgRly:
        if (localB->VoutInvtr / localB->PackVoltage >=
            localP->State_Machine_vRatio) {
          localDW->is_CloseInvtrContactors = AdasPlantModel_IN_ClosePosCntct;
          localDW->temporalCounter_i3 = 0U;
        } else if (localDW->temporalCounter_i3 >=
                   localP->State_Machine_timeoutContactor * 10) {
          localDW->is_CloseInvtrContactors = AdasPlantModel0_IN_PreChrgFlt;
        }
        break;

       case AdasPlantMode_IN_OpenPreChrgRly:
        localDW->InvtrCntctState = Contact::Close;
        break;

       default:
        /* case IN_PreChrgFlt: */
        break;
      }
    }

    /* Constant: '<S25>/Constant' */
    /* case IN_OpenInvtrContactors: */
  } else if ((localP->Constant_Value_c2 == 2.0F) && (localDW->ChrgCntctState ==
              Contact::Open) && (!localDW->FaultPresent)) {
    localDW->is_OpenInvtrContactors = AdasPlantMod_IN_NO_ACTIVE_CHILD;
    localDW->is_InverterContactorState = AdasPla_IN_CloseInvtrContactors;
    localDW->InvtrCntctState = Contact::Init;
    localDW->is_CloseInvtrContactors = AdasPlantModel_IN_CloseNegCntct;
    localDW->temporalCounter_i3 = 0U;
  } else {
    switch (localDW->is_OpenInvtrContactors) {
     case AdasPlantM_IN_ClosePreChrgRly_l:
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = AdasPlantModel0_IN_OpenPosCntct;
        localDW->temporalCounter_i3 = 0U;
      }
      break;

     case AdasPlantModel0_IN_OpenNegCntct:
      localDW->InvtrCntctState = Contact::Open;
      break;

     case AdasPlantModel0_IN_OpenPosCntct:
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = AdasPlantMode_IN_OpenPreChrgRly;
        localDW->temporalCounter_i3 = 0U;
      }
      break;

     default:
      /* case IN_OpenPreChrgRly: */
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = AdasPlantModel0_IN_OpenNegCntct;
        localDW->InvtrCntctState = Contact::Open;
      }
      break;
    }
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_div0protect(const real_T u[4], real_T tol,
  real_T y[4], real_T yabs[4])
{
  real_T x_data[4];
  real_T x;
  int32_T partialTrueCount_tmp;
  int32_T trueCount;
  int8_T tmp_data[4];
  int8_T tmp_data_0[4];
  yabs[0] = std::abs(u[0]);
  yabs[1] = std::abs(u[1]);
  yabs[2] = std::abs(u[2]);
  yabs[3] = std::abs(u[3]);
  x = 2.0 * tol;
  trueCount = 0;
  partialTrueCount_tmp = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (yabs[i] < tol) {
      tmp_data[trueCount] = static_cast<int8_T>(i);
      partialTrueCount_tmp = trueCount + 1;
      trueCount++;
    }
  }

  trueCount = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (yabs[i] < tol) {
      tmp_data_0[trueCount] = static_cast<int8_T>(i);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    real_T varargin_1;
    varargin_1 = yabs[tmp_data_0[trueCount]] / tol;
    x_data[trueCount] = x / (3.0 - varargin_1 * varargin_1);
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    yabs[tmp_data[trueCount]] = x_data[trueCount];
  }

  y[0] = yabs[0];
  y[1] = yabs[1];
  y[2] = yabs[2];
  y[3] = yabs[3];
  for (int32_T i{0}; i < 4; i++) {
    if (u[i] < 0.0) {
      y[i] = -yabs[i];
    }
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_sqrt(real_T x_data[], const int32_T
  x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[0] = std::sqrt(x_data[0]);
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_abs(const real_T x_data[], const int32_T
  *x_size, real_T y_data[], int32_T *y_size)
{
  int32_T b;
  *y_size = *x_size;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    y_data[k] = std::abs(x_data[k]);
  }
}

void AdasPlantModel0::Ada_binary_expand_op_nxejpfz5mi(real_T in1[4], const
  int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], const real_T
  in4[4], real_T in5, const real_T in6[4], real_T in7, const real_T in8[108])
{
  real_T in4_data[4];
  real_T tmp_data[4];
  int32_T loop_ub;
  int32_T stride_0_0_tmp;
  int32_T stride_1_0;
  int32_T tmp;
  int32_T tmp_size;
  loop_ub = *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in4_data[tmp_size] = in4[in2_data[tmp_size]];
  }

  AdasPlantModel0_abs(in4_data, in2_size, tmp_data, &tmp_size);
  stride_0_0_tmp = (*in2_size != 1);
  stride_1_0 = (tmp_size != 1);
  loop_ub = *in2_size == 1 ? *in2_size == 1 ? tmp_size == 1 ? *in2_size :
    tmp_size : *in2_size : *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    tmp = in2_data[tmp_size * stride_0_0_tmp];
    in1[static_cast<int8_T>(in2_data[tmp_size])] = (in6[tmp] * in5 / in7 +
      in3[tmp] / tmp_data[tmp_size * stride_1_0]) * in8[tmp * 27 + 22];
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

void AdasPlantModel0::AdasPlant_binary_expand_op_nxej(real_T in1[4], const
  int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], real_T in4)
{
  real_T in3_data[4];
  real_T tmp_data[4];
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T tmp_size;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' */
  loop_ub = *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in3_data[tmp_size] = in3[in2_data[tmp_size]];
  }

  AdasPlantModel0_abs(in3_data, in2_size, tmp_data, &tmp_size);
  loop_ub = tmp_size == 1 ? *in2_size : tmp_size;
  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (tmp_size != 1);
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in3_data[tmp_size] = tmp_data[tmp_size * stride_1_0] / in4 *
      in1[in2_data[tmp_size * stride_0_0]];
  }

  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in1[static_cast<int8_T>(in2_data[tmp_size])] = in3_data[tmp_size];
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_div0protect_f(const real_T u[4], real_T y
  [4])
{
  real_T y_data[4];
  int32_T partialTrueCount_tmp;
  int32_T trueCount;
  int8_T tmp_data[4];
  int8_T tmp_data_0[4];
  int8_T tmp_data_1[4];
  int8_T tmp_data_2[4];
  y[0] = std::abs(u[0]);
  y[1] = std::abs(u[1]);
  y[2] = std::abs(u[2]);
  y[3] = std::abs(u[3]);
  trueCount = 0;
  partialTrueCount_tmp = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (y[i] < 0.0001) {
      tmp_data[trueCount] = static_cast<int8_T>(i);
      partialTrueCount_tmp = trueCount + 1;
      trueCount++;
    }
  }

  trueCount = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (y[i] < 0.0001) {
      tmp_data_0[trueCount] = static_cast<int8_T>(i);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    real_T varargin_1;
    varargin_1 = y[tmp_data_0[trueCount]] / 0.0001;
    y_data[trueCount] = 0.0002 / (3.0 - varargin_1 * varargin_1);
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    y[tmp_data[trueCount]] = y_data[trueCount];
  }

  trueCount = 0;
  partialTrueCount_tmp = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (u[i] < 0.0) {
      tmp_data_1[trueCount] = static_cast<int8_T>(i);
      partialTrueCount_tmp = trueCount + 1;
      trueCount++;
    }
  }

  trueCount = 0;
  for (int32_T i{0}; i < 4; i++) {
    if (u[i] < 0.0) {
      tmp_data_2[trueCount] = static_cast<int8_T>(i);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    y_data[trueCount] = -y[tmp_data_2[trueCount]];
  }

  for (trueCount = 0; trueCount < partialTrueCount_tmp; trueCount++) {
    y[tmp_data_1[trueCount]] = y_data[trueCount];
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
boolean_T AdasPlantModel0::AdasPlantModel0_any(const boolean_T x[4])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_atan(real_T x_data[], const int32_T
  *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::atan(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_cos(real_T x_data[], const int32_T *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::cos(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_sqrt_h(real_T x_data[], const int32_T
  *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::sqrt(x_data[k]);
  }
}

void AdasPlantModel0::AdasPlantM_binary_expand_op_nxe(real_T in1_data[], int32_T
  *in1_size, real_T in2, real_T in3, const real_T in4[4], const real_T in5[4],
  const int32_T in6_data[], const int32_T *in6_size, const real_T in7_data[],
  const int32_T *in7_size, real_T in8, const real_T in9_data[], const int32_T
  *in9_size)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' */
  i = *in9_size == 1 ? *in7_size : *in9_size;
  loop_ub = i == 1 ? *in6_size : i;
  *in1_size = loop_ub;
  stride_0_0 = (*in6_size != 1);
  stride_1_0 = (*in7_size != 1);
  stride_2_0 = (*in9_size != 1);
  for (i = 0; i < loop_ub; i++) {
    int32_T tmp;
    tmp = in6_data[i * stride_0_0];
    in1_data[i] = (in4[tmp] * in3 + 1.0) * in2 * in5[tmp] * (in9_data[i *
      stride_2_0] * in8 + in7_data[i * stride_1_0]);
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magicsin(const real_T D[4], real_T C,
  const real_T B[4], real_T E, const real_T u[4], real_T y[4])
{
  real_T y_0;
  y_0 = B[0] * u[0];
  y[0] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E) * C) * D[0];
  y_0 = B[1] * u[1];
  y[1] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E) * C) * D[1];
  y_0 = B[2] * u[2];
  y[2] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E) * C) * D[2];
  y_0 = B[3] * u[3];
  y[3] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E) * C) * D[3];
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magiccos(real_T C, const real_T B[4],
  const real_T E[4], const real_T u[4], real_T y[4])
{
  real_T y_0;
  y_0 = B[0] * u[0];
  y[0] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[0]) * C);
  y_0 = B[1] * u[1];
  y[1] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[1]) * C);
  y_0 = B[2] * u[2];
  y[2] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[2]) * C);
  y_0 = B[3] * u[3];
  y[3] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[3]) * C);
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magiccos_l(real_T C, const real_T B[4],
  const real_T E[4], real_T y[4])
{
  y[0] = std::cos(std::atan(B[0] * 0.0 - (B[0] * 0.0 - std::atan(B[0] * 0.0)) *
    E[0]) * C);
  y[1] = std::cos(std::atan(B[1] * 0.0 - (B[1] * 0.0 - std::atan(B[1] * 0.0)) *
    E[1]) * C);
  y[2] = std::cos(std::atan(B[2] * 0.0 - (B[2] * 0.0 - std::atan(B[2] * 0.0)) *
    E[2]) * C);
  y[3] = std::cos(std::atan(B[3] * 0.0 - (B[3] * 0.0 - std::atan(B[3] * 0.0)) *
    E[3]) * C);
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magicsin_d(const real_T D[4], const real_T
  C[4], const real_T B[4], const real_T E[4], const real_T u[4], real_T y[4])
{
  real_T y_0;
  y_0 = B[0] * u[0];
  y[0] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[0]) * C[0]) * D[0];
  y_0 = B[1] * u[1];
  y[1] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[1]) * C[1]) * D[1];
  y_0 = B[2] * u[2];
  y[2] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[2]) * C[2]) * D[2];
  y_0 = B[3] * u[3];
  y[3] = std::sin(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[3]) * C[3]) * D[3];
}

void AdasPlantModel0::AdasPlantMo_binary_expand_op_nx(real_T in1_data[], int32_T
  *in1_size, const real_T in2[4], const real_T in3[4], const real_T in4[4],
  const int32_T in5_data[], const int32_T *in5_size, const real_T in6[4], const
  real_T in7[4])
{
  real_T in6_data[4];
  real_T tmp_data[4];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0_tmp;
  int32_T tmp;
  int32_T tmp_size;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' */
  loop_ub = *in5_size;
  for (i = 0; i < loop_ub; i++) {
    in6_data[i] = in6[in5_data[i]];
  }

  AdasPlantModel0_abs(in6_data, in5_size, tmp_data, &tmp_size);
  i = *in5_size == 1 ? tmp_size : *in5_size;
  loop_ub = i == 1 ? *in5_size : i;
  *in1_size = loop_ub;
  stride_0_0_tmp = (*in5_size != 1);
  tmp_size = (tmp_size != 1);
  for (i = 0; i < loop_ub; i++) {
    tmp = in5_data[i * stride_0_0_tmp];
    in1_data[i] = in2[tmp] * 2.0 / 3.1415926535897931 * in3[tmp] * in4[tmp] /
      (in7[tmp] * 0.0001 + tmp_data[i * tmp_size]);
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_acos(real_T x_data[], const int32_T
  *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::acos(x_data[k]);
  }
}

void AdasPlantModel0::AdasPlantMod_binary_expand_op_n(real_T in1[4], const
  int8_T in2_data[], const real_T in3[4], const int32_T in4_data[], const
  int32_T *in4_size, const real_T in5[108], const int8_T in6[2], const real_T
  in7[4], const real_T in8[4], const real_T in9[4])
{
  int32_T loop_ub;
  int32_T stride_0_0_tmp;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S510>/Vector Concatenate'
   */
  stride_0_0_tmp = (*in4_size != 1);
  loop_ub = *in4_size == 1 ? *in4_size == 1 ? in6[0] == 1 ? *in4_size :
    static_cast<int32_T>(in6[0]) : *in4_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    int32_T tmp;
    tmp = in4_data[i * stride_0_0_tmp];
    in1[in2_data[i]] = (in5[tmp * 27 + 11] * (in3[tmp] * 0.0) + in7[tmp]) -
      in8[tmp] / in9[tmp];
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

void AdasPlantModel0::AdasPlantModel_binary_expand_op(real_T in1[4], const
  int8_T in2_data[], const real_T in3[4], const int32_T in4_data[], const
  int32_T *in4_size, const real_T in5[108], const int8_T in6[2], const real_T
  in7[4], const real_T in8[4], const real_T in9[4], const real_T in10[4], const
  real_T in11[36])
{
  int32_T loop_ub;
  int32_T stride_0_0_tmp;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S510>/Vector Concatenate'
   */
  stride_0_0_tmp = (*in4_size != 1);
  loop_ub = *in4_size == 1 ? *in4_size == 1 ? in6[0] == 1 ? *in4_size :
    static_cast<int32_T>(in6[0]) : *in4_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    int32_T tmp;
    int32_T tmp_0;
    tmp = in4_data[i * stride_0_0_tmp];
    tmp_0 = tmp * 9;
    in1[in2_data[i]] = (((in7[tmp] * in8[tmp] - in9[tmp]) / in10[tmp] *
                         in11[tmp_0] + in5[tmp * 27 + 11] * (in3[tmp] * 0.0)) +
                        in11[tmp_0 + 4]) - 1.0;
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_rollingMoment(const real_T Fx[4], const
  real_T Vcx[4], const real_T Fz[4], const real_T press[4], const real_T
  b_gamma[4], real_T Vo, real_T Ro, real_T Fzo, real_T pio, real_T b_QSY1,
  real_T b_QSY2, real_T b_QSY3, real_T b_QSY4, real_T b_QSY5, real_T b_QSY6,
  real_T b_QSY7, real_T b_QSY8, const real_T lam_My[4], real_T My[4])
{
  real_T Ro_0;
  real_T x;
  real_T x_tmp;
  Ro_0 = -Ro * Fzo;
  x_tmp = Fz[0] / Fzo;
  x = Vcx[0] / Vo;
  My[0] = ((((Fx[0] / Fzo * b_QSY2 + b_QSY1) + b_QSY3 * std::abs(x)) + b_QSY4 *
            rt_powd_snf(x, 4.0)) + (b_QSY6 * x_tmp + b_QSY5) * b_gamma[0] *
           b_gamma[0]) * (Ro_0 * lam_My[0]) * (rt_powd_snf(std::fmax(press[0] /
    pio, 0.05), b_QSY8) * rt_powd_snf(std::fmax(x_tmp, 0.05), b_QSY7));
  x_tmp = Fz[1] / Fzo;
  x = Vcx[1] / Vo;
  My[1] = ((((Fx[1] / Fzo * b_QSY2 + b_QSY1) + b_QSY3 * std::abs(x)) + b_QSY4 *
            rt_powd_snf(x, 4.0)) + (b_QSY6 * x_tmp + b_QSY5) * b_gamma[1] *
           b_gamma[1]) * (Ro_0 * lam_My[1]) * (rt_powd_snf(std::fmax(press[1] /
    pio, 0.05), b_QSY8) * rt_powd_snf(std::fmax(x_tmp, 0.05), b_QSY7));
  x_tmp = Fz[2] / Fzo;
  x = Vcx[2] / Vo;
  My[2] = ((((Fx[2] / Fzo * b_QSY2 + b_QSY1) + b_QSY3 * std::abs(x)) + b_QSY4 *
            rt_powd_snf(x, 4.0)) + (b_QSY6 * x_tmp + b_QSY5) * b_gamma[2] *
           b_gamma[2]) * (Ro_0 * lam_My[2]) * (rt_powd_snf(std::fmax(press[2] /
    pio, 0.05), b_QSY8) * rt_powd_snf(std::fmax(x_tmp, 0.05), b_QSY7));
  x_tmp = Fz[3] / Fzo;
  x = Vcx[3] / Vo;
  My[3] = ((((Fx[3] / Fzo * b_QSY2 + b_QSY1) + b_QSY3 * std::abs(x)) + b_QSY4 *
            rt_powd_snf(x, 4.0)) + (b_QSY6 * x_tmp + b_QSY5) * b_gamma[3] *
           b_gamma[3]) * (Ro_0 * lam_My[3]) * (rt_powd_snf(std::fmax(press[3] /
    pio, 0.05), b_QSY8) * rt_powd_snf(std::fmax(x_tmp, 0.05), b_QSY7));
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magiccos_l1m(const real_T D[4], real_T C,
  const real_T B[4], const real_T E[4], const real_T u[4], real_T y[4])
{
  real_T y_0;
  y_0 = B[0] * u[0];
  y[0] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[0]) * C) * D[0];
  y_0 = B[1] * u[1];
  y[1] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[1]) * C) * D[1];
  y_0 = B[2] * u[2];
  y[2] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[2]) * C) * D[2];
  y_0 = B[3] * u[3];
  y[3] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * E[3]) * C) * D[3];
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_magiccos_l1(const real_T D[4], const
  real_T C[4], const real_T B[4], const real_T u[4], real_T y[4])
{
  real_T y_0;
  y_0 = B[0] * u[0];
  y[0] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * 0.0) * C[0]) * D[0];
  y_0 = B[1] * u[1];
  y[1] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * 0.0) * C[1]) * D[1];
  y_0 = B[2] * u[2];
  y[2] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * 0.0) * C[2]) * D[2];
  y_0 = B[3] * u[3];
  y[3] = std::cos(std::atan(y_0 - (y_0 - std::atan(y_0)) * 0.0) * C[3]) * D[3];
}

/* Function for MATLAB Function: '<S513>/Magic Tire Const Input' */
void AdasPlantModel0::AdasPlantModel0_vdyncsmtire(const real_T Omega[4], const
  real_T Vx[4], const real_T Vy[4], const real_T psidot[4], real_T b_gamma[4],
  real_T press[4], const real_T scaleFactors[108], const real_T rhoz[4], real_T
  b_turnslip, real_T b_PRESMAX, real_T b_PRESMIN, real_T b_FZMAX, real_T b_FZMIN,
  real_T b_VXLOW, real_T b_KPUMAX, real_T b_KPUMIN, real_T b_ALPMAX, real_T
  b_ALPMIN, real_T b_CAMMIN, real_T b_CAMMAX, real_T b_LONGVL, real_T
  b_UNLOADED_RADIUS, real_T b_RIM_RADIUS, real_T b_NOMPRES, real_T b_FNOMIN,
  real_T b_VERTICAL_STIFFNESS, real_T b_DREFF, real_T b_BREFF, real_T b_FREFF,
  real_T b_Q_RE0, real_T b_Q_V1, real_T b_Q_V2, real_T b_Q_FZ1, real_T b_Q_FZ2,
  real_T b_Q_FCX, real_T b_Q_FCY, real_T b_PFZ1, real_T b_Q_FCY2, real_T
  b_BOTTOM_OFFST, real_T b_BOTTOM_STIFF, real_T b_PCX1, real_T b_PDX1, real_T
  b_PDX2, real_T b_PDX3, real_T b_PEX1, real_T b_PEX2, real_T b_PEX3, real_T
  b_PEX4, real_T b_PKX1, real_T b_PKX2, real_T b_PKX3, real_T b_PHX1, real_T
  b_PHX2, real_T b_PVX1, real_T b_PVX2, real_T b_PPX1, real_T b_PPX2, real_T
  b_PPX3, real_T b_PPX4, real_T b_RBX1, real_T b_RBX2, real_T b_RBX3, real_T
  b_RCX1, real_T b_REX1, real_T b_REX2, real_T b_QSX2, real_T b_QSX3, real_T
  b_QSX4, real_T b_QSX5, real_T b_QSX6, real_T b_QSX7, real_T b_QSX8, real_T
  b_QSX9, real_T b_QSX10, real_T b_QSX11, real_T b_PPMX1, real_T b_PCY1, real_T
  b_PDY1, real_T b_PDY2, real_T b_PDY3, real_T b_PEY1, real_T b_PEY2, real_T
  b_PEY4, real_T b_PEY5, real_T b_PKY1, real_T b_PKY2, real_T b_PKY3, real_T
  b_PKY4, real_T b_PKY5, real_T b_PKY6, real_T b_PKY7, real_T b_PVY3, real_T
  b_PVY4, real_T b_PPY1, real_T b_PPY2, real_T b_PPY3, real_T b_PPY4, real_T
  b_PPY5, real_T b_RBY1, real_T b_RBY2, real_T b_RBY4, real_T b_RCY1, real_T
  b_REY1, real_T b_REY2, real_T b_RHY1, real_T b_RHY2, real_T b_RVY3, real_T
  b_RVY4, real_T b_RVY5, real_T b_RVY6, real_T b_QSY1, real_T b_QSY2, real_T
  b_QSY3, real_T b_QSY4, real_T b_QSY5, real_T b_QSY6, real_T b_QSY7, real_T
  b_QSY8, real_T b_QBZ1, real_T b_QBZ2, real_T b_QBZ3, real_T b_QBZ5, real_T
  b_QBZ6, real_T b_QBZ9, real_T b_QBZ10, real_T b_QCZ1, real_T b_QDZ1, real_T
  b_QDZ2, real_T b_QDZ4, real_T b_QDZ8, real_T b_QDZ9, real_T b_QDZ10, real_T
  b_QDZ11, real_T b_QEZ1, real_T b_QEZ2, real_T b_QEZ3, real_T b_QEZ5, real_T
  b_QHZ3, real_T b_QHZ4, real_T b_PPZ1, real_T b_PPZ2, real_T b_SSZ2, real_T
  b_SSZ3, real_T b_SSZ4, real_T b_PDXP1, real_T b_PDXP2, real_T b_PDXP3, real_T
  b_PKYP1, real_T b_PDYP1, real_T b_PDYP2, real_T b_PDYP3, real_T b_PDYP4,
  real_T b_PHYP1, real_T b_PHYP2, real_T b_PHYP3, real_T b_PHYP4, real_T b_PECP1,
  real_T b_PECP2, real_T b_QDTP1, real_T b_QCRP1, real_T b_QCRP2, real_T b_QBRP1,
  real_T b_QDRP1, real_T b_QDRP2, real_T b_WIDTH, real_T b_Q_RA1, real_T b_Q_RA2,
  real_T b_Q_RB1, real_T b_Q_RB2, real_T b_QSX12, real_T b_QSX13, real_T b_QSX14,
  real_T b_Q_FZ3, real_T b_LONGITUDINAL_STIFFNESS, real_T b_LATERAL_STIFFNESS,
  real_T b_PCFX1, real_T b_PCFX2, real_T b_PCFX3, real_T b_PCFY1, real_T b_PCFY2,
  real_T b_PCFY3, const real_T Fx_ext[4], const real_T Fy_ext[4], real_T Fz_ext
  [4], real_T vertType, real_T Fx[4], real_T Fy[4], real_T Mx[4], real_T My[4],
  real_T Mz[4], real_T Re[4], real_T kappa[4], real_T alpha[4], real_T sig_x[4],
  real_T sig_y[4], real_T patch_a[4], real_T patch_b[4])
{
  real_T zeta[36];
  real_T Bykappa[4];
  real_T Eykappa[4];
  real_T FzUnSat[4];
  real_T Kygammao[4];
  real_T Mzphiinf[4];
  real_T R_omega[4];
  real_T SHy[4];
  real_T SHykappa[4];
  real_T Vs[4];
  real_T Vsy[4];
  real_T b_x[4];
  real_T dc_data[4];
  real_T dfz[4];
  real_T epsilon_gamma[4];
  real_T gamma_star[4];
  real_T kappa_x[4];
  real_T lam_Cz[4];
  real_T lam_Kygamma[4];
  real_T lam_muy[4];
  real_T phi[4];
  real_T phi_t[4];
  real_T rhoz_data[4];
  real_T rhoz_data_0[4];
  real_T tmpDrphiVar_data[4];
  real_T Bykappa_tmp;
  real_T Dx_tmp;
  real_T Dx_tmp_0;
  real_T Dx_tmp_1;
  real_T Dx_tmp_2;
  real_T Fzo_prime_idx_0;
  real_T Fzo_prime_idx_1;
  real_T Fzo_prime_idx_2;
  real_T Fzo_prime_idx_3;
  real_T R_omega_0;
  real_T Vs_0;
  real_T Vs_tmp;
  real_T Vs_tmp_0;
  real_T Vs_tmp_1;
  real_T Vsy_tmp;
  real_T Vsy_tmp_0;
  real_T Vsy_tmp_1;
  real_T a_tmp;
  real_T ab_idx_0;
  real_T d_y;
  real_T dfz_0;
  real_T dpi_idx_0;
  real_T dpi_idx_1;
  real_T dpi_idx_2;
  real_T dpi_idx_3;
  real_T ec_data;
  real_T gamma_star_tmp;
  real_T gamma_star_tmp_0;
  real_T gamma_star_tmp_1;
  real_T gamma_star_tmp_2;
  real_T lam_Cz_0;
  real_T lam_Cz_tmp;
  real_T lam_Cz_tmp_tmp;
  real_T lam_muy_prime_idx_0;
  real_T lam_muy_prime_idx_1;
  real_T lam_muy_prime_idx_2;
  real_T lam_muy_prime_idx_3;
  real_T mu_y_idx_0;
  real_T mu_y_idx_1;
  real_T mu_y_idx_2;
  real_T mu_y_tmp;
  real_T x_idx_0;
  int32_T bc_tmp_data[4];
  int32_T tmp_data[4];
  int32_T tmp_data_0[4];
  int32_T tmp_data_2[4];
  int32_T ec_size[2];
  int32_T i;
  int32_T partialTrueCount;
  int32_T tmp_size;
  int32_T tmp_size_0;
  int32_T trueCount;
  int8_T bc_data[4];
  int8_T tmp_data_1[4];
  int8_T lb[2];
  boolean_T nomslipinds[4];
  boolean_T tempInds[4];
  boolean_T nomslipinds_0;
  Fx[0] = scaleFactors[1];
  lam_muy[0] = scaleFactors[2];
  Fx[1] = scaleFactors[28];
  lam_muy[1] = scaleFactors[29];
  Fx[2] = scaleFactors[55];
  lam_muy[2] = scaleFactors[56];
  Fx[3] = scaleFactors[82];
  lam_muy[3] = scaleFactors[83];
  AdasPlantModel0_div0protect(Vx, b_VXLOW, R_omega, Vsy);
  for (i = 0; i < 4; i++) {
    dpi_idx_0 = b_gamma[i];
    if (dpi_idx_0 < b_CAMMIN) {
      dpi_idx_0 = b_CAMMIN;
      b_gamma[i] = b_CAMMIN;
    }

    if (dpi_idx_0 > b_CAMMAX) {
      b_gamma[i] = b_CAMMAX;
    }

    dpi_idx_0 = press[i];
    if (dpi_idx_0 < b_PRESMIN) {
      dpi_idx_0 = b_PRESMIN;
      press[i] = b_PRESMIN;
    }

    if (dpi_idx_0 > b_PRESMAX) {
      press[i] = b_PRESMAX;
    }

    if (Fx[i] <= 0.0) {
      Fx[i] = 2.2204460492503131E-16;
    }

    if (lam_muy[i] <= 0.0) {
      lam_muy[i] = 2.2204460492503131E-16;
    }
  }

  dpi_idx_0 = (press[0] - b_NOMPRES) / b_NOMPRES;
  dpi_idx_1 = (press[1] - b_NOMPRES) / b_NOMPRES;
  dpi_idx_2 = (press[2] - b_NOMPRES) / b_NOMPRES;
  dpi_idx_3 = (press[3] - b_NOMPRES) / b_NOMPRES;
  Fzo_prime_idx_0 = scaleFactors[0] * b_FNOMIN;
  Fzo_prime_idx_1 = scaleFactors[27] * b_FNOMIN;
  Fzo_prime_idx_2 = scaleFactors[54] * b_FNOMIN;
  Fzo_prime_idx_3 = scaleFactors[81] * b_FNOMIN;
  if (vertType == 2.0) {
    if (b_Q_FZ1 == 0.0) {
      a_tmp = b_VERTICAL_STIFFNESS * b_UNLOADED_RADIUS / b_FNOMIN;
      mu_y_idx_1 = a_tmp * a_tmp - 4.0 * b_Q_FZ2;
      if (mu_y_idx_1 < 0.0) {
        b_Q_FZ1 = b_Q_FZ2 * 0.0;
      }

      trueCount = 0;
      nomslipinds_0 = !(mu_y_idx_1 < 0.0);
      if (nomslipinds_0) {
        for (i = 0; i < 1; i++) {
          trueCount++;
        }
      }

      ec_size[0] = 1;
      ec_size[1] = trueCount;
      if (trueCount - 1 >= 0) {
        ec_data = mu_y_idx_1;
      }

      AdasPlantModel0_sqrt(&ec_data, ec_size);
      if (nomslipinds_0) {
        b_Q_FZ1 = ec_data;
      }
    }

    a_tmp = b_RIM_RADIUS + b_BOTTOM_OFFST;
    ec_data = b_Q_FCX * Fx_ext[0] / b_FNOMIN;
    d_y = ec_data * ec_data;
    ec_data = b_Q_FCY * Fy_ext[0] / b_FNOMIN;
    lam_muy_prime_idx_3 = ec_data * ec_data;
    ec_data = rhoz[0] / b_UNLOADED_RADIUS;
    Fz_ext[0] = std::fmax((((b_Q_V2 * std::abs(Omega[0]) * b_UNLOADED_RADIUS /
      b_LONGVL + 1.0) - d_y) - lam_muy_prime_idx_3) * ((b_Q_FZ3 * b_gamma[0] *
      b_gamma[0] + b_Q_FZ1) * rhoz[0] / b_UNLOADED_RADIUS + ec_data * ec_data *
      b_Q_FZ2) * (b_PFZ1 * dpi_idx_0 + 1.0) * Fzo_prime_idx_0, (a_tmp -
      (b_UNLOADED_RADIUS + rhoz[0]) / std::cos(b_gamma[0])) * b_BOTTOM_STIFF);
    ec_data = b_Q_FCX * Fx_ext[1] / b_FNOMIN;
    d_y = ec_data * ec_data;
    ec_data = b_Q_FCY * Fy_ext[1] / b_FNOMIN;
    lam_muy_prime_idx_3 = ec_data * ec_data;
    ec_data = rhoz[1] / b_UNLOADED_RADIUS;
    Fz_ext[1] = std::fmax((((b_Q_V2 * std::abs(Omega[1]) * b_UNLOADED_RADIUS /
      b_LONGVL + 1.0) - d_y) - lam_muy_prime_idx_3) * ((b_Q_FZ3 * b_gamma[1] *
      b_gamma[1] + b_Q_FZ1) * rhoz[1] / b_UNLOADED_RADIUS + ec_data * ec_data *
      b_Q_FZ2) * (b_PFZ1 * dpi_idx_1 + 1.0) * Fzo_prime_idx_1, (a_tmp -
      (b_UNLOADED_RADIUS + rhoz[1]) / std::cos(b_gamma[1])) * b_BOTTOM_STIFF);
    ec_data = b_Q_FCX * Fx_ext[2] / b_FNOMIN;
    d_y = ec_data * ec_data;
    ec_data = b_Q_FCY * Fy_ext[2] / b_FNOMIN;
    lam_muy_prime_idx_3 = ec_data * ec_data;
    ec_data = rhoz[2] / b_UNLOADED_RADIUS;
    Fz_ext[2] = std::fmax((((b_Q_V2 * std::abs(Omega[2]) * b_UNLOADED_RADIUS /
      b_LONGVL + 1.0) - d_y) - lam_muy_prime_idx_3) * ((b_Q_FZ3 * b_gamma[2] *
      b_gamma[2] + b_Q_FZ1) * rhoz[2] / b_UNLOADED_RADIUS + ec_data * ec_data *
      b_Q_FZ2) * (b_PFZ1 * dpi_idx_2 + 1.0) * Fzo_prime_idx_2, (a_tmp -
      (b_UNLOADED_RADIUS + rhoz[2]) / std::cos(b_gamma[2])) * b_BOTTOM_STIFF);
    ec_data = b_Q_FCX * Fx_ext[3] / b_FNOMIN;
    d_y = ec_data * ec_data;
    ec_data = b_Q_FCY * Fy_ext[3] / b_FNOMIN;
    lam_muy_prime_idx_3 = ec_data * ec_data;
    ec_data = rhoz[3] / b_UNLOADED_RADIUS;
    Fz_ext[3] = std::fmax((((b_Q_V2 * std::abs(Omega[3]) * b_UNLOADED_RADIUS /
      b_LONGVL + 1.0) - d_y) - lam_muy_prime_idx_3) * ((b_Q_FZ3 * b_gamma[3] *
      b_gamma[3] + b_Q_FZ1) * rhoz[3] / b_UNLOADED_RADIUS + ec_data * ec_data *
      b_Q_FZ2) * (b_PFZ1 * dpi_idx_3 + 1.0) * Fzo_prime_idx_3, (a_tmp -
      (b_UNLOADED_RADIUS + rhoz[3]) / std::cos(b_gamma[3])) * b_BOTTOM_STIFF);
  }

  Re[0] = b_VERTICAL_STIFFNESS * scaleFactors[22];
  Re[1] = b_VERTICAL_STIFFNESS * scaleFactors[49];
  Re[2] = b_VERTICAL_STIFFNESS * scaleFactors[76];
  Re[3] = b_VERTICAL_STIFFNESS * scaleFactors[103];
  trueCount = 0;
  for (i = 0; i < 4; i++) {
    if (rhoz[i] > 0.0) {
      trueCount++;
    }
  }

  tmp_size = trueCount;
  partialTrueCount = 0;
  for (i = 0; i < 4; i++) {
    if (rhoz[i] > 0.0) {
      tmp_data[partialTrueCount] = i;
      partialTrueCount++;
    }
  }

  partialTrueCount = trueCount;
  for (i = 0; i < trueCount; i++) {
    partialTrueCount = tmp_data[i];
    rhoz_data[i] = rhoz[partialTrueCount];
    rhoz_data_0[i] = rhoz[partialTrueCount];
    phi_t[i] = rhoz[partialTrueCount];
  }

  AdasPlantModel0_abs(phi_t, &trueCount, phi, &tmp_size_0);
  i = trueCount == 1 ? tmp_size_0 : trueCount;
  AdasPlantModel0_abs(rhoz_data, &trueCount, phi, &tmp_size_0);
  AdasPlantModel0_abs(rhoz_data_0, &trueCount, phi, &partialTrueCount);
  if ((trueCount == tmp_size_0) && ((trueCount == 1 ? partialTrueCount :
        trueCount) == trueCount) && ((i == 1 ? trueCount : i) == trueCount)) {
    partialTrueCount = trueCount;
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = rhoz[tmp_data[i]];
    }

    AdasPlantModel0_abs(rhoz_data, &partialTrueCount, rhoz_data_0, &trueCount);
    for (i = 0; i < tmp_size; i++) {
      partialTrueCount = tmp_data[i];
      Re[partialTrueCount] = (b_Q_FCY2 * Fy_ext[partialTrueCount] / b_FNOMIN +
        Fz_ext[partialTrueCount] / rhoz_data_0[i]) * scaleFactors[27 *
        partialTrueCount + 22];
    }
  } else {
    Ada_binary_expand_op_nxejpfz5mi(Re, tmp_data, &trueCount, Fz_ext, rhoz,
      b_Q_FCY2, Fy_ext, b_FNOMIN, scaleFactors);
  }

  FzUnSat[0] = Fz_ext[0];
  FzUnSat[1] = Fz_ext[1];
  FzUnSat[2] = Fz_ext[2];
  FzUnSat[3] = Fz_ext[3];
  ec_data = Omega[0] * b_UNLOADED_RADIUS / b_LONGVL;
  R_omega_0 = (ec_data * ec_data * b_Q_V1 + b_Q_RE0) * b_UNLOADED_RADIUS;
  R_omega[0] = R_omega_0;
  lam_Cz_0 = Fz_ext[0] / b_FNOMIN;
  Re[0] = R_omega_0 - (std::atan(b_BREFF * lam_Cz_0) * b_DREFF + b_FREFF *
                       lam_Cz_0) * (b_FNOMIN / Re[0]);
  ec_data = Omega[1] * b_UNLOADED_RADIUS / b_LONGVL;
  R_omega_0 = (ec_data * ec_data * b_Q_V1 + b_Q_RE0) * b_UNLOADED_RADIUS;
  R_omega[1] = R_omega_0;
  lam_Cz_0 = Fz_ext[1] / b_FNOMIN;
  Re[1] = R_omega_0 - (std::atan(b_BREFF * lam_Cz_0) * b_DREFF + b_FREFF *
                       lam_Cz_0) * (b_FNOMIN / Re[1]);
  ec_data = Omega[2] * b_UNLOADED_RADIUS / b_LONGVL;
  R_omega_0 = (ec_data * ec_data * b_Q_V1 + b_Q_RE0) * b_UNLOADED_RADIUS;
  R_omega[2] = R_omega_0;
  lam_Cz_0 = Fz_ext[2] / b_FNOMIN;
  Re[2] = R_omega_0 - (std::atan(b_BREFF * lam_Cz_0) * b_DREFF + b_FREFF *
                       lam_Cz_0) * (b_FNOMIN / Re[2]);
  ec_data = Omega[3] * b_UNLOADED_RADIUS / b_LONGVL;
  R_omega_0 = (ec_data * ec_data * b_Q_V1 + b_Q_RE0) * b_UNLOADED_RADIUS;
  lam_Cz_0 = Fz_ext[3] / b_FNOMIN;
  Re[3] = R_omega_0 - (std::atan(b_BREFF * lam_Cz_0) * b_DREFF + b_FREFF *
                       lam_Cz_0) * (b_FNOMIN / Re[3]);
  for (i = 0; i < 4; i++) {
    a_tmp = Fz_ext[i];
    if (a_tmp < b_FZMIN) {
      a_tmp = b_FZMIN;
      Fz_ext[i] = b_FZMIN;
    }

    if (a_tmp > b_FZMAX) {
      Fz_ext[i] = b_FZMAX;
    }

    if (Re[i] < 0.001) {
      Re[i] = 0.001;
    }
  }

  dfz_0 = (Fz_ext[0] - Fzo_prime_idx_0) / Fzo_prime_idx_0;
  dfz[0] = dfz_0;
  epsilon_gamma[0] = (b_PECP2 * dfz_0 + 1.0) * b_PECP1;
  dfz_0 = (Fz_ext[1] - Fzo_prime_idx_1) / Fzo_prime_idx_1;
  dfz[1] = dfz_0;
  epsilon_gamma[1] = (b_PECP2 * dfz_0 + 1.0) * b_PECP1;
  dfz_0 = (Fz_ext[2] - Fzo_prime_idx_2) / Fzo_prime_idx_2;
  dfz[2] = dfz_0;
  epsilon_gamma[2] = (b_PECP2 * dfz_0 + 1.0) * b_PECP1;
  dfz_0 = (Fz_ext[3] - Fzo_prime_idx_3) / Fzo_prime_idx_3;
  dfz[3] = dfz_0;
  epsilon_gamma[3] = (b_PECP2 * dfz_0 + 1.0) * b_PECP1;
  a_tmp = std::fmax(R_omega[0] - (b_UNLOADED_RADIUS + rhoz[0]), 0.0) /
    b_UNLOADED_RADIUS;
  patch_a[0] = (b_Q_RA2 * a_tmp + b_Q_RA1 * std::sqrt(a_tmp)) *
    b_UNLOADED_RADIUS;
  patch_b[0] = (b_Q_RB2 * a_tmp + b_Q_RB1 * rt_powd_snf(a_tmp,
    0.33333333333333331)) * b_WIDTH;
  kappa[0] = (Re[0] * Omega[0] - Vx[0]) / Vsy[0];
  a_tmp = std::fmax(R_omega[1] - (b_UNLOADED_RADIUS + rhoz[1]), 0.0) /
    b_UNLOADED_RADIUS;
  patch_a[1] = (b_Q_RA2 * a_tmp + b_Q_RA1 * std::sqrt(a_tmp)) *
    b_UNLOADED_RADIUS;
  patch_b[1] = (b_Q_RB2 * a_tmp + b_Q_RB1 * rt_powd_snf(a_tmp,
    0.33333333333333331)) * b_WIDTH;
  kappa[1] = (Re[1] * Omega[1] - Vx[1]) / Vsy[1];
  a_tmp = std::fmax(R_omega[2] - (b_UNLOADED_RADIUS + rhoz[2]), 0.0) /
    b_UNLOADED_RADIUS;
  patch_a[2] = (b_Q_RA2 * a_tmp + b_Q_RA1 * std::sqrt(a_tmp)) *
    b_UNLOADED_RADIUS;
  patch_b[2] = (b_Q_RB2 * a_tmp + b_Q_RB1 * rt_powd_snf(a_tmp,
    0.33333333333333331)) * b_WIDTH;
  kappa[2] = (Re[2] * Omega[2] - Vx[2]) / Vsy[2];
  a_tmp = std::fmax(R_omega_0 - (b_UNLOADED_RADIUS + rhoz[3]), 0.0) /
    b_UNLOADED_RADIUS;
  patch_a[3] = (b_Q_RA2 * a_tmp + b_Q_RA1 * std::sqrt(a_tmp)) *
    b_UNLOADED_RADIUS;
  patch_b[3] = (b_Q_RB2 * a_tmp + b_Q_RB1 * rt_powd_snf(a_tmp,
    0.33333333333333331)) * b_WIDTH;
  kappa[3] = (Re[3] * Omega[3] - Vx[3]) / Vsy[3];
  alpha[0] = rt_atan2d_snf(Vy[0], Vsy[0]);
  alpha[1] = rt_atan2d_snf(Vy[1], Vsy[1]);
  alpha[2] = rt_atan2d_snf(Vy[2], Vsy[2]);
  alpha[3] = rt_atan2d_snf(Vy[3], Vsy[3]);
  for (i = 0; i < 4; i++) {
    a_tmp = kappa[i];
    if (a_tmp < b_KPUMIN) {
      a_tmp = b_KPUMIN;
      kappa[i] = b_KPUMIN;
    }

    if (a_tmp > b_KPUMAX) {
      kappa[i] = b_KPUMAX;
    }

    a_tmp = alpha[i];
    if (a_tmp < b_ALPMIN) {
      a_tmp = b_ALPMIN;
      alpha[i] = b_ALPMIN;
    }

    if (a_tmp > b_ALPMAX) {
      alpha[i] = b_ALPMAX;
    }
  }

  kappa_x[0] = (b_PHX2 * dfz[0] + b_PHX1) * scaleFactors[10] + kappa[0];
  kappa_x[1] = (b_PHX2 * dfz[1] + b_PHX1) * scaleFactors[37] + kappa[1];
  kappa_x[2] = (b_PHX2 * dfz[2] + b_PHX1) * scaleFactors[64] + kappa[2];
  kappa_x[3] = (b_PHX2 * dfz_0 + b_PHX1) * scaleFactors[91] + kappa[3];
  gamma_star_tmp = std::sin(b_gamma[0]);
  gamma_star[0] = gamma_star_tmp;
  ec_data = -Vsy[0] * kappa[0];
  Vsy_tmp = std::tan(alpha[0]);
  lam_Cz_0 = -Vsy[0] * Vsy_tmp;
  Vs_tmp = lam_Cz_0 * lam_Cz_0;
  Vs_0 = ec_data * ec_data + Vs_tmp;
  gamma_star_tmp_0 = std::sin(b_gamma[1]);
  gamma_star[1] = gamma_star_tmp_0;
  ec_data = -Vsy[1] * kappa[1];
  Vsy_tmp_0 = std::tan(alpha[1]);
  lam_Cz_0 = -Vsy[1] * Vsy_tmp_0;
  Vs_tmp_0 = lam_Cz_0 * lam_Cz_0;
  a_tmp = ec_data * ec_data + Vs_tmp_0;
  gamma_star_tmp_1 = std::sin(b_gamma[2]);
  gamma_star[2] = gamma_star_tmp_1;
  ec_data = -Vsy[2] * kappa[2];
  Vsy_tmp_1 = std::tan(alpha[2]);
  lam_Cz_0 = -Vsy[2] * Vsy_tmp_1;
  Vs_tmp_1 = lam_Cz_0 * lam_Cz_0;
  d_y = ec_data * ec_data + Vs_tmp_1;
  gamma_star_tmp_2 = std::sin(b_gamma[3]);
  gamma_star[3] = gamma_star_tmp_2;
  ec_data = -Vsy[3] * kappa[3];
  R_omega_0 = std::tan(alpha[3]);
  lam_Cz_0 = -Vsy[3] * R_omega_0;
  AdasPlantModel0_div0protect(Vx, b_VXLOW, phi_t, lam_Cz);
  R_omega[0] = std::sqrt(Vx[0] * Vx[0] + Vs_tmp);
  Vs_0 = scaleFactors[3] * std::sqrt(Vs_0) / b_LONGVL + 1.0;
  Vs[0] = Vs_0;
  Fx[0] /= Vs_0;
  R_omega[1] = std::sqrt(Vx[1] * Vx[1] + Vs_tmp_0);
  Vs_0 = scaleFactors[30] * std::sqrt(a_tmp) / b_LONGVL + 1.0;
  Vs[1] = Vs_0;
  Fx[1] /= Vs_0;
  R_omega[2] = std::sqrt(Vx[2] * Vx[2] + Vs_tmp_1);
  Vs_0 = scaleFactors[57] * std::sqrt(d_y) / b_LONGVL + 1.0;
  Vs[2] = Vs_0;
  Fx[2] /= Vs_0;
  a_tmp = lam_Cz_0 * lam_Cz_0;
  R_omega[3] = std::sqrt(Vx[3] * Vx[3] + a_tmp);
  Vs_0 = std::sqrt(ec_data * ec_data + a_tmp) * scaleFactors[84] / b_LONGVL +
    1.0;
  Fx[3] /= Vs_0;
  AdasPlantModel0_div0protect(R_omega, b_VXLOW, Mz, lam_Cz);
  Dx_tmp = dpi_idx_0 * dpi_idx_0;
  a_tmp = lam_muy[0] / Vs[0];
  lam_muy[0] = a_tmp;
  lam_muy_prime_idx_0 = a_tmp * 10.0 / (9.0 * a_tmp + 1.0);
  Vs_tmp_0 = gamma_star_tmp * gamma_star_tmp;
  ec_data = ((b_PPY3 * dpi_idx_0 + 1.0) + Dx_tmp * b_PPY4) * (b_PDY2 * dfz[0] +
    b_PDY1) * (1.0 - Vs_tmp_0 * b_PDY3) * a_tmp;
  phi_t[0] = -psidot[0] / phi_t[0] * std::cos(alpha[0]);
  Dx_tmp_0 = dpi_idx_1 * dpi_idx_1;
  a_tmp = lam_muy[1] / Vs[1];
  lam_muy[1] = a_tmp;
  lam_muy_prime_idx_1 = a_tmp * 10.0 / (9.0 * a_tmp + 1.0);
  Vs_tmp = gamma_star_tmp_0 * gamma_star_tmp_0;
  d_y = ((b_PPY3 * dpi_idx_1 + 1.0) + Dx_tmp_0 * b_PPY4) * (b_PDY2 * dfz[1] +
    b_PDY1) * (1.0 - Vs_tmp * b_PDY3) * a_tmp;
  phi_t[1] = -psidot[1] / phi_t[1] * std::cos(alpha[1]);
  Dx_tmp_1 = dpi_idx_2 * dpi_idx_2;
  a_tmp = lam_muy[2] / Vs[2];
  lam_muy[2] = a_tmp;
  lam_muy_prime_idx_2 = a_tmp * 10.0 / (9.0 * a_tmp + 1.0);
  mu_y_tmp = gamma_star_tmp_1 * gamma_star_tmp_1;
  Vs_tmp_1 = ((b_PPY3 * dpi_idx_2 + 1.0) + Dx_tmp_1 * b_PPY4) * (b_PDY2 * dfz[2]
    + b_PDY1) * (1.0 - mu_y_tmp * b_PDY3) * a_tmp;
  phi_t[2] = -psidot[2] / phi_t[2] * std::cos(alpha[2]);
  Dx_tmp_2 = dpi_idx_3 * dpi_idx_3;
  a_tmp = lam_muy[3] / Vs_0;
  lam_muy_prime_idx_3 = a_tmp * 10.0 / (9.0 * a_tmp + 1.0);
  mu_y_idx_0 = gamma_star_tmp_2 * gamma_star_tmp_2;
  Vs_0 = ((b_PPY3 * dpi_idx_3 + 1.0) + Dx_tmp_2 * b_PPY4) * (b_PDY2 * dfz_0 +
    b_PDY1) * (1.0 - mu_y_idx_0 * b_PDY3) * a_tmp;
  phi_t[3] = -psidot[3] / phi_t[3] * std::cos(alpha[3]);
  trueCount = 0;
  for (i = 0; i < 4; i++) {
    if (Vx[i] < b_VXLOW) {
      trueCount++;
    }
  }

  tmp_size_0 = trueCount;
  partialTrueCount = 0;
  for (i = 0; i < 4; i++) {
    if (Vx[i] < b_VXLOW) {
      tmp_data_0[partialTrueCount] = i;
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    rhoz_data[i] = Vx[tmp_data_0[i]];
  }

  AdasPlantModel0_abs(rhoz_data, &trueCount, phi, &tmp_size);
  if (trueCount == tmp_size) {
    partialTrueCount = trueCount;
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = Vx[tmp_data_0[i]];
    }

    AdasPlantModel0_abs(rhoz_data, &partialTrueCount, rhoz_data_0, &trueCount);
    for (i = 0; i < tmp_size_0; i++) {
      rhoz_data[i] = rhoz_data_0[i] / b_VXLOW * phi_t[tmp_data_0[i]];
    }

    for (i = 0; i < tmp_size_0; i++) {
      phi_t[tmp_data_0[i]] = rhoz_data[i];
    }
  } else {
    AdasPlant_binary_expand_op_nxej(phi_t, tmp_data_0, &trueCount, Vx, b_VXLOW);
  }

  AdasPlantModel0_div0protect_f(R_omega, rhoz_data);
  phi[0] = ((1.0 - epsilon_gamma[0]) * std::abs(Omega[0]) * gamma_star_tmp +
            psidot[0]) * (1.0 / rhoz_data[0]);
  phi[1] = ((1.0 - epsilon_gamma[1]) * std::abs(Omega[1]) * gamma_star_tmp_0 +
            psidot[1]) * (1.0 / rhoz_data[1]);
  phi[2] = ((1.0 - epsilon_gamma[2]) * std::abs(Omega[2]) * gamma_star_tmp_1 +
            psidot[2]) * (1.0 / rhoz_data[2]);
  phi[3] = ((1.0 - epsilon_gamma[3]) * std::abs(Omega[3]) * gamma_star_tmp_2 +
            psidot[3]) * (1.0 / rhoz_data[3]);
  if (b_turnslip == 1.0) {
    tempInds[0] = (std::abs(phi[0]) > 0.01);
    tempInds[1] = (std::abs(phi[1]) > 0.01);
    tempInds[2] = (std::abs(phi[2]) > 0.01);
    tempInds[3] = (std::abs(phi[3]) > 0.01);
  } else {
    tempInds[0] = false;
    tempInds[1] = false;
    tempInds[2] = false;
    tempInds[3] = false;
  }

  nomslipinds[0] = !tempInds[0];
  SHykappa[0] = b_RHY2 * dfz[0] + b_RHY1;
  Eykappa[0] = b_REY2 * dfz[0] + b_REY1;
  nomslipinds[1] = !tempInds[1];
  SHykappa[1] = b_RHY2 * dfz[1] + b_RHY1;
  Eykappa[1] = b_REY2 * dfz[1] + b_REY1;
  nomslipinds[2] = !tempInds[2];
  SHykappa[2] = b_RHY2 * dfz[2] + b_RHY1;
  Eykappa[2] = b_REY2 * dfz[2] + b_REY1;
  nomslipinds[3] = !tempInds[3];
  SHykappa[3] = b_RHY2 * dfz_0 + b_RHY1;
  Eykappa[3] = b_REY2 * dfz_0 + b_REY1;
  Bykappa[0] = (Vs_tmp_0 * b_RBY4 + b_RBY1) * std::cos(std::atan(b_RBY2 * alpha
    [0])) * scaleFactors[19];
  Bykappa[1] = (Vs_tmp * b_RBY4 + b_RBY1) * std::cos(std::atan(b_RBY2 * alpha[1]))
    * scaleFactors[46];
  Bykappa[2] = (mu_y_tmp * b_RBY4 + b_RBY1) * std::cos(std::atan(b_RBY2 * alpha
    [2])) * scaleFactors[73];
  Bykappa[3] = (mu_y_idx_0 * b_RBY4 + b_RBY1) * std::cos(std::atan(b_RBY2 *
    alpha[3])) * scaleFactors[100];
  for (i = 0; i < 4; i++) {
    if (Eykappa[i] > 1.0) {
      Eykappa[i] = 1.0;
    }

    if (Bykappa[i] < 0.0) {
      Bykappa[i] = 0.0;
    }
  }

  for (i = 0; i < 36; i++) {
    zeta[i] = 1.0;
  }

  trueCount = 0;
  for (i = 0; i < 4; i++) {
    if (tempInds[i]) {
      trueCount++;
    }
  }

  tmp_size_0 = trueCount;
  partialTrueCount = 0;
  for (i = 0; i < 4; i++) {
    if (tempInds[i]) {
      bc_tmp_data[partialTrueCount] = i;
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    bc_data[i] = static_cast<int8_T>(bc_tmp_data[i]);
  }

  for (i = 0; i < trueCount; i++) {
    zeta[9 * bc_data[i]] = 0.0;
  }

  nomslipinds_0 = AdasPlantModel0_any(tempInds);
  if (nomslipinds_0) {
    b_x[0] = std::cos(std::atan(b_PDXP3 * kappa[0]));
    lam_Cz[0] = std::cos(std::atan(b_PDYP3 * Vsy_tmp));
    b_x[1] = std::cos(std::atan(b_PDXP3 * kappa[1]));
    lam_Cz[1] = std::cos(std::atan(b_PDYP3 * Vsy_tmp_0));
    b_x[2] = std::cos(std::atan(b_PDXP3 * kappa[2]));
    lam_Cz[2] = std::cos(std::atan(b_PDYP3 * Vsy_tmp_1));
    b_x[3] = std::cos(std::atan(b_PDXP3 * kappa[3]));
    lam_Cz[3] = std::cos(std::atan(b_PDYP3 * R_omega_0));
    for (i = 0; i < tmp_size_0; i++) {
      partialTrueCount = bc_tmp_data[i];
      rhoz_data[i] = (b_PDXP2 * dfz[partialTrueCount] + 1.0) * b_PDXP1 *
        b_x[partialTrueCount] * b_UNLOADED_RADIUS * phi[partialTrueCount];
    }

    AdasPlantModel0_atan(rhoz_data, &tmp_size_0);
    AdasPlantModel0_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 1] = rhoz_data[i];
      tmpDrphiVar_data[i] = phi[bc_tmp_data[i]];
    }

    AdasPlantModel0_abs(tmpDrphiVar_data, &tmp_size_0, rhoz_data_0, &trueCount);
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = b_UNLOADED_RADIUS * rhoz_data_0[i];
    }

    tmp_size = trueCount;
    if (trueCount - 1 >= 0) {
      std::memcpy(&tmpDrphiVar_data[0], &rhoz_data[0], static_cast<uint32_T>
                  (trueCount) * sizeof(real_T));
    }

    AdasPlantModel0_sqrt_h(tmpDrphiVar_data, &trueCount);
    if ((trueCount == trueCount) && ((trueCount == 1 ? trueCount : trueCount) ==
         tmp_size_0)) {
      tmp_size = tmp_size_0;
      for (i = 0; i < tmp_size_0; i++) {
        partialTrueCount = bc_tmp_data[i];
        dc_data[i] = (b_PDYP2 * dfz[partialTrueCount] + 1.0) * b_PDYP1 *
          lam_Cz[partialTrueCount] * (b_PDYP4 * tmpDrphiVar_data[i] +
          rhoz_data[i]);
      }
    } else {
      AdasPlantM_binary_expand_op_nxe(dc_data, &tmp_size, b_PDYP1, b_PDYP2, dfz,
        lam_Cz, bc_tmp_data, &tmp_size_0, rhoz_data, &trueCount, b_PDYP4,
        tmpDrphiVar_data, &trueCount);
    }

    AdasPlantModel0_atan(dc_data, &tmp_size);
    AdasPlantModel0_cos(dc_data, &tmp_size);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 2] = dc_data[i];
    }

    dfz_0 = b_UNLOADED_RADIUS * b_UNLOADED_RADIUS * b_PKYP1;
    for (i = 0; i < tmp_size_0; i++) {
      Vsy_tmp = phi[bc_tmp_data[i]];
      rhoz_data[i] = Vsy_tmp * Vsy_tmp * dfz_0;
    }

    AdasPlantModel0_atan(rhoz_data, &tmp_size_0);
    AdasPlantModel0_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 3] = rhoz_data[i];
    }
  }

  mu_y_idx_1 = 1.0 - b_PKY3 * 0.0;
  Kygammao[0] = (b_PKY7 * dfz[0] + b_PKY6) * Fz_ext[0] * (b_PPY5 * dpi_idx_0 +
    1.0) * scaleFactors[14];
  lam_Cz_0 = Fz_ext[0] / Fzo_prime_idx_0;
  Mzphiinf[0] = lam_Cz_0;
  R_omega_0 = (b_PPY1 * dpi_idx_0 + 1.0) * (b_PKY1 * Fzo_prime_idx_0);
  mu_y_idx_2 = std::sin(std::atan(lam_Cz_0 / (Vs_tmp_0 * b_PKY5 + b_PKY2) /
    (b_PPY2 * dpi_idx_0 + 1.0)) * b_PKY4);
  dfz_0 = (1.0 - b_PKY3 * std::abs(gamma_star_tmp)) * R_omega_0 * mu_y_idx_2 *
    zeta[3] * scaleFactors[5];
  Vsy[0] = dfz_0;
  R_omega[0] = R_omega_0 * mu_y_idx_1 * mu_y_idx_2 * zeta[3] * scaleFactors[5];
  Kygammao[1] = (b_PKY7 * dfz[1] + b_PKY6) * Fz_ext[1] * (b_PPY5 * dpi_idx_1 +
    1.0) * scaleFactors[41];
  lam_Cz_0 = Fz_ext[1] / Fzo_prime_idx_1;
  Mzphiinf[1] = lam_Cz_0;
  R_omega_0 = (b_PPY1 * dpi_idx_1 + 1.0) * (b_PKY1 * Fzo_prime_idx_1);
  mu_y_idx_2 = std::sin(std::atan(lam_Cz_0 / (Vs_tmp * b_PKY5 + b_PKY2) /
    (b_PPY2 * dpi_idx_1 + 1.0)) * b_PKY4);
  Vsy_tmp = (1.0 - b_PKY3 * std::abs(gamma_star_tmp_0)) * R_omega_0 * mu_y_idx_2
    * zeta[12] * scaleFactors[32];
  Vsy[1] = Vsy_tmp;
  R_omega[1] = R_omega_0 * mu_y_idx_1 * mu_y_idx_2 * zeta[12] * scaleFactors[32];
  Kygammao[2] = (b_PKY7 * dfz[2] + b_PKY6) * Fz_ext[2] * (b_PPY5 * dpi_idx_2 +
    1.0) * scaleFactors[68];
  lam_Cz_0 = Fz_ext[2] / Fzo_prime_idx_2;
  Mzphiinf[2] = lam_Cz_0;
  R_omega_0 = (b_PPY1 * dpi_idx_2 + 1.0) * (b_PKY1 * Fzo_prime_idx_2);
  mu_y_idx_2 = std::sin(std::atan(lam_Cz_0 / (mu_y_tmp * b_PKY5 + b_PKY2) /
    (b_PPY2 * dpi_idx_2 + 1.0)) * b_PKY4);
  Vsy_tmp_0 = (1.0 - b_PKY3 * std::abs(gamma_star_tmp_1)) * R_omega_0 *
    mu_y_idx_2 * zeta[21] * scaleFactors[59];
  Vsy[2] = Vsy_tmp_0;
  R_omega[2] = R_omega_0 * mu_y_idx_1 * mu_y_idx_2 * zeta[21] * scaleFactors[59];
  Kygammao[3] = (b_PKY7 * dfz[3] + b_PKY6) * Fz_ext[3] * (b_PPY5 * dpi_idx_3 +
    1.0) * scaleFactors[95];
  lam_Cz_0 = Fz_ext[3] / Fzo_prime_idx_3;
  R_omega_0 = (b_PPY1 * dpi_idx_3 + 1.0) * (b_PKY1 * Fzo_prime_idx_3);
  mu_y_idx_2 = std::sin(std::atan(lam_Cz_0 / (mu_y_idx_0 * b_PKY5 + b_PKY2) /
    (b_PPY2 * dpi_idx_3 + 1.0)) * b_PKY4);
  Vsy_tmp_1 = (1.0 - b_PKY3 * std::abs(gamma_star_tmp_2)) * R_omega_0 *
    mu_y_idx_2 * zeta[30] * scaleFactors[86];
  Vsy[3] = Vsy_tmp_1;
  R_omega[3] = R_omega_0 * mu_y_idx_1 * mu_y_idx_2 * zeta[30] * scaleFactors[86];
  AdasPlantModel0_div0protect(Vsy, 0.0001, b_x, lam_Cz);
  AdasPlantModel0_div0protect(R_omega, 0.0001, Vsy, lam_Cz);
  x_idx_0 = b_PHYP1;
  if (b_PHYP1 < 0.0) {
    x_idx_0 = 0.0;
  }

  R_omega_0 = std::tanh(Vx[0]);
  lam_Cz[0] = (b_PHYP3 * dfz[0] + b_PHYP2) * R_omega_0;
  mu_y_idx_1 = std::tanh(Vx[1]);
  lam_Cz[1] = (b_PHYP3 * dfz[1] + b_PHYP2) * mu_y_idx_1;
  mu_y_idx_2 = std::tanh(Vx[2]);
  lam_Cz[2] = (b_PHYP3 * dfz[2] + b_PHYP2) * mu_y_idx_2;
  lam_Cz_tmp_tmp = std::tanh(Vx[3]);
  lam_Cz_tmp = (b_PHYP3 * dfz[3] + b_PHYP2) * lam_Cz_tmp_tmp;
  lam_Cz[3] = lam_Cz_tmp;
  ab_idx_0 = b_PHYP4;
  if (b_PHYP4 > 1.0) {
    ab_idx_0 = 1.0;
  }

  Vs[0] = b_UNLOADED_RADIUS * phi[0];
  dc_data[0] = Kygammao[0] / (1.0 - epsilon_gamma[0]) / (x_idx_0 * lam_Cz[0] *
    Vsy[0]);
  Vs[1] = b_UNLOADED_RADIUS * phi[1];
  dc_data[1] = Kygammao[1] / (1.0 - epsilon_gamma[1]) / (x_idx_0 * lam_Cz[1] *
    Vsy[1]);
  Vs[2] = b_UNLOADED_RADIUS * phi[2];
  dc_data[2] = Kygammao[2] / (1.0 - epsilon_gamma[2]) / (x_idx_0 * lam_Cz[2] *
    Vsy[2]);
  Vs[3] = b_UNLOADED_RADIUS * phi[3];
  dc_data[3] = Kygammao[3] / (1.0 - epsilon_gamma[3]) / (lam_Cz_tmp * x_idx_0 *
    Vsy[3]);
  AdasPlantModel0_magicsin(lam_Cz, x_idx_0, dc_data, ab_idx_0, Vs, rhoz_data);
  Vsy[0] = rhoz_data[0] * R_omega_0;
  lam_Kygamma[0] = (b_PVY4 * dfz[0] + b_PVY3) * Fz_ext[0] * gamma_star_tmp *
    zeta[2] * scaleFactors[14] * lam_muy_prime_idx_0;
  SHy[0] = 0.0;
  dc_data[0] = kappa[0] + SHykappa[0];
  Vsy[1] = rhoz_data[1] * mu_y_idx_1;
  lam_Kygamma[1] = (b_PVY4 * dfz[1] + b_PVY3) * Fz_ext[1] * gamma_star_tmp_0 *
    zeta[11] * scaleFactors[41] * lam_muy_prime_idx_1;
  SHy[1] = 0.0;
  dc_data[1] = kappa[1] + SHykappa[1];
  Vsy[2] = rhoz_data[2] * mu_y_idx_2;
  lam_Kygamma[2] = (b_PVY4 * dfz[2] + b_PVY3) * Fz_ext[2] * gamma_star_tmp_1 *
    zeta[20] * scaleFactors[68] * lam_muy_prime_idx_2;
  SHy[2] = 0.0;
  dc_data[2] = kappa[2] + SHykappa[2];
  Vsy[3] = rhoz_data[3] * lam_Cz_tmp_tmp;
  lam_Kygamma[3] = (b_PVY4 * dfz[3] + b_PVY3) * Fz_ext[3] * gamma_star_tmp_2 *
    zeta[29] * scaleFactors[95] * lam_muy_prime_idx_3;
  SHy[3] = 0.0;
  dc_data[3] = kappa[3] + SHykappa[3];
  AdasPlantModel0_magiccos(b_RCY1, Bykappa, Eykappa, dc_data, rhoz_data);
  AdasPlantModel0_magiccos(b_RCY1, Bykappa, Eykappa, SHykappa, dc_data);
  Fy[0] = rhoz_data[0] / dc_data[0];
  Fy[1] = rhoz_data[1] / dc_data[1];
  Fy[2] = rhoz_data[2] / dc_data[2];
  Fy[3] = rhoz_data[3] / dc_data[3];
  for (i = 0; i < 4; i++) {
    if (Fy[i] < 0.0) {
      Fy[i] = 0.0;
    }
  }

  if (nomslipinds_0) {
    for (i = 0; i < tmp_size_0; i++) {
      partialTrueCount = bc_tmp_data[i];
      zeta[9 * bc_data[i] + 4] = (Vsy[partialTrueCount] + 1.0) -
        lam_Kygamma[partialTrueCount] / b_x[partialTrueCount];
    }

    gamma_star_tmp = b_QDTP1 * b_UNLOADED_RADIUS;
    for (i = 0; i < tmp_size_0; i++) {
      rhoz_data[i] = gamma_star_tmp * phi[bc_tmp_data[i]];
    }

    AdasPlantModel0_atan(rhoz_data, &tmp_size_0);
    AdasPlantModel0_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 5] = rhoz_data[i];
    }

    gamma_star_tmp = b_QBRP1 * b_UNLOADED_RADIUS;
    for (i = 0; i < tmp_size_0; i++) {
      rhoz_data[i] = gamma_star_tmp * phi[bc_tmp_data[i]];
    }

    AdasPlantModel0_atan(rhoz_data, &tmp_size_0);
    AdasPlantModel0_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 6] = rhoz_data[i];
    }

    Mzphiinf[0] = b_QCRP1 * ec_data * b_UNLOADED_RADIUS * Fz_ext[0] * std::sqrt
      (Mzphiinf[0]) * scaleFactors[26];
    Mzphiinf[1] = b_QCRP1 * d_y * b_UNLOADED_RADIUS * Fz_ext[1] * std::sqrt
      (Mzphiinf[1]) * scaleFactors[53];
    Mzphiinf[2] = b_QCRP1 * Vs_tmp_1 * b_UNLOADED_RADIUS * Fz_ext[2] * std::sqrt
      (Mzphiinf[2]) * scaleFactors[80];
    Mzphiinf[3] = b_QCRP1 * Vs_0 * b_UNLOADED_RADIUS * Fz_ext[3] * std::sqrt
      (lam_Cz_0) * scaleFactors[107];
    for (i = 0; i < 4; i++) {
      if (Mzphiinf[i] < 0.0) {
        Mzphiinf[i] = 1.0E-6;
      }
    }

    gamma_star_tmp = b_QCRP2 * b_UNLOADED_RADIUS;
    Bykappa[0] = std::atan(gamma_star_tmp * std::abs(phi_t[0]));
    Bykappa[1] = std::atan(gamma_star_tmp * std::abs(phi_t[1]));
    Bykappa[2] = std::atan(gamma_star_tmp * std::abs(phi_t[2]));
    Bykappa[3] = std::atan(gamma_star_tmp * std::abs(phi_t[3]));
    R_omega_0 = b_QDRP1;
    if (b_QDRP1 < 0.0) {
      R_omega_0 = 0.0;
    }

    gamma_star_tmp_0 = b_QDRP2;
    if (b_QDRP2 < 0.0) {
      gamma_star_tmp_0 = 0.0;
    }

    gamma_star_tmp = std::sin(1.5707963267948966 * R_omega_0);
    lam_Cz_0 = Mzphiinf[0] / gamma_star_tmp;
    lam_Cz[0] = lam_Cz_0;
    if (std::isnan(1.0 - epsilon_gamma[0])) {
      mu_y_idx_1 = (rtNaN);
    } else if (1.0 - epsilon_gamma[0] < 0.0) {
      mu_y_idx_1 = -1.0;
    } else {
      mu_y_idx_1 = (1.0 - epsilon_gamma[0] > 0.0);
    }

    rhoz_data[0] = ((b_QDZ11 * dfz[0] + b_QDZ10) * std::abs(b_gamma[0]) +
                    (b_QDZ9 * dfz[0] + b_QDZ8)) * (Fz_ext[0] * b_UNLOADED_RADIUS)
      * scaleFactors[15] / (R_omega_0 * lam_Cz_0 * (1.0 - epsilon_gamma[0]) +
      0.0001 * mu_y_idx_1);
    lam_Cz_0 = Mzphiinf[1] / gamma_star_tmp;
    lam_Cz[1] = lam_Cz_0;
    if (std::isnan(1.0 - epsilon_gamma[1])) {
      mu_y_idx_1 = (rtNaN);
    } else if (1.0 - epsilon_gamma[1] < 0.0) {
      mu_y_idx_1 = -1.0;
    } else {
      mu_y_idx_1 = (1.0 - epsilon_gamma[1] > 0.0);
    }

    rhoz_data[1] = ((b_QDZ11 * dfz[1] + b_QDZ10) * std::abs(b_gamma[1]) +
                    (b_QDZ9 * dfz[1] + b_QDZ8)) * (Fz_ext[1] * b_UNLOADED_RADIUS)
      * scaleFactors[42] / (R_omega_0 * lam_Cz_0 * (1.0 - epsilon_gamma[1]) +
      0.0001 * mu_y_idx_1);
    lam_Cz_0 = Mzphiinf[2] / gamma_star_tmp;
    lam_Cz[2] = lam_Cz_0;
    if (std::isnan(1.0 - epsilon_gamma[2])) {
      mu_y_idx_1 = (rtNaN);
    } else if (1.0 - epsilon_gamma[2] < 0.0) {
      mu_y_idx_1 = -1.0;
    } else {
      mu_y_idx_1 = (1.0 - epsilon_gamma[2] > 0.0);
    }

    rhoz_data[2] = ((b_QDZ11 * dfz[2] + b_QDZ10) * std::abs(b_gamma[2]) +
                    (b_QDZ9 * dfz[2] + b_QDZ8)) * (Fz_ext[2] * b_UNLOADED_RADIUS)
      * scaleFactors[69] / (R_omega_0 * lam_Cz_0 * (1.0 - epsilon_gamma[2]) +
      0.0001 * mu_y_idx_1);
    lam_Cz_0 = Mzphiinf[3] / gamma_star_tmp;
    lam_Cz[3] = lam_Cz_0;
    if (std::isnan(1.0 - epsilon_gamma[3])) {
      mu_y_idx_1 = (rtNaN);
    } else if (1.0 - epsilon_gamma[3] < 0.0) {
      mu_y_idx_1 = -1.0;
    } else {
      mu_y_idx_1 = (1.0 - epsilon_gamma[3] > 0.0);
    }

    rhoz_data[3] = ((b_QDZ11 * dfz[3] + b_QDZ10) * std::abs(b_gamma[3]) +
                    (b_QDZ9 * dfz[3] + b_QDZ8)) * (Fz_ext[3] * b_UNLOADED_RADIUS)
      * scaleFactors[96] / (R_omega_0 * lam_Cz_0 * (1.0 - epsilon_gamma[3]) +
      0.0001 * mu_y_idx_1);
    AdasPlantModel0_magicsin(lam_Cz, R_omega_0, rhoz_data, gamma_star_tmp_0, Vs,
      R_omega);
    if (std::isnan(R_omega[0])) {
      lam_Cz[0] = (rtNaN);
    } else if (R_omega[0] < 0.0) {
      lam_Cz[0] = -1.0;
    } else {
      lam_Cz[0] = (R_omega[0] > 0.0);
    }

    if (std::isnan(R_omega[1])) {
      lam_Cz[1] = (rtNaN);
    } else if (R_omega[1] < 0.0) {
      lam_Cz[1] = -1.0;
    } else {
      lam_Cz[1] = (R_omega[1] > 0.0);
    }

    if (std::isnan(R_omega[2])) {
      lam_Cz[2] = (rtNaN);
    } else if (R_omega[2] < 0.0) {
      lam_Cz[2] = -1.0;
    } else {
      lam_Cz[2] = (R_omega[2] > 0.0);
    }

    if (std::isnan(R_omega[3])) {
      lam_Cz[3] = (rtNaN);
    } else if (R_omega[3] < 0.0) {
      lam_Cz[3] = -1.0;
    } else {
      lam_Cz[3] = (R_omega[3] > 0.0);
    }

    for (i = 0; i < 4; i++) {
      if (lam_Cz[i] == 0.0) {
        lam_Cz[i] = 1.0;
      }
    }

    for (i = 0; i < tmp_size_0; i++) {
      partialTrueCount = bc_tmp_data[i];
      dc_data[i] = R_omega[partialTrueCount];
      rhoz_data[i] = R_omega[partialTrueCount];
    }

    AdasPlantModel0_abs(rhoz_data, &tmp_size_0, rhoz_data_0, &trueCount);
    AdasPlantModel0_abs(dc_data, &tmp_size_0, phi, &tmp_size);
    if ((tmp_size == tmp_size_0) && ((trueCount == 1 ? tmp_size_0 : trueCount) ==
         tmp_size_0)) {
      for (i = 0; i < tmp_size_0; i++) {
        dc_data[i] = R_omega[bc_tmp_data[i]];
      }

      AdasPlantModel0_abs(dc_data, &tmp_size_0, rhoz_data_0, &trueCount);
      tmp_size = tmp_size_0;
      for (i = 0; i < tmp_size_0; i++) {
        partialTrueCount = bc_tmp_data[i];
        tmpDrphiVar_data[i] = Mzphiinf[partialTrueCount] * 2.0 /
          3.1415926535897931 * Bykappa[partialTrueCount] * Fy[partialTrueCount] /
          (0.0001 * lam_Cz[partialTrueCount] + rhoz_data_0[i]);
      }
    } else {
      AdasPlantMo_binary_expand_op_nx(tmpDrphiVar_data, &tmp_size, Mzphiinf,
        Bykappa, Fy, bc_tmp_data, &tmp_size_0, R_omega, lam_Cz);
    }

    trueCount = tmp_size - 1;
    for (i = 0; i <= trueCount; i++) {
      if (tmpDrphiVar_data[i] > 1.0) {
        tmpDrphiVar_data[i] = 1.0;
      }

      if (tmpDrphiVar_data[i] < -1.0) {
        tmpDrphiVar_data[i] = -1.0;
      }
    }

    AdasPlantModel0_acos(tmpDrphiVar_data, &tmp_size);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 7] = 0.63661977236758138 * tmpDrphiVar_data[i];
    }

    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 8] = R_omega[bc_tmp_data[i]] + 1.0;
    }

    trueCount = 0;
    for (i = 0; i < 4; i++) {
      if (tempInds[i]) {
        trueCount++;
      }
    }

    lb[0] = static_cast<int8_T>(trueCount);
    lb[1] = 1;
    i = tmp_size_0 == 1 ? static_cast<int32_T>(static_cast<int8_T>(trueCount)) :
      tmp_size_0;
    if ((tmp_size_0 == static_cast<int8_T>(trueCount)) && (i == tmp_size_0) &&
        ((i == 1 ? tmp_size_0 : i) == tmp_size_0)) {
      for (i = 0; i < tmp_size_0; i++) {
        partialTrueCount = bc_tmp_data[i];
        SHy[bc_data[i]] = (scaleFactors[27 * partialTrueCount + 11] * (0.0 *
          dfz[partialTrueCount]) + Vsy[partialTrueCount]) -
          lam_Kygamma[partialTrueCount] / b_x[partialTrueCount];
      }
    } else {
      AdasPlantMod_binary_expand_op_n(SHy, bc_data, dfz, bc_tmp_data,
        &tmp_size_0, scaleFactors, lb, Vsy, lam_Kygamma, b_x);
    }
  }

  Eykappa[0] = b_PCX1 * scaleFactors[6];
  Eykappa[1] = b_PCX1 * scaleFactors[33];
  Eykappa[2] = b_PCX1 * scaleFactors[60];
  Eykappa[3] = b_PCX1 * scaleFactors[87];
  gamma_star_tmp = b_gamma[0] * b_gamma[0];
  epsilon_gamma[0] = ((b_PPX3 * dpi_idx_0 + 1.0) + b_PPX4 * Dx_tmp) * (b_PDX2 *
    dfz[0] + b_PDX1) * (1.0 - gamma_star_tmp * b_PDX3) * Fx[0] * Fz_ext[0] *
    zeta[1];
  gamma_star_tmp_0 = b_gamma[1] * b_gamma[1];
  epsilon_gamma[1] = ((b_PPX3 * dpi_idx_1 + 1.0) + b_PPX4 * Dx_tmp_0) * (b_PDX2 *
    dfz[1] + b_PDX1) * (1.0 - gamma_star_tmp_0 * b_PDX3) * Fx[1] * Fz_ext[1] *
    zeta[10];
  gamma_star_tmp_1 = b_gamma[2] * b_gamma[2];
  epsilon_gamma[2] = ((b_PPX3 * dpi_idx_2 + 1.0) + b_PPX4 * Dx_tmp_1) * (b_PDX2 *
    dfz[2] + b_PDX1) * (1.0 - gamma_star_tmp_1 * b_PDX3) * Fx[2] * Fz_ext[2] *
    zeta[19];
  gamma_star_tmp_2 = b_gamma[3] * b_gamma[3];
  epsilon_gamma[3] = ((b_PPX3 * dpi_idx_3 + 1.0) + b_PPX4 * Dx_tmp_2) * (b_PDX2 *
    dfz[3] + b_PDX1) * (1.0 - gamma_star_tmp_2 * b_PDX3) * Fx[3] * Fz_ext[3] *
    zeta[28];
  x_idx_0 = dfz[0] * dfz[0];
  Bykappa[0] = ((b_PEX2 * dfz[0] + b_PEX1) + x_idx_0 * b_PEX3) * (1.0 - std::
    tanh(10.0 * kappa_x[0]) * b_PEX4) * scaleFactors[8];
  lam_Cz_tmp = dfz[1] * dfz[1];
  Bykappa[1] = ((b_PEX2 * dfz[1] + b_PEX1) + lam_Cz_tmp * b_PEX3) * (1.0 - std::
    tanh(10.0 * kappa_x[1]) * b_PEX4) * scaleFactors[35];
  ab_idx_0 = dfz[2] * dfz[2];
  Bykappa[2] = ((b_PEX2 * dfz[2] + b_PEX1) + ab_idx_0 * b_PEX3) * (1.0 - std::
    tanh(10.0 * kappa_x[2]) * b_PEX4) * scaleFactors[62];
  Bykappa_tmp = dfz[3] * dfz[3];
  Bykappa[3] = ((b_PEX2 * dfz[3] + b_PEX1) + Bykappa_tmp * b_PEX3) * (1.0 - std::
    tanh(10.0 * kappa_x[3]) * b_PEX4) * scaleFactors[89];
  for (i = 0; i < 4; i++) {
    if (Eykappa[i] < 0.0) {
      Eykappa[i] = 0.0;
    }

    if (epsilon_gamma[i] < 0.0) {
      epsilon_gamma[i] = 0.0;
    }

    if (Bykappa[i] > 1.0) {
      Bykappa[i] = 1.0;
    }
  }

  phi_t[0] = (b_PKX2 * dfz[0] + b_PKX1) * Fz_ext[0] * std::exp(b_PKX3 * dfz[0]) *
    ((b_PPX1 * dpi_idx_0 + 1.0) + Dx_tmp * b_PPX2) * scaleFactors[4];
  Vs[0] = Eykappa[0] * epsilon_gamma[0];
  phi_t[1] = (b_PKX2 * dfz[1] + b_PKX1) * Fz_ext[1] * std::exp(b_PKX3 * dfz[1]) *
    ((b_PPX1 * dpi_idx_1 + 1.0) + Dx_tmp_0 * b_PPX2) * scaleFactors[31];
  Vs[1] = Eykappa[1] * epsilon_gamma[1];
  phi_t[2] = (b_PKX2 * dfz[2] + b_PKX1) * Fz_ext[2] * std::exp(b_PKX3 * dfz[2]) *
    ((b_PPX1 * dpi_idx_2 + 1.0) + Dx_tmp_1 * b_PPX2) * scaleFactors[58];
  Vs[2] = Eykappa[2] * epsilon_gamma[2];
  Dx_tmp = (b_PKX2 * dfz[3] + b_PKX1) * Fz_ext[3] * std::exp(b_PKX3 * dfz[3]) *
    ((b_PPX1 * dpi_idx_3 + 1.0) + Dx_tmp_2 * b_PPX2) * scaleFactors[85];
  Vs[3] = Eykappa[3] * epsilon_gamma[3];
  AdasPlantModel0_div0protect(Vs, 0.0001, Vsy, lam_Cz);
  lam_Cz[0] = b_REX2 * dfz[0] + b_REX1;
  lam_Cz[1] = b_REX2 * dfz[1] + b_REX1;
  lam_Cz[2] = b_REX2 * dfz[2] + b_REX1;
  lam_Cz[3] = b_REX2 * dfz[3] + b_REX1;
  R_omega[0] = (Vs_tmp_0 * b_RBX3 + b_RBX1) * std::cos(std::atan(b_RBX2 * kappa
    [0])) * scaleFactors[18];
  R_omega[1] = (Vs_tmp * b_RBX3 + b_RBX1) * std::cos(std::atan(b_RBX2 * kappa[1]))
    * scaleFactors[45];
  R_omega[2] = (mu_y_tmp * b_RBX3 + b_RBX1) * std::cos(std::atan(b_RBX2 * kappa
    [2])) * scaleFactors[72];
  R_omega[3] = (mu_y_idx_0 * b_RBX3 + b_RBX1) * std::cos(std::atan(b_RBX2 *
    kappa[3])) * scaleFactors[99];
  for (i = 0; i < 4; i++) {
    if (lam_Cz[i] > 1.0) {
      lam_Cz[i] = 1.0;
    }

    if (R_omega[i] < 0.0) {
      R_omega[i] = 0.0;
    }
  }

  AdasPlantModel0_magiccos(b_RCX1, R_omega, lam_Cz, alpha, rhoz_data);
  AdasPlantModel0_magiccos_l(b_RCX1, R_omega, lam_Cz, dc_data);
  Vs[0] = rhoz_data[0] / dc_data[0];
  Vs[1] = rhoz_data[1] / dc_data[1];
  Vs[2] = rhoz_data[2] / dc_data[2];
  Vs[3] = rhoz_data[3] / dc_data[3];
  for (i = 0; i < 4; i++) {
    if (Vs[i] < 0.0) {
      Vs[i] = 0.0;
    }
  }

  Mzphiinf[0] = phi_t[0] / Vsy[0];
  Mzphiinf[1] = phi_t[1] / Vsy[1];
  Mzphiinf[2] = phi_t[2] / Vsy[2];
  Mzphiinf[3] = Dx_tmp / Vsy[3];
  AdasPlantModel0_magicsin_d(epsilon_gamma, Eykappa, Mzphiinf, Bykappa, kappa_x,
    rhoz_data);
  mu_y_tmp = ((b_PVX2 * dfz[0] + b_PVX1) * Fz_ext[0] * (Fx[0] * 10.0 / (9.0 *
    Fx[0] + 1.0)) * scaleFactors[12] * zeta[1] + rhoz_data[0]) * Vs[0];
  Fx[0] = mu_y_tmp;
  Mzphiinf[0] = b_PCY1 * scaleFactors[7];
  Dx_tmp_0 = ((b_PVX2 * dfz[1] + b_PVX1) * Fz_ext[1] * (Fx[1] * 10.0 / (9.0 *
    Fx[1] + 1.0)) * scaleFactors[39] * zeta[10] + rhoz_data[1]) * Vs[1];
  Fx[1] = Dx_tmp_0;
  Mzphiinf[1] = b_PCY1 * scaleFactors[34];
  Dx_tmp_1 = ((b_PVX2 * dfz[2] + b_PVX1) * Fz_ext[2] * (Fx[2] * 10.0 / (9.0 *
    Fx[2] + 1.0)) * scaleFactors[66] * zeta[19] + rhoz_data[2]) * Vs[2];
  Fx[2] = Dx_tmp_1;
  Mzphiinf[2] = b_PCY1 * scaleFactors[61];
  Dx_tmp_2 = ((b_PVX2 * dfz[3] + b_PVX1) * Fz_ext[3] * (Fx[3] * 10.0 / (9.0 *
    Fx[3] + 1.0)) * scaleFactors[93] * zeta[28] + rhoz_data[3]) * Vs[3];
  Fx[3] = Dx_tmp_2;
  Mzphiinf[3] = b_PCY1 * scaleFactors[88];
  for (i = 0; i < 4; i++) {
    if (Mzphiinf[i] < 0.0) {
      Mzphiinf[i] = 0.0;
    }
  }

  ec_data *= Fz_ext[0];
  mu_y_idx_0 = ec_data;
  lam_Cz_0 = ec_data * zeta[2];
  Vsy[0] = lam_Cz_0;
  Vs[0] = Mzphiinf[0] * lam_Cz_0;
  ec_data = d_y * Fz_ext[1];
  mu_y_idx_1 = ec_data;
  lam_Cz_0 = ec_data * zeta[11];
  Vsy[1] = lam_Cz_0;
  Vs[1] = Mzphiinf[1] * lam_Cz_0;
  ec_data = Vs_tmp_1 * Fz_ext[2];
  mu_y_idx_2 = ec_data;
  lam_Cz_0 = ec_data * zeta[20];
  Vsy[2] = lam_Cz_0;
  Vs[2] = Mzphiinf[2] * lam_Cz_0;
  ec_data = Vs_0 * Fz_ext[3];
  lam_Cz_0 = ec_data * zeta[29];
  Vsy[3] = lam_Cz_0;
  Vs[3] = Mzphiinf[3] * lam_Cz_0;
  AdasPlantModel0_div0protect(Vs, 0.0001, epsilon_gamma, lam_Cz);
  epsilon_gamma[0] = dfz_0 / epsilon_gamma[0];
  epsilon_gamma[1] = Vsy_tmp / epsilon_gamma[1];
  epsilon_gamma[2] = Vsy_tmp_0 / epsilon_gamma[2];
  epsilon_gamma[3] = Vsy_tmp_1 / epsilon_gamma[3];
  if (AdasPlantModel0_any(nomslipinds)) {
    trueCount = 0;
    lb[1] = 1;
    for (i = 0; i < 4; i++) {
      if (nomslipinds[i]) {
        trueCount++;
      }
    }

    lb[0] = static_cast<int8_T>(trueCount);
    partialTrueCount = 0;
    tmp_size = 0;
    for (i = 0; i < 4; i++) {
      if (nomslipinds[i]) {
        tmp_data_1[partialTrueCount] = static_cast<int8_T>(i);
        partialTrueCount++;
        tmp_size++;
      }
    }

    partialTrueCount = 0;
    for (i = 0; i < 4; i++) {
      if (nomslipinds[i]) {
        tmp_data_2[partialTrueCount] = i;
        partialTrueCount++;
      }
    }

    i = tmp_size == 1 ? static_cast<int32_T>(static_cast<int8_T>(trueCount)) :
      tmp_size;
    if ((tmp_size == static_cast<int8_T>(trueCount)) && (i == tmp_size) && ((i ==
          1 ? tmp_size : i) == tmp_size)) {
      for (i = 0; i < tmp_size; i++) {
        partialTrueCount = tmp_data_2[i];
        SHy[tmp_data_1[i]] = (((Kygammao[partialTrueCount] *
          gamma_star[partialTrueCount] - lam_Kygamma[partialTrueCount]) /
          b_x[partialTrueCount] * zeta[9 * partialTrueCount] + scaleFactors[27 *
          partialTrueCount + 11] * (0.0 * dfz[partialTrueCount])) + zeta[9 *
                              partialTrueCount + 4]) - 1.0;
      }
    } else {
      AdasPlantModel_binary_expand_op(SHy, tmp_data_1, dfz, tmp_data_2,
        &tmp_size, scaleFactors, lb, Kygammao, gamma_star, lam_Kygamma, b_x,
        zeta);
    }
  }

  lam_muy_prime_idx_0 = 0.0 * dfz[0] * Fz_ext[0] * scaleFactors[13] *
    lam_muy_prime_idx_0 * zeta[2] + lam_Kygamma[0];
  R_omega_0 = alpha[0] + SHy[0];
  R_omega[0] = R_omega_0;
  if (std::isnan(R_omega_0)) {
    lam_Cz[0] = (rtNaN);
  } else if (R_omega_0 < 0.0) {
    lam_Cz[0] = -1.0;
  } else {
    lam_Cz[0] = (R_omega_0 > 0.0);
  }

  lam_muy_prime_idx_1 = 0.0 * dfz[1] * Fz_ext[1] * scaleFactors[40] *
    lam_muy_prime_idx_1 * zeta[11] + lam_Kygamma[1];
  R_omega_0 = alpha[1] + SHy[1];
  R_omega[1] = R_omega_0;
  if (std::isnan(R_omega_0)) {
    lam_Cz[1] = (rtNaN);
  } else if (R_omega_0 < 0.0) {
    lam_Cz[1] = -1.0;
  } else {
    lam_Cz[1] = (R_omega_0 > 0.0);
  }

  lam_muy_prime_idx_2 = 0.0 * dfz[2] * Fz_ext[2] * scaleFactors[67] *
    lam_muy_prime_idx_2 * zeta[20] + lam_Kygamma[2];
  R_omega_0 = alpha[2] + SHy[2];
  R_omega[2] = R_omega_0;
  if (std::isnan(R_omega_0)) {
    lam_Cz[2] = (rtNaN);
  } else if (R_omega_0 < 0.0) {
    lam_Cz[2] = -1.0;
  } else {
    lam_Cz[2] = (R_omega_0 > 0.0);
  }

  lam_muy_prime_idx_3 = 0.0 * dfz[3] * Fz_ext[3] * scaleFactors[94] *
    lam_muy_prime_idx_3 * zeta[29] + lam_Kygamma[3];
  R_omega_0 = alpha[3] + SHy[3];
  R_omega[3] = R_omega_0;
  if (std::isnan(R_omega_0)) {
    lam_Cz[3] = (rtNaN);
  } else if (R_omega_0 < 0.0) {
    lam_Cz[3] = -1.0;
  } else {
    lam_Cz[3] = (R_omega_0 > 0.0);
  }

  for (i = 0; i < 4; i++) {
    if (lam_Cz[i] == 0.0) {
      lam_Cz[i] = 1.0;
    }
  }

  Vs_tmp = gamma_star[0] * gamma_star[0];
  Vs[0] = ((Vs_tmp * b_PEY5 + 1.0) - b_PEY4 * gamma_star[0] * lam_Cz[0]) *
    (b_PEY2 * dfz[0] + b_PEY1) * scaleFactors[9];
  Vs_tmp_0 = gamma_star[1] * gamma_star[1];
  Vs[1] = ((Vs_tmp_0 * b_PEY5 + 1.0) - b_PEY4 * gamma_star[1] * lam_Cz[1]) *
    (b_PEY2 * dfz[1] + b_PEY1) * scaleFactors[36];
  Vs_tmp_1 = gamma_star[2] * gamma_star[2];
  Vs[2] = ((Vs_tmp_1 * b_PEY5 + 1.0) - b_PEY4 * gamma_star[2] * lam_Cz[2]) *
    (b_PEY2 * dfz[2] + b_PEY1) * scaleFactors[63];
  lam_Cz_0 = gamma_star[3] * gamma_star[3];
  Vs[3] = ((lam_Cz_0 * b_PEY5 + 1.0) - b_PEY4 * gamma_star[3] * lam_Cz[3]) *
    (b_PEY2 * dfz[3] + b_PEY1) * scaleFactors[90];
  for (i = 0; i < 4; i++) {
    if (Vs[i] > 1.0) {
      Vs[i] = 1.0;
    }
  }

  AdasPlantModel0_magicsin_d(Vsy, Mzphiinf, epsilon_gamma, Vs, R_omega,
    rhoz_data);
  d_y = (0.0 * dfz[0] + b_RVY3 * gamma_star[0]) * mu_y_idx_0 * std::cos(std::
    atan(b_RVY4 * alpha[0])) * zeta[2] * std::sin(std::atan(b_RVY6 * kappa[0]) *
    b_RVY5) * scaleFactors[20];
  mu_y_idx_0 = d_y;
  Fy[0] = (rhoz_data[0] + lam_muy_prime_idx_0) * Fy[0] + d_y;
  Eykappa[0] = scaleFactors[25];
  d_y = (0.0 * dfz[1] + b_RVY3 * gamma_star[1]) * mu_y_idx_1 * std::cos(std::
    atan(b_RVY4 * alpha[1])) * zeta[11] * std::sin(std::atan(b_RVY6 * kappa[1]) *
    b_RVY5) * scaleFactors[47];
  mu_y_idx_1 = d_y;
  Fy[1] = (rhoz_data[1] + lam_muy_prime_idx_1) * Fy[1] + d_y;
  Eykappa[1] = scaleFactors[52];
  d_y = (0.0 * dfz[2] + b_RVY3 * gamma_star[2]) * mu_y_idx_2 * std::cos(std::
    atan(b_RVY4 * alpha[2])) * zeta[20] * std::sin(std::atan(b_RVY6 * kappa[2]) *
    b_RVY5) * scaleFactors[74];
  mu_y_idx_2 = d_y;
  Fy[2] = (rhoz_data[2] + lam_muy_prime_idx_2) * Fy[2] + d_y;
  Eykappa[2] = scaleFactors[79];
  d_y = (0.0 * dfz[3] + b_RVY3 * gamma_star[3]) * ec_data * std::cos(std::atan
    (b_RVY4 * alpha[3])) * zeta[29] * std::sin(std::atan(b_RVY6 * kappa[3]) *
    b_RVY5) * scaleFactors[101];
  Fy[3] = (rhoz_data[3] + lam_muy_prime_idx_3) * Fy[3] + d_y;
  Eykappa[3] = scaleFactors[106];
  AdasPlantModel0_rollingMoment(Fx, Vx, FzUnSat, press, b_gamma, b_LONGVL,
    b_UNLOADED_RADIUS, b_FNOMIN, b_NOMPRES, b_QSY1, b_QSY2, b_QSY3, b_QSY4,
    b_QSY5, b_QSY6, b_QSY7, b_QSY8, Eykappa, rhoz_data);
  My[0] = std::tanh(10.0 * Omega[0]) * rhoz_data[0];
  ec_data = b_QSX6 * Fz_ext[0] / b_FNOMIN;
  R_omega_0 = b_UNLOADED_RADIUS * Fz_ext[0];
  Bykappa[0] = R_omega_0;
  lam_Cz_tmp_tmp = std::abs(b_gamma[0]);
  Mx[0] = (((((0.0 * scaleFactors[24] - (b_PPMX1 * dpi_idx_0 + 1.0) * (b_QSX2 *
    b_gamma[0])) - b_QSX12 * b_gamma[0] * lam_Cz_tmp_tmp) + b_QSX3 * Fy[0] /
             b_FNOMIN) + std::sin(std::atan(b_QSX9 * Fy[0] / b_FNOMIN) * b_QSX8
             + b_QSX7 * b_gamma[0]) * (std::cos(std::atan(ec_data * ec_data) *
              b_QSX5) * b_QSX4)) + std::atan(b_QSX11 * Fz_ext[0] / b_FNOMIN) *
           b_QSX10 * b_gamma[0]) * (R_omega_0 * scaleFactors[23]) +
    b_UNLOADED_RADIUS * Fy[0] * scaleFactors[23] * (b_QSX14 * lam_Cz_tmp_tmp +
    b_QSX13);
  Mz[0] = Vx[0] / Mz[0];
  Vsy[0] = ((b_QHZ4 * dfz[0] + b_QHZ3) * gamma_star[0] + 0.0 * dfz[0]) + alpha[0];
  SHy[0] = (lam_muy_prime_idx_0 / b_x[0] + SHy[0]) + alpha[0];
  Vs_0 = 0.0 * b_gamma[0] + 1.0;
  Vs[0] = Vs_0;
  Eykappa[0] = ((b_QBZ2 * dfz[0] + b_QBZ1) + x_idx_0 * b_QBZ3) * ((b_QBZ5 *
    lam_Cz_tmp_tmp + Vs_0) + Vs_tmp * b_QBZ6) * scaleFactors[5] / lam_muy[0];
  My[1] = std::tanh(10.0 * Omega[1]) * rhoz_data[1];
  ec_data = b_QSX6 * Fz_ext[1] / b_FNOMIN;
  R_omega_0 = b_UNLOADED_RADIUS * Fz_ext[1];
  Bykappa[1] = R_omega_0;
  lam_Cz_tmp_tmp = std::abs(b_gamma[1]);
  Mx[1] = (((((0.0 * scaleFactors[51] - (b_PPMX1 * dpi_idx_1 + 1.0) * (b_QSX2 *
    b_gamma[1])) - b_QSX12 * b_gamma[1] * lam_Cz_tmp_tmp) + b_QSX3 * Fy[1] /
             b_FNOMIN) + std::sin(std::atan(b_QSX9 * Fy[1] / b_FNOMIN) * b_QSX8
             + b_QSX7 * b_gamma[1]) * (std::cos(std::atan(ec_data * ec_data) *
              b_QSX5) * b_QSX4)) + std::atan(b_QSX11 * Fz_ext[1] / b_FNOMIN) *
           b_QSX10 * b_gamma[1]) * (R_omega_0 * scaleFactors[50]) +
    b_UNLOADED_RADIUS * Fy[1] * scaleFactors[50] * (b_QSX14 * lam_Cz_tmp_tmp +
    b_QSX13);
  Mz[1] = Vx[1] / Mz[1];
  Vsy[1] = ((b_QHZ4 * dfz[1] + b_QHZ3) * gamma_star[1] + 0.0 * dfz[1]) + alpha[1];
  SHy[1] = (lam_muy_prime_idx_1 / b_x[1] + SHy[1]) + alpha[1];
  Vs_0 = 0.0 * b_gamma[1] + 1.0;
  Vs[1] = Vs_0;
  Eykappa[1] = ((b_QBZ2 * dfz[1] + b_QBZ1) + lam_Cz_tmp * b_QBZ3) * ((b_QBZ5 *
    lam_Cz_tmp_tmp + Vs_0) + Vs_tmp_0 * b_QBZ6) * scaleFactors[32] / lam_muy[1];
  My[2] = std::tanh(10.0 * Omega[2]) * rhoz_data[2];
  ec_data = b_QSX6 * Fz_ext[2] / b_FNOMIN;
  R_omega_0 = b_UNLOADED_RADIUS * Fz_ext[2];
  Bykappa[2] = R_omega_0;
  lam_Cz_tmp_tmp = std::abs(b_gamma[2]);
  Mx[2] = (((((0.0 * scaleFactors[78] - (b_PPMX1 * dpi_idx_2 + 1.0) * (b_QSX2 *
    b_gamma[2])) - b_QSX12 * b_gamma[2] * lam_Cz_tmp_tmp) + b_QSX3 * Fy[2] /
             b_FNOMIN) + std::sin(std::atan(b_QSX9 * Fy[2] / b_FNOMIN) * b_QSX8
             + b_QSX7 * b_gamma[2]) * (std::cos(std::atan(ec_data * ec_data) *
              b_QSX5) * b_QSX4)) + std::atan(b_QSX11 * Fz_ext[2] / b_FNOMIN) *
           b_QSX10 * b_gamma[2]) * (R_omega_0 * scaleFactors[77]) +
    b_UNLOADED_RADIUS * Fy[2] * scaleFactors[77] * (b_QSX14 * lam_Cz_tmp_tmp +
    b_QSX13);
  Mz[2] = Vx[2] / Mz[2];
  Vsy[2] = ((b_QHZ4 * dfz[2] + b_QHZ3) * gamma_star[2] + 0.0 * dfz[2]) + alpha[2];
  SHy[2] = (lam_muy_prime_idx_2 / b_x[2] + SHy[2]) + alpha[2];
  Vs_0 = 0.0 * b_gamma[2] + 1.0;
  Vs[2] = Vs_0;
  Eykappa[2] = ((b_QBZ2 * dfz[2] + b_QBZ1) + ab_idx_0 * b_QBZ3) * ((b_QBZ5 *
    lam_Cz_tmp_tmp + Vs_0) + Vs_tmp_1 * b_QBZ6) * scaleFactors[59] / lam_muy[2];
  My[3] = std::tanh(10.0 * Omega[3]) * rhoz_data[3];
  ec_data = b_QSX6 * Fz_ext[3] / b_FNOMIN;
  R_omega_0 = b_UNLOADED_RADIUS * Fz_ext[3];
  lam_Cz_tmp_tmp = std::abs(b_gamma[3]);
  Mx[3] = (((((0.0 * scaleFactors[105] - (b_PPMX1 * dpi_idx_3 + 1.0) * (b_QSX2 *
    b_gamma[3])) - b_QSX12 * b_gamma[3] * lam_Cz_tmp_tmp) + b_QSX3 * Fy[3] /
             b_FNOMIN) + std::sin(std::atan(b_QSX9 * Fy[3] / b_FNOMIN) * b_QSX8
             + b_QSX7 * b_gamma[3]) * (std::cos(std::atan(ec_data * ec_data) *
              b_QSX5) * b_QSX4)) + std::atan(b_QSX11 * Fz_ext[3] / b_FNOMIN) *
           b_QSX10 * b_gamma[3]) * (R_omega_0 * scaleFactors[104]) +
    b_UNLOADED_RADIUS * Fy[3] * scaleFactors[104] * (b_QSX14 * lam_Cz_tmp_tmp +
    b_QSX13);
  Mz[3] = Vx[3] / Mz[3];
  Vsy[3] = ((b_QHZ4 * dfz[3] + b_QHZ3) * gamma_star[3] + 0.0 * dfz[3]) + alpha[3];
  SHy[3] = (lam_muy_prime_idx_3 / b_x[3] + SHy[3]) + alpha[3];
  Vs_0 = 0.0 * b_gamma[3] + 1.0;
  Eykappa[3] = ((b_QBZ2 * dfz[3] + b_QBZ1) + Bykappa_tmp * b_QBZ3) * ((b_QBZ5 *
    lam_Cz_tmp_tmp + Vs_0) + lam_Cz_0 * b_QBZ6) * scaleFactors[86] / a_tmp;
  for (i = 0; i < 4; i++) {
    if (Eykappa[i] < 0.0) {
      Eykappa[i] = 0.0;
    }
  }

  ec_data = b_QCZ1;
  if (b_QCZ1 < 0.0) {
    ec_data = 0.0;
  }

  SHykappa[0] = (b_QEZ5 * gamma_star[0] * 2.0 / 3.1415926535897931 * std::atan
                 (Eykappa[0] * ec_data * Vsy[0]) + 1.0) * ((b_QEZ2 * dfz[0] +
    b_QEZ1) + x_idx_0 * b_QEZ3);
  SHykappa[1] = (b_QEZ5 * gamma_star[1] * 2.0 / 3.1415926535897931 * std::atan
                 (ec_data * Eykappa[1] * Vsy[1]) + 1.0) * ((b_QEZ2 * dfz[1] +
    b_QEZ1) + lam_Cz_tmp * b_QEZ3);
  SHykappa[2] = (b_QEZ5 * gamma_star[2] * 2.0 / 3.1415926535897931 * std::atan
                 (ec_data * Eykappa[2] * Vsy[2]) + 1.0) * ((b_QEZ2 * dfz[2] +
    b_QEZ1) + ab_idx_0 * b_QEZ3);
  SHykappa[3] = (b_QEZ5 * gamma_star[3] * 2.0 / 3.1415926535897931 * std::atan
                 (ec_data * Eykappa[3] * Vsy[3]) + 1.0) * ((b_QEZ2 * dfz[3] +
    b_QEZ1) + Bykappa_tmp * b_QEZ3);
  for (i = 0; i < 4; i++) {
    if (SHykappa[i] > 1.0) {
      SHykappa[i] = 1.0;
    }
  }

  lam_Cz_0 = std::tan(SHy[0]);
  lam_muy_prime_idx_3 = phi_t[0] / b_x[0];
  Vs_tmp_1 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (kappa[0] * kappa[0]);
  lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1);
  lam_Cz_0 = std::tan(Vsy[0]);
  dc_data[0] = (b_QDZ2 * dfz[0] + b_QDZ1) * (1.0 - b_PPZ1 * dpi_idx_0) *
    (gamma_star_tmp * b_QDZ4 + Vs[0]) * Fz_ext[0] * (b_UNLOADED_RADIUS /
    Fzo_prime_idx_0) * scaleFactors[16] * zeta[5];
  phi[0] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1)) * std::tanh
    (1000.0 * Vsy[0]);
  FzUnSat[0] = ((((b_QDZ9 * dfz[0] + b_QDZ8) * (b_PPZ2 * dpi_idx_0 + 1.0) +
                  (b_QDZ11 * dfz[0] + b_QDZ10) * std::abs(gamma_star[0])) *
                 gamma_star[0] * scaleFactors[15] * zeta[0] + 0.0 * dfz[0] *
                 scaleFactors[17] * zeta[2]) * Bykappa[0] * lam_muy[0] * std::
                tanh(10.0 * Vx[0]) * Mz[0] + zeta[8]) - 1.0;
  kappa_x[0] = zeta[7];
  lam_Cz[0] = (b_QBZ9 * scaleFactors[5] / lam_muy[0] + b_QBZ10 * epsilon_gamma[0]
               * Mzphiinf[0]) * zeta[6];
  Kygammao[0] = std::tanh(1000.0 * SHy[0]) * std::atan(lam_muy_prime_idx_3);
  lam_Cz_0 = std::tan(SHy[1]);
  lam_muy_prime_idx_3 = phi_t[1] / b_x[1];
  Vs_tmp_1 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (kappa[1] * kappa[1]);
  lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1);
  lam_Cz_0 = std::tan(Vsy[1]);
  dc_data[1] = (b_QDZ2 * dfz[1] + b_QDZ1) * (1.0 - b_PPZ1 * dpi_idx_1) *
    (gamma_star_tmp_0 * b_QDZ4 + Vs[1]) * Fz_ext[1] * (b_UNLOADED_RADIUS /
    Fzo_prime_idx_1) * scaleFactors[43] * zeta[14];
  phi[1] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1)) * std::tanh
    (1000.0 * Vsy[1]);
  FzUnSat[1] = ((((b_QDZ9 * dfz[1] + b_QDZ8) * (b_PPZ2 * dpi_idx_1 + 1.0) +
                  (b_QDZ11 * dfz[1] + b_QDZ10) * std::abs(gamma_star[1])) *
                 gamma_star[1] * scaleFactors[42] * zeta[9] + 0.0 * dfz[1] *
                 scaleFactors[44] * zeta[11]) * Bykappa[1] * lam_muy[1] * std::
                tanh(10.0 * Vx[1]) * Mz[1] + zeta[17]) - 1.0;
  kappa_x[1] = zeta[16];
  lam_Cz[1] = (b_QBZ9 * scaleFactors[32] / lam_muy[1] + b_QBZ10 * epsilon_gamma
               [1] * Mzphiinf[1]) * zeta[15];
  Kygammao[1] = std::tanh(1000.0 * SHy[1]) * std::atan(lam_muy_prime_idx_3);
  lam_Cz_0 = std::tan(SHy[2]);
  lam_muy_prime_idx_3 = phi_t[2] / b_x[2];
  Vs_tmp_1 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (kappa[2] * kappa[2]);
  lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1);
  lam_Cz_0 = std::tan(Vsy[2]);
  dc_data[2] = (b_QDZ2 * dfz[2] + b_QDZ1) * (1.0 - b_PPZ1 * dpi_idx_2) *
    (gamma_star_tmp_1 * b_QDZ4 + Vs[2]) * Fz_ext[2] * (b_UNLOADED_RADIUS /
    Fzo_prime_idx_2) * scaleFactors[70] * zeta[23];
  phi[2] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1)) * std::tanh
    (1000.0 * Vsy[2]);
  FzUnSat[2] = ((((b_QDZ9 * dfz[2] + b_QDZ8) * (b_PPZ2 * dpi_idx_2 + 1.0) +
                  (b_QDZ11 * dfz[2] + b_QDZ10) * std::abs(gamma_star[2])) *
                 gamma_star[2] * scaleFactors[69] * zeta[18] + 0.0 * dfz[2] *
                 scaleFactors[71] * zeta[20]) * Bykappa[2] * lam_muy[2] * std::
                tanh(10.0 * Vx[2]) * Mz[2] + zeta[26]) - 1.0;
  kappa_x[2] = zeta[25];
  lam_Cz[2] = (b_QBZ9 * scaleFactors[59] / lam_muy[2] + b_QBZ10 * epsilon_gamma
               [2] * Mzphiinf[2]) * zeta[24];
  Kygammao[2] = std::tanh(1000.0 * SHy[2]) * std::atan(lam_muy_prime_idx_3);
  lam_Cz_0 = std::tan(SHy[3]);
  lam_muy_prime_idx_3 = Dx_tmp / b_x[3];
  Vs_tmp_1 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (kappa[3] * kappa[3]);
  lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1);
  lam_Cz_0 = std::tan(Vsy[3]);
  dc_data[3] = (b_QDZ2 * dfz[3] + b_QDZ1) * (1.0 - b_PPZ1 * dpi_idx_3) *
    (gamma_star_tmp_2 * b_QDZ4 + Vs_0) * Fz_ext[3] * (b_UNLOADED_RADIUS /
    Fzo_prime_idx_3) * scaleFactors[97] * zeta[32];
  phi[3] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Vs_tmp_1)) * std::tanh
    (1000.0 * Vsy[3]);
  FzUnSat[3] = ((((b_QDZ9 * dfz[3] + b_QDZ8) * (b_PPZ2 * dpi_idx_3 + 1.0) +
                  (b_QDZ11 * dfz[3] + b_QDZ10) * std::abs(gamma_star[3])) *
                 gamma_star[3] * scaleFactors[96] * zeta[27] + 0.0 * dfz[3] *
                 scaleFactors[98] * zeta[29]) * R_omega_0 * a_tmp * std::tanh
                (10.0 * Vx[3]) * Mz[3] + zeta[35]) - 1.0;
  kappa_x[3] = zeta[34];
  lam_Cz[3] = (b_QBZ9 * scaleFactors[86] / a_tmp + b_QBZ10 * epsilon_gamma[3] *
               Mzphiinf[3]) * zeta[33];
  Kygammao[3] = std::tanh(1000.0 * SHy[3]) * std::atan(lam_muy_prime_idx_3);
  AdasPlantModel0_magiccos_l1m(dc_data, ec_data, Eykappa, SHykappa, phi,
    rhoz_data);
  AdasPlantModel0_magiccos_l1(FzUnSat, kappa_x, lam_Cz, Kygammao, dc_data);
  Mz[0] = ((b_SSZ4 * dfz[0] + b_SSZ3) * gamma_star[0] + b_SSZ2 * Fy[0] /
           b_FNOMIN) * b_UNLOADED_RADIUS * scaleFactors[21] * mu_y_tmp +
    (-(rhoz_data[0] * Mz[0] * scaleFactors[0]) * (Fy[0] - mu_y_idx_0) + dc_data
     [0]);
  sig_x[0] = std::abs(phi_t[0] / (((b_PCFX1 * dfz[0] + 1.0) + x_idx_0 * b_PCFX2)
    * b_LONGITUDINAL_STIFFNESS * (b_PCFX3 * dpi_idx_0 + 1.0)));
  sig_y[0] = std::abs(dfz_0 / (((b_PCFY1 * dfz[0] + 1.0) + x_idx_0 * b_PCFY2) *
    b_LATERAL_STIFFNESS * (b_PCFY3 * dpi_idx_0 + 1.0)));
  Mz[1] = ((b_SSZ4 * dfz[1] + b_SSZ3) * gamma_star[1] + b_SSZ2 * Fy[1] /
           b_FNOMIN) * b_UNLOADED_RADIUS * scaleFactors[48] * Dx_tmp_0 +
    (-(rhoz_data[1] * Mz[1] * scaleFactors[27]) * (Fy[1] - mu_y_idx_1) +
     dc_data[1]);
  sig_x[1] = std::abs(phi_t[1] / (((b_PCFX1 * dfz[1] + 1.0) + lam_Cz_tmp *
    b_PCFX2) * b_LONGITUDINAL_STIFFNESS * (b_PCFX3 * dpi_idx_1 + 1.0)));
  sig_y[1] = std::abs(Vsy_tmp / (((b_PCFY1 * dfz[1] + 1.0) + lam_Cz_tmp *
    b_PCFY2) * b_LATERAL_STIFFNESS * (b_PCFY3 * dpi_idx_1 + 1.0)));
  Mz[2] = ((b_SSZ4 * dfz[2] + b_SSZ3) * gamma_star[2] + b_SSZ2 * Fy[2] /
           b_FNOMIN) * b_UNLOADED_RADIUS * scaleFactors[75] * Dx_tmp_1 +
    (-(rhoz_data[2] * Mz[2] * scaleFactors[54]) * (Fy[2] - mu_y_idx_2) +
     dc_data[2]);
  sig_x[2] = std::abs(phi_t[2] / (((b_PCFX1 * dfz[2] + 1.0) + ab_idx_0 * b_PCFX2)
    * b_LONGITUDINAL_STIFFNESS * (b_PCFX3 * dpi_idx_2 + 1.0)));
  sig_y[2] = std::abs(Vsy_tmp_0 / (((b_PCFY1 * dfz[2] + 1.0) + ab_idx_0 *
    b_PCFY2) * b_LATERAL_STIFFNESS * (b_PCFY3 * dpi_idx_2 + 1.0)));
  Mz[3] = ((b_SSZ4 * dfz[3] + b_SSZ3) * gamma_star[3] + b_SSZ2 * Fy[3] /
           b_FNOMIN) * b_UNLOADED_RADIUS * scaleFactors[102] * Dx_tmp_2 +
    (-(rhoz_data[3] * Mz[3] * scaleFactors[81]) * (Fy[3] - d_y) + dc_data[3]);
  sig_x[3] = std::abs(Dx_tmp / (((b_PCFX1 * dfz[3] + 1.0) + Bykappa_tmp *
    b_PCFX2) * b_LONGITUDINAL_STIFFNESS * (b_PCFX3 * dpi_idx_3 + 1.0)));
  sig_y[3] = std::abs(Vsy_tmp_1 / (((b_PCFY1 * dfz[3] + 1.0) + Bykappa_tmp *
    b_PCFY2) * b_LATERAL_STIFFNESS * (b_PCFY3 * dpi_idx_3 + 1.0)));
}

void AdasPlantModel0::AdasPlan_binary_expand_op_nxejp(real_T in1[4], const
  int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], const real_T
  in4[4], real_T in5, const real_T in6[4], real_T in7, const real_T in8[108])
{
  real_T in4_data[4];
  real_T tmp_data[4];
  int32_T in3_tmp;
  int32_T loop_ub;
  int32_T stride_0_0_tmp;
  int32_T stride_1_0;
  int32_T tmp_size;

  /* MATLAB Function: '<S513>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S510>/Vector Concatenate'
   */
  loop_ub = *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in4_data[tmp_size] = in4[in2_data[tmp_size]];
  }

  AdasPlantModel0_abs(in4_data, in2_size, tmp_data, &tmp_size);
  loop_ub = *in2_size == 1 ? *in2_size == 1 ? tmp_size == 1 ? *in2_size :
    tmp_size : *in2_size : *in2_size;
  stride_0_0_tmp = (*in2_size != 1);
  stride_1_0 = (tmp_size != 1);
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in3_tmp = in2_data[tmp_size * stride_0_0_tmp];
    in4_data[tmp_size] = (in6[in3_tmp] * in5 / in7 + in3[in3_tmp] /
                          tmp_data[tmp_size * stride_1_0]) * in8[in3_tmp * 27 +
      22];
  }

  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in1[static_cast<int8_T>(in2_data[tmp_size])] = in4_data[tmp_size];
  }

  /* End of MATLAB Function: '<S513>/Magic Tire Const Input' */
}

void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1[9],
  real_T y[3])
{
  real_T A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  std::memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(u1[0]);
  a21 = std::abs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u1[r2] / u1[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (std::abs(A[r3 + 3]) > std::abs(A[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[r1] = u0[0] / A[r1];
  y[r2] = u0[1] - A[r1 + 3] * y[r1];
  y[r3] = u0[2] - A[r1 + 6] * y[r1];
  y[r2] /= A[r2 + 3];
  y[r3] -= A[r2 + 6] * y[r2];
  y[r3] /= A[r3 + 6];
  y[r2] -= A[r3 + 3] * y[r3];
  y[r1] -= y[r3] * A[r3];
  y[r1] -= y[r2] * A[r2];
}

/* Function for MATLAB Function: '<S552>/Open Differential' */
void AdasPlantModel0::AdasPlantModel0_automldiffopen(const real_T u[3], real_T
  bw1, real_T bd, real_T bw2, real_T Ndiff, real_T shaftSwitch, real_T Jd,
  real_T Jw1, real_T Jw2, const real_T x[2], real_T y[3], real_T xdot[2])
{
  real_T diffDir_0[6];
  real_T diffDir_1[6];
  real_T invJ_0[6];
  real_T invJ[4];
  real_T NbdTerm;
  real_T invJ_1;
  real_T invJ_tmp;
  real_T term1;
  real_T term2;
  int32_T diffDir;
  term1 = Ndiff * Ndiff;
  NbdTerm = term1 * bd / 4.0;
  if (shaftSwitch != 0.0) {
    diffDir = -1;
  } else {
    diffDir = 1;
  }

  term1 *= Jd;
  term2 = (4.0 * Jw1 * Jw2 + term1 * Jw1) + Jw2 * term1;
  invJ[0] = (Jw2 * 4.0 + term1) / term2;
  invJ_tmp = -term1 / term2;
  invJ[2] = invJ_tmp;
  invJ[1] = invJ_tmp;
  invJ[3] = (Jw1 * 4.0 + term1) / term2;
  invJ_tmp = static_cast<real_T>(diffDir) / 2.0 * Ndiff;
  diffDir_0[0] = invJ_tmp;
  diffDir_0[2] = -1.0;
  diffDir_0[4] = 0.0;
  diffDir_0[1] = invJ_tmp;
  diffDir_0[3] = 0.0;
  diffDir_0[5] = -1.0;
  term1 = -(bw1 + NbdTerm);
  term2 = -(NbdTerm + bw2);
  diffDir_1[0] = invJ_tmp;
  diffDir_1[3] = invJ_tmp;
  for (diffDir = 0; diffDir < 2; diffDir++) {
    invJ_tmp = invJ[diffDir + 2];
    invJ_1 = invJ[diffDir];
    for (int32_T i{0}; i < 3; i++) {
      int32_T invJ_tmp_0;
      invJ_tmp_0 = i << 1;
      invJ_0[diffDir + invJ_tmp_0] = diffDir_0[invJ_tmp_0 + 1] * invJ_tmp +
        diffDir_0[invJ_tmp_0] * invJ_1;
    }

    xdot[diffDir] = ((invJ_0[diffDir + 2] * u[1] + invJ_0[diffDir] * u[0]) +
                     invJ_0[diffDir + 4] * u[2]) + ((invJ_tmp * term2 + invJ_1 *
      -NbdTerm) * x[1] + (invJ_tmp * -NbdTerm + invJ_1 * term1) * x[0]);
    diffDir_1[3 * diffDir + 1] = static_cast<real_T>(diffDir) - 1.0;
    diffDir_1[3 * diffDir + 2] = 0.0 - static_cast<real_T>(diffDir);
  }

  NbdTerm = x[1];
  term1 = x[0];
  term2 = u[0];
  invJ_tmp = u[1];
  invJ_1 = u[2];
  for (diffDir = 0; diffDir < 3; diffDir++) {
    y[diffDir] = (diffDir_1[diffDir + 3] * NbdTerm + diffDir_1[diffDir] * term1)
      + ((0.0 * term2 + 0.0 * invJ_tmp) + 0.0 * invJ_1);
  }
}

/* System initialize for atomic system: '<Root>/AdasPlantModel' */
void AdasPlantModel0::AdasPlantMo_AdasPlantModel_Init
  (B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
   *localDW, P_AdasPlantModel_AdasPlantMod_T *localP, P_AdasPlantModel0_T
   *AdasPlantModel0_P, X_AdasPlantModel_AdasPlantMod_T *localX,
   ZCE_AdasPlantModel_AdasPlantM_T *localZCE)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T i;

  /* Start for Constant: '<S578>/domega_o' */
  localB->domega_o = AdasPlantModel0_P->PlntDriveshftInitVel;

  /* Start for Constant: '<S586>/domega_o' */
  localB->domega_o_o = AdasPlantModel0_P->PlntDriveshftInitVel;

  /* Start for Constant: '<S600>/domega_o' */
  localB->domega_o_b = AdasPlantModel0_P->PlntDriveshftInitVel;

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  std::memcpy(&localDW->UnitDelay_1_DSTATE[0],
              &localP->UnitDelay_1_InitialCondition[0], 96U * sizeof(real32_T));

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  std::memcpy(&localDW->UnitDelay_4_DSTATE[0],
              &localP->UnitDelay_4_InitialCondition[0], 96U * sizeof(real32_T));

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  localDW->UnitDelay_2_DSTATE = localP->UnitDelay_2_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  localDW->UnitDelay_5_DSTATE = localP->UnitDelay_5_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  localDW->UnitDelay_6_DSTATE = localP->UnitDelay_6_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S25>/Unit Delay' */
  localDW->UnitDelay_3_DSTATE = localP->UnitDelay_3_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = static_cast<real32_T>
    (AdasPlantModel0_P->PlntBattSocInit);

  /* InitializeConditions for Integrator: '<S630>/Integrator' incorporates:
   *  Integrator: '<S579>/Integrator'
   */
  if (rtmIsFirstInitCond((&AdasPlantModel0_M))) {
    localX->Integrator_CSTATE = 0.0;
    localX->Integrator_CSTATE_i = 0.0;
  }

  localDW->Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S630>/Integrator' */

  /* InitializeConditions for RateTransition: '<S21>/Rate Transition18' */
  localDW->RateTransition18_Buffer[0] = localP->RateTransition18_InitialConditi;

  /* InitializeConditions for RateTransition: '<S21>/Rate Transition19' */
  localDW->RateTransition19_Buffer[0] = localP->RateTransition19_InitialConditi;

  /* InitializeConditions for RateTransition: '<S21>/Rate Transition20' */
  localDW->RateTransition20_Buffer[0] = localP->RateTransition20_InitialConditi;

  /* InitializeConditions for RateTransition: '<S21>/Rate Transition21' */
  localDW->RateTransition21_Buffer[0] = localP->RateTransition21_InitialConditi;

  /* InitializeConditions for Integrator: '<S609>/Integrator' */
  localX->Integrator_CSTATE_j = AdasPlantModel0_P->PlntEM1RotInitSpd;

  /* InitializeConditions for Integrator: '<S406>/ub,vb,wb' */
  localX->ubvbwb_CSTATE[0] = localP->VehicleBody6DOF_xbdot_o[0];
  localX->ubvbwb_CSTATE[1] = localP->VehicleBody6DOF_xbdot_o[1];
  localX->ubvbwb_CSTATE[2] = localP->VehicleBody6DOF_xbdot_o[2];

  /* InitializeConditions for FirstOrderHold: '<S79>/First Order Hold' */
  localDW->Tk = (rtInf);
  localDW->Ck = localP->FirstOrderHold_IniOut;
  localDW->Uk = (rtInf);

  /* InitializeConditions for Integrator: '<S105>/Integrator1' */
  localX->Integrator1_CSTATE[0] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S516>/Integrator' */
  localX->Integrator_CSTATE_f[0] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_p[0] = localP->Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S373>/Integrator1' */
  localX->Integrator1_CSTATE_c[0] = localP->Integrator1_IC_b;

  /* InitializeConditions for Integrator: '<S105>/Integrator1' */
  localX->Integrator1_CSTATE[1] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S516>/Integrator' */
  localX->Integrator_CSTATE_f[1] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_p[1] = localP->Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S373>/Integrator1' */
  localX->Integrator1_CSTATE_c[1] = localP->Integrator1_IC_b;

  /* InitializeConditions for Integrator: '<S105>/Integrator1' */
  localX->Integrator1_CSTATE[2] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S516>/Integrator' */
  localX->Integrator_CSTATE_f[2] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_p[2] = localP->Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S373>/Integrator1' */
  localX->Integrator1_CSTATE_c[2] = localP->Integrator1_IC_b;

  /* InitializeConditions for Integrator: '<S105>/Integrator1' */
  localX->Integrator1_CSTATE[3] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S516>/Integrator' */
  localX->Integrator_CSTATE_f[3] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_p[3] = localP->Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S373>/Integrator1' */
  localX->Integrator1_CSTATE_c[3] = localP->Integrator1_IC_b;

  /* InitializeConditions for Memory: '<S579>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S579>/Integrator' */
  localDW->Integrator_IWORK_a = 1;

  /* InitializeConditions for Integrator: '<S578>/Integrator' */
  localX->Integrator_CSTATE_m = AdasPlantModel0_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Memory: '<S587>/Memory' */
  localDW->Memory_PreviousInput_g = localP->Memory_InitialCondition_e;

  /* InitializeConditions for Integrator: '<S587>/Integrator' */
  if (rtmIsFirstInitCond((&AdasPlantModel0_M))) {
    localX->Integrator_CSTATE_fd = 0.0;
  }

  localDW->Integrator_IWORK_c = 1;

  /* End of InitializeConditions for Integrator: '<S587>/Integrator' */

  /* InitializeConditions for Integrator: '<S586>/Integrator' */
  localX->Integrator_CSTATE_jc = AdasPlantModel0_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Integrator: '<S519>/Integrator' */
  localX->Integrator_CSTATE_m1[0] = localP->Integrator_IC_l;

  /* InitializeConditions for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[0] =
    AdasPlantModel0_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S519>/Integrator' */
  localX->Integrator_CSTATE_m1[1] = localP->Integrator_IC_l;

  /* InitializeConditions for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[1] =
    AdasPlantModel0_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S519>/Integrator' */
  localX->Integrator_CSTATE_m1[2] = localP->Integrator_IC_l;

  /* InitializeConditions for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[2] =
    AdasPlantModel0_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S519>/Integrator' */
  localX->Integrator_CSTATE_m1[3] = localP->Integrator_IC_l;

  /* InitializeConditions for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[3] =
    AdasPlantModel0_P->PlntVehInitVertPos;
  localX->IntegratorSecondOrder_CSTATE[4] = localP->CombinedSlipWheel2DOF_zdoto
    [0];
  localX->IntegratorSecondOrder_CSTATE[5] = localP->CombinedSlipWheel2DOF_zdoto
    [1];
  localX->IntegratorSecondOrder_CSTATE[6] = localP->CombinedSlipWheel2DOF_zdoto
    [2];
  localX->IntegratorSecondOrder_CSTATE[7] = localP->CombinedSlipWheel2DOF_zdoto
    [3];

  /* InitializeConditions for Integrator: '<S406>/p,q,r ' */
  localX->pqr_CSTATE[0] = localP->VehicleBody6DOF_p_o[0];
  localX->pqr_CSTATE[1] = localP->VehicleBody6DOF_p_o[1];
  localX->pqr_CSTATE[2] = localP->VehicleBody6DOF_p_o[2];

  /* InitializeConditions for Integrator: '<S374>/Integrator1' */
  for (i = 0; i < 12; i++) {
    localX->Integrator1_CSTATE_n[i] = localP->Integrator1_IC_m;
  }

  /* End of InitializeConditions for Integrator: '<S374>/Integrator1' */

  /* InitializeConditions for Integrator: '<S406>/xe,ye,ze' */
  localX->xeyeze_CSTATE[0] = localP->VehicleBody6DOF_Xe_o[0];

  /* InitializeConditions for Integrator: '<S412>/phi theta psi' */
  localX->phithetapsi_CSTATE[0] = localP->VehicleBody6DOF_eul_o[0];

  /* InitializeConditions for Integrator: '<S406>/xe,ye,ze' */
  localX->xeyeze_CSTATE[1] = localP->VehicleBody6DOF_Xe_o[1];

  /* InitializeConditions for Integrator: '<S412>/phi theta psi' */
  localX->phithetapsi_CSTATE[1] = localP->VehicleBody6DOF_eul_o[1];

  /* InitializeConditions for Integrator: '<S406>/xe,ye,ze' */
  localX->xeyeze_CSTATE[2] = localP->VehicleBody6DOF_Xe_o[2];

  /* InitializeConditions for Integrator: '<S412>/phi theta psi' */
  localX->phithetapsi_CSTATE[2] = localP->VehicleBody6DOF_eul_o[2];

  /* InitializeConditions for SecondOrderIntegrator: '<S157>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_h[0] = localP->IntegratorSecondOrder_ICX;
  localX->IntegratorSecondOrder_CSTATE_h[1] =
    localP->IntegratorSecondOrder_ICDXDT;

  /* InitializeConditions for Integrator: '<S289>/Integrator1' */
  localX->Integrator1_CSTATE_no[0] = localP->Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_b[0] = localP->Integrator1_IC_gh;

  /* InitializeConditions for Integrator: '<S289>/Integrator1' */
  localX->Integrator1_CSTATE_no[1] = localP->Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_b[1] = localP->Integrator1_IC_gh;

  /* InitializeConditions for Integrator: '<S289>/Integrator1' */
  localX->Integrator1_CSTATE_no[2] = localP->Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_b[2] = localP->Integrator1_IC_gh;

  /* InitializeConditions for Integrator: '<S289>/Integrator1' */
  localX->Integrator1_CSTATE_no[3] = localP->Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_b[3] = localP->Integrator1_IC_gh;

  /* InitializeConditions for Backlash: '<S117>/Backlash' */
  localDW->PrevY = localP->Backlash_InitialOutput;

  /* InitializeConditions for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_a[0] =
    localP->IntegratorSecondOrder_ICX_i;
  localX->IntegratorSecondOrder_CSTATE_a[1] =
    localP->IntegratorSecondOrder_ICDXDT_l;

  /* InitializeConditions for Integrator: '<S131>/Integrator' */
  localX->Integrator_CSTATE_e = localP->Integrator_IC_c2;

  /* InitializeConditions for Derivative: '<S131>/Derivative' */
  localDW->TimeStampA = (rtInf);
  localDW->TimeStampB = (rtInf);

  /* InitializeConditions for SecondOrderIntegrator: '<S138>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_m[0] =
    localP->IntegratorSecondOrder_ICX_k;
  localX->IntegratorSecondOrder_CSTATE_m[1] =
    localP->IntegratorSecondOrder_ICDXDT_a;

  /* InitializeConditions for Integrator: '<S126>/Integrator1' */
  localX->Integrator1_CSTATE_c1 = localP->Integrator1_IC_e;

  /* InitializeConditions for Memory generated from: '<S132>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemInp =
    localP->TmpLatchAtTriggeredSubsystemInp;

  /* InitializeConditions for Memory generated from: '<S132>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_e =
    localP->TmpLatchAtTriggeredSubsystemI_f;

  /* InitializeConditions for Memory generated from: '<S133>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_l =
    localP->TmpLatchAtTriggeredSubsystemI_m;

  /* InitializeConditions for Memory generated from: '<S133>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_d =
    localP->TmpLatchAtTriggeredSubsystemI_n;

  /* InitializeConditions for Memory: '<S132>/Memory' */
  localDW->Memory_PreviousInput_i = localP->Memory_InitialCondition_p;

  /* InitializeConditions for Memory: '<S132>/Memory1' */
  localDW->Memory1_PreviousInput = localP->Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S133>/Memory' */
  localDW->Memory_PreviousInput_e = localP->Memory_InitialCondition_i;

  /* InitializeConditions for Memory: '<S133>/Memory1' */
  localDW->Memory1_PreviousInput_f = localP->Memory1_InitialCondition_k;

  /* InitializeConditions for SecondOrderIntegrator: '<S244>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_b[0] =
    localP->IntegratorSecondOrder_ICX_o;
  localX->IntegratorSecondOrder_CSTATE_b[1] =
    localP->IntegratorSecondOrder_ICDXDT_c;

  /* InitializeConditions for Backlash: '<S204>/Backlash' */
  localDW->PrevY_f = localP->Backlash_InitialOutput_h;

  /* InitializeConditions for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_f[0] =
    localP->IntegratorSecondOrder_ICX_c;
  localX->IntegratorSecondOrder_CSTATE_f[1] =
    localP->IntegratorSecondOrder_ICDXDT_h;

  /* InitializeConditions for Integrator: '<S218>/Integrator' */
  localX->Integrator_CSTATE_n = localP->Integrator_IC_m;

  /* InitializeConditions for Derivative: '<S218>/Derivative' */
  localDW->TimeStampA_g = (rtInf);
  localDW->TimeStampB_h = (rtInf);

  /* InitializeConditions for SecondOrderIntegrator: '<S225>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_j[0] =
    localP->IntegratorSecondOrder_ICX_n;
  localX->IntegratorSecondOrder_CSTATE_j[1] =
    localP->IntegratorSecondOrder_ICDXDT_i;

  /* InitializeConditions for Integrator: '<S213>/Integrator1' */
  localX->Integrator1_CSTATE_j = localP->Integrator1_IC_gd;

  /* InitializeConditions for Memory generated from: '<S219>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_a =
    localP->TmpLatchAtTriggeredSubsystemI_e;

  /* InitializeConditions for Memory generated from: '<S219>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_c =
    localP->TmpLatchAtTriggeredSubsystem_fy;

  /* InitializeConditions for Memory generated from: '<S220>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_k =
    localP->TmpLatchAtTriggeredSubsystemI_a;

  /* InitializeConditions for Memory generated from: '<S220>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_m =
    localP->TmpLatchAtTriggeredSubsystemI_p;

  /* InitializeConditions for Memory: '<S219>/Memory' */
  localDW->Memory_PreviousInput_m = localP->Memory_InitialCondition_pm;

  /* InitializeConditions for Memory: '<S219>/Memory1' */
  localDW->Memory1_PreviousInput_d = localP->Memory1_InitialCondition_j;

  /* InitializeConditions for Memory: '<S220>/Memory' */
  localDW->Memory_PreviousInput_mf = localP->Memory_InitialCondition_a;

  /* InitializeConditions for Memory: '<S220>/Memory1' */
  localDW->Memory1_PreviousInput_k = localP->Memory1_InitialCondition_o;

  /* InitializeConditions for Integrator: '<S392>/Integrator1' */
  localX->Integrator1_CSTATE_m[0] = localP->Integrator1_IC_gq;
  localX->Integrator1_CSTATE_m[1] = localP->Integrator1_IC_gq;

  /* InitializeConditions for Integrator: '<S410>/Integrator' */
  localX->Integrator_CSTATE_k[0] = localP->Integrator_IC_f;
  localX->Integrator_CSTATE_k[1] = localP->Integrator_IC_f;
  localX->Integrator_CSTATE_k[2] = localP->Integrator_IC_f;

  /* InitializeConditions for Memory: '<S601>/Memory' */
  localDW->Memory_PreviousInput_l = localP->Memory_InitialCondition_f;

  /* InitializeConditions for Integrator: '<S601>/Integrator' incorporates:
   *  Integrator: '<S552>/Integrator'
   */
  if (rtmIsFirstInitCond((&AdasPlantModel0_M))) {
    localX->Integrator_CSTATE_d = 0.0;
    localX->Integrator_CSTATE_a[0] = 0.0;
    localX->Integrator_CSTATE_a[1] = 0.0;
  }

  localDW->Integrator_IWORK_c3 = 1;

  /* End of InitializeConditions for Integrator: '<S601>/Integrator' */

  /* InitializeConditions for Integrator: '<S600>/Integrator' */
  localX->Integrator_CSTATE_jcw = AdasPlantModel0_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Integrator: '<S552>/Integrator' */
  localDW->Integrator_IWORK_f = 1;

  /* InitializeConditions for TransferFcn: '<S657>/Motor Coupling Dynamics' */
  localX->MotorCouplingDynamics_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S643>/Integrator' incorporates:
   *  Integrator: '<S632>/Integrator Limited'
   */
  if (rtmIsFirstInitCond((&AdasPlantModel0_M))) {
    localX->Integrator_CSTATE_o = 0.0;
    localX->IntegratorLimited_CSTATE = 0.0;
  }

  localDW->Integrator_IWORK_fi = 1;

  /* End of InitializeConditions for Integrator: '<S643>/Integrator' */

  /* InitializeConditions for Integrator: '<S665>/Integrator' */
  localX->Integrator_CSTATE_ky = localP->Integrator_IC_i;

  /* InitializeConditions for Integrator: '<S632>/Integrator Limited' */
  localDW->IntegratorLimited_IWORK = 1;

  /* InitializeConditions for SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[0] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[1] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[2] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[3] =
    localP->IntegratorSecondOrderLimited__m;

  /* InitializeConditions for SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__f[0] =
    localP->IntegratorSecondOrderLimited__o;

  /* InitializeConditions for SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[4] =
    localP->IntegratorSecondOrderLimited__m;

  /* InitializeConditions for SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__f[1] =
    localP->IntegratorSecondOrderLimited__o;

  /* InitializeConditions for SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[5] =
    localP->IntegratorSecondOrderLimited__m;

  /* InitializeConditions for SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__f[2] =
    localP->IntegratorSecondOrderLimited__o;
  localX->IntegratorSecondOrderLimited__f[3] =
    localP->IntegratorSecondOrderLimited__e;
  localX->IntegratorSecondOrderLimited__f[4] =
    localP->IntegratorSecondOrderLimited__e;
  localX->IntegratorSecondOrderLimited__f[5] =
    localP->IntegratorSecondOrderLimited__e;

  /* SystemInitialize for Chart: '<S30>/State_Machine' */
  localDW->ChrgCntctState = Contact::Open;
  localDW->InvtrCntctState = Contact::Open;

  /* SystemInitialize for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* SystemInitialize for Chart: '<S526>/Clutch' */
    if (ForEach_itr > 2147483646) {
      i = MAX_int32_T;
    } else {
      i = ForEach_itr + 1;
    }

    /* Outputs for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
    /* SystemInitialize for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
    AdasPlantModel0_Clutch_Init(localP->ClutchPartitionedParameters_ome[i - 1],
      &localB->CoreSubsys_k[ForEach_itr].sf_Clutch, &localDW->
      CoreSubsys_k[ForEach_itr].sf_Clutch, &localP->CoreSubsys_k.sf_Clutch,
      &localX->CoreSubsys_k[ForEach_itr].sf_Clutch);

    /* End of SystemInitialize for Chart: '<S526>/Clutch' */
    /* End of SystemInitialize for SubSystem: '<S522>/Clutch Partitioned Parameters' */
    /* End of Outputs for SubSystem: '<S522>/Clutch Partitioned Parameters' */
  }

  /* End of SystemInitialize for SubSystem: '<S522>/Clutch Partitioned Parameters' */

  /* SystemInitialize for Iterator SubSystem: '<S434>/Unwrap' */
  for (ForEach_itr_c = 0; ForEach_itr_c < 3; ForEach_itr_c++) {
    /* InitializeConditions for Memory: '<S439>/Memory1' */
    localDW->CoreSubsys_b[ForEach_itr_c].Memory1_PreviousInput =
      localP->CoreSubsys_b.Memory1_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S439>/Function-Call Subsystem' */
    /* InitializeConditions for UnitDelay: '<S441>/Unit Delay' */
    localDW->CoreSubsys_b[ForEach_itr_c].UnitDelay_DSTATE =
      localP->CoreSubsys_b.UnitDelay_InitialCondition;

    /* SystemInitialize for Sum: '<S441>/Sum' incorporates:
     *  Outport: '<S441>/Out1'
     */
    localB->CoreSubsys_b[ForEach_itr_c].Sum = localP->CoreSubsys_b.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S439>/Function-Call Subsystem' */
    localZCE->CoreSubsys_b[ForEach_itr_c].FunctionCallSubsystem_Trig_ZCE =
      POS_ZCSIG;
  }

  /* End of SystemInitialize for SubSystem: '<S434>/Unwrap' */

  /* SystemInitialize for Triggered SubSystem: '<S132>/Triggered Subsystem' */
  AdasPla_TriggeredSubsystem_Init(&localB->TriggeredSubsystem,
    &localP->TriggeredSubsystem);

  /* End of SystemInitialize for SubSystem: '<S132>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S132>/Enabled Subsystem' */
  AdasPlant_EnabledSubsystem_Init(&localB->EnabledSubsystem,
    &localP->EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S132>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S132>/Enabled Subsystem1' */
  AdasPlan_EnabledSubsystem1_Init(&localB->EnabledSubsystem1,
    &localP->EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S132>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S133>/Triggered Subsystem' */
  AdasPla_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_d,
    &localP->TriggeredSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S133>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  AdasPlant_EnabledSubsystem_Init(&localB->EnabledSubsystem_i,
    &localP->EnabledSubsystem_i);

  /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  AdasPlan_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_j,
    &localP->EnabledSubsystem1_j);

  /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S219>/Triggered Subsystem' */
  AdasPla_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_f,
    &localP->TriggeredSubsystem_f);

  /* End of SystemInitialize for SubSystem: '<S219>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  AdasPlant_EnabledSubsystem_Init(&localB->EnabledSubsystem_l,
    &localP->EnabledSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem1' */
  AdasPlan_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_c,
    &localP->EnabledSubsystem1_c);

  /* End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S220>/Triggered Subsystem' */
  AdasPla_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_e,
    &localP->TriggeredSubsystem_e);

  /* End of SystemInitialize for SubSystem: '<S220>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  AdasPlant_EnabledSubsystem_Init(&localB->EnabledSubsystem_o,
    &localP->EnabledSubsystem_o);

  /* End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem1' */
  AdasPlan_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_l,
    &localP->EnabledSubsystem1_l);

  /* End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem1' */
}

/* Outputs for atomic system: '<Root>/AdasPlantModel' */
void AdasPlantModel0::AdasPlantModel0_AdasPlantModel(real_T rtu_DriverSteerCmd,
  real_T rtu_DriverAccelCmd, real_T rtu_DriverBrakeCmd, real_T rtu_DriverGearCmd,
  real_T rtu_AdasEnable, real_T rtu_AdasSteerCmd, real_T rtu_AdasLongTrq, real_T
  rtu_AdasGearCmd, real_T rty_VehFdbk[3], real_T rty_VehFdbk_c[4],
  B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
  *localDW, P_AdasPlantModel_AdasPlantMod_T *localP, P_AdasPlantModel0_T
  *AdasPlantModel0_P, X_AdasPlantModel_AdasPlantMod_T *localX,
  ZCE_AdasPlantModel_AdasPlantM_T *localZCE)
{
  /* local block i/o variables */
  real_T rtb_Selector[2];
  real_T rtb_Selector1_e[2];
  real_T rtb_Selector2[2];
  real_T rtb_Selector3[2];
  real_T rtb_Selector_l[2];
  real_T rtb_Selector1_b[2];
  real_T rtb_IntegratorSecondOrder_o1;
  real_T rtb_Add2_n;
  real_T rtb_Add4;
  real_T rtb_Add2_f;
  real_T rtb_Add4_p;
  real_T rtb_Selector_k[2];
  real_T rtb_Selector1_i[2];
  real_T rtb_Selector2_e[2];
  real_T rtb_Selector3_i[2];
  real_T rtb_Selector14[2];
  real_T rtb_Selector15[2];
  real_T rtb_IntegratorSecondOrder_o1_i;
  real_T rtb_Add2_e;
  real_T rtb_Add4_l;
  real_T rtb_Add2_p;
  real_T rtb_Add4_f;
  real_T rtb_ImpAsg_InsertedFor_Fsa_y_at[2];
  real_T rtb_ImpAsg_InsertedFor_Fsa_y__f[2];
  real_T rtb_TmpLatchAtTriggeredSubsyste;
  real_T rtb_TmpLatchAtTriggeredSubsys_m;
  real_T rtb_TmpLatchAtTriggeredSubsys_i;
  real_T rtb_TmpLatchAtTriggeredSubsys_g;
  real_T rtb_TmpLatchAtTriggeredSubsys_f;
  real_T rtb_TmpLatchAtTriggeredSubsys_o;
  real_T rtb_TmpLatchAtTriggeredSubsys_l;
  real_T rtb_TmpLatchAtTriggeredSubsys_c;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_g;
  int32_T ForEach_itr_m;
  int32_T ForEach_itr_op;
  int32_T ForEach_itr_og;
  static const int8_T e[9]{ 1, -1, -1, -1, 1, -1, -1, -1, 1 };

  static const int8_T f_b[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T c[3]{ -1, 1, -1 };

  real_T Imat[72];
  real_T Itemp[72];
  real_T zeta[36];
  real_T rtb_ImpAsg_InsertedFor_Info_at_[32];
  real_T R[24];
  real_T d_b[24];
  real_T b_b[21];
  real_T rtb_MatrixConcatenation[18];
  real_T rtb_ImpAsg_InsertedFor_FsB_at_i[12];
  real_T rtb_ImpAsg_InsertedFor_MsB_at_i[12];
  real_T rtb_ImpAsg_InsertedFor_VehM_at_[12];
  real_T rtb_ImpAsg_InsertedFor_WhlAng_a[12];
  real_T rtb_VectorConcatenate8[12];
  real_T tmp_0[12];
  real_T rtb_Ibar[9];
  real_T rtb_Transpose[9];
  real_T rtb_Transpose1[9];
  real_T rtb_Transpose1_e[9];
  real_T rtb_Transpose1_k[9];
  real_T rtb_VectorConcatenate_ci[9];
  real_T rtb_MatrixConcatenate2[8];
  real_T rtb_MatrixConcatenate3[8];
  real_T rtb_Abs1_d[6];
  real_T rtb_Abs_k[6];
  real_T tmp[6];
  real_T Bykappa[4];
  real_T Eykappa[4];
  real_T FzUnSat[4];
  real_T Kyalpha[4];
  real_T Kygammao[4];
  real_T Mzphiinf[4];
  real_T R_omega[4];
  real_T SHy[4];
  real_T SHykappa[4];
  real_T Vsy[4];
  real_T b_x[4];
  real_T cosprimealpha[4];
  real_T d_y[4];
  real_T dc_data[4];
  real_T dfz[4];
  real_T epsilon_gamma[4];
  real_T lam_Cz[4];
  real_T lam_muy[4];
  real_T phi[4];
  real_T phi_t[4];
  real_T rtb_ImpAsg_InsertedFor_Fx_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Fy_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Fz_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Mx_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_My_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Mz_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_VehFz_at[4];
  real_T rtb_ImpAsg_InsertedFor_WhlFz_at[4];
  real_T rtb_ImpAsg_InsertedFor_xdotWhee[4];
  real_T rtb_ImpAsg_InsertedFor_ydotWhee[4];
  real_T rtb_ImpAsg_InsertedFor_zdotWhee[4];
  real_T rtb_My[4];
  real_T rtb_Product[4];
  real_T rtb_Saturation[4];
  real_T rtb_Saturation_data[4];
  real_T rtb_Saturation_data_0[4];
  real_T rtb_VectorConcatenate3[4];
  real_T rtb_sig_x[4];
  real_T rtb_sig_y[4];
  real_T tmpDrphiVar_data[4];
  real_T rtb_Divide2[3];
  real_T rtb_IntegratorSecondOrderLimite[3];
  real_T rtb_Product3_ju[3];
  real_T rtb_Product4_i[3];
  real_T rtb_Switch1_h[3];
  real_T rtb_VectorConcatenate_km[3];
  real_T rtb_VectorConcatenate_n[3];
  real_T rtb_sincos_o1[3];
  real_T rtb_ubvbwb[3];
  real_T rtb_UnaryMinus1_c[2];
  real_T Bykappa_tmp;
  real_T Dx_tmp;
  real_T Dx_tmp_0;
  real_T Fzo_prime_idx_0;
  real_T Fzo_prime_idx_1;
  real_T Fzo_prime_idx_2;
  real_T Fzo_prime_idx_3;
  real_T Kyalpha_tmp_tmp;
  real_T R_omega_0;
  real_T ab_idx_0;
  real_T dpi_idx_0;
  real_T dpi_idx_1;
  real_T dpi_idx_2;
  real_T dpi_idx_3;
  real_T lam_Cz_0;
  real_T lam_Cz_tmp;
  real_T lam_Cz_tmp_tmp;
  real_T lam_muy_prime_idx_0;
  real_T lam_muy_prime_idx_1;
  real_T lam_muy_prime_idx_3;
  real_T mu_y;
  real_T mu_y_idx_0;
  real_T mu_y_idx_1;
  real_T mu_y_idx_2;
  real_T mu_y_tmp;
  real_T mu_y_tmp_0;
  real_T mu_y_tmp_1;
  real_T mu_y_tmp_2;
  real_T rtb_BattPackVolt;
  real_T rtb_ChrgCurrLmt;
  real_T rtb_DischrgCurrLmt;
  real_T rtb_Divide_pl;
  real_T rtb_FrontBiasGain;
  real_T rtb_Gain1_g0;
  real_T rtb_Integrator1_p;
  real_T rtb_Product2_fq;
  real_T rtb_Product_py;
  real_T rtb_SOC_CC;
  real_T rtb_Saturation_0;
  real_T rtb_Saturation_tmp;
  real_T rtb_Saturation_tmp_0;
  real_T rtb_Saturation_tmp_1;
  real_T rtb_Smallangleapproximationford;
  real_T rtb_Sum1_m;
  real_T rtb_Sum3_h;
  real_T rtb_Sum4_g;
  real_T rtb_Switch_e1;
  real_T rtb_Switch_p_idx_0;
  real_T rtb_Switch_p_idx_1;
  real_T rtb_Switch_p_idx_2;
  real_T rtb_Switch_p_idx_3;
  real_T rtb_UnaryMinus2_idx_0;
  real_T rtb_UnitConversion_mr_idx_0;
  real_T rtb_UnitConversion_mr_idx_1;
  real_T rtb_UnitConversion_mr_idx_2;
  real_T rtb_UnitConversion_mr_idx_3;
  real_T rtb_min;
  real_T x_idx_0;
  real_T *lastU;
  int32_T bc_tmp_data[4];
  int32_T tmp_data[4];
  int32_T tmp_data_0[4];
  int32_T tmp_data_2[4];
  int32_T ec_size[2];
  int32_T Itemp_tmp;
  int32_T i;
  int32_T ibmat;
  int32_T iy;
  int32_T rtb_Saturation_size;
  real32_T rtb_CellTemperatures_i[96];
  real32_T rtb_RT[96];
  real32_T maxV;
  real32_T maxV_0;
  real32_T minV;
  real32_T minV_tmp;
  real32_T rtb_RT1;
  real32_T rtb_VoutChgr;
  int8_T c_b[21];
  int8_T bc_data[4];
  int8_T tmp_data_1[4];
  int8_T lb[2];
  boolean_T nomslipinds[4];
  boolean_T tempInds[4];
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T rtb_RelationalOperator;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* UnitDelay generated from: '<S25>/Unit Delay' */
    std::memcpy(&localB->CellVoltages[0], &localDW->UnitDelay_1_DSTATE[0], 96U *
                sizeof(real32_T));

    /* RateTransition: '<S25>/RT' */
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
      std::memcpy(&localDW->RT_Buffer[0], &localB->CellVoltages[0], 96U * sizeof
                  (real32_T));
    }
  }

  /* RateTransition: '<S25>/RT' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
    std::memcpy(&rtb_RT[0], &localDW->RT_Buffer[0], 96U * sizeof(real32_T));
  }

  /* RateTransition: '<S25>/RT2' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* MinMax: '<S32>/MinMax' */
    minV = localB->CellVoltages[0];
    for (iy = 0; iy < 95; iy++) {
      minV = std::fmin(minV, localB->CellVoltages[iy + 1]);
    }

    /* MinMax: '<S32>/MinMax' */
    localB->MinCellVolt = minV;

    /* MinMax: '<S32>/MinMax1' incorporates:
     *  UnitDelay generated from: '<S25>/Unit Delay'
     */
    minV = localDW->UnitDelay_4_DSTATE[0];

    /* MinMax: '<S32>/MinMax4' incorporates:
     *  UnitDelay generated from: '<S25>/Unit Delay'
     */
    maxV = localDW->UnitDelay_4_DSTATE[0];

    /* MinMax: '<S32>/MinMax2' */
    maxV_0 = localB->CellVoltages[0];
    for (iy = 0; iy < 95; iy++) {
      /* UnitDelay generated from: '<S25>/Unit Delay' incorporates:
       *  MinMax: '<S32>/MinMax1'
       *  MinMax: '<S32>/MinMax4'
       */
      minV_tmp = localDW->UnitDelay_4_DSTATE[iy + 1];

      /* MinMax: '<S32>/MinMax1' incorporates:
       *  UnitDelay generated from: '<S25>/Unit Delay'
       */
      minV = std::fmin(minV, minV_tmp);

      /* MinMax: '<S32>/MinMax4' */
      maxV = std::fmax(maxV, minV_tmp);

      /* MinMax: '<S32>/MinMax2' */
      maxV_0 = std::fmax(maxV_0, localB->CellVoltages[iy + 1]);
    }

    /* Gain: '<S34>/Np_Module' incorporates:
     *  Gain: '<S34>/MaxDchrgCurrLim'
     *  Lookup_n-D: '<S34>/HighTempDchrgCurrentLim'
     *  Lookup_n-D: '<S34>/LowTempDchrgCurrentLim'
     *  Lookup_n-D: '<S34>/MinCellVoltDchrgCurrentLim'
     *  MinMax: '<S32>/MinMax'
     *  MinMax: '<S32>/MinMax1'
     *  MinMax: '<S32>/MinMax4'
     *  MinMax: '<S34>/MinMax2'
     */
    localB->Np_Module = localP->MaxDchrgCurrLim_Gain * std::fmin(std::fmin
      (look1_iflf_binlcpw(localB->MinCellVolt,
                          localP->MinCellVoltDchrgCurrentLim_bp01,
                          localP->MinCellVoltDchrgCurrentLim_tabl, 2U),
       look1_iflf_binlcpw(minV, localP->LowTempDchrgCurrentLim_bp01Data,
                          localP->LowTempDchrgCurrentLim_tableDat, 6U)),
      look1_iflf_binlcpw(maxV, localP->HighTempDchrgCurrentLim_bp01Dat,
                         localP->HighTempDchrgCurrentLim_tableDa, 3U)) *
      static_cast<real32_T>(AdasPlantModel0_P->PlntBattModNumCellPar);

    /* MinMax: '<S32>/MinMax2' */
    localB->MaxCellVolt = maxV_0;

    /* Gain: '<S33>/Np_Module' incorporates:
     *  Gain: '<S33>/MaxChrgCurrLim'
     *  Lookup_n-D: '<S33>/HighTempChrgCurrentLim'
     *  Lookup_n-D: '<S33>/LowTempChrgCurrentLim'
     *  Lookup_n-D: '<S33>/MaxCellVoltChrgCurrentLim'
     *  MinMax: '<S32>/MinMax1'
     *  MinMax: '<S32>/MinMax2'
     *  MinMax: '<S32>/MinMax4'
     *  MinMax: '<S33>/MinMax2'
     */
    localB->ChargeCurrentLimit = localP->MaxChrgCurrLim_Gain * std::fmin(std::
      fmin(look1_iflf_binlcpw(localB->MaxCellVolt,
      localP->MaxCellVoltChrgCurrentLim_bp01D,
      localP->MaxCellVoltChrgCurrentLim_table, 3U), look1_iflf_binlcpw(minV,
      localP->LowTempChrgCurrentLim_bp01Data,
      localP->LowTempChrgCurrentLim_tableData, 6U)), look1_iflf_binlcpw(maxV,
      localP->HighTempChrgCurrentLim_bp01Data,
      localP->HighTempChrgCurrentLim_tableDat, 4U)) * static_cast<real32_T>
      (AdasPlantModel0_P->PlntBattModNumCellPar);

    /* UnitDelay generated from: '<S25>/Unit Delay' */
    localB->PackVoltage = localDW->UnitDelay_2_DSTATE;

    /* UnitDelay generated from: '<S25>/Unit Delay' */
    localB->VoutInvtr = localDW->UnitDelay_6_DSTATE;

    /* UnitDelay generated from: '<S25>/Unit Delay' */
    localB->PackCurrent = localDW->UnitDelay_3_DSTATE;

    /* Chart: '<S30>/State_Machine' incorporates:
     *  Constant: '<S25>/Constant'
     *  MinMax: '<S32>/MinMax1'
     *  MinMax: '<S32>/MinMax4'
     *  UnitDelay generated from: '<S25>/Unit Delay'
     */
    if (localDW->temporalCounter_i1 < 4095U) {
      localDW->temporalCounter_i1 = static_cast<uint16_T>
        (localDW->temporalCounter_i1 + 1U);
    }

    if (localDW->temporalCounter_i2 < 4095U) {
      localDW->temporalCounter_i2 = static_cast<uint16_T>
        (localDW->temporalCounter_i2 + 1U);
    }

    if (localDW->temporalCounter_i3 < 4095U) {
      localDW->temporalCounter_i3 = static_cast<uint16_T>
        (localDW->temporalCounter_i3 + 1U);
    }

    if (localDW->is_active_c2_AdasPlantModel0 == 0U) {
      localDW->is_active_c2_AdasPlantModel0 = 1U;
      localDW->is_MainStateMachine = AdasPlantModel0_IN_Standby;
      localB->BMSState = 0.0F;
      localDW->is_ChargerContactorState = AdasPlant_IN_OpenChgrContactors;
      localDW->ChrgCntctState = Contact::Init;
      localDW->is_OpenChgrContactors = AdasPlantM_IN_ClosePreChrgRly_l;
      localDW->temporalCounter_i2 = 0U;
      localDW->is_InverterContactorState = AdasPlan_IN_OpenInvtrContactors;
      localDW->InvtrCntctState = Contact::Init;
      localDW->is_OpenInvtrContactors = AdasPlantM_IN_ClosePreChrgRly_l;
      localDW->temporalCounter_i3 = 0U;
      localDW->MonitorCurrLimMode = MonitorCurrLimModeType::NoCurrLimFault;
      localDW->MonitorCellVoltageMode = MonitorCellVoltageModeType::
        NoCellVoltFault;
      minV = localB->CellVoltages[0];
      for (iy = 0; iy < 95; iy++) {
        minV += localB->CellVoltages[iy + 1];
      }

      localDW->Delta = std::abs(localB->PackVoltage - minV);
      localDW->FaultPresent = false;
      localDW->MonitorCellTempMode = MonitorCellTempModeType::NoCellTempFault;
    } else {
      AdasPlantModel_MainStateMachine(localB, localDW, localP);
      if (localDW->is_ChargerContactorState == AdasPlan_IN_CloseChgrContactors)
      {
        if ((localP->Constant_Value_c2 != 1.0F) || localDW->FaultPresent) {
          localDW->is_CloseChgrContactors = AdasPlantMod_IN_NO_ACTIVE_CHILD;
          localDW->is_ChargerContactorState = AdasPlant_IN_OpenChgrContactors;
          localDW->ChrgCntctState = Contact::Init;
          localDW->is_OpenChgrContactors = AdasPlantM_IN_ClosePreChrgRly_l;
          localDW->temporalCounter_i2 = 0U;
        } else {
          switch (localDW->is_CloseChgrContactors) {
           case AdasPlantModel_IN_CloseNegCntct:
            if (localDW->temporalCounter_i2 * 100 >=
                localP->State_Machine_contactorTime) {
              localDW->is_CloseChgrContactors = AdasPlantMod_IN_ClosePreChrgRly;
              localDW->temporalCounter_i2 = 0U;
            }
            break;

           case AdasPlantModel_IN_ClosePosCntct:
            if (localDW->temporalCounter_i2 * 100 >=
                localP->State_Machine_contactorTime) {
              localDW->is_CloseChgrContactors = AdasPlantMode_IN_OpenPreChrgRly;
              localDW->ChrgCntctState = Contact::Close;
            }
            break;

           case AdasPlantMod_IN_ClosePreChrgRly:
            if (localDW->UnitDelay_5_DSTATE / localB->PackVoltage >=
                localP->State_Machine_vRatio) {
              localDW->is_CloseChgrContactors = AdasPlantModel_IN_ClosePosCntct;
              localDW->temporalCounter_i2 = 0U;
            } else if (localDW->temporalCounter_i2 >=
                       localP->State_Machine_timeoutContactor * 10) {
              localDW->is_CloseChgrContactors = AdasPlantModel0_IN_PreChrgFlt;
            }
            break;

           case AdasPlantMode_IN_OpenPreChrgRly:
            localDW->ChrgCntctState = Contact::Close;
            break;

           default:
            /* case IN_PreChrgFlt: */
            break;
          }
        }

        /* case IN_OpenChgrContactors: */
      } else if ((localP->Constant_Value_c2 == 1.0F) &&
                 (localDW->InvtrCntctState == Contact::Open) &&
                 (!localDW->FaultPresent)) {
        localDW->is_OpenChgrContactors = AdasPlantMod_IN_NO_ACTIVE_CHILD;
        localDW->is_ChargerContactorState = AdasPlan_IN_CloseChgrContactors;
        localDW->ChrgCntctState = Contact::Init;
        localDW->is_CloseChgrContactors = AdasPlantModel_IN_CloseNegCntct;
        localDW->temporalCounter_i2 = 0U;
      } else {
        switch (localDW->is_OpenChgrContactors) {
         case AdasPlantM_IN_ClosePreChrgRly_l:
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = AdasPlantModel0_IN_OpenPosCntct;
            localDW->temporalCounter_i2 = 0U;
          }
          break;

         case AdasPlantModel0_IN_OpenNegCntct:
          localDW->ChrgCntctState = Contact::Open;
          break;

         case AdasPlantModel0_IN_OpenPosCntct:
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = AdasPlantMode_IN_OpenPreChrgRly;
            localDW->temporalCounter_i2 = 0U;
          }
          break;

         default:
          /* case IN_OpenPreChrgRly: */
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = AdasPlantModel0_IN_OpenNegCntct;
            localDW->ChrgCntctState = Contact::Open;
          }
          break;
        }
      }

      AdasPlan_InverterContactorState(localB, localDW, localP);
      switch (localDW->MonitorCurrLimMode) {
       case MonitorCurrLimModeType::NoCurrLimFault:
        if ((localB->PackCurrent < localB->Np_Module) || (localB->PackCurrent >
             localB->ChargeCurrentLimit)) {
          localDW->MonitorCurrLimMode = MonitorCurrLimModeType::Wait;
          localDW->temporalCounter_i1 = 0U;
        }
        break;

       case MonitorCurrLimModeType::OverCurrentFault:
        break;

       default:
        /* State Wait */
        if (localDW->temporalCounter_i1 >= localP->State_Machine_timeoutCurrent *
            10) {
          localDW->MonitorCurrLimMode = MonitorCurrLimModeType::OverCurrentFault;
          localDW->FaultPresent = true;
        } else if ((localB->PackCurrent >= localB->Np_Module) &&
                   (localB->PackCurrent <= localB->ChargeCurrentLimit)) {
          localDW->MonitorCurrLimMode = MonitorCurrLimModeType::NoCurrLimFault;
        }
        break;
      }

      switch (localDW->MonitorCellVoltageMode) {
       case MonitorCellVoltageModeType::NoCellVoltFault:
        if (localB->MaxCellVolt >= localP->State_Machine_OverCellVoltageLi) {
          localDW->MonitorCellVoltageMode = MonitorCellVoltageModeType::
            OverVoltageFault;
          localDW->FaultPresent = true;
        } else if (localDW->Delta >= static_cast<real32_T>
                   (localP->State_Machine_SnsrFltThld)) {
          localDW->MonitorCellVoltageMode = MonitorCellVoltageModeType::
            SensorFaut;
          localDW->FaultPresent = true;
        } else if (localB->MinCellVolt <=
                   localP->State_Machine_UnderCellVoltageL) {
          localDW->MonitorCellVoltageMode = MonitorCellVoltageModeType::
            UnderVoltageFault;
          localDW->FaultPresent = true;
        } else {
          maxV_0 = localB->CellVoltages[0];
          for (iy = 0; iy < 95; iy++) {
            maxV_0 += localB->CellVoltages[iy + 1];
          }

          localDW->Delta = std::abs(localB->PackVoltage - maxV_0);
        }
        break;

       case MonitorCellVoltageModeType::OverVoltageFault:
       case MonitorCellVoltageModeType::SensorFaut:
        break;

       default:
        /* State UnderVoltageFault */
        break;
      }

      switch (localDW->MonitorCellTempMode) {
       case MonitorCellTempModeType::HighTemperatureFault:
       case MonitorCellTempModeType::LowTemperatureFault:
        break;

       default:
        /* State NoCellTempFault */
        if (maxV >= localP->State_Machine_HighTempLimit) {
          localDW->MonitorCellTempMode = MonitorCellTempModeType::
            HighTemperatureFault;
          localDW->FaultPresent = true;
        } else if (minV <= localP->State_Machine_LowTempLimit) {
          localDW->MonitorCellTempMode = MonitorCellTempModeType::
            LowTemperatureFault;
          localDW->FaultPresent = true;
        }
        break;
      }
    }

    /* End of Chart: '<S30>/State_Machine' */

    /* RateTransition: '<S25>/RT1' */
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
      localDW->RT1_Buffer = localB->BMSState;
    }

    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
      localDW->RT2_Buffer = localB->MaxCellVolt;
    }
  }

  /* RateTransition: '<S25>/RT1' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
    rtb_RT1 = localDW->RT1_Buffer;
  }

  /* RateTransition: '<S25>/RT3' */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) &&
      (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0)) {
    localDW->RT3_Buffer = localB->MinCellVolt;
  }

  /* RateTransition: '<S25>/RT2' incorporates:
   *  RateTransition: '<S25>/RT3'
   */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S26>/Balancing' */
    if (localDW->temporalCounter_i1_i < 8191U) {
      localDW->temporalCounter_i1_i = static_cast<uint16_T>
        (localDW->temporalCounter_i1_i + 1U);
    }

    if (localDW->is_active_c1_AdasPlantModel0 == 0U) {
      localDW->is_active_c1_AdasPlantModel0 = 1U;
      localDW->flgBalCompl = true;
      localDW->is_c1_AdasPlantModel0 = AdasPlantModel0_IN_BalancingOFF;
      localDW->temporalCounter_i1_i = 0U;
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
    } else if (localDW->is_c1_AdasPlantModel0 == AdasPlantModel0_IN_BalancingOFF)
    {
      if (localP->Balancing_flgEnBalancing && (rtb_RT1 != 2.0F) &&
          (localDW->temporalCounter_i1_i * 5 >= localP->Balancing_BalOffWait) &&
          (localDW->DeltaCellVolt > localP->Balancing_TargetDeltaV)) {
        localDW->is_c1_AdasPlantModel0 = AdasPlantModel0_IN_BalancingON;
        localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
        localDW->is_BalancingON = AdasPlantModel0_IN_BalActive;
        localDW->flgBalCompl = true;
        iy = 0;
        exitg3 = false;
        while ((!exitg3) && (iy < 96)) {
          if (rtb_RT[iy] - localDW->RT3_Buffer > localP->Balancing_TargetDeltaV /
              2.0F) {
            localDW->flgBalCompl = false;
            exitg3 = true;
          } else {
            iy++;
          }
        }
      } else {
        localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
      }

      /* case IN_BalancingON: */
    } else if (rtb_RT1 == 2.0F) {
      localDW->is_BalancingON = AdasPlantMod_IN_NO_ACTIVE_CHILD;
      localDW->is_c1_AdasPlantModel0 = AdasPlantModel0_IN_BalancingOFF;
      localDW->temporalCounter_i1_i = 0U;
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
    } else {
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
      switch (localDW->is_BalancingON) {
       case AdasPlantModel0_IN_BalActive:
        if (localDW->flgBalCompl) {
          localDW->is_BalancingON = AdasPlantModel0_IN_BalNotActive;
          localDW->temporalCounter_i1_i = 0U;
        } else {
          localDW->flgBalCompl = true;
          iy = 0;
          exitg2 = false;
          while ((!exitg2) && (iy < 96)) {
            if (rtb_RT[iy] - localDW->RT3_Buffer >
                localP->Balancing_TargetDeltaV / 2.0F) {
              localDW->flgBalCompl = false;
              exitg2 = true;
            } else {
              iy++;
            }
          }
        }
        break;

       default:
        /* case IN_BalNotActive: */
        i = localDW->temporalCounter_i1_i * 5;
        if ((i >= localP->Balancing_BalNotActWait) && (localDW->DeltaCellVolt >
             localP->Balancing_TargetDeltaV)) {
          localDW->is_BalancingON = AdasPlantModel0_IN_BalActive;
          localDW->flgBalCompl = true;
          iy = 0;
          exitg1 = false;
          while ((!exitg1) && (iy < 96)) {
            if (rtb_RT[iy] - localDW->RT3_Buffer >
                localP->Balancing_TargetDeltaV / 2.0F) {
              localDW->flgBalCompl = false;
              exitg1 = true;
            } else {
              iy++;
            }
          }
        } else if (i >= localP->Balancing_BalOnWait) {
          localDW->is_BalancingON = AdasPlantMod_IN_NO_ACTIVE_CHILD;
          localDW->is_c1_AdasPlantModel0 = AdasPlantModel0_IN_BalancingOFF;
          localDW->temporalCounter_i1_i = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S26>/Balancing' */
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    localB->SOC_CC = localDW->DiscreteTimeIntegrator_DSTATE;

    /* Product: '<S37>/Divide' incorporates:
     *  Constant: '<S37>/Constant'
     *  Gain: '<S37>/Gain'
     */
    localB->Divide_cf = localP->Gain_Gain_em * localB->PackCurrent /
      static_cast<real32_T>(3.153 * AdasPlantModel0_P->PlntBattModNumCellPar);
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S630>/Product' incorporates:
     *  Constant: '<S630>/Constant1'
     *  Constant: '<S630>/Constant2'
     */
    localB->Product = AdasPlantModel0_P->PlntBattNumCellSer * 3.791 *
      AdasPlantModel0_P->PlntBattTimeCnst;
  }

  /* Integrator: '<S630>/Integrator' */
  if (localDW->Integrator_IWORK != 0) {
    localX->Integrator_CSTATE = localB->Product;
  }

  /* Gain: '<S630>/Gain1' incorporates:
   *  Integrator: '<S630>/Integrator'
   */
  localB->Gain1 = 1.0 / AdasPlantModel0_P->PlntBattTimeCnst *
    localX->Integrator_CSTATE;

  /* DataTypeConversion: '<S627>/Data Type Conversion1' */
  localB->PackVoltage_d = static_cast<real32_T>(localB->Gain1);

  /* RateTransition generated from: '<S627>/Rate Transition' incorporates:
   *  RateTransition: '<S21>/Rate Transition18'
   */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
      localDW->RateTransition_2_Buffer = localB->PackVoltage_d;
    }

    rtb_BattPackVolt = localDW->RateTransition18_Buffer
      [localDW->RateTransition18_ActiveBufIdx];
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S627>/Rate Transition' */
    localB->PackVoltage_i = localDW->RateTransition_2_Buffer;

    /* DataTypeConversion: '<S21>/Data Type Conversion1' */
    localB->DataTypeConversion1 = localB->PackVoltage_i;

    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    localB->DataTypeConversion = localB->SOC_CC;

    /* DataTypeConversion: '<S21>/Data Type Conversion2' */
    localB->DataTypeConversion2 = localB->Np_Module;

    /* DataTypeConversion: '<S21>/Data Type Conversion3' */
    localB->DataTypeConversion3 = localB->ChargeCurrentLimit;
  }

  /* RateTransition: '<S21>/Rate Transition19' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    rtb_SOC_CC = localDW->RateTransition19_Buffer
      [localDW->RateTransition19_ActiveBufIdx];

    /* RateTransition: '<S21>/Rate Transition20' */
    rtb_DischrgCurrLmt = localDW->RateTransition20_Buffer
      [localDW->RateTransition20_ActiveBufIdx];

    /* RateTransition: '<S21>/Rate Transition21' */
    rtb_ChrgCurrLmt = localDW->RateTransition21_Buffer
      [localDW->RateTransition21_ActiveBufIdx];

    /* DeadZone: '<S671>/Dead Zone1' */
    if (rtu_DriverBrakeCmd > localP->DeadZone1_End) {
      /* DeadZone: '<S671>/Dead Zone1' */
      localB->DeadZone1 = rtu_DriverBrakeCmd - localP->DeadZone1_End;
    } else if (rtu_DriverBrakeCmd >= localP->DeadZone1_Start) {
      /* DeadZone: '<S671>/Dead Zone1' */
      localB->DeadZone1 = 0.0;
    } else {
      /* DeadZone: '<S671>/Dead Zone1' */
      localB->DeadZone1 = rtu_DriverBrakeCmd - localP->DeadZone1_Start;
    }

    /* End of DeadZone: '<S671>/Dead Zone1' */

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S48>/Rear Bias'
     *  Gain: '<S48>/Gain4'
     *  Product: '<S48>/Product'
     */
    if (rtu_AdasEnable > localP->Switch_Threshold_h) {
      /* Saturate: '<S45>/Saturation' */
      if (rtu_AdasLongTrq > localP->Saturation_UpperSat) {
        rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat;
      } else if (rtu_AdasLongTrq < localP->Saturation_LowerSat) {
        rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat;
      } else {
        rtb_UnaryMinus2_idx_0 = rtu_AdasLongTrq;
      }

      /* Product: '<S45>/Divide' incorporates:
       *  Constant: '<S45>/Constant2'
       *  Gain: '<S45>/Gain'
       *  Saturate: '<S45>/Saturation'
       */
      rtb_Divide_pl = localP->Gain_Gain * rtb_UnaryMinus2_idx_0 /
        (AdasPlantModel0_P->PlntBrkKinFricCffFrnt * 3.1415926535897931 *
         0.0025000000000000005 * AdasPlantModel0_P->PlntBrkPadMeanRadiusFrnt *
         AdasPlantModel0_P->PlntBrkNumPadsFrnt / 4.0);

      /* Gain: '<S45>/FrontBiasGain' */
      rtb_FrontBiasGain = AdasPlantModel0_P->PlntBrkFrntBias * rtb_Divide_pl;

      /* Gain: '<S45>/RearBiasGain' */
      rtb_Divide_pl *= AdasPlantModel0_P->PlntBrkRearBias;
      rtb_Switch_p_idx_0 = rtb_FrontBiasGain;
      rtb_Switch_p_idx_1 = rtb_FrontBiasGain;
      rtb_Switch_p_idx_2 = rtb_Divide_pl;
      rtb_Switch_p_idx_3 = rtb_Divide_pl;
    } else {
      /* Gain: '<S48>/Gain4' incorporates:
       *  Constant: '<S48>/Front Bias'
       *  Product: '<S48>/Product'
       */
      rtb_Switch_p_idx_0 = AdasPlantModel0_P->PlntBrkFrntBias *
        localB->DeadZone1 * AdasPlantModel0_P->PlntBrkPrsFctr;
      rtb_Switch_p_idx_1 = rtb_Switch_p_idx_0;
      rtb_Switch_p_idx_2 = AdasPlantModel0_P->PlntBrkRearBias *
        localB->DeadZone1 * AdasPlantModel0_P->PlntBrkPrsFctr;
      rtb_Switch_p_idx_3 = AdasPlantModel0_P->PlntBrkRearBias *
        localB->DeadZone1 * AdasPlantModel0_P->PlntBrkPrsFctr;
    }

    /* End of Switch: '<S45>/Switch' */

    /* DeadZone: '<S95>/Dead Zone2' */
    if (rtu_DriverAccelCmd > localP->DeadZone2_End) {
      /* DeadZone: '<S95>/Dead Zone2' */
      localB->DeadZone2 = rtu_DriverAccelCmd - localP->DeadZone2_End;
    } else if (rtu_DriverAccelCmd >= localP->DeadZone2_Start) {
      /* DeadZone: '<S95>/Dead Zone2' */
      localB->DeadZone2 = 0.0;
    } else {
      /* DeadZone: '<S95>/Dead Zone2' */
      localB->DeadZone2 = rtu_DriverAccelCmd - localP->DeadZone2_Start;
    }

    /* End of DeadZone: '<S95>/Dead Zone2' */
  }

  /* End of RateTransition: '<S21>/Rate Transition19' */

  /* Integrator: '<S609>/Integrator' */
  localB->Spd = localX->Integrator_CSTATE_j;

  /* Switch: '<S3>/Switch' */
  if (rtu_AdasEnable > localP->Switch_Threshold_a) {
    /* Switch: '<S3>/Switch' */
    localB->GearCmd = rtu_AdasGearCmd;
  } else {
    /* Switch: '<S3>/Switch' */
    localB->GearCmd = rtu_DriverGearCmd;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Integrator: '<S406>/ub,vb,wb' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  rtb_ubvbwb[0] = localX->ubvbwb_CSTATE[0];

  /* UnitConversion: '<S416>/Unit Conversion' incorporates:
   *  Integrator: '<S406>/ub,vb,wb'
   */
  localB->UnitConversion[0] = localX->ubvbwb_CSTATE[0];

  /* Integrator: '<S406>/ub,vb,wb' */
  rtb_ubvbwb[1] = localX->ubvbwb_CSTATE[1];

  /* UnitConversion: '<S416>/Unit Conversion' incorporates:
   *  Integrator: '<S406>/ub,vb,wb'
   */
  localB->UnitConversion[1] = localX->ubvbwb_CSTATE[1];

  /* Integrator: '<S406>/ub,vb,wb' */
  rtb_ubvbwb[2] = localX->ubvbwb_CSTATE[2];

  /* UnitConversion: '<S416>/Unit Conversion' incorporates:
   *  Integrator: '<S406>/ub,vb,wb'
   */
  localB->UnitConversion[2] = localX->ubvbwb_CSTATE[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S55>/Constant'
     *  RelationalOperator: '<S54>/Compare'
     *  RelationalOperator: '<S55>/Compare'
     */
    if (rtu_AdasEnable > localP->Switch_Threshold_au) {
      rtb_RelationalOperator = (rtu_AdasLongTrq >
        localP->CompareToConstant_const);
    } else {
      rtb_RelationalOperator = (localB->DeadZone2 >
        localP->CompareToConstant1_const);
    }

    /* End of Switch: '<S49>/Switch' */

    /* Product: '<S69>/Product6' incorporates:
     *  Constant: '<S69>/Constant1'
     *  Constant: '<S69>/Constant2'
     *  Product: '<S69>/Product4'
     */
    rtb_UnitConversion_mr_idx_1 = AdasPlantModel0_P->PlntBrkKinFricCffFrnt *
      3.1415926535897931 * 0.0025000000000000005 *
      AdasPlantModel0_P->PlntBrkPadMeanRadiusFrnt *
      AdasPlantModel0_P->PlntBrkNumPadsFrnt / 4.0;

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S69>/Constant2'
     *  Product: '<S69>/Product5'
     *  Product: '<S69>/Product6'
     */
    rtb_Sum4_g = rtb_UnitConversion_mr_idx_1 * rtb_Switch_p_idx_0 +
      rtb_UnitConversion_mr_idx_1 * rtb_Switch_p_idx_1;

    /* Lookup_n-D: '<S69>/RegenBrakingCutoff' */
    rtb_Sum3_h = look1_binlcapw(localB->UnitConversion[0],
      AdasPlantModel0_P->CtrlVcuEvRegenBrkSpdBpt,
      AdasPlantModel0_P->CtrlVcuEvRegenBrkCutOff, 1U);

    /* Gain: '<S52>/convert2percent' */
    rtb_Product2_fq = localP->convert2percent_Gain * rtb_SOC_CC;

    /* Product: '<S69>/Product3' incorporates:
     *  Gain: '<S69>/MotTrqReflectedToWheels'
     *  Gain: '<S69>/rads_to_rpm'
     *  Lookup_n-D: '<S69>/ChrgLmt'
     *  Lookup_n-D: '<S69>/MaxMotTrqVsSpd'
     *  MinMax: '<S69>/MinMax'
     *  Product: '<S447>/Product2'
     *  Product: '<S69>/Product1'
     */
    rtb_min = std::fmin(rtb_Sum4_g, look1_binlcapw(localP->rads_to_rpm_Gain_h *
      localB->Spd, localP->MaxMotTrqVsSpd_bp01Data,
      AdasPlantModel0_P->PlntEM1Trq, 13U) * AdasPlantModel0_P->PlntDiffrntlRatio)
      * (rtb_Sum3_h * look1_binlcapw(rtb_Product2_fq,
          AdasPlantModel0_P->CtrlVcuEvSocBpt,
          AdasPlantModel0_P->CtrlVcuEvChrgLmtBpt, 10U));

    /* Switch: '<S49>/Accel Decel Switch' incorporates:
     *  Gain: '<S69>/Gain'
     *  Gain: '<S69>/WhlTrqReflectedToMot'
     *  Product: '<S44>/Product'
     */
    if (rtb_RelationalOperator) {
      /* Switch: '<S46>/Switch' incorporates:
       *  Gain: '<S47>/rads_to_rpm'
       *  Lookup_n-D: '<S47>/MaxEMTrqVsSpd'
       *  Product: '<S47>/Product1'
       */
      if (rtu_AdasEnable > localP->Switch_Threshold) {
        /* Saturate: '<S46>/Saturation' */
        if (rtu_AdasLongTrq > localP->Saturation_UpperSat_e) {
          rtb_SOC_CC = localP->Saturation_UpperSat_e;
        } else if (rtu_AdasLongTrq < localP->Saturation_LowerSat_l) {
          rtb_SOC_CC = localP->Saturation_LowerSat_l;
        } else {
          rtb_SOC_CC = rtu_AdasLongTrq;
        }

        /* End of Saturate: '<S46>/Saturation' */
      } else {
        rtb_SOC_CC = look1_binlcapw(localP->rads_to_rpm_Gain_c * localB->Spd,
          localP->MaxEMTrqVsSpd_bp01Data, AdasPlantModel0_P->PlntEM1Trq, 13U) *
          localB->DeadZone2;
      }

      /* End of Switch: '<S46>/Switch' */
      rtb_SOC_CC *= localB->GearCmd;
    } else {
      rtb_SOC_CC = 1.0 / AdasPlantModel0_P->PlntDiffrntlRatio * rtb_min *
        localP->Gain_Gain_i;
    }

    /* End of Switch: '<S49>/Accel Decel Switch' */

    /* Switch: '<S56>/Switch1' incorporates:
     *  Abs: '<S56>/Abs'
     *  Constant: '<S58>/Constant'
     *  RelationalOperator: '<S58>/Compare'
     */
    if (!(std::abs(localB->Spd) < localP->CompareToConstant_const_k)) {
      /* Product: '<S50>/Product' incorporates:
       *  Gain: '<S50>/Gain1'
       */
      rtb_DischrgCurrLmt = localP->Gain1_Gain * rtb_DischrgCurrLmt *
        rtb_BattPackVolt;

      /* Product: '<S59>/Product' incorporates:
       *  Product: '<S59>/Product3'
       */
      rtb_UnaryMinus2_idx_0 = localB->Spd * rtb_SOC_CC;

      /* Switch: '<S59>/Switch2' incorporates:
       *  Constant: '<S59>/Constant1'
       *  Constant: '<S59>/Constant2'
       *  Product: '<S59>/Product'
       */
      if (rtb_UnaryMinus2_idx_0 >= localP->Switch2_Threshold) {
        rtb_FrontBiasGain = localP->Constant1_Value;
      } else {
        rtb_FrontBiasGain = localP->Constant2_Value;
      }

      /* End of Switch: '<S59>/Switch2' */

      /* Gain: '<S59>/Gain1' incorporates:
       *  Abs: '<S59>/Abs'
       *  Abs: '<S59>/Abs1'
       *  Gain: '<S59>/rads_to_rpm'
       *  Lookup_n-D: '<S59>/Eff Map'
       */
      rtb_Divide_pl = look2_binlcapw(std::abs(localP->rads_to_rpm_Gain *
        localB->Spd), std::abs(rtb_SOC_CC), localP->EffMap_bp01Data,
        AdasPlantModel0_P->PlntEM1TrqEff, AdasPlantModel0_P->PlntEM1EffTbl,
        localP->EffMap_maxIndex, 14U) * localP->Gain1_Gain_d;

      /* Math: '<S59>/Math Function' */
      if ((rtb_Divide_pl < 0.0) && (rtb_FrontBiasGain > std::floor
           (rtb_FrontBiasGain))) {
        rtb_FrontBiasGain = -rt_powd_snf(-rtb_Divide_pl, rtb_FrontBiasGain);
      } else {
        rtb_FrontBiasGain = rt_powd_snf(rtb_Divide_pl, rtb_FrontBiasGain);
      }

      /* End of Math: '<S59>/Math Function' */

      /* Product: '<S59>/Product4' */
      rtb_Divide_pl = rtb_UnaryMinus2_idx_0 * rtb_FrontBiasGain;

      /* Product: '<S50>/Product1' incorporates:
       *  Gain: '<S50>/Gain'
       */
      rtb_BattPackVolt *= localP->Gain_Gain_h * rtb_ChrgCurrLmt;

      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S62>/Constant'
       *  Constant: '<S63>/Constant'
       *  Logic: '<S57>/Logical Operator'
       *  Product: '<S56>/ElecToMechPwr'
       *  Product: '<S56>/MechPwrToTrq'
       *  RelationalOperator: '<S62>/Compare'
       *  RelationalOperator: '<S63>/Compare'
       *  Sum: '<S57>/Subtract'
       *  Sum: '<S57>/Subtract1'
       */
      if ((!(rtb_DischrgCurrLmt - rtb_Divide_pl >= localP->Constant_Value_d)) ||
          (!(rtb_BattPackVolt - rtb_Divide_pl <= localP->Constant_Value_e))) {
        /* Switch: '<S61>/Switch' incorporates:
         *  Constant: '<S67>/Constant'
         *  Constant: '<S68>/Constant'
         *  Fcn: '<S61>/Fcn'
         *  Logic: '<S61>/Logical Operator'
         *  Product: '<S61>/Product'
         *  RelationalOperator: '<S67>/Compare'
         *  RelationalOperator: '<S68>/Compare'
         */
        if ((localB->Spd >= -localP->div0protectpoly_thresh) && (localB->Spd <=
             localP->div0protectpoly_thresh)) {
          /* Switch: '<S61>/Switch1' incorporates:
           *  Constant: '<S61>/Constant'
           *  UnaryMinus: '<S61>/Unary Minus'
           */
          if (localB->Spd >= localP->Switch1_Threshold) {
            rtb_ChrgCurrLmt = localP->Constant_Value_f;
          } else {
            rtb_ChrgCurrLmt = -localP->Constant_Value_f;
          }

          /* End of Switch: '<S61>/Switch1' */
          rtb_ChrgCurrLmt *= 4.0 / (3.0 - rt_powd_snf(localB->Spd / 2.0, 2.0));
        } else {
          rtb_ChrgCurrLmt = localB->Spd;
        }

        /* End of Switch: '<S61>/Switch' */

        /* Switch: '<S64>/Switch2' incorporates:
         *  RelationalOperator: '<S64>/LowerRelop1'
         */
        if (!(rtb_Divide_pl > rtb_DischrgCurrLmt)) {
          /* Switch: '<S64>/Switch' incorporates:
           *  RelationalOperator: '<S64>/UpperRelop'
           */
          if (rtb_Divide_pl < rtb_BattPackVolt) {
            rtb_DischrgCurrLmt = rtb_BattPackVolt;
          } else {
            rtb_DischrgCurrLmt = rtb_Divide_pl;
          }

          /* End of Switch: '<S64>/Switch' */
        }

        /* End of Switch: '<S64>/Switch2' */
        rtb_SOC_CC = rtb_DischrgCurrLmt / rtb_FrontBiasGain / rtb_ChrgCurrLmt;
      }

      /* End of Switch: '<S56>/Switch' */
    }

    /* End of Switch: '<S56>/Switch1' */

    /* Lookup_n-D: '<S60>/MaxEMTrqVsSpd' incorporates:
     *  Gain: '<S60>/rads_to_rpm'
     */
    rtb_BattPackVolt = look1_binlcapw(localP->rads_to_rpm_Gain_a * localB->Spd,
      localP->MaxEMTrqVsSpd_bp01Data_k, AdasPlantModel0_P->PlntEM1Trq, 13U);

    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  Constant: '<S65>/Constant'
     *  RelationalOperator: '<S65>/Compare'
     */
    if (rtb_Product2_fq > localP->CompareToConstant_const_ke) {
      rtb_Product2_fq = rtb_BattPackVolt;
    } else {
      rtb_Product2_fq = localP->Constant_Value;
    }

    /* End of Switch: '<S60>/Switch' */

    /* Switch: '<S66>/Switch2' incorporates:
     *  RelationalOperator: '<S66>/LowerRelop1'
     */
    if (rtb_SOC_CC > rtb_Product2_fq) {
      /* Switch: '<S66>/Switch2' */
      localB->Switch2 = rtb_Product2_fq;
    } else {
      /* Gain: '<S60>/Gain' */
      rtb_Product2_fq = localP->Gain_Gain_e * rtb_BattPackVolt;

      /* Switch: '<S66>/Switch' incorporates:
       *  RelationalOperator: '<S66>/UpperRelop'
       */
      if (rtb_SOC_CC < rtb_Product2_fq) {
        /* Switch: '<S66>/Switch2' */
        localB->Switch2 = rtb_Product2_fq;
      } else {
        /* Switch: '<S66>/Switch2' */
        localB->Switch2 = rtb_SOC_CC;
      }

      /* End of Switch: '<S66>/Switch' */
    }

    /* End of Switch: '<S66>/Switch2' */

    /* Sum: '<S69>/Subtract' */
    rtb_Sum4_g -= rtb_min;

    /* Saturate: '<S69>/Negative 5' */
    if (rtb_Sum4_g > localP->Negative5_UpperSat) {
      rtb_Sum4_g = localP->Negative5_UpperSat;
    } else if (rtb_Sum4_g < localP->Negative5_LowerSat) {
      rtb_Sum4_g = localP->Negative5_LowerSat;
    }

    /* End of Saturate: '<S69>/Negative 5' */

    /* Gain: '<S69>/Gain6' incorporates:
     *  Constant: '<S69>/Constant1'
     *  Product: '<S69>/Product4'
     */
    rtb_Product2_fq = rtb_Sum4_g / (rtb_UnitConversion_mr_idx_1 * 2.0) * (1.0 /
      AdasPlantModel0_P->PlntBrkPrsFctr);

    /* Saturate: '<S69>/Saturation' */
    if (rtb_Product2_fq > localP->Saturation_UpperSat_d) {
      rtb_Product2_fq = localP->Saturation_UpperSat_d;
    } else if (rtb_Product2_fq < localP->Saturation_LowerSat_m) {
      rtb_Product2_fq = localP->Saturation_LowerSat_m;
    }

    /* End of Saturate: '<S69>/Saturation' */

    /* SignalConversion generated from: '<S69>/Vector Concatenate' */
    rtb_UnitConversion_mr_idx_0 = rtb_Product2_fq;

    /* SignalConversion generated from: '<S69>/Vector Concatenate' */
    rtb_UnitConversion_mr_idx_1 = rtb_Product2_fq;

    /* Gain: '<S69>/Gain8' */
    rtb_Product_py = 1.0 / AdasPlantModel0_P->PlntBrkPrsFctr;

    /* SignalConversion generated from: '<S69>/Vector Concatenate' incorporates:
     *  Gain: '<S69>/Gain8'
     */
    rtb_UnitConversion_mr_idx_2 = rtb_Product_py * rtb_Switch_p_idx_2;

    /* SignalConversion generated from: '<S69>/Vector Concatenate' incorporates:
     *  Gain: '<S69>/Gain8'
     */
    rtb_UnitConversion_mr_idx_3 = rtb_Product_py * rtb_Switch_p_idx_3;

    /* Constant: '<S3>/Constant' */
    localB->IgnSwtch = localP->Constant_Value_b;

    /* Constant: '<S4>/Constant3' incorporates:
     *  Concatenate: '<S4>/Vector Concatenate'
     */
    localB->Wind[0] = AdasPlantModel0_P->EnvWindVelX;

    /* Constant: '<S4>/Constant4' incorporates:
     *  Concatenate: '<S4>/Vector Concatenate'
     */
    localB->Wind[1] = AdasPlantModel0_P->EnvWindVelY;

    /* Constant: '<S4>/Constant5' incorporates:
     *  Concatenate: '<S4>/Vector Concatenate'
     */
    localB->Wind[2] = AdasPlantModel0_P->EnvWindVelZ;

    /* Constant: '<S73>/Constant2' */
    std::memcpy(&localB->DCM[0], &localP->Constant2_Value_p[0], 36U * sizeof
                (real_T));

    /* SignalConversion generated from: '<S75>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate1'
     *  Constant: '<S73>/Constant1'
     */
    localB->VectorConcatenate1[0] = localP->Constant1_Value_k[0];

    /* SignalConversion generated from: '<S75>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate1'
     *  Constant: '<S73>/Constant1'
     */
    localB->VectorConcatenate1[1] = localP->Constant1_Value_k[1];

    /* SignalConversion generated from: '<S75>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate1'
     *  Constant: '<S73>/Constant1'
     */
    localB->VectorConcatenate1[2] = localP->Constant1_Value_k[2];

    /* SignalConversion generated from: '<S75>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate1'
     *  Constant: '<S73>/Constant1'
     */
    localB->VectorConcatenate1[3] = localP->Constant1_Value_k[3];

    /* SignalConversion generated from: '<S75>/Vector Concatenate' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate'
     *  Constant: '<S74>/Friction Scaling'
     */
    localB->VectorConcatenate[0] = AdasPlantModel0_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S75>/Vector Concatenate' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate'
     *  Constant: '<S74>/Friction Scaling'
     */
    localB->VectorConcatenate[1] = AdasPlantModel0_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S75>/Vector Concatenate' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate'
     *  Constant: '<S74>/Friction Scaling'
     */
    localB->VectorConcatenate[2] = AdasPlantModel0_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S75>/Vector Concatenate' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate'
     *  Constant: '<S74>/Friction Scaling'
     */
    localB->VectorConcatenate[3] = AdasPlantModel0_P->EnvNomFrictionScaling;
  }

  /* Switch: '<S3>/Switch1' */
  if (rtu_AdasEnable > localP->Switch1_Threshold_hp) {
    /* Switch: '<S3>/Switch1' */
    rtb_min = rtu_AdasSteerCmd;
  } else {
    /* Switch: '<S3>/Switch1' */
    rtb_min = rtu_DriverSteerCmd;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* FirstOrderHold: '<S79>/First Order Hold' */
  localB->EMTrqCmd = localDW->Ck;

  /* FirstOrderHold: '<S79>/First Order Hold' */
  if (localDW->Tk != (rtInf)) {
    /* FirstOrderHold: '<S79>/First Order Hold' */
    localB->EMTrqCmd += ((&AdasPlantModel0_M)->Timing.t[0] - localDW->Tk) *
      localDW->Mk;
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* DeadZone: '<S104>/Dead Zone' */
    if (rtb_UnitConversion_mr_idx_0 > localP->DeadZone_End) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[0] = rtb_UnitConversion_mr_idx_0 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_mr_idx_0 >= localP->DeadZone_Start) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[0] = 0.0;
    } else {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[0] = rtb_UnitConversion_mr_idx_0 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_mr_idx_1 > localP->DeadZone_End) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[1] = rtb_UnitConversion_mr_idx_1 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_mr_idx_1 >= localP->DeadZone_Start) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[1] = 0.0;
    } else {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[1] = rtb_UnitConversion_mr_idx_1 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_mr_idx_2 > localP->DeadZone_End) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[2] = rtb_UnitConversion_mr_idx_2 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_mr_idx_2 >= localP->DeadZone_Start) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[2] = 0.0;
    } else {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[2] = rtb_UnitConversion_mr_idx_2 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_mr_idx_3 > localP->DeadZone_End) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[3] = rtb_UnitConversion_mr_idx_3 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_mr_idx_3 >= localP->DeadZone_Start) {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[3] = 0.0;
    } else {
      /* DeadZone: '<S104>/Dead Zone' */
      localB->DeadZone[3] = rtb_UnitConversion_mr_idx_3 - localP->DeadZone_Start;
    }

    /* End of DeadZone: '<S104>/Dead Zone' */
  }

  /* Gain: '<S104>/Gain4' incorporates:
   *  Constant: '<S104>/Front Bias'
   *  Constant: '<S104>/Rear Bias'
   *  Integrator: '<S105>/Integrator1'
   *  Product: '<S104>/Product'
   */
  localB->Gain4[0] = AdasPlantModel0_P->PlntBrkFrntBias *
    localX->Integrator1_CSTATE[0] * AdasPlantModel0_P->PlntBrkPrsFctr;
  localB->Gain4[1] = AdasPlantModel0_P->PlntBrkFrntBias *
    localX->Integrator1_CSTATE[1] * AdasPlantModel0_P->PlntBrkPrsFctr;
  localB->Gain4[2] = AdasPlantModel0_P->PlntBrkRearBias *
    localX->Integrator1_CSTATE[2] * AdasPlantModel0_P->PlntBrkPrsFctr;
  localB->Gain4[3] = AdasPlantModel0_P->PlntBrkRearBias *
    localX->Integrator1_CSTATE[3] * AdasPlantModel0_P->PlntBrkPrsFctr;

  /* Product: '<S105>/Divide' incorporates:
   *  Constant: '<S105>/Constant'
   *  Integrator: '<S105>/Integrator1'
   *  Sum: '<S105>/Sum'
   */
  localB->Divide[0] = (localB->DeadZone[0] - localX->Integrator1_CSTATE[0]) *
    AdasPlantModel0_P->PlntBrkWc;

  /* Integrator: '<S516>/Integrator' */
  localB->Integrator[0] = localX->Integrator_CSTATE_f[0];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S516>/Integrator'
   */
  rtb_VectorConcatenate8[0] = localX->Integrator_CSTATE_f[0];

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator_i[0] = localX->Integrator_CSTATE_p[0];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[4] = localX->Integrator_CSTATE_p[0];

  /* Integrator: '<S373>/Integrator1' */
  rtb_UnitConversion_mr_idx_0 = localX->Integrator1_CSTATE_c[0];

  /* Saturate: '<S286>/Saturation' incorporates:
   *  Integrator: '<S373>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_c[0] > localP->Saturation_UpperSat_c) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[0] = localP->Saturation_UpperSat_c;
  } else if (localX->Integrator1_CSTATE_c[0] < localP->Saturation_LowerSat_n) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[0] = localP->Saturation_LowerSat_n;
  } else {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[0] = localX->Integrator1_CSTATE_c[0];
  }

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' */
  rtb_VectorConcatenate8[8] = localB->Saturation[0];

  /* Product: '<S105>/Divide' incorporates:
   *  Constant: '<S105>/Constant'
   *  Integrator: '<S105>/Integrator1'
   *  Sum: '<S105>/Sum'
   */
  localB->Divide[1] = (localB->DeadZone[1] - localX->Integrator1_CSTATE[1]) *
    AdasPlantModel0_P->PlntBrkWc;

  /* Integrator: '<S516>/Integrator' */
  localB->Integrator[1] = localX->Integrator_CSTATE_f[1];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S516>/Integrator'
   */
  rtb_VectorConcatenate8[1] = localX->Integrator_CSTATE_f[1];

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator_i[1] = localX->Integrator_CSTATE_p[1];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[5] = localX->Integrator_CSTATE_p[1];

  /* Integrator: '<S373>/Integrator1' */
  rtb_UnitConversion_mr_idx_1 = localX->Integrator1_CSTATE_c[1];

  /* Saturate: '<S286>/Saturation' incorporates:
   *  Integrator: '<S373>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_c[1] > localP->Saturation_UpperSat_c) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[1] = localP->Saturation_UpperSat_c;
  } else if (localX->Integrator1_CSTATE_c[1] < localP->Saturation_LowerSat_n) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[1] = localP->Saturation_LowerSat_n;
  } else {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[1] = localX->Integrator1_CSTATE_c[1];
  }

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' */
  rtb_VectorConcatenate8[9] = localB->Saturation[1];

  /* Product: '<S105>/Divide' incorporates:
   *  Constant: '<S105>/Constant'
   *  Integrator: '<S105>/Integrator1'
   *  Sum: '<S105>/Sum'
   */
  localB->Divide[2] = (localB->DeadZone[2] - localX->Integrator1_CSTATE[2]) *
    AdasPlantModel0_P->PlntBrkWc;

  /* Integrator: '<S516>/Integrator' */
  localB->Integrator[2] = localX->Integrator_CSTATE_f[2];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S516>/Integrator'
   */
  rtb_VectorConcatenate8[2] = localX->Integrator_CSTATE_f[2];

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator_i[2] = localX->Integrator_CSTATE_p[2];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[6] = localX->Integrator_CSTATE_p[2];

  /* Integrator: '<S373>/Integrator1' */
  rtb_UnitConversion_mr_idx_2 = localX->Integrator1_CSTATE_c[2];

  /* Saturate: '<S286>/Saturation' incorporates:
   *  Integrator: '<S373>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_c[2] > localP->Saturation_UpperSat_c) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[2] = localP->Saturation_UpperSat_c;
  } else if (localX->Integrator1_CSTATE_c[2] < localP->Saturation_LowerSat_n) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[2] = localP->Saturation_LowerSat_n;
  } else {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[2] = localX->Integrator1_CSTATE_c[2];
  }

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' */
  rtb_VectorConcatenate8[10] = localB->Saturation[2];

  /* Product: '<S105>/Divide' incorporates:
   *  Constant: '<S105>/Constant'
   *  Integrator: '<S105>/Integrator1'
   *  Sum: '<S105>/Sum'
   */
  localB->Divide[3] = (localB->DeadZone[3] - localX->Integrator1_CSTATE[3]) *
    AdasPlantModel0_P->PlntBrkWc;

  /* Integrator: '<S516>/Integrator' */
  localB->Integrator[3] = localX->Integrator_CSTATE_f[3];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S516>/Integrator'
   */
  rtb_VectorConcatenate8[3] = localX->Integrator_CSTATE_f[3];

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator_i[3] = localX->Integrator_CSTATE_p[3];

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[7] = localX->Integrator_CSTATE_p[3];

  /* Integrator: '<S373>/Integrator1' */
  rtb_UnitConversion_mr_idx_3 = localX->Integrator1_CSTATE_c[3];

  /* Saturate: '<S286>/Saturation' incorporates:
   *  Integrator: '<S373>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_c[3] > localP->Saturation_UpperSat_c) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[3] = localP->Saturation_UpperSat_c;
  } else if (localX->Integrator1_CSTATE_c[3] < localP->Saturation_LowerSat_n) {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[3] = localP->Saturation_LowerSat_n;
  } else {
    /* Saturate: '<S286>/Saturation' */
    localB->Saturation[3] = localX->Integrator1_CSTATE_c[3];
  }

  /* SignalConversion generated from: '<S287>/Vector Concatenate8' */
  rtb_VectorConcatenate8[11] = localB->Saturation[3];
  for (i = 0; i < 4; i++) {
    /* Math: '<S287>/Math Function' incorporates:
     *  Concatenate: '<S287>/Vector Concatenate8'
     */
    localB->MathFunction[3 * i] = rtb_VectorConcatenate8[i];
    localB->MathFunction[3 * i + 1] = rtb_VectorConcatenate8[i + 4];
    localB->MathFunction[3 * i + 2] = rtb_VectorConcatenate8[i + 8];
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S579>/Memory' */
    localB->Memory = localDW->Memory_PreviousInput;

    /* Constant: '<S578>/domega_o' */
    localB->domega_o = AdasPlantModel0_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S579>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE,
                       (localB->Memory));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_a != 0)) {
      localX->Integrator_CSTATE_i = localB->domega_o;
    }
  }

  rtb_BattPackVolt = localX->Integrator_CSTATE_i;

  /* Sum: '<S578>/Subtract1' incorporates:
   *  Gain: '<S578>/Gain1'
   *  Gain: '<S578>/Gain2'
   *  Integrator: '<S578>/Integrator'
   *  Integrator: '<S579>/Integrator'
   */
  rtb_ChrgCurrLmt = AdasPlantModel0_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_i + AdasPlantModel0_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_m;

  /* SignalConversion generated from: '<S540>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S540>/Vector Concatenate1'
   */
  localB->VectorConcatenate1_h[0] = rtb_ChrgCurrLmt;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S587>/Memory' */
    localB->Memory_a = localDW->Memory_PreviousInput_g;

    /* Constant: '<S586>/domega_o' */
    localB->domega_o_o = AdasPlantModel0_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S587>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE_i,
                       (localB->Memory_a));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_c != 0)) {
      localX->Integrator_CSTATE_fd = localB->domega_o_o;
    }
  }

  rtb_SOC_CC = localX->Integrator_CSTATE_fd;

  /* Sum: '<S586>/Subtract1' incorporates:
   *  Gain: '<S586>/Gain1'
   *  Gain: '<S586>/Gain2'
   *  Integrator: '<S586>/Integrator'
   *  Integrator: '<S587>/Integrator'
   */
  rtb_DischrgCurrLmt = AdasPlantModel0_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_fd + AdasPlantModel0_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_jc;

  /* SignalConversion generated from: '<S540>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S540>/Vector Concatenate1'
   */
  localB->VectorConcatenate1_h[1] = rtb_DischrgCurrLmt;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S595>/Constant1' incorporates:
     *  Concatenate: '<S540>/Vector Concatenate1'
     */
    localB->VectorConcatenate1_h[2] = localP->Constant1_Value_ky;

    /* Constant: '<S595>/Constant3' incorporates:
     *  Concatenate: '<S540>/Vector Concatenate1'
     */
    localB->VectorConcatenate1_h[3] = localP->Constant3_Value;
  }

  /* Integrator: '<S519>/Integrator' */
  localB->Integrator_e[0] = localX->Integrator_CSTATE_m1[0];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o1[0] = localX->IntegratorSecondOrder_CSTATE[0];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o2[0] = localX->IntegratorSecondOrder_CSTATE[4];

  /* Sum: '<S520>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S520>/Integrator, Second-Order'
   */
  rtb_Switch_p_idx_3 = localB->VectorConcatenate1[0] -
    localX->IntegratorSecondOrder_CSTATE[0];
  rtb_Switch_p_idx_0 = rtb_Switch_p_idx_3;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Switch_p_idx_3 > localP->Saturation_UpperSat_g) {
    rtb_Saturation_0 = localP->Saturation_UpperSat_g;
  } else if (rtb_Switch_p_idx_3 < localP->Saturation_LowerSat_mx) {
    rtb_Saturation_0 = localP->Saturation_LowerSat_mx;
  } else {
    rtb_Saturation_0 = rtb_Switch_p_idx_3;
  }

  rtb_Saturation[0] = rtb_Saturation_0;

  /* Sum: '<S515>/Add2' incorporates:
   *  Constant: '<S515>/Constant9'
   */
  rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlUnldRadius -
    rtb_Saturation_0;

  /* Saturate: '<S515>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_n) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_n;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_k;
  }

  /* Sum: '<S515>/Add1' incorporates:
   *  Product: '<S515>/Product3'
   *  Saturate: '<S515>/Saturation'
   */
  localB->Add1[0] = (localB->Integrator[0] * rtb_UnaryMinus2_idx_0 -
                     localB->VectorConcatenate1_h[0]) - localB->Integrator_e[0];

  /* Integrator: '<S519>/Integrator' */
  localB->Integrator_e[1] = localX->Integrator_CSTATE_m1[1];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o1[1] = localX->IntegratorSecondOrder_CSTATE[1];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o2[1] = localX->IntegratorSecondOrder_CSTATE[5];

  /* Sum: '<S520>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S520>/Integrator, Second-Order'
   */
  rtb_Switch_p_idx_3 = localB->VectorConcatenate1[1] -
    localX->IntegratorSecondOrder_CSTATE[1];
  rtb_Switch_p_idx_1 = rtb_Switch_p_idx_3;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Switch_p_idx_3 > localP->Saturation_UpperSat_g) {
    rtb_Saturation_0 = localP->Saturation_UpperSat_g;
  } else if (rtb_Switch_p_idx_3 < localP->Saturation_LowerSat_mx) {
    rtb_Saturation_0 = localP->Saturation_LowerSat_mx;
  } else {
    rtb_Saturation_0 = rtb_Switch_p_idx_3;
  }

  rtb_Saturation[1] = rtb_Saturation_0;

  /* Sum: '<S515>/Add2' incorporates:
   *  Constant: '<S515>/Constant9'
   */
  rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlUnldRadius -
    rtb_Saturation_0;

  /* Saturate: '<S515>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_n) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_n;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_k;
  }

  /* Sum: '<S515>/Add1' incorporates:
   *  Product: '<S515>/Product3'
   *  Saturate: '<S515>/Saturation'
   */
  localB->Add1[1] = (localB->Integrator[1] * rtb_UnaryMinus2_idx_0 -
                     localB->VectorConcatenate1_h[1]) - localB->Integrator_e[1];

  /* Integrator: '<S519>/Integrator' */
  localB->Integrator_e[2] = localX->Integrator_CSTATE_m1[2];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o1[2] = localX->IntegratorSecondOrder_CSTATE[2];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o2[2] = localX->IntegratorSecondOrder_CSTATE[6];

  /* Sum: '<S520>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S520>/Integrator, Second-Order'
   */
  rtb_Switch_p_idx_3 = localB->VectorConcatenate1[2] -
    localX->IntegratorSecondOrder_CSTATE[2];
  rtb_Switch_p_idx_2 = rtb_Switch_p_idx_3;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Switch_p_idx_3 > localP->Saturation_UpperSat_g) {
    rtb_Saturation_0 = localP->Saturation_UpperSat_g;
  } else if (rtb_Switch_p_idx_3 < localP->Saturation_LowerSat_mx) {
    rtb_Saturation_0 = localP->Saturation_LowerSat_mx;
  } else {
    rtb_Saturation_0 = rtb_Switch_p_idx_3;
  }

  rtb_Saturation[2] = rtb_Saturation_0;

  /* Sum: '<S515>/Add2' incorporates:
   *  Constant: '<S515>/Constant9'
   */
  rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlUnldRadius -
    rtb_Saturation_0;

  /* Saturate: '<S515>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_n) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_n;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_k;
  }

  /* Sum: '<S515>/Add1' incorporates:
   *  Product: '<S515>/Product3'
   *  Saturate: '<S515>/Saturation'
   */
  localB->Add1[2] = (localB->Integrator[2] * rtb_UnaryMinus2_idx_0 -
                     localB->VectorConcatenate1_h[2]) - localB->Integrator_e[2];

  /* Integrator: '<S519>/Integrator' */
  localB->Integrator_e[3] = localX->Integrator_CSTATE_m1[3];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o1[3] = localX->IntegratorSecondOrder_CSTATE[3];

  /* SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  localB->IntegratorSecondOrder_o2[3] = localX->IntegratorSecondOrder_CSTATE[7];

  /* Sum: '<S520>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S520>/Integrator, Second-Order'
   */
  rtb_Switch_p_idx_3 = localB->VectorConcatenate1[3] -
    localX->IntegratorSecondOrder_CSTATE[3];

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Switch_p_idx_3 > localP->Saturation_UpperSat_g) {
    rtb_Saturation_0 = localP->Saturation_UpperSat_g;
  } else if (rtb_Switch_p_idx_3 < localP->Saturation_LowerSat_mx) {
    rtb_Saturation_0 = localP->Saturation_LowerSat_mx;
  } else {
    rtb_Saturation_0 = rtb_Switch_p_idx_3;
  }

  rtb_Saturation[3] = rtb_Saturation_0;

  /* Sum: '<S515>/Add2' incorporates:
   *  Constant: '<S515>/Constant9'
   */
  rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlUnldRadius -
    rtb_Saturation_0;

  /* Saturate: '<S515>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_n) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_n;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_k;
  }

  /* Sum: '<S515>/Add1' incorporates:
   *  Product: '<S515>/Product3'
   *  Saturate: '<S515>/Saturation'
   */
  localB->Add1[3] = (localB->Integrator[3] * rtb_UnaryMinus2_idx_0 -
                     localB->VectorConcatenate1_h[3]) - localB->Integrator_e[3];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S525>/Torque Conversion1' incorporates:
     *  Constant: '<S525>/Disk brake actuator bore'
     */
    localB->TorqueConversion1[0] = localP->TorqueConversion1_Gain *
      localP->CombinedSlipWheel2DOF_disk_abor[0];
    localB->TorqueConversion1[1] = localP->TorqueConversion1_Gain *
      localP->CombinedSlipWheel2DOF_disk_abor[1];
    localB->TorqueConversion1[2] = localP->TorqueConversion1_Gain *
      localP->CombinedSlipWheel2DOF_disk_abor[2];
    localB->TorqueConversion1[3] = localP->TorqueConversion1_Gain *
      localP->CombinedSlipWheel2DOF_disk_abor[3];
  }

  /* Product: '<S525>/product' incorporates:
   *  Constant: '<S525>/Disk brake actuator bore'
   *  Constant: '<S525>/Number of brake pads'
   */
  rtb_UnaryMinus2_idx_0 = localB->Gain4[0] * localB->TorqueConversion1[0] *
    localP->CombinedSlipWheel2DOF_disk_abor[0] *
    localP->CombinedSlipWheel2DOF_num_pads[0];

  /* Saturate: '<S525>/Disallow Negative Brake Torque' */
  if (rtb_UnaryMinus2_idx_0 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_UnaryMinus2_idx_0 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S525>/Torque Conversion' incorporates:
   *  Saturate: '<S525>/Disallow Negative Brake Torque'
   */
  localB->TorqueConversion[0] = localP->CombinedSlipWheel2DOF_Rm[0] *
    localP->CombinedSlipWheel2DOF_mu_kineti[0] * rtb_UnaryMinus2_idx_0;

  /* Gain: '<S523>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[0] = localP->CombinedSlipWheel2DOF_mu_static[0]
    / localP->CombinedSlipWheel2DOF_mu_kineti[0] * localB->TorqueConversion[0];

  /* Gain: '<S523>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S523>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[0] = localP->CombinedSlipWheel2DOF_mu_kineti[0]
    / localP->CombinedSlipWheel2DOF_mu_kineti[0] * localB->TorqueConversion[0];

  /* Product: '<S525>/product' incorporates:
   *  Constant: '<S525>/Disk brake actuator bore'
   *  Constant: '<S525>/Number of brake pads'
   */
  rtb_UnaryMinus2_idx_0 = localB->Gain4[1] * localB->TorqueConversion1[1] *
    localP->CombinedSlipWheel2DOF_disk_abor[1] *
    localP->CombinedSlipWheel2DOF_num_pads[1];

  /* Saturate: '<S525>/Disallow Negative Brake Torque' */
  if (rtb_UnaryMinus2_idx_0 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_UnaryMinus2_idx_0 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S525>/Torque Conversion' incorporates:
   *  Saturate: '<S525>/Disallow Negative Brake Torque'
   */
  localB->TorqueConversion[1] = localP->CombinedSlipWheel2DOF_Rm[1] *
    localP->CombinedSlipWheel2DOF_mu_kineti[1] * rtb_UnaryMinus2_idx_0;

  /* Gain: '<S523>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[1] = localP->CombinedSlipWheel2DOF_mu_static[1]
    / localP->CombinedSlipWheel2DOF_mu_kineti[1] * localB->TorqueConversion[1];

  /* Gain: '<S523>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S523>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[1] = localP->CombinedSlipWheel2DOF_mu_kineti[1]
    / localP->CombinedSlipWheel2DOF_mu_kineti[1] * localB->TorqueConversion[1];

  /* Product: '<S525>/product' incorporates:
   *  Constant: '<S525>/Disk brake actuator bore'
   *  Constant: '<S525>/Number of brake pads'
   */
  rtb_UnaryMinus2_idx_0 = localB->Gain4[2] * localB->TorqueConversion1[2] *
    localP->CombinedSlipWheel2DOF_disk_abor[2] *
    localP->CombinedSlipWheel2DOF_num_pads[2];

  /* Saturate: '<S525>/Disallow Negative Brake Torque' */
  if (rtb_UnaryMinus2_idx_0 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_UnaryMinus2_idx_0 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S525>/Torque Conversion' incorporates:
   *  Saturate: '<S525>/Disallow Negative Brake Torque'
   */
  localB->TorqueConversion[2] = localP->CombinedSlipWheel2DOF_Rm[2] *
    localP->CombinedSlipWheel2DOF_mu_kineti[2] * rtb_UnaryMinus2_idx_0;

  /* Gain: '<S523>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[2] = localP->CombinedSlipWheel2DOF_mu_static[2]
    / localP->CombinedSlipWheel2DOF_mu_kineti[2] * localB->TorqueConversion[2];

  /* Gain: '<S523>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S523>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[2] = localP->CombinedSlipWheel2DOF_mu_kineti[2]
    / localP->CombinedSlipWheel2DOF_mu_kineti[2] * localB->TorqueConversion[2];

  /* Product: '<S525>/product' incorporates:
   *  Constant: '<S525>/Disk brake actuator bore'
   *  Constant: '<S525>/Number of brake pads'
   */
  rtb_UnaryMinus2_idx_0 = localB->Gain4[3] * localB->TorqueConversion1[3] *
    localP->CombinedSlipWheel2DOF_disk_abor[3] *
    localP->CombinedSlipWheel2DOF_num_pads[3];

  /* Saturate: '<S525>/Disallow Negative Brake Torque' */
  if (rtb_UnaryMinus2_idx_0 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_UnaryMinus2_idx_0 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_UnaryMinus2_idx_0 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S525>/Torque Conversion' incorporates:
   *  Saturate: '<S525>/Disallow Negative Brake Torque'
   */
  localB->TorqueConversion[3] = localP->CombinedSlipWheel2DOF_Rm[3] *
    localP->CombinedSlipWheel2DOF_mu_kineti[3] * rtb_UnaryMinus2_idx_0;

  /* Gain: '<S523>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[3] = localP->CombinedSlipWheel2DOF_mu_static[3]
    / localP->CombinedSlipWheel2DOF_mu_kineti[3] * localB->TorqueConversion[3];

  /* Gain: '<S523>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S523>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[3] = localP->CombinedSlipWheel2DOF_mu_kineti[3]
    / localP->CombinedSlipWheel2DOF_mu_kineti[3] * localB->TorqueConversion[3];

  /* Outputs for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' incorporates:
   *  ForEach: '<S526>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* Chart: '<S526>/Clutch' incorporates:
     *  ForEachSliceSelector generated from: '<S526>/Tfmaxk'
     *  ForEachSliceSelector generated from: '<S526>/Tfmaxs'
     *  ForEachSliceSelector generated from: '<S526>/Tout'
     */
    if (ForEach_itr > 2147483646) {
      i = MAX_int32_T;
    } else {
      i = ForEach_itr + 1;
    }

    if (ForEach_itr > 2147483646) {
      iy = MAX_int32_T;
    } else {
      iy = ForEach_itr + 1;
    }

    if (ForEach_itr > 2147483646) {
      ibmat = MAX_int32_T;
    } else {
      ibmat = ForEach_itr + 1;
    }

    /* Outputs for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
    AdasPlantModel0_Clutch(localB->Add1[ForEach_itr],
      localB->Ratioofstatictokinetic[ForEach_itr],
      localB->Ratioofstatictokinetic1[ForEach_itr],
      localP->ClutchPartitionedParameters_ome[i - 1],
      localP->ClutchPartitionedParameters_br[iy - 1],
      localP->ClutchPartitionedParameters_Iyy[ibmat - 1],
      localP->CoreSubsys_k.Clutch_OmegaTol, &localB->CoreSubsys_k[ForEach_itr].
      sf_Clutch, &localDW->CoreSubsys_k[ForEach_itr].sf_Clutch,
      &localP->CoreSubsys_k.sf_Clutch, &localX->CoreSubsys_k[ForEach_itr].
      sf_Clutch);

    /* End of Chart: '<S526>/Clutch' */
    /* End of Outputs for SubSystem: '<S522>/Clutch Partitioned Parameters' */

    /* ForEachSliceAssignment generated from: '<S526>/Omega' */
    rty_VehFdbk_c[ForEach_itr] = localB->CoreSubsys_k[ForEach_itr].
      sf_Clutch.Omega;
  }

  /* End of Outputs for SubSystem: '<S522>/Clutch Partitioned Parameters' */

  /* Integrator: '<S406>/p,q,r ' */
  localB->pqr[0] = localX->pqr_CSTATE[0];
  localB->pqr[1] = localX->pqr_CSTATE[1];
  localB->pqr[2] = localX->pqr_CSTATE[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<S391>/vehdyncginert' */
    rtb_VectorConcatenate_n[0] = AdasPlantModel0_P->PlntVehDstCGFrntAxl;
    rtb_VectorConcatenate_n[1] = -localP->VehicleBody6DOF_d;
    rtb_VectorConcatenate_n[2] = AdasPlantModel0_P->PlntVehCGHgtAxl;
    for (iy = 0; iy < 3; iy++) {
      ibmat = iy * 7;
      for (i = 0; i < 7; i++) {
        b_b[ibmat + i] = rtb_VectorConcatenate_n[iy];
      }
    }

    for (iy = 0; iy < 3; iy++) {
      ibmat = iy * 7;
      for (i = 0; i < 7; i++) {
        c_b[ibmat + i] = c[iy];
      }

      R[iy << 3] = 0.0;
    }

    R[1] = localP->VehicleBody6DOF_z1R[0] * static_cast<real_T>(c_b[0]) + b_b[0];
    R[2] = localP->VehicleBody6DOF_z2R[0] * static_cast<real_T>(c_b[1]) + b_b[1];
    R[3] = localP->VehicleBody6DOF_z3R[0] * static_cast<real_T>(c_b[2]) + b_b[2];
    R[4] = localP->VehicleBody6DOF_z4R[0] * static_cast<real_T>(c_b[3]) + b_b[3];
    R[5] = localP->VehicleBody6DOF_z5R[0] * static_cast<real_T>(c_b[4]) + b_b[4];
    R[6] = localP->VehicleBody6DOF_z6R[0] * static_cast<real_T>(c_b[5]) + b_b[5];
    R[7] = localP->VehicleBody6DOF_z7R[0] * static_cast<real_T>(c_b[6]) + b_b[6];
    R[9] = localP->VehicleBody6DOF_z1R[1] * static_cast<real_T>(c_b[7]) + b_b[7];
    R[10] = localP->VehicleBody6DOF_z2R[1] * static_cast<real_T>(c_b[8]) + b_b[8];
    R[11] = localP->VehicleBody6DOF_z3R[1] * static_cast<real_T>(c_b[9]) + b_b[9];
    R[12] = localP->VehicleBody6DOF_z4R[1] * static_cast<real_T>(c_b[10]) + b_b
      [10];
    R[13] = localP->VehicleBody6DOF_z5R[1] * static_cast<real_T>(c_b[11]) + b_b
      [11];
    R[14] = localP->VehicleBody6DOF_z6R[1] * static_cast<real_T>(c_b[12]) + b_b
      [12];
    R[15] = localP->VehicleBody6DOF_z7R[1] * static_cast<real_T>(c_b[13]) + b_b
      [13];
    R[17] = localP->VehicleBody6DOF_z1R[2] * static_cast<real_T>(c_b[14]) + b_b
      [14];
    R[18] = localP->VehicleBody6DOF_z2R[2] * static_cast<real_T>(c_b[15]) + b_b
      [15];
    R[19] = localP->VehicleBody6DOF_z3R[2] * static_cast<real_T>(c_b[16]) + b_b
      [16];
    R[20] = localP->VehicleBody6DOF_z4R[2] * static_cast<real_T>(c_b[17]) + b_b
      [17];
    R[21] = localP->VehicleBody6DOF_z5R[2] * static_cast<real_T>(c_b[18]) + b_b
      [18];
    R[22] = localP->VehicleBody6DOF_z6R[2] * static_cast<real_T>(c_b[19]) + b_b
      [19];
    R[23] = localP->VehicleBody6DOF_z7R[2] * static_cast<real_T>(c_b[20]) + b_b
      [20];
    rtb_MatrixConcatenate2[0] = AdasPlantModel0_P->PlntVehMass;
    rtb_MatrixConcatenate2[1] = localP->VehicleBody6DOF_z1m;
    rtb_MatrixConcatenate2[2] = localP->VehicleBody6DOF_z2m;
    rtb_MatrixConcatenate2[3] = localP->VehicleBody6DOF_z3m;
    rtb_MatrixConcatenate2[4] = localP->VehicleBody6DOF_z4m;
    rtb_MatrixConcatenate2[5] = localP->VehicleBody6DOF_z5m;
    rtb_MatrixConcatenate2[6] = localP->VehicleBody6DOF_z6m;
    rtb_MatrixConcatenate2[7] = localP->VehicleBody6DOF_z7m;
    for (i = 0; i < 9; i++) {
      Imat[i] = localP->VehicleBody6DOF_Iveh[i];
      Imat[i + 9] = localP->VehicleBody6DOF_z1I[i];
      Imat[i + 18] = localP->VehicleBody6DOF_z2I[i];
      Imat[i + 27] = localP->VehicleBody6DOF_z3I[i];
      Imat[i + 36] = localP->VehicleBody6DOF_z4I[i];
      Imat[i + 45] = localP->VehicleBody6DOF_z5I[i];
      Imat[i + 54] = localP->VehicleBody6DOF_z6I[i];
      Imat[i + 63] = localP->VehicleBody6DOF_z7I[i];
    }

    for (i = 0; i < 3; i++) {
      std::memcpy(&d_b[i << 3], &rtb_MatrixConcatenate2[0], sizeof(real_T) << 3U);
    }

    rtb_FrontBiasGain = AdasPlantModel0_P->PlntVehMass;
    for (iy = 0; iy < 7; iy++) {
      rtb_FrontBiasGain += rtb_MatrixConcatenate2[iy + 1];
    }

    for (i = 0; i < 24; i++) {
      d_b[i] = d_b[i] * R[i] / rtb_FrontBiasGain;
    }

    for (i = 0; i < 3; i++) {
      ibmat = i << 3;
      dpi_idx_0 = d_b[ibmat];
      for (iy = 0; iy < 7; iy++) {
        dpi_idx_0 += d_b[(ibmat + iy) + 1];
      }

      localB->Rbar[i] = dpi_idx_0;
    }

    rtb_FrontBiasGain = AdasPlantModel0_P->PlntVehMass;
    for (iy = 0; iy < 7; iy++) {
      rtb_FrontBiasGain += rtb_MatrixConcatenate2[iy + 1];
    }

    for (iy = 0; iy < 3; iy++) {
      ibmat = iy << 3;
      for (i = 0; i < 8; i++) {
        d_b[ibmat + i] = localB->Rbar[iy];
      }
    }

    for (i = 0; i < 24; i++) {
      R[i] -= d_b[i];
    }

    for (iy = 0; iy < 8; iy++) {
      rtb_VectorConcatenate_n[0] = R[iy];
      rtb_VectorConcatenate_n[1] = R[iy + 8];
      rtb_VectorConcatenate_n[2] = R[iy + 16];
      rtb_Divide_pl = (rtb_VectorConcatenate_n[0] * rtb_VectorConcatenate_n[0] +
                       rtb_VectorConcatenate_n[1] * rtb_VectorConcatenate_n[1])
        + rtb_VectorConcatenate_n[2] * rtb_VectorConcatenate_n[2];
      rtb_Product_py = rtb_MatrixConcatenate2[iy];
      rtb_UnaryMinus2_idx_0 = rtb_VectorConcatenate_n[0];
      rtb_Gain1_g0 = rtb_VectorConcatenate_n[1];
      lam_muy_prime_idx_3 = rtb_VectorConcatenate_n[2];
      for (i = 0; i < 3; i++) {
        dpi_idx_0 = R[(i << 3) + iy];
        ibmat = 3 * i + 9 * iy;
        Itemp[ibmat] = (static_cast<real_T>(f_b[3 * i]) * rtb_Divide_pl -
                        dpi_idx_0 * rtb_UnaryMinus2_idx_0) * rtb_Product_py *
          static_cast<real_T>(e[3 * i]) + Imat[ibmat];
        Itemp_tmp = 3 * i + 1;
        Itemp[ibmat + 1] = (static_cast<real_T>(f_b[Itemp_tmp]) * rtb_Divide_pl
                            - dpi_idx_0 * rtb_Gain1_g0) * rtb_Product_py *
          static_cast<real_T>(e[Itemp_tmp]) + Imat[ibmat + 1];
        Itemp_tmp = 3 * i + 2;
        Itemp[ibmat + 2] = (static_cast<real_T>(f_b[Itemp_tmp]) * rtb_Divide_pl
                            - dpi_idx_0 * lam_muy_prime_idx_3) * rtb_Product_py *
          static_cast<real_T>(e[Itemp_tmp]) + Imat[ibmat + 2];
      }
    }

    std::memcpy(&rtb_Ibar[0], &Itemp[0], 9U * sizeof(real_T));
    for (iy = 0; iy < 7; iy++) {
      ibmat = (iy + 1) * 9;
      for (i = 0; i < 9; i++) {
        rtb_Ibar[i] += Itemp[ibmat + i];
      }
    }

    localB->Mbar = rtb_FrontBiasGain;
    localB->Xbar[0] = AdasPlantModel0_P->PlntVehDstCGFrntAxl - localB->Rbar[0];
    localB->Xbar[1] = AdasPlantModel0_P->PlntVehDstCGRearAxl + localB->Rbar[0];
    localB->Xbar[2] = AdasPlantModel0_P->PlntVehCGHgtAxl - localB->Rbar[2];
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0;
    rtb_Divide_pl = AdasPlantModel0_P->PlntVehTrckWdth[1] / 2.0;
    localB->Wbar[0] = rtb_UnaryMinus2_idx_0 + localB->Rbar[1];
    localB->Wbar[1] = rtb_UnaryMinus2_idx_0 - localB->Rbar[1];
    localB->Wbar[2] = rtb_Divide_pl + localB->Rbar[1];
    localB->Wbar[3] = rtb_Divide_pl - localB->Rbar[1];
    localB->HPbar[0] = localB->Xbar[0];
    localB->HPbar[3] = localB->Xbar[0];
    localB->HPbar[6] = -localB->Xbar[1];
    localB->HPbar[9] = -localB->Xbar[1];
    localB->HPbar[1] = -localB->Wbar[0];
    localB->HPbar[4] = localB->Wbar[1];
    localB->HPbar[7] = -localB->Wbar[2];
    localB->HPbar[10] = localB->Wbar[3];
    localB->HPbar[2] = localB->Xbar[2];
    localB->HPbar[5] = localB->Xbar[2];
    localB->HPbar[8] = localB->Xbar[2];
    localB->HPbar[11] = localB->Xbar[2];

    /* End of MATLAB Function: '<S391>/vehdyncginert' */

    /* Selector: '<S450>/Selector1' */
    localB->Selector1[0] = localB->HPbar[0];
    localB->Selector1[1] = localB->HPbar[1];
    localB->Selector1[2] = localB->HPbar[2];

    /* Selector: '<S451>/Selector1' */
    localB->Selector1_h[0] = localB->HPbar[3];
    localB->Selector1_h[1] = localB->HPbar[4];
    localB->Selector1_h[2] = localB->HPbar[5];
  }

  /* Sum: '<S460>/Sum' incorporates:
   *  Product: '<S462>/i x j'
   *  Product: '<S462>/j x k'
   *  Product: '<S462>/k x i'
   *  Product: '<S463>/i x k'
   *  Product: '<S463>/j x i'
   *  Product: '<S463>/k x j'
   */
  rtb_Product4_i[0] = localB->pqr[1] * localB->Selector1[2] - localB->Selector1
    [1] * localB->pqr[2];
  rtb_Product4_i[1] = localB->Selector1[0] * localB->pqr[2] - localB->pqr[0] *
    localB->Selector1[2];
  rtb_Product4_i[2] = localB->pqr[0] * localB->Selector1[1] - localB->Selector1
    [0] * localB->pqr[1];

  /* Sum: '<S456>/Add1' */
  localB->Add1_h[0] = rtb_Product4_i[0] + localB->UnitConversion[0];
  localB->Add1_h[1] = rtb_Product4_i[1] + localB->UnitConversion[1];
  localB->Add1_h[2] = rtb_Product4_i[2] + localB->UnitConversion[2];

  /* Sum: '<S468>/Sum' incorporates:
   *  Product: '<S470>/i x j'
   *  Product: '<S470>/j x k'
   *  Product: '<S470>/k x i'
   *  Product: '<S471>/i x k'
   *  Product: '<S471>/j x i'
   *  Product: '<S471>/k x j'
   */
  rtb_VectorConcatenate_n[0] = localB->pqr[1] * localB->Selector1_h[2] -
    localB->Selector1_h[1] * localB->pqr[2];
  rtb_VectorConcatenate_n[1] = localB->Selector1_h[0] * localB->pqr[2] -
    localB->pqr[0] * localB->Selector1_h[2];
  rtb_VectorConcatenate_n[2] = localB->pqr[0] * localB->Selector1_h[1] -
    localB->Selector1_h[0] * localB->pqr[1];

  /* Sum: '<S464>/Add1' */
  localB->Add1_d[0] = rtb_VectorConcatenate_n[0] + localB->UnitConversion[0];
  localB->Add1_d[1] = rtb_VectorConcatenate_n[1] + localB->UnitConversion[1];
  localB->Add1_d[2] = rtb_VectorConcatenate_n[2] + localB->UnitConversion[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Selector: '<S454>/Selector1' */
    localB->Selector1_p[0] = localB->HPbar[6];
    localB->Selector1_p[1] = localB->HPbar[7];
    localB->Selector1_p[2] = localB->HPbar[8];

    /* Selector: '<S455>/Selector1' */
    localB->Selector1_f[0] = localB->HPbar[9];
    localB->Selector1_f[1] = localB->HPbar[10];
    localB->Selector1_f[2] = localB->HPbar[11];
  }

  /* Sum: '<S496>/Sum' incorporates:
   *  Product: '<S498>/i x j'
   *  Product: '<S498>/j x k'
   *  Product: '<S498>/k x i'
   *  Product: '<S499>/i x k'
   *  Product: '<S499>/j x i'
   *  Product: '<S499>/k x j'
   */
  rtb_VectorConcatenate_km[0] = localB->pqr[1] * localB->Selector1_p[2] -
    localB->Selector1_p[1] * localB->pqr[2];
  rtb_VectorConcatenate_km[1] = localB->Selector1_p[0] * localB->pqr[2] -
    localB->pqr[0] * localB->Selector1_p[2];
  rtb_VectorConcatenate_km[2] = localB->pqr[0] * localB->Selector1_p[1] -
    localB->Selector1_p[0] * localB->pqr[1];

  /* Sum: '<S492>/Add1' */
  localB->Add1_b[0] = rtb_VectorConcatenate_km[0] + localB->UnitConversion[0];
  localB->Add1_b[1] = rtb_VectorConcatenate_km[1] + localB->UnitConversion[1];
  localB->Add1_b[2] = rtb_VectorConcatenate_km[2] + localB->UnitConversion[2];

  /* Sum: '<S504>/Sum' incorporates:
   *  Product: '<S506>/i x j'
   *  Product: '<S506>/j x k'
   *  Product: '<S506>/k x i'
   *  Product: '<S507>/i x k'
   *  Product: '<S507>/j x i'
   *  Product: '<S507>/k x j'
   */
  rtb_Product3_ju[0] = localB->pqr[1] * localB->Selector1_f[2] -
    localB->Selector1_f[1] * localB->pqr[2];
  rtb_Product3_ju[1] = localB->Selector1_f[0] * localB->pqr[2] - localB->pqr[0] *
    localB->Selector1_f[2];
  rtb_Product3_ju[2] = localB->pqr[0] * localB->Selector1_f[1] -
    localB->Selector1_f[0] * localB->pqr[1];

  /* Sum: '<S500>/Add1' */
  dpi_idx_0 = rtb_Product3_ju[0] + localB->UnitConversion[0];
  localB->Add1_j[0] = dpi_idx_0;

  /* Reshape: '<S294>/Reshape2' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  rtb_VectorConcatenate8[9] = dpi_idx_0;

  /* Sum: '<S500>/Add1' */
  dpi_idx_0 = rtb_Product3_ju[1] + localB->UnitConversion[1];
  localB->Add1_j[1] = dpi_idx_0;
  localB->Add1_j[2] = rtb_Product3_ju[2] + localB->UnitConversion[2];

  /* Selector: '<S285>/Selector1' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->xdot[0] = localB->Add1_h[0];

  /* Selector: '<S285>/Selector2' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->ydot[0] = localB->Add1_h[1];

  /* Concatenate: '<S286>/Matrix Concatenate' incorporates:
   *  Reshape: '<S294>/Reshape2'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  localB->MatrixConcatenate[0] = localB->Add1_h[0];
  localB->MatrixConcatenate[1] = localB->Add1_h[1];
  localB->MatrixConcatenate[2] = -localB->IntegratorSecondOrder_o2[0];

  /* Concatenate: '<S376>/Vector Concatenate3' incorporates:
   *  Constant: '<S376>/Constant3'
   *  Integrator: '<S374>/Integrator1'
   *  Selector: '<S286>/Selector2'
   *  Selector: '<S286>/Selector3'
   */
  localB->VectorConcatenate3[0] = localX->Integrator1_CSTATE_n[0];
  localB->VectorConcatenate3[1] = localP->Constant3_Value_n[0];
  localB->VectorConcatenate3[2] = localX->Integrator1_CSTATE_n[2];

  /* Selector: '<S285>/Selector1' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->xdot[1] = localB->Add1_d[0];

  /* Selector: '<S285>/Selector2' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->ydot[1] = localB->Add1_d[1];

  /* Concatenate: '<S286>/Matrix Concatenate' incorporates:
   *  Reshape: '<S294>/Reshape2'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  localB->MatrixConcatenate[3] = localB->Add1_d[0];
  localB->MatrixConcatenate[4] = localB->Add1_d[1];
  localB->MatrixConcatenate[5] = -localB->IntegratorSecondOrder_o2[1];

  /* Concatenate: '<S376>/Vector Concatenate3' incorporates:
   *  Constant: '<S376>/Constant3'
   *  Integrator: '<S374>/Integrator1'
   *  Selector: '<S286>/Selector2'
   *  Selector: '<S286>/Selector3'
   */
  localB->VectorConcatenate3[3] = localX->Integrator1_CSTATE_n[3];
  localB->VectorConcatenate3[4] = localP->Constant3_Value_n[1];
  localB->VectorConcatenate3[5] = localX->Integrator1_CSTATE_n[5];

  /* Selector: '<S285>/Selector1' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->xdot[2] = localB->Add1_b[0];

  /* Selector: '<S285>/Selector2' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->ydot[2] = localB->Add1_b[1];

  /* Concatenate: '<S286>/Matrix Concatenate' incorporates:
   *  Reshape: '<S294>/Reshape2'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  localB->MatrixConcatenate[6] = localB->Add1_b[0];
  localB->MatrixConcatenate[7] = localB->Add1_b[1];
  localB->MatrixConcatenate[8] = -localB->IntegratorSecondOrder_o2[2];

  /* Concatenate: '<S376>/Vector Concatenate3' incorporates:
   *  Constant: '<S376>/Constant3'
   *  Integrator: '<S374>/Integrator1'
   *  Selector: '<S286>/Selector2'
   *  Selector: '<S286>/Selector3'
   */
  localB->VectorConcatenate3[6] = localX->Integrator1_CSTATE_n[6];
  localB->VectorConcatenate3[7] = localP->Constant3_Value_n[2];
  localB->VectorConcatenate3[8] = localX->Integrator1_CSTATE_n[8];

  /* Selector: '<S285>/Selector1' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  localB->xdot[3] = rtb_VectorConcatenate8[9];

  /* Selector: '<S285>/Selector2' incorporates:
   *  Reshape: '<S294>/Reshape2'
   */
  localB->ydot[3] = dpi_idx_0;

  /* Concatenate: '<S286>/Matrix Concatenate' incorporates:
   *  Integrator: '<S374>/Integrator1'
   *  Reshape: '<S294>/Reshape2'
   *  Selector: '<S285>/Selector1'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  localB->MatrixConcatenate[9] = rtb_VectorConcatenate8[9];
  localB->MatrixConcatenate[10] = dpi_idx_0;
  localB->MatrixConcatenate[11] = -localB->IntegratorSecondOrder_o2[3];

  /* Concatenate: '<S376>/Vector Concatenate3' incorporates:
   *  Constant: '<S376>/Constant3'
   *  Integrator: '<S374>/Integrator1'
   *  Selector: '<S286>/Selector2'
   *  Selector: '<S286>/Selector3'
   */
  localB->VectorConcatenate3[9] = localX->Integrator1_CSTATE_n[9];
  localB->VectorConcatenate3[10] = localP->Constant3_Value_n[3];
  localB->VectorConcatenate3[11] = localX->Integrator1_CSTATE_n[11];

  /* Outputs for Iterator SubSystem: '<S375>/Wheel to Body Transform' incorporates:
   *  ForEach: '<S377>/For Each'
   */
  for (ForEach_itr_op = 0; ForEach_itr_op < 4; ForEach_itr_op++) {
    /* ForEachSliceSelector generated from: '<S377>/WheelAngles' incorporates:
     *  ForEachSliceSelector generated from: '<S377>/VelVeh'
     *  Product: '<S377>/Divide1'
     *  SignalConversion generated from: '<S378>/sincos'
     */
    iy = 3 * ForEach_itr_op + 2;

    /* SignalConversion generated from: '<S378>/sincos' incorporates:
     *  Concatenate: '<S376>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S377>/WheelAngles'
     */
    rtb_IntegratorSecondOrderLimite[0] = localB->VectorConcatenate3[iy];

    /* ForEachSliceSelector generated from: '<S377>/WheelAngles' incorporates:
     *  ForEachSliceSelector generated from: '<S377>/VelVeh'
     *  Product: '<S377>/Divide1'
     *  SignalConversion generated from: '<S378>/sincos'
     */
    ibmat = 3 * ForEach_itr_op + 1;

    /* SignalConversion generated from: '<S378>/sincos' incorporates:
     *  Concatenate: '<S376>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S377>/WheelAngles'
     */
    rtb_IntegratorSecondOrderLimite[1] = localB->VectorConcatenate3[ibmat];
    rtb_IntegratorSecondOrderLimite[2] = localB->VectorConcatenate3[3 *
      ForEach_itr_op];

    /* Trigonometry: '<S378>/sincos' */
    rtb_Switch1_h[0] = std::cos(rtb_IntegratorSecondOrderLimite[0]);
    rtb_UnaryMinus2_idx_0 = std::sin(rtb_IntegratorSecondOrderLimite[0]);
    rtb_Switch1_h[1] = std::cos(rtb_IntegratorSecondOrderLimite[1]);
    lam_muy_prime_idx_3 = std::sin(rtb_IntegratorSecondOrderLimite[1]);
    rtb_Switch1_h[2] = std::cos(rtb_IntegratorSecondOrderLimite[2]);
    rtb_FrontBiasGain = std::sin(rtb_IntegratorSecondOrderLimite[2]);

    /* Fcn: '<S378>/Fcn11' */
    rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

    /* Fcn: '<S378>/Fcn21' incorporates:
     *  Fcn: '<S378>/Fcn22'
     *  Trigonometry: '<S378>/sincos'
     */
    dpi_idx_0 = lam_muy_prime_idx_3 * rtb_FrontBiasGain;
    rtb_VectorConcatenate_ci[1] = dpi_idx_0 * rtb_Switch1_h[0] -
      rtb_UnaryMinus2_idx_0 * rtb_Switch1_h[2];

    /* Fcn: '<S378>/Fcn31' incorporates:
     *  Fcn: '<S378>/Fcn32'
     *  Trigonometry: '<S378>/sincos'
     */
    dpi_idx_1 = lam_muy_prime_idx_3 * rtb_Switch1_h[2];
    rtb_VectorConcatenate_ci[2] = dpi_idx_1 * rtb_Switch1_h[0] +
      rtb_UnaryMinus2_idx_0 * rtb_FrontBiasGain;

    /* Fcn: '<S378>/Fcn12' incorporates:
     *  Trigonometry: '<S378>/sincos'
     */
    rtb_VectorConcatenate_ci[3] = rtb_UnaryMinus2_idx_0 * rtb_Switch1_h[1];

    /* Fcn: '<S378>/Fcn22' incorporates:
     *  Trigonometry: '<S378>/sincos'
     */
    rtb_VectorConcatenate_ci[4] = dpi_idx_0 * rtb_UnaryMinus2_idx_0 +
      rtb_Switch1_h[0] * rtb_Switch1_h[2];

    /* Fcn: '<S378>/Fcn32' incorporates:
     *  Trigonometry: '<S378>/sincos'
     */
    rtb_VectorConcatenate_ci[5] = dpi_idx_1 * rtb_UnaryMinus2_idx_0 -
      rtb_Switch1_h[0] * rtb_FrontBiasGain;

    /* Fcn: '<S378>/Fcn13' incorporates:
     *  Trigonometry: '<S378>/sincos'
     */
    rtb_VectorConcatenate_ci[6] = -lam_muy_prime_idx_3;

    /* Fcn: '<S378>/Fcn23' incorporates:
     *  Trigonometry: '<S378>/sincos'
     */
    rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] * rtb_FrontBiasGain;

    /* Fcn: '<S378>/Fcn33' */
    rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

    /* Product: '<S377>/Divide1' */
    for (i = 0; i < 3; i++) {
      /* SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' incorporates:
       *  Concatenate: '<S489>/Vector Concatenate'
       *  ForEachSliceSelector generated from: '<S377>/VelVeh'
       */
      rtb_IntegratorSecondOrderLimite[i] = (rtb_VectorConcatenate_ci[i + 3] *
        localB->MatrixConcatenate[ibmat] + localB->MatrixConcatenate[3 *
        ForEach_itr_op] * rtb_VectorConcatenate_ci[i]) +
        rtb_VectorConcatenate_ci[i + 6] * localB->MatrixConcatenate[iy];
    }

    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Trigonometry: '<S379>/sincos' incorporates:
       *  Constant: '<S377>/Constant'
       *  SignalConversion generated from: '<S379>/sincos'
       */
      rtb_Divide_pl = std::cos(localP->CoreSubsys_p.Constant_Value[2]);
      dpi_idx_2 = std::sin(localP->CoreSubsys_p.Constant_Value[2]);
      rtb_Gain1_g0 = std::cos(localP->CoreSubsys_p.Constant_Value[1]);
      dpi_idx_3 = std::sin(localP->CoreSubsys_p.Constant_Value[1]);
      Fzo_prime_idx_0 = std::cos(localP->CoreSubsys_p.Constant_Value[0]);
      Fzo_prime_idx_1 = std::sin(localP->CoreSubsys_p.Constant_Value[0]);

      /* Fcn: '<S379>/Fcn11' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[0] = rtb_Divide_pl *
        rtb_Gain1_g0;

      /* Fcn: '<S379>/Fcn21' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Fcn: '<S379>/Fcn22'
       *  Trigonometry: '<S379>/sincos'
       */
      dpi_idx_0 = dpi_idx_3 * Fzo_prime_idx_1;
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[1] = dpi_idx_0 *
        rtb_Divide_pl - dpi_idx_2 * Fzo_prime_idx_0;

      /* Fcn: '<S379>/Fcn31' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Fcn: '<S379>/Fcn32'
       *  Trigonometry: '<S379>/sincos'
       */
      dpi_idx_1 = dpi_idx_3 * Fzo_prime_idx_0;
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[2] = dpi_idx_1 *
        rtb_Divide_pl + dpi_idx_2 * Fzo_prime_idx_1;

      /* Fcn: '<S379>/Fcn12' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Trigonometry: '<S379>/sincos'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[3] = dpi_idx_2 *
        rtb_Gain1_g0;

      /* Fcn: '<S379>/Fcn22' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Trigonometry: '<S379>/sincos'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[4] = dpi_idx_0 *
        dpi_idx_2 + rtb_Divide_pl * Fzo_prime_idx_0;

      /* Fcn: '<S379>/Fcn32' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Trigonometry: '<S379>/sincos'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[5] = dpi_idx_1 *
        dpi_idx_2 - rtb_Divide_pl * Fzo_prime_idx_1;

      /* Fcn: '<S379>/Fcn13' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Trigonometry: '<S379>/sincos'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[6] = -dpi_idx_3;

      /* Fcn: '<S379>/Fcn23' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       *  Trigonometry: '<S379>/sincos'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[7] = rtb_Gain1_g0 *
        Fzo_prime_idx_1;

      /* Fcn: '<S379>/Fcn33' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       */
      localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[8] = rtb_Gain1_g0 *
        Fzo_prime_idx_0;
    }

    /* Product: '<S377>/Divide2' incorporates:
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     */
    rtb_UnaryMinus2_idx_0 = rtb_IntegratorSecondOrderLimite[1];
    lam_muy_prime_idx_3 = rtb_IntegratorSecondOrderLimite[0];
    rtb_FrontBiasGain = rtb_IntegratorSecondOrderLimite[2];
    for (i = 0; i < 3; i++) {
      /* Product: '<S377>/Divide2' incorporates:
       *  Concatenate: '<S381>/Vector Concatenate'
       */
      rtb_Divide2[i] = (localB->CoreSubsys_p[ForEach_itr_op].VectorConcatenate[i
                        + 3] * rtb_UnaryMinus2_idx_0 + localB->
                        CoreSubsys_p[ForEach_itr_op].VectorConcatenate[i] *
                        lam_muy_prime_idx_3) + localB->
        CoreSubsys_p[ForEach_itr_op].VectorConcatenate[i + 6] *
        rtb_FrontBiasGain;
    }

    /* End of Product: '<S377>/Divide2' */

    /* ForEachSliceAssignment generated from: '<S377>/zdotWheel' */
    rtb_ImpAsg_InsertedFor_zdotWhee[ForEach_itr_op] = rtb_Divide2[2];

    /* ForEachSliceAssignment generated from: '<S377>/ydotWheel' */
    rtb_ImpAsg_InsertedFor_ydotWhee[ForEach_itr_op] = rtb_Divide2[1];

    /* ForEachSliceAssignment generated from: '<S377>/xdotWheel' */
    rtb_ImpAsg_InsertedFor_xdotWhee[ForEach_itr_op] = rtb_Divide2[0];
  }

  /* End of Outputs for SubSystem: '<S375>/Wheel to Body Transform' */

  /* Reshape: '<S375>/Reshape1' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/xdotWheel'
   */
  localB->Reshape1[0] = rtb_ImpAsg_InsertedFor_xdotWhee[0];

  /* Reshape: '<S375>/Reshape2' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/ydotWheel'
   */
  localB->Reshape2[0] = rtb_ImpAsg_InsertedFor_ydotWhee[0];

  /* Reshape: '<S375>/Reshape1' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/xdotWheel'
   */
  localB->Reshape1[1] = rtb_ImpAsg_InsertedFor_xdotWhee[1];

  /* Reshape: '<S375>/Reshape2' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/ydotWheel'
   */
  localB->Reshape2[1] = rtb_ImpAsg_InsertedFor_ydotWhee[1];

  /* Reshape: '<S375>/Reshape1' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/xdotWheel'
   */
  localB->Reshape1[2] = rtb_ImpAsg_InsertedFor_xdotWhee[2];

  /* Reshape: '<S375>/Reshape2' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/ydotWheel'
   */
  localB->Reshape2[2] = rtb_ImpAsg_InsertedFor_ydotWhee[2];

  /* Reshape: '<S375>/Reshape1' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/xdotWheel'
   */
  localB->Reshape1[3] = rtb_ImpAsg_InsertedFor_xdotWhee[3];

  /* Reshape: '<S375>/Reshape2' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/ydotWheel'
   */
  localB->Reshape2[3] = rtb_ImpAsg_InsertedFor_ydotWhee[3];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Concatenate: '<S292>/Matrix Concatenate1' incorporates:
     *  Constant: '<S292>/SteerRates'
     */
    localB->MatrixConcatenate1[0] = localP->SteerRates_Value[0];
    localB->MatrixConcatenate1[1] = localP->SteerRates_Value[0];
    localB->MatrixConcatenate1[2] = localP->SteerRates_Value[0];
    localB->MatrixConcatenate1[3] = localP->SteerRates_Value[1];
    localB->MatrixConcatenate1[4] = localP->SteerRates_Value[1];
    localB->MatrixConcatenate1[5] = localP->SteerRates_Value[1];
    localB->MatrixConcatenate1[6] = localP->SteerRates_Value[2];
    localB->MatrixConcatenate1[7] = localP->SteerRates_Value[2];
    localB->MatrixConcatenate1[8] = localP->SteerRates_Value[2];
    localB->MatrixConcatenate1[9] = localP->SteerRates_Value[3];
    localB->MatrixConcatenate1[10] = localP->SteerRates_Value[3];
    localB->MatrixConcatenate1[11] = localP->SteerRates_Value[3];
  }

  /* Concatenate: '<S292>/Matrix Concatenate' incorporates:
   *  Constant: '<S292>/Constant'
   *  Reshape: '<S292>/Reshape4'
   */
  rtb_VectorConcatenate8[0] = localP->Constant_Value_bk[0];
  rtb_VectorConcatenate8[1] = localP->Constant_Value_bk[0];
  rtb_VectorConcatenate8[3] = localP->Constant_Value_bk[1];
  rtb_VectorConcatenate8[4] = localP->Constant_Value_bk[1];
  rtb_VectorConcatenate8[6] = localP->Constant_Value_bk[2];
  rtb_VectorConcatenate8[7] = localP->Constant_Value_bk[2];
  rtb_VectorConcatenate8[9] = localP->Constant_Value_bk[3];
  rtb_VectorConcatenate8[10] = localP->Constant_Value_bk[3];
  rtb_VectorConcatenate8[2] = localB->pqr[2];
  rtb_VectorConcatenate8[5] = localB->pqr[2];
  rtb_VectorConcatenate8[8] = localB->pqr[2];
  rtb_VectorConcatenate8[11] = localB->pqr[2];
  for (i = 0; i < 12; i++) {
    /* Sum: '<S292>/Add' incorporates:
     *  Concatenate: '<S292>/Matrix Concatenate1'
     */
    localB->AngVel[i] = localB->MatrixConcatenate1[i] + rtb_VectorConcatenate8[i];
  }

  /* UnaryMinus: '<S375>/Unary Minus' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Sum: '<S292>/Add'
   */
  localB->UnaryMinus[0] = -localB->AngVel[2];

  /* Reshape: '<S508>/Reshape' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate3'
   *  Selector: '<S508>/Selector'
   */
  localB->Reshape[0] = localB->VectorConcatenate3[0];

  /* UnaryMinus: '<S375>/Unary Minus' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Sum: '<S292>/Add'
   */
  localB->UnaryMinus[1] = -localB->AngVel[5];

  /* Reshape: '<S508>/Reshape' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate3'
   *  Selector: '<S508>/Selector'
   */
  localB->Reshape[1] = localB->VectorConcatenate3[3];

  /* UnaryMinus: '<S375>/Unary Minus' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Sum: '<S292>/Add'
   */
  localB->UnaryMinus[2] = -localB->AngVel[8];

  /* Reshape: '<S508>/Reshape' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate3'
   *  Selector: '<S508>/Selector'
   */
  localB->Reshape[2] = localB->VectorConcatenate3[6];

  /* UnaryMinus: '<S375>/Unary Minus' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Sum: '<S292>/Add'
   */
  localB->UnaryMinus[3] = -localB->AngVel[11];

  /* Reshape: '<S508>/Reshape' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate3'
   *  Selector: '<S508>/Selector'
   */
  localB->Reshape[3] = localB->VectorConcatenate3[9];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S508>/Front Pressure' */
    localB->FrontPressure[0] = AdasPlantModel0_P->PlntWhlPrsFrnt;

    /* Constant: '<S508>/Rear Pressure' */
    localB->RearPressure[0] = AdasPlantModel0_P->PlntWhlPrsRear;

    /* Constant: '<S508>/Front Pressure' */
    localB->FrontPressure[1] = AdasPlantModel0_P->PlntWhlPrsFrnt;

    /* Constant: '<S508>/Rear Pressure' */
    localB->RearPressure[1] = AdasPlantModel0_P->PlntWhlPrsRear;

    /* Concatenate: '<S510>/Vector Concatenate' incorporates:
     *  Concatenate: '<S75>/Vector Concatenate'
     *  Constant: '<S510>/0'
     *  Constant: '<S510>/1'
     *  Constant: '<S510>/2'
     *  Constant: '<S510>/ones'
     *  Constant: '<S510>/ones1'
     *  Constant: '<S510>/ones2'
     *  Constant: '<S510>/ones3'
     */
    localB->VectorConcatenate_e[0] = localP->ones2_Value[0];
    localB->VectorConcatenate_e[1] = localB->VectorConcatenate[0];
    localB->VectorConcatenate_e[2] = localB->VectorConcatenate[0];
    localB->VectorConcatenate_e[3] = localP->u_Value[0];
    localB->VectorConcatenate_e[27] = localP->ones2_Value[1];
    localB->VectorConcatenate_e[28] = localB->VectorConcatenate[1];
    localB->VectorConcatenate_e[29] = localB->VectorConcatenate[1];
    localB->VectorConcatenate_e[30] = localP->u_Value[1];
    localB->VectorConcatenate_e[54] = localP->ones2_Value[2];
    localB->VectorConcatenate_e[55] = localB->VectorConcatenate[2];
    localB->VectorConcatenate_e[56] = localB->VectorConcatenate[2];
    localB->VectorConcatenate_e[57] = localP->u_Value[2];
    localB->VectorConcatenate_e[81] = localP->ones2_Value[3];
    localB->VectorConcatenate_e[82] = localB->VectorConcatenate[3];
    localB->VectorConcatenate_e[83] = localB->VectorConcatenate[3];
    localB->VectorConcatenate_e[84] = localP->u_Value[3];
    for (i = 0; i < 9; i++) {
      localB->VectorConcatenate_e[i + 4] = localP->ones1_Value[i];
      localB->VectorConcatenate_e[i + 31] = localP->ones1_Value[i + 9];
      localB->VectorConcatenate_e[i + 58] = localP->ones1_Value[i + 18];
      localB->VectorConcatenate_e[i + 85] = localP->ones1_Value[i + 27];
    }

    for (i = 0; i < 4; i++) {
      localB->VectorConcatenate_e[27 * i + 13] = localP->u_Value_h[i];
      for (iy = 0; iy < 5; iy++) {
        localB->VectorConcatenate_e[(iy + 27 * i) + 14] = localP->ones3_Value[5 *
          i + iy];
      }

      iy = i << 1;
      localB->VectorConcatenate_e[27 * i + 19] = localP->u_Value_c[iy];
      localB->VectorConcatenate_e[27 * i + 20] = localP->u_Value_c[iy + 1];
    }

    for (i = 0; i < 6; i++) {
      localB->VectorConcatenate_e[i + 21] = localP->ones_Value[i];
      localB->VectorConcatenate_e[i + 48] = localP->ones_Value[i + 6];
      localB->VectorConcatenate_e[i + 75] = localP->ones_Value[i + 12];
      localB->VectorConcatenate_e[i + 102] = localP->ones_Value[i + 18];
    }
  }

  /* Product: '<S520>/Product' incorporates:
   *  Constant: '<S520>/Constant1'
   */
  rtb_Product[0] = localP->Constant1_Value_f * localB->Saturation[0];
  rtb_Product[1] = localP->Constant1_Value_f * localB->Saturation[1];
  rtb_Product[2] = localP->Constant1_Value_f * localB->Saturation[2];
  rtb_Product[3] = localP->Constant1_Value_f * localB->Saturation[3];

  /* SignalConversion generated from: '<S518>/ SFunction ' incorporates:
   *  MATLAB Function: '<S513>/Magic Tire Const Input'
   */
  rtb_VectorConcatenate3[0] = localB->FrontPressure[0];
  rtb_VectorConcatenate3[2] = localB->RearPressure[0];
  rtb_VectorConcatenate3[1] = localB->FrontPressure[1];
  rtb_VectorConcatenate3[3] = localB->RearPressure[1];

  /* MATLAB Function: '<S513>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S510>/Vector Concatenate'
   *  Constant: '<S511>/vertType'
   *  Saturate: '<S520>/Saturation'
   */
  rtb_sig_x[0] = localB->Reshape[0];
  rtb_sig_x[1] = localB->Reshape[1];
  rtb_sig_x[2] = localB->Reshape[2];
  rtb_sig_x[3] = localB->Reshape[3];
  rtb_Divide_pl = localP->CombinedSlipWheel2DOF_Q_FZ1;
  if (localP->MagicTireConstInput_vdynMF[3] == 1.0) {
    rtb_ImpAsg_InsertedFor_ydotWhee[0] = localB->VectorConcatenate_e[1];
    lam_muy[0] = localB->VectorConcatenate_e[2];
    localB->Mx_c[0] = localB->VectorConcatenate_e[23];
    rtb_ImpAsg_InsertedFor_ydotWhee[1] = localB->VectorConcatenate_e[28];
    lam_muy[1] = localB->VectorConcatenate_e[29];
    localB->Mx_c[1] = localB->VectorConcatenate_e[50];
    rtb_ImpAsg_InsertedFor_ydotWhee[2] = localB->VectorConcatenate_e[55];
    lam_muy[2] = localB->VectorConcatenate_e[56];
    localB->Mx_c[2] = localB->VectorConcatenate_e[77];
    rtb_ImpAsg_InsertedFor_ydotWhee[3] = localB->VectorConcatenate_e[82];
    lam_muy[3] = localB->VectorConcatenate_e[83];
    localB->Mx_c[3] = localB->VectorConcatenate_e[104];
    AdasPlantModel0_div0protect(localB->Reshape1,
      AdasPlantModel0_P->PlntWhlVelTolLowVel, R_omega, Vsy);
    for (i = 0; i < 4; i++) {
      if (localB->Reshape[i] < AdasPlantModel0_P->PlntWhlMinCmbr) {
        rtb_sig_x[i] = AdasPlantModel0_P->PlntWhlMinCmbr;
      }

      if (rtb_sig_x[i] > AdasPlantModel0_P->PlntWhlMaxCmbr) {
        rtb_sig_x[i] = AdasPlantModel0_P->PlntWhlMaxCmbr;
      }

      dpi_idx_0 = rtb_VectorConcatenate3[i];
      if (dpi_idx_0 < AdasPlantModel0_P->PlntWhlMinPress) {
        dpi_idx_0 = AdasPlantModel0_P->PlntWhlMinPress;
        rtb_VectorConcatenate3[i] = AdasPlantModel0_P->PlntWhlMinPress;
      }

      if (dpi_idx_0 > AdasPlantModel0_P->PlntWhlMaxPress) {
        rtb_VectorConcatenate3[i] = AdasPlantModel0_P->PlntWhlMaxPress;
      }

      if (rtb_ImpAsg_InsertedFor_ydotWhee[i] <= 0.0) {
        rtb_ImpAsg_InsertedFor_ydotWhee[i] = 2.2204460492503131E-16;
      }

      if (lam_muy[i] <= 0.0) {
        lam_muy[i] = 2.2204460492503131E-16;
      }
    }

    dpi_idx_0 = (rtb_VectorConcatenate3[0] - AdasPlantModel0_P->PlntWhlNomPress)
      / AdasPlantModel0_P->PlntWhlNomPress;
    dpi_idx_1 = (rtb_VectorConcatenate3[1] - AdasPlantModel0_P->PlntWhlNomPress)
      / AdasPlantModel0_P->PlntWhlNomPress;
    dpi_idx_2 = (rtb_VectorConcatenate3[2] - AdasPlantModel0_P->PlntWhlNomPress)
      / AdasPlantModel0_P->PlntWhlNomPress;
    dpi_idx_3 = (rtb_VectorConcatenate3[3] - AdasPlantModel0_P->PlntWhlNomPress)
      / AdasPlantModel0_P->PlntWhlNomPress;
    Fzo_prime_idx_0 = localB->VectorConcatenate_e[0] *
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_1 = localB->VectorConcatenate_e[27] *
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_2 = localB->VectorConcatenate_e[54] *
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_3 = localB->VectorConcatenate_e[81] *
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    if (localP->vertType_Value == 2.0) {
      if (localP->CombinedSlipWheel2DOF_Q_FZ1 == 0.0) {
        rtb_Divide_pl = localP->CombinedSlipWheel2DOF_VERTICAL_ *
          AdasPlantModel0_P->PlntWhlUnldRadius /
          AdasPlantModel0_P->PlntWhlNomNorlForce;
        rtb_UnaryMinus2_idx_0 = localP->CombinedSlipWheel2DOF_Q_FZ1;
        rtb_Divide_pl = rtb_Divide_pl * rtb_Divide_pl - 4.0 *
          localP->CombinedSlipWheel2DOF_Q_FZ2;
        if (rtb_Divide_pl < 0.0) {
          rtb_UnaryMinus2_idx_0 = localP->CombinedSlipWheel2DOF_Q_FZ2 * 0.0;
        }

        iy = 0;
        if (!(rtb_Divide_pl < 0.0)) {
          for (i = 0; i < 1; i++) {
            iy++;
          }
        }

        ec_size[0] = 1;
        ec_size[1] = iy;
        if (iy - 1 >= 0) {
          rtb_Smallangleapproximationford = rtb_Divide_pl;
        }

        AdasPlantModel0_sqrt(&rtb_Smallangleapproximationford, ec_size);
        if (!(rtb_Divide_pl < 0.0)) {
          rtb_UnaryMinus2_idx_0 = rtb_Smallangleapproximationford;
        }

        rtb_Divide_pl = rtb_UnaryMinus2_idx_0;
      }

      rtb_Gain1_g0 = std::abs(rty_VehFdbk_c[0]);
      rtb_FrontBiasGain = std::abs(rty_VehFdbk_c[1]);
      rtb_Product_py = std::abs(rty_VehFdbk_c[2]);
      rtb_Smallangleapproximationford = std::abs(rty_VehFdbk_c[3]);
      rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlRimRadius +
        localP->CombinedSlipWheel2DOF_BOTTOM_OF;
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[0] /
        AdasPlantModel0_P->PlntWhlNomNorlForce;
      rtb_Integrator1_p = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_i[0]
        / AdasPlantModel0_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = rtb_Saturation[0] / AdasPlantModel0_P->PlntWhlUnldRadius;
      rtb_Product[0] = std::fmax((((localP->CombinedSlipWheel2DOF_Q_V2 *
        rtb_Gain1_g0 * AdasPlantModel0_P->PlntWhlUnldRadius /
        AdasPlantModel0_P->PlntWhlLongSpd + 1.0) - rtb_Integrator1_p) -
        lam_muy_prime_idx_3) * ((localP->CombinedSlipWheel2DOF_Q_FZ3 *
        rtb_sig_x[0] * rtb_sig_x[0] + rtb_Divide_pl) * rtb_Saturation[0] /
        AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Sum1_m * rtb_Sum1_m *
        localP->CombinedSlipWheel2DOF_Q_FZ2) *
        (localP->CombinedSlipWheel2DOF_PFZ1 * dpi_idx_0 + 1.0) * Fzo_prime_idx_0,
        (rtb_UnaryMinus2_idx_0 - (AdasPlantModel0_P->PlntWhlUnldRadius +
        rtb_Saturation[0]) / std::cos(rtb_sig_x[0])) *
        localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[1] /
        AdasPlantModel0_P->PlntWhlNomNorlForce;
      rtb_Integrator1_p = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_i[1]
        / AdasPlantModel0_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = rtb_Saturation[1] / AdasPlantModel0_P->PlntWhlUnldRadius;
      rtb_Product[1] = std::fmax((((localP->CombinedSlipWheel2DOF_Q_V2 *
        rtb_FrontBiasGain * AdasPlantModel0_P->PlntWhlUnldRadius /
        AdasPlantModel0_P->PlntWhlLongSpd + 1.0) - rtb_Integrator1_p) -
        lam_muy_prime_idx_3) * ((localP->CombinedSlipWheel2DOF_Q_FZ3 *
        rtb_sig_x[1] * rtb_sig_x[1] + rtb_Divide_pl) * rtb_Saturation[1] /
        AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Sum1_m * rtb_Sum1_m *
        localP->CombinedSlipWheel2DOF_Q_FZ2) *
        (localP->CombinedSlipWheel2DOF_PFZ1 * dpi_idx_1 + 1.0) * Fzo_prime_idx_1,
        (rtb_UnaryMinus2_idx_0 - (AdasPlantModel0_P->PlntWhlUnldRadius +
        rtb_Saturation[1]) / std::cos(rtb_sig_x[1])) *
        localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[2] /
        AdasPlantModel0_P->PlntWhlNomNorlForce;
      rtb_Integrator1_p = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_i[2]
        / AdasPlantModel0_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = rtb_Saturation[2] / AdasPlantModel0_P->PlntWhlUnldRadius;
      rtb_Product[2] = std::fmax((((localP->CombinedSlipWheel2DOF_Q_V2 *
        rtb_Product_py * AdasPlantModel0_P->PlntWhlUnldRadius /
        AdasPlantModel0_P->PlntWhlLongSpd + 1.0) - rtb_Integrator1_p) -
        lam_muy_prime_idx_3) * ((localP->CombinedSlipWheel2DOF_Q_FZ3 *
        rtb_sig_x[2] * rtb_sig_x[2] + rtb_Divide_pl) * rtb_Saturation[2] /
        AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Sum1_m * rtb_Sum1_m *
        localP->CombinedSlipWheel2DOF_Q_FZ2) *
        (localP->CombinedSlipWheel2DOF_PFZ1 * dpi_idx_2 + 1.0) * Fzo_prime_idx_2,
        (rtb_UnaryMinus2_idx_0 - (AdasPlantModel0_P->PlntWhlUnldRadius +
        rtb_Saturation[2]) / std::cos(rtb_sig_x[2])) *
        localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[3] /
        AdasPlantModel0_P->PlntWhlNomNorlForce;
      rtb_Integrator1_p = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_i[3]
        / AdasPlantModel0_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = rtb_Sum1_m * rtb_Sum1_m;
      rtb_Sum1_m = rtb_Saturation_0 / AdasPlantModel0_P->PlntWhlUnldRadius;
      rtb_Product[3] = std::fmax((((localP->CombinedSlipWheel2DOF_Q_V2 *
        rtb_Smallangleapproximationford * AdasPlantModel0_P->PlntWhlUnldRadius /
        AdasPlantModel0_P->PlntWhlLongSpd + 1.0) - rtb_Integrator1_p) -
        lam_muy_prime_idx_3) * ((localP->CombinedSlipWheel2DOF_Q_FZ3 *
        rtb_sig_x[3] * rtb_sig_x[3] + rtb_Divide_pl) * rtb_Saturation_0 /
        AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Sum1_m * rtb_Sum1_m *
        localP->CombinedSlipWheel2DOF_Q_FZ2) *
        (localP->CombinedSlipWheel2DOF_PFZ1 * dpi_idx_3 + 1.0) * Fzo_prime_idx_3,
        (rtb_UnaryMinus2_idx_0 - (AdasPlantModel0_P->PlntWhlUnldRadius +
        rtb_Saturation_0) / std::cos(rtb_sig_x[3])) *
        localP->CombinedSlipWheel2DOF_BOTTOM_ST);
    }

    localB->Re[0] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate_e[22];
    localB->Re[1] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate_e[49];
    localB->Re[2] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate_e[76];
    localB->Re[3] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate_e[103];
    iy = 0;
    for (i = 0; i < 4; i++) {
      if (rtb_Saturation[i] > 0.0) {
        iy++;
      }
    }

    Itemp_tmp = iy;
    ibmat = 0;
    for (i = 0; i < 4; i++) {
      if (rtb_Saturation[i] > 0.0) {
        tmp_data[ibmat] = i;
        ibmat++;
      }
    }

    ibmat = iy;
    rtb_Saturation_size = iy;
    for (i = 0; i < ibmat; i++) {
      iy = tmp_data[i];
      rtb_Saturation_data[i] = rtb_Saturation[iy];
      rtb_Saturation_data_0[i] = rtb_Saturation[iy];
      rtb_ImpAsg_InsertedFor_xdotWhee[i] = rtb_Saturation[iy];
    }

    AdasPlantModel0_abs(rtb_ImpAsg_InsertedFor_xdotWhee, &rtb_Saturation_size,
                        phi, &iy);
    i = Itemp_tmp == 1 ? iy : Itemp_tmp;
    AdasPlantModel0_abs(rtb_Saturation_data, &Itemp_tmp, phi, &iy);
    AdasPlantModel0_abs(rtb_Saturation_data_0, &ibmat, phi, &rtb_Saturation_size);
    if ((Itemp_tmp == iy) && ((Itemp_tmp == 1 ? rtb_Saturation_size : Itemp_tmp)
         == Itemp_tmp) && ((i == 1 ? Itemp_tmp : i) == Itemp_tmp)) {
      for (i = 0; i < Itemp_tmp; i++) {
        rtb_Saturation_data[i] = rtb_Saturation[tmp_data[i]];
      }

      AdasPlantModel0_abs(rtb_Saturation_data, &Itemp_tmp, rtb_Saturation_data_0,
                          &ibmat);
      for (i = 0; i < Itemp_tmp; i++) {
        iy = tmp_data[i];
        localB->Re[iy] = (localP->CombinedSlipWheel2DOF_Q_FCY2 *
                          localB->Integrator_i[iy] /
                          AdasPlantModel0_P->PlntWhlNomNorlForce +
                          rtb_Product[iy] / rtb_Saturation_data_0[i]) *
          localB->VectorConcatenate_e[27 * iy + 22];
      }
    } else {
      AdasPlan_binary_expand_op_nxejp(localB->Re, tmp_data, &Itemp_tmp,
        rtb_Product, rtb_Saturation, localP->CombinedSlipWheel2DOF_Q_FCY2,
        localB->Integrator_i, AdasPlantModel0_P->PlntWhlNomNorlForce,
        localB->VectorConcatenate_e);
    }

    FzUnSat[0] = rtb_Product[0];
    FzUnSat[1] = rtb_Product[1];
    FzUnSat[2] = rtb_Product[2];
    FzUnSat[3] = rtb_Product[3];
    for (i = 0; i < 4; i++) {
      rtb_Saturation_0 = rtb_Product[i];
      if (rtb_Saturation_0 < AdasPlantModel0_P->PlntWhlMinFz) {
        rtb_Saturation_0 = AdasPlantModel0_P->PlntWhlMinFz;
        rtb_Product[i] = AdasPlantModel0_P->PlntWhlMinFz;
      }

      if (rtb_Saturation_0 > AdasPlantModel0_P->PlntWhlMaxFz) {
        rtb_Product[i] = AdasPlantModel0_P->PlntWhlMaxFz;
      }
    }

    rtb_Product_py = (rtb_Product[0] - Fzo_prime_idx_0) / Fzo_prime_idx_0;
    dfz[0] = rtb_Product_py;
    epsilon_gamma[0] = (localP->MagicTireConstInput_PECP2 * rtb_Product_py + 1.0)
      * localP->MagicTireConstInput_PECP1;
    rtb_Product_py = (rtb_Product[1] - Fzo_prime_idx_1) / Fzo_prime_idx_1;
    dfz[1] = rtb_Product_py;
    epsilon_gamma[1] = (localP->MagicTireConstInput_PECP2 * rtb_Product_py + 1.0)
      * localP->MagicTireConstInput_PECP1;
    rtb_Product_py = (rtb_Product[2] - Fzo_prime_idx_2) / Fzo_prime_idx_2;
    dfz[2] = rtb_Product_py;
    epsilon_gamma[2] = (localP->MagicTireConstInput_PECP2 * rtb_Product_py + 1.0)
      * localP->MagicTireConstInput_PECP1;
    rtb_Product_py = (rtb_Product[3] - Fzo_prime_idx_3) / Fzo_prime_idx_3;
    dfz[3] = rtb_Product_py;
    epsilon_gamma[3] = (localP->MagicTireConstInput_PECP2 * rtb_Product_py + 1.0)
      * localP->MagicTireConstInput_PECP1;
    b_x[0] = rty_VehFdbk_c[0] * AdasPlantModel0_P->PlntWhlUnldRadius /
      AdasPlantModel0_P->PlntWhlLongSpd;
    b_x[1] = rty_VehFdbk_c[1] * AdasPlantModel0_P->PlntWhlUnldRadius /
      AdasPlantModel0_P->PlntWhlLongSpd;
    b_x[2] = rty_VehFdbk_c[2] * AdasPlantModel0_P->PlntWhlUnldRadius /
      AdasPlantModel0_P->PlntWhlLongSpd;
    b_x[3] = rty_VehFdbk_c[3] * AdasPlantModel0_P->PlntWhlUnldRadius /
      AdasPlantModel0_P->PlntWhlLongSpd;
    R_omega_0 = (b_x[0] * b_x[0] * localP->CombinedSlipWheel2DOF_Q_V1 +
                 localP->CombinedSlipWheel2DOF_Q_RE0) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    R_omega[0] = R_omega_0;
    lam_Cz_0 = FzUnSat[0] / AdasPlantModel0_P->PlntWhlNomNorlForce;
    localB->Re[0] = R_omega_0 - (std::atan(localP->CombinedSlipWheel2DOF_BREFF *
      lam_Cz_0) * localP->CombinedSlipWheel2DOF_DREFF +
      localP->CombinedSlipWheel2DOF_FREFF * lam_Cz_0) *
      (AdasPlantModel0_P->PlntWhlNomNorlForce / localB->Re[0]);
    R_omega_0 = (b_x[1] * b_x[1] * localP->CombinedSlipWheel2DOF_Q_V1 +
                 localP->CombinedSlipWheel2DOF_Q_RE0) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    R_omega[1] = R_omega_0;
    lam_Cz_0 = FzUnSat[1] / AdasPlantModel0_P->PlntWhlNomNorlForce;
    localB->Re[1] = R_omega_0 - (std::atan(localP->CombinedSlipWheel2DOF_BREFF *
      lam_Cz_0) * localP->CombinedSlipWheel2DOF_DREFF +
      localP->CombinedSlipWheel2DOF_FREFF * lam_Cz_0) *
      (AdasPlantModel0_P->PlntWhlNomNorlForce / localB->Re[1]);
    R_omega_0 = (b_x[2] * b_x[2] * localP->CombinedSlipWheel2DOF_Q_V1 +
                 localP->CombinedSlipWheel2DOF_Q_RE0) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    R_omega[2] = R_omega_0;
    lam_Cz_0 = FzUnSat[2] / AdasPlantModel0_P->PlntWhlNomNorlForce;
    localB->Re[2] = R_omega_0 - (std::atan(localP->CombinedSlipWheel2DOF_BREFF *
      lam_Cz_0) * localP->CombinedSlipWheel2DOF_DREFF +
      localP->CombinedSlipWheel2DOF_FREFF * lam_Cz_0) *
      (AdasPlantModel0_P->PlntWhlNomNorlForce / localB->Re[2]);
    R_omega_0 = (b_x[3] * b_x[3] * localP->CombinedSlipWheel2DOF_Q_V1 +
                 localP->CombinedSlipWheel2DOF_Q_RE0) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    lam_Cz_0 = FzUnSat[3] / AdasPlantModel0_P->PlntWhlNomNorlForce;
    localB->Re[3] = R_omega_0 - (std::atan(localP->CombinedSlipWheel2DOF_BREFF *
      lam_Cz_0) * localP->CombinedSlipWheel2DOF_DREFF +
      localP->CombinedSlipWheel2DOF_FREFF * lam_Cz_0) *
      (AdasPlantModel0_P->PlntWhlNomNorlForce / localB->Re[3]);
    for (i = 0; i < 4; i++) {
      if (localB->Re[i] < 0.001) {
        localB->Re[i] = 0.001;
      }
    }

    rtb_Saturation_0 = std::fmax(R_omega[0] -
      (AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Saturation[0]), 0.0) /
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[0] = rtb_Saturation_0;
    localB->a[0] = rtb_Saturation_0;
    localB->a[0] = std::sqrt(localB->a[0]);
    localB->a[0] = (localP->MagicTireConstInput_Q_RA2 * rtb_Saturation_0 +
                    localP->MagicTireConstInput_Q_RA1 * localB->a[0]) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[0] = (localP->MagicTireConstInput_Q_RB2 * localB->b[0] +
                    localP->MagicTireConstInput_Q_RB1 * rt_powd_snf(localB->b[0],
      0.33333333333333331)) * AdasPlantModel0_P->PlntWhlWidth;
    rtb_Saturation_0 = std::fmax(R_omega[1] -
      (AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Saturation[1]), 0.0) /
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[1] = rtb_Saturation_0;
    localB->a[1] = rtb_Saturation_0;
    localB->a[1] = std::sqrt(localB->a[1]);
    localB->a[1] = (localP->MagicTireConstInput_Q_RA2 * rtb_Saturation_0 +
                    localP->MagicTireConstInput_Q_RA1 * localB->a[1]) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[1] = (localP->MagicTireConstInput_Q_RB2 * localB->b[1] +
                    localP->MagicTireConstInput_Q_RB1 * rt_powd_snf(localB->b[1],
      0.33333333333333331)) * AdasPlantModel0_P->PlntWhlWidth;
    rtb_Saturation_0 = std::fmax(R_omega[2] -
      (AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Saturation[2]), 0.0) /
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[2] = rtb_Saturation_0;
    localB->a[2] = rtb_Saturation_0;
    localB->a[2] = std::sqrt(localB->a[2]);
    localB->a[2] = (localP->MagicTireConstInput_Q_RA2 * rtb_Saturation_0 +
                    localP->MagicTireConstInput_Q_RA1 * localB->a[2]) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[2] = (localP->MagicTireConstInput_Q_RB2 * localB->b[2] +
                    localP->MagicTireConstInput_Q_RB1 * rt_powd_snf(localB->b[2],
      0.33333333333333331)) * AdasPlantModel0_P->PlntWhlWidth;
    rtb_Saturation_0 = std::fmax(R_omega_0 -
      (AdasPlantModel0_P->PlntWhlUnldRadius + rtb_Saturation[3]), 0.0) /
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[3] = rtb_Saturation_0;
    localB->a[3] = rtb_Saturation_0;
    localB->a[3] = std::sqrt(localB->a[3]);
    localB->a[3] = (localP->MagicTireConstInput_Q_RA2 * rtb_Saturation_0 +
                    localP->MagicTireConstInput_Q_RA1 * localB->a[3]) *
      AdasPlantModel0_P->PlntWhlUnldRadius;
    localB->b[3] = (localP->MagicTireConstInput_Q_RB2 * localB->b[3] +
                    localP->MagicTireConstInput_Q_RB1 * rt_powd_snf(localB->b[3],
      0.33333333333333331)) * AdasPlantModel0_P->PlntWhlWidth;
    localB->Kappa[0] = (localB->Re[0] * rty_VehFdbk_c[0] - localB->Reshape1[0]) /
      Vsy[0];
    localB->Kappa[1] = (localB->Re[1] * rty_VehFdbk_c[1] - localB->Reshape1[1]) /
      Vsy[1];
    localB->Kappa[2] = (localB->Re[2] * rty_VehFdbk_c[2] - localB->Reshape1[2]) /
      Vsy[2];
    localB->Kappa[3] = (localB->Re[3] * rty_VehFdbk_c[3] - localB->Reshape1[3]) /
      Vsy[3];
    localB->Alpha[0] = rt_atan2d_snf(localB->Reshape2[0], Vsy[0]);
    localB->Alpha[1] = rt_atan2d_snf(localB->Reshape2[1], Vsy[1]);
    localB->Alpha[2] = rt_atan2d_snf(localB->Reshape2[2], Vsy[2]);
    localB->Alpha[3] = rt_atan2d_snf(localB->Reshape2[3], Vsy[3]);
    for (i = 0; i < 4; i++) {
      rtb_Saturation_0 = localB->Kappa[i];
      if (rtb_Saturation_0 < AdasPlantModel0_P->PlntWhlMinSlipRatio) {
        rtb_Saturation_0 = AdasPlantModel0_P->PlntWhlMinSlipRatio;
        localB->Kappa[i] = AdasPlantModel0_P->PlntWhlMinSlipRatio;
      }

      if (rtb_Saturation_0 > AdasPlantModel0_P->PlntWhlMaxSlipRatio) {
        localB->Kappa[i] = AdasPlantModel0_P->PlntWhlMaxSlipRatio;
      }

      rtb_Saturation_0 = localB->Alpha[i];
      if (rtb_Saturation_0 < AdasPlantModel0_P->PlntWhlMinSlipAngle) {
        rtb_Saturation_0 = AdasPlantModel0_P->PlntWhlMinSlipAngle;
        localB->Alpha[i] = AdasPlantModel0_P->PlntWhlMinSlipAngle;
      }

      if (rtb_Saturation_0 > AdasPlantModel0_P->PlntWhlMaxSlipAngle) {
        localB->Alpha[i] = AdasPlantModel0_P->PlntWhlMaxSlipAngle;
      }
    }

    rtb_My[0] = (localP->MagicTireConstInput_PHX2 * dfz[0] +
                 localP->MagicTireConstInput_PHX1) * localB->
      VectorConcatenate_e[10] + localB->Kappa[0];
    rtb_My[1] = (localP->MagicTireConstInput_PHX2 * dfz[1] +
                 localP->MagicTireConstInput_PHX1) * localB->
      VectorConcatenate_e[37] + localB->Kappa[1];
    rtb_My[2] = (localP->MagicTireConstInput_PHX2 * dfz[2] +
                 localP->MagicTireConstInput_PHX1) * localB->
      VectorConcatenate_e[64] + localB->Kappa[2];
    rtb_My[3] = (localP->MagicTireConstInput_PHX2 * rtb_Product_py +
                 localP->MagicTireConstInput_PHX1) * localB->
      VectorConcatenate_e[91] + localB->Kappa[3];
    rtb_Divide_pl = std::sin(rtb_sig_x[0]);
    rtb_Saturation[0] = rtb_Divide_pl;
    rtb_Sum1_m = -Vsy[0] * localB->Kappa[0];
    rtb_UnaryMinus2_idx_0 = -Vsy[0] * std::tan(localB->Alpha[0]);
    rtb_Saturation_0 = rtb_UnaryMinus2_idx_0 * rtb_UnaryMinus2_idx_0;
    R_omega[0] = std::sqrt(localB->Reshape1[0] * localB->Reshape1[0] +
      rtb_Saturation_0);
    rtb_UnaryMinus2_idx_0 = std::sqrt(rtb_Sum1_m * rtb_Sum1_m + rtb_Saturation_0)
      * localB->VectorConcatenate_e[3] / AdasPlantModel0_P->PlntWhlLongSpd + 1.0;
    rtb_sig_y[0] = rtb_UnaryMinus2_idx_0;
    rtb_ImpAsg_InsertedFor_ydotWhee[0] /= rtb_UnaryMinus2_idx_0;
    rtb_Saturation_tmp = std::sin(rtb_sig_x[1]);
    rtb_Saturation[1] = rtb_Saturation_tmp;
    rtb_Sum1_m = -Vsy[1] * localB->Kappa[1];
    rtb_Smallangleapproximationford = std::tan(localB->Alpha[1]);
    rtb_UnaryMinus2_idx_0 = -Vsy[1] * rtb_Smallangleapproximationford;
    rtb_Saturation_0 = rtb_UnaryMinus2_idx_0 * rtb_UnaryMinus2_idx_0;
    R_omega[1] = std::sqrt(localB->Reshape1[1] * localB->Reshape1[1] +
      rtb_Saturation_0);
    rtb_UnaryMinus2_idx_0 = std::sqrt(rtb_Sum1_m * rtb_Sum1_m + rtb_Saturation_0)
      * localB->VectorConcatenate_e[30] / AdasPlantModel0_P->PlntWhlLongSpd +
      1.0;
    rtb_sig_y[1] = rtb_UnaryMinus2_idx_0;
    rtb_ImpAsg_InsertedFor_ydotWhee[1] /= rtb_UnaryMinus2_idx_0;
    rtb_Saturation_tmp_0 = std::sin(rtb_sig_x[2]);
    rtb_Saturation[2] = rtb_Saturation_tmp_0;
    rtb_Sum1_m = -Vsy[2] * localB->Kappa[2];
    rtb_Integrator1_p = std::tan(localB->Alpha[2]);
    rtb_UnaryMinus2_idx_0 = -Vsy[2] * rtb_Integrator1_p;
    rtb_Saturation_0 = rtb_UnaryMinus2_idx_0 * rtb_UnaryMinus2_idx_0;
    R_omega[2] = std::sqrt(localB->Reshape1[2] * localB->Reshape1[2] +
      rtb_Saturation_0);
    rtb_UnaryMinus2_idx_0 = std::sqrt(rtb_Sum1_m * rtb_Sum1_m + rtb_Saturation_0)
      * localB->VectorConcatenate_e[57] / AdasPlantModel0_P->PlntWhlLongSpd +
      1.0;
    rtb_sig_y[2] = rtb_UnaryMinus2_idx_0;
    rtb_ImpAsg_InsertedFor_ydotWhee[2] /= rtb_UnaryMinus2_idx_0;
    rtb_Saturation_tmp_1 = std::sin(rtb_sig_x[3]);
    rtb_Saturation[3] = rtb_Saturation_tmp_1;
    rtb_Sum1_m = -Vsy[3] * localB->Kappa[3];
    rtb_Switch_e1 = std::tan(localB->Alpha[3]);
    rtb_UnaryMinus2_idx_0 = -Vsy[3] * rtb_Switch_e1;
    rtb_Saturation_0 = rtb_UnaryMinus2_idx_0 * rtb_UnaryMinus2_idx_0;
    R_omega[3] = std::sqrt(localB->Reshape1[3] * localB->Reshape1[3] +
      rtb_Saturation_0);
    rtb_UnaryMinus2_idx_0 = std::sqrt(rtb_Sum1_m * rtb_Sum1_m + rtb_Saturation_0)
      * localB->VectorConcatenate_e[84] / AdasPlantModel0_P->PlntWhlLongSpd +
      1.0;
    rtb_ImpAsg_InsertedFor_ydotWhee[3] /= rtb_UnaryMinus2_idx_0;
    AdasPlantModel0_div0protect(localB->Reshape1,
      AdasPlantModel0_P->PlntWhlVelTolLowVel, phi_t, lam_Cz);
    AdasPlantModel0_div0protect(R_omega, AdasPlantModel0_P->PlntWhlVelTolLowVel,
      cosprimealpha, lam_Cz);
    Dx_tmp = dpi_idx_0 * dpi_idx_0;
    rtb_Saturation_0 = lam_muy[0] / rtb_sig_y[0];
    lam_muy[0] = rtb_Saturation_0;
    lam_muy_prime_idx_0 = rtb_Saturation_0 * 10.0 / (9.0 * rtb_Saturation_0 +
      1.0);
    mu_y_tmp = rtb_Divide_pl * rtb_Divide_pl;
    rtb_Sum1_m = ((localP->MagicTireConstInput_PPY3 * dpi_idx_0 + 1.0) + Dx_tmp *
                  localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[0] +
       localP->MagicTireConstInput_PDY1) * (1.0 - mu_y_tmp *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_0;
    phi_t[0] = -localB->UnaryMinus[0] / phi_t[0] * std::cos(localB->Alpha[0]);
    Dx_tmp_0 = dpi_idx_1 * dpi_idx_1;
    rtb_Saturation_0 = lam_muy[1] / rtb_sig_y[1];
    lam_muy[1] = rtb_Saturation_0;
    lam_muy_prime_idx_1 = rtb_Saturation_0 * 10.0 / (9.0 * rtb_Saturation_0 +
      1.0);
    mu_y_tmp_0 = rtb_Saturation_tmp * rtb_Saturation_tmp;
    rtb_Gain1_g0 = ((localP->MagicTireConstInput_PPY3 * dpi_idx_1 + 1.0) +
                    Dx_tmp_0 * localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[1] +
       localP->MagicTireConstInput_PDY1) * (1.0 - mu_y_tmp_0 *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_0;
    phi_t[1] = -localB->UnaryMinus[1] / phi_t[1] * std::cos(localB->Alpha[1]);
    mu_y_idx_0 = dpi_idx_2 * dpi_idx_2;
    rtb_Saturation_0 = lam_muy[2] / rtb_sig_y[2];
    lam_muy[2] = rtb_Saturation_0;
    rtb_FrontBiasGain = rtb_Saturation_0 * 10.0 / (9.0 * rtb_Saturation_0 + 1.0);
    mu_y_tmp_1 = rtb_Saturation_tmp_0 * rtb_Saturation_tmp_0;
    mu_y_idx_2 = ((localP->MagicTireConstInput_PPY3 * dpi_idx_2 + 1.0) +
                  mu_y_idx_0 * localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[2] +
       localP->MagicTireConstInput_PDY1) * (1.0 - mu_y_tmp_1 *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_0;
    phi_t[2] = -localB->UnaryMinus[2] / phi_t[2] * std::cos(localB->Alpha[2]);
    mu_y_idx_1 = dpi_idx_3 * dpi_idx_3;
    rtb_Saturation_0 = lam_muy[3] / rtb_UnaryMinus2_idx_0;
    lam_muy_prime_idx_3 = rtb_Saturation_0 * 10.0 / (9.0 * rtb_Saturation_0 +
      1.0);
    mu_y_tmp_2 = rtb_Saturation_tmp_1 * rtb_Saturation_tmp_1;
    mu_y = ((localP->MagicTireConstInput_PPY3 * dpi_idx_3 + 1.0) + mu_y_idx_1 *
            localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * rtb_Product_py +
       localP->MagicTireConstInput_PDY1) * (1.0 - mu_y_tmp_2 *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_0;
    phi_t[3] = -localB->UnaryMinus[3] / phi_t[3] * std::cos(localB->Alpha[3]);
    iy = 0;
    for (i = 0; i < 4; i++) {
      if (localB->Reshape1[i] < AdasPlantModel0_P->PlntWhlVelTolLowVel) {
        iy++;
      }
    }

    ibmat = 0;
    for (i = 0; i < 4; i++) {
      if (localB->Reshape1[i] < AdasPlantModel0_P->PlntWhlVelTolLowVel) {
        tmp_data_0[ibmat] = i;
        ibmat++;
      }
    }

    for (i = 0; i < iy; i++) {
      rtb_Saturation_data_0[i] = localB->Reshape1[tmp_data_0[i]];
    }

    AdasPlantModel0_abs(rtb_Saturation_data_0, &iy, phi, &Itemp_tmp);
    if (iy == Itemp_tmp) {
      for (i = 0; i < iy; i++) {
        rtb_Saturation_data_0[i] = localB->Reshape1[tmp_data_0[i]];
      }

      AdasPlantModel0_abs(rtb_Saturation_data_0, &iy, rtb_Saturation_data,
                          &Itemp_tmp);
      for (i = 0; i < iy; i++) {
        rtb_Saturation_data_0[i] = rtb_Saturation_data[i] /
          AdasPlantModel0_P->PlntWhlVelTolLowVel * phi_t[tmp_data_0[i]];
      }

      for (i = 0; i < iy; i++) {
        phi_t[tmp_data_0[i]] = rtb_Saturation_data_0[i];
      }
    } else {
      AdasPlant_binary_expand_op_nxej(phi_t, tmp_data_0, &iy, localB->Reshape1,
        AdasPlantModel0_P->PlntWhlVelTolLowVel);
    }

    d_y[0] = std::abs(rty_VehFdbk_c[0]);
    d_y[1] = std::abs(rty_VehFdbk_c[1]);
    d_y[2] = std::abs(rty_VehFdbk_c[2]);
    d_y[3] = std::abs(rty_VehFdbk_c[3]);
    AdasPlantModel0_div0protect_f(R_omega, rtb_Saturation_data);
    phi[0] = ((1.0 - epsilon_gamma[0]) * d_y[0] * rtb_Divide_pl +
              localB->UnaryMinus[0]) * (1.0 / rtb_Saturation_data[0]);
    phi[1] = ((1.0 - epsilon_gamma[1]) * d_y[1] * rtb_Saturation_tmp +
              localB->UnaryMinus[1]) * (1.0 / rtb_Saturation_data[1]);
    phi[2] = ((1.0 - epsilon_gamma[2]) * d_y[2] * rtb_Saturation_tmp_0 +
              localB->UnaryMinus[2]) * (1.0 / rtb_Saturation_data[2]);
    phi[3] = ((1.0 - epsilon_gamma[3]) * d_y[3] * rtb_Saturation_tmp_1 +
              localB->UnaryMinus[3]) * (1.0 / rtb_Saturation_data[3]);
    if (localP->CombinedSlipWheel2DOF_turnslip == 1.0) {
      tempInds[0] = (std::abs(phi[0]) > 0.01);
      tempInds[1] = (std::abs(phi[1]) > 0.01);
      tempInds[2] = (std::abs(phi[2]) > 0.01);
      tempInds[3] = (std::abs(phi[3]) > 0.01);
    } else {
      tempInds[0] = false;
      tempInds[1] = false;
      tempInds[2] = false;
      tempInds[3] = false;
    }

    nomslipinds[0] = !tempInds[0];
    SHykappa[0] = localP->MagicTireConstInput_RHY2 * dfz[0] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[0] = localP->MagicTireConstInput_REY2 * dfz[0] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[1] = !tempInds[1];
    SHykappa[1] = localP->MagicTireConstInput_RHY2 * dfz[1] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[1] = localP->MagicTireConstInput_REY2 * dfz[1] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[2] = !tempInds[2];
    SHykappa[2] = localP->MagicTireConstInput_RHY2 * dfz[2] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[2] = localP->MagicTireConstInput_REY2 * dfz[2] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[3] = !tempInds[3];
    SHykappa[3] = localP->MagicTireConstInput_RHY2 * rtb_Product_py +
      localP->MagicTireConstInput_RHY1;
    Eykappa[3] = localP->MagicTireConstInput_REY2 * rtb_Product_py +
      localP->MagicTireConstInput_REY1;
    Bykappa[0] = (mu_y_tmp * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * localB->Alpha[0])) *
      localB->VectorConcatenate_e[19];
    Bykappa[1] = (mu_y_tmp_0 * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * localB->Alpha[1])) *
      localB->VectorConcatenate_e[46];
    Bykappa[2] = (mu_y_tmp_1 * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * localB->Alpha[2])) *
      localB->VectorConcatenate_e[73];
    Bykappa[3] = (mu_y_tmp_2 * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * localB->Alpha[3])) *
      localB->VectorConcatenate_e[100];
    for (i = 0; i < 4; i++) {
      if (Eykappa[i] > 1.0) {
        Eykappa[i] = 1.0;
      }

      if (Bykappa[i] < 0.0) {
        Bykappa[i] = 0.0;
      }
    }

    for (i = 0; i < 36; i++) {
      zeta[i] = 1.0;
    }

    iy = 0;
    for (i = 0; i < 4; i++) {
      if (tempInds[i]) {
        iy++;
      }
    }

    rtb_Saturation_size = iy;
    ibmat = 0;
    for (i = 0; i < 4; i++) {
      if (tempInds[i]) {
        bc_tmp_data[ibmat] = i;
        ibmat++;
      }
    }

    for (i = 0; i < iy; i++) {
      bc_data[i] = static_cast<int8_T>(bc_tmp_data[i]);
    }

    for (i = 0; i < iy; i++) {
      zeta[9 * bc_data[i]] = 0.0;
    }

    rtb_RelationalOperator = AdasPlantModel0_any(tempInds);
    if (rtb_RelationalOperator) {
      b_x[0] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 *
        localB->Kappa[0]));
      lam_Cz[0] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 * std::
        tan(localB->Alpha[0])));
      b_x[1] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 *
        localB->Kappa[1]));
      lam_Cz[1] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        rtb_Smallangleapproximationford));
      b_x[2] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 *
        localB->Kappa[2]));
      lam_Cz[2] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        rtb_Integrator1_p));
      b_x[3] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 *
        localB->Kappa[3]));
      lam_Cz[3] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        rtb_Switch_e1));
      Itemp_tmp = iy;
      ibmat = iy;
      for (i = 0; i < ibmat; i++) {
        iy = bc_tmp_data[i];
        rtb_Saturation_data[i] = (localP->MagicTireConstInput_PDXP2 * dfz[iy] +
          1.0) * localP->MagicTireConstInput_PDXP1 * b_x[iy] *
          AdasPlantModel0_P->PlntWhlUnldRadius * phi[iy];
      }

      AdasPlantModel0_atan(rtb_Saturation_data, &Itemp_tmp);
      AdasPlantModel0_cos(rtb_Saturation_data, &Itemp_tmp);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 1] = rtb_Saturation_data[i];
        tmpDrphiVar_data[i] = phi[bc_tmp_data[i]];
      }

      AdasPlantModel0_abs(tmpDrphiVar_data, &rtb_Saturation_size,
                          rtb_Saturation_data_0, &ibmat);
      for (i = 0; i < ibmat; i++) {
        rtb_Saturation_data[i] = AdasPlantModel0_P->PlntWhlUnldRadius *
          rtb_Saturation_data_0[i];
      }

      if (ibmat - 1 >= 0) {
        std::memcpy(&tmpDrphiVar_data[0], &rtb_Saturation_data[0],
                    static_cast<uint32_T>(ibmat) * sizeof(real_T));
      }

      AdasPlantModel0_sqrt_h(tmpDrphiVar_data, &ibmat);
      if ((ibmat == ibmat) && ((ibmat == 1 ? ibmat : ibmat) ==
           rtb_Saturation_size)) {
        for (i = 0; i < rtb_Saturation_size; i++) {
          iy = bc_tmp_data[i];
          dc_data[i] = (localP->MagicTireConstInput_PDYP2 * dfz[iy] + 1.0) *
            localP->MagicTireConstInput_PDYP1 * lam_Cz[iy] *
            (localP->MagicTireConstInput_PDYP4 * tmpDrphiVar_data[i] +
             rtb_Saturation_data[i]);
        }
      } else {
        AdasPlantM_binary_expand_op_nxe(dc_data, &Itemp_tmp,
          localP->MagicTireConstInput_PDYP1, localP->MagicTireConstInput_PDYP2,
          dfz, lam_Cz, bc_tmp_data, &rtb_Saturation_size, rtb_Saturation_data,
          &ibmat, localP->MagicTireConstInput_PDYP4, tmpDrphiVar_data, &ibmat);
      }

      AdasPlantModel0_atan(dc_data, &Itemp_tmp);
      AdasPlantModel0_cos(dc_data, &Itemp_tmp);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 2] = dc_data[i];
      }

      rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntWhlUnldRadius *
        AdasPlantModel0_P->PlntWhlUnldRadius * localP->MagicTireConstInput_PKYP1;
      for (i = 0; i < rtb_Saturation_size; i++) {
        rtb_Product_py = phi[bc_tmp_data[i]];
        rtb_Saturation_data[i] = rtb_Product_py * rtb_Product_py *
          rtb_UnaryMinus2_idx_0;
      }

      AdasPlantModel0_atan(rtb_Saturation_data, &rtb_Saturation_size);
      AdasPlantModel0_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 3] = rtb_Saturation_data[i];
      }
    }

    rtb_UnaryMinus2_idx_0 = 1.0 - localP->MagicTireConstInput_PKY3 * 0.0;
    Kygammao[0] = (localP->MagicTireConstInput_PKY7 * dfz[0] +
                   localP->MagicTireConstInput_PKY6) * rtb_Product[0] *
      (localP->MagicTireConstInput_PPY5 * dpi_idx_0 + 1.0) *
      localB->VectorConcatenate_e[14];
    lam_Cz_0 = rtb_Product[0] / Fzo_prime_idx_0;
    Mzphiinf[0] = lam_Cz_0;
    R_omega_0 = (localP->MagicTireConstInput_PPY1 * dpi_idx_0 + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_0);
    Kyalpha_tmp_tmp = std::sin(std::atan(lam_Cz_0 / (mu_y_tmp *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi_idx_0 + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_Product_py = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
                      (rtb_Divide_pl)) * R_omega_0 * Kyalpha_tmp_tmp * zeta[3] *
      localB->VectorConcatenate_e[5];
    Kyalpha[0] = rtb_Product_py;
    rtb_ImpAsg_InsertedFor_xdotWhee[0] = R_omega_0 * rtb_UnaryMinus2_idx_0 *
      Kyalpha_tmp_tmp * zeta[3] * localB->VectorConcatenate_e[5];
    Kygammao[1] = (localP->MagicTireConstInput_PKY7 * dfz[1] +
                   localP->MagicTireConstInput_PKY6) * rtb_Product[1] *
      (localP->MagicTireConstInput_PPY5 * dpi_idx_1 + 1.0) *
      localB->VectorConcatenate_e[41];
    lam_Cz_0 = rtb_Product[1] / Fzo_prime_idx_1;
    Mzphiinf[1] = lam_Cz_0;
    R_omega_0 = (localP->MagicTireConstInput_PPY1 * dpi_idx_1 + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_1);
    Kyalpha_tmp_tmp = std::sin(std::atan(lam_Cz_0 / (mu_y_tmp_0 *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi_idx_1 + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_Smallangleapproximationford = (1.0 - localP->MagicTireConstInput_PKY3 *
      std::abs(rtb_Saturation_tmp)) * R_omega_0 * Kyalpha_tmp_tmp * zeta[12] *
      localB->VectorConcatenate_e[32];
    Kyalpha[1] = rtb_Smallangleapproximationford;
    rtb_ImpAsg_InsertedFor_xdotWhee[1] = R_omega_0 * rtb_UnaryMinus2_idx_0 *
      Kyalpha_tmp_tmp * zeta[12] * localB->VectorConcatenate_e[32];
    Kygammao[2] = (localP->MagicTireConstInput_PKY7 * dfz[2] +
                   localP->MagicTireConstInput_PKY6) * rtb_Product[2] *
      (localP->MagicTireConstInput_PPY5 * dpi_idx_2 + 1.0) *
      localB->VectorConcatenate_e[68];
    lam_Cz_0 = rtb_Product[2] / Fzo_prime_idx_2;
    Mzphiinf[2] = lam_Cz_0;
    R_omega_0 = (localP->MagicTireConstInput_PPY1 * dpi_idx_2 + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_2);
    Kyalpha_tmp_tmp = std::sin(std::atan(lam_Cz_0 / (mu_y_tmp_1 *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi_idx_2 + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_Integrator1_p = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
                         (rtb_Saturation_tmp_0)) * R_omega_0 * Kyalpha_tmp_tmp *
      zeta[21] * localB->VectorConcatenate_e[59];
    Kyalpha[2] = rtb_Integrator1_p;
    rtb_ImpAsg_InsertedFor_xdotWhee[2] = R_omega_0 * rtb_UnaryMinus2_idx_0 *
      Kyalpha_tmp_tmp * zeta[21] * localB->VectorConcatenate_e[59];
    Kygammao[3] = (localP->MagicTireConstInput_PKY7 * dfz[3] +
                   localP->MagicTireConstInput_PKY6) * rtb_Product[3] *
      (localP->MagicTireConstInput_PPY5 * dpi_idx_3 + 1.0) *
      localB->VectorConcatenate_e[95];
    lam_Cz_0 = rtb_Product[3] / Fzo_prime_idx_3;
    R_omega_0 = (localP->MagicTireConstInput_PPY1 * dpi_idx_3 + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_3);
    Kyalpha_tmp_tmp = std::sin(std::atan(lam_Cz_0 / (mu_y_tmp_2 *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi_idx_3 + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_Switch_e1 = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
                     (rtb_Saturation_tmp_1)) * R_omega_0 * Kyalpha_tmp_tmp *
      zeta[30] * localB->VectorConcatenate_e[86];
    Kyalpha[3] = rtb_Switch_e1;
    rtb_ImpAsg_InsertedFor_xdotWhee[3] = R_omega_0 * rtb_UnaryMinus2_idx_0 *
      Kyalpha_tmp_tmp * zeta[30] * localB->VectorConcatenate_e[86];
    AdasPlantModel0_div0protect(Kyalpha, 0.0001, b_x, lam_Cz);
    AdasPlantModel0_div0protect(rtb_ImpAsg_InsertedFor_xdotWhee, 0.0001, Vsy,
      lam_Cz);
    x_idx_0 = localP->MagicTireConstInput_PHYP1;
    if (localP->MagicTireConstInput_PHYP1 < 0.0) {
      x_idx_0 = 0.0;
    }

    rtb_UnaryMinus2_idx_0 = std::tanh(localB->Reshape1[0]);
    lam_Cz[0] = (localP->MagicTireConstInput_PHYP3 * dfz[0] +
                 localP->MagicTireConstInput_PHYP2) * rtb_UnaryMinus2_idx_0;
    R_omega_0 = std::tanh(localB->Reshape1[1]);
    lam_Cz[1] = (localP->MagicTireConstInput_PHYP3 * dfz[1] +
                 localP->MagicTireConstInput_PHYP2) * R_omega_0;
    Kyalpha_tmp_tmp = std::tanh(localB->Reshape1[2]);
    lam_Cz[2] = (localP->MagicTireConstInput_PHYP3 * dfz[2] +
                 localP->MagicTireConstInput_PHYP2) * Kyalpha_tmp_tmp;
    lam_Cz_tmp_tmp = std::tanh(localB->Reshape1[3]);
    lam_Cz_tmp = (localP->MagicTireConstInput_PHYP3 * dfz[3] +
                  localP->MagicTireConstInput_PHYP2) * lam_Cz_tmp_tmp;
    lam_Cz[3] = lam_Cz_tmp;
    ab_idx_0 = localP->MagicTireConstInput_PHYP4;
    if (localP->MagicTireConstInput_PHYP4 > 1.0) {
      ab_idx_0 = 1.0;
    }

    rtb_sig_y[0] = AdasPlantModel0_P->PlntWhlUnldRadius * phi[0];
    rtb_ImpAsg_InsertedFor_xdotWhee[0] = Kygammao[0] / (1.0 - epsilon_gamma[0]) /
      (x_idx_0 * lam_Cz[0] * Vsy[0]);
    rtb_sig_y[1] = AdasPlantModel0_P->PlntWhlUnldRadius * phi[1];
    rtb_ImpAsg_InsertedFor_xdotWhee[1] = Kygammao[1] / (1.0 - epsilon_gamma[1]) /
      (x_idx_0 * lam_Cz[1] * Vsy[1]);
    rtb_sig_y[2] = AdasPlantModel0_P->PlntWhlUnldRadius * phi[2];
    rtb_ImpAsg_InsertedFor_xdotWhee[2] = Kygammao[2] / (1.0 - epsilon_gamma[2]) /
      (x_idx_0 * lam_Cz[2] * Vsy[2]);
    rtb_sig_y[3] = AdasPlantModel0_P->PlntWhlUnldRadius * phi[3];
    rtb_ImpAsg_InsertedFor_xdotWhee[3] = Kygammao[3] / (1.0 - epsilon_gamma[3]) /
      (lam_Cz_tmp * x_idx_0 * Vsy[3]);
    AdasPlantModel0_magicsin(lam_Cz, x_idx_0, rtb_ImpAsg_InsertedFor_xdotWhee,
      ab_idx_0, rtb_sig_y, rtb_Saturation_data);
    Vsy[0] = rtb_Saturation_data[0] * rtb_UnaryMinus2_idx_0;
    Kyalpha[0] = (localP->MagicTireConstInput_PVY4 * dfz[0] +
                  localP->MagicTireConstInput_PVY3) * rtb_Product[0] *
      rtb_Divide_pl * zeta[2] * localB->VectorConcatenate_e[14] *
      lam_muy_prime_idx_0;
    SHy[0] = 0.0;
    d_y[0] = localB->Kappa[0] + SHykappa[0];
    Vsy[1] = rtb_Saturation_data[1] * R_omega_0;
    Kyalpha[1] = (localP->MagicTireConstInput_PVY4 * dfz[1] +
                  localP->MagicTireConstInput_PVY3) * rtb_Product[1] *
      rtb_Saturation_tmp * zeta[11] * localB->VectorConcatenate_e[41] *
      lam_muy_prime_idx_1;
    SHy[1] = 0.0;
    d_y[1] = localB->Kappa[1] + SHykappa[1];
    Vsy[2] = rtb_Saturation_data[2] * Kyalpha_tmp_tmp;
    Kyalpha[2] = (localP->MagicTireConstInput_PVY4 * dfz[2] +
                  localP->MagicTireConstInput_PVY3) * rtb_Product[2] *
      rtb_Saturation_tmp_0 * zeta[20] * localB->VectorConcatenate_e[68] *
      rtb_FrontBiasGain;
    SHy[2] = 0.0;
    d_y[2] = localB->Kappa[2] + SHykappa[2];
    Vsy[3] = rtb_Saturation_data[3] * lam_Cz_tmp_tmp;
    Kyalpha[3] = (localP->MagicTireConstInput_PVY4 * dfz[3] +
                  localP->MagicTireConstInput_PVY3) * rtb_Product[3] *
      rtb_Saturation_tmp_1 * zeta[29] * localB->VectorConcatenate_e[95] *
      lam_muy_prime_idx_3;
    SHy[3] = 0.0;
    d_y[3] = localB->Kappa[3] + SHykappa[3];
    AdasPlantModel0_magiccos(localP->MagicTireConstInput_RCY1, Bykappa, Eykappa,
      d_y, rtb_Saturation_data);
    AdasPlantModel0_magiccos(localP->MagicTireConstInput_RCY1, Bykappa, Eykappa,
      SHykappa, d_y);
    rtb_ImpAsg_InsertedFor_xdotWhee[0] = rtb_Saturation_data[0] / d_y[0];
    rtb_ImpAsg_InsertedFor_xdotWhee[1] = rtb_Saturation_data[1] / d_y[1];
    rtb_ImpAsg_InsertedFor_xdotWhee[2] = rtb_Saturation_data[2] / d_y[2];
    rtb_ImpAsg_InsertedFor_xdotWhee[3] = rtb_Saturation_data[3] / d_y[3];
    for (i = 0; i < 4; i++) {
      if (rtb_ImpAsg_InsertedFor_xdotWhee[i] < 0.0) {
        rtb_ImpAsg_InsertedFor_xdotWhee[i] = 0.0;
      }
    }

    if (rtb_RelationalOperator) {
      for (i = 0; i < rtb_Saturation_size; i++) {
        iy = bc_tmp_data[i];
        zeta[9 * bc_data[i] + 4] = (Vsy[iy] + 1.0) - Kyalpha[iy] / b_x[iy];
      }

      rtb_UnaryMinus2_idx_0 = localP->MagicTireConstInput_QDTP1 *
        AdasPlantModel0_P->PlntWhlUnldRadius;
      for (i = 0; i < rtb_Saturation_size; i++) {
        rtb_Saturation_data[i] = rtb_UnaryMinus2_idx_0 * phi[bc_tmp_data[i]];
      }

      AdasPlantModel0_atan(rtb_Saturation_data, &rtb_Saturation_size);
      AdasPlantModel0_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 5] = rtb_Saturation_data[i];
      }

      rtb_UnaryMinus2_idx_0 = localP->MagicTireConstInput_QBRP1 *
        AdasPlantModel0_P->PlntWhlUnldRadius;
      for (i = 0; i < rtb_Saturation_size; i++) {
        rtb_Saturation_data[i] = rtb_UnaryMinus2_idx_0 * phi[bc_tmp_data[i]];
      }

      AdasPlantModel0_atan(rtb_Saturation_data, &rtb_Saturation_size);
      AdasPlantModel0_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 6] = rtb_Saturation_data[i];
      }

      Mzphiinf[0] = localP->MagicTireConstInput_QCRP1 * rtb_Sum1_m *
        AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[0] * std::sqrt
        (Mzphiinf[0]) * localB->VectorConcatenate_e[26];
      Mzphiinf[1] = localP->MagicTireConstInput_QCRP1 * rtb_Gain1_g0 *
        AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[1] * std::sqrt
        (Mzphiinf[1]) * localB->VectorConcatenate_e[53];
      Mzphiinf[2] = localP->MagicTireConstInput_QCRP1 * mu_y_idx_2 *
        AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[2] * std::sqrt
        (Mzphiinf[2]) * localB->VectorConcatenate_e[80];
      Mzphiinf[3] = localP->MagicTireConstInput_QCRP1 * mu_y *
        AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[3] * std::sqrt
        (lam_Cz_0) * localB->VectorConcatenate_e[107];
      for (i = 0; i < 4; i++) {
        if (Mzphiinf[i] < 0.0) {
          Mzphiinf[i] = 1.0E-6;
        }
      }

      rtb_UnaryMinus2_idx_0 = localP->MagicTireConstInput_QCRP2 *
        AdasPlantModel0_P->PlntWhlUnldRadius;
      d_y[0] = std::atan(rtb_UnaryMinus2_idx_0 * std::abs(phi_t[0]));
      d_y[1] = std::atan(rtb_UnaryMinus2_idx_0 * std::abs(phi_t[1]));
      d_y[2] = std::atan(rtb_UnaryMinus2_idx_0 * std::abs(phi_t[2]));
      d_y[3] = std::atan(rtb_UnaryMinus2_idx_0 * std::abs(phi_t[3]));
      rtb_Saturation_tmp = localP->MagicTireConstInput_QDRP1;
      if (localP->MagicTireConstInput_QDRP1 < 0.0) {
        rtb_Saturation_tmp = 0.0;
      }

      rtb_Saturation_tmp_0 = localP->MagicTireConstInput_QDRP2;
      if (localP->MagicTireConstInput_QDRP2 < 0.0) {
        rtb_Saturation_tmp_0 = 0.0;
      }

      rtb_Divide_pl = std::sin(1.5707963267948966 * rtb_Saturation_tmp);
      lam_Cz_0 = Mzphiinf[0] / rtb_Divide_pl;
      lam_Cz[0] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[0])) {
        rtb_UnaryMinus2_idx_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[0] < 0.0) {
        rtb_UnaryMinus2_idx_0 = -1.0;
      } else {
        rtb_UnaryMinus2_idx_0 = (1.0 - epsilon_gamma[0] > 0.0);
      }

      Eykappa[0] = ((localP->MagicTireConstInput_QDZ11 * dfz[0] +
                     localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[0])
                    + (localP->MagicTireConstInput_QDZ9 * dfz[0] +
                       localP->MagicTireConstInput_QDZ8)) * (rtb_Product[0] *
        AdasPlantModel0_P->PlntWhlUnldRadius) * localB->VectorConcatenate_e[15] /
        (rtb_Saturation_tmp * lam_Cz_0 * (1.0 - epsilon_gamma[0]) + 0.0001 *
         rtb_UnaryMinus2_idx_0);
      lam_Cz_0 = Mzphiinf[1] / rtb_Divide_pl;
      lam_Cz[1] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[1])) {
        rtb_UnaryMinus2_idx_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[1] < 0.0) {
        rtb_UnaryMinus2_idx_0 = -1.0;
      } else {
        rtb_UnaryMinus2_idx_0 = (1.0 - epsilon_gamma[1] > 0.0);
      }

      Eykappa[1] = ((localP->MagicTireConstInput_QDZ11 * dfz[1] +
                     localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[1])
                    + (localP->MagicTireConstInput_QDZ9 * dfz[1] +
                       localP->MagicTireConstInput_QDZ8)) * (rtb_Product[1] *
        AdasPlantModel0_P->PlntWhlUnldRadius) * localB->VectorConcatenate_e[42] /
        (rtb_Saturation_tmp * lam_Cz_0 * (1.0 - epsilon_gamma[1]) + 0.0001 *
         rtb_UnaryMinus2_idx_0);
      lam_Cz_0 = Mzphiinf[2] / rtb_Divide_pl;
      lam_Cz[2] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[2])) {
        rtb_UnaryMinus2_idx_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[2] < 0.0) {
        rtb_UnaryMinus2_idx_0 = -1.0;
      } else {
        rtb_UnaryMinus2_idx_0 = (1.0 - epsilon_gamma[2] > 0.0);
      }

      Eykappa[2] = ((localP->MagicTireConstInput_QDZ11 * dfz[2] +
                     localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[2])
                    + (localP->MagicTireConstInput_QDZ9 * dfz[2] +
                       localP->MagicTireConstInput_QDZ8)) * (rtb_Product[2] *
        AdasPlantModel0_P->PlntWhlUnldRadius) * localB->VectorConcatenate_e[69] /
        (rtb_Saturation_tmp * lam_Cz_0 * (1.0 - epsilon_gamma[2]) + 0.0001 *
         rtb_UnaryMinus2_idx_0);
      lam_Cz_0 = Mzphiinf[3] / rtb_Divide_pl;
      lam_Cz[3] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[3])) {
        rtb_UnaryMinus2_idx_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[3] < 0.0) {
        rtb_UnaryMinus2_idx_0 = -1.0;
      } else {
        rtb_UnaryMinus2_idx_0 = (1.0 - epsilon_gamma[3] > 0.0);
      }

      Eykappa[3] = ((localP->MagicTireConstInput_QDZ11 * dfz[3] +
                     localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[3])
                    + (localP->MagicTireConstInput_QDZ9 * dfz[3] +
                       localP->MagicTireConstInput_QDZ8)) * (rtb_Product[3] *
        AdasPlantModel0_P->PlntWhlUnldRadius) * localB->VectorConcatenate_e[96] /
        (rtb_Saturation_tmp * lam_Cz_0 * (1.0 - epsilon_gamma[3]) + 0.0001 *
         rtb_UnaryMinus2_idx_0);
      AdasPlantModel0_magicsin(lam_Cz, rtb_Saturation_tmp, Eykappa,
        rtb_Saturation_tmp_0, rtb_sig_y, R_omega);
      if (std::isnan(R_omega[0])) {
        lam_Cz[0] = (rtNaN);
      } else if (R_omega[0] < 0.0) {
        lam_Cz[0] = -1.0;
      } else {
        lam_Cz[0] = (R_omega[0] > 0.0);
      }

      if (std::isnan(R_omega[1])) {
        lam_Cz[1] = (rtNaN);
      } else if (R_omega[1] < 0.0) {
        lam_Cz[1] = -1.0;
      } else {
        lam_Cz[1] = (R_omega[1] > 0.0);
      }

      if (std::isnan(R_omega[2])) {
        lam_Cz[2] = (rtNaN);
      } else if (R_omega[2] < 0.0) {
        lam_Cz[2] = -1.0;
      } else {
        lam_Cz[2] = (R_omega[2] > 0.0);
      }

      if (std::isnan(R_omega[3])) {
        lam_Cz[3] = (rtNaN);
      } else if (R_omega[3] < 0.0) {
        lam_Cz[3] = -1.0;
      } else {
        lam_Cz[3] = (R_omega[3] > 0.0);
      }

      for (i = 0; i < 4; i++) {
        if (lam_Cz[i] == 0.0) {
          lam_Cz[i] = 1.0;
        }
      }

      for (i = 0; i < rtb_Saturation_size; i++) {
        iy = bc_tmp_data[i];
        dc_data[i] = R_omega[iy];
        rtb_Saturation_data[i] = R_omega[iy];
      }

      AdasPlantModel0_abs(rtb_Saturation_data, &rtb_Saturation_size,
                          rtb_Saturation_data_0, &ibmat);
      AdasPlantModel0_abs(dc_data, &rtb_Saturation_size, phi, &Itemp_tmp);
      if ((Itemp_tmp == rtb_Saturation_size) && ((ibmat == 1 ?
            rtb_Saturation_size : ibmat) == rtb_Saturation_size)) {
        for (i = 0; i < rtb_Saturation_size; i++) {
          dc_data[i] = R_omega[bc_tmp_data[i]];
        }

        AdasPlantModel0_abs(dc_data, &rtb_Saturation_size, rtb_Saturation_data_0,
                            &ibmat);
        ibmat = rtb_Saturation_size;
        for (i = 0; i < rtb_Saturation_size; i++) {
          iy = bc_tmp_data[i];
          tmpDrphiVar_data[i] = Mzphiinf[iy] * 2.0 / 3.1415926535897931 * d_y[iy]
            * rtb_ImpAsg_InsertedFor_xdotWhee[iy] / (0.0001 * lam_Cz[iy] +
            rtb_Saturation_data_0[i]);
        }
      } else {
        AdasPlantMo_binary_expand_op_nx(tmpDrphiVar_data, &ibmat, Mzphiinf, d_y,
          rtb_ImpAsg_InsertedFor_xdotWhee, bc_tmp_data, &rtb_Saturation_size,
          R_omega, lam_Cz);
      }

      iy = ibmat - 1;
      for (i = 0; i <= iy; i++) {
        if (tmpDrphiVar_data[i] > 1.0) {
          tmpDrphiVar_data[i] = 1.0;
        }

        if (tmpDrphiVar_data[i] < -1.0) {
          tmpDrphiVar_data[i] = -1.0;
        }
      }

      AdasPlantModel0_acos(tmpDrphiVar_data, &ibmat);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 7] = 0.63661977236758138 * tmpDrphiVar_data[i];
      }

      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 8] = R_omega[bc_tmp_data[i]] + 1.0;
      }

      iy = 0;
      for (i = 0; i < 4; i++) {
        if (tempInds[i]) {
          iy++;
        }
      }

      lb[0] = static_cast<int8_T>(iy);
      lb[1] = 1;
      i = rtb_Saturation_size == 1 ? static_cast<int32_T>(static_cast<int8_T>(iy))
        : rtb_Saturation_size;
      if ((rtb_Saturation_size == static_cast<int8_T>(iy)) && (i ==
           rtb_Saturation_size) && ((i == 1 ? rtb_Saturation_size : i) ==
           rtb_Saturation_size)) {
        for (i = 0; i < rtb_Saturation_size; i++) {
          iy = bc_tmp_data[i];
          SHy[bc_data[i]] = (localB->VectorConcatenate_e[27 * iy + 11] * (0.0 *
            dfz[iy]) + Vsy[iy]) - Kyalpha[iy] / b_x[iy];
        }
      } else {
        AdasPlantMod_binary_expand_op_n(SHy, bc_data, dfz, bc_tmp_data,
          &rtb_Saturation_size, localB->VectorConcatenate_e, lb, Vsy, Kyalpha,
          b_x);
      }
    }

    Eykappa[0] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate_e
      [6];
    Eykappa[1] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate_e
      [33];
    Eykappa[2] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate_e
      [60];
    Eykappa[3] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate_e
      [87];
    rtb_Divide_pl = rtb_sig_x[0] * rtb_sig_x[0];
    epsilon_gamma[0] = ((localP->MagicTireConstInput_PPX3 * dpi_idx_0 + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp) *
      (localP->MagicTireConstInput_PDX2 * dfz[0] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Divide_pl *
      localP->MagicTireConstInput_PDX3) * rtb_ImpAsg_InsertedFor_ydotWhee[0] *
      rtb_Product[0] * zeta[1];
    rtb_Saturation_tmp = rtb_sig_x[1] * rtb_sig_x[1];
    epsilon_gamma[1] = ((localP->MagicTireConstInput_PPX3 * dpi_idx_1 + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp_0) *
      (localP->MagicTireConstInput_PDX2 * dfz[1] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp *
      localP->MagicTireConstInput_PDX3) * rtb_ImpAsg_InsertedFor_ydotWhee[1] *
      rtb_Product[1] * zeta[10];
    rtb_Saturation_tmp_0 = rtb_sig_x[2] * rtb_sig_x[2];
    epsilon_gamma[2] = ((localP->MagicTireConstInput_PPX3 * dpi_idx_2 + 1.0) +
                        localP->MagicTireConstInput_PPX4 * mu_y_idx_0) *
      (localP->MagicTireConstInput_PDX2 * dfz[2] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp_0 *
      localP->MagicTireConstInput_PDX3) * rtb_ImpAsg_InsertedFor_ydotWhee[2] *
      rtb_Product[2] * zeta[19];
    rtb_Saturation_tmp_1 = rtb_sig_x[3] * rtb_sig_x[3];
    epsilon_gamma[3] = ((localP->MagicTireConstInput_PPX3 * dpi_idx_3 + 1.0) +
                        localP->MagicTireConstInput_PPX4 * mu_y_idx_1) *
      (localP->MagicTireConstInput_PDX2 * dfz[3] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp_1 *
      localP->MagicTireConstInput_PDX3) * rtb_ImpAsg_InsertedFor_ydotWhee[3] *
      rtb_Product[3] * zeta[28];
    x_idx_0 = dfz[0] * dfz[0];
    Bykappa[0] = ((localP->MagicTireConstInput_PEX2 * dfz[0] +
                   localP->MagicTireConstInput_PEX1) + x_idx_0 *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[0]) * localP->MagicTireConstInput_PEX4) *
      localB->VectorConcatenate_e[8];
    lam_Cz_tmp = dfz[1] * dfz[1];
    Bykappa[1] = ((localP->MagicTireConstInput_PEX2 * dfz[1] +
                   localP->MagicTireConstInput_PEX1) + lam_Cz_tmp *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[1]) * localP->MagicTireConstInput_PEX4) *
      localB->VectorConcatenate_e[35];
    ab_idx_0 = dfz[2] * dfz[2];
    Bykappa[2] = ((localP->MagicTireConstInput_PEX2 * dfz[2] +
                   localP->MagicTireConstInput_PEX1) + ab_idx_0 *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[2]) * localP->MagicTireConstInput_PEX4) *
      localB->VectorConcatenate_e[62];
    Bykappa_tmp = dfz[3] * dfz[3];
    Bykappa[3] = ((localP->MagicTireConstInput_PEX2 * dfz[3] +
                   localP->MagicTireConstInput_PEX1) + Bykappa_tmp *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[3]) * localP->MagicTireConstInput_PEX4) *
      localB->VectorConcatenate_e[89];
    for (i = 0; i < 4; i++) {
      if (Eykappa[i] < 0.0) {
        Eykappa[i] = 0.0;
      }

      if (epsilon_gamma[i] < 0.0) {
        epsilon_gamma[i] = 0.0;
      }

      if (Bykappa[i] > 1.0) {
        Bykappa[i] = 1.0;
      }
    }

    phi_t[0] = (localP->MagicTireConstInput_PKX2 * dfz[0] +
                localP->MagicTireConstInput_PKX1) * rtb_Product[0] * std::exp
      (localP->MagicTireConstInput_PKX3 * dfz[0]) *
      ((localP->MagicTireConstInput_PPX1 * dpi_idx_0 + 1.0) + Dx_tmp *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate_e[4];
    rtb_sig_y[0] = Eykappa[0] * epsilon_gamma[0];
    phi_t[1] = (localP->MagicTireConstInput_PKX2 * dfz[1] +
                localP->MagicTireConstInput_PKX1) * rtb_Product[1] * std::exp
      (localP->MagicTireConstInput_PKX3 * dfz[1]) *
      ((localP->MagicTireConstInput_PPX1 * dpi_idx_1 + 1.0) + Dx_tmp_0 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate_e[31];
    rtb_sig_y[1] = Eykappa[1] * epsilon_gamma[1];
    phi_t[2] = (localP->MagicTireConstInput_PKX2 * dfz[2] +
                localP->MagicTireConstInput_PKX1) * rtb_Product[2] * std::exp
      (localP->MagicTireConstInput_PKX3 * dfz[2]) *
      ((localP->MagicTireConstInput_PPX1 * dpi_idx_2 + 1.0) + mu_y_idx_0 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate_e[58];
    rtb_sig_y[2] = Eykappa[2] * epsilon_gamma[2];
    Dx_tmp = (localP->MagicTireConstInput_PKX2 * dfz[3] +
              localP->MagicTireConstInput_PKX1) * rtb_Product[3] * std::exp
      (localP->MagicTireConstInput_PKX3 * dfz[3]) *
      ((localP->MagicTireConstInput_PPX1 * dpi_idx_3 + 1.0) + mu_y_idx_1 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate_e[85];
    rtb_sig_y[3] = Eykappa[3] * epsilon_gamma[3];
    AdasPlantModel0_div0protect(rtb_sig_y, 0.0001, Vsy, lam_Cz);
    lam_Cz[0] = localP->MagicTireConstInput_REX2 * dfz[0] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[1] = localP->MagicTireConstInput_REX2 * dfz[1] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[2] = localP->MagicTireConstInput_REX2 * dfz[2] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[3] = localP->MagicTireConstInput_REX2 * dfz[3] +
      localP->MagicTireConstInput_REX1;
    R_omega[0] = (mu_y_tmp * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * localB->Kappa[0])) *
      localB->VectorConcatenate_e[18];
    R_omega[1] = (mu_y_tmp_0 * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * localB->Kappa[1])) *
      localB->VectorConcatenate_e[45];
    R_omega[2] = (mu_y_tmp_1 * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * localB->Kappa[2])) *
      localB->VectorConcatenate_e[72];
    R_omega[3] = (mu_y_tmp_2 * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * localB->Kappa[3])) *
      localB->VectorConcatenate_e[99];
    for (i = 0; i < 4; i++) {
      if (lam_Cz[i] > 1.0) {
        lam_Cz[i] = 1.0;
      }

      if (R_omega[i] < 0.0) {
        R_omega[i] = 0.0;
      }
    }

    AdasPlantModel0_magiccos(localP->MagicTireConstInput_RCX1, R_omega, lam_Cz,
      localB->Alpha, rtb_Saturation_data);
    AdasPlantModel0_magiccos_l(localP->MagicTireConstInput_RCX1, R_omega, lam_Cz,
      d_y);
    rtb_sig_y[0] = rtb_Saturation_data[0] / d_y[0];
    rtb_sig_y[1] = rtb_Saturation_data[1] / d_y[1];
    rtb_sig_y[2] = rtb_Saturation_data[2] / d_y[2];
    rtb_sig_y[3] = rtb_Saturation_data[3] / d_y[3];
    for (i = 0; i < 4; i++) {
      if (rtb_sig_y[i] < 0.0) {
        rtb_sig_y[i] = 0.0;
      }
    }

    Mzphiinf[0] = phi_t[0] / Vsy[0];
    Mzphiinf[1] = phi_t[1] / Vsy[1];
    Mzphiinf[2] = phi_t[2] / Vsy[2];
    Mzphiinf[3] = Dx_tmp / Vsy[3];
    AdasPlantModel0_magicsin_d(epsilon_gamma, Eykappa, Mzphiinf, Bykappa, rtb_My,
      rtb_Saturation_data);
    mu_y_tmp = ((localP->MagicTireConstInput_PVX2 * dfz[0] +
                 localP->MagicTireConstInput_PVX1) * rtb_Product[0] *
                (rtb_ImpAsg_InsertedFor_ydotWhee[0] * 10.0 / (9.0 *
      rtb_ImpAsg_InsertedFor_ydotWhee[0] + 1.0)) * localB->VectorConcatenate_e
                [12] * zeta[1] + rtb_Saturation_data[0]) * rtb_sig_y[0];
    rtb_ImpAsg_InsertedFor_ydotWhee[0] = mu_y_tmp;
    Mzphiinf[0] = localP->MagicTireConstInput_PCY1 * localB->
      VectorConcatenate_e[7];
    mu_y_tmp_0 = ((localP->MagicTireConstInput_PVX2 * dfz[1] +
                   localP->MagicTireConstInput_PVX1) * rtb_Product[1] *
                  (rtb_ImpAsg_InsertedFor_ydotWhee[1] * 10.0 / (9.0 *
      rtb_ImpAsg_InsertedFor_ydotWhee[1] + 1.0)) * localB->VectorConcatenate_e
                  [39] * zeta[10] + rtb_Saturation_data[1]) * rtb_sig_y[1];
    rtb_ImpAsg_InsertedFor_ydotWhee[1] = mu_y_tmp_0;
    Mzphiinf[1] = localP->MagicTireConstInput_PCY1 * localB->
      VectorConcatenate_e[34];
    mu_y_tmp_1 = ((localP->MagicTireConstInput_PVX2 * dfz[2] +
                   localP->MagicTireConstInput_PVX1) * rtb_Product[2] *
                  (rtb_ImpAsg_InsertedFor_ydotWhee[2] * 10.0 / (9.0 *
      rtb_ImpAsg_InsertedFor_ydotWhee[2] + 1.0)) * localB->VectorConcatenate_e
                  [66] * zeta[19] + rtb_Saturation_data[2]) * rtb_sig_y[2];
    rtb_ImpAsg_InsertedFor_ydotWhee[2] = mu_y_tmp_1;
    Mzphiinf[2] = localP->MagicTireConstInput_PCY1 * localB->
      VectorConcatenate_e[61];
    Dx_tmp_0 = ((localP->MagicTireConstInput_PVX2 * dfz[3] +
                 localP->MagicTireConstInput_PVX1) * rtb_Product[3] *
                (rtb_ImpAsg_InsertedFor_ydotWhee[3] * 10.0 / (9.0 *
      rtb_ImpAsg_InsertedFor_ydotWhee[3] + 1.0)) * localB->VectorConcatenate_e
                [93] * zeta[28] + rtb_Saturation_data[3]) * rtb_sig_y[3];
    rtb_ImpAsg_InsertedFor_ydotWhee[3] = Dx_tmp_0;
    Mzphiinf[3] = localP->MagicTireConstInput_PCY1 * localB->
      VectorConcatenate_e[88];
    for (i = 0; i < 4; i++) {
      if (Mzphiinf[i] < 0.0) {
        Mzphiinf[i] = 0.0;
      }
    }

    rtb_Sum1_m *= rtb_Product[0];
    mu_y_idx_0 = rtb_Sum1_m;
    rtb_UnaryMinus2_idx_0 = rtb_Sum1_m * zeta[2];
    Vsy[0] = rtb_UnaryMinus2_idx_0;
    phi[0] = Mzphiinf[0] * rtb_UnaryMinus2_idx_0;
    rtb_Sum1_m = rtb_Gain1_g0 * rtb_Product[1];
    mu_y_idx_1 = rtb_Sum1_m;
    rtb_UnaryMinus2_idx_0 = rtb_Sum1_m * zeta[11];
    Vsy[1] = rtb_UnaryMinus2_idx_0;
    phi[1] = Mzphiinf[1] * rtb_UnaryMinus2_idx_0;
    rtb_Sum1_m = mu_y_idx_2 * rtb_Product[2];
    mu_y_idx_2 = rtb_Sum1_m;
    rtb_UnaryMinus2_idx_0 = rtb_Sum1_m * zeta[20];
    Vsy[2] = rtb_UnaryMinus2_idx_0;
    phi[2] = Mzphiinf[2] * rtb_UnaryMinus2_idx_0;
    rtb_Sum1_m = mu_y * rtb_Product[3];
    rtb_UnaryMinus2_idx_0 = rtb_Sum1_m * zeta[29];
    Vsy[3] = rtb_UnaryMinus2_idx_0;
    phi[3] = Mzphiinf[3] * rtb_UnaryMinus2_idx_0;
    AdasPlantModel0_div0protect(phi, 0.0001, epsilon_gamma, lam_Cz);
    epsilon_gamma[0] = rtb_Product_py / epsilon_gamma[0];
    epsilon_gamma[1] = rtb_Smallangleapproximationford / epsilon_gamma[1];
    epsilon_gamma[2] = rtb_Integrator1_p / epsilon_gamma[2];
    epsilon_gamma[3] = rtb_Switch_e1 / epsilon_gamma[3];
    if (AdasPlantModel0_any(nomslipinds)) {
      iy = 0;
      lb[1] = 1;
      for (i = 0; i < 4; i++) {
        if (nomslipinds[i]) {
          iy++;
        }
      }

      lb[0] = static_cast<int8_T>(iy);
      ibmat = 0;
      Itemp_tmp = 0;
      for (i = 0; i < 4; i++) {
        if (nomslipinds[i]) {
          tmp_data_1[ibmat] = static_cast<int8_T>(i);
          ibmat++;
          Itemp_tmp++;
        }
      }

      ibmat = 0;
      for (i = 0; i < 4; i++) {
        if (nomslipinds[i]) {
          tmp_data_2[ibmat] = i;
          ibmat++;
        }
      }

      i = Itemp_tmp == 1 ? static_cast<int32_T>(static_cast<int8_T>(iy)) :
        Itemp_tmp;
      if ((Itemp_tmp == static_cast<int8_T>(iy)) && (i == Itemp_tmp) && ((i == 1
            ? Itemp_tmp : i) == Itemp_tmp)) {
        for (i = 0; i < Itemp_tmp; i++) {
          iy = tmp_data_2[i];
          SHy[tmp_data_1[i]] = (((Kygammao[iy] * rtb_Saturation[iy] - Kyalpha[iy])
            / b_x[iy] * zeta[9 * iy] + localB->VectorConcatenate_e[27 * iy + 11]
            * (0.0 * dfz[iy])) + zeta[9 * iy + 4]) - 1.0;
        }
      } else {
        AdasPlantModel_binary_expand_op(SHy, tmp_data_1, dfz, tmp_data_2,
          &Itemp_tmp, localB->VectorConcatenate_e, lb, Kygammao, rtb_Saturation,
          Kyalpha, b_x, zeta);
      }
    }

    lam_muy_prime_idx_0 = 0.0 * dfz[0] * rtb_Product[0] *
      localB->VectorConcatenate_e[13] * lam_muy_prime_idx_0 * zeta[2] + Kyalpha
      [0];
    R_omega_0 = localB->Alpha[0] + SHy[0];
    R_omega[0] = R_omega_0;
    if (std::isnan(R_omega_0)) {
      lam_Cz[0] = (rtNaN);
    } else if (R_omega_0 < 0.0) {
      lam_Cz[0] = -1.0;
    } else {
      lam_Cz[0] = (R_omega_0 > 0.0);
    }

    lam_muy_prime_idx_1 = 0.0 * dfz[1] * rtb_Product[1] *
      localB->VectorConcatenate_e[40] * lam_muy_prime_idx_1 * zeta[11] +
      Kyalpha[1];
    R_omega_0 = localB->Alpha[1] + SHy[1];
    R_omega[1] = R_omega_0;
    if (std::isnan(R_omega_0)) {
      lam_Cz[1] = (rtNaN);
    } else if (R_omega_0 < 0.0) {
      lam_Cz[1] = -1.0;
    } else {
      lam_Cz[1] = (R_omega_0 > 0.0);
    }

    rtb_FrontBiasGain = 0.0 * dfz[2] * rtb_Product[2] *
      localB->VectorConcatenate_e[67] * rtb_FrontBiasGain * zeta[20] + Kyalpha[2];
    R_omega_0 = localB->Alpha[2] + SHy[2];
    R_omega[2] = R_omega_0;
    if (std::isnan(R_omega_0)) {
      lam_Cz[2] = (rtNaN);
    } else if (R_omega_0 < 0.0) {
      lam_Cz[2] = -1.0;
    } else {
      lam_Cz[2] = (R_omega_0 > 0.0);
    }

    lam_muy_prime_idx_3 = 0.0 * dfz[3] * rtb_Product[3] *
      localB->VectorConcatenate_e[94] * lam_muy_prime_idx_3 * zeta[29] +
      Kyalpha[3];
    R_omega_0 = localB->Alpha[3] + SHy[3];
    R_omega[3] = R_omega_0;
    if (std::isnan(R_omega_0)) {
      lam_Cz[3] = (rtNaN);
    } else if (R_omega_0 < 0.0) {
      lam_Cz[3] = -1.0;
    } else {
      lam_Cz[3] = (R_omega_0 > 0.0);
    }

    for (i = 0; i < 4; i++) {
      if (lam_Cz[i] == 0.0) {
        lam_Cz[i] = 1.0;
      }
    }

    lam_Cz_tmp_tmp = rtb_Saturation[0] * rtb_Saturation[0];
    rtb_sig_y[0] = ((lam_Cz_tmp_tmp * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[0] *
                    lam_Cz[0]) * (localP->MagicTireConstInput_PEY2 * dfz[0] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate_e[9];
    Kyalpha_tmp_tmp = rtb_Saturation[1] * rtb_Saturation[1];
    rtb_sig_y[1] = ((Kyalpha_tmp_tmp * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[1] *
                    lam_Cz[1]) * (localP->MagicTireConstInput_PEY2 * dfz[1] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate_e[36];
    mu_y_tmp_2 = rtb_Saturation[2] * rtb_Saturation[2];
    rtb_sig_y[2] = ((mu_y_tmp_2 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[2] *
                    lam_Cz[2]) * (localP->MagicTireConstInput_PEY2 * dfz[2] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate_e[63];
    lam_Cz_0 = rtb_Saturation[3] * rtb_Saturation[3];
    rtb_sig_y[3] = ((lam_Cz_0 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[3] *
                    lam_Cz[3]) * (localP->MagicTireConstInput_PEY2 * dfz[3] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate_e[90];
    for (i = 0; i < 4; i++) {
      if (rtb_sig_y[i] > 1.0) {
        rtb_sig_y[i] = 1.0;
      }
    }

    AdasPlantModel0_magicsin_d(Vsy, Mzphiinf, epsilon_gamma, rtb_sig_y, R_omega,
      rtb_Saturation_data);
    rtb_Gain1_g0 = (0.0 * dfz[0] + localP->MagicTireConstInput_RVY3 *
                    rtb_Saturation[0]) * mu_y_idx_0 * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * localB->Alpha[0])) * zeta[2] * std::
      sin(std::atan(localP->MagicTireConstInput_RVY6 * localB->Kappa[0]) *
          localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate_e[20];
    mu_y_idx_0 = rtb_Gain1_g0;
    rtb_ImpAsg_InsertedFor_xdotWhee[0] = (rtb_Saturation_data[0] +
      lam_muy_prime_idx_0) * rtb_ImpAsg_InsertedFor_xdotWhee[0] + rtb_Gain1_g0;
    rtb_Gain1_g0 = (0.0 * dfz[1] + localP->MagicTireConstInput_RVY3 *
                    rtb_Saturation[1]) * mu_y_idx_1 * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * localB->Alpha[1])) * zeta[11] * std::
      sin(std::atan(localP->MagicTireConstInput_RVY6 * localB->Kappa[1]) *
          localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate_e[47];
    mu_y_idx_1 = rtb_Gain1_g0;
    rtb_ImpAsg_InsertedFor_xdotWhee[1] = (rtb_Saturation_data[1] +
      lam_muy_prime_idx_1) * rtb_ImpAsg_InsertedFor_xdotWhee[1] + rtb_Gain1_g0;
    rtb_Gain1_g0 = (0.0 * dfz[2] + localP->MagicTireConstInput_RVY3 *
                    rtb_Saturation[2]) * mu_y_idx_2 * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * localB->Alpha[2])) * zeta[20] * std::
      sin(std::atan(localP->MagicTireConstInput_RVY6 * localB->Kappa[2]) *
          localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate_e[74];
    mu_y_idx_2 = rtb_Gain1_g0;
    rtb_ImpAsg_InsertedFor_xdotWhee[2] = (rtb_Saturation_data[2] +
      rtb_FrontBiasGain) * rtb_ImpAsg_InsertedFor_xdotWhee[2] + rtb_Gain1_g0;
    rtb_Gain1_g0 = (0.0 * dfz[3] + localP->MagicTireConstInput_RVY3 *
                    rtb_Saturation[3]) * rtb_Sum1_m * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * localB->Alpha[3])) * zeta[29] * std::
      sin(std::atan(localP->MagicTireConstInput_RVY6 * localB->Kappa[3]) *
          localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate_e[101];
    rtb_ImpAsg_InsertedFor_xdotWhee[3] = (rtb_Saturation_data[3] +
      lam_muy_prime_idx_3) * rtb_ImpAsg_InsertedFor_xdotWhee[3] + rtb_Gain1_g0;
    rtb_My[0] = 10.0 * rty_VehFdbk_c[0];
    rtb_My[1] = 10.0 * rty_VehFdbk_c[1];
    rtb_My[2] = 10.0 * rty_VehFdbk_c[2];
    rtb_My[3] = 10.0 * rty_VehFdbk_c[3];
    rtb_My[0] = std::tanh(rtb_My[0]);
    rtb_Saturation_data[0] = localB->VectorConcatenate_e[25];
    rtb_My[1] = std::tanh(rtb_My[1]);
    rtb_Saturation_data[1] = localB->VectorConcatenate_e[52];
    rtb_My[2] = std::tanh(rtb_My[2]);
    rtb_Saturation_data[2] = localB->VectorConcatenate_e[79];
    rtb_My[3] = std::tanh(rtb_My[3]);
    rtb_Saturation_data[3] = localB->VectorConcatenate_e[106];
    AdasPlantModel0_rollingMoment(rtb_ImpAsg_InsertedFor_ydotWhee,
      localB->Reshape1, FzUnSat, rtb_VectorConcatenate3, rtb_sig_x,
      AdasPlantModel0_P->PlntWhlLongSpd, AdasPlantModel0_P->PlntWhlUnldRadius,
      AdasPlantModel0_P->PlntWhlNomNorlForce, AdasPlantModel0_P->PlntWhlNomPress,
      localP->MagicTireConstInput_QSY1, localP->MagicTireConstInput_QSY2,
      localP->MagicTireConstInput_QSY3, localP->MagicTireConstInput_QSY4,
      localP->MagicTireConstInput_QSY5, localP->MagicTireConstInput_QSY6,
      localP->MagicTireConstInput_QSY7, localP->MagicTireConstInput_QSY8,
      rtb_Saturation_data, d_y);
    rtb_My[0] *= d_y[0];
    rtb_Sum1_m = localP->MagicTireConstInput_QSX6 * rtb_Product[0] /
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    mu_y = AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[0];
    Bykappa[0] = mu_y;
    R_omega_0 = std::abs(rtb_sig_x[0]);
    localB->Mx_c[0] = (((((0.0 * localB->VectorConcatenate_e[24] -
      (localP->MagicTireConstInput_PPMX1 * dpi_idx_0 + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[0])) -
                          localP->MagicTireConstInput_QSX12 * rtb_sig_x[0] *
                          R_omega_0) + localP->MagicTireConstInput_QSX3 *
                         rtb_ImpAsg_InsertedFor_xdotWhee[0] /
                         AdasPlantModel0_P->PlntWhlNomNorlForce) + std::sin(std::
      atan(localP->MagicTireConstInput_QSX9 * rtb_ImpAsg_InsertedFor_xdotWhee[0]
           / AdasPlantModel0_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[0]) * (std::cos(std::atan(rtb_Sum1_m * rtb_Sum1_m) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
                       std::atan(localP->MagicTireConstInput_QSX11 *
      rtb_Product[0] / AdasPlantModel0_P->PlntWhlNomNorlForce) *
                       localP->MagicTireConstInput_QSX10 * rtb_sig_x[0]) * (mu_y
      * localB->Mx_c[0]) + AdasPlantModel0_P->PlntWhlUnldRadius *
      rtb_ImpAsg_InsertedFor_xdotWhee[0] * localB->Mx_c[0] *
      (localP->MagicTireConstInput_QSX14 * R_omega_0 +
       localP->MagicTireConstInput_QSX13);
    cosprimealpha[0] = localB->Reshape1[0] / cosprimealpha[0];
    Eykappa[0] = ((localP->MagicTireConstInput_QHZ4 * dfz[0] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[0] + 0.0 *
                  dfz[0]) + localB->Alpha[0];
    SHy[0] = (lam_muy_prime_idx_0 / b_x[0] + SHy[0]) + localB->Alpha[0];
    rtb_UnaryMinus2_idx_0 = 0.0 * rtb_sig_x[0] + 1.0;
    rtb_sig_y[0] = rtb_UnaryMinus2_idx_0;
    SHykappa[0] = ((localP->MagicTireConstInput_QBZ2 * dfz[0] +
                    localP->MagicTireConstInput_QBZ1) + x_idx_0 *
                   localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * R_omega_0 + rtb_UnaryMinus2_idx_0) +
       lam_Cz_tmp_tmp * localP->MagicTireConstInput_QBZ6) *
      localB->VectorConcatenate_e[5] / lam_muy[0];
    rtb_My[1] *= d_y[1];
    rtb_Sum1_m = localP->MagicTireConstInput_QSX6 * rtb_Product[1] /
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    mu_y = AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[1];
    Bykappa[1] = mu_y;
    R_omega_0 = std::abs(rtb_sig_x[1]);
    localB->Mx_c[1] = (((((0.0 * localB->VectorConcatenate_e[51] -
      (localP->MagicTireConstInput_PPMX1 * dpi_idx_1 + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[1])) -
                          localP->MagicTireConstInput_QSX12 * rtb_sig_x[1] *
                          R_omega_0) + localP->MagicTireConstInput_QSX3 *
                         rtb_ImpAsg_InsertedFor_xdotWhee[1] /
                         AdasPlantModel0_P->PlntWhlNomNorlForce) + std::sin(std::
      atan(localP->MagicTireConstInput_QSX9 * rtb_ImpAsg_InsertedFor_xdotWhee[1]
           / AdasPlantModel0_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[1]) * (std::cos(std::atan(rtb_Sum1_m * rtb_Sum1_m) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
                       std::atan(localP->MagicTireConstInput_QSX11 *
      rtb_Product[1] / AdasPlantModel0_P->PlntWhlNomNorlForce) *
                       localP->MagicTireConstInput_QSX10 * rtb_sig_x[1]) * (mu_y
      * localB->Mx_c[1]) + AdasPlantModel0_P->PlntWhlUnldRadius *
      rtb_ImpAsg_InsertedFor_xdotWhee[1] * localB->Mx_c[1] *
      (localP->MagicTireConstInput_QSX14 * R_omega_0 +
       localP->MagicTireConstInput_QSX13);
    cosprimealpha[1] = localB->Reshape1[1] / cosprimealpha[1];
    Eykappa[1] = ((localP->MagicTireConstInput_QHZ4 * dfz[1] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[1] + 0.0 *
                  dfz[1]) + localB->Alpha[1];
    SHy[1] = (lam_muy_prime_idx_1 / b_x[1] + SHy[1]) + localB->Alpha[1];
    rtb_UnaryMinus2_idx_0 = 0.0 * rtb_sig_x[1] + 1.0;
    rtb_sig_y[1] = rtb_UnaryMinus2_idx_0;
    SHykappa[1] = ((localP->MagicTireConstInput_QBZ2 * dfz[1] +
                    localP->MagicTireConstInput_QBZ1) + lam_Cz_tmp *
                   localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * R_omega_0 + rtb_UnaryMinus2_idx_0) +
       Kyalpha_tmp_tmp * localP->MagicTireConstInput_QBZ6) *
      localB->VectorConcatenate_e[32] / lam_muy[1];
    rtb_My[2] *= d_y[2];
    rtb_Sum1_m = localP->MagicTireConstInput_QSX6 * rtb_Product[2] /
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    mu_y = AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[2];
    Bykappa[2] = mu_y;
    R_omega_0 = std::abs(rtb_sig_x[2]);
    localB->Mx_c[2] = (((((0.0 * localB->VectorConcatenate_e[78] -
      (localP->MagicTireConstInput_PPMX1 * dpi_idx_2 + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[2])) -
                          localP->MagicTireConstInput_QSX12 * rtb_sig_x[2] *
                          R_omega_0) + localP->MagicTireConstInput_QSX3 *
                         rtb_ImpAsg_InsertedFor_xdotWhee[2] /
                         AdasPlantModel0_P->PlntWhlNomNorlForce) + std::sin(std::
      atan(localP->MagicTireConstInput_QSX9 * rtb_ImpAsg_InsertedFor_xdotWhee[2]
           / AdasPlantModel0_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[2]) * (std::cos(std::atan(rtb_Sum1_m * rtb_Sum1_m) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
                       std::atan(localP->MagicTireConstInput_QSX11 *
      rtb_Product[2] / AdasPlantModel0_P->PlntWhlNomNorlForce) *
                       localP->MagicTireConstInput_QSX10 * rtb_sig_x[2]) * (mu_y
      * localB->Mx_c[2]) + AdasPlantModel0_P->PlntWhlUnldRadius *
      rtb_ImpAsg_InsertedFor_xdotWhee[2] * localB->Mx_c[2] *
      (localP->MagicTireConstInput_QSX14 * R_omega_0 +
       localP->MagicTireConstInput_QSX13);
    cosprimealpha[2] = localB->Reshape1[2] / cosprimealpha[2];
    Eykappa[2] = ((localP->MagicTireConstInput_QHZ4 * dfz[2] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[2] + 0.0 *
                  dfz[2]) + localB->Alpha[2];
    SHy[2] = (rtb_FrontBiasGain / b_x[2] + SHy[2]) + localB->Alpha[2];
    rtb_UnaryMinus2_idx_0 = 0.0 * rtb_sig_x[2] + 1.0;
    rtb_sig_y[2] = rtb_UnaryMinus2_idx_0;
    SHykappa[2] = ((localP->MagicTireConstInput_QBZ2 * dfz[2] +
                    localP->MagicTireConstInput_QBZ1) + ab_idx_0 *
                   localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * R_omega_0 + rtb_UnaryMinus2_idx_0) +
       mu_y_tmp_2 * localP->MagicTireConstInput_QBZ6) *
      localB->VectorConcatenate_e[59] / lam_muy[2];
    rtb_My[3] *= d_y[3];
    rtb_Sum1_m = localP->MagicTireConstInput_QSX6 * rtb_Product[3] /
      AdasPlantModel0_P->PlntWhlNomNorlForce;
    mu_y = AdasPlantModel0_P->PlntWhlUnldRadius * rtb_Product[3];
    R_omega_0 = std::abs(rtb_sig_x[3]);
    localB->Mx_c[3] = (((((0.0 * localB->VectorConcatenate_e[105] -
      (localP->MagicTireConstInput_PPMX1 * dpi_idx_3 + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[3])) -
                          localP->MagicTireConstInput_QSX12 * rtb_sig_x[3] *
                          R_omega_0) + localP->MagicTireConstInput_QSX3 *
                         rtb_ImpAsg_InsertedFor_xdotWhee[3] /
                         AdasPlantModel0_P->PlntWhlNomNorlForce) + std::sin(std::
      atan(localP->MagicTireConstInput_QSX9 * rtb_ImpAsg_InsertedFor_xdotWhee[3]
           / AdasPlantModel0_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[3]) * (std::cos(std::atan(rtb_Sum1_m * rtb_Sum1_m) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
                       std::atan(localP->MagicTireConstInput_QSX11 *
      rtb_Product[3] / AdasPlantModel0_P->PlntWhlNomNorlForce) *
                       localP->MagicTireConstInput_QSX10 * rtb_sig_x[3]) * (mu_y
      * localB->Mx_c[3]) + AdasPlantModel0_P->PlntWhlUnldRadius *
      rtb_ImpAsg_InsertedFor_xdotWhee[3] * localB->Mx_c[3] *
      (localP->MagicTireConstInput_QSX14 * R_omega_0 +
       localP->MagicTireConstInput_QSX13);
    cosprimealpha[3] = localB->Reshape1[3] / cosprimealpha[3];
    Eykappa[3] = ((localP->MagicTireConstInput_QHZ4 * dfz[3] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[3] + 0.0 *
                  dfz[3]) + localB->Alpha[3];
    SHy[3] = (lam_muy_prime_idx_3 / b_x[3] + SHy[3]) + localB->Alpha[3];
    rtb_UnaryMinus2_idx_0 = 0.0 * rtb_sig_x[3] + 1.0;
    SHykappa[3] = ((localP->MagicTireConstInput_QBZ2 * dfz[3] +
                    localP->MagicTireConstInput_QBZ1) + Bykappa_tmp *
                   localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * R_omega_0 + rtb_UnaryMinus2_idx_0) +
       lam_Cz_0 * localP->MagicTireConstInput_QBZ6) *
      localB->VectorConcatenate_e[86] / rtb_Saturation_0;
    for (i = 0; i < 4; i++) {
      if (SHykappa[i] < 0.0) {
        SHykappa[i] = 0.0;
      }
    }

    rtb_FrontBiasGain = localP->MagicTireConstInput_QCZ1;
    if (localP->MagicTireConstInput_QCZ1 < 0.0) {
      rtb_FrontBiasGain = 0.0;
    }

    Vsy[0] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[0] * 2.0 /
              3.1415926535897931 * std::atan(SHykappa[0] * rtb_FrontBiasGain *
               Eykappa[0]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[0]
      + localP->MagicTireConstInput_QEZ1) + x_idx_0 *
      localP->MagicTireConstInput_QEZ3);
    Vsy[1] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[1] * 2.0 /
              3.1415926535897931 * std::atan(rtb_FrontBiasGain * SHykappa[1] *
               Eykappa[1]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[1]
      + localP->MagicTireConstInput_QEZ1) + lam_Cz_tmp *
      localP->MagicTireConstInput_QEZ3);
    Vsy[2] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[2] * 2.0 /
              3.1415926535897931 * std::atan(rtb_FrontBiasGain * SHykappa[2] *
               Eykappa[2]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[2]
      + localP->MagicTireConstInput_QEZ1) + ab_idx_0 *
      localP->MagicTireConstInput_QEZ3);
    Vsy[3] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[3] * 2.0 /
              3.1415926535897931 * std::atan(rtb_FrontBiasGain * SHykappa[3] *
               Eykappa[3]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[3]
      + localP->MagicTireConstInput_QEZ1) + Bykappa_tmp *
      localP->MagicTireConstInput_QEZ3);
    for (i = 0; i < 4; i++) {
      if (Vsy[i] > 1.0) {
        Vsy[i] = 1.0;
      }
    }

    lam_Cz_0 = std::tan(SHy[0]);
    lam_muy_prime_idx_3 = phi_t[0] / b_x[0];
    mu_y_tmp_2 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (localB->Kappa[0] *
      localB->Kappa[0]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2);
    lam_Cz_0 = std::tan(Eykappa[0]);
    rtb_Saturation_data[0] = (localP->MagicTireConstInput_QDZ2 * dfz[0] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi_idx_0) * (rtb_Divide_pl *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[0]) * rtb_Product[0] *
      (AdasPlantModel0_P->PlntWhlUnldRadius / Fzo_prime_idx_0) *
      localB->VectorConcatenate_e[16] * zeta[5];
    phi[0] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2)) * std::tanh
      (1000.0 * Eykappa[0]);
    rtb_VectorConcatenate3[0] = ((((localP->MagicTireConstInput_QDZ9 * dfz[0] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi_idx_0 + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[0] +
                          localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[0])) * rtb_Saturation[0] * localB->VectorConcatenate_e[15]
      * zeta[0] + 0.0 * dfz[0] * localB->VectorConcatenate_e[17] * zeta[2]) *
      Bykappa[0] * lam_muy[0] * std::tanh(10.0 * localB->Reshape1[0]) *
      cosprimealpha[0] + zeta[8]) - 1.0;
    R_omega[0] = zeta[7];
    d_y[0] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate_e[5] /
              lam_muy[0] + localP->MagicTireConstInput_QBZ10 * epsilon_gamma[0] *
              Mzphiinf[0]) * zeta[6];
    rtb_sig_x[0] = std::tanh(1000.0 * SHy[0]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[1]);
    lam_muy_prime_idx_3 = phi_t[1] / b_x[1];
    mu_y_tmp_2 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (localB->Kappa[1] *
      localB->Kappa[1]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2);
    lam_Cz_0 = std::tan(Eykappa[1]);
    rtb_Saturation_data[1] = (localP->MagicTireConstInput_QDZ2 * dfz[1] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi_idx_1) * (rtb_Saturation_tmp *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[1]) * rtb_Product[1] *
      (AdasPlantModel0_P->PlntWhlUnldRadius / Fzo_prime_idx_1) *
      localB->VectorConcatenate_e[43] * zeta[14];
    phi[1] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2)) * std::tanh
      (1000.0 * Eykappa[1]);
    rtb_VectorConcatenate3[1] = ((((localP->MagicTireConstInput_QDZ9 * dfz[1] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi_idx_1 + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[1] +
                          localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[1])) * rtb_Saturation[1] * localB->VectorConcatenate_e[42]
      * zeta[9] + 0.0 * dfz[1] * localB->VectorConcatenate_e[44] * zeta[11]) *
      Bykappa[1] * lam_muy[1] * std::tanh(10.0 * localB->Reshape1[1]) *
      cosprimealpha[1] + zeta[17]) - 1.0;
    R_omega[1] = zeta[16];
    d_y[1] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate_e[32]
              / lam_muy[1] + localP->MagicTireConstInput_QBZ10 * epsilon_gamma[1]
              * Mzphiinf[1]) * zeta[15];
    rtb_sig_x[1] = std::tanh(1000.0 * SHy[1]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[2]);
    lam_muy_prime_idx_3 = phi_t[2] / b_x[2];
    mu_y_tmp_2 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (localB->Kappa[2] *
      localB->Kappa[2]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2);
    lam_Cz_0 = std::tan(Eykappa[2]);
    rtb_Saturation_data[2] = (localP->MagicTireConstInput_QDZ2 * dfz[2] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi_idx_2) * (rtb_Saturation_tmp_0 *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[2]) * rtb_Product[2] *
      (AdasPlantModel0_P->PlntWhlUnldRadius / Fzo_prime_idx_2) *
      localB->VectorConcatenate_e[70] * zeta[23];
    phi[2] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2)) * std::tanh
      (1000.0 * Eykappa[2]);
    rtb_VectorConcatenate3[2] = ((((localP->MagicTireConstInput_QDZ9 * dfz[2] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi_idx_2 + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[2] +
                          localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[2])) * rtb_Saturation[2] * localB->VectorConcatenate_e[69]
      * zeta[18] + 0.0 * dfz[2] * localB->VectorConcatenate_e[71] * zeta[20]) *
      Bykappa[2] * lam_muy[2] * std::tanh(10.0 * localB->Reshape1[2]) *
      cosprimealpha[2] + zeta[26]) - 1.0;
    R_omega[2] = zeta[25];
    d_y[2] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate_e[59]
              / lam_muy[2] + localP->MagicTireConstInput_QBZ10 * epsilon_gamma[2]
              * Mzphiinf[2]) * zeta[24];
    rtb_sig_x[2] = std::tanh(1000.0 * SHy[2]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[3]);
    lam_muy_prime_idx_3 = Dx_tmp / b_x[3];
    mu_y_tmp_2 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (localB->Kappa[3] *
      localB->Kappa[3]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2);
    lam_Cz_0 = std::tan(Eykappa[3]);
    rtb_Saturation_data[3] = (localP->MagicTireConstInput_QDZ2 * dfz[3] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi_idx_3) * (rtb_Saturation_tmp_1 *
      localP->MagicTireConstInput_QDZ4 + rtb_UnaryMinus2_idx_0) * rtb_Product[3]
      * (AdasPlantModel0_P->PlntWhlUnldRadius / Fzo_prime_idx_3) *
      localB->VectorConcatenate_e[97] * zeta[32];
    phi[3] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + mu_y_tmp_2)) * std::tanh
      (1000.0 * Eykappa[3]);
    rtb_VectorConcatenate3[3] = ((((localP->MagicTireConstInput_QDZ9 * dfz[3] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi_idx_3 + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[3] +
                          localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[3])) * rtb_Saturation[3] * localB->VectorConcatenate_e[96]
      * zeta[27] + 0.0 * dfz[3] * localB->VectorConcatenate_e[98] * zeta[29]) *
      mu_y * rtb_Saturation_0 * std::tanh(10.0 * localB->Reshape1[3]) *
      cosprimealpha[3] + zeta[35]) - 1.0;
    R_omega[3] = zeta[34];
    d_y[3] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate_e[86]
              / rtb_Saturation_0 + localP->MagicTireConstInput_QBZ10 *
              epsilon_gamma[3] * Mzphiinf[3]) * zeta[33];
    rtb_sig_x[3] = std::tanh(1000.0 * SHy[3]) * std::atan(lam_muy_prime_idx_3);
    AdasPlantModel0_magiccos_l1m(rtb_Saturation_data, rtb_FrontBiasGain,
      SHykappa, Vsy, phi, localB->Mz_j);
    AdasPlantModel0_magiccos_l1(rtb_VectorConcatenate3, R_omega, d_y, rtb_sig_x,
      rtb_Saturation_data);
    localB->Mz_j[0] = ((localP->MagicTireConstInput_SSZ4 * dfz[0] +
                        localP->MagicTireConstInput_SSZ3) * rtb_Saturation[0] +
                       localP->MagicTireConstInput_SSZ2 *
                       rtb_ImpAsg_InsertedFor_xdotWhee[0] /
                       AdasPlantModel0_P->PlntWhlNomNorlForce) *
      AdasPlantModel0_P->PlntWhlUnldRadius * localB->VectorConcatenate_e[21] *
      mu_y_tmp + (-(localB->Mz_j[0] * cosprimealpha[0] *
                    localB->VectorConcatenate_e[0]) *
                  (rtb_ImpAsg_InsertedFor_xdotWhee[0] - mu_y_idx_0) +
                  rtb_Saturation_data[0]);
    rtb_sig_x[0] = std::abs(phi_t[0] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[0] + 1.0) + x_idx_0 * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi_idx_0 + 1.0)));
    rtb_sig_y[0] = std::abs(rtb_Product_py /
      (((localP->MagicTireConstInput_PCFY1 * dfz[0] + 1.0) + x_idx_0 *
        localP->MagicTireConstInput_PCFY2) *
       localP->MagicTireConstInput_LATERAL_STI *
       (localP->MagicTireConstInput_PCFY3 * dpi_idx_0 + 1.0)));
    localB->Mz_j[1] = ((localP->MagicTireConstInput_SSZ4 * dfz[1] +
                        localP->MagicTireConstInput_SSZ3) * rtb_Saturation[1] +
                       localP->MagicTireConstInput_SSZ2 *
                       rtb_ImpAsg_InsertedFor_xdotWhee[1] /
                       AdasPlantModel0_P->PlntWhlNomNorlForce) *
      AdasPlantModel0_P->PlntWhlUnldRadius * localB->VectorConcatenate_e[48] *
      mu_y_tmp_0 + (-(localB->Mz_j[1] * cosprimealpha[1] *
                      localB->VectorConcatenate_e[27]) *
                    (rtb_ImpAsg_InsertedFor_xdotWhee[1] - mu_y_idx_1) +
                    rtb_Saturation_data[1]);
    rtb_sig_x[1] = std::abs(phi_t[1] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[1] + 1.0) + lam_Cz_tmp * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi_idx_1 + 1.0)));
    rtb_sig_y[1] = std::abs(rtb_Smallangleapproximationford /
      (((localP->MagicTireConstInput_PCFY1 * dfz[1] + 1.0) + lam_Cz_tmp *
        localP->MagicTireConstInput_PCFY2) *
       localP->MagicTireConstInput_LATERAL_STI *
       (localP->MagicTireConstInput_PCFY3 * dpi_idx_1 + 1.0)));
    localB->Mz_j[2] = ((localP->MagicTireConstInput_SSZ4 * dfz[2] +
                        localP->MagicTireConstInput_SSZ3) * rtb_Saturation[2] +
                       localP->MagicTireConstInput_SSZ2 *
                       rtb_ImpAsg_InsertedFor_xdotWhee[2] /
                       AdasPlantModel0_P->PlntWhlNomNorlForce) *
      AdasPlantModel0_P->PlntWhlUnldRadius * localB->VectorConcatenate_e[75] *
      mu_y_tmp_1 + (-(localB->Mz_j[2] * cosprimealpha[2] *
                      localB->VectorConcatenate_e[54]) *
                    (rtb_ImpAsg_InsertedFor_xdotWhee[2] - mu_y_idx_2) +
                    rtb_Saturation_data[2]);
    rtb_sig_x[2] = std::abs(phi_t[2] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[2] + 1.0) + ab_idx_0 * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi_idx_2 + 1.0)));
    rtb_sig_y[2] = std::abs(rtb_Integrator1_p /
      (((localP->MagicTireConstInput_PCFY1 * dfz[2] + 1.0) + ab_idx_0 *
        localP->MagicTireConstInput_PCFY2) *
       localP->MagicTireConstInput_LATERAL_STI *
       (localP->MagicTireConstInput_PCFY3 * dpi_idx_2 + 1.0)));
    localB->Mz_j[3] = ((localP->MagicTireConstInput_SSZ4 * dfz[3] +
                        localP->MagicTireConstInput_SSZ3) * rtb_Saturation[3] +
                       localP->MagicTireConstInput_SSZ2 *
                       rtb_ImpAsg_InsertedFor_xdotWhee[3] /
                       AdasPlantModel0_P->PlntWhlNomNorlForce) *
      AdasPlantModel0_P->PlntWhlUnldRadius * localB->VectorConcatenate_e[102] *
      Dx_tmp_0 + (-(localB->Mz_j[3] * cosprimealpha[3] *
                    localB->VectorConcatenate_e[81]) *
                  (rtb_ImpAsg_InsertedFor_xdotWhee[3] - rtb_Gain1_g0) +
                  rtb_Saturation_data[3]);
    rtb_sig_x[3] = std::abs(Dx_tmp / (((localP->MagicTireConstInput_PCFX1 * dfz
      [3] + 1.0) + Bykappa_tmp * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi_idx_3 + 1.0)));
    rtb_sig_y[3] = std::abs(rtb_Switch_e1 / (((localP->MagicTireConstInput_PCFY1
      * dfz[3] + 1.0) + Bykappa_tmp * localP->MagicTireConstInput_PCFY2) *
      localP->MagicTireConstInput_LATERAL_STI *
      (localP->MagicTireConstInput_PCFY3 * dpi_idx_3 + 1.0)));
  } else {
    for (i = 0; i < 4; i++) {
      lam_muy[i] = localB->Reshape[i];
    }

    AdasPlantModel0_vdyncsmtire(rty_VehFdbk_c, localB->Reshape1,
      localB->Reshape2, localB->UnaryMinus, lam_muy, rtb_VectorConcatenate3,
      localB->VectorConcatenate_e, rtb_Saturation,
      localP->CombinedSlipWheel2DOF_turnslip, AdasPlantModel0_P->PlntWhlMaxPress,
      AdasPlantModel0_P->PlntWhlMinPress, AdasPlantModel0_P->PlntWhlMaxFz,
      AdasPlantModel0_P->PlntWhlMinFz, AdasPlantModel0_P->PlntWhlVelTolLowVel,
      AdasPlantModel0_P->PlntWhlMaxSlipRatio,
      AdasPlantModel0_P->PlntWhlMinSlipRatio,
      AdasPlantModel0_P->PlntWhlMaxSlipAngle,
      AdasPlantModel0_P->PlntWhlMinSlipAngle, AdasPlantModel0_P->PlntWhlMinCmbr,
      AdasPlantModel0_P->PlntWhlMaxCmbr, AdasPlantModel0_P->PlntWhlLongSpd,
      AdasPlantModel0_P->PlntWhlUnldRadius, AdasPlantModel0_P->PlntWhlRimRadius,
      AdasPlantModel0_P->PlntWhlNomPress, AdasPlantModel0_P->PlntWhlNomNorlForce,
      localP->MagicTireConstInput_vdynMF[38], localP->
      MagicTireConstInput_vdynMF[43], localP->MagicTireConstInput_vdynMF[42],
      localP->MagicTireConstInput_vdynMF[44], localP->
      MagicTireConstInput_vdynMF[45], localP->MagicTireConstInput_vdynMF[46],
      localP->MagicTireConstInput_vdynMF[47], localP->
      MagicTireConstInput_vdynMF[48], localP->MagicTireConstInput_vdynMF[49],
      localP->MagicTireConstInput_vdynMF[51], localP->
      MagicTireConstInput_vdynMF[52], localP->MagicTireConstInput_vdynMF[54],
      localP->MagicTireConstInput_vdynMF[55], localP->
      MagicTireConstInput_vdynMF[62], localP->MagicTireConstInput_vdynMF[63],
      localP->MagicTireConstInput_vdynMF[134],
      localP->MagicTireConstInput_vdynMF[135],
      localP->MagicTireConstInput_vdynMF[136],
      localP->MagicTireConstInput_vdynMF[137],
      localP->MagicTireConstInput_vdynMF[138],
      localP->MagicTireConstInput_vdynMF[139],
      localP->MagicTireConstInput_vdynMF[140],
      localP->MagicTireConstInput_vdynMF[141],
      localP->MagicTireConstInput_vdynMF[142],
      localP->MagicTireConstInput_vdynMF[143],
      localP->MagicTireConstInput_vdynMF[144],
      localP->MagicTireConstInput_vdynMF[145],
      localP->MagicTireConstInput_vdynMF[146],
      localP->MagicTireConstInput_vdynMF[147],
      localP->MagicTireConstInput_vdynMF[148],
      localP->MagicTireConstInput_vdynMF[149],
      localP->MagicTireConstInput_vdynMF[150],
      localP->MagicTireConstInput_vdynMF[151],
      localP->MagicTireConstInput_vdynMF[152],
      localP->MagicTireConstInput_vdynMF[153],
      localP->MagicTireConstInput_vdynMF[154],
      localP->MagicTireConstInput_vdynMF[155],
      localP->MagicTireConstInput_vdynMF[156],
      localP->MagicTireConstInput_vdynMF[157],
      localP->MagicTireConstInput_vdynMF[158],
      localP->MagicTireConstInput_vdynMF[161],
      localP->MagicTireConstInput_vdynMF[162],
      localP->MagicTireConstInput_vdynMF[163],
      localP->MagicTireConstInput_vdynMF[164],
      localP->MagicTireConstInput_vdynMF[165],
      localP->MagicTireConstInput_vdynMF[166],
      localP->MagicTireConstInput_vdynMF[167],
      localP->MagicTireConstInput_vdynMF[168],
      localP->MagicTireConstInput_vdynMF[169],
      localP->MagicTireConstInput_vdynMF[170],
      localP->MagicTireConstInput_vdynMF[174],
      localP->MagicTireConstInput_vdynMF[175],
      localP->MagicTireConstInput_vdynMF[176],
      localP->MagicTireConstInput_vdynMF[177],
      localP->MagicTireConstInput_vdynMF[178],
      localP->MagicTireConstInput_vdynMF[179],
      localP->MagicTireConstInput_vdynMF[180],
      localP->MagicTireConstInput_vdynMF[182],
      localP->MagicTireConstInput_vdynMF[183],
      localP->MagicTireConstInput_vdynMF[184],
      localP->MagicTireConstInput_vdynMF[185],
      localP->MagicTireConstInput_vdynMF[186],
      localP->MagicTireConstInput_vdynMF[187],
      localP->MagicTireConstInput_vdynMF[188],
      localP->MagicTireConstInput_vdynMF[189],
      localP->MagicTireConstInput_vdynMF[190],
      localP->MagicTireConstInput_vdynMF[195],
      localP->MagicTireConstInput_vdynMF[196],
      localP->MagicTireConstInput_vdynMF[197],
      localP->MagicTireConstInput_vdynMF[198],
      localP->MagicTireConstInput_vdynMF[199],
      localP->MagicTireConstInput_vdynMF[200],
      localP->MagicTireConstInput_vdynMF[201],
      localP->MagicTireConstInput_vdynMF[202],
      localP->MagicTireConstInput_vdynMF[203],
      localP->MagicTireConstInput_vdynMF[205],
      localP->MagicTireConstInput_vdynMF[206],
      localP->MagicTireConstInput_vdynMF[207],
      localP->MagicTireConstInput_vdynMF[208],
      localP->MagicTireConstInput_vdynMF[209],
      localP->MagicTireConstInput_vdynMF[210],
      localP->MagicTireConstInput_vdynMF[213],
      localP->MagicTireConstInput_vdynMF[214],
      localP->MagicTireConstInput_vdynMF[215],
      localP->MagicTireConstInput_vdynMF[216],
      localP->MagicTireConstInput_vdynMF[217],
      localP->MagicTireConstInput_vdynMF[218],
      localP->MagicTireConstInput_vdynMF[219],
      localP->MagicTireConstInput_vdynMF[220],
      localP->MagicTireConstInput_vdynMF[221],
      localP->MagicTireConstInput_vdynMF[222],
      localP->MagicTireConstInput_vdynMF[223],
      localP->MagicTireConstInput_vdynMF[224],
      localP->MagicTireConstInput_vdynMF[225],
      localP->MagicTireConstInput_vdynMF[226],
      localP->MagicTireConstInput_vdynMF[227],
      localP->MagicTireConstInput_vdynMF[229],
      localP->MagicTireConstInput_vdynMF[230],
      localP->MagicTireConstInput_vdynMF[231],
      localP->MagicTireConstInput_vdynMF[232],
      localP->MagicTireConstInput_vdynMF[233],
      localP->MagicTireConstInput_vdynMF[234],
      localP->MagicTireConstInput_vdynMF[235],
      localP->MagicTireConstInput_vdynMF[237],
      localP->MagicTireConstInput_vdynMF[240],
      localP->MagicTireConstInput_vdynMF[242],
      localP->MagicTireConstInput_vdynMF[242],
      localP->MagicTireConstInput_vdynMF[243],
      localP->MagicTireConstInput_vdynMF[244],
      localP->MagicTireConstInput_vdynMF[245],
      localP->MagicTireConstInput_vdynMF[246],
      localP->MagicTireConstInput_vdynMF[248],
      localP->MagicTireConstInput_vdynMF[251],
      localP->MagicTireConstInput_vdynMF[252],
      localP->MagicTireConstInput_vdynMF[253],
      localP->MagicTireConstInput_vdynMF[254],
      localP->MagicTireConstInput_vdynMF[256],
      localP->MagicTireConstInput_vdynMF[257],
      localP->MagicTireConstInput_vdynMF[258],
      localP->MagicTireConstInput_vdynMF[259],
      localP->MagicTireConstInput_vdynMF[260],
      localP->MagicTireConstInput_vdynMF[261],
      localP->MagicTireConstInput_vdynMF[262],
      localP->MagicTireConstInput_vdynMF[263],
      localP->MagicTireConstInput_vdynMF[264],
      localP->MagicTireConstInput_vdynMF[265],
      localP->MagicTireConstInput_vdynMF[266],
      localP->MagicTireConstInput_vdynMF[267],
      localP->MagicTireConstInput_vdynMF[268],
      localP->MagicTireConstInput_vdynMF[269],
      localP->MagicTireConstInput_vdynMF[270],
      localP->MagicTireConstInput_vdynMF[271],
      localP->MagicTireConstInput_vdynMF[272],
      localP->MagicTireConstInput_vdynMF[273],
      localP->MagicTireConstInput_vdynMF[274],
      localP->MagicTireConstInput_vdynMF[275],
      localP->MagicTireConstInput_vdynMF[276],
      localP->MagicTireConstInput_vdynMF[277],
      localP->MagicTireConstInput_vdynMF[278], AdasPlantModel0_P->PlntWhlWidth,
      localP->MagicTireConstInput_vdynMF[86], localP->
      MagicTireConstInput_vdynMF[87], localP->MagicTireConstInput_vdynMF[88],
      localP->MagicTireConstInput_vdynMF[89], localP->
      MagicTireConstInput_vdynMF[171], localP->MagicTireConstInput_vdynMF[172],
      localP->MagicTireConstInput_vdynMF[173],
      localP->MagicTireConstInput_vdynMF[50], localP->
      MagicTireConstInput_vdynMF[64], localP->MagicTireConstInput_vdynMF[65],
      localP->MagicTireConstInput_vdynMF[79], localP->
      MagicTireConstInput_vdynMF[80], localP->MagicTireConstInput_vdynMF[81],
      localP->MagicTireConstInput_vdynMF[82], localP->
      MagicTireConstInput_vdynMF[83], localP->MagicTireConstInput_vdynMF[84],
      localB->Integrator, localB->Integrator_i, rtb_Product,
      localP->vertType_Value, rtb_ImpAsg_InsertedFor_ydotWhee,
      rtb_ImpAsg_InsertedFor_xdotWhee, localB->Mx_c, rtb_My, localB->Mz_j,
      localB->Re, localB->Kappa, localB->Alpha, rtb_sig_x, rtb_sig_y, localB->a,
      localB->b);
  }

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[0] = localB->Mx_c[0];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[4] = localB->Integrator_e[0];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[8] = localB->Mz_j[0];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[1] = localB->Mx_c[1];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[5] = localB->Integrator_e[1];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[9] = localB->Mz_j[1];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[2] = localB->Mx_c[2];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[6] = localB->Integrator_e[2];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[10] = localB->Mz_j[2];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[3] = localB->Mx_c[3];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[7] = localB->Integrator_e[3];

  /* SignalConversion generated from: '<S287>/Vector Concatenate1' */
  rtb_VectorConcatenate8[11] = localB->Mz_j[3];
  for (i = 0; i < 4; i++) {
    /* Math: '<S287>/Math Function1' incorporates:
     *  Concatenate: '<S287>/Vector Concatenate1'
     */
    localB->MathFunction1[3 * i] = rtb_VectorConcatenate8[i];
    localB->MathFunction1[3 * i + 1] = rtb_VectorConcatenate8[i + 4];
    localB->MathFunction1[3 * i + 2] = rtb_VectorConcatenate8[i + 8];
  }

  /* Outputs for Iterator SubSystem: '<S287>/Wheel to Body Transform' incorporates:
   *  ForEach: '<S383>/For Each'
   */
  for (ForEach_itr_m = 0; ForEach_itr_m < 4; ForEach_itr_m++) {
    /* Product: '<S384>/Element Product' incorporates:
     *  Abs: '<S409>/Abs1'
     *  Constant: '<S383>/Constant1'
     *  ForEachSliceSelector generated from: '<S383>/Forces'
     *  ForEachSliceSelector generated from: '<S383>/Moments'
     *  ForEachSliceSelector generated from: '<S383>/Re'
     *  ForEachSliceSelector generated from: '<S383>/WheelAngles'
     *  Math: '<S287>/Math Function'
     *  SignalConversion generated from: '<S386>/sincos'
     *  Sum: '<S383>/Add'
     */
    rtb_Abs_k[0] = localP->CoreSubsys_pn.Constant1_Value[1];
    rtb_Abs_k[1] = localB->Re[ForEach_itr_m];
    rtb_Abs_k[2] = localP->CoreSubsys_pn.Constant1_Value[0];
    rtb_Abs_k[3] = localB->Re[ForEach_itr_m];
    i = 3 * ForEach_itr_m + 2;
    rtb_UnaryMinus2_idx_0 = localB->MathFunction[i];
    tmp[0] = rtb_UnaryMinus2_idx_0;
    rtb_Abs_k[4] = localP->CoreSubsys_pn.Constant1_Value[0];
    rtb_Integrator1_p = localB->MathFunction[3 * ForEach_itr_m];
    tmp[1] = rtb_Integrator1_p;
    iy = 3 * ForEach_itr_m + 1;
    lam_muy_prime_idx_1 = localB->MathFunction[iy];
    tmp[3] = lam_muy_prime_idx_1;
    rtb_Abs_k[5] = localP->CoreSubsys_pn.Constant1_Value[1];
    tmp[2] = lam_muy_prime_idx_1;
    tmp[4] = rtb_UnaryMinus2_idx_0;
    tmp[5] = rtb_Integrator1_p;
    for (ibmat = 0; ibmat < 6; ibmat++) {
      rtb_Abs1_d[ibmat] = rtb_Abs_k[ibmat] * tmp[ibmat];
    }

    /* End of Product: '<S384>/Element Product' */

    /* Sum: '<S383>/Add' incorporates:
     *  ForEachSliceSelector generated from: '<S383>/Moments'
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     *  Sum: '<S384>/Sum'
     */
    rtb_IntegratorSecondOrderLimite[0] = (rtb_Abs1_d[0] - rtb_Abs1_d[3]) +
      localB->MathFunction1[3 * ForEach_itr_m];
    rtb_IntegratorSecondOrderLimite[1] = (rtb_Abs1_d[1] - rtb_Abs1_d[4]) +
      localB->MathFunction1[iy];
    rtb_IntegratorSecondOrderLimite[2] = (rtb_Abs1_d[2] - rtb_Abs1_d[5]) +
      localB->MathFunction1[i];
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      for (ibmat = 0; ibmat < 3; ibmat++) {
        /* Math: '<S383>/Transpose1' incorporates:
         *  ForEachSliceSelector generated from: '<S383>/DCM'
         */
        Itemp_tmp = 9 * ForEach_itr_m + ibmat;

        /* Math: '<S383>/Transpose1' incorporates:
         *  Constant: '<S287>/Constant'
         *  ForEachSliceSelector generated from: '<S383>/DCM'
         */
        localB->CoreSubsys_pn[ForEach_itr_m].Transpose1[3 * ibmat] =
          localP->Constant_Value_eb[Itemp_tmp];
        localB->CoreSubsys_pn[ForEach_itr_m].Transpose1[3 * ibmat + 1] =
          localP->Constant_Value_eb[Itemp_tmp + 3];
        localB->CoreSubsys_pn[ForEach_itr_m].Transpose1[3 * ibmat + 2] =
          localP->Constant_Value_eb[Itemp_tmp + 6];
      }
    }

    /* SignalConversion generated from: '<S386>/sincos' incorporates:
     *  Concatenate: '<S376>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S383>/WheelAngles'
     */
    rtb_Switch1_h[0] = localB->VectorConcatenate3[i];
    rtb_Switch1_h[1] = localB->VectorConcatenate3[iy];
    rtb_Switch1_h[2] = localB->VectorConcatenate3[3 * ForEach_itr_m];

    /* Trigonometry: '<S386>/sincos' */
    rtb_sincos_o1[0] = std::cos(rtb_Switch1_h[0]);
    dpi_idx_2 = std::sin(rtb_Switch1_h[0]);
    rtb_sincos_o1[1] = std::cos(rtb_Switch1_h[1]);
    dpi_idx_3 = std::sin(rtb_Switch1_h[1]);
    rtb_sincos_o1[2] = std::cos(rtb_Switch1_h[2]);
    Fzo_prime_idx_0 = std::sin(rtb_Switch1_h[2]);

    /* Fcn: '<S386>/Fcn11' */
    rtb_VectorConcatenate_ci[0] = rtb_sincos_o1[0] * rtb_sincos_o1[1];

    /* Fcn: '<S386>/Fcn21' incorporates:
     *  Fcn: '<S386>/Fcn22'
     *  Trigonometry: '<S386>/sincos'
     */
    dpi_idx_0 = dpi_idx_3 * Fzo_prime_idx_0;
    rtb_VectorConcatenate_ci[1] = dpi_idx_0 * rtb_sincos_o1[0] - dpi_idx_2 *
      rtb_sincos_o1[2];

    /* Fcn: '<S386>/Fcn31' incorporates:
     *  Fcn: '<S386>/Fcn32'
     *  Trigonometry: '<S386>/sincos'
     */
    dpi_idx_1 = dpi_idx_3 * rtb_sincos_o1[2];
    rtb_VectorConcatenate_ci[2] = dpi_idx_1 * rtb_sincos_o1[0] + dpi_idx_2 *
      Fzo_prime_idx_0;

    /* Fcn: '<S386>/Fcn12' incorporates:
     *  Trigonometry: '<S386>/sincos'
     */
    rtb_VectorConcatenate_ci[3] = dpi_idx_2 * rtb_sincos_o1[1];

    /* Fcn: '<S386>/Fcn22' incorporates:
     *  Trigonometry: '<S386>/sincos'
     */
    rtb_VectorConcatenate_ci[4] = dpi_idx_0 * dpi_idx_2 + rtb_sincos_o1[0] *
      rtb_sincos_o1[2];

    /* Fcn: '<S386>/Fcn32' incorporates:
     *  Trigonometry: '<S386>/sincos'
     */
    rtb_VectorConcatenate_ci[5] = dpi_idx_1 * dpi_idx_2 - rtb_sincos_o1[0] *
      Fzo_prime_idx_0;

    /* Fcn: '<S386>/Fcn13' incorporates:
     *  Trigonometry: '<S386>/sincos'
     */
    rtb_VectorConcatenate_ci[6] = -dpi_idx_3;

    /* Fcn: '<S386>/Fcn23' incorporates:
     *  Trigonometry: '<S386>/sincos'
     */
    rtb_VectorConcatenate_ci[7] = rtb_sincos_o1[1] * Fzo_prime_idx_0;

    /* Fcn: '<S386>/Fcn33' */
    rtb_VectorConcatenate_ci[8] = rtb_sincos_o1[1] * rtb_sincos_o1[2];
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Trigonometry: '<S385>/sincos' incorporates:
       *  Constant: '<S383>/Constant'
       *  SignalConversion generated from: '<S385>/sincos'
       */
      dpi_idx_2 = std::cos(localP->CoreSubsys_pn.Constant_Value[2]);
      dpi_idx_3 = std::sin(localP->CoreSubsys_pn.Constant_Value[2]);
      Fzo_prime_idx_0 = std::cos(localP->CoreSubsys_pn.Constant_Value[1]);
      Fzo_prime_idx_1 = std::sin(localP->CoreSubsys_pn.Constant_Value[1]);
      Fzo_prime_idx_2 = std::cos(localP->CoreSubsys_pn.Constant_Value[0]);
      Fzo_prime_idx_3 = std::sin(localP->CoreSubsys_pn.Constant_Value[0]);

      /* Fcn: '<S385>/Fcn11' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[0] = dpi_idx_2 *
        Fzo_prime_idx_0;

      /* Fcn: '<S385>/Fcn21' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Fcn: '<S385>/Fcn22'
       *  Trigonometry: '<S385>/sincos'
       */
      dpi_idx_0 = Fzo_prime_idx_1 * Fzo_prime_idx_3;
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[1] = dpi_idx_0 *
        dpi_idx_2 - dpi_idx_3 * Fzo_prime_idx_2;

      /* Fcn: '<S385>/Fcn31' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Fcn: '<S385>/Fcn32'
       *  Trigonometry: '<S385>/sincos'
       */
      dpi_idx_1 = Fzo_prime_idx_1 * Fzo_prime_idx_2;
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[2] = dpi_idx_1 *
        dpi_idx_2 + dpi_idx_3 * Fzo_prime_idx_3;

      /* Fcn: '<S385>/Fcn12' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Trigonometry: '<S385>/sincos'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[3] = dpi_idx_3 *
        Fzo_prime_idx_0;

      /* Fcn: '<S385>/Fcn22' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Trigonometry: '<S385>/sincos'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[4] = dpi_idx_0 *
        dpi_idx_3 + dpi_idx_2 * Fzo_prime_idx_2;

      /* Fcn: '<S385>/Fcn32' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Trigonometry: '<S385>/sincos'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[5] = dpi_idx_1 *
        dpi_idx_3 - dpi_idx_2 * Fzo_prime_idx_3;

      /* Fcn: '<S385>/Fcn13' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Trigonometry: '<S385>/sincos'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[6] =
        -Fzo_prime_idx_1;

      /* Fcn: '<S385>/Fcn23' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       *  Trigonometry: '<S385>/sincos'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[7] =
        Fzo_prime_idx_0 * Fzo_prime_idx_3;

      /* Fcn: '<S385>/Fcn33' incorporates:
       *  Concatenate: '<S387>/Vector Concatenate'
       */
      localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[8] =
        Fzo_prime_idx_0 * Fzo_prime_idx_2;
    }

    /* Product: '<S383>/Divide1' incorporates:
     *  Concatenate: '<S387>/Vector Concatenate'
     *  Math: '<S383>/Transpose'
     */
    for (i = 0; i < 3; i++) {
      /* Math: '<S383>/Transpose' incorporates:
       *  Concatenate: '<S489>/Vector Concatenate'
       */
      dpi_idx_0 = rtb_VectorConcatenate_ci[3 * i + 1];
      dpi_idx_1 = rtb_VectorConcatenate_ci[3 * i];
      dpi_idx_2 = rtb_VectorConcatenate_ci[3 * i + 2];
      for (iy = 0; iy < 3; iy++) {
        rtb_Transpose1[i + 3 * iy] = (localB->CoreSubsys_pn[ForEach_itr_m].
          VectorConcatenate[3 * iy + 1] * dpi_idx_0 + localB->
          CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[3 * iy] * dpi_idx_1) +
          localB->CoreSubsys_pn[ForEach_itr_m].VectorConcatenate[3 * iy + 2] *
          dpi_idx_2;
      }
    }

    for (i = 0; i < 3; i++) {
      /* Product: '<S383>/Divide2' */
      dpi_idx_0 = 0.0;

      /* Product: '<S383>/Divide3' */
      dpi_idx_1 = 0.0;
      for (iy = 0; iy < 3; iy++) {
        rtb_UnaryMinus2_idx_0 = (rtb_Transpose1[3 * iy + 1] *
          localB->CoreSubsys_pn[ForEach_itr_m].Transpose1[i + 3] +
          rtb_Transpose1[3 * iy] * localB->CoreSubsys_pn[ForEach_itr_m].
          Transpose1[i]) + rtb_Transpose1[3 * iy + 2] * localB->
          CoreSubsys_pn[ForEach_itr_m].Transpose1[i + 6];

        /* Product: '<S383>/Divide2' incorporates:
         *  ForEachSliceSelector generated from: '<S383>/Forces'
         *  Math: '<S287>/Math Function'
         *  Math: '<S383>/Transpose1'
         *  Math: '<S394>/Transpose'
         */
        dpi_idx_0 += localB->MathFunction[3 * ForEach_itr_m + iy] *
          rtb_UnaryMinus2_idx_0;

        /* Product: '<S383>/Divide3' incorporates:
         *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
         */
        dpi_idx_1 += rtb_UnaryMinus2_idx_0 * rtb_IntegratorSecondOrderLimite[iy];
      }

      /* Product: '<S383>/Divide3' incorporates:
       *  Math: '<S383>/Transpose1'
       *  Math: '<S394>/Transpose'
       */
      rtb_Switch1_h[i] = dpi_idx_1;

      /* Product: '<S383>/Divide2' */
      rtb_Divide2[i] = dpi_idx_0;
    }

    /* End of Product: '<S383>/Divide1' */

    /* ForEachSliceAssignment generated from: '<S383>/Mz' */
    rtb_ImpAsg_InsertedFor_Mz_at_in[ForEach_itr_m] = rtb_Switch1_h[2];

    /* ForEachSliceAssignment generated from: '<S383>/My' */
    rtb_ImpAsg_InsertedFor_My_at_in[ForEach_itr_m] = rtb_Switch1_h[1];

    /* ForEachSliceAssignment generated from: '<S383>/Mx' */
    rtb_ImpAsg_InsertedFor_Mx_at_in[ForEach_itr_m] = rtb_Switch1_h[0];

    /* ForEachSliceAssignment generated from: '<S383>/Fz' */
    rtb_ImpAsg_InsertedFor_Fz_at_in[ForEach_itr_m] = rtb_Divide2[2];

    /* ForEachSliceAssignment generated from: '<S383>/Fy' */
    rtb_ImpAsg_InsertedFor_Fy_at_in[ForEach_itr_m] = rtb_Divide2[1];

    /* ForEachSliceAssignment generated from: '<S383>/Fx' */
    rtb_ImpAsg_InsertedFor_Fx_at_in[ForEach_itr_m] = rtb_Divide2[0];
  }

  /* End of Outputs for SubSystem: '<S287>/Wheel to Body Transform' */

  /* Selector: '<S108>/Selector' */
  rtb_Selector[0] = rtb_ImpAsg_InsertedFor_Fx_at_in[0];

  /* Selector: '<S108>/Selector1' */
  rtb_Selector1_e[0] = rtb_ImpAsg_InsertedFor_Fy_at_in[0];

  /* Selector: '<S108>/Selector2' */
  rtb_Selector2[0] = rtb_ImpAsg_InsertedFor_Fz_at_in[0];

  /* Selector: '<S108>/Selector3' incorporates:
   *  Concatenate: '<S120>/Matrix Concatenate'
   */
  rtb_Selector3[0] = rtb_ImpAsg_InsertedFor_Mz_at_in[0];

  /* Selector: '<S108>/Selector' */
  rtb_Selector[1] = rtb_ImpAsg_InsertedFor_Fx_at_in[1];

  /* Selector: '<S108>/Selector1' */
  rtb_Selector1_e[1] = rtb_ImpAsg_InsertedFor_Fy_at_in[1];

  /* Selector: '<S108>/Selector2' */
  rtb_Selector2[1] = rtb_ImpAsg_InsertedFor_Fz_at_in[1];

  /* Selector: '<S108>/Selector3' incorporates:
   *  Concatenate: '<S120>/Matrix Concatenate'
   */
  rtb_Selector3[1] = rtb_ImpAsg_InsertedFor_Mz_at_in[1];

  /* UnaryMinus: '<S382>/Unary Minus1' */
  localB->z[0] = -localB->IntegratorSecondOrder_o1[0];

  /* Concatenate: '<S291>/Matrix Concatenate2' incorporates:
   *  UnaryMinus: '<S382>/Unary Minus1'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  rtb_MatrixConcatenate2[0] = -localB->IntegratorSecondOrder_o1[0];
  rtb_MatrixConcatenate2[1] = -localB->IntegratorSecondOrder_o2[0];

  /* UnaryMinus: '<S382>/Unary Minus1' */
  localB->z[1] = -localB->IntegratorSecondOrder_o1[1];

  /* Concatenate: '<S291>/Matrix Concatenate2' incorporates:
   *  UnaryMinus: '<S382>/Unary Minus1'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  rtb_MatrixConcatenate2[2] = -localB->IntegratorSecondOrder_o1[1];
  rtb_MatrixConcatenate2[3] = -localB->IntegratorSecondOrder_o2[1];

  /* UnaryMinus: '<S382>/Unary Minus1' */
  localB->z[2] = -localB->IntegratorSecondOrder_o1[2];

  /* Concatenate: '<S291>/Matrix Concatenate2' incorporates:
   *  UnaryMinus: '<S382>/Unary Minus1'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  rtb_MatrixConcatenate2[4] = -localB->IntegratorSecondOrder_o1[2];
  rtb_MatrixConcatenate2[5] = -localB->IntegratorSecondOrder_o2[2];

  /* UnaryMinus: '<S382>/Unary Minus1' */
  localB->z[3] = -localB->IntegratorSecondOrder_o1[3];

  /* Concatenate: '<S291>/Matrix Concatenate2' incorporates:
   *  UnaryMinus: '<S382>/Unary Minus1'
   *  UnaryMinus: '<S382>/Unary Minus2'
   */
  rtb_MatrixConcatenate2[6] = -localB->IntegratorSecondOrder_o1[3];
  rtb_MatrixConcatenate2[7] = -localB->IntegratorSecondOrder_o2[3];

  /* Integrator: '<S406>/xe,ye,ze' */
  localB->xeyeze[0] = localX->xeyeze_CSTATE[0];

  /* Integrator: '<S412>/phi theta psi' */
  localB->phithetapsi[0] = localX->phithetapsi_CSTATE[0];

  /* Integrator: '<S406>/xe,ye,ze' */
  localB->xeyeze[1] = localX->xeyeze_CSTATE[1];

  /* Integrator: '<S412>/phi theta psi' */
  localB->phithetapsi[1] = localX->phithetapsi_CSTATE[1];

  /* Integrator: '<S406>/xe,ye,ze' */
  localB->xeyeze[2] = localX->xeyeze_CSTATE[2];

  /* Integrator: '<S412>/phi theta psi' */
  localB->phithetapsi[2] = localX->phithetapsi_CSTATE[2];

  /* Outputs for Iterator SubSystem: '<S434>/Unwrap' incorporates:
   *  ForEach: '<S438>/For Each'
   */
  for (ForEach_itr_c = 0; ForEach_itr_c < 3; ForEach_itr_c++) {
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S439>/Memory1' */
      localB->CoreSubsys_b[ForEach_itr_c].Memory1 = localDW->
        CoreSubsys_b[ForEach_itr_c].Memory1_PreviousInput;
    }

    /* RelationalOperator: '<S440>/Compare' incorporates:
     *  Abs: '<S439>/Abs'
     *  Constant: '<S440>/Constant'
     *  ForEachSliceSelector generated from: '<S438>/u'
     *  Sum: '<S439>/Subtract'
     */
    localB->CoreSubsys_b[ForEach_itr_c].Compare = (std::abs(localB->
      phithetapsi[ForEach_itr_c] - localB->CoreSubsys_b[ForEach_itr_c].Memory1) >=
      localP->CoreSubsys_b.CompareToConstant_const);
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Outputs for Triggered SubSystem: '<S439>/Function-Call Subsystem' incorporates:
       *  TriggerPort: '<S441>/function'
       */
      if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
        if (localB->CoreSubsys_b[ForEach_itr_c].Compare &&
            (localZCE->CoreSubsys_b[ForEach_itr_c].
             FunctionCallSubsystem_Trig_ZCE != POS_ZCSIG)) {
          /* ForEachSliceSelector generated from: '<S438>/u' */
          rtb_Integrator1_p = localB->phithetapsi[ForEach_itr_c];

          /* Signum: '<S441>/Sign' */
          if (std::isnan(rtb_Integrator1_p)) {
            rtb_UnaryMinus2_idx_0 = (rtNaN);
          } else if (rtb_Integrator1_p < 0.0) {
            rtb_UnaryMinus2_idx_0 = -1.0;
          } else {
            rtb_UnaryMinus2_idx_0 = (rtb_Integrator1_p > 0.0);
          }

          /* Sum: '<S441>/Sum' incorporates:
           *  Constant: '<S441>/Constant'
           *  Product: '<S441>/Product'
           *  Signum: '<S441>/Sign'
           *  UnitDelay: '<S441>/Unit Delay'
           */
          localB->CoreSubsys_b[ForEach_itr_c].Sum = localDW->
            CoreSubsys_b[ForEach_itr_c].UnitDelay_DSTATE - rtb_UnaryMinus2_idx_0
            * localP->CoreSubsys_b.Constant_Value;

          /* Update for UnitDelay: '<S441>/Unit Delay' */
          localDW->CoreSubsys_b[ForEach_itr_c].UnitDelay_DSTATE =
            localB->CoreSubsys_b[ForEach_itr_c].Sum;
        }

        localZCE->CoreSubsys_b[ForEach_itr_c].FunctionCallSubsystem_Trig_ZCE =
          localB->CoreSubsys_b[ForEach_itr_c].Compare;
      }

      /* End of Outputs for SubSystem: '<S439>/Function-Call Subsystem' */
    }

    /* ForEachSliceAssignment generated from: '<S438>/y' incorporates:
     *  ForEachSliceSelector generated from: '<S438>/u'
     *  Sum: '<S439>/Subtract1'
     */
    rty_VehFdbk[ForEach_itr_c] = localB->CoreSubsys_b[ForEach_itr_c].Sum +
      localB->phithetapsi[ForEach_itr_c];
  }

  /* End of Outputs for SubSystem: '<S434>/Unwrap' */

  /* SignalConversion generated from: '<S457>/sincos' */
  rtb_sincos_o1[0] = rty_VehFdbk[2];
  rtb_sincos_o1[1] = rty_VehFdbk[1];
  rtb_sincos_o1[2] = rty_VehFdbk[0];

  /* Trigonometry: '<S457>/sincos' incorporates:
   *  Trigonometry: '<S474>/sincos'
   *  Trigonometry: '<S485>/sincos'
   */
  Fzo_prime_idx_3 = std::sin(rtb_sincos_o1[0]);
  rtb_Divide_pl = std::cos(rtb_sincos_o1[0]);
  dpi_idx_2 = std::sin(rtb_sincos_o1[1]);
  rtb_Saturation_0 = std::cos(rtb_sincos_o1[1]);
  rtb_Gain1_g0 = std::sin(rtb_sincos_o1[2]);
  rtb_UnaryMinus2_idx_0 = std::cos(rtb_sincos_o1[2]);

  /* Fcn: '<S457>/Fcn11' incorporates:
   *  Fcn: '<S474>/Fcn11'
   *  Fcn: '<S485>/Fcn11'
   *  Trigonometry: '<S457>/sincos'
   */
  dpi_idx_0 = rtb_Divide_pl * rtb_Saturation_0;
  rtb_VectorConcatenate_ci[0] = dpi_idx_0;

  /* Fcn: '<S457>/Fcn21' incorporates:
   *  Fcn: '<S457>/Fcn22'
   *  Fcn: '<S474>/Fcn21'
   *  Fcn: '<S485>/Fcn21'
   *  Trigonometry: '<S457>/sincos'
   */
  dpi_idx_1 = dpi_idx_2 * rtb_Gain1_g0;
  dpi_idx_3 = dpi_idx_1 * rtb_Divide_pl - Fzo_prime_idx_3 *
    rtb_UnaryMinus2_idx_0;
  rtb_VectorConcatenate_ci[1] = dpi_idx_3;

  /* Fcn: '<S457>/Fcn31' incorporates:
   *  Fcn: '<S457>/Fcn32'
   *  Fcn: '<S474>/Fcn31'
   *  Fcn: '<S485>/Fcn31'
   *  Trigonometry: '<S457>/sincos'
   */
  Fzo_prime_idx_0 = dpi_idx_2 * rtb_UnaryMinus2_idx_0;
  Fzo_prime_idx_1 = Fzo_prime_idx_0 * rtb_Divide_pl + Fzo_prime_idx_3 *
    rtb_Gain1_g0;
  rtb_VectorConcatenate_ci[2] = Fzo_prime_idx_1;

  /* Fcn: '<S457>/Fcn12' incorporates:
   *  Fcn: '<S474>/Fcn12'
   *  Fcn: '<S485>/Fcn12'
   *  Trigonometry: '<S457>/sincos'
   */
  Fzo_prime_idx_2 = Fzo_prime_idx_3 * rtb_Saturation_0;
  rtb_VectorConcatenate_ci[3] = Fzo_prime_idx_2;

  /* Fcn: '<S457>/Fcn22' incorporates:
   *  Fcn: '<S474>/Fcn22'
   *  Fcn: '<S485>/Fcn22'
   *  Trigonometry: '<S457>/sincos'
   */
  dpi_idx_1 = dpi_idx_1 * Fzo_prime_idx_3 + rtb_Divide_pl *
    rtb_UnaryMinus2_idx_0;
  rtb_VectorConcatenate_ci[4] = dpi_idx_1;

  /* Fcn: '<S457>/Fcn32' incorporates:
   *  Fcn: '<S474>/Fcn32'
   *  Fcn: '<S485>/Fcn32'
   *  Trigonometry: '<S457>/sincos'
   */
  Fzo_prime_idx_0 = Fzo_prime_idx_0 * Fzo_prime_idx_3 - rtb_Divide_pl *
    rtb_Gain1_g0;
  rtb_VectorConcatenate_ci[5] = Fzo_prime_idx_0;

  /* Fcn: '<S457>/Fcn13' incorporates:
   *  Trigonometry: '<S457>/sincos'
   */
  rtb_VectorConcatenate_ci[6] = -dpi_idx_2;

  /* Fcn: '<S457>/Fcn23' incorporates:
   *  Fcn: '<S474>/Fcn23'
   *  Fcn: '<S485>/Fcn23'
   *  Trigonometry: '<S457>/sincos'
   */
  Fzo_prime_idx_3 = rtb_Saturation_0 * rtb_Gain1_g0;
  rtb_VectorConcatenate_ci[7] = Fzo_prime_idx_3;

  /* Fcn: '<S457>/Fcn33' incorporates:
   *  Fcn: '<S474>/Fcn33'
   *  Fcn: '<S485>/Fcn33'
   *  Trigonometry: '<S457>/sincos'
   */
  rtb_Saturation_0 *= rtb_UnaryMinus2_idx_0;
  rtb_VectorConcatenate_ci[8] = rtb_Saturation_0;

  /* Math: '<S456>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose1[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose1[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S456>/Transpose1' */

  /* Product: '<S459>/Product' incorporates:
   *  Selector: '<S450>/Selector1'
   */
  rtb_Divide_pl = localB->Selector1[1];
  rtb_Gain1_g0 = localB->Selector1[0];
  lam_muy_prime_idx_3 = localB->Selector1[2];
  for (iy = 0; iy < 3; iy++) {
    /* Sum: '<S456>/Add' incorporates:
     *  Math: '<S456>/Transpose1'
     */
    localB->Add[iy] = ((rtb_Transpose1[iy + 3] * rtb_Divide_pl +
                        rtb_Transpose1[iy] * rtb_Gain1_g0) + rtb_Transpose1[iy +
                       6] * lam_muy_prime_idx_3) + localB->xeyeze[iy];

    /* Trigonometry: '<S465>/sincos' */
    rtb_UnaryMinus2_idx_0 = rtb_sincos_o1[iy];
    rtb_IntegratorSecondOrderLimite[iy] = std::sin(rtb_UnaryMinus2_idx_0);
    rtb_Switch1_h[iy] = std::cos(rtb_UnaryMinus2_idx_0);
  }

  /* End of Product: '<S459>/Product' */

  /* Fcn: '<S465>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

  /* Fcn: '<S465>/Fcn21' incorporates:
   *  Fcn: '<S465>/Fcn22'
   */
  rtb_Product_py = rtb_IntegratorSecondOrderLimite[1] *
    rtb_IntegratorSecondOrderLimite[2];
  rtb_VectorConcatenate_ci[1] = rtb_Product_py * rtb_Switch1_h[0] -
    rtb_IntegratorSecondOrderLimite[0] * rtb_Switch1_h[2];

  /* Fcn: '<S465>/Fcn31' incorporates:
   *  Fcn: '<S465>/Fcn32'
   */
  rtb_Smallangleapproximationford = rtb_IntegratorSecondOrderLimite[1] *
    rtb_Switch1_h[2];
  rtb_VectorConcatenate_ci[2] = rtb_Smallangleapproximationford * rtb_Switch1_h
    [0] + rtb_IntegratorSecondOrderLimite[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S465>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = rtb_IntegratorSecondOrderLimite[0] *
    rtb_Switch1_h[1];

  /* Fcn: '<S465>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = rtb_Product_py *
    rtb_IntegratorSecondOrderLimite[0] + rtb_Switch1_h[0] * rtb_Switch1_h[2];

  /* Fcn: '<S465>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = rtb_Smallangleapproximationford *
    rtb_IntegratorSecondOrderLimite[0] - rtb_Switch1_h[0] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S465>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -rtb_IntegratorSecondOrderLimite[1];

  /* Fcn: '<S465>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S465>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

  /* Math: '<S464>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1_e[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose1_e[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose1_e[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S464>/Transpose1' */

  /* Product: '<S467>/Product' incorporates:
   *  Selector: '<S451>/Selector1'
   */
  rtb_Divide_pl = localB->Selector1_h[1];
  rtb_Gain1_g0 = localB->Selector1_h[0];
  lam_muy_prime_idx_3 = localB->Selector1_h[2];
  for (iy = 0; iy < 3; iy++) {
    /* Sum: '<S464>/Add' incorporates:
     *  Math: '<S464>/Transpose1'
     */
    localB->Add_n[iy] = ((rtb_Transpose1_e[iy + 3] * rtb_Divide_pl +
                          rtb_Transpose1_e[iy] * rtb_Gain1_g0) +
                         rtb_Transpose1_e[iy + 6] * lam_muy_prime_idx_3) +
      localB->xeyeze[iy];

    /* Trigonometry: '<S493>/sincos' */
    rtb_UnaryMinus2_idx_0 = rtb_sincos_o1[iy];
    rtb_IntegratorSecondOrderLimite[iy] = std::sin(rtb_UnaryMinus2_idx_0);
    rtb_Switch1_h[iy] = std::cos(rtb_UnaryMinus2_idx_0);
  }

  /* End of Product: '<S467>/Product' */

  /* Fcn: '<S493>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

  /* Fcn: '<S493>/Fcn21' incorporates:
   *  Fcn: '<S493>/Fcn22'
   */
  rtb_Product_py = rtb_IntegratorSecondOrderLimite[1] *
    rtb_IntegratorSecondOrderLimite[2];
  rtb_VectorConcatenate_ci[1] = rtb_Product_py * rtb_Switch1_h[0] -
    rtb_IntegratorSecondOrderLimite[0] * rtb_Switch1_h[2];

  /* Fcn: '<S493>/Fcn31' incorporates:
   *  Fcn: '<S493>/Fcn32'
   */
  rtb_Smallangleapproximationford = rtb_IntegratorSecondOrderLimite[1] *
    rtb_Switch1_h[2];
  rtb_VectorConcatenate_ci[2] = rtb_Smallangleapproximationford * rtb_Switch1_h
    [0] + rtb_IntegratorSecondOrderLimite[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S493>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = rtb_IntegratorSecondOrderLimite[0] *
    rtb_Switch1_h[1];

  /* Fcn: '<S493>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = rtb_Product_py *
    rtb_IntegratorSecondOrderLimite[0] + rtb_Switch1_h[0] * rtb_Switch1_h[2];

  /* Fcn: '<S493>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = rtb_Smallangleapproximationford *
    rtb_IntegratorSecondOrderLimite[0] - rtb_Switch1_h[0] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S493>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -rtb_IntegratorSecondOrderLimite[1];

  /* Fcn: '<S493>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S493>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

  /* Math: '<S492>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1_k[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose1_k[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose1_k[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S492>/Transpose1' */

  /* Product: '<S495>/Product' incorporates:
   *  Selector: '<S454>/Selector1'
   */
  rtb_Divide_pl = localB->Selector1_p[1];
  rtb_Gain1_g0 = localB->Selector1_p[0];
  lam_muy_prime_idx_3 = localB->Selector1_p[2];
  for (iy = 0; iy < 3; iy++) {
    /* Sum: '<S492>/Add' incorporates:
     *  Math: '<S492>/Transpose1'
     */
    localB->Add_b[iy] = ((rtb_Transpose1_k[iy + 3] * rtb_Divide_pl +
                          rtb_Transpose1_k[iy] * rtb_Gain1_g0) +
                         rtb_Transpose1_k[iy + 6] * lam_muy_prime_idx_3) +
      localB->xeyeze[iy];

    /* Trigonometry: '<S501>/sincos' */
    rtb_UnaryMinus2_idx_0 = rtb_sincos_o1[iy];
    rtb_IntegratorSecondOrderLimite[iy] = std::sin(rtb_UnaryMinus2_idx_0);
    rtb_Switch1_h[iy] = std::cos(rtb_UnaryMinus2_idx_0);
  }

  /* End of Product: '<S495>/Product' */

  /* Fcn: '<S501>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

  /* Fcn: '<S501>/Fcn21' incorporates:
   *  Fcn: '<S501>/Fcn22'
   */
  rtb_Product_py = rtb_IntegratorSecondOrderLimite[1] *
    rtb_IntegratorSecondOrderLimite[2];
  rtb_VectorConcatenate_ci[1] = rtb_Product_py * rtb_Switch1_h[0] -
    rtb_IntegratorSecondOrderLimite[0] * rtb_Switch1_h[2];

  /* Fcn: '<S501>/Fcn31' incorporates:
   *  Fcn: '<S501>/Fcn32'
   */
  rtb_Smallangleapproximationford = rtb_IntegratorSecondOrderLimite[1] *
    rtb_Switch1_h[2];
  rtb_VectorConcatenate_ci[2] = rtb_Smallangleapproximationford * rtb_Switch1_h
    [0] + rtb_IntegratorSecondOrderLimite[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S501>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = rtb_IntegratorSecondOrderLimite[0] *
    rtb_Switch1_h[1];

  /* Fcn: '<S501>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = rtb_Product_py *
    rtb_IntegratorSecondOrderLimite[0] + rtb_Switch1_h[0] * rtb_Switch1_h[2];

  /* Fcn: '<S501>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = rtb_Smallangleapproximationford *
    rtb_IntegratorSecondOrderLimite[0] - rtb_Switch1_h[0] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S501>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -rtb_IntegratorSecondOrderLimite[1];

  /* Fcn: '<S501>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S501>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

  /* Math: '<S500>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   *  Math: '<S394>/Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S500>/Transpose1' */

  /* SignalConversion generated from: '<S420>/sincos' */
  rtb_IntegratorSecondOrderLimite[0] = localB->phithetapsi[2];
  rtb_IntegratorSecondOrderLimite[1] = localB->phithetapsi[1];
  rtb_IntegratorSecondOrderLimite[2] = localB->phithetapsi[0];

  /* Product: '<S503>/Product' incorporates:
   *  Selector: '<S455>/Selector1'
   */
  rtb_Divide_pl = localB->Selector1_f[1];
  rtb_Gain1_g0 = localB->Selector1_f[0];
  lam_muy_prime_idx_3 = localB->Selector1_f[2];
  for (iy = 0; iy < 3; iy++) {
    /* Sum: '<S500>/Add' incorporates:
     *  Math: '<S394>/Transpose'
     */
    localB->Add_a[iy] = ((rtb_Transpose[iy + 3] * rtb_Divide_pl +
                          rtb_Transpose[iy] * rtb_Gain1_g0) + rtb_Transpose[iy +
                         6] * lam_muy_prime_idx_3) + localB->xeyeze[iy];

    /* Trigonometry: '<S420>/sincos' */
    rtb_UnaryMinus2_idx_0 = rtb_IntegratorSecondOrderLimite[iy];
    rtb_Switch1_h[iy] = std::cos(rtb_UnaryMinus2_idx_0);
    rtb_IntegratorSecondOrderLimite[iy] = std::sin(rtb_UnaryMinus2_idx_0);
  }

  /* End of Product: '<S503>/Product' */

  /* Fcn: '<S420>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

  /* Fcn: '<S420>/Fcn21' incorporates:
   *  Fcn: '<S420>/Fcn22'
   */
  rtb_Product_py = rtb_IntegratorSecondOrderLimite[1] *
    rtb_IntegratorSecondOrderLimite[2];
  rtb_VectorConcatenate_ci[1] = rtb_Product_py * rtb_Switch1_h[0] -
    rtb_IntegratorSecondOrderLimite[0] * rtb_Switch1_h[2];

  /* Fcn: '<S420>/Fcn31' incorporates:
   *  Fcn: '<S420>/Fcn32'
   */
  rtb_Smallangleapproximationford = rtb_IntegratorSecondOrderLimite[1] *
    rtb_Switch1_h[2];
  rtb_VectorConcatenate_ci[2] = rtb_Smallangleapproximationford * rtb_Switch1_h
    [0] + rtb_IntegratorSecondOrderLimite[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S420>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = rtb_IntegratorSecondOrderLimite[0] *
    rtb_Switch1_h[1];

  /* Fcn: '<S420>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = rtb_Product_py *
    rtb_IntegratorSecondOrderLimite[0] + rtb_Switch1_h[0] * rtb_Switch1_h[2];

  /* Fcn: '<S420>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = rtb_Smallangleapproximationford *
    rtb_IntegratorSecondOrderLimite[0] - rtb_Switch1_h[0] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S420>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -rtb_IntegratorSecondOrderLimite[1];

  /* Fcn: '<S420>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S420>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

  /* Reshape: '<S422>/Reshape (9) to [3x3] column-major' */
  std::memcpy(&localB->Reshape9to3x3columnmajor[0], &rtb_VectorConcatenate_ci[0],
              9U * sizeof(real_T));

  /* Product: '<S419>/Product' incorporates:
   *  Integrator: '<S406>/ub,vb,wb'
   *  Math: '<S406>/Transpose'
   */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  rtb_FrontBiasGain = rtb_ubvbwb[1];
  rtb_Product_py = rtb_ubvbwb[0];
  rtb_Smallangleapproximationford = rtb_ubvbwb[2];

  /* Product: '<S458>/Product' incorporates:
   *  Product: '<S433>/Product4'
   */
  rtb_Divide_pl = rtb_Product4_i[1];
  rtb_Integrator1_p = rtb_Product4_i[0];
  rtb_Switch_e1 = rtb_Product4_i[2];

  /* Product: '<S466>/Product' incorporates:
   *  Concatenate: '<S411>/Vector Concatenate'
   */
  rtb_UnaryMinus2_idx_0 = rtb_VectorConcatenate_n[1];
  rtb_Gain1_g0 = rtb_VectorConcatenate_n[0];
  lam_muy_prime_idx_3 = rtb_VectorConcatenate_n[2];

  /* Product: '<S494>/Product' incorporates:
   *  Concatenate: '<S399>/Vector Concatenate'
   */
  lam_muy_prime_idx_1 = rtb_VectorConcatenate_km[1];
  lam_muy_prime_idx_0 = rtb_VectorConcatenate_km[0];
  rtb_Sum1_m = rtb_VectorConcatenate_km[2];

  /* Product: '<S502>/Product' incorporates:
   *  Product: '<S433>/Product3'
   */
  mu_y_idx_2 = rtb_Product3_ju[1];
  mu_y = rtb_Product3_ju[0];
  rtb_Saturation_tmp = rtb_Product3_ju[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S419>/Product' incorporates:
     *  Integrator: '<S406>/ub,vb,wb'
     *  Math: '<S406>/Transpose'
     *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
     */
    mu_y_tmp = (localB->Reshape9to3x3columnmajor[3 * i + 1] * rtb_FrontBiasGain
                + localB->Reshape9to3x3columnmajor[3 * i] * rtb_Product_py) +
      localB->Reshape9to3x3columnmajor[3 * i + 2] *
      rtb_Smallangleapproximationford;
    localB->Product_d[i] = mu_y_tmp;

    /* UnitConversion: '<S417>/Unit Conversion' incorporates:
     *  Product: '<S419>/Product'
     */
    localB->UnitConversion_i[i] = mu_y_tmp;

    /* Sum: '<S456>/Add4' incorporates:
     *  Math: '<S456>/Transpose1'
     *  Product: '<S419>/Product'
     *  Product: '<S433>/Product4'
     *  Product: '<S458>/Product'
     */
    rtb_Saturation_tmp_0 = ((rtb_Transpose1[i + 3] * rtb_Divide_pl +
      rtb_Transpose1[i] * rtb_Integrator1_p) + rtb_Transpose1[i + 6] *
      rtb_Switch_e1) + mu_y_tmp;
    localB->V_wb[i] = rtb_Saturation_tmp_0;

    /* Sum: '<S464>/Add4' incorporates:
     *  Concatenate: '<S411>/Vector Concatenate'
     *  Math: '<S464>/Transpose1'
     *  Product: '<S419>/Product'
     *  Product: '<S466>/Product'
     */
    rtb_Saturation_tmp_1 = ((rtb_Transpose1_e[i + 3] * rtb_UnaryMinus2_idx_0 +
      rtb_Transpose1_e[i] * rtb_Gain1_g0) + rtb_Transpose1_e[i + 6] *
      lam_muy_prime_idx_3) + mu_y_tmp;
    localB->V_wb_d[i] = rtb_Saturation_tmp_1;

    /* Sum: '<S492>/Add4' incorporates:
     *  Concatenate: '<S399>/Vector Concatenate'
     *  Math: '<S492>/Transpose1'
     *  Product: '<S419>/Product'
     *  Product: '<S494>/Product'
     */
    lam_Cz_0 = ((rtb_Transpose1_k[i + 3] * lam_muy_prime_idx_1 +
                 rtb_Transpose1_k[i] * lam_muy_prime_idx_0) + rtb_Transpose1_k[i
                + 6] * rtb_Sum1_m) + mu_y_tmp;
    localB->V_wb_h[i] = lam_Cz_0;

    /* Sum: '<S500>/Add4' incorporates:
     *  Math: '<S394>/Transpose'
     *  Product: '<S419>/Product'
     *  Product: '<S433>/Product3'
     *  Product: '<S502>/Product'
     */
    mu_y_tmp += (rtb_Transpose[i + 3] * mu_y_idx_2 + rtb_Transpose[i] * mu_y) +
      rtb_Transpose[i + 6] * rtb_Saturation_tmp;
    localB->V_wb_j[i] = mu_y_tmp;

    /* Reshape: '<S294>/Reshape' */
    rtb_VectorConcatenate8[i] = localB->Add[i];
    rtb_VectorConcatenate8[i + 3] = localB->Add_n[i];
    rtb_VectorConcatenate8[i + 6] = localB->Add_b[i];
    rtb_VectorConcatenate8[i + 9] = localB->Add_a[i];

    /* Reshape: '<S294>/Reshape1' */
    tmp_0[i] = rtb_Saturation_tmp_0;
    tmp_0[i + 3] = rtb_Saturation_tmp_1;
    tmp_0[i + 6] = lam_Cz_0;
    tmp_0[i + 9] = mu_y_tmp;
  }

  /* Concatenate: '<S291>/Matrix Concatenate3' incorporates:
   *  Constant: '<S294>/Inertial Frame CG to Axle Offset'
   *  Selector: '<S291>/Selector'
   *  Selector: '<S291>/Selector1'
   *  Sum: '<S294>/Sum'
   */
  rtb_MatrixConcatenate3[0] = rtb_VectorConcatenate8[2] -
    localP->InertialFrameCGtoAxleOffset_Val[2];
  rtb_MatrixConcatenate3[1] = tmp_0[2];
  rtb_MatrixConcatenate3[2] = rtb_VectorConcatenate8[5] -
    localP->InertialFrameCGtoAxleOffset_Val[5];
  rtb_MatrixConcatenate3[3] = tmp_0[5];
  rtb_MatrixConcatenate3[4] = rtb_VectorConcatenate8[8] -
    localP->InertialFrameCGtoAxleOffset_Val[8];
  rtb_MatrixConcatenate3[5] = tmp_0[8];
  rtb_MatrixConcatenate3[6] = rtb_VectorConcatenate8[11] -
    localP->InertialFrameCGtoAxleOffset_Val[11];
  rtb_MatrixConcatenate3[7] = tmp_0[11];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S173>/Add' incorporates:
     *  Constant: '<S173>/Constant'
     *  Constant: '<S173>/Constant1'
     */
    rtb_Product2_fq = AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
      AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

    /* Product: '<S173>/Divide' incorporates:
     *  Constant: '<S173>/Constant3'
     */
    rtb_Divide_pl = localP->RackandPinforDynStr_d / rtb_Product2_fq;

    /* Sum: '<S173>/Add1' incorporates:
     *  Constant: '<S173>/Constant2'
     *  Math: '<S173>/Math Function'
     *  Math: '<S173>/Math Function1'
     */
    rtb_Product2_fq = rtb_Product2_fq * rtb_Product2_fq +
      localP->RackandPinforDynStr_d * localP->RackandPinforDynStr_d;

    /* Sum: '<S173>/Add2' incorporates:
     *  Constant: '<S173>/Constant4'
     *  Constant: '<S173>/Constant5'
     *  Math: '<S173>/Math Function2'
     *  Math: '<S173>/Math Function3'
     */
    lam_muy_prime_idx_3 = (AdasPlantModel0_P->PlntSteerStrgArmLngth *
      AdasPlantModel0_P->PlntSteerStrgArmLngth + rtb_Product2_fq) -
      AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;

    /* Sqrt: '<S173>/Sqrt' */
    rtb_Product2_fq = std::sqrt(rtb_Product2_fq);

    /* Product: '<S173>/Divide1' incorporates:
     *  Constant: '<S173>/Constant6'
     *  Constant: '<S173>/Constant7'
     */
    rtb_UnaryMinus2_idx_0 = lam_muy_prime_idx_3 / localP->Constant6_Value /
      AdasPlantModel0_P->PlntSteerStrgArmLngth / rtb_Product2_fq;

    /* Trigonometry: '<S173>/Trigonometric Function1' */
    if (rtb_UnaryMinus2_idx_0 > 1.0) {
      rtb_UnaryMinus2_idx_0 = 1.0;
    } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
      rtb_UnaryMinus2_idx_0 = -1.0;
    }

    /* Sum: '<S173>/Add3' incorporates:
     *  Constant: '<S173>/Constant8'
     *  Trigonometry: '<S173>/Trigonometric Function'
     *  Trigonometry: '<S173>/Trigonometric Function1'
     */
    localB->Add3 = (localP->Constant8_Value - std::atan(rtb_Divide_pl)) - std::
      acos(rtb_UnaryMinus2_idx_0);

    /* Product: '<S157>/Divide' incorporates:
     *  Constant: '<S108>/RckGnConstant'
     *  Constant: '<S157>/Constant'
     */
    localB->Divide_l = AdasPlantModel0_P->PlntSteerRckGn /
      localP->Constant_Value_h;

    /* UnaryMinus: '<S168>/Unary Minus1' */
    localB->UnaryMinus1 = -localB->Divide_l;
  }

  /* Sum: '<S171>/Add' incorporates:
   *  Constant: '<S171>/Constant'
   *  Constant: '<S171>/Constant1'
   *  Product: '<S168>/Product'
   *  SecondOrderIntegrator: '<S157>/Integrator, Second-Order'
   */
  rtb_Product_py = (AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
                    localB->UnaryMinus1 * localX->
                    IntegratorSecondOrder_CSTATE_h[0]) -
    AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S171>/Trigonometric Function' incorporates:
   *  Constant: '<S171>/Constant3'
   *  Product: '<S171>/Divide'
   */
  rtb_Divide_pl = std::atan(localP->RackandPinforDynStr_d / rtb_Product_py);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S171>/Math Function1' incorporates:
     *  Constant: '<S171>/Constant2'
     */
    localB->MathFunction1_e = localP->RackandPinforDynStr_d *
      localP->RackandPinforDynStr_d;

    /* Math: '<S171>/Math Function2' incorporates:
     *  Constant: '<S171>/Constant4'
     */
    localB->MathFunction2 = AdasPlantModel0_P->PlntSteerStrgArmLngth *
      AdasPlantModel0_P->PlntSteerStrgArmLngth;

    /* Math: '<S171>/Math Function3' incorporates:
     *  Constant: '<S171>/Constant5'
     */
    localB->MathFunction3 = AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S171>/Add1' incorporates:
   *  Math: '<S171>/Math Function'
   */
  rtb_Product_py = rtb_Product_py * rtb_Product_py + localB->MathFunction1_e;

  /* Product: '<S171>/Divide1' incorporates:
   *  Constant: '<S171>/Constant6'
   *  Constant: '<S171>/Constant7'
   *  Sqrt: '<S171>/Sqrt'
   *  Sum: '<S171>/Add2'
   */
  rtb_UnaryMinus2_idx_0 = ((rtb_Product_py + localB->MathFunction2) -
    localB->MathFunction3) / localP->Constant6_Value_n /
    AdasPlantModel0_P->PlntSteerStrgArmLngth / std::sqrt(rtb_Product_py);

  /* Trigonometry: '<S171>/Trigonometric Function1' */
  if (rtb_UnaryMinus2_idx_0 > 1.0) {
    rtb_UnaryMinus2_idx_0 = 1.0;
  } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  }

  /* Sum: '<S168>/Add' incorporates:
   *  Constant: '<S171>/Constant8'
   *  Sum: '<S171>/Add3'
   *  Trigonometry: '<S171>/Trigonometric Function1'
   */
  rtb_Product_py = ((localP->Constant8_Value_d - rtb_Divide_pl) - std::acos
                    (rtb_UnaryMinus2_idx_0)) - localB->Add3;

  /* Sum: '<S172>/Add' incorporates:
   *  Constant: '<S172>/Constant'
   *  Constant: '<S172>/Constant1'
   *  Product: '<S168>/Product3'
   *  SecondOrderIntegrator: '<S157>/Integrator, Second-Order'
   */
  lam_muy_prime_idx_1 = (AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
    localB->Divide_l * localX->IntegratorSecondOrder_CSTATE_h[0]) -
    AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S172>/Trigonometric Function' incorporates:
   *  Constant: '<S172>/Constant3'
   *  Product: '<S172>/Divide'
   */
  rtb_Divide_pl = std::atan(localP->RackandPinforDynStr_d / lam_muy_prime_idx_1);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S172>/Math Function1' incorporates:
     *  Constant: '<S172>/Constant2'
     */
    localB->MathFunction1_m = localP->RackandPinforDynStr_d *
      localP->RackandPinforDynStr_d;

    /* Math: '<S172>/Math Function2' incorporates:
     *  Constant: '<S172>/Constant4'
     */
    localB->MathFunction2_n = AdasPlantModel0_P->PlntSteerStrgArmLngth *
      AdasPlantModel0_P->PlntSteerStrgArmLngth;

    /* Math: '<S172>/Math Function3' incorporates:
     *  Constant: '<S172>/Constant5'
     */
    localB->MathFunction3_h = AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S172>/Add1' incorporates:
   *  Math: '<S172>/Math Function'
   */
  lam_muy_prime_idx_1 = lam_muy_prime_idx_1 * lam_muy_prime_idx_1 +
    localB->MathFunction1_m;

  /* Product: '<S172>/Divide1' incorporates:
   *  Constant: '<S172>/Constant6'
   *  Constant: '<S172>/Constant7'
   *  Sqrt: '<S172>/Sqrt'
   *  Sum: '<S172>/Add2'
   */
  rtb_UnaryMinus2_idx_0 = ((lam_muy_prime_idx_1 + localB->MathFunction2_n) -
    localB->MathFunction3_h) / localP->Constant6_Value_j /
    AdasPlantModel0_P->PlntSteerStrgArmLngth / std::sqrt(lam_muy_prime_idx_1);

  /* Trigonometry: '<S172>/Trigonometric Function1' */
  if (rtb_UnaryMinus2_idx_0 > 1.0) {
    rtb_UnaryMinus2_idx_0 = 1.0;
  } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  }

  /* Sum: '<S168>/Add1' incorporates:
   *  Constant: '<S172>/Constant8'
   *  Sum: '<S172>/Add3'
   *  Trigonometry: '<S172>/Trigonometric Function1'
   */
  lam_muy_prime_idx_1 = localB->Add3 - ((localP->Constant8_Value_n -
    rtb_Divide_pl) - std::acos(rtb_UnaryMinus2_idx_0));

  /* Switch: '<S157>/Switch' incorporates:
   *  SecondOrderIntegrator: '<S157>/Integrator, Second-Order'
   */
  if (localX->IntegratorSecondOrder_CSTATE_h[0] > localP->Switch_Threshold_j) {
    rtb_UnaryMinus2_idx_0 = lam_muy_prime_idx_1;
    rtb_Divide_pl = rtb_Product_py;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_Product_py;
    rtb_Divide_pl = lam_muy_prime_idx_1;
  }

  /* End of Switch: '<S157>/Switch' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S157>/Gain5' incorporates:
     *  Constant: '<S108>/PctAckConstant'
     */
    localB->Gain5 = localP->Gain5_Gain * AdasPlantModel0_P->PlntSteerPctAck;

    /* Sum: '<S157>/Add1' incorporates:
     *  Constant: '<S157>/Constant1'
     */
    localB->Add1_o = localP->Constant1_Value_i - localB->Gain5;
  }

  /* Switch: '<S157>/Switch1' incorporates:
   *  Product: '<S157>/Product1'
   *  Product: '<S157>/Product2'
   *  SecondOrderIntegrator: '<S157>/Integrator, Second-Order'
   *  Sum: '<S157>/Sum'
   */
  if (localX->IntegratorSecondOrder_CSTATE_h[0] > localP->Switch1_Threshold_l) {
    rtb_UnaryMinus1_c[0] = rtb_UnaryMinus2_idx_0 * localB->Add1_o +
      rtb_Divide_pl * localB->Gain5;
    rtb_UnaryMinus1_c[1] = rtb_UnaryMinus2_idx_0;
  } else {
    rtb_UnaryMinus1_c[0] = rtb_UnaryMinus2_idx_0;
    rtb_UnaryMinus1_c[1] = rtb_UnaryMinus2_idx_0 * localB->Add1_o +
      rtb_Divide_pl * localB->Gain5;
  }

  /* End of Switch: '<S157>/Switch1' */

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S108>/LocFlagConstant'
   *  Constant: '<S157>/AckermanFlagConstant'
   *  Switch: '<S157>/Switch4'
   */
  if (localP->LocFlagConstant_Value > localP->Switch_Threshold_i) {
    /* Switch: '<S157>/Switch4' incorporates:
     *  Constant: '<S157>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value > localP->Switch4_Threshold) {
      /* Switch: '<S110>/Switch' */
      localB->Switch = rtb_Product_py;
    } else {
      /* Switch: '<S110>/Switch' */
      localB->Switch = rtb_UnaryMinus1_c[0];
    }
  } else if (localP->AckermanFlagConstant_Value > localP->Switch4_Threshold) {
    /* Switch: '<S157>/Switch4' incorporates:
     *  Switch: '<S110>/Switch'
     *  UnaryMinus: '<S110>/Unary Minus1'
     */
    localB->Switch = -rtb_Product_py;
  } else {
    /* Switch: '<S110>/Switch' incorporates:
     *  Switch: '<S157>/Switch4'
     *  UnaryMinus: '<S110>/Unary Minus1'
     */
    localB->Switch = -rtb_UnaryMinus1_c[0];
  }

  /* End of Switch: '<S110>/Switch' */

  /* Switch: '<S110>/Switch1' incorporates:
   *  Constant: '<S108>/LocFlagConstant'
   *  Constant: '<S157>/AckermanFlagConstant'
   *  Switch: '<S157>/Switch5'
   */
  if (localP->LocFlagConstant_Value > localP->Switch1_Threshold_m) {
    /* Switch: '<S157>/Switch5' incorporates:
     *  Constant: '<S157>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value > localP->Switch5_Threshold) {
      /* Switch: '<S110>/Switch1' */
      localB->Switch1 = lam_muy_prime_idx_1;
    } else {
      /* Switch: '<S110>/Switch1' */
      localB->Switch1 = rtb_UnaryMinus1_c[1];
    }
  } else if (localP->AckermanFlagConstant_Value > localP->Switch5_Threshold) {
    /* Switch: '<S157>/Switch5' incorporates:
     *  Switch: '<S110>/Switch1'
     *  UnaryMinus: '<S110>/Unary Minus'
     */
    localB->Switch1 = -lam_muy_prime_idx_1;
  } else {
    /* Switch: '<S110>/Switch1' incorporates:
     *  Switch: '<S157>/Switch5'
     *  UnaryMinus: '<S110>/Unary Minus'
     */
    localB->Switch1 = -rtb_UnaryMinus1_c[1];
  }

  /* End of Switch: '<S110>/Switch1' */

  /* Concatenate: '<S295>/Matrix Concatenate' incorporates:
   *  ForEachSliceAssignment generated from: '<S383>/Mx'
   *  ForEachSliceAssignment generated from: '<S383>/My'
   *  ForEachSliceAssignment generated from: '<S383>/Mz'
   */
  rtb_VectorConcatenate8[0] = rtb_ImpAsg_InsertedFor_Mx_at_in[0];
  rtb_VectorConcatenate8[1] = rtb_ImpAsg_InsertedFor_My_at_in[0];
  rtb_VectorConcatenate8[2] = rtb_ImpAsg_InsertedFor_Mz_at_in[0];
  rtb_VectorConcatenate8[3] = rtb_ImpAsg_InsertedFor_Mx_at_in[1];
  rtb_VectorConcatenate8[4] = rtb_ImpAsg_InsertedFor_My_at_in[1];
  rtb_VectorConcatenate8[5] = rtb_ImpAsg_InsertedFor_Mz_at_in[1];
  rtb_VectorConcatenate8[6] = rtb_ImpAsg_InsertedFor_Mx_at_in[2];
  rtb_VectorConcatenate8[7] = rtb_ImpAsg_InsertedFor_My_at_in[2];
  rtb_VectorConcatenate8[8] = rtb_ImpAsg_InsertedFor_Mz_at_in[2];
  rtb_VectorConcatenate8[9] = rtb_ImpAsg_InsertedFor_Mx_at_in[3];
  rtb_VectorConcatenate8[10] = rtb_ImpAsg_InsertedFor_My_at_in[3];
  rtb_VectorConcatenate8[11] = rtb_ImpAsg_InsertedFor_Mz_at_in[3];

  /* Trigonometry: '<S291>/Small angle approximation for downstream multiplications' */
  rtb_Smallangleapproximationford = std::tan(rty_VehFdbk[0]);

  /* Gain: '<S288>/Gain' incorporates:
   *  Integrator: '<S290>/Integrator1'
   */
  rtb_Integrator1_p = localP->Gain_Gain_f * localX->Integrator1_CSTATE_b[0];
  lam_muy_prime_idx_3 = localP->Gain_Gain_f * localX->Integrator1_CSTATE_b[1];
  rtb_Divide_pl = localP->Gain_Gain_f * localX->Integrator1_CSTATE_b[2];
  rtb_Gain1_g0 = localP->Gain_Gain_f * localX->Integrator1_CSTATE_b[3];

  /* Signum: '<S288>/Sign' */
  if (std::isnan(rtb_Integrator1_p)) {
    rtb_UnaryMinus2_idx_0 = (rtNaN);
  } else if (rtb_Integrator1_p < 0.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  } else {
    rtb_UnaryMinus2_idx_0 = (rtb_Integrator1_p > 0.0);
  }

  if (std::isnan(lam_muy_prime_idx_3)) {
    rtb_Integrator1_p = (rtNaN);
  } else if (lam_muy_prime_idx_3 < 0.0) {
    rtb_Integrator1_p = -1.0;
  } else {
    rtb_Integrator1_p = (lam_muy_prime_idx_3 > 0.0);
  }

  /* Sum: '<S296>/Add' incorporates:
   *  Abs: '<S296>/Abs'
   *  Abs: '<S296>/Abs1'
   *  Constant: '<S296>/Front Track'
   *  Integrator: '<S289>/Integrator1'
   *  Product: '<S296>/Product'
   *  Product: '<S296>/Product1'
   *  Signum: '<S288>/Sign'
   */
  rtb_UnaryMinus1_c[0] = (std::abs(localX->Integrator1_CSTATE_no[0]) *
    rtb_UnaryMinus2_idx_0 + localP->FrontTrack_Value) + std::abs
    (localX->Integrator1_CSTATE_no[1]) * rtb_Integrator1_p;

  /* Signum: '<S288>/Sign' */
  if (std::isnan(rtb_Divide_pl)) {
    rtb_UnaryMinus2_idx_0 = (rtNaN);
  } else if (rtb_Divide_pl < 0.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  } else {
    rtb_UnaryMinus2_idx_0 = (rtb_Divide_pl > 0.0);
  }

  if (std::isnan(rtb_Gain1_g0)) {
    rtb_Integrator1_p = (rtNaN);
  } else if (rtb_Gain1_g0 < 0.0) {
    rtb_Integrator1_p = -1.0;
  } else {
    rtb_Integrator1_p = (rtb_Gain1_g0 > 0.0);
  }

  /* Sum: '<S297>/Add1' incorporates:
   *  Abs: '<S297>/Abs2'
   *  Abs: '<S297>/Abs3'
   *  Constant: '<S297>/Rear Track'
   *  Integrator: '<S289>/Integrator1'
   *  Product: '<S297>/Product2'
   *  Product: '<S297>/Product3'
   *  Signum: '<S288>/Sign'
   */
  rtb_UnaryMinus1_c[1] = (std::abs(localX->Integrator1_CSTATE_no[2]) *
    rtb_UnaryMinus2_idx_0 + localP->RearTrack_Value) + std::abs
    (localX->Integrator1_CSTATE_no[3]) * rtb_Integrator1_p;

  /* Outputs for Iterator SubSystem: '<S291>/For each track and axle combination calculate suspension forces and moments' incorporates:
   *  ForEach: '<S299>/For Each'
   */
  for (ForEach_itr_og = 0; ForEach_itr_og < 4; ForEach_itr_og++) {
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S301>/Sum2' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S291>/Wheel Number'
       *  Constant: '<S301>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  ForEachSliceSelector generated from: '<S299>/Wheel Number'
       *  Selector: '<S301>/Selector1'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      localB->CoreSubsys[ForEach_itr_og].Sum2 =
        localP->CoreSubsys.VehicleVehicleWheelOffset3_Valu[static_cast<int32_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1] +
        localP->IndependentKandCSuspension_WhlN[ForEach_itr_og];

      /* Selector: '<S308>/Selector5' incorporates:
       *  Constant: '<S308>/Constant4'
       *  UnitConversion: '<S308>/Unit Conversion'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector5 =
        AdasPlantModel0_P->PlntSpKCStatCamber[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1] * 0.017453292519943295;

      /* Selector: '<S321>/Selector2' incorporates:
       *  Constant: '<S321>/Constant5'
       *  Selector: '<S308>/Selector5'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector2 =
        AdasPlantModel0_P->PlntSpKCBumpCamber[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Selector: '<S301>/Selector' incorporates:
     *  Selector: '<S301>/Selector2'
     *  Sum: '<S358>/Add'
     */
    i = (static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1) << 1;

    /* Sum: '<S358>/Add' incorporates:
     *  Concatenate: '<S291>/Matrix Concatenate2'
     *  Concatenate: '<S291>/Matrix Concatenate3'
     *  Selector: '<S301>/Selector'
     *  Selector: '<S301>/Selector2'
     */
    rtb_Divide_pl = rtb_MatrixConcatenate3[i] - rtb_MatrixConcatenate2[i];

    /* Gain: '<S359>/Height Sign Convention' */
    lam_muy_prime_idx_3 = localP->CoreSubsys.HeightSignConvention_Gain *
      rtb_Divide_pl;

    /* Gain: '<S306>/Sign Convention' */
    rtb_Gain1_g0 = localP->CoreSubsys.SignConvention_Gain * lam_muy_prime_idx_3;

    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S326>/Sum of Elements' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S325>/Constant3'
       *  Constant: '<S326>/Axle Numbers'
       *  DataTypeConversion: '<S326>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  Product: '<S326>/Product'
       *  RelationalOperator: '<S326>/Relational Operator'
       *  Selector: '<S325>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_og].SumofElements =
        AdasPlantModel0_P->PlntSpKCCambVsSteerAng[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1] * static_cast<real_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_og] ==
         localP->CoreSubsys.SelectSteerCamberSlope_AxleNums);

      /* Selector: '<S302>/Selector5' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  Selector: '<S346>/Selector1'
       */
      i = static_cast<int32_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1;

      /* Product: '<S302>/Product' incorporates:
       *  Constant: '<S302>/Vehicle Vehicle Wheel Offset1'
       *  Selector: '<S302>/Selector5'
       */
      localB->CoreSubsys[ForEach_itr_og].Product =
        localP->CoreSubsys.VehicleVehicleWheelOffset1_Valu[i] *
        localB->CoreSubsys[ForEach_itr_og].Sum2;

      /* Sum: '<S346>/Sum1' incorporates:
       *  Constant: '<S291>/Wheel Number'
       *  Constant: '<S346>/Constant'
       *  Constant: '<S346>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S299>/Wheel Number'
       *  Gain: '<S346>/Gain'
       *  Selector: '<S346>/Selector1'
       *  Sum: '<S346>/Sum'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      rtb_Integrator1_p = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_d[i]
                           + localP->CoreSubsys.Constant_Value_f) *
        localP->CoreSubsys.Gain_Gain - localP->
        IndependentKandCSuspension_WhlN[ForEach_itr_og];

      /* Signum: '<S346>/Sign' */
      if (std::isnan(rtb_Integrator1_p)) {
        rtb_UnaryMinus2_idx_0 = (rtNaN);
      } else if (rtb_Integrator1_p < 0.0) {
        rtb_UnaryMinus2_idx_0 = -1.0;
      } else {
        rtb_UnaryMinus2_idx_0 = (rtb_Integrator1_p > 0.0);
      }

      /* Product: '<S346>/Product' incorporates:
       *  Constant: '<S313>/Constant1'
       *  Selector: '<S325>/Selector1'
       *  Selector: '<S346>/Selector5'
       *  Signum: '<S346>/Sign'
       *  UnitConversion: '<S313>/Unit Conversion'
       */
      rtb_Product_py = AdasPlantModel0_P->PlntSpKCStatToe[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1] * 0.017453292519943295 *
        rtb_UnaryMinus2_idx_0;

      /* Sum: '<S352>/Sum of Elements' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S352>/Axle Numbers'
       *  DataTypeConversion: '<S352>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  Product: '<S352>/Product'
       *  RelationalOperator: '<S352>/Relational Operator'
       */
      localB->CoreSubsys[ForEach_itr_og].SumofElements_m = static_cast<real_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_og] ==
         localP->CoreSubsys.SelectStaticToeSetting_AxleNums[0]) * rtb_Product_py
        + static_cast<real_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_og] ==
        localP->CoreSubsys.SelectStaticToeSetting_AxleNums[1]) * rtb_Product_py;

      /* Selector: '<S354>/Selector5' incorporates:
       *  Constant: '<S354>/Constant'
       *  Selector: '<S325>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector5_o =
        AdasPlantModel0_P->PlntSpKCBumpSteer[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Selector: '<S353>/Selector10' incorporates:
       *  Constant: '<S353>/Constant12'
       *  Selector: '<S325>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector10 =
        AdasPlantModel0_P->PlntSpKCAlgnTrqSteerCompl[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N*m to: kN*m
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S355>/Selector2' incorporates:
       *  Constant: '<S355>/Constant2'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector2_m =
        AdasPlantModel0_P->PlntSpKCLatSteerCompl[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* SignalConversion generated from: '<S302>/Selector3' incorporates:
     *  Constant: '<S302>/Constant'
     *  Reshape: '<S293>/Reshape1'
     */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Product3_ju[0] = localP->CoreSubsys.Constant_Value;
    rtb_Product3_ju[1] = localB->Switch;
    rtb_Product3_ju[2] = localB->Switch1;

    /* Gain: '<S313>/Gain1' incorporates:
     *  ForEachSliceAssignment generated from: '<S383>/Fx'
     *  Gain: '<S308>/Gain1'
     *  Gain: '<S309>/Gain2'
     *  Gain: '<S311>/Gain'
     *  Gain: '<S312>/Gain'
     *  Product: '<S304>/Product1'
     *  Selector: '<S304>/Selector2'
     *  Selector: '<S323>/Selector5'
     *  Selector: '<S332>/Selector5'
     *  Selector: '<S341>/Selector1'
     *  Selector: '<S345>/Selector3'
     *  Selector: '<S356>/Selector3'
     */
    rtb_UnaryMinus2_idx_0 = rtb_ImpAsg_InsertedFor_Fx_at_in[static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    rtb_Integrator1_p = rtb_UnaryMinus2_idx_0 * localP->CoreSubsys.Gain1_Gain;

    /* Switch: '<S356>/Switch' incorporates:
     *  Constant: '<S356>/Constant3'
     *  Constant: '<S356>/Constant6'
     *  Gain: '<S313>/Gain1'
     *  Gain: '<S356>/Gain2'
     *  Selector: '<S356>/Selector3'
     *  Selector: '<S356>/Selector6'
     */
    if (rtb_Integrator1_p * localP->CoreSubsys.Gain2_Gain >=
        localP->CoreSubsys.Switch_Threshold) {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant6_Value
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    } else {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant3_Value
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Gain: '<S313>/Gain4' incorporates:
     *  Concatenate: '<S295>/Matrix Concatenate'
     *  Gain: '<S308>/Gain4'
     *  Selector: '<S320>/Selector'
     *  Selector: '<S353>/Selector'
     *  Selector: '<S356>/Selector3'
     */
    rtb_FrontBiasGain = rtb_VectorConcatenate8[(static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1) * 3 + 2];

    /* Gain: '<S313>/Gain3' incorporates:
     *  ForEachSliceAssignment generated from: '<S383>/Fy'
     *  Gain: '<S308>/Gain3'
     *  Gain: '<S311>/Gain3'
     *  Selector: '<S304>/Selector1'
     *  Selector: '<S322>/Selector3'
     *  Selector: '<S340>/Selector3'
     *  Selector: '<S355>/Selector1'
     *  Selector: '<S356>/Selector3'
     *  UnaryMinus: '<S304>/Unary Minus'
     */
    lam_muy_prime_idx_0 = rtb_ImpAsg_InsertedFor_Fy_at_in[static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

    /* Sum: '<S306>/Sum3' incorporates:
     *  ForEachSliceAssignment generated from: '<S383>/Fy'
     *  Gain: '<S313>/Gain'
     *  Gain: '<S313>/Gain3'
     *  Gain: '<S313>/Gain4'
     *  Gain: '<S313>/Gain5'
     *  Product: '<S353>/Product9'
     *  Product: '<S354>/Product'
     *  Product: '<S355>/Product1'
     *  Product: '<S356>/Product4'
     *  Selector: '<S302>/Selector3'
     *  Selector: '<S353>/Selector'
     *  Selector: '<S355>/Selector1'
     *  Sum: '<S313>/Sum'
     *  Sum: '<S313>/Sum1'
     *  Switch: '<S356>/Switch'
     *  UnitConversion: '<S353>/Unit Conversion'
     *  UnitConversion: '<S353>/Unit Conversion1'
     *  UnitConversion: '<S354>/Unit Conversion'
     *  UnitConversion: '<S355>/Unit Conversion'
     *  UnitConversion: '<S355>/Unit Conversion1'
     *  UnitConversion: '<S356>/Unit Conversion'
     *  UnitConversion: '<S356>/Unit Conversion1'
     */
    rtb_Product_py = ((((rtb_FrontBiasGain * localP->CoreSubsys.Gain4_Gain *
                         0.001 * localB->CoreSubsys[ForEach_itr_og].Selector10 *
                         0.017453292519943295 + localP->CoreSubsys.Gain5_Gain_m *
                         rtb_Gain1_g0 * localB->CoreSubsys[ForEach_itr_og].
                         Selector5_o * 0.017453292519943295) +
                        lam_muy_prime_idx_0 * localP->CoreSubsys.Gain3_Gain *
                        0.001 * localB->CoreSubsys[ForEach_itr_og].Selector2_m *
                        0.017453292519943295) + rtb_Integrator1_p * 0.001 *
                       lam_muy_prime_idx_1 * 0.017453292519943295) *
                      localP->CoreSubsys.Gain_Gain_l + localB->
                      CoreSubsys[ForEach_itr_og].SumofElements_m) +
      rtb_Product3_ju[static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].
      Product)];
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S320>/Selector8' incorporates:
       *  Constant: '<S320>/Constant11'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector8 =
        AdasPlantModel0_P->PlntSpKCAlgnTrqCambCompl[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Selector: '<S322>/Selector4' incorporates:
       *  Constant: '<S322>/Constant2'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector4 =
        AdasPlantModel0_P->PlntSpKCLatCambCompl[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Gain: '<S308>/Gain1' */
    /* Unit Conversion - from: N*m to: kN*m
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Integrator1_p = rtb_UnaryMinus2_idx_0 * localP->CoreSubsys.Gain1_Gain_j;

    /* Switch: '<S323>/Switch' incorporates:
     *  Constant: '<S323>/Constant1'
     *  Constant: '<S323>/Constant6'
     *  Gain: '<S308>/Gain1'
     *  Gain: '<S323>/Gain2'
     *  Selector: '<S323>/Selector6'
     *  Selector: '<S356>/Selector3'
     */
    if (rtb_Integrator1_p * localP->CoreSubsys.Gain2_Gain_i >=
        localP->CoreSubsys.Switch_Threshold_i) {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant6_Value_i
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    } else {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant1_Value_i[static_cast<
        int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Sum: '<S308>/Sum2' incorporates:
     *  Gain: '<S308>/Gain'
     *  Gain: '<S308>/Gain3'
     *  Gain: '<S308>/Gain4'
     *  Gain: '<S308>/Gain5'
     *  Product: '<S320>/Product8'
     *  Product: '<S321>/Product3'
     *  Product: '<S322>/Product1'
     *  Product: '<S323>/Product4'
     *  Product: '<S325>/Product2'
     *  Switch: '<S323>/Switch'
     *  UnitConversion: '<S320>/Unit Conversion'
     *  UnitConversion: '<S320>/Unit Conversion1'
     *  UnitConversion: '<S321>/Unit Conversion'
     *  UnitConversion: '<S322>/Unit Conversion'
     *  UnitConversion: '<S322>/Unit Conversion1'
     *  UnitConversion: '<S323>/Unit Conversion'
     *  UnitConversion: '<S323>/Unit Conversion1'
     */
    rtb_FrontBiasGain = ((((localP->CoreSubsys.Gain5_Gain * rtb_Gain1_g0 *
      localB->CoreSubsys[ForEach_itr_og].Selector2 * 0.017453292519943295 +
      localB->CoreSubsys[ForEach_itr_og].Selector5) +
      localP->CoreSubsys.Gain_Gain_e * rtb_Product_py * localB->
      CoreSubsys[ForEach_itr_og].SumofElements) + rtb_FrontBiasGain *
                          localP->CoreSubsys.Gain4_Gain_c * 0.001 *
                          localB->CoreSubsys[ForEach_itr_og].Selector8 *
                          0.017453292519943295) + lam_muy_prime_idx_0 *
                         localP->CoreSubsys.Gain3_Gain_d * 0.001 *
                         localB->CoreSubsys[ForEach_itr_og].Selector4 *
                         0.017453292519943295) + rtb_Integrator1_p * 0.001 *
      lam_muy_prime_idx_1 * 0.017453292519943295;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S309>/Selector5' incorporates:
       *  Constant: '<S309>/Constant7'
       *  Selector: '<S356>/Selector3'
       *  UnitConversion: '<S309>/Unit Conversion'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      localB->CoreSubsys[ForEach_itr_og].Selector5_a =
        AdasPlantModel0_P->PlntSpKCStatCaster[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1] * 0.017453292519943295;

      /* Selector: '<S331>/Selector4' incorporates:
       *  Constant: '<S331>/Constant8'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector4_g =
        AdasPlantModel0_P->PlntSpKCBumpCaster[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Sum: '<S335>/Sum of Elements' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S334>/Constant6'
       *  Constant: '<S335>/Axle Numbers'
       *  DataTypeConversion: '<S335>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  Product: '<S335>/Product'
       *  RelationalOperator: '<S335>/Relational Operator'
       *  Selector: '<S334>/Selector3'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].SumofElements_h =
        AdasPlantModel0_P->PlntSpKCCastVsSteerAng[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1] * static_cast<real_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_og] ==
         localP->CoreSubsys.SelectSteerCasterSlope_AxleNums);
    }

    /* Gain: '<S309>/Gain2' */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Integrator1_p = rtb_UnaryMinus2_idx_0 * localP->CoreSubsys.Gain2_Gain_k;

    /* Switch: '<S332>/Switch' incorporates:
     *  Constant: '<S332>/Constant2'
     *  Constant: '<S332>/Constant4'
     *  Gain: '<S309>/Gain2'
     *  Gain: '<S332>/Gain2'
     *  Selector: '<S332>/Selector6'
     *  Selector: '<S356>/Selector3'
     */
    if (rtb_Integrator1_p * localP->CoreSubsys.Gain2_Gain_f >=
        localP->CoreSubsys.Switch_Threshold_f) {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant4_Value
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    } else {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant2_Value
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Sum: '<S309>/Sum1' incorporates:
     *  Gain: '<S309>/Gain'
     *  Gain: '<S309>/Gain4'
     *  Product: '<S331>/Product5'
     *  Product: '<S332>/Product3'
     *  Product: '<S334>/Product4'
     *  Switch: '<S332>/Switch'
     *  UnitConversion: '<S331>/Unit Conversion'
     *  UnitConversion: '<S332>/Unit Conversion'
     *  UnitConversion: '<S332>/Unit Conversion1'
     */
    rtb_Sum1_m = ((localP->CoreSubsys.Gain4_Gain_n * rtb_Gain1_g0 *
                   localB->CoreSubsys[ForEach_itr_og].Selector4_g *
                   0.017453292519943295 + localB->CoreSubsys[ForEach_itr_og].
                   Selector5_a) + localP->CoreSubsys.Gain_Gain_b *
                  rtb_Product_py * localB->CoreSubsys[ForEach_itr_og].
                  SumofElements_h) + rtb_Integrator1_p * 0.001 *
      lam_muy_prime_idx_1 * 0.017453292519943295;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S310>/Sum1' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S291>/Wheel Number'
       *  Constant: '<S310>/Constant'
       *  Constant: '<S310>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  ForEachSliceSelector generated from: '<S299>/Wheel Number'
       *  Gain: '<S310>/Gain'
       *  Selector: '<S310>/Selector1'
       *  Sum: '<S310>/Sum'
       */
      rtb_Integrator1_p = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_a[
                           static_cast<int32_T>
                           (localP->
                            IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1]
                           + localP->CoreSubsys.Constant_Value_c) *
        localP->CoreSubsys.Gain_Gain_g - localP->
        IndependentKandCSuspension_WhlN[ForEach_itr_og];

      /* Signum: '<S310>/Sign' */
      if (std::isnan(rtb_Integrator1_p)) {
        /* Signum: '<S310>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign = (rtNaN);
      } else if (rtb_Integrator1_p < 0.0) {
        /* Signum: '<S310>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign = -1.0;
      } else {
        /* Signum: '<S310>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign = (rtb_Integrator1_p > 0.0);
      }

      /* End of Signum: '<S310>/Sign' */

      /* Selector: '<S372>/Selector2' incorporates:
       *  Constant: '<S372>/Constant5'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector2_e =
        AdasPlantModel0_P->PlntSpKCNrmlWhlRates[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Selector: '<S372>/Selector1' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector1 =
        AdasPlantModel0_P->PlntSpKCNrmlWhlFrcOff[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Sum: '<S372>/Sum' incorporates:
     *  Gain: '<S359>/Gain2'
     *  Product: '<S372>/Product3'
     *  UnitConversion: '<S372>/Unit Conversion'
     */
    /* Unit Conversion - from: m to: mm
       Expression: output = (1000*input) + (0) */
    lam_muy_prime_idx_1 = localP->CoreSubsys.Gain2_Gain_j * rtb_Divide_pl *
      1000.0 * localB->CoreSubsys[ForEach_itr_og].Selector2_e +
      localB->CoreSubsys[ForEach_itr_og].Selector1;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S371>/Selector6' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  Constant: '<S371>/Constant7'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector6 =
        AdasPlantModel0_P->PlntSpKCMotRatios[static_cast<int32_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1];

      /* Selector: '<S371>/Selector1' incorporates:
       *  Constant: '<S371>/Constant1'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector1_n =
        AdasPlantModel0_P->PlntSpKCShckFrcVsCompRate[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* Selector: '<S301>/Selector' incorporates:
     *  Selector: '<S301>/Selector2'
     *  Selector: '<S356>/Selector3'
     *  Sum: '<S358>/Add2'
     */
    i = ((static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1) <<
         1) + 1;

    /* Sum: '<S358>/Add2' incorporates:
     *  Concatenate: '<S291>/Matrix Concatenate2'
     *  Concatenate: '<S291>/Matrix Concatenate3'
     *  Selector: '<S301>/Selector'
     *  Selector: '<S301>/Selector2'
     */
    rtb_Integrator1_p = rtb_MatrixConcatenate3[i] - rtb_MatrixConcatenate2[i];

    /* Sum: '<S359>/Add1' incorporates:
     *  Product: '<S371>/Product'
     *  Product: '<S371>/Product1'
     *  Product: '<S371>/Product2'
     *  UnitConversion: '<S371>/Unit Conversion'
     */
    /* Unit Conversion - from: m/s to: mm/s
       Expression: output = (1000*input) + (0) */
    rtb_Switch_e1 = 1000.0 * rtb_Integrator1_p * localB->
      CoreSubsys[ForEach_itr_og].Selector6 * localB->CoreSubsys[ForEach_itr_og].
      Selector1_n * localB->CoreSubsys[ForEach_itr_og].Selector6 +
      lam_muy_prime_idx_1;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S344>/Selector7' incorporates:
       *  Constant: '<S344>/Constant10'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector7 =
        AdasPlantModel0_P->PlntSpKCLngWhlCtrDisp[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Selector: '<S339>/Selector6' incorporates:
       *  Constant: '<S339>/Constant9'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector6_g =
        AdasPlantModel0_P->PlntSpKCLatWhlCtrDisp[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];

      /* Selector: '<S340>/Selector4' incorporates:
       *  Constant: '<S340>/Constant2'
       *  Selector: '<S356>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_og].Selector4_h =
        AdasPlantModel0_P->PlntSpKCLatWhlCtrComplLat[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S299>/Info' incorporates:
     *  Product: '<S310>/Product'
     *  Product: '<S359>/Product1'
     *  SignalConversion generated from: '<S299>/Info'
     */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: mm to: m
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: mm to: m
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: mm to: m
       Expression: output = (0.001*input) + (0) */
    i = ForEach_itr_og << 3;
    rtb_ImpAsg_InsertedFor_Info_at_[i] = rtb_FrontBiasGain;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 1] = rtb_Sum1_m;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 2] = rtb_Product_py * localB->
      CoreSubsys[ForEach_itr_og].Sign;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 3] = lam_muy_prime_idx_3;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 4] = rtb_Switch_e1 * rtb_Integrator1_p;

    /* Signum: '<S359>/Sign1' */
    if (std::isnan(rtb_Divide_pl)) {
      rtb_Integrator1_p = (rtNaN);
    } else if (rtb_Divide_pl < 0.0) {
      rtb_Integrator1_p = -1.0;
    } else {
      rtb_Integrator1_p = (rtb_Divide_pl > 0.0);
    }

    /* ForEachSliceAssignment generated from: '<S299>/Info' incorporates:
     *  Product: '<S359>/Product2'
     *  SignalConversion generated from: '<S299>/Info'
     *  Signum: '<S359>/Sign1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 5] = rtb_Integrator1_p * rtb_Divide_pl *
      lam_muy_prime_idx_1;

    /* Gain: '<S312>/Gain' */
    rtb_Integrator1_p = rtb_UnaryMinus2_idx_0 * localP->CoreSubsys.Gain_Gain_c;

    /* Switch: '<S345>/Switch' incorporates:
     *  Constant: '<S345>/Constant1'
     *  Constant: '<S345>/Constant2'
     *  Gain: '<S312>/Gain'
     *  Gain: '<S345>/Gain2'
     *  Selector: '<S345>/Selector4'
     *  Selector: '<S356>/Selector3'
     */
    if (rtb_Integrator1_p * localP->CoreSubsys.Gain2_Gain_kb >=
        localP->CoreSubsys.Switch_Threshold_k) {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant2_Value_k
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    } else {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant1_Value_k[static_cast<
        int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S299>/Info' incorporates:
     *  Gain: '<S312>/Gain1'
     *  Gain: '<S312>/Gain4'
     *  Product: '<S344>/Product7'
     *  Product: '<S345>/Product1'
     *  SignalConversion generated from: '<S299>/Info'
     *  Sum: '<S312>/Add'
     *  Switch: '<S345>/Switch'
     *  UnitConversion: '<S345>/Unit Conversion'
     *  UnitConversion: '<S345>/Unit Conversion1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 6] = (rtb_Integrator1_p * 0.001 *
      lam_muy_prime_idx_1 * 0.001 + localP->CoreSubsys.Gain4_Gain_o *
      rtb_Gain1_g0 * localB->CoreSubsys[ForEach_itr_og].Selector7) *
      localP->CoreSubsys.Gain1_Gain_c;

    /* Gain: '<S311>/Gain' */
    rtb_Integrator1_p = rtb_UnaryMinus2_idx_0 * localP->CoreSubsys.Gain_Gain_k;

    /* Switch: '<S341>/Switch' incorporates:
     *  Constant: '<S341>/Constant1'
     *  Constant: '<S341>/Constant3'
     *  Gain: '<S311>/Gain'
     *  Gain: '<S341>/Gain2'
     *  Selector: '<S341>/Selector2'
     *  Selector: '<S356>/Selector3'
     */
    if (rtb_Integrator1_p * localP->CoreSubsys.Gain2_Gain_a >=
        localP->CoreSubsys.Switch_Threshold_a) {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant3_Value_a
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    } else {
      lam_muy_prime_idx_1 = localP->CoreSubsys.Constant1_Value_a[static_cast<
        int32_T>(localB->CoreSubsys[ForEach_itr_og].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S299>/Info' incorporates:
     *  Gain: '<S311>/Gain1'
     *  Gain: '<S311>/Gain3'
     *  Gain: '<S311>/Gain4'
     *  Product: '<S339>/Product6'
     *  Product: '<S340>/Product1'
     *  Product: '<S341>/Product2'
     *  SignalConversion generated from: '<S299>/Info'
     *  Sum: '<S311>/Add'
     *  Switch: '<S341>/Switch'
     *  UnitConversion: '<S340>/Unit Conversion'
     *  UnitConversion: '<S340>/Unit Conversion1'
     *  UnitConversion: '<S341>/Unit Conversion'
     *  UnitConversion: '<S341>/Unit Conversion1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 7] = ((lam_muy_prime_idx_0 *
      localP->CoreSubsys.Gain3_Gain_i * 0.001 * localB->
      CoreSubsys[ForEach_itr_og].Selector4_h * 0.001 +
      localP->CoreSubsys.Gain4_Gain_f * rtb_Gain1_g0 * localB->
      CoreSubsys[ForEach_itr_og].Selector6_g) + rtb_Integrator1_p * 0.001 *
      lam_muy_prime_idx_1 * 0.001) * localP->CoreSubsys.Gain1_Gain_p;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S365>/Selector' incorporates:
       *  Constant: '<S291>/Axle Number'
       *  ForEachSliceSelector generated from: '<S299>/Axle Number'
       *  Selector: '<S360>/Selector1'
       */
      i = static_cast<int32_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1;

      /* Switch: '<S365>/Switch' incorporates:
       *  Constant: '<S365>/Constant'
       *  Constant: '<S365>/Constant1'
       *  Constant: '<S368>/Constant3'
       *  Constant: '<S368>/Constant4'
       *  DataTypeConversion: '<S365>/Data Type Conversion'
       *  Selector: '<S365>/Selector'
       *  Sum: '<S368>/Sum'
       */
      if (localP->CoreSubsys.Constant_Value_k[i] != 0.0) {
        rtb_Gain1_g0 = AdasPlantModel0_P->PlntSpKCRollStiffArb[0] -
          AdasPlantModel0_P->PlntSpKCRollStiffNoArb[0];
        lam_muy_prime_idx_3 = AdasPlantModel0_P->PlntSpKCRollStiffArb[1] -
          AdasPlantModel0_P->PlntSpKCRollStiffNoArb[1];
      } else {
        rtb_Gain1_g0 = localP->CoreSubsys.Constant1_Value[0];
        lam_muy_prime_idx_3 = localP->CoreSubsys.Constant1_Value[1];
      }

      /* End of Switch: '<S365>/Switch' */

      /* ForEachSliceSelector generated from: '<S299>/Axle Number' incorporates:
       *  Constant: '<S291>/Axle Number'
       */
      /* Unit Conversion - from: N*m/deg to: N*m/rad
         Expression: output = (57.2958*input) + (0) */
      rtb_Integrator1_p = localP->IndependentKandCSuspension_Axle[ForEach_itr_og];

      /* Sum: '<S366>/Sum of Elements' incorporates:
       *  Constant: '<S366>/Axle Numbers'
       *  DataTypeConversion: '<S366>/Data Type Conversion'
       *  Product: '<S366>/Product'
       *  RelationalOperator: '<S366>/Relational Operator'
       *  UnitConversion: '<S365>/Unit Conversion'
       */
      localB->CoreSubsys[ForEach_itr_og].SumofElements_l = 57.295779513082323 *
        rtb_Gain1_g0 * static_cast<real_T>(rtb_Integrator1_p ==
        localP->CoreSubsys.Constrainedspringdampercombinat[0]) +
        57.295779513082323 * lam_muy_prime_idx_3 * static_cast<real_T>
        (rtb_Integrator1_p == localP->
         CoreSubsys.Constrainedspringdampercombinat[1]);

      /* Sum: '<S360>/Sum1' incorporates:
       *  Constant: '<S291>/Wheel Number'
       *  Constant: '<S360>/Constant'
       *  Constant: '<S360>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S299>/Wheel Number'
       *  Gain: '<S360>/Gain'
       *  Selector: '<S360>/Selector1'
       *  Sum: '<S360>/Sum'
       */
      rtb_Integrator1_p = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_m[i]
                           + localP->CoreSubsys.Constant_Value_g) *
        localP->CoreSubsys.Gain_Gain_o - localP->
        IndependentKandCSuspension_WhlN[ForEach_itr_og];

      /* Signum: '<S360>/Sign1' */
      if (std::isnan(rtb_Integrator1_p)) {
        /* Signum: '<S360>/Sign1' */
        localB->CoreSubsys[ForEach_itr_og].Sign1 = (rtNaN);
      } else if (rtb_Integrator1_p < 0.0) {
        /* Signum: '<S360>/Sign1' */
        localB->CoreSubsys[ForEach_itr_og].Sign1 = -1.0;
      } else {
        /* Signum: '<S360>/Sign1' */
        localB->CoreSubsys[ForEach_itr_og].Sign1 = (rtb_Integrator1_p > 0.0);
      }

      /* End of Signum: '<S360>/Sign1' */
    }

    /* Selector: '<S360>/Selector2' incorporates:
     *  Constant: '<S291>/Axle Number'
     *  ForEachSliceSelector generated from: '<S299>/Axle Number'
     *  Selector: '<S307>/Selector1'
     */
    i = static_cast<int32_T>(localP->
      IndependentKandCSuspension_Axle[ForEach_itr_og]) - 1;

    /* Gain: '<S359>/Gain4' incorporates:
     *  Constant: '<S370>/Constant'
     *  Gain: '<S360>/Gain1'
     *  Product: '<S360>/Divide'
     *  Product: '<S360>/Product'
     *  Product: '<S360>/Product2'
     *  Selector: '<S360>/Selector2'
     *  Sum: '<S359>/Add'
     */
    lam_muy_prime_idx_3 = (localB->CoreSubsys[ForEach_itr_og].SumofElements_l *
      rtb_Smallangleapproximationford / rtb_UnaryMinus1_c[i] *
      localB->CoreSubsys[ForEach_itr_og].Sign1 * localP->CoreSubsys.Gain1_Gain_o
      + (rtb_Switch_e1 + localP->CoreSubsys.Constant_Value_m)) *
      localP->CoreSubsys.Gain4_Gain_od;

    /* Sum: '<S304>/Sum' incorporates:
     *  Gain: '<S358>/Sign convention'
     *  Selector: '<S304>/Selector'
     *  Selector: '<S356>/Selector3'
     */
    rtb_Divide_pl = localB->Re[static_cast<int32_T>(localB->
      CoreSubsys[ForEach_itr_og].Sum2) - 1] +
      localP->CoreSubsys.Signconvention_Gain * rtb_Divide_pl;
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S307>/Sum1' incorporates:
       *  Constant: '<S291>/Wheel Number'
       *  Constant: '<S307>/Constant'
       *  Constant: '<S307>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S299>/Wheel Number'
       *  Gain: '<S307>/Gain'
       *  Selector: '<S307>/Selector1'
       *  Sum: '<S307>/Sum'
       */
      rtb_Integrator1_p = localP->IndependentKandCSuspension_WhlN[ForEach_itr_og]
        - (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_b[i] +
           localP->CoreSubsys.Constant_Value_d) *
        localP->CoreSubsys.Gain_Gain_le;

      /* Signum: '<S307>/Sign' */
      if (std::isnan(rtb_Integrator1_p)) {
        /* Signum: '<S307>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign_d = (rtNaN);
      } else if (rtb_Integrator1_p < 0.0) {
        /* Signum: '<S307>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign_d = -1.0;
      } else {
        /* Signum: '<S307>/Sign' */
        localB->CoreSubsys[ForEach_itr_og].Sign_d = (rtb_Integrator1_p > 0.0);
      }

      /* End of Signum: '<S307>/Sign' */
    }

    /* ForEachSliceAssignment generated from: '<S299>/WhlFz' */
    rtb_ImpAsg_InsertedFor_WhlFz_at[ForEach_itr_og] = lam_muy_prime_idx_3;

    /* ForEachSliceAssignment generated from: '<S299>/WhlAng' incorporates:
     *  Product: '<S307>/Product'
     *  SignalConversion generated from: '<S299>/WhlAng'
     */
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_og * 3] = rtb_FrontBiasGain *
      localB->CoreSubsys[ForEach_itr_og].Sign_d;
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_og * 3 + 1] = rtb_Sum1_m;
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_og * 3 + 2] = rtb_Product_py;

    /* ForEachSliceAssignment generated from: '<S299>/VehM' incorporates:
     *  Constant: '<S304>/Constant'
     *  Product: '<S304>/Product'
     *  Product: '<S304>/Product1'
     *  UnaryMinus: '<S304>/Unary Minus'
     */
    i = ForEach_itr_og * 3;
    rtb_ImpAsg_InsertedFor_VehM_at_[i] = -(lam_muy_prime_idx_0 * rtb_Divide_pl);
    rtb_ImpAsg_InsertedFor_VehM_at_[i + 1] = rtb_UnaryMinus2_idx_0 *
      rtb_Divide_pl;
    rtb_ImpAsg_InsertedFor_VehM_at_[i + 2] = localP->CoreSubsys.Constant_Value_i;

    /* ForEachSliceAssignment generated from: '<S299>/VehFz' incorporates:
     *  Gain: '<S358>/Vehicle Force Sign'
     */
    rtb_ImpAsg_InsertedFor_VehFz_at[ForEach_itr_og] =
      localP->CoreSubsys.VehicleForceSign_Gain * lam_muy_prime_idx_3;
  }

  /* End of Outputs for SubSystem: '<S291>/For each track and axle combination calculate suspension forces and moments' */

  /* Reshape: '<S291>/Reshape5' */
  std::memcpy(&localB->Reshape5[0], &rtb_ImpAsg_InsertedFor_WhlAng_a[0], 12U *
              sizeof(real_T));

  /* Selector: '<S107>/Selector' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector_l[0] = localB->Reshape5[1];

  /* Selector: '<S107>/Selector1' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector1_b[0] = localB->Reshape5[2];

  /* Selector: '<S107>/Selector' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector_l[1] = localB->Reshape5[4];

  /* Selector: '<S107>/Selector1' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector1_b[1] = localB->Reshape5[5];

  /* Outputs for Iterator SubSystem: '<S108>/Kinpin axle moment and tie rod force' */
  /* Constant: '<S108>/RckGnConstant' */
  Kinpinaxlemomentandtierodforce(rtb_Selector1_e, rtb_Selector2, rtb_Selector3,
    rtb_Selector_l, rtb_Selector1_b, AdasPlantModel0_P->PlntSteerRckGn,
    rtb_ImpAsg_InsertedFor_Fsa_y__f, AdasPlantModel0_P->PlntSteerHbLead,
    AdasPlantModel0_P->PlntSteerKngpnOfst, AdasPlantModel0_P->PlntSteerLambda,
    AdasPlantModel0_P->PlntSteerRatio, AdasPlantModel0_P->PlntSteerStcLdRadius);

  /* End of Outputs for SubSystem: '<S108>/Kinpin axle moment and tie rod force' */

  /* Backlash: '<S117>/Backlash' */
  rtb_Gain1_g0 = localP->FrontSteering_DbWdth / 2.0;
  if (rtb_min < localDW->PrevY - rtb_Gain1_g0) {
    /* Backlash: '<S117>/Backlash' */
    localB->Backlash = rtb_min + rtb_Gain1_g0;
  } else if (rtb_min <= localDW->PrevY + rtb_Gain1_g0) {
    /* Backlash: '<S117>/Backlash' */
    localB->Backlash = localDW->PrevY;
  } else {
    /* Backlash: '<S117>/Backlash' */
    localB->Backlash = rtb_min - rtb_Gain1_g0;
  }

  /* End of Backlash: '<S117>/Backlash' */

  /* Saturate: '<S117>/Saturation' */
  if (localB->Backlash > AdasPlantModel0_P->PlntSteerRange) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntSteerRange;
  } else if (localB->Backlash < -AdasPlantModel0_P->PlntSteerRange) {
    rtb_UnaryMinus2_idx_0 = -AdasPlantModel0_P->PlntSteerRange;
  } else {
    rtb_UnaryMinus2_idx_0 = localB->Backlash;
  }

  /* Sum: '<S131>/Subtract' incorporates:
   *  Saturate: '<S117>/Saturation'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   */
  lam_muy_prime_idx_1 = rtb_UnaryMinus2_idx_0 -
    localX->IntegratorSecondOrder_CSTATE_a[0];

  /* Integrator: '<S131>/Integrator' */
  /* Limited  Integrator  */
  if (localX->Integrator_CSTATE_e >= localP->Integrator_UpperSat) {
    localX->Integrator_CSTATE_e = localP->Integrator_UpperSat;
  } else if (localX->Integrator_CSTATE_e <= localP->Integrator_LowerSat) {
    localX->Integrator_CSTATE_e = localP->Integrator_LowerSat;
  }

  /* Gain: '<S131>/Gain2' */
  localB->Gain2 = localP->SteerTorqueControl_D * lam_muy_prime_idx_1;

  /* Derivative: '<S131>/Derivative' incorporates:
   *  Derivative: '<S218>/Derivative'
   */
  rtb_Product_py = (&AdasPlantModel0_M)->Timing.t[0];
  if ((localDW->TimeStampA >= rtb_Product_py) && (localDW->TimeStampB >=
       rtb_Product_py)) {
    rtb_Gain1_g0 = 0.0;
  } else {
    rtb_Gain1_g0 = localDW->TimeStampA;
    lastU = &localDW->LastUAtTimeA;
    if (localDW->TimeStampA < localDW->TimeStampB) {
      if (localDW->TimeStampB < rtb_Product_py) {
        rtb_Gain1_g0 = localDW->TimeStampB;
        lastU = &localDW->LastUAtTimeB;
      }
    } else if (localDW->TimeStampA >= rtb_Product_py) {
      rtb_Gain1_g0 = localDW->TimeStampB;
      lastU = &localDW->LastUAtTimeB;
    }

    rtb_Gain1_g0 = (localB->Gain2 - *lastU) / (rtb_Product_py - rtb_Gain1_g0);
  }

  /* End of Derivative: '<S131>/Derivative' */

  /* Sum: '<S131>/Subtract1' incorporates:
   *  Gain: '<S131>/Gain'
   *  Integrator: '<S131>/Integrator'
   */
  rtb_FrontBiasGain = (localP->SteerTorqueControl_P * lam_muy_prime_idx_1 +
                       localX->Integrator_CSTATE_e) + rtb_Gain1_g0;

  /* Saturate: '<S131>/Saturation' */
  if (rtb_FrontBiasGain > localP->SteerTorqueControl_OutSatUpLmt) {
    rtb_FrontBiasGain = localP->SteerTorqueControl_OutSatUpLmt;
  } else if (rtb_FrontBiasGain < localP->SteerTorqueControl_OutSatLowLmt) {
    rtb_FrontBiasGain = localP->SteerTorqueControl_OutSatLowLmt;
  }

  /* End of Saturate: '<S131>/Saturation' */

  /* Switch: '<S108>/Switch' incorporates:
   *  Constant: '<S108>/SteerInputFlagConstant'
   */
  if (localP->SteerInputFlagConstant_Value > localP->Switch_Threshold_d) {
    rtb_Gain1_g0 = 0.0;
  } else {
    rtb_Gain1_g0 = rtb_FrontBiasGain;
  }

  /* End of Switch: '<S108>/Switch' */

  /* SecondOrderIntegrator: '<S138>/Integrator, Second-Order' */
  rtb_IntegratorSecondOrder_o1 = localX->IntegratorSecondOrder_CSTATE_m[0];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S127>/Unary Minus' incorporates:
     *  Constant: '<S127>/Constant'
     */
    localB->UnaryMinus_n = -localP->Constant_Value_dn;
  }

  /* Switch: '<S127>/Switch' incorporates:
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  Fcn: '<S127>/Fcn'
   *  Logic: '<S127>/Logical Operator'
   *  Product: '<S127>/Product'
   *  RelationalOperator: '<S128>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   *  SecondOrderIntegrator: '<S138>/Integrator, Second-Order'
   *  Switch: '<S127>/Switch1'
   */
  if ((localX->IntegratorSecondOrder_CSTATE_m[1] >=
       -localP->div0protectpoly_thresh_i) &&
      (localX->IntegratorSecondOrder_CSTATE_m[1] <=
       localP->div0protectpoly_thresh_i)) {
    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if (localX->IntegratorSecondOrder_CSTATE_m[1] >= localP->Switch1_Threshold_h)
    {
      rtb_UnaryMinus2_idx_0 = localP->Constant_Value_dn;
    } else {
      rtb_UnaryMinus2_idx_0 = localB->UnaryMinus_n;
    }

    rtb_Divide_pl = 0.02 / (3.0 - rt_powd_snf
      (localX->IntegratorSecondOrder_CSTATE_m[1] / 0.01, 2.0)) *
      rtb_UnaryMinus2_idx_0;
  } else {
    rtb_Divide_pl = localX->IntegratorSecondOrder_CSTATE_m[1];
  }

  /* End of Switch: '<S127>/Switch' */

  /* Lookup_n-D: '<S125>/TrqAssistTbl' incorporates:
   *  Gain: '<S665>/Gain1'
   */
  rtb_UnaryMinus2_idx_0 = look2_binlcpw(rtb_Gain1_g0, localB->UnitConversion[0],
    AdasPlantModel0_P->PlntSteerWheelTrqBpt, localP->FrontSteering_VehSpdBpts,
    AdasPlantModel0_P->PlntSteerTrqAsstTbl, localP->TrqAssistTbl_maxIndex, 3U);

  /* Saturate: '<S125>/Saturation1' */
  if (rtb_UnaryMinus2_idx_0 > AdasPlantModel0_P->PlntSteerTrqLimit) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntSteerTrqLimit;
  } else if (rtb_UnaryMinus2_idx_0 < -AdasPlantModel0_P->PlntSteerTrqLimit) {
    rtb_UnaryMinus2_idx_0 = -AdasPlantModel0_P->PlntSteerTrqLimit;
  }

  /* Product: '<S125>/Product' incorporates:
   *  Saturate: '<S125>/Saturation1'
   */
  rtb_UnaryMinus2_idx_0 *= rtb_Divide_pl;

  /* Saturate: '<S125>/Saturation2' */
  if (rtb_UnaryMinus2_idx_0 > AdasPlantModel0_P->PlntSteerPwrLimit) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntSteerPwrLimit;
  } else if (rtb_UnaryMinus2_idx_0 < -AdasPlantModel0_P->PlntSteerPwrLimit) {
    rtb_UnaryMinus2_idx_0 = -AdasPlantModel0_P->PlntSteerPwrLimit;
  }

  /* Product: '<S126>/Divide' incorporates:
   *  Constant: '<S126>/Constant'
   *  Gain: '<S125>/Gain1'
   *  Integrator: '<S126>/Integrator1'
   *  Product: '<S125>/Product1'
   *  Saturate: '<S125>/Saturation2'
   *  Sum: '<S126>/Sum'
   */
  localB->Divide_b = (rtb_UnaryMinus2_idx_0 / rtb_Divide_pl *
                      localP->FrontSteering_Eta - localX->Integrator1_CSTATE_c1)
    * AdasPlantModel0_P->PlntSteerWc;

  /* Sum: '<S131>/Subtract2' incorporates:
   *  Gain: '<S131>/Gain1'
   *  Gain: '<S131>/Gain3'
   */
  localB->Subtract2 = localP->SteerTorqueControl_I * lam_muy_prime_idx_1 -
    localP->SteerTorqueControl_A * rtb_FrontBiasGain;

  /* Sum: '<S119>/Add' incorporates:
   *  Gain: '<S136>/Gain'
   *  Gain: '<S136>/Gain1'
   *  SecondOrderIntegrator: '<S138>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   *  Sum: '<S136>/Add'
   *  Sum: '<S136>/Add1'
   */
  lam_muy_prime_idx_3 = (localX->IntegratorSecondOrder_CSTATE_a[0] -
    rtb_IntegratorSecondOrder_o1) * AdasPlantModel0_P->PlntSteerTorStf +
    (localX->IntegratorSecondOrder_CSTATE_a[1] -
     localX->IntegratorSecondOrder_CSTATE_m[1]) *
    AdasPlantModel0_P->PlntSteerTorDamp;

  /* Sum: '<S132>/Add' incorporates:
   *  Constant: '<S119>/Constant1'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   */
  localB->Add_p = localX->IntegratorSecondOrder_CSTATE_a[0] -
    localP->Constant1_Value_fu[0];

  /* Sum: '<S132>/Add1' incorporates:
   *  Constant: '<S119>/Constant1'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   */
  localB->Add1_a = localX->IntegratorSecondOrder_CSTATE_a[1] -
    localP->Constant1_Value_fu[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S132>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsyste = localDW->TmpLatchAtTriggeredSubsystemInp;

    /* Memory generated from: '<S132>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_m = localDW->TmpLatchAtTriggeredSubsystemI_e;

    /* Outputs for Triggered SubSystem: '<S132>/Triggered Subsystem' */
    AdasPlantMod_TriggeredSubsystem(localB->Add1_a, localB->Add_p,
      rtb_TmpLatchAtTriggeredSubsyste, rtb_TmpLatchAtTriggeredSubsys_m,
      AdasPlantModel0_P->PlntSteerUpprFric, AdasPlantModel0_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem, &localZCE->TriggeredSubsystem);

    /* End of Outputs for SubSystem: '<S132>/Triggered Subsystem' */
  }

  /* Sum: '<S132>/Add3' */
  rtb_FrontBiasGain = localB->Add_p - localB->TriggeredSubsystem.In;

  /* Sum: '<S132>/Add2' */
  rtb_Add2_n = localB->TriggeredSubsystem.y + rtb_FrontBiasGain;

  /* Signum: '<S132>/Sign' */
  if (std::isnan(localB->Add1_a)) {
    /* Signum: '<S132>/Sign' */
    localB->Sign = localB->Add1_a;
  } else if (localB->Add1_a < 0.0) {
    /* Signum: '<S132>/Sign' */
    localB->Sign = -1.0;
  } else {
    /* Signum: '<S132>/Sign' */
    localB->Sign = (localB->Add1_a > 0.0);
  }

  /* End of Signum: '<S132>/Sign' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S140>/Enable' */
    localB->HiddenBuf_InsertedFor_EnabledSu = localB->Sign;
  }

  /* Outputs for Enabled SubSystem: '<S132>/Enabled Subsystem' */
  AdasPlantModel_EnabledSubsystem(localB->HiddenBuf_InsertedFor_EnabledSu,
    rtb_Add2_n, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem,
    &localDW->EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S132>/Enabled Subsystem' */

  /* Sum: '<S132>/Add4' */
  rtb_Add4 = localB->TriggeredSubsystem.y_a + rtb_FrontBiasGain;

  /* Gain: '<S132>/Gain' */
  localB->Gain = localP->Gain_Gain_p * localB->Sign;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S141>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_n = localB->Gain;
  }

  /* Outputs for Enabled SubSystem: '<S132>/Enabled Subsystem1' */
  AdasPlantMode_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_n,
    rtb_Add4, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem1,
    &localDW->EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S132>/Enabled Subsystem1' */

  /* Sum: '<S119>/Add1' incorporates:
   *  Sum: '<S132>/Add5'
   */
  rtb_FrontBiasGain = (rtb_Gain1_g0 - (localB->EnabledSubsystem.y +
    localB->EnabledSubsystem1.y)) - lam_muy_prime_idx_3;

  /* Sum: '<S133>/Add' incorporates:
   *  Constant: '<S119>/Constant2'
   */
  localB->Add_c = rtb_IntegratorSecondOrder_o1 - localP->Constant2_Value_g[0];

  /* Sum: '<S133>/Add1' incorporates:
   *  Constant: '<S119>/Constant2'
   *  SecondOrderIntegrator: '<S138>/Integrator, Second-Order'
   */
  localB->Add1_h5 = localX->IntegratorSecondOrder_CSTATE_m[1] -
    localP->Constant2_Value_g[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S133>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_i = localDW->TmpLatchAtTriggeredSubsystemI_l;

    /* Memory generated from: '<S133>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_g = localDW->TmpLatchAtTriggeredSubsystemI_d;

    /* Outputs for Triggered SubSystem: '<S133>/Triggered Subsystem' */
    AdasPlantMod_TriggeredSubsystem(localB->Add1_h5, localB->Add_c,
      rtb_TmpLatchAtTriggeredSubsys_i, rtb_TmpLatchAtTriggeredSubsys_g,
      AdasPlantModel0_P->PlntSteerUpprFric, AdasPlantModel0_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_d, &localZCE->TriggeredSubsystem_d);

    /* End of Outputs for SubSystem: '<S133>/Triggered Subsystem' */
  }

  /* Sum: '<S133>/Add3' */
  rtb_Gain1_g0 = localB->Add_c - localB->TriggeredSubsystem_d.In;

  /* Sum: '<S133>/Add2' */
  rtb_Add2_f = localB->TriggeredSubsystem_d.y + rtb_Gain1_g0;

  /* Signum: '<S133>/Sign' */
  if (std::isnan(localB->Add1_h5)) {
    /* Signum: '<S133>/Sign' */
    localB->Sign_e = localB->Add1_h5;
  } else if (localB->Add1_h5 < 0.0) {
    /* Signum: '<S133>/Sign' */
    localB->Sign_e = -1.0;
  } else {
    /* Signum: '<S133>/Sign' */
    localB->Sign_e = (localB->Add1_h5 > 0.0);
  }

  /* End of Signum: '<S133>/Sign' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S147>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_l = localB->Sign_e;
  }

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  AdasPlantModel_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enabled_l,
    rtb_Add2_f, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem_i,
    &localDW->EnabledSubsystem_i);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem' */

  /* Sum: '<S133>/Add4' */
  rtb_Add4_p = localB->TriggeredSubsystem_d.y_a + rtb_Gain1_g0;

  /* Gain: '<S133>/Gain' */
  localB->Gain_k = localP->Gain_Gain_k * localB->Sign_e;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S148>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_b = localB->Gain_k;
  }

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  AdasPlantMode_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_b,
    rtb_Add4_p, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem1_j,
    &localDW->EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem1' */

  /* Sum: '<S119>/Add3' incorporates:
   *  Gain: '<S137>/Gain'
   *  Gain: '<S137>/Gain1'
   *  SecondOrderIntegrator: '<S138>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S157>/Integrator, Second-Order'
   *  Sum: '<S137>/Add'
   *  Sum: '<S137>/Add1'
   */
  rtb_Gain1_g0 = (rtb_IntegratorSecondOrder_o1 -
                  localX->IntegratorSecondOrder_CSTATE_h[0]) *
    AdasPlantModel0_P->PlntSteerTorStf + (localX->
    IntegratorSecondOrder_CSTATE_m[1] - localX->IntegratorSecondOrder_CSTATE_h[1])
    * AdasPlantModel0_P->PlntSteerTorDamp;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S132>/Memory' */
    localB->Memory_d = localDW->Memory_PreviousInput_i;

    /* Memory: '<S132>/Memory1' */
    localB->Memory1 = localDW->Memory1_PreviousInput;

    /* Memory: '<S133>/Memory' */
    localB->Memory_e = localDW->Memory_PreviousInput_e;

    /* Memory: '<S133>/Memory1' */
    localB->Memory1_d = localDW->Memory1_PreviousInput_f;
  }

  /* MATLAB Function: '<S154>/MATLAB Function1' */
  AdasPlantModel0_MATLABFunction1(rtb_IntegratorSecondOrder_o1,
    localP->FrontSteering_SptlAng, &localB->sf_MATLABFunction1);

  /* Gain: '<S157>/Gain3' incorporates:
   *  Gain: '<S157>/Gain'
   *  Product: '<S154>/Divide'
   *  Product: '<S157>/Divide1'
   *  Product: '<S157>/Product4'
   *  Sum: '<S108>/Add'
   *  Sum: '<S157>/Add'
   */
  localB->Gain3 = (rtb_Gain1_g0 / localB->sf_MATLABFunction1.y *
                   AdasPlantModel0_P->PlntSteerEpsilon / localB->Divide_l +
                   (rtb_ImpAsg_InsertedFor_Fsa_y__f[0] +
                    rtb_ImpAsg_InsertedFor_Fsa_y__f[1])) * localB->Divide_l *
    (1.0 / AdasPlantModel0_P->PlntSteerPnInert);

  /* Gain: '<S138>/Gain' incorporates:
   *  Integrator: '<S126>/Integrator1'
   *  Sum: '<S119>/Add2'
   *  Sum: '<S133>/Add5'
   */
  localB->Gain_e = (((lam_muy_prime_idx_3 + localX->Integrator1_CSTATE_c1) -
                     (localB->EnabledSubsystem_i.y +
                      localB->EnabledSubsystem1_j.y)) - rtb_Gain1_g0) * (1.0 /
    AdasPlantModel0_P->PlntSteerLowerInertia);

  /* Gain: '<S139>/Gain' */
  localB->Gain_m = 1.0 / AdasPlantModel0_P->PlntSteerUpperInertia *
    rtb_FrontBiasGain;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S260>/Add' incorporates:
     *  Constant: '<S260>/Constant'
     *  Constant: '<S260>/Constant1'
     */
    rtb_Product2_fq = AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
      AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

    /* Product: '<S260>/Divide' incorporates:
     *  Constant: '<S260>/Constant3'
     */
    rtb_Divide_pl = localP->RackandPinforDynStr_d_c / rtb_Product2_fq;

    /* Sum: '<S260>/Add1' incorporates:
     *  Constant: '<S260>/Constant2'
     *  Math: '<S260>/Math Function'
     *  Math: '<S260>/Math Function1'
     */
    rtb_Product2_fq = rtb_Product2_fq * rtb_Product2_fq +
      localP->RackandPinforDynStr_d_c * localP->RackandPinforDynStr_d_c;

    /* Sum: '<S260>/Add2' incorporates:
     *  Constant: '<S260>/Constant4'
     *  Constant: '<S260>/Constant5'
     *  Math: '<S260>/Math Function2'
     *  Math: '<S260>/Math Function3'
     */
    rtb_FrontBiasGain = (AdasPlantModel0_P->PlntSteerStrgArmLngth *
                         AdasPlantModel0_P->PlntSteerStrgArmLngth +
                         rtb_Product2_fq) -
      AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;

    /* Sqrt: '<S260>/Sqrt' */
    rtb_Product2_fq = std::sqrt(rtb_Product2_fq);

    /* Product: '<S260>/Divide1' incorporates:
     *  Constant: '<S260>/Constant6'
     *  Constant: '<S260>/Constant7'
     */
    rtb_UnaryMinus2_idx_0 = rtb_FrontBiasGain / localP->Constant6_Value_c /
      AdasPlantModel0_P->PlntSteerStrgArmLngth / rtb_Product2_fq;

    /* Trigonometry: '<S260>/Trigonometric Function1' */
    if (rtb_UnaryMinus2_idx_0 > 1.0) {
      rtb_UnaryMinus2_idx_0 = 1.0;
    } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
      rtb_UnaryMinus2_idx_0 = -1.0;
    }

    /* Sum: '<S260>/Add3' incorporates:
     *  Constant: '<S260>/Constant8'
     *  Trigonometry: '<S260>/Trigonometric Function'
     *  Trigonometry: '<S260>/Trigonometric Function1'
     */
    localB->Add3_c = (localP->Constant8_Value_l - std::atan(rtb_Divide_pl)) -
      std::acos(rtb_UnaryMinus2_idx_0);

    /* Product: '<S244>/Divide' incorporates:
     *  Constant: '<S109>/RckGnConstant'
     *  Constant: '<S244>/Constant'
     */
    localB->Divide_n = AdasPlantModel0_P->PlntSteerRckGn /
      localP->Constant_Value_ge;

    /* UnaryMinus: '<S255>/Unary Minus1' */
    localB->UnaryMinus1_f = -localB->Divide_n;
  }

  /* Sum: '<S258>/Add' incorporates:
   *  Constant: '<S258>/Constant'
   *  Constant: '<S258>/Constant1'
   *  Product: '<S255>/Product'
   *  SecondOrderIntegrator: '<S244>/Integrator, Second-Order'
   */
  rtb_Gain1_g0 = (AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
                  localB->UnaryMinus1_f * localX->
                  IntegratorSecondOrder_CSTATE_b[0]) -
    AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S258>/Trigonometric Function' incorporates:
   *  Constant: '<S258>/Constant3'
   *  Product: '<S258>/Divide'
   */
  rtb_Divide_pl = std::atan(localP->RackandPinforDynStr_d_c / rtb_Gain1_g0);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S258>/Math Function1' incorporates:
     *  Constant: '<S258>/Constant2'
     */
    localB->MathFunction1_my = localP->RackandPinforDynStr_d_c *
      localP->RackandPinforDynStr_d_c;

    /* Math: '<S258>/Math Function2' incorporates:
     *  Constant: '<S258>/Constant4'
     */
    localB->MathFunction2_d = AdasPlantModel0_P->PlntSteerStrgArmLngth *
      AdasPlantModel0_P->PlntSteerStrgArmLngth;

    /* Math: '<S258>/Math Function3' incorporates:
     *  Constant: '<S258>/Constant5'
     */
    localB->MathFunction3_g = AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S258>/Add1' incorporates:
   *  Math: '<S258>/Math Function'
   */
  rtb_Gain1_g0 = rtb_Gain1_g0 * rtb_Gain1_g0 + localB->MathFunction1_my;

  /* Product: '<S258>/Divide1' incorporates:
   *  Constant: '<S258>/Constant6'
   *  Constant: '<S258>/Constant7'
   *  Sqrt: '<S258>/Sqrt'
   *  Sum: '<S258>/Add2'
   */
  rtb_UnaryMinus2_idx_0 = ((rtb_Gain1_g0 + localB->MathFunction2_d) -
    localB->MathFunction3_g) / localP->Constant6_Value_nq /
    AdasPlantModel0_P->PlntSteerStrgArmLngth / std::sqrt(rtb_Gain1_g0);

  /* Trigonometry: '<S258>/Trigonometric Function1' */
  if (rtb_UnaryMinus2_idx_0 > 1.0) {
    rtb_UnaryMinus2_idx_0 = 1.0;
  } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  }

  /* Sum: '<S255>/Add' incorporates:
   *  Constant: '<S258>/Constant8'
   *  Sum: '<S258>/Add3'
   *  Trigonometry: '<S258>/Trigonometric Function1'
   */
  rtb_Gain1_g0 = ((localP->Constant8_Value_g - rtb_Divide_pl) - std::acos
                  (rtb_UnaryMinus2_idx_0)) - localB->Add3_c;

  /* Sum: '<S259>/Add' incorporates:
   *  Constant: '<S259>/Constant'
   *  Constant: '<S259>/Constant1'
   *  Product: '<S255>/Product3'
   *  SecondOrderIntegrator: '<S244>/Integrator, Second-Order'
   */
  rtb_FrontBiasGain = (AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0 -
                       localB->Divide_n * localX->
                       IntegratorSecondOrder_CSTATE_b[0]) -
    AdasPlantModel0_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S259>/Trigonometric Function' incorporates:
   *  Constant: '<S259>/Constant3'
   *  Product: '<S259>/Divide'
   */
  rtb_Divide_pl = std::atan(localP->RackandPinforDynStr_d_c / rtb_FrontBiasGain);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S259>/Math Function1' incorporates:
     *  Constant: '<S259>/Constant2'
     */
    localB->MathFunction1_n = localP->RackandPinforDynStr_d_c *
      localP->RackandPinforDynStr_d_c;

    /* Math: '<S259>/Math Function2' incorporates:
     *  Constant: '<S259>/Constant4'
     */
    localB->MathFunction2_ds = AdasPlantModel0_P->PlntSteerStrgArmLngth *
      AdasPlantModel0_P->PlntSteerStrgArmLngth;

    /* Math: '<S259>/Math Function3' incorporates:
     *  Constant: '<S259>/Constant5'
     */
    localB->MathFunction3_n = AdasPlantModel0_P->PlntSteerTieRodLngth *
      AdasPlantModel0_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S259>/Add1' incorporates:
   *  Math: '<S259>/Math Function'
   */
  rtb_FrontBiasGain = rtb_FrontBiasGain * rtb_FrontBiasGain +
    localB->MathFunction1_n;

  /* Product: '<S259>/Divide1' incorporates:
   *  Constant: '<S259>/Constant6'
   *  Constant: '<S259>/Constant7'
   *  Sqrt: '<S259>/Sqrt'
   *  Sum: '<S259>/Add2'
   */
  rtb_UnaryMinus2_idx_0 = ((rtb_FrontBiasGain + localB->MathFunction2_ds) -
    localB->MathFunction3_n) / localP->Constant6_Value_l /
    AdasPlantModel0_P->PlntSteerStrgArmLngth / std::sqrt(rtb_FrontBiasGain);

  /* Trigonometry: '<S259>/Trigonometric Function1' */
  if (rtb_UnaryMinus2_idx_0 > 1.0) {
    rtb_UnaryMinus2_idx_0 = 1.0;
  } else if (rtb_UnaryMinus2_idx_0 < -1.0) {
    rtb_UnaryMinus2_idx_0 = -1.0;
  }

  /* Sum: '<S255>/Add1' incorporates:
   *  Constant: '<S259>/Constant8'
   *  Sum: '<S259>/Add3'
   *  Trigonometry: '<S259>/Trigonometric Function1'
   */
  rtb_FrontBiasGain = localB->Add3_c - ((localP->Constant8_Value_nr -
    rtb_Divide_pl) - std::acos(rtb_UnaryMinus2_idx_0));

  /* Switch: '<S244>/Switch' incorporates:
   *  SecondOrderIntegrator: '<S244>/Integrator, Second-Order'
   */
  if (localX->IntegratorSecondOrder_CSTATE_b[0] > localP->Switch_Threshold_k) {
    rtb_UnaryMinus1_c[0] = rtb_FrontBiasGain;
    rtb_UnaryMinus1_c[1] = rtb_Gain1_g0;
  } else {
    rtb_UnaryMinus1_c[0] = rtb_Gain1_g0;
    rtb_UnaryMinus1_c[1] = rtb_FrontBiasGain;
  }

  /* End of Switch: '<S244>/Switch' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S244>/Gain5' incorporates:
     *  Constant: '<S109>/PctAckConstant'
     */
    localB->Gain5_n = localP->Gain5_Gain_h * AdasPlantModel0_P->PlntSteerPctAck;

    /* Sum: '<S244>/Add1' incorporates:
     *  Constant: '<S244>/Constant1'
     */
    localB->Add1_i = localP->Constant1_Value_a - localB->Gain5_n;
  }

  /* Switch: '<S244>/Switch1' incorporates:
   *  Product: '<S244>/Product1'
   *  Product: '<S244>/Product2'
   *  SecondOrderIntegrator: '<S244>/Integrator, Second-Order'
   *  Sum: '<S244>/Sum'
   */
  if (localX->IntegratorSecondOrder_CSTATE_b[0] > localP->Switch1_Threshold_k) {
    rtb_UnaryMinus2_idx_0 = rtb_UnaryMinus1_c[0] * localB->Add1_i +
      rtb_UnaryMinus1_c[1] * localB->Gain5_n;
    rtb_Divide_pl = rtb_UnaryMinus1_c[0];
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_UnaryMinus1_c[0];
    rtb_Divide_pl = rtb_UnaryMinus1_c[0] * localB->Add1_i + rtb_UnaryMinus1_c[1]
      * localB->Gain5_n;
  }

  /* End of Switch: '<S244>/Switch1' */

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S109>/LocFlagConstant'
   *  Constant: '<S244>/AckermanFlagConstant'
   *  Switch: '<S244>/Switch4'
   *  UnaryMinus: '<S197>/Unary Minus1'
   */
  if (localP->LocFlagConstant_Value_e > localP->Switch_Threshold_p) {
    /* Switch: '<S244>/Switch4' incorporates:
     *  Constant: '<S244>/AckermanFlagConstant'
     */
    if (!(localP->AckermanFlagConstant_Value_n > localP->Switch4_Threshold_o)) {
      rtb_Gain1_g0 = rtb_UnaryMinus2_idx_0;
    }
  } else if (localP->AckermanFlagConstant_Value_n > localP->Switch4_Threshold_o)
  {
    /* Switch: '<S244>/Switch4' incorporates:
     *  UnaryMinus: '<S197>/Unary Minus1'
     */
    rtb_Gain1_g0 = -rtb_Gain1_g0;
  } else {
    rtb_Gain1_g0 = -rtb_UnaryMinus2_idx_0;
  }

  /* End of Switch: '<S197>/Switch' */

  /* Gain: '<S107>/Gain' */
  localB->RL = localP->Gain_Gain_l * rtb_Gain1_g0;

  /* Switch: '<S197>/Switch1' incorporates:
   *  Constant: '<S109>/LocFlagConstant'
   *  Constant: '<S244>/AckermanFlagConstant'
   *  Switch: '<S244>/Switch5'
   *  UnaryMinus: '<S197>/Unary Minus'
   */
  if (localP->LocFlagConstant_Value_e > localP->Switch1_Threshold_m1) {
    /* Switch: '<S244>/Switch5' incorporates:
     *  Constant: '<S244>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value_n > localP->Switch5_Threshold_c) {
      rtb_Divide_pl = rtb_FrontBiasGain;
    }
  } else if (localP->AckermanFlagConstant_Value_n > localP->Switch5_Threshold_c)
  {
    /* Switch: '<S244>/Switch5' incorporates:
     *  UnaryMinus: '<S197>/Unary Minus'
     */
    rtb_Divide_pl = -rtb_FrontBiasGain;
  } else {
    rtb_Divide_pl = -rtb_Divide_pl;
  }

  /* Gain: '<S107>/Gain1' incorporates:
   *  Switch: '<S197>/Switch1'
   */
  localB->RR = localP->Gain1_Gain_a * rtb_Divide_pl;

  /* Selector: '<S109>/Selector' */
  rtb_Selector_k[0] = rtb_ImpAsg_InsertedFor_Fx_at_in[2];

  /* Selector: '<S109>/Selector1' */
  rtb_Selector1_i[0] = rtb_ImpAsg_InsertedFor_Fy_at_in[2];

  /* Selector: '<S109>/Selector2' */
  rtb_Selector2_e[0] = rtb_ImpAsg_InsertedFor_Fz_at_in[2];

  /* Selector: '<S109>/Selector3' incorporates:
   *  Concatenate: '<S207>/Matrix Concatenate'
   */
  rtb_Selector3_i[0] = rtb_ImpAsg_InsertedFor_Mz_at_in[2];

  /* Selector: '<S107>/Selector14' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector14[0] = localB->Reshape5[1];

  /* Selector: '<S107>/Selector15' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector15[0] = localB->Reshape5[2];

  /* Selector: '<S109>/Selector' */
  rtb_Selector_k[1] = rtb_ImpAsg_InsertedFor_Fx_at_in[3];

  /* Selector: '<S109>/Selector1' */
  rtb_Selector1_i[1] = rtb_ImpAsg_InsertedFor_Fy_at_in[3];

  /* Selector: '<S109>/Selector2' */
  rtb_Selector2_e[1] = rtb_ImpAsg_InsertedFor_Fz_at_in[3];

  /* Selector: '<S109>/Selector3' incorporates:
   *  Concatenate: '<S207>/Matrix Concatenate'
   */
  rtb_Selector3_i[1] = rtb_ImpAsg_InsertedFor_Mz_at_in[3];

  /* Selector: '<S107>/Selector14' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector14[1] = localB->Reshape5[4];

  /* Selector: '<S107>/Selector15' incorporates:
   *  Reshape: '<S291>/Reshape5'
   */
  rtb_Selector15[1] = localB->Reshape5[5];

  /* Outputs for Iterator SubSystem: '<S109>/Kinpin axle moment and tie rod force' */
  /* Constant: '<S109>/RckGnConstant' */
  Kinpinaxlemomentandtierodforce(rtb_Selector1_i, rtb_Selector2_e,
    rtb_Selector3_i, rtb_Selector14, rtb_Selector15,
    AdasPlantModel0_P->PlntSteerRckGn, rtb_ImpAsg_InsertedFor_Fsa_y_at,
    AdasPlantModel0_P->PlntSteerHbLead, AdasPlantModel0_P->PlntSteerKngpnOfst,
    AdasPlantModel0_P->PlntSteerLambda, AdasPlantModel0_P->PlntSteerRatio,
    AdasPlantModel0_P->PlntSteerStcLdRadius);

  /* End of Outputs for SubSystem: '<S109>/Kinpin axle moment and tie rod force' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Backlash: '<S204>/Backlash' incorporates:
     *  Constant: '<S107>/Constant'
     */
    rtb_Gain1_g0 = localP->RearSteering_DbWdth / 2.0;
    if (localP->Constant_Value_ba < localDW->PrevY_f - rtb_Gain1_g0) {
      /* Backlash: '<S204>/Backlash' */
      localB->Backlash_i = localP->Constant_Value_ba + rtb_Gain1_g0;
    } else if (localP->Constant_Value_ba <= localDW->PrevY_f + rtb_Gain1_g0) {
      /* Backlash: '<S204>/Backlash' */
      localB->Backlash_i = localDW->PrevY_f;
    } else {
      /* Backlash: '<S204>/Backlash' */
      localB->Backlash_i = localP->Constant_Value_ba - rtb_Gain1_g0;
    }

    /* End of Backlash: '<S204>/Backlash' */

    /* Saturate: '<S204>/Saturation' */
    if (localB->Backlash_i > AdasPlantModel0_P->PlntSteerRange) {
      /* Saturate: '<S204>/Saturation' */
      localB->Saturation_f = AdasPlantModel0_P->PlntSteerRange;
    } else if (localB->Backlash_i < -AdasPlantModel0_P->PlntSteerRange) {
      /* Saturate: '<S204>/Saturation' */
      localB->Saturation_f = -AdasPlantModel0_P->PlntSteerRange;
    } else {
      /* Saturate: '<S204>/Saturation' */
      localB->Saturation_f = localB->Backlash_i;
    }

    /* End of Saturate: '<S204>/Saturation' */
  }

  /* Sum: '<S218>/Subtract' incorporates:
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   */
  lam_muy_prime_idx_3 = localB->Saturation_f -
    localX->IntegratorSecondOrder_CSTATE_f[0];

  /* Integrator: '<S218>/Integrator' */
  /* Limited  Integrator  */
  if (localX->Integrator_CSTATE_n >= localP->Integrator_UpperSat_i) {
    localX->Integrator_CSTATE_n = localP->Integrator_UpperSat_i;
  } else if (localX->Integrator_CSTATE_n <= localP->Integrator_LowerSat_h) {
    localX->Integrator_CSTATE_n = localP->Integrator_LowerSat_h;
  }

  /* Gain: '<S218>/Gain2' */
  localB->Gain2_b = localP->SteerTorqueControl_D_f * lam_muy_prime_idx_3;

  /* Derivative: '<S218>/Derivative' */
  if ((localDW->TimeStampA_g >= rtb_Product_py) && (localDW->TimeStampB_h >=
       rtb_Product_py)) {
    lam_muy_prime_idx_1 = 0.0;
  } else {
    rtb_Gain1_g0 = localDW->TimeStampA_g;
    lastU = &localDW->LastUAtTimeA_k;
    if (localDW->TimeStampA_g < localDW->TimeStampB_h) {
      if (localDW->TimeStampB_h < rtb_Product_py) {
        rtb_Gain1_g0 = localDW->TimeStampB_h;
        lastU = &localDW->LastUAtTimeB_g;
      }
    } else if (localDW->TimeStampA_g >= rtb_Product_py) {
      rtb_Gain1_g0 = localDW->TimeStampB_h;
      lastU = &localDW->LastUAtTimeB_g;
    }

    lam_muy_prime_idx_1 = (localB->Gain2_b - *lastU) / (rtb_Product_py -
      rtb_Gain1_g0);
  }

  /* Sum: '<S218>/Subtract1' incorporates:
   *  Gain: '<S218>/Gain'
   *  Integrator: '<S218>/Integrator'
   */
  rtb_Product_py = (localP->SteerTorqueControl_P_d * lam_muy_prime_idx_3 +
                    localX->Integrator_CSTATE_n) + lam_muy_prime_idx_1;

  /* Saturate: '<S218>/Saturation' */
  if (rtb_Product_py > localP->SteerTorqueControl_OutSatUpLm_k) {
    rtb_Product_py = localP->SteerTorqueControl_OutSatUpLm_k;
  } else if (rtb_Product_py < localP->SteerTorqueControl_OutSatLowL_g) {
    rtb_Product_py = localP->SteerTorqueControl_OutSatLowL_g;
  }

  /* End of Saturate: '<S218>/Saturation' */

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/SteerInputFlagConstant'
   */
  if (localP->SteerInputFlagConstant_Value_j > localP->Switch_Threshold_g) {
    lam_muy_prime_idx_1 = 0.0;
  } else {
    lam_muy_prime_idx_1 = rtb_Product_py;
  }

  /* End of Switch: '<S109>/Switch' */

  /* SecondOrderIntegrator: '<S225>/Integrator, Second-Order' */
  rtb_IntegratorSecondOrder_o1_i = localX->IntegratorSecondOrder_CSTATE_j[0];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S214>/Unary Minus' incorporates:
     *  Constant: '<S214>/Constant'
     */
    localB->UnaryMinus_f = -localP->Constant_Value_b4;
  }

  /* Switch: '<S214>/Switch' incorporates:
   *  Constant: '<S215>/Constant'
   *  Constant: '<S216>/Constant'
   *  Fcn: '<S214>/Fcn'
   *  Logic: '<S214>/Logical Operator'
   *  Product: '<S214>/Product'
   *  RelationalOperator: '<S215>/Compare'
   *  RelationalOperator: '<S216>/Compare'
   *  SecondOrderIntegrator: '<S225>/Integrator, Second-Order'
   *  Switch: '<S214>/Switch1'
   */
  if ((localX->IntegratorSecondOrder_CSTATE_j[1] >=
       -localP->div0protectpoly_thresh_n) &&
      (localX->IntegratorSecondOrder_CSTATE_j[1] <=
       localP->div0protectpoly_thresh_n)) {
    /* Switch: '<S214>/Switch1' incorporates:
     *  Constant: '<S214>/Constant'
     */
    if (localX->IntegratorSecondOrder_CSTATE_j[1] >= localP->Switch1_Threshold_d)
    {
      rtb_UnaryMinus2_idx_0 = localP->Constant_Value_b4;
    } else {
      rtb_UnaryMinus2_idx_0 = localB->UnaryMinus_f;
    }

    rtb_Switch_e1 = 0.02 / (3.0 - rt_powd_snf
      (localX->IntegratorSecondOrder_CSTATE_j[1] / 0.01, 2.0)) *
      rtb_UnaryMinus2_idx_0;
  } else {
    rtb_Switch_e1 = localX->IntegratorSecondOrder_CSTATE_j[1];
  }

  /* End of Switch: '<S214>/Switch' */

  /* Lookup_n-D: '<S212>/TrqAssistTbl' incorporates:
   *  Switch: '<S109>/Switch'
   */
  rtb_UnaryMinus2_idx_0 = look2_binlcpw(lam_muy_prime_idx_1,
    localB->UnitConversion[0], AdasPlantModel0_P->PlntSteerWheelTrqBpt,
    localP->RearSteering_VehSpdBpts, AdasPlantModel0_P->PlntSteerTrqAsstTbl,
    localP->TrqAssistTbl_maxIndex_c, 3U);

  /* Saturate: '<S212>/Saturation1' */
  if (rtb_UnaryMinus2_idx_0 > AdasPlantModel0_P->PlntSteerTrqLimit) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntSteerTrqLimit;
  } else if (rtb_UnaryMinus2_idx_0 < -AdasPlantModel0_P->PlntSteerTrqLimit) {
    rtb_UnaryMinus2_idx_0 = -AdasPlantModel0_P->PlntSteerTrqLimit;
  }

  /* Product: '<S212>/Product' incorporates:
   *  Saturate: '<S212>/Saturation1'
   */
  rtb_UnaryMinus2_idx_0 *= rtb_Switch_e1;

  /* Saturate: '<S212>/Saturation2' */
  if (rtb_UnaryMinus2_idx_0 > AdasPlantModel0_P->PlntSteerPwrLimit) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntSteerPwrLimit;
  } else if (rtb_UnaryMinus2_idx_0 < -AdasPlantModel0_P->PlntSteerPwrLimit) {
    rtb_UnaryMinus2_idx_0 = -AdasPlantModel0_P->PlntSteerPwrLimit;
  }

  /* Product: '<S213>/Divide' incorporates:
   *  Constant: '<S213>/Constant'
   *  Gain: '<S212>/Gain1'
   *  Integrator: '<S213>/Integrator1'
   *  Product: '<S212>/Product1'
   *  Saturate: '<S212>/Saturation2'
   *  Sum: '<S213>/Sum'
   */
  localB->Divide_h = (rtb_UnaryMinus2_idx_0 / rtb_Switch_e1 *
                      localP->RearSteering_Eta - localX->Integrator1_CSTATE_j) *
    AdasPlantModel0_P->PlntSteerWc;

  /* Sum: '<S218>/Subtract2' incorporates:
   *  Gain: '<S218>/Gain1'
   *  Gain: '<S218>/Gain3'
   */
  localB->Subtract2_p = localP->SteerTorqueControl_I_e * lam_muy_prime_idx_3 -
    localP->SteerTorqueControl_A_o * rtb_Product_py;

  /* Sum: '<S206>/Add' incorporates:
   *  Gain: '<S223>/Gain'
   *  Gain: '<S223>/Gain1'
   *  SecondOrderIntegrator: '<S225>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   *  Sum: '<S223>/Add'
   *  Sum: '<S223>/Add1'
   */
  lam_muy_prime_idx_3 = (localX->IntegratorSecondOrder_CSTATE_f[0] -
    rtb_IntegratorSecondOrder_o1_i) * AdasPlantModel0_P->PlntSteerTorStf +
    (localX->IntegratorSecondOrder_CSTATE_f[1] -
     localX->IntegratorSecondOrder_CSTATE_j[1]) *
    AdasPlantModel0_P->PlntSteerTorDamp;

  /* Sum: '<S219>/Add' incorporates:
   *  Constant: '<S206>/Constant1'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   */
  localB->Add_c0 = localX->IntegratorSecondOrder_CSTATE_f[0] -
    localP->Constant1_Value_e[0];

  /* Sum: '<S219>/Add1' incorporates:
   *  Constant: '<S206>/Constant1'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   */
  localB->Add1_c = localX->IntegratorSecondOrder_CSTATE_f[1] -
    localP->Constant1_Value_e[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S219>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_f = localDW->TmpLatchAtTriggeredSubsystemI_a;

    /* Memory generated from: '<S219>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_o = localDW->TmpLatchAtTriggeredSubsystemI_c;

    /* Outputs for Triggered SubSystem: '<S219>/Triggered Subsystem' */
    AdasPlantMod_TriggeredSubsystem(localB->Add1_c, localB->Add_c0,
      rtb_TmpLatchAtTriggeredSubsys_f, rtb_TmpLatchAtTriggeredSubsys_o,
      AdasPlantModel0_P->PlntSteerUpprFric, AdasPlantModel0_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_f, &localZCE->TriggeredSubsystem_f);

    /* End of Outputs for SubSystem: '<S219>/Triggered Subsystem' */
  }

  /* Sum: '<S219>/Add3' */
  rtb_FrontBiasGain = localB->Add_c0 - localB->TriggeredSubsystem_f.In;

  /* Sum: '<S219>/Add2' */
  rtb_Add2_e = localB->TriggeredSubsystem_f.y + rtb_FrontBiasGain;

  /* Signum: '<S219>/Sign' */
  if (std::isnan(localB->Add1_c)) {
    /* Signum: '<S219>/Sign' */
    localB->Sign_p = localB->Add1_c;
  } else if (localB->Add1_c < 0.0) {
    /* Signum: '<S219>/Sign' */
    localB->Sign_p = -1.0;
  } else {
    /* Signum: '<S219>/Sign' */
    localB->Sign_p = (localB->Add1_c > 0.0);
  }

  /* End of Signum: '<S219>/Sign' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S227>/Enable' */
    localB->HiddenBuf_InsertedFor_Enable_b1 = localB->Sign_p;
  }

  /* Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  AdasPlantModel_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enable_b1,
    rtb_Add2_e, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem_l,
    &localDW->EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S219>/Enabled Subsystem' */

  /* Sum: '<S219>/Add4' */
  rtb_Add4_l = localB->TriggeredSubsystem_f.y_a + rtb_FrontBiasGain;

  /* Gain: '<S219>/Gain' */
  localB->Gain_p = localP->Gain_Gain_j * localB->Sign_p;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S228>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_i = localB->Gain_p;
  }

  /* Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem1' */
  AdasPlantMode_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_i,
    rtb_Add4_l, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem1_c,
    &localDW->EnabledSubsystem1_c);

  /* End of Outputs for SubSystem: '<S219>/Enabled Subsystem1' */

  /* Sum: '<S220>/Add' incorporates:
   *  Constant: '<S206>/Constant2'
   */
  localB->Add_nb = rtb_IntegratorSecondOrder_o1_i - localP->Constant2_Value_e[0];

  /* Sum: '<S220>/Add1' incorporates:
   *  Constant: '<S206>/Constant2'
   *  SecondOrderIntegrator: '<S225>/Integrator, Second-Order'
   */
  localB->Add1_jo = localX->IntegratorSecondOrder_CSTATE_j[1] -
    localP->Constant2_Value_e[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S220>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_l = localDW->TmpLatchAtTriggeredSubsystemI_k;

    /* Memory generated from: '<S220>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_c = localDW->TmpLatchAtTriggeredSubsystemI_m;

    /* Outputs for Triggered SubSystem: '<S220>/Triggered Subsystem' */
    AdasPlantMod_TriggeredSubsystem(localB->Add1_jo, localB->Add_nb,
      rtb_TmpLatchAtTriggeredSubsys_l, rtb_TmpLatchAtTriggeredSubsys_c,
      AdasPlantModel0_P->PlntSteerUpprFric, AdasPlantModel0_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_e, &localZCE->TriggeredSubsystem_e);

    /* End of Outputs for SubSystem: '<S220>/Triggered Subsystem' */
  }

  /* Sum: '<S220>/Add3' */
  rtb_FrontBiasGain = localB->Add_nb - localB->TriggeredSubsystem_e.In;

  /* Sum: '<S220>/Add2' */
  rtb_Add2_p = localB->TriggeredSubsystem_e.y + rtb_FrontBiasGain;

  /* Signum: '<S220>/Sign' */
  if (std::isnan(localB->Add1_jo)) {
    /* Signum: '<S220>/Sign' */
    localB->Sign_c = localB->Add1_jo;
  } else if (localB->Add1_jo < 0.0) {
    /* Signum: '<S220>/Sign' */
    localB->Sign_c = -1.0;
  } else {
    /* Signum: '<S220>/Sign' */
    localB->Sign_c = (localB->Add1_jo > 0.0);
  }

  /* End of Signum: '<S220>/Sign' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S234>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_a = localB->Sign_c;
  }

  /* Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  AdasPlantModel_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enabled_a,
    rtb_Add2_p, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem_o,
    &localDW->EnabledSubsystem_o);

  /* End of Outputs for SubSystem: '<S220>/Enabled Subsystem' */

  /* Sum: '<S220>/Add4' */
  rtb_Add4_f = localB->TriggeredSubsystem_e.y_a + rtb_FrontBiasGain;

  /* Gain: '<S220>/Gain' */
  localB->Gain_g = localP->Gain_Gain_c * localB->Sign_c;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S235>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_d = localB->Gain_g;
  }

  /* Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem1' */
  AdasPlantMode_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_d,
    rtb_Add4_f, AdasPlantModel0_P->PlntSteerUpprFric,
    AdasPlantModel0_P->PlntSteerSlgStf, &localB->EnabledSubsystem1_l,
    &localDW->EnabledSubsystem1_l);

  /* End of Outputs for SubSystem: '<S220>/Enabled Subsystem1' */

  /* Sum: '<S206>/Add3' incorporates:
   *  Gain: '<S224>/Gain'
   *  Gain: '<S224>/Gain1'
   *  SecondOrderIntegrator: '<S225>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S244>/Integrator, Second-Order'
   *  Sum: '<S224>/Add'
   *  Sum: '<S224>/Add1'
   */
  rtb_Divide_pl = (rtb_IntegratorSecondOrder_o1_i -
                   localX->IntegratorSecondOrder_CSTATE_b[0]) *
    AdasPlantModel0_P->PlntSteerTorStf + (localX->
    IntegratorSecondOrder_CSTATE_j[1] - localX->IntegratorSecondOrder_CSTATE_b[1])
    * AdasPlantModel0_P->PlntSteerTorDamp;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S219>/Memory' */
    localB->Memory_e0 = localDW->Memory_PreviousInput_m;

    /* Memory: '<S219>/Memory1' */
    localB->Memory1_c = localDW->Memory1_PreviousInput_d;

    /* Memory: '<S220>/Memory' */
    localB->Memory_h = localDW->Memory_PreviousInput_mf;

    /* Memory: '<S220>/Memory1' */
    localB->Memory1_h = localDW->Memory1_PreviousInput_k;
  }

  /* MATLAB Function: '<S241>/MATLAB Function1' */
  AdasPlantModel0_MATLABFunction1(rtb_IntegratorSecondOrder_o1_i,
    localP->RearSteering_SptlAng, &localB->sf_MATLABFunction1_n);

  /* Gain: '<S244>/Gain3' incorporates:
   *  Gain: '<S244>/Gain'
   *  Product: '<S241>/Divide'
   *  Product: '<S244>/Divide1'
   *  Product: '<S244>/Product4'
   *  Sum: '<S109>/Add'
   *  Sum: '<S244>/Add'
   */
  localB->Gain3_o = (rtb_Divide_pl / localB->sf_MATLABFunction1_n.y *
                     AdasPlantModel0_P->PlntSteerEpsilon / localB->Divide_n +
                     (rtb_ImpAsg_InsertedFor_Fsa_y_at[0] +
                      rtb_ImpAsg_InsertedFor_Fsa_y_at[1])) * localB->Divide_n *
    (1.0 / AdasPlantModel0_P->PlntSteerPnInert);

  /* Gain: '<S225>/Gain' incorporates:
   *  Integrator: '<S213>/Integrator1'
   *  Sum: '<S206>/Add2'
   *  Sum: '<S220>/Add5'
   */
  localB->Gain_o = (((lam_muy_prime_idx_3 + localX->Integrator1_CSTATE_j) -
                     (localB->EnabledSubsystem_o.y +
                      localB->EnabledSubsystem1_l.y)) - rtb_Divide_pl) * (1.0 /
    AdasPlantModel0_P->PlntSteerLowerInertia);

  /* Gain: '<S226>/Gain' incorporates:
   *  Sum: '<S206>/Add1'
   *  Sum: '<S219>/Add5'
   */
  localB->Gain_o5 = ((lam_muy_prime_idx_1 - (localB->EnabledSubsystem_l.y +
    localB->EnabledSubsystem1_c.y)) - lam_muy_prime_idx_3) * (1.0 /
    AdasPlantModel0_P->PlntSteerUpperInertia);
  for (i = 0; i < 4; i++) {
    /* Selector: '<S291>/dWhlY select' incorporates:
     *  Selector: '<S291>/Height select'
     */
    iy = i << 3;

    /* Product: '<S289>/Divide' incorporates:
     *  Constant: '<S289>/Constant'
     *  ForEachSliceAssignment generated from: '<S299>/Info'
     *  Integrator: '<S289>/Integrator1'
     *  Selector: '<S291>/dWhlY select'
     *  Sum: '<S289>/Sum'
     */
    localB->Divide_c[i] = (rtb_ImpAsg_InsertedFor_Info_at_[iy + 7] -
      localX->Integrator1_CSTATE_no[i]) * localP->ContLPF_wc;

    /* Product: '<S290>/Divide' incorporates:
     *  Constant: '<S290>/Constant'
     *  ForEachSliceAssignment generated from: '<S299>/Info'
     *  Integrator: '<S290>/Integrator1'
     *  Selector: '<S291>/Height select'
     *  Sum: '<S290>/Sum'
     */
    localB->Divide_p[i] = (rtb_ImpAsg_InsertedFor_Info_at_[iy + 3] -
      localX->Integrator1_CSTATE_b[i]) * localP->ContLPF2_wc;

    /* Concatenate: '<S291>/Matrix Concatenate4' incorporates:
     *  ForEachSliceAssignment generated from: '<S383>/Fx'
     *  ForEachSliceAssignment generated from: '<S383>/Fy'
     */
    rtb_Product_py = rtb_ImpAsg_InsertedFor_Fx_at_in[i];
    rtb_UnaryMinus2_idx_0 = rtb_ImpAsg_InsertedFor_Fy_at_in[i];

    /* Concatenate: '<S291>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S291>/Matrix Concatenate1'
     */
    iy = 3 * i + 2;

    /* Concatenate: '<S291>/Matrix Concatenate' incorporates:
     *  ForEachSliceAssignment generated from: '<S299>/VehFz'
     */
    localB->MatrixConcatenate_f[iy] = rtb_ImpAsg_InsertedFor_VehFz_at[i];
    localB->MatrixConcatenate_f[3 * i] = rtb_Product_py;

    /* Concatenate: '<S291>/Matrix Concatenate1' */
    localB->MatrixConcatenate1_p[3 * i] = rtb_Product_py;

    /* Concatenate: '<S291>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S291>/Matrix Concatenate1'
     */
    ibmat = 3 * i + 1;

    /* Concatenate: '<S291>/Matrix Concatenate' */
    localB->MatrixConcatenate_f[ibmat] = rtb_UnaryMinus2_idx_0;

    /* Concatenate: '<S291>/Matrix Concatenate1' incorporates:
     *  ForEachSliceAssignment generated from: '<S299>/WhlFz'
     */
    localB->MatrixConcatenate1_p[ibmat] = rtb_UnaryMinus2_idx_0;
    localB->MatrixConcatenate1_p[iy] = rtb_ImpAsg_InsertedFor_WhlFz_at[i];
  }

  /* Product: '<S373>/Divide' incorporates:
   *  Concatenate: '<S291>/Matrix Concatenate1'
   *  Constant: '<S373>/Constant'
   *  Selector: '<S286>/Selector'
   *  Sum: '<S373>/Sum'
   */
  localB->Divide_f[0] = (localB->MatrixConcatenate1_p[2] -
    rtb_UnitConversion_mr_idx_0) * localP->ContLPF_wc_f;
  localB->Divide_f[1] = (localB->MatrixConcatenate1_p[5] -
    rtb_UnitConversion_mr_idx_1) * localP->ContLPF_wc_f;
  localB->Divide_f[2] = (localB->MatrixConcatenate1_p[8] -
    rtb_UnitConversion_mr_idx_2) * localP->ContLPF_wc_f;
  localB->Divide_f[3] = (localB->MatrixConcatenate1_p[11] -
    rtb_UnitConversion_mr_idx_3) * localP->ContLPF_wc_f;
  for (i = 0; i < 12; i++) {
    /* Reshape: '<S291>/Reshape14' incorporates:
     *  ForEachSliceAssignment generated from: '<S299>/VehM'
     */
    localB->Reshape14[i] = rtb_ImpAsg_InsertedFor_VehM_at_[i];

    /* Product: '<S374>/Divide' incorporates:
     *  Constant: '<S374>/Constant'
     *  Integrator: '<S374>/Integrator1'
     *  Reshape: '<S291>/Reshape5'
     *  Sum: '<S374>/Sum'
     */
    localB->Divide_pz[i] = (localB->Reshape5[i] - localX->Integrator1_CSTATE_n[i])
      * localP->ContLPF1_wc;
  }

  /* Reshape: '<S375>/Reshape5' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/zdotWheel'
   */
  localB->Reshape5_d[0] = rtb_ImpAsg_InsertedFor_zdotWhee[0];

  /* Sum: '<S382>/Subtract' incorporates:
   *  SignalConversion generated from: '<S382>/Vector Concatenate3'
   *  SignalConversion generated from: '<S382>/Vector Concatenate4'
   */
  localB->dz[0] = (localB->Add[2] - localB->z[0]) - localB->Selector1[2];

  /* Reshape: '<S375>/Reshape5' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/zdotWheel'
   */
  localB->Reshape5_d[1] = rtb_ImpAsg_InsertedFor_zdotWhee[1];

  /* Sum: '<S382>/Subtract' incorporates:
   *  SignalConversion generated from: '<S382>/Vector Concatenate3'
   *  SignalConversion generated from: '<S382>/Vector Concatenate4'
   */
  localB->dz[1] = (localB->Add_n[2] - localB->z[1]) - localB->Selector1_h[2];

  /* Reshape: '<S375>/Reshape5' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/zdotWheel'
   */
  localB->Reshape5_d[2] = rtb_ImpAsg_InsertedFor_zdotWhee[2];

  /* Sum: '<S382>/Subtract' incorporates:
   *  SignalConversion generated from: '<S382>/Vector Concatenate3'
   *  SignalConversion generated from: '<S382>/Vector Concatenate4'
   */
  localB->dz[2] = (localB->Add_b[2] - localB->z[2]) - localB->Selector1_p[2];

  /* Reshape: '<S375>/Reshape5' incorporates:
   *  ForEachSliceAssignment generated from: '<S377>/zdotWheel'
   */
  localB->Reshape5_d[3] = rtb_ImpAsg_InsertedFor_zdotWhee[3];

  /* Sum: '<S382>/Subtract' incorporates:
   *  SignalConversion generated from: '<S382>/Vector Concatenate3'
   *  SignalConversion generated from: '<S382>/Vector Concatenate4'
   */
  localB->dz[3] = (localB->Add_a[2] - localB->z[3]) - localB->Selector1_f[2];

  /* Gain: '<S390>/Unsprung Masses sum([VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassRearAxle//2 VEH.UnsprungMassRearAxle//2])' incorporates:
   *  Concatenate: '<S390>/Vector Concatenate'
   *  Integrator: '<S392>/Integrator1'
   */
  localB->VectorConcatenate_b[0] = localP->UnsprungMassessumVEHUnsprungMas *
    localX->Integrator1_CSTATE_m[0];
  localB->VectorConcatenate_b[1] = localP->UnsprungMassessumVEHUnsprungMas *
    localX->Integrator1_CSTATE_m[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S389>/Constant1' */
    localB->Constant1[0] = localP->Constant1_Value_kj[0];
    localB->Constant1[1] = localP->Constant1_Value_kj[1];
    localB->Constant1[2] = localP->Constant1_Value_kj[2];

    /* Constant: '<S390>/Vertical' incorporates:
     *  Concatenate: '<S390>/Vector Concatenate'
     */
    localB->VectorConcatenate_b[2] = localP->Vertical_Value;

    /* Product: '<S408>/Product' incorporates:
     *  Constant: '<S408>/0'
     */
    rtb_UnitConversion_mr_idx_0 = localP->u_Value_n * localB->Mbar;

    /* Product: '<S408>/Product' incorporates:
     *  Constant: '<S408>/g'
     */
    localB->Fg_I[0] = rtb_UnitConversion_mr_idx_0;
    localB->Fg_I[1] = rtb_UnitConversion_mr_idx_0;
    localB->Fg_I[2] = AdasPlantModel0_P->EnvGrvty * localB->Mbar;
  }

  /* UnaryMinus: '<S390>/Unary Minus' */
  localB->UnaryMinus_j[0] = -localB->VectorConcatenate_b[0];
  localB->UnaryMinus_j[1] = -localB->VectorConcatenate_b[1];
  localB->UnaryMinus_j[2] = -localB->VectorConcatenate_b[2];

  /* Product: '<S408>/Inertial to Body' */
  rtb_UnitConversion_mr_idx_0 = localB->Fg_I[0];
  rtb_UnitConversion_mr_idx_1 = localB->Fg_I[1];
  rtb_UnitConversion_mr_idx_2 = localB->Fg_I[2];

  /* Product: '<S432>/Inertial to Body' */
  rtb_UnitConversion_mr_idx_3 = localB->Wind[0];
  rtb_Divide_pl = localB->Wind[1];
  rtb_Gain1_g0 = localB->Wind[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S408>/Inertial to Body' incorporates:
     *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
     */
    lam_muy_prime_idx_3 = localB->Reshape9to3x3columnmajor[i];

    /* Product: '<S408>/Inertial to Body' */
    rtb_FrontBiasGain = lam_muy_prime_idx_3 * rtb_UnitConversion_mr_idx_0;

    /* Sum: '<S433>/Add1' incorporates:
     *  Product: '<S432>/Inertial to Body'
     */
    rtb_UnaryMinus2_idx_0 = lam_muy_prime_idx_3 * rtb_UnitConversion_mr_idx_3;

    /* Product: '<S408>/Inertial to Body' incorporates:
     *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
     */
    lam_muy_prime_idx_3 = localB->Reshape9to3x3columnmajor[i + 3];

    /* Product: '<S408>/Inertial to Body' */
    rtb_FrontBiasGain += lam_muy_prime_idx_3 * rtb_UnitConversion_mr_idx_1;

    /* Sum: '<S433>/Add1' incorporates:
     *  Product: '<S432>/Inertial to Body'
     */
    rtb_UnaryMinus2_idx_0 += lam_muy_prime_idx_3 * rtb_Divide_pl;

    /* Product: '<S408>/Inertial to Body' incorporates:
     *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
     */
    lam_muy_prime_idx_3 = localB->Reshape9to3x3columnmajor[i + 6];

    /* Product: '<S408>/Inertial to Body' */
    localB->Fg_B[i] = lam_muy_prime_idx_3 * rtb_UnitConversion_mr_idx_2 +
      rtb_FrontBiasGain;

    /* Sum: '<S433>/Add1' incorporates:
     *  Product: '<S432>/Inertial to Body'
     */
    rtb_UnaryMinus2_idx_0 = localB->UnitConversion[i] - (lam_muy_prime_idx_3 *
      rtb_Gain1_g0 + rtb_UnaryMinus2_idx_0);
    rtb_IntegratorSecondOrderLimite[i] = rtb_UnaryMinus2_idx_0;

    /* Trigonometry: '<S433>/Tanh' incorporates:
     *  Gain: '<S433>/4'
     */
    rtb_Switch1_h[i] = std::tanh(localP->u_Gain[i] * rtb_UnaryMinus2_idx_0);

    /* Product: '<S433>/Product' */
    rtb_Product3_ju[i] = rtb_UnaryMinus2_idx_0 * rtb_UnaryMinus2_idx_0;
  }

  /* Sqrt: '<S433>/Sqrt' incorporates:
   *  Sum: '<S433>/Sum of Elements'
   */
  rtb_Divide_pl = std::sqrt((rtb_Product3_ju[0] + rtb_Product3_ju[1]) +
    rtb_Product3_ju[2]);

  /* Product: '<S433>/Product2' */
  rtb_UnitConversion_mr_idx_0 = rtb_Divide_pl * rtb_Divide_pl;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S433>/Constant' incorporates:
     *  Concatenate: '<S433>/Vector Concatenate'
     */
    localB->VectorConcatenate_bb[0] = AdasPlantModel0_P->PlntVehAeroDragCff;
  }

  /* Trigonometry: '<S433>/Trigonometric Function' */
  rtb_Divide_pl = rt_atan2d_snf(rtb_IntegratorSecondOrderLimite[1],
    rtb_IntegratorSecondOrderLimite[0]);

  /* Lookup_n-D: '<S433>/Cs' incorporates:
   *  Concatenate: '<S433>/Vector Concatenate'
   *  Gain: '<S643>/Gain1'
   */
  localB->VectorConcatenate_bb[1] = look1_binlcpw(rtb_Divide_pl,
    localP->VehicleBody6DOF_beta_w, localP->VehicleBody6DOF_Cs, 30U);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S433>/Constant1' incorporates:
     *  Concatenate: '<S433>/Vector Concatenate'
     */
    localB->VectorConcatenate_bb[2] = AdasPlantModel0_P->PlntVehAeroLiftCff;
  }

  /* Lookup_n-D: '<S433>/Crm' incorporates:
   *  Concatenate: '<S433>/Vector Concatenate'
   *  Gain: '<S643>/Gain1'
   */
  localB->VectorConcatenate_bb[3] = look1_binlxpw(rtb_Divide_pl,
    localP->Crm_bp01Data, localP->Crm_tableData, 1U);

  /* Product: '<S433>/Product5' incorporates:
   *  Concatenate: '<S433>/Vector Concatenate'
   *  Constant: '<S433>/Constant2'
   */
  localB->VectorConcatenate_bb[4] = rtb_Switch1_h[0] *
    AdasPlantModel0_P->PlntVehAeroPitchCff;

  /* Lookup_n-D: '<S433>/Cym' incorporates:
   *  Concatenate: '<S433>/Vector Concatenate'
   *  Gain: '<S643>/Gain1'
   */
  localB->VectorConcatenate_bb[5] = look1_binlxpw(rtb_Divide_pl,
    localP->VehicleBody6DOF_beta_w, localP->VehicleBody6DOF_Cym, 30U);

  /* Gain: '<S433>/.5.*A.*Pabs.//R.//T' incorporates:
   *  Constant: '<S391>/AirTempConstant'
   *  Product: '<S433>/Product1'
   */
  rtb_Product_py = 0.5 * AdasPlantModel0_P->PlntVehAeroFrntArea *
    AdasPlantModel0_P->EnvAbsPrs / localP->DragForce_R;
  for (i = 0; i < 6; i++) {
    rtb_Abs_k[i] = rtb_UnitConversion_mr_idx_0 * localB->VectorConcatenate_bb[i]
      / AdasPlantModel0_P->EnvAirTemp * rtb_Product_py;
  }

  /* End of Gain: '<S433>/.5.*A.*Pabs.//R.//T' */

  /* Product: '<S433>/Product3' incorporates:
   *  Constant: '<S433>/Constant4'
   *  Sum: '<S433>/Add2'
   */
  rtb_Product3_ju[0] = (rtb_Switch1_h[0] - localP->Constant4_Value[0]) *
    rtb_Abs_k[0];
  rtb_Product3_ju[1] = (rtb_Switch1_h[1] - localP->Constant4_Value[1]) *
    rtb_Abs_k[1];
  rtb_Product3_ju[2] = (rtb_Switch1_h[2] - localP->Constant4_Value[2]) *
    rtb_Abs_k[2];

  /* Fcn: '<S474>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = dpi_idx_0;

  /* Fcn: '<S474>/Fcn21' */
  rtb_VectorConcatenate_ci[1] = dpi_idx_3;

  /* Fcn: '<S474>/Fcn31' */
  rtb_VectorConcatenate_ci[2] = Fzo_prime_idx_1;

  /* Fcn: '<S474>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = Fzo_prime_idx_2;

  /* Fcn: '<S474>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = dpi_idx_1;

  /* Fcn: '<S474>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = Fzo_prime_idx_0;

  /* Fcn: '<S474>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -dpi_idx_2;

  /* Fcn: '<S474>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = Fzo_prime_idx_3;

  /* Fcn: '<S474>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Saturation_0;

  /* Math: '<S472>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   *  Math: '<S484>/Transpose1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose1[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose1[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S472>/Transpose1' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S452>/Subtract' incorporates:
     *  Constant: '<S452>/latOff'
     *  Constant: '<S452>/longOff'
     *  Constant: '<S452>/vertOff '
     */
    localB->Subtract[0] = localP->VehicleBody6DOF_longOff + localB->Rbar[0];
    localB->Subtract[1] = localP->VehicleBody6DOF_latOff + localB->Rbar[1];
    localB->Subtract[2] = localP->VehicleBody6DOF_vertOff + localB->Rbar[2];
  }

  /* Product: '<S476>/Product' incorporates:
   *  Sum: '<S452>/Subtract'
   */
  rtb_UnitConversion_mr_idx_0 = localB->Subtract[1];
  rtb_UnitConversion_mr_idx_1 = localB->Subtract[0];
  rtb_UnitConversion_mr_idx_2 = localB->Subtract[2];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S472>/Add' incorporates:
     *  Math: '<S484>/Transpose1'
     */
    localB->Add_o[i] = ((rtb_Transpose1[i + 3] * rtb_UnitConversion_mr_idx_0 +
                         rtb_Transpose1[i] * rtb_UnitConversion_mr_idx_1) +
                        rtb_Transpose1[i + 6] * rtb_UnitConversion_mr_idx_2) +
      localB->xeyeze[i];
  }

  /* End of Product: '<S476>/Product' */

  /* MATLAB Function: '<S390>/Estimated Unsprung Mass Orientation' incorporates:
   *  Constant: '<S433>/Constant3'
   *  Product: '<S433>/Product4'
   */
  rtb_Divide_pl = std::atan(((localB->z[0] - localB->z[1]) + (localB->z[2] -
    localB->z[3])) / AdasPlantModel0_P->PlntVehTrckWdth[0] / 2.0);
  rtb_UnitConversion_mr_idx_0 = AdasPlantModel0_P->PlntVehDstCGFrntAxl +
    AdasPlantModel0_P->PlntVehDstCGRearAxl;
  rtb_Gain1_g0 = std::atan(((localB->z[0] - localB->z[2]) + (localB->z[1] -
    localB->z[3])) / rtb_UnitConversion_mr_idx_0 / 2.0);

  /* Outputs for Iterator SubSystem: '<S390>/Susp2Body' incorporates:
   *  ForEach: '<S394>/For Each'
   */
  for (ForEach_itr_g = 0; ForEach_itr_g < 4; ForEach_itr_g++) {
    /* SignalConversion generated from: '<S394>/Vector Concatenate' */
    rtb_UnitConversion_mr_idx_1 = rty_VehFdbk[2];

    /* Trigonometry: '<S395>/sincos' incorporates:
     *  SignalConversion generated from: '<S395>/sincos'
     *  UnaryMinus: '<S394>/Unary Minus'
     */
    rtb_Switch1_h[0] = std::cos(rtb_UnitConversion_mr_idx_1);
    rtb_UnaryMinus2_idx_0 = std::sin(rtb_UnitConversion_mr_idx_1);
    rtb_Switch1_h[1] = std::cos(-rtb_Gain1_g0);
    lam_muy_prime_idx_3 = std::sin(-rtb_Gain1_g0);
    rtb_Switch1_h[2] = std::cos(-rtb_Divide_pl);
    rtb_FrontBiasGain = std::sin(-rtb_Divide_pl);

    /* Fcn: '<S395>/Fcn11' */
    rtb_VectorConcatenate_ci[0] = rtb_Switch1_h[0] * rtb_Switch1_h[1];

    /* Fcn: '<S395>/Fcn21' incorporates:
     *  Fcn: '<S395>/Fcn22'
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_Product_py = lam_muy_prime_idx_3 * rtb_FrontBiasGain;
    rtb_VectorConcatenate_ci[1] = rtb_Product_py * rtb_Switch1_h[0] -
      rtb_UnaryMinus2_idx_0 * rtb_Switch1_h[2];

    /* Fcn: '<S395>/Fcn31' incorporates:
     *  Fcn: '<S395>/Fcn32'
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_Smallangleapproximationford = lam_muy_prime_idx_3 * rtb_Switch1_h[2];
    rtb_VectorConcatenate_ci[2] = rtb_Smallangleapproximationford *
      rtb_Switch1_h[0] + rtb_UnaryMinus2_idx_0 * rtb_FrontBiasGain;

    /* Fcn: '<S395>/Fcn12' incorporates:
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_VectorConcatenate_ci[3] = rtb_UnaryMinus2_idx_0 * rtb_Switch1_h[1];

    /* Fcn: '<S395>/Fcn22' incorporates:
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_VectorConcatenate_ci[4] = rtb_Product_py * rtb_UnaryMinus2_idx_0 +
      rtb_Switch1_h[0] * rtb_Switch1_h[2];

    /* Fcn: '<S395>/Fcn32' incorporates:
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_VectorConcatenate_ci[5] = rtb_Smallangleapproximationford *
      rtb_UnaryMinus2_idx_0 - rtb_Switch1_h[0] * rtb_FrontBiasGain;

    /* Fcn: '<S395>/Fcn13' incorporates:
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_VectorConcatenate_ci[6] = -lam_muy_prime_idx_3;

    /* Fcn: '<S395>/Fcn23' incorporates:
     *  Trigonometry: '<S395>/sincos'
     */
    rtb_VectorConcatenate_ci[7] = rtb_Switch1_h[1] * rtb_FrontBiasGain;

    /* Fcn: '<S395>/Fcn33' */
    rtb_VectorConcatenate_ci[8] = rtb_Switch1_h[1] * rtb_Switch1_h[2];

    /* Math: '<S394>/Transpose' incorporates:
     *  Concatenate: '<S489>/Vector Concatenate'
     */
    for (i = 0; i < 3; i++) {
      rtb_Transpose[3 * i] = rtb_VectorConcatenate_ci[i];
      rtb_Transpose[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
      rtb_Transpose[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
    }

    /* End of Math: '<S394>/Transpose' */

    /* Product: '<S397>/Product' */
    for (i = 0; i < 3; i++) {
      /* SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' incorporates:
       *  ForEachSliceSelector generated from: '<S394>/Ms'
       *  Math: '<S394>/Transpose'
       */
      rtb_IntegratorSecondOrderLimite[i] = (localB->Reshape14[3 * ForEach_itr_g
        + 1] * rtb_Transpose[i + 3] + localB->Reshape14[3 * ForEach_itr_g] *
        rtb_Transpose[i]) + localB->Reshape14[3 * ForEach_itr_g + 2] *
        rtb_Transpose[i + 6];
    }

    /* End of Product: '<S397>/Product' */

    /* Product: '<S394>/Inertial to Body1' */
    rtb_UnaryMinus2_idx_0 = rtb_IntegratorSecondOrderLimite[0];
    lam_muy_prime_idx_3 = rtb_IntegratorSecondOrderLimite[1];
    rtb_FrontBiasGain = rtb_IntegratorSecondOrderLimite[2];
    for (i = 0; i < 3; i++) {
      /* ForEachSliceAssignment generated from: '<S394>/MsB' incorporates:
       *  Product: '<S394>/Inertial to Body1'
       *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
       */
      iy = 3 * ForEach_itr_g + i;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] = 0.0;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i]
        * rtb_UnaryMinus2_idx_0;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i
        + 3] * lam_muy_prime_idx_3;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i
        + 6] * rtb_FrontBiasGain;

      /* Product: '<S396>/Product' incorporates:
       *  ForEachSliceSelector generated from: '<S394>/Fs'
       *  Math: '<S394>/Transpose'
       */
      rtb_Product4_i[i] = (localB->MatrixConcatenate_f[3 * ForEach_itr_g + 1] *
                           rtb_Transpose[i + 3] + localB->MatrixConcatenate_f[3 *
                           ForEach_itr_g] * rtb_Transpose[i]) +
        localB->MatrixConcatenate_f[3 * ForEach_itr_g + 2] * rtb_Transpose[i + 6];
    }

    /* Product: '<S396>/Product' incorporates:
     *  Product: '<S394>/Inertial to Body'
     */
    rtb_UnaryMinus2_idx_0 = rtb_Product4_i[0];
    rtb_UnitConversion_mr_idx_1 = rtb_Product4_i[1];
    rtb_UnitConversion_mr_idx_2 = rtb_Product4_i[2];

    /* ForEachSliceAssignment generated from: '<S394>/FsB' incorporates:
     *  Product: '<S394>/Inertial to Body'
     *  Product: '<S396>/Product'
     *  Reshape: '<S422>/Reshape (9) to [3x3] column-major'
     */
    for (i = 0; i < 3; i++) {
      iy = 3 * ForEach_itr_g + i;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] = 0.0;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i]
        * rtb_UnaryMinus2_idx_0;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i
        + 3] * rtb_UnitConversion_mr_idx_1;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += localB->Reshape9to3x3columnmajor[i
        + 6] * rtb_UnitConversion_mr_idx_2;
    }

    /* End of ForEachSliceAssignment generated from: '<S394>/FsB' */
  }

  /* End of Outputs for SubSystem: '<S390>/Susp2Body' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 6; i++) {
      /* Constant: '<S696>/Constant' */
      localB->Hitch[i] = localP->Constant_Value_e3[i];
    }
  }

  /* Sum: '<S399>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Selector: '<S404>/Selector1'
   *  Sum: '<S404>/Sum of Elements'
   */
  localB->Sum[0] = ((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] +
                       rtb_ImpAsg_InsertedFor_FsB_at_i[3]) +
                      rtb_ImpAsg_InsertedFor_FsB_at_i[6]) +
                     rtb_ImpAsg_InsertedFor_FsB_at_i[9]) +
                    ((localB->UnaryMinus_j[0] + localB->Fg_B[0]) -
                     rtb_Product3_ju[0])) + localB->Hitch[0];

  /* Sum: '<S404>/Sum of Elements1' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Selector: '<S404>/Selector2'
   *  Sum: '<S401>/Sum of Elements10'
   */
  rtb_UnitConversion_mr_idx_1 = rtb_ImpAsg_InsertedFor_FsB_at_i[1] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[4];

  /* Sum: '<S399>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Selector: '<S404>/Selector2'
   *  Sum: '<S404>/Sum of Elements1'
   */
  localB->Sum[1] = (((rtb_UnitConversion_mr_idx_1 +
                      rtb_ImpAsg_InsertedFor_FsB_at_i[7]) +
                     rtb_ImpAsg_InsertedFor_FsB_at_i[10]) +
                    ((localB->UnaryMinus_j[1] + localB->Fg_B[1]) -
                     rtb_Product3_ju[1])) + localB->Hitch[1];

  /* Sum: '<S404>/Sum of Elements2' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Selector: '<S404>/Selector3'
   *  Sum: '<S401>/Sum of Elements2'
   */
  rtb_UnitConversion_mr_idx_2 = rtb_ImpAsg_InsertedFor_FsB_at_i[2] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[5];

  /* Sum: '<S399>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Selector: '<S404>/Selector3'
   *  Sum: '<S404>/Sum of Elements2'
   */
  localB->Sum[2] = (((rtb_UnitConversion_mr_idx_2 +
                      rtb_ImpAsg_InsertedFor_FsB_at_i[8]) +
                     rtb_ImpAsg_InsertedFor_FsB_at_i[11]) +
                    ((localB->UnaryMinus_j[2] + localB->Fg_B[2]) -
                     rtb_Product3_ju[2])) + localB->Hitch[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S428>/Sum of Elements' */
    localB->SumofElements[0] = 0.0;
    localB->SumofElements[1] = 0.0;
    localB->SumofElements[2] = 0.0;
  }

  /* Sum: '<S406>/Sum' incorporates:
   *  Product: '<S406>/Product'
   *  Product: '<S430>/j x k'
   *  Product: '<S431>/k x j'
   *  Sum: '<S414>/Sum'
   *  Sum: '<S415>/Sum'
   */
  /* Unit Conversion - from: m/s^2 to: m/s^2
     Expression: output = (1*input) + (0) */
  rtb_UnitConversion_mr_idx_3 = (localB->Sum[0] + localB->SumofElements[0]) /
    localB->Mbar + (rtb_ubvbwb[1] * localB->pqr[2] - localB->pqr[1] *
                    rtb_ubvbwb[2]);
  localB->Sum_l[0] = rtb_UnitConversion_mr_idx_3;

  /* UnitConversion: '<S410>/Unit Conversion1' */
  localB->UnitConversion1[0] = rtb_UnitConversion_mr_idx_3;

  /* Sum: '<S406>/Sum' incorporates:
   *  Product: '<S406>/Product'
   *  Product: '<S430>/k x i'
   *  Product: '<S431>/i x k'
   *  Sum: '<S414>/Sum'
   *  Sum: '<S415>/Sum'
   */
  rtb_UnitConversion_mr_idx_3 = (localB->Sum[1] + localB->SumofElements[1]) /
    localB->Mbar + (localB->pqr[0] * rtb_ubvbwb[2] - rtb_ubvbwb[0] * localB->
                    pqr[2]);
  localB->Sum_l[1] = rtb_UnitConversion_mr_idx_3;

  /* UnitConversion: '<S410>/Unit Conversion1' */
  localB->UnitConversion1[1] = rtb_UnitConversion_mr_idx_3;

  /* Sum: '<S406>/Sum' incorporates:
   *  Product: '<S406>/Product'
   *  Product: '<S430>/i x j'
   *  Product: '<S431>/j x i'
   *  Sum: '<S414>/Sum'
   *  Sum: '<S415>/Sum'
   */
  rtb_UnitConversion_mr_idx_3 = (localB->Sum[2] + localB->SumofElements[2]) /
    localB->Mbar + (rtb_ubvbwb[0] * localB->pqr[1] - localB->pqr[0] *
                    rtb_ubvbwb[1]);
  localB->Sum_l[2] = rtb_UnitConversion_mr_idx_3;

  /* UnitConversion: '<S410>/Unit Conversion1' */
  localB->UnitConversion1[2] = rtb_UnitConversion_mr_idx_3;

  /* Product: '<S392>/Divide' incorporates:
   *  Constant: '<S392>/Constant'
   *  Integrator: '<S392>/Integrator1'
   *  Product: '<S390>/Product'
   *  Product: '<S390>/Product1'
   *  Sum: '<S390>/Add'
   *  Sum: '<S390>/Add1'
   *  Sum: '<S392>/Sum'
   */
  localB->Divide_e[0] = ((localB->UnitConversion1[0] - localB->UnitConversion[1]
    * localB->pqr[2]) - localX->Integrator1_CSTATE_m[0]) * localP->Bushings_wc[0];
  localB->Divide_e[1] = ((localB->UnitConversion[0] * localB->pqr[2] +
    localB->UnitConversion1[1]) - localX->Integrator1_CSTATE_m[1]) *
    localP->Bushings_wc[1];

  /* Trigonometry: '<S421>/sincos' */
  rtb_IntegratorSecondOrderLimite[0] = std::sin(localB->phithetapsi[0]);
  rtb_Switch1_h[0] = std::cos(localB->phithetapsi[0]);
  rtb_Switch1_h[1] = std::cos(localB->phithetapsi[1]);

  /* Fcn: '<S421>/phidot' incorporates:
   *  Fcn: '<S421>/psidot'
   */
  rtb_UnitConversion_mr_idx_3 = rtb_IntegratorSecondOrderLimite[0] * localB->
    pqr[1] + rtb_Switch1_h[0] * localB->pqr[2];

  /* SignalConversion generated from: '<S412>/phi theta psi' incorporates:
   *  Fcn: '<S421>/phidot'
   *  Fcn: '<S421>/psidot'
   *  Fcn: '<S421>/thetadot'
   *  Trigonometry: '<S421>/sincos'
   */
  localB->TmpSignalConversionAtphithetaps[0] = std::sin(localB->phithetapsi[1]) /
    rtb_Switch1_h[1] * rtb_UnitConversion_mr_idx_3 + localB->pqr[0];
  localB->TmpSignalConversionAtphithetaps[1] = rtb_Switch1_h[0] * localB->pqr[1]
    - rtb_IntegratorSecondOrderLimite[0] * localB->pqr[2];
  localB->TmpSignalConversionAtphithetaps[2] = rtb_UnitConversion_mr_idx_3 /
    rtb_Switch1_h[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S414>/Matrix Concatenation' incorporates:
       *  Constant: '<S399>/Constant1'
       */
      rtb_UnitConversion_mr_idx_3 = rtb_Ibar[3 * i];
      rtb_MatrixConcatenation[6 * i] = rtb_UnitConversion_mr_idx_3;
      rtb_MatrixConcatenation[6 * i + 3] = localP->Constant1_Value_m[3 * i];

      /* Selector: '<S413>/Selector' */
      localB->Selector[3 * i] = rtb_UnitConversion_mr_idx_3;

      /* Concatenate: '<S414>/Matrix Concatenation' incorporates:
       *  Constant: '<S399>/Constant1'
       *  Selector: '<S413>/Selector'
       */
      iy = 3 * i + 1;
      rtb_UnitConversion_mr_idx_3 = rtb_Ibar[iy];
      rtb_MatrixConcatenation[6 * i + 1] = rtb_UnitConversion_mr_idx_3;
      rtb_MatrixConcatenation[6 * i + 4] = localP->Constant1_Value_m[iy];

      /* Selector: '<S413>/Selector' */
      localB->Selector[iy] = rtb_UnitConversion_mr_idx_3;

      /* Concatenate: '<S414>/Matrix Concatenation' incorporates:
       *  Constant: '<S399>/Constant1'
       *  Selector: '<S413>/Selector'
       */
      iy = 3 * i + 2;
      rtb_UnitConversion_mr_idx_3 = rtb_Ibar[iy];
      rtb_MatrixConcatenation[6 * i + 2] = rtb_UnitConversion_mr_idx_3;
      rtb_MatrixConcatenation[6 * i + 5] = localP->Constant1_Value_m[iy];

      /* Selector: '<S413>/Selector' */
      localB->Selector[iy] = rtb_UnitConversion_mr_idx_3;
    }
  }

  /* Product: '<S424>/Product' incorporates:
   *  Integrator: '<S406>/p,q,r '
   */
  rtb_UnitConversion_mr_idx_3 = localB->pqr[1];
  rtb_UnaryMinus2_idx_0 = localB->pqr[0];
  rtb_Gain1_g0 = localB->pqr[2];
  for (i = 0; i < 3; i++) {
    /* SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' incorporates:
     *  Selector: '<S413>/Selector'
     */
    rtb_IntegratorSecondOrderLimite[i] = (localB->Selector[i + 3] *
      rtb_UnitConversion_mr_idx_3 + localB->Selector[i] * rtb_UnaryMinus2_idx_0)
      + localB->Selector[i + 6] * rtb_Gain1_g0;
  }

  /* End of Product: '<S424>/Product' */

  /* Product: '<S426>/j x k' */
  rtb_UnaryMinus2_idx_0 = rtb_IntegratorSecondOrderLimite[2];

  /* Product: '<S426>/k x i' */
  lam_muy_prime_idx_3 = rtb_IntegratorSecondOrderLimite[0];

  /* Product: '<S426>/i x j' */
  rtb_FrontBiasGain = rtb_IntegratorSecondOrderLimite[1];

  /* Product: '<S427>/k x j' */
  rtb_UnitConversion_mr_idx_3 = rtb_IntegratorSecondOrderLimite[1];

  /* Product: '<S427>/i x k' */
  rtb_Divide_pl = rtb_IntegratorSecondOrderLimite[2];

  /* Product: '<S427>/j x i' */
  rtb_Gain1_g0 = rtb_IntegratorSecondOrderLimite[0];

  /* Sum: '<S423>/Sum' incorporates:
   *  Product: '<S426>/i x j'
   *  Product: '<S426>/j x k'
   *  Product: '<S426>/k x i'
   *  Product: '<S427>/i x k'
   *  Product: '<S427>/j x i'
   *  Product: '<S427>/k x j'
   */
  rtb_IntegratorSecondOrderLimite[0] = localB->pqr[1] * rtb_UnaryMinus2_idx_0 -
    rtb_UnitConversion_mr_idx_3 * localB->pqr[2];
  rtb_IntegratorSecondOrderLimite[1] = lam_muy_prime_idx_3 * localB->pqr[2] -
    localB->pqr[0] * rtb_Divide_pl;
  rtb_IntegratorSecondOrderLimite[2] = localB->pqr[0] * rtb_FrontBiasGain -
    rtb_Gain1_g0 * localB->pqr[1];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S413>/Selector1' incorporates:
       *  Concatenate: '<S414>/Matrix Concatenation'
       */
      localB->Selector1_j[3 * i] = rtb_MatrixConcatenation[6 * i + 3];
      localB->Selector1_j[3 * i + 1] = rtb_MatrixConcatenation[6 * i + 4];
      localB->Selector1_j[3 * i + 2] = rtb_MatrixConcatenation[6 * i + 5];
    }

    /* Sum: '<S447>/Sum1' incorporates:
     *  Constant: '<S447>/Constant1'
     *  Constant: '<S449>/Constant1'
     */
    rtb_Product2_fq = (AdasPlantModel0_P->PlntVehCGHgtAxl - localB->Rbar[2]) -
      AdasPlantModel0_P->PlntVehHtchHgtAxl;

    /* Sum: '<S447>/Sum3' incorporates:
     *  Constant: '<S447>/Constant'
     *  Constant: '<S449>/Constant2'
     */
    rtb_Sum3_h = (localP->VehicleBody6DOF_hl - localP->VehicleBody6DOF_d) -
      localB->Rbar[1];

    /* Sum: '<S447>/Mx' incorporates:
     *  Product: '<S447>/Product4'
     *  Product: '<S447>/Product5'
     */
    localB->Mx = rtb_Sum3_h * localB->Hitch[2] - rtb_Product2_fq * localB->
      Hitch[1];

    /* Sum: '<S447>/Sum4' incorporates:
     *  Constant: '<S449>/Constant'
     */
    rtb_Sum4_g = AdasPlantModel0_P->PlntVehHtchDst + localB->Rbar[0];

    /* Sum: '<S447>/My' incorporates:
     *  Product: '<S447>/Product'
     *  Product: '<S447>/Product3'
     */
    localB->My = rtb_Product2_fq * localB->Hitch[0] + localB->Hitch[2] *
      rtb_Sum4_g;
  }

  /* Sum: '<S401>/Sum of Elements6' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Product: '<S401>/Product1'
   *  Product: '<S401>/Product2'
   *  Selector: '<S404>/Selector2'
   *  Selector: '<S404>/Selector3'
   *  Sum: '<S401>/Sum of Elements1'
   *  Sum: '<S401>/Sum of Elements15'
   */
  rtb_VectorConcatenate_km[0] = (localB->Mx - (((localB->Wbar[0] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[2] - localB->Wbar[1] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[5]) + localB->Wbar[2] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[8]) - localB->Wbar[3] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[11])) - (((rtb_ImpAsg_InsertedFor_FsB_at_i[1]
    * localB->Xbar[2] + localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[4]) +
    localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[7]) + localB->Xbar[2] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[10]);

  /* Sum: '<S401>/Sum of Elements9' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Product: '<S401>/Product'
   *  Product: '<S401>/Product4'
   *  Product: '<S401>/Product5'
   *  Selector: '<S404>/Selector1'
   *  Selector: '<S404>/Selector3'
   *  Sum: '<S401>/Sum of Elements16'
   *  Sum: '<S401>/Sum of Elements3'
   *  Sum: '<S401>/Sum of Elements4'
   */
  rtb_VectorConcatenate_km[1] = ((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] *
    localB->Xbar[2] + localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[3]) +
    localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[6]) + localB->Xbar[2] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[9]) + ((rtb_ImpAsg_InsertedFor_FsB_at_i[8] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[11]) * localB->Xbar[1] -
    rtb_UnitConversion_mr_idx_2 * localB->Xbar[0])) + localB->My;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S447>/Mz' incorporates:
     *  Product: '<S447>/Product1'
     *  Product: '<S447>/Product2'
     */
    localB->Mz = (0.0 - localB->Hitch[0] * rtb_Sum3_h) - localB->Hitch[1] *
      rtb_Sum4_g;
  }

  /* Sum: '<S401>/Sum of Elements5' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/FsB'
   *  Product: '<S401>/Product3'
   *  Product: '<S401>/Product6'
   *  Product: '<S401>/Product7'
   *  Selector: '<S404>/Selector1'
   *  Selector: '<S404>/Selector2'
   *  Sum: '<S401>/Sum of Elements11'
   *  Sum: '<S401>/Sum of Elements7'
   *  Sum: '<S401>/Sum of Elements8'
   */
  rtb_VectorConcatenate_km[2] = ((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] *
    localB->Wbar[0] - localB->Wbar[1] * rtb_ImpAsg_InsertedFor_FsB_at_i[3]) +
    localB->Wbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[6]) - localB->Wbar[3] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[9]) + (rtb_UnitConversion_mr_idx_1 *
    localB->Xbar[0] - (rtb_ImpAsg_InsertedFor_FsB_at_i[7] +
                       rtb_ImpAsg_InsertedFor_FsB_at_i[10]) * localB->Xbar[1]))
    + localB->Mz;

  /* Sum: '<S411>/Sum of Elements' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/MsB'
   *  Selector: '<S411>/Selector1'
   */
  rtb_VectorConcatenate_n[0] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[0] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[3]) + rtb_ImpAsg_InsertedFor_MsB_at_i[6]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[9];

  /* Sum: '<S411>/Sum of Elements1' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/MsB'
   *  Selector: '<S411>/Selector2'
   */
  rtb_VectorConcatenate_n[1] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[1] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[4]) + rtb_ImpAsg_InsertedFor_MsB_at_i[7]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[10];

  /* Sum: '<S411>/Sum of Elements2' incorporates:
   *  ForEachSliceAssignment generated from: '<S394>/MsB'
   *  Selector: '<S411>/Selector3'
   */
  rtb_VectorConcatenate_n[2] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[2] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[5]) + rtb_ImpAsg_InsertedFor_MsB_at_i[8]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[11];

  /* Product: '<S425>/Product' incorporates:
   *  Integrator: '<S406>/p,q,r '
   */
  rtb_UnitConversion_mr_idx_3 = localB->pqr[1];
  rtb_UnaryMinus2_idx_0 = localB->pqr[0];
  rtb_Gain1_g0 = localB->pqr[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S433>/Product4' */
    rtb_Divide_pl = rtb_Abs_k[i + 3] * rtb_UnitConversion_mr_idx_0;
    rtb_Product4_i[i] = rtb_Divide_pl;

    /* Sum: '<S399>/Add' */
    rtb_UnitConversion_mr_idx_1 = (((rtb_VectorConcatenate_km[i] +
      localB->Constant1[i]) + rtb_VectorConcatenate_n[i]) - rtb_Divide_pl) +
      localB->Hitch[i + 3];
    localB->Add_np[i] = rtb_UnitConversion_mr_idx_1;

    /* Sum: '<S413>/Sum2' incorporates:
     *  Integrator: '<S406>/p,q,r '
     *  Product: '<S425>/Product'
     *  Selector: '<S413>/Selector1'
     */
    rtb_Switch1_h[i] = (rtb_UnitConversion_mr_idx_1 - ((localB->Selector1_j[i +
      3] * rtb_UnitConversion_mr_idx_3 + localB->Selector1_j[i] *
      rtb_UnaryMinus2_idx_0) + localB->Selector1_j[i + 6] * rtb_Gain1_g0)) -
      rtb_IntegratorSecondOrderLimite[i];
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S413>/Selector2' incorporates:
       *  Concatenate: '<S414>/Matrix Concatenation'
       */
      localB->Selector2[3 * i] = rtb_MatrixConcatenation[6 * i];
      localB->Selector2[3 * i + 1] = rtb_MatrixConcatenation[6 * i + 1];
      localB->Selector2[3 * i + 2] = rtb_MatrixConcatenation[6 * i + 2];
    }
  }

  /* Product: '<S413>/Product2' incorporates:
   *  Selector: '<S413>/Selector2'
   *  Switch: '<S692>/Switch1'
   */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(rtb_Switch1_h, localB->Selector2,
    localB->Product2);

  /* Product: '<S409>/Product8' */
  rtb_Abs_k[0] = localB->Sum[0] * localB->UnitConversion[0];

  /* Product: '<S409>/Product1' */
  rtb_Abs_k[3] = localB->Add_np[0] * localB->pqr[0];

  /* Product: '<S409>/Product8' */
  rtb_Abs_k[1] = localB->Sum[1] * localB->UnitConversion[1];

  /* Product: '<S409>/Product1' */
  rtb_Abs_k[4] = localB->Add_np[1] * localB->pqr[1];

  /* Product: '<S409>/Product8' */
  rtb_Abs_k[2] = localB->Sum[2] * localB->UnitConversion[2];

  /* Product: '<S409>/Product1' */
  rtb_Abs_k[5] = localB->Add_np[2] * localB->pqr[2];

  /* Product: '<S409>/Product9' */
  rtb_Abs1_d[0] = localB->UnitConversion[0] * rtb_Product3_ju[0];

  /* UnaryMinus: '<S399>/Unary Minus' */
  localB->UnaryMinus_k[0] = -rtb_Product4_i[0];

  /* Product: '<S409>/Product2' incorporates:
   *  UnaryMinus: '<S399>/Unary Minus'
   */
  rtb_Abs1_d[3] = localB->pqr[0] * -rtb_Product4_i[0];

  /* Product: '<S409>/Product9' */
  rtb_Abs1_d[1] = localB->UnitConversion[1] * rtb_Product3_ju[1];

  /* UnaryMinus: '<S399>/Unary Minus' */
  localB->UnaryMinus_k[1] = -rtb_Product4_i[1];

  /* Product: '<S409>/Product2' incorporates:
   *  UnaryMinus: '<S399>/Unary Minus'
   */
  rtb_Abs1_d[4] = localB->pqr[1] * -rtb_Product4_i[1];

  /* Product: '<S409>/Product9' */
  rtb_Abs1_d[2] = localB->UnitConversion[2] * rtb_Product3_ju[2];

  /* UnaryMinus: '<S399>/Unary Minus' */
  localB->UnaryMinus_k[2] = -rtb_Product4_i[2];

  /* Product: '<S409>/Product2' incorporates:
   *  UnaryMinus: '<S399>/Unary Minus'
   */
  rtb_Abs1_d[5] = localB->pqr[2] * -rtb_Product4_i[2];

  /* Sum: '<S409>/Sum of Elements' */
  rtb_Product_py = -0.0;
  for (i = 0; i < 6; i++) {
    /* Abs: '<S409>/Abs' */
    rtb_UnitConversion_mr_idx_0 = std::abs(rtb_Abs_k[i]);
    rtb_Abs_k[i] = rtb_UnitConversion_mr_idx_0;

    /* Abs: '<S409>/Abs1' */
    rtb_Abs1_d[i] = std::abs(rtb_Abs1_d[i]);

    /* Sum: '<S409>/Sum of Elements' */
    rtb_Product_py += rtb_UnitConversion_mr_idx_0;
  }

  /* Sum: '<S409>/Sum of Elements' */
  localB->SumofElements_o = rtb_Product_py;

  /* Sum: '<S409>/Sum of Elements1' */
  rtb_Product_py = -0.0;
  for (i = 0; i < 6; i++) {
    rtb_Product_py += rtb_Abs1_d[i];
  }

  /* Sum: '<S409>/Sum of Elements1' */
  localB->SumofElements1 = rtb_Product_py;

  /* Trigonometry: '<S436>/sincos' */
  rtb_UnitConversion_mr_idx_0 = rty_VehFdbk[0];
  rtb_IntegratorSecondOrderLimite[0] = std::sin(rtb_UnitConversion_mr_idx_0);
  rtb_Switch1_h[0] = std::cos(rtb_UnitConversion_mr_idx_0);
  rtb_UnitConversion_mr_idx_0 = rty_VehFdbk[1];
  rtb_Switch1_h[1] = std::cos(rtb_UnitConversion_mr_idx_0);

  /* Fcn: '<S436>/thetadot' */
  rtb_Divide_pl = rtb_Switch1_h[0] * localB->pqr[1] -
    rtb_IntegratorSecondOrderLimite[0] * localB->pqr[2];

  /* Product: '<S445>/j x k' */
  lam_muy_prime_idx_3 = rtb_Divide_pl * localB->UnitConversion[2];

  /* Fcn: '<S436>/psidot' incorporates:
   *  Fcn: '<S436>/phidot'
   */
  rtb_UnitConversion_mr_idx_1 = rtb_IntegratorSecondOrderLimite[0] * localB->
    pqr[1] + rtb_Switch1_h[0] * localB->pqr[2];
  rtb_Gain1_g0 = rtb_UnitConversion_mr_idx_1 / rtb_Switch1_h[1];

  /* Fcn: '<S436>/phidot' incorporates:
   *  Trigonometry: '<S436>/sincos'
   */
  rtb_FrontBiasGain = std::sin(rtb_UnitConversion_mr_idx_0) / rtb_Switch1_h[1] *
    rtb_UnitConversion_mr_idx_1 + localB->pqr[0];

  /* Product: '<S446>/j x i' */
  rtb_UnitConversion_mr_idx_0 = rtb_Divide_pl * localB->UnitConversion[0];

  /* Switch: '<S442>/Switch' incorporates:
   *  Abs: '<S442>/Abs'
   *  Constant: '<S443>/Constant'
   *  Constant: '<S444>/Constant'
   *  Fcn: '<S442>/Fcn'
   *  Logic: '<S442>/Logical Operator'
   *  RelationalOperator: '<S443>/Compare'
   *  RelationalOperator: '<S444>/Compare'
   */
  if ((localB->UnitConversion[0] >= -localP->VehicleBody6DOF_xdot_tol) &&
      (localB->UnitConversion[0] <= localP->VehicleBody6DOF_xdot_tol)) {
    rtb_Divide_pl = 0.2 / (3.0 - rt_powd_snf(localB->UnitConversion[0] / 0.1,
      2.0));
  } else {
    rtb_Divide_pl = std::abs(localB->UnitConversion[0]);
  }

  /* End of Switch: '<S442>/Switch' */

  /* Trigonometry: '<S435>/Trigonometric Function' incorporates:
   *  Product: '<S435>/Divide'
   */
  localB->Beta = std::atan(localB->UnitConversion[1] / rtb_Divide_pl);

  /* UnitConversion: '<S410>/Unit Conversion3' incorporates:
   *  Product: '<S445>/i x j'
   *  Product: '<S445>/k x i'
   *  Product: '<S446>/i x k'
   *  Product: '<S446>/k x j'
   *  Sum: '<S410>/Add'
   *  Sum: '<S437>/Sum'
   */
  /* Unit Conversion - from: rad/s^2 to: rad/s^2
     Expression: output = (1*input) + (0) */
  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  localB->UnitConversion3[0] = ((lam_muy_prime_idx_3 - rtb_Gain1_g0 *
    localB->UnitConversion[1]) + localB->Sum_l[0]) * 0.10197162129779282;
  localB->UnitConversion3[1] = ((rtb_Gain1_g0 * localB->UnitConversion[0] -
    rtb_FrontBiasGain * localB->UnitConversion[2]) + localB->Sum_l[1]) *
    0.10197162129779282;
  localB->UnitConversion3[2] = ((rtb_FrontBiasGain * localB->UnitConversion[1] -
    rtb_UnitConversion_mr_idx_0) + localB->Sum_l[2]) * 0.10197162129779282;

  /* UnitConversion: '<S410>/Unit Conversion2' */
  localB->UnitConversion2[0] = localB->Product2[0];

  /* UnaryMinus: '<S399>/Unary Minus1' */
  localB->UnaryMinus1_o[0] = -rtb_Product3_ju[0];

  /* UnitConversion: '<S410>/Unit Conversion2' */
  localB->UnitConversion2[1] = localB->Product2[1];

  /* UnaryMinus: '<S399>/Unary Minus1' */
  localB->UnaryMinus1_o[1] = -rtb_Product3_ju[1];

  /* UnitConversion: '<S410>/Unit Conversion2' */
  localB->UnitConversion2[2] = localB->Product2[2];

  /* UnaryMinus: '<S399>/Unary Minus1' */
  localB->UnaryMinus1_o[2] = -rtb_Product3_ju[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S391>/Constant' */
    std::memcpy(&localB->Constant[0], &localP->Constant_Value_j[0], 12U * sizeof
                (real_T));
  }

  /* Sum: '<S477>/Sum' incorporates:
   *  Product: '<S482>/i x j'
   *  Product: '<S482>/j x k'
   *  Product: '<S482>/k x i'
   *  Product: '<S483>/i x k'
   *  Product: '<S483>/j x i'
   *  Product: '<S483>/k x j'
   */
  rtb_IntegratorSecondOrderLimite[0] = localB->pqr[1] * localB->Subtract[2] -
    localB->Subtract[1] * localB->pqr[2];
  rtb_IntegratorSecondOrderLimite[1] = localB->Subtract[0] * localB->pqr[2] -
    localB->pqr[0] * localB->Subtract[2];
  rtb_IntegratorSecondOrderLimite[2] = localB->pqr[0] * localB->Subtract[1] -
    localB->Subtract[0] * localB->pqr[1];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S472>/Add1' */
    localB->Add1_f[i] = rtb_IntegratorSecondOrderLimite[i] +
      localB->UnitConversion[i];

    /* Sum: '<S472>/Add4' incorporates:
     *  Math: '<S484>/Transpose1'
     *  Product: '<S475>/Product'
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     */
    localB->V_wb_k[i] = ((rtb_Transpose1[i + 3] *
                          rtb_IntegratorSecondOrderLimite[1] + rtb_Transpose1[i]
                          * rtb_IntegratorSecondOrderLimite[0]) +
                         rtb_Transpose1[i + 6] *
                         rtb_IntegratorSecondOrderLimite[2]) +
      localB->UnitConversion_i[i];
  }

  /* Switch: '<S478>/Switch' incorporates:
   *  Abs: '<S478>/Abs'
   *  Constant: '<S479>/Constant'
   *  Constant: '<S480>/Constant'
   *  Fcn: '<S478>/Fcn'
   *  Logic: '<S478>/Logical Operator'
   *  RelationalOperator: '<S479>/Compare'
   *  RelationalOperator: '<S480>/Compare'
   */
  if ((localB->Add1_f[0] >= -localP->VehicleBody6DOF_xdot_tol) &&
      (localB->Add1_f[0] <= localP->VehicleBody6DOF_xdot_tol)) {
    rtb_Divide_pl = 0.2 / (3.0 - rt_powd_snf(localB->Add1_f[0] / 0.1, 2.0));
  } else {
    rtb_Divide_pl = std::abs(localB->Add1_f[0]);
  }

  /* End of Switch: '<S478>/Switch' */

  /* Trigonometry: '<S473>/Trigonometric Function' incorporates:
   *  Product: '<S473>/Divide'
   */
  localB->Beta_b = std::atan(localB->Add1_f[1] / rtb_Divide_pl);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S453>/Vector Concatenate' incorporates:
     *  Concatenate: '<S453>/Vector Concatenate'
     */
    localB->VectorConcatenate_o[1] = rtb_Sum3_h;

    /* SignalConversion generated from: '<S453>/Vector Concatenate' incorporates:
     *  Concatenate: '<S453>/Vector Concatenate'
     */
    localB->VectorConcatenate_o[2] = rtb_Product2_fq;
  }

  /* Fcn: '<S485>/Fcn11' */
  rtb_VectorConcatenate_ci[0] = dpi_idx_0;

  /* Fcn: '<S485>/Fcn21' */
  rtb_VectorConcatenate_ci[1] = dpi_idx_3;

  /* Fcn: '<S485>/Fcn31' */
  rtb_VectorConcatenate_ci[2] = Fzo_prime_idx_1;

  /* Fcn: '<S485>/Fcn12' */
  rtb_VectorConcatenate_ci[3] = Fzo_prime_idx_2;

  /* Fcn: '<S485>/Fcn22' */
  rtb_VectorConcatenate_ci[4] = dpi_idx_1;

  /* Fcn: '<S485>/Fcn32' */
  rtb_VectorConcatenate_ci[5] = Fzo_prime_idx_0;

  /* Fcn: '<S485>/Fcn13' */
  rtb_VectorConcatenate_ci[6] = -dpi_idx_2;

  /* Fcn: '<S485>/Fcn23' */
  rtb_VectorConcatenate_ci[7] = Fzo_prime_idx_3;

  /* Fcn: '<S485>/Fcn33' */
  rtb_VectorConcatenate_ci[8] = rtb_Saturation_0;

  /* Math: '<S484>/Transpose1' incorporates:
   *  Concatenate: '<S489>/Vector Concatenate'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1[3 * i] = rtb_VectorConcatenate_ci[i];
    rtb_Transpose1[3 * i + 1] = rtb_VectorConcatenate_ci[i + 3];
    rtb_Transpose1[3 * i + 2] = rtb_VectorConcatenate_ci[i + 6];
  }

  /* End of Math: '<S484>/Transpose1' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S453>/Unary Minus2' incorporates:
     *  Concatenate: '<S453>/Vector Concatenate'
     */
    localB->VectorConcatenate_o[0] = -rtb_Sum4_g;
  }

  /* Sum: '<S488>/Sum' incorporates:
   *  Product: '<S490>/i x j'
   *  Product: '<S490>/j x k'
   *  Product: '<S490>/k x i'
   *  Product: '<S491>/i x k'
   *  Product: '<S491>/j x i'
   *  Product: '<S491>/k x j'
   */
  rtb_IntegratorSecondOrderLimite[0] = localB->pqr[1] *
    localB->VectorConcatenate_o[2] - localB->VectorConcatenate_o[1] *
    localB->pqr[2];
  rtb_IntegratorSecondOrderLimite[1] = localB->VectorConcatenate_o[0] *
    localB->pqr[2] - localB->pqr[0] * localB->VectorConcatenate_o[2];
  rtb_IntegratorSecondOrderLimite[2] = localB->pqr[0] *
    localB->VectorConcatenate_o[1] - localB->VectorConcatenate_o[0] *
    localB->pqr[1];

  /* Product: '<S487>/Product' incorporates:
   *  Concatenate: '<S453>/Vector Concatenate'
   *  Math: '<S484>/Transpose1'
   */
  rtb_Sum4_g = localB->VectorConcatenate_o[0];
  rtb_Product2_fq = localB->VectorConcatenate_o[1];
  rtb_Sum3_h = localB->VectorConcatenate_o[2];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S484>/Add1' */
    localB->Add1_k[i] = rtb_IntegratorSecondOrderLimite[i] +
      localB->UnitConversion[i];
    rtb_UnitConversion_mr_idx_0 = rtb_Transpose1[i];
    rtb_UnitConversion_mr_idx_1 = rtb_UnitConversion_mr_idx_0 * rtb_Sum4_g;

    /* Product: '<S486>/Product' incorporates:
     *  Math: '<S484>/Transpose1'
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     *  Switch: '<S692>/Switch1'
     */
    dpi_idx_2 = rtb_UnitConversion_mr_idx_0 * rtb_IntegratorSecondOrderLimite[0];
    rtb_UnitConversion_mr_idx_0 = rtb_Transpose1[i + 3];
    rtb_UnitConversion_mr_idx_1 += rtb_UnitConversion_mr_idx_0 * rtb_Product2_fq;

    /* Product: '<S486>/Product' incorporates:
     *  Math: '<S484>/Transpose1'
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     *  Switch: '<S692>/Switch1'
     */
    dpi_idx_2 += rtb_UnitConversion_mr_idx_0 * rtb_IntegratorSecondOrderLimite[1];
    rtb_UnitConversion_mr_idx_0 = rtb_Transpose1[i + 6];

    /* Sum: '<S484>/Add' incorporates:
     *  Math: '<S484>/Transpose1'
     */
    localB->Add_k[i] = (rtb_UnitConversion_mr_idx_0 * rtb_Sum3_h +
                        rtb_UnitConversion_mr_idx_1) + localB->xeyeze[i];

    /* Sum: '<S484>/Add4' incorporates:
     *  Product: '<S486>/Product'
     *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
     *  Switch: '<S692>/Switch1'
     */
    localB->V_wb_jq[i] = (rtb_UnitConversion_mr_idx_0 *
                          rtb_IntegratorSecondOrderLimite[2] + dpi_idx_2) +
      localB->UnitConversion_i[i];

    /* Selector: '<S404>/Selector4' incorporates:
     *  Concatenate: '<S404>/Vector Concatenate2'
     *  ForEachSliceAssignment generated from: '<S394>/FsB'
     */
    localB->VectorConcatenate2[i + 3] = rtb_ImpAsg_InsertedFor_FsB_at_i[i + 3];

    /* Selector: '<S404>/Selector5' incorporates:
     *  Concatenate: '<S404>/Vector Concatenate2'
     *  ForEachSliceAssignment generated from: '<S394>/FsB'
     */
    localB->VectorConcatenate2[i + 6] = rtb_ImpAsg_InsertedFor_FsB_at_i[i + 6];

    /* Selector: '<S404>/Selector6' incorporates:
     *  Concatenate: '<S404>/Vector Concatenate2'
     *  ForEachSliceAssignment generated from: '<S394>/FsB'
     */
    localB->VectorConcatenate2[i + 9] = rtb_ImpAsg_InsertedFor_FsB_at_i[i + 9];

    /* Selector: '<S404>/Selector7' incorporates:
     *  Concatenate: '<S404>/Vector Concatenate2'
     *  ForEachSliceAssignment generated from: '<S394>/FsB'
     */
    localB->VectorConcatenate2[i] = rtb_ImpAsg_InsertedFor_FsB_at_i[i];
  }

  /* End of Product: '<S487>/Product' */

  /* SignalConversion: '<S512>/Signal Copy' */
  localB->SignalCopy[0] = rtb_Product[0];
  localB->SignalCopy[1] = rtb_Product[1];
  localB->SignalCopy[2] = rtb_Product[2];
  localB->SignalCopy[3] = rtb_Product[3];

  /* Product: '<S516>/Product2' */
  Kyalpha[0] = rty_VehFdbk_c[0] * localB->Re[0];
  Kyalpha[1] = rty_VehFdbk_c[1] * localB->Re[1];
  Kyalpha[2] = rty_VehFdbk_c[2] * localB->Re[2];
  Kyalpha[3] = rty_VehFdbk_c[3] * localB->Re[3];

  /* Saturate: '<S516>/Saturation1' */
  if (rtb_sig_x[0] > localP->Saturation1_UpperSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[0] < localP->Saturation1_LowerSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[0];
  }

  /* Product: '<S516>/Product3' incorporates:
   *  Abs: '<S516>/Abs'
   *  Saturate: '<S516>/Saturation1'
   *  Sum: '<S516>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[0] - Kyalpha[0]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_k;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_mf) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_mf;
  }

  /* Product: '<S516>/Product1' incorporates:
   *  Saturate: '<S516>/Saturation'
   *  Sum: '<S516>/Add'
   */
  localB->Product1[0] = (rtb_ImpAsg_InsertedFor_ydotWhee[0] - localB->
    Integrator[0]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation1' */
  if (rtb_sig_x[1] > localP->Saturation1_UpperSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[1] < localP->Saturation1_LowerSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[1];
  }

  /* Product: '<S516>/Product3' incorporates:
   *  Abs: '<S516>/Abs'
   *  Saturate: '<S516>/Saturation1'
   *  Sum: '<S516>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[1] - Kyalpha[1]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_k;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_mf) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_mf;
  }

  /* Product: '<S516>/Product1' incorporates:
   *  Saturate: '<S516>/Saturation'
   *  Sum: '<S516>/Add'
   */
  localB->Product1[1] = (rtb_ImpAsg_InsertedFor_ydotWhee[1] - localB->
    Integrator[1]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation1' */
  if (rtb_sig_x[2] > localP->Saturation1_UpperSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[2] < localP->Saturation1_LowerSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[2];
  }

  /* Product: '<S516>/Product3' incorporates:
   *  Abs: '<S516>/Abs'
   *  Saturate: '<S516>/Saturation1'
   *  Sum: '<S516>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[2] - Kyalpha[2]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_k;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_mf) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_mf;
  }

  /* Product: '<S516>/Product1' incorporates:
   *  Saturate: '<S516>/Saturation'
   *  Sum: '<S516>/Add'
   */
  localB->Product1[2] = (rtb_ImpAsg_InsertedFor_ydotWhee[2] - localB->
    Integrator[2]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation1' */
  if (rtb_sig_x[3] > localP->Saturation1_UpperSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[3] < localP->Saturation1_LowerSat) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[3];
  }

  /* Product: '<S516>/Product3' incorporates:
   *  Abs: '<S516>/Abs'
   *  Saturate: '<S516>/Saturation1'
   *  Sum: '<S516>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[3] - Kyalpha[3]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_k) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_k;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_mf) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_mf;
  }

  /* Product: '<S516>/Product1' incorporates:
   *  Saturate: '<S516>/Saturation'
   *  Sum: '<S516>/Add'
   */
  localB->Product1[3] = (rtb_ImpAsg_InsertedFor_ydotWhee[3] - localB->
    Integrator[3]) * rtb_UnaryMinus2_idx_0;

  /* Product: '<S517>/Product2' */
  Kyalpha[0] = rty_VehFdbk_c[0] * localB->Re[0];
  Kyalpha[1] = rty_VehFdbk_c[1] * localB->Re[1];
  Kyalpha[2] = rty_VehFdbk_c[2] * localB->Re[2];
  Kyalpha[3] = rty_VehFdbk_c[3] * localB->Re[3];

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_y[0] > localP->Saturation1_UpperSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_j;
  } else if (rtb_sig_y[0] < localP->Saturation1_LowerSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_f;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_y[0];
  }

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   *  Sum: '<S517>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape2[0] - Kyalpha[0]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_h) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_h;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_o) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_o;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1_p[0] = (rtb_ImpAsg_InsertedFor_xdotWhee[0] -
    localB->Integrator_i[0]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_y[1] > localP->Saturation1_UpperSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_j;
  } else if (rtb_sig_y[1] < localP->Saturation1_LowerSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_f;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_y[1];
  }

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   *  Sum: '<S517>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape2[1] - Kyalpha[1]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_h) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_h;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_o) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_o;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1_p[1] = (rtb_ImpAsg_InsertedFor_xdotWhee[1] -
    localB->Integrator_i[1]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_y[2] > localP->Saturation1_UpperSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_j;
  } else if (rtb_sig_y[2] < localP->Saturation1_LowerSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_f;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_y[2];
  }

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   *  Sum: '<S517>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape2[2] - Kyalpha[2]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_h) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_h;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_o) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_o;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1_p[2] = (rtb_ImpAsg_InsertedFor_xdotWhee[2] -
    localB->Integrator_i[2]) * rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_y[3] > localP->Saturation1_UpperSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_j;
  } else if (rtb_sig_y[3] < localP->Saturation1_LowerSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_f;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_y[3];
  }

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   *  Sum: '<S517>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape2[3] - Kyalpha[3]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_h) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_h;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_o) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_o;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1_p[3] = (rtb_ImpAsg_InsertedFor_xdotWhee[3] -
    localB->Integrator_i[3]) * rtb_UnaryMinus2_idx_0;

  /* Product: '<S519>/Product2' */
  Kyalpha[0] = rty_VehFdbk_c[0] * localB->Re[0];
  Kyalpha[1] = rty_VehFdbk_c[1] * localB->Re[1];
  Kyalpha[2] = rty_VehFdbk_c[2] * localB->Re[2];
  Kyalpha[3] = rty_VehFdbk_c[3] * localB->Re[3];

  /* Saturate: '<S519>/Saturation1' */
  if (rtb_sig_x[0] > localP->Saturation1_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_f;
  } else if (rtb_sig_x[0] < localP->Saturation1_LowerSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_j;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[0];
  }

  /* Product: '<S519>/Product3' incorporates:
   *  Abs: '<S519>/Abs'
   *  Saturate: '<S519>/Saturation1'
   *  Sum: '<S519>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[0] - Kyalpha[0]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S519>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_f;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_d) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_d;
  }

  /* Product: '<S519>/Product1' incorporates:
   *  Saturate: '<S519>/Saturation'
   *  Sum: '<S519>/Add'
   */
  localB->Product1_l[0] = (rtb_My[0] - localB->Integrator_e[0]) *
    rtb_UnaryMinus2_idx_0;

  /* Switch: '<S520>/Switch' incorporates:
   *  Constant: '<S520>/Constant'
   */
  if (rtb_Switch_p_idx_0 > localP->Switch_Threshold_c) {
    rtb_UnaryMinus2_idx_0 = localB->IntegratorSecondOrder_o2[0];
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_c;
  }

  /* Gain: '<S520>/Gain1' incorporates:
   *  Constant: '<S520>/Fg'
   *  Gain: '<S520>/Gain2'
   *  Sum: '<S520>/Sum2'
   *  Switch: '<S520>/Switch'
   */
  localB->Gain1_d[0] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
    AdasPlantModel0_P->PlntWhlMass[0] + localB->SignalCopy[0]) -
    localB->Saturation[0]) - AdasPlantModel0_P->PlntWhlVertDampCoeff[0] *
                        rtb_UnaryMinus2_idx_0) * (1.0 /
    AdasPlantModel0_P->PlntWhlMass[0]);

  /* Saturate: '<S519>/Saturation1' */
  if (rtb_sig_x[1] > localP->Saturation1_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_f;
  } else if (rtb_sig_x[1] < localP->Saturation1_LowerSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_j;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[1];
  }

  /* Product: '<S519>/Product3' incorporates:
   *  Abs: '<S519>/Abs'
   *  Saturate: '<S519>/Saturation1'
   *  Sum: '<S519>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[1] - Kyalpha[1]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S519>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_f;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_d) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_d;
  }

  /* Product: '<S519>/Product1' incorporates:
   *  Saturate: '<S519>/Saturation'
   *  Sum: '<S519>/Add'
   */
  localB->Product1_l[1] = (rtb_My[1] - localB->Integrator_e[1]) *
    rtb_UnaryMinus2_idx_0;

  /* Switch: '<S520>/Switch' incorporates:
   *  Constant: '<S520>/Constant'
   */
  if (rtb_Switch_p_idx_1 > localP->Switch_Threshold_c) {
    rtb_UnaryMinus2_idx_0 = localB->IntegratorSecondOrder_o2[1];
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_c;
  }

  /* Gain: '<S520>/Gain1' incorporates:
   *  Constant: '<S520>/Fg'
   *  Gain: '<S520>/Gain2'
   *  Sum: '<S520>/Sum2'
   *  Switch: '<S520>/Switch'
   */
  localB->Gain1_d[1] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
    AdasPlantModel0_P->PlntWhlMass[1] + localB->SignalCopy[1]) -
    localB->Saturation[1]) - AdasPlantModel0_P->PlntWhlVertDampCoeff[1] *
                        rtb_UnaryMinus2_idx_0) * (1.0 /
    AdasPlantModel0_P->PlntWhlMass[1]);

  /* Saturate: '<S519>/Saturation1' */
  if (rtb_sig_x[2] > localP->Saturation1_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_f;
  } else if (rtb_sig_x[2] < localP->Saturation1_LowerSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_j;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[2];
  }

  /* Product: '<S519>/Product3' incorporates:
   *  Abs: '<S519>/Abs'
   *  Saturate: '<S519>/Saturation1'
   *  Sum: '<S519>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[2] - Kyalpha[2]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S519>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_f;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_d) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_d;
  }

  /* Product: '<S519>/Product1' incorporates:
   *  Saturate: '<S519>/Saturation'
   *  Sum: '<S519>/Add'
   */
  localB->Product1_l[2] = (rtb_My[2] - localB->Integrator_e[2]) *
    rtb_UnaryMinus2_idx_0;

  /* Switch: '<S520>/Switch' incorporates:
   *  Constant: '<S520>/Constant'
   */
  if (rtb_Switch_p_idx_2 > localP->Switch_Threshold_c) {
    rtb_UnaryMinus2_idx_0 = localB->IntegratorSecondOrder_o2[2];
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_c;
  }

  /* Gain: '<S520>/Gain1' incorporates:
   *  Constant: '<S520>/Fg'
   *  Gain: '<S520>/Gain2'
   *  Sum: '<S520>/Sum2'
   *  Switch: '<S520>/Switch'
   */
  localB->Gain1_d[2] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
    AdasPlantModel0_P->PlntWhlMass[2] + localB->SignalCopy[2]) -
    localB->Saturation[2]) - AdasPlantModel0_P->PlntWhlVertDampCoeff[2] *
                        rtb_UnaryMinus2_idx_0) * (1.0 /
    AdasPlantModel0_P->PlntWhlMass[2]);

  /* Saturate: '<S519>/Saturation1' */
  if (rtb_sig_x[3] > localP->Saturation1_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_UpperSat_f;
  } else if (rtb_sig_x[3] < localP->Saturation1_LowerSat_j) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation1_LowerSat_j;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_sig_x[3];
  }

  /* Product: '<S519>/Product3' incorporates:
   *  Abs: '<S519>/Abs'
   *  Saturate: '<S519>/Saturation1'
   *  Sum: '<S519>/Add1'
   */
  rtb_UnaryMinus2_idx_0 = std::abs(localB->Reshape1[3] - Kyalpha[3]) /
    rtb_UnaryMinus2_idx_0;

  /* Saturate: '<S519>/Saturation' */
  if (rtb_UnaryMinus2_idx_0 > localP->Saturation_UpperSat_f) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_f;
  } else if (rtb_UnaryMinus2_idx_0 < localP->Saturation_LowerSat_d) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_d;
  }

  /* Product: '<S519>/Product1' incorporates:
   *  Saturate: '<S519>/Saturation'
   *  Sum: '<S519>/Add'
   */
  localB->Product1_l[3] = (rtb_My[3] - localB->Integrator_e[3]) *
    rtb_UnaryMinus2_idx_0;

  /* Switch: '<S520>/Switch' incorporates:
   *  Constant: '<S520>/Constant'
   *  Sum: '<S520>/Sum6'
   */
  if (rtb_Switch_p_idx_3 > localP->Switch_Threshold_c) {
    rtb_UnaryMinus2_idx_0 = localB->IntegratorSecondOrder_o2[3];
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_c;
  }

  /* Gain: '<S520>/Gain1' incorporates:
   *  Constant: '<S520>/Fg'
   *  Gain: '<S520>/Gain2'
   *  Sum: '<S520>/Sum2'
   *  Switch: '<S520>/Switch'
   */
  localB->Gain1_d[3] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
    AdasPlantModel0_P->PlntWhlMass[3] + localB->SignalCopy[3]) -
    localB->Saturation[3]) - AdasPlantModel0_P->PlntWhlVertDampCoeff[3] *
                        rtb_UnaryMinus2_idx_0) * (1.0 /
    AdasPlantModel0_P->PlntWhlMass[3]);
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S601>/Memory' */
    localB->Memory_l = localDW->Memory_PreviousInput_l;

    /* Constant: '<S600>/domega_o' */
    localB->domega_o_b = AdasPlantModel0_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S601>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&AdasPlantModel0_M)->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE_d,
                       (localB->Memory_l));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_c3 != 0)) {
      localX->Integrator_CSTATE_d = localB->domega_o_b;
    }
  }

  /* Sum: '<S600>/Subtract1' incorporates:
   *  Gain: '<S600>/Gain1'
   *  Gain: '<S600>/Gain2'
   *  Integrator: '<S600>/Integrator'
   *  Integrator: '<S601>/Integrator'
   */
  lam_muy_prime_idx_3 = AdasPlantModel0_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_d + AdasPlantModel0_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_jcw;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S556>/Switch' incorporates:
     *  Constant: '<S556>/Constant'
     */
    if (localP->Constant_Value_k > localP->Switch_Threshold_ao) {
      /* Switch: '<S556>/Switch' incorporates:
       *  Constant: '<S556>/Constant1'
       */
      localB->diffDir = localP->Constant1_Value_l;
    } else {
      /* Switch: '<S556>/Switch' incorporates:
       *  Constant: '<S556>/Constant1'
       *  UnaryMinus: '<S556>/Unary Minus'
       */
      localB->diffDir = -localP->Constant1_Value_l;
    }

    /* End of Switch: '<S556>/Switch' */

    /* Constant: '<S552>/Constant' incorporates:
     *  Concatenate: '<S552>/Vector Concatenate'
     */
    localB->VectorConcatenate_c[0] = AdasPlantModel0_P->PlntDiffrntlAxl1InitVel;

    /* Constant: '<S552>/Constant1' incorporates:
     *  Concatenate: '<S552>/Vector Concatenate'
     */
    localB->VectorConcatenate_c[1] = AdasPlantModel0_P->PlntDiffrntlAxl2InitVel;
  }

  /* Integrator: '<S552>/Integrator' */
  /* Limited  Integrator  */
  if (localDW->Integrator_IWORK_f != 0) {
    localX->Integrator_CSTATE_a[0] = localB->VectorConcatenate_c[0];
    localX->Integrator_CSTATE_a[1] = localB->VectorConcatenate_c[1];
  }

  /* Gain: '<S556>/Gain' */
  rtb_Product_py = AdasPlantModel0_P->PlntDiffrntlRatio / 2.0;

  /* Integrator: '<S552>/Integrator' */
  rtb_Switch_p_idx_0 = localX->Integrator_CSTATE_a[0];
  if (localX->Integrator_CSTATE_a[0] >= localP->Integrator_UpperSat_k) {
    rtb_Switch_p_idx_0 = localP->Integrator_UpperSat_k;
    localX->Integrator_CSTATE_a[0] = localP->Integrator_UpperSat_k;
  } else if (localX->Integrator_CSTATE_a[0] <= localP->Integrator_LowerSat_j) {
    rtb_Switch_p_idx_0 = localP->Integrator_LowerSat_j;
    localX->Integrator_CSTATE_a[0] = localP->Integrator_LowerSat_j;
  }

  /* Gain: '<S556>/Gain' incorporates:
   *  Integrator: '<S552>/Integrator'
   *  Product: '<S556>/Product'
   */
  rtb_UnaryMinus2_idx_0 = localB->diffDir * rtb_Switch_p_idx_0 * rtb_Product_py;

  /* Integrator: '<S552>/Integrator' */
  rtb_Switch_p_idx_0 = localX->Integrator_CSTATE_a[1];
  if (localX->Integrator_CSTATE_a[1] >= localP->Integrator_UpperSat_k) {
    rtb_Switch_p_idx_0 = localP->Integrator_UpperSat_k;
    localX->Integrator_CSTATE_a[1] = localP->Integrator_UpperSat_k;
  } else if (localX->Integrator_CSTATE_a[1] <= localP->Integrator_LowerSat_j) {
    rtb_Switch_p_idx_0 = localP->Integrator_LowerSat_j;
    localX->Integrator_CSTATE_a[1] = localP->Integrator_LowerSat_j;
  }

  /* Sum: '<S556>/Sum of Elements' incorporates:
   *  Gain: '<S556>/Gain'
   *  Integrator: '<S552>/Integrator'
   *  Product: '<S556>/Product'
   */
  localB->SumofElements_m = localB->diffDir * rtb_Switch_p_idx_0 *
    rtb_Product_py + rtb_UnaryMinus2_idx_0;

  /* Gain: '<S573>/Gain' incorporates:
   *  Abs: '<S572>/Abs'
   *  Constant: '<S573>/Constant1'
   *  Gain: '<S573>/Gain1'
   *  Gain: '<S573>/Gain2'
   *  SignalConversion generated from: '<S556>/Vector Concatenate'
   *  Sum: '<S573>/Subtract1'
   *  Sum: '<S573>/Subtract2'
   *  Trigonometry: '<S573>/Trigonometric Function'
   */
  rtb_FrontBiasGain = (std::tanh((localP->Gain1_Gain_e * std::abs
    (localB->SumofElements_m) - localP->Constant1_Value_lx) * localP->Gain2_Gain)
                       + localP->Constant1_Value_lx) * localP->Gain_Gain_d;

  /* Switch: '<S566>/Switch' incorporates:
   *  Constant: '<S566>/Constant'
   *  Constant: '<S574>/Constant'
   *  Product: '<S566>/Product1'
   *  SignalConversion generated from: '<S556>/Vector Concatenate'
   */
  if (lam_muy_prime_idx_3 * localB->SumofElements_m >
      localP->Switch_Threshold_i2) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntDiffrntlEff;
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_fl;
  }

  /* Sum: '<S572>/Subtract1' incorporates:
   *  Constant: '<S572>/Constant'
   *  Constant: '<S573>/Constant1'
   *  Product: '<S572>/Product3'
   *  Product: '<S572>/Product5'
   *  Sum: '<S573>/Subtract'
   *  Switch: '<S566>/Switch'
   */
  rtb_Sum4_g = (localP->Constant1_Value_lx - rtb_FrontBiasGain) *
    localP->Constant_Value_l + rtb_UnaryMinus2_idx_0 * rtb_FrontBiasGain;

  /* Gain: '<S569>/Gain' incorporates:
   *  Abs: '<S568>/Abs'
   *  Constant: '<S569>/Constant1'
   *  Gain: '<S569>/Gain1'
   *  Gain: '<S569>/Gain2'
   *  Integrator: '<S552>/Integrator'
   *  Sum: '<S569>/Subtract1'
   *  Sum: '<S569>/Subtract2'
   *  Trigonometry: '<S569>/Trigonometric Function'
   *  UnaryMinus: '<S556>/Unary Minus1'
   */
  rtb_FrontBiasGain = (std::tanh((localP->Gain1_Gain_a2 * std::abs
    (-localX->Integrator_CSTATE_a[0]) - localP->Constant1_Value_h) *
    localP->Gain2_Gain_p) + localP->Constant1_Value_h) * localP->Gain_Gain_ja;

  /* Switch: '<S564>/Switch' incorporates:
   *  Constant: '<S564>/Constant'
   *  Constant: '<S574>/Constant'
   *  Integrator: '<S552>/Integrator'
   *  Product: '<S564>/Product1'
   *  UnaryMinus: '<S556>/Unary Minus1'
   *  UnaryMinus: '<S578>/Unary Minus'
   */
  if (-rtb_ChrgCurrLmt * -localX->Integrator_CSTATE_a[0] >
      localP->Switch_Threshold_b) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntDiffrntlEff;
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_fq;
  }

  /* Sum: '<S568>/Subtract1' incorporates:
   *  Constant: '<S568>/Constant'
   *  Constant: '<S569>/Constant1'
   *  Product: '<S568>/Product3'
   *  Product: '<S568>/Product5'
   *  Sum: '<S569>/Subtract'
   *  Switch: '<S564>/Switch'
   */
  rtb_Sum3_h = (localP->Constant1_Value_h - rtb_FrontBiasGain) *
    localP->Constant_Value_lo + rtb_UnaryMinus2_idx_0 * rtb_FrontBiasGain;

  /* Gain: '<S571>/Gain' incorporates:
   *  Abs: '<S570>/Abs'
   *  Constant: '<S571>/Constant1'
   *  Gain: '<S571>/Gain1'
   *  Gain: '<S571>/Gain2'
   *  Integrator: '<S552>/Integrator'
   *  Sum: '<S571>/Subtract1'
   *  Sum: '<S571>/Subtract2'
   *  Trigonometry: '<S571>/Trigonometric Function'
   *  UnaryMinus: '<S556>/Unary Minus1'
   */
  rtb_FrontBiasGain = (std::tanh((localP->Gain1_Gain_m * std::abs
    (-localX->Integrator_CSTATE_a[1]) - localP->Constant1_Value_o) *
    localP->Gain2_Gain_e) + localP->Constant1_Value_o) * localP->Gain_Gain_lj;

  /* SignalConversion generated from: '<S555>/ SFunction ' incorporates:
   *  MATLAB Function: '<S552>/Open Differential'
   *  Product: '<S564>/Product4'
   *  Product: '<S566>/Product4'
   *  UnaryMinus: '<S578>/Unary Minus'
   */
  rtb_IntegratorSecondOrderLimite[0] = rtb_Sum4_g * lam_muy_prime_idx_3;
  rtb_IntegratorSecondOrderLimite[1] = rtb_Sum3_h * -rtb_ChrgCurrLmt;

  /* Switch: '<S565>/Switch' incorporates:
   *  Constant: '<S565>/Constant'
   *  Constant: '<S574>/Constant'
   *  Integrator: '<S552>/Integrator'
   *  Product: '<S565>/Product1'
   *  UnaryMinus: '<S556>/Unary Minus1'
   *  UnaryMinus: '<S586>/Unary Minus'
   */
  if (-rtb_DischrgCurrLmt * -localX->Integrator_CSTATE_a[1] >
      localP->Switch_Threshold_l) {
    rtb_UnaryMinus2_idx_0 = AdasPlantModel0_P->PlntDiffrntlEff;
  } else {
    rtb_UnaryMinus2_idx_0 = localP->Constant_Value_f4;
  }

  /* SignalConversion generated from: '<S555>/ SFunction ' incorporates:
   *  Constant: '<S570>/Constant'
   *  Constant: '<S571>/Constant1'
   *  MATLAB Function: '<S552>/Open Differential'
   *  Product: '<S565>/Product4'
   *  Product: '<S570>/Product3'
   *  Product: '<S570>/Product5'
   *  Sum: '<S570>/Subtract1'
   *  Sum: '<S571>/Subtract'
   *  Switch: '<S565>/Switch'
   *  UnaryMinus: '<S586>/Unary Minus'
   */
  rtb_IntegratorSecondOrderLimite[2] = ((localP->Constant1_Value_o -
    rtb_FrontBiasGain) * localP->Constant_Value_bf + rtb_UnaryMinus2_idx_0 *
    rtb_FrontBiasGain) * -rtb_DischrgCurrLmt;

  /* MATLAB Function: '<S552>/Open Differential' incorporates:
   *  Constant: '<S552>/Jd'
   *  Constant: '<S552>/Jw1'
   *  Constant: '<S552>/Jw3'
   *  Constant: '<S552>/Ndiff2'
   *  Constant: '<S552>/bd'
   *  Constant: '<S552>/bw1'
   *  Constant: '<S552>/bw2'
   *  Integrator: '<S552>/Integrator'
   */
  if (localP->OpenDifferential_shaftSwitchMas == 1.0) {
    AdasPlantModel0_automldiffopen(rtb_IntegratorSecondOrderLimite,
      AdasPlantModel0_P->PlntDiffrntlAxl1Damp,
      AdasPlantModel0_P->PlntDiffrntlCarrDamp,
      AdasPlantModel0_P->PlntDiffrntlAxl2Damp,
      AdasPlantModel0_P->PlntDiffrntlRatio, 1.0,
      AdasPlantModel0_P->PlntDiffrntlCarrInertia,
      AdasPlantModel0_P->PlntDiffrntlAxl1Inertia,
      AdasPlantModel0_P->PlntDiffrntlAxl2Inertia, localX->Integrator_CSTATE_a,
      rtb_ubvbwb, localB->xdot_m);
  } else {
    AdasPlantModel0_automldiffopen(rtb_IntegratorSecondOrderLimite,
      AdasPlantModel0_P->PlntDiffrntlAxl1Damp,
      AdasPlantModel0_P->PlntDiffrntlCarrDamp,
      AdasPlantModel0_P->PlntDiffrntlAxl2Damp,
      AdasPlantModel0_P->PlntDiffrntlRatio, 0.0,
      AdasPlantModel0_P->PlntDiffrntlCarrInertia,
      AdasPlantModel0_P->PlntDiffrntlAxl1Inertia,
      AdasPlantModel0_P->PlntDiffrntlAxl2Inertia, localX->Integrator_CSTATE_a,
      rtb_ubvbwb, localB->xdot_m);
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S559>/Switch1' incorporates:
     *  Constant: '<S559>/Constant'
     */
    if (localP->Constant_Value_a > localP->Switch1_Threshold_f) {
      /* Switch: '<S559>/Switch1' incorporates:
       *  Constant: '<S559>/Constant6'
       */
      localB->diffDir_h = localP->Constant6_Value_cd;
    } else {
      /* Switch: '<S559>/Switch1' incorporates:
       *  Constant: '<S559>/Constant6'
       *  UnaryMinus: '<S559>/Unary Minus'
       */
      localB->diffDir_h = -localP->Constant6_Value_cd;
    }

    /* End of Switch: '<S559>/Switch1' */
  }

  /* Sum: '<S578>/Subtract' incorporates:
   *  Integrator: '<S552>/Integrator'
   *  UnaryMinus: '<S556>/Unary Minus1'
   */
  localB->Subtract_p = -localX->Integrator_CSTATE_a[0] - rty_VehFdbk_c[0];

  /* Switch: '<S579>/Switch' */
  if (!(localB->Memory != 0.0)) {
    rtb_BattPackVolt = localB->domega_o;
  }

  /* Product: '<S579>/Product' incorporates:
   *  Constant: '<S578>/omega_c'
   *  Sum: '<S579>/Sum'
   *  Switch: '<S579>/Switch'
   */
  localB->Product_f = (localB->Subtract_p - rtb_BattPackVolt) *
    AdasPlantModel0_P->PlntDriveshftDampCutoffFreq;

  /* Sum: '<S586>/Subtract' incorporates:
   *  Integrator: '<S552>/Integrator'
   *  UnaryMinus: '<S556>/Unary Minus1'
   */
  localB->Subtract_f = -localX->Integrator_CSTATE_a[1] - rty_VehFdbk_c[1];

  /* Switch: '<S587>/Switch' */
  if (!(localB->Memory_a != 0.0)) {
    rtb_SOC_CC = localB->domega_o_o;
  }

  /* Product: '<S587>/Product' incorporates:
   *  Constant: '<S586>/omega_c'
   *  Sum: '<S587>/Sum'
   *  Switch: '<S587>/Switch'
   */
  localB->Product_e = (localB->Subtract_f - rtb_SOC_CC) *
    AdasPlantModel0_P->PlntDriveshftDampCutoffFreq;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S599>/Constant1' */
    localB->Cltch1State = localP->Constant1_Value_n;

    /* Constant: '<S599>/Constant2' */
    localB->Cltch2State = localP->Constant2_Value_p2;

    /* Constant: '<S620>/Constant' */
    localB->TransGear = localP->Constant_Value_d5;

    /* Constant: '<S620>/Constant1' */
    localB->EngTrq = localP->Constant1_Value_em;

    /* Constant: '<S620>/Constant10' */
    localB->PwrEffLoss = localP->Constant10_Value;

    /* Constant: '<S620>/Constant11' */
    localB->PwrDampLoss = localP->Constant11_Value;

    /* Constant: '<S620>/Constant12' */
    localB->PwrStoredTrans = localP->Constant12_Value;

    /* Constant: '<S620>/Constant2' */
    localB->EngSpd = localP->Constant2_Value_n;

    /* Constant: '<S620>/Constant3' */
    localB->DiffTrq = localP->Constant3_Value_h;

    /* Constant: '<S620>/Constant4' */
    localB->DiffSpd = localP->Constant4_Value_j;

    /* Constant: '<S620>/Constant5' */
    localB->TransSpdRatio = localP->Constant5_Value;

    /* Constant: '<S620>/Constant6' */
    localB->TransEta = localP->Constant6_Value_d;

    /* Constant: '<S620>/Constant7' */
    localB->TransGearCmd = localP->Constant7_Value;

    /* Constant: '<S620>/Constant8' */
    localB->PwrEng = localP->Constant8_Value_e;

    /* Constant: '<S620>/Constant9' */
    localB->PwrDiffrntl = localP->Constant9_Value;
  }

  /* Sum: '<S600>/Subtract' */
  localB->Subtract_d = localB->Spd - localB->SumofElements_m;

  /* Switch: '<S601>/Switch' incorporates:
   *  Integrator: '<S601>/Integrator'
   */
  if (localB->Memory_l != 0.0) {
    rtb_UnaryMinus2_idx_0 = localX->Integrator_CSTATE_d;
  } else {
    rtb_UnaryMinus2_idx_0 = localB->domega_o_b;
  }

  /* Product: '<S601>/Product' incorporates:
   *  Constant: '<S600>/omega_c'
   *  Sum: '<S601>/Sum'
   *  Switch: '<S601>/Switch'
   */
  localB->Product_p = (localB->Subtract_d - rtb_UnaryMinus2_idx_0) *
    AdasPlantModel0_P->PlntDriveshftDampCutoffFreq;

  /* TransferFcn: '<S657>/Motor Coupling Dynamics' */
  localB->EMTrq = 0.0;
  localB->EMTrq += localP->MotorCouplingDynamics_C *
    localX->MotorCouplingDynamics_CSTATE;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S611>/Switch' incorporates:
     *  Constant: '<S608>/J'
     *  Constant: '<S618>/Constant'
     *  Constant: '<S619>/Constant'
     *  Logic: '<S611>/Logical Operator'
     *  RelationalOperator: '<S618>/Compare'
     *  RelationalOperator: '<S619>/Compare'
     */
    if ((AdasPlantModel0_P->PlntEM1RotInertia >=
         -localP->div0protectabspoly_thresh) &&
        (AdasPlantModel0_P->PlntEM1RotInertia <=
         localP->div0protectabspoly_thresh)) {
      /* Switch: '<S611>/Switch' incorporates:
       *  Fcn: '<S611>/Fcn'
       */
      localB->Switch_k = 2.0E-6 / (3.0 - rt_powd_snf
        (AdasPlantModel0_P->PlntEM1RotInertia / 1.0e-6, 2.0));
    } else {
      /* Switch: '<S611>/Switch' incorporates:
       *  Abs: '<S611>/Abs'
       */
      localB->Switch_k = std::abs(AdasPlantModel0_P->PlntEM1RotInertia);
    }

    /* End of Switch: '<S611>/Switch' */

    /* Gain: '<S643>/Gain2' incorporates:
     *  Constant: '<S643>/Constant1'
     */
    localB->Gain2_c = AdasPlantModel0_P->PlntDCDCTimeCnst *
      AdasPlantModel0_P->PlntDCDCVoltInit;
  }

  /* Product: '<S609>/Divide' incorporates:
   *  Gain: '<S609>/Gain2'
   *  Sum: '<S609>/Subtract'
   *  UnaryMinus: '<S600>/Unary Minus'
   */
  localB->Divide_fp = ((localB->EMTrq - lam_muy_prime_idx_3) +
                       -AdasPlantModel0_P->PlntEM1RotDamp * localB->Spd) /
    localB->Switch_k;

  /* Integrator: '<S643>/Integrator' */
  if (localDW->Integrator_IWORK_fi != 0) {
    localX->Integrator_CSTATE_o = localB->Gain2_c;
  }

  /* Gain: '<S643>/Gain1' incorporates:
   *  Integrator: '<S643>/Integrator'
   */
  rtb_Divide_pl = 1.0 / AdasPlantModel0_P->PlntDCDCTimeCnst *
    localX->Integrator_CSTATE_o;

  /* Lookup_n-D: '<S665>/Max Torque Limit' incorporates:
   *  Integrator: '<S609>/Integrator'
   */
  lam_muy_prime_idx_3 = look1_binlcapw(localB->Spd,
    localP->MaxTorqueLimit_bp01Data, localP->MaxTorqueLimit_tableData, 26U);

  /* Gain: '<S665>/Gain1' incorporates:
   *  Integrator: '<S665>/Integrator'
   */
  rtb_Gain1_g0 = 1.0 / AdasPlantModel0_P->PlntEM1TimeCnst *
    localX->Integrator_CSTATE_ky;

  /* Product: '<S665>/Divide2' incorporates:
   *  Lookup_n-D: '<S665>/Interpolated zero-crossing'
   *  Product: '<S665>/Product'
   */
  localB->Divide2 = look1_binlcpw(1.0 / lam_muy_prime_idx_3 * rtb_Gain1_g0,
    localP->Interpolatedzerocrossing_bp01Da,
    localP->Interpolatedzerocrossing_tableD, 1U) * lam_muy_prime_idx_3;

  /* Saturate: '<S662>/Saturation' */
  if (rtb_Divide_pl > localP->Saturation_UpperSat_a) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_UpperSat_a;
  } else if (rtb_Divide_pl < localP->Saturation_LowerSat_d3) {
    rtb_UnaryMinus2_idx_0 = localP->Saturation_LowerSat_d3;
  } else {
    rtb_UnaryMinus2_idx_0 = rtb_Divide_pl;
  }

  /* Product: '<S662>/Divide' incorporates:
   *  Integrator: '<S609>/Integrator'
   *  Lookup_n-D: '<S664>/2-D Lookup Table'
   *  Product: '<S664>/Product'
   *  Product: '<S665>/Divide2'
   *  Saturate: '<S662>/Saturation'
   *  Sum: '<S662>/Add'
   */
  rtb_Sum4_g = (localB->Spd * localB->Divide2 + look2_binlcapw(localB->Spd,
    localB->Divide2, localP->uDLookupTable_bp01Data,
    localP->uDLookupTable_bp02Data, localP->uDLookupTable_tableData,
    localP->uDLookupTable_maxIndex, 27U)) / rtb_UnaryMinus2_idx_0;

  /* Product: '<S645>/Product' incorporates:
   *  Product: '<S657>/Product'
   */
  rtb_BattPackVolt = rtb_Divide_pl * rtb_Sum4_g;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S645>/Subtract' incorporates:
     *  Constant: '<S645>/Constant'
     *  Constant: '<S645>/Constant1'
     */
    rtb_UnitConversion_mr_idx_0 = localP->Constant1_Value_b -
      AdasPlantModel0_P->PlntDCDCEff;

    /* Product: '<S645>/Divide' incorporates:
     *  Constant: '<S645>/Constant'
     */
    localB->Divide_o = rtb_UnitConversion_mr_idx_0 /
      AdasPlantModel0_P->PlntDCDCEff;

    /* Product: '<S645>/Divide1' incorporates:
     *  Constant: '<S645>/Constant2'
     */
    localB->Divide1 = rtb_UnitConversion_mr_idx_0 / localP->Constant2_Value_n1;

    /* UnaryMinus: '<S650>/Unary Minus' incorporates:
     *  Constant: '<S650>/Constant'
     */
    localB->UnaryMinus_g = -localP->Constant_Value_cg;
  }

  /* Switch: '<S645>/Switch' incorporates:
   *  Abs: '<S645>/Abs'
   *  Product: '<S645>/Product'
   *  Product: '<S645>/Product1'
   *  Product: '<S645>/Product2'
   */
  if (rtb_BattPackVolt >= localP->Switch_Threshold_g2) {
    rtb_UnaryMinus2_idx_0 = rtb_BattPackVolt * localB->Divide_o;
  } else {
    rtb_UnaryMinus2_idx_0 = std::abs(rtb_BattPackVolt) * localB->Divide1;
  }

  /* Switch: '<S650>/Switch' incorporates:
   *  Constant: '<S651>/Constant'
   *  Constant: '<S652>/Constant'
   *  Fcn: '<S650>/Fcn'
   *  Logic: '<S650>/Logical Operator'
   *  Product: '<S650>/Product'
   *  RelationalOperator: '<S651>/Compare'
   *  RelationalOperator: '<S652>/Compare'
   *  Switch: '<S650>/Switch1'
   */
  if ((localB->Gain1 >= -localP->div0protectpoly_thresh_g) && (localB->Gain1 <=
       localP->div0protectpoly_thresh_g)) {
    /* Switch: '<S650>/Switch1' incorporates:
     *  Constant: '<S650>/Constant'
     */
    if (localB->Gain1 >= localP->Switch1_Threshold_n) {
      rtb_Integrator1_p = localP->Constant_Value_cg;
    } else {
      rtb_Integrator1_p = localB->UnaryMinus_g;
    }

    lam_muy_prime_idx_3 = 0.002 / (3.0 - rt_powd_snf(localB->Gain1 / 0.001, 2.0))
      * rtb_Integrator1_p;
  } else {
    lam_muy_prime_idx_3 = localB->Gain1;
  }

  /* End of Switch: '<S650>/Switch' */

  /* Product: '<S644>/Divide' incorporates:
   *  Product: '<S645>/Product'
   *  Sum: '<S644>/Add'
   *  Switch: '<S645>/Switch'
   */
  localB->Divide_pf = (rtb_BattPackVolt + rtb_UnaryMinus2_idx_0) /
    lam_muy_prime_idx_3;

  /* Gain: '<S632>/Gain1' */
  localB->Gain1_g = -1.0 / (AdasPlantModel0_P->PlntBattNumCellPar * 3600.0) *
    localB->Divide_pf;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S632>/Switch' incorporates:
     *  Constant: '<S628>/Constant1'
     */
    if (AdasPlantModel0_P->PlntBattCapInit > AdasPlantModel0_P->PlntBattChrgMax)
    {
      /* Switch: '<S632>/Switch' incorporates:
       *  Constant: '<S632>/Constant1'
       */
      localB->Switch_d = AdasPlantModel0_P->PlntBattChrgMax;
    } else {
      /* Switch: '<S632>/Switch' */
      localB->Switch_d = AdasPlantModel0_P->PlntBattCapInit;
    }

    /* End of Switch: '<S632>/Switch' */
  }

  /* Integrator: '<S632>/Integrator Limited' */
  /* Limited  Integrator  */
  if (localDW->IntegratorLimited_IWORK != 0) {
    localX->IntegratorLimited_CSTATE = localB->Switch_d;
  }

  if (localX->IntegratorLimited_CSTATE >= AdasPlantModel0_P->PlntBattChrgMax) {
    localX->IntegratorLimited_CSTATE = AdasPlantModel0_P->PlntBattChrgMax;
  } else if (localX->IntegratorLimited_CSTATE <=
             localP->IntegratorLimited_LowerSat) {
    localX->IntegratorLimited_CSTATE = localP->IntegratorLimited_LowerSat;
  }

  /* Product: '<S633>/Divide' incorporates:
   *  Constant: '<S633>/Constant1'
   *  Integrator: '<S632>/Integrator Limited'
   */
  lam_muy_prime_idx_3 = localX->IntegratorLimited_CSTATE /
    AdasPlantModel0_P->PlntBattChrgMax;

  /* Sum: '<S630>/Sum' incorporates:
   *  Constant: '<S4>/Temp_degK'
   *  Gain: '<S634>/Gain1'
   *  Gain: '<S634>/Gain2'
   *  Lookup_n-D: '<S634>/Em'
   *  Lookup_n-D: '<S634>/R'
   *  Product: '<S634>/Product'
   *  Product: '<S643>/Divide'
   *  Sum: '<S634>/Subtract'
   */
  localB->Sum_f = (look1_binlcapw(lam_muy_prime_idx_3,
    AdasPlantModel0_P->PlntBattVoltSocBpt,
    AdasPlantModel0_P->PlntBattOpenCirctVolt, 100U) - 1.0 /
                   AdasPlantModel0_P->PlntBattNumCellPar * localB->Divide_pf *
                   look2_binlcapw(AdasPlantModel0_P->EnvAirTemp,
    lam_muy_prime_idx_3, AdasPlantModel0_P->PlntBattTempBpt,
    AdasPlantModel0_P->PlntBattSocBpt, AdasPlantModel0_P->PlntBattIntrnRes,
    localP->R_maxIndex, 7U)) * AdasPlantModel0_P->PlntBattNumCellSer -
    localB->Gain1;

  /* Gain: '<S625>/SOC Ratio to %' */
  localB->SOCRatioto = localP->SOCRatioto_Gain * lam_muy_prime_idx_3;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S639>/Sum' incorporates:
     *  Constant: '<S4>/Temp_degK'
     *  Constant: '<S639>/Constant1'
     */
    rtb_Switch_p_idx_0 = AdasPlantModel0_P->EnvAirTemp -
      localP->Constant1_Value_lb;

    /* DataTypeConversion: '<S627>/Data Type Conversion3' incorporates:
     *  Gain: '<S627>/Gain1'
     */
    for (i = 0; i < 96; i++) {
      rtb_CellTemperatures_i[i] = static_cast<real32_T>(localP->Gain1_Gain_a3[i]
        * rtb_Switch_p_idx_0);
    }

    /* End of DataTypeConversion: '<S627>/Data Type Conversion3' */

    /* DataTypeConversion: '<S627>/Data Type Conversion4' incorporates:
     *  Constant: '<S627>/Constant1'
     */
    rtb_VoutChgr = static_cast<real32_T>(localP->Constant1_Value_l1);
  }

  /* DataTypeConversion: '<S627>/Data Type Conversion2' incorporates:
   *  Gain: '<S627>/Gain2'
   */
  localB->PackCurrent_i = static_cast<real32_T>(localP->Gain2_Gain_l *
    localB->Divide_pf);

  /* DataTypeConversion: '<S627>/Data Type Conversion5' */
  localB->VoutInvtr_k = static_cast<real32_T>(localB->Gain1);
  for (i = 0; i < 96; i++) {
    /* DataTypeConversion: '<S627>/Data Type Conversion6' incorporates:
     *  Gain: '<S627>/Gain'
     */
    localB->CellVoltages_j[i] = static_cast<real32_T>(1.0 /
      AdasPlantModel0_P->PlntBattNumCellSer * localB->Gain1);
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
      std::memcpy(&localDW->RateTransition_1_Buffer[0], &localB->CellVoltages_j
                  [0], 96U * sizeof(real32_T));
    }

    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
      localDW->RateTransition_3_Buffer = localB->PackCurrent_i;
    }
  }

  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S627>/Rate Transition' */
    std::memcpy(&localB->CellVoltages_e[0], &localDW->RateTransition_1_Buffer[0],
                96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0)) {
    std::memcpy(&localDW->RateTransition_4_Buffer[0], &rtb_CellTemperatures_i[0],
                96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S627>/Rate Transition' */
    localB->PackCurrent_j = localDW->RateTransition_3_Buffer;
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0)) {
    localDW->RateTransition_5_Buffer = rtb_VoutChgr;
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S627>/Rate Transition' */
    std::memcpy(&localB->CellTemperatures[0], &localDW->RateTransition_4_Buffer
                [0], 96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
       (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0)) {
    localDW->RateTransition_6_Buffer = localB->VoutInvtr_k;
  }

  /* RateTransition generated from: '<S627>/Rate Transition' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S627>/Rate Transition' */
    localB->VoutChgr_k = localDW->RateTransition_5_Buffer;

    /* RateTransition generated from: '<S627>/Rate Transition' */
    localB->VoutInvtr_km = localDW->RateTransition_6_Buffer;
  }

  /* Switch: '<S647>/Switch' incorporates:
   *  Abs: '<S647>/Abs'
   *  Constant: '<S648>/Constant'
   *  Constant: '<S649>/Constant'
   *  Fcn: '<S647>/Fcn'
   *  Logic: '<S647>/Logical Operator'
   *  RelationalOperator: '<S648>/Compare'
   *  RelationalOperator: '<S649>/Compare'
   */
  if ((rtb_Sum4_g >= -localP->div0protectabspoly_thresh_o) && (rtb_Sum4_g <=
       localP->div0protectabspoly_thresh_o)) {
    lam_muy_prime_idx_3 = 0.002 / (3.0 - rt_powd_snf(rtb_Sum4_g / 0.001, 2.0));
  } else {
    lam_muy_prime_idx_3 = std::abs(rtb_Sum4_g);
  }

  /* End of Switch: '<S647>/Switch' */

  /* Product: '<S643>/Divide' incorporates:
   *  Constant: '<S643>/MaxLdPwr'
   */
  lam_muy_prime_idx_3 = AdasPlantModel0_P->PlntDCDCPwrLmt / lam_muy_prime_idx_3;
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S643>/Switch' incorporates:
     *  Constant: '<S621>/Constant3'
     */
    if (AdasPlantModel0_P->PlntDCDCVoltInit >= localP->Switch_Threshold_kz) {
      /* Switch: '<S643>/Switch' */
      localB->Switch_m = AdasPlantModel0_P->PlntDCDCVoltInit;
    } else {
      /* Switch: '<S643>/Switch' incorporates:
       *  Constant: '<S643>/Constant'
       */
      localB->Switch_m = localP->Constant_Value_m;
    }

    /* End of Switch: '<S643>/Switch' */

    /* Constant: '<S621>/Constant' */
    localB->FuelCellVolt = localP->Constant_Value_kc;

    /* Constant: '<S621>/Constant1' */
    localB->FuelCellCurr = localP->Constant1_Value_en;

    /* Constant: '<S621>/Constant2' */
    localB->H2Flw = localP->Constant2_Value_n13;

    /* Constant: '<S670>/Bsfc' */
    localB->Bsfc = localP->Bsfc_Value;

    /* Constant: '<S670>/CrkAng' */
    localB->CrkAng = localP->CrkAng_Value;

    /* Constant: '<S670>/CylPrs' */
    localB->CylPrs = localP->CylPrs_Value;

    /* Constant: '<S670>/EgrVlvAreaPct' */
    localB->EgrVlvAreaPct = localP->EgrVlvAreaPct_Value;

    /* Constant: '<S670>/EngSpd' */
    localB->EngSpd_b = localP->EngSpd_Value;

    /* Constant: '<S670>/EngTrq' */
    localB->EngTrq_c = localP->EngTrq_Value;

    /* Constant: '<S670>/EngTrqCrk' */
    localB->EngTrqCrk = localP->EngTrqCrk_Value;

    /* Constant: '<S670>/ExhCamPhase' */
    localB->ExhCamPhase = localP->ExhCamPhase_Value;

    /* Constant: '<S670>/ExhManGasTemp' */
    localB->ExhManGasTemp = localP->ExhManGasTemp_Value;

    /* Constant: '<S670>/IntkCamPhase' */
    localB->IntkCamPhase = localP->IntkCamPhase_Value;

    /* Constant: '<S670>/IntkGasMassFlw' */
    localB->IntkGasMassFlw = localP->IntkGasMassFlw_Value;

    /* Constant: '<S670>/IntkSwirlVlvPos' */
    localB->IntkSwirlVlvPos = localP->IntkSwirlVlvPos_Value;

    /* Constant: '<S670>/IntkVlvLift' */
    localB->IntkVlvLift = localP->IntkVlvLift_Value;

    /* Constant: '<S670>/Map' */
    localB->Map = localP->Map_Value;

    /* Constant: '<S670>/Map1' */
    localB->Map1 = localP->Map1_Value;

    /* Constant: '<S670>/Map2' */
    localB->Map2 = localP->Map2_Value;

    /* Constant: '<S670>/Map3' */
    localB->Map3 = localP->Map3_Value;

    /* Constant: '<S670>/Map4' */
    localB->Map4 = localP->Map4_Value;

    /* Constant: '<S670>/Map5' */
    localB->Map5 = localP->Map5_Value;

    /* Constant: '<S670>/Map6' */
    localB->Map6 = localP->Map6_Value;

    /* Constant: '<S670>/Mat' */
    localB->Mat = localP->Mat_Value;

    /* Constant: '<S670>/Mat1' */
    localB->Mat1 = localP->Mat1_Value;

    /* Constant: '<S670>/Mat2' */
    localB->Mat2 = localP->Mat2_Value;

    /* Constant: '<S670>/Mat3' */
    localB->Mat3 = localP->Mat3_Value;

    /* Constant: '<S670>/NrmlzdAirChrg' */
    localB->NrmlzdAirChrg = localP->NrmlzdAirChrg_Value;

    /* Product: '<S670>/Product' incorporates:
     *  Constant: '<S670>/ClsdLpFuelMult'
     *  Constant: '<S670>/FuelMassFlw'
     */
    localB->Product_a = localP->FuelMassFlw_Value * localP->ClsdLpFuelMult_Value;

    /* Product: '<S670>/Product1' incorporates:
     *  Constant: '<S670>/Afr'
     *  Constant: '<S670>/ClsdLpFuelMult'
     */
    localB->Product1_a = localP->Afr_Value / localP->ClsdLpFuelMult_Value;

    /* Product: '<S670>/Product2' incorporates:
     *  Constant: '<S670>/ClsdLpFuelMult'
     *  Constant: '<S670>/FuelVolFlw'
     */
    localB->Product2_e = localP->FuelVolFlw_Value * localP->ClsdLpFuelMult_Value;

    /* Constant: '<S670>/TPCO' */
    localB->TPCO = localP->TPCO_Value;

    /* Constant: '<S670>/TPCO2' */
    localB->TPCO2 = localP->TPCO2_Value;

    /* Constant: '<S670>/TPHC' */
    localB->TPHC = localP->TPHC_Value;

    /* Constant: '<S670>/TPNOx' */
    localB->TPNOx = localP->TPNOx_Value;

    /* Constant: '<S670>/ThrPosPct' */
    localB->ThrPosPct = localP->ThrPosPct_Value;

    /* Constant: '<S670>/TurboRackPos' */
    localB->TurboRackPos = localP->TurboRackPos_Value;

    /* Constant: '<S670>/TurboSpd' */
    localB->TurboSpd = localP->TurboSpd_Value;

    /* Constant: '<S670>/TurboSpd1' */
    localB->TurboSpd1 = localP->TurboSpd1_Value;

    /* Constant: '<S670>/TurboSpd2' */
    localB->TurboSpd2 = localP->TurboSpd2_Value;

    /* Constant: '<S670>/TurboSpd3' */
    localB->TurboSpd3 = localP->TurboSpd3_Value;

    /* Constant: '<S670>/VarCompRatioPos' */
    localB->VarCompRatioPos = localP->VarCompRatioPos_Value;

    /* Constant: '<S670>/VarIntkRunLen' */
    localB->VarIntkRunLen = localP->VarIntkRunLen_Value;

    /* Constant: '<S670>/WgAreaPct' */
    localB->WgAreaPct = localP->WgAreaPct_Value;
  }

  /* Sum: '<S643>/Sum' incorporates:
   *  MinMax: '<S643>/MinMax'
   */
  localB->Sum_m = std::fmin(lam_muy_prime_idx_3, localB->Switch_m) -
    rtb_Divide_pl;

  /* Sum: '<S665>/Sum' */
  localB->Sum_e = localB->EMTrqCmd - rtb_Gain1_g0;

  /* Product: '<S657>/Product' */
  localB->EMPwrElec = rtb_BattPackVolt;

  /* Product: '<S621>/Product2' */
  localB->BattPwr = localB->Divide_pf * localB->Gain1;

  /* DeadZone: '<S95>/Dead Zone3' */
  if (rtb_min > localP->DeadZone3_End) {
    /* DeadZone: '<S95>/Dead Zone3' */
    localB->DeadZone3 = rtb_min - localP->DeadZone3_End;
  } else if (rtb_min >= localP->DeadZone3_Start) {
    /* DeadZone: '<S95>/Dead Zone3' */
    localB->DeadZone3 = 0.0;
  } else {
    /* DeadZone: '<S95>/Dead Zone3' */
    localB->DeadZone3 = rtb_min - localP->DeadZone3_Start;
  }

  /* End of DeadZone: '<S95>/Dead Zone3' */

  /* Gain: '<S683>/2*zeta * wn' */
  /* Unit Conversion - from: gn to: m/s^2
     Expression: output = (9.80665*input) + (0) */
  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  rtb_Product_py = 2.0 * localP->SecondorderDynamics_zn *
    localP->SecondorderDynamics_wn;

  /* UnitConversion: '<S673>/Unit Conversion' */
  rtb_ubvbwb[0] = 9.8066500000000012 * localB->UnitConversion3[0];

  /* Gain: '<S683>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited'
   */
  rtb_sincos_o1[0] = rtb_Product_py * localX->IntegratorSecondOrderLimited_CS[3];

  /* UnitConversion: '<S673>/Unit Conversion' */
  rtb_ubvbwb[1] = 9.8066500000000012 * localB->UnitConversion3[1];

  /* Gain: '<S683>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited'
   */
  rtb_sincos_o1[1] = rtb_Product_py * localX->IntegratorSecondOrderLimited_CS[4];

  /* UnitConversion: '<S673>/Unit Conversion' */
  rtb_ubvbwb[2] = 9.8066500000000012 * localB->UnitConversion3[2];

  /* Gain: '<S683>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited'
   */
  rtb_sincos_o1[2] = rtb_Product_py * localX->IntegratorSecondOrderLimited_CS[5];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S676>/Zero-Order Hold2' incorporates:
     *  Constant: '<S673>/Constant1'
     *  UnaryMinus: '<S674>/Unary Minus'
     */
    localB->ZeroOrderHold2[0] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kq[0];

    /* Gain: '<S676>/Gain' incorporates:
     *  Constant: '<S673>/Constant'
     *  Constant: '<S676>/wl_ins'
     *  Gain: '<S676>/Zero-Order Hold4'
     *  Sum: '<S676>/Sum7'
     */
    localB->Gain_d[0] = (localP->ZeroOrderHold4_Gain * localP->
                         Constant_Value_ha[0] -
                         localP->ThreeaxisInertialMeasurementU_h[0]) *
      localP->Gain_Gain_ij[0];

    /* Gain: '<S676>/Zero-Order Hold2' incorporates:
     *  Constant: '<S673>/Constant1'
     *  UnaryMinus: '<S674>/Unary Minus'
     */
    localB->ZeroOrderHold2[1] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kq[1];

    /* Gain: '<S676>/Gain' incorporates:
     *  Constant: '<S673>/Constant'
     *  Constant: '<S676>/wl_ins'
     *  Gain: '<S676>/Zero-Order Hold4'
     *  Sum: '<S676>/Sum7'
     */
    localB->Gain_d[1] = (localP->ZeroOrderHold4_Gain * localP->
                         Constant_Value_ha[1] -
                         localP->ThreeaxisInertialMeasurementU_h[1]) *
      localP->Gain_Gain_ij[1];

    /* Gain: '<S676>/Zero-Order Hold2' incorporates:
     *  Constant: '<S673>/Constant1'
     *  UnaryMinus: '<S674>/Unary Minus'
     */
    localB->ZeroOrderHold2[2] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kq[2];

    /* Gain: '<S676>/Gain' incorporates:
     *  Constant: '<S673>/Constant'
     *  Constant: '<S676>/wl_ins'
     *  Gain: '<S676>/Zero-Order Hold4'
     *  Sum: '<S676>/Sum7'
     */
    localB->Gain_d[2] = (localP->ZeroOrderHold4_Gain * localP->
                         Constant_Value_ha[2] -
                         localP->ThreeaxisInertialMeasurementU_h[2]) *
      localP->Gain_Gain_ij[2];
  }

  /* Switch: '<S678>/Switch1' incorporates:
   *  Constant: '<S676>/Measurement bias'
   *  Constant: '<S676>/Scale factors & Cross-coupling  errors'
   *  Constant: '<S678>/0'
   *  Constant: '<S678>/Constant'
   *  Product: '<S676>/Product'
   *  Sum: '<S676>/Sum4'
   */
  if (localP->Constant_Value_k1 >= localP->Switch1_Threshold_a) {
    /* Gain: '<S676>/Zero-Order Hold3' */
    rtb_BattPackVolt = localP->ZeroOrderHold3_Gain * localB->UnitConversion2[0];

    /* Gain: '<S676>/Zero-Order Hold' */
    rtb_SOC_CC = localP->ZeroOrderHold_Gain * localB->pqr[0];

    /* Gain: '<S676>/Zero-Order Hold3' */
    rtb_DischrgCurrLmt = localP->ZeroOrderHold3_Gain * localB->UnitConversion2[1];

    /* Gain: '<S676>/Zero-Order Hold' */
    rtb_ChrgCurrLmt = localP->ZeroOrderHold_Gain * localB->pqr[1];

    /* Gain: '<S676>/Zero-Order Hold3' */
    rtb_min = localP->ZeroOrderHold3_Gain * localB->UnitConversion2[2];

    /* Gain: '<S676>/Zero-Order Hold' */
    rtb_UnitConversion_mr_idx_1 = localP->ZeroOrderHold_Gain * localB->pqr[2];

    /* Sum: '<S685>/Sum' incorporates:
     *  Product: '<S688>/i x j'
     *  Product: '<S688>/j x k'
     *  Product: '<S688>/k x i'
     *  Product: '<S689>/i x k'
     *  Product: '<S689>/j x i'
     *  Product: '<S689>/k x j'
     */
    rtb_VectorConcatenate_n[0] = rtb_ChrgCurrLmt * localB->Gain_d[2] -
      localB->Gain_d[1] * rtb_UnitConversion_mr_idx_1;
    rtb_VectorConcatenate_n[1] = localB->Gain_d[0] * rtb_UnitConversion_mr_idx_1
      - rtb_SOC_CC * localB->Gain_d[2];
    rtb_VectorConcatenate_n[2] = rtb_SOC_CC * localB->Gain_d[1] - localB->
      Gain_d[0] * rtb_ChrgCurrLmt;

    /* Sum: '<S676>/Sum' incorporates:
     *  Gain: '<S676>/Zero-Order Hold1'
     *  Product: '<S686>/i x j'
     *  Product: '<S686>/j x k'
     *  Product: '<S686>/k x i'
     *  Product: '<S687>/i x k'
     *  Product: '<S687>/j x i'
     *  Product: '<S687>/k x j'
     *  Product: '<S690>/i x j'
     *  Product: '<S690>/j x k'
     *  Product: '<S690>/k x i'
     *  Product: '<S691>/i x k'
     *  Product: '<S691>/j x i'
     *  Product: '<S691>/k x j'
     *  Sum: '<S681>/Sum'
     *  Sum: '<S684>/Sum'
     */
    rtb_Switch_p_idx_0 = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[0] -
      localB->ZeroOrderHold2[0]) + (rtb_ChrgCurrLmt * rtb_VectorConcatenate_n[2]
      - rtb_VectorConcatenate_n[1] * rtb_UnitConversion_mr_idx_1)) +
      (rtb_DischrgCurrLmt * localB->Gain_d[2] - localB->Gain_d[1] * rtb_min);
    rtb_min = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[1] -
                localB->ZeroOrderHold2[1]) + (rtb_VectorConcatenate_n[0] *
                rtb_UnitConversion_mr_idx_1 - rtb_SOC_CC *
                rtb_VectorConcatenate_n[2])) + (localB->Gain_d[0] * rtb_min -
      rtb_BattPackVolt * localB->Gain_d[2]);
    rtb_BattPackVolt = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[2] -
                         localB->ZeroOrderHold2[2]) + (rtb_SOC_CC *
      rtb_VectorConcatenate_n[1] - rtb_VectorConcatenate_n[0] * rtb_ChrgCurrLmt))
      + (rtb_BattPackVolt * localB->Gain_d[1] - localB->Gain_d[0] *
         rtb_DischrgCurrLmt);
    for (i = 0; i < 3; i++) {
      rtb_Switch1_h[i] = ((localP->ThreeaxisInertialMeasurementU_j[i + 3] *
                           rtb_min + localP->ThreeaxisInertialMeasurementU_j[i] *
                           rtb_Switch_p_idx_0) +
                          localP->ThreeaxisInertialMeasurementU_j[i + 6] *
                          rtb_BattPackVolt) +
        localP->ThreeaxisInertialMeasurementUni[i];
    }
  } else {
    rtb_Switch1_h[0] = localP->u_Value_g[0];
    rtb_Switch1_h[1] = localP->u_Value_g[1];
    rtb_Switch1_h[2] = localP->u_Value_g[2];
  }

  /* End of Switch: '<S678>/Switch1' */

  /* Gain: '<S683>/wn^2' */
  rtb_Product_py = localP->SecondorderDynamics_wn *
    localP->SecondorderDynamics_wn;

  /* Sum: '<S683>/Sum2' incorporates:
   *  Gain: '<S683>/wn^2'
   *  SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited'
   *  Sum: '<S683>/Sum3'
   */
  localB->Sum2[0] = (rtb_Switch1_h[0] - localX->IntegratorSecondOrderLimited_CS
                     [0]) * rtb_Product_py - rtb_sincos_o1[0];
  localB->Sum2[1] = (rtb_Switch1_h[1] - localX->IntegratorSecondOrderLimited_CS
                     [1]) * rtb_Product_py - rtb_sincos_o1[1];
  localB->Sum2[2] = (rtb_Switch1_h[2] - localX->IntegratorSecondOrderLimited_CS
                     [2]) * rtb_Product_py - rtb_sincos_o1[2];

  /* Gain: '<S695>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
   */
  rtb_Product_py = 2.0 * localP->SecondorderDynamics_zn_e *
    localP->SecondorderDynamics_wn_e;
  rtb_sincos_o1[0] = rtb_Product_py * localX->IntegratorSecondOrderLimited__f[3];
  rtb_sincos_o1[1] = rtb_Product_py * localX->IntegratorSecondOrderLimited__f[4];
  rtb_sincos_o1[2] = rtb_Product_py * localX->IntegratorSecondOrderLimited__f[5];

  /* Switch: '<S692>/Switch1' incorporates:
   *  Constant: '<S677>/Measurement bias'
   *  Constant: '<S677>/Scale factors & Cross-coupling  errors '
   *  Constant: '<S677>/g-sensitive bias'
   *  Constant: '<S692>/0'
   *  Constant: '<S692>/Constant'
   *  Gain: '<S677>/Zero-Order Hold'
   *  Gain: '<S677>/Zero-Order Hold1'
   *  Product: '<S677>/Product'
   *  Product: '<S677>/Product1'
   *  Sum: '<S677>/Sum4'
   *  UnitConversion: '<S675>/Unit Conversion'
   */
  if (localP->Constant_Value_bj >= localP->Switch1_Threshold_ds) {
    /* Gain: '<S677>/Zero-Order Hold' incorporates:
     *  Constant: '<S677>/Scale factors & Cross-coupling  errors '
     *  Product: '<S677>/Product'
     */
    rtb_UnitConversion_mr_idx_3 = localB->pqr[0];
    rtb_UnaryMinus2_idx_0 = localB->pqr[1];
    rtb_Gain1_g0 = localB->pqr[2];
    for (i = 0; i < 3; i++) {
      rtb_Switch1_h[i] = (((localP->ZeroOrderHold_Gain_i *
                            rtb_UnitConversion_mr_idx_3 *
                            localP->ThreeaxisInertialMeasurementU_f[i] +
                            localP->ThreeaxisInertialMeasurementU_f[i + 3] *
                            (localP->ZeroOrderHold_Gain_i *
        rtb_UnaryMinus2_idx_0)) + localP->ThreeaxisInertialMeasurementU_f[i + 6]
                           * (localP->ZeroOrderHold_Gain_i * rtb_Gain1_g0)) +
                          localP->ThreeaxisInertialMeasurementU_n[i]) +
        0.10197162129779282 * rtb_ubvbwb[i] * localP->ZeroOrderHold1_Gain_d *
        localP->ThreeaxisInertialMeasurementU_m[i];
    }
  } else {
    rtb_Switch1_h[0] = localP->u_Value_h2[0];
    rtb_Switch1_h[1] = localP->u_Value_h2[1];
    rtb_Switch1_h[2] = localP->u_Value_h2[2];
  }

  /* End of Switch: '<S692>/Switch1' */

  /* Gain: '<S695>/wn^2' */
  rtb_Product_py = localP->SecondorderDynamics_wn_e *
    localP->SecondorderDynamics_wn_e;

  /* Sum: '<S695>/Sum2' incorporates:
   *  Gain: '<S695>/wn^2'
   *  SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited'
   *  Sum: '<S695>/Sum3'
   */
  localB->Sum2_k[0] = (rtb_Switch1_h[0] -
                       localX->IntegratorSecondOrderLimited__f[0]) *
    rtb_Product_py - rtb_sincos_o1[0];
  localB->Sum2_k[1] = (rtb_Switch1_h[1] -
                       localX->IntegratorSecondOrderLimited__f[1]) *
    rtb_Product_py - rtb_sincos_o1[1];
  localB->Sum2_k[2] = (rtb_Switch1_h[2] -
                       localX->IntegratorSecondOrderLimited__f[2]) *
    rtb_Product_py - rtb_sincos_o1[2];
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S696>/Constant15' */
    localB->Wheels = localP->Constant15_Value;

    /* Constant: '<S696>/Constant1' */
    localB->X = localP->Constant1_Value_g;

    /* Constant: '<S696>/Constant10' */
    localB->Y = localP->Constant10_Value_b;

    /* Constant: '<S696>/Constant11' */
    localB->X_c = localP->Constant11_Value_i;

    /* Constant: '<S696>/Constant12' */
    localB->Y_a = localP->Constant12_Value_c;

    /* Constant: '<S696>/Constant13' */
    localB->X_j = localP->Constant13_Value;

    /* Constant: '<S696>/Constant14' */
    localB->Y_h = localP->Constant14_Value;

    /* Constant: '<S696>/Constant2' */
    localB->Y_j = localP->Constant2_Value_a;

    /* Constant: '<S696>/Constant3' */
    localB->X_o = localP->Constant3_Value_k;

    /* Constant: '<S696>/Constant4' */
    localB->Y_l = localP->Constant4_Value_f;

    /* Constant: '<S696>/Constant5' */
    localB->X_f = localP->Constant5_Value_a;

    /* Constant: '<S696>/Constant6' */
    localB->Y_e = localP->Constant6_Value_nc;

    /* Constant: '<S696>/Constant7' */
    localB->X_k = localP->Constant7_Value_i;

    /* Constant: '<S696>/Constant8' */
    localB->Y_d = localP->Constant8_Value_b;

    /* Constant: '<S696>/Constant9' */
    localB->X_e = localP->Constant9_Value_p;
  }
}

/* Update for atomic system: '<Root>/AdasPlantModel' */
void AdasPlantModel0::AdasPlant_AdasPlantModel_Update
  (B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
   *localDW, P_AdasPlantModel_AdasPlantMod_T *localP)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_c;
  real_T err;
  real_T tol;
  real_T *lastU;
  boolean_T guard1;

  /* Update for RateTransition: '<S21>/Rate Transition18' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    std::memcpy(&localDW->UnitDelay_1_DSTATE[0], &localB->CellVoltages_e[0], 96U
                * sizeof(real32_T));

    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    std::memcpy(&localDW->UnitDelay_4_DSTATE[0], &localB->CellTemperatures[0],
                96U * sizeof(real32_T));

    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    localDW->UnitDelay_2_DSTATE = localB->PackVoltage_i;

    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    localDW->UnitDelay_5_DSTATE = localB->VoutChgr_k;

    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    localDW->UnitDelay_6_DSTATE = localB->VoutInvtr_km;

    /* Update for UnitDelay generated from: '<S25>/Unit Delay' */
    localDW->UnitDelay_3_DSTATE = localB->PackCurrent_j;

    /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localB->Divide_cf;
    if (localDW->DiscreteTimeIntegrator_DSTATE >=
        localP->DiscreteTimeIntegrator_UpperSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_UpperSat;
    } else if (localDW->DiscreteTimeIntegrator_DSTATE <=
               localP->DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_LowerSat;
    }

    /* End of Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
    localDW->RateTransition18_Buffer[static_cast<int32_T>
      (localDW->RateTransition18_ActiveBufIdx == 0)] =
      localB->DataTypeConversion1;
    localDW->RateTransition18_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition18_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S21>/Rate Transition19' */
    localDW->RateTransition19_Buffer[static_cast<int32_T>
      (localDW->RateTransition19_ActiveBufIdx == 0)] =
      localB->DataTypeConversion;
    localDW->RateTransition19_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition19_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S21>/Rate Transition20' */
    localDW->RateTransition20_Buffer[static_cast<int32_T>
      (localDW->RateTransition20_ActiveBufIdx == 0)] =
      localB->DataTypeConversion2;
    localDW->RateTransition20_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition20_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S21>/Rate Transition21' */
    localDW->RateTransition21_Buffer[static_cast<int32_T>
      (localDW->RateTransition21_ActiveBufIdx == 0)] =
      localB->DataTypeConversion3;
    localDW->RateTransition21_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition21_ActiveBufIdx == 0);
  }

  /* End of Update for RateTransition: '<S21>/Rate Transition18' */

  /* Update for Integrator: '<S630>/Integrator' */
  localDW->Integrator_IWORK = 0;

  /* Update for FirstOrderHold: '<S79>/First Order Hold' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    guard1 = false;
    if (!(localDW->Tk == (rtInf))) {
      if ((localB->Switch2 >= -1.0) && (localB->Switch2 <= 1.0)) {
        tol = localP->FirstOrderHold_ErrTol;
      } else if (localB->Switch2 > 1.0) {
        tol = localB->Switch2 * localP->FirstOrderHold_ErrTol;
      } else {
        tol = -(localB->Switch2 * localP->FirstOrderHold_ErrTol);
      }

      err = localB->EMTrqCmd - localB->Switch2;
      if ((err > tol) || (err < -tol)) {
        guard1 = true;
      } else {
        localDW->Mk = (localB->Switch2 - localDW->Uk) / ((&AdasPlantModel0_M)
          ->Timing.t[0] - localDW->Tk);
        localDW->Ck = localB->EMTrqCmd;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (localB->Switch2 != localB->EMTrqCmd) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(&(&AdasPlantModel0_M)
          ->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&AdasPlantModel0_M)->solverInfo, true);
      }

      localDW->Ck = localB->Switch2;
      localDW->Mk = 0.0;
    }

    localDW->Uk = localB->Switch2;
    localDW->Tk = (&AdasPlantModel0_M)->Timing.t[0];

    /* Update for Memory: '<S579>/Memory' incorporates:
     *  Constant: '<S579>/Reset'
     *  FirstOrderHold: '<S79>/First Order Hold'
     */
    localDW->Memory_PreviousInput = localP->Reset_Value;

    /* Update for Memory: '<S587>/Memory' incorporates:
     *  Constant: '<S587>/Reset'
     */
    localDW->Memory_PreviousInput_g = localP->Reset_Value_l;
  }

  /* End of Update for FirstOrderHold: '<S79>/First Order Hold' */

  /* Update for Integrator: '<S579>/Integrator' */
  localDW->Integrator_IWORK_a = 0;

  /* Update for Integrator: '<S587>/Integrator' */
  localDW->Integrator_IWORK_c = 0;

  /* Update for Iterator SubSystem: '<S434>/Unwrap' */
  for (ForEach_itr_c = 0; ForEach_itr_c < 3; ForEach_itr_c++) {
    if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
        (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Memory: '<S439>/Memory1' incorporates:
       *  ForEachSliceSelector generated from: '<S438>/u'
       */
      localDW->CoreSubsys_b[ForEach_itr_c].Memory1_PreviousInput =
        localB->phithetapsi[ForEach_itr_c];
    }
  }

  /* End of Update for SubSystem: '<S434>/Unwrap' */

  /* Update for Backlash: '<S117>/Backlash' */
  localDW->PrevY = localB->Backlash;

  /* Update for Derivative: '<S131>/Derivative' */
  if (localDW->TimeStampA == (rtInf)) {
    localDW->TimeStampA = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA;
  } else if (localDW->TimeStampB == (rtInf)) {
    localDW->TimeStampB = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB;
  } else if (localDW->TimeStampA < localDW->TimeStampB) {
    localDW->TimeStampA = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA;
  } else {
    localDW->TimeStampB = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB;
  }

  *lastU = localB->Gain2;

  /* End of Update for Derivative: '<S131>/Derivative' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S132>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemInp = localB->Memory_d;

    /* Update for Memory generated from: '<S132>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_e = localB->Memory1;

    /* Update for Memory generated from: '<S133>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_l = localB->Memory_e;

    /* Update for Memory generated from: '<S133>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_d = localB->Memory1_d;

    /* Update for Memory: '<S132>/Memory' */
    localDW->Memory_PreviousInput_i = localB->EnabledSubsystem.y;

    /* Update for Memory: '<S132>/Memory1' */
    localDW->Memory1_PreviousInput = localB->EnabledSubsystem1.y;

    /* Update for Memory: '<S133>/Memory' */
    localDW->Memory_PreviousInput_e = localB->EnabledSubsystem_i.y;

    /* Update for Memory: '<S133>/Memory1' */
    localDW->Memory1_PreviousInput_f = localB->EnabledSubsystem1_j.y;

    /* Update for Backlash: '<S204>/Backlash' */
    localDW->PrevY_f = localB->Backlash_i;
  }

  /* Update for Derivative: '<S218>/Derivative' */
  if (localDW->TimeStampA_g == (rtInf)) {
    localDW->TimeStampA_g = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA_k;
  } else if (localDW->TimeStampB_h == (rtInf)) {
    localDW->TimeStampB_h = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB_g;
  } else if (localDW->TimeStampA_g < localDW->TimeStampB_h) {
    localDW->TimeStampA_g = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA_k;
  } else {
    localDW->TimeStampB_h = (&AdasPlantModel0_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB_g;
  }

  *lastU = localB->Gain2_b;

  /* End of Update for Derivative: '<S218>/Derivative' */
  if (rtmIsMajorTimeStep((&AdasPlantModel0_M)) &&
      (&AdasPlantModel0_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S219>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_a = localB->Memory_e0;

    /* Update for Memory generated from: '<S219>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_c = localB->Memory1_c;

    /* Update for Memory generated from: '<S220>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_k = localB->Memory_h;

    /* Update for Memory generated from: '<S220>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_m = localB->Memory1_h;

    /* Update for Memory: '<S219>/Memory' */
    localDW->Memory_PreviousInput_m = localB->EnabledSubsystem_l.y;

    /* Update for Memory: '<S219>/Memory1' */
    localDW->Memory1_PreviousInput_d = localB->EnabledSubsystem1_c.y;

    /* Update for Memory: '<S220>/Memory' */
    localDW->Memory_PreviousInput_mf = localB->EnabledSubsystem_o.y;

    /* Update for Memory: '<S220>/Memory1' */
    localDW->Memory1_PreviousInput_k = localB->EnabledSubsystem1_l.y;

    /* Update for Memory: '<S601>/Memory' incorporates:
     *  Constant: '<S601>/Reset'
     */
    localDW->Memory_PreviousInput_l = localP->Reset_Value_e;
  }

  /* Update for Integrator: '<S601>/Integrator' */
  localDW->Integrator_IWORK_c3 = 0;

  /* Update for Integrator: '<S552>/Integrator' */
  localDW->Integrator_IWORK_f = 0;

  /* Update for Integrator: '<S643>/Integrator' */
  localDW->Integrator_IWORK_fi = 0;

  /* Update for Integrator: '<S632>/Integrator Limited' */
  localDW->IntegratorLimited_IWORK = 0;
}

/* Derivatives for atomic system: '<Root>/AdasPlantModel' */
void AdasPlantModel0::AdasPlantM_AdasPlantModel_Deriv
  (B_AdasPlantModel_AdasPlantMod_T *localB, DW_AdasPlantModel_AdasPlantMo_T
   *localDW, P_AdasPlantModel_AdasPlantMod_T *localP, P_AdasPlantModel0_T
   *AdasPlantModel0_P, X_AdasPlantModel_AdasPlantMod_T *localX,
   XDot_AdasPlantModel_AdasPlant_T *localXdot)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  boolean_T lsat;
  boolean_T usat;

  /* Derivatives for Integrator: '<S630>/Integrator' */
  localXdot->Integrator_CSTATE = localB->Sum_f;

  /* Derivatives for Integrator: '<S609>/Integrator' */
  localXdot->Integrator_CSTATE_j = localB->Divide_fp;

  /* Derivatives for Integrator: '<S406>/ub,vb,wb' */
  localXdot->ubvbwb_CSTATE[0] = localB->Sum_l[0];
  localXdot->ubvbwb_CSTATE[1] = localB->Sum_l[1];
  localXdot->ubvbwb_CSTATE[2] = localB->Sum_l[2];

  /* Derivatives for Integrator: '<S579>/Integrator' */
  localXdot->Integrator_CSTATE_i = localB->Product_f;

  /* Derivatives for Integrator: '<S578>/Integrator' */
  localXdot->Integrator_CSTATE_m = localB->Subtract_p;

  /* Derivatives for Integrator: '<S587>/Integrator' */
  localXdot->Integrator_CSTATE_fd = localB->Product_e;

  /* Derivatives for Integrator: '<S586>/Integrator' */
  localXdot->Integrator_CSTATE_jc = localB->Subtract_f;

  /* Derivatives for Integrator: '<S105>/Integrator1' */
  localXdot->Integrator1_CSTATE[0] = localB->Divide[0];

  /* Derivatives for Integrator: '<S516>/Integrator' */
  localXdot->Integrator_CSTATE_f[0] = localB->Product1[0];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_p[0] = localB->Product1_p[0];

  /* Derivatives for Integrator: '<S373>/Integrator1' */
  localXdot->Integrator1_CSTATE_c[0] = localB->Divide_f[0];

  /* Derivatives for Integrator: '<S519>/Integrator' */
  localXdot->Integrator_CSTATE_m1[0] = localB->Product1_l[0];

  /* Derivatives for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[0] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[0] =
      localX->IntegratorSecondOrder_CSTATE[4];
    localXdot->IntegratorSecondOrder_CSTATE[4] = localB->Gain1_d[0];
  }

  /* Derivatives for Integrator: '<S105>/Integrator1' */
  localXdot->Integrator1_CSTATE[1] = localB->Divide[1];

  /* Derivatives for Integrator: '<S516>/Integrator' */
  localXdot->Integrator_CSTATE_f[1] = localB->Product1[1];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_p[1] = localB->Product1_p[1];

  /* Derivatives for Integrator: '<S373>/Integrator1' */
  localXdot->Integrator1_CSTATE_c[1] = localB->Divide_f[1];

  /* Derivatives for Integrator: '<S519>/Integrator' */
  localXdot->Integrator_CSTATE_m1[1] = localB->Product1_l[1];

  /* Derivatives for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[1] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[1] =
      localX->IntegratorSecondOrder_CSTATE[5];
    localXdot->IntegratorSecondOrder_CSTATE[5] = localB->Gain1_d[1];
  }

  /* Derivatives for Integrator: '<S105>/Integrator1' */
  localXdot->Integrator1_CSTATE[2] = localB->Divide[2];

  /* Derivatives for Integrator: '<S516>/Integrator' */
  localXdot->Integrator_CSTATE_f[2] = localB->Product1[2];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_p[2] = localB->Product1_p[2];

  /* Derivatives for Integrator: '<S373>/Integrator1' */
  localXdot->Integrator1_CSTATE_c[2] = localB->Divide_f[2];

  /* Derivatives for Integrator: '<S519>/Integrator' */
  localXdot->Integrator_CSTATE_m1[2] = localB->Product1_l[2];

  /* Derivatives for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[2] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[2] =
      localX->IntegratorSecondOrder_CSTATE[6];
    localXdot->IntegratorSecondOrder_CSTATE[6] = localB->Gain1_d[2];
  }

  /* Derivatives for Integrator: '<S105>/Integrator1' */
  localXdot->Integrator1_CSTATE[3] = localB->Divide[3];

  /* Derivatives for Integrator: '<S516>/Integrator' */
  localXdot->Integrator_CSTATE_f[3] = localB->Product1[3];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_p[3] = localB->Product1_p[3];

  /* Derivatives for Integrator: '<S373>/Integrator1' */
  localXdot->Integrator1_CSTATE_c[3] = localB->Divide_f[3];

  /* Derivatives for Integrator: '<S519>/Integrator' */
  localXdot->Integrator_CSTATE_m1[3] = localB->Product1_l[3];

  /* Derivatives for SecondOrderIntegrator: '<S520>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[3] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[3] =
      localX->IntegratorSecondOrder_CSTATE[7];
    localXdot->IntegratorSecondOrder_CSTATE[7] = localB->Gain1_d[3];
  }

  /* Derivatives for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* Derivatives for Iterator SubSystem: '<S522>/Clutch Partitioned Parameters' */
    /* Derivatives for Chart: '<S526>/Clutch' */
    AdasPlantModel0_Clutch_Deriv(&localB->CoreSubsys_k[ForEach_itr].sf_Clutch,
      &localDW->CoreSubsys_k[ForEach_itr].sf_Clutch, &localXdot->
      CoreSubsys_k[ForEach_itr].sf_Clutch);

    /* End of Derivatives for SubSystem: '<S522>/Clutch Partitioned Parameters' */
  }

  /* End of Derivatives for SubSystem: '<S522>/Clutch Partitioned Parameters' */
  /* Derivatives for Integrator: '<S406>/p,q,r ' */
  localXdot->pqr_CSTATE[0] = localB->Product2[0];
  localXdot->pqr_CSTATE[1] = localB->Product2[1];
  localXdot->pqr_CSTATE[2] = localB->Product2[2];

  /* Derivatives for Integrator: '<S374>/Integrator1' incorporates:
   *  Product: '<S374>/Divide'
   */
  std::memcpy(&localXdot->Integrator1_CSTATE_n[0], &localB->Divide_pz[0], 12U *
              sizeof(real_T));

  /* Derivatives for Integrator: '<S406>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[0] = localB->Product_d[0];

  /* Derivatives for Integrator: '<S412>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[0] = localB->TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S406>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[1] = localB->Product_d[1];

  /* Derivatives for Integrator: '<S412>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[1] = localB->TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S406>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[2] = localB->Product_d[2];

  /* Derivatives for Integrator: '<S412>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[2] = localB->TmpSignalConversionAtphithetaps[2];

  /* Derivatives for SecondOrderIntegrator: '<S157>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_h == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_h[0] =
      localX->IntegratorSecondOrder_CSTATE_h[1];
    localXdot->IntegratorSecondOrder_CSTATE_h[1] = localB->Gain3;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S157>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S289>/Integrator1' incorporates:
   *  Product: '<S289>/Divide'
   */
  localXdot->Integrator1_CSTATE_no[0] = localB->Divide_c[0];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_b[0] = localB->Divide_p[0];

  /* Derivatives for Integrator: '<S289>/Integrator1' incorporates:
   *  Product: '<S289>/Divide'
   */
  localXdot->Integrator1_CSTATE_no[1] = localB->Divide_c[1];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_b[1] = localB->Divide_p[1];

  /* Derivatives for Integrator: '<S289>/Integrator1' incorporates:
   *  Product: '<S289>/Divide'
   */
  localXdot->Integrator1_CSTATE_no[2] = localB->Divide_c[2];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_b[2] = localB->Divide_p[2];

  /* Derivatives for Integrator: '<S289>/Integrator1' incorporates:
   *  Product: '<S289>/Divide'
   */
  localXdot->Integrator1_CSTATE_no[3] = localB->Divide_c[3];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_b[3] = localB->Divide_p[3];

  /* Derivatives for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_b == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_a[0] =
      localX->IntegratorSecondOrder_CSTATE_a[1];
    localXdot->IntegratorSecondOrder_CSTATE_a[1] = localB->Gain_m;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S131>/Integrator' */
  lsat = (localX->Integrator_CSTATE_e <= localP->Integrator_LowerSat);
  usat = (localX->Integrator_CSTATE_e >= localP->Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (localB->Subtract2 > 0.0)) || (usat &&
       (localB->Subtract2 < 0.0))) {
    localXdot->Integrator_CSTATE_e = localB->Subtract2;
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_e = 0.0;
  }

  /* End of Derivatives for Integrator: '<S131>/Integrator' */

  /* Derivatives for SecondOrderIntegrator: '<S138>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_i == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_m[0] =
      localX->IntegratorSecondOrder_CSTATE_m[1];
    localXdot->IntegratorSecondOrder_CSTATE_m[1] = localB->Gain_e;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S138>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S126>/Integrator1' */
  localXdot->Integrator1_CSTATE_c1 = localB->Divide_b;

  /* Derivatives for SecondOrderIntegrator: '<S244>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_e == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_b[0] =
      localX->IntegratorSecondOrder_CSTATE_b[1];
    localXdot->IntegratorSecondOrder_CSTATE_b[1] = localB->Gain3_o;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S244>/Integrator, Second-Order' */

  /* Derivatives for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_d == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_f[0] =
      localX->IntegratorSecondOrder_CSTATE_f[1];
    localXdot->IntegratorSecondOrder_CSTATE_f[1] = localB->Gain_o5;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S218>/Integrator' */
  lsat = (localX->Integrator_CSTATE_n <= localP->Integrator_LowerSat_h);
  usat = (localX->Integrator_CSTATE_n >= localP->Integrator_UpperSat_i);
  if (((!lsat) && (!usat)) || (lsat && (localB->Subtract2_p > 0.0)) || (usat &&
       (localB->Subtract2_p < 0.0))) {
    localXdot->Integrator_CSTATE_n = localB->Subtract2_p;
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_n = 0.0;
  }

  /* End of Derivatives for Integrator: '<S218>/Integrator' */

  /* Derivatives for SecondOrderIntegrator: '<S225>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_ex == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_j[0] =
      localX->IntegratorSecondOrder_CSTATE_j[1];
    localXdot->IntegratorSecondOrder_CSTATE_j[1] = localB->Gain_o;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S225>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S213>/Integrator1' */
  localXdot->Integrator1_CSTATE_j = localB->Divide_h;

  /* Derivatives for Integrator: '<S392>/Integrator1' */
  localXdot->Integrator1_CSTATE_m[0] = localB->Divide_e[0];
  localXdot->Integrator1_CSTATE_m[1] = localB->Divide_e[1];

  /* Derivatives for Integrator: '<S410>/Integrator' */
  localXdot->Integrator_CSTATE_k[0] = localB->UnitConversion[0];
  localXdot->Integrator_CSTATE_k[1] = localB->UnitConversion[1];
  localXdot->Integrator_CSTATE_k[2] = localB->UnitConversion[2];

  /* Derivatives for Integrator: '<S601>/Integrator' */
  localXdot->Integrator_CSTATE_d = localB->Product_p;

  /* Derivatives for Integrator: '<S600>/Integrator' */
  localXdot->Integrator_CSTATE_jcw = localB->Subtract_d;

  /* Derivatives for Integrator: '<S552>/Integrator' */
  lsat = (localX->Integrator_CSTATE_a[0] <= localP->Integrator_LowerSat_j);
  usat = (localX->Integrator_CSTATE_a[0] >= localP->Integrator_UpperSat_k);
  if (((!lsat) && (!usat)) || (lsat && (localB->xdot_m[0] > 0.0)) || (usat &&
       (localB->xdot_m[0] < 0.0))) {
    localXdot->Integrator_CSTATE_a[0] = localB->xdot_m[0];
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_a[0] = 0.0;
  }

  lsat = (localX->Integrator_CSTATE_a[1] <= localP->Integrator_LowerSat_j);
  usat = (localX->Integrator_CSTATE_a[1] >= localP->Integrator_UpperSat_k);
  if (((!lsat) && (!usat)) || (lsat && (localB->xdot_m[1] > 0.0)) || (usat &&
       (localB->xdot_m[1] < 0.0))) {
    localXdot->Integrator_CSTATE_a[1] = localB->xdot_m[1];
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_a[1] = 0.0;
  }

  /* End of Derivatives for Integrator: '<S552>/Integrator' */

  /* Derivatives for TransferFcn: '<S657>/Motor Coupling Dynamics' */
  localXdot->MotorCouplingDynamics_CSTATE = 0.0;
  localXdot->MotorCouplingDynamics_CSTATE += localP->MotorCouplingDynamics_A *
    localX->MotorCouplingDynamics_CSTATE;
  localXdot->MotorCouplingDynamics_CSTATE += localB->Divide2;

  /* Derivatives for Integrator: '<S643>/Integrator' */
  localXdot->Integrator_CSTATE_o = localB->Sum_m;

  /* Derivatives for Integrator: '<S665>/Integrator' */
  localXdot->Integrator_CSTATE_ky = localB->Sum_e;

  /* Derivatives for Integrator: '<S632>/Integrator Limited' */
  lsat = (localX->IntegratorLimited_CSTATE <= localP->IntegratorLimited_LowerSat);
  usat = (localX->IntegratorLimited_CSTATE >= AdasPlantModel0_P->PlntBattChrgMax);
  if (((!lsat) && (!usat)) || (lsat && (localB->Gain1_g > 0.0)) || (usat &&
       (localB->Gain1_g < 0.0))) {
    localXdot->IntegratorLimited_CSTATE = localB->Gain1_g;
  } else {
    /* in saturation */
    localXdot->IntegratorLimited_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S632>/Integrator Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited' */
  if (localDW->IntegratorSecondOrderLimited_MO[0] == 0) {
    localXdot->IntegratorSecondOrderLimited_CS[0] =
      localX->IntegratorSecondOrderLimited_CS[3];
    localXdot->IntegratorSecondOrderLimited_CS[3] = localB->Sum2[0];
  }

  if (localDW->IntegratorSecondOrderLimited_MO[1] == 0) {
    localXdot->IntegratorSecondOrderLimited_CS[1] =
      localX->IntegratorSecondOrderLimited_CS[4];
    localXdot->IntegratorSecondOrderLimited_CS[4] = localB->Sum2[1];
  }

  if (localDW->IntegratorSecondOrderLimited_MO[2] == 0) {
    localXdot->IntegratorSecondOrderLimited_CS[2] =
      localX->IntegratorSecondOrderLimited_CS[5];
    localXdot->IntegratorSecondOrderLimited_CS[5] = localB->Sum2[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S683>/Integrator, Second-Order Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' */
  if (localDW->IntegratorSecondOrderLimited__m[0] == 0) {
    localXdot->IntegratorSecondOrderLimited__f[0] =
      localX->IntegratorSecondOrderLimited__f[3];
    localXdot->IntegratorSecondOrderLimited__f[3] = localB->Sum2_k[0];
  }

  if (localDW->IntegratorSecondOrderLimited__m[1] == 0) {
    localXdot->IntegratorSecondOrderLimited__f[1] =
      localX->IntegratorSecondOrderLimited__f[4];
    localXdot->IntegratorSecondOrderLimited__f[4] = localB->Sum2_k[1];
  }

  if (localDW->IntegratorSecondOrderLimited__m[2] == 0) {
    localXdot->IntegratorSecondOrderLimited__f[2] =
      localX->IntegratorSecondOrderLimited__f[5];
    localXdot->IntegratorSecondOrderLimited__f[5] = localB->Sum2_k[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S695>/Integrator, Second-Order Limited' */
}
