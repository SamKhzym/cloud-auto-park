/*
 * Code generation for system system '<Root>/AdasPlantModel'
 *
 * Model                      : ConfiguredVirtualVehicleModel
 * Model version              : 6.83
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Wed Oct  8 00:11:54 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "rtwtypes.h"
#include "AdasPlantModel.h"
#include "ConfiguredVirtualVehicleModel_types.h"
#include "ConfiguredVirtualVehicleModel.h"
#include <cmath>
#include "ConfiguredVirtualVehicleModel_private.h"
#include <cstring>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S527>/Clutch' */
const uint8_T ConfiguredVirtualVe_IN_Slipping{ 2U };

const uint8_T ConfiguredVirtualVehi_IN_Locked{ 1U };

/* Named constants for Chart: '<S27>/Balancing' */
const uint8_T ConfiguredVi_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T ConfiguredVirtu_IN_BalNotActive{ 2U };

const uint8_T ConfiguredVirtu_IN_BalancingOFF{ 1U };

const uint8_T ConfiguredVirtua_IN_BalancingON{ 2U };

const uint8_T ConfiguredVirtualV_IN_BalActive{ 1U };

/* Named constants for Chart: '<S31>/State_Machine' */
const uint8_T Configu_IN_CloseInvtrContactors{ 1U };

const uint8_T Configur_IN_CloseChgrContactors{ 1U };

const uint8_T Configur_IN_OpenInvtrContactors{ 2U };

const uint8_T Configure_IN_OpenChgrContactors{ 2U };

const uint8_T ConfiguredVi_IN_ClosePreChrgRly{ 3U };

const uint8_T ConfiguredVir_IN_OpenPreChrgRly{ 4U };

const uint8_T ConfiguredVirt_IN_CloseNegCntct{ 1U };

const uint8_T ConfiguredVirt_IN_ClosePosCntct{ 2U };

const uint8_T ConfiguredVirtu_IN_OpenNegCntct{ 2U };

const uint8_T ConfiguredVirtu_IN_OpenPosCntct{ 3U };

const uint8_T ConfiguredVirtualV_IN_Init_Mode{ 3U };

const uint8_T ConfiguredVirtualVe_IN_Charging{ 1U };

const uint8_T ConfiguredVirtualVeh_IN_CC_Mode{ 1U };

const uint8_T ConfiguredVirtualVeh_IN_CV_Mode{ 2U };

const uint8_T ConfiguredVirtualVeh_IN_Driving{ 2U };

const uint8_T ConfiguredVirtualVeh_IN_Standby{ 4U };

const uint8_T ConfiguredVirtualVehic_IN_Fault{ 3U };

const uint8_T ConfiguredVirtual_IN_PreChrgFlt{ 5U };

const uint8_T Configured_IN_ClosePreChrgRly_d{ 1U };

/*
 * Output and update for iterator system:
 *    '<S109>/Kinpin axle moment and tie rod force'
 *    '<S110>/Kinpin axle moment and tie rod force'
 */
void ConfiguredVirtualVehicleModel::Kinpinaxlemomentandtierodforce(const real_T
  rtu_Fy[2], const real_T rtu_Fz[2], const real_T rtu_Mz[2], const real_T
  rtu_nu[2], const real_T rtu_delta[2], real_T rtu_RackGain, real_T rty_Fsa_y[2],
  real_T rtp_HbLead, real_T rtp_KngpnOfst, real_T rtp_Lambda, real_T
  rtp_OvrlStrRatio, real_T rtp_StcLdRadius)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S109>/Kinpin axle moment and tie rod force' incorporates:
   *  ForEach: '<S113>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    real_T r_s;
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;

    /* MATLAB Function: '<S113>/MATLAB Function' incorporates:
     *  ForEachSliceSelector generated from: '<S113>/delta'
     *  ForEachSliceSelector generated from: '<S113>/nu'
     */
    r_s = rtp_KngpnOfst - rtp_StcLdRadius * std::tan(rtp_Lambda);
    tmp = std::cos(rtu_delta[ForEach_itr]);
    tmp_0 = std::cos(rtu_nu[ForEach_itr]);
    tmp_1 = std::cos(rtp_Lambda);

    /* ForEachSliceAssignment generated from: '<S113>/Fsa_y' incorporates:
     *  ForEachSliceSelector generated from: '<S113>/Fy'
     *  ForEachSliceSelector generated from: '<S113>/Fz'
     *  ForEachSliceSelector generated from: '<S113>/Mz'
     *  ForEachSliceSelector generated from: '<S113>/delta'
     *  ForEachSliceSelector generated from: '<S113>/nu'
     *  MATLAB Function: '<S113>/MATLAB Function'
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

  /* End of Outputs for SubSystem: '<S109>/Kinpin axle moment and tie rod force' */
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
 *    '<S133>/Enabled Subsystem'
 *    '<S134>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 *    '<S221>/Enabled Subsystem'
 */
void ConfiguredVirtualVehicleModel::Configure_EnabledSubsystem_Init
  (B_EnabledSubsystem_Configured_T *localB, P_EnabledSubsystem_Configured_T
   *localP)
{
  /* SystemInitialize for Outport: '<S141>/Fright' */
  localB->y = localP->Fright_Y0;
}

/*
 * Disable for enable system:
 *    '<S133>/Enabled Subsystem'
 *    '<S134>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 *    '<S221>/Enabled Subsystem'
 */
void ConfiguredVirtualVehicleModel::Config_EnabledSubsystem_Disable
  (DW_EnabledSubsystem_Configure_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S133>/Enabled Subsystem'
 *    '<S134>/Enabled Subsystem'
 *    '<S220>/Enabled Subsystem'
 *    '<S221>/Enabled Subsystem'
 */
void ConfiguredVirtualVehicleModel::ConfiguredVirt_EnabledSubsystem(real_T
  rtu_Enable, real_T rtu_In, real_T rtp_Frup, real_T rtp_k,
  B_EnabledSubsystem_Configured_T *localB, DW_EnabledSubsystem_Configure_T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S141>/Enable'
   */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    if (rtu_Enable > 0.0) {
      localDW->EnabledSubsystem_MODE = true;
    } else if (localDW->EnabledSubsystem_MODE) {
      Config_EnabledSubsystem_Disable(localDW);
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* MATLAB Function: '<S141>/MATLAB Function' */
    localB->y = rt_powd_snf(rtp_Frup, 1.0 - std::exp(-rt_powd_snf(rtp_k, rtu_In)));
  }

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S133>/Enabled Subsystem1'
 *    '<S134>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 *    '<S221>/Enabled Subsystem1'
 */
void ConfiguredVirtualVehicleModel::Configur_EnabledSubsystem1_Init
  (B_EnabledSubsystem1_Configure_T *localB, P_EnabledSubsystem1_Configure_T
   *localP)
{
  /* SystemInitialize for Outport: '<S142>/Fleft' */
  localB->y = localP->Fleft_Y0;
}

/*
 * Disable for enable system:
 *    '<S133>/Enabled Subsystem1'
 *    '<S134>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 *    '<S221>/Enabled Subsystem1'
 */
void ConfiguredVirtualVehicleModel::Confi_EnabledSubsystem1_Disable
  (DW_EnabledSubsystem1_Configur_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S133>/Enabled Subsystem1'
 *    '<S134>/Enabled Subsystem1'
 *    '<S220>/Enabled Subsystem1'
 *    '<S221>/Enabled Subsystem1'
 */
void ConfiguredVirtualVehicleModel::ConfiguredVir_EnabledSubsystem1(real_T
  rtu_Enable, real_T rtu_In, real_T rtp_Frup, real_T rtp_k,
  B_EnabledSubsystem1_Configure_T *localB, DW_EnabledSubsystem1_Configur_T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    if (rtu_Enable > 0.0) {
      localDW->EnabledSubsystem1_MODE = true;
    } else if (localDW->EnabledSubsystem1_MODE) {
      Confi_EnabledSubsystem1_Disable(localDW);
    }
  }

  if (localDW->EnabledSubsystem1_MODE) {
    /* MATLAB Function: '<S142>/MATLAB Function' */
    localB->y = -rt_powd_snf(rtp_Frup, 1.0 - std::exp(rt_powd_snf(rtp_k, rtu_In)));
  }

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem1' */
}

/*
 * System initialize for trigger system:
 *    '<S133>/Triggered Subsystem'
 *    '<S134>/Triggered Subsystem'
 *    '<S220>/Triggered Subsystem'
 *    '<S221>/Triggered Subsystem'
 */
void ConfiguredVirtualVehicleModel::Configu_TriggeredSubsystem_Init
  (B_TriggeredSubsystem_Configur_T *localB, P_TriggeredSubsystem_Configur_T
   *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S143>/In' incorporates:
   *  Outport: '<S143>/Out'
   */
  localB->In = localP->Out_Y0;

  /* SystemInitialize for Outport: '<S143>/xleft' */
  localB->y_i = localP->xleft_Y0;

  /* SystemInitialize for Outport: '<S143>/xright' */
  localB->y = localP->xright_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S133>/Triggered Subsystem'
 *    '<S134>/Triggered Subsystem'
 *    '<S220>/Triggered Subsystem'
 *    '<S221>/Triggered Subsystem'
 */
void ConfiguredVirtualVehicleModel::ConfiguredVi_TriggeredSubsystem(real_T
  rtu_Trigger, real_T rtu_In, real_T rtu_Fright, real_T rtu_Fleft, real_T
  rtp_Frup, real_T rtp_k, B_TriggeredSubsystem_Configur_T *localB,
  ZCE_TriggeredSubsystem_Config_T *localZCE)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<S133>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S143>/Trigger'
   */
  if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&localZCE->TriggeredSubsystem_Trig_ZCE,
                       (rtu_Trigger));
    if (zcEvent != NO_ZCEVENT) {
      /* SignalConversion generated from: '<S143>/In' */
      localB->In = rtu_In;

      /* MATLAB Function: '<S143>/MATLAB Function' */
      localB->y_i = std::log(rtu_Fright / rtp_Frup + 1.0) * (1.0 / rtp_k);

      /* MATLAB Function: '<S143>/MATLAB Function1' */
      localB->y = std::log(1.0 - rtu_Fleft / rtp_Frup) * (-1.0 / rtp_k);
    }
  }

  /* End of Outputs for SubSystem: '<S133>/Triggered Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S155>/MATLAB Function1'
 *    '<S242>/MATLAB Function1'
 */
void ConfiguredVirtualVehicleModel::ConfiguredVirtu_MATLABFunction1(real_T rtu_u,
  real_T rtp_SptlAng, B_MATLABFunction1_ConfiguredV_T *localB)
{
  real_T a;
  real_T b_a;
  a = std::sin(3.1415926535897931 - rtp_SptlAng);
  b_a = std::sin(rtu_u);
  localB->y = std::cos(3.1415926535897931 - rtp_SptlAng) / (1.0 - a * a * (b_a *
    b_a));
}

/* Function for Chart: '<S527>/Clutch' */
boolean_T ConfiguredVirtualVehicleModel::ConfiguredVirtualVeh_detectSlip(real_T
  Tout, real_T Tfmaxs, B_Clutch_ConfiguredVirtualVeh_T *localB)
{
  localB->Tout = Tout;
  localB->Tfmaxs = Tfmaxs;

  /* Outputs for Function Call SubSystem: '<S528>/detectSlip' */
  /* RelationalOperator: '<S540>/Relational Operator' incorporates:
   *  Abs: '<S540>/Abs'
   */
  localB->RelationalOperator = (std::abs(localB->Tout) >= localB->Tfmaxs);

  /* End of Outputs for SubSystem: '<S528>/detectSlip' */
  return localB->RelationalOperator;
}

/* Function for Chart: '<S527>/Clutch' */
boolean_T ConfiguredVirtualVehicleModel::ConfiguredVirtualV_detectLockup(real_T
  Tout, real_T Tfmaxs, real_T rtp_br, B_Clutch_ConfiguredVirtualVeh_T *localB,
  DW_Clutch_ConfiguredVirtualVe_T *localDW, P_Clutch_ConfiguredVirtualVeh_T
  *localP)
{
  real_T rtb_Abs_hd;
  localB->Tout_l = Tout;
  localB->Tfmaxs_g = Tfmaxs;

  /* Outputs for Function Call SubSystem: '<S528>/detectLockup' */
  /* Gain: '<S537>/Output Damping' incorporates:
   *  Constant: '<S531>/Constant'
   */
  rtb_Abs_hd = rtp_br * localP->Constant_Value;

  /* CombinatorialLogic: '<S536>/Combinatorial  Logic' incorporates:
   *  Abs: '<S534>/Abs'
   *  Abs: '<S539>/Abs'
   *  RelationalOperator: '<S534>/Relational Operator'
   *  RelationalOperator: '<S539>/Relational Operator'
   *  Sum: '<S537>/Sum1'
   *  Sum: '<S537>/Sum2'
   *  UnaryMinus: '<S538>/Unary Minus'
   *  UnitDelay: '<S536>/Unit Delay'
   */
  localB->CombinatorialLogic = localP->CombinatorialLogic_table[(((std::abs
    (((0.0 - localB->Tout_l) - rtb_Abs_hd) + rtb_Abs_hd) >= localB->Tfmaxs_g) +
    (static_cast<uint32_T>(std::abs(-localB->Tout_l) <= localB->Tfmaxs_g) << 1))
    << 1) + localDW->UnitDelay_DSTATE];

  /* Update for UnitDelay: '<S536>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->CombinatorialLogic;

  /* End of Outputs for SubSystem: '<S528>/detectLockup' */
  return localB->CombinatorialLogic;
}

/* System initialize for atomic system: '<S527>/Clutch' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVe_Clutch_Init(real_T
  rtp_omegao, B_Clutch_ConfiguredVirtualVeh_T *localB,
  DW_Clutch_ConfiguredVirtualVe_T *localDW, P_Clutch_ConfiguredVirtualVeh_T
  *localP, X_Clutch_ConfiguredVirtualVeh_T *localX)
{
  /* SystemInitialize for Function Call SubSystem: '<S528>/detectSlip' */
  /* SystemInitialize for RelationalOperator: '<S540>/Relational Operator' incorporates:
   *  Outport: '<S532>/yn'
   */
  localB->RelationalOperator = localP->yn_Y0;

  /* End of SystemInitialize for SubSystem: '<S528>/detectSlip' */

  /* SystemInitialize for Function Call SubSystem: '<S528>/detectLockup' */
  /* InitializeConditions for UnitDelay: '<S536>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for CombinatorialLogic: '<S536>/Combinatorial  Logic' incorporates:
   *  Outport: '<S531>/yn'
   */
  localB->CombinatorialLogic = localP->yn_Y0_n;

  /* End of SystemInitialize for SubSystem: '<S528>/detectLockup' */

  /* SystemInitialize for IfAction SubSystem: '<S528>/Slipping' */
  /* InitializeConditions for Integrator: '<S530>/omega wheel' */
  localX->omegaWheel = rtp_omegao;

  /* End of SystemInitialize for SubSystem: '<S528>/Slipping' */
}

/* Outputs for atomic system: '<S527>/Clutch' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicle_Clutch(real_T
  rtu_Tout, real_T rtu_Tfmaxs, real_T rtu_Tfmaxk, real_T rtp_omegao, real_T
  rtp_br, real_T rtp_Iyy, real_T rtp_OmegaTol, B_Clutch_ConfiguredVirtualVeh_T
  *localB, DW_Clutch_ConfiguredVirtualVe_T *localDW,
  P_Clutch_ConfiguredVirtualVeh_T *localP, X_Clutch_ConfiguredVirtualVeh_T
  *localX)
{
  real_T rtb_OutputSum;
  if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    localDW->lastMajorTime = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];

    /* Chart: '<S527>/Clutch' */
    if (localDW->is_active_c8_autolibshared == 0U) {
      localDW->is_active_c8_autolibshared = 1U;
      localX->omegaWheel = rtp_omegao;
      localDW->is_c8_autolibshared = ConfiguredVirtualVe_IN_Slipping;

      /* Gain: '<S530>/Output Damping' incorporates:
       *  Integrator: '<S530>/omega wheel'
       */
      rtb_OutputSum = rtp_br * localX->omegaWheel;

      /* Merge: '<S528>/ Merge 3' incorporates:
       *  SignalConversion generated from: '<S530>/Myb'
       */
      localB->Myb = rtb_OutputSum;

      /* Merge: '<S528>/ Merge ' incorporates:
       *  Integrator: '<S530>/omega wheel'
       *  SignalConversion generated from: '<S530>/Omega'
       */
      localB->Omega = localX->omegaWheel;

      /* Gain: '<S530>/Output Inertia' incorporates:
       *  Gain: '<S530>/-4'
       *  Integrator: '<S530>/omega wheel'
       *  Product: '<S530>/Max Dynamic Friction Torque1'
       *  Sum: '<S530>/Output Sum'
       *  Trigonometry: '<S530>/Trigonometric Function'
       */
      localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel) *
        rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

      /* Merge: '<S528>/ Merge 1' incorporates:
       *  SignalConversion generated from: '<S530>/Omegadot'
       */
      localB->Omegadot = localB->OutputInertia;
      localDW->Slipping_entered = true;
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, true);
    } else if (localDW->is_c8_autolibshared == ConfiguredVirtualVehi_IN_Locked)
    {
      if (ConfiguredVirtualVeh_detectSlip(rtu_Tout, rtu_Tfmaxs, localB)) {
        localX->omegaWheel = 0.0;
        localDW->Locked_entered = false;
        localDW->is_c8_autolibshared = ConfiguredVirtualVe_IN_Slipping;

        /* Gain: '<S530>/Output Damping' incorporates:
         *  Integrator: '<S530>/omega wheel'
         */
        rtb_OutputSum = rtp_br * localX->omegaWheel;

        /* Merge: '<S528>/ Merge 3' incorporates:
         *  SignalConversion generated from: '<S530>/Myb'
         */
        localB->Myb = rtb_OutputSum;

        /* Merge: '<S528>/ Merge ' incorporates:
         *  Integrator: '<S530>/omega wheel'
         *  SignalConversion generated from: '<S530>/Omega'
         */
        localB->Omega = localX->omegaWheel;

        /* Gain: '<S530>/Output Inertia' incorporates:
         *  Gain: '<S530>/-4'
         *  Integrator: '<S530>/omega wheel'
         *  Product: '<S530>/Max Dynamic Friction Torque1'
         *  Sum: '<S530>/Output Sum'
         *  Trigonometry: '<S530>/Trigonometric Function'
         */
        localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel)
          * rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

        /* Merge: '<S528>/ Merge 1' incorporates:
         *  SignalConversion generated from: '<S530>/Omegadot'
         */
        localB->Omegadot = localB->OutputInertia;
        localDW->Slipping_entered = true;
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, true);
      }

      /* case IN_Slipping: */
    } else if (ConfiguredVirtualV_detectLockup(rtu_Tout, rtu_Tfmaxs, rtp_br,
                localB, localDW, localP) && (std::abs(localB->Omega) <=
                rtp_OmegaTol)) {
      localDW->Slipping_entered = false;
      localDW->is_c8_autolibshared = ConfiguredVirtualVehi_IN_Locked;
      if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
          (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
        /* Merge: '<S528>/ Merge ' incorporates:
         *  Constant: '<S529>/Constant'
         *  SignalConversion generated from: '<S529>/Omega'
         */
        localB->Omega = localP->Constant_Value_o;

        /* Merge: '<S528>/ Merge 1' incorporates:
         *  Constant: '<S529>/Constant1'
         *  SignalConversion generated from: '<S529>/Omegadot'
         */
        localB->Omegadot = localP->Constant1_Value;

        /* Merge: '<S528>/ Merge 3' incorporates:
         *  Constant: '<S529>/Constant2'
         *  SignalConversion generated from: '<S529>/Myb'
         */
        localB->Myb = localP->Constant2_Value;
      }

      localDW->Locked_entered = true;
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, true);
    }

    /* End of Chart: '<S527>/Clutch' */
  }

  if (localDW->is_c8_autolibshared == ConfiguredVirtualVehi_IN_Locked) {
    if (!localDW->Locked_entered) {
      if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
          (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
        /* Merge: '<S528>/ Merge ' incorporates:
         *  Constant: '<S529>/Constant'
         *  SignalConversion generated from: '<S529>/Omega'
         */
        localB->Omega = localP->Constant_Value_o;

        /* Merge: '<S528>/ Merge 1' incorporates:
         *  Constant: '<S529>/Constant1'
         *  SignalConversion generated from: '<S529>/Omegadot'
         */
        localB->Omegadot = localP->Constant1_Value;

        /* Merge: '<S528>/ Merge 3' incorporates:
         *  Constant: '<S529>/Constant2'
         *  SignalConversion generated from: '<S529>/Myb'
         */
        localB->Myb = localP->Constant2_Value;
      }
    } else {
      localDW->Locked_entered = false;
    }

    /* case IN_Slipping: */
  } else if (!localDW->Slipping_entered) {
    /* Gain: '<S530>/Output Damping' incorporates:
     *  Integrator: '<S530>/omega wheel'
     */
    rtb_OutputSum = rtp_br * localX->omegaWheel;

    /* Merge: '<S528>/ Merge 3' incorporates:
     *  SignalConversion generated from: '<S530>/Myb'
     */
    localB->Myb = rtb_OutputSum;

    /* Merge: '<S528>/ Merge ' incorporates:
     *  Integrator: '<S530>/omega wheel'
     *  SignalConversion generated from: '<S530>/Omega'
     */
    localB->Omega = localX->omegaWheel;

    /* Gain: '<S530>/Output Inertia' incorporates:
     *  Gain: '<S530>/-4'
     *  Integrator: '<S530>/omega wheel'
     *  Product: '<S530>/Max Dynamic Friction Torque1'
     *  Sum: '<S530>/Output Sum'
     *  Trigonometry: '<S530>/Trigonometric Function'
     */
    localB->OutputInertia = ((std::tanh(localP->u_Gain * localX->omegaWheel) *
      rtu_Tfmaxk - rtu_Tout) - rtb_OutputSum) * (1.0 / rtp_Iyy);

    /* Merge: '<S528>/ Merge 1' incorporates:
     *  SignalConversion generated from: '<S530>/Omegadot'
     */
    localB->Omegadot = localB->OutputInertia;
  } else {
    localDW->Slipping_entered = false;
  }
}

/* Derivatives for atomic system: '<S527>/Clutch' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualV_Clutch_Deriv
  (B_Clutch_ConfiguredVirtualVeh_T *localB, DW_Clutch_ConfiguredVirtualVe_T
   *localDW, XDot_Clutch_ConfiguredVirtual_T *localXdot)
{
  localXdot->omegaWheel = 0.0;
  if (localDW->is_c8_autolibshared == ConfiguredVirtualVe_IN_Slipping) {
    /* Derivatives for Integrator: '<S530>/omega wheel' */
    localXdot->omegaWheel = localB->OutputInertia;
  }

  if (localDW->is_c8_autolibshared == ConfiguredVirtualVehi_IN_Locked) {
    if (localDW->Locked_entered) {
      localDW->Locked_entered = false;
    }

    /* case IN_Slipping: */
  } else if (localDW->Slipping_entered) {
    localDW->Slipping_entered = false;
  }
}

/* Function for Chart: '<S31>/State_Machine' */
void ConfiguredVirtualVehicleModel::ConfiguredVirt_MainStateMachine
  (B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
   *localDW, P_AdasPlantModel_ConfiguredVi_T *localP)
{
  switch (localDW->is_MainStateMachine) {
   case ConfiguredVirtualVe_IN_Charging:
    if (localDW->FaultPresent) {
      localB->ChargeCurrentReq = 0.0F;
      localDW->is_Charging = ConfiguredVi_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = ConfiguredVirtualVehic_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_nt == 2.0F) && (localDW->InvtrCntctState ==
                Contact::Close)) {
      localDW->is_Charging = ConfiguredVi_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = ConfiguredVirtualVeh_IN_Driving;
      localB->BMSState = 2.0F;
    } else if ((localP->Constant_Value_nt != 1.0F) && (localDW->ChrgCntctState ==
                Contact::Init)) {
      localDW->is_Charging = ConfiguredVi_IN_NO_ACTIVE_CHILD;
      localDW->is_MainStateMachine = ConfiguredVirtualVeh_IN_Standby;
      localB->BMSState = 0.0F;
    } else {
      switch (localDW->is_Charging) {
       case ConfiguredVirtualVeh_IN_CC_Mode:
        /* Constant: '<S26>/Constant' */
        if (localP->Constant_Value_nt != 1.0F) {
          localDW->is_Charging = ConfiguredVirtualV_IN_Init_Mode;
          localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
        } else if (localB->MaxCellVolt >=
                   localP->State_Machine_MaxCellVoltThrsld) {
          localDW->is_Charging = ConfiguredVirtualVeh_IN_CV_Mode;
        } else {
          localB->ChargeCurrentReq = std::fmin(localP->State_Machine_I_cc,
            localB->ChargeCurrentLimit);
        }
        break;

       case ConfiguredVirtualVeh_IN_CV_Mode:
        /* Constant: '<S26>/Constant' */
        if ((localP->Constant_Value_nt != 1.0F) || (localB->ChargeCurrentReq <=
             localP->State_Machine_I_cc / localP->State_Machine_currentFactor))
        {
          localDW->is_Charging = ConfiguredVirtualV_IN_Init_Mode;
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
        /* Constant: '<S26>/Constant' */
        /* case IN_Init_Mode: */
        if ((localP->Constant_Value_nt == 1.0F) && (localB->MaxCellVolt <
             localP->State_Machine_voltThreshold)) {
          localDW->is_Charging = ConfiguredVirtualVeh_IN_CC_Mode;
        }
        break;
      }
    }
    break;

   case ConfiguredVirtualVeh_IN_Driving:
    if (localDW->FaultPresent) {
      localDW->is_MainStateMachine = ConfiguredVirtualVehic_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_nt == 1.0F) && (localDW->ChrgCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = ConfiguredVirtualVe_IN_Charging;
      localB->BMSState = 1.0F;
      localDW->is_Charging = ConfiguredVirtualV_IN_Init_Mode;
      localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
    } else if ((localP->Constant_Value_nt != 2.0F) && (localDW->InvtrCntctState ==
                Contact::Init)) {
      localDW->is_MainStateMachine = ConfiguredVirtualVeh_IN_Standby;
      localB->BMSState = 0.0F;
    }
    break;

   case ConfiguredVirtualVehic_IN_Fault:
    localB->BMSState = 3.0F;
    break;

   default:
    /* case IN_Standby: */
    if (localDW->FaultPresent) {
      localDW->is_MainStateMachine = ConfiguredVirtualVehic_IN_Fault;
      localB->BMSState = 3.0F;
    } else if ((localP->Constant_Value_nt == 1.0F) && (localDW->ChrgCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = ConfiguredVirtualVe_IN_Charging;
      localB->BMSState = 1.0F;
      localDW->is_Charging = ConfiguredVirtualV_IN_Init_Mode;
      localB->ChargeCurrentReq = localP->State_Machine_noCurrent;
    } else if ((localP->Constant_Value_nt == 2.0F) && (localDW->InvtrCntctState ==
                Contact::Close)) {
      localDW->is_MainStateMachine = ConfiguredVirtualVeh_IN_Driving;
      localB->BMSState = 2.0F;
    }
    break;
  }
}

/* Function for Chart: '<S31>/State_Machine' */
void ConfiguredVirtualVehicleModel::Configur_InverterContactorState
  (B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
   *localDW, P_AdasPlantModel_ConfiguredVi_T *localP)
{
  if (localDW->is_InverterContactorState == Configu_IN_CloseInvtrContactors) {
    /* Constant: '<S26>/Constant' */
    if ((localP->Constant_Value_nt != 2.0F) || localDW->FaultPresent) {
      localDW->is_CloseInvtrContactors = ConfiguredVi_IN_NO_ACTIVE_CHILD;
      localDW->is_InverterContactorState = Configur_IN_OpenInvtrContactors;
      localDW->InvtrCntctState = Contact::Init;
      localDW->is_OpenInvtrContactors = Configured_IN_ClosePreChrgRly_d;
      localDW->temporalCounter_i3 = 0U;
    } else {
      switch (localDW->is_CloseInvtrContactors) {
       case ConfiguredVirt_IN_CloseNegCntct:
        if (localDW->temporalCounter_i3 * 100 >=
            localP->State_Machine_contactorTime) {
          localDW->is_CloseInvtrContactors = ConfiguredVi_IN_ClosePreChrgRly;
          localDW->temporalCounter_i3 = 0U;
        }
        break;

       case ConfiguredVirt_IN_ClosePosCntct:
        if (localDW->temporalCounter_i3 * 100 >=
            localP->State_Machine_contactorTime) {
          localDW->is_CloseInvtrContactors = ConfiguredVir_IN_OpenPreChrgRly;
          localDW->InvtrCntctState = Contact::Close;
        }
        break;

       case ConfiguredVi_IN_ClosePreChrgRly:
        if (localB->VoutInvtr / localB->PackVoltage >=
            localP->State_Machine_vRatio) {
          localDW->is_CloseInvtrContactors = ConfiguredVirt_IN_ClosePosCntct;
          localDW->temporalCounter_i3 = 0U;
        } else if (localDW->temporalCounter_i3 >=
                   localP->State_Machine_timeoutContactor * 10) {
          localDW->is_CloseInvtrContactors = ConfiguredVirtual_IN_PreChrgFlt;
        }
        break;

       case ConfiguredVir_IN_OpenPreChrgRly:
        localDW->InvtrCntctState = Contact::Close;
        break;

       default:
        /* case IN_PreChrgFlt: */
        break;
      }
    }

    /* Constant: '<S26>/Constant' */
    /* case IN_OpenInvtrContactors: */
  } else if ((localP->Constant_Value_nt == 2.0F) && (localDW->ChrgCntctState ==
              Contact::Open) && (!localDW->FaultPresent)) {
    localDW->is_OpenInvtrContactors = ConfiguredVi_IN_NO_ACTIVE_CHILD;
    localDW->is_InverterContactorState = Configu_IN_CloseInvtrContactors;
    localDW->InvtrCntctState = Contact::Init;
    localDW->is_CloseInvtrContactors = ConfiguredVirt_IN_CloseNegCntct;
    localDW->temporalCounter_i3 = 0U;
  } else {
    switch (localDW->is_OpenInvtrContactors) {
     case Configured_IN_ClosePreChrgRly_d:
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = ConfiguredVirtu_IN_OpenPosCntct;
        localDW->temporalCounter_i3 = 0U;
      }
      break;

     case ConfiguredVirtu_IN_OpenNegCntct:
      localDW->InvtrCntctState = Contact::Open;
      break;

     case ConfiguredVirtu_IN_OpenPosCntct:
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = ConfiguredVir_IN_OpenPreChrgRly;
        localDW->temporalCounter_i3 = 0U;
      }
      break;

     default:
      /* case IN_OpenPreChrgRly: */
      if (localDW->temporalCounter_i3 * 100 >=
          localP->State_Machine_contactorTime) {
        localDW->is_OpenInvtrContactors = ConfiguredVirtu_IN_OpenNegCntct;
        localDW->InvtrCntctState = Contact::Open;
      }
      break;
    }
  }
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVe_div0protect(const real_T
  u[4], real_T tol, real_T y[4], real_T yabs[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMo_sqrt(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[0] = std::sqrt(x_data[0]);
  }
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMod_abs(const real_T
  x_data[], const int32_T *x_size, real_T y_data[], int32_T *y_size)
{
  int32_T b;
  *y_size = *x_size;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    y_data[k] = std::abs(x_data[k]);
  }
}

void ConfiguredVirtualVehicleModel::Con_binary_expand_op_nxejpfz5mi(real_T in1[4],
  const int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], const
  real_T in4[4], real_T in5, const real_T in6[4], real_T in7, const real_T in8
  [108])
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

  ConfiguredVirtualVehicleMod_abs(in4_data, in2_size, tmp_data, &tmp_size);
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

void ConfiguredVirtualVehicleModel::Configure_binary_expand_op_nxej(real_T in1[4],
  const int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], real_T
  in4)
{
  real_T in3_data[4];
  real_T tmp_data[4];
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T tmp_size;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' incorporates:
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Reshape: '<S376>/Reshape1'
   */
  loop_ub = *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in3_data[tmp_size] = in3[in2_data[tmp_size]];
  }

  ConfiguredVirtualVehicleMod_abs(in3_data, in2_size, tmp_data, &tmp_size);
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtual_div0protect_g(const real_T
  u[4], real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
boolean_T ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMod_any(const
  boolean_T x[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMo_atan(real_T
  x_data[], const int32_T *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::atan(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMod_cos(real_T
  x_data[], const int32_T *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::cos(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicle_sqrt_c(real_T
  x_data[], const int32_T *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::sqrt(x_data[k]);
  }
}

void ConfiguredVirtualVehicleModel::Configured_binary_expand_op_nxe(real_T
  in1_data[], int32_T *in1_size, real_T in2, real_T in3, const real_T in4[4],
  const real_T in5[4], const int32_T in6_data[], const int32_T *in6_size, const
  real_T in7_data[], const int32_T *in7_size, real_T in8, const real_T in9_data[],
  const int32_T *in9_size)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' */
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehic_magicsin(const real_T
  D[4], real_T C, const real_T B[4], real_T E, const real_T u[4], real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehic_magiccos(real_T C,
  const real_T B[4], const real_T E[4], const real_T u[4], real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVeh_magiccos_o(real_T C,
  const real_T B[4], const real_T E[4], real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVeh_magicsin_p(const real_T
  D[4], const real_T C[4], const real_T B[4], const real_T E[4], const real_T u
  [4], real_T y[4])
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

void ConfiguredVirtualVehicleModel::ConfiguredV_binary_expand_op_nx(real_T
  in1_data[], int32_T *in1_size, const real_T in2[4], const real_T in3[4], const
  real_T in4[4], const int32_T in5_data[], const int32_T *in5_size, const real_T
  in6[4], const real_T in7[4])
{
  real_T in6_data[4];
  real_T tmp_data[4];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0_tmp;
  int32_T tmp;
  int32_T tmp_size;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' */
  loop_ub = *in5_size;
  for (i = 0; i < loop_ub; i++) {
    in6_data[i] = in6[in5_data[i]];
  }

  ConfiguredVirtualVehicleMod_abs(in6_data, in5_size, tmp_data, &tmp_size);
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVehicleMo_acos(real_T
  x_data[], const int32_T *x_size)
{
  int32_T b;
  b = *x_size;
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::acos(x_data[k]);
  }
}

void ConfiguredVirtualVehicleModel::ConfiguredVi_binary_expand_op_n(real_T in1[4],
  const int8_T in2_data[], const real_T in3[4], const int32_T in4_data[], const
  int32_T *in4_size, const real_T in5[108], const int8_T in6[2], const real_T
  in7[4], const real_T in8[4], const real_T in9[4])
{
  int32_T loop_ub;
  int32_T stride_0_0_tmp;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S511>/Vector Concatenate'
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
}

void ConfiguredVirtualVehicleModel::ConfiguredVirt_binary_expand_op(real_T in1[4],
  const int8_T in2_data[], const real_T in3[4], const int32_T in4_data[], const
  int32_T *in4_size, const real_T in5[108], const int8_T in6[2], const real_T
  in7[4], const real_T in8[4], const real_T in9[4], const real_T in10[4], const
  real_T in11[36])
{
  int32_T loop_ub;
  int32_T stride_0_0_tmp;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S511>/Vector Concatenate'
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
}

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtual_rollingMoment(const real_T
  Fx[4], const real_T Vcx[4], const real_T Fz[4], const real_T press[4], const
  real_T b_gamma[4], real_T Vo, real_T Ro, real_T Fzo, real_T pio, real_T b_QSY1,
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualV_magiccos_odr(const real_T
  D[4], real_T C, const real_T B[4], const real_T E[4], const real_T u[4],
  real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVe_magiccos_od(const real_T
  D[4], const real_T C[4], const real_T B[4], const real_T u[4], real_T y[4])
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

/* Function for MATLAB Function: '<S514>/Magic Tire Const Input' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtualVe_vdyncsmtire(const real_T
  Omega[4], const real_T Vx[4], const real_T Vy[4], const real_T psidot[4],
  real_T b_gamma[4], real_T press[4], const real_T scaleFactors[108], const
  real_T rhoz[4], real_T b_turnslip, real_T b_PRESMAX, real_T b_PRESMIN, real_T
  b_FZMAX, real_T b_FZMIN, real_T b_VXLOW, real_T b_KPUMAX, real_T b_KPUMIN,
  real_T b_ALPMAX, real_T b_ALPMIN, real_T b_CAMMIN, real_T b_CAMMAX, real_T
  b_LONGVL, real_T b_UNLOADED_RADIUS, real_T b_RIM_RADIUS, real_T b_NOMPRES,
  real_T b_FNOMIN, real_T b_VERTICAL_STIFFNESS, real_T b_DREFF, real_T b_BREFF,
  real_T b_FREFF, real_T b_Q_RE0, real_T b_Q_V1, real_T b_Q_V2, real_T b_Q_FZ1,
  real_T b_Q_FZ2, real_T b_Q_FCX, real_T b_Q_FCY, real_T b_PFZ1, real_T b_Q_FCY2,
  real_T b_BOTTOM_OFFST, real_T b_BOTTOM_STIFF, real_T b_PCX1, real_T b_PDX1,
  real_T b_PDX2, real_T b_PDX3, real_T b_PEX1, real_T b_PEX2, real_T b_PEX3,
  real_T b_PEX4, real_T b_PKX1, real_T b_PKX2, real_T b_PKX3, real_T b_PHX1,
  real_T b_PHX2, real_T b_PVX1, real_T b_PVX2, real_T b_PPX1, real_T b_PPX2,
  real_T b_PPX3, real_T b_PPX4, real_T b_RBX1, real_T b_RBX2, real_T b_RBX3,
  real_T b_RCX1, real_T b_REX1, real_T b_REX2, real_T b_QSX2, real_T b_QSX3,
  real_T b_QSX4, real_T b_QSX5, real_T b_QSX6, real_T b_QSX7, real_T b_QSX8,
  real_T b_QSX9, real_T b_QSX10, real_T b_QSX11, real_T b_PPMX1, real_T b_PCY1,
  real_T b_PDY1, real_T b_PDY2, real_T b_PDY3, real_T b_PEY1, real_T b_PEY2,
  real_T b_PEY4, real_T b_PEY5, real_T b_PKY1, real_T b_PKY2, real_T b_PKY3,
  real_T b_PKY4, real_T b_PKY5, real_T b_PKY6, real_T b_PKY7, real_T b_PVY3,
  real_T b_PVY4, real_T b_PPY1, real_T b_PPY2, real_T b_PPY3, real_T b_PPY4,
  real_T b_PPY5, real_T b_RBY1, real_T b_RBY2, real_T b_RBY4, real_T b_RCY1,
  real_T b_REY1, real_T b_REY2, real_T b_RHY1, real_T b_RHY2, real_T b_RVY3,
  real_T b_RVY4, real_T b_RVY5, real_T b_RVY6, real_T b_QSY1, real_T b_QSY2,
  real_T b_QSY3, real_T b_QSY4, real_T b_QSY5, real_T b_QSY6, real_T b_QSY7,
  real_T b_QSY8, real_T b_QBZ1, real_T b_QBZ2, real_T b_QBZ3, real_T b_QBZ5,
  real_T b_QBZ6, real_T b_QBZ9, real_T b_QBZ10, real_T b_QCZ1, real_T b_QDZ1,
  real_T b_QDZ2, real_T b_QDZ4, real_T b_QDZ8, real_T b_QDZ9, real_T b_QDZ10,
  real_T b_QDZ11, real_T b_QEZ1, real_T b_QEZ2, real_T b_QEZ3, real_T b_QEZ5,
  real_T b_QHZ3, real_T b_QHZ4, real_T b_PPZ1, real_T b_PPZ2, real_T b_SSZ2,
  real_T b_SSZ3, real_T b_SSZ4, real_T b_PDXP1, real_T b_PDXP2, real_T b_PDXP3,
  real_T b_PKYP1, real_T b_PDYP1, real_T b_PDYP2, real_T b_PDYP3, real_T b_PDYP4,
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
  ConfiguredVirtualVe_div0protect(Vx, b_VXLOW, R_omega, Vsy);
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

      ConfiguredVirtualVehicleMo_sqrt(&ec_data, ec_size);
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

  ConfiguredVirtualVehicleMod_abs(phi_t, &trueCount, phi, &tmp_size_0);
  i = trueCount == 1 ? tmp_size_0 : trueCount;
  ConfiguredVirtualVehicleMod_abs(rhoz_data, &trueCount, phi, &tmp_size_0);
  ConfiguredVirtualVehicleMod_abs(rhoz_data_0, &trueCount, phi,
    &partialTrueCount);
  if ((trueCount == tmp_size_0) && ((trueCount == 1 ? partialTrueCount :
        trueCount) == trueCount) && ((i == 1 ? trueCount : i) == trueCount)) {
    partialTrueCount = trueCount;
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = rhoz[tmp_data[i]];
    }

    ConfiguredVirtualVehicleMod_abs(rhoz_data, &partialTrueCount, rhoz_data_0,
      &trueCount);
    for (i = 0; i < tmp_size; i++) {
      partialTrueCount = tmp_data[i];
      Re[partialTrueCount] = (b_Q_FCY2 * Fy_ext[partialTrueCount] / b_FNOMIN +
        Fz_ext[partialTrueCount] / rhoz_data_0[i]) * scaleFactors[27 *
        partialTrueCount + 22];
    }
  } else {
    Con_binary_expand_op_nxejpfz5mi(Re, tmp_data, &trueCount, Fz_ext, rhoz,
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
  ConfiguredVirtualVe_div0protect(Vx, b_VXLOW, phi_t, lam_Cz);
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
  ConfiguredVirtualVe_div0protect(R_omega, b_VXLOW, Mz, lam_Cz);
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

  ConfiguredVirtualVehicleMod_abs(rhoz_data, &trueCount, phi, &tmp_size);
  if (trueCount == tmp_size) {
    partialTrueCount = trueCount;
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = Vx[tmp_data_0[i]];
    }

    ConfiguredVirtualVehicleMod_abs(rhoz_data, &partialTrueCount, rhoz_data_0,
      &trueCount);
    for (i = 0; i < tmp_size_0; i++) {
      rhoz_data[i] = rhoz_data_0[i] / b_VXLOW * phi_t[tmp_data_0[i]];
    }

    for (i = 0; i < tmp_size_0; i++) {
      phi_t[tmp_data_0[i]] = rhoz_data[i];
    }
  } else {
    Configure_binary_expand_op_nxej(phi_t, tmp_data_0, &trueCount, Vx, b_VXLOW);
  }

  ConfiguredVirtual_div0protect_g(R_omega, rhoz_data);
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

  nomslipinds_0 = ConfiguredVirtualVehicleMod_any(tempInds);
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

    ConfiguredVirtualVehicleMo_atan(rhoz_data, &tmp_size_0);
    ConfiguredVirtualVehicleMod_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 1] = rhoz_data[i];
      tmpDrphiVar_data[i] = phi[bc_tmp_data[i]];
    }

    ConfiguredVirtualVehicleMod_abs(tmpDrphiVar_data, &tmp_size_0, rhoz_data_0,
      &trueCount);
    for (i = 0; i < trueCount; i++) {
      rhoz_data[i] = b_UNLOADED_RADIUS * rhoz_data_0[i];
    }

    tmp_size = trueCount;
    if (trueCount - 1 >= 0) {
      std::memcpy(&tmpDrphiVar_data[0], &rhoz_data[0], static_cast<uint32_T>
                  (trueCount) * sizeof(real_T));
    }

    ConfiguredVirtualVehicle_sqrt_c(tmpDrphiVar_data, &trueCount);
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
      Configured_binary_expand_op_nxe(dc_data, &tmp_size, b_PDYP1, b_PDYP2, dfz,
        lam_Cz, bc_tmp_data, &tmp_size_0, rhoz_data, &trueCount, b_PDYP4,
        tmpDrphiVar_data, &trueCount);
    }

    ConfiguredVirtualVehicleMo_atan(dc_data, &tmp_size);
    ConfiguredVirtualVehicleMod_cos(dc_data, &tmp_size);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 2] = dc_data[i];
    }

    dfz_0 = b_UNLOADED_RADIUS * b_UNLOADED_RADIUS * b_PKYP1;
    for (i = 0; i < tmp_size_0; i++) {
      Vsy_tmp = phi[bc_tmp_data[i]];
      rhoz_data[i] = Vsy_tmp * Vsy_tmp * dfz_0;
    }

    ConfiguredVirtualVehicleMo_atan(rhoz_data, &tmp_size_0);
    ConfiguredVirtualVehicleMod_cos(rhoz_data, &tmp_size_0);
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
  ConfiguredVirtualVe_div0protect(Vsy, 0.0001, b_x, lam_Cz);
  ConfiguredVirtualVe_div0protect(R_omega, 0.0001, Vsy, lam_Cz);
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
  ConfiguredVirtualVehic_magicsin(lam_Cz, x_idx_0, dc_data, ab_idx_0, Vs,
    rhoz_data);
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
  ConfiguredVirtualVehic_magiccos(b_RCY1, Bykappa, Eykappa, dc_data, rhoz_data);
  ConfiguredVirtualVehic_magiccos(b_RCY1, Bykappa, Eykappa, SHykappa, dc_data);
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

    ConfiguredVirtualVehicleMo_atan(rhoz_data, &tmp_size_0);
    ConfiguredVirtualVehicleMod_cos(rhoz_data, &tmp_size_0);
    for (i = 0; i < tmp_size_0; i++) {
      zeta[9 * bc_data[i] + 5] = rhoz_data[i];
    }

    gamma_star_tmp = b_QBRP1 * b_UNLOADED_RADIUS;
    for (i = 0; i < tmp_size_0; i++) {
      rhoz_data[i] = gamma_star_tmp * phi[bc_tmp_data[i]];
    }

    ConfiguredVirtualVehicleMo_atan(rhoz_data, &tmp_size_0);
    ConfiguredVirtualVehicleMod_cos(rhoz_data, &tmp_size_0);
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
    ConfiguredVirtualVehic_magicsin(lam_Cz, R_omega_0, rhoz_data,
      gamma_star_tmp_0, Vs, R_omega);
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

    ConfiguredVirtualVehicleMod_abs(rhoz_data, &tmp_size_0, rhoz_data_0,
      &trueCount);
    ConfiguredVirtualVehicleMod_abs(dc_data, &tmp_size_0, phi, &tmp_size);
    if ((tmp_size == tmp_size_0) && ((trueCount == 1 ? tmp_size_0 : trueCount) ==
         tmp_size_0)) {
      for (i = 0; i < tmp_size_0; i++) {
        dc_data[i] = R_omega[bc_tmp_data[i]];
      }

      ConfiguredVirtualVehicleMod_abs(dc_data, &tmp_size_0, rhoz_data_0,
        &trueCount);
      tmp_size = tmp_size_0;
      for (i = 0; i < tmp_size_0; i++) {
        partialTrueCount = bc_tmp_data[i];
        tmpDrphiVar_data[i] = Mzphiinf[partialTrueCount] * 2.0 /
          3.1415926535897931 * Bykappa[partialTrueCount] * Fy[partialTrueCount] /
          (0.0001 * lam_Cz[partialTrueCount] + rhoz_data_0[i]);
      }
    } else {
      ConfiguredV_binary_expand_op_nx(tmpDrphiVar_data, &tmp_size, Mzphiinf,
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

    ConfiguredVirtualVehicleMo_acos(tmpDrphiVar_data, &tmp_size);
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
      ConfiguredVi_binary_expand_op_n(SHy, bc_data, dfz, bc_tmp_data,
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
  ConfiguredVirtualVe_div0protect(Vs, 0.0001, Vsy, lam_Cz);
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

  ConfiguredVirtualVehic_magiccos(b_RCX1, R_omega, lam_Cz, alpha, rhoz_data);
  ConfiguredVirtualVeh_magiccos_o(b_RCX1, R_omega, lam_Cz, dc_data);
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
  ConfiguredVirtualVeh_magicsin_p(epsilon_gamma, Eykappa, Mzphiinf, Bykappa,
    kappa_x, rhoz_data);
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
  ConfiguredVirtualVe_div0protect(Vs, 0.0001, epsilon_gamma, lam_Cz);
  epsilon_gamma[0] = dfz_0 / epsilon_gamma[0];
  epsilon_gamma[1] = Vsy_tmp / epsilon_gamma[1];
  epsilon_gamma[2] = Vsy_tmp_0 / epsilon_gamma[2];
  epsilon_gamma[3] = Vsy_tmp_1 / epsilon_gamma[3];
  if (ConfiguredVirtualVehicleMod_any(nomslipinds)) {
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
      ConfiguredVirt_binary_expand_op(SHy, tmp_data_1, dfz, tmp_data_2,
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

  ConfiguredVirtualVeh_magicsin_p(Vsy, Mzphiinf, epsilon_gamma, Vs, R_omega,
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
  ConfiguredVirtual_rollingMoment(Fx, Vx, FzUnSat, press, b_gamma, b_LONGVL,
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
  ConfiguredVirtualV_magiccos_odr(dc_data, ec_data, Eykappa, SHykappa, phi,
    rhoz_data);
  ConfiguredVirtualVe_magiccos_od(FzUnSat, kappa_x, lam_Cz, Kygammao, dc_data);
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

void ConfiguredVirtualVehicleModel::Configur_binary_expand_op_nxejp(real_T in1[4],
  const int32_T in2_data[], const int32_T *in2_size, const real_T in3[4], const
  real_T in4[4], real_T in5, const real_T in6[4], real_T in7, const real_T in8
  [108])
{
  real_T in4_data[4];
  real_T tmp_data[4];
  int32_T in3_tmp;
  int32_T loop_ub;
  int32_T stride_0_0_tmp;
  int32_T stride_1_0;
  int32_T tmp_size;

  /* MATLAB Function: '<S514>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S511>/Vector Concatenate'
   */
  loop_ub = *in2_size;
  for (tmp_size = 0; tmp_size < loop_ub; tmp_size++) {
    in4_data[tmp_size] = in4[in2_data[tmp_size]];
  }

  ConfiguredVirtualVehicleMod_abs(in4_data, in2_size, tmp_data, &tmp_size);
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

  /* End of MATLAB Function: '<S514>/Magic Tire Const Input' */
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

/* Function for MATLAB Function: '<S553>/Open Differential' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtua_automldiffopen(const real_T
  u[3], real_T bw1, real_T bd, real_T bw2, real_T Ndiff, real_T shaftSwitch,
  real_T Jd, real_T Jw1, real_T Jw2, const real_T x[2], real_T y[3], real_T
  xdot[2])
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
void ConfiguredVirtualVehicleModel::ConfiguredV_AdasPlantModel_Init
  (B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
   *localDW, P_AdasPlantModel_ConfiguredVi_T *localP,
   P_ConfiguredVirtualVehicleMod_T *ConfiguredVirtualVehicleModel_P,
   X_AdasPlantModel_ConfiguredVi_T *localX, ZCE_AdasPlantModel_Configured_T
   *localZCE)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_a;
  int32_T i;

  /* Start for Constant: '<S579>/domega_o' */
  localB->domega_o = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;

  /* Start for Constant: '<S587>/domega_o' */
  localB->domega_o_o = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;

  /* Start for Constant: '<S601>/domega_o' */
  localB->domega_o_n = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  std::memcpy(&localDW->UnitDelay_1_DSTATE[0],
              &localP->UnitDelay_1_InitialCondition[0], 96U * sizeof(real32_T));

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  std::memcpy(&localDW->UnitDelay_4_DSTATE[0],
              &localP->UnitDelay_4_InitialCondition[0], 96U * sizeof(real32_T));

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  localDW->UnitDelay_2_DSTATE = localP->UnitDelay_2_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  localDW->UnitDelay_5_DSTATE = localP->UnitDelay_5_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  localDW->UnitDelay_6_DSTATE = localP->UnitDelay_6_InitialCondition;

  /* InitializeConditions for UnitDelay generated from: '<S26>/Unit Delay' */
  localDW->UnitDelay_3_DSTATE = localP->UnitDelay_3_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = static_cast<real32_T>
    (ConfiguredVirtualVehicleModel_P->PlntBattSocInit);

  /* InitializeConditions for Integrator: '<S631>/Integrator' incorporates:
   *  Integrator: '<S580>/Integrator'
   */
  if (rtmIsFirstInitCond((&ConfiguredVirtualVehicleMode_M))) {
    localX->Integrator_CSTATE_p = 0.0;
    localX->Integrator_CSTATE_m = 0.0;
  }

  localDW->Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S631>/Integrator' */

  /* InitializeConditions for RateTransition: '<S22>/Rate Transition18' */
  localDW->RateTransition18_Buffer[0] = localP->RateTransition18_InitialConditi;

  /* InitializeConditions for RateTransition: '<S22>/Rate Transition19' */
  localDW->RateTransition19_Buffer[0] = localP->RateTransition19_InitialConditi;

  /* InitializeConditions for RateTransition: '<S22>/Rate Transition20' */
  localDW->RateTransition20_Buffer[0] = localP->RateTransition20_InitialConditi;

  /* InitializeConditions for RateTransition: '<S22>/Rate Transition21' */
  localDW->RateTransition21_Buffer[0] = localP->RateTransition21_InitialConditi;

  /* InitializeConditions for Integrator: '<S610>/Integrator' */
  localX->Integrator_CSTATE_i =
    ConfiguredVirtualVehicleModel_P->PlntEM1RotInitSpd;

  /* InitializeConditions for Integrator: '<S407>/ub,vb,wb' */
  localX->ubvbwb_CSTATE[0] = localP->VehicleBody6DOF_xbdot_o[0];
  localX->ubvbwb_CSTATE[1] = localP->VehicleBody6DOF_xbdot_o[1];
  localX->ubvbwb_CSTATE[2] = localP->VehicleBody6DOF_xbdot_o[2];

  /* InitializeConditions for FirstOrderHold: '<S80>/First Order Hold' */
  localDW->Tk = (rtInf);
  localDW->Ck = localP->FirstOrderHold_IniOut;
  localDW->Uk = (rtInf);

  /* InitializeConditions for Integrator: '<S106>/Integrator1' */
  localX->Integrator1_CSTATE_h[0] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_e[0] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S518>/Integrator' */
  localX->Integrator_CSTATE_c[0] = localP->Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S374>/Integrator1' */
  localX->Integrator1_CSTATE_n[0] = localP->Integrator1_IC_o;

  /* InitializeConditions for Integrator: '<S106>/Integrator1' */
  localX->Integrator1_CSTATE_h[1] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_e[1] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S518>/Integrator' */
  localX->Integrator_CSTATE_c[1] = localP->Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S374>/Integrator1' */
  localX->Integrator1_CSTATE_n[1] = localP->Integrator1_IC_o;

  /* InitializeConditions for Integrator: '<S106>/Integrator1' */
  localX->Integrator1_CSTATE_h[2] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_e[2] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S518>/Integrator' */
  localX->Integrator_CSTATE_c[2] = localP->Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S374>/Integrator1' */
  localX->Integrator1_CSTATE_n[2] = localP->Integrator1_IC_o;

  /* InitializeConditions for Integrator: '<S106>/Integrator1' */
  localX->Integrator1_CSTATE_h[3] = localP->Integrator1_IC;

  /* InitializeConditions for Integrator: '<S517>/Integrator' */
  localX->Integrator_CSTATE_e[3] = localP->Integrator_IC;

  /* InitializeConditions for Integrator: '<S518>/Integrator' */
  localX->Integrator_CSTATE_c[3] = localP->Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S374>/Integrator1' */
  localX->Integrator1_CSTATE_n[3] = localP->Integrator1_IC_o;

  /* InitializeConditions for Memory: '<S580>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S580>/Integrator' */
  localDW->Integrator_IWORK_n = 1;

  /* InitializeConditions for Integrator: '<S579>/Integrator' */
  localX->Integrator_CSTATE_f =
    ConfiguredVirtualVehicleModel_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Memory: '<S588>/Memory' */
  localDW->Memory_PreviousInput_e = localP->Memory_InitialCondition_a;

  /* InitializeConditions for Integrator: '<S588>/Integrator' */
  if (rtmIsFirstInitCond((&ConfiguredVirtualVehicleMode_M))) {
    localX->Integrator_CSTATE_j = 0.0;
  }

  localDW->Integrator_IWORK_m = 1;

  /* End of InitializeConditions for Integrator: '<S588>/Integrator' */

  /* InitializeConditions for Integrator: '<S587>/Integrator' */
  localX->Integrator_CSTATE_cw =
    ConfiguredVirtualVehicleModel_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Integrator: '<S520>/Integrator' */
  localX->Integrator_CSTATE_cf[0] = localP->Integrator_IC_p3;

  /* InitializeConditions for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[0] =
    ConfiguredVirtualVehicleModel_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S520>/Integrator' */
  localX->Integrator_CSTATE_cf[1] = localP->Integrator_IC_p3;

  /* InitializeConditions for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[1] =
    ConfiguredVirtualVehicleModel_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S520>/Integrator' */
  localX->Integrator_CSTATE_cf[2] = localP->Integrator_IC_p3;

  /* InitializeConditions for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[2] =
    ConfiguredVirtualVehicleModel_P->PlntVehInitVertPos;

  /* InitializeConditions for Integrator: '<S520>/Integrator' */
  localX->Integrator_CSTATE_cf[3] = localP->Integrator_IC_p3;

  /* InitializeConditions for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE[3] =
    ConfiguredVirtualVehicleModel_P->PlntVehInitVertPos;
  localX->IntegratorSecondOrder_CSTATE[4] = localP->CombinedSlipWheel2DOF_zdoto
    [0];
  localX->IntegratorSecondOrder_CSTATE[5] = localP->CombinedSlipWheel2DOF_zdoto
    [1];
  localX->IntegratorSecondOrder_CSTATE[6] = localP->CombinedSlipWheel2DOF_zdoto
    [2];
  localX->IntegratorSecondOrder_CSTATE[7] = localP->CombinedSlipWheel2DOF_zdoto
    [3];

  /* InitializeConditions for Integrator: '<S407>/p,q,r ' */
  localX->pqr_CSTATE[0] = localP->VehicleBody6DOF_p_o[0];
  localX->pqr_CSTATE[1] = localP->VehicleBody6DOF_p_o[1];
  localX->pqr_CSTATE[2] = localP->VehicleBody6DOF_p_o[2];

  /* InitializeConditions for Integrator: '<S375>/Integrator1' */
  for (i = 0; i < 12; i++) {
    localX->Integrator1_CSTATE_e[i] = localP->Integrator1_IC_c;
  }

  /* End of InitializeConditions for Integrator: '<S375>/Integrator1' */

  /* InitializeConditions for Integrator: '<S407>/xe,ye,ze' */
  localX->xeyeze_CSTATE[0] = localP->VehicleBody6DOF_Xe_o[0];

  /* InitializeConditions for Integrator: '<S413>/phi theta psi' */
  localX->phithetapsi_CSTATE[0] = localP->VehicleBody6DOF_eul_o[0];

  /* InitializeConditions for Integrator: '<S407>/xe,ye,ze' */
  localX->xeyeze_CSTATE[1] = localP->VehicleBody6DOF_Xe_o[1];

  /* InitializeConditions for Integrator: '<S413>/phi theta psi' */
  localX->phithetapsi_CSTATE[1] = localP->VehicleBody6DOF_eul_o[1];

  /* InitializeConditions for Integrator: '<S407>/xe,ye,ze' */
  localX->xeyeze_CSTATE[2] = localP->VehicleBody6DOF_Xe_o[2];

  /* InitializeConditions for Integrator: '<S413>/phi theta psi' */
  localX->phithetapsi_CSTATE[2] = localP->VehicleBody6DOF_eul_o[2];

  /* InitializeConditions for SecondOrderIntegrator: '<S158>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_e[0] = localP->IntegratorSecondOrder_ICX;
  localX->IntegratorSecondOrder_CSTATE_e[1] =
    localP->IntegratorSecondOrder_ICDXDT;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_d[0] = localP->Integrator1_IC_m;

  /* InitializeConditions for Integrator: '<S291>/Integrator1' */
  localX->Integrator1_CSTATE_nd[0] = localP->Integrator1_IC_h;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_d[1] = localP->Integrator1_IC_m;

  /* InitializeConditions for Integrator: '<S291>/Integrator1' */
  localX->Integrator1_CSTATE_nd[1] = localP->Integrator1_IC_h;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_d[2] = localP->Integrator1_IC_m;

  /* InitializeConditions for Integrator: '<S291>/Integrator1' */
  localX->Integrator1_CSTATE_nd[2] = localP->Integrator1_IC_h;

  /* InitializeConditions for Integrator: '<S290>/Integrator1' */
  localX->Integrator1_CSTATE_d[3] = localP->Integrator1_IC_m;

  /* InitializeConditions for Integrator: '<S291>/Integrator1' */
  localX->Integrator1_CSTATE_nd[3] = localP->Integrator1_IC_h;

  /* InitializeConditions for Backlash: '<S118>/Backlash' */
  localDW->PrevY = localP->Backlash_InitialOutput;

  /* InitializeConditions for SecondOrderIntegrator: '<S140>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_a[0] =
    localP->IntegratorSecondOrder_ICX_b;
  localX->IntegratorSecondOrder_CSTATE_a[1] =
    localP->IntegratorSecondOrder_ICDXDT_g;

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  localX->Integrator_CSTATE_id = localP->Integrator_IC_m;

  /* InitializeConditions for Derivative: '<S132>/Derivative' */
  localDW->TimeStampA = (rtInf);
  localDW->TimeStampB = (rtInf);

  /* InitializeConditions for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_d[0] =
    localP->IntegratorSecondOrder_ICX_b4;
  localX->IntegratorSecondOrder_CSTATE_d[1] =
    localP->IntegratorSecondOrder_ICDXDT_k;

  /* InitializeConditions for Integrator: '<S127>/Integrator1' */
  localX->Integrator1_CSTATE_nx = localP->Integrator1_IC_j;

  /* InitializeConditions for Memory generated from: '<S133>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemInp =
    localP->TmpLatchAtTriggeredSubsystemInp;

  /* InitializeConditions for Memory generated from: '<S133>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_l =
    localP->TmpLatchAtTriggeredSubsystemI_o;

  /* InitializeConditions for Memory generated from: '<S134>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_n =
    localP->TmpLatchAtTriggeredSubsystemI_g;

  /* InitializeConditions for Memory generated from: '<S134>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_k =
    localP->TmpLatchAtTriggeredSubsystemI_l;

  /* InitializeConditions for Memory: '<S133>/Memory' */
  localDW->Memory_PreviousInput_p = localP->Memory_InitialCondition_h;

  /* InitializeConditions for Memory: '<S133>/Memory1' */
  localDW->Memory1_PreviousInput = localP->Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S134>/Memory' */
  localDW->Memory_PreviousInput_g = localP->Memory_InitialCondition_ag;

  /* InitializeConditions for Memory: '<S134>/Memory1' */
  localDW->Memory1_PreviousInput_n = localP->Memory1_InitialCondition_c;

  /* InitializeConditions for SecondOrderIntegrator: '<S245>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_k[0] =
    localP->IntegratorSecondOrder_ICX_i;
  localX->IntegratorSecondOrder_CSTATE_k[1] =
    localP->IntegratorSecondOrder_ICDXDT_p;

  /* InitializeConditions for Backlash: '<S205>/Backlash' */
  localDW->PrevY_g = localP->Backlash_InitialOutput_d;

  /* InitializeConditions for SecondOrderIntegrator: '<S227>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_ak[0] =
    localP->IntegratorSecondOrder_ICX_f;
  localX->IntegratorSecondOrder_CSTATE_ak[1] =
    localP->IntegratorSecondOrder_ICDXDT_d;

  /* InitializeConditions for Integrator: '<S219>/Integrator' */
  localX->Integrator_CSTATE_jz = localP->Integrator_IC_o;

  /* InitializeConditions for Derivative: '<S219>/Derivative' */
  localDW->TimeStampA_g = (rtInf);
  localDW->TimeStampB_a = (rtInf);

  /* InitializeConditions for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */
  localX->IntegratorSecondOrder_CSTATE_l[0] =
    localP->IntegratorSecondOrder_ICX_l;
  localX->IntegratorSecondOrder_CSTATE_l[1] =
    localP->IntegratorSecondOrder_ICDXDT_f;

  /* InitializeConditions for Integrator: '<S214>/Integrator1' */
  localX->Integrator1_CSTATE_dc = localP->Integrator1_IC_a;

  /* InitializeConditions for Memory generated from: '<S220>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_c =
    localP->TmpLatchAtTriggeredSubsystemI_b;

  /* InitializeConditions for Memory generated from: '<S220>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_g =
    localP->TmpLatchAtTriggeredSubsystemI_m;

  /* InitializeConditions for Memory generated from: '<S221>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_a =
    localP->TmpLatchAtTriggeredSubsystemI_e;

  /* InitializeConditions for Memory generated from: '<S221>/Triggered Subsystem' */
  localDW->TmpLatchAtTriggeredSubsystemI_i =
    localP->TmpLatchAtTriggeredSubsystemI_h;

  /* InitializeConditions for Memory: '<S220>/Memory' */
  localDW->Memory_PreviousInput_o = localP->Memory_InitialCondition_m;

  /* InitializeConditions for Memory: '<S220>/Memory1' */
  localDW->Memory1_PreviousInput_f = localP->Memory1_InitialCondition_e;

  /* InitializeConditions for Memory: '<S221>/Memory' */
  localDW->Memory_PreviousInput_h = localP->Memory_InitialCondition_j;

  /* InitializeConditions for Memory: '<S221>/Memory1' */
  localDW->Memory1_PreviousInput_m = localP->Memory1_InitialCondition_o;

  /* InitializeConditions for Integrator: '<S393>/Integrator1' */
  localX->Integrator1_CSTATE_a[0] = localP->Integrator1_IC_g;
  localX->Integrator1_CSTATE_a[1] = localP->Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S411>/Integrator' */
  localX->Integrator_CSTATE_ez[0] = localP->Integrator_IC_j;
  localX->Integrator_CSTATE_ez[1] = localP->Integrator_IC_j;
  localX->Integrator_CSTATE_ez[2] = localP->Integrator_IC_j;

  /* InitializeConditions for Memory: '<S602>/Memory' */
  localDW->Memory_PreviousInput_l = localP->Memory_InitialCondition_b;

  /* InitializeConditions for Integrator: '<S602>/Integrator' incorporates:
   *  Integrator: '<S553>/Integrator'
   */
  if (rtmIsFirstInitCond((&ConfiguredVirtualVehicleMode_M))) {
    localX->Integrator_CSTATE_n = 0.0;
    localX->Integrator_CSTATE_d[0] = 0.0;
    localX->Integrator_CSTATE_d[1] = 0.0;
  }

  localDW->Integrator_IWORK_g = 1;

  /* End of InitializeConditions for Integrator: '<S602>/Integrator' */

  /* InitializeConditions for Integrator: '<S601>/Integrator' */
  localX->Integrator_CSTATE_e0 =
    ConfiguredVirtualVehicleModel_P->PlntDriveshftInitDeflect;

  /* InitializeConditions for Integrator: '<S553>/Integrator' */
  localDW->Integrator_IWORK_d = 1;

  /* InitializeConditions for TransferFcn: '<S658>/Motor Coupling Dynamics' */
  localX->MotorCouplingDynamics_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S644>/Integrator' incorporates:
   *  Integrator: '<S633>/Integrator Limited'
   */
  if (rtmIsFirstInitCond((&ConfiguredVirtualVehicleMode_M))) {
    localX->Integrator_CSTATE_a = 0.0;
    localX->IntegratorLimited_CSTATE = 0.0;
  }

  localDW->Integrator_IWORK_a = 1;

  /* End of InitializeConditions for Integrator: '<S644>/Integrator' */

  /* InitializeConditions for Integrator: '<S666>/Integrator' */
  localX->Integrator_CSTATE_l = localP->Integrator_IC_jd;

  /* InitializeConditions for Integrator: '<S633>/Integrator Limited' */
  localDW->IntegratorLimited_IWORK = 1;

  /* InitializeConditions for SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[0] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[1] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[2] =
    localP->IntegratorSecondOrderLimited_IC;
  localX->IntegratorSecondOrderLimited_CS[3] =
    localP->IntegratorSecondOrderLimited__i;

  /* InitializeConditions for SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__i[0] =
    localP->IntegratorSecondOrderLimited__e;

  /* InitializeConditions for SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[4] =
    localP->IntegratorSecondOrderLimited__i;

  /* InitializeConditions for SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__i[1] =
    localP->IntegratorSecondOrderLimited__e;

  /* InitializeConditions for SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited_CS[5] =
    localP->IntegratorSecondOrderLimited__i;

  /* InitializeConditions for SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' */
  localX->IntegratorSecondOrderLimited__i[2] =
    localP->IntegratorSecondOrderLimited__e;
  localX->IntegratorSecondOrderLimited__i[3] =
    localP->IntegratorSecondOrderLimited__a;
  localX->IntegratorSecondOrderLimited__i[4] =
    localP->IntegratorSecondOrderLimited__a;
  localX->IntegratorSecondOrderLimited__i[5] =
    localP->IntegratorSecondOrderLimited__a;

  /* SystemInitialize for Chart: '<S31>/State_Machine' */
  localDW->ChrgCntctState = Contact::Open;
  localDW->InvtrCntctState = Contact::Open;

  /* SystemInitialize for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* SystemInitialize for Chart: '<S527>/Clutch' */
    if (ForEach_itr > 2147483646) {
      i = MAX_int32_T;
    } else {
      i = ForEach_itr + 1;
    }

    /* Outputs for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
    /* SystemInitialize for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
    ConfiguredVirtualVe_Clutch_Init(localP->ClutchPartitionedParameters_ome[i -
      1], &localB->CoreSubsys_l[ForEach_itr].sf_Clutch, &localDW->
      CoreSubsys_l[ForEach_itr].sf_Clutch, &localP->CoreSubsys_l.sf_Clutch,
      &localX->CoreSubsys_l[ForEach_itr].sf_Clutch);

    /* End of SystemInitialize for Chart: '<S527>/Clutch' */
    /* End of SystemInitialize for SubSystem: '<S523>/Clutch Partitioned Parameters' */
    /* End of Outputs for SubSystem: '<S523>/Clutch Partitioned Parameters' */
  }

  /* End of SystemInitialize for SubSystem: '<S523>/Clutch Partitioned Parameters' */

  /* SystemInitialize for Iterator SubSystem: '<S435>/Unwrap' */
  for (ForEach_itr_a = 0; ForEach_itr_a < 3; ForEach_itr_a++) {
    /* InitializeConditions for Memory: '<S440>/Memory1' */
    localDW->CoreSubsys_n[ForEach_itr_a].Memory1_PreviousInput =
      localP->CoreSubsys_n.Memory1_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S440>/Function-Call Subsystem' */
    /* InitializeConditions for UnitDelay: '<S442>/Unit Delay' */
    localDW->CoreSubsys_n[ForEach_itr_a].UnitDelay_DSTATE =
      localP->CoreSubsys_n.UnitDelay_InitialCondition;

    /* SystemInitialize for Sum: '<S442>/Sum' incorporates:
     *  Outport: '<S442>/Out1'
     */
    localB->CoreSubsys_n[ForEach_itr_a].Sum = localP->CoreSubsys_n.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S440>/Function-Call Subsystem' */
    localZCE->CoreSubsys_n[ForEach_itr_a].FunctionCallSubsystem_Trig_ZCE =
      POS_ZCSIG;
  }

  /* End of SystemInitialize for SubSystem: '<S435>/Unwrap' */

  /* SystemInitialize for Triggered SubSystem: '<S133>/Triggered Subsystem' */
  Configu_TriggeredSubsystem_Init(&localB->TriggeredSubsystem,
    &localP->TriggeredSubsystem);

  /* End of SystemInitialize for SubSystem: '<S133>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  Configure_EnabledSubsystem_Init(&localB->EnabledSubsystem,
    &localP->EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  Configur_EnabledSubsystem1_Init(&localB->EnabledSubsystem1,
    &localP->EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S134>/Triggered Subsystem' */
  Configu_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_k,
    &localP->TriggeredSubsystem_k);

  /* End of SystemInitialize for SubSystem: '<S134>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S134>/Enabled Subsystem' */
  Configure_EnabledSubsystem_Init(&localB->EnabledSubsystem_h,
    &localP->EnabledSubsystem_h);

  /* End of SystemInitialize for SubSystem: '<S134>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S134>/Enabled Subsystem1' */
  Configur_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_d,
    &localP->EnabledSubsystem1_d);

  /* End of SystemInitialize for SubSystem: '<S134>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S220>/Triggered Subsystem' */
  Configu_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_e,
    &localP->TriggeredSubsystem_e);

  /* End of SystemInitialize for SubSystem: '<S220>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  Configure_EnabledSubsystem_Init(&localB->EnabledSubsystem_g,
    &localP->EnabledSubsystem_g);

  /* End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem1' */
  Configur_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_i,
    &localP->EnabledSubsystem1_i);

  /* End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem1' */

  /* SystemInitialize for Triggered SubSystem: '<S221>/Triggered Subsystem' */
  Configu_TriggeredSubsystem_Init(&localB->TriggeredSubsystem_l,
    &localP->TriggeredSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S221>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S221>/Enabled Subsystem' */
  Configure_EnabledSubsystem_Init(&localB->EnabledSubsystem_n,
    &localP->EnabledSubsystem_n);

  /* End of SystemInitialize for SubSystem: '<S221>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S221>/Enabled Subsystem1' */
  Configur_EnabledSubsystem1_Init(&localB->EnabledSubsystem1_j,
    &localP->EnabledSubsystem1_j);

  /* End of SystemInitialize for SubSystem: '<S221>/Enabled Subsystem1' */
}

/* Outputs for atomic system: '<Root>/AdasPlantModel' */
void ConfiguredVirtualVehicleModel::ConfiguredVirtua_AdasPlantModel(real_T
  rtu_DriverSteerCmd, real_T rtu_DriverAccelCmd, real_T rtu_DriverBrakeCmd,
  real_T rtu_DriverGearCmd, real_T rtu_AdasEnable, real_T rtu_AdasSteerCmd,
  real_T rtu_AdasLongTrq, real_T rtu_AdasGearCmd, real_T rty_VehFdbk[3],
  B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
  *localDW, P_AdasPlantModel_ConfiguredVi_T *localP,
  P_ConfiguredVirtualVehicleMod_T *ConfiguredVirtualVehicleModel_P,
  X_AdasPlantModel_ConfiguredVi_T *localX, ZCE_AdasPlantModel_Configured_T
  *localZCE)
{
  /* local block i/o variables */
  real_T rtb_Selector[2];
  real_T rtb_Selector1_j[2];
  real_T rtb_Selector2[2];
  real_T rtb_Selector3[2];
  real_T rtb_Selector_i[2];
  real_T rtb_Selector1_i[2];
  real_T rtb_IntegratorSecondOrder_o1;
  real_T rtb_Add2_i;
  real_T rtb_Add4;
  real_T rtb_Add2_d;
  real_T rtb_Add4_i;
  real_T rtb_Selector_i2[2];
  real_T rtb_Selector1_h[2];
  real_T rtb_Selector2_d[2];
  real_T rtb_Selector3_m[2];
  real_T rtb_Selector14[2];
  real_T rtb_Selector15[2];
  real_T rtb_IntegratorSecondOrder_o1_e;
  real_T rtb_Add2_m;
  real_T rtb_Add4_e;
  real_T rtb_Add2_n;
  real_T rtb_Add4_j;
  real_T rtb_ImpAsg_InsertedFor_Fsa_y_at[2];
  real_T rtb_ImpAsg_InsertedFor_Fsa_y__p[2];
  real_T rtb_TmpLatchAtTriggeredSubsyste;
  real_T rtb_TmpLatchAtTriggeredSubsys_p;
  real_T rtb_TmpLatchAtTriggeredSubsys_i;
  real_T rtb_TmpLatchAtTriggeredSubsys_g;
  real_T rtb_TmpLatchAtTriggeredSubsys_b;
  real_T rtb_TmpLatchAtTriggeredSubsys_m;
  real_T rtb_TmpLatchAtTriggeredSubsys_l;
  real_T rtb_TmpLatchAtTriggeredSubsy_b4;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_a;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_p;
  int32_T ForEach_itr_j;
  int32_T ForEach_itr_jh;
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
  real_T rtb_VectorConcatenate1[12];
  real_T rtb_VectorConcatenate8[12];
  real_T rtb_Ibar[9];
  real_T rtb_Reshape9to3x3columnmajor[9];
  real_T rtb_Transpose[9];
  real_T rtb_Transpose1[9];
  real_T rtb_Transpose1_c[9];
  real_T rtb_Transpose1_p[9];
  real_T rtb_VectorConcatenate_lq[9];
  real_T rtb_MatrixConcatenate2[8];
  real_T rtb_MatrixConcatenate3[8];
  real_T rtb_Abs_j[6];
  real_T tmp[6];
  real_T tmp_0[6];
  real_T Bykappa[4];
  real_T Eykappa[4];
  real_T FzUnSat[4];
  real_T Gykappa[4];
  real_T Kygammao[4];
  real_T Mzphiinf[4];
  real_T R_omega[4];
  real_T SHy[4];
  real_T Vsy[4];
  real_T b_x[4];
  real_T cosprimealpha[4];
  real_T dc_data[4];
  real_T dfz[4];
  real_T dpi[4];
  real_T epsilon_gamma[4];
  real_T lam_Cz[4];
  real_T lam_mux[4];
  real_T lam_muy[4];
  real_T phi[4];
  real_T phi_t[4];
  real_T rtb_Alpha[4];
  real_T rtb_ImpAsg_InsertedFor_Fx_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Fy_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Fz_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Mx_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_My_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Mz_at_in[4];
  real_T rtb_ImpAsg_InsertedFor_Omega_at[4];
  real_T rtb_ImpAsg_InsertedFor_VehFz_at[4];
  real_T rtb_ImpAsg_InsertedFor_WhlFz_at[4];
  real_T rtb_ImpAsg_InsertedFor_xdotWhee[4];
  real_T rtb_ImpAsg_InsertedFor_ydotWhee[4];
  real_T rtb_Kappa[4];
  real_T rtb_My[4];
  real_T rtb_Saturation[4];
  real_T rtb_Saturation_data[4];
  real_T rtb_Saturation_data_0[4];
  real_T rtb_Saturation_g[4];
  real_T rtb_UnaryMinus[4];
  real_T rtb_VectorConcatenate_j[4];
  real_T rtb_a[4];
  real_T rtb_b[4];
  real_T rtb_sig_x[4];
  real_T rtb_sig_y[4];
  real_T tmpDrphiVar_data[4];
  real_T rtb_Add_bl[3];
  real_T rtb_IntegratorSecondOrderLimite[3];
  real_T rtb_Product_o0[3];
  real_T rtb_Sum_c5[3];
  real_T rtb_Switch1_f[3];
  real_T rtb_V_wb_m[3];
  real_T rtb_VectorConcatenate_d[3];
  real_T rtb_sincos_o1[3];
  real_T rtb_ubvbwb[3];
  real_T rtb_UnaryMinus1_b[2];
  real_T Dx_tmp;
  real_T Dx_tmp_0;
  real_T Dx_tmp_1;
  real_T Dx_tmp_2;
  real_T Fzo_prime_idx_0;
  real_T Fzo_prime_idx_1;
  real_T Fzo_prime_idx_2;
  real_T Fzo_prime_idx_3;
  real_T Mzphiinf_0;
  real_T SteerCmd;
  real_T Vsy_0;
  real_T Vsy_tmp;
  real_T ab_idx_0;
  real_T dfz_0;
  real_T ec_data;
  real_T lam_Cz_0;
  real_T lam_Cz_tmp;
  real_T lam_Cz_tmp_0;
  real_T lam_muy_prime_idx_0;
  real_T lam_muy_prime_idx_1;
  real_T lam_muy_prime_idx_2;
  real_T lam_muy_prime_idx_3;
  real_T rtb_BattPackVolt;
  real_T rtb_ChrgCurrLmt;
  real_T rtb_DeadZone1;
  real_T rtb_DischrgCurrLmt;
  real_T rtb_Divide_ag;
  real_T rtb_Gain1;
  real_T rtb_Integrator1_f;
  real_T rtb_Integrator1_hl_idx_0;
  real_T rtb_Integrator1_hl_idx_1;
  real_T rtb_Integrator1_hl_idx_2;
  real_T rtb_Integrator1_hl_idx_3;
  real_T rtb_Integrator_ks_idx_0;
  real_T rtb_Integrator_ks_idx_1;
  real_T rtb_Integrator_ks_idx_2;
  real_T rtb_Integrator_ks_idx_3;
  real_T rtb_Product1_o_idx_1;
  real_T rtb_Product1_o_idx_3;
  real_T rtb_Product2_lv;
  real_T rtb_Product_pm;
  real_T rtb_SOC_CC;
  real_T rtb_Saturation1_idx_0;
  real_T rtb_Saturation1_idx_1;
  real_T rtb_Saturation1_idx_2;
  real_T rtb_Saturation_1;
  real_T rtb_Saturation_tmp;
  real_T rtb_Saturation_tmp_0;
  real_T rtb_Saturation_tmp_1;
  real_T rtb_Sum3_l;
  real_T rtb_Sum4_d;
  real_T rtb_Sum6_0;
  real_T rtb_Sum6_idx_0;
  real_T rtb_Sum6_idx_1;
  real_T rtb_Sum6_idx_2;
  real_T rtb_SumofElements15;
  real_T rtb_Switch_bk_idx_0;
  real_T rtb_Switch_bk_idx_1;
  real_T rtb_Switch_bk_idx_2;
  real_T rtb_Switch_bk_idx_3;
  real_T rtb_Transpose1_h;
  real_T rtb_Transpose1_h_0;
  real_T rtb_UnaryMinus2_idx_1;
  real_T rtb_UnaryMinus_c_idx_0;
  real_T rtb_UnaryMinus_c_idx_1;
  real_T rtb_UnaryMinus_c_idx_2;
  real_T rtb_UnitConversion_gd_idx_0;
  real_T rtb_UnitConversion_gd_idx_1;
  real_T rtb_UnitConversion_gd_idx_2;
  real_T rtb_UnitConversion_gd_idx_3;
  real_T rtb_V_wb_d_idx_2;
  real_T rtb_a_tmp_tmp;
  real_T rtb_b_tmp;
  real_T rtb_b_tmp_0;
  real_T rtb_b_tmp_1;
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
  real32_T rtb_CellTemperatures_g[96];
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
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* UnitDelay generated from: '<S26>/Unit Delay' */
    std::memcpy(&localB->CellVoltages[0], &localDW->UnitDelay_1_DSTATE[0], 96U *
                sizeof(real32_T));

    /* RateTransition: '<S26>/RT' */
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
      std::memcpy(&localDW->RT_Buffer[0], &localB->CellVoltages[0], 96U * sizeof
                  (real32_T));
    }
  }

  /* RateTransition: '<S26>/RT' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
    std::memcpy(&rtb_RT[0], &localDW->RT_Buffer[0], 96U * sizeof(real32_T));
  }

  /* RateTransition: '<S26>/RT2' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* MinMax: '<S33>/MinMax' */
    minV = localB->CellVoltages[0];
    for (iy = 0; iy < 95; iy++) {
      minV = std::fmin(minV, localB->CellVoltages[iy + 1]);
    }

    /* MinMax: '<S33>/MinMax' */
    localB->MinCellVolt = minV;

    /* MinMax: '<S33>/MinMax1' incorporates:
     *  UnitDelay generated from: '<S26>/Unit Delay'
     */
    minV = localDW->UnitDelay_4_DSTATE[0];

    /* MinMax: '<S33>/MinMax4' incorporates:
     *  UnitDelay generated from: '<S26>/Unit Delay'
     */
    maxV = localDW->UnitDelay_4_DSTATE[0];

    /* MinMax: '<S33>/MinMax2' */
    maxV_0 = localB->CellVoltages[0];
    for (iy = 0; iy < 95; iy++) {
      /* UnitDelay generated from: '<S26>/Unit Delay' incorporates:
       *  MinMax: '<S33>/MinMax1'
       *  MinMax: '<S33>/MinMax4'
       */
      minV_tmp = localDW->UnitDelay_4_DSTATE[iy + 1];

      /* MinMax: '<S33>/MinMax1' incorporates:
       *  UnitDelay generated from: '<S26>/Unit Delay'
       */
      minV = std::fmin(minV, minV_tmp);

      /* MinMax: '<S33>/MinMax4' */
      maxV = std::fmax(maxV, minV_tmp);

      /* MinMax: '<S33>/MinMax2' */
      maxV_0 = std::fmax(maxV_0, localB->CellVoltages[iy + 1]);
    }

    /* Gain: '<S35>/Np_Module' incorporates:
     *  Gain: '<S35>/MaxDchrgCurrLim'
     *  Lookup_n-D: '<S35>/HighTempDchrgCurrentLim'
     *  Lookup_n-D: '<S35>/LowTempDchrgCurrentLim'
     *  Lookup_n-D: '<S35>/MinCellVoltDchrgCurrentLim'
     *  MinMax: '<S33>/MinMax'
     *  MinMax: '<S33>/MinMax1'
     *  MinMax: '<S33>/MinMax4'
     *  MinMax: '<S35>/MinMax2'
     */
    localB->Np_Module = localP->MaxDchrgCurrLim_Gain * std::fmin(std::fmin
      (look1_iflf_binlcpw(localB->MinCellVolt,
                          localP->MinCellVoltDchrgCurrentLim_bp01,
                          localP->MinCellVoltDchrgCurrentLim_tabl, 2U),
       look1_iflf_binlcpw(minV, localP->LowTempDchrgCurrentLim_bp01Data,
                          localP->LowTempDchrgCurrentLim_tableDat, 6U)),
      look1_iflf_binlcpw(maxV, localP->HighTempDchrgCurrentLim_bp01Dat,
                         localP->HighTempDchrgCurrentLim_tableDa, 3U)) *
      static_cast<real32_T>
      (ConfiguredVirtualVehicleModel_P->PlntBattModNumCellPar);

    /* MinMax: '<S33>/MinMax2' */
    localB->MaxCellVolt = maxV_0;

    /* Gain: '<S34>/Np_Module' incorporates:
     *  Gain: '<S34>/MaxChrgCurrLim'
     *  Lookup_n-D: '<S34>/HighTempChrgCurrentLim'
     *  Lookup_n-D: '<S34>/LowTempChrgCurrentLim'
     *  Lookup_n-D: '<S34>/MaxCellVoltChrgCurrentLim'
     *  MinMax: '<S33>/MinMax1'
     *  MinMax: '<S33>/MinMax2'
     *  MinMax: '<S33>/MinMax4'
     *  MinMax: '<S34>/MinMax2'
     */
    localB->ChargeCurrentLimit = localP->MaxChrgCurrLim_Gain * std::fmin(std::
      fmin(look1_iflf_binlcpw(localB->MaxCellVolt,
      localP->MaxCellVoltChrgCurrentLim_bp01D,
      localP->MaxCellVoltChrgCurrentLim_table, 3U), look1_iflf_binlcpw(minV,
      localP->LowTempChrgCurrentLim_bp01Data,
      localP->LowTempChrgCurrentLim_tableData, 6U)), look1_iflf_binlcpw(maxV,
      localP->HighTempChrgCurrentLim_bp01Data,
      localP->HighTempChrgCurrentLim_tableDat, 4U)) * static_cast<real32_T>
      (ConfiguredVirtualVehicleModel_P->PlntBattModNumCellPar);

    /* UnitDelay generated from: '<S26>/Unit Delay' */
    localB->PackVoltage = localDW->UnitDelay_2_DSTATE;

    /* UnitDelay generated from: '<S26>/Unit Delay' */
    localB->VoutInvtr = localDW->UnitDelay_6_DSTATE;

    /* UnitDelay generated from: '<S26>/Unit Delay' */
    localB->PackCurrent = localDW->UnitDelay_3_DSTATE;

    /* Chart: '<S31>/State_Machine' incorporates:
     *  Constant: '<S26>/Constant'
     *  MinMax: '<S33>/MinMax1'
     *  MinMax: '<S33>/MinMax4'
     *  UnitDelay generated from: '<S26>/Unit Delay'
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

    if (localDW->is_active_c2_ConfiguredVirtualV == 0U) {
      localDW->is_active_c2_ConfiguredVirtualV = 1U;
      localDW->is_MainStateMachine = ConfiguredVirtualVeh_IN_Standby;
      localB->BMSState = 0.0F;
      localDW->is_ChargerContactorState = Configure_IN_OpenChgrContactors;
      localDW->ChrgCntctState = Contact::Init;
      localDW->is_OpenChgrContactors = Configured_IN_ClosePreChrgRly_d;
      localDW->temporalCounter_i2 = 0U;
      localDW->is_InverterContactorState = Configur_IN_OpenInvtrContactors;
      localDW->InvtrCntctState = Contact::Init;
      localDW->is_OpenInvtrContactors = Configured_IN_ClosePreChrgRly_d;
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
      ConfiguredVirt_MainStateMachine(localB, localDW, localP);
      if (localDW->is_ChargerContactorState == Configur_IN_CloseChgrContactors)
      {
        if ((localP->Constant_Value_nt != 1.0F) || localDW->FaultPresent) {
          localDW->is_CloseChgrContactors = ConfiguredVi_IN_NO_ACTIVE_CHILD;
          localDW->is_ChargerContactorState = Configure_IN_OpenChgrContactors;
          localDW->ChrgCntctState = Contact::Init;
          localDW->is_OpenChgrContactors = Configured_IN_ClosePreChrgRly_d;
          localDW->temporalCounter_i2 = 0U;
        } else {
          switch (localDW->is_CloseChgrContactors) {
           case ConfiguredVirt_IN_CloseNegCntct:
            if (localDW->temporalCounter_i2 * 100 >=
                localP->State_Machine_contactorTime) {
              localDW->is_CloseChgrContactors = ConfiguredVi_IN_ClosePreChrgRly;
              localDW->temporalCounter_i2 = 0U;
            }
            break;

           case ConfiguredVirt_IN_ClosePosCntct:
            if (localDW->temporalCounter_i2 * 100 >=
                localP->State_Machine_contactorTime) {
              localDW->is_CloseChgrContactors = ConfiguredVir_IN_OpenPreChrgRly;
              localDW->ChrgCntctState = Contact::Close;
            }
            break;

           case ConfiguredVi_IN_ClosePreChrgRly:
            if (localDW->UnitDelay_5_DSTATE / localB->PackVoltage >=
                localP->State_Machine_vRatio) {
              localDW->is_CloseChgrContactors = ConfiguredVirt_IN_ClosePosCntct;
              localDW->temporalCounter_i2 = 0U;
            } else if (localDW->temporalCounter_i2 >=
                       localP->State_Machine_timeoutContactor * 10) {
              localDW->is_CloseChgrContactors = ConfiguredVirtual_IN_PreChrgFlt;
            }
            break;

           case ConfiguredVir_IN_OpenPreChrgRly:
            localDW->ChrgCntctState = Contact::Close;
            break;

           default:
            /* case IN_PreChrgFlt: */
            break;
          }
        }

        /* case IN_OpenChgrContactors: */
      } else if ((localP->Constant_Value_nt == 1.0F) &&
                 (localDW->InvtrCntctState == Contact::Open) &&
                 (!localDW->FaultPresent)) {
        localDW->is_OpenChgrContactors = ConfiguredVi_IN_NO_ACTIVE_CHILD;
        localDW->is_ChargerContactorState = Configur_IN_CloseChgrContactors;
        localDW->ChrgCntctState = Contact::Init;
        localDW->is_CloseChgrContactors = ConfiguredVirt_IN_CloseNegCntct;
        localDW->temporalCounter_i2 = 0U;
      } else {
        switch (localDW->is_OpenChgrContactors) {
         case Configured_IN_ClosePreChrgRly_d:
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = ConfiguredVirtu_IN_OpenPosCntct;
            localDW->temporalCounter_i2 = 0U;
          }
          break;

         case ConfiguredVirtu_IN_OpenNegCntct:
          localDW->ChrgCntctState = Contact::Open;
          break;

         case ConfiguredVirtu_IN_OpenPosCntct:
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = ConfiguredVir_IN_OpenPreChrgRly;
            localDW->temporalCounter_i2 = 0U;
          }
          break;

         default:
          /* case IN_OpenPreChrgRly: */
          if (localDW->temporalCounter_i2 * 100 >=
              localP->State_Machine_contactorTime) {
            localDW->is_OpenChgrContactors = ConfiguredVirtu_IN_OpenNegCntct;
            localDW->ChrgCntctState = Contact::Open;
          }
          break;
        }
      }

      Configur_InverterContactorState(localB, localDW, localP);
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

    /* End of Chart: '<S31>/State_Machine' */

    /* RateTransition: '<S26>/RT1' */
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
      localDW->RT1_Buffer = localB->BMSState;
    }

    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
      localDW->RT2_Buffer = localB->MaxCellVolt;
    }
  }

  /* RateTransition: '<S26>/RT1' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
    rtb_RT1 = localDW->RT1_Buffer;
  }

  /* RateTransition: '<S26>/RT3' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) &&
      (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0)) {
    localDW->RT3_Buffer = localB->MinCellVolt;
  }

  /* RateTransition: '<S26>/RT2' incorporates:
   *  RateTransition: '<S26>/RT3'
   */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S27>/Balancing' */
    if (localDW->temporalCounter_i1_g < 8191U) {
      localDW->temporalCounter_i1_g = static_cast<uint16_T>
        (localDW->temporalCounter_i1_g + 1U);
    }

    if (localDW->is_active_c1_ConfiguredVirtualV == 0U) {
      localDW->is_active_c1_ConfiguredVirtualV = 1U;
      localDW->flgBalCompl = true;
      localDW->is_c1_ConfiguredVirtualVehicleM = ConfiguredVirtu_IN_BalancingOFF;
      localDW->temporalCounter_i1_g = 0U;
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
    } else if (localDW->is_c1_ConfiguredVirtualVehicleM ==
               ConfiguredVirtu_IN_BalancingOFF) {
      if (localP->Balancing_flgEnBalancing && (rtb_RT1 != 2.0F) &&
          (localDW->temporalCounter_i1_g * 5 >= localP->Balancing_BalOffWait) &&
          (localDW->DeltaCellVolt > localP->Balancing_TargetDeltaV)) {
        localDW->is_c1_ConfiguredVirtualVehicleM =
          ConfiguredVirtua_IN_BalancingON;
        localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
        localDW->is_BalancingON = ConfiguredVirtualV_IN_BalActive;
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
      localDW->is_BalancingON = ConfiguredVi_IN_NO_ACTIVE_CHILD;
      localDW->is_c1_ConfiguredVirtualVehicleM = ConfiguredVirtu_IN_BalancingOFF;
      localDW->temporalCounter_i1_g = 0U;
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
    } else {
      localDW->DeltaCellVolt = localDW->RT2_Buffer - localDW->RT3_Buffer;
      switch (localDW->is_BalancingON) {
       case ConfiguredVirtualV_IN_BalActive:
        if (localDW->flgBalCompl) {
          localDW->is_BalancingON = ConfiguredVirtu_IN_BalNotActive;
          localDW->temporalCounter_i1_g = 0U;
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
        i = localDW->temporalCounter_i1_g * 5;
        if ((i >= localP->Balancing_BalNotActWait) && (localDW->DeltaCellVolt >
             localP->Balancing_TargetDeltaV)) {
          localDW->is_BalancingON = ConfiguredVirtualV_IN_BalActive;
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
          localDW->is_BalancingON = ConfiguredVi_IN_NO_ACTIVE_CHILD;
          localDW->is_c1_ConfiguredVirtualVehicleM =
            ConfiguredVirtu_IN_BalancingOFF;
          localDW->temporalCounter_i1_g = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S27>/Balancing' */
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
    localB->SOC_CC = localDW->DiscreteTimeIntegrator_DSTATE;

    /* Product: '<S38>/Divide' incorporates:
     *  Constant: '<S38>/Constant'
     *  Gain: '<S38>/Gain'
     */
    localB->Divide_pf = localP->Gain_Gain_bp * localB->PackCurrent /
      static_cast<real32_T>(3.153 *
      ConfiguredVirtualVehicleModel_P->PlntBattModNumCellPar);
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Product: '<S631>/Product' incorporates:
     *  Constant: '<S631>/Constant1'
     *  Constant: '<S631>/Constant2'
     */
    localB->Product = ConfiguredVirtualVehicleModel_P->PlntBattNumCellSer *
      3.791 * ConfiguredVirtualVehicleModel_P->PlntBattTimeCnst;
  }

  /* Integrator: '<S631>/Integrator' */
  if (localDW->Integrator_IWORK != 0) {
    localX->Integrator_CSTATE_p = localB->Product;
  }

  /* Gain: '<S631>/Gain1' incorporates:
   *  Integrator: '<S631>/Integrator'
   */
  rtb_Gain1 = 1.0 / ConfiguredVirtualVehicleModel_P->PlntBattTimeCnst *
    localX->Integrator_CSTATE_p;

  /* DataTypeConversion: '<S628>/Data Type Conversion1' */
  localB->PackVoltage_h = static_cast<real32_T>(rtb_Gain1);

  /* RateTransition generated from: '<S628>/Rate Transition' incorporates:
   *  RateTransition: '<S22>/Rate Transition18'
   */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
      localDW->RateTransition_2_Buffer = localB->PackVoltage_h;
    }

    rtb_BattPackVolt = localDW->RateTransition18_Buffer
      [localDW->RateTransition18_ActiveBufIdx];
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S628>/Rate Transition' */
    localB->PackVoltage_l = localDW->RateTransition_2_Buffer;

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    localB->DataTypeConversion1 = localB->PackVoltage_l;

    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    localB->DataTypeConversion = localB->SOC_CC;

    /* DataTypeConversion: '<S22>/Data Type Conversion2' */
    localB->DataTypeConversion2 = localB->Np_Module;

    /* DataTypeConversion: '<S22>/Data Type Conversion3' */
    localB->DataTypeConversion3 = localB->ChargeCurrentLimit;
  }

  /* Integrator: '<S610>/Integrator' */
  localB->Spd = localX->Integrator_CSTATE_i;

  /* RateTransition: '<S22>/Rate Transition19' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    rtb_SOC_CC = localDW->RateTransition19_Buffer
      [localDW->RateTransition19_ActiveBufIdx];

    /* RateTransition: '<S22>/Rate Transition20' */
    rtb_DischrgCurrLmt = localDW->RateTransition20_Buffer
      [localDW->RateTransition20_ActiveBufIdx];

    /* RateTransition: '<S22>/Rate Transition21' */
    rtb_ChrgCurrLmt = localDW->RateTransition21_Buffer
      [localDW->RateTransition21_ActiveBufIdx];

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S49>/Rear Bias'
     *  DeadZone: '<S672>/Dead Zone1'
     *  Gain: '<S49>/Gain4'
     *  Product: '<S49>/Product'
     */
    if (rtu_AdasEnable > localP->Switch_Threshold_a) {
      /* Saturate: '<S46>/Saturation' */
      if (rtu_AdasLongTrq > localP->Saturation_UpperSat) {
        Vsy_0 = localP->Saturation_UpperSat;
      } else if (rtu_AdasLongTrq < localP->Saturation_LowerSat) {
        Vsy_0 = localP->Saturation_LowerSat;
      } else {
        Vsy_0 = rtu_AdasLongTrq;
      }

      /* Product: '<S46>/Divide' incorporates:
       *  Constant: '<S46>/Constant2'
       *  Gain: '<S46>/Gain'
       *  Saturate: '<S46>/Saturation'
       */
      rtb_Divide_ag = localP->Gain_Gain * Vsy_0 /
        (ConfiguredVirtualVehicleModel_P->PlntBrkKinFricCffFrnt *
         3.1415926535897931 * 0.0025000000000000005 *
         ConfiguredVirtualVehicleModel_P->PlntBrkPadMeanRadiusFrnt *
         ConfiguredVirtualVehicleModel_P->PlntBrkNumPadsFrnt / 4.0);

      /* Gain: '<S46>/FrontBiasGain' */
      rtb_DeadZone1 = ConfiguredVirtualVehicleModel_P->PlntBrkFrntBias *
        rtb_Divide_ag;

      /* Gain: '<S46>/RearBiasGain' */
      rtb_Divide_ag *= ConfiguredVirtualVehicleModel_P->PlntBrkRearBias;
      rtb_VectorConcatenate_j[0] = rtb_DeadZone1;
      rtb_VectorConcatenate_j[1] = rtb_DeadZone1;
      rtb_VectorConcatenate_j[2] = rtb_Divide_ag;
      rtb_VectorConcatenate_j[3] = rtb_Divide_ag;
    } else {
      if (rtu_DriverBrakeCmd > localP->DeadZone1_End) {
        /* DeadZone: '<S672>/Dead Zone1' */
        rtb_DeadZone1 = rtu_DriverBrakeCmd - localP->DeadZone1_End;
      } else if (rtu_DriverBrakeCmd >= localP->DeadZone1_Start) {
        /* DeadZone: '<S672>/Dead Zone1' */
        rtb_DeadZone1 = 0.0;
      } else {
        /* DeadZone: '<S672>/Dead Zone1' */
        rtb_DeadZone1 = rtu_DriverBrakeCmd - localP->DeadZone1_Start;
      }

      /* Gain: '<S49>/Gain4' incorporates:
       *  Constant: '<S49>/Front Bias'
       *  DeadZone: '<S672>/Dead Zone1'
       *  Product: '<S49>/Product'
       */
      rtb_Integrator_ks_idx_0 = ConfiguredVirtualVehicleModel_P->PlntBrkFrntBias
        * rtb_DeadZone1 * ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr;
      rtb_VectorConcatenate_j[0] = rtb_Integrator_ks_idx_0;
      rtb_VectorConcatenate_j[1] = rtb_Integrator_ks_idx_0;
      rtb_VectorConcatenate_j[2] =
        ConfiguredVirtualVehicleModel_P->PlntBrkRearBias * rtb_DeadZone1 *
        ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr;
      rtb_VectorConcatenate_j[3] =
        ConfiguredVirtualVehicleModel_P->PlntBrkRearBias * rtb_DeadZone1 *
        ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr;
    }

    /* End of Switch: '<S46>/Switch' */

    /* DeadZone: '<S96>/Dead Zone2' */
    if (rtu_DriverAccelCmd > localP->DeadZone2_End) {
      rtb_DeadZone1 = rtu_DriverAccelCmd - localP->DeadZone2_End;
    } else if (rtu_DriverAccelCmd >= localP->DeadZone2_Start) {
      rtb_DeadZone1 = 0.0;
    } else {
      rtb_DeadZone1 = rtu_DriverAccelCmd - localP->DeadZone2_Start;
    }

    /* End of DeadZone: '<S96>/Dead Zone2' */
  }

  /* End of RateTransition: '<S22>/Rate Transition19' */

  /* Integrator: '<S407>/ub,vb,wb' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  rtb_ubvbwb[0] = localX->ubvbwb_CSTATE[0];

  /* UnitConversion: '<S417>/Unit Conversion' incorporates:
   *  Integrator: '<S407>/ub,vb,wb'
   */
  localB->UnitConversion[0] = localX->ubvbwb_CSTATE[0];

  /* Integrator: '<S407>/ub,vb,wb' */
  rtb_ubvbwb[1] = localX->ubvbwb_CSTATE[1];

  /* UnitConversion: '<S417>/Unit Conversion' incorporates:
   *  Integrator: '<S407>/ub,vb,wb'
   */
  localB->UnitConversion[1] = localX->ubvbwb_CSTATE[1];

  /* Integrator: '<S407>/ub,vb,wb' */
  rtb_ubvbwb[2] = localX->ubvbwb_CSTATE[2];

  /* UnitConversion: '<S417>/Unit Conversion' incorporates:
   *  Integrator: '<S407>/ub,vb,wb'
   */
  localB->UnitConversion[2] = localX->ubvbwb_CSTATE[2];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S56>/Constant'
     *  RelationalOperator: '<S55>/Compare'
     *  RelationalOperator: '<S56>/Compare'
     */
    if (rtu_AdasEnable > localP->Switch_Threshold_g) {
      rtb_RelationalOperator = (rtu_AdasLongTrq >
        localP->CompareToConstant_const);
    } else {
      rtb_RelationalOperator = (rtb_DeadZone1 > localP->CompareToConstant1_const);
    }

    /* End of Switch: '<S50>/Switch' */

    /* Product: '<S70>/Product6' incorporates:
     *  Constant: '<S70>/Constant1'
     *  Constant: '<S70>/Constant2'
     *  Product: '<S70>/Product4'
     */
    rtb_Saturation1_idx_0 =
      ConfiguredVirtualVehicleModel_P->PlntBrkKinFricCffFrnt *
      3.1415926535897931 * 0.0025000000000000005 *
      ConfiguredVirtualVehicleModel_P->PlntBrkPadMeanRadiusFrnt *
      ConfiguredVirtualVehicleModel_P->PlntBrkNumPadsFrnt / 4.0;

    /* Sum: '<S70>/Add' incorporates:
     *  Constant: '<S70>/Constant2'
     *  Product: '<S70>/Product5'
     *  Product: '<S70>/Product6'
     */
    rtb_Sum4_d = rtb_Saturation1_idx_0 * rtb_VectorConcatenate_j[0] +
      rtb_Saturation1_idx_0 * rtb_VectorConcatenate_j[1];

    /* Lookup_n-D: '<S70>/RegenBrakingCutoff' */
    rtb_Sum3_l = look1_binlcapw(localB->UnitConversion[0],
      ConfiguredVirtualVehicleModel_P->CtrlVcuEvRegenBrkSpdBpt,
      ConfiguredVirtualVehicleModel_P->CtrlVcuEvRegenBrkCutOff, 1U);

    /* Gain: '<S53>/convert2percent' */
    rtb_Product2_lv = localP->convert2percent_Gain * rtb_SOC_CC;

    /* Product: '<S70>/Product3' incorporates:
     *  Gain: '<S70>/MotTrqReflectedToWheels'
     *  Gain: '<S70>/rads_to_rpm'
     *  Lookup_n-D: '<S70>/ChrgLmt'
     *  Lookup_n-D: '<S70>/MaxMotTrqVsSpd'
     *  MinMax: '<S70>/MinMax'
     *  Product: '<S448>/Product2'
     *  Product: '<S70>/Product1'
     */
    rtb_min = std::fmin(rtb_Sum4_d, look1_binlcapw(localP->rads_to_rpm_Gain_g *
      localB->Spd, localP->MaxMotTrqVsSpd_bp01Data,
      ConfiguredVirtualVehicleModel_P->PlntEM1Trq, 13U) *
                        ConfiguredVirtualVehicleModel_P->PlntDiffrntlRatio) *
      (rtb_Sum3_l * look1_binlcapw(rtb_Product2_lv,
        ConfiguredVirtualVehicleModel_P->CtrlVcuEvSocBpt,
        ConfiguredVirtualVehicleModel_P->CtrlVcuEvChrgLmtBpt, 10U));

    /* Switch: '<S50>/Accel Decel Switch' incorporates:
     *  Gain: '<S70>/Gain'
     *  Gain: '<S70>/WhlTrqReflectedToMot'
     *  Product: '<S45>/Product'
     */
    if (rtb_RelationalOperator) {
      /* Switch: '<S4>/Switch' */
      if (rtu_AdasEnable > localP->Switch_Threshold) {
        /* Switch: '<S4>/Switch' */
        localB->GearCmd = rtu_AdasGearCmd;
      } else {
        /* Switch: '<S4>/Switch' */
        localB->GearCmd = rtu_DriverGearCmd;
      }

      /* End of Switch: '<S4>/Switch' */

      /* Switch: '<S47>/Switch' incorporates:
       *  Gain: '<S48>/rads_to_rpm'
       *  Lookup_n-D: '<S48>/MaxEMTrqVsSpd'
       *  Product: '<S48>/Product1'
       */
      if (rtu_AdasEnable > localP->Switch_Threshold_i) {
        /* Saturate: '<S47>/Saturation' */
        if (rtu_AdasLongTrq > localP->Saturation_UpperSat_d) {
          rtb_SOC_CC = localP->Saturation_UpperSat_d;
        } else if (rtu_AdasLongTrq < localP->Saturation_LowerSat_l) {
          rtb_SOC_CC = localP->Saturation_LowerSat_l;
        } else {
          rtb_SOC_CC = rtu_AdasLongTrq;
        }

        /* End of Saturate: '<S47>/Saturation' */
      } else {
        rtb_SOC_CC = look1_binlcapw(localP->rads_to_rpm_Gain_b * localB->Spd,
          localP->MaxEMTrqVsSpd_bp01Data,
          ConfiguredVirtualVehicleModel_P->PlntEM1Trq, 13U) * rtb_DeadZone1;
      }

      /* End of Switch: '<S47>/Switch' */
      rtb_SOC_CC *= localB->GearCmd;
    } else {
      rtb_SOC_CC = 1.0 / ConfiguredVirtualVehicleModel_P->PlntDiffrntlRatio *
        rtb_min * localP->Gain_Gain_f;
    }

    /* End of Switch: '<S50>/Accel Decel Switch' */

    /* Switch: '<S57>/Switch1' incorporates:
     *  Abs: '<S57>/Abs'
     *  Constant: '<S59>/Constant'
     *  RelationalOperator: '<S59>/Compare'
     */
    if (!(std::abs(localB->Spd) < localP->CompareToConstant_const_n)) {
      /* Product: '<S51>/Product' incorporates:
       *  Gain: '<S51>/Gain1'
       */
      rtb_DischrgCurrLmt = localP->Gain1_Gain * rtb_DischrgCurrLmt *
        rtb_BattPackVolt;

      /* Product: '<S60>/Product' incorporates:
       *  Product: '<S60>/Product3'
       */
      Vsy_0 = localB->Spd * rtb_SOC_CC;

      /* Switch: '<S60>/Switch2' incorporates:
       *  Constant: '<S60>/Constant1'
       *  Constant: '<S60>/Constant2'
       *  Product: '<S60>/Product'
       */
      if (Vsy_0 >= localP->Switch2_Threshold) {
        rtb_DeadZone1 = localP->Constant1_Value;
      } else {
        rtb_DeadZone1 = localP->Constant2_Value;
      }

      /* End of Switch: '<S60>/Switch2' */

      /* Gain: '<S60>/Gain1' incorporates:
       *  Abs: '<S60>/Abs'
       *  Abs: '<S60>/Abs1'
       *  Gain: '<S60>/rads_to_rpm'
       *  Lookup_n-D: '<S60>/Eff Map'
       */
      rtb_Divide_ag = look2_binlcapw(std::abs(localP->rads_to_rpm_Gain *
        localB->Spd), std::abs(rtb_SOC_CC), localP->EffMap_bp01Data,
        ConfiguredVirtualVehicleModel_P->PlntEM1TrqEff,
        ConfiguredVirtualVehicleModel_P->PlntEM1EffTbl, localP->EffMap_maxIndex,
        14U) * localP->Gain1_Gain_i;

      /* Math: '<S60>/Math Function' */
      if ((rtb_Divide_ag < 0.0) && (rtb_DeadZone1 > std::floor(rtb_DeadZone1)))
      {
        rtb_DeadZone1 = -rt_powd_snf(-rtb_Divide_ag, rtb_DeadZone1);
      } else {
        rtb_DeadZone1 = rt_powd_snf(rtb_Divide_ag, rtb_DeadZone1);
      }

      /* End of Math: '<S60>/Math Function' */

      /* Product: '<S60>/Product4' */
      rtb_Divide_ag = Vsy_0 * rtb_DeadZone1;

      /* Product: '<S51>/Product1' incorporates:
       *  Gain: '<S51>/Gain'
       */
      rtb_BattPackVolt *= localP->Gain_Gain_d * rtb_ChrgCurrLmt;

      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S63>/Constant'
       *  Constant: '<S64>/Constant'
       *  Logic: '<S58>/Logical Operator'
       *  Product: '<S57>/ElecToMechPwr'
       *  Product: '<S57>/MechPwrToTrq'
       *  RelationalOperator: '<S63>/Compare'
       *  RelationalOperator: '<S64>/Compare'
       *  Sum: '<S58>/Subtract'
       *  Sum: '<S58>/Subtract1'
       */
      if ((!(rtb_DischrgCurrLmt - rtb_Divide_ag >= localP->Constant_Value_l)) ||
          (!(rtb_BattPackVolt - rtb_Divide_ag <= localP->Constant_Value_p))) {
        /* Switch: '<S62>/Switch' incorporates:
         *  Constant: '<S68>/Constant'
         *  Constant: '<S69>/Constant'
         *  Fcn: '<S62>/Fcn'
         *  Logic: '<S62>/Logical Operator'
         *  Product: '<S62>/Product'
         *  RelationalOperator: '<S68>/Compare'
         *  RelationalOperator: '<S69>/Compare'
         */
        if ((localB->Spd >= -localP->div0protectpoly_thresh) && (localB->Spd <=
             localP->div0protectpoly_thresh)) {
          /* Switch: '<S62>/Switch1' incorporates:
           *  Constant: '<S62>/Constant'
           *  UnaryMinus: '<S62>/Unary Minus'
           */
          if (localB->Spd >= localP->Switch1_Threshold) {
            rtb_ChrgCurrLmt = localP->Constant_Value_pc;
          } else {
            rtb_ChrgCurrLmt = -localP->Constant_Value_pc;
          }

          /* End of Switch: '<S62>/Switch1' */
          rtb_ChrgCurrLmt *= 4.0 / (3.0 - rt_powd_snf(localB->Spd / 2.0, 2.0));
        } else {
          rtb_ChrgCurrLmt = localB->Spd;
        }

        /* End of Switch: '<S62>/Switch' */

        /* Switch: '<S65>/Switch2' incorporates:
         *  RelationalOperator: '<S65>/LowerRelop1'
         */
        if (!(rtb_Divide_ag > rtb_DischrgCurrLmt)) {
          /* Switch: '<S65>/Switch' incorporates:
           *  RelationalOperator: '<S65>/UpperRelop'
           */
          if (rtb_Divide_ag < rtb_BattPackVolt) {
            rtb_DischrgCurrLmt = rtb_BattPackVolt;
          } else {
            rtb_DischrgCurrLmt = rtb_Divide_ag;
          }

          /* End of Switch: '<S65>/Switch' */
        }

        /* End of Switch: '<S65>/Switch2' */
        rtb_SOC_CC = rtb_DischrgCurrLmt / rtb_DeadZone1 / rtb_ChrgCurrLmt;
      }

      /* End of Switch: '<S57>/Switch' */
    }

    /* End of Switch: '<S57>/Switch1' */

    /* Lookup_n-D: '<S61>/MaxEMTrqVsSpd' incorporates:
     *  Gain: '<S61>/rads_to_rpm'
     */
    rtb_BattPackVolt = look1_binlcapw(localP->rads_to_rpm_Gain_a * localB->Spd,
      localP->MaxEMTrqVsSpd_bp01Data_o,
      ConfiguredVirtualVehicleModel_P->PlntEM1Trq, 13U);

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/Constant'
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Compare'
     */
    if (rtb_Product2_lv > localP->CompareToConstant_const_l) {
      rtb_Product2_lv = rtb_BattPackVolt;
    } else {
      rtb_Product2_lv = localP->Constant_Value;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Switch: '<S67>/Switch2' incorporates:
     *  RelationalOperator: '<S67>/LowerRelop1'
     */
    if (rtb_SOC_CC > rtb_Product2_lv) {
      /* Switch: '<S67>/Switch2' */
      localB->Switch2 = rtb_Product2_lv;
    } else {
      /* Gain: '<S61>/Gain' */
      rtb_Product2_lv = localP->Gain_Gain_p * rtb_BattPackVolt;

      /* Switch: '<S67>/Switch' incorporates:
       *  RelationalOperator: '<S67>/UpperRelop'
       */
      if (rtb_SOC_CC < rtb_Product2_lv) {
        /* Switch: '<S67>/Switch2' */
        localB->Switch2 = rtb_Product2_lv;
      } else {
        /* Switch: '<S67>/Switch2' */
        localB->Switch2 = rtb_SOC_CC;
      }

      /* End of Switch: '<S67>/Switch' */
    }

    /* End of Switch: '<S67>/Switch2' */

    /* Sum: '<S70>/Subtract' */
    rtb_Sum4_d -= rtb_min;

    /* Saturate: '<S70>/Negative 5' */
    if (rtb_Sum4_d > localP->Negative5_UpperSat) {
      rtb_Sum4_d = localP->Negative5_UpperSat;
    } else if (rtb_Sum4_d < localP->Negative5_LowerSat) {
      rtb_Sum4_d = localP->Negative5_LowerSat;
    }

    /* End of Saturate: '<S70>/Negative 5' */

    /* Gain: '<S70>/Gain6' incorporates:
     *  Constant: '<S70>/Constant1'
     *  Product: '<S70>/Product4'
     */
    rtb_Product2_lv = rtb_Sum4_d / (rtb_Saturation1_idx_0 * 2.0) * (1.0 /
      ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr);

    /* Saturate: '<S70>/Saturation' */
    if (rtb_Product2_lv > localP->Saturation_UpperSat_p) {
      rtb_Product2_lv = localP->Saturation_UpperSat_p;
    } else if (rtb_Product2_lv < localP->Saturation_LowerSat_d) {
      rtb_Product2_lv = localP->Saturation_LowerSat_d;
    }

    /* End of Saturate: '<S70>/Saturation' */

    /* SignalConversion generated from: '<S70>/Vector Concatenate' */
    rtb_UnitConversion_gd_idx_0 = rtb_Product2_lv;

    /* SignalConversion generated from: '<S70>/Vector Concatenate' */
    rtb_UnitConversion_gd_idx_1 = rtb_Product2_lv;

    /* Gain: '<S70>/Gain8' */
    rtb_Product_pm = 1.0 / ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr;

    /* SignalConversion generated from: '<S70>/Vector Concatenate' incorporates:
     *  Gain: '<S70>/Gain8'
     */
    rtb_UnitConversion_gd_idx_2 = rtb_Product_pm * rtb_VectorConcatenate_j[2];

    /* SignalConversion generated from: '<S70>/Vector Concatenate' incorporates:
     *  Gain: '<S70>/Gain8'
     */
    rtb_UnitConversion_gd_idx_3 = rtb_Product_pm * rtb_VectorConcatenate_j[3];

    /* Constant: '<S5>/Constant3' incorporates:
     *  Concatenate: '<S5>/Vector Concatenate'
     */
    localB->Wind[0] = ConfiguredVirtualVehicleModel_P->EnvWindVelX;

    /* Constant: '<S5>/Constant4' incorporates:
     *  Concatenate: '<S5>/Vector Concatenate'
     */
    localB->Wind[1] = ConfiguredVirtualVehicleModel_P->EnvWindVelY;

    /* Constant: '<S5>/Constant5' incorporates:
     *  Concatenate: '<S5>/Vector Concatenate'
     */
    localB->Wind[2] = ConfiguredVirtualVehicleModel_P->EnvWindVelZ;

    /* SignalConversion generated from: '<S76>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S76>/Vector Concatenate1'
     *  Constant: '<S74>/Constant1'
     */
    localB->VectorConcatenate1[0] = localP->Constant1_Value_f[0];

    /* SignalConversion generated from: '<S76>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S76>/Vector Concatenate1'
     *  Constant: '<S74>/Constant1'
     */
    localB->VectorConcatenate1[1] = localP->Constant1_Value_f[1];

    /* SignalConversion generated from: '<S76>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S76>/Vector Concatenate1'
     *  Constant: '<S74>/Constant1'
     */
    localB->VectorConcatenate1[2] = localP->Constant1_Value_f[2];

    /* SignalConversion generated from: '<S76>/Vector Concatenate1' incorporates:
     *  Concatenate: '<S76>/Vector Concatenate1'
     *  Constant: '<S74>/Constant1'
     */
    localB->VectorConcatenate1[3] = localP->Constant1_Value_f[3];

    /* SignalConversion generated from: '<S76>/Vector Concatenate' incorporates:
     *  Constant: '<S75>/Friction Scaling'
     */
    rtb_VectorConcatenate_j[0] =
      ConfiguredVirtualVehicleModel_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S76>/Vector Concatenate' incorporates:
     *  Constant: '<S75>/Friction Scaling'
     */
    rtb_VectorConcatenate_j[1] =
      ConfiguredVirtualVehicleModel_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S76>/Vector Concatenate' incorporates:
     *  Constant: '<S75>/Friction Scaling'
     */
    rtb_VectorConcatenate_j[2] =
      ConfiguredVirtualVehicleModel_P->EnvNomFrictionScaling;

    /* SignalConversion generated from: '<S76>/Vector Concatenate' incorporates:
     *  Constant: '<S75>/Friction Scaling'
     */
    rtb_VectorConcatenate_j[3] =
      ConfiguredVirtualVehicleModel_P->EnvNomFrictionScaling;
  }

  /* Switch: '<S4>/Switch1' */
  if (rtu_AdasEnable > localP->Switch1_Threshold_n) {
    /* Switch: '<S4>/Switch1' */
    SteerCmd = rtu_AdasSteerCmd;
  } else {
    /* Switch: '<S4>/Switch1' */
    SteerCmd = rtu_DriverSteerCmd;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* FirstOrderHold: '<S80>/First Order Hold' */
  localB->EMTrqCmd = localDW->Ck;

  /* FirstOrderHold: '<S80>/First Order Hold' */
  if (localDW->Tk != (rtInf)) {
    /* FirstOrderHold: '<S80>/First Order Hold' */
    localB->EMTrqCmd += ((&ConfiguredVirtualVehicleMode_M)->Timing.t[0] -
                         localDW->Tk) * localDW->Mk;
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* DeadZone: '<S105>/Dead Zone' */
    if (rtb_UnitConversion_gd_idx_0 > localP->DeadZone_End) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[0] = rtb_UnitConversion_gd_idx_0 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_gd_idx_0 >= localP->DeadZone_Start) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[0] = 0.0;
    } else {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[0] = rtb_UnitConversion_gd_idx_0 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_gd_idx_1 > localP->DeadZone_End) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[1] = rtb_UnitConversion_gd_idx_1 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_gd_idx_1 >= localP->DeadZone_Start) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[1] = 0.0;
    } else {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[1] = rtb_UnitConversion_gd_idx_1 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_gd_idx_2 > localP->DeadZone_End) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[2] = rtb_UnitConversion_gd_idx_2 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_gd_idx_2 >= localP->DeadZone_Start) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[2] = 0.0;
    } else {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[2] = rtb_UnitConversion_gd_idx_2 - localP->DeadZone_Start;
    }

    if (rtb_UnitConversion_gd_idx_3 > localP->DeadZone_End) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[3] = rtb_UnitConversion_gd_idx_3 - localP->DeadZone_End;
    } else if (rtb_UnitConversion_gd_idx_3 >= localP->DeadZone_Start) {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[3] = 0.0;
    } else {
      /* DeadZone: '<S105>/Dead Zone' */
      localB->DeadZone[3] = rtb_UnitConversion_gd_idx_3 - localP->DeadZone_Start;
    }

    /* End of DeadZone: '<S105>/Dead Zone' */
  }

  /* Product: '<S106>/Divide' incorporates:
   *  Constant: '<S106>/Constant'
   *  Integrator: '<S106>/Integrator1'
   *  Sum: '<S106>/Sum'
   */
  localB->Divide[0] = (localB->DeadZone[0] - localX->Integrator1_CSTATE_h[0]) *
    ConfiguredVirtualVehicleModel_P->PlntBrkWc;

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator[0] = localX->Integrator_CSTATE_e[0];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[0] = localX->Integrator_CSTATE_e[0];

  /* Integrator: '<S518>/Integrator' */
  localB->Integrator_h[0] = localX->Integrator_CSTATE_c[0];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S518>/Integrator'
   */
  rtb_VectorConcatenate8[4] = localX->Integrator_CSTATE_c[0];

  /* Integrator: '<S374>/Integrator1' */
  rtb_Integrator1_hl_idx_0 = localX->Integrator1_CSTATE_n[0];

  /* Saturate: '<S287>/Saturation' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_n[0] > localP->Saturation_UpperSat_e) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_UpperSat_e;
  } else if (localX->Integrator1_CSTATE_n[0] < localP->Saturation_LowerSat_p) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_LowerSat_p;
  } else {
    rtb_UnitConversion_gd_idx_3 = localX->Integrator1_CSTATE_n[0];
  }

  rtb_UnitConversion_gd_idx_0 = rtb_UnitConversion_gd_idx_3;

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' */
  rtb_VectorConcatenate8[8] = rtb_UnitConversion_gd_idx_3;

  /* Product: '<S106>/Divide' incorporates:
   *  Constant: '<S106>/Constant'
   *  Integrator: '<S106>/Integrator1'
   *  Sum: '<S106>/Sum'
   */
  localB->Divide[1] = (localB->DeadZone[1] - localX->Integrator1_CSTATE_h[1]) *
    ConfiguredVirtualVehicleModel_P->PlntBrkWc;

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator[1] = localX->Integrator_CSTATE_e[1];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[1] = localX->Integrator_CSTATE_e[1];

  /* Integrator: '<S518>/Integrator' */
  localB->Integrator_h[1] = localX->Integrator_CSTATE_c[1];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S518>/Integrator'
   */
  rtb_VectorConcatenate8[5] = localX->Integrator_CSTATE_c[1];

  /* Integrator: '<S374>/Integrator1' */
  rtb_Integrator1_hl_idx_1 = localX->Integrator1_CSTATE_n[1];

  /* Saturate: '<S287>/Saturation' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_n[1] > localP->Saturation_UpperSat_e) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_UpperSat_e;
  } else if (localX->Integrator1_CSTATE_n[1] < localP->Saturation_LowerSat_p) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_LowerSat_p;
  } else {
    rtb_UnitConversion_gd_idx_3 = localX->Integrator1_CSTATE_n[1];
  }

  rtb_UnitConversion_gd_idx_1 = rtb_UnitConversion_gd_idx_3;

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' */
  rtb_VectorConcatenate8[9] = rtb_UnitConversion_gd_idx_3;

  /* Product: '<S106>/Divide' incorporates:
   *  Constant: '<S106>/Constant'
   *  Integrator: '<S106>/Integrator1'
   *  Sum: '<S106>/Sum'
   */
  localB->Divide[2] = (localB->DeadZone[2] - localX->Integrator1_CSTATE_h[2]) *
    ConfiguredVirtualVehicleModel_P->PlntBrkWc;

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator[2] = localX->Integrator_CSTATE_e[2];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[2] = localX->Integrator_CSTATE_e[2];

  /* Integrator: '<S518>/Integrator' */
  localB->Integrator_h[2] = localX->Integrator_CSTATE_c[2];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S518>/Integrator'
   */
  rtb_VectorConcatenate8[6] = localX->Integrator_CSTATE_c[2];

  /* Integrator: '<S374>/Integrator1' */
  rtb_Integrator1_hl_idx_2 = localX->Integrator1_CSTATE_n[2];

  /* Saturate: '<S287>/Saturation' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_n[2] > localP->Saturation_UpperSat_e) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_UpperSat_e;
  } else if (localX->Integrator1_CSTATE_n[2] < localP->Saturation_LowerSat_p) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_LowerSat_p;
  } else {
    rtb_UnitConversion_gd_idx_3 = localX->Integrator1_CSTATE_n[2];
  }

  rtb_UnitConversion_gd_idx_2 = rtb_UnitConversion_gd_idx_3;

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' */
  rtb_VectorConcatenate8[10] = rtb_UnitConversion_gd_idx_3;

  /* Product: '<S106>/Divide' incorporates:
   *  Constant: '<S106>/Constant'
   *  Integrator: '<S106>/Integrator1'
   *  Sum: '<S106>/Sum'
   */
  localB->Divide[3] = (localB->DeadZone[3] - localX->Integrator1_CSTATE_h[3]) *
    ConfiguredVirtualVehicleModel_P->PlntBrkWc;

  /* Integrator: '<S517>/Integrator' */
  localB->Integrator[3] = localX->Integrator_CSTATE_e[3];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S517>/Integrator'
   */
  rtb_VectorConcatenate8[3] = localX->Integrator_CSTATE_e[3];

  /* Integrator: '<S518>/Integrator' */
  localB->Integrator_h[3] = localX->Integrator_CSTATE_c[3];

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' incorporates:
   *  Integrator: '<S518>/Integrator'
   */
  rtb_VectorConcatenate8[7] = localX->Integrator_CSTATE_c[3];

  /* Integrator: '<S374>/Integrator1' */
  rtb_Integrator1_hl_idx_3 = localX->Integrator1_CSTATE_n[3];

  /* Saturate: '<S287>/Saturation' incorporates:
   *  Integrator: '<S374>/Integrator1'
   */
  if (localX->Integrator1_CSTATE_n[3] > localP->Saturation_UpperSat_e) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_UpperSat_e;
  } else if (localX->Integrator1_CSTATE_n[3] < localP->Saturation_LowerSat_p) {
    rtb_UnitConversion_gd_idx_3 = localP->Saturation_LowerSat_p;
  } else {
    rtb_UnitConversion_gd_idx_3 = localX->Integrator1_CSTATE_n[3];
  }

  /* SignalConversion generated from: '<S288>/Vector Concatenate8' */
  rtb_VectorConcatenate8[11] = rtb_UnitConversion_gd_idx_3;
  for (i = 0; i < 4; i++) {
    /* Math: '<S288>/Math Function' incorporates:
     *  Concatenate: '<S288>/Vector Concatenate8'
     */
    localB->MathFunction[3 * i] = rtb_VectorConcatenate8[i];
    localB->MathFunction[3 * i + 1] = rtb_VectorConcatenate8[i + 4];
    localB->MathFunction[3 * i + 2] = rtb_VectorConcatenate8[i + 8];
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S580>/Memory' */
    localB->Memory = localDW->Memory_PreviousInput;

    /* Constant: '<S579>/domega_o' */
    localB->domega_o = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S580>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE,
                       (localB->Memory));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_n != 0)) {
      localX->Integrator_CSTATE_m = localB->domega_o;
    }
  }

  rtb_BattPackVolt = localX->Integrator_CSTATE_m;

  /* Sum: '<S579>/Subtract1' incorporates:
   *  Gain: '<S579>/Gain1'
   *  Gain: '<S579>/Gain2'
   *  Integrator: '<S579>/Integrator'
   *  Integrator: '<S580>/Integrator'
   */
  rtb_ChrgCurrLmt = ConfiguredVirtualVehicleModel_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_m +
    ConfiguredVirtualVehicleModel_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_f;

  /* SignalConversion generated from: '<S541>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S541>/Vector Concatenate1'
   */
  localB->VectorConcatenate1_f[0] = rtb_ChrgCurrLmt;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S588>/Memory' */
    localB->Memory_h = localDW->Memory_PreviousInput_e;

    /* Constant: '<S587>/domega_o' */
    localB->domega_o_o = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S588>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE_j,
                       (localB->Memory_h));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_m != 0)) {
      localX->Integrator_CSTATE_j = localB->domega_o_o;
    }
  }

  rtb_min = localX->Integrator_CSTATE_j;

  /* Sum: '<S587>/Subtract1' incorporates:
   *  Gain: '<S587>/Gain1'
   *  Gain: '<S587>/Gain2'
   *  Integrator: '<S587>/Integrator'
   *  Integrator: '<S588>/Integrator'
   */
  rtb_DischrgCurrLmt = ConfiguredVirtualVehicleModel_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_j +
    ConfiguredVirtualVehicleModel_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_cw;

  /* SignalConversion generated from: '<S541>/Vector Concatenate1' incorporates:
   *  Concatenate: '<S541>/Vector Concatenate1'
   */
  localB->VectorConcatenate1_f[1] = rtb_DischrgCurrLmt;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S596>/Constant1' incorporates:
     *  Concatenate: '<S541>/Vector Concatenate1'
     */
    localB->VectorConcatenate1_f[2] = localP->Constant1_Value_fm;

    /* Constant: '<S596>/Constant3' incorporates:
     *  Concatenate: '<S541>/Vector Concatenate1'
     */
    localB->VectorConcatenate1_f[3] = localP->Constant3_Value;
  }

  /* Integrator: '<S520>/Integrator' */
  rtb_Integrator_ks_idx_0 = localX->Integrator_CSTATE_cf[0];

  /* SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  rtb_Saturation1_idx_0 = localX->IntegratorSecondOrder_CSTATE[0];
  rtb_Switch_bk_idx_0 = localX->IntegratorSecondOrder_CSTATE[4];

  /* Sum: '<S521>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   */
  rtb_Sum6_0 = localB->VectorConcatenate1[0] -
    localX->IntegratorSecondOrder_CSTATE[0];
  rtb_Sum6_idx_0 = rtb_Sum6_0;

  /* Saturate: '<S521>/Saturation' */
  if (rtb_Sum6_0 > localP->Saturation_UpperSat_i) {
    rtb_Saturation_1 = localP->Saturation_UpperSat_i;
  } else if (rtb_Sum6_0 < localP->Saturation_LowerSat_ln) {
    rtb_Saturation_1 = localP->Saturation_LowerSat_ln;
  } else {
    rtb_Saturation_1 = rtb_Sum6_0;
  }

  rtb_Saturation[0] = rtb_Saturation_1;

  /* Sum: '<S516>/Add2' incorporates:
   *  Constant: '<S516>/Constant9'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius -
    rtb_Saturation_1;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_do) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_do;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_dz) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_dz;
  }

  /* Sum: '<S516>/Add1' incorporates:
   *  Integrator: '<S520>/Integrator'
   *  Product: '<S516>/Product3'
   *  Saturate: '<S516>/Saturation'
   */
  localB->Add1[0] = (localB->Integrator[0] * rtb_Product1_o_idx_3 -
                     localB->VectorConcatenate1_f[0]) -
    localX->Integrator_CSTATE_cf[0];

  /* Integrator: '<S520>/Integrator' */
  rtb_Integrator_ks_idx_1 = localX->Integrator_CSTATE_cf[1];

  /* SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  rtb_Saturation1_idx_1 = localX->IntegratorSecondOrder_CSTATE[1];
  rtb_Switch_bk_idx_1 = localX->IntegratorSecondOrder_CSTATE[5];

  /* Sum: '<S521>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   */
  rtb_Sum6_0 = localB->VectorConcatenate1[1] -
    localX->IntegratorSecondOrder_CSTATE[1];
  rtb_Sum6_idx_1 = rtb_Sum6_0;

  /* Saturate: '<S521>/Saturation' */
  if (rtb_Sum6_0 > localP->Saturation_UpperSat_i) {
    rtb_Saturation_1 = localP->Saturation_UpperSat_i;
  } else if (rtb_Sum6_0 < localP->Saturation_LowerSat_ln) {
    rtb_Saturation_1 = localP->Saturation_LowerSat_ln;
  } else {
    rtb_Saturation_1 = rtb_Sum6_0;
  }

  rtb_Saturation[1] = rtb_Saturation_1;

  /* Sum: '<S516>/Add2' incorporates:
   *  Constant: '<S516>/Constant9'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius -
    rtb_Saturation_1;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_do) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_do;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_dz) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_dz;
  }

  /* Sum: '<S516>/Add1' incorporates:
   *  Integrator: '<S520>/Integrator'
   *  Product: '<S516>/Product3'
   *  Saturate: '<S516>/Saturation'
   */
  localB->Add1[1] = (localB->Integrator[1] * rtb_Product1_o_idx_3 -
                     localB->VectorConcatenate1_f[1]) -
    localX->Integrator_CSTATE_cf[1];

  /* Integrator: '<S520>/Integrator' */
  rtb_Integrator_ks_idx_2 = localX->Integrator_CSTATE_cf[2];

  /* SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  rtb_Saturation1_idx_2 = localX->IntegratorSecondOrder_CSTATE[2];
  rtb_Switch_bk_idx_2 = localX->IntegratorSecondOrder_CSTATE[6];

  /* Sum: '<S521>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   */
  rtb_Sum6_0 = localB->VectorConcatenate1[2] -
    localX->IntegratorSecondOrder_CSTATE[2];
  rtb_Sum6_idx_2 = rtb_Sum6_0;

  /* Saturate: '<S521>/Saturation' */
  if (rtb_Sum6_0 > localP->Saturation_UpperSat_i) {
    rtb_Saturation_1 = localP->Saturation_UpperSat_i;
  } else if (rtb_Sum6_0 < localP->Saturation_LowerSat_ln) {
    rtb_Saturation_1 = localP->Saturation_LowerSat_ln;
  } else {
    rtb_Saturation_1 = rtb_Sum6_0;
  }

  rtb_Saturation[2] = rtb_Saturation_1;

  /* Sum: '<S516>/Add2' incorporates:
   *  Constant: '<S516>/Constant9'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius -
    rtb_Saturation_1;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_do) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_do;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_dz) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_dz;
  }

  /* Sum: '<S516>/Add1' incorporates:
   *  Integrator: '<S520>/Integrator'
   *  Product: '<S516>/Product3'
   *  Saturate: '<S516>/Saturation'
   */
  localB->Add1[2] = (localB->Integrator[2] * rtb_Product1_o_idx_3 -
                     localB->VectorConcatenate1_f[2]) -
    localX->Integrator_CSTATE_cf[2];

  /* Integrator: '<S520>/Integrator' */
  rtb_Integrator_ks_idx_3 = localX->Integrator_CSTATE_cf[3];

  /* SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  rtb_SumofElements15 = localX->IntegratorSecondOrder_CSTATE[3];
  rtb_Switch_bk_idx_3 = localX->IntegratorSecondOrder_CSTATE[7];

  /* Sum: '<S521>/Sum6' incorporates:
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   */
  rtb_Sum6_0 = localB->VectorConcatenate1[3] -
    localX->IntegratorSecondOrder_CSTATE[3];

  /* Saturate: '<S521>/Saturation' */
  if (rtb_Sum6_0 > localP->Saturation_UpperSat_i) {
    rtb_Saturation_1 = localP->Saturation_UpperSat_i;
  } else if (rtb_Sum6_0 < localP->Saturation_LowerSat_ln) {
    rtb_Saturation_1 = localP->Saturation_LowerSat_ln;
  } else {
    rtb_Saturation_1 = rtb_Sum6_0;
  }

  rtb_Saturation[3] = rtb_Saturation_1;

  /* Sum: '<S516>/Add2' incorporates:
   *  Constant: '<S516>/Constant9'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius -
    rtb_Saturation_1;

  /* Saturate: '<S516>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_do) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_do;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_dz) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_dz;
  }

  /* Sum: '<S516>/Add1' incorporates:
   *  Integrator: '<S520>/Integrator'
   *  Product: '<S516>/Product3'
   *  Saturate: '<S516>/Saturation'
   */
  localB->Add1[3] = (localB->Integrator[3] * rtb_Product1_o_idx_3 -
                     localB->VectorConcatenate1_f[3]) -
    localX->Integrator_CSTATE_cf[3];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S526>/Torque Conversion1' incorporates:
     *  Constant: '<S526>/Disk brake actuator bore'
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

  /* Product: '<S526>/product' incorporates:
   *  Constant: '<S105>/Front Bias'
   *  Constant: '<S526>/Disk brake actuator bore'
   *  Constant: '<S526>/Number of brake pads'
   *  Gain: '<S105>/Gain4'
   *  Integrator: '<S106>/Integrator1'
   *  Product: '<S105>/Product'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntBrkFrntBias *
    localX->Integrator1_CSTATE_h[0] *
    ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr * localB->TorqueConversion1
    [0] * localP->CombinedSlipWheel2DOF_disk_abor[0] *
    localP->CombinedSlipWheel2DOF_num_pads[0];

  /* Saturate: '<S526>/Disallow Negative Brake Torque' */
  if (rtb_Product1_o_idx_3 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_Product1_o_idx_3 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S526>/Torque Conversion' incorporates:
   *  Saturate: '<S526>/Disallow Negative Brake Torque'
   */
  rtb_DeadZone1 = localP->CombinedSlipWheel2DOF_Rm[0] *
    localP->CombinedSlipWheel2DOF_mu_kineti[0] * rtb_Product1_o_idx_3;

  /* Product: '<S526>/product' incorporates:
   *  Constant: '<S105>/Front Bias'
   *  Constant: '<S526>/Disk brake actuator bore'
   *  Constant: '<S526>/Number of brake pads'
   *  Gain: '<S105>/Gain4'
   *  Integrator: '<S106>/Integrator1'
   *  Product: '<S105>/Product'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntBrkFrntBias *
    localX->Integrator1_CSTATE_h[1] *
    ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr * localB->TorqueConversion1
    [1] * localP->CombinedSlipWheel2DOF_disk_abor[1] *
    localP->CombinedSlipWheel2DOF_num_pads[1];

  /* Saturate: '<S526>/Disallow Negative Brake Torque' */
  if (rtb_Product1_o_idx_3 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_Product1_o_idx_3 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S526>/Torque Conversion' incorporates:
   *  Saturate: '<S526>/Disallow Negative Brake Torque'
   */
  rtb_Product1_o_idx_1 = localP->CombinedSlipWheel2DOF_Rm[1] *
    localP->CombinedSlipWheel2DOF_mu_kineti[1] * rtb_Product1_o_idx_3;

  /* Product: '<S526>/product' incorporates:
   *  Constant: '<S105>/Rear Bias'
   *  Constant: '<S526>/Disk brake actuator bore'
   *  Constant: '<S526>/Number of brake pads'
   *  Gain: '<S105>/Gain4'
   *  Integrator: '<S106>/Integrator1'
   *  Product: '<S105>/Product'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntBrkRearBias *
    localX->Integrator1_CSTATE_h[2] *
    ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr * localB->TorqueConversion1
    [2] * localP->CombinedSlipWheel2DOF_disk_abor[2] *
    localP->CombinedSlipWheel2DOF_num_pads[2];

  /* Saturate: '<S526>/Disallow Negative Brake Torque' */
  if (rtb_Product1_o_idx_3 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_Product1_o_idx_3 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S526>/Torque Conversion' incorporates:
   *  Saturate: '<S526>/Disallow Negative Brake Torque'
   */
  rtb_Product_pm = localP->CombinedSlipWheel2DOF_Rm[2] *
    localP->CombinedSlipWheel2DOF_mu_kineti[2] * rtb_Product1_o_idx_3;

  /* Product: '<S526>/product' incorporates:
   *  Constant: '<S105>/Rear Bias'
   *  Constant: '<S526>/Disk brake actuator bore'
   *  Constant: '<S526>/Number of brake pads'
   *  Gain: '<S105>/Gain4'
   *  Integrator: '<S106>/Integrator1'
   *  Product: '<S105>/Product'
   */
  rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntBrkRearBias *
    localX->Integrator1_CSTATE_h[3] *
    ConfiguredVirtualVehicleModel_P->PlntBrkPrsFctr * localB->TorqueConversion1
    [3] * localP->CombinedSlipWheel2DOF_disk_abor[3] *
    localP->CombinedSlipWheel2DOF_num_pads[3];

  /* Saturate: '<S526>/Disallow Negative Brake Torque' */
  if (rtb_Product1_o_idx_3 > localP->DisallowNegativeBrakeTorque_Upp) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Upp;
  } else if (rtb_Product1_o_idx_3 < localP->DisallowNegativeBrakeTorque_Low) {
    rtb_Product1_o_idx_3 = localP->DisallowNegativeBrakeTorque_Low;
  }

  /* Gain: '<S526>/Torque Conversion' incorporates:
   *  Saturate: '<S526>/Disallow Negative Brake Torque'
   */
  rtb_Product1_o_idx_3 *= localP->CombinedSlipWheel2DOF_Rm[3] *
    localP->CombinedSlipWheel2DOF_mu_kineti[3];

  /* Gain: '<S524>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[0] = localP->CombinedSlipWheel2DOF_mu_static[0]
    / localP->CombinedSlipWheel2DOF_mu_kineti[0] * rtb_DeadZone1;

  /* Gain: '<S524>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S524>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[0] = localP->CombinedSlipWheel2DOF_mu_kineti[0]
    / localP->CombinedSlipWheel2DOF_mu_kineti[0] * rtb_DeadZone1;

  /* Gain: '<S524>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[1] = localP->CombinedSlipWheel2DOF_mu_static[1]
    / localP->CombinedSlipWheel2DOF_mu_kineti[1] * rtb_Product1_o_idx_1;

  /* Gain: '<S524>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S524>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[1] = localP->CombinedSlipWheel2DOF_mu_kineti[1]
    / localP->CombinedSlipWheel2DOF_mu_kineti[1] * rtb_Product1_o_idx_1;

  /* Gain: '<S524>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[2] = localP->CombinedSlipWheel2DOF_mu_static[2]
    / localP->CombinedSlipWheel2DOF_mu_kineti[2] * rtb_Product_pm;

  /* Gain: '<S524>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S524>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[2] = localP->CombinedSlipWheel2DOF_mu_kineti[2]
    / localP->CombinedSlipWheel2DOF_mu_kineti[2] * rtb_Product_pm;

  /* Gain: '<S524>/Ratio of static to kinetic' */
  localB->Ratioofstatictokinetic[3] = localP->CombinedSlipWheel2DOF_mu_static[3]
    / localP->CombinedSlipWheel2DOF_mu_kineti[3] * rtb_Product1_o_idx_3;

  /* Gain: '<S524>/Ratio of static to kinetic1' incorporates:
   *  Gain: '<S524>/Ratio of static to kinetic'
   */
  localB->Ratioofstatictokinetic1[3] = localP->CombinedSlipWheel2DOF_mu_kineti[3]
    / localP->CombinedSlipWheel2DOF_mu_kineti[3] * rtb_Product1_o_idx_3;

  /* Outputs for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' incorporates:
   *  ForEach: '<S527>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* Chart: '<S527>/Clutch' incorporates:
     *  ForEachSliceSelector generated from: '<S527>/Tfmaxk'
     *  ForEachSliceSelector generated from: '<S527>/Tfmaxs'
     *  ForEachSliceSelector generated from: '<S527>/Tout'
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

    /* Outputs for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
    ConfiguredVirtualVehicle_Clutch(localB->Add1[ForEach_itr],
      localB->Ratioofstatictokinetic[ForEach_itr],
      localB->Ratioofstatictokinetic1[ForEach_itr],
      localP->ClutchPartitionedParameters_ome[i - 1],
      localP->ClutchPartitionedParameters_br[iy - 1],
      localP->ClutchPartitionedParameters_Iyy[ibmat - 1],
      localP->CoreSubsys_l.Clutch_OmegaTol, &localB->CoreSubsys_l[ForEach_itr].
      sf_Clutch, &localDW->CoreSubsys_l[ForEach_itr].sf_Clutch,
      &localP->CoreSubsys_l.sf_Clutch, &localX->CoreSubsys_l[ForEach_itr].
      sf_Clutch);

    /* End of Chart: '<S527>/Clutch' */
    /* End of Outputs for SubSystem: '<S523>/Clutch Partitioned Parameters' */

    /* ForEachSliceAssignment generated from: '<S527>/Omega' */
    rtb_ImpAsg_InsertedFor_Omega_at[ForEach_itr] = localB->
      CoreSubsys_l[ForEach_itr].sf_Clutch.Omega;
  }

  /* End of Outputs for SubSystem: '<S523>/Clutch Partitioned Parameters' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<S392>/vehdyncginert' */
    rtb_VectorConcatenate_d[0] =
      ConfiguredVirtualVehicleModel_P->PlntVehDstCGFrntAxl;
    rtb_VectorConcatenate_d[1] = -localP->VehicleBody6DOF_d;
    rtb_VectorConcatenate_d[2] =
      ConfiguredVirtualVehicleModel_P->PlntVehCGHgtAxl;
    for (iy = 0; iy < 3; iy++) {
      ibmat = iy * 7;
      for (i = 0; i < 7; i++) {
        b_b[ibmat + i] = rtb_VectorConcatenate_d[iy];
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
    rtb_MatrixConcatenate2[0] = ConfiguredVirtualVehicleModel_P->PlntVehMass;
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

    rtb_SOC_CC = ConfiguredVirtualVehicleModel_P->PlntVehMass;
    for (iy = 0; iy < 7; iy++) {
      rtb_SOC_CC += rtb_MatrixConcatenate2[iy + 1];
    }

    for (i = 0; i < 24; i++) {
      d_b[i] = d_b[i] * R[i] / rtb_SOC_CC;
    }

    for (i = 0; i < 3; i++) {
      ibmat = i << 3;
      rtb_DeadZone1 = d_b[ibmat];
      for (iy = 0; iy < 7; iy++) {
        rtb_DeadZone1 += d_b[(ibmat + iy) + 1];
      }

      localB->Rbar[i] = rtb_DeadZone1;
    }

    rtb_SOC_CC = ConfiguredVirtualVehicleModel_P->PlntVehMass;
    for (iy = 0; iy < 7; iy++) {
      rtb_SOC_CC += rtb_MatrixConcatenate2[iy + 1];
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
      rtb_VectorConcatenate_d[0] = R[iy];
      rtb_VectorConcatenate_d[1] = R[iy + 8];
      rtb_VectorConcatenate_d[2] = R[iy + 16];
      rtb_DeadZone1 = (rtb_VectorConcatenate_d[0] * rtb_VectorConcatenate_d[0] +
                       rtb_VectorConcatenate_d[1] * rtb_VectorConcatenate_d[1])
        + rtb_VectorConcatenate_d[2] * rtb_VectorConcatenate_d[2];
      rtb_Product1_o_idx_1 = rtb_MatrixConcatenate2[iy];
      rtb_Product_pm = rtb_VectorConcatenate_d[0];
      rtb_Product1_o_idx_3 = rtb_VectorConcatenate_d[1];
      rtb_UnaryMinus2_idx_1 = rtb_VectorConcatenate_d[2];
      for (i = 0; i < 3; i++) {
        rtb_V_wb_d_idx_2 = R[(i << 3) + iy];
        ibmat = 3 * i + 9 * iy;
        Itemp[ibmat] = (static_cast<real_T>(f_b[3 * i]) * rtb_DeadZone1 -
                        rtb_V_wb_d_idx_2 * rtb_Product_pm) *
          rtb_Product1_o_idx_1 * static_cast<real_T>(e[3 * i]) + Imat[ibmat];
        Itemp_tmp = 3 * i + 1;
        Itemp[ibmat + 1] = (static_cast<real_T>(f_b[Itemp_tmp]) * rtb_DeadZone1
                            - rtb_V_wb_d_idx_2 * rtb_Product1_o_idx_3) *
          rtb_Product1_o_idx_1 * static_cast<real_T>(e[Itemp_tmp]) + Imat[ibmat
          + 1];
        Itemp_tmp = 3 * i + 2;
        Itemp[ibmat + 2] = (static_cast<real_T>(f_b[Itemp_tmp]) * rtb_DeadZone1
                            - rtb_V_wb_d_idx_2 * rtb_UnaryMinus2_idx_1) *
          rtb_Product1_o_idx_1 * static_cast<real_T>(e[Itemp_tmp]) + Imat[ibmat
          + 2];
      }
    }

    std::memcpy(&rtb_Ibar[0], &Itemp[0], 9U * sizeof(real_T));
    for (iy = 0; iy < 7; iy++) {
      ibmat = (iy + 1) * 9;
      for (i = 0; i < 9; i++) {
        rtb_Ibar[i] += Itemp[ibmat + i];
      }
    }

    localB->Mbar = rtb_SOC_CC;
    localB->Xbar[0] = ConfiguredVirtualVehicleModel_P->PlntVehDstCGFrntAxl -
      localB->Rbar[0];
    localB->Xbar[1] = ConfiguredVirtualVehicleModel_P->PlntVehDstCGRearAxl +
      localB->Rbar[0];
    localB->Xbar[2] = ConfiguredVirtualVehicleModel_P->PlntVehCGHgtAxl -
      localB->Rbar[2];
    rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] /
      2.0;
    rtb_UnaryMinus2_idx_1 = ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[1] /
      2.0;
    localB->Wbar[0] = rtb_Product1_o_idx_3 + localB->Rbar[1];
    localB->Wbar[1] = rtb_Product1_o_idx_3 - localB->Rbar[1];
    localB->Wbar[2] = rtb_UnaryMinus2_idx_1 + localB->Rbar[1];
    localB->Wbar[3] = rtb_UnaryMinus2_idx_1 - localB->Rbar[1];
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

    /* End of MATLAB Function: '<S392>/vehdyncginert' */

    /* Selector: '<S451>/Selector1' */
    localB->Selector1[0] = localB->HPbar[0];
    localB->Selector1[1] = localB->HPbar[1];
    localB->Selector1[2] = localB->HPbar[2];

    /* Selector: '<S452>/Selector1' */
    localB->Selector1_f[0] = localB->HPbar[3];
    localB->Selector1_f[1] = localB->HPbar[4];
    localB->Selector1_f[2] = localB->HPbar[5];
  }

  /* Sum: '<S461>/Sum' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S463>/i x j'
   *  Product: '<S463>/j x k'
   *  Product: '<S463>/k x i'
   *  Product: '<S464>/i x k'
   *  Product: '<S464>/j x i'
   *  Product: '<S464>/k x j'
   */
  rtb_Product1_o_idx_3 = localX->pqr_CSTATE[1] * localB->Selector1[2] -
    localB->Selector1[1] * localX->pqr_CSTATE[2];
  rtb_UnaryMinus2_idx_1 = localB->Selector1[0] * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * localB->Selector1[2];
  rtb_V_wb_d_idx_2 = localX->pqr_CSTATE[0] * localB->Selector1[1] -
    localB->Selector1[0] * localX->pqr_CSTATE[1];

  /* Sum: '<S469>/Sum' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S471>/i x j'
   *  Product: '<S471>/j x k'
   *  Product: '<S471>/k x i'
   *  Product: '<S472>/i x k'
   *  Product: '<S472>/j x i'
   *  Product: '<S472>/k x j'
   */
  rtb_UnaryMinus_c_idx_0 = localX->pqr_CSTATE[1] * localB->Selector1_f[2] -
    localB->Selector1_f[1] * localX->pqr_CSTATE[2];
  rtb_UnaryMinus_c_idx_1 = localB->Selector1_f[0] * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * localB->Selector1_f[2];
  rtb_UnaryMinus_c_idx_2 = localX->pqr_CSTATE[0] * localB->Selector1_f[1] -
    localB->Selector1_f[0] * localX->pqr_CSTATE[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Selector: '<S455>/Selector1' */
    localB->Selector1_f2[0] = localB->HPbar[6];
    localB->Selector1_f2[1] = localB->HPbar[7];
    localB->Selector1_f2[2] = localB->HPbar[8];

    /* Selector: '<S456>/Selector1' */
    localB->Selector1_n[0] = localB->HPbar[9];
    localB->Selector1_n[1] = localB->HPbar[10];
    localB->Selector1_n[2] = localB->HPbar[11];
  }

  /* Sum: '<S497>/Sum' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S499>/i x j'
   *  Product: '<S499>/j x k'
   *  Product: '<S499>/k x i'
   *  Product: '<S500>/i x k'
   *  Product: '<S500>/j x i'
   *  Product: '<S500>/k x j'
   */
  rtb_Product_pm = localX->pqr_CSTATE[1] * localB->Selector1_f2[2] -
    localB->Selector1_f2[1] * localX->pqr_CSTATE[2];
  rtb_Product1_o_idx_1 = localB->Selector1_f2[0] * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * localB->Selector1_f2[2];
  rtb_DeadZone1 = localX->pqr_CSTATE[0] * localB->Selector1_f2[1] -
    localB->Selector1_f2[0] * localX->pqr_CSTATE[1];

  /* Product: '<S507>/j x k' incorporates:
   *  Integrator: '<S407>/p,q,r '
   */
  rtb_SOC_CC = localX->pqr_CSTATE[1] * localB->Selector1_n[2];

  /* Sum: '<S505>/Sum' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S507>/k x i'
   *  Product: '<S508>/i x k'
   *  Product: '<S508>/k x j'
   */
  rtb_Add_bl[0] = rtb_SOC_CC - localB->Selector1_n[1] * localX->pqr_CSTATE[2];
  rtb_Add_bl[1] = localB->Selector1_n[0] * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * localB->Selector1_n[2];

  /* Concatenate: '<S287>/Matrix Concatenate' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Selector: '<S286>/Selector2'
   *  Sum: '<S457>/Add1'
   *  UnaryMinus: '<S383>/Unary Minus2'
   */
  localB->MatrixConcatenate[0] = rtb_Product1_o_idx_3 + localB->UnitConversion[0];
  localB->MatrixConcatenate[1] = rtb_UnaryMinus2_idx_1 + localB->UnitConversion
    [1];
  localB->MatrixConcatenate[2] = -rtb_Switch_bk_idx_0;

  /* Concatenate: '<S377>/Vector Concatenate3' incorporates:
   *  Constant: '<S377>/Constant3'
   *  Integrator: '<S375>/Integrator1'
   *  Selector: '<S287>/Selector2'
   *  Selector: '<S287>/Selector3'
   */
  localB->VectorConcatenate3[0] = localX->Integrator1_CSTATE_e[0];
  localB->VectorConcatenate3[1] = localP->Constant3_Value_d[0];
  localB->VectorConcatenate3[2] = localX->Integrator1_CSTATE_e[2];

  /* Concatenate: '<S287>/Matrix Concatenate' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Selector: '<S286>/Selector2'
   *  Sum: '<S465>/Add1'
   *  UnaryMinus: '<S383>/Unary Minus2'
   */
  localB->MatrixConcatenate[3] = rtb_UnaryMinus_c_idx_0 + localB->
    UnitConversion[0];
  localB->MatrixConcatenate[4] = rtb_UnaryMinus_c_idx_1 + localB->
    UnitConversion[1];
  localB->MatrixConcatenate[5] = -rtb_Switch_bk_idx_1;

  /* Concatenate: '<S377>/Vector Concatenate3' incorporates:
   *  Constant: '<S377>/Constant3'
   *  Integrator: '<S375>/Integrator1'
   *  Selector: '<S287>/Selector2'
   *  Selector: '<S287>/Selector3'
   */
  localB->VectorConcatenate3[3] = localX->Integrator1_CSTATE_e[3];
  localB->VectorConcatenate3[4] = localP->Constant3_Value_d[1];
  localB->VectorConcatenate3[5] = localX->Integrator1_CSTATE_e[5];

  /* Concatenate: '<S287>/Matrix Concatenate' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Selector: '<S286>/Selector2'
   *  Sum: '<S493>/Add1'
   *  UnaryMinus: '<S383>/Unary Minus2'
   */
  localB->MatrixConcatenate[6] = rtb_Product_pm + localB->UnitConversion[0];
  localB->MatrixConcatenate[7] = rtb_Product1_o_idx_1 + localB->UnitConversion[1];
  localB->MatrixConcatenate[8] = -rtb_Switch_bk_idx_2;

  /* Concatenate: '<S377>/Vector Concatenate3' incorporates:
   *  Constant: '<S377>/Constant3'
   *  Integrator: '<S375>/Integrator1'
   *  Selector: '<S287>/Selector2'
   *  Selector: '<S287>/Selector3'
   */
  localB->VectorConcatenate3[6] = localX->Integrator1_CSTATE_e[6];
  localB->VectorConcatenate3[7] = localP->Constant3_Value_d[2];
  localB->VectorConcatenate3[8] = localX->Integrator1_CSTATE_e[8];

  /* Concatenate: '<S287>/Matrix Concatenate' incorporates:
   *  Selector: '<S286>/Selector1'
   *  Selector: '<S286>/Selector2'
   *  Sum: '<S493>/Add1'
   *  Sum: '<S501>/Add1'
   *  UnaryMinus: '<S383>/Unary Minus2'
   */
  localB->MatrixConcatenate[9] = rtb_Add_bl[0] + localB->UnitConversion[0];
  localB->MatrixConcatenate[10] = rtb_Add_bl[1] + localB->UnitConversion[1];
  localB->MatrixConcatenate[11] = -rtb_Switch_bk_idx_3;

  /* Concatenate: '<S377>/Vector Concatenate3' incorporates:
   *  Constant: '<S377>/Constant3'
   *  Integrator: '<S375>/Integrator1'
   *  Selector: '<S287>/Selector2'
   *  Selector: '<S287>/Selector3'
   */
  localB->VectorConcatenate3[9] = localX->Integrator1_CSTATE_e[9];
  localB->VectorConcatenate3[10] = localP->Constant3_Value_d[3];
  localB->VectorConcatenate3[11] = localX->Integrator1_CSTATE_e[11];

  /* Outputs for Iterator SubSystem: '<S376>/Wheel to Body Transform' incorporates:
   *  ForEach: '<S378>/For Each'
   */
  for (ForEach_itr_j = 0; ForEach_itr_j < 4; ForEach_itr_j++) {
    /* ForEachSliceSelector generated from: '<S378>/WheelAngles' incorporates:
     *  ForEachSliceSelector generated from: '<S378>/VelVeh'
     *  Product: '<S378>/Divide1'
     *  SignalConversion generated from: '<S379>/sincos'
     */
    iy = 3 * ForEach_itr_j + 2;

    /* SignalConversion generated from: '<S379>/sincos' incorporates:
     *  Concatenate: '<S377>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S378>/WheelAngles'
     */
    rtb_IntegratorSecondOrderLimite[0] = localB->VectorConcatenate3[iy];

    /* ForEachSliceSelector generated from: '<S378>/WheelAngles' incorporates:
     *  ForEachSliceSelector generated from: '<S378>/VelVeh'
     *  Product: '<S378>/Divide1'
     *  SignalConversion generated from: '<S379>/sincos'
     */
    ibmat = 3 * ForEach_itr_j + 1;

    /* SignalConversion generated from: '<S379>/sincos' incorporates:
     *  Concatenate: '<S377>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S378>/WheelAngles'
     */
    rtb_IntegratorSecondOrderLimite[1] = localB->VectorConcatenate3[ibmat];
    rtb_IntegratorSecondOrderLimite[2] = localB->VectorConcatenate3[3 *
      ForEach_itr_j];

    /* Trigonometry: '<S379>/sincos' */
    rtb_Switch1_f[0] = std::cos(rtb_IntegratorSecondOrderLimite[0]);
    Fzo_prime_idx_2 = std::sin(rtb_IntegratorSecondOrderLimite[0]);
    rtb_Switch1_f[1] = std::cos(rtb_IntegratorSecondOrderLimite[1]);
    Fzo_prime_idx_3 = std::sin(rtb_IntegratorSecondOrderLimite[1]);
    rtb_Switch1_f[2] = std::cos(rtb_IntegratorSecondOrderLimite[2]);
    lam_muy_prime_idx_3 = std::sin(rtb_IntegratorSecondOrderLimite[2]);

    /* Fcn: '<S379>/Fcn11' */
    rtb_VectorConcatenate_lq[0] = rtb_Switch1_f[0] * rtb_Switch1_f[1];

    /* Fcn: '<S379>/Fcn21' incorporates:
     *  Fcn: '<S379>/Fcn22'
     *  Trigonometry: '<S379>/sincos'
     */
    Fzo_prime_idx_0 = Fzo_prime_idx_3 * lam_muy_prime_idx_3;
    rtb_VectorConcatenate_lq[1] = Fzo_prime_idx_0 * rtb_Switch1_f[0] -
      Fzo_prime_idx_2 * rtb_Switch1_f[2];

    /* Fcn: '<S379>/Fcn31' incorporates:
     *  Fcn: '<S379>/Fcn32'
     *  Trigonometry: '<S379>/sincos'
     */
    Fzo_prime_idx_1 = Fzo_prime_idx_3 * rtb_Switch1_f[2];
    rtb_VectorConcatenate_lq[2] = Fzo_prime_idx_1 * rtb_Switch1_f[0] +
      Fzo_prime_idx_2 * lam_muy_prime_idx_3;

    /* Fcn: '<S379>/Fcn12' incorporates:
     *  Trigonometry: '<S379>/sincos'
     */
    rtb_VectorConcatenate_lq[3] = Fzo_prime_idx_2 * rtb_Switch1_f[1];

    /* Fcn: '<S379>/Fcn22' incorporates:
     *  Trigonometry: '<S379>/sincos'
     */
    rtb_VectorConcatenate_lq[4] = Fzo_prime_idx_0 * Fzo_prime_idx_2 +
      rtb_Switch1_f[0] * rtb_Switch1_f[2];

    /* Fcn: '<S379>/Fcn32' incorporates:
     *  Trigonometry: '<S379>/sincos'
     */
    rtb_VectorConcatenate_lq[5] = Fzo_prime_idx_1 * Fzo_prime_idx_2 -
      rtb_Switch1_f[0] * lam_muy_prime_idx_3;

    /* Fcn: '<S379>/Fcn13' incorporates:
     *  Trigonometry: '<S379>/sincos'
     */
    rtb_VectorConcatenate_lq[6] = -Fzo_prime_idx_3;

    /* Fcn: '<S379>/Fcn23' incorporates:
     *  Trigonometry: '<S379>/sincos'
     */
    rtb_VectorConcatenate_lq[7] = rtb_Switch1_f[1] * lam_muy_prime_idx_3;

    /* Fcn: '<S379>/Fcn33' */
    rtb_VectorConcatenate_lq[8] = rtb_Switch1_f[1] * rtb_Switch1_f[2];

    /* Product: '<S378>/Divide1' */
    for (i = 0; i < 3; i++) {
      /* SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' incorporates:
       *  Concatenate: '<S490>/Vector Concatenate'
       *  ForEachSliceSelector generated from: '<S378>/VelVeh'
       */
      rtb_IntegratorSecondOrderLimite[i] = (rtb_VectorConcatenate_lq[i + 3] *
        localB->MatrixConcatenate[ibmat] + localB->MatrixConcatenate[3 *
        ForEach_itr_j] * rtb_VectorConcatenate_lq[i]) +
        rtb_VectorConcatenate_lq[i + 6] * localB->MatrixConcatenate[iy];
    }

    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Trigonometry: '<S380>/sincos' incorporates:
       *  Constant: '<S378>/Constant'
       *  SignalConversion generated from: '<S380>/sincos'
       */
      Fzo_prime_idx_2 = std::cos(localP->CoreSubsys_d.Constant_Value[2]);
      Vsy_0 = std::sin(localP->CoreSubsys_d.Constant_Value[2]);
      Fzo_prime_idx_3 = std::cos(localP->CoreSubsys_d.Constant_Value[1]);
      lam_muy_prime_idx_3 = std::sin(localP->CoreSubsys_d.Constant_Value[1]);
      lam_muy_prime_idx_2 = std::cos(localP->CoreSubsys_d.Constant_Value[0]);
      lam_muy_prime_idx_1 = std::sin(localP->CoreSubsys_d.Constant_Value[0]);

      /* Fcn: '<S380>/Fcn11' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[0] = Fzo_prime_idx_2
        * Fzo_prime_idx_3;

      /* Fcn: '<S380>/Fcn21' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Fcn: '<S380>/Fcn22'
       *  Trigonometry: '<S380>/sincos'
       */
      Fzo_prime_idx_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_1;
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[1] = Fzo_prime_idx_0
        * Fzo_prime_idx_2 - Vsy_0 * lam_muy_prime_idx_2;

      /* Fcn: '<S380>/Fcn31' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Fcn: '<S380>/Fcn32'
       *  Trigonometry: '<S380>/sincos'
       */
      Fzo_prime_idx_1 = lam_muy_prime_idx_3 * lam_muy_prime_idx_2;
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[2] = Fzo_prime_idx_1
        * Fzo_prime_idx_2 + Vsy_0 * lam_muy_prime_idx_1;

      /* Fcn: '<S380>/Fcn12' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Trigonometry: '<S380>/sincos'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[3] = Vsy_0 *
        Fzo_prime_idx_3;

      /* Fcn: '<S380>/Fcn22' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Trigonometry: '<S380>/sincos'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[4] = Fzo_prime_idx_0
        * Vsy_0 + Fzo_prime_idx_2 * lam_muy_prime_idx_2;

      /* Fcn: '<S380>/Fcn32' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Trigonometry: '<S380>/sincos'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[5] = Fzo_prime_idx_1
        * Vsy_0 - Fzo_prime_idx_2 * lam_muy_prime_idx_1;

      /* Fcn: '<S380>/Fcn13' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Trigonometry: '<S380>/sincos'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[6] =
        -lam_muy_prime_idx_3;

      /* Fcn: '<S380>/Fcn23' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       *  Trigonometry: '<S380>/sincos'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[7] = Fzo_prime_idx_3
        * lam_muy_prime_idx_1;

      /* Fcn: '<S380>/Fcn33' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       */
      localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[8] = Fzo_prime_idx_3
        * lam_muy_prime_idx_2;
    }

    /* Product: '<S378>/Divide2' incorporates:
     *  SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited'
     */
    Fzo_prime_idx_2 = rtb_IntegratorSecondOrderLimite[1];
    Fzo_prime_idx_3 = rtb_IntegratorSecondOrderLimite[0];
    lam_muy_prime_idx_3 = rtb_IntegratorSecondOrderLimite[2];
    for (i = 0; i < 3; i++) {
      /* Product: '<S378>/Divide2' incorporates:
       *  Concatenate: '<S382>/Vector Concatenate'
       */
      rtb_VectorConcatenate_d[i] = (localB->CoreSubsys_d[ForEach_itr_j].
        VectorConcatenate[i + 3] * Fzo_prime_idx_2 + localB->
        CoreSubsys_d[ForEach_itr_j].VectorConcatenate[i] * Fzo_prime_idx_3) +
        localB->CoreSubsys_d[ForEach_itr_j].VectorConcatenate[i + 6] *
        lam_muy_prime_idx_3;
    }

    /* End of Product: '<S378>/Divide2' */

    /* ForEachSliceAssignment generated from: '<S378>/ydotWheel' */
    rtb_ImpAsg_InsertedFor_ydotWhee[ForEach_itr_j] = rtb_VectorConcatenate_d[1];

    /* ForEachSliceAssignment generated from: '<S378>/xdotWheel' */
    rtb_ImpAsg_InsertedFor_xdotWhee[ForEach_itr_j] = rtb_VectorConcatenate_d[0];
  }

  /* End of Outputs for SubSystem: '<S376>/Wheel to Body Transform' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Concatenate: '<S293>/Matrix Concatenate1' incorporates:
     *  Constant: '<S293>/SteerRates'
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

    /* Constant: '<S509>/Front Pressure' */
    localB->FrontPressure[0] = ConfiguredVirtualVehicleModel_P->PlntWhlPrsFrnt;

    /* Constant: '<S509>/Rear Pressure' */
    localB->RearPressure[0] = ConfiguredVirtualVehicleModel_P->PlntWhlPrsRear;

    /* Constant: '<S509>/Front Pressure' */
    localB->FrontPressure[1] = ConfiguredVirtualVehicleModel_P->PlntWhlPrsFrnt;

    /* Constant: '<S509>/Rear Pressure' */
    localB->RearPressure[1] = ConfiguredVirtualVehicleModel_P->PlntWhlPrsRear;

    /* Concatenate: '<S511>/Vector Concatenate' incorporates:
     *  Concatenate: '<S76>/Vector Concatenate'
     *  Constant: '<S511>/0'
     *  Constant: '<S511>/1'
     *  Constant: '<S511>/2'
     *  Constant: '<S511>/ones'
     *  Constant: '<S511>/ones1'
     *  Constant: '<S511>/ones2'
     *  Constant: '<S511>/ones3'
     */
    localB->VectorConcatenate[0] = localP->ones2_Value[0];
    localB->VectorConcatenate[1] = rtb_VectorConcatenate_j[0];
    localB->VectorConcatenate[2] = rtb_VectorConcatenate_j[0];
    localB->VectorConcatenate[3] = localP->u_Value[0];
    localB->VectorConcatenate[27] = localP->ones2_Value[1];
    localB->VectorConcatenate[28] = rtb_VectorConcatenate_j[1];
    localB->VectorConcatenate[29] = rtb_VectorConcatenate_j[1];
    localB->VectorConcatenate[30] = localP->u_Value[1];
    localB->VectorConcatenate[54] = localP->ones2_Value[2];
    localB->VectorConcatenate[55] = rtb_VectorConcatenate_j[2];
    localB->VectorConcatenate[56] = rtb_VectorConcatenate_j[2];
    localB->VectorConcatenate[57] = localP->u_Value[2];
    localB->VectorConcatenate[81] = localP->ones2_Value[3];
    localB->VectorConcatenate[82] = rtb_VectorConcatenate_j[3];
    localB->VectorConcatenate[83] = rtb_VectorConcatenate_j[3];
    localB->VectorConcatenate[84] = localP->u_Value[3];
    for (i = 0; i < 9; i++) {
      localB->VectorConcatenate[i + 4] = localP->ones1_Value[i];
      localB->VectorConcatenate[i + 31] = localP->ones1_Value[i + 9];
      localB->VectorConcatenate[i + 58] = localP->ones1_Value[i + 18];
      localB->VectorConcatenate[i + 85] = localP->ones1_Value[i + 27];
    }

    for (i = 0; i < 4; i++) {
      localB->VectorConcatenate[27 * i + 13] = localP->u_Value_l[i];
      for (iy = 0; iy < 5; iy++) {
        localB->VectorConcatenate[(iy + 27 * i) + 14] = localP->ones3_Value[5 *
          i + iy];
      }

      iy = i << 1;
      localB->VectorConcatenate[27 * i + 19] = localP->u_Value_f[iy];
      localB->VectorConcatenate[27 * i + 20] = localP->u_Value_f[iy + 1];
    }

    for (i = 0; i < 6; i++) {
      localB->VectorConcatenate[i + 21] = localP->ones_Value[i];
      localB->VectorConcatenate[i + 48] = localP->ones_Value[i + 6];
      localB->VectorConcatenate[i + 75] = localP->ones_Value[i + 12];
      localB->VectorConcatenate[i + 102] = localP->ones_Value[i + 18];
    }
  }

  /* UnaryMinus: '<S376>/Unary Minus' incorporates:
   *  Concatenate: '<S293>/Matrix Concatenate1'
   *  Integrator: '<S407>/p,q,r '
   *  Reshape: '<S293>/Reshape4'
   *  Selector: '<S287>/Selector1'
   *  Sum: '<S293>/Add'
   */
  rtb_UnaryMinus[0] = -(localB->MatrixConcatenate1[2] + localX->pqr_CSTATE[2]);

  /* Selector: '<S509>/Selector' incorporates:
   *  Concatenate: '<S377>/Vector Concatenate3'
   */
  dpi[0] = localB->VectorConcatenate3[0];

  /* UnaryMinus: '<S376>/Unary Minus' incorporates:
   *  Concatenate: '<S293>/Matrix Concatenate1'
   *  Integrator: '<S407>/p,q,r '
   *  Reshape: '<S293>/Reshape4'
   *  Selector: '<S287>/Selector1'
   *  Sum: '<S293>/Add'
   */
  rtb_UnaryMinus[1] = -(localX->pqr_CSTATE[2] + localB->MatrixConcatenate1[5]);

  /* Selector: '<S509>/Selector' incorporates:
   *  Concatenate: '<S377>/Vector Concatenate3'
   */
  dpi[1] = localB->VectorConcatenate3[3];

  /* UnaryMinus: '<S376>/Unary Minus' incorporates:
   *  Concatenate: '<S293>/Matrix Concatenate1'
   *  Integrator: '<S407>/p,q,r '
   *  Reshape: '<S293>/Reshape4'
   *  Selector: '<S287>/Selector1'
   *  Sum: '<S293>/Add'
   */
  rtb_UnaryMinus[2] = -(localX->pqr_CSTATE[2] + localB->MatrixConcatenate1[8]);

  /* Selector: '<S509>/Selector' incorporates:
   *  Concatenate: '<S377>/Vector Concatenate3'
   */
  dpi[2] = localB->VectorConcatenate3[6];

  /* UnaryMinus: '<S376>/Unary Minus' incorporates:
   *  Concatenate: '<S293>/Matrix Concatenate1'
   *  Integrator: '<S407>/p,q,r '
   *  Reshape: '<S293>/Reshape4'
   *  Selector: '<S287>/Selector1'
   *  Sum: '<S293>/Add'
   */
  rtb_UnaryMinus[3] = -(localX->pqr_CSTATE[2] + localB->MatrixConcatenate1[11]);

  /* Selector: '<S509>/Selector' incorporates:
   *  Concatenate: '<S377>/Vector Concatenate3'
   */
  dpi[3] = localB->VectorConcatenate3[9];

  /* Product: '<S521>/Product' incorporates:
   *  Constant: '<S521>/Constant1'
   *  Saturate: '<S287>/Saturation'
   */
  rtb_VectorConcatenate_j[0] = localP->Constant1_Value_c *
    rtb_UnitConversion_gd_idx_0;
  rtb_VectorConcatenate_j[1] = localP->Constant1_Value_c *
    rtb_UnitConversion_gd_idx_1;
  rtb_VectorConcatenate_j[2] = localP->Constant1_Value_c *
    rtb_UnitConversion_gd_idx_2;
  rtb_VectorConcatenate_j[3] = localP->Constant1_Value_c *
    rtb_UnitConversion_gd_idx_3;

  /* SignalConversion generated from: '<S519>/ SFunction ' incorporates:
   *  MATLAB Function: '<S514>/Magic Tire Const Input'
   */
  rtb_Saturation_g[0] = localB->FrontPressure[0];
  rtb_Saturation_g[2] = localB->RearPressure[0];
  rtb_Saturation_g[1] = localB->FrontPressure[1];
  rtb_Saturation_g[3] = localB->RearPressure[1];

  /* MATLAB Function: '<S514>/Magic Tire Const Input' incorporates:
   *  Concatenate: '<S377>/Vector Concatenate3'
   *  Concatenate: '<S511>/Vector Concatenate'
   *  Constant: '<S512>/vertType'
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Reshape: '<S376>/Reshape1'
   *  Reshape: '<S376>/Reshape2'
   *  Saturate: '<S521>/Saturation'
   *  Selector: '<S509>/Selector'
   */
  rtb_sig_x[0] = localB->VectorConcatenate3[0];
  rtb_sig_x[1] = localB->VectorConcatenate3[3];
  rtb_sig_x[2] = localB->VectorConcatenate3[6];
  rtb_sig_x[3] = localB->VectorConcatenate3[9];
  rtb_Divide_ag = localP->CombinedSlipWheel2DOF_Q_FZ1;
  if (localP->MagicTireConstInput_vdynMF[3] == 1.0) {
    lam_mux[0] = localB->VectorConcatenate[1];
    lam_muy[0] = localB->VectorConcatenate[2];
    lam_mux[1] = localB->VectorConcatenate[28];
    lam_muy[1] = localB->VectorConcatenate[29];
    lam_mux[2] = localB->VectorConcatenate[55];
    lam_muy[2] = localB->VectorConcatenate[56];
    lam_mux[3] = localB->VectorConcatenate[82];
    lam_muy[3] = localB->VectorConcatenate[83];
    ConfiguredVirtualVe_div0protect(rtb_ImpAsg_InsertedFor_xdotWhee,
      ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel, R_omega, Vsy);
    for (i = 0; i < 4; i++) {
      if (dpi[i] < ConfiguredVirtualVehicleModel_P->PlntWhlMinCmbr) {
        rtb_sig_x[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMinCmbr;
      }

      if (rtb_sig_x[i] > ConfiguredVirtualVehicleModel_P->PlntWhlMaxCmbr) {
        rtb_sig_x[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMaxCmbr;
      }

      Fzo_prime_idx_0 = rtb_Saturation_g[i];
      if (Fzo_prime_idx_0 < ConfiguredVirtualVehicleModel_P->PlntWhlMinPress) {
        Fzo_prime_idx_0 = ConfiguredVirtualVehicleModel_P->PlntWhlMinPress;
        rtb_Saturation_g[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMinPress;
      }

      if (Fzo_prime_idx_0 > ConfiguredVirtualVehicleModel_P->PlntWhlMaxPress) {
        rtb_Saturation_g[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMaxPress;
      }

      if (lam_mux[i] <= 0.0) {
        lam_mux[i] = 2.2204460492503131E-16;
      }

      if (lam_muy[i] <= 0.0) {
        lam_muy[i] = 2.2204460492503131E-16;
      }
    }

    dpi[0] = (rtb_Saturation_g[0] -
              ConfiguredVirtualVehicleModel_P->PlntWhlNomPress) /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress;
    dpi[1] = (rtb_Saturation_g[1] -
              ConfiguredVirtualVehicleModel_P->PlntWhlNomPress) /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress;
    dpi[2] = (rtb_Saturation_g[2] -
              ConfiguredVirtualVehicleModel_P->PlntWhlNomPress) /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress;
    dpi[3] = (rtb_Saturation_g[3] -
              ConfiguredVirtualVehicleModel_P->PlntWhlNomPress) /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress;
    Fzo_prime_idx_0 = localB->VectorConcatenate[0] *
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_1 = localB->VectorConcatenate[27] *
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_2 = localB->VectorConcatenate[54] *
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    Fzo_prime_idx_3 = localB->VectorConcatenate[81] *
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    if (localP->vertType_Value == 2.0) {
      if (localP->CombinedSlipWheel2DOF_Q_FZ1 == 0.0) {
        lam_muy_prime_idx_3 = localP->CombinedSlipWheel2DOF_VERTICAL_ *
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
          ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
        rtb_Divide_ag = localP->CombinedSlipWheel2DOF_Q_FZ1;
        Vsy_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 - 4.0 *
          localP->CombinedSlipWheel2DOF_Q_FZ2;
        if (Vsy_0 < 0.0) {
          rtb_Divide_ag = localP->CombinedSlipWheel2DOF_Q_FZ2 * 0.0;
        }

        iy = 0;
        if (!(Vsy_0 < 0.0)) {
          for (i = 0; i < 1; i++) {
            iy++;
          }
        }

        ec_size[0] = 1;
        ec_size[1] = iy;
        if (iy - 1 >= 0) {
          ec_data = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 - 4.0 *
            localP->CombinedSlipWheel2DOF_Q_FZ2;
        }

        ConfiguredVirtualVehicleMo_sqrt(&ec_data, ec_size);
        if (!(Vsy_0 < 0.0)) {
          rtb_Divide_ag = ec_data;
        }
      }

      Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntWhlRimRadius +
        localP->CombinedSlipWheel2DOF_BOTTOM_OF;
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[0] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_2 = ec_data * ec_data;
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_h[0] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = ec_data * ec_data;
      ec_data = rtb_Saturation[0] /
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      rtb_VectorConcatenate_j[0] = std::fmax
        ((((localP->CombinedSlipWheel2DOF_Q_V2 * std::abs
            (rtb_ImpAsg_InsertedFor_Omega_at[0]) *
            ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
            ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0) -
           lam_muy_prime_idx_2) - lam_muy_prime_idx_3) *
         ((localP->CombinedSlipWheel2DOF_Q_FZ3 * rtb_sig_x[0] * rtb_sig_x[0] +
           rtb_Divide_ag) * rtb_Saturation[0] /
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius + ec_data * ec_data
          * localP->CombinedSlipWheel2DOF_Q_FZ2) *
         (localP->CombinedSlipWheel2DOF_PFZ1 * dpi[0] + 1.0) * Fzo_prime_idx_0,
         (Vsy_0 - (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius +
                   rtb_Saturation[0]) / std::cos(rtb_sig_x[0])) *
         localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[1] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_2 = ec_data * ec_data;
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_h[1] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = ec_data * ec_data;
      ec_data = rtb_Saturation[1] /
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      rtb_VectorConcatenate_j[1] = std::fmax
        ((((localP->CombinedSlipWheel2DOF_Q_V2 * std::abs
            (rtb_ImpAsg_InsertedFor_Omega_at[1]) *
            ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
            ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0) -
           lam_muy_prime_idx_2) - lam_muy_prime_idx_3) *
         ((localP->CombinedSlipWheel2DOF_Q_FZ3 * rtb_sig_x[1] * rtb_sig_x[1] +
           rtb_Divide_ag) * rtb_Saturation[1] /
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius + ec_data * ec_data
          * localP->CombinedSlipWheel2DOF_Q_FZ2) *
         (localP->CombinedSlipWheel2DOF_PFZ1 * dpi[1] + 1.0) * Fzo_prime_idx_1,
         (Vsy_0 - (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius +
                   rtb_Saturation[1]) / std::cos(rtb_sig_x[1])) *
         localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[2] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_2 = ec_data * ec_data;
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_h[2] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = ec_data * ec_data;
      ec_data = rtb_Saturation[2] /
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      rtb_VectorConcatenate_j[2] = std::fmax
        ((((localP->CombinedSlipWheel2DOF_Q_V2 * std::abs
            (rtb_ImpAsg_InsertedFor_Omega_at[2]) *
            ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
            ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0) -
           lam_muy_prime_idx_2) - lam_muy_prime_idx_3) *
         ((localP->CombinedSlipWheel2DOF_Q_FZ3 * rtb_sig_x[2] * rtb_sig_x[2] +
           rtb_Divide_ag) * rtb_Saturation[2] /
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius + ec_data * ec_data
          * localP->CombinedSlipWheel2DOF_Q_FZ2) *
         (localP->CombinedSlipWheel2DOF_PFZ1 * dpi[2] + 1.0) * Fzo_prime_idx_2,
         (Vsy_0 - (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius +
                   rtb_Saturation[2]) / std::cos(rtb_sig_x[2])) *
         localP->CombinedSlipWheel2DOF_BOTTOM_ST);
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCX * localB->Integrator[3] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_2 = ec_data * ec_data;
      ec_data = localP->CombinedSlipWheel2DOF_Q_FCY * localB->Integrator_h[3] /
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
      lam_muy_prime_idx_3 = ec_data * ec_data;
      ec_data = rtb_Saturation_1 /
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      rtb_VectorConcatenate_j[3] = std::fmax
        ((((localP->CombinedSlipWheel2DOF_Q_V2 * std::abs
            (rtb_ImpAsg_InsertedFor_Omega_at[3]) *
            ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
            ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0) -
           lam_muy_prime_idx_2) - lam_muy_prime_idx_3) *
         ((localP->CombinedSlipWheel2DOF_Q_FZ3 * rtb_sig_x[3] * rtb_sig_x[3] +
           rtb_Divide_ag) * rtb_Saturation_1 /
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius + ec_data * ec_data
          * localP->CombinedSlipWheel2DOF_Q_FZ2) *
         (localP->CombinedSlipWheel2DOF_PFZ1 * dpi[3] + 1.0) * Fzo_prime_idx_3,
         (Vsy_0 - (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius +
                   rtb_Saturation_1) / std::cos(rtb_sig_x[3])) *
         localP->CombinedSlipWheel2DOF_BOTTOM_ST);
    }

    localB->Re[0] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate[22];
    localB->Re[1] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate[49];
    localB->Re[2] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate[76];
    localB->Re[3] = localP->CombinedSlipWheel2DOF_VERTICAL_ *
      localB->VectorConcatenate[103];
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
      Gykappa[i] = rtb_Saturation[iy];
    }

    ConfiguredVirtualVehicleMod_abs(Gykappa, &rtb_Saturation_size, phi, &iy);
    i = Itemp_tmp == 1 ? iy : Itemp_tmp;
    ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data, &ibmat, phi, &iy);
    ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data_0, &ibmat, phi,
      &rtb_Saturation_size);
    if ((Itemp_tmp == iy) && ((Itemp_tmp == 1 ? rtb_Saturation_size : Itemp_tmp)
         == Itemp_tmp) && ((i == 1 ? Itemp_tmp : i) == Itemp_tmp)) {
      for (i = 0; i < Itemp_tmp; i++) {
        rtb_Saturation_data[i] = rtb_Saturation[tmp_data[i]];
      }

      ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data, &Itemp_tmp,
        rtb_Saturation_data_0, &ibmat);
      for (i = 0; i < Itemp_tmp; i++) {
        iy = tmp_data[i];
        localB->Re[iy] = (localP->CombinedSlipWheel2DOF_Q_FCY2 *
                          localB->Integrator_h[iy] /
                          ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce +
                          rtb_VectorConcatenate_j[iy] / rtb_Saturation_data_0[i])
          * localB->VectorConcatenate[27 * iy + 22];
      }
    } else {
      Configur_binary_expand_op_nxejp(localB->Re, tmp_data, &Itemp_tmp,
        rtb_VectorConcatenate_j, rtb_Saturation,
        localP->CombinedSlipWheel2DOF_Q_FCY2, localB->Integrator_h,
        ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce,
        localB->VectorConcatenate);
    }

    FzUnSat[0] = rtb_VectorConcatenate_j[0];
    FzUnSat[1] = rtb_VectorConcatenate_j[1];
    FzUnSat[2] = rtb_VectorConcatenate_j[2];
    FzUnSat[3] = rtb_VectorConcatenate_j[3];
    ec_data = rtb_ImpAsg_InsertedFor_Omega_at[0] *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd;
    lam_Cz_0 = rtb_VectorConcatenate_j[0] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    localB->Re[0] = (ec_data * ec_data * localP->CombinedSlipWheel2DOF_Q_V1 +
                     localP->CombinedSlipWheel2DOF_Q_RE0) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius - (std::atan
      (localP->CombinedSlipWheel2DOF_BREFF * lam_Cz_0) *
      localP->CombinedSlipWheel2DOF_DREFF + localP->CombinedSlipWheel2DOF_FREFF *
      lam_Cz_0) * (ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce /
                   localB->Re[0]);
    ec_data = rtb_ImpAsg_InsertedFor_Omega_at[1] *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd;
    lam_Cz_0 = rtb_VectorConcatenate_j[1] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    localB->Re[1] = (ec_data * ec_data * localP->CombinedSlipWheel2DOF_Q_V1 +
                     localP->CombinedSlipWheel2DOF_Q_RE0) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius - (std::atan
      (localP->CombinedSlipWheel2DOF_BREFF * lam_Cz_0) *
      localP->CombinedSlipWheel2DOF_DREFF + localP->CombinedSlipWheel2DOF_FREFF *
      lam_Cz_0) * (ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce /
                   localB->Re[1]);
    ec_data = rtb_ImpAsg_InsertedFor_Omega_at[2] *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd;
    lam_Cz_0 = rtb_VectorConcatenate_j[2] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    localB->Re[2] = (ec_data * ec_data * localP->CombinedSlipWheel2DOF_Q_V1 +
                     localP->CombinedSlipWheel2DOF_Q_RE0) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius - (std::atan
      (localP->CombinedSlipWheel2DOF_BREFF * lam_Cz_0) *
      localP->CombinedSlipWheel2DOF_DREFF + localP->CombinedSlipWheel2DOF_FREFF *
      lam_Cz_0) * (ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce /
                   localB->Re[2]);
    ec_data = rtb_ImpAsg_InsertedFor_Omega_at[3] *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd;
    lam_Cz_0 = rtb_VectorConcatenate_j[3] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    localB->Re[3] = (ec_data * ec_data * localP->CombinedSlipWheel2DOF_Q_V1 +
                     localP->CombinedSlipWheel2DOF_Q_RE0) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius - (std::atan
      (localP->CombinedSlipWheel2DOF_BREFF * lam_Cz_0) *
      localP->CombinedSlipWheel2DOF_DREFF + localP->CombinedSlipWheel2DOF_FREFF *
      lam_Cz_0) * (ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce /
                   localB->Re[3]);
    for (i = 0; i < 4; i++) {
      rtb_Saturation_1 = rtb_VectorConcatenate_j[i];
      if (rtb_Saturation_1 < ConfiguredVirtualVehicleModel_P->PlntWhlMinFz) {
        rtb_Saturation_1 = ConfiguredVirtualVehicleModel_P->PlntWhlMinFz;
        rtb_VectorConcatenate_j[i] =
          ConfiguredVirtualVehicleModel_P->PlntWhlMinFz;
      }

      if (rtb_Saturation_1 > ConfiguredVirtualVehicleModel_P->PlntWhlMaxFz) {
        rtb_VectorConcatenate_j[i] =
          ConfiguredVirtualVehicleModel_P->PlntWhlMaxFz;
      }

      if (localB->Re[i] < 0.001) {
        localB->Re[i] = 0.001;
      }
    }

    dfz_0 = (rtb_VectorConcatenate_j[0] - Fzo_prime_idx_0) / Fzo_prime_idx_0;
    dfz[0] = dfz_0;
    epsilon_gamma[0] = (localP->MagicTireConstInput_PECP2 * dfz_0 + 1.0) *
      localP->MagicTireConstInput_PECP1;
    dfz_0 = (rtb_VectorConcatenate_j[1] - Fzo_prime_idx_1) / Fzo_prime_idx_1;
    dfz[1] = dfz_0;
    epsilon_gamma[1] = (localP->MagicTireConstInput_PECP2 * dfz_0 + 1.0) *
      localP->MagicTireConstInput_PECP1;
    dfz_0 = (rtb_VectorConcatenate_j[2] - Fzo_prime_idx_2) / Fzo_prime_idx_2;
    dfz[2] = dfz_0;
    epsilon_gamma[2] = (localP->MagicTireConstInput_PECP2 * dfz_0 + 1.0) *
      localP->MagicTireConstInput_PECP1;
    dfz_0 = (rtb_VectorConcatenate_j[3] - Fzo_prime_idx_3) / Fzo_prime_idx_3;
    dfz[3] = dfz_0;
    epsilon_gamma[3] = (localP->MagicTireConstInput_PECP2 * dfz_0 + 1.0) *
      localP->MagicTireConstInput_PECP1;
    rtb_Kappa[0] = (localB->Re[0] * rtb_ImpAsg_InsertedFor_Omega_at[0] -
                    rtb_ImpAsg_InsertedFor_xdotWhee[0]) / Vsy[0];
    rtb_Kappa[1] = (localB->Re[1] * rtb_ImpAsg_InsertedFor_Omega_at[1] -
                    rtb_ImpAsg_InsertedFor_xdotWhee[1]) / Vsy[1];
    rtb_Kappa[2] = (localB->Re[2] * rtb_ImpAsg_InsertedFor_Omega_at[2] -
                    rtb_ImpAsg_InsertedFor_xdotWhee[2]) / Vsy[2];
    rtb_Kappa[3] = (localB->Re[3] * rtb_ImpAsg_InsertedFor_Omega_at[3] -
                    rtb_ImpAsg_InsertedFor_xdotWhee[3]) / Vsy[3];
    rtb_Alpha[0] = rt_atan2d_snf(rtb_ImpAsg_InsertedFor_ydotWhee[0], Vsy[0]);
    rtb_Alpha[1] = rt_atan2d_snf(rtb_ImpAsg_InsertedFor_ydotWhee[1], Vsy[1]);
    rtb_Alpha[2] = rt_atan2d_snf(rtb_ImpAsg_InsertedFor_ydotWhee[2], Vsy[2]);
    rtb_Alpha[3] = rt_atan2d_snf(rtb_ImpAsg_InsertedFor_ydotWhee[3], Vsy[3]);
    for (i = 0; i < 4; i++) {
      rtb_Saturation_1 = rtb_Kappa[i];
      if (rtb_Saturation_1 <
          ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipRatio) {
        rtb_Saturation_1 = ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipRatio;
        rtb_Kappa[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipRatio;
      }

      if (rtb_Saturation_1 >
          ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipRatio) {
        rtb_Kappa[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipRatio;
      }

      rtb_Saturation_1 = rtb_Alpha[i];
      if (rtb_Saturation_1 <
          ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipAngle) {
        rtb_Saturation_1 = ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipAngle;
        rtb_Alpha[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipAngle;
      }

      if (rtb_Saturation_1 >
          ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipAngle) {
        rtb_Alpha[i] = ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipAngle;
      }
    }

    rtb_My[0] = (localP->MagicTireConstInput_PHX2 * dfz[0] +
                 localP->MagicTireConstInput_PHX1) * localB->VectorConcatenate
      [10] + rtb_Kappa[0];
    rtb_My[1] = (localP->MagicTireConstInput_PHX2 * dfz[1] +
                 localP->MagicTireConstInput_PHX1) * localB->VectorConcatenate
      [37] + rtb_Kappa[1];
    rtb_My[2] = (localP->MagicTireConstInput_PHX2 * dfz[2] +
                 localP->MagicTireConstInput_PHX1) * localB->VectorConcatenate
      [64] + rtb_Kappa[2];
    rtb_My[3] = (localP->MagicTireConstInput_PHX2 * dfz_0 +
                 localP->MagicTireConstInput_PHX1) * localB->VectorConcatenate
      [91] + rtb_Kappa[3];
    rtb_Divide_ag = std::sin(rtb_sig_x[0]);
    rtb_Saturation[0] = rtb_Divide_ag;
    ec_data = -Vsy[0] * rtb_Kappa[0];
    rtb_SOC_CC = std::tan(rtb_Alpha[0]);
    Vsy_0 = -Vsy[0] * rtb_SOC_CC;
    rtb_Saturation_1 = Vsy_0 * Vsy_0;
    R_omega[0] = std::sqrt(rtb_ImpAsg_InsertedFor_xdotWhee[0] *
      rtb_ImpAsg_InsertedFor_xdotWhee[0] + rtb_Saturation_1);
    Vsy_0 = std::sqrt(ec_data * ec_data + rtb_Saturation_1) *
      localB->VectorConcatenate[3] /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0;
    rtb_sig_y[0] = Vsy_0;
    lam_mux[0] /= Vsy_0;
    rtb_Saturation_tmp = std::sin(rtb_sig_x[1]);
    rtb_Saturation[1] = rtb_Saturation_tmp;
    ec_data = -Vsy[1] * rtb_Kappa[1];
    rtb_Integrator1_f = std::tan(rtb_Alpha[1]);
    Vsy_0 = -Vsy[1] * rtb_Integrator1_f;
    rtb_Saturation_1 = Vsy_0 * Vsy_0;
    R_omega[1] = std::sqrt(rtb_ImpAsg_InsertedFor_xdotWhee[1] *
      rtb_ImpAsg_InsertedFor_xdotWhee[1] + rtb_Saturation_1);
    Vsy_0 = std::sqrt(ec_data * ec_data + rtb_Saturation_1) *
      localB->VectorConcatenate[30] /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0;
    rtb_sig_y[1] = Vsy_0;
    lam_mux[1] /= Vsy_0;
    rtb_Saturation_tmp_0 = std::sin(rtb_sig_x[2]);
    rtb_Saturation[2] = rtb_Saturation_tmp_0;
    ec_data = -Vsy[2] * rtb_Kappa[2];
    Vsy_tmp = std::tan(rtb_Alpha[2]);
    Vsy_0 = -Vsy[2] * Vsy_tmp;
    rtb_Saturation_1 = Vsy_0 * Vsy_0;
    R_omega[2] = std::sqrt(rtb_ImpAsg_InsertedFor_xdotWhee[2] *
      rtb_ImpAsg_InsertedFor_xdotWhee[2] + rtb_Saturation_1);
    Vsy_0 = std::sqrt(ec_data * ec_data + rtb_Saturation_1) *
      localB->VectorConcatenate[57] /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0;
    rtb_sig_y[2] = Vsy_0;
    lam_mux[2] /= Vsy_0;
    rtb_Saturation_tmp_1 = std::sin(rtb_sig_x[3]);
    rtb_Saturation[3] = rtb_Saturation_tmp_1;
    ec_data = -Vsy[3] * rtb_Kappa[3];
    lam_Cz_0 = std::tan(rtb_Alpha[3]);
    Vsy_0 = -Vsy[3] * lam_Cz_0;
    rtb_Saturation_1 = Vsy_0 * Vsy_0;
    R_omega[3] = std::sqrt(rtb_ImpAsg_InsertedFor_xdotWhee[3] *
      rtb_ImpAsg_InsertedFor_xdotWhee[3] + rtb_Saturation_1);
    Vsy_0 = std::sqrt(ec_data * ec_data + rtb_Saturation_1) *
      localB->VectorConcatenate[84] /
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd + 1.0;
    lam_mux[3] /= Vsy_0;
    ConfiguredVirtualVe_div0protect(rtb_ImpAsg_InsertedFor_xdotWhee,
      ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel, phi_t, lam_Cz);
    ConfiguredVirtualVe_div0protect(R_omega,
      ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel, cosprimealpha,
      lam_Cz);
    Dx_tmp = dpi[0] * dpi[0];
    rtb_Saturation_1 = lam_muy[0] / rtb_sig_y[0];
    lam_muy[0] = rtb_Saturation_1;
    lam_muy_prime_idx_0 = rtb_Saturation_1 * 10.0 / (9.0 * rtb_Saturation_1 +
      1.0);
    ec_data = rtb_Divide_ag * rtb_Divide_ag;
    rtb_b[0] = ((localP->MagicTireConstInput_PPY3 * dpi[0] + 1.0) + Dx_tmp *
                localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[0] +
       localP->MagicTireConstInput_PDY1) * (1.0 - ec_data *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_1;
    phi_t[0] = -rtb_UnaryMinus[0] / phi_t[0] * std::cos(rtb_Alpha[0]);
    Dx_tmp_0 = dpi[1] * dpi[1];
    rtb_Saturation_1 = lam_muy[1] / rtb_sig_y[1];
    lam_muy[1] = rtb_Saturation_1;
    lam_muy_prime_idx_1 = rtb_Saturation_1 * 10.0 / (9.0 * rtb_Saturation_1 +
      1.0);
    rtb_b_tmp = rtb_Saturation_tmp * rtb_Saturation_tmp;
    rtb_b[1] = ((localP->MagicTireConstInput_PPY3 * dpi[1] + 1.0) + Dx_tmp_0 *
                localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[1] +
       localP->MagicTireConstInput_PDY1) * (1.0 - rtb_b_tmp *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_1;
    phi_t[1] = -rtb_UnaryMinus[1] / phi_t[1] * std::cos(rtb_Alpha[1]);
    Dx_tmp_1 = dpi[2] * dpi[2];
    rtb_Saturation_1 = lam_muy[2] / rtb_sig_y[2];
    lam_muy[2] = rtb_Saturation_1;
    lam_muy_prime_idx_2 = rtb_Saturation_1 * 10.0 / (9.0 * rtb_Saturation_1 +
      1.0);
    rtb_b_tmp_0 = rtb_Saturation_tmp_0 * rtb_Saturation_tmp_0;
    rtb_b[2] = ((localP->MagicTireConstInput_PPY3 * dpi[2] + 1.0) + Dx_tmp_1 *
                localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz[2] +
       localP->MagicTireConstInput_PDY1) * (1.0 - rtb_b_tmp_0 *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_1;
    phi_t[2] = -rtb_UnaryMinus[2] / phi_t[2] * std::cos(rtb_Alpha[2]);
    Dx_tmp_2 = dpi[3] * dpi[3];
    rtb_Saturation_1 = lam_muy[3] / Vsy_0;
    lam_muy_prime_idx_3 = rtb_Saturation_1 * 10.0 / (9.0 * rtb_Saturation_1 +
      1.0);
    rtb_b_tmp_1 = rtb_Saturation_tmp_1 * rtb_Saturation_tmp_1;
    rtb_b[3] = ((localP->MagicTireConstInput_PPY3 * dpi[3] + 1.0) + Dx_tmp_2 *
                localP->MagicTireConstInput_PPY4) *
      (localP->MagicTireConstInput_PDY2 * dfz_0 +
       localP->MagicTireConstInput_PDY1) * (1.0 - rtb_b_tmp_1 *
      localP->MagicTireConstInput_PDY3) * rtb_Saturation_1;
    phi_t[3] = -rtb_UnaryMinus[3] / phi_t[3] * std::cos(rtb_Alpha[3]);
    iy = 0;
    for (i = 0; i < 4; i++) {
      if (rtb_ImpAsg_InsertedFor_xdotWhee[i] <
          ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel) {
        iy++;
      }
    }

    ibmat = 0;
    for (i = 0; i < 4; i++) {
      if (rtb_ImpAsg_InsertedFor_xdotWhee[i] <
          ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel) {
        tmp_data_0[ibmat] = i;
        ibmat++;
      }
    }

    for (i = 0; i < iy; i++) {
      rtb_Saturation_data[i] = rtb_ImpAsg_InsertedFor_xdotWhee[tmp_data_0[i]];
    }

    ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data, &iy, phi, &Itemp_tmp);
    if (iy == Itemp_tmp) {
      for (i = 0; i < iy; i++) {
        rtb_Saturation_data[i] = rtb_ImpAsg_InsertedFor_xdotWhee[tmp_data_0[i]];
      }

      ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data, &iy,
        rtb_Saturation_data_0, &ibmat);
      for (i = 0; i < iy; i++) {
        rtb_Saturation_data[i] = rtb_Saturation_data_0[i] /
          ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel *
          phi_t[tmp_data_0[i]];
      }

      for (i = 0; i < iy; i++) {
        phi_t[tmp_data_0[i]] = rtb_Saturation_data[i];
      }
    } else {
      Configure_binary_expand_op_nxej(phi_t, tmp_data_0, &iy,
        rtb_ImpAsg_InsertedFor_xdotWhee,
        ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel);
    }

    ConfiguredVirtual_div0protect_g(R_omega, rtb_Saturation_data);
    phi[0] = ((1.0 - epsilon_gamma[0]) * std::abs
              (rtb_ImpAsg_InsertedFor_Omega_at[0]) * rtb_Divide_ag +
              rtb_UnaryMinus[0]) * (1.0 / rtb_Saturation_data[0]);
    phi[1] = ((1.0 - epsilon_gamma[1]) * std::abs
              (rtb_ImpAsg_InsertedFor_Omega_at[1]) * rtb_Saturation_tmp +
              rtb_UnaryMinus[1]) * (1.0 / rtb_Saturation_data[1]);
    phi[2] = ((1.0 - epsilon_gamma[2]) * std::abs
              (rtb_ImpAsg_InsertedFor_Omega_at[2]) * rtb_Saturation_tmp_0 +
              rtb_UnaryMinus[2]) * (1.0 / rtb_Saturation_data[2]);
    phi[3] = ((1.0 - epsilon_gamma[3]) * std::abs
              (rtb_ImpAsg_InsertedFor_Omega_at[3]) * rtb_Saturation_tmp_1 +
              rtb_UnaryMinus[3]) * (1.0 / rtb_Saturation_data[3]);
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
    rtb_UnaryMinus[0] = localP->MagicTireConstInput_RHY2 * dfz[0] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[0] = localP->MagicTireConstInput_REY2 * dfz[0] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[1] = !tempInds[1];
    rtb_UnaryMinus[1] = localP->MagicTireConstInput_RHY2 * dfz[1] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[1] = localP->MagicTireConstInput_REY2 * dfz[1] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[2] = !tempInds[2];
    rtb_UnaryMinus[2] = localP->MagicTireConstInput_RHY2 * dfz[2] +
      localP->MagicTireConstInput_RHY1;
    Eykappa[2] = localP->MagicTireConstInput_REY2 * dfz[2] +
      localP->MagicTireConstInput_REY1;
    nomslipinds[3] = !tempInds[3];
    rtb_UnaryMinus[3] = localP->MagicTireConstInput_RHY2 * dfz_0 +
      localP->MagicTireConstInput_RHY1;
    Eykappa[3] = localP->MagicTireConstInput_REY2 * dfz_0 +
      localP->MagicTireConstInput_REY1;
    Bykappa[0] = (ec_data * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * rtb_Alpha[0])) *
      localB->VectorConcatenate[19];
    Bykappa[1] = (rtb_b_tmp * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * rtb_Alpha[1])) *
      localB->VectorConcatenate[46];
    Bykappa[2] = (rtb_b_tmp_0 * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * rtb_Alpha[2])) *
      localB->VectorConcatenate[73];
    Bykappa[3] = (rtb_b_tmp_1 * localP->MagicTireConstInput_RBY4 +
                  localP->MagicTireConstInput_RBY1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBY2 * rtb_Alpha[3])) *
      localB->VectorConcatenate[100];
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

    rtb_RelationalOperator = ConfiguredVirtualVehicleMod_any(tempInds);
    if (rtb_RelationalOperator) {
      b_x[0] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 * rtb_Kappa
        [0]));
      lam_Cz[0] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        rtb_SOC_CC));
      b_x[1] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 * rtb_Kappa
        [1]));
      lam_Cz[1] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        rtb_Integrator1_f));
      b_x[2] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 * rtb_Kappa
        [2]));
      lam_Cz[2] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 * Vsy_tmp));
      b_x[3] = std::cos(std::atan(localP->MagicTireConstInput_PDXP3 * rtb_Kappa
        [3]));
      lam_Cz[3] = std::cos(std::atan(localP->MagicTireConstInput_PDYP3 *
        lam_Cz_0));
      ibmat = iy;
      for (i = 0; i < ibmat; i++) {
        iy = bc_tmp_data[i];
        rtb_Saturation_data[i] = (localP->MagicTireConstInput_PDXP2 * dfz[iy] +
          1.0) * localP->MagicTireConstInput_PDXP1 * b_x[iy] *
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * phi[iy];
      }

      ConfiguredVirtualVehicleMo_atan(rtb_Saturation_data, &ibmat);
      ConfiguredVirtualVehicleMod_cos(rtb_Saturation_data, &ibmat);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 1] = rtb_Saturation_data[i];
        tmpDrphiVar_data[i] = phi[bc_tmp_data[i]];
      }

      ConfiguredVirtualVehicleMod_abs(tmpDrphiVar_data, &rtb_Saturation_size,
        rtb_Saturation_data_0, &ibmat);
      for (i = 0; i < ibmat; i++) {
        rtb_Saturation_data[i] =
          ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
          rtb_Saturation_data_0[i];
      }

      if (ibmat - 1 >= 0) {
        std::memcpy(&tmpDrphiVar_data[0], &rtb_Saturation_data[0],
                    static_cast<uint32_T>(ibmat) * sizeof(real_T));
      }

      ConfiguredVirtualVehicle_sqrt_c(tmpDrphiVar_data, &ibmat);
      if ((ibmat == ibmat) && ((ibmat == 1 ? ibmat : ibmat) ==
           rtb_Saturation_size)) {
        Itemp_tmp = rtb_Saturation_size;
        for (i = 0; i < rtb_Saturation_size; i++) {
          iy = bc_tmp_data[i];
          dc_data[i] = (localP->MagicTireConstInput_PDYP2 * dfz[iy] + 1.0) *
            localP->MagicTireConstInput_PDYP1 * lam_Cz[iy] *
            (localP->MagicTireConstInput_PDYP4 * tmpDrphiVar_data[i] +
             rtb_Saturation_data[i]);
        }
      } else {
        Configured_binary_expand_op_nxe(dc_data, &Itemp_tmp,
          localP->MagicTireConstInput_PDYP1, localP->MagicTireConstInput_PDYP2,
          dfz, lam_Cz, bc_tmp_data, &rtb_Saturation_size, rtb_Saturation_data,
          &ibmat, localP->MagicTireConstInput_PDYP4, tmpDrphiVar_data, &ibmat);
      }

      ConfiguredVirtualVehicleMo_atan(dc_data, &Itemp_tmp);
      ConfiguredVirtualVehicleMod_cos(dc_data, &Itemp_tmp);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 2] = dc_data[i];
      }

      Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        localP->MagicTireConstInput_PKYP1;
      for (i = 0; i < rtb_Saturation_size; i++) {
        dfz_0 = phi[bc_tmp_data[i]];
        rtb_Saturation_data[i] = dfz_0 * dfz_0 * Vsy_0;
      }

      ConfiguredVirtualVehicleMo_atan(rtb_Saturation_data, &rtb_Saturation_size);
      ConfiguredVirtualVehicleMod_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 3] = rtb_Saturation_data[i];
      }
    }

    Vsy_0 = 1.0 - localP->MagicTireConstInput_PKY3 * 0.0;
    Kygammao[0] = (localP->MagicTireConstInput_PKY7 * dfz[0] +
                   localP->MagicTireConstInput_PKY6) * rtb_VectorConcatenate_j[0]
      * (localP->MagicTireConstInput_PPY5 * dpi[0] + 1.0) *
      localB->VectorConcatenate[14];
    Mzphiinf_0 = rtb_VectorConcatenate_j[0] / Fzo_prime_idx_0;
    Mzphiinf[0] = Mzphiinf_0;
    lam_Cz_0 = (localP->MagicTireConstInput_PPY1 * dpi[0] + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_0);
    rtb_a_tmp_tmp = std::sin(std::atan(Mzphiinf_0 / (ec_data *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi[0] + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    dfz_0 = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs(rtb_Divide_ag)) *
      lam_Cz_0 * rtb_a_tmp_tmp * zeta[3] * localB->VectorConcatenate[5];
    rtb_a[0] = dfz_0;
    Gykappa[0] = lam_Cz_0 * Vsy_0 * rtb_a_tmp_tmp * zeta[3] *
      localB->VectorConcatenate[5];
    Kygammao[1] = (localP->MagicTireConstInput_PKY7 * dfz[1] +
                   localP->MagicTireConstInput_PKY6) * rtb_VectorConcatenate_j[1]
      * (localP->MagicTireConstInput_PPY5 * dpi[1] + 1.0) *
      localB->VectorConcatenate[41];
    Mzphiinf_0 = rtb_VectorConcatenate_j[1] / Fzo_prime_idx_1;
    Mzphiinf[1] = Mzphiinf_0;
    lam_Cz_0 = (localP->MagicTireConstInput_PPY1 * dpi[1] + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_1);
    rtb_a_tmp_tmp = std::sin(std::atan(Mzphiinf_0 / (rtb_b_tmp *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi[1] + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_SOC_CC = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
                  (rtb_Saturation_tmp)) * lam_Cz_0 * rtb_a_tmp_tmp * zeta[12] *
      localB->VectorConcatenate[32];
    rtb_a[1] = rtb_SOC_CC;
    Gykappa[1] = lam_Cz_0 * Vsy_0 * rtb_a_tmp_tmp * zeta[12] *
      localB->VectorConcatenate[32];
    Kygammao[2] = (localP->MagicTireConstInput_PKY7 * dfz[2] +
                   localP->MagicTireConstInput_PKY6) * rtb_VectorConcatenate_j[2]
      * (localP->MagicTireConstInput_PPY5 * dpi[2] + 1.0) *
      localB->VectorConcatenate[68];
    Mzphiinf_0 = rtb_VectorConcatenate_j[2] / Fzo_prime_idx_2;
    Mzphiinf[2] = Mzphiinf_0;
    lam_Cz_0 = (localP->MagicTireConstInput_PPY1 * dpi[2] + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_2);
    rtb_a_tmp_tmp = std::sin(std::atan(Mzphiinf_0 / (rtb_b_tmp_0 *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi[2] + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    rtb_Integrator1_f = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
                         (rtb_Saturation_tmp_0)) * lam_Cz_0 * rtb_a_tmp_tmp *
      zeta[21] * localB->VectorConcatenate[59];
    rtb_a[2] = rtb_Integrator1_f;
    Gykappa[2] = lam_Cz_0 * Vsy_0 * rtb_a_tmp_tmp * zeta[21] *
      localB->VectorConcatenate[59];
    Kygammao[3] = (localP->MagicTireConstInput_PKY7 * dfz[3] +
                   localP->MagicTireConstInput_PKY6) * rtb_VectorConcatenate_j[3]
      * (localP->MagicTireConstInput_PPY5 * dpi[3] + 1.0) *
      localB->VectorConcatenate[95];
    Mzphiinf_0 = rtb_VectorConcatenate_j[3] / Fzo_prime_idx_3;
    lam_Cz_0 = (localP->MagicTireConstInput_PPY1 * dpi[3] + 1.0) *
      (localP->MagicTireConstInput_PKY1 * Fzo_prime_idx_3);
    rtb_a_tmp_tmp = std::sin(std::atan(Mzphiinf_0 / (rtb_b_tmp_1 *
      localP->MagicTireConstInput_PKY5 + localP->MagicTireConstInput_PKY2) /
      (localP->MagicTireConstInput_PPY2 * dpi[3] + 1.0)) *
      localP->MagicTireConstInput_PKY4);
    Vsy_tmp = (1.0 - localP->MagicTireConstInput_PKY3 * std::abs
               (rtb_Saturation_tmp_1)) * lam_Cz_0 * rtb_a_tmp_tmp * zeta[30] *
      localB->VectorConcatenate[86];
    rtb_a[3] = Vsy_tmp;
    Gykappa[3] = lam_Cz_0 * Vsy_0 * rtb_a_tmp_tmp * zeta[30] *
      localB->VectorConcatenate[86];
    ConfiguredVirtualVe_div0protect(rtb_a, 0.0001, b_x, lam_Cz);
    ConfiguredVirtualVe_div0protect(Gykappa, 0.0001, Vsy, lam_Cz);
    x_idx_0 = localP->MagicTireConstInput_PHYP1;
    if (localP->MagicTireConstInput_PHYP1 < 0.0) {
      x_idx_0 = 0.0;
    }

    Vsy_0 = std::tanh(rtb_ImpAsg_InsertedFor_xdotWhee[0]);
    lam_Cz[0] = (localP->MagicTireConstInput_PHYP3 * dfz[0] +
                 localP->MagicTireConstInput_PHYP2) * Vsy_0;
    lam_Cz_0 = std::tanh(rtb_ImpAsg_InsertedFor_xdotWhee[1]);
    lam_Cz[1] = (localP->MagicTireConstInput_PHYP3 * dfz[1] +
                 localP->MagicTireConstInput_PHYP2) * lam_Cz_0;
    rtb_a_tmp_tmp = std::tanh(rtb_ImpAsg_InsertedFor_xdotWhee[2]);
    lam_Cz[2] = (localP->MagicTireConstInput_PHYP3 * dfz[2] +
                 localP->MagicTireConstInput_PHYP2) * rtb_a_tmp_tmp;
    lam_Cz_tmp = std::tanh(rtb_ImpAsg_InsertedFor_xdotWhee[3]);
    lam_Cz_tmp_0 = (localP->MagicTireConstInput_PHYP3 * dfz[3] +
                    localP->MagicTireConstInput_PHYP2) * lam_Cz_tmp;
    lam_Cz[3] = lam_Cz_tmp_0;
    ab_idx_0 = localP->MagicTireConstInput_PHYP4;
    if (localP->MagicTireConstInput_PHYP4 > 1.0) {
      ab_idx_0 = 1.0;
    }

    rtb_sig_y[0] = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * phi[0];
    Gykappa[0] = Kygammao[0] / (1.0 - epsilon_gamma[0]) / (x_idx_0 * lam_Cz[0] *
      Vsy[0]);
    rtb_sig_y[1] = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * phi[1];
    Gykappa[1] = Kygammao[1] / (1.0 - epsilon_gamma[1]) / (x_idx_0 * lam_Cz[1] *
      Vsy[1]);
    rtb_sig_y[2] = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * phi[2];
    Gykappa[2] = Kygammao[2] / (1.0 - epsilon_gamma[2]) / (x_idx_0 * lam_Cz[2] *
      Vsy[2]);
    rtb_sig_y[3] = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * phi[3];
    Gykappa[3] = Kygammao[3] / (1.0 - epsilon_gamma[3]) / (lam_Cz_tmp_0 *
      x_idx_0 * Vsy[3]);
    ConfiguredVirtualVehic_magicsin(lam_Cz, x_idx_0, Gykappa, ab_idx_0,
      rtb_sig_y, rtb_Saturation_data);
    Vsy[0] = rtb_Saturation_data[0] * Vsy_0;
    rtb_a[0] = (localP->MagicTireConstInput_PVY4 * dfz[0] +
                localP->MagicTireConstInput_PVY3) * rtb_VectorConcatenate_j[0] *
      rtb_Divide_ag * zeta[2] * localB->VectorConcatenate[14] *
      lam_muy_prime_idx_0;
    SHy[0] = 0.0;
    Gykappa[0] = rtb_Kappa[0] + rtb_UnaryMinus[0];
    Vsy[1] = rtb_Saturation_data[1] * lam_Cz_0;
    rtb_a[1] = (localP->MagicTireConstInput_PVY4 * dfz[1] +
                localP->MagicTireConstInput_PVY3) * rtb_VectorConcatenate_j[1] *
      rtb_Saturation_tmp * zeta[11] * localB->VectorConcatenate[41] *
      lam_muy_prime_idx_1;
    SHy[1] = 0.0;
    Gykappa[1] = rtb_Kappa[1] + rtb_UnaryMinus[1];
    Vsy[2] = rtb_Saturation_data[2] * rtb_a_tmp_tmp;
    rtb_a[2] = (localP->MagicTireConstInput_PVY4 * dfz[2] +
                localP->MagicTireConstInput_PVY3) * rtb_VectorConcatenate_j[2] *
      rtb_Saturation_tmp_0 * zeta[20] * localB->VectorConcatenate[68] *
      lam_muy_prime_idx_2;
    SHy[2] = 0.0;
    Gykappa[2] = rtb_Kappa[2] + rtb_UnaryMinus[2];
    Vsy[3] = rtb_Saturation_data[3] * lam_Cz_tmp;
    rtb_a[3] = (localP->MagicTireConstInput_PVY4 * dfz[3] +
                localP->MagicTireConstInput_PVY3) * rtb_VectorConcatenate_j[3] *
      rtb_Saturation_tmp_1 * zeta[29] * localB->VectorConcatenate[95] *
      lam_muy_prime_idx_3;
    SHy[3] = 0.0;
    Gykappa[3] = rtb_Kappa[3] + rtb_UnaryMinus[3];
    ConfiguredVirtualVehic_magiccos(localP->MagicTireConstInput_RCY1, Bykappa,
      Eykappa, Gykappa, rtb_Saturation_data);
    ConfiguredVirtualVehic_magiccos(localP->MagicTireConstInput_RCY1, Bykappa,
      Eykappa, rtb_UnaryMinus, dc_data);
    Gykappa[0] = rtb_Saturation_data[0] / dc_data[0];
    Gykappa[1] = rtb_Saturation_data[1] / dc_data[1];
    Gykappa[2] = rtb_Saturation_data[2] / dc_data[2];
    Gykappa[3] = rtb_Saturation_data[3] / dc_data[3];
    for (i = 0; i < 4; i++) {
      if (Gykappa[i] < 0.0) {
        Gykappa[i] = 0.0;
      }
    }

    if (rtb_RelationalOperator) {
      for (i = 0; i < rtb_Saturation_size; i++) {
        iy = bc_tmp_data[i];
        zeta[9 * bc_data[i] + 4] = (Vsy[iy] + 1.0) - rtb_a[iy] / b_x[iy];
      }

      Vsy_0 = localP->MagicTireConstInput_QDTP1 *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      for (i = 0; i < rtb_Saturation_size; i++) {
        rtb_Saturation_data[i] = Vsy_0 * phi[bc_tmp_data[i]];
      }

      ConfiguredVirtualVehicleMo_atan(rtb_Saturation_data, &rtb_Saturation_size);
      ConfiguredVirtualVehicleMod_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 5] = rtb_Saturation_data[i];
      }

      Vsy_0 = localP->MagicTireConstInput_QBRP1 *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      for (i = 0; i < rtb_Saturation_size; i++) {
        rtb_Saturation_data[i] = Vsy_0 * phi[bc_tmp_data[i]];
      }

      ConfiguredVirtualVehicleMo_atan(rtb_Saturation_data, &rtb_Saturation_size);
      ConfiguredVirtualVehicleMod_cos(rtb_Saturation_data, &rtb_Saturation_size);
      for (i = 0; i < rtb_Saturation_size; i++) {
        zeta[9 * bc_data[i] + 6] = rtb_Saturation_data[i];
      }

      Mzphiinf[0] = localP->MagicTireConstInput_QCRP1 * rtb_b[0] *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        rtb_VectorConcatenate_j[0] * std::sqrt(Mzphiinf[0]) *
        localB->VectorConcatenate[26];
      Mzphiinf[1] = localP->MagicTireConstInput_QCRP1 * rtb_b[1] *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        rtb_VectorConcatenate_j[1] * std::sqrt(Mzphiinf[1]) *
        localB->VectorConcatenate[53];
      Mzphiinf[2] = localP->MagicTireConstInput_QCRP1 * rtb_b[2] *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        rtb_VectorConcatenate_j[2] * std::sqrt(Mzphiinf[2]) *
        localB->VectorConcatenate[80];
      Mzphiinf[3] = localP->MagicTireConstInput_QCRP1 * rtb_b[3] *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
        rtb_VectorConcatenate_j[3] * std::sqrt(Mzphiinf_0) *
        localB->VectorConcatenate[107];
      for (i = 0; i < 4; i++) {
        if (Mzphiinf[i] < 0.0) {
          Mzphiinf[i] = 1.0E-6;
        }
      }

      Vsy_0 = localP->MagicTireConstInput_QCRP2 *
        ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius;
      Eykappa[0] = std::atan(Vsy_0 * std::abs(phi_t[0]));
      Eykappa[1] = std::atan(Vsy_0 * std::abs(phi_t[1]));
      Eykappa[2] = std::atan(Vsy_0 * std::abs(phi_t[2]));
      Eykappa[3] = std::atan(Vsy_0 * std::abs(phi_t[3]));
      rtb_Saturation_tmp = localP->MagicTireConstInput_QDRP1;
      if (localP->MagicTireConstInput_QDRP1 < 0.0) {
        rtb_Saturation_tmp = 0.0;
      }

      rtb_Saturation_tmp_0 = localP->MagicTireConstInput_QDRP2;
      if (localP->MagicTireConstInput_QDRP2 < 0.0) {
        rtb_Saturation_tmp_0 = 0.0;
      }

      rtb_Divide_ag = std::sin(1.5707963267948966 * rtb_Saturation_tmp);
      lam_Cz_0 = Mzphiinf[0] / rtb_Divide_ag;
      lam_Cz[0] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[0])) {
        Vsy_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[0] < 0.0) {
        Vsy_0 = -1.0;
      } else {
        Vsy_0 = (1.0 - epsilon_gamma[0] > 0.0);
      }

      phi[0] = ((localP->MagicTireConstInput_QDZ11 * dfz[0] +
                 localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[0]) +
                (localP->MagicTireConstInput_QDZ9 * dfz[0] +
                 localP->MagicTireConstInput_QDZ8)) * (rtb_VectorConcatenate_j[0]
        * ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius) *
        localB->VectorConcatenate[15] / (rtb_Saturation_tmp * lam_Cz_0 * (1.0 -
        epsilon_gamma[0]) + 0.0001 * Vsy_0);
      lam_Cz_0 = Mzphiinf[1] / rtb_Divide_ag;
      lam_Cz[1] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[1])) {
        Vsy_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[1] < 0.0) {
        Vsy_0 = -1.0;
      } else {
        Vsy_0 = (1.0 - epsilon_gamma[1] > 0.0);
      }

      phi[1] = ((localP->MagicTireConstInput_QDZ11 * dfz[1] +
                 localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[1]) +
                (localP->MagicTireConstInput_QDZ9 * dfz[1] +
                 localP->MagicTireConstInput_QDZ8)) * (rtb_VectorConcatenate_j[1]
        * ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius) *
        localB->VectorConcatenate[42] / (rtb_Saturation_tmp * lam_Cz_0 * (1.0 -
        epsilon_gamma[1]) + 0.0001 * Vsy_0);
      lam_Cz_0 = Mzphiinf[2] / rtb_Divide_ag;
      lam_Cz[2] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[2])) {
        Vsy_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[2] < 0.0) {
        Vsy_0 = -1.0;
      } else {
        Vsy_0 = (1.0 - epsilon_gamma[2] > 0.0);
      }

      phi[2] = ((localP->MagicTireConstInput_QDZ11 * dfz[2] +
                 localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[2]) +
                (localP->MagicTireConstInput_QDZ9 * dfz[2] +
                 localP->MagicTireConstInput_QDZ8)) * (rtb_VectorConcatenate_j[2]
        * ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius) *
        localB->VectorConcatenate[69] / (rtb_Saturation_tmp * lam_Cz_0 * (1.0 -
        epsilon_gamma[2]) + 0.0001 * Vsy_0);
      lam_Cz_0 = Mzphiinf[3] / rtb_Divide_ag;
      lam_Cz[3] = lam_Cz_0;
      if (std::isnan(1.0 - epsilon_gamma[3])) {
        Vsy_0 = (rtNaN);
      } else if (1.0 - epsilon_gamma[3] < 0.0) {
        Vsy_0 = -1.0;
      } else {
        Vsy_0 = (1.0 - epsilon_gamma[3] > 0.0);
      }

      phi[3] = ((localP->MagicTireConstInput_QDZ11 * dfz[3] +
                 localP->MagicTireConstInput_QDZ10) * std::abs(rtb_sig_x[3]) +
                (localP->MagicTireConstInput_QDZ9 * dfz[3] +
                 localP->MagicTireConstInput_QDZ8)) * (rtb_VectorConcatenate_j[3]
        * ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius) *
        localB->VectorConcatenate[96] / (rtb_Saturation_tmp * lam_Cz_0 * (1.0 -
        epsilon_gamma[3]) + 0.0001 * Vsy_0);
      ConfiguredVirtualVehic_magicsin(lam_Cz, rtb_Saturation_tmp, phi,
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

      ConfiguredVirtualVehicleMod_abs(rtb_Saturation_data, &rtb_Saturation_size,
        rtb_Saturation_data_0, &ibmat);
      ConfiguredVirtualVehicleMod_abs(dc_data, &rtb_Saturation_size, phi,
        &Itemp_tmp);
      if ((Itemp_tmp == rtb_Saturation_size) && ((ibmat == 1 ?
            rtb_Saturation_size : ibmat) == rtb_Saturation_size)) {
        for (i = 0; i < rtb_Saturation_size; i++) {
          dc_data[i] = R_omega[bc_tmp_data[i]];
        }

        ConfiguredVirtualVehicleMod_abs(dc_data, &rtb_Saturation_size,
          rtb_Saturation_data_0, &ibmat);
        ibmat = rtb_Saturation_size;
        for (i = 0; i < rtb_Saturation_size; i++) {
          iy = bc_tmp_data[i];
          tmpDrphiVar_data[i] = Mzphiinf[iy] * 2.0 / 3.1415926535897931 *
            Eykappa[iy] * Gykappa[iy] / (0.0001 * lam_Cz[iy] +
            rtb_Saturation_data_0[i]);
        }
      } else {
        ConfiguredV_binary_expand_op_nx(tmpDrphiVar_data, &ibmat, Mzphiinf,
          Eykappa, Gykappa, bc_tmp_data, &rtb_Saturation_size, R_omega, lam_Cz);
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

      ConfiguredVirtualVehicleMo_acos(tmpDrphiVar_data, &ibmat);
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
          SHy[bc_data[i]] = (localB->VectorConcatenate[27 * iy + 11] * (0.0 *
            dfz[iy]) + Vsy[iy]) - rtb_a[iy] / b_x[iy];
        }
      } else {
        ConfiguredVi_binary_expand_op_n(SHy, bc_data, dfz, bc_tmp_data,
          &rtb_Saturation_size, localB->VectorConcatenate, lb, Vsy, rtb_a, b_x);
      }
    }

    Eykappa[0] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate[6];
    Eykappa[1] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate[33];
    Eykappa[2] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate[60];
    Eykappa[3] = localP->MagicTireConstInput_PCX1 * localB->VectorConcatenate[87];
    rtb_Divide_ag = rtb_sig_x[0] * rtb_sig_x[0];
    epsilon_gamma[0] = ((localP->MagicTireConstInput_PPX3 * dpi[0] + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp) *
      (localP->MagicTireConstInput_PDX2 * dfz[0] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Divide_ag *
      localP->MagicTireConstInput_PDX3) * lam_mux[0] * rtb_VectorConcatenate_j[0]
      * zeta[1];
    rtb_Saturation_tmp = rtb_sig_x[1] * rtb_sig_x[1];
    epsilon_gamma[1] = ((localP->MagicTireConstInput_PPX3 * dpi[1] + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp_0) *
      (localP->MagicTireConstInput_PDX2 * dfz[1] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp *
      localP->MagicTireConstInput_PDX3) * lam_mux[1] * rtb_VectorConcatenate_j[1]
      * zeta[10];
    rtb_Saturation_tmp_0 = rtb_sig_x[2] * rtb_sig_x[2];
    epsilon_gamma[2] = ((localP->MagicTireConstInput_PPX3 * dpi[2] + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp_1) *
      (localP->MagicTireConstInput_PDX2 * dfz[2] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp_0 *
      localP->MagicTireConstInput_PDX3) * lam_mux[2] * rtb_VectorConcatenate_j[2]
      * zeta[19];
    rtb_Saturation_tmp_1 = rtb_sig_x[3] * rtb_sig_x[3];
    epsilon_gamma[3] = ((localP->MagicTireConstInput_PPX3 * dpi[3] + 1.0) +
                        localP->MagicTireConstInput_PPX4 * Dx_tmp_2) *
      (localP->MagicTireConstInput_PDX2 * dfz[3] +
       localP->MagicTireConstInput_PDX1) * (1.0 - rtb_Saturation_tmp_1 *
      localP->MagicTireConstInput_PDX3) * lam_mux[3] * rtb_VectorConcatenate_j[3]
      * zeta[28];
    Mzphiinf_0 = dfz[0] * dfz[0];
    Bykappa[0] = ((localP->MagicTireConstInput_PEX2 * dfz[0] +
                   localP->MagicTireConstInput_PEX1) + Mzphiinf_0 *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[0]) * localP->MagicTireConstInput_PEX4) * localB->
      VectorConcatenate[8];
    rtb_a_tmp_tmp = dfz[1] * dfz[1];
    Bykappa[1] = ((localP->MagicTireConstInput_PEX2 * dfz[1] +
                   localP->MagicTireConstInput_PEX1) + rtb_a_tmp_tmp *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[1]) * localP->MagicTireConstInput_PEX4) * localB->
      VectorConcatenate[35];
    lam_Cz_tmp = dfz[2] * dfz[2];
    Bykappa[2] = ((localP->MagicTireConstInput_PEX2 * dfz[2] +
                   localP->MagicTireConstInput_PEX1) + lam_Cz_tmp *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[2]) * localP->MagicTireConstInput_PEX4) * localB->
      VectorConcatenate[62];
    lam_Cz_tmp_0 = dfz[3] * dfz[3];
    Bykappa[3] = ((localP->MagicTireConstInput_PEX2 * dfz[3] +
                   localP->MagicTireConstInput_PEX1) + lam_Cz_tmp_0 *
                  localP->MagicTireConstInput_PEX3) * (1.0 - std::tanh(10.0 *
      rtb_My[3]) * localP->MagicTireConstInput_PEX4) * localB->
      VectorConcatenate[89];
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
                localP->MagicTireConstInput_PKX1) * rtb_VectorConcatenate_j[0] *
      std::exp(localP->MagicTireConstInput_PKX3 * dfz[0]) *
      ((localP->MagicTireConstInput_PPX1 * dpi[0] + 1.0) + Dx_tmp *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate[4];
    rtb_sig_y[0] = Eykappa[0] * epsilon_gamma[0];
    phi_t[1] = (localP->MagicTireConstInput_PKX2 * dfz[1] +
                localP->MagicTireConstInput_PKX1) * rtb_VectorConcatenate_j[1] *
      std::exp(localP->MagicTireConstInput_PKX3 * dfz[1]) *
      ((localP->MagicTireConstInput_PPX1 * dpi[1] + 1.0) + Dx_tmp_0 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate[31];
    rtb_sig_y[1] = Eykappa[1] * epsilon_gamma[1];
    phi_t[2] = (localP->MagicTireConstInput_PKX2 * dfz[2] +
                localP->MagicTireConstInput_PKX1) * rtb_VectorConcatenate_j[2] *
      std::exp(localP->MagicTireConstInput_PKX3 * dfz[2]) *
      ((localP->MagicTireConstInput_PPX1 * dpi[2] + 1.0) + Dx_tmp_1 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate[58];
    rtb_sig_y[2] = Eykappa[2] * epsilon_gamma[2];
    Dx_tmp = (localP->MagicTireConstInput_PKX2 * dfz[3] +
              localP->MagicTireConstInput_PKX1) * rtb_VectorConcatenate_j[3] *
      std::exp(localP->MagicTireConstInput_PKX3 * dfz[3]) *
      ((localP->MagicTireConstInput_PPX1 * dpi[3] + 1.0) + Dx_tmp_2 *
       localP->MagicTireConstInput_PPX2) * localB->VectorConcatenate[85];
    rtb_sig_y[3] = Eykappa[3] * epsilon_gamma[3];
    ConfiguredVirtualVe_div0protect(rtb_sig_y, 0.0001, Vsy, lam_Cz);
    lam_Cz[0] = localP->MagicTireConstInput_REX2 * dfz[0] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[1] = localP->MagicTireConstInput_REX2 * dfz[1] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[2] = localP->MagicTireConstInput_REX2 * dfz[2] +
      localP->MagicTireConstInput_REX1;
    lam_Cz[3] = localP->MagicTireConstInput_REX2 * dfz[3] +
      localP->MagicTireConstInput_REX1;
    R_omega[0] = (ec_data * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * rtb_Kappa[0])) *
      localB->VectorConcatenate[18];
    R_omega[1] = (rtb_b_tmp * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * rtb_Kappa[1])) *
      localB->VectorConcatenate[45];
    R_omega[2] = (rtb_b_tmp_0 * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * rtb_Kappa[2])) *
      localB->VectorConcatenate[72];
    R_omega[3] = (rtb_b_tmp_1 * localP->MagicTireConstInput_RBX3 +
                  localP->MagicTireConstInput_RBX1) * std::cos(std::atan
      (localP->MagicTireConstInput_RBX2 * rtb_Kappa[3])) *
      localB->VectorConcatenate[99];
    for (i = 0; i < 4; i++) {
      if (lam_Cz[i] > 1.0) {
        lam_Cz[i] = 1.0;
      }

      if (R_omega[i] < 0.0) {
        R_omega[i] = 0.0;
      }
    }

    ConfiguredVirtualVehic_magiccos(localP->MagicTireConstInput_RCX1, R_omega,
      lam_Cz, rtb_Alpha, rtb_Saturation_data);
    ConfiguredVirtualVeh_magiccos_o(localP->MagicTireConstInput_RCX1, R_omega,
      lam_Cz, dc_data);
    rtb_sig_y[0] = rtb_Saturation_data[0] / dc_data[0];
    rtb_sig_y[1] = rtb_Saturation_data[1] / dc_data[1];
    rtb_sig_y[2] = rtb_Saturation_data[2] / dc_data[2];
    rtb_sig_y[3] = rtb_Saturation_data[3] / dc_data[3];
    for (i = 0; i < 4; i++) {
      if (rtb_sig_y[i] < 0.0) {
        rtb_sig_y[i] = 0.0;
      }
    }

    Mzphiinf[0] = phi_t[0] / Vsy[0];
    Mzphiinf[1] = phi_t[1] / Vsy[1];
    Mzphiinf[2] = phi_t[2] / Vsy[2];
    Mzphiinf[3] = Dx_tmp / Vsy[3];
    ConfiguredVirtualVeh_magicsin_p(epsilon_gamma, Eykappa, Mzphiinf, Bykappa,
      rtb_My, rtb_Saturation_data);
    lam_mux[0] = ((localP->MagicTireConstInput_PVX2 * dfz[0] +
                   localP->MagicTireConstInput_PVX1) * rtb_VectorConcatenate_j[0]
                  * (lam_mux[0] * 10.0 / (9.0 * lam_mux[0] + 1.0)) *
                  localB->VectorConcatenate[12] * zeta[1] + rtb_Saturation_data
                  [0]) * rtb_sig_y[0];
    Mzphiinf[0] = localP->MagicTireConstInput_PCY1 * localB->VectorConcatenate[7];
    lam_mux[1] = ((localP->MagicTireConstInput_PVX2 * dfz[1] +
                   localP->MagicTireConstInput_PVX1) * rtb_VectorConcatenate_j[1]
                  * (lam_mux[1] * 10.0 / (9.0 * lam_mux[1] + 1.0)) *
                  localB->VectorConcatenate[39] * zeta[10] +
                  rtb_Saturation_data[1]) * rtb_sig_y[1];
    Mzphiinf[1] = localP->MagicTireConstInput_PCY1 * localB->VectorConcatenate
      [34];
    lam_mux[2] = ((localP->MagicTireConstInput_PVX2 * dfz[2] +
                   localP->MagicTireConstInput_PVX1) * rtb_VectorConcatenate_j[2]
                  * (lam_mux[2] * 10.0 / (9.0 * lam_mux[2] + 1.0)) *
                  localB->VectorConcatenate[66] * zeta[19] +
                  rtb_Saturation_data[2]) * rtb_sig_y[2];
    Mzphiinf[2] = localP->MagicTireConstInput_PCY1 * localB->VectorConcatenate
      [61];
    lam_mux[3] = ((localP->MagicTireConstInput_PVX2 * dfz[3] +
                   localP->MagicTireConstInput_PVX1) * rtb_VectorConcatenate_j[3]
                  * (lam_mux[3] * 10.0 / (9.0 * lam_mux[3] + 1.0)) *
                  localB->VectorConcatenate[93] * zeta[28] +
                  rtb_Saturation_data[3]) * rtb_sig_y[3];
    Mzphiinf[3] = localP->MagicTireConstInput_PCY1 * localB->VectorConcatenate
      [88];
    for (i = 0; i < 4; i++) {
      if (Mzphiinf[i] < 0.0) {
        Mzphiinf[i] = 0.0;
      }
    }

    ec_data = rtb_b[0] * rtb_VectorConcatenate_j[0];
    rtb_b[0] = ec_data;
    Vsy_0 = ec_data * zeta[2];
    Vsy[0] = Vsy_0;
    phi[0] = Mzphiinf[0] * Vsy_0;
    ec_data = rtb_b[1] * rtb_VectorConcatenate_j[1];
    rtb_b[1] = ec_data;
    Vsy_0 = ec_data * zeta[11];
    Vsy[1] = Vsy_0;
    phi[1] = Mzphiinf[1] * Vsy_0;
    ec_data = rtb_b[2] * rtb_VectorConcatenate_j[2];
    rtb_b[2] = ec_data;
    Vsy_0 = ec_data * zeta[20];
    Vsy[2] = Vsy_0;
    phi[2] = Mzphiinf[2] * Vsy_0;
    ec_data = rtb_b[3] * rtb_VectorConcatenate_j[3];
    Vsy_0 = ec_data * zeta[29];
    Vsy[3] = Vsy_0;
    phi[3] = Mzphiinf[3] * Vsy_0;
    ConfiguredVirtualVe_div0protect(phi, 0.0001, epsilon_gamma, lam_Cz);
    epsilon_gamma[0] = dfz_0 / epsilon_gamma[0];
    epsilon_gamma[1] = rtb_SOC_CC / epsilon_gamma[1];
    epsilon_gamma[2] = rtb_Integrator1_f / epsilon_gamma[2];
    epsilon_gamma[3] = Vsy_tmp / epsilon_gamma[3];
    if (ConfiguredVirtualVehicleMod_any(nomslipinds)) {
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
          SHy[tmp_data_1[i]] = (((Kygammao[iy] * rtb_Saturation[iy] - rtb_a[iy])
            / b_x[iy] * zeta[9 * iy] + localB->VectorConcatenate[27 * iy + 11] *
            (0.0 * dfz[iy])) + zeta[9 * iy + 4]) - 1.0;
        }
      } else {
        ConfiguredVirt_binary_expand_op(SHy, tmp_data_1, dfz, tmp_data_2,
          &Itemp_tmp, localB->VectorConcatenate, lb, Kygammao, rtb_Saturation,
          rtb_a, b_x, zeta);
      }
    }

    lam_muy_prime_idx_0 = 0.0 * dfz[0] * rtb_VectorConcatenate_j[0] *
      localB->VectorConcatenate[13] * lam_muy_prime_idx_0 * zeta[2] + rtb_a[0];
    lam_Cz_0 = rtb_Alpha[0] + SHy[0];
    R_omega[0] = lam_Cz_0;
    if (std::isnan(lam_Cz_0)) {
      lam_Cz[0] = (rtNaN);
    } else if (lam_Cz_0 < 0.0) {
      lam_Cz[0] = -1.0;
    } else {
      lam_Cz[0] = (lam_Cz_0 > 0.0);
    }

    lam_muy_prime_idx_1 = 0.0 * dfz[1] * rtb_VectorConcatenate_j[1] *
      localB->VectorConcatenate[40] * lam_muy_prime_idx_1 * zeta[11] + rtb_a[1];
    lam_Cz_0 = rtb_Alpha[1] + SHy[1];
    R_omega[1] = lam_Cz_0;
    if (std::isnan(lam_Cz_0)) {
      lam_Cz[1] = (rtNaN);
    } else if (lam_Cz_0 < 0.0) {
      lam_Cz[1] = -1.0;
    } else {
      lam_Cz[1] = (lam_Cz_0 > 0.0);
    }

    lam_muy_prime_idx_2 = 0.0 * dfz[2] * rtb_VectorConcatenate_j[2] *
      localB->VectorConcatenate[67] * lam_muy_prime_idx_2 * zeta[20] + rtb_a[2];
    lam_Cz_0 = rtb_Alpha[2] + SHy[2];
    R_omega[2] = lam_Cz_0;
    if (std::isnan(lam_Cz_0)) {
      lam_Cz[2] = (rtNaN);
    } else if (lam_Cz_0 < 0.0) {
      lam_Cz[2] = -1.0;
    } else {
      lam_Cz[2] = (lam_Cz_0 > 0.0);
    }

    lam_muy_prime_idx_3 = 0.0 * dfz[3] * rtb_VectorConcatenate_j[3] *
      localB->VectorConcatenate[94] * lam_muy_prime_idx_3 * zeta[29] + rtb_a[3];
    lam_Cz_0 = rtb_Alpha[3] + SHy[3];
    R_omega[3] = lam_Cz_0;
    if (std::isnan(lam_Cz_0)) {
      lam_Cz[3] = (rtNaN);
    } else if (lam_Cz_0 < 0.0) {
      lam_Cz[3] = -1.0;
    } else {
      lam_Cz[3] = (lam_Cz_0 > 0.0);
    }

    for (i = 0; i < 4; i++) {
      if (lam_Cz[i] == 0.0) {
        lam_Cz[i] = 1.0;
      }
    }

    lam_Cz_0 = rtb_Saturation[0] * rtb_Saturation[0];
    rtb_sig_y[0] = ((lam_Cz_0 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[0] *
                    lam_Cz[0]) * (localP->MagicTireConstInput_PEY2 * dfz[0] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate[9];
    rtb_b_tmp_1 = rtb_Saturation[1] * rtb_Saturation[1];
    rtb_sig_y[1] = ((rtb_b_tmp_1 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[1] *
                    lam_Cz[1]) * (localP->MagicTireConstInput_PEY2 * dfz[1] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate[36];
    Dx_tmp_1 = rtb_Saturation[2] * rtb_Saturation[2];
    rtb_sig_y[2] = ((Dx_tmp_1 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[2] *
                    lam_Cz[2]) * (localP->MagicTireConstInput_PEY2 * dfz[2] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate[63];
    Dx_tmp_0 = rtb_Saturation[3] * rtb_Saturation[3];
    rtb_sig_y[3] = ((Dx_tmp_0 * localP->MagicTireConstInput_PEY5 + 1.0) -
                    localP->MagicTireConstInput_PEY4 * rtb_Saturation[3] *
                    lam_Cz[3]) * (localP->MagicTireConstInput_PEY2 * dfz[3] +
      localP->MagicTireConstInput_PEY1) * localB->VectorConcatenate[90];
    for (i = 0; i < 4; i++) {
      if (rtb_sig_y[i] > 1.0) {
        rtb_sig_y[i] = 1.0;
      }
    }

    ConfiguredVirtualVeh_magicsin_p(Vsy, Mzphiinf, epsilon_gamma, rtb_sig_y,
      R_omega, rtb_Saturation_data);
    rtb_b_tmp = (0.0 * dfz[0] + localP->MagicTireConstInput_RVY3 *
                 rtb_Saturation[0]) * rtb_b[0] * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * rtb_Alpha[0])) * zeta[2] * std::sin
      (std::atan(localP->MagicTireConstInput_RVY6 * rtb_Kappa[0]) *
       localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate[20];
    rtb_b[0] = rtb_b_tmp;
    Gykappa[0] = (rtb_Saturation_data[0] + lam_muy_prime_idx_0) * Gykappa[0] +
      rtb_b_tmp;
    dc_data[0] = localB->VectorConcatenate[25];
    rtb_b_tmp = (0.0 * dfz[1] + localP->MagicTireConstInput_RVY3 *
                 rtb_Saturation[1]) * rtb_b[1] * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * rtb_Alpha[1])) * zeta[11] * std::sin
      (std::atan(localP->MagicTireConstInput_RVY6 * rtb_Kappa[1]) *
       localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate[47];
    rtb_b[1] = rtb_b_tmp;
    Gykappa[1] = (rtb_Saturation_data[1] + lam_muy_prime_idx_1) * Gykappa[1] +
      rtb_b_tmp;
    dc_data[1] = localB->VectorConcatenate[52];
    rtb_b_tmp = (0.0 * dfz[2] + localP->MagicTireConstInput_RVY3 *
                 rtb_Saturation[2]) * rtb_b[2] * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * rtb_Alpha[2])) * zeta[20] * std::sin
      (std::atan(localP->MagicTireConstInput_RVY6 * rtb_Kappa[2]) *
       localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate[74];
    rtb_b[2] = rtb_b_tmp;
    Gykappa[2] = (rtb_Saturation_data[2] + lam_muy_prime_idx_2) * Gykappa[2] +
      rtb_b_tmp;
    dc_data[2] = localB->VectorConcatenate[79];
    rtb_b_tmp = (0.0 * dfz[3] + localP->MagicTireConstInput_RVY3 *
                 rtb_Saturation[3]) * ec_data * std::cos(std::atan
      (localP->MagicTireConstInput_RVY4 * rtb_Alpha[3])) * zeta[29] * std::sin
      (std::atan(localP->MagicTireConstInput_RVY6 * rtb_Kappa[3]) *
       localP->MagicTireConstInput_RVY5) * localB->VectorConcatenate[101];
    Gykappa[3] = (rtb_Saturation_data[3] + lam_muy_prime_idx_3) * Gykappa[3] +
      rtb_b_tmp;
    dc_data[3] = localB->VectorConcatenate[106];
    ConfiguredVirtual_rollingMoment(lam_mux, rtb_ImpAsg_InsertedFor_xdotWhee,
      FzUnSat, rtb_Saturation_g, rtb_sig_x,
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd,
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius,
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce,
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress,
      localP->MagicTireConstInput_QSY1, localP->MagicTireConstInput_QSY2,
      localP->MagicTireConstInput_QSY3, localP->MagicTireConstInput_QSY4,
      localP->MagicTireConstInput_QSY5, localP->MagicTireConstInput_QSY6,
      localP->MagicTireConstInput_QSY7, localP->MagicTireConstInput_QSY8,
      dc_data, rtb_Saturation_data);
    rtb_My[0] = std::tanh(10.0 * rtb_ImpAsg_InsertedFor_Omega_at[0]) *
      rtb_Saturation_data[0];
    ec_data = localP->MagicTireConstInput_QSX6 * rtb_VectorConcatenate_j[0] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    rtb_b_tmp_0 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      rtb_VectorConcatenate_j[0];
    Bykappa[0] = rtb_b_tmp_0;
    Dx_tmp_2 = std::abs(rtb_sig_x[0]);
    rtb_VectorConcatenate1[0] = (((((0.0 * localB->VectorConcatenate[24] -
      (localP->MagicTireConstInput_PPMX1 * dpi[0] + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[0])) -
      localP->MagicTireConstInput_QSX12 * rtb_sig_x[0] * Dx_tmp_2) +
      localP->MagicTireConstInput_QSX3 * Gykappa[0] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) + std::sin(std::atan
      (localP->MagicTireConstInput_QSX9 * Gykappa[0] /
       ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[0]) * (std::cos(std::atan(ec_data * ec_data) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
      std::atan(localP->MagicTireConstInput_QSX11 * rtb_VectorConcatenate_j[0] /
                ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX10 * rtb_sig_x[0]) * (rtb_b_tmp_0 *
      localB->VectorConcatenate[23]) +
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * Gykappa[0] *
      localB->VectorConcatenate[23] * (localP->MagicTireConstInput_QSX14 *
      Dx_tmp_2 + localP->MagicTireConstInput_QSX13);
    cosprimealpha[0] = rtb_ImpAsg_InsertedFor_xdotWhee[0] / cosprimealpha[0];
    Eykappa[0] = ((localP->MagicTireConstInput_QHZ4 * dfz[0] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[0] + 0.0 *
                  dfz[0]) + rtb_Alpha[0];
    SHy[0] = (lam_muy_prime_idx_0 / b_x[0] + SHy[0]) + rtb_Alpha[0];
    Vsy_0 = 0.0 * rtb_sig_x[0] + 1.0;
    rtb_sig_y[0] = Vsy_0;
    rtb_UnaryMinus[0] = ((localP->MagicTireConstInput_QBZ2 * dfz[0] +
                          localP->MagicTireConstInput_QBZ1) + Mzphiinf_0 *
                         localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * Dx_tmp_2 + Vsy_0) + lam_Cz_0 *
       localP->MagicTireConstInput_QBZ6) * localB->VectorConcatenate[5] /
      lam_muy[0];
    rtb_My[1] = std::tanh(10.0 * rtb_ImpAsg_InsertedFor_Omega_at[1]) *
      rtb_Saturation_data[1];
    ec_data = localP->MagicTireConstInput_QSX6 * rtb_VectorConcatenate_j[1] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    rtb_b_tmp_0 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      rtb_VectorConcatenate_j[1];
    Bykappa[1] = rtb_b_tmp_0;
    Dx_tmp_2 = std::abs(rtb_sig_x[1]);
    rtb_VectorConcatenate1[1] = (((((0.0 * localB->VectorConcatenate[51] -
      (localP->MagicTireConstInput_PPMX1 * dpi[1] + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[1])) -
      localP->MagicTireConstInput_QSX12 * rtb_sig_x[1] * Dx_tmp_2) +
      localP->MagicTireConstInput_QSX3 * Gykappa[1] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) + std::sin(std::atan
      (localP->MagicTireConstInput_QSX9 * Gykappa[1] /
       ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[1]) * (std::cos(std::atan(ec_data * ec_data) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
      std::atan(localP->MagicTireConstInput_QSX11 * rtb_VectorConcatenate_j[1] /
                ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX10 * rtb_sig_x[1]) * (rtb_b_tmp_0 *
      localB->VectorConcatenate[50]) +
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * Gykappa[1] *
      localB->VectorConcatenate[50] * (localP->MagicTireConstInput_QSX14 *
      Dx_tmp_2 + localP->MagicTireConstInput_QSX13);
    cosprimealpha[1] = rtb_ImpAsg_InsertedFor_xdotWhee[1] / cosprimealpha[1];
    Eykappa[1] = ((localP->MagicTireConstInput_QHZ4 * dfz[1] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[1] + 0.0 *
                  dfz[1]) + rtb_Alpha[1];
    SHy[1] = (lam_muy_prime_idx_1 / b_x[1] + SHy[1]) + rtb_Alpha[1];
    Vsy_0 = 0.0 * rtb_sig_x[1] + 1.0;
    rtb_sig_y[1] = Vsy_0;
    rtb_UnaryMinus[1] = ((localP->MagicTireConstInput_QBZ2 * dfz[1] +
                          localP->MagicTireConstInput_QBZ1) + rtb_a_tmp_tmp *
                         localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * Dx_tmp_2 + Vsy_0) + rtb_b_tmp_1 *
       localP->MagicTireConstInput_QBZ6) * localB->VectorConcatenate[32] /
      lam_muy[1];
    rtb_My[2] = std::tanh(10.0 * rtb_ImpAsg_InsertedFor_Omega_at[2]) *
      rtb_Saturation_data[2];
    ec_data = localP->MagicTireConstInput_QSX6 * rtb_VectorConcatenate_j[2] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    rtb_b_tmp_0 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      rtb_VectorConcatenate_j[2];
    Bykappa[2] = rtb_b_tmp_0;
    Dx_tmp_2 = std::abs(rtb_sig_x[2]);
    rtb_VectorConcatenate1[2] = (((((0.0 * localB->VectorConcatenate[78] -
      (localP->MagicTireConstInput_PPMX1 * dpi[2] + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[2])) -
      localP->MagicTireConstInput_QSX12 * rtb_sig_x[2] * Dx_tmp_2) +
      localP->MagicTireConstInput_QSX3 * Gykappa[2] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) + std::sin(std::atan
      (localP->MagicTireConstInput_QSX9 * Gykappa[2] /
       ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[2]) * (std::cos(std::atan(ec_data * ec_data) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
      std::atan(localP->MagicTireConstInput_QSX11 * rtb_VectorConcatenate_j[2] /
                ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX10 * rtb_sig_x[2]) * (rtb_b_tmp_0 *
      localB->VectorConcatenate[77]) +
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * Gykappa[2] *
      localB->VectorConcatenate[77] * (localP->MagicTireConstInput_QSX14 *
      Dx_tmp_2 + localP->MagicTireConstInput_QSX13);
    cosprimealpha[2] = rtb_ImpAsg_InsertedFor_xdotWhee[2] / cosprimealpha[2];
    Eykappa[2] = ((localP->MagicTireConstInput_QHZ4 * dfz[2] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[2] + 0.0 *
                  dfz[2]) + rtb_Alpha[2];
    SHy[2] = (lam_muy_prime_idx_2 / b_x[2] + SHy[2]) + rtb_Alpha[2];
    Vsy_0 = 0.0 * rtb_sig_x[2] + 1.0;
    rtb_sig_y[2] = Vsy_0;
    rtb_UnaryMinus[2] = ((localP->MagicTireConstInput_QBZ2 * dfz[2] +
                          localP->MagicTireConstInput_QBZ1) + lam_Cz_tmp *
                         localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * Dx_tmp_2 + Vsy_0) + Dx_tmp_1 *
       localP->MagicTireConstInput_QBZ6) * localB->VectorConcatenate[59] /
      lam_muy[2];
    rtb_My[3] = std::tanh(10.0 * rtb_ImpAsg_InsertedFor_Omega_at[3]) *
      rtb_Saturation_data[3];
    ec_data = localP->MagicTireConstInput_QSX6 * rtb_VectorConcatenate_j[3] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce;
    rtb_b_tmp_0 = ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      rtb_VectorConcatenate_j[3];
    Dx_tmp_2 = std::abs(rtb_sig_x[3]);
    rtb_VectorConcatenate1[3] = (((((0.0 * localB->VectorConcatenate[105] -
      (localP->MagicTireConstInput_PPMX1 * dpi[3] + 1.0) *
      (localP->MagicTireConstInput_QSX2 * rtb_sig_x[3])) -
      localP->MagicTireConstInput_QSX12 * rtb_sig_x[3] * Dx_tmp_2) +
      localP->MagicTireConstInput_QSX3 * Gykappa[3] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) + std::sin(std::atan
      (localP->MagicTireConstInput_QSX9 * Gykappa[3] /
       ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX8 + localP->MagicTireConstInput_QSX7 *
      rtb_sig_x[3]) * (std::cos(std::atan(ec_data * ec_data) *
      localP->MagicTireConstInput_QSX5) * localP->MagicTireConstInput_QSX4)) +
      std::atan(localP->MagicTireConstInput_QSX11 * rtb_VectorConcatenate_j[3] /
                ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      localP->MagicTireConstInput_QSX10 * rtb_sig_x[3]) * (rtb_b_tmp_0 *
      localB->VectorConcatenate[104]) +
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius * Gykappa[3] *
      localB->VectorConcatenate[104] * (localP->MagicTireConstInput_QSX14 *
      Dx_tmp_2 + localP->MagicTireConstInput_QSX13);
    cosprimealpha[3] = rtb_ImpAsg_InsertedFor_xdotWhee[3] / cosprimealpha[3];
    Eykappa[3] = ((localP->MagicTireConstInput_QHZ4 * dfz[3] +
                   localP->MagicTireConstInput_QHZ3) * rtb_Saturation[3] + 0.0 *
                  dfz[3]) + rtb_Alpha[3];
    SHy[3] = (lam_muy_prime_idx_3 / b_x[3] + SHy[3]) + rtb_Alpha[3];
    Vsy_0 = 0.0 * rtb_sig_x[3] + 1.0;
    rtb_UnaryMinus[3] = ((localP->MagicTireConstInput_QBZ2 * dfz[3] +
                          localP->MagicTireConstInput_QBZ1) + lam_Cz_tmp_0 *
                         localP->MagicTireConstInput_QBZ3) *
      ((localP->MagicTireConstInput_QBZ5 * Dx_tmp_2 + Vsy_0) + Dx_tmp_0 *
       localP->MagicTireConstInput_QBZ6) * localB->VectorConcatenate[86] /
      rtb_Saturation_1;
    for (i = 0; i < 4; i++) {
      if (rtb_UnaryMinus[i] < 0.0) {
        rtb_UnaryMinus[i] = 0.0;
      }
    }

    ec_data = localP->MagicTireConstInput_QCZ1;
    if (localP->MagicTireConstInput_QCZ1 < 0.0) {
      ec_data = 0.0;
    }

    Vsy[0] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[0] * 2.0 /
              3.1415926535897931 * std::atan(rtb_UnaryMinus[0] * ec_data *
               Eykappa[0]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[0]
      + localP->MagicTireConstInput_QEZ1) + Mzphiinf_0 *
      localP->MagicTireConstInput_QEZ3);
    Vsy[1] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[1] * 2.0 /
              3.1415926535897931 * std::atan(ec_data * rtb_UnaryMinus[1] *
               Eykappa[1]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[1]
      + localP->MagicTireConstInput_QEZ1) + rtb_a_tmp_tmp *
      localP->MagicTireConstInput_QEZ3);
    Vsy[2] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[2] * 2.0 /
              3.1415926535897931 * std::atan(ec_data * rtb_UnaryMinus[2] *
               Eykappa[2]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[2]
      + localP->MagicTireConstInput_QEZ1) + lam_Cz_tmp *
      localP->MagicTireConstInput_QEZ3);
    Vsy[3] = (localP->MagicTireConstInput_QEZ5 * rtb_Saturation[3] * 2.0 /
              3.1415926535897931 * std::atan(ec_data * rtb_UnaryMinus[3] *
               Eykappa[3]) + 1.0) * ((localP->MagicTireConstInput_QEZ2 * dfz[3]
      + localP->MagicTireConstInput_QEZ1) + lam_Cz_tmp_0 *
      localP->MagicTireConstInput_QEZ3);
    for (i = 0; i < 4; i++) {
      if (Vsy[i] > 1.0) {
        Vsy[i] = 1.0;
      }
    }

    lam_Cz_0 = std::tan(SHy[0]);
    lam_muy_prime_idx_3 = phi_t[0] / b_x[0];
    Dx_tmp_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (rtb_Kappa[0] *
      rtb_Kappa[0]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0);
    lam_Cz_0 = std::tan(Eykappa[0]);
    rtb_Saturation_data[0] = (localP->MagicTireConstInput_QDZ2 * dfz[0] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi[0]) * (rtb_Divide_ag *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[0]) *
      rtb_VectorConcatenate_j[0] *
      (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius / Fzo_prime_idx_0) *
      localB->VectorConcatenate[16] * zeta[5];
    phi[0] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0)) * std::tanh
      (1000.0 * Eykappa[0]);
    rtb_Saturation_g[0] = ((((localP->MagicTireConstInput_QDZ9 * dfz[0] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi[0] + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[0] +
                       localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[0])) * rtb_Saturation[0] * localB->VectorConcatenate[15] *
      zeta[0] + 0.0 * dfz[0] * localB->VectorConcatenate[17] * zeta[2]) *
      Bykappa[0] * lam_muy[0] * std::tanh(10.0 *
      rtb_ImpAsg_InsertedFor_xdotWhee[0]) * cosprimealpha[0] + zeta[8]) - 1.0;
    rtb_Alpha[0] = zeta[7];
    dc_data[0] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate[5]
                  / lam_muy[0] + localP->MagicTireConstInput_QBZ10 *
                  epsilon_gamma[0] * Mzphiinf[0]) * zeta[6];
    rtb_sig_x[0] = std::tanh(1000.0 * SHy[0]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[1]);
    lam_muy_prime_idx_3 = phi_t[1] / b_x[1];
    Dx_tmp_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (rtb_Kappa[1] *
      rtb_Kappa[1]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0);
    lam_Cz_0 = std::tan(Eykappa[1]);
    rtb_Saturation_data[1] = (localP->MagicTireConstInput_QDZ2 * dfz[1] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi[1]) * (rtb_Saturation_tmp *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[1]) *
      rtb_VectorConcatenate_j[1] *
      (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius / Fzo_prime_idx_1) *
      localB->VectorConcatenate[43] * zeta[14];
    phi[1] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0)) * std::tanh
      (1000.0 * Eykappa[1]);
    rtb_Saturation_g[1] = ((((localP->MagicTireConstInput_QDZ9 * dfz[1] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi[1] + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[1] +
                       localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[1])) * rtb_Saturation[1] * localB->VectorConcatenate[42] *
      zeta[9] + 0.0 * dfz[1] * localB->VectorConcatenate[44] * zeta[11]) *
      Bykappa[1] * lam_muy[1] * std::tanh(10.0 *
      rtb_ImpAsg_InsertedFor_xdotWhee[1]) * cosprimealpha[1] + zeta[17]) - 1.0;
    rtb_Alpha[1] = zeta[16];
    dc_data[1] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate
                  [32] / lam_muy[1] + localP->MagicTireConstInput_QBZ10 *
                  epsilon_gamma[1] * Mzphiinf[1]) * zeta[15];
    rtb_sig_x[1] = std::tanh(1000.0 * SHy[1]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[2]);
    lam_muy_prime_idx_3 = phi_t[2] / b_x[2];
    Dx_tmp_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (rtb_Kappa[2] *
      rtb_Kappa[2]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0);
    lam_Cz_0 = std::tan(Eykappa[2]);
    rtb_Saturation_data[2] = (localP->MagicTireConstInput_QDZ2 * dfz[2] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi[2]) * (rtb_Saturation_tmp_0 *
      localP->MagicTireConstInput_QDZ4 + rtb_sig_y[2]) *
      rtb_VectorConcatenate_j[2] *
      (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius / Fzo_prime_idx_2) *
      localB->VectorConcatenate[70] * zeta[23];
    phi[2] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0)) * std::tanh
      (1000.0 * Eykappa[2]);
    rtb_Saturation_g[2] = ((((localP->MagicTireConstInput_QDZ9 * dfz[2] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi[2] + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[2] +
                       localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[2])) * rtb_Saturation[2] * localB->VectorConcatenate[69] *
      zeta[18] + 0.0 * dfz[2] * localB->VectorConcatenate[71] * zeta[20]) *
      Bykappa[2] * lam_muy[2] * std::tanh(10.0 *
      rtb_ImpAsg_InsertedFor_xdotWhee[2]) * cosprimealpha[2] + zeta[26]) - 1.0;
    rtb_Alpha[2] = zeta[25];
    dc_data[2] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate
                  [59] / lam_muy[2] + localP->MagicTireConstInput_QBZ10 *
                  epsilon_gamma[2] * Mzphiinf[2]) * zeta[24];
    rtb_sig_x[2] = std::tanh(1000.0 * SHy[2]) * std::atan(lam_muy_prime_idx_3);
    lam_Cz_0 = std::tan(SHy[3]);
    lam_muy_prime_idx_3 = Dx_tmp / b_x[3];
    Dx_tmp_0 = lam_muy_prime_idx_3 * lam_muy_prime_idx_3 * (rtb_Kappa[3] *
      rtb_Kappa[3]);
    lam_muy_prime_idx_3 = std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0);
    lam_Cz_0 = std::tan(Eykappa[3]);
    rtb_Saturation_data[3] = (localP->MagicTireConstInput_QDZ2 * dfz[3] +
      localP->MagicTireConstInput_QDZ1) * (1.0 -
      localP->MagicTireConstInput_PPZ1 * dpi[3]) * (rtb_Saturation_tmp_1 *
      localP->MagicTireConstInput_QDZ4 + Vsy_0) * rtb_VectorConcatenate_j[3] *
      (ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius / Fzo_prime_idx_3) *
      localB->VectorConcatenate[97] * zeta[32];
    phi[3] = std::atan(std::sqrt(lam_Cz_0 * lam_Cz_0 + Dx_tmp_0)) * std::tanh
      (1000.0 * Eykappa[3]);
    rtb_Saturation_g[3] = ((((localP->MagicTireConstInput_QDZ9 * dfz[3] +
      localP->MagicTireConstInput_QDZ8) * (localP->MagicTireConstInput_PPZ2 *
      dpi[3] + 1.0) + (localP->MagicTireConstInput_QDZ11 * dfz[3] +
                       localP->MagicTireConstInput_QDZ10) * std::abs
      (rtb_Saturation[3])) * rtb_Saturation[3] * localB->VectorConcatenate[96] *
      zeta[27] + 0.0 * dfz[3] * localB->VectorConcatenate[98] * zeta[29]) *
      rtb_b_tmp_0 * rtb_Saturation_1 * std::tanh(10.0 *
      rtb_ImpAsg_InsertedFor_xdotWhee[3]) * cosprimealpha[3] + zeta[35]) - 1.0;
    rtb_Alpha[3] = zeta[34];
    dc_data[3] = (localP->MagicTireConstInput_QBZ9 * localB->VectorConcatenate
                  [86] / rtb_Saturation_1 + localP->MagicTireConstInput_QBZ10 *
                  epsilon_gamma[3] * Mzphiinf[3]) * zeta[33];
    rtb_sig_x[3] = std::tanh(1000.0 * SHy[3]) * std::atan(lam_muy_prime_idx_3);
    ConfiguredVirtualV_magiccos_odr(rtb_Saturation_data, ec_data, rtb_UnaryMinus,
      Vsy, phi, &rtb_VectorConcatenate1[8]);
    ConfiguredVirtualVe_magiccos_od(rtb_Saturation_g, rtb_Alpha, dc_data,
      rtb_sig_x, rtb_Saturation_data);
    rtb_VectorConcatenate1[8] = ((localP->MagicTireConstInput_SSZ4 * dfz[0] +
      localP->MagicTireConstInput_SSZ3) * rtb_Saturation[0] +
      localP->MagicTireConstInput_SSZ2 * Gykappa[0] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      localB->VectorConcatenate[21] * lam_mux[0] + (-(cosprimealpha[0] *
      rtb_VectorConcatenate1[8] * localB->VectorConcatenate[0]) * (Gykappa[0] -
      rtb_b[0]) + rtb_Saturation_data[0]);
    rtb_VectorConcatenate1[9] = ((localP->MagicTireConstInput_SSZ4 * dfz[1] +
      localP->MagicTireConstInput_SSZ3) * rtb_Saturation[1] +
      localP->MagicTireConstInput_SSZ2 * Gykappa[1] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      localB->VectorConcatenate[48] * lam_mux[1] + (-(cosprimealpha[1] *
      rtb_VectorConcatenate1[9] * localB->VectorConcatenate[27]) * (Gykappa[1] -
      rtb_b[1]) + rtb_Saturation_data[1]);
    rtb_VectorConcatenate1[10] = ((localP->MagicTireConstInput_SSZ4 * dfz[2] +
      localP->MagicTireConstInput_SSZ3) * rtb_Saturation[2] +
      localP->MagicTireConstInput_SSZ2 * Gykappa[2] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      localB->VectorConcatenate[75] * lam_mux[2] + (-(cosprimealpha[2] *
      rtb_VectorConcatenate1[10] * localB->VectorConcatenate[54]) * (Gykappa[2]
      - rtb_b[2]) + rtb_Saturation_data[2]);
    rtb_VectorConcatenate1[11] = ((localP->MagicTireConstInput_SSZ4 * dfz[3] +
      localP->MagicTireConstInput_SSZ3) * rtb_Saturation[3] +
      localP->MagicTireConstInput_SSZ2 * Gykappa[3] /
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce) *
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius *
      localB->VectorConcatenate[102] * lam_mux[3] + (-(cosprimealpha[3] *
      rtb_VectorConcatenate1[11] * localB->VectorConcatenate[81]) * (Gykappa[3]
      - rtb_b_tmp) + rtb_Saturation_data[3]);
    rtb_sig_x[0] = std::abs(phi_t[0] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[0] + 1.0) + Mzphiinf_0 * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi[0] + 1.0)));
    rtb_sig_y[0] = std::abs(dfz_0 / (((localP->MagicTireConstInput_PCFY1 * dfz[0]
      + 1.0) + Mzphiinf_0 * localP->MagicTireConstInput_PCFY2) *
      localP->MagicTireConstInput_LATERAL_STI *
      (localP->MagicTireConstInput_PCFY3 * dpi[0] + 1.0)));
    rtb_sig_x[1] = std::abs(phi_t[1] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[1] + 1.0) + rtb_a_tmp_tmp * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi[1] + 1.0)));
    rtb_sig_y[1] = std::abs(rtb_SOC_CC / (((localP->MagicTireConstInput_PCFY1 *
      dfz[1] + 1.0) + rtb_a_tmp_tmp * localP->MagicTireConstInput_PCFY2) *
      localP->MagicTireConstInput_LATERAL_STI *
      (localP->MagicTireConstInput_PCFY3 * dpi[1] + 1.0)));
    rtb_sig_x[2] = std::abs(phi_t[2] / (((localP->MagicTireConstInput_PCFX1 *
      dfz[2] + 1.0) + lam_Cz_tmp * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi[2] + 1.0)));
    rtb_sig_y[2] = std::abs(rtb_Integrator1_f /
      (((localP->MagicTireConstInput_PCFY1 * dfz[2] + 1.0) + lam_Cz_tmp *
        localP->MagicTireConstInput_PCFY2) *
       localP->MagicTireConstInput_LATERAL_STI *
       (localP->MagicTireConstInput_PCFY3 * dpi[2] + 1.0)));
    rtb_sig_x[3] = std::abs(Dx_tmp / (((localP->MagicTireConstInput_PCFX1 * dfz
      [3] + 1.0) + lam_Cz_tmp_0 * localP->MagicTireConstInput_PCFX2) *
      localP->MagicTireConstInput_LONGITUDINA *
      (localP->MagicTireConstInput_PCFX3 * dpi[3] + 1.0)));
    rtb_sig_y[3] = std::abs(Vsy_tmp / (((localP->MagicTireConstInput_PCFY1 *
      dfz[3] + 1.0) + lam_Cz_tmp_0 * localP->MagicTireConstInput_PCFY2) *
      localP->MagicTireConstInput_LATERAL_STI *
      (localP->MagicTireConstInput_PCFY3 * dpi[3] + 1.0)));
  } else {
    ConfiguredVirtualVe_vdyncsmtire(rtb_ImpAsg_InsertedFor_Omega_at,
      rtb_ImpAsg_InsertedFor_xdotWhee, rtb_ImpAsg_InsertedFor_ydotWhee,
      rtb_UnaryMinus, dpi, rtb_Saturation_g, localB->VectorConcatenate,
      rtb_Saturation, localP->CombinedSlipWheel2DOF_turnslip,
      ConfiguredVirtualVehicleModel_P->PlntWhlMaxPress,
      ConfiguredVirtualVehicleModel_P->PlntWhlMinPress,
      ConfiguredVirtualVehicleModel_P->PlntWhlMaxFz,
      ConfiguredVirtualVehicleModel_P->PlntWhlMinFz,
      ConfiguredVirtualVehicleModel_P->PlntWhlVelTolLowVel,
      ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipRatio,
      ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipRatio,
      ConfiguredVirtualVehicleModel_P->PlntWhlMaxSlipAngle,
      ConfiguredVirtualVehicleModel_P->PlntWhlMinSlipAngle,
      ConfiguredVirtualVehicleModel_P->PlntWhlMinCmbr,
      ConfiguredVirtualVehicleModel_P->PlntWhlMaxCmbr,
      ConfiguredVirtualVehicleModel_P->PlntWhlLongSpd,
      ConfiguredVirtualVehicleModel_P->PlntWhlUnldRadius,
      ConfiguredVirtualVehicleModel_P->PlntWhlRimRadius,
      ConfiguredVirtualVehicleModel_P->PlntWhlNomPress,
      ConfiguredVirtualVehicleModel_P->PlntWhlNomNorlForce,
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
      localP->MagicTireConstInput_vdynMF[278],
      ConfiguredVirtualVehicleModel_P->PlntWhlWidth,
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
      localB->Integrator, localB->Integrator_h, rtb_VectorConcatenate_j,
      localP->vertType_Value, lam_mux, Gykappa, &rtb_VectorConcatenate1[0],
      rtb_My, &rtb_VectorConcatenate1[8], localB->Re, rtb_Kappa, rtb_Alpha,
      rtb_sig_x, rtb_sig_y, rtb_a, rtb_b);
  }

  /* SignalConversion generated from: '<S288>/Vector Concatenate1' */
  rtb_VectorConcatenate1[4] = rtb_Integrator_ks_idx_0;
  rtb_VectorConcatenate1[5] = rtb_Integrator_ks_idx_1;
  rtb_VectorConcatenate1[6] = rtb_Integrator_ks_idx_2;
  rtb_VectorConcatenate1[7] = rtb_Integrator_ks_idx_3;
  for (i = 0; i < 4; i++) {
    /* Math: '<S288>/Math Function1' incorporates:
     *  Concatenate: '<S288>/Vector Concatenate1'
     */
    localB->MathFunction1[3 * i] = rtb_VectorConcatenate1[i];
    localB->MathFunction1[3 * i + 1] = rtb_VectorConcatenate1[i + 4];
    localB->MathFunction1[3 * i + 2] = rtb_VectorConcatenate1[i + 8];
  }

  /* Outputs for Iterator SubSystem: '<S288>/Wheel to Body Transform' incorporates:
   *  ForEach: '<S384>/For Each'
   */
  for (ForEach_itr_p = 0; ForEach_itr_p < 4; ForEach_itr_p++) {
    /* Product: '<S385>/Element Product' incorporates:
     *  Abs: '<S410>/Abs1'
     *  Constant: '<S384>/Constant1'
     *  ForEachSliceSelector generated from: '<S384>/Moments'
     *  ForEachSliceSelector generated from: '<S384>/Re'
     *  Math: '<S288>/Math Function'
     *  SignalConversion generated from: '<S387>/sincos'
     *  Sum: '<S384>/Add'
     */
    tmp[0] = localP->CoreSubsys_dk.Constant1_Value[1];
    tmp[1] = localB->Re[ForEach_itr_p];
    tmp[2] = localP->CoreSubsys_dk.Constant1_Value[0];
    tmp[3] = localB->Re[ForEach_itr_p];
    i = 3 * ForEach_itr_p + 2;
    Vsy_0 = localB->MathFunction[i];
    tmp_0[0] = Vsy_0;
    tmp[4] = localP->CoreSubsys_dk.Constant1_Value[0];
    rtb_Integrator1_f = localB->MathFunction[3 * ForEach_itr_p];
    tmp_0[1] = rtb_Integrator1_f;
    iy = 3 * ForEach_itr_p + 1;
    Vsy_tmp = localB->MathFunction[iy];
    tmp_0[3] = Vsy_tmp;
    tmp[5] = localP->CoreSubsys_dk.Constant1_Value[1];
    tmp_0[2] = Vsy_tmp;
    tmp_0[4] = Vsy_0;
    tmp_0[5] = rtb_Integrator1_f;
    for (ibmat = 0; ibmat < 6; ibmat++) {
      rtb_Abs_j[ibmat] = tmp[ibmat] * tmp_0[ibmat];
    }

    /* End of Product: '<S385>/Element Product' */

    /* Sum: '<S384>/Add' incorporates:
     *  ForEachSliceSelector generated from: '<S384>/Moments'
     *  SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited'
     *  Sum: '<S385>/Sum'
     */
    rtb_IntegratorSecondOrderLimite[0] = (rtb_Abs_j[0] - rtb_Abs_j[3]) +
      localB->MathFunction1[3 * ForEach_itr_p];
    rtb_IntegratorSecondOrderLimite[1] = (rtb_Abs_j[1] - rtb_Abs_j[4]) +
      localB->MathFunction1[iy];
    rtb_IntegratorSecondOrderLimite[2] = (rtb_Abs_j[2] - rtb_Abs_j[5]) +
      localB->MathFunction1[i];
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      for (ibmat = 0; ibmat < 3; ibmat++) {
        /* Math: '<S384>/Transpose1' incorporates:
         *  ForEachSliceSelector generated from: '<S384>/DCM'
         */
        Itemp_tmp = 9 * ForEach_itr_p + ibmat;

        /* Math: '<S384>/Transpose1' incorporates:
         *  Constant: '<S288>/Constant'
         *  ForEachSliceSelector generated from: '<S384>/DCM'
         */
        localB->CoreSubsys_dk[ForEach_itr_p].Transpose1[3 * ibmat] =
          localP->Constant_Value_e[Itemp_tmp];
        localB->CoreSubsys_dk[ForEach_itr_p].Transpose1[3 * ibmat + 1] =
          localP->Constant_Value_e[Itemp_tmp + 3];
        localB->CoreSubsys_dk[ForEach_itr_p].Transpose1[3 * ibmat + 2] =
          localP->Constant_Value_e[Itemp_tmp + 6];
      }
    }

    /* SignalConversion generated from: '<S387>/sincos' incorporates:
     *  Concatenate: '<S377>/Vector Concatenate3'
     *  ForEachSliceSelector generated from: '<S384>/WheelAngles'
     */
    rtb_Switch1_f[0] = localB->VectorConcatenate3[i];
    rtb_Switch1_f[1] = localB->VectorConcatenate3[iy];
    rtb_Switch1_f[2] = localB->VectorConcatenate3[3 * ForEach_itr_p];

    /* Trigonometry: '<S387>/sincos' */
    rtb_Sum_c5[0] = std::cos(rtb_Switch1_f[0]);
    Fzo_prime_idx_2 = std::sin(rtb_Switch1_f[0]);
    rtb_Sum_c5[1] = std::cos(rtb_Switch1_f[1]);
    Fzo_prime_idx_3 = std::sin(rtb_Switch1_f[1]);
    rtb_Sum_c5[2] = std::cos(rtb_Switch1_f[2]);
    rtb_Saturation_1 = std::sin(rtb_Switch1_f[2]);

    /* Fcn: '<S387>/Fcn11' */
    rtb_VectorConcatenate_lq[0] = rtb_Sum_c5[0] * rtb_Sum_c5[1];

    /* Fcn: '<S387>/Fcn21' incorporates:
     *  Fcn: '<S387>/Fcn22'
     *  Trigonometry: '<S387>/sincos'
     */
    Fzo_prime_idx_0 = Fzo_prime_idx_3 * rtb_Saturation_1;
    rtb_VectorConcatenate_lq[1] = Fzo_prime_idx_0 * rtb_Sum_c5[0] -
      Fzo_prime_idx_2 * rtb_Sum_c5[2];

    /* Fcn: '<S387>/Fcn31' incorporates:
     *  Fcn: '<S387>/Fcn32'
     *  Trigonometry: '<S387>/sincos'
     */
    Fzo_prime_idx_1 = Fzo_prime_idx_3 * rtb_Sum_c5[2];
    rtb_VectorConcatenate_lq[2] = Fzo_prime_idx_1 * rtb_Sum_c5[0] +
      Fzo_prime_idx_2 * rtb_Saturation_1;

    /* Fcn: '<S387>/Fcn12' incorporates:
     *  Trigonometry: '<S387>/sincos'
     */
    rtb_VectorConcatenate_lq[3] = Fzo_prime_idx_2 * rtb_Sum_c5[1];

    /* Fcn: '<S387>/Fcn22' incorporates:
     *  Trigonometry: '<S387>/sincos'
     */
    rtb_VectorConcatenate_lq[4] = Fzo_prime_idx_0 * Fzo_prime_idx_2 +
      rtb_Sum_c5[0] * rtb_Sum_c5[2];

    /* Fcn: '<S387>/Fcn32' incorporates:
     *  Trigonometry: '<S387>/sincos'
     */
    rtb_VectorConcatenate_lq[5] = Fzo_prime_idx_1 * Fzo_prime_idx_2 -
      rtb_Sum_c5[0] * rtb_Saturation_1;

    /* Fcn: '<S387>/Fcn13' incorporates:
     *  Trigonometry: '<S387>/sincos'
     */
    rtb_VectorConcatenate_lq[6] = -Fzo_prime_idx_3;

    /* Fcn: '<S387>/Fcn23' incorporates:
     *  Trigonometry: '<S387>/sincos'
     */
    rtb_VectorConcatenate_lq[7] = rtb_Sum_c5[1] * rtb_Saturation_1;

    /* Fcn: '<S387>/Fcn33' */
    rtb_VectorConcatenate_lq[8] = rtb_Sum_c5[1] * rtb_Sum_c5[2];
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Trigonometry: '<S386>/sincos' incorporates:
       *  Constant: '<S384>/Constant'
       *  SignalConversion generated from: '<S386>/sincos'
       */
      rtb_sincos_o1[0] = std::cos(localP->CoreSubsys_dk.Constant_Value[2]);
      Fzo_prime_idx_2 = std::sin(localP->CoreSubsys_dk.Constant_Value[2]);
      rtb_sincos_o1[1] = std::cos(localP->CoreSubsys_dk.Constant_Value[1]);
      Fzo_prime_idx_3 = std::sin(localP->CoreSubsys_dk.Constant_Value[1]);
      rtb_sincos_o1[2] = std::cos(localP->CoreSubsys_dk.Constant_Value[0]);
      rtb_Saturation_1 = std::sin(localP->CoreSubsys_dk.Constant_Value[0]);

      /* Fcn: '<S386>/Fcn11' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[0] = rtb_sincos_o1
        [0] * rtb_sincos_o1[1];

      /* Fcn: '<S386>/Fcn21' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Fcn: '<S386>/Fcn22'
       *  Trigonometry: '<S386>/sincos'
       */
      Fzo_prime_idx_0 = Fzo_prime_idx_3 * rtb_Saturation_1;
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[1] =
        Fzo_prime_idx_0 * rtb_sincos_o1[0] - Fzo_prime_idx_2 * rtb_sincos_o1[2];

      /* Fcn: '<S386>/Fcn31' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Fcn: '<S386>/Fcn32'
       *  Trigonometry: '<S386>/sincos'
       */
      Fzo_prime_idx_1 = Fzo_prime_idx_3 * rtb_sincos_o1[2];
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[2] =
        Fzo_prime_idx_1 * rtb_sincos_o1[0] + Fzo_prime_idx_2 * rtb_Saturation_1;

      /* Fcn: '<S386>/Fcn12' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Trigonometry: '<S386>/sincos'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[3] =
        Fzo_prime_idx_2 * rtb_sincos_o1[1];

      /* Fcn: '<S386>/Fcn22' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Trigonometry: '<S386>/sincos'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[4] =
        Fzo_prime_idx_0 * Fzo_prime_idx_2 + rtb_sincos_o1[0] * rtb_sincos_o1[2];

      /* Fcn: '<S386>/Fcn32' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Trigonometry: '<S386>/sincos'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[5] =
        Fzo_prime_idx_1 * Fzo_prime_idx_2 - rtb_sincos_o1[0] * rtb_Saturation_1;

      /* Fcn: '<S386>/Fcn13' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Trigonometry: '<S386>/sincos'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[6] =
        -Fzo_prime_idx_3;

      /* Fcn: '<S386>/Fcn23' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       *  Trigonometry: '<S386>/sincos'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[7] = rtb_sincos_o1
        [1] * rtb_Saturation_1;

      /* Fcn: '<S386>/Fcn33' incorporates:
       *  Concatenate: '<S388>/Vector Concatenate'
       */
      localB->CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[8] = rtb_sincos_o1
        [1] * rtb_sincos_o1[2];
    }

    /* Product: '<S384>/Divide1' incorporates:
     *  Concatenate: '<S388>/Vector Concatenate'
     *  Math: '<S384>/Transpose'
     */
    for (i = 0; i < 3; i++) {
      /* Math: '<S384>/Transpose' incorporates:
       *  Concatenate: '<S490>/Vector Concatenate'
       */
      rtb_Divide_ag = rtb_VectorConcatenate_lq[3 * i + 1];
      Fzo_prime_idx_0 = rtb_VectorConcatenate_lq[3 * i];
      Fzo_prime_idx_1 = rtb_VectorConcatenate_lq[3 * i + 2];
      for (iy = 0; iy < 3; iy++) {
        rtb_Transpose1[i + 3 * iy] = (localB->CoreSubsys_dk[ForEach_itr_p].
          VectorConcatenate[3 * iy + 1] * rtb_Divide_ag + localB->
          CoreSubsys_dk[ForEach_itr_p].VectorConcatenate[3 * iy] *
          Fzo_prime_idx_0) + localB->CoreSubsys_dk[ForEach_itr_p].
          VectorConcatenate[3 * iy + 2] * Fzo_prime_idx_1;
      }
    }

    for (i = 0; i < 3; i++) {
      /* Product: '<S384>/Divide2' */
      Fzo_prime_idx_0 = 0.0;

      /* Product: '<S384>/Divide3' */
      Fzo_prime_idx_1 = 0.0;
      for (iy = 0; iy < 3; iy++) {
        Vsy_0 = (rtb_Transpose1[3 * iy + 1] * localB->
                 CoreSubsys_dk[ForEach_itr_p].Transpose1[i + 3] +
                 rtb_Transpose1[3 * iy] * localB->CoreSubsys_dk[ForEach_itr_p].
                 Transpose1[i]) + rtb_Transpose1[3 * iy + 2] *
          localB->CoreSubsys_dk[ForEach_itr_p].Transpose1[i + 6];

        /* Product: '<S384>/Divide2' incorporates:
         *  ForEachSliceSelector generated from: '<S384>/Forces'
         *  Math: '<S288>/Math Function'
         *  Math: '<S384>/Transpose1'
         *  Math: '<S395>/Transpose'
         */
        Fzo_prime_idx_0 += localB->MathFunction[3 * ForEach_itr_p + iy] * Vsy_0;

        /* Product: '<S384>/Divide3' incorporates:
         *  SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited'
         */
        Fzo_prime_idx_1 += Vsy_0 * rtb_IntegratorSecondOrderLimite[iy];
      }

      /* Product: '<S384>/Divide3' incorporates:
       *  Math: '<S384>/Transpose1'
       *  Math: '<S395>/Transpose'
       */
      rtb_Switch1_f[i] = Fzo_prime_idx_1;

      /* Product: '<S384>/Divide2' */
      rtb_VectorConcatenate_d[i] = Fzo_prime_idx_0;
    }

    /* End of Product: '<S384>/Divide1' */

    /* ForEachSliceAssignment generated from: '<S384>/Mz' */
    rtb_ImpAsg_InsertedFor_Mz_at_in[ForEach_itr_p] = rtb_Switch1_f[2];

    /* ForEachSliceAssignment generated from: '<S384>/My' */
    rtb_ImpAsg_InsertedFor_My_at_in[ForEach_itr_p] = rtb_Switch1_f[1];

    /* ForEachSliceAssignment generated from: '<S384>/Mx' */
    rtb_ImpAsg_InsertedFor_Mx_at_in[ForEach_itr_p] = rtb_Switch1_f[0];

    /* ForEachSliceAssignment generated from: '<S384>/Fz' */
    rtb_ImpAsg_InsertedFor_Fz_at_in[ForEach_itr_p] = rtb_VectorConcatenate_d[2];

    /* ForEachSliceAssignment generated from: '<S384>/Fy' */
    rtb_ImpAsg_InsertedFor_Fy_at_in[ForEach_itr_p] = rtb_VectorConcatenate_d[1];

    /* ForEachSliceAssignment generated from: '<S384>/Fx' */
    rtb_ImpAsg_InsertedFor_Fx_at_in[ForEach_itr_p] = rtb_VectorConcatenate_d[0];
  }

  /* End of Outputs for SubSystem: '<S288>/Wheel to Body Transform' */

  /* Selector: '<S109>/Selector' */
  rtb_Selector[0] = rtb_ImpAsg_InsertedFor_Fx_at_in[0];

  /* Selector: '<S109>/Selector1' */
  rtb_Selector1_j[0] = rtb_ImpAsg_InsertedFor_Fy_at_in[0];

  /* Selector: '<S109>/Selector2' */
  rtb_Selector2[0] = rtb_ImpAsg_InsertedFor_Fz_at_in[0];

  /* Selector: '<S109>/Selector3' incorporates:
   *  Concatenate: '<S121>/Matrix Concatenate'
   */
  rtb_Selector3[0] = rtb_ImpAsg_InsertedFor_Mz_at_in[0];

  /* Selector: '<S109>/Selector' */
  rtb_Selector[1] = rtb_ImpAsg_InsertedFor_Fx_at_in[1];

  /* Selector: '<S109>/Selector1' */
  rtb_Selector1_j[1] = rtb_ImpAsg_InsertedFor_Fy_at_in[1];

  /* Selector: '<S109>/Selector2' */
  rtb_Selector2[1] = rtb_ImpAsg_InsertedFor_Fz_at_in[1];

  /* Selector: '<S109>/Selector3' incorporates:
   *  Concatenate: '<S121>/Matrix Concatenate'
   */
  rtb_Selector3[1] = rtb_ImpAsg_InsertedFor_Mz_at_in[1];

  /* Concatenate: '<S292>/Matrix Concatenate2' incorporates:
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   *  UnaryMinus: '<S383>/Unary Minus1'
   *  UnaryMinus: '<S383>/Unary Minus2'
   */
  rtb_MatrixConcatenate2[0] = -rtb_Saturation1_idx_0;
  rtb_MatrixConcatenate2[1] = -rtb_Switch_bk_idx_0;
  rtb_MatrixConcatenate2[2] = -rtb_Saturation1_idx_1;
  rtb_MatrixConcatenate2[3] = -rtb_Switch_bk_idx_1;
  rtb_MatrixConcatenate2[4] = -rtb_Saturation1_idx_2;
  rtb_MatrixConcatenate2[5] = -rtb_Switch_bk_idx_2;
  rtb_MatrixConcatenate2[6] = -rtb_SumofElements15;
  rtb_MatrixConcatenate2[7] = -rtb_Switch_bk_idx_3;

  /* Integrator: '<S413>/phi theta psi' */
  localB->phithetapsi[0] = localX->phithetapsi_CSTATE[0];
  localB->phithetapsi[1] = localX->phithetapsi_CSTATE[1];
  localB->phithetapsi[2] = localX->phithetapsi_CSTATE[2];

  /* Outputs for Iterator SubSystem: '<S435>/Unwrap' incorporates:
   *  ForEach: '<S439>/For Each'
   */
  for (ForEach_itr_a = 0; ForEach_itr_a < 3; ForEach_itr_a++) {
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S440>/Memory1' */
      localB->CoreSubsys_n[ForEach_itr_a].Memory1 = localDW->
        CoreSubsys_n[ForEach_itr_a].Memory1_PreviousInput;
    }

    /* RelationalOperator: '<S441>/Compare' incorporates:
     *  Abs: '<S440>/Abs'
     *  Constant: '<S441>/Constant'
     *  ForEachSliceSelector generated from: '<S439>/u'
     *  Sum: '<S440>/Subtract'
     */
    localB->CoreSubsys_n[ForEach_itr_a].Compare = (std::abs(localB->
      phithetapsi[ForEach_itr_a] - localB->CoreSubsys_n[ForEach_itr_a].Memory1) >=
      localP->CoreSubsys_n.CompareToConstant_const);
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Outputs for Triggered SubSystem: '<S440>/Function-Call Subsystem' incorporates:
       *  TriggerPort: '<S442>/function'
       */
      if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)
           ->solverInfo)) {
        if (localB->CoreSubsys_n[ForEach_itr_a].Compare &&
            (localZCE->CoreSubsys_n[ForEach_itr_a].
             FunctionCallSubsystem_Trig_ZCE != POS_ZCSIG)) {
          /* ForEachSliceSelector generated from: '<S439>/u' */
          rtb_Integrator1_f = localB->phithetapsi[ForEach_itr_a];

          /* Signum: '<S442>/Sign' */
          if (std::isnan(rtb_Integrator1_f)) {
            Vsy_0 = (rtNaN);
          } else if (rtb_Integrator1_f < 0.0) {
            Vsy_0 = -1.0;
          } else {
            Vsy_0 = (rtb_Integrator1_f > 0.0);
          }

          /* Sum: '<S442>/Sum' incorporates:
           *  Constant: '<S442>/Constant'
           *  Product: '<S442>/Product'
           *  Signum: '<S442>/Sign'
           *  UnitDelay: '<S442>/Unit Delay'
           */
          localB->CoreSubsys_n[ForEach_itr_a].Sum = localDW->
            CoreSubsys_n[ForEach_itr_a].UnitDelay_DSTATE - Vsy_0 *
            localP->CoreSubsys_n.Constant_Value;

          /* Update for UnitDelay: '<S442>/Unit Delay' */
          localDW->CoreSubsys_n[ForEach_itr_a].UnitDelay_DSTATE =
            localB->CoreSubsys_n[ForEach_itr_a].Sum;
        }

        localZCE->CoreSubsys_n[ForEach_itr_a].FunctionCallSubsystem_Trig_ZCE =
          localB->CoreSubsys_n[ForEach_itr_a].Compare;
      }

      /* End of Outputs for SubSystem: '<S440>/Function-Call Subsystem' */
    }

    /* ForEachSliceAssignment generated from: '<S439>/y' incorporates:
     *  ForEachSliceSelector generated from: '<S439>/u'
     *  Sum: '<S440>/Subtract1'
     */
    rty_VehFdbk[ForEach_itr_a] = localB->CoreSubsys_n[ForEach_itr_a].Sum +
      localB->phithetapsi[ForEach_itr_a];
  }

  /* End of Outputs for SubSystem: '<S435>/Unwrap' */

  /* SignalConversion generated from: '<S458>/sincos' */
  rtb_sincos_o1[0] = rty_VehFdbk[2];
  rtb_sincos_o1[1] = rty_VehFdbk[1];
  rtb_sincos_o1[2] = rty_VehFdbk[0];

  /* Trigonometry: '<S458>/sincos' incorporates:
   *  Trigonometry: '<S475>/sincos'
   */
  lam_muy_prime_idx_1 = std::sin(rtb_sincos_o1[0]);
  rtb_Divide_ag = std::cos(rtb_sincos_o1[0]);
  Fzo_prime_idx_2 = std::sin(rtb_sincos_o1[1]);
  dfz_0 = std::cos(rtb_sincos_o1[1]);
  rtb_SOC_CC = std::sin(rtb_sincos_o1[2]);
  Vsy_0 = std::cos(rtb_sincos_o1[2]);

  /* Fcn: '<S458>/Fcn11' incorporates:
   *  Fcn: '<S475>/Fcn11'
   *  Trigonometry: '<S458>/sincos'
   */
  Fzo_prime_idx_0 = rtb_Divide_ag * dfz_0;
  rtb_VectorConcatenate_lq[0] = Fzo_prime_idx_0;

  /* Fcn: '<S458>/Fcn21' incorporates:
   *  Fcn: '<S458>/Fcn22'
   *  Fcn: '<S475>/Fcn21'
   *  Trigonometry: '<S458>/sincos'
   */
  Fzo_prime_idx_1 = Fzo_prime_idx_2 * rtb_SOC_CC;
  Fzo_prime_idx_3 = Fzo_prime_idx_1 * rtb_Divide_ag - lam_muy_prime_idx_1 *
    Vsy_0;
  rtb_VectorConcatenate_lq[1] = Fzo_prime_idx_3;

  /* Fcn: '<S458>/Fcn31' incorporates:
   *  Fcn: '<S458>/Fcn32'
   *  Fcn: '<S475>/Fcn31'
   *  Trigonometry: '<S458>/sincos'
   */
  rtb_Saturation_1 = Fzo_prime_idx_2 * Vsy_0;
  lam_muy_prime_idx_3 = rtb_Saturation_1 * rtb_Divide_ag + lam_muy_prime_idx_1 *
    rtb_SOC_CC;
  rtb_VectorConcatenate_lq[2] = lam_muy_prime_idx_3;

  /* Fcn: '<S458>/Fcn12' incorporates:
   *  Fcn: '<S475>/Fcn12'
   *  Trigonometry: '<S458>/sincos'
   */
  lam_muy_prime_idx_2 = lam_muy_prime_idx_1 * dfz_0;
  rtb_VectorConcatenate_lq[3] = lam_muy_prime_idx_2;

  /* Fcn: '<S458>/Fcn22' incorporates:
   *  Fcn: '<S475>/Fcn22'
   *  Trigonometry: '<S458>/sincos'
   */
  Fzo_prime_idx_1 = Fzo_prime_idx_1 * lam_muy_prime_idx_1 + rtb_Divide_ag *
    Vsy_0;
  rtb_VectorConcatenate_lq[4] = Fzo_prime_idx_1;

  /* Fcn: '<S458>/Fcn32' incorporates:
   *  Fcn: '<S475>/Fcn32'
   *  Trigonometry: '<S458>/sincos'
   */
  rtb_Saturation_1 = rtb_Saturation_1 * lam_muy_prime_idx_1 - rtb_Divide_ag *
    rtb_SOC_CC;
  rtb_VectorConcatenate_lq[5] = rtb_Saturation_1;

  /* Fcn: '<S458>/Fcn13' incorporates:
   *  Trigonometry: '<S458>/sincos'
   */
  rtb_VectorConcatenate_lq[6] = -Fzo_prime_idx_2;

  /* Fcn: '<S458>/Fcn23' incorporates:
   *  Fcn: '<S475>/Fcn23'
   *  Trigonometry: '<S458>/sincos'
   */
  lam_muy_prime_idx_1 = dfz_0 * rtb_SOC_CC;
  rtb_VectorConcatenate_lq[7] = lam_muy_prime_idx_1;

  /* Fcn: '<S458>/Fcn33' incorporates:
   *  Fcn: '<S475>/Fcn33'
   *  Trigonometry: '<S458>/sincos'
   */
  dfz_0 *= Vsy_0;
  rtb_VectorConcatenate_lq[8] = dfz_0;

  /* Math: '<S457>/Transpose1' incorporates:
   *  Concatenate: '<S490>/Vector Concatenate'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1[3 * i] = rtb_VectorConcatenate_lq[i];
    rtb_Transpose1[3 * i + 1] = rtb_VectorConcatenate_lq[i + 3];
    rtb_Transpose1[3 * i + 2] = rtb_VectorConcatenate_lq[i + 6];
  }

  /* End of Math: '<S457>/Transpose1' */

  /* Product: '<S460>/Product' incorporates:
   *  Selector: '<S451>/Selector1'
   */
  rtb_Divide_ag = localB->Selector1[1];
  rtb_SOC_CC = localB->Selector1[0];
  rtb_Integrator1_f = localB->Selector1[2];
  for (iy = 0; iy < 3; iy++) {
    /* Sum: '<S457>/Add' incorporates:
     *  Integrator: '<S407>/xe,ye,ze'
     *  Math: '<S457>/Transpose1'
     */
    rtb_VectorConcatenate_d[iy] = ((rtb_Transpose1[iy + 3] * rtb_Divide_ag +
      rtb_Transpose1[iy] * rtb_SOC_CC) + rtb_Transpose1[iy + 6] *
      rtb_Integrator1_f) + localX->xeyeze_CSTATE[iy];

    /* Trigonometry: '<S466>/sincos' */
    Vsy_0 = rtb_sincos_o1[iy];
    rtb_V_wb_m[iy] = std::sin(Vsy_0);
    rtb_Product_o0[iy] = std::cos(Vsy_0);
  }

  /* End of Product: '<S460>/Product' */

  /* Fcn: '<S466>/Fcn11' */
  rtb_VectorConcatenate_lq[0] = rtb_Product_o0[0] * rtb_Product_o0[1];

  /* Fcn: '<S466>/Fcn21' incorporates:
   *  Fcn: '<S466>/Fcn22'
   */
  Vsy_0 = rtb_V_wb_m[1] * rtb_V_wb_m[2];
  rtb_VectorConcatenate_lq[1] = Vsy_0 * rtb_Product_o0[0] - rtb_V_wb_m[0] *
    rtb_Product_o0[2];

  /* Fcn: '<S466>/Fcn31' incorporates:
   *  Fcn: '<S466>/Fcn32'
   */
  rtb_Divide_ag = rtb_V_wb_m[1] * rtb_Product_o0[2];
  rtb_VectorConcatenate_lq[2] = rtb_Divide_ag * rtb_Product_o0[0] + rtb_V_wb_m[0]
    * rtb_V_wb_m[2];

  /* Fcn: '<S466>/Fcn12' */
  rtb_VectorConcatenate_lq[3] = rtb_V_wb_m[0] * rtb_Product_o0[1];

  /* Fcn: '<S466>/Fcn22' */
  rtb_VectorConcatenate_lq[4] = Vsy_0 * rtb_V_wb_m[0] + rtb_Product_o0[0] *
    rtb_Product_o0[2];

  /* Fcn: '<S466>/Fcn32' */
  rtb_VectorConcatenate_lq[5] = rtb_Divide_ag * rtb_V_wb_m[0] - rtb_Product_o0[0]
    * rtb_V_wb_m[2];

  /* Fcn: '<S466>/Fcn13' */
  rtb_VectorConcatenate_lq[6] = -rtb_V_wb_m[1];

  /* Fcn: '<S466>/Fcn23' */
  rtb_VectorConcatenate_lq[7] = rtb_Product_o0[1] * rtb_V_wb_m[2];

  /* Fcn: '<S466>/Fcn33' */
  rtb_VectorConcatenate_lq[8] = rtb_Product_o0[1] * rtb_Product_o0[2];
  for (iy = 0; iy < 3; iy++) {
    /* Math: '<S465>/Transpose1' incorporates:
     *  Concatenate: '<S490>/Vector Concatenate'
     */
    rtb_Transpose1_c[3 * iy] = rtb_VectorConcatenate_lq[iy];
    rtb_Transpose1_c[3 * iy + 1] = rtb_VectorConcatenate_lq[iy + 3];
    rtb_Transpose1_c[3 * iy + 2] = rtb_VectorConcatenate_lq[iy + 6];

    /* Trigonometry: '<S494>/sincos' */
    Vsy_0 = rtb_sincos_o1[iy];
    rtb_V_wb_m[iy] = std::sin(Vsy_0);
    rtb_Sum_c5[iy] = std::cos(Vsy_0);
  }

  /* Fcn: '<S494>/Fcn11' */
  rtb_VectorConcatenate_lq[0] = rtb_Sum_c5[0] * rtb_Sum_c5[1];

  /* Fcn: '<S494>/Fcn21' incorporates:
   *  Fcn: '<S494>/Fcn22'
   */
  Vsy_0 = rtb_V_wb_m[1] * rtb_V_wb_m[2];
  rtb_VectorConcatenate_lq[1] = Vsy_0 * rtb_Sum_c5[0] - rtb_V_wb_m[0] *
    rtb_Sum_c5[2];

  /* Fcn: '<S494>/Fcn31' incorporates:
   *  Fcn: '<S494>/Fcn32'
   */
  rtb_Divide_ag = rtb_V_wb_m[1] * rtb_Sum_c5[2];
  rtb_VectorConcatenate_lq[2] = rtb_Divide_ag * rtb_Sum_c5[0] + rtb_V_wb_m[0] *
    rtb_V_wb_m[2];

  /* Fcn: '<S494>/Fcn12' */
  rtb_VectorConcatenate_lq[3] = rtb_V_wb_m[0] * rtb_Sum_c5[1];

  /* Fcn: '<S494>/Fcn22' */
  rtb_VectorConcatenate_lq[4] = Vsy_0 * rtb_V_wb_m[0] + rtb_Sum_c5[0] *
    rtb_Sum_c5[2];

  /* Fcn: '<S494>/Fcn32' */
  rtb_VectorConcatenate_lq[5] = rtb_Divide_ag * rtb_V_wb_m[0] - rtb_Sum_c5[0] *
    rtb_V_wb_m[2];

  /* Fcn: '<S494>/Fcn13' */
  rtb_VectorConcatenate_lq[6] = -rtb_V_wb_m[1];

  /* Fcn: '<S494>/Fcn23' */
  rtb_VectorConcatenate_lq[7] = rtb_Sum_c5[1] * rtb_V_wb_m[2];

  /* Fcn: '<S494>/Fcn33' */
  rtb_VectorConcatenate_lq[8] = rtb_Sum_c5[1] * rtb_Sum_c5[2];
  for (iy = 0; iy < 3; iy++) {
    /* Math: '<S493>/Transpose1' incorporates:
     *  Concatenate: '<S490>/Vector Concatenate'
     */
    rtb_Transpose1_p[3 * iy] = rtb_VectorConcatenate_lq[iy];
    rtb_Transpose1_p[3 * iy + 1] = rtb_VectorConcatenate_lq[iy + 3];
    rtb_Transpose1_p[3 * iy + 2] = rtb_VectorConcatenate_lq[iy + 6];

    /* Trigonometry: '<S502>/sincos' */
    Vsy_0 = rtb_sincos_o1[iy];
    rtb_V_wb_m[iy] = std::sin(Vsy_0);
    rtb_Switch1_f[iy] = std::cos(Vsy_0);
  }

  /* Fcn: '<S502>/Fcn11' */
  rtb_VectorConcatenate_lq[0] = rtb_Switch1_f[0] * rtb_Switch1_f[1];

  /* Fcn: '<S502>/Fcn21' incorporates:
   *  Fcn: '<S502>/Fcn22'
   */
  Vsy_0 = rtb_V_wb_m[1] * rtb_V_wb_m[2];
  rtb_VectorConcatenate_lq[1] = Vsy_0 * rtb_Switch1_f[0] - rtb_V_wb_m[0] *
    rtb_Switch1_f[2];

  /* Fcn: '<S502>/Fcn31' incorporates:
   *  Fcn: '<S502>/Fcn32'
   */
  rtb_Divide_ag = rtb_V_wb_m[1] * rtb_Switch1_f[2];
  rtb_VectorConcatenate_lq[2] = rtb_Divide_ag * rtb_Switch1_f[0] + rtb_V_wb_m[0]
    * rtb_V_wb_m[2];

  /* Fcn: '<S502>/Fcn12' */
  rtb_VectorConcatenate_lq[3] = rtb_V_wb_m[0] * rtb_Switch1_f[1];

  /* Fcn: '<S502>/Fcn22' */
  rtb_VectorConcatenate_lq[4] = Vsy_0 * rtb_V_wb_m[0] + rtb_Switch1_f[0] *
    rtb_Switch1_f[2];

  /* Fcn: '<S502>/Fcn32' */
  rtb_VectorConcatenate_lq[5] = rtb_Divide_ag * rtb_V_wb_m[0] - rtb_Switch1_f[0]
    * rtb_V_wb_m[2];

  /* Fcn: '<S502>/Fcn13' */
  rtb_VectorConcatenate_lq[6] = -rtb_V_wb_m[1];

  /* Fcn: '<S502>/Fcn23' */
  rtb_VectorConcatenate_lq[7] = rtb_Switch1_f[1] * rtb_V_wb_m[2];

  /* Fcn: '<S502>/Fcn33' */
  rtb_VectorConcatenate_lq[8] = rtb_Switch1_f[1] * rtb_Switch1_f[2];

  /* SignalConversion generated from: '<S421>/sincos' */
  rtb_V_wb_m[0] = localB->phithetapsi[2];
  rtb_V_wb_m[1] = localB->phithetapsi[1];
  rtb_V_wb_m[2] = localB->phithetapsi[0];
  for (iy = 0; iy < 3; iy++) {
    /* Math: '<S501>/Transpose1' incorporates:
     *  Concatenate: '<S490>/Vector Concatenate'
     *  Math: '<S395>/Transpose'
     */
    rtb_Transpose[3 * iy] = rtb_VectorConcatenate_lq[iy];
    rtb_Transpose[3 * iy + 1] = rtb_VectorConcatenate_lq[iy + 3];
    rtb_Transpose[3 * iy + 2] = rtb_VectorConcatenate_lq[iy + 6];

    /* Trigonometry: '<S421>/sincos' */
    Vsy_0 = rtb_V_wb_m[iy];
    rtb_IntegratorSecondOrderLimite[iy] = std::cos(Vsy_0);
    rtb_V_wb_m[iy] = std::sin(Vsy_0);
  }

  /* Fcn: '<S421>/Fcn11' */
  rtb_VectorConcatenate_lq[0] = rtb_IntegratorSecondOrderLimite[0] *
    rtb_IntegratorSecondOrderLimite[1];

  /* Fcn: '<S421>/Fcn21' incorporates:
   *  Fcn: '<S421>/Fcn22'
   */
  Vsy_0 = rtb_V_wb_m[1] * rtb_V_wb_m[2];
  rtb_VectorConcatenate_lq[1] = Vsy_0 * rtb_IntegratorSecondOrderLimite[0] -
    rtb_V_wb_m[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S421>/Fcn31' incorporates:
   *  Fcn: '<S421>/Fcn32'
   */
  rtb_Divide_ag = rtb_V_wb_m[1] * rtb_IntegratorSecondOrderLimite[2];
  rtb_VectorConcatenate_lq[2] = rtb_Divide_ag * rtb_IntegratorSecondOrderLimite
    [0] + rtb_V_wb_m[0] * rtb_V_wb_m[2];

  /* Fcn: '<S421>/Fcn12' */
  rtb_VectorConcatenate_lq[3] = rtb_V_wb_m[0] * rtb_IntegratorSecondOrderLimite
    [1];

  /* Fcn: '<S421>/Fcn22' */
  rtb_VectorConcatenate_lq[4] = Vsy_0 * rtb_V_wb_m[0] +
    rtb_IntegratorSecondOrderLimite[0] * rtb_IntegratorSecondOrderLimite[2];

  /* Fcn: '<S421>/Fcn32' */
  rtb_VectorConcatenate_lq[5] = rtb_Divide_ag * rtb_V_wb_m[0] -
    rtb_IntegratorSecondOrderLimite[0] * rtb_V_wb_m[2];

  /* Fcn: '<S421>/Fcn13' */
  rtb_VectorConcatenate_lq[6] = -rtb_V_wb_m[1];

  /* Fcn: '<S421>/Fcn23' */
  rtb_VectorConcatenate_lq[7] = rtb_IntegratorSecondOrderLimite[1] * rtb_V_wb_m
    [2];

  /* Fcn: '<S421>/Fcn33' */
  rtb_VectorConcatenate_lq[8] = rtb_IntegratorSecondOrderLimite[1] *
    rtb_IntegratorSecondOrderLimite[2];

  /* Reshape: '<S423>/Reshape (9) to [3x3] column-major' */
  std::memcpy(&rtb_Reshape9to3x3columnmajor[0], &rtb_VectorConcatenate_lq[0], 9U
              * sizeof(real_T));

  /* Product: '<S420>/Product' incorporates:
   *  Integrator: '<S407>/ub,vb,wb'
   *  Math: '<S407>/Transpose'
   */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  rtb_Integrator1_f = rtb_ubvbwb[1];
  Vsy_tmp = rtb_ubvbwb[0];
  lam_muy_prime_idx_0 = rtb_ubvbwb[2];

  /* Product: '<S468>/Product' incorporates:
   *  Selector: '<S452>/Selector1'
   */
  ec_data = localB->Selector1_f[1];
  rtb_b_tmp = localB->Selector1_f[0];
  rtb_b_tmp_0 = localB->Selector1_f[2];

  /* Product: '<S496>/Product' incorporates:
   *  Selector: '<S455>/Selector1'
   */
  Dx_tmp = localB->Selector1_f2[1];
  Dx_tmp_0 = localB->Selector1_f2[0];
  Dx_tmp_1 = localB->Selector1_f2[2];

  /* Product: '<S504>/Product' incorporates:
   *  Selector: '<S456>/Selector1'
   */
  Dx_tmp_2 = localB->Selector1_n[1];
  rtb_b_tmp_1 = localB->Selector1_n[0];
  rtb_Saturation_tmp = localB->Selector1_n[2];

  /* Product: '<S503>/Product' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S507>/i x j'
   *  Product: '<S508>/j x i'
   *  Sum: '<S400>/Add'
   *  Sum: '<S505>/Sum'
   */
  rtb_Saturation_tmp_0 = rtb_Add_bl[1];
  rtb_Saturation_tmp_1 = rtb_Add_bl[0];
  lam_Cz_0 = localX->pqr_CSTATE[0] * localB->Selector1_n[1] -
    localB->Selector1_n[0] * localX->pqr_CSTATE[1];
  for (i = 0; i < 3; i++) {
    /* Product: '<S420>/Product' incorporates:
     *  Integrator: '<S407>/ub,vb,wb'
     *  Math: '<S407>/Transpose'
     *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
     */
    Mzphiinf_0 = (rtb_VectorConcatenate_lq[3 * i + 1] * rtb_Integrator1_f +
                  rtb_VectorConcatenate_lq[3 * i] * Vsy_tmp) +
      rtb_VectorConcatenate_lq[3 * i + 2] * lam_muy_prime_idx_0;
    localB->Product_k[i] = Mzphiinf_0;

    /* Reshape: '<S295>/Reshape' */
    rtb_VectorConcatenate8[i] = rtb_VectorConcatenate_d[i];

    /* Integrator: '<S407>/xe,ye,ze' */
    rtb_a_tmp_tmp = localX->xeyeze_CSTATE[i];

    /* Product: '<S468>/Product' incorporates:
     *  Math: '<S465>/Transpose1'
     */
    lam_Cz_tmp = rtb_Transpose1_c[i + 3];
    lam_Cz_tmp_0 = rtb_Transpose1_c[i];
    x_idx_0 = rtb_Transpose1_c[i + 6];

    /* Reshape: '<S295>/Reshape' incorporates:
     *  Integrator: '<S407>/xe,ye,ze'
     *  Product: '<S468>/Product'
     *  Selector: '<S452>/Selector1'
     *  Sum: '<S465>/Add'
     */
    rtb_VectorConcatenate8[i + 3] = ((lam_Cz_tmp * ec_data + lam_Cz_tmp_0 *
      rtb_b_tmp) + x_idx_0 * rtb_b_tmp_0) + rtb_a_tmp_tmp;

    /* Product: '<S496>/Product' incorporates:
     *  Math: '<S493>/Transpose1'
     */
    ab_idx_0 = rtb_Transpose1_p[i + 3];
    rtb_Transpose1_h = rtb_Transpose1_p[i];
    rtb_Transpose1_h_0 = rtb_Transpose1_p[i + 6];

    /* Reshape: '<S295>/Reshape' incorporates:
     *  Integrator: '<S407>/xe,ye,ze'
     *  Product: '<S496>/Product'
     *  Selector: '<S455>/Selector1'
     *  Sum: '<S493>/Add'
     */
    rtb_VectorConcatenate8[i + 6] = ((ab_idx_0 * Dx_tmp + rtb_Transpose1_h *
      Dx_tmp_0) + rtb_Transpose1_h_0 * Dx_tmp_1) + rtb_a_tmp_tmp;

    /* Product: '<S504>/Product' incorporates:
     *  Math: '<S395>/Transpose'
     */
    Vsy_0 = rtb_Transpose[i + 3];
    rtb_Divide_ag = rtb_Transpose[i];
    rtb_SOC_CC = rtb_Transpose[i + 6];

    /* Reshape: '<S295>/Reshape' incorporates:
     *  Integrator: '<S407>/xe,ye,ze'
     *  Product: '<S504>/Product'
     *  Selector: '<S456>/Selector1'
     *  Sum: '<S501>/Add'
     */
    rtb_VectorConcatenate8[i + 9] = ((Vsy_0 * Dx_tmp_2 + rtb_Divide_ag *
      rtb_b_tmp_1) + rtb_SOC_CC * rtb_Saturation_tmp) + rtb_a_tmp_tmp;

    /* Reshape: '<S295>/Reshape1' incorporates:
     *  Math: '<S457>/Transpose1'
     *  Product: '<S434>/Product3'
     *  Product: '<S459>/Product'
     *  Product: '<S467>/Product'
     *  Product: '<S495>/Product'
     *  Product: '<S503>/Product'
     *  Sum: '<S400>/Add'
     *  Sum: '<S457>/Add4'
     *  Sum: '<S465>/Add4'
     *  Sum: '<S493>/Add4'
     *  Sum: '<S501>/Add4'
     *  UnaryMinus: '<S400>/Unary Minus'
     *  UnitConversion: '<S418>/Unit Conversion'
     */
    rtb_VectorConcatenate1[i] = ((rtb_Transpose1[i + 3] * rtb_UnaryMinus2_idx_1
      + rtb_Transpose1[i] * rtb_Product1_o_idx_3) + rtb_Transpose1[i + 6] *
      rtb_V_wb_d_idx_2) + Mzphiinf_0;
    rtb_VectorConcatenate1[i + 3] = ((lam_Cz_tmp * rtb_UnaryMinus_c_idx_1 +
      lam_Cz_tmp_0 * rtb_UnaryMinus_c_idx_0) + x_idx_0 * rtb_UnaryMinus_c_idx_2)
      + Mzphiinf_0;
    rtb_VectorConcatenate1[i + 6] = ((ab_idx_0 * rtb_Product1_o_idx_1 +
      rtb_Transpose1_h * rtb_Product_pm) + rtb_Transpose1_h_0 * rtb_DeadZone1) +
      Mzphiinf_0;
    rtb_VectorConcatenate1[i + 9] = ((Vsy_0 * rtb_Saturation_tmp_0 +
      rtb_Divide_ag * rtb_Saturation_tmp_1) + rtb_SOC_CC * lam_Cz_0) +
      Mzphiinf_0;
  }

  /* Concatenate: '<S292>/Matrix Concatenate3' incorporates:
   *  Constant: '<S295>/Inertial Frame CG to Axle Offset'
   *  Selector: '<S292>/Selector'
   *  Selector: '<S292>/Selector1'
   *  Sum: '<S295>/Sum'
   */
  rtb_MatrixConcatenate3[0] = rtb_VectorConcatenate8[2] -
    localP->InertialFrameCGtoAxleOffset_Val[2];
  rtb_MatrixConcatenate3[1] = rtb_VectorConcatenate1[2];
  rtb_MatrixConcatenate3[2] = rtb_VectorConcatenate8[5] -
    localP->InertialFrameCGtoAxleOffset_Val[5];
  rtb_MatrixConcatenate3[3] = rtb_VectorConcatenate1[5];
  rtb_MatrixConcatenate3[4] = rtb_VectorConcatenate8[8] -
    localP->InertialFrameCGtoAxleOffset_Val[8];
  rtb_MatrixConcatenate3[5] = rtb_VectorConcatenate1[8];
  rtb_MatrixConcatenate3[6] = rtb_VectorConcatenate8[11] -
    localP->InertialFrameCGtoAxleOffset_Val[11];
  rtb_MatrixConcatenate3[7] = rtb_VectorConcatenate1[11];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S174>/Add' incorporates:
     *  Constant: '<S174>/Constant'
     *  Constant: '<S174>/Constant1'
     */
    rtb_Product2_lv = ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] / 2.0
      - ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

    /* Product: '<S174>/Divide' incorporates:
     *  Constant: '<S174>/Constant3'
     */
    rtb_Divide_ag = localP->RackandPinforDynStr_d / rtb_Product2_lv;

    /* Sum: '<S174>/Add1' incorporates:
     *  Constant: '<S174>/Constant2'
     *  Math: '<S174>/Math Function'
     *  Math: '<S174>/Math Function1'
     */
    rtb_Product2_lv = rtb_Product2_lv * rtb_Product2_lv +
      localP->RackandPinforDynStr_d * localP->RackandPinforDynStr_d;

    /* Sum: '<S174>/Add2' incorporates:
     *  Constant: '<S174>/Constant4'
     *  Constant: '<S174>/Constant5'
     *  Math: '<S174>/Math Function2'
     *  Math: '<S174>/Math Function3'
     */
    rtb_UnaryMinus2_idx_1 =
      (ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
       ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth + rtb_Product2_lv)
      - ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;

    /* Sqrt: '<S174>/Sqrt' */
    rtb_Product2_lv = std::sqrt(rtb_Product2_lv);

    /* Product: '<S174>/Divide1' incorporates:
     *  Constant: '<S174>/Constant6'
     *  Constant: '<S174>/Constant7'
     */
    rtb_Product1_o_idx_3 = rtb_UnaryMinus2_idx_1 / localP->Constant6_Value /
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / rtb_Product2_lv;

    /* Trigonometry: '<S174>/Trigonometric Function1' */
    if (rtb_Product1_o_idx_3 > 1.0) {
      rtb_Product1_o_idx_3 = 1.0;
    } else if (rtb_Product1_o_idx_3 < -1.0) {
      rtb_Product1_o_idx_3 = -1.0;
    }

    /* Sum: '<S174>/Add3' incorporates:
     *  Constant: '<S174>/Constant8'
     *  Trigonometry: '<S174>/Trigonometric Function'
     *  Trigonometry: '<S174>/Trigonometric Function1'
     */
    localB->Add3 = (localP->Constant8_Value - std::atan(rtb_Divide_ag)) - std::
      acos(rtb_Product1_o_idx_3);

    /* Product: '<S158>/Divide' incorporates:
     *  Constant: '<S109>/RckGnConstant'
     *  Constant: '<S158>/Constant'
     */
    localB->Divide_e = ConfiguredVirtualVehicleModel_P->PlntSteerRckGn /
      localP->Constant_Value_b;

    /* UnaryMinus: '<S169>/Unary Minus1' */
    localB->UnaryMinus1 = -localB->Divide_e;
  }

  /* SecondOrderIntegrator: '<S158>/Integrator, Second-Order' */
  rtb_SOC_CC = localX->IntegratorSecondOrder_CSTATE_e[0];

  /* Sum: '<S172>/Add' incorporates:
   *  Constant: '<S172>/Constant'
   *  Constant: '<S172>/Constant1'
   *  Product: '<S169>/Product'
   */
  rtb_Product_pm = (ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] / 2.0 -
                    localB->UnaryMinus1 * rtb_SOC_CC) -
    ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S172>/Trigonometric Function' incorporates:
   *  Constant: '<S172>/Constant3'
   *  Product: '<S172>/Divide'
   */
  rtb_Divide_ag = std::atan(localP->RackandPinforDynStr_d / rtb_Product_pm);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S172>/Math Function1' incorporates:
     *  Constant: '<S172>/Constant2'
     */
    localB->MathFunction1_e = localP->RackandPinforDynStr_d *
      localP->RackandPinforDynStr_d;

    /* Math: '<S172>/Math Function2' incorporates:
     *  Constant: '<S172>/Constant4'
     */
    localB->MathFunction2 =
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth;

    /* Math: '<S172>/Math Function3' incorporates:
     *  Constant: '<S172>/Constant5'
     */
    localB->MathFunction3 =
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S172>/Add1' incorporates:
   *  Math: '<S172>/Math Function'
   */
  rtb_Product_pm = rtb_Product_pm * rtb_Product_pm + localB->MathFunction1_e;

  /* Product: '<S172>/Divide1' incorporates:
   *  Constant: '<S172>/Constant6'
   *  Constant: '<S172>/Constant7'
   *  Sqrt: '<S172>/Sqrt'
   *  Sum: '<S172>/Add2'
   */
  rtb_Product1_o_idx_3 = ((rtb_Product_pm + localB->MathFunction2) -
    localB->MathFunction3) / localP->Constant6_Value_i /
    ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / std::sqrt
    (rtb_Product_pm);

  /* Trigonometry: '<S172>/Trigonometric Function1' */
  if (rtb_Product1_o_idx_3 > 1.0) {
    rtb_Product1_o_idx_3 = 1.0;
  } else if (rtb_Product1_o_idx_3 < -1.0) {
    rtb_Product1_o_idx_3 = -1.0;
  }

  /* Sum: '<S169>/Add' incorporates:
   *  Constant: '<S172>/Constant8'
   *  Sum: '<S172>/Add3'
   *  Trigonometry: '<S172>/Trigonometric Function1'
   */
  rtb_Product_pm = ((localP->Constant8_Value_o - rtb_Divide_ag) - std::acos
                    (rtb_Product1_o_idx_3)) - localB->Add3;

  /* Sum: '<S173>/Add' incorporates:
   *  Constant: '<S173>/Constant'
   *  Constant: '<S173>/Constant1'
   *  Product: '<S169>/Product3'
   */
  rtb_UnaryMinus_c_idx_0 = (ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] /
    2.0 - localB->Divide_e * rtb_SOC_CC) -
    ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S173>/Trigonometric Function' incorporates:
   *  Constant: '<S173>/Constant3'
   *  Product: '<S173>/Divide'
   */
  rtb_Divide_ag = std::atan(localP->RackandPinforDynStr_d /
    rtb_UnaryMinus_c_idx_0);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S173>/Math Function1' incorporates:
     *  Constant: '<S173>/Constant2'
     */
    localB->MathFunction1_o = localP->RackandPinforDynStr_d *
      localP->RackandPinforDynStr_d;

    /* Math: '<S173>/Math Function2' incorporates:
     *  Constant: '<S173>/Constant4'
     */
    localB->MathFunction2_l =
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth;

    /* Math: '<S173>/Math Function3' incorporates:
     *  Constant: '<S173>/Constant5'
     */
    localB->MathFunction3_j =
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S173>/Add1' incorporates:
   *  Math: '<S173>/Math Function'
   */
  rtb_UnaryMinus_c_idx_0 = rtb_UnaryMinus_c_idx_0 * rtb_UnaryMinus_c_idx_0 +
    localB->MathFunction1_o;

  /* Product: '<S173>/Divide1' incorporates:
   *  Constant: '<S173>/Constant6'
   *  Constant: '<S173>/Constant7'
   *  Sqrt: '<S173>/Sqrt'
   *  Sum: '<S173>/Add2'
   */
  rtb_Product1_o_idx_3 = ((rtb_UnaryMinus_c_idx_0 + localB->MathFunction2_l) -
    localB->MathFunction3_j) / localP->Constant6_Value_f /
    ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / std::sqrt
    (rtb_UnaryMinus_c_idx_0);

  /* Trigonometry: '<S173>/Trigonometric Function1' */
  if (rtb_Product1_o_idx_3 > 1.0) {
    rtb_Product1_o_idx_3 = 1.0;
  } else if (rtb_Product1_o_idx_3 < -1.0) {
    rtb_Product1_o_idx_3 = -1.0;
  }

  /* Sum: '<S169>/Add1' incorporates:
   *  Constant: '<S173>/Constant8'
   *  Sum: '<S173>/Add3'
   *  Trigonometry: '<S173>/Trigonometric Function1'
   */
  rtb_UnaryMinus_c_idx_0 = localB->Add3 - ((localP->Constant8_Value_a -
    rtb_Divide_ag) - std::acos(rtb_Product1_o_idx_3));

  /* Switch: '<S158>/Switch' */
  if (rtb_SOC_CC > localP->Switch_Threshold_p) {
    rtb_Product1_o_idx_3 = rtb_UnaryMinus_c_idx_0;
    rtb_UnaryMinus2_idx_1 = rtb_Product_pm;
  } else {
    rtb_Product1_o_idx_3 = rtb_Product_pm;
    rtb_UnaryMinus2_idx_1 = rtb_UnaryMinus_c_idx_0;
  }

  /* End of Switch: '<S158>/Switch' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S158>/Gain5' incorporates:
     *  Constant: '<S109>/PctAckConstant'
     */
    localB->Gain5 = localP->Gain5_Gain *
      ConfiguredVirtualVehicleModel_P->PlntSteerPctAck;

    /* Sum: '<S158>/Add1' incorporates:
     *  Constant: '<S158>/Constant1'
     */
    localB->Add1_a = localP->Constant1_Value_b - localB->Gain5;
  }

  /* Switch: '<S158>/Switch1' incorporates:
   *  Product: '<S158>/Product1'
   *  Product: '<S158>/Product2'
   *  Sum: '<S158>/Sum'
   */
  if (rtb_SOC_CC > localP->Switch1_Threshold_h) {
    rtb_UnaryMinus1_b[0] = rtb_Product1_o_idx_3 * localB->Add1_a +
      rtb_UnaryMinus2_idx_1 * localB->Gain5;
    rtb_UnaryMinus1_b[1] = rtb_Product1_o_idx_3;
  } else {
    rtb_UnaryMinus1_b[0] = rtb_Product1_o_idx_3;
    rtb_UnaryMinus1_b[1] = rtb_Product1_o_idx_3 * localB->Add1_a +
      rtb_UnaryMinus2_idx_1 * localB->Gain5;
  }

  /* End of Switch: '<S158>/Switch1' */

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S109>/LocFlagConstant'
   *  Constant: '<S158>/AckermanFlagConstant'
   *  Switch: '<S158>/Switch4'
   */
  if (localP->LocFlagConstant_Value > localP->Switch_Threshold_ik) {
    /* Switch: '<S158>/Switch4' incorporates:
     *  Constant: '<S158>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value > localP->Switch4_Threshold) {
      /* Switch: '<S111>/Switch' */
      localB->Switch = rtb_Product_pm;
    } else {
      /* Switch: '<S111>/Switch' */
      localB->Switch = rtb_UnaryMinus1_b[0];
    }
  } else if (localP->AckermanFlagConstant_Value > localP->Switch4_Threshold) {
    /* Switch: '<S158>/Switch4' incorporates:
     *  Switch: '<S111>/Switch'
     *  UnaryMinus: '<S111>/Unary Minus1'
     */
    localB->Switch = -rtb_Product_pm;
  } else {
    /* Switch: '<S111>/Switch' incorporates:
     *  Switch: '<S158>/Switch4'
     *  UnaryMinus: '<S111>/Unary Minus1'
     */
    localB->Switch = -rtb_UnaryMinus1_b[0];
  }

  /* End of Switch: '<S111>/Switch' */

  /* Switch: '<S111>/Switch1' incorporates:
   *  Constant: '<S109>/LocFlagConstant'
   *  Constant: '<S158>/AckermanFlagConstant'
   *  Switch: '<S158>/Switch5'
   */
  if (localP->LocFlagConstant_Value > localP->Switch1_Threshold_p) {
    /* Switch: '<S158>/Switch5' incorporates:
     *  Constant: '<S158>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value > localP->Switch5_Threshold) {
      /* Switch: '<S111>/Switch1' */
      localB->Switch1 = rtb_UnaryMinus_c_idx_0;
    } else {
      /* Switch: '<S111>/Switch1' */
      localB->Switch1 = rtb_UnaryMinus1_b[1];
    }
  } else if (localP->AckermanFlagConstant_Value > localP->Switch5_Threshold) {
    /* Switch: '<S158>/Switch5' incorporates:
     *  Switch: '<S111>/Switch1'
     *  UnaryMinus: '<S111>/Unary Minus'
     */
    localB->Switch1 = -rtb_UnaryMinus_c_idx_0;
  } else {
    /* Switch: '<S111>/Switch1' incorporates:
     *  Switch: '<S158>/Switch5'
     *  UnaryMinus: '<S111>/Unary Minus'
     */
    localB->Switch1 = -rtb_UnaryMinus1_b[1];
  }

  /* End of Switch: '<S111>/Switch1' */

  /* Concatenate: '<S296>/Matrix Concatenate' incorporates:
   *  ForEachSliceAssignment generated from: '<S384>/Mx'
   */
  rtb_VectorConcatenate1[0] = rtb_ImpAsg_InsertedFor_Mx_at_in[0];
  rtb_VectorConcatenate1[1] = rtb_ImpAsg_InsertedFor_My_at_in[0];
  rtb_VectorConcatenate1[2] = rtb_ImpAsg_InsertedFor_Mz_at_in[0];
  rtb_VectorConcatenate1[3] = rtb_ImpAsg_InsertedFor_Mx_at_in[1];
  rtb_VectorConcatenate1[4] = rtb_ImpAsg_InsertedFor_My_at_in[1];
  rtb_VectorConcatenate1[5] = rtb_ImpAsg_InsertedFor_Mz_at_in[1];
  rtb_VectorConcatenate1[6] = rtb_ImpAsg_InsertedFor_Mx_at_in[2];
  rtb_VectorConcatenate1[7] = rtb_ImpAsg_InsertedFor_My_at_in[2];
  rtb_VectorConcatenate1[8] = rtb_ImpAsg_InsertedFor_Mz_at_in[2];
  rtb_VectorConcatenate1[9] = rtb_ImpAsg_InsertedFor_Mx_at_in[3];
  rtb_VectorConcatenate1[10] = rtb_ImpAsg_InsertedFor_My_at_in[3];
  rtb_VectorConcatenate1[11] = rtb_ImpAsg_InsertedFor_Mz_at_in[3];

  /* Trigonometry: '<S292>/Small angle approximation for downstream multiplications' */
  rtb_Product1_o_idx_3 = std::tan(rty_VehFdbk[0]);

  /* Gain: '<S289>/Gain' incorporates:
   *  Integrator: '<S291>/Integrator1'
   */
  rtb_Integrator1_f = localP->Gain_Gain_dp * localX->Integrator1_CSTATE_nd[0];
  rtb_Product_pm = localP->Gain_Gain_dp * localX->Integrator1_CSTATE_nd[1];
  rtb_DeadZone1 = localP->Gain_Gain_dp * localX->Integrator1_CSTATE_nd[2];
  rtb_Product1_o_idx_1 = localP->Gain_Gain_dp * localX->Integrator1_CSTATE_nd[3];

  /* Signum: '<S289>/Sign' */
  if (std::isnan(rtb_Integrator1_f)) {
    Vsy_0 = (rtNaN);
  } else if (rtb_Integrator1_f < 0.0) {
    Vsy_0 = -1.0;
  } else {
    Vsy_0 = (rtb_Integrator1_f > 0.0);
  }

  if (std::isnan(rtb_Product_pm)) {
    rtb_Integrator1_f = (rtNaN);
  } else if (rtb_Product_pm < 0.0) {
    rtb_Integrator1_f = -1.0;
  } else {
    rtb_Integrator1_f = (rtb_Product_pm > 0.0);
  }

  /* Sum: '<S297>/Add' incorporates:
   *  Abs: '<S297>/Abs'
   *  Abs: '<S297>/Abs1'
   *  Constant: '<S297>/Front Track'
   *  Integrator: '<S290>/Integrator1'
   *  Product: '<S297>/Product'
   *  Product: '<S297>/Product1'
   *  Signum: '<S289>/Sign'
   */
  rtb_UnaryMinus1_b[0] = (std::abs(localX->Integrator1_CSTATE_d[0]) * Vsy_0 +
    localP->FrontTrack_Value) + std::abs(localX->Integrator1_CSTATE_d[1]) *
    rtb_Integrator1_f;

  /* Signum: '<S289>/Sign' */
  if (std::isnan(rtb_DeadZone1)) {
    Vsy_0 = (rtNaN);
  } else if (rtb_DeadZone1 < 0.0) {
    Vsy_0 = -1.0;
  } else {
    Vsy_0 = (rtb_DeadZone1 > 0.0);
  }

  if (std::isnan(rtb_Product1_o_idx_1)) {
    rtb_Integrator1_f = (rtNaN);
  } else if (rtb_Product1_o_idx_1 < 0.0) {
    rtb_Integrator1_f = -1.0;
  } else {
    rtb_Integrator1_f = (rtb_Product1_o_idx_1 > 0.0);
  }

  /* Sum: '<S298>/Add1' incorporates:
   *  Abs: '<S298>/Abs2'
   *  Abs: '<S298>/Abs3'
   *  Constant: '<S298>/Rear Track'
   *  Integrator: '<S290>/Integrator1'
   *  Product: '<S298>/Product2'
   *  Product: '<S298>/Product3'
   *  Signum: '<S289>/Sign'
   */
  rtb_UnaryMinus1_b[1] = (std::abs(localX->Integrator1_CSTATE_d[2]) * Vsy_0 +
    localP->RearTrack_Value) + std::abs(localX->Integrator1_CSTATE_d[3]) *
    rtb_Integrator1_f;

  /* Outputs for Iterator SubSystem: '<S292>/For each track and axle combination calculate suspension forces and moments' incorporates:
   *  ForEach: '<S300>/For Each'
   */
  for (ForEach_itr_jh = 0; ForEach_itr_jh < 4; ForEach_itr_jh++) {
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S302>/Sum2' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S292>/Wheel Number'
       *  Constant: '<S302>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  ForEachSliceSelector generated from: '<S300>/Wheel Number'
       *  Selector: '<S302>/Selector1'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      localB->CoreSubsys[ForEach_itr_jh].Sum2 =
        localP->CoreSubsys.VehicleVehicleWheelOffset3_Valu[static_cast<int32_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1] +
        localP->IndependentKandCSuspension_WhlN[ForEach_itr_jh];

      /* Selector: '<S309>/Selector5' incorporates:
       *  Constant: '<S309>/Constant4'
       *  UnitConversion: '<S309>/Unit Conversion'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector5 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCStatCamber[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1] * 0.017453292519943295;

      /* Selector: '<S322>/Selector2' incorporates:
       *  Constant: '<S322>/Constant5'
       *  Selector: '<S309>/Selector5'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector2 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCBumpCamber[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Selector: '<S302>/Selector' incorporates:
     *  Selector: '<S302>/Selector2'
     *  Sum: '<S359>/Add'
     */
    i = (static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1) << 1;

    /* Sum: '<S359>/Add' incorporates:
     *  Concatenate: '<S292>/Matrix Concatenate2'
     *  Concatenate: '<S292>/Matrix Concatenate3'
     *  Selector: '<S302>/Selector'
     *  Selector: '<S302>/Selector2'
     */
    rtb_Divide_ag = rtb_MatrixConcatenate3[i] - rtb_MatrixConcatenate2[i];

    /* Gain: '<S360>/Height Sign Convention' */
    rtb_UnaryMinus2_idx_1 = localP->CoreSubsys.HeightSignConvention_Gain *
      rtb_Divide_ag;

    /* Gain: '<S307>/Sign Convention' */
    rtb_DeadZone1 = localP->CoreSubsys.SignConvention_Gain *
      rtb_UnaryMinus2_idx_1;

    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S327>/Sum of Elements' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S326>/Constant3'
       *  Constant: '<S327>/Axle Numbers'
       *  DataTypeConversion: '<S327>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  Product: '<S327>/Product'
       *  RelationalOperator: '<S327>/Relational Operator'
       *  Selector: '<S326>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_jh].SumofElements =
        ConfiguredVirtualVehicleModel_P->PlntSpKCCambVsSteerAng
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1] *
        static_cast<real_T>(localP->
                            IndependentKandCSuspension_Axle[ForEach_itr_jh] ==
                            localP->CoreSubsys.SelectSteerCamberSlope_AxleNums);

      /* Selector: '<S303>/Selector5' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  Selector: '<S347>/Selector1'
       */
      i = static_cast<int32_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1;

      /* Product: '<S303>/Product' incorporates:
       *  Constant: '<S303>/Vehicle Vehicle Wheel Offset1'
       *  Selector: '<S303>/Selector5'
       */
      localB->CoreSubsys[ForEach_itr_jh].Product =
        localP->CoreSubsys.VehicleVehicleWheelOffset1_Valu[i] *
        localB->CoreSubsys[ForEach_itr_jh].Sum2;

      /* Sum: '<S347>/Sum1' incorporates:
       *  Constant: '<S292>/Wheel Number'
       *  Constant: '<S347>/Constant'
       *  Constant: '<S347>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S300>/Wheel Number'
       *  Gain: '<S347>/Gain'
       *  Selector: '<S347>/Selector1'
       *  Sum: '<S347>/Sum'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      rtb_Integrator1_f = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_i[i]
                           + localP->CoreSubsys.Constant_Value_f) *
        localP->CoreSubsys.Gain_Gain - localP->
        IndependentKandCSuspension_WhlN[ForEach_itr_jh];

      /* Signum: '<S347>/Sign' */
      if (std::isnan(rtb_Integrator1_f)) {
        Vsy_0 = (rtNaN);
      } else if (rtb_Integrator1_f < 0.0) {
        Vsy_0 = -1.0;
      } else {
        Vsy_0 = (rtb_Integrator1_f > 0.0);
      }

      /* Product: '<S347>/Product' incorporates:
       *  Constant: '<S314>/Constant1'
       *  Selector: '<S326>/Selector1'
       *  Selector: '<S347>/Selector5'
       *  Signum: '<S347>/Sign'
       *  UnitConversion: '<S314>/Unit Conversion'
       */
      rtb_Product_pm = ConfiguredVirtualVehicleModel_P->PlntSpKCStatToe[
        static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1] *
        0.017453292519943295 * Vsy_0;

      /* Sum: '<S353>/Sum of Elements' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S353>/Axle Numbers'
       *  DataTypeConversion: '<S353>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  Product: '<S353>/Product'
       *  RelationalOperator: '<S353>/Relational Operator'
       */
      localB->CoreSubsys[ForEach_itr_jh].SumofElements_j = static_cast<real_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_jh] ==
         localP->CoreSubsys.SelectStaticToeSetting_AxleNums[0]) * rtb_Product_pm
        + static_cast<real_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_jh] ==
        localP->CoreSubsys.SelectStaticToeSetting_AxleNums[1]) * rtb_Product_pm;

      /* Selector: '<S355>/Selector5' incorporates:
       *  Constant: '<S355>/Constant'
       *  Selector: '<S326>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector5_j =
        ConfiguredVirtualVehicleModel_P->PlntSpKCBumpSteer[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Selector: '<S354>/Selector10' incorporates:
       *  Constant: '<S354>/Constant12'
       *  Selector: '<S326>/Selector1'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector10 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCAlgnTrqSteerCompl
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N*m to: kN*m
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S356>/Selector2' incorporates:
       *  Constant: '<S356>/Constant2'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector2_c =
        ConfiguredVirtualVehicleModel_P->PlntSpKCLatSteerCompl
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* SignalConversion generated from: '<S303>/Selector3' incorporates:
     *  Constant: '<S303>/Constant'
     *  Reshape: '<S294>/Reshape1'
     */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Add_bl[0] = localP->CoreSubsys.Constant_Value;
    rtb_Add_bl[1] = localB->Switch;
    rtb_Add_bl[2] = localB->Switch1;

    /* Gain: '<S314>/Gain1' incorporates:
     *  ForEachSliceAssignment generated from: '<S384>/Fx'
     *  Gain: '<S309>/Gain1'
     *  Gain: '<S310>/Gain2'
     *  Gain: '<S312>/Gain'
     *  Gain: '<S313>/Gain'
     *  Product: '<S305>/Product1'
     *  Selector: '<S305>/Selector2'
     *  Selector: '<S324>/Selector5'
     *  Selector: '<S333>/Selector5'
     *  Selector: '<S342>/Selector1'
     *  Selector: '<S346>/Selector3'
     *  Selector: '<S357>/Selector3'
     */
    Vsy_0 = rtb_ImpAsg_InsertedFor_Fx_at_in[static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    rtb_Integrator1_f = Vsy_0 * localP->CoreSubsys.Gain1_Gain;

    /* Switch: '<S357>/Switch' incorporates:
     *  Constant: '<S357>/Constant3'
     *  Constant: '<S357>/Constant6'
     *  Gain: '<S314>/Gain1'
     *  Gain: '<S357>/Gain2'
     *  Selector: '<S357>/Selector3'
     *  Selector: '<S357>/Selector6'
     */
    if (rtb_Integrator1_f * localP->CoreSubsys.Gain2_Gain >=
        localP->CoreSubsys.Switch_Threshold) {
      Vsy_tmp = localP->CoreSubsys.Constant6_Value[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    } else {
      Vsy_tmp = localP->CoreSubsys.Constant3_Value[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Gain: '<S314>/Gain4' incorporates:
     *  Concatenate: '<S296>/Matrix Concatenate'
     *  Gain: '<S309>/Gain4'
     *  Selector: '<S321>/Selector'
     *  Selector: '<S354>/Selector'
     *  Selector: '<S357>/Selector3'
     */
    rtb_Product1_o_idx_1 = rtb_VectorConcatenate1[(static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1) * 3 + 2];

    /* Gain: '<S314>/Gain3' incorporates:
     *  ForEachSliceAssignment generated from: '<S384>/Fy'
     *  Gain: '<S309>/Gain3'
     *  Gain: '<S312>/Gain3'
     *  Selector: '<S305>/Selector1'
     *  Selector: '<S323>/Selector3'
     *  Selector: '<S341>/Selector3'
     *  Selector: '<S356>/Selector1'
     *  Selector: '<S357>/Selector3'
     *  UnaryMinus: '<S305>/Unary Minus'
     */
    rtb_UnaryMinus_c_idx_1 = rtb_ImpAsg_InsertedFor_Fy_at_in[static_cast<int32_T>
      (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

    /* Sum: '<S307>/Sum3' incorporates:
     *  ForEachSliceAssignment generated from: '<S384>/Fy'
     *  Gain: '<S314>/Gain'
     *  Gain: '<S314>/Gain3'
     *  Gain: '<S314>/Gain4'
     *  Gain: '<S314>/Gain5'
     *  Product: '<S354>/Product9'
     *  Product: '<S355>/Product'
     *  Product: '<S356>/Product1'
     *  Product: '<S357>/Product4'
     *  Selector: '<S303>/Selector3'
     *  Selector: '<S354>/Selector'
     *  Selector: '<S356>/Selector1'
     *  Sum: '<S314>/Sum'
     *  Sum: '<S314>/Sum1'
     *  Switch: '<S357>/Switch'
     *  UnitConversion: '<S354>/Unit Conversion'
     *  UnitConversion: '<S354>/Unit Conversion1'
     *  UnitConversion: '<S355>/Unit Conversion'
     *  UnitConversion: '<S356>/Unit Conversion'
     *  UnitConversion: '<S356>/Unit Conversion1'
     *  UnitConversion: '<S357>/Unit Conversion'
     *  UnitConversion: '<S357>/Unit Conversion1'
     */
    rtb_Product_pm = ((((rtb_Product1_o_idx_1 * localP->CoreSubsys.Gain4_Gain *
                         0.001 * localB->CoreSubsys[ForEach_itr_jh].Selector10 *
                         0.017453292519943295 + localP->CoreSubsys.Gain5_Gain_b *
                         rtb_DeadZone1 * localB->CoreSubsys[ForEach_itr_jh].
                         Selector5_j * 0.017453292519943295) +
                        rtb_UnaryMinus_c_idx_1 * localP->CoreSubsys.Gain3_Gain *
                        0.001 * localB->CoreSubsys[ForEach_itr_jh].Selector2_c *
                        0.017453292519943295) + rtb_Integrator1_f * 0.001 *
                       Vsy_tmp * 0.017453292519943295) *
                      localP->CoreSubsys.Gain_Gain_h + localB->
                      CoreSubsys[ForEach_itr_jh].SumofElements_j) + rtb_Add_bl[
      static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Product)];
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S321>/Selector8' incorporates:
       *  Constant: '<S321>/Constant11'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector8 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCAlgnTrqCambCompl[static_cast<
        int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Selector: '<S323>/Selector4' incorporates:
       *  Constant: '<S323>/Constant2'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector4 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCLatCambCompl
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Gain: '<S309>/Gain1' */
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
    rtb_Integrator1_f = Vsy_0 * localP->CoreSubsys.Gain1_Gain_j;

    /* Switch: '<S324>/Switch' incorporates:
     *  Constant: '<S324>/Constant1'
     *  Constant: '<S324>/Constant6'
     *  Gain: '<S309>/Gain1'
     *  Gain: '<S324>/Gain2'
     *  Selector: '<S324>/Selector6'
     *  Selector: '<S357>/Selector3'
     */
    if (rtb_Integrator1_f * localP->CoreSubsys.Gain2_Gain_d >=
        localP->CoreSubsys.Switch_Threshold_d) {
      Vsy_tmp = localP->CoreSubsys.Constant6_Value_d[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    } else {
      Vsy_tmp = localP->CoreSubsys.Constant1_Value_d[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Sum: '<S309>/Sum2' incorporates:
     *  Gain: '<S309>/Gain'
     *  Gain: '<S309>/Gain3'
     *  Gain: '<S309>/Gain4'
     *  Gain: '<S309>/Gain5'
     *  Product: '<S321>/Product8'
     *  Product: '<S322>/Product3'
     *  Product: '<S323>/Product1'
     *  Product: '<S324>/Product4'
     *  Product: '<S326>/Product2'
     *  Switch: '<S324>/Switch'
     *  UnitConversion: '<S321>/Unit Conversion'
     *  UnitConversion: '<S321>/Unit Conversion1'
     *  UnitConversion: '<S322>/Unit Conversion'
     *  UnitConversion: '<S323>/Unit Conversion'
     *  UnitConversion: '<S323>/Unit Conversion1'
     *  UnitConversion: '<S324>/Unit Conversion'
     *  UnitConversion: '<S324>/Unit Conversion1'
     */
    rtb_Product1_o_idx_1 = ((((localP->CoreSubsys.Gain5_Gain * rtb_DeadZone1 *
      localB->CoreSubsys[ForEach_itr_jh].Selector2 * 0.017453292519943295 +
      localB->CoreSubsys[ForEach_itr_jh].Selector5) +
      localP->CoreSubsys.Gain_Gain_d * rtb_Product_pm * localB->
      CoreSubsys[ForEach_itr_jh].SumofElements) + rtb_Product1_o_idx_1 *
      localP->CoreSubsys.Gain4_Gain_e * 0.001 * localB->
      CoreSubsys[ForEach_itr_jh].Selector8 * 0.017453292519943295) +
      rtb_UnaryMinus_c_idx_1 * localP->CoreSubsys.Gain3_Gain_h * 0.001 *
      localB->CoreSubsys[ForEach_itr_jh].Selector4 * 0.017453292519943295) +
      rtb_Integrator1_f * 0.001 * Vsy_tmp * 0.017453292519943295;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S310>/Selector5' incorporates:
       *  Constant: '<S310>/Constant7'
       *  Selector: '<S357>/Selector3'
       *  UnitConversion: '<S310>/Unit Conversion'
       */
      /* Unit Conversion - from: deg to: rad
         Expression: output = (0.0174533*input) + (0) */
      localB->CoreSubsys[ForEach_itr_jh].Selector5_o =
        ConfiguredVirtualVehicleModel_P->PlntSpKCStatCaster[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1] * 0.017453292519943295;

      /* Selector: '<S332>/Selector4' incorporates:
       *  Constant: '<S332>/Constant8'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector4_d =
        ConfiguredVirtualVehicleModel_P->PlntSpKCBumpCaster[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Sum: '<S336>/Sum of Elements' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S335>/Constant6'
       *  Constant: '<S336>/Axle Numbers'
       *  DataTypeConversion: '<S336>/Data Type Conversion'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  Product: '<S336>/Product'
       *  RelationalOperator: '<S336>/Relational Operator'
       *  Selector: '<S335>/Selector3'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].SumofElements_d =
        ConfiguredVirtualVehicleModel_P->PlntSpKCCastVsSteerAng
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1] *
        static_cast<real_T>(localP->
                            IndependentKandCSuspension_Axle[ForEach_itr_jh] ==
                            localP->CoreSubsys.SelectSteerCasterSlope_AxleNums);
    }

    /* Gain: '<S310>/Gain2' */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    /* Unit Conversion - from: N to: kN
       Expression: output = (0.001*input) + (0) */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Integrator1_f = Vsy_0 * localP->CoreSubsys.Gain2_Gain_k;

    /* Switch: '<S333>/Switch' incorporates:
     *  Constant: '<S333>/Constant2'
     *  Constant: '<S333>/Constant4'
     *  Gain: '<S310>/Gain2'
     *  Gain: '<S333>/Gain2'
     *  Selector: '<S333>/Selector6'
     *  Selector: '<S357>/Selector3'
     */
    if (rtb_Integrator1_f * localP->CoreSubsys.Gain2_Gain_d2 >=
        localP->CoreSubsys.Switch_Threshold_d2) {
      Vsy_tmp = localP->CoreSubsys.Constant4_Value[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    } else {
      Vsy_tmp = localP->CoreSubsys.Constant2_Value[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Sum: '<S310>/Sum1' incorporates:
     *  Gain: '<S310>/Gain'
     *  Gain: '<S310>/Gain4'
     *  Product: '<S332>/Product5'
     *  Product: '<S333>/Product3'
     *  Product: '<S335>/Product4'
     *  Switch: '<S333>/Switch'
     *  UnitConversion: '<S332>/Unit Conversion'
     *  UnitConversion: '<S333>/Unit Conversion'
     *  UnitConversion: '<S333>/Unit Conversion1'
     */
    rtb_UnaryMinus_c_idx_2 = ((localP->CoreSubsys.Gain4_Gain_h * rtb_DeadZone1 *
      localB->CoreSubsys[ForEach_itr_jh].Selector4_d * 0.017453292519943295 +
      localB->CoreSubsys[ForEach_itr_jh].Selector5_o) +
      localP->CoreSubsys.Gain_Gain_p * rtb_Product_pm * localB->
      CoreSubsys[ForEach_itr_jh].SumofElements_d) + rtb_Integrator1_f * 0.001 *
      Vsy_tmp * 0.017453292519943295;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S311>/Sum1' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S292>/Wheel Number'
       *  Constant: '<S311>/Constant'
       *  Constant: '<S311>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  ForEachSliceSelector generated from: '<S300>/Wheel Number'
       *  Gain: '<S311>/Gain'
       *  Selector: '<S311>/Selector1'
       *  Sum: '<S311>/Sum'
       */
      rtb_Integrator1_f = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_c[
                           static_cast<int32_T>
                           (localP->
                            IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1]
                           + localP->CoreSubsys.Constant_Value_o) *
        localP->CoreSubsys.Gain_Gain_i - localP->
        IndependentKandCSuspension_WhlN[ForEach_itr_jh];

      /* Signum: '<S311>/Sign' */
      if (std::isnan(rtb_Integrator1_f)) {
        /* Signum: '<S311>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign = (rtNaN);
      } else if (rtb_Integrator1_f < 0.0) {
        /* Signum: '<S311>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign = -1.0;
      } else {
        /* Signum: '<S311>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign = (rtb_Integrator1_f > 0.0);
      }

      /* End of Signum: '<S311>/Sign' */

      /* Selector: '<S373>/Selector2' incorporates:
       *  Constant: '<S373>/Constant5'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector2_l =
        ConfiguredVirtualVehicleModel_P->PlntSpKCNrmlWhlRates
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Selector: '<S373>/Selector1' incorporates:
       *  Constant: '<S373>/Constant1'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector1 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCNrmlWhlFrcOff
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Sum: '<S373>/Sum' incorporates:
     *  Gain: '<S360>/Gain2'
     *  Product: '<S373>/Product3'
     *  UnitConversion: '<S373>/Unit Conversion'
     */
    /* Unit Conversion - from: m to: mm
       Expression: output = (1000*input) + (0) */
    rtb_UnaryMinus_c_idx_0 = localP->CoreSubsys.Gain2_Gain_n * rtb_Divide_ag *
      1000.0 * localB->CoreSubsys[ForEach_itr_jh].Selector2_l +
      localB->CoreSubsys[ForEach_itr_jh].Selector1;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S372>/Selector6' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  Constant: '<S372>/Constant7'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector6 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCMotRatios[static_cast<int32_T>
        (localP->IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1];

      /* Selector: '<S372>/Selector1' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector1_k =
        ConfiguredVirtualVehicleModel_P->PlntSpKCShckFrcVsCompRate
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* Selector: '<S302>/Selector' incorporates:
     *  Selector: '<S302>/Selector2'
     *  Selector: '<S357>/Selector3'
     *  Sum: '<S359>/Add2'
     */
    i = ((static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1) <<
         1) + 1;

    /* Sum: '<S359>/Add2' incorporates:
     *  Concatenate: '<S292>/Matrix Concatenate2'
     *  Concatenate: '<S292>/Matrix Concatenate3'
     *  Selector: '<S302>/Selector'
     *  Selector: '<S302>/Selector2'
     */
    rtb_Integrator1_f = rtb_MatrixConcatenate3[i] - rtb_MatrixConcatenate2[i];

    /* Sum: '<S360>/Add1' incorporates:
     *  Product: '<S372>/Product'
     *  Product: '<S372>/Product1'
     *  Product: '<S372>/Product2'
     *  UnitConversion: '<S372>/Unit Conversion'
     */
    /* Unit Conversion - from: m/s to: mm/s
       Expression: output = (1000*input) + (0) */
    rtb_V_wb_d_idx_2 = 1000.0 * rtb_Integrator1_f * localB->
      CoreSubsys[ForEach_itr_jh].Selector6 * localB->CoreSubsys[ForEach_itr_jh].
      Selector1_k * localB->CoreSubsys[ForEach_itr_jh].Selector6 +
      rtb_UnaryMinus_c_idx_0;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S345>/Selector7' incorporates:
       *  Constant: '<S345>/Constant10'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector7 =
        ConfiguredVirtualVehicleModel_P->PlntSpKCLngWhlCtrDisp
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Selector: '<S340>/Selector6' incorporates:
       *  Constant: '<S340>/Constant9'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector6_m =
        ConfiguredVirtualVehicleModel_P->PlntSpKCLatWhlCtrDisp
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];

      /* Selector: '<S341>/Selector4' incorporates:
       *  Constant: '<S341>/Constant2'
       *  Selector: '<S357>/Selector3'
       */
      localB->CoreSubsys[ForEach_itr_jh].Selector4_p =
        ConfiguredVirtualVehicleModel_P->PlntSpKCLatWhlCtrComplLat
        [static_cast<int32_T>(localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S300>/Info' incorporates:
     *  Product: '<S311>/Product'
     *  Product: '<S360>/Product1'
     *  SignalConversion generated from: '<S300>/Info'
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
    i = ForEach_itr_jh << 3;
    rtb_ImpAsg_InsertedFor_Info_at_[i] = rtb_Product1_o_idx_1;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 1] = rtb_UnaryMinus_c_idx_2;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 2] = rtb_Product_pm * localB->
      CoreSubsys[ForEach_itr_jh].Sign;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 3] = rtb_UnaryMinus2_idx_1;
    rtb_ImpAsg_InsertedFor_Info_at_[i + 4] = rtb_V_wb_d_idx_2 *
      rtb_Integrator1_f;

    /* Signum: '<S360>/Sign1' */
    if (std::isnan(rtb_Divide_ag)) {
      rtb_Integrator1_f = (rtNaN);
    } else if (rtb_Divide_ag < 0.0) {
      rtb_Integrator1_f = -1.0;
    } else {
      rtb_Integrator1_f = (rtb_Divide_ag > 0.0);
    }

    /* ForEachSliceAssignment generated from: '<S300>/Info' incorporates:
     *  Product: '<S360>/Product2'
     *  SignalConversion generated from: '<S300>/Info'
     *  Signum: '<S360>/Sign1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 5] = rtb_Integrator1_f * rtb_Divide_ag *
      rtb_UnaryMinus_c_idx_0;

    /* Gain: '<S313>/Gain' */
    rtb_Integrator1_f = Vsy_0 * localP->CoreSubsys.Gain_Gain_n;

    /* Switch: '<S346>/Switch' incorporates:
     *  Constant: '<S346>/Constant1'
     *  Constant: '<S346>/Constant2'
     *  Gain: '<S313>/Gain'
     *  Gain: '<S346>/Gain2'
     *  Selector: '<S346>/Selector4'
     *  Selector: '<S357>/Selector3'
     */
    if (rtb_Integrator1_f * localP->CoreSubsys.Gain2_Gain_i >=
        localP->CoreSubsys.Switch_Threshold_i) {
      Vsy_tmp = localP->CoreSubsys.Constant2_Value_i[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    } else {
      Vsy_tmp = localP->CoreSubsys.Constant1_Value_i[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S300>/Info' incorporates:
     *  Gain: '<S313>/Gain1'
     *  Gain: '<S313>/Gain4'
     *  Product: '<S345>/Product7'
     *  Product: '<S346>/Product1'
     *  SignalConversion generated from: '<S300>/Info'
     *  Sum: '<S313>/Add'
     *  Switch: '<S346>/Switch'
     *  UnitConversion: '<S346>/Unit Conversion'
     *  UnitConversion: '<S346>/Unit Conversion1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 6] = (rtb_Integrator1_f * 0.001 *
      Vsy_tmp * 0.001 + localP->CoreSubsys.Gain4_Gain_f * rtb_DeadZone1 *
      localB->CoreSubsys[ForEach_itr_jh].Selector7) *
      localP->CoreSubsys.Gain1_Gain_c;

    /* Gain: '<S312>/Gain' */
    rtb_Integrator1_f = Vsy_0 * localP->CoreSubsys.Gain_Gain_ia;

    /* Switch: '<S342>/Switch' incorporates:
     *  Constant: '<S342>/Constant1'
     *  Constant: '<S342>/Constant3'
     *  Gain: '<S312>/Gain'
     *  Gain: '<S342>/Gain2'
     *  Selector: '<S342>/Selector2'
     *  Selector: '<S357>/Selector3'
     */
    if (rtb_Integrator1_f * localP->CoreSubsys.Gain2_Gain_p >=
        localP->CoreSubsys.Switch_Threshold_p) {
      Vsy_tmp = localP->CoreSubsys.Constant3_Value_p[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    } else {
      Vsy_tmp = localP->CoreSubsys.Constant1_Value_p[static_cast<int32_T>
        (localB->CoreSubsys[ForEach_itr_jh].Sum2) - 1];
    }

    /* ForEachSliceAssignment generated from: '<S300>/Info' incorporates:
     *  Gain: '<S312>/Gain1'
     *  Gain: '<S312>/Gain3'
     *  Gain: '<S312>/Gain4'
     *  Product: '<S340>/Product6'
     *  Product: '<S341>/Product1'
     *  Product: '<S342>/Product2'
     *  SignalConversion generated from: '<S300>/Info'
     *  Sum: '<S312>/Add'
     *  Switch: '<S342>/Switch'
     *  UnitConversion: '<S341>/Unit Conversion'
     *  UnitConversion: '<S341>/Unit Conversion1'
     *  UnitConversion: '<S342>/Unit Conversion'
     *  UnitConversion: '<S342>/Unit Conversion1'
     */
    rtb_ImpAsg_InsertedFor_Info_at_[i + 7] = ((rtb_UnaryMinus_c_idx_1 *
      localP->CoreSubsys.Gain3_Gain_d * 0.001 * localB->
      CoreSubsys[ForEach_itr_jh].Selector4_p * 0.001 +
      localP->CoreSubsys.Gain4_Gain_ep * rtb_DeadZone1 * localB->
      CoreSubsys[ForEach_itr_jh].Selector6_m) + rtb_Integrator1_f * 0.001 *
      Vsy_tmp * 0.001) * localP->CoreSubsys.Gain1_Gain_l;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Selector: '<S366>/Selector' incorporates:
       *  Constant: '<S292>/Axle Number'
       *  ForEachSliceSelector generated from: '<S300>/Axle Number'
       *  Selector: '<S361>/Selector1'
       */
      i = static_cast<int32_T>(localP->
        IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1;

      /* Switch: '<S366>/Switch' incorporates:
       *  Constant: '<S366>/Constant'
       *  Constant: '<S366>/Constant1'
       *  Constant: '<S369>/Constant3'
       *  Constant: '<S369>/Constant4'
       *  DataTypeConversion: '<S366>/Data Type Conversion'
       *  Selector: '<S366>/Selector'
       *  Sum: '<S369>/Sum'
       */
      if (localP->CoreSubsys.Constant_Value_l[i] != 0.0) {
        rtb_DeadZone1 = ConfiguredVirtualVehicleModel_P->PlntSpKCRollStiffArb[0]
          - ConfiguredVirtualVehicleModel_P->PlntSpKCRollStiffNoArb[0];
        rtb_UnaryMinus2_idx_1 =
          ConfiguredVirtualVehicleModel_P->PlntSpKCRollStiffArb[1] -
          ConfiguredVirtualVehicleModel_P->PlntSpKCRollStiffNoArb[1];
      } else {
        rtb_DeadZone1 = localP->CoreSubsys.Constant1_Value[0];
        rtb_UnaryMinus2_idx_1 = localP->CoreSubsys.Constant1_Value[1];
      }

      /* End of Switch: '<S366>/Switch' */

      /* ForEachSliceSelector generated from: '<S300>/Axle Number' incorporates:
       *  Constant: '<S292>/Axle Number'
       */
      /* Unit Conversion - from: N*m/deg to: N*m/rad
         Expression: output = (57.2958*input) + (0) */
      rtb_Integrator1_f = localP->IndependentKandCSuspension_Axle[ForEach_itr_jh];

      /* Sum: '<S367>/Sum of Elements' incorporates:
       *  Constant: '<S367>/Axle Numbers'
       *  DataTypeConversion: '<S367>/Data Type Conversion'
       *  Product: '<S367>/Product'
       *  RelationalOperator: '<S367>/Relational Operator'
       *  UnitConversion: '<S366>/Unit Conversion'
       */
      localB->CoreSubsys[ForEach_itr_jh].SumofElements_g = 57.295779513082323 *
        rtb_DeadZone1 * static_cast<real_T>(rtb_Integrator1_f ==
        localP->CoreSubsys.Constrainedspringdampercombinat[0]) +
        57.295779513082323 * rtb_UnaryMinus2_idx_1 * static_cast<real_T>
        (rtb_Integrator1_f == localP->
         CoreSubsys.Constrainedspringdampercombinat[1]);

      /* Sum: '<S361>/Sum1' incorporates:
       *  Constant: '<S292>/Wheel Number'
       *  Constant: '<S361>/Constant'
       *  Constant: '<S361>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S300>/Wheel Number'
       *  Gain: '<S361>/Gain'
       *  Selector: '<S361>/Selector1'
       *  Sum: '<S361>/Sum'
       */
      rtb_Integrator1_f = (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_h[i]
                           + localP->CoreSubsys.Constant_Value_l1) *
        localP->CoreSubsys.Gain_Gain_ih -
        localP->IndependentKandCSuspension_WhlN[ForEach_itr_jh];

      /* Signum: '<S361>/Sign1' */
      if (std::isnan(rtb_Integrator1_f)) {
        /* Signum: '<S361>/Sign1' */
        localB->CoreSubsys[ForEach_itr_jh].Sign1 = (rtNaN);
      } else if (rtb_Integrator1_f < 0.0) {
        /* Signum: '<S361>/Sign1' */
        localB->CoreSubsys[ForEach_itr_jh].Sign1 = -1.0;
      } else {
        /* Signum: '<S361>/Sign1' */
        localB->CoreSubsys[ForEach_itr_jh].Sign1 = (rtb_Integrator1_f > 0.0);
      }

      /* End of Signum: '<S361>/Sign1' */
    }

    /* Selector: '<S361>/Selector2' incorporates:
     *  Constant: '<S292>/Axle Number'
     *  ForEachSliceSelector generated from: '<S300>/Axle Number'
     *  Selector: '<S308>/Selector1'
     */
    i = static_cast<int32_T>(localP->
      IndependentKandCSuspension_Axle[ForEach_itr_jh]) - 1;

    /* Gain: '<S360>/Gain4' incorporates:
     *  Constant: '<S371>/Constant'
     *  Gain: '<S361>/Gain1'
     *  Product: '<S361>/Divide'
     *  Product: '<S361>/Product'
     *  Product: '<S361>/Product2'
     *  Selector: '<S361>/Selector2'
     *  Sum: '<S360>/Add'
     */
    rtb_UnaryMinus2_idx_1 = (localB->CoreSubsys[ForEach_itr_jh].SumofElements_g *
      rtb_Product1_o_idx_3 / rtb_UnaryMinus1_b[i] * localB->
      CoreSubsys[ForEach_itr_jh].Sign1 * localP->CoreSubsys.Gain1_Gain_k +
      (rtb_V_wb_d_idx_2 + localP->CoreSubsys.Constant_Value_c)) *
      localP->CoreSubsys.Gain4_Gain_b;

    /* Sum: '<S305>/Sum' incorporates:
     *  Gain: '<S359>/Sign convention'
     *  Selector: '<S305>/Selector'
     *  Selector: '<S357>/Selector3'
     */
    rtb_Divide_ag = localB->Re[static_cast<int32_T>(localB->
      CoreSubsys[ForEach_itr_jh].Sum2) - 1] +
      localP->CoreSubsys.Signconvention_Gain * rtb_Divide_ag;
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S308>/Sum1' incorporates:
       *  Constant: '<S292>/Wheel Number'
       *  Constant: '<S308>/Constant'
       *  Constant: '<S308>/Vehicle Vehicle Wheel Offset3'
       *  ForEachSliceSelector generated from: '<S300>/Wheel Number'
       *  Gain: '<S308>/Gain'
       *  Selector: '<S308>/Selector1'
       *  Sum: '<S308>/Sum'
       */
      rtb_Integrator1_f = localP->IndependentKandCSuspension_WhlN[ForEach_itr_jh]
        - (localP->CoreSubsys.VehicleVehicleWheelOffset3_Va_e[i] +
           localP->CoreSubsys.Constant_Value_cm) *
        localP->CoreSubsys.Gain_Gain_dx;

      /* Signum: '<S308>/Sign' */
      if (std::isnan(rtb_Integrator1_f)) {
        /* Signum: '<S308>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign_e = (rtNaN);
      } else if (rtb_Integrator1_f < 0.0) {
        /* Signum: '<S308>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign_e = -1.0;
      } else {
        /* Signum: '<S308>/Sign' */
        localB->CoreSubsys[ForEach_itr_jh].Sign_e = (rtb_Integrator1_f > 0.0);
      }

      /* End of Signum: '<S308>/Sign' */
    }

    /* ForEachSliceAssignment generated from: '<S300>/WhlFz' */
    rtb_ImpAsg_InsertedFor_WhlFz_at[ForEach_itr_jh] = rtb_UnaryMinus2_idx_1;

    /* ForEachSliceAssignment generated from: '<S300>/WhlAng' incorporates:
     *  Product: '<S308>/Product'
     *  SignalConversion generated from: '<S300>/WhlAng'
     */
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_jh * 3] = rtb_Product1_o_idx_1 *
      localB->CoreSubsys[ForEach_itr_jh].Sign_e;
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_jh * 3 + 1] =
      rtb_UnaryMinus_c_idx_2;
    rtb_ImpAsg_InsertedFor_WhlAng_a[ForEach_itr_jh * 3 + 2] = rtb_Product_pm;

    /* ForEachSliceAssignment generated from: '<S300>/VehM' incorporates:
     *  Constant: '<S305>/Constant'
     *  Product: '<S305>/Product'
     *  Product: '<S305>/Product1'
     *  UnaryMinus: '<S305>/Unary Minus'
     */
    i = ForEach_itr_jh * 3;
    rtb_ImpAsg_InsertedFor_VehM_at_[i] = -(rtb_UnaryMinus_c_idx_1 *
      rtb_Divide_ag);
    rtb_ImpAsg_InsertedFor_VehM_at_[i + 1] = Vsy_0 * rtb_Divide_ag;
    rtb_ImpAsg_InsertedFor_VehM_at_[i + 2] = localP->CoreSubsys.Constant_Value_d;

    /* ForEachSliceAssignment generated from: '<S300>/VehFz' incorporates:
     *  Gain: '<S359>/Vehicle Force Sign'
     */
    rtb_ImpAsg_InsertedFor_VehFz_at[ForEach_itr_jh] =
      localP->CoreSubsys.VehicleForceSign_Gain * rtb_UnaryMinus2_idx_1;
  }

  /* End of Outputs for SubSystem: '<S292>/For each track and axle combination calculate suspension forces and moments' */

  /* Selector: '<S108>/Selector' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector_i[0] = rtb_ImpAsg_InsertedFor_WhlAng_a[1];

  /* Selector: '<S108>/Selector1' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector1_i[0] = rtb_ImpAsg_InsertedFor_WhlAng_a[2];

  /* Selector: '<S108>/Selector' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector_i[1] = rtb_ImpAsg_InsertedFor_WhlAng_a[4];

  /* Selector: '<S108>/Selector1' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector1_i[1] = rtb_ImpAsg_InsertedFor_WhlAng_a[5];

  /* Outputs for Iterator SubSystem: '<S109>/Kinpin axle moment and tie rod force' */
  /* Constant: '<S109>/RckGnConstant' */
  Kinpinaxlemomentandtierodforce(rtb_Selector1_j, rtb_Selector2, rtb_Selector3,
    rtb_Selector_i, rtb_Selector1_i,
    ConfiguredVirtualVehicleModel_P->PlntSteerRckGn,
    rtb_ImpAsg_InsertedFor_Fsa_y__p,
    ConfiguredVirtualVehicleModel_P->PlntSteerHbLead,
    ConfiguredVirtualVehicleModel_P->PlntSteerKngpnOfst,
    ConfiguredVirtualVehicleModel_P->PlntSteerLambda,
    ConfiguredVirtualVehicleModel_P->PlntSteerRatio,
    ConfiguredVirtualVehicleModel_P->PlntSteerStcLdRadius);

  /* End of Outputs for SubSystem: '<S109>/Kinpin axle moment and tie rod force' */

  /* Backlash: '<S118>/Backlash' */
  rtb_DeadZone1 = localP->FrontSteering_DbWdth / 2.0;
  if (SteerCmd < localDW->PrevY - rtb_DeadZone1) {
    /* Backlash: '<S118>/Backlash' */
    localB->Backlash = SteerCmd + rtb_DeadZone1;
  } else if (SteerCmd <= localDW->PrevY + rtb_DeadZone1) {
    /* Backlash: '<S118>/Backlash' */
    localB->Backlash = localDW->PrevY;
  } else {
    /* Backlash: '<S118>/Backlash' */
    localB->Backlash = SteerCmd - rtb_DeadZone1;
  }

  /* End of Backlash: '<S118>/Backlash' */

  /* Saturate: '<S118>/Saturation' */
  if (localB->Backlash > ConfiguredVirtualVehicleModel_P->PlntSteerRange) {
    Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntSteerRange;
  } else if (localB->Backlash < -ConfiguredVirtualVehicleModel_P->PlntSteerRange)
  {
    Vsy_0 = -ConfiguredVirtualVehicleModel_P->PlntSteerRange;
  } else {
    Vsy_0 = localB->Backlash;
  }

  /* Sum: '<S132>/Subtract' incorporates:
   *  Saturate: '<S118>/Saturation'
   *  SecondOrderIntegrator: '<S140>/Integrator, Second-Order'
   */
  rtb_UnaryMinus_c_idx_0 = Vsy_0 - localX->IntegratorSecondOrder_CSTATE_a[0];

  /* Integrator: '<S132>/Integrator' */
  /* Limited  Integrator  */
  if (localX->Integrator_CSTATE_id >= localP->Integrator_UpperSat) {
    localX->Integrator_CSTATE_id = localP->Integrator_UpperSat;
  } else if (localX->Integrator_CSTATE_id <= localP->Integrator_LowerSat) {
    localX->Integrator_CSTATE_id = localP->Integrator_LowerSat;
  }

  /* Gain: '<S132>/Gain2' */
  localB->Gain2 = localP->SteerTorqueControl_D * rtb_UnaryMinus_c_idx_0;

  /* Derivative: '<S132>/Derivative' incorporates:
   *  Derivative: '<S219>/Derivative'
   */
  rtb_Product_pm = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
  if ((localDW->TimeStampA >= rtb_Product_pm) && (localDW->TimeStampB >=
       rtb_Product_pm)) {
    rtb_DeadZone1 = 0.0;
  } else {
    SteerCmd = localDW->TimeStampA;
    lastU = &localDW->LastUAtTimeA;
    if (localDW->TimeStampA < localDW->TimeStampB) {
      if (localDW->TimeStampB < rtb_Product_pm) {
        SteerCmd = localDW->TimeStampB;
        lastU = &localDW->LastUAtTimeB;
      }
    } else if (localDW->TimeStampA >= rtb_Product_pm) {
      SteerCmd = localDW->TimeStampB;
      lastU = &localDW->LastUAtTimeB;
    }

    rtb_DeadZone1 = (localB->Gain2 - *lastU) / (rtb_Product_pm - SteerCmd);
  }

  /* End of Derivative: '<S132>/Derivative' */

  /* Sum: '<S132>/Subtract1' incorporates:
   *  Gain: '<S132>/Gain'
   *  Integrator: '<S132>/Integrator'
   */
  rtb_Product1_o_idx_1 = (localP->SteerTorqueControl_P * rtb_UnaryMinus_c_idx_0
    + localX->Integrator_CSTATE_id) + rtb_DeadZone1;

  /* Saturate: '<S132>/Saturation' */
  if (rtb_Product1_o_idx_1 > localP->SteerTorqueControl_OutSatUpLmt) {
    rtb_Product1_o_idx_1 = localP->SteerTorqueControl_OutSatUpLmt;
  } else if (rtb_Product1_o_idx_1 < localP->SteerTorqueControl_OutSatLowLmt) {
    rtb_Product1_o_idx_1 = localP->SteerTorqueControl_OutSatLowLmt;
  }

  /* End of Saturate: '<S132>/Saturation' */

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/SteerInputFlagConstant'
   */
  if (localP->SteerInputFlagConstant_Value > localP->Switch_Threshold_b) {
    rtb_DeadZone1 = 0.0;
  } else {
    rtb_DeadZone1 = rtb_Product1_o_idx_1;
  }

  /* End of Switch: '<S109>/Switch' */

  /* SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */
  rtb_IntegratorSecondOrder_o1 = localX->IntegratorSecondOrder_CSTATE_d[0];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S128>/Unary Minus' incorporates:
     *  Constant: '<S128>/Constant'
     */
    localB->UnaryMinus = -localP->Constant_Value_ka;
  }

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S129>/Constant'
   *  Constant: '<S130>/Constant'
   *  Fcn: '<S128>/Fcn'
   *  Logic: '<S128>/Logical Operator'
   *  Product: '<S128>/Product'
   *  RelationalOperator: '<S129>/Compare'
   *  RelationalOperator: '<S130>/Compare'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   *  Switch: '<S128>/Switch1'
   */
  if ((localX->IntegratorSecondOrder_CSTATE_d[1] >=
       -localP->div0protectpoly_thresh_b) &&
      (localX->IntegratorSecondOrder_CSTATE_d[1] <=
       localP->div0protectpoly_thresh_b)) {
    /* Switch: '<S128>/Switch1' incorporates:
     *  Constant: '<S128>/Constant'
     */
    if (localX->IntegratorSecondOrder_CSTATE_d[1] >= localP->Switch1_Threshold_e)
    {
      Vsy_0 = localP->Constant_Value_ka;
    } else {
      Vsy_0 = localB->UnaryMinus;
    }

    rtb_Divide_ag = 0.02 / (3.0 - rt_powd_snf
      (localX->IntegratorSecondOrder_CSTATE_d[1] / 0.01, 2.0)) * Vsy_0;
  } else {
    rtb_Divide_ag = localX->IntegratorSecondOrder_CSTATE_d[1];
  }

  /* End of Switch: '<S128>/Switch' */

  /* Lookup_n-D: '<S126>/TrqAssistTbl' incorporates:
   *  Gain: '<S666>/Gain1'
   */
  rtb_Product1_o_idx_3 = look2_binlcpw(rtb_DeadZone1, localB->UnitConversion[0],
    ConfiguredVirtualVehicleModel_P->PlntSteerWheelTrqBpt,
    localP->FrontSteering_VehSpdBpts,
    ConfiguredVirtualVehicleModel_P->PlntSteerTrqAsstTbl,
    localP->TrqAssistTbl_maxIndex, 3U);

  /* Saturate: '<S126>/Saturation1' */
  if (rtb_Product1_o_idx_3 > ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit)
  {
    rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit;
  } else if (rtb_Product1_o_idx_3 <
             -ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit) {
    rtb_Product1_o_idx_3 = -ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit;
  }

  /* Product: '<S126>/Product' incorporates:
   *  Saturate: '<S126>/Saturation1'
   */
  rtb_Product1_o_idx_3 *= rtb_Divide_ag;

  /* Saturate: '<S126>/Saturation2' */
  if (rtb_Product1_o_idx_3 > ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit)
  {
    rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit;
  } else if (rtb_Product1_o_idx_3 <
             -ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit) {
    rtb_Product1_o_idx_3 = -ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit;
  }

  /* Product: '<S127>/Divide' incorporates:
   *  Constant: '<S127>/Constant'
   *  Gain: '<S126>/Gain1'
   *  Integrator: '<S127>/Integrator1'
   *  Product: '<S126>/Product1'
   *  Saturate: '<S126>/Saturation2'
   *  Sum: '<S127>/Sum'
   */
  localB->Divide_p = (rtb_Product1_o_idx_3 / rtb_Divide_ag *
                      localP->FrontSteering_Eta - localX->Integrator1_CSTATE_nx)
    * ConfiguredVirtualVehicleModel_P->PlntSteerWc;

  /* Sum: '<S132>/Subtract2' incorporates:
   *  Gain: '<S132>/Gain1'
   *  Gain: '<S132>/Gain3'
   */
  localB->Subtract2 = localP->SteerTorqueControl_I * rtb_UnaryMinus_c_idx_0 -
    localP->SteerTorqueControl_A * rtb_Product1_o_idx_1;

  /* Sum: '<S120>/Add' incorporates:
   *  Gain: '<S137>/Gain'
   *  Gain: '<S137>/Gain1'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S140>/Integrator, Second-Order'
   *  Sum: '<S137>/Add'
   *  Sum: '<S137>/Add1'
   */
  rtb_UnaryMinus2_idx_1 = (localX->IntegratorSecondOrder_CSTATE_a[0] -
    rtb_IntegratorSecondOrder_o1) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorStf +
    (localX->IntegratorSecondOrder_CSTATE_a[1] -
     localX->IntegratorSecondOrder_CSTATE_d[1]) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorDamp;

  /* Sum: '<S133>/Add' incorporates:
   *  Constant: '<S120>/Constant1'
   *  SecondOrderIntegrator: '<S140>/Integrator, Second-Order'
   */
  localB->Add = localX->IntegratorSecondOrder_CSTATE_a[0] -
    localP->Constant1_Value_c1[0];

  /* Sum: '<S133>/Add1' incorporates:
   *  Constant: '<S120>/Constant1'
   *  SecondOrderIntegrator: '<S140>/Integrator, Second-Order'
   */
  localB->Add1_m = localX->IntegratorSecondOrder_CSTATE_a[1] -
    localP->Constant1_Value_c1[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S133>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsyste = localDW->TmpLatchAtTriggeredSubsystemInp;

    /* Memory generated from: '<S133>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_p = localDW->TmpLatchAtTriggeredSubsystemI_l;

    /* Outputs for Triggered SubSystem: '<S133>/Triggered Subsystem' */
    ConfiguredVi_TriggeredSubsystem(localB->Add1_m, localB->Add,
      rtb_TmpLatchAtTriggeredSubsyste, rtb_TmpLatchAtTriggeredSubsys_p,
      ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
      ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem, &localZCE->TriggeredSubsystem);

    /* End of Outputs for SubSystem: '<S133>/Triggered Subsystem' */
  }

  /* Sum: '<S133>/Add3' */
  rtb_Product1_o_idx_1 = localB->Add - localB->TriggeredSubsystem.In;

  /* Sum: '<S133>/Add2' */
  rtb_Add2_i = localB->TriggeredSubsystem.y + rtb_Product1_o_idx_1;

  /* Signum: '<S133>/Sign' */
  if (std::isnan(localB->Add1_m)) {
    /* Signum: '<S133>/Sign' */
    localB->Sign = localB->Add1_m;
  } else if (localB->Add1_m < 0.0) {
    /* Signum: '<S133>/Sign' */
    localB->Sign = -1.0;
  } else {
    /* Signum: '<S133>/Sign' */
    localB->Sign = (localB->Add1_m > 0.0);
  }

  /* End of Signum: '<S133>/Sign' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S141>/Enable' */
    localB->HiddenBuf_InsertedFor_EnabledSu = localB->Sign;
  }

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  ConfiguredVirt_EnabledSubsystem(localB->HiddenBuf_InsertedFor_EnabledSu,
    rtb_Add2_i, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf, &localB->EnabledSubsystem,
    &localDW->EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem' */

  /* Sum: '<S133>/Add4' */
  rtb_Add4 = localB->TriggeredSubsystem.y_i + rtb_Product1_o_idx_1;

  /* Gain: '<S133>/Gain' */
  localB->Gain = localP->Gain_Gain_o * localB->Sign;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S142>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_h = localB->Gain;
  }

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  ConfiguredVir_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_h,
    rtb_Add4, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf, &localB->EnabledSubsystem1,
    &localDW->EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem1' */

  /* Sum: '<S120>/Add1' incorporates:
   *  Sum: '<S133>/Add5'
   */
  SteerCmd = (rtb_DeadZone1 - (localB->EnabledSubsystem.y +
    localB->EnabledSubsystem1.y)) - rtb_UnaryMinus2_idx_1;

  /* Sum: '<S134>/Add' incorporates:
   *  Constant: '<S120>/Constant2'
   */
  localB->Add_k = rtb_IntegratorSecondOrder_o1 - localP->Constant2_Value_o[0];

  /* Sum: '<S134>/Add1' incorporates:
   *  Constant: '<S120>/Constant2'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   */
  localB->Add1_c = localX->IntegratorSecondOrder_CSTATE_d[1] -
    localP->Constant2_Value_o[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S134>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_i = localDW->TmpLatchAtTriggeredSubsystemI_n;

    /* Memory generated from: '<S134>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_g = localDW->TmpLatchAtTriggeredSubsystemI_k;

    /* Outputs for Triggered SubSystem: '<S134>/Triggered Subsystem' */
    ConfiguredVi_TriggeredSubsystem(localB->Add1_c, localB->Add_k,
      rtb_TmpLatchAtTriggeredSubsys_i, rtb_TmpLatchAtTriggeredSubsys_g,
      ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
      ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_k, &localZCE->TriggeredSubsystem_k);

    /* End of Outputs for SubSystem: '<S134>/Triggered Subsystem' */
  }

  /* Sum: '<S134>/Add3' */
  rtb_DeadZone1 = localB->Add_k - localB->TriggeredSubsystem_k.In;

  /* Sum: '<S134>/Add2' */
  rtb_Add2_d = localB->TriggeredSubsystem_k.y + rtb_DeadZone1;

  /* Signum: '<S134>/Sign' */
  if (std::isnan(localB->Add1_c)) {
    /* Signum: '<S134>/Sign' */
    localB->Sign_l = localB->Add1_c;
  } else if (localB->Add1_c < 0.0) {
    /* Signum: '<S134>/Sign' */
    localB->Sign_l = -1.0;
  } else {
    /* Signum: '<S134>/Sign' */
    localB->Sign_l = (localB->Add1_c > 0.0);
  }

  /* End of Signum: '<S134>/Sign' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S148>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_a = localB->Sign_l;
  }

  /* Outputs for Enabled SubSystem: '<S134>/Enabled Subsystem' */
  ConfiguredVirt_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enabled_a,
    rtb_Add2_d, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem_h, &localDW->EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S134>/Enabled Subsystem' */

  /* Sum: '<S134>/Add4' */
  rtb_Add4_i = localB->TriggeredSubsystem_k.y_i + rtb_DeadZone1;

  /* Gain: '<S134>/Gain' */
  localB->Gain_o = localP->Gain_Gain_m * localB->Sign_l;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S149>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_g = localB->Gain_o;
  }

  /* Outputs for Enabled SubSystem: '<S134>/Enabled Subsystem1' */
  ConfiguredVir_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_g,
    rtb_Add4_i, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem1_d, &localDW->EnabledSubsystem1_d);

  /* End of Outputs for SubSystem: '<S134>/Enabled Subsystem1' */

  /* Sum: '<S120>/Add3' incorporates:
   *  Gain: '<S138>/Gain'
   *  Gain: '<S138>/Gain1'
   *  SecondOrderIntegrator: '<S139>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S158>/Integrator, Second-Order'
   *  Sum: '<S138>/Add'
   *  Sum: '<S138>/Add1'
   */
  rtb_DeadZone1 = (rtb_IntegratorSecondOrder_o1 - rtb_SOC_CC) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorStf +
    (localX->IntegratorSecondOrder_CSTATE_d[1] -
     localX->IntegratorSecondOrder_CSTATE_e[1]) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorDamp;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S133>/Memory' */
    localB->Memory_j = localDW->Memory_PreviousInput_p;

    /* Memory: '<S133>/Memory1' */
    localB->Memory1 = localDW->Memory1_PreviousInput;

    /* Memory: '<S134>/Memory' */
    localB->Memory_hm = localDW->Memory_PreviousInput_g;

    /* Memory: '<S134>/Memory1' */
    localB->Memory1_k = localDW->Memory1_PreviousInput_n;
  }

  /* MATLAB Function: '<S155>/MATLAB Function1' */
  ConfiguredVirtu_MATLABFunction1(rtb_IntegratorSecondOrder_o1,
    localP->FrontSteering_SptlAng, &localB->sf_MATLABFunction1);

  /* Gain: '<S158>/Gain3' incorporates:
   *  Gain: '<S158>/Gain'
   *  Product: '<S155>/Divide'
   *  Product: '<S158>/Divide1'
   *  Product: '<S158>/Product4'
   *  Sum: '<S109>/Add'
   *  Sum: '<S158>/Add'
   */
  localB->Gain3 = (rtb_DeadZone1 / localB->sf_MATLABFunction1.y *
                   ConfiguredVirtualVehicleModel_P->PlntSteerEpsilon /
                   localB->Divide_e + (rtb_ImpAsg_InsertedFor_Fsa_y__p[0] +
    rtb_ImpAsg_InsertedFor_Fsa_y__p[1])) * localB->Divide_e * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntSteerPnInert);

  /* Gain: '<S139>/Gain' incorporates:
   *  Integrator: '<S127>/Integrator1'
   *  Sum: '<S120>/Add2'
   *  Sum: '<S134>/Add5'
   */
  localB->Gain_n = (((rtb_UnaryMinus2_idx_1 + localX->Integrator1_CSTATE_nx) -
                     (localB->EnabledSubsystem_h.y +
                      localB->EnabledSubsystem1_d.y)) - rtb_DeadZone1) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntSteerLowerInertia);

  /* Gain: '<S140>/Gain' */
  localB->Gain_a = 1.0 / ConfiguredVirtualVehicleModel_P->PlntSteerUpperInertia *
    SteerCmd;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S261>/Add' incorporates:
     *  Constant: '<S261>/Constant'
     *  Constant: '<S261>/Constant1'
     */
    rtb_Product2_lv = ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] / 2.0
      - ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

    /* Product: '<S261>/Divide' incorporates:
     *  Constant: '<S261>/Constant3'
     */
    SteerCmd = localP->RackandPinforDynStr_d_o / rtb_Product2_lv;

    /* Sum: '<S261>/Add1' incorporates:
     *  Constant: '<S261>/Constant2'
     *  Math: '<S261>/Math Function'
     *  Math: '<S261>/Math Function1'
     */
    rtb_Product2_lv = rtb_Product2_lv * rtb_Product2_lv +
      localP->RackandPinforDynStr_d_o * localP->RackandPinforDynStr_d_o;

    /* Sum: '<S261>/Add2' incorporates:
     *  Constant: '<S261>/Constant4'
     *  Constant: '<S261>/Constant5'
     *  Math: '<S261>/Math Function2'
     *  Math: '<S261>/Math Function3'
     */
    rtb_SOC_CC = (ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
                  ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth +
                  rtb_Product2_lv) -
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;

    /* Sqrt: '<S261>/Sqrt' */
    rtb_Product2_lv = std::sqrt(rtb_Product2_lv);

    /* Product: '<S261>/Divide1' incorporates:
     *  Constant: '<S261>/Constant6'
     *  Constant: '<S261>/Constant7'
     */
    rtb_Product1_o_idx_3 = rtb_SOC_CC / localP->Constant6_Value_c /
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / rtb_Product2_lv;

    /* Trigonometry: '<S261>/Trigonometric Function1' */
    if (rtb_Product1_o_idx_3 > 1.0) {
      rtb_Product1_o_idx_3 = 1.0;
    } else if (rtb_Product1_o_idx_3 < -1.0) {
      rtb_Product1_o_idx_3 = -1.0;
    }

    /* Sum: '<S261>/Add3' incorporates:
     *  Constant: '<S261>/Constant8'
     *  Trigonometry: '<S261>/Trigonometric Function'
     *  Trigonometry: '<S261>/Trigonometric Function1'
     */
    localB->Add3_m = (localP->Constant8_Value_i - std::atan(SteerCmd)) - std::
      acos(rtb_Product1_o_idx_3);

    /* Product: '<S245>/Divide' incorporates:
     *  Constant: '<S110>/RckGnConstant'
     *  Constant: '<S245>/Constant'
     */
    localB->Divide_j = ConfiguredVirtualVehicleModel_P->PlntSteerRckGn /
      localP->Constant_Value_cq;

    /* UnaryMinus: '<S256>/Unary Minus1' */
    localB->UnaryMinus1_l = -localB->Divide_j;
  }

  /* Sum: '<S259>/Add' incorporates:
   *  Constant: '<S259>/Constant'
   *  Constant: '<S259>/Constant1'
   *  Product: '<S256>/Product'
   *  SecondOrderIntegrator: '<S245>/Integrator, Second-Order'
   */
  rtb_DeadZone1 = (ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] / 2.0 -
                   localB->UnaryMinus1_l *
                   localX->IntegratorSecondOrder_CSTATE_k[0]) -
    ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S259>/Trigonometric Function' incorporates:
   *  Constant: '<S259>/Constant3'
   *  Product: '<S259>/Divide'
   */
  SteerCmd = std::atan(localP->RackandPinforDynStr_d_o / rtb_DeadZone1);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S259>/Math Function1' incorporates:
     *  Constant: '<S259>/Constant2'
     */
    localB->MathFunction1_k = localP->RackandPinforDynStr_d_o *
      localP->RackandPinforDynStr_d_o;

    /* Math: '<S259>/Math Function2' incorporates:
     *  Constant: '<S259>/Constant4'
     */
    localB->MathFunction2_m =
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth;

    /* Math: '<S259>/Math Function3' incorporates:
     *  Constant: '<S259>/Constant5'
     */
    localB->MathFunction3_d =
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S259>/Add1' incorporates:
   *  Math: '<S259>/Math Function'
   */
  rtb_DeadZone1 = rtb_DeadZone1 * rtb_DeadZone1 + localB->MathFunction1_k;

  /* Product: '<S259>/Divide1' incorporates:
   *  Constant: '<S259>/Constant6'
   *  Constant: '<S259>/Constant7'
   *  Sqrt: '<S259>/Sqrt'
   *  Sum: '<S259>/Add2'
   */
  rtb_Product1_o_idx_3 = ((rtb_DeadZone1 + localB->MathFunction2_m) -
    localB->MathFunction3_d) / localP->Constant6_Value_e /
    ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / std::sqrt
    (rtb_DeadZone1);

  /* Trigonometry: '<S259>/Trigonometric Function1' */
  if (rtb_Product1_o_idx_3 > 1.0) {
    rtb_Product1_o_idx_3 = 1.0;
  } else if (rtb_Product1_o_idx_3 < -1.0) {
    rtb_Product1_o_idx_3 = -1.0;
  }

  /* Sum: '<S256>/Add' incorporates:
   *  Constant: '<S259>/Constant8'
   *  Sum: '<S259>/Add3'
   *  Trigonometry: '<S259>/Trigonometric Function1'
   */
  rtb_DeadZone1 = ((localP->Constant8_Value_p - SteerCmd) - std::acos
                   (rtb_Product1_o_idx_3)) - localB->Add3_m;

  /* Sum: '<S260>/Add' incorporates:
   *  Constant: '<S260>/Constant'
   *  Constant: '<S260>/Constant1'
   *  Product: '<S256>/Product3'
   *  SecondOrderIntegrator: '<S245>/Integrator, Second-Order'
   */
  rtb_Product1_o_idx_1 = (ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] /
    2.0 - localB->Divide_j * localX->IntegratorSecondOrder_CSTATE_k[0]) -
    ConfiguredVirtualVehicleModel_P->PlntSteerRckCsLngth / 2.0;

  /* Trigonometry: '<S260>/Trigonometric Function' incorporates:
   *  Constant: '<S260>/Constant3'
   *  Product: '<S260>/Divide'
   */
  SteerCmd = std::atan(localP->RackandPinforDynStr_d_o / rtb_Product1_o_idx_1);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S260>/Math Function1' incorporates:
     *  Constant: '<S260>/Constant2'
     */
    localB->MathFunction1_a = localP->RackandPinforDynStr_d_o *
      localP->RackandPinforDynStr_d_o;

    /* Math: '<S260>/Math Function2' incorporates:
     *  Constant: '<S260>/Constant4'
     */
    localB->MathFunction2_b =
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth;

    /* Math: '<S260>/Math Function3' incorporates:
     *  Constant: '<S260>/Constant5'
     */
    localB->MathFunction3_m =
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth *
      ConfiguredVirtualVehicleModel_P->PlntSteerTieRodLngth;
  }

  /* Sum: '<S260>/Add1' incorporates:
   *  Math: '<S260>/Math Function'
   */
  rtb_Product1_o_idx_1 = rtb_Product1_o_idx_1 * rtb_Product1_o_idx_1 +
    localB->MathFunction1_a;

  /* Product: '<S260>/Divide1' incorporates:
   *  Constant: '<S260>/Constant6'
   *  Constant: '<S260>/Constant7'
   *  Sqrt: '<S260>/Sqrt'
   *  Sum: '<S260>/Add2'
   */
  rtb_Product1_o_idx_3 = ((rtb_Product1_o_idx_1 + localB->MathFunction2_b) -
    localB->MathFunction3_m) / localP->Constant6_Value_n /
    ConfiguredVirtualVehicleModel_P->PlntSteerStrgArmLngth / std::sqrt
    (rtb_Product1_o_idx_1);

  /* Trigonometry: '<S260>/Trigonometric Function1' */
  if (rtb_Product1_o_idx_3 > 1.0) {
    rtb_Product1_o_idx_3 = 1.0;
  } else if (rtb_Product1_o_idx_3 < -1.0) {
    rtb_Product1_o_idx_3 = -1.0;
  }

  /* Sum: '<S256>/Add1' incorporates:
   *  Constant: '<S260>/Constant8'
   *  Sum: '<S260>/Add3'
   *  Trigonometry: '<S260>/Trigonometric Function1'
   */
  rtb_Product1_o_idx_1 = localB->Add3_m - ((localP->Constant8_Value_j - SteerCmd)
    - std::acos(rtb_Product1_o_idx_3));

  /* Switch: '<S245>/Switch' incorporates:
   *  SecondOrderIntegrator: '<S245>/Integrator, Second-Order'
   */
  if (localX->IntegratorSecondOrder_CSTATE_k[0] > localP->Switch_Threshold_gp) {
    rtb_UnaryMinus1_b[0] = rtb_Product1_o_idx_1;
    rtb_UnaryMinus1_b[1] = rtb_DeadZone1;
  } else {
    rtb_UnaryMinus1_b[0] = rtb_DeadZone1;
    rtb_UnaryMinus1_b[1] = rtb_Product1_o_idx_1;
  }

  /* End of Switch: '<S245>/Switch' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S245>/Gain5' incorporates:
     *  Constant: '<S110>/PctAckConstant'
     */
    localB->Gain5_c = localP->Gain5_Gain_h *
      ConfiguredVirtualVehicleModel_P->PlntSteerPctAck;

    /* Sum: '<S245>/Add1' incorporates:
     *  Constant: '<S245>/Constant1'
     */
    localB->Add1_m4 = localP->Constant1_Value_n - localB->Gain5_c;
  }

  /* Sum: '<S245>/Sum' incorporates:
   *  Product: '<S245>/Product1'
   *  Product: '<S245>/Product2'
   */
  rtb_SOC_CC = rtb_UnaryMinus1_b[0] * localB->Add1_m4 + rtb_UnaryMinus1_b[1] *
    localB->Gain5_c;

  /* Switch: '<S245>/Switch1' incorporates:
   *  SecondOrderIntegrator: '<S245>/Integrator, Second-Order'
   */
  if (localX->IntegratorSecondOrder_CSTATE_k[0] > localP->Switch1_Threshold_p4)
  {
    rtb_Product1_o_idx_3 = rtb_SOC_CC;
    rtb_UnaryMinus2_idx_1 = rtb_UnaryMinus1_b[0];
  } else {
    rtb_Product1_o_idx_3 = rtb_UnaryMinus1_b[0];
    rtb_UnaryMinus2_idx_1 = rtb_SOC_CC;
  }

  /* End of Switch: '<S245>/Switch1' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S110>/LocFlagConstant'
   *  Constant: '<S245>/AckermanFlagConstant'
   *  Switch: '<S245>/Switch4'
   *  UnaryMinus: '<S198>/Unary Minus1'
   */
  if (localP->LocFlagConstant_Value_e > localP->Switch_Threshold_k) {
    /* Switch: '<S245>/Switch4' incorporates:
     *  Constant: '<S245>/AckermanFlagConstant'
     */
    if (!(localP->AckermanFlagConstant_Value_m > localP->Switch4_Threshold_j)) {
      rtb_DeadZone1 = rtb_Product1_o_idx_3;
    }
  } else if (localP->AckermanFlagConstant_Value_m > localP->Switch4_Threshold_j)
  {
    /* Switch: '<S245>/Switch4' incorporates:
     *  UnaryMinus: '<S198>/Unary Minus1'
     */
    rtb_DeadZone1 = -rtb_DeadZone1;
  } else {
    rtb_DeadZone1 = -rtb_Product1_o_idx_3;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Gain: '<S108>/Gain' */
  localB->RL = localP->Gain_Gain_pi * rtb_DeadZone1;

  /* Switch: '<S198>/Switch1' incorporates:
   *  Constant: '<S110>/LocFlagConstant'
   *  Constant: '<S245>/AckermanFlagConstant'
   *  Switch: '<S245>/Switch5'
   *  UnaryMinus: '<S198>/Unary Minus'
   */
  if (localP->LocFlagConstant_Value_e > localP->Switch1_Threshold_hf) {
    /* Switch: '<S245>/Switch5' incorporates:
     *  Constant: '<S245>/AckermanFlagConstant'
     */
    if (localP->AckermanFlagConstant_Value_m > localP->Switch5_Threshold_a) {
      rtb_UnaryMinus2_idx_1 = rtb_Product1_o_idx_1;
    }
  } else if (localP->AckermanFlagConstant_Value_m > localP->Switch5_Threshold_a)
  {
    /* Switch: '<S245>/Switch5' incorporates:
     *  UnaryMinus: '<S198>/Unary Minus'
     */
    rtb_UnaryMinus2_idx_1 = -rtb_Product1_o_idx_1;
  } else {
    rtb_UnaryMinus2_idx_1 = -rtb_UnaryMinus2_idx_1;
  }

  /* Gain: '<S108>/Gain1' incorporates:
   *  Switch: '<S198>/Switch1'
   */
  localB->RR = localP->Gain1_Gain_p * rtb_UnaryMinus2_idx_1;

  /* Selector: '<S110>/Selector' */
  rtb_Selector_i2[0] = rtb_ImpAsg_InsertedFor_Fx_at_in[2];

  /* Selector: '<S110>/Selector1' */
  rtb_Selector1_h[0] = rtb_ImpAsg_InsertedFor_Fy_at_in[2];

  /* Selector: '<S110>/Selector2' */
  rtb_Selector2_d[0] = rtb_ImpAsg_InsertedFor_Fz_at_in[2];

  /* Selector: '<S110>/Selector3' incorporates:
   *  Concatenate: '<S208>/Matrix Concatenate'
   */
  rtb_Selector3_m[0] = rtb_ImpAsg_InsertedFor_Mz_at_in[2];

  /* Selector: '<S108>/Selector14' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector14[0] = rtb_ImpAsg_InsertedFor_WhlAng_a[1];

  /* Selector: '<S108>/Selector15' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector15[0] = rtb_ImpAsg_InsertedFor_WhlAng_a[2];

  /* Selector: '<S110>/Selector' */
  rtb_Selector_i2[1] = rtb_ImpAsg_InsertedFor_Fx_at_in[3];

  /* Selector: '<S110>/Selector1' */
  rtb_Selector1_h[1] = rtb_ImpAsg_InsertedFor_Fy_at_in[3];

  /* Selector: '<S110>/Selector2' */
  rtb_Selector2_d[1] = rtb_ImpAsg_InsertedFor_Fz_at_in[3];

  /* Selector: '<S110>/Selector3' incorporates:
   *  Concatenate: '<S208>/Matrix Concatenate'
   */
  rtb_Selector3_m[1] = rtb_ImpAsg_InsertedFor_Mz_at_in[3];

  /* Selector: '<S108>/Selector14' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector14[1] = rtb_ImpAsg_InsertedFor_WhlAng_a[4];

  /* Selector: '<S108>/Selector15' incorporates:
   *  Reshape: '<S292>/Reshape5'
   */
  rtb_Selector15[1] = rtb_ImpAsg_InsertedFor_WhlAng_a[5];

  /* Outputs for Iterator SubSystem: '<S110>/Kinpin axle moment and tie rod force' */
  /* Constant: '<S110>/RckGnConstant' */
  Kinpinaxlemomentandtierodforce(rtb_Selector1_h, rtb_Selector2_d,
    rtb_Selector3_m, rtb_Selector14, rtb_Selector15,
    ConfiguredVirtualVehicleModel_P->PlntSteerRckGn,
    rtb_ImpAsg_InsertedFor_Fsa_y_at,
    ConfiguredVirtualVehicleModel_P->PlntSteerHbLead,
    ConfiguredVirtualVehicleModel_P->PlntSteerKngpnOfst,
    ConfiguredVirtualVehicleModel_P->PlntSteerLambda,
    ConfiguredVirtualVehicleModel_P->PlntSteerRatio,
    ConfiguredVirtualVehicleModel_P->PlntSteerStcLdRadius);

  /* End of Outputs for SubSystem: '<S110>/Kinpin axle moment and tie rod force' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Backlash: '<S205>/Backlash' incorporates:
     *  Constant: '<S108>/Constant'
     */
    rtb_DeadZone1 = localP->RearSteering_DbWdth / 2.0;
    if (localP->Constant_Value_k < localDW->PrevY_g - rtb_DeadZone1) {
      /* Backlash: '<S205>/Backlash' */
      localB->Backlash_a = localP->Constant_Value_k + rtb_DeadZone1;
    } else if (localP->Constant_Value_k <= localDW->PrevY_g + rtb_DeadZone1) {
      /* Backlash: '<S205>/Backlash' */
      localB->Backlash_a = localDW->PrevY_g;
    } else {
      /* Backlash: '<S205>/Backlash' */
      localB->Backlash_a = localP->Constant_Value_k - rtb_DeadZone1;
    }

    /* End of Backlash: '<S205>/Backlash' */

    /* Saturate: '<S205>/Saturation' */
    if (localB->Backlash_a > ConfiguredVirtualVehicleModel_P->PlntSteerRange) {
      /* Saturate: '<S205>/Saturation' */
      localB->Saturation = ConfiguredVirtualVehicleModel_P->PlntSteerRange;
    } else if (localB->Backlash_a <
               -ConfiguredVirtualVehicleModel_P->PlntSteerRange) {
      /* Saturate: '<S205>/Saturation' */
      localB->Saturation = -ConfiguredVirtualVehicleModel_P->PlntSteerRange;
    } else {
      /* Saturate: '<S205>/Saturation' */
      localB->Saturation = localB->Backlash_a;
    }

    /* End of Saturate: '<S205>/Saturation' */
  }

  /* SecondOrderIntegrator: '<S227>/Integrator, Second-Order' */
  rtb_SOC_CC = localX->IntegratorSecondOrder_CSTATE_ak[1];

  /* Sum: '<S219>/Subtract' incorporates:
   *  SecondOrderIntegrator: '<S227>/Integrator, Second-Order'
   */
  rtb_DeadZone1 = localB->Saturation - localX->IntegratorSecondOrder_CSTATE_ak[0];

  /* Integrator: '<S219>/Integrator' */
  /* Limited  Integrator  */
  if (localX->Integrator_CSTATE_jz >= localP->Integrator_UpperSat_p) {
    localX->Integrator_CSTATE_jz = localP->Integrator_UpperSat_p;
  } else if (localX->Integrator_CSTATE_jz <= localP->Integrator_LowerSat_l) {
    localX->Integrator_CSTATE_jz = localP->Integrator_LowerSat_l;
  }

  /* Gain: '<S219>/Gain2' */
  localB->Gain2_j = localP->SteerTorqueControl_D_c * rtb_DeadZone1;

  /* Derivative: '<S219>/Derivative' */
  if ((localDW->TimeStampA_g >= rtb_Product_pm) && (localDW->TimeStampB_a >=
       rtb_Product_pm)) {
    rtb_UnaryMinus_c_idx_0 = 0.0;
  } else {
    SteerCmd = localDW->TimeStampA_g;
    lastU = &localDW->LastUAtTimeA_j;
    if (localDW->TimeStampA_g < localDW->TimeStampB_a) {
      if (localDW->TimeStampB_a < rtb_Product_pm) {
        SteerCmd = localDW->TimeStampB_a;
        lastU = &localDW->LastUAtTimeB_l;
      }
    } else if (localDW->TimeStampA_g >= rtb_Product_pm) {
      SteerCmd = localDW->TimeStampB_a;
      lastU = &localDW->LastUAtTimeB_l;
    }

    rtb_UnaryMinus_c_idx_0 = (localB->Gain2_j - *lastU) / (rtb_Product_pm -
      SteerCmd);
  }

  /* Sum: '<S219>/Subtract1' incorporates:
   *  Gain: '<S219>/Gain'
   *  Integrator: '<S219>/Integrator'
   */
  rtb_Product_pm = (localP->SteerTorqueControl_P_p * rtb_DeadZone1 +
                    localX->Integrator_CSTATE_jz) + rtb_UnaryMinus_c_idx_0;

  /* Saturate: '<S219>/Saturation' */
  if (rtb_Product_pm > localP->SteerTorqueControl_OutSatUpLm_l) {
    rtb_Product_pm = localP->SteerTorqueControl_OutSatUpLm_l;
  } else if (rtb_Product_pm < localP->SteerTorqueControl_OutSatLowL_b) {
    rtb_Product_pm = localP->SteerTorqueControl_OutSatLowL_b;
  }

  /* End of Saturate: '<S219>/Saturation' */

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/SteerInputFlagConstant'
   */
  if (localP->SteerInputFlagConstant_Value_c > localP->Switch_Threshold_m) {
    rtb_UnaryMinus_c_idx_0 = 0.0;
  } else {
    rtb_UnaryMinus_c_idx_0 = rtb_Product_pm;
  }

  /* End of Switch: '<S110>/Switch' */

  /* SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */
  rtb_IntegratorSecondOrder_o1_e = localX->IntegratorSecondOrder_CSTATE_l[0];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S215>/Unary Minus' incorporates:
     *  Constant: '<S215>/Constant'
     */
    localB->UnaryMinus_l = -localP->Constant_Value_kw;
  }

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S216>/Constant'
   *  Constant: '<S217>/Constant'
   *  Fcn: '<S215>/Fcn'
   *  Logic: '<S215>/Logical Operator'
   *  Product: '<S215>/Product'
   *  RelationalOperator: '<S216>/Compare'
   *  RelationalOperator: '<S217>/Compare'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   *  Switch: '<S215>/Switch1'
   */
  if ((localX->IntegratorSecondOrder_CSTATE_l[1] >=
       -localP->div0protectpoly_thresh_a) &&
      (localX->IntegratorSecondOrder_CSTATE_l[1] <=
       localP->div0protectpoly_thresh_a)) {
    /* Switch: '<S215>/Switch1' incorporates:
     *  Constant: '<S215>/Constant'
     */
    if (localX->IntegratorSecondOrder_CSTATE_l[1] >= localP->Switch1_Threshold_b)
    {
      Vsy_0 = localP->Constant_Value_kw;
    } else {
      Vsy_0 = localB->UnaryMinus_l;
    }

    rtb_V_wb_d_idx_2 = 0.02 / (3.0 - rt_powd_snf
      (localX->IntegratorSecondOrder_CSTATE_l[1] / 0.01, 2.0)) * Vsy_0;
  } else {
    rtb_V_wb_d_idx_2 = localX->IntegratorSecondOrder_CSTATE_l[1];
  }

  /* End of Switch: '<S215>/Switch' */

  /* Lookup_n-D: '<S213>/TrqAssistTbl' incorporates:
   *  Switch: '<S110>/Switch'
   */
  rtb_Product1_o_idx_3 = look2_binlcpw(rtb_UnaryMinus_c_idx_0,
    localB->UnitConversion[0],
    ConfiguredVirtualVehicleModel_P->PlntSteerWheelTrqBpt,
    localP->RearSteering_VehSpdBpts,
    ConfiguredVirtualVehicleModel_P->PlntSteerTrqAsstTbl,
    localP->TrqAssistTbl_maxIndex_f, 3U);

  /* Saturate: '<S213>/Saturation1' */
  if (rtb_Product1_o_idx_3 > ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit)
  {
    rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit;
  } else if (rtb_Product1_o_idx_3 <
             -ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit) {
    rtb_Product1_o_idx_3 = -ConfiguredVirtualVehicleModel_P->PlntSteerTrqLimit;
  }

  /* Product: '<S213>/Product' incorporates:
   *  Saturate: '<S213>/Saturation1'
   */
  rtb_Product1_o_idx_3 *= rtb_V_wb_d_idx_2;

  /* Saturate: '<S213>/Saturation2' */
  if (rtb_Product1_o_idx_3 > ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit)
  {
    rtb_Product1_o_idx_3 = ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit;
  } else if (rtb_Product1_o_idx_3 <
             -ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit) {
    rtb_Product1_o_idx_3 = -ConfiguredVirtualVehicleModel_P->PlntSteerPwrLimit;
  }

  /* Product: '<S214>/Divide' incorporates:
   *  Constant: '<S214>/Constant'
   *  Gain: '<S213>/Gain1'
   *  Integrator: '<S214>/Integrator1'
   *  Product: '<S213>/Product1'
   *  Saturate: '<S213>/Saturation2'
   *  Sum: '<S214>/Sum'
   */
  localB->Divide_jz = (rtb_Product1_o_idx_3 / rtb_V_wb_d_idx_2 *
                       localP->RearSteering_Eta - localX->Integrator1_CSTATE_dc)
    * ConfiguredVirtualVehicleModel_P->PlntSteerWc;

  /* Sum: '<S219>/Subtract2' incorporates:
   *  Gain: '<S219>/Gain1'
   *  Gain: '<S219>/Gain3'
   */
  localB->Subtract2_c = localP->SteerTorqueControl_I_f * rtb_DeadZone1 -
    localP->SteerTorqueControl_A_i * rtb_Product_pm;

  /* Sum: '<S207>/Add' incorporates:
   *  Gain: '<S224>/Gain'
   *  Gain: '<S224>/Gain1'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S227>/Integrator, Second-Order'
   *  Sum: '<S224>/Add'
   *  Sum: '<S224>/Add1'
   */
  rtb_DeadZone1 = (localX->IntegratorSecondOrder_CSTATE_ak[0] -
                   rtb_IntegratorSecondOrder_o1_e) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorStf + (rtb_SOC_CC -
    localX->IntegratorSecondOrder_CSTATE_l[1]) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorDamp;

  /* Sum: '<S220>/Add' incorporates:
   *  Constant: '<S207>/Constant1'
   *  SecondOrderIntegrator: '<S227>/Integrator, Second-Order'
   */
  localB->Add_o = localX->IntegratorSecondOrder_CSTATE_ak[0] -
    localP->Constant1_Value_e[0];

  /* Sum: '<S220>/Add1' incorporates:
   *  Constant: '<S207>/Constant1'
   */
  localB->Add1_mi = rtb_SOC_CC - localP->Constant1_Value_e[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S220>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_b = localDW->TmpLatchAtTriggeredSubsystemI_c;

    /* Memory generated from: '<S220>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_m = localDW->TmpLatchAtTriggeredSubsystemI_g;

    /* Outputs for Triggered SubSystem: '<S220>/Triggered Subsystem' */
    ConfiguredVi_TriggeredSubsystem(localB->Add1_mi, localB->Add_o,
      rtb_TmpLatchAtTriggeredSubsys_b, rtb_TmpLatchAtTriggeredSubsys_m,
      ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
      ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_e, &localZCE->TriggeredSubsystem_e);

    /* End of Outputs for SubSystem: '<S220>/Triggered Subsystem' */
  }

  /* Sum: '<S220>/Add3' */
  rtb_Product1_o_idx_1 = localB->Add_o - localB->TriggeredSubsystem_e.In;

  /* Sum: '<S220>/Add2' */
  rtb_Add2_m = localB->TriggeredSubsystem_e.y + rtb_Product1_o_idx_1;

  /* Signum: '<S220>/Sign' */
  if (std::isnan(localB->Add1_mi)) {
    /* Signum: '<S220>/Sign' */
    localB->Sign_f = localB->Add1_mi;
  } else if (localB->Add1_mi < 0.0) {
    /* Signum: '<S220>/Sign' */
    localB->Sign_f = -1.0;
  } else {
    /* Signum: '<S220>/Sign' */
    localB->Sign_f = (localB->Add1_mi > 0.0);
  }

  /* End of Signum: '<S220>/Sign' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S228>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_e = localB->Sign_f;
  }

  /* Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  ConfiguredVirt_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enabled_e,
    rtb_Add2_m, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem_g, &localDW->EnabledSubsystem_g);

  /* End of Outputs for SubSystem: '<S220>/Enabled Subsystem' */

  /* Sum: '<S220>/Add4' */
  rtb_Add4_e = localB->TriggeredSubsystem_e.y_i + rtb_Product1_o_idx_1;

  /* Gain: '<S220>/Gain' */
  localB->Gain_p = localP->Gain_Gain_b * localB->Sign_f;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S229>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_j = localB->Gain_p;
  }

  /* Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem1' */
  ConfiguredVir_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_j,
    rtb_Add4_e, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem1_i, &localDW->EnabledSubsystem1_i);

  /* End of Outputs for SubSystem: '<S220>/Enabled Subsystem1' */

  /* Sum: '<S221>/Add' incorporates:
   *  Constant: '<S207>/Constant2'
   */
  localB->Add_h = rtb_IntegratorSecondOrder_o1_e - localP->Constant2_Value_p[0];

  /* Sum: '<S221>/Add1' incorporates:
   *  Constant: '<S207>/Constant2'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   */
  localB->Add1_k = localX->IntegratorSecondOrder_CSTATE_l[1] -
    localP->Constant2_Value_p[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory generated from: '<S221>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsys_l = localDW->TmpLatchAtTriggeredSubsystemI_a;

    /* Memory generated from: '<S221>/Triggered Subsystem' */
    rtb_TmpLatchAtTriggeredSubsy_b4 = localDW->TmpLatchAtTriggeredSubsystemI_i;

    /* Outputs for Triggered SubSystem: '<S221>/Triggered Subsystem' */
    ConfiguredVi_TriggeredSubsystem(localB->Add1_k, localB->Add_h,
      rtb_TmpLatchAtTriggeredSubsys_l, rtb_TmpLatchAtTriggeredSubsy_b4,
      ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
      ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
      &localB->TriggeredSubsystem_l, &localZCE->TriggeredSubsystem_l);

    /* End of Outputs for SubSystem: '<S221>/Triggered Subsystem' */
  }

  /* Sum: '<S221>/Add3' */
  rtb_Product1_o_idx_1 = localB->Add_h - localB->TriggeredSubsystem_l.In;

  /* Sum: '<S221>/Add2' */
  rtb_Add2_n = localB->TriggeredSubsystem_l.y + rtb_Product1_o_idx_1;

  /* Signum: '<S221>/Sign' */
  if (std::isnan(localB->Add1_k)) {
    /* Signum: '<S221>/Sign' */
    localB->Sign_d = localB->Add1_k;
  } else if (localB->Add1_k < 0.0) {
    /* Signum: '<S221>/Sign' */
    localB->Sign_d = -1.0;
  } else {
    /* Signum: '<S221>/Sign' */
    localB->Sign_d = (localB->Add1_k > 0.0);
  }

  /* End of Signum: '<S221>/Sign' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S235>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_f = localB->Sign_d;
  }

  /* Outputs for Enabled SubSystem: '<S221>/Enabled Subsystem' */
  ConfiguredVirt_EnabledSubsystem(localB->HiddenBuf_InsertedFor_Enabled_f,
    rtb_Add2_n, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem_n, &localDW->EnabledSubsystem_n);

  /* End of Outputs for SubSystem: '<S221>/Enabled Subsystem' */

  /* Sum: '<S221>/Add4' */
  rtb_Add4_j = localB->TriggeredSubsystem_l.y_i + rtb_Product1_o_idx_1;

  /* Gain: '<S221>/Gain' */
  localB->Gain_l = localP->Gain_Gain_p2 * localB->Sign_d;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S236>/Enable' */
    localB->HiddenBuf_InsertedFor_Enabled_n = localB->Gain_l;
  }

  /* Outputs for Enabled SubSystem: '<S221>/Enabled Subsystem1' */
  ConfiguredVir_EnabledSubsystem1(localB->HiddenBuf_InsertedFor_Enabled_n,
    rtb_Add4_j, ConfiguredVirtualVehicleModel_P->PlntSteerUpprFric,
    ConfiguredVirtualVehicleModel_P->PlntSteerSlgStf,
    &localB->EnabledSubsystem1_j, &localDW->EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S221>/Enabled Subsystem1' */

  /* Sum: '<S207>/Add3' incorporates:
   *  Gain: '<S225>/Gain'
   *  Gain: '<S225>/Gain1'
   *  SecondOrderIntegrator: '<S226>/Integrator, Second-Order'
   *  SecondOrderIntegrator: '<S245>/Integrator, Second-Order'
   *  Sum: '<S225>/Add'
   *  Sum: '<S225>/Add1'
   */
  rtb_Divide_ag = (rtb_IntegratorSecondOrder_o1_e -
                   localX->IntegratorSecondOrder_CSTATE_k[0]) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorStf +
    (localX->IntegratorSecondOrder_CSTATE_l[1] -
     localX->IntegratorSecondOrder_CSTATE_k[1]) *
    ConfiguredVirtualVehicleModel_P->PlntSteerTorDamp;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S220>/Memory' */
    localB->Memory_e = localDW->Memory_PreviousInput_o;

    /* Memory: '<S220>/Memory1' */
    localB->Memory1_c = localDW->Memory1_PreviousInput_f;

    /* Memory: '<S221>/Memory' */
    localB->Memory_g = localDW->Memory_PreviousInput_h;

    /* Memory: '<S221>/Memory1' */
    localB->Memory1_j = localDW->Memory1_PreviousInput_m;
  }

  /* MATLAB Function: '<S242>/MATLAB Function1' */
  ConfiguredVirtu_MATLABFunction1(rtb_IntegratorSecondOrder_o1_e,
    localP->RearSteering_SptlAng, &localB->sf_MATLABFunction1_i);

  /* Gain: '<S245>/Gain3' incorporates:
   *  Gain: '<S245>/Gain'
   *  Product: '<S242>/Divide'
   *  Product: '<S245>/Divide1'
   *  Product: '<S245>/Product4'
   *  Sum: '<S110>/Add'
   *  Sum: '<S245>/Add'
   */
  localB->Gain3_n = (rtb_Divide_ag / localB->sf_MATLABFunction1_i.y *
                     ConfiguredVirtualVehicleModel_P->PlntSteerEpsilon /
                     localB->Divide_j + (rtb_ImpAsg_InsertedFor_Fsa_y_at[0] +
    rtb_ImpAsg_InsertedFor_Fsa_y_at[1])) * localB->Divide_j * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntSteerPnInert);

  /* Gain: '<S226>/Gain' incorporates:
   *  Integrator: '<S214>/Integrator1'
   *  Sum: '<S207>/Add2'
   *  Sum: '<S221>/Add5'
   */
  localB->Gain_b = (((rtb_DeadZone1 + localX->Integrator1_CSTATE_dc) -
                     (localB->EnabledSubsystem_n.y +
                      localB->EnabledSubsystem1_j.y)) - rtb_Divide_ag) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntSteerLowerInertia);

  /* Gain: '<S227>/Gain' incorporates:
   *  Sum: '<S207>/Add1'
   *  Sum: '<S220>/Add5'
   */
  localB->Gain_m = ((rtb_UnaryMinus_c_idx_0 - (localB->EnabledSubsystem_g.y +
    localB->EnabledSubsystem1_i.y)) - rtb_DeadZone1) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntSteerUpperInertia);

  /* Product: '<S290>/Divide' incorporates:
   *  Constant: '<S290>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S290>/Integrator1'
   *  Selector: '<S292>/dWhlY select'
   *  Sum: '<S290>/Sum'
   */
  localB->Divide_c[0] = (rtb_ImpAsg_InsertedFor_Info_at_[7] -
    localX->Integrator1_CSTATE_d[0]) * localP->ContLPF_wc;

  /* Product: '<S291>/Divide' incorporates:
   *  Constant: '<S291>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S291>/Integrator1'
   *  Selector: '<S292>/Height select'
   *  Sum: '<S291>/Sum'
   */
  localB->Divide_k[0] = (rtb_ImpAsg_InsertedFor_Info_at_[3] -
    localX->Integrator1_CSTATE_nd[0]) * localP->ContLPF2_wc;

  /* Concatenate: '<S292>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate4'
   *  ForEachSliceAssignment generated from: '<S300>/VehFz'
   *  ForEachSliceAssignment generated from: '<S384>/Fx'
   */
  rtb_VectorConcatenate1[0] = rtb_ImpAsg_InsertedFor_Fx_at_in[0];
  rtb_VectorConcatenate1[1] = rtb_ImpAsg_InsertedFor_Fy_at_in[0];
  rtb_VectorConcatenate1[2] = rtb_ImpAsg_InsertedFor_VehFz_at[0];

  /* Product: '<S374>/Divide' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate1'
   *  Constant: '<S374>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/WhlFz'
   *  Sum: '<S374>/Sum'
   */
  localB->Divide_c3[0] = (rtb_ImpAsg_InsertedFor_WhlFz_at[0] -
    rtb_Integrator1_hl_idx_0) * localP->ContLPF_wc_p;

  /* Product: '<S290>/Divide' incorporates:
   *  Constant: '<S290>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S290>/Integrator1'
   *  Selector: '<S292>/dWhlY select'
   *  Sum: '<S290>/Sum'
   */
  localB->Divide_c[1] = (rtb_ImpAsg_InsertedFor_Info_at_[15] -
    localX->Integrator1_CSTATE_d[1]) * localP->ContLPF_wc;

  /* Product: '<S291>/Divide' incorporates:
   *  Constant: '<S291>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S291>/Integrator1'
   *  Selector: '<S292>/Height select'
   *  Sum: '<S291>/Sum'
   */
  localB->Divide_k[1] = (rtb_ImpAsg_InsertedFor_Info_at_[11] -
    localX->Integrator1_CSTATE_nd[1]) * localP->ContLPF2_wc;

  /* Concatenate: '<S292>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate4'
   *  ForEachSliceAssignment generated from: '<S300>/VehFz'
   *  ForEachSliceAssignment generated from: '<S384>/Fx'
   */
  rtb_VectorConcatenate1[3] = rtb_ImpAsg_InsertedFor_Fx_at_in[1];
  rtb_VectorConcatenate1[4] = rtb_ImpAsg_InsertedFor_Fy_at_in[1];
  rtb_VectorConcatenate1[5] = rtb_ImpAsg_InsertedFor_VehFz_at[1];

  /* Product: '<S374>/Divide' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate1'
   *  Constant: '<S374>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/WhlFz'
   *  Sum: '<S374>/Sum'
   */
  localB->Divide_c3[1] = (rtb_ImpAsg_InsertedFor_WhlFz_at[1] -
    rtb_Integrator1_hl_idx_1) * localP->ContLPF_wc_p;

  /* Product: '<S290>/Divide' incorporates:
   *  Constant: '<S290>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S290>/Integrator1'
   *  Selector: '<S292>/dWhlY select'
   *  Sum: '<S290>/Sum'
   */
  localB->Divide_c[2] = (rtb_ImpAsg_InsertedFor_Info_at_[23] -
    localX->Integrator1_CSTATE_d[2]) * localP->ContLPF_wc;

  /* Product: '<S291>/Divide' incorporates:
   *  Constant: '<S291>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S291>/Integrator1'
   *  Selector: '<S292>/Height select'
   *  Sum: '<S291>/Sum'
   */
  localB->Divide_k[2] = (rtb_ImpAsg_InsertedFor_Info_at_[19] -
    localX->Integrator1_CSTATE_nd[2]) * localP->ContLPF2_wc;

  /* Concatenate: '<S292>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate4'
   *  ForEachSliceAssignment generated from: '<S300>/VehFz'
   *  ForEachSliceAssignment generated from: '<S384>/Fx'
   */
  rtb_VectorConcatenate1[6] = rtb_ImpAsg_InsertedFor_Fx_at_in[2];
  rtb_VectorConcatenate1[7] = rtb_ImpAsg_InsertedFor_Fy_at_in[2];
  rtb_VectorConcatenate1[8] = rtb_ImpAsg_InsertedFor_VehFz_at[2];

  /* Product: '<S374>/Divide' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate1'
   *  Constant: '<S374>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/WhlFz'
   *  Sum: '<S374>/Sum'
   */
  localB->Divide_c3[2] = (rtb_ImpAsg_InsertedFor_WhlFz_at[2] -
    rtb_Integrator1_hl_idx_2) * localP->ContLPF_wc_p;

  /* Product: '<S290>/Divide' incorporates:
   *  Constant: '<S290>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S290>/Integrator1'
   *  Selector: '<S292>/dWhlY select'
   *  Sum: '<S290>/Sum'
   */
  localB->Divide_c[3] = (rtb_ImpAsg_InsertedFor_Info_at_[31] -
    localX->Integrator1_CSTATE_d[3]) * localP->ContLPF_wc;

  /* Product: '<S291>/Divide' incorporates:
   *  Constant: '<S291>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/Info'
   *  Integrator: '<S291>/Integrator1'
   *  Selector: '<S292>/Height select'
   *  Sum: '<S291>/Sum'
   */
  localB->Divide_k[3] = (rtb_ImpAsg_InsertedFor_Info_at_[27] -
    localX->Integrator1_CSTATE_nd[3]) * localP->ContLPF2_wc;

  /* Concatenate: '<S292>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate4'
   *  ForEachSliceAssignment generated from: '<S300>/VehFz'
   *  ForEachSliceAssignment generated from: '<S384>/Fx'
   */
  rtb_VectorConcatenate1[9] = rtb_ImpAsg_InsertedFor_Fx_at_in[3];
  rtb_VectorConcatenate1[10] = rtb_ImpAsg_InsertedFor_Fy_at_in[3];
  rtb_VectorConcatenate1[11] = rtb_ImpAsg_InsertedFor_VehFz_at[3];

  /* Product: '<S374>/Divide' incorporates:
   *  Concatenate: '<S292>/Matrix Concatenate1'
   *  Constant: '<S374>/Constant'
   *  ForEachSliceAssignment generated from: '<S300>/WhlFz'
   *  Sum: '<S374>/Sum'
   */
  localB->Divide_c3[3] = (rtb_ImpAsg_InsertedFor_WhlFz_at[3] -
    rtb_Integrator1_hl_idx_3) * localP->ContLPF_wc_p;
  for (i = 0; i < 12; i++) {
    /* Product: '<S375>/Divide' incorporates:
     *  Constant: '<S375>/Constant'
     *  Integrator: '<S375>/Integrator1'
     *  Reshape: '<S292>/Reshape5'
     *  Sum: '<S375>/Sum'
     */
    localB->Divide_b[i] = (rtb_ImpAsg_InsertedFor_WhlAng_a[i] -
      localX->Integrator1_CSTATE_e[i]) * localP->ContLPF1_wc;
  }

  /* Gain: '<S391>/Unsprung Masses sum([VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassRearAxle//2 VEH.UnsprungMassRearAxle//2])' incorporates:
   *  Concatenate: '<S391>/Vector Concatenate'
   *  Integrator: '<S393>/Integrator1'
   */
  localB->VectorConcatenate_l[0] = localP->UnsprungMassessumVEHUnsprungMas *
    localX->Integrator1_CSTATE_a[0];
  localB->VectorConcatenate_l[1] = localP->UnsprungMassessumVEHUnsprungMas *
    localX->Integrator1_CSTATE_a[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S390>/Constant1' */
    localB->Constant1[0] = localP->Constant1_Value_o[0];
    localB->Constant1[1] = localP->Constant1_Value_o[1];
    localB->Constant1[2] = localP->Constant1_Value_o[2];

    /* Constant: '<S391>/Vertical' incorporates:
     *  Concatenate: '<S391>/Vector Concatenate'
     */
    localB->VectorConcatenate_l[2] = localP->Vertical_Value;

    /* Product: '<S409>/Product' incorporates:
     *  Constant: '<S409>/0'
     */
    SteerCmd = localP->u_Value_d * localB->Mbar;

    /* Product: '<S409>/Product' incorporates:
     *  Constant: '<S409>/g'
     */
    localB->Fg_I[0] = SteerCmd;
    localB->Fg_I[1] = SteerCmd;
    localB->Fg_I[2] = ConfiguredVirtualVehicleModel_P->EnvGrvty * localB->Mbar;
  }

  /* Product: '<S409>/Inertial to Body' */
  rtb_Integrator1_hl_idx_0 = localB->Fg_I[0];
  rtb_Integrator1_hl_idx_1 = localB->Fg_I[1];
  rtb_Integrator1_hl_idx_2 = localB->Fg_I[2];

  /* Product: '<S433>/Inertial to Body' */
  rtb_Integrator1_hl_idx_3 = localB->Wind[0];
  rtb_DeadZone1 = localB->Wind[1];
  rtb_Product1_o_idx_1 = localB->Wind[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S409>/Inertial to Body' incorporates:
     *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
     */
    rtb_Divide_ag = rtb_VectorConcatenate_lq[i];
    SteerCmd = rtb_Divide_ag * rtb_Integrator1_hl_idx_0;

    /* Sum: '<S434>/Add1' incorporates:
     *  Product: '<S433>/Inertial to Body'
     */
    Vsy_0 = rtb_Divide_ag * rtb_Integrator1_hl_idx_3;

    /* Product: '<S409>/Inertial to Body' incorporates:
     *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
     */
    rtb_Divide_ag = rtb_VectorConcatenate_lq[i + 3];
    SteerCmd += rtb_Divide_ag * rtb_Integrator1_hl_idx_1;

    /* Sum: '<S434>/Add1' incorporates:
     *  Product: '<S433>/Inertial to Body'
     */
    Vsy_0 += rtb_Divide_ag * rtb_DeadZone1;

    /* Product: '<S409>/Inertial to Body' incorporates:
     *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
     */
    rtb_Divide_ag = rtb_VectorConcatenate_lq[i + 6];
    rtb_Sum_c5[i] = rtb_Divide_ag * rtb_Integrator1_hl_idx_2 + SteerCmd;

    /* Sum: '<S434>/Add1' incorporates:
     *  Product: '<S433>/Inertial to Body'
     */
    SteerCmd = localB->UnitConversion[i] - (rtb_Divide_ag * rtb_Product1_o_idx_1
      + Vsy_0);
    rtb_Product_o0[i] = SteerCmd;

    /* Trigonometry: '<S434>/Tanh' incorporates:
     *  Gain: '<S434>/4'
     */
    rtb_Add_bl[i] = std::tanh(localP->u_Gain[i] * SteerCmd);

    /* Product: '<S434>/Product' */
    rtb_Switch1_f[i] = SteerCmd * SteerCmd;
  }

  /* Sqrt: '<S434>/Sqrt' incorporates:
   *  Sum: '<S434>/Sum of Elements'
   */
  rtb_Divide_ag = std::sqrt((rtb_Switch1_f[0] + rtb_Switch1_f[1]) +
    rtb_Switch1_f[2]);

  /* Product: '<S434>/Product2' */
  SteerCmd = rtb_Divide_ag * rtb_Divide_ag;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S434>/Constant' incorporates:
     *  Concatenate: '<S434>/Vector Concatenate'
     */
    localB->VectorConcatenate_k[0] =
      ConfiguredVirtualVehicleModel_P->PlntVehAeroDragCff;
  }

  /* Trigonometry: '<S434>/Trigonometric Function' */
  rtb_Divide_ag = rt_atan2d_snf(rtb_Product_o0[1], rtb_Product_o0[0]);

  /* Lookup_n-D: '<S434>/Cs' incorporates:
   *  Concatenate: '<S434>/Vector Concatenate'
   *  Gain: '<S644>/Gain1'
   */
  localB->VectorConcatenate_k[1] = look1_binlcpw(rtb_Divide_ag,
    localP->VehicleBody6DOF_beta_w, localP->VehicleBody6DOF_Cs, 30U);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S434>/Constant1' incorporates:
     *  Concatenate: '<S434>/Vector Concatenate'
     */
    localB->VectorConcatenate_k[2] =
      ConfiguredVirtualVehicleModel_P->PlntVehAeroLiftCff;
  }

  /* Lookup_n-D: '<S434>/Crm' incorporates:
   *  Concatenate: '<S434>/Vector Concatenate'
   *  Gain: '<S644>/Gain1'
   */
  localB->VectorConcatenate_k[3] = look1_binlxpw(rtb_Divide_ag,
    localP->Crm_bp01Data, localP->Crm_tableData, 1U);

  /* Product: '<S434>/Product5' incorporates:
   *  Concatenate: '<S434>/Vector Concatenate'
   *  Constant: '<S434>/Constant2'
   */
  localB->VectorConcatenate_k[4] = rtb_Add_bl[0] *
    ConfiguredVirtualVehicleModel_P->PlntVehAeroPitchCff;

  /* Lookup_n-D: '<S434>/Cym' incorporates:
   *  Concatenate: '<S434>/Vector Concatenate'
   *  Gain: '<S644>/Gain1'
   */
  localB->VectorConcatenate_k[5] = look1_binlxpw(rtb_Divide_ag,
    localP->VehicleBody6DOF_beta_w, localP->VehicleBody6DOF_Cym, 30U);

  /* Gain: '<S434>/.5.*A.*Pabs.//R.//T' incorporates:
   *  Constant: '<S392>/AirTempConstant'
   *  Product: '<S434>/Product1'
   */
  rtb_Product_pm = 0.5 * ConfiguredVirtualVehicleModel_P->PlntVehAeroFrntArea *
    ConfiguredVirtualVehicleModel_P->EnvAbsPrs / localP->DragForce_R;
  for (i = 0; i < 6; i++) {
    rtb_Abs_j[i] = SteerCmd * localB->VectorConcatenate_k[i] /
      ConfiguredVirtualVehicleModel_P->EnvAirTemp * rtb_Product_pm;
  }

  /* End of Gain: '<S434>/.5.*A.*Pabs.//R.//T' */

  /* Product: '<S434>/Product3' incorporates:
   *  Constant: '<S434>/Constant4'
   *  Sum: '<S434>/Add2'
   */
  rtb_Product_pm = (rtb_Add_bl[0] - localP->Constant4_Value[0]) * rtb_Abs_j[0];
  rtb_Product1_o_idx_1 = (rtb_Add_bl[1] - localP->Constant4_Value[1]) *
    rtb_Abs_j[1];
  rtb_DeadZone1 = (rtb_Add_bl[2] - localP->Constant4_Value[2]) * rtb_Abs_j[2];

  /* Fcn: '<S475>/Fcn11' */
  rtb_VectorConcatenate_lq[0] = Fzo_prime_idx_0;

  /* Fcn: '<S475>/Fcn21' */
  rtb_VectorConcatenate_lq[1] = Fzo_prime_idx_3;

  /* Fcn: '<S475>/Fcn31' */
  rtb_VectorConcatenate_lq[2] = lam_muy_prime_idx_3;

  /* Fcn: '<S475>/Fcn12' */
  rtb_VectorConcatenate_lq[3] = lam_muy_prime_idx_2;

  /* Fcn: '<S475>/Fcn22' */
  rtb_VectorConcatenate_lq[4] = Fzo_prime_idx_1;

  /* Fcn: '<S475>/Fcn32' */
  rtb_VectorConcatenate_lq[5] = rtb_Saturation_1;

  /* Fcn: '<S475>/Fcn13' */
  rtb_VectorConcatenate_lq[6] = -Fzo_prime_idx_2;

  /* Fcn: '<S475>/Fcn23' */
  rtb_VectorConcatenate_lq[7] = lam_muy_prime_idx_1;

  /* Fcn: '<S475>/Fcn33' */
  rtb_VectorConcatenate_lq[8] = dfz_0;

  /* Math: '<S473>/Transpose1' incorporates:
   *  Concatenate: '<S490>/Vector Concatenate'
   *  Math: '<S485>/Transpose1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Transpose1[3 * i] = rtb_VectorConcatenate_lq[i];
    rtb_Transpose1[3 * i + 1] = rtb_VectorConcatenate_lq[i + 3];
    rtb_Transpose1[3 * i + 2] = rtb_VectorConcatenate_lq[i + 6];
  }

  /* End of Math: '<S473>/Transpose1' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S453>/Subtract' incorporates:
     *  Constant: '<S453>/latOff'
     *  Constant: '<S453>/longOff'
     *  Constant: '<S453>/vertOff '
     */
    localB->Subtract[0] = localP->VehicleBody6DOF_longOff + localB->Rbar[0];
    localB->Subtract[1] = localP->VehicleBody6DOF_latOff + localB->Rbar[1];
    localB->Subtract[2] = localP->VehicleBody6DOF_vertOff + localB->Rbar[2];
  }

  /* Product: '<S477>/Product' incorporates:
   *  Sum: '<S453>/Subtract'
   */
  SteerCmd = localB->Subtract[1];
  rtb_Integrator1_hl_idx_0 = localB->Subtract[0];
  rtb_Integrator1_hl_idx_1 = localB->Subtract[2];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S473>/Add' incorporates:
     *  Integrator: '<S407>/xe,ye,ze'
     *  Math: '<S485>/Transpose1'
     */
    localB->Add_n[i] = ((rtb_Transpose1[i + 3] * SteerCmd + rtb_Transpose1[i] *
                         rtb_Integrator1_hl_idx_0) + rtb_Transpose1[i + 6] *
                        rtb_Integrator1_hl_idx_1) + localX->xeyeze_CSTATE[i];
  }

  /* End of Product: '<S477>/Product' */

  /* MATLAB Function: '<S391>/Estimated Unsprung Mass Orientation' incorporates:
   *  Constant: '<S434>/Constant3'
   *  Product: '<S434>/Product4'
   *  SecondOrderIntegrator: '<S521>/Integrator, Second-Order'
   *  UnaryMinus: '<S383>/Unary Minus1'
   */
  rtb_Switch1_f[0] = std::atan(((-rtb_Saturation1_idx_0 -
    (-rtb_Saturation1_idx_1)) + (-rtb_Saturation1_idx_2 - (-rtb_SumofElements15)))
    / ConfiguredVirtualVehicleModel_P->PlntVehTrckWdth[0] / 2.0);
  rtb_Integrator1_hl_idx_0 =
    ConfiguredVirtualVehicleModel_P->PlntVehDstCGFrntAxl +
    ConfiguredVirtualVehicleModel_P->PlntVehDstCGRearAxl;
  rtb_Switch1_f[1] = std::atan(((-rtb_Saturation1_idx_0 -
    (-rtb_Saturation1_idx_2)) + (-rtb_Saturation1_idx_1 - (-rtb_SumofElements15)))
    / rtb_Integrator1_hl_idx_0 / 2.0);

  /* Outputs for Iterator SubSystem: '<S391>/Susp2Body' incorporates:
   *  ForEach: '<S395>/For Each'
   */
  for (ForEach_itr_n = 0; ForEach_itr_n < 4; ForEach_itr_n++) {
    /* SignalConversion generated from: '<S395>/Vector Concatenate' */
    rtb_SumofElements15 = rty_VehFdbk[2];

    /* Trigonometry: '<S396>/sincos' incorporates:
     *  SignalConversion generated from: '<S396>/sincos'
     *  UnaryMinus: '<S395>/Unary Minus'
     */
    rtb_Add_bl[0] = std::cos(rtb_SumofElements15);
    SteerCmd = std::sin(rtb_SumofElements15);
    rtb_Add_bl[1] = std::cos(-rtb_Switch1_f[1]);
    rtb_SumofElements15 = std::sin(-rtb_Switch1_f[1]);
    rtb_Add_bl[2] = std::cos(-rtb_Switch1_f[0]);
    rtb_Saturation1_idx_0 = std::sin(-rtb_Switch1_f[0]);

    /* Fcn: '<S396>/Fcn11' */
    rtb_VectorConcatenate_lq[0] = rtb_Add_bl[0] * rtb_Add_bl[1];

    /* Fcn: '<S396>/Fcn21' incorporates:
     *  Fcn: '<S396>/Fcn22'
     *  Trigonometry: '<S396>/sincos'
     */
    Fzo_prime_idx_0 = rtb_SumofElements15 * rtb_Saturation1_idx_0;
    rtb_VectorConcatenate_lq[1] = Fzo_prime_idx_0 * rtb_Add_bl[0] - SteerCmd *
      rtb_Add_bl[2];

    /* Fcn: '<S396>/Fcn31' incorporates:
     *  Fcn: '<S396>/Fcn32'
     *  Trigonometry: '<S396>/sincos'
     */
    Fzo_prime_idx_1 = rtb_SumofElements15 * rtb_Add_bl[2];
    rtb_VectorConcatenate_lq[2] = Fzo_prime_idx_1 * rtb_Add_bl[0] + SteerCmd *
      rtb_Saturation1_idx_0;

    /* Fcn: '<S396>/Fcn12' incorporates:
     *  Trigonometry: '<S396>/sincos'
     */
    rtb_VectorConcatenate_lq[3] = SteerCmd * rtb_Add_bl[1];

    /* Fcn: '<S396>/Fcn22' incorporates:
     *  Trigonometry: '<S396>/sincos'
     */
    rtb_VectorConcatenate_lq[4] = Fzo_prime_idx_0 * SteerCmd + rtb_Add_bl[0] *
      rtb_Add_bl[2];

    /* Fcn: '<S396>/Fcn32' incorporates:
     *  Trigonometry: '<S396>/sincos'
     */
    rtb_VectorConcatenate_lq[5] = Fzo_prime_idx_1 * SteerCmd - rtb_Add_bl[0] *
      rtb_Saturation1_idx_0;

    /* Fcn: '<S396>/Fcn13' incorporates:
     *  Trigonometry: '<S396>/sincos'
     */
    rtb_VectorConcatenate_lq[6] = -rtb_SumofElements15;

    /* Fcn: '<S396>/Fcn23' incorporates:
     *  Trigonometry: '<S396>/sincos'
     */
    rtb_VectorConcatenate_lq[7] = rtb_Add_bl[1] * rtb_Saturation1_idx_0;

    /* Fcn: '<S396>/Fcn33' */
    rtb_VectorConcatenate_lq[8] = rtb_Add_bl[1] * rtb_Add_bl[2];

    /* Math: '<S395>/Transpose' incorporates:
     *  Concatenate: '<S490>/Vector Concatenate'
     */
    for (i = 0; i < 3; i++) {
      rtb_Transpose[3 * i] = rtb_VectorConcatenate_lq[i];
      rtb_Transpose[3 * i + 1] = rtb_VectorConcatenate_lq[i + 3];
      rtb_Transpose[3 * i + 2] = rtb_VectorConcatenate_lq[i + 6];
    }

    /* End of Math: '<S395>/Transpose' */

    /* Product: '<S398>/Product' */
    for (i = 0; i < 3; i++) {
      /* Product: '<S487>/Product' incorporates:
       *  ForEachSliceAssignment generated from: '<S300>/VehM'
       *  ForEachSliceSelector generated from: '<S395>/Ms'
       *  Math: '<S395>/Transpose'
       *  Reshape: '<S292>/Reshape14'
       */
      rtb_Product_o0[i] = (rtb_ImpAsg_InsertedFor_VehM_at_[3 * ForEach_itr_n + 1]
                           * rtb_Transpose[i + 3] +
                           rtb_ImpAsg_InsertedFor_VehM_at_[3 * ForEach_itr_n] *
                           rtb_Transpose[i]) + rtb_ImpAsg_InsertedFor_VehM_at_[3
        * ForEach_itr_n + 2] * rtb_Transpose[i + 6];
    }

    /* End of Product: '<S398>/Product' */

    /* Product: '<S395>/Inertial to Body1' */
    SteerCmd = rtb_Product_o0[0];
    rtb_SumofElements15 = rtb_Product_o0[1];
    rtb_Saturation1_idx_0 = rtb_Product_o0[2];
    for (i = 0; i < 3; i++) {
      /* ForEachSliceAssignment generated from: '<S395>/MsB' incorporates:
       *  Product: '<S395>/Inertial to Body1'
       *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
       */
      iy = 3 * ForEach_itr_n + i;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] = 0.0;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i] *
        SteerCmd;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i + 3]
        * rtb_SumofElements15;
      rtb_ImpAsg_InsertedFor_MsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i + 6]
        * rtb_Saturation1_idx_0;

      /* Product: '<S397>/Product' incorporates:
       *  ForEachSliceSelector generated from: '<S395>/Fs'
       *  Math: '<S395>/Transpose'
       */
      rtb_sincos_o1[i] = (rtb_VectorConcatenate1[3 * ForEach_itr_n + 1] *
                          rtb_Transpose[i + 3] + rtb_VectorConcatenate1[3 *
                          ForEach_itr_n] * rtb_Transpose[i]) +
        rtb_VectorConcatenate1[3 * ForEach_itr_n + 2] * rtb_Transpose[i + 6];
    }

    /* Product: '<S397>/Product' incorporates:
     *  Product: '<S395>/Inertial to Body'
     */
    Vsy_0 = rtb_sincos_o1[0];
    rtb_Divide_ag = rtb_sincos_o1[1];
    rtb_SOC_CC = rtb_sincos_o1[2];

    /* ForEachSliceAssignment generated from: '<S395>/FsB' incorporates:
     *  Product: '<S395>/Inertial to Body'
     *  Product: '<S397>/Product'
     *  Reshape: '<S423>/Reshape (9) to [3x3] column-major'
     */
    for (i = 0; i < 3; i++) {
      iy = 3 * ForEach_itr_n + i;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] = 0.0;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i] *
        Vsy_0;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i + 3]
        * rtb_Divide_ag;
      rtb_ImpAsg_InsertedFor_FsB_at_i[iy] += rtb_Reshape9to3x3columnmajor[i + 6]
        * rtb_SOC_CC;
    }
  }

  /* End of Outputs for SubSystem: '<S391>/Susp2Body' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 6; i++) {
      /* Constant: '<S697>/Constant' */
      localB->Hitch[i] = localP->Constant_Value_bj[i];
    }

    /* Sum: '<S429>/Sum of Elements' */
    localB->SumofElements[0] = 0.0;
    localB->SumofElements[1] = 0.0;
    localB->SumofElements[2] = 0.0;
  }

  /* Sum: '<S407>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S407>/Product'
   *  Product: '<S431>/j x k'
   *  Product: '<S432>/k x j'
   *  Selector: '<S405>/Selector1'
   *  Sum: '<S400>/Sum'
   *  Sum: '<S405>/Sum of Elements'
   *  Sum: '<S415>/Sum'
   *  Sum: '<S416>/Sum'
   *  UnaryMinus: '<S391>/Unary Minus'
   */
  localB->Sum[0] = ((((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[3]) + rtb_ImpAsg_InsertedFor_FsB_at_i[6]) +
                       rtb_ImpAsg_InsertedFor_FsB_at_i[9]) +
                      ((-localB->VectorConcatenate_l[0] + rtb_Sum_c5[0]) -
                       rtb_Product_pm)) + localB->Hitch[0]) +
                    localB->SumofElements[0]) / localB->Mbar + (rtb_ubvbwb[1] *
    localX->pqr_CSTATE[2] - localX->pqr_CSTATE[1] * rtb_ubvbwb[2]);

  /* Sum: '<S405>/Sum of Elements1' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Selector: '<S405>/Selector2'
   *  Sum: '<S402>/Sum of Elements10'
   */
  rtb_SumofElements15 = rtb_ImpAsg_InsertedFor_FsB_at_i[1] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[4];

  /* Sum: '<S407>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S407>/Product'
   *  Product: '<S431>/k x i'
   *  Product: '<S432>/i x k'
   *  Selector: '<S405>/Selector2'
   *  Sum: '<S400>/Sum'
   *  Sum: '<S405>/Sum of Elements1'
   *  Sum: '<S415>/Sum'
   *  Sum: '<S416>/Sum'
   *  UnaryMinus: '<S391>/Unary Minus'
   */
  localB->Sum[1] = (((((rtb_SumofElements15 + rtb_ImpAsg_InsertedFor_FsB_at_i[7])
                       + rtb_ImpAsg_InsertedFor_FsB_at_i[10]) +
                      ((-localB->VectorConcatenate_l[1] + rtb_Sum_c5[1]) -
                       rtb_Product1_o_idx_1)) + localB->Hitch[1]) +
                    localB->SumofElements[1]) / localB->Mbar +
    (localX->pqr_CSTATE[0] * rtb_ubvbwb[2] - rtb_ubvbwb[0] * localX->pqr_CSTATE
     [2]);

  /* Sum: '<S405>/Sum of Elements2' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Selector: '<S405>/Selector3'
   *  Sum: '<S402>/Sum of Elements2'
   */
  rtb_Saturation1_idx_0 = rtb_ImpAsg_InsertedFor_FsB_at_i[2] +
    rtb_ImpAsg_InsertedFor_FsB_at_i[5];

  /* Sum: '<S407>/Sum' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S407>/Product'
   *  Product: '<S431>/i x j'
   *  Product: '<S432>/j x i'
   *  Selector: '<S405>/Selector3'
   *  Sum: '<S400>/Sum'
   *  Sum: '<S405>/Sum of Elements2'
   *  Sum: '<S415>/Sum'
   *  Sum: '<S416>/Sum'
   *  UnaryMinus: '<S391>/Unary Minus'
   */
  localB->Sum[2] = (((((rtb_Saturation1_idx_0 + rtb_ImpAsg_InsertedFor_FsB_at_i
                        [8]) + rtb_ImpAsg_InsertedFor_FsB_at_i[11]) +
                      ((-localB->VectorConcatenate_l[2] + rtb_Sum_c5[2]) -
                       rtb_DeadZone1)) + localB->Hitch[2]) +
                    localB->SumofElements[2]) / localB->Mbar + (rtb_ubvbwb[0] *
    localX->pqr_CSTATE[1] - localX->pqr_CSTATE[0] * rtb_ubvbwb[1]);

  /* Product: '<S393>/Divide' incorporates:
   *  Constant: '<S393>/Constant'
   *  Integrator: '<S393>/Integrator1'
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S391>/Product'
   *  Product: '<S391>/Product1'
   *  Sum: '<S391>/Add'
   *  Sum: '<S391>/Add1'
   *  Sum: '<S393>/Sum'
   *  UnitConversion: '<S411>/Unit Conversion1'
   */
  /* Unit Conversion - from: m/s^2 to: m/s^2
     Expression: output = (1*input) + (0) */
  localB->Divide_d[0] = ((localB->Sum[0] - localB->UnitConversion[1] *
    localX->pqr_CSTATE[2]) - localX->Integrator1_CSTATE_a[0]) *
    localP->Bushings_wc[0];
  localB->Divide_d[1] = ((localB->UnitConversion[0] * localX->pqr_CSTATE[2] +
    localB->Sum[1]) - localX->Integrator1_CSTATE_a[1]) * localP->Bushings_wc[1];

  /* Trigonometry: '<S422>/sincos' */
  rtb_Sum_c5[0] = std::sin(localB->phithetapsi[0]);
  rtb_Product_o0[0] = std::cos(localB->phithetapsi[0]);
  rtb_Product_o0[1] = std::cos(localB->phithetapsi[1]);

  /* Fcn: '<S422>/phidot' incorporates:
   *  Fcn: '<S422>/psidot'
   *  Integrator: '<S407>/p,q,r '
   */
  rtb_Saturation1_idx_1 = rtb_Sum_c5[0] * localX->pqr_CSTATE[1] +
    rtb_Product_o0[0] * localX->pqr_CSTATE[2];

  /* SignalConversion generated from: '<S413>/phi theta psi' incorporates:
   *  Fcn: '<S422>/phidot'
   *  Fcn: '<S422>/psidot'
   *  Fcn: '<S422>/thetadot'
   *  Integrator: '<S407>/p,q,r '
   *  Trigonometry: '<S422>/sincos'
   */
  localB->TmpSignalConversionAtphithetaps[0] = std::sin(localB->phithetapsi[1]) /
    rtb_Product_o0[1] * rtb_Saturation1_idx_1 + localX->pqr_CSTATE[0];
  localB->TmpSignalConversionAtphithetaps[1] = rtb_Product_o0[0] *
    localX->pqr_CSTATE[1] - rtb_Sum_c5[0] * localX->pqr_CSTATE[2];
  localB->TmpSignalConversionAtphithetaps[2] = rtb_Saturation1_idx_1 /
    rtb_Product_o0[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S415>/Matrix Concatenation' incorporates:
       *  Constant: '<S400>/Constant1'
       */
      rtb_Saturation1_idx_1 = rtb_Ibar[3 * i];
      rtb_MatrixConcatenation[6 * i] = rtb_Saturation1_idx_1;
      rtb_MatrixConcatenation[6 * i + 3] = localP->Constant1_Value_p[3 * i];

      /* Selector: '<S414>/Selector' */
      localB->Selector[3 * i] = rtb_Saturation1_idx_1;

      /* Concatenate: '<S415>/Matrix Concatenation' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Selector: '<S414>/Selector'
       */
      iy = 3 * i + 1;
      rtb_Saturation1_idx_1 = rtb_Ibar[iy];
      rtb_MatrixConcatenation[6 * i + 1] = rtb_Saturation1_idx_1;
      rtb_MatrixConcatenation[6 * i + 4] = localP->Constant1_Value_p[iy];

      /* Selector: '<S414>/Selector' */
      localB->Selector[iy] = rtb_Saturation1_idx_1;

      /* Concatenate: '<S415>/Matrix Concatenation' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Selector: '<S414>/Selector'
       */
      iy = 3 * i + 2;
      rtb_Saturation1_idx_1 = rtb_Ibar[iy];
      rtb_MatrixConcatenation[6 * i + 2] = rtb_Saturation1_idx_1;
      rtb_MatrixConcatenation[6 * i + 5] = localP->Constant1_Value_p[iy];

      /* Selector: '<S414>/Selector' */
      localB->Selector[iy] = rtb_Saturation1_idx_1;
    }
  }

  /* Integrator: '<S407>/p,q,r ' incorporates:
   *  Product: '<S425>/Product'
   */
  rtb_Saturation1_idx_1 = localX->pqr_CSTATE[1];
  rtb_Saturation1_idx_2 = localX->pqr_CSTATE[0];
  SteerCmd = localX->pqr_CSTATE[2];

  /* Product: '<S425>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S489>/Sum' incorporates:
     *  Integrator: '<S407>/p,q,r '
     *  Selector: '<S414>/Selector'
     */
    rtb_Sum_c5[i] = (localB->Selector[i + 3] * rtb_Saturation1_idx_1 +
                     localB->Selector[i] * rtb_Saturation1_idx_2) +
      localB->Selector[i + 6] * SteerCmd;
  }

  /* Product: '<S427>/j x k' */
  SteerCmd = rtb_Sum_c5[2];

  /* Product: '<S427>/k x i' */
  rtb_Saturation1_idx_1 = rtb_Sum_c5[0];

  /* Product: '<S427>/i x j' */
  rtb_Saturation1_idx_2 = rtb_Sum_c5[1];

  /* Product: '<S428>/k x j' */
  rtb_Integrator1_hl_idx_1 = rtb_Sum_c5[1];

  /* Product: '<S428>/i x k' */
  rtb_Integrator1_hl_idx_2 = rtb_Sum_c5[2];

  /* Product: '<S428>/j x i' */
  rtb_Integrator1_hl_idx_3 = rtb_Sum_c5[0];

  /* Sum: '<S424>/Sum' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S427>/i x j'
   *  Product: '<S427>/j x k'
   *  Product: '<S427>/k x i'
   *  Product: '<S428>/i x k'
   *  Product: '<S428>/j x i'
   *  Product: '<S428>/k x j'
   */
  rtb_Sum_c5[0] = localX->pqr_CSTATE[1] * SteerCmd - rtb_Integrator1_hl_idx_1 *
    localX->pqr_CSTATE[2];
  rtb_Sum_c5[1] = rtb_Saturation1_idx_1 * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * rtb_Integrator1_hl_idx_2;
  rtb_Sum_c5[2] = localX->pqr_CSTATE[0] * rtb_Saturation1_idx_2 -
    rtb_Integrator1_hl_idx_3 * localX->pqr_CSTATE[1];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S414>/Selector1' incorporates:
       *  Concatenate: '<S415>/Matrix Concatenation'
       */
      localB->Selector1_nm[3 * i] = rtb_MatrixConcatenation[6 * i + 3];
      localB->Selector1_nm[3 * i + 1] = rtb_MatrixConcatenation[6 * i + 4];
      localB->Selector1_nm[3 * i + 2] = rtb_MatrixConcatenation[6 * i + 5];
    }

    /* Sum: '<S448>/Sum1' incorporates:
     *  Constant: '<S448>/Constant1'
     *  Constant: '<S450>/Constant1'
     */
    rtb_Product2_lv = (ConfiguredVirtualVehicleModel_P->PlntVehCGHgtAxl -
                       localB->Rbar[2]) -
      ConfiguredVirtualVehicleModel_P->PlntVehHtchHgtAxl;

    /* Sum: '<S448>/Sum3' incorporates:
     *  Constant: '<S448>/Constant'
     *  Constant: '<S450>/Constant2'
     */
    rtb_Sum3_l = (localP->VehicleBody6DOF_hl - localP->VehicleBody6DOF_d) -
      localB->Rbar[1];

    /* Sum: '<S448>/Mx' incorporates:
     *  Product: '<S448>/Product4'
     *  Product: '<S448>/Product5'
     */
    localB->Mx = rtb_Sum3_l * localB->Hitch[2] - rtb_Product2_lv * localB->
      Hitch[1];

    /* Sum: '<S448>/Sum4' incorporates:
     *  Constant: '<S450>/Constant'
     */
    rtb_Sum4_d = ConfiguredVirtualVehicleModel_P->PlntVehHtchDst + localB->Rbar
      [0];

    /* Sum: '<S448>/My' incorporates:
     *  Product: '<S448>/Product'
     *  Product: '<S448>/Product3'
     */
    localB->My = rtb_Product2_lv * localB->Hitch[0] + localB->Hitch[2] *
      rtb_Sum4_d;
  }

  /* Sum: '<S402>/Sum of Elements6' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Product: '<S402>/Product1'
   *  Product: '<S402>/Product2'
   *  Selector: '<S405>/Selector2'
   *  Selector: '<S405>/Selector3'
   *  Sum: '<S402>/Sum of Elements1'
   *  Sum: '<S402>/Sum of Elements15'
   */
  rtb_Add_bl[0] = (localB->Mx - (((localB->Wbar[0] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[2] - localB->Wbar[1] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[5]) + localB->Wbar[2] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[8]) - localB->Wbar[3] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[11])) - (((rtb_ImpAsg_InsertedFor_FsB_at_i[1]
    * localB->Xbar[2] + localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[4]) +
    localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[7]) + localB->Xbar[2] *
    rtb_ImpAsg_InsertedFor_FsB_at_i[10]);

  /* Sum: '<S402>/Sum of Elements9' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Product: '<S402>/Product'
   *  Product: '<S402>/Product4'
   *  Product: '<S402>/Product5'
   *  Selector: '<S405>/Selector1'
   *  Selector: '<S405>/Selector3'
   *  Sum: '<S402>/Sum of Elements16'
   *  Sum: '<S402>/Sum of Elements3'
   *  Sum: '<S402>/Sum of Elements4'
   */
  rtb_Add_bl[1] = ((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] * localB->Xbar[2] +
                      localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[3]) +
                     localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[6]) +
                    localB->Xbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[9]) +
                   ((rtb_ImpAsg_InsertedFor_FsB_at_i[8] +
                     rtb_ImpAsg_InsertedFor_FsB_at_i[11]) * localB->Xbar[1] -
                    rtb_Saturation1_idx_0 * localB->Xbar[0])) + localB->My;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S448>/Mz' incorporates:
     *  Product: '<S448>/Product1'
     *  Product: '<S448>/Product2'
     */
    localB->Mz = (0.0 - localB->Hitch[0] * rtb_Sum3_l) - localB->Hitch[1] *
      rtb_Sum4_d;
    for (i = 0; i < 3; i++) {
      /* Selector: '<S414>/Selector2' incorporates:
       *  Concatenate: '<S415>/Matrix Concatenation'
       */
      localB->Selector2[3 * i] = rtb_MatrixConcatenation[6 * i];
      localB->Selector2[3 * i + 1] = rtb_MatrixConcatenation[6 * i + 1];
      localB->Selector2[3 * i + 2] = rtb_MatrixConcatenation[6 * i + 2];
    }
  }

  /* Sum: '<S402>/Sum of Elements5' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/FsB'
   *  Product: '<S402>/Product3'
   *  Product: '<S402>/Product6'
   *  Product: '<S402>/Product7'
   *  Selector: '<S405>/Selector1'
   *  Selector: '<S405>/Selector2'
   *  Sum: '<S402>/Sum of Elements11'
   *  Sum: '<S402>/Sum of Elements7'
   *  Sum: '<S402>/Sum of Elements8'
   */
  rtb_Add_bl[2] = ((((rtb_ImpAsg_InsertedFor_FsB_at_i[0] * localB->Wbar[0] -
                      localB->Wbar[1] * rtb_ImpAsg_InsertedFor_FsB_at_i[3]) +
                     localB->Wbar[2] * rtb_ImpAsg_InsertedFor_FsB_at_i[6]) -
                    localB->Wbar[3] * rtb_ImpAsg_InsertedFor_FsB_at_i[9]) +
                   (rtb_SumofElements15 * localB->Xbar[0] -
                    (rtb_ImpAsg_InsertedFor_FsB_at_i[7] +
                     rtb_ImpAsg_InsertedFor_FsB_at_i[10]) * localB->Xbar[1])) +
    localB->Mz;

  /* Sum: '<S412>/Sum of Elements' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/MsB'
   *  Selector: '<S412>/Selector1'
   */
  rtb_VectorConcatenate_d[0] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[0] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[3]) + rtb_ImpAsg_InsertedFor_MsB_at_i[6]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[9];

  /* Sum: '<S412>/Sum of Elements1' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/MsB'
   *  Selector: '<S412>/Selector2'
   */
  rtb_VectorConcatenate_d[1] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[1] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[4]) + rtb_ImpAsg_InsertedFor_MsB_at_i[7]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[10];

  /* Sum: '<S412>/Sum of Elements2' incorporates:
   *  ForEachSliceAssignment generated from: '<S395>/MsB'
   *  Selector: '<S412>/Selector3'
   */
  rtb_VectorConcatenate_d[2] = ((rtb_ImpAsg_InsertedFor_MsB_at_i[2] +
    rtb_ImpAsg_InsertedFor_MsB_at_i[5]) + rtb_ImpAsg_InsertedFor_MsB_at_i[8]) +
    rtb_ImpAsg_InsertedFor_MsB_at_i[11];

  /* Integrator: '<S407>/p,q,r ' incorporates:
   *  Product: '<S426>/Product'
   */
  rtb_Saturation1_idx_1 = localX->pqr_CSTATE[1];
  rtb_Saturation1_idx_2 = localX->pqr_CSTATE[0];
  SteerCmd = localX->pqr_CSTATE[2];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S414>/Sum2' incorporates:
     *  Integrator: '<S407>/p,q,r '
     *  Product: '<S426>/Product'
     *  Product: '<S434>/Product4'
     *  Selector: '<S414>/Selector1'
     *  Sum: '<S400>/Add'
     */
    rtb_ubvbwb[i] = (((((rtb_Add_bl[i] + localB->Constant1[i]) +
                        rtb_VectorConcatenate_d[i]) - rtb_Abs_j[i + 3] *
                       rtb_Integrator1_hl_idx_0) + localB->Hitch[i + 3]) -
                     ((localB->Selector1_nm[i + 3] * rtb_Saturation1_idx_1 +
                       localB->Selector1_nm[i] * rtb_Saturation1_idx_2) +
                      localB->Selector1_nm[i + 6] * SteerCmd)) - rtb_Sum_c5[i];
  }

  /* Product: '<S414>/Product2' incorporates:
   *  Selector: '<S414>/Selector2'
   */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(rtb_ubvbwb, localB->Selector2,
    localB->Product2);

  /* Trigonometry: '<S437>/sincos' */
  rtb_SumofElements15 = rty_VehFdbk[0];
  rtb_Switch1_f[0] = std::sin(rtb_SumofElements15);
  rtb_Sum_c5[0] = std::cos(rtb_SumofElements15);
  rtb_SumofElements15 = rty_VehFdbk[1];
  rtb_Sum_c5[1] = std::cos(rtb_SumofElements15);

  /* Fcn: '<S437>/thetadot' incorporates:
   *  Integrator: '<S407>/p,q,r '
   */
  rtb_Divide_ag = rtb_Sum_c5[0] * localX->pqr_CSTATE[1] - rtb_Switch1_f[0] *
    localX->pqr_CSTATE[2];

  /* Fcn: '<S437>/psidot' incorporates:
   *  Fcn: '<S437>/phidot'
   *  Integrator: '<S407>/p,q,r '
   */
  rtb_Saturation1_idx_0 = rtb_Switch1_f[0] * localX->pqr_CSTATE[1] + rtb_Sum_c5
    [0] * localX->pqr_CSTATE[2];
  rtb_DeadZone1 = rtb_Saturation1_idx_0 / rtb_Sum_c5[1];

  /* Fcn: '<S437>/phidot' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Trigonometry: '<S437>/sincos'
   */
  rtb_SOC_CC = std::sin(rtb_SumofElements15) / rtb_Sum_c5[1] *
    rtb_Saturation1_idx_0 + localX->pqr_CSTATE[0];

  /* UnitConversion: '<S411>/Unit Conversion3' incorporates:
   *  Product: '<S446>/i x j'
   *  Product: '<S446>/j x k'
   *  Product: '<S446>/k x i'
   *  Product: '<S447>/i x k'
   *  Product: '<S447>/j x i'
   *  Product: '<S447>/k x j'
   *  Sum: '<S411>/Add'
   *  Sum: '<S438>/Sum'
   */
  /* Unit Conversion - from: rad/s^2 to: rad/s^2
     Expression: output = (1*input) + (0) */
  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  rtb_Switch1_f[0] = ((rtb_Divide_ag * localB->UnitConversion[2] - rtb_DeadZone1
                       * localB->UnitConversion[1]) + localB->Sum[0]) *
    0.10197162129779282;
  rtb_Switch1_f[1] = ((rtb_DeadZone1 * localB->UnitConversion[0] - rtb_SOC_CC *
                       localB->UnitConversion[2]) + localB->Sum[1]) *
    0.10197162129779282;
  rtb_Switch1_f[2] = ((rtb_SOC_CC * localB->UnitConversion[1] - rtb_Divide_ag *
                       localB->UnitConversion[0]) + localB->Sum[2]) *
    0.10197162129779282;

  /* Product: '<S476>/Product' incorporates:
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S483>/i x j'
   *  Product: '<S483>/j x k'
   *  Product: '<S483>/k x i'
   *  Product: '<S484>/i x k'
   *  Product: '<S484>/j x i'
   *  Product: '<S484>/k x j'
   *  Sum: '<S478>/Sum'
   */
  rtb_Saturation1_idx_0 = localX->pqr_CSTATE[1] * localB->Subtract[2] -
    localB->Subtract[1] * localX->pqr_CSTATE[2];
  rtb_SumofElements15 = localB->Subtract[0] * localX->pqr_CSTATE[2] -
    localX->pqr_CSTATE[0] * localB->Subtract[2];
  rtb_Saturation1_idx_1 = localX->pqr_CSTATE[0] * localB->Subtract[1] -
    localB->Subtract[0] * localX->pqr_CSTATE[1];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S473>/Add4' incorporates:
     *  Math: '<S485>/Transpose1'
     *  UnitConversion: '<S418>/Unit Conversion'
     */
    localB->V_wb[i] = ((rtb_Transpose1[i + 3] * rtb_SumofElements15 +
                        rtb_Transpose1[i] * rtb_Saturation1_idx_0) +
                       rtb_Transpose1[i + 6] * rtb_Saturation1_idx_1) +
      localB->Product_k[i];
  }

  /* End of Product: '<S476>/Product' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<S454>/Vector Concatenate' incorporates:
     *  Concatenate: '<S454>/Vector Concatenate'
     */
    localB->VectorConcatenate_p[1] = rtb_Sum3_l;

    /* SignalConversion generated from: '<S454>/Vector Concatenate' incorporates:
     *  Concatenate: '<S454>/Vector Concatenate'
     */
    localB->VectorConcatenate_p[2] = rtb_Product2_lv;

    /* UnaryMinus: '<S454>/Unary Minus2' incorporates:
     *  Concatenate: '<S454>/Vector Concatenate'
     */
    localB->VectorConcatenate_p[0] = -rtb_Sum4_d;
  }

  /* Product: '<S517>/Product2' incorporates:
   *  Product: '<S518>/Product2'
   */
  rtb_SumofElements15 = rtb_ImpAsg_InsertedFor_Omega_at[0] * localB->Re[0];

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_x[0] > localP->Saturation1_UpperSat) {
    Vsy_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[0] < localP->Saturation1_LowerSat) {
    Vsy_0 = localP->Saturation1_LowerSat;
  } else {
    Vsy_0 = rtb_sig_x[0];
  }

  /* Abs: '<S517>/Abs' incorporates:
   *  Abs: '<S520>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Product: '<S517>/Product2'
   *  Reshape: '<S376>/Reshape1'
   *  Sum: '<S517>/Add1'
   */
  rtb_Product2_lv = std::abs(rtb_ImpAsg_InsertedFor_xdotWhee[0] -
    rtb_SumofElements15);

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_n) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_n;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_g) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_g;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1[0] = (lam_mux[0] - localB->Integrator[0]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S518>/Saturation1' */
  if (rtb_sig_y[0] > localP->Saturation1_UpperSat_e) {
    Vsy_0 = localP->Saturation1_UpperSat_e;
  } else if (rtb_sig_y[0] < localP->Saturation1_LowerSat_h) {
    Vsy_0 = localP->Saturation1_LowerSat_h;
  } else {
    Vsy_0 = rtb_sig_y[0];
  }

  /* Product: '<S518>/Product3' incorporates:
   *  Abs: '<S518>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/ydotWheel'
   *  Product: '<S518>/Product2'
   *  Reshape: '<S376>/Reshape2'
   *  Saturate: '<S518>/Saturation1'
   *  Sum: '<S518>/Add1'
   */
  rtb_Product1_o_idx_3 = std::abs(rtb_ImpAsg_InsertedFor_ydotWhee[0] -
    rtb_SumofElements15) / Vsy_0;

  /* Saturate: '<S518>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_o) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_o;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_m;
  }

  /* Product: '<S518>/Product1' incorporates:
   *  Saturate: '<S518>/Saturation'
   *  Sum: '<S518>/Add'
   */
  localB->Product1_i[0] = (Gykappa[0] - localB->Integrator_h[0]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S520>/Saturation1' incorporates:
   *  Saturate: '<S517>/Saturation1'
   */
  if (rtb_sig_x[0] > localP->Saturation1_UpperSat_i) {
    Vsy_0 = localP->Saturation1_UpperSat_i;
  } else if (rtb_sig_x[0] < localP->Saturation1_LowerSat_i) {
    Vsy_0 = localP->Saturation1_LowerSat_i;
  } else {
    Vsy_0 = rtb_sig_x[0];
  }

  /* Product: '<S520>/Product3' incorporates:
   *  Saturate: '<S520>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_m;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_f) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_f;
  }

  /* Product: '<S520>/Product1' incorporates:
   *  Saturate: '<S520>/Saturation'
   *  Sum: '<S520>/Add'
   */
  localB->Product1_j[0] = (rtb_My[0] - rtb_Integrator_ks_idx_0) *
    rtb_Product1_o_idx_3;

  /* Switch: '<S521>/Switch' incorporates:
   *  Constant: '<S521>/Constant'
   */
  if (!(rtb_Sum6_idx_0 > localP->Switch_Threshold_bz)) {
    rtb_Switch_bk_idx_0 = localP->Constant_Value_g;
  }

  /* Gain: '<S521>/Gain1' incorporates:
   *  Constant: '<S521>/Fg'
   *  Gain: '<S521>/Gain2'
   *  SignalConversion: '<S513>/Signal Copy'
   *  Sum: '<S521>/Sum2'
   *  Switch: '<S521>/Switch'
   */
  localB->Gain1[0] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
                        ConfiguredVirtualVehicleModel_P->PlntWhlMass[0] +
                        rtb_VectorConcatenate_j[0]) -
                       rtb_UnitConversion_gd_idx_0) -
                      ConfiguredVirtualVehicleModel_P->PlntWhlVertDampCoeff[0] *
                      rtb_Switch_bk_idx_0) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntWhlMass[0]);

  /* Product: '<S517>/Product2' incorporates:
   *  Product: '<S518>/Product2'
   */
  rtb_SumofElements15 = rtb_ImpAsg_InsertedFor_Omega_at[1] * localB->Re[1];

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_x[1] > localP->Saturation1_UpperSat) {
    Vsy_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[1] < localP->Saturation1_LowerSat) {
    Vsy_0 = localP->Saturation1_LowerSat;
  } else {
    Vsy_0 = rtb_sig_x[1];
  }

  /* Abs: '<S517>/Abs' incorporates:
   *  Abs: '<S520>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Product: '<S517>/Product2'
   *  Reshape: '<S376>/Reshape1'
   *  Sum: '<S517>/Add1'
   */
  rtb_Product2_lv = std::abs(rtb_ImpAsg_InsertedFor_xdotWhee[1] -
    rtb_SumofElements15);

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_n) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_n;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_g) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_g;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1[1] = (lam_mux[1] - localB->Integrator[1]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S518>/Saturation1' */
  if (rtb_sig_y[1] > localP->Saturation1_UpperSat_e) {
    Vsy_0 = localP->Saturation1_UpperSat_e;
  } else if (rtb_sig_y[1] < localP->Saturation1_LowerSat_h) {
    Vsy_0 = localP->Saturation1_LowerSat_h;
  } else {
    Vsy_0 = rtb_sig_y[1];
  }

  /* Product: '<S518>/Product3' incorporates:
   *  Abs: '<S518>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/ydotWheel'
   *  Product: '<S518>/Product2'
   *  Reshape: '<S376>/Reshape2'
   *  Saturate: '<S518>/Saturation1'
   *  Sum: '<S518>/Add1'
   */
  rtb_Product1_o_idx_3 = std::abs(rtb_ImpAsg_InsertedFor_ydotWhee[1] -
    rtb_SumofElements15) / Vsy_0;

  /* Saturate: '<S518>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_o) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_o;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_m;
  }

  /* Product: '<S518>/Product1' incorporates:
   *  Saturate: '<S518>/Saturation'
   *  Sum: '<S518>/Add'
   */
  localB->Product1_i[1] = (Gykappa[1] - localB->Integrator_h[1]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S520>/Saturation1' incorporates:
   *  Saturate: '<S517>/Saturation1'
   */
  if (rtb_sig_x[1] > localP->Saturation1_UpperSat_i) {
    Vsy_0 = localP->Saturation1_UpperSat_i;
  } else if (rtb_sig_x[1] < localP->Saturation1_LowerSat_i) {
    Vsy_0 = localP->Saturation1_LowerSat_i;
  } else {
    Vsy_0 = rtb_sig_x[1];
  }

  /* Product: '<S520>/Product3' incorporates:
   *  Saturate: '<S520>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_m;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_f) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_f;
  }

  /* Product: '<S520>/Product1' incorporates:
   *  Saturate: '<S520>/Saturation'
   *  Sum: '<S520>/Add'
   */
  localB->Product1_j[1] = (rtb_My[1] - rtb_Integrator_ks_idx_1) *
    rtb_Product1_o_idx_3;

  /* Switch: '<S521>/Switch' incorporates:
   *  Constant: '<S521>/Constant'
   */
  if (!(rtb_Sum6_idx_1 > localP->Switch_Threshold_bz)) {
    rtb_Switch_bk_idx_1 = localP->Constant_Value_g;
  }

  /* Gain: '<S521>/Gain1' incorporates:
   *  Constant: '<S521>/Fg'
   *  Gain: '<S521>/Gain2'
   *  SignalConversion: '<S513>/Signal Copy'
   *  Sum: '<S521>/Sum2'
   *  Switch: '<S521>/Switch'
   */
  localB->Gain1[1] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
                        ConfiguredVirtualVehicleModel_P->PlntWhlMass[1] +
                        rtb_VectorConcatenate_j[1]) -
                       rtb_UnitConversion_gd_idx_1) -
                      ConfiguredVirtualVehicleModel_P->PlntWhlVertDampCoeff[1] *
                      rtb_Switch_bk_idx_1) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntWhlMass[1]);

  /* Product: '<S517>/Product2' incorporates:
   *  Product: '<S518>/Product2'
   */
  rtb_SumofElements15 = rtb_ImpAsg_InsertedFor_Omega_at[2] * localB->Re[2];

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_x[2] > localP->Saturation1_UpperSat) {
    Vsy_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[2] < localP->Saturation1_LowerSat) {
    Vsy_0 = localP->Saturation1_LowerSat;
  } else {
    Vsy_0 = rtb_sig_x[2];
  }

  /* Abs: '<S517>/Abs' incorporates:
   *  Abs: '<S520>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Product: '<S517>/Product2'
   *  Reshape: '<S376>/Reshape1'
   *  Sum: '<S517>/Add1'
   */
  rtb_Product2_lv = std::abs(rtb_ImpAsg_InsertedFor_xdotWhee[2] -
    rtb_SumofElements15);

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_n) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_n;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_g) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_g;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1[2] = (lam_mux[2] - localB->Integrator[2]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S518>/Saturation1' */
  if (rtb_sig_y[2] > localP->Saturation1_UpperSat_e) {
    Vsy_0 = localP->Saturation1_UpperSat_e;
  } else if (rtb_sig_y[2] < localP->Saturation1_LowerSat_h) {
    Vsy_0 = localP->Saturation1_LowerSat_h;
  } else {
    Vsy_0 = rtb_sig_y[2];
  }

  /* Product: '<S518>/Product3' incorporates:
   *  Abs: '<S518>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/ydotWheel'
   *  Product: '<S518>/Product2'
   *  Reshape: '<S376>/Reshape2'
   *  Saturate: '<S518>/Saturation1'
   *  Sum: '<S518>/Add1'
   */
  rtb_Product1_o_idx_3 = std::abs(rtb_ImpAsg_InsertedFor_ydotWhee[2] -
    rtb_SumofElements15) / Vsy_0;

  /* Saturate: '<S518>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_o) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_o;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_m;
  }

  /* Product: '<S518>/Product1' incorporates:
   *  Saturate: '<S518>/Saturation'
   *  Sum: '<S518>/Add'
   */
  localB->Product1_i[2] = (Gykappa[2] - localB->Integrator_h[2]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S520>/Saturation1' incorporates:
   *  Saturate: '<S517>/Saturation1'
   */
  if (rtb_sig_x[2] > localP->Saturation1_UpperSat_i) {
    Vsy_0 = localP->Saturation1_UpperSat_i;
  } else if (rtb_sig_x[2] < localP->Saturation1_LowerSat_i) {
    Vsy_0 = localP->Saturation1_LowerSat_i;
  } else {
    Vsy_0 = rtb_sig_x[2];
  }

  /* Product: '<S520>/Product3' incorporates:
   *  Saturate: '<S520>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_m;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_f) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_f;
  }

  /* Product: '<S520>/Product1' incorporates:
   *  Saturate: '<S520>/Saturation'
   *  Sum: '<S520>/Add'
   */
  localB->Product1_j[2] = (rtb_My[2] - rtb_Integrator_ks_idx_2) *
    rtb_Product1_o_idx_3;

  /* Switch: '<S521>/Switch' incorporates:
   *  Constant: '<S521>/Constant'
   */
  if (!(rtb_Sum6_idx_2 > localP->Switch_Threshold_bz)) {
    rtb_Switch_bk_idx_2 = localP->Constant_Value_g;
  }

  /* Gain: '<S521>/Gain1' incorporates:
   *  Constant: '<S521>/Fg'
   *  Gain: '<S521>/Gain2'
   *  SignalConversion: '<S513>/Signal Copy'
   *  Sum: '<S521>/Sum2'
   *  Switch: '<S521>/Switch'
   */
  localB->Gain1[2] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
                        ConfiguredVirtualVehicleModel_P->PlntWhlMass[2] +
                        rtb_VectorConcatenate_j[2]) -
                       rtb_UnitConversion_gd_idx_2) -
                      ConfiguredVirtualVehicleModel_P->PlntWhlVertDampCoeff[2] *
                      rtb_Switch_bk_idx_2) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntWhlMass[2]);

  /* Product: '<S517>/Product2' incorporates:
   *  Product: '<S518>/Product2'
   */
  rtb_SumofElements15 = rtb_ImpAsg_InsertedFor_Omega_at[3] * localB->Re[3];

  /* Saturate: '<S517>/Saturation1' */
  if (rtb_sig_x[3] > localP->Saturation1_UpperSat) {
    Vsy_0 = localP->Saturation1_UpperSat;
  } else if (rtb_sig_x[3] < localP->Saturation1_LowerSat) {
    Vsy_0 = localP->Saturation1_LowerSat;
  } else {
    Vsy_0 = rtb_sig_x[3];
  }

  /* Abs: '<S517>/Abs' incorporates:
   *  Abs: '<S520>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/xdotWheel'
   *  Product: '<S517>/Product2'
   *  Reshape: '<S376>/Reshape1'
   *  Sum: '<S517>/Add1'
   */
  rtb_Product2_lv = std::abs(rtb_ImpAsg_InsertedFor_xdotWhee[3] -
    rtb_SumofElements15);

  /* Product: '<S517>/Product3' incorporates:
   *  Abs: '<S517>/Abs'
   *  Saturate: '<S517>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S517>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_n) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_n;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_g) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_g;
  }

  /* Product: '<S517>/Product1' incorporates:
   *  Saturate: '<S517>/Saturation'
   *  Sum: '<S517>/Add'
   */
  localB->Product1[3] = (lam_mux[3] - localB->Integrator[3]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S518>/Saturation1' */
  if (rtb_sig_y[3] > localP->Saturation1_UpperSat_e) {
    Vsy_0 = localP->Saturation1_UpperSat_e;
  } else if (rtb_sig_y[3] < localP->Saturation1_LowerSat_h) {
    Vsy_0 = localP->Saturation1_LowerSat_h;
  } else {
    Vsy_0 = rtb_sig_y[3];
  }

  /* Product: '<S518>/Product3' incorporates:
   *  Abs: '<S518>/Abs'
   *  ForEachSliceAssignment generated from: '<S378>/ydotWheel'
   *  Product: '<S518>/Product2'
   *  Reshape: '<S376>/Reshape2'
   *  Saturate: '<S518>/Saturation1'
   *  Sum: '<S518>/Add1'
   */
  rtb_Product1_o_idx_3 = std::abs(rtb_ImpAsg_InsertedFor_ydotWhee[3] -
    rtb_SumofElements15) / Vsy_0;

  /* Saturate: '<S518>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_o) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_o;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_m;
  }

  /* Product: '<S518>/Product1' incorporates:
   *  Saturate: '<S518>/Saturation'
   *  Sum: '<S518>/Add'
   */
  localB->Product1_i[3] = (Gykappa[3] - localB->Integrator_h[3]) *
    rtb_Product1_o_idx_3;

  /* Saturate: '<S520>/Saturation1' incorporates:
   *  Saturate: '<S517>/Saturation1'
   */
  if (rtb_sig_x[3] > localP->Saturation1_UpperSat_i) {
    Vsy_0 = localP->Saturation1_UpperSat_i;
  } else if (rtb_sig_x[3] < localP->Saturation1_LowerSat_i) {
    Vsy_0 = localP->Saturation1_LowerSat_i;
  } else {
    Vsy_0 = rtb_sig_x[3];
  }

  /* Product: '<S520>/Product3' incorporates:
   *  Saturate: '<S520>/Saturation1'
   */
  rtb_Product1_o_idx_3 = rtb_Product2_lv / Vsy_0;

  /* Saturate: '<S520>/Saturation' */
  if (rtb_Product1_o_idx_3 > localP->Saturation_UpperSat_m) {
    rtb_Product1_o_idx_3 = localP->Saturation_UpperSat_m;
  } else if (rtb_Product1_o_idx_3 < localP->Saturation_LowerSat_f) {
    rtb_Product1_o_idx_3 = localP->Saturation_LowerSat_f;
  }

  /* Product: '<S520>/Product1' incorporates:
   *  Saturate: '<S520>/Saturation'
   *  Sum: '<S520>/Add'
   */
  localB->Product1_j[3] = (rtb_My[3] - rtb_Integrator_ks_idx_3) *
    rtb_Product1_o_idx_3;

  /* Switch: '<S521>/Switch' incorporates:
   *  Constant: '<S521>/Constant'
   *  Sum: '<S521>/Sum6'
   */
  if (!(rtb_Sum6_0 > localP->Switch_Threshold_bz)) {
    rtb_Switch_bk_idx_3 = localP->Constant_Value_g;
  }

  /* Gain: '<S521>/Gain1' incorporates:
   *  Constant: '<S521>/Fg'
   *  Gain: '<S521>/Gain2'
   *  Saturate: '<S287>/Saturation'
   *  SignalConversion: '<S513>/Signal Copy'
   *  Sum: '<S521>/Sum2'
   *  Switch: '<S521>/Switch'
   */
  localB->Gain1[3] = (((localP->CombinedSlipWheel2DOF_GRAVITY *
                        ConfiguredVirtualVehicleModel_P->PlntWhlMass[3] +
                        rtb_VectorConcatenate_j[3]) -
                       rtb_UnitConversion_gd_idx_3) -
                      ConfiguredVirtualVehicleModel_P->PlntWhlVertDampCoeff[3] *
                      rtb_Switch_bk_idx_3) * (1.0 /
    ConfiguredVirtualVehicleModel_P->PlntWhlMass[3]);
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S602>/Memory' */
    localB->Memory_m = localDW->Memory_PreviousInput_l;

    /* Constant: '<S601>/domega_o' */
    localB->domega_o_n = ConfiguredVirtualVehicleModel_P->PlntDriveshftInitVel;
  }

  /* Integrator: '<S602>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&(&ConfiguredVirtualVehicleMode_M)->solverInfo))
  {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->Integrator_Reset_ZCE_d,
                       (localB->Memory_m));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (localDW->Integrator_IWORK_g != 0)) {
      localX->Integrator_CSTATE_n = localB->domega_o_n;
    }
  }

  /* Sum: '<S601>/Subtract1' incorporates:
   *  Gain: '<S601>/Gain1'
   *  Gain: '<S601>/Gain2'
   *  Integrator: '<S601>/Integrator'
   *  Integrator: '<S602>/Integrator'
   */
  rtb_UnaryMinus2_idx_1 = ConfiguredVirtualVehicleModel_P->PlntDriveshftDamp *
    localX->Integrator_CSTATE_n +
    ConfiguredVirtualVehicleModel_P->PlntDriveshftStiff *
    localX->Integrator_CSTATE_e0;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S557>/Switch' incorporates:
     *  Constant: '<S557>/Constant'
     */
    if (localP->Constant_Value_n > localP->Switch_Threshold_e) {
      /* Switch: '<S557>/Switch' incorporates:
       *  Constant: '<S557>/Constant1'
       */
      localB->diffDir = localP->Constant1_Value_fd;
    } else {
      /* Switch: '<S557>/Switch' incorporates:
       *  Constant: '<S557>/Constant1'
       *  UnaryMinus: '<S557>/Unary Minus'
       */
      localB->diffDir = -localP->Constant1_Value_fd;
    }

    /* End of Switch: '<S557>/Switch' */

    /* Constant: '<S553>/Constant' incorporates:
     *  Concatenate: '<S553>/Vector Concatenate'
     */
    localB->VectorConcatenate_n[0] =
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl1InitVel;

    /* Constant: '<S553>/Constant1' incorporates:
     *  Concatenate: '<S553>/Vector Concatenate'
     */
    localB->VectorConcatenate_n[1] =
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl2InitVel;
  }

  /* Integrator: '<S553>/Integrator' */
  /* Limited  Integrator  */
  if (localDW->Integrator_IWORK_d != 0) {
    localX->Integrator_CSTATE_d[0] = localB->VectorConcatenate_n[0];
    localX->Integrator_CSTATE_d[1] = localB->VectorConcatenate_n[1];
  }

  /* Gain: '<S557>/Gain' */
  rtb_Product_pm = ConfiguredVirtualVehicleModel_P->PlntDiffrntlRatio / 2.0;

  /* Integrator: '<S553>/Integrator' */
  rtb_UnitConversion_gd_idx_0 = localX->Integrator_CSTATE_d[0];
  if (localX->Integrator_CSTATE_d[0] >= localP->Integrator_UpperSat_i) {
    rtb_UnitConversion_gd_idx_0 = localP->Integrator_UpperSat_i;
    localX->Integrator_CSTATE_d[0] = localP->Integrator_UpperSat_i;
  } else if (localX->Integrator_CSTATE_d[0] <= localP->Integrator_LowerSat_h) {
    rtb_UnitConversion_gd_idx_0 = localP->Integrator_LowerSat_h;
    localX->Integrator_CSTATE_d[0] = localP->Integrator_LowerSat_h;
  }

  /* Gain: '<S557>/Gain' incorporates:
   *  Integrator: '<S553>/Integrator'
   *  Product: '<S557>/Product'
   */
  rtb_Product1_o_idx_3 = localB->diffDir * rtb_UnitConversion_gd_idx_0 *
    rtb_Product_pm;

  /* Integrator: '<S553>/Integrator' */
  rtb_UnitConversion_gd_idx_0 = localX->Integrator_CSTATE_d[1];
  if (localX->Integrator_CSTATE_d[1] >= localP->Integrator_UpperSat_i) {
    rtb_UnitConversion_gd_idx_0 = localP->Integrator_UpperSat_i;
    localX->Integrator_CSTATE_d[1] = localP->Integrator_UpperSat_i;
  } else if (localX->Integrator_CSTATE_d[1] <= localP->Integrator_LowerSat_h) {
    rtb_UnitConversion_gd_idx_0 = localP->Integrator_LowerSat_h;
    localX->Integrator_CSTATE_d[1] = localP->Integrator_LowerSat_h;
  }

  /* Sum: '<S557>/Sum of Elements' incorporates:
   *  Gain: '<S557>/Gain'
   *  Integrator: '<S553>/Integrator'
   *  Product: '<S557>/Product'
   */
  rtb_DeadZone1 = localB->diffDir * rtb_UnitConversion_gd_idx_0 * rtb_Product_pm
    + rtb_Product1_o_idx_3;

  /* Gain: '<S574>/Gain' incorporates:
   *  Abs: '<S573>/Abs'
   *  Constant: '<S574>/Constant1'
   *  Gain: '<S574>/Gain1'
   *  Gain: '<S574>/Gain2'
   *  SignalConversion generated from: '<S557>/Vector Concatenate'
   *  Sum: '<S574>/Subtract1'
   *  Sum: '<S574>/Subtract2'
   *  Trigonometry: '<S574>/Trigonometric Function'
   */
  rtb_SOC_CC = (std::tanh((localP->Gain1_Gain_d * std::abs(rtb_DeadZone1) -
    localP->Constant1_Value_cj) * localP->Gain2_Gain) +
                localP->Constant1_Value_cj) * localP->Gain_Gain_du;

  /* Switch: '<S567>/Switch' incorporates:
   *  Constant: '<S567>/Constant'
   *  Constant: '<S575>/Constant'
   *  Product: '<S567>/Product1'
   *  SignalConversion generated from: '<S557>/Vector Concatenate'
   */
  if (rtb_UnaryMinus2_idx_1 * rtb_DeadZone1 > localP->Switch_Threshold_h) {
    Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntDiffrntlEff;
  } else {
    Vsy_0 = localP->Constant_Value_l3;
  }

  /* Sum: '<S573>/Subtract1' incorporates:
   *  Constant: '<S573>/Constant'
   *  Constant: '<S574>/Constant1'
   *  Product: '<S573>/Product3'
   *  Product: '<S573>/Product5'
   *  Sum: '<S574>/Subtract'
   *  Switch: '<S567>/Switch'
   */
  rtb_Sum4_d = (localP->Constant1_Value_cj - rtb_SOC_CC) *
    localP->Constant_Value_e0 + Vsy_0 * rtb_SOC_CC;

  /* Gain: '<S570>/Gain' incorporates:
   *  Abs: '<S569>/Abs'
   *  Constant: '<S570>/Constant1'
   *  Gain: '<S570>/Gain1'
   *  Gain: '<S570>/Gain2'
   *  Integrator: '<S553>/Integrator'
   *  Sum: '<S570>/Subtract1'
   *  Sum: '<S570>/Subtract2'
   *  Trigonometry: '<S570>/Trigonometric Function'
   *  UnaryMinus: '<S557>/Unary Minus1'
   */
  rtb_SOC_CC = (std::tanh((localP->Gain1_Gain_e * std::abs
    (-localX->Integrator_CSTATE_d[0]) - localP->Constant1_Value_f2) *
    localP->Gain2_Gain_h) + localP->Constant1_Value_f2) * localP->Gain_Gain_pl;

  /* Switch: '<S565>/Switch' incorporates:
   *  Constant: '<S565>/Constant'
   *  Constant: '<S575>/Constant'
   *  Integrator: '<S553>/Integrator'
   *  Product: '<S565>/Product1'
   *  UnaryMinus: '<S557>/Unary Minus1'
   *  UnaryMinus: '<S579>/Unary Minus'
   */
  if (-rtb_ChrgCurrLmt * -localX->Integrator_CSTATE_d[0] >
      localP->Switch_Threshold_ez) {
    Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntDiffrntlEff;
  } else {
    Vsy_0 = localP->Constant_Value_pp;
  }

  /* Sum: '<S569>/Subtract1' incorporates:
   *  Constant: '<S569>/Constant'
   *  Constant: '<S570>/Constant1'
   *  Product: '<S569>/Product3'
   *  Product: '<S569>/Product5'
   *  Sum: '<S570>/Subtract'
   *  Switch: '<S565>/Switch'
   */
  rtb_Sum3_l = (localP->Constant1_Value_f2 - rtb_SOC_CC) *
    localP->Constant_Value_po + Vsy_0 * rtb_SOC_CC;

  /* Gain: '<S572>/Gain' incorporates:
   *  Abs: '<S571>/Abs'
   *  Constant: '<S572>/Constant1'
   *  Gain: '<S572>/Gain1'
   *  Gain: '<S572>/Gain2'
   *  Integrator: '<S553>/Integrator'
   *  Sum: '<S572>/Subtract1'
   *  Sum: '<S572>/Subtract2'
   *  Trigonometry: '<S572>/Trigonometric Function'
   *  UnaryMinus: '<S557>/Unary Minus1'
   */
  rtb_SOC_CC = (std::tanh((localP->Gain1_Gain_m * std::abs
    (-localX->Integrator_CSTATE_d[1]) - localP->Constant1_Value_oo) *
    localP->Gain2_Gain_b) + localP->Constant1_Value_oo) * localP->Gain_Gain_fo;

  /* SignalConversion generated from: '<S556>/ SFunction ' incorporates:
   *  MATLAB Function: '<S553>/Open Differential'
   *  Product: '<S565>/Product4'
   *  Product: '<S567>/Product4'
   *  UnaryMinus: '<S579>/Unary Minus'
   */
  rtb_IntegratorSecondOrderLimite[0] = rtb_Sum4_d * rtb_UnaryMinus2_idx_1;
  rtb_IntegratorSecondOrderLimite[1] = rtb_Sum3_l * -rtb_ChrgCurrLmt;

  /* Switch: '<S566>/Switch' incorporates:
   *  Constant: '<S566>/Constant'
   *  Constant: '<S575>/Constant'
   *  Integrator: '<S553>/Integrator'
   *  Product: '<S566>/Product1'
   *  UnaryMinus: '<S557>/Unary Minus1'
   *  UnaryMinus: '<S587>/Unary Minus'
   */
  if (-rtb_DischrgCurrLmt * -localX->Integrator_CSTATE_d[1] >
      localP->Switch_Threshold_c) {
    Vsy_0 = ConfiguredVirtualVehicleModel_P->PlntDiffrntlEff;
  } else {
    Vsy_0 = localP->Constant_Value_p1;
  }

  /* SignalConversion generated from: '<S556>/ SFunction ' incorporates:
   *  Constant: '<S571>/Constant'
   *  Constant: '<S572>/Constant1'
   *  MATLAB Function: '<S553>/Open Differential'
   *  Product: '<S566>/Product4'
   *  Product: '<S571>/Product3'
   *  Product: '<S571>/Product5'
   *  Sum: '<S571>/Subtract1'
   *  Sum: '<S572>/Subtract'
   *  Switch: '<S566>/Switch'
   *  UnaryMinus: '<S587>/Unary Minus'
   */
  rtb_IntegratorSecondOrderLimite[2] = ((localP->Constant1_Value_oo - rtb_SOC_CC)
    * localP->Constant_Value_nn + Vsy_0 * rtb_SOC_CC) * -rtb_DischrgCurrLmt;

  /* MATLAB Function: '<S553>/Open Differential' incorporates:
   *  Constant: '<S553>/Jd'
   *  Constant: '<S553>/Jw1'
   *  Constant: '<S553>/Jw3'
   *  Constant: '<S553>/Ndiff2'
   *  Constant: '<S553>/bd'
   *  Constant: '<S553>/bw1'
   *  Constant: '<S553>/bw2'
   *  Integrator: '<S553>/Integrator'
   */
  if (localP->OpenDifferential_shaftSwitchMas == 1.0) {
    ConfiguredVirtua_automldiffopen(rtb_IntegratorSecondOrderLimite,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl1Damp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlCarrDamp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl2Damp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlRatio, 1.0,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlCarrInertia,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl1Inertia,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl2Inertia,
      localX->Integrator_CSTATE_d, rtb_ubvbwb, localB->xdot);
  } else {
    ConfiguredVirtua_automldiffopen(rtb_IntegratorSecondOrderLimite,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl1Damp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlCarrDamp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl2Damp,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlRatio, 0.0,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlCarrInertia,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl1Inertia,
      ConfiguredVirtualVehicleModel_P->PlntDiffrntlAxl2Inertia,
      localX->Integrator_CSTATE_d, rtb_ubvbwb, localB->xdot);
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S560>/Switch1' incorporates:
     *  Constant: '<S560>/Constant'
     */
    if (localP->Constant_Value_pk > localP->Switch1_Threshold_o) {
      /* Switch: '<S560>/Switch1' incorporates:
       *  Constant: '<S560>/Constant6'
       */
      localB->diffDir_p = localP->Constant6_Value_d;
    } else {
      /* Switch: '<S560>/Switch1' incorporates:
       *  Constant: '<S560>/Constant6'
       *  UnaryMinus: '<S560>/Unary Minus'
       */
      localB->diffDir_p = -localP->Constant6_Value_d;
    }

    /* End of Switch: '<S560>/Switch1' */
  }

  /* Sum: '<S579>/Subtract' incorporates:
   *  Integrator: '<S553>/Integrator'
   *  UnaryMinus: '<S557>/Unary Minus1'
   */
  localB->Subtract_m = -localX->Integrator_CSTATE_d[0] -
    rtb_ImpAsg_InsertedFor_Omega_at[0];

  /* Switch: '<S580>/Switch' */
  if (!(localB->Memory != 0.0)) {
    rtb_BattPackVolt = localB->domega_o;
  }

  /* Product: '<S580>/Product' incorporates:
   *  Constant: '<S579>/omega_c'
   *  Sum: '<S580>/Sum'
   *  Switch: '<S580>/Switch'
   */
  localB->Product_n = (localB->Subtract_m - rtb_BattPackVolt) *
    ConfiguredVirtualVehicleModel_P->PlntDriveshftDampCutoffFreq;

  /* Sum: '<S587>/Subtract' incorporates:
   *  Integrator: '<S553>/Integrator'
   *  UnaryMinus: '<S557>/Unary Minus1'
   */
  localB->Subtract_g = -localX->Integrator_CSTATE_d[1] -
    rtb_ImpAsg_InsertedFor_Omega_at[1];

  /* Switch: '<S588>/Switch' */
  if (!(localB->Memory_h != 0.0)) {
    rtb_min = localB->domega_o_o;
  }

  /* Product: '<S588>/Product' incorporates:
   *  Constant: '<S587>/omega_c'
   *  Sum: '<S588>/Sum'
   *  Switch: '<S588>/Switch'
   */
  localB->Product_a = (localB->Subtract_g - rtb_min) *
    ConfiguredVirtualVehicleModel_P->PlntDriveshftDampCutoffFreq;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S621>/Constant' */
    localB->TransGear = localP->Constant_Value_jt;
  }

  /* Sum: '<S601>/Subtract' */
  localB->Subtract_gw = localB->Spd - rtb_DeadZone1;

  /* Switch: '<S602>/Switch' incorporates:
   *  Integrator: '<S602>/Integrator'
   */
  if (localB->Memory_m != 0.0) {
    Vsy_0 = localX->Integrator_CSTATE_n;
  } else {
    Vsy_0 = localB->domega_o_n;
  }

  /* Product: '<S602>/Product' incorporates:
   *  Constant: '<S601>/omega_c'
   *  Sum: '<S602>/Sum'
   *  Switch: '<S602>/Switch'
   */
  localB->Product_m = (localB->Subtract_gw - Vsy_0) *
    ConfiguredVirtualVehicleModel_P->PlntDriveshftDampCutoffFreq;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S612>/Switch' incorporates:
     *  Constant: '<S609>/J'
     *  Constant: '<S619>/Constant'
     *  Constant: '<S620>/Constant'
     *  Logic: '<S612>/Logical Operator'
     *  RelationalOperator: '<S619>/Compare'
     *  RelationalOperator: '<S620>/Compare'
     */
    if ((ConfiguredVirtualVehicleModel_P->PlntEM1RotInertia >=
         -localP->div0protectabspoly_thresh) &&
        (ConfiguredVirtualVehicleModel_P->PlntEM1RotInertia <=
         localP->div0protectabspoly_thresh)) {
      /* Switch: '<S612>/Switch' incorporates:
       *  Fcn: '<S612>/Fcn'
       */
      localB->Switch_g = 2.0E-6 / (3.0 - rt_powd_snf
        (ConfiguredVirtualVehicleModel_P->PlntEM1RotInertia / 1.0e-6, 2.0));
    } else {
      /* Switch: '<S612>/Switch' incorporates:
       *  Abs: '<S612>/Abs'
       */
      localB->Switch_g = std::abs
        (ConfiguredVirtualVehicleModel_P->PlntEM1RotInertia);
    }

    /* End of Switch: '<S612>/Switch' */

    /* Gain: '<S644>/Gain2' incorporates:
     *  Constant: '<S644>/Constant1'
     */
    localB->Gain2_c = ConfiguredVirtualVehicleModel_P->PlntDCDCTimeCnst *
      ConfiguredVirtualVehicleModel_P->PlntDCDCVoltInit;
  }

  /* Product: '<S610>/Divide' incorporates:
   *  Gain: '<S610>/Gain2'
   *  Sum: '<S610>/Subtract'
   *  TransferFcn: '<S658>/Motor Coupling Dynamics'
   *  UnaryMinus: '<S601>/Unary Minus'
   */
  localB->Divide_h = ((localP->MotorCouplingDynamics_C *
                       localX->MotorCouplingDynamics_CSTATE -
                       rtb_UnaryMinus2_idx_1) +
                      -ConfiguredVirtualVehicleModel_P->PlntEM1RotDamp *
                      localB->Spd) / localB->Switch_g;

  /* Integrator: '<S644>/Integrator' */
  if (localDW->Integrator_IWORK_a != 0) {
    localX->Integrator_CSTATE_a = localB->Gain2_c;
  }

  /* Gain: '<S644>/Gain1' incorporates:
   *  Integrator: '<S644>/Integrator'
   */
  rtb_Divide_ag = 1.0 / ConfiguredVirtualVehicleModel_P->PlntDCDCTimeCnst *
    localX->Integrator_CSTATE_a;

  /* Lookup_n-D: '<S666>/Max Torque Limit' incorporates:
   *  Integrator: '<S610>/Integrator'
   */
  rtb_UnaryMinus2_idx_1 = look1_binlcapw(localB->Spd,
    localP->MaxTorqueLimit_bp01Data, localP->MaxTorqueLimit_tableData, 26U);

  /* Gain: '<S666>/Gain1' incorporates:
   *  Integrator: '<S666>/Integrator'
   */
  rtb_DeadZone1 = 1.0 / ConfiguredVirtualVehicleModel_P->PlntEM1TimeCnst *
    localX->Integrator_CSTATE_l;

  /* Product: '<S666>/Divide2' incorporates:
   *  Lookup_n-D: '<S666>/Interpolated zero-crossing'
   *  Product: '<S666>/Product'
   */
  localB->Divide2 = look1_binlcpw(1.0 / rtb_UnaryMinus2_idx_1 * rtb_DeadZone1,
    localP->Interpolatedzerocrossing_bp01Da,
    localP->Interpolatedzerocrossing_tableD, 1U) * rtb_UnaryMinus2_idx_1;

  /* Saturate: '<S663>/Saturation' */
  if (rtb_Divide_ag > localP->Saturation_UpperSat_h) {
    Vsy_0 = localP->Saturation_UpperSat_h;
  } else if (rtb_Divide_ag < localP->Saturation_LowerSat_b) {
    Vsy_0 = localP->Saturation_LowerSat_b;
  } else {
    Vsy_0 = rtb_Divide_ag;
  }

  /* Product: '<S663>/Divide' incorporates:
   *  Integrator: '<S610>/Integrator'
   *  Lookup_n-D: '<S665>/2-D Lookup Table'
   *  Product: '<S665>/Product'
   *  Product: '<S666>/Divide2'
   *  Saturate: '<S663>/Saturation'
   *  Sum: '<S663>/Add'
   */
  rtb_Sum4_d = (localB->Spd * localB->Divide2 + look2_binlcapw(localB->Spd,
    localB->Divide2, localP->uDLookupTable_bp01Data,
    localP->uDLookupTable_bp02Data, localP->uDLookupTable_tableData,
    localP->uDLookupTable_maxIndex, 27U)) / Vsy_0;

  /* Product: '<S646>/Product' */
  rtb_Sum3_l = rtb_Divide_ag * rtb_Sum4_d;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S646>/Subtract' incorporates:
     *  Constant: '<S646>/Constant'
     *  Constant: '<S646>/Constant1'
     */
    rtb_SumofElements15 = localP->Constant1_Value_d -
      ConfiguredVirtualVehicleModel_P->PlntDCDCEff;

    /* Product: '<S646>/Divide' incorporates:
     *  Constant: '<S646>/Constant'
     */
    localB->Divide_jj = rtb_SumofElements15 /
      ConfiguredVirtualVehicleModel_P->PlntDCDCEff;

    /* Product: '<S646>/Divide1' incorporates:
     *  Constant: '<S646>/Constant2'
     */
    localB->Divide1 = rtb_SumofElements15 / localP->Constant2_Value_f;
  }

  /* Switch: '<S646>/Switch' incorporates:
   *  Abs: '<S646>/Abs'
   *  Product: '<S646>/Product1'
   *  Product: '<S646>/Product2'
   */
  if (rtb_Sum3_l >= localP->Switch_Threshold_n) {
    Vsy_0 = rtb_Sum3_l * localB->Divide_jj;
  } else {
    Vsy_0 = std::abs(rtb_Sum3_l) * localB->Divide1;
  }

  /* Sum: '<S645>/Add' incorporates:
   *  Switch: '<S646>/Switch'
   */
  rtb_Sum3_l += Vsy_0;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* UnaryMinus: '<S651>/Unary Minus' incorporates:
     *  Constant: '<S651>/Constant'
     */
    localB->UnaryMinus_d = -localP->Constant_Value_m;
  }

  /* Switch: '<S651>/Switch' incorporates:
   *  Constant: '<S652>/Constant'
   *  Constant: '<S653>/Constant'
   *  Fcn: '<S651>/Fcn'
   *  Logic: '<S651>/Logical Operator'
   *  Product: '<S651>/Product'
   *  RelationalOperator: '<S652>/Compare'
   *  RelationalOperator: '<S653>/Compare'
   *  Switch: '<S651>/Switch1'
   */
  if ((rtb_Gain1 >= -localP->div0protectpoly_thresh_p) && (rtb_Gain1 <=
       localP->div0protectpoly_thresh_p)) {
    /* Switch: '<S651>/Switch1' incorporates:
     *  Constant: '<S651>/Constant'
     */
    if (rtb_Gain1 >= localP->Switch1_Threshold_i) {
      Vsy_0 = localP->Constant_Value_m;
    } else {
      Vsy_0 = localB->UnaryMinus_d;
    }

    rtb_UnaryMinus2_idx_1 = 0.002 / (3.0 - rt_powd_snf(rtb_Gain1 / 0.001, 2.0)) *
      Vsy_0;
  } else {
    rtb_UnaryMinus2_idx_1 = rtb_Gain1;
  }

  /* End of Switch: '<S651>/Switch' */

  /* Product: '<S645>/Divide' */
  rtb_UnaryMinus2_idx_1 = rtb_Sum3_l / rtb_UnaryMinus2_idx_1;

  /* Gain: '<S633>/Gain1' */
  localB->Gain1_o = -1.0 / (ConfiguredVirtualVehicleModel_P->PlntBattNumCellPar *
    3600.0) * rtb_UnaryMinus2_idx_1;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S633>/Switch' incorporates:
     *  Constant: '<S629>/Constant1'
     */
    if (ConfiguredVirtualVehicleModel_P->PlntBattCapInit >
        ConfiguredVirtualVehicleModel_P->PlntBattChrgMax) {
      /* Switch: '<S633>/Switch' incorporates:
       *  Constant: '<S633>/Constant1'
       */
      localB->Switch_g4 = ConfiguredVirtualVehicleModel_P->PlntBattChrgMax;
    } else {
      /* Switch: '<S633>/Switch' */
      localB->Switch_g4 = ConfiguredVirtualVehicleModel_P->PlntBattCapInit;
    }

    /* End of Switch: '<S633>/Switch' */
  }

  /* Integrator: '<S633>/Integrator Limited' */
  /* Limited  Integrator  */
  if (localDW->IntegratorLimited_IWORK != 0) {
    localX->IntegratorLimited_CSTATE = localB->Switch_g4;
  }

  if (localX->IntegratorLimited_CSTATE >=
      ConfiguredVirtualVehicleModel_P->PlntBattChrgMax) {
    localX->IntegratorLimited_CSTATE =
      ConfiguredVirtualVehicleModel_P->PlntBattChrgMax;
  } else if (localX->IntegratorLimited_CSTATE <=
             localP->IntegratorLimited_LowerSat) {
    localX->IntegratorLimited_CSTATE = localP->IntegratorLimited_LowerSat;
  }

  /* Product: '<S634>/Divide' incorporates:
   *  Constant: '<S634>/Constant1'
   *  Integrator: '<S633>/Integrator Limited'
   */
  rtb_Product1_o_idx_1 = localX->IntegratorLimited_CSTATE /
    ConfiguredVirtualVehicleModel_P->PlntBattChrgMax;

  /* Sum: '<S631>/Sum' incorporates:
   *  Constant: '<S5>/Temp_degK'
   *  Gain: '<S635>/Gain1'
   *  Gain: '<S635>/Gain2'
   *  Lookup_n-D: '<S635>/Em'
   *  Lookup_n-D: '<S635>/R'
   *  Product: '<S635>/Product'
   *  Product: '<S644>/Divide'
   *  Sum: '<S635>/Subtract'
   */
  localB->Sum_l = (look1_binlcapw(rtb_Product1_o_idx_1,
    ConfiguredVirtualVehicleModel_P->PlntBattVoltSocBpt,
    ConfiguredVirtualVehicleModel_P->PlntBattOpenCirctVolt, 100U) - 1.0 /
                   ConfiguredVirtualVehicleModel_P->PlntBattNumCellPar *
                   rtb_UnaryMinus2_idx_1 * look2_binlcapw
                   (ConfiguredVirtualVehicleModel_P->EnvAirTemp,
                    rtb_Product1_o_idx_1,
                    ConfiguredVirtualVehicleModel_P->PlntBattTempBpt,
                    ConfiguredVirtualVehicleModel_P->PlntBattSocBpt,
                    ConfiguredVirtualVehicleModel_P->PlntBattIntrnRes,
                    localP->R_maxIndex, 7U)) *
    ConfiguredVirtualVehicleModel_P->PlntBattNumCellSer - rtb_Gain1;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S640>/Sum' incorporates:
     *  Constant: '<S5>/Temp_degK'
     *  Constant: '<S640>/Constant1'
     */
    rtb_SOC_CC = ConfiguredVirtualVehicleModel_P->EnvAirTemp -
      localP->Constant1_Value_eg;

    /* DataTypeConversion: '<S628>/Data Type Conversion3' incorporates:
     *  Gain: '<S628>/Gain1'
     */
    for (i = 0; i < 96; i++) {
      rtb_CellTemperatures_g[i] = static_cast<real32_T>(localP->Gain1_Gain_b[i] *
        rtb_SOC_CC);
    }

    /* End of DataTypeConversion: '<S628>/Data Type Conversion3' */

    /* DataTypeConversion: '<S628>/Data Type Conversion4' incorporates:
     *  Constant: '<S628>/Constant1'
     */
    rtb_VoutChgr = static_cast<real32_T>(localP->Constant1_Value_j);
  }

  /* DataTypeConversion: '<S628>/Data Type Conversion2' incorporates:
   *  Gain: '<S628>/Gain2'
   */
  localB->PackCurrent_e = static_cast<real32_T>(localP->Gain2_Gain_m *
    rtb_UnaryMinus2_idx_1);

  /* DataTypeConversion: '<S628>/Data Type Conversion5' incorporates:
   *  DataTypeConversion: '<S628>/Data Type Conversion1'
   */
  localB->VoutInvtr_p = static_cast<real32_T>(rtb_Gain1);
  for (i = 0; i < 96; i++) {
    /* DataTypeConversion: '<S628>/Data Type Conversion6' incorporates:
     *  Gain: '<S628>/Gain'
     */
    localB->CellVoltages_g[i] = static_cast<real32_T>(1.0 /
      ConfiguredVirtualVehicleModel_P->PlntBattNumCellSer * rtb_Gain1);
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
      std::memcpy(&localDW->RateTransition_1_Buffer[0], &localB->CellVoltages_g
                  [0], 96U * sizeof(real32_T));
    }

    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
      localDW->RateTransition_3_Buffer = localB->PackCurrent_e;
    }
  }

  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S628>/Rate Transition' */
    std::memcpy(&localB->CellVoltages_m[0], &localDW->RateTransition_1_Buffer[0],
                96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0)) {
    std::memcpy(&localDW->RateTransition_4_Buffer[0], &rtb_CellTemperatures_g[0],
                96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S628>/Rate Transition' */
    localB->PackCurrent_c = localDW->RateTransition_3_Buffer;
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0)) {
    localDW->RateTransition_5_Buffer = rtb_VoutChgr;
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S628>/Rate Transition' */
    std::memcpy(&localB->CellTemperatures[0], &localDW->RateTransition_4_Buffer
                [0], 96U * sizeof(real32_T));
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if ((rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) &&
      (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
       (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0)) {
    localDW->RateTransition_6_Buffer = localB->VoutInvtr_p;
  }

  /* RateTransition generated from: '<S628>/Rate Transition' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* RateTransition generated from: '<S628>/Rate Transition' */
    localB->VoutChgr_i = localDW->RateTransition_5_Buffer;

    /* RateTransition generated from: '<S628>/Rate Transition' */
    localB->VoutInvtr_pm = localDW->RateTransition_6_Buffer;
  }

  /* Switch: '<S648>/Switch' incorporates:
   *  Abs: '<S648>/Abs'
   *  Constant: '<S649>/Constant'
   *  Constant: '<S650>/Constant'
   *  Fcn: '<S648>/Fcn'
   *  Logic: '<S648>/Logical Operator'
   *  RelationalOperator: '<S649>/Compare'
   *  RelationalOperator: '<S650>/Compare'
   */
  if ((rtb_Sum4_d >= -localP->div0protectabspoly_thresh_f) && (rtb_Sum4_d <=
       localP->div0protectabspoly_thresh_f)) {
    rtb_Product1_o_idx_1 = 0.002 / (3.0 - rt_powd_snf(rtb_Sum4_d / 0.001, 2.0));
  } else {
    rtb_Product1_o_idx_1 = std::abs(rtb_Sum4_d);
  }

  /* End of Switch: '<S648>/Switch' */

  /* Product: '<S644>/Divide' incorporates:
   *  Constant: '<S644>/MaxLdPwr'
   */
  rtb_Product1_o_idx_1 = ConfiguredVirtualVehicleModel_P->PlntDCDCPwrLmt /
    rtb_Product1_o_idx_1;
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S644>/Switch' incorporates:
     *  Constant: '<S622>/Constant3'
     */
    if (ConfiguredVirtualVehicleModel_P->PlntDCDCVoltInit >=
        localP->Switch_Threshold_ae) {
      /* Switch: '<S644>/Switch' */
      localB->Switch_e = ConfiguredVirtualVehicleModel_P->PlntDCDCVoltInit;
    } else {
      /* Switch: '<S644>/Switch' incorporates:
       *  Constant: '<S644>/Constant'
       */
      localB->Switch_e = localP->Constant_Value_c;
    }

    /* End of Switch: '<S644>/Switch' */

    /* Product: '<S671>/Product2' incorporates:
     *  Constant: '<S671>/ClsdLpFuelMult'
     *  Constant: '<S671>/FuelVolFlw'
     */
    localB->Product2_o = localP->FuelVolFlw_Value * localP->ClsdLpFuelMult_Value;

    /* Constant: '<S671>/TPCO' */
    localB->TPCO = localP->TPCO_Value;

    /* Constant: '<S671>/TPCO2' */
    localB->TPCO2 = localP->TPCO2_Value;

    /* Constant: '<S671>/TPHC' */
    localB->TPHC = localP->TPHC_Value;

    /* Constant: '<S671>/TPNOx' */
    localB->TPNOx = localP->TPNOx_Value;
  }

  /* Sum: '<S644>/Sum' incorporates:
   *  MinMax: '<S644>/MinMax'
   */
  localB->Sum_o = std::fmin(rtb_Product1_o_idx_1, localB->Switch_e) -
    rtb_Divide_ag;

  /* Sum: '<S666>/Sum' */
  localB->Sum_d = localB->EMTrqCmd - rtb_DeadZone1;

  /* Product: '<S622>/Product2' */
  localB->BattPwr = rtb_UnaryMinus2_idx_1 * rtb_Gain1;

  /* Gain: '<S684>/2*zeta * wn' */
  /* Unit Conversion - from: gn to: m/s^2
     Expression: output = (9.80665*input) + (0) */
  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  rtb_Product_pm = 2.0 * localP->SecondorderDynamics_zn *
    localP->SecondorderDynamics_wn;

  /* UnitConversion: '<S674>/Unit Conversion' */
  rtb_ubvbwb[0] = 9.8066500000000012 * rtb_Switch1_f[0];

  /* Gain: '<S684>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited'
   */
  rtb_Product_o0[0] = rtb_Product_pm * localX->IntegratorSecondOrderLimited_CS[3];

  /* UnitConversion: '<S674>/Unit Conversion' */
  rtb_ubvbwb[1] = 9.8066500000000012 * rtb_Switch1_f[1];

  /* Gain: '<S684>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited'
   */
  rtb_Product_o0[1] = rtb_Product_pm * localX->IntegratorSecondOrderLimited_CS[4];

  /* UnitConversion: '<S674>/Unit Conversion' */
  rtb_ubvbwb[2] = 9.8066500000000012 * rtb_Switch1_f[2];

  /* Gain: '<S684>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited'
   */
  rtb_Product_o0[2] = rtb_Product_pm * localX->IntegratorSecondOrderLimited_CS[5];
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S677>/Zero-Order Hold2' incorporates:
     *  Constant: '<S674>/Constant1'
     *  UnaryMinus: '<S675>/Unary Minus'
     */
    localB->ZeroOrderHold2[0] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kn[0];

    /* Gain: '<S677>/Gain' incorporates:
     *  Constant: '<S674>/Constant'
     *  Constant: '<S677>/wl_ins'
     *  Gain: '<S677>/Zero-Order Hold4'
     *  Sum: '<S677>/Sum7'
     */
    localB->Gain_bd[0] = (localP->ZeroOrderHold4_Gain * localP->
                          Constant_Value_o[0] -
                          localP->ThreeaxisInertialMeasurementU_d[0]) *
      localP->Gain_Gain_a[0];

    /* Gain: '<S677>/Zero-Order Hold2' incorporates:
     *  Constant: '<S674>/Constant1'
     *  UnaryMinus: '<S675>/Unary Minus'
     */
    localB->ZeroOrderHold2[1] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kn[1];

    /* Gain: '<S677>/Gain' incorporates:
     *  Constant: '<S674>/Constant'
     *  Constant: '<S677>/wl_ins'
     *  Gain: '<S677>/Zero-Order Hold4'
     *  Sum: '<S677>/Sum7'
     */
    localB->Gain_bd[1] = (localP->ZeroOrderHold4_Gain * localP->
                          Constant_Value_o[1] -
                          localP->ThreeaxisInertialMeasurementU_d[1]) *
      localP->Gain_Gain_a[1];

    /* Gain: '<S677>/Zero-Order Hold2' incorporates:
     *  Constant: '<S674>/Constant1'
     *  UnaryMinus: '<S675>/Unary Minus'
     */
    localB->ZeroOrderHold2[2] = localP->ZeroOrderHold2_Gain *
      -localP->Constant1_Value_kn[2];

    /* Gain: '<S677>/Gain' incorporates:
     *  Constant: '<S674>/Constant'
     *  Constant: '<S677>/wl_ins'
     *  Gain: '<S677>/Zero-Order Hold4'
     *  Sum: '<S677>/Sum7'
     */
    localB->Gain_bd[2] = (localP->ZeroOrderHold4_Gain * localP->
                          Constant_Value_o[2] -
                          localP->ThreeaxisInertialMeasurementU_d[2]) *
      localP->Gain_Gain_a[2];
  }

  /* Switch: '<S679>/Switch1' incorporates:
   *  Constant: '<S677>/Measurement bias'
   *  Constant: '<S677>/Scale factors & Cross-coupling  errors'
   *  Constant: '<S679>/0'
   *  Constant: '<S679>/Constant'
   *  Product: '<S677>/Product'
   *  Sum: '<S677>/Sum4'
   */
  if (localP->Constant_Value_i >= localP->Switch1_Threshold_c) {
    /* Gain: '<S677>/Zero-Order Hold3' incorporates:
     *  UnitConversion: '<S411>/Unit Conversion2'
     */
    rtb_Sum_c5[0] = localP->ZeroOrderHold3_Gain * localB->Product2[0];

    /* Gain: '<S677>/Zero-Order Hold' incorporates:
     *  Integrator: '<S407>/p,q,r '
     */
    rtb_Gain1 = localP->ZeroOrderHold_Gain * localX->pqr_CSTATE[0];

    /* Gain: '<S677>/Zero-Order Hold3' incorporates:
     *  UnitConversion: '<S411>/Unit Conversion2'
     */
    rtb_Sum_c5[1] = localP->ZeroOrderHold3_Gain * localB->Product2[1];

    /* Gain: '<S677>/Zero-Order Hold' incorporates:
     *  Integrator: '<S407>/p,q,r '
     */
    rtb_BattPackVolt = localP->ZeroOrderHold_Gain * localX->pqr_CSTATE[1];

    /* Gain: '<S677>/Zero-Order Hold3' incorporates:
     *  UnitConversion: '<S411>/Unit Conversion2'
     */
    rtb_Sum_c5[2] = localP->ZeroOrderHold3_Gain * localB->Product2[2];

    /* Gain: '<S677>/Zero-Order Hold' incorporates:
     *  Integrator: '<S407>/p,q,r '
     */
    rtb_SOC_CC = localP->ZeroOrderHold_Gain * localX->pqr_CSTATE[2];

    /* Sum: '<S686>/Sum' incorporates:
     *  Product: '<S689>/i x j'
     *  Product: '<S689>/j x k'
     *  Product: '<S689>/k x i'
     *  Product: '<S690>/i x k'
     *  Product: '<S690>/j x i'
     *  Product: '<S690>/k x j'
     */
    rtb_DischrgCurrLmt = rtb_BattPackVolt * localB->Gain_bd[2] - localB->
      Gain_bd[1] * rtb_SOC_CC;
    rtb_ChrgCurrLmt = localB->Gain_bd[0] * rtb_SOC_CC - rtb_Gain1 *
      localB->Gain_bd[2];
    rtb_SumofElements15 = rtb_Gain1 * localB->Gain_bd[1] - localB->Gain_bd[0] *
      rtb_BattPackVolt;

    /* Sum: '<S677>/Sum' incorporates:
     *  Gain: '<S677>/Zero-Order Hold1'
     *  Product: '<S687>/i x j'
     *  Product: '<S687>/j x k'
     *  Product: '<S687>/k x i'
     *  Product: '<S688>/i x k'
     *  Product: '<S688>/j x i'
     *  Product: '<S688>/k x j'
     *  Product: '<S691>/i x j'
     *  Product: '<S691>/j x k'
     *  Product: '<S691>/k x i'
     *  Product: '<S692>/i x k'
     *  Product: '<S692>/j x i'
     *  Product: '<S692>/k x j'
     *  Sum: '<S682>/Sum'
     *  Sum: '<S685>/Sum'
     */
    rtb_Saturation1_idx_0 = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[0] -
      localB->ZeroOrderHold2[0]) + (rtb_BattPackVolt * rtb_SumofElements15 -
      rtb_ChrgCurrLmt * rtb_SOC_CC)) + (rtb_Sum_c5[1] * localB->Gain_bd[2] -
      localB->Gain_bd[1] * rtb_Sum_c5[2]);
    rtb_SumofElements15 = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[1] -
      localB->ZeroOrderHold2[1]) + (rtb_DischrgCurrLmt * rtb_SOC_CC - rtb_Gain1 *
      rtb_SumofElements15)) + (localB->Gain_bd[0] * rtb_Sum_c5[2] - rtb_Sum_c5[0]
      * localB->Gain_bd[2]);
    rtb_Saturation1_idx_1 = ((localP->ZeroOrderHold1_Gain * rtb_ubvbwb[2] -
      localB->ZeroOrderHold2[2]) + (rtb_Gain1 * rtb_ChrgCurrLmt -
      rtb_DischrgCurrLmt * rtb_BattPackVolt)) + (rtb_Sum_c5[0] * localB->
      Gain_bd[1] - localB->Gain_bd[0] * rtb_Sum_c5[1]);
    for (i = 0; i < 3; i++) {
      rtb_Switch1_f[i] = ((localP->ThreeaxisInertialMeasurementU_f[i + 3] *
                           rtb_SumofElements15 +
                           localP->ThreeaxisInertialMeasurementU_f[i] *
                           rtb_Saturation1_idx_0) +
                          localP->ThreeaxisInertialMeasurementU_f[i + 6] *
                          rtb_Saturation1_idx_1) +
        localP->ThreeaxisInertialMeasurementUni[i];
    }
  } else {
    rtb_Switch1_f[0] = localP->u_Value_g[0];
    rtb_Switch1_f[1] = localP->u_Value_g[1];
    rtb_Switch1_f[2] = localP->u_Value_g[2];
  }

  /* End of Switch: '<S679>/Switch1' */

  /* Gain: '<S684>/wn^2' */
  rtb_Product_pm = localP->SecondorderDynamics_wn *
    localP->SecondorderDynamics_wn;

  /* Sum: '<S684>/Sum2' incorporates:
   *  Gain: '<S684>/wn^2'
   *  SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited'
   *  Sum: '<S684>/Sum3'
   */
  localB->Sum2[0] = (rtb_Switch1_f[0] - localX->IntegratorSecondOrderLimited_CS
                     [0]) * rtb_Product_pm - rtb_Product_o0[0];
  localB->Sum2[1] = (rtb_Switch1_f[1] - localX->IntegratorSecondOrderLimited_CS
                     [1]) * rtb_Product_pm - rtb_Product_o0[1];
  localB->Sum2[2] = (rtb_Switch1_f[2] - localX->IntegratorSecondOrderLimited_CS
                     [2]) * rtb_Product_pm - rtb_Product_o0[2];

  /* Gain: '<S696>/2*zeta * wn' incorporates:
   *  SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited'
   */
  rtb_Product_pm = 2.0 * localP->SecondorderDynamics_zn_o *
    localP->SecondorderDynamics_wn_p;
  rtb_Product_o0[0] = rtb_Product_pm * localX->IntegratorSecondOrderLimited__i[3];
  rtb_Product_o0[1] = rtb_Product_pm * localX->IntegratorSecondOrderLimited__i[4];
  rtb_Product_o0[2] = rtb_Product_pm * localX->IntegratorSecondOrderLimited__i[5];

  /* Switch: '<S693>/Switch1' incorporates:
   *  Constant: '<S678>/Measurement bias'
   *  Constant: '<S678>/Scale factors & Cross-coupling  errors '
   *  Constant: '<S678>/g-sensitive bias'
   *  Constant: '<S693>/0'
   *  Constant: '<S693>/Constant'
   *  Gain: '<S678>/Zero-Order Hold'
   *  Gain: '<S678>/Zero-Order Hold1'
   *  Integrator: '<S407>/p,q,r '
   *  Product: '<S678>/Product'
   *  Product: '<S678>/Product1'
   *  Sum: '<S678>/Sum4'
   *  UnitConversion: '<S676>/Unit Conversion'
   */
  if (localP->Constant_Value_bq >= localP->Switch1_Threshold_g) {
    /* Integrator: '<S407>/p,q,r ' incorporates:
     *  Constant: '<S678>/Scale factors & Cross-coupling  errors '
     *  Product: '<S678>/Product'
     */
    rtb_Saturation1_idx_1 = localX->pqr_CSTATE[0];
    rtb_Saturation1_idx_2 = localX->pqr_CSTATE[1];
    SteerCmd = localX->pqr_CSTATE[2];
    for (i = 0; i < 3; i++) {
      rtb_Switch1_f[i] = (((localP->ZeroOrderHold_Gain_k * rtb_Saturation1_idx_1
                            * localP->ThreeaxisInertialMeasurementU_k[i] +
                            localP->ThreeaxisInertialMeasurementU_k[i + 3] *
                            (localP->ZeroOrderHold_Gain_k *
        rtb_Saturation1_idx_2)) + localP->ThreeaxisInertialMeasurementU_k[i + 6]
                           * (localP->ZeroOrderHold_Gain_k * SteerCmd)) +
                          localP->ThreeaxisInertialMeasurementU_c[i]) +
        0.10197162129779282 * rtb_ubvbwb[i] * localP->ZeroOrderHold1_Gain_a *
        localP->ThreeaxisInertialMeasurementU_p[i];
    }
  } else {
    rtb_Switch1_f[0] = localP->u_Value_g4[0];
    rtb_Switch1_f[1] = localP->u_Value_g4[1];
    rtb_Switch1_f[2] = localP->u_Value_g4[2];
  }

  /* End of Switch: '<S693>/Switch1' */

  /* Gain: '<S696>/wn^2' */
  rtb_Product_pm = localP->SecondorderDynamics_wn_p *
    localP->SecondorderDynamics_wn_p;

  /* Sum: '<S696>/Sum2' incorporates:
   *  Gain: '<S696>/wn^2'
   *  SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited'
   *  Sum: '<S696>/Sum3'
   */
  localB->Sum2_c[0] = (rtb_Switch1_f[0] -
                       localX->IntegratorSecondOrderLimited__i[0]) *
    rtb_Product_pm - rtb_Product_o0[0];
  localB->Sum2_c[1] = (rtb_Switch1_f[1] -
                       localX->IntegratorSecondOrderLimited__i[1]) *
    rtb_Product_pm - rtb_Product_o0[1];
  localB->Sum2_c[2] = (rtb_Switch1_f[2] -
                       localX->IntegratorSecondOrderLimited__i[2]) *
    rtb_Product_pm - rtb_Product_o0[2];
}

/* Update for atomic system: '<Root>/AdasPlantModel' */
void ConfiguredVirtualVehicleModel::Configure_AdasPlantModel_Update
  (B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
   *localDW, P_AdasPlantModel_ConfiguredVi_T *localP)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_a;
  real_T err;
  real_T tol;
  real_T *lastU;
  boolean_T guard1;

  /* Update for RateTransition: '<S22>/Rate Transition18' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    std::memcpy(&localDW->UnitDelay_1_DSTATE[0], &localB->CellVoltages_m[0], 96U
                * sizeof(real32_T));

    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    std::memcpy(&localDW->UnitDelay_4_DSTATE[0], &localB->CellTemperatures[0],
                96U * sizeof(real32_T));

    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    localDW->UnitDelay_2_DSTATE = localB->PackVoltage_l;

    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    localDW->UnitDelay_5_DSTATE = localB->VoutChgr_i;

    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    localDW->UnitDelay_6_DSTATE = localB->VoutInvtr_pm;

    /* Update for UnitDelay generated from: '<S26>/Unit Delay' */
    localDW->UnitDelay_3_DSTATE = localB->PackCurrent_c;

    /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localB->Divide_pf;
    if (localDW->DiscreteTimeIntegrator_DSTATE >=
        localP->DiscreteTimeIntegrator_UpperSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_UpperSat;
    } else if (localDW->DiscreteTimeIntegrator_DSTATE <=
               localP->DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_LowerSat;
    }

    /* End of Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
    localDW->RateTransition18_Buffer[static_cast<int32_T>
      (localDW->RateTransition18_ActiveBufIdx == 0)] =
      localB->DataTypeConversion1;
    localDW->RateTransition18_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition18_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S22>/Rate Transition19' */
    localDW->RateTransition19_Buffer[static_cast<int32_T>
      (localDW->RateTransition19_ActiveBufIdx == 0)] =
      localB->DataTypeConversion;
    localDW->RateTransition19_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition19_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S22>/Rate Transition20' */
    localDW->RateTransition20_Buffer[static_cast<int32_T>
      (localDW->RateTransition20_ActiveBufIdx == 0)] =
      localB->DataTypeConversion2;
    localDW->RateTransition20_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition20_ActiveBufIdx == 0);

    /* Update for RateTransition: '<S22>/Rate Transition21' */
    localDW->RateTransition21_Buffer[static_cast<int32_T>
      (localDW->RateTransition21_ActiveBufIdx == 0)] =
      localB->DataTypeConversion3;
    localDW->RateTransition21_ActiveBufIdx = static_cast<int8_T>
      (localDW->RateTransition21_ActiveBufIdx == 0);
  }

  /* End of Update for RateTransition: '<S22>/Rate Transition18' */

  /* Update for Integrator: '<S631>/Integrator' */
  localDW->Integrator_IWORK = 0;

  /* Update for FirstOrderHold: '<S80>/First Order Hold' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
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
        localDW->Mk = (localB->Switch2 - localDW->Uk) /
          ((&ConfiguredVirtualVehicleMode_M)->Timing.t[0] - localDW->Tk);
        localDW->Ck = localB->EMTrqCmd;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (localB->Switch2 != localB->EMTrqCmd) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&(&ConfiguredVirtualVehicleMode_M)->solverInfo, true);
      }

      localDW->Ck = localB->Switch2;
      localDW->Mk = 0.0;
    }

    localDW->Uk = localB->Switch2;
    localDW->Tk = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];

    /* Update for Memory: '<S580>/Memory' incorporates:
     *  Constant: '<S580>/Reset'
     *  FirstOrderHold: '<S80>/First Order Hold'
     */
    localDW->Memory_PreviousInput = localP->Reset_Value;

    /* Update for Memory: '<S588>/Memory' incorporates:
     *  Constant: '<S588>/Reset'
     */
    localDW->Memory_PreviousInput_e = localP->Reset_Value_e;
  }

  /* End of Update for FirstOrderHold: '<S80>/First Order Hold' */

  /* Update for Integrator: '<S580>/Integrator' */
  localDW->Integrator_IWORK_n = 0;

  /* Update for Integrator: '<S588>/Integrator' */
  localDW->Integrator_IWORK_m = 0;

  /* Update for Iterator SubSystem: '<S435>/Unwrap' */
  for (ForEach_itr_a = 0; ForEach_itr_a < 3; ForEach_itr_a++) {
    if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
        (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Memory: '<S440>/Memory1' incorporates:
       *  ForEachSliceSelector generated from: '<S439>/u'
       */
      localDW->CoreSubsys_n[ForEach_itr_a].Memory1_PreviousInput =
        localB->phithetapsi[ForEach_itr_a];
    }
  }

  /* End of Update for SubSystem: '<S435>/Unwrap' */

  /* Update for Backlash: '<S118>/Backlash' */
  localDW->PrevY = localB->Backlash;

  /* Update for Derivative: '<S132>/Derivative' */
  if (localDW->TimeStampA == (rtInf)) {
    localDW->TimeStampA = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA;
  } else if (localDW->TimeStampB == (rtInf)) {
    localDW->TimeStampB = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB;
  } else if (localDW->TimeStampA < localDW->TimeStampB) {
    localDW->TimeStampA = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA;
  } else {
    localDW->TimeStampB = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB;
  }

  *lastU = localB->Gain2;

  /* End of Update for Derivative: '<S132>/Derivative' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S133>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemInp = localB->Memory_j;

    /* Update for Memory generated from: '<S133>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_l = localB->Memory1;

    /* Update for Memory generated from: '<S134>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_n = localB->Memory_hm;

    /* Update for Memory generated from: '<S134>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_k = localB->Memory1_k;

    /* Update for Memory: '<S133>/Memory' */
    localDW->Memory_PreviousInput_p = localB->EnabledSubsystem.y;

    /* Update for Memory: '<S133>/Memory1' */
    localDW->Memory1_PreviousInput = localB->EnabledSubsystem1.y;

    /* Update for Memory: '<S134>/Memory' */
    localDW->Memory_PreviousInput_g = localB->EnabledSubsystem_h.y;

    /* Update for Memory: '<S134>/Memory1' */
    localDW->Memory1_PreviousInput_n = localB->EnabledSubsystem1_d.y;

    /* Update for Backlash: '<S205>/Backlash' */
    localDW->PrevY_g = localB->Backlash_a;
  }

  /* Update for Derivative: '<S219>/Derivative' */
  if (localDW->TimeStampA_g == (rtInf)) {
    localDW->TimeStampA_g = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA_j;
  } else if (localDW->TimeStampB_a == (rtInf)) {
    localDW->TimeStampB_a = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB_l;
  } else if (localDW->TimeStampA_g < localDW->TimeStampB_a) {
    localDW->TimeStampA_g = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeA_j;
  } else {
    localDW->TimeStampB_a = (&ConfiguredVirtualVehicleMode_M)->Timing.t[0];
    lastU = &localDW->LastUAtTimeB_l;
  }

  *lastU = localB->Gain2_j;

  /* End of Update for Derivative: '<S219>/Derivative' */
  if (rtmIsMajorTimeStep((&ConfiguredVirtualVehicleMode_M)) &&
      (&ConfiguredVirtualVehicleMode_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory generated from: '<S220>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_c = localB->Memory_e;

    /* Update for Memory generated from: '<S220>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_g = localB->Memory1_c;

    /* Update for Memory generated from: '<S221>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_a = localB->Memory_g;

    /* Update for Memory generated from: '<S221>/Triggered Subsystem' */
    localDW->TmpLatchAtTriggeredSubsystemI_i = localB->Memory1_j;

    /* Update for Memory: '<S220>/Memory' */
    localDW->Memory_PreviousInput_o = localB->EnabledSubsystem_g.y;

    /* Update for Memory: '<S220>/Memory1' */
    localDW->Memory1_PreviousInput_f = localB->EnabledSubsystem1_i.y;

    /* Update for Memory: '<S221>/Memory' */
    localDW->Memory_PreviousInput_h = localB->EnabledSubsystem_n.y;

    /* Update for Memory: '<S221>/Memory1' */
    localDW->Memory1_PreviousInput_m = localB->EnabledSubsystem1_j.y;

    /* Update for Memory: '<S602>/Memory' incorporates:
     *  Constant: '<S602>/Reset'
     */
    localDW->Memory_PreviousInput_l = localP->Reset_Value_d;
  }

  /* Update for Integrator: '<S602>/Integrator' */
  localDW->Integrator_IWORK_g = 0;

  /* Update for Integrator: '<S553>/Integrator' */
  localDW->Integrator_IWORK_d = 0;

  /* Update for Integrator: '<S644>/Integrator' */
  localDW->Integrator_IWORK_a = 0;

  /* Update for Integrator: '<S633>/Integrator Limited' */
  localDW->IntegratorLimited_IWORK = 0;
}

/* Derivatives for atomic system: '<Root>/AdasPlantModel' */
void ConfiguredVirtualVehicleModel::Configured_AdasPlantModel_Deriv
  (B_AdasPlantModel_ConfiguredVi_T *localB, DW_AdasPlantModel_ConfiguredV_T
   *localDW, P_AdasPlantModel_ConfiguredVi_T *localP,
   P_ConfiguredVirtualVehicleMod_T *ConfiguredVirtualVehicleModel_P,
   X_AdasPlantModel_ConfiguredVi_T *localX, XDot_AdasPlantModel_Configure_T
   *localXdot)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  boolean_T lsat;
  boolean_T usat;

  /* Derivatives for Integrator: '<S631>/Integrator' */
  localXdot->Integrator_CSTATE_p = localB->Sum_l;

  /* Derivatives for Integrator: '<S610>/Integrator' */
  localXdot->Integrator_CSTATE_i = localB->Divide_h;

  /* Derivatives for Integrator: '<S407>/ub,vb,wb' */
  localXdot->ubvbwb_CSTATE[0] = localB->Sum[0];
  localXdot->ubvbwb_CSTATE[1] = localB->Sum[1];
  localXdot->ubvbwb_CSTATE[2] = localB->Sum[2];

  /* Derivatives for Integrator: '<S580>/Integrator' */
  localXdot->Integrator_CSTATE_m = localB->Product_n;

  /* Derivatives for Integrator: '<S579>/Integrator' */
  localXdot->Integrator_CSTATE_f = localB->Subtract_m;

  /* Derivatives for Integrator: '<S588>/Integrator' */
  localXdot->Integrator_CSTATE_j = localB->Product_a;

  /* Derivatives for Integrator: '<S587>/Integrator' */
  localXdot->Integrator_CSTATE_cw = localB->Subtract_g;

  /* Derivatives for Integrator: '<S106>/Integrator1' */
  localXdot->Integrator1_CSTATE_h[0] = localB->Divide[0];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_e[0] = localB->Product1[0];

  /* Derivatives for Integrator: '<S518>/Integrator' */
  localXdot->Integrator_CSTATE_c[0] = localB->Product1_i[0];

  /* Derivatives for Integrator: '<S374>/Integrator1' */
  localXdot->Integrator1_CSTATE_n[0] = localB->Divide_c3[0];

  /* Derivatives for Integrator: '<S520>/Integrator' */
  localXdot->Integrator_CSTATE_cf[0] = localB->Product1_j[0];

  /* Derivatives for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[0] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[0] =
      localX->IntegratorSecondOrder_CSTATE[4];
    localXdot->IntegratorSecondOrder_CSTATE[4] = localB->Gain1[0];
  }

  /* Derivatives for Integrator: '<S106>/Integrator1' */
  localXdot->Integrator1_CSTATE_h[1] = localB->Divide[1];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_e[1] = localB->Product1[1];

  /* Derivatives for Integrator: '<S518>/Integrator' */
  localXdot->Integrator_CSTATE_c[1] = localB->Product1_i[1];

  /* Derivatives for Integrator: '<S374>/Integrator1' */
  localXdot->Integrator1_CSTATE_n[1] = localB->Divide_c3[1];

  /* Derivatives for Integrator: '<S520>/Integrator' */
  localXdot->Integrator_CSTATE_cf[1] = localB->Product1_j[1];

  /* Derivatives for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[1] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[1] =
      localX->IntegratorSecondOrder_CSTATE[5];
    localXdot->IntegratorSecondOrder_CSTATE[5] = localB->Gain1[1];
  }

  /* Derivatives for Integrator: '<S106>/Integrator1' */
  localXdot->Integrator1_CSTATE_h[2] = localB->Divide[2];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_e[2] = localB->Product1[2];

  /* Derivatives for Integrator: '<S518>/Integrator' */
  localXdot->Integrator_CSTATE_c[2] = localB->Product1_i[2];

  /* Derivatives for Integrator: '<S374>/Integrator1' */
  localXdot->Integrator1_CSTATE_n[2] = localB->Divide_c3[2];

  /* Derivatives for Integrator: '<S520>/Integrator' */
  localXdot->Integrator_CSTATE_cf[2] = localB->Product1_j[2];

  /* Derivatives for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[2] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[2] =
      localX->IntegratorSecondOrder_CSTATE[6];
    localXdot->IntegratorSecondOrder_CSTATE[6] = localB->Gain1[2];
  }

  /* Derivatives for Integrator: '<S106>/Integrator1' */
  localXdot->Integrator1_CSTATE_h[3] = localB->Divide[3];

  /* Derivatives for Integrator: '<S517>/Integrator' */
  localXdot->Integrator_CSTATE_e[3] = localB->Product1[3];

  /* Derivatives for Integrator: '<S518>/Integrator' */
  localXdot->Integrator_CSTATE_c[3] = localB->Product1_i[3];

  /* Derivatives for Integrator: '<S374>/Integrator1' */
  localXdot->Integrator1_CSTATE_n[3] = localB->Divide_c3[3];

  /* Derivatives for Integrator: '<S520>/Integrator' */
  localXdot->Integrator_CSTATE_cf[3] = localB->Product1_j[3];

  /* Derivatives for SecondOrderIntegrator: '<S521>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE[3] == 0) {
    localXdot->IntegratorSecondOrder_CSTATE[3] =
      localX->IntegratorSecondOrder_CSTATE[7];
    localXdot->IntegratorSecondOrder_CSTATE[7] = localB->Gain1[3];
  }

  /* Derivatives for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* Derivatives for Iterator SubSystem: '<S523>/Clutch Partitioned Parameters' */
    /* Derivatives for Chart: '<S527>/Clutch' */
    ConfiguredVirtualV_Clutch_Deriv(&localB->CoreSubsys_l[ForEach_itr].sf_Clutch,
      &localDW->CoreSubsys_l[ForEach_itr].sf_Clutch, &localXdot->
      CoreSubsys_l[ForEach_itr].sf_Clutch);

    /* End of Derivatives for SubSystem: '<S523>/Clutch Partitioned Parameters' */
  }

  /* End of Derivatives for SubSystem: '<S523>/Clutch Partitioned Parameters' */
  /* Derivatives for Integrator: '<S407>/p,q,r ' */
  localXdot->pqr_CSTATE[0] = localB->Product2[0];
  localXdot->pqr_CSTATE[1] = localB->Product2[1];
  localXdot->pqr_CSTATE[2] = localB->Product2[2];

  /* Derivatives for Integrator: '<S375>/Integrator1' incorporates:
   *  Product: '<S375>/Divide'
   */
  std::memcpy(&localXdot->Integrator1_CSTATE_e[0], &localB->Divide_b[0], 12U *
              sizeof(real_T));

  /* Derivatives for Integrator: '<S407>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[0] = localB->Product_k[0];

  /* Derivatives for Integrator: '<S413>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[0] = localB->TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S407>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[1] = localB->Product_k[1];

  /* Derivatives for Integrator: '<S413>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[1] = localB->TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S407>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[2] = localB->Product_k[2];

  /* Derivatives for Integrator: '<S413>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[2] = localB->TmpSignalConversionAtphithetaps[2];

  /* Derivatives for SecondOrderIntegrator: '<S158>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_o == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_e[0] =
      localX->IntegratorSecondOrder_CSTATE_e[1];
    localXdot->IntegratorSecondOrder_CSTATE_e[1] = localB->Gain3;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S158>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_d[0] = localB->Divide_c[0];

  /* Derivatives for Integrator: '<S291>/Integrator1' incorporates:
   *  Product: '<S291>/Divide'
   */
  localXdot->Integrator1_CSTATE_nd[0] = localB->Divide_k[0];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_d[1] = localB->Divide_c[1];

  /* Derivatives for Integrator: '<S291>/Integrator1' incorporates:
   *  Product: '<S291>/Divide'
   */
  localXdot->Integrator1_CSTATE_nd[1] = localB->Divide_k[1];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_d[2] = localB->Divide_c[2];

  /* Derivatives for Integrator: '<S291>/Integrator1' incorporates:
   *  Product: '<S291>/Divide'
   */
  localXdot->Integrator1_CSTATE_nd[2] = localB->Divide_k[2];

  /* Derivatives for Integrator: '<S290>/Integrator1' incorporates:
   *  Product: '<S290>/Divide'
   */
  localXdot->Integrator1_CSTATE_d[3] = localB->Divide_c[3];

  /* Derivatives for Integrator: '<S291>/Integrator1' incorporates:
   *  Product: '<S291>/Divide'
   */
  localXdot->Integrator1_CSTATE_nd[3] = localB->Divide_k[3];

  /* Derivatives for SecondOrderIntegrator: '<S140>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_j == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_a[0] =
      localX->IntegratorSecondOrder_CSTATE_a[1];
    localXdot->IntegratorSecondOrder_CSTATE_a[1] = localB->Gain_a;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S140>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S132>/Integrator' */
  lsat = (localX->Integrator_CSTATE_id <= localP->Integrator_LowerSat);
  usat = (localX->Integrator_CSTATE_id >= localP->Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (localB->Subtract2 > 0.0)) || (usat &&
       (localB->Subtract2 < 0.0))) {
    localXdot->Integrator_CSTATE_id = localB->Subtract2;
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_id = 0.0;
  }

  /* End of Derivatives for Integrator: '<S132>/Integrator' */

  /* Derivatives for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_i == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_d[0] =
      localX->IntegratorSecondOrder_CSTATE_d[1];
    localXdot->IntegratorSecondOrder_CSTATE_d[1] = localB->Gain_n;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S139>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S127>/Integrator1' */
  localXdot->Integrator1_CSTATE_nx = localB->Divide_p;

  /* Derivatives for SecondOrderIntegrator: '<S245>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_f == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_k[0] =
      localX->IntegratorSecondOrder_CSTATE_k[1];
    localXdot->IntegratorSecondOrder_CSTATE_k[1] = localB->Gain3_n;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S245>/Integrator, Second-Order' */

  /* Derivatives for SecondOrderIntegrator: '<S227>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_k == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_ak[0] =
      localX->IntegratorSecondOrder_CSTATE_ak[1];
    localXdot->IntegratorSecondOrder_CSTATE_ak[1] = localB->Gain_m;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S227>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S219>/Integrator' */
  lsat = (localX->Integrator_CSTATE_jz <= localP->Integrator_LowerSat_l);
  usat = (localX->Integrator_CSTATE_jz >= localP->Integrator_UpperSat_p);
  if (((!lsat) && (!usat)) || (lsat && (localB->Subtract2_c > 0.0)) || (usat &&
       (localB->Subtract2_c < 0.0))) {
    localXdot->Integrator_CSTATE_jz = localB->Subtract2_c;
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_jz = 0.0;
  }

  /* End of Derivatives for Integrator: '<S219>/Integrator' */

  /* Derivatives for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */
  if (localDW->IntegratorSecondOrder_MODE_io == 0) {
    localXdot->IntegratorSecondOrder_CSTATE_l[0] =
      localX->IntegratorSecondOrder_CSTATE_l[1];
    localXdot->IntegratorSecondOrder_CSTATE_l[1] = localB->Gain_b;
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S226>/Integrator, Second-Order' */

  /* Derivatives for Integrator: '<S214>/Integrator1' */
  localXdot->Integrator1_CSTATE_dc = localB->Divide_jz;

  /* Derivatives for Integrator: '<S393>/Integrator1' */
  localXdot->Integrator1_CSTATE_a[0] = localB->Divide_d[0];
  localXdot->Integrator1_CSTATE_a[1] = localB->Divide_d[1];

  /* Derivatives for Integrator: '<S411>/Integrator' */
  localXdot->Integrator_CSTATE_ez[0] = localB->UnitConversion[0];
  localXdot->Integrator_CSTATE_ez[1] = localB->UnitConversion[1];
  localXdot->Integrator_CSTATE_ez[2] = localB->UnitConversion[2];

  /* Derivatives for Integrator: '<S602>/Integrator' */
  localXdot->Integrator_CSTATE_n = localB->Product_m;

  /* Derivatives for Integrator: '<S601>/Integrator' */
  localXdot->Integrator_CSTATE_e0 = localB->Subtract_gw;

  /* Derivatives for Integrator: '<S553>/Integrator' */
  lsat = (localX->Integrator_CSTATE_d[0] <= localP->Integrator_LowerSat_h);
  usat = (localX->Integrator_CSTATE_d[0] >= localP->Integrator_UpperSat_i);
  if (((!lsat) && (!usat)) || (lsat && (localB->xdot[0] > 0.0)) || (usat &&
       (localB->xdot[0] < 0.0))) {
    localXdot->Integrator_CSTATE_d[0] = localB->xdot[0];
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_d[0] = 0.0;
  }

  lsat = (localX->Integrator_CSTATE_d[1] <= localP->Integrator_LowerSat_h);
  usat = (localX->Integrator_CSTATE_d[1] >= localP->Integrator_UpperSat_i);
  if (((!lsat) && (!usat)) || (lsat && (localB->xdot[1] > 0.0)) || (usat &&
       (localB->xdot[1] < 0.0))) {
    localXdot->Integrator_CSTATE_d[1] = localB->xdot[1];
  } else {
    /* in saturation */
    localXdot->Integrator_CSTATE_d[1] = 0.0;
  }

  /* End of Derivatives for Integrator: '<S553>/Integrator' */

  /* Derivatives for TransferFcn: '<S658>/Motor Coupling Dynamics' */
  localXdot->MotorCouplingDynamics_CSTATE = 0.0;
  localXdot->MotorCouplingDynamics_CSTATE += localP->MotorCouplingDynamics_A *
    localX->MotorCouplingDynamics_CSTATE;
  localXdot->MotorCouplingDynamics_CSTATE += localB->Divide2;

  /* Derivatives for Integrator: '<S644>/Integrator' */
  localXdot->Integrator_CSTATE_a = localB->Sum_o;

  /* Derivatives for Integrator: '<S666>/Integrator' */
  localXdot->Integrator_CSTATE_l = localB->Sum_d;

  /* Derivatives for Integrator: '<S633>/Integrator Limited' */
  lsat = (localX->IntegratorLimited_CSTATE <= localP->IntegratorLimited_LowerSat);
  usat = (localX->IntegratorLimited_CSTATE >=
          ConfiguredVirtualVehicleModel_P->PlntBattChrgMax);
  if (((!lsat) && (!usat)) || (lsat && (localB->Gain1_o > 0.0)) || (usat &&
       (localB->Gain1_o < 0.0))) {
    localXdot->IntegratorLimited_CSTATE = localB->Gain1_o;
  } else {
    /* in saturation */
    localXdot->IntegratorLimited_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S633>/Integrator Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited' */
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

  /* End of Derivatives for SecondOrderIntegrator: '<S684>/Integrator, Second-Order Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' */
  if (localDW->IntegratorSecondOrderLimited__k[0] == 0) {
    localXdot->IntegratorSecondOrderLimited__i[0] =
      localX->IntegratorSecondOrderLimited__i[3];
    localXdot->IntegratorSecondOrderLimited__i[3] = localB->Sum2_c[0];
  }

  if (localDW->IntegratorSecondOrderLimited__k[1] == 0) {
    localXdot->IntegratorSecondOrderLimited__i[1] =
      localX->IntegratorSecondOrderLimited__i[4];
    localXdot->IntegratorSecondOrderLimited__i[4] = localB->Sum2_c[1];
  }

  if (localDW->IntegratorSecondOrderLimited__k[2] == 0) {
    localXdot->IntegratorSecondOrderLimited__i[2] =
      localX->IntegratorSecondOrderLimited__i[5];
    localXdot->IntegratorSecondOrderLimited__i[5] = localB->Sum2_c[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S696>/Integrator, Second-Order Limited' */
}
