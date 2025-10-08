/*
 * Code generation for system model 'BMSOut'
 *
 * Model                      : BMSOut
 * Model version              : 6.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:29:10 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "BMSOut.h"
#include "rtwtypes.h"
#include <cstring>
#include "BMSOut_private.h"

/* Output and update for referenced model: 'BMSOut' */
void BMSOut::step(const real32_T *rtu_CurrentLimits_DischargeCurrentLimit, const
                  real32_T *rtu_CurrentLimits_ChargeCurrentLimit, const real32_T
                  *rtu_ChargeCurrentReq, const boolean_T
                  *rtu_Contactors_Cmd_PosContactorChgrCmd, const boolean_T
                  *rtu_Contactors_Cmd_PreChargeRelayChgrCmd, const boolean_T
                  *rtu_Contactors_Cmd_NegContactorChgrCmd, const boolean_T
                  *rtu_Contactors_Cmd_PosContactorInvtrCmd, const boolean_T
                  *rtu_Contactors_Cmd_PreChargeRelayInvtrCmd, const boolean_T
                  *rtu_Contactors_Cmd_NegContactorInvtrCmd, const boolean_T
                  *rtu_Faults, const real32_T *rtu_BMSState, const real32_T
                  *rtu_SOC_SOC_CC, const real32_T *rtu_SOC_SOC_UKF, const
                  real32_T *rtu_SOC_SOC_EKF, const boolean_T rtu_BalCmd[96],
                  real32_T *rty_BMSCommands_CurrentLimitsBus_DischargeCurrentLi,
                  real32_T *rty_BMSCommands_CurrentLimitsBus_ChargeCurrentLimit,
                  real32_T *rty_BMSCommands_ChargeCurrentReq, boolean_T
                  *rty_BMSCommands_ContactorsCmdBus_PosContactorChgrCm,
                  boolean_T *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayChgr,
                  boolean_T *rty_BMSCommands_ContactorsCmdBus_NegContactorChgrCm,
                  boolean_T *rty_BMSCommands_ContactorsCmdBus_PosContactorInvtrC,
                  boolean_T *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayInvt,
                  boolean_T *rty_BMSCommands_ContactorsCmdBus_NegContactorInvtrC,
                  boolean_T rty_BMSCommands_BalCmd[96], boolean_T
                  *rty_BMSInfo_Faults, real32_T *rty_BMSInfo_BMSState, real32_T *
                  rty_BMSInfo_SOC_SOC_CC, real32_T *rty_BMSInfo_SOC_SOC_UKF,
                  real32_T *rty_BMSInfo_SOC_SOC_EKF)
{
  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_CurrentLimitsBus_DischargeCurrentLi =
    *rtu_CurrentLimits_DischargeCurrentLimit;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_CurrentLimitsBus_ChargeCurrentLimit =
    *rtu_CurrentLimits_ChargeCurrentLimit;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ChargeCurrentReq = *rtu_ChargeCurrentReq;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_PosContactorChgrCm =
    *rtu_Contactors_Cmd_PosContactorChgrCmd;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayChgr =
    *rtu_Contactors_Cmd_PreChargeRelayChgrCmd;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_NegContactorChgrCm =
    *rtu_Contactors_Cmd_NegContactorChgrCmd;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_PosContactorInvtrC =
    *rtu_Contactors_Cmd_PosContactorInvtrCmd;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayInvt =
    *rtu_Contactors_Cmd_PreChargeRelayInvtrCmd;

  /* SignalConversion generated from: '<Root>/BMSCommands_Outport_1' */
  *rty_BMSCommands_ContactorsCmdBus_NegContactorInvtrC =
    *rtu_Contactors_Cmd_NegContactorInvtrCmd;

  /* SignalConversion generated from: '<Root>/BMSInfo_Outport_2' */
  *rty_BMSInfo_Faults = *rtu_Faults;

  /* SignalConversion generated from: '<Root>/BMSInfo_Outport_2' */
  *rty_BMSInfo_BMSState = *rtu_BMSState;

  /* SignalConversion generated from: '<Root>/BMSInfo_Outport_2' */
  *rty_BMSInfo_SOC_SOC_CC = *rtu_SOC_SOC_CC;

  /* SignalConversion generated from: '<Root>/BMSInfo_Outport_2' */
  *rty_BMSInfo_SOC_SOC_UKF = *rtu_SOC_SOC_UKF;

  /* SignalConversion generated from: '<Root>/BMSInfo_Outport_2' */
  *rty_BMSInfo_SOC_SOC_EKF = *rtu_SOC_SOC_EKF;

  /* RateTransition: '<Root>/Rate Transition' */
  std::memcpy(&rty_BMSCommands_BalCmd[0], &rtu_BalCmd[0], 96U * sizeof(boolean_T));
}

/* Constructor */
BMSOut::BMSOut() :
  BMSOut_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
BMSOut::~BMSOut() = default;

/* Real-Time Model get method */
RT_MODEL_BMSOut_T * BMSOut::getRTM()
{
  return (&BMSOut_M);
}

/* member function to setup error status pointer */
void BMSOut::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&BMSOut_M), rt_errorStatus);
}
