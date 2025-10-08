/*
 * Code generation for system model 'BMSStateMachine'
 *
 * Model                      : BMSStateMachine
 * Model version              : 6.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:34:59 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "BMSStateMachine.h"
#include "rtwtypes.h"
#include "BMSStateMachine_types.h"
#include <cmath>
#include "BMSStateMachine_private.h"

/* Named constants for Chart: '<Root>/State_Machine' */
const uint8_T BMSStateMachine_IN_CC_Mode{ 1U };

const uint8_T BMSStateMachine_IN_CV_Mode{ 2U };

const uint8_T BMSStateMachine_IN_Charging{ 1U };

const uint8_T BMSStateMachine_IN_CloseChgrContactors{ 1U };

const uint8_T BMSStateMachine_IN_CloseInvtrContactors{ 1U };

const uint8_T BMSStateMachine_IN_CloseNegCntct{ 1U };

const uint8_T BMSStateMachine_IN_ClosePosCntct{ 2U };

const uint8_T BMSStateMachine_IN_ClosePreChrgRly{ 3U };

const uint8_T BMSStateMachine_IN_ClosePreChrgRly_dwpa{ 1U };

const uint8_T BMSStateMachine_IN_Driving{ 2U };

const uint8_T BMSStateMachine_IN_Fault{ 3U };

const uint8_T BMSStateMachine_IN_Init_Mode{ 3U };

const uint8_T BMSStateMachine_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T BMSStateMachine_IN_OpenChgrContactors{ 2U };

const uint8_T BMSStateMachine_IN_OpenInvtrContactors{ 2U };

const uint8_T BMSStateMachine_IN_OpenNegCntct{ 2U };

const uint8_T BMSStateMachine_IN_OpenPosCntct{ 3U };

const uint8_T BMSStateMachine_IN_OpenPreChrgRly{ 4U };

const uint8_T BMSStateMachine_IN_PreChrgFlt{ 5U };

const uint8_T BMSStateMachine_IN_Standby{ 4U };

/* Function for Chart: '<Root>/State_Machine' */
void BMSStateMachine::BMSStateMachine_MainStateMachine(const real32_T
  *rtu_StateRequest, const real32_T *rtu_CurrentLimits_ChargeCurrentLimit, const
  real32_T *rtu_Min_Max_Cells_MaxCellVolt, real32_T *rty_ChargeCurrentReq,
  real32_T *rty_BMSState)
{
  boolean_T e_out;
  switch (BMSStateMachine_DW.is_MainStateMachine) {
   case BMSStateMachine_IN_Charging:
    if (BMSStateMachine_DW.FaultPresent) {
      /* Chart: '<Root>/State_Machine' */
      *rty_ChargeCurrentReq = 0.0F;
      BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_NO_ACTIVE_CHILD;
      BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Fault;

      /* Chart: '<Root>/State_Machine' */
      *rty_BMSState = 3.0F;
    } else {
      /* Chart: '<Root>/State_Machine' */
      e_out = ((*rtu_StateRequest == 2.0F) &&
               (BMSStateMachine_DW.InvtrCntctState == Contact::Close));
      if (e_out) {
        BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_NO_ACTIVE_CHILD;
        BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Driving;

        /* Chart: '<Root>/State_Machine' */
        *rty_BMSState = 2.0F;
      } else {
        /* Chart: '<Root>/State_Machine' */
        e_out = ((*rtu_StateRequest != 1.0F) &&
                 (BMSStateMachine_DW.ChrgCntctState == Contact::Init));
        if (e_out) {
          BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_NO_ACTIVE_CHILD;
          BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Standby;

          /* Chart: '<Root>/State_Machine' */
          *rty_BMSState = 0.0F;
        } else {
          switch (BMSStateMachine_DW.is_Charging) {
           case BMSStateMachine_IN_CC_Mode:
            /* Chart: '<Root>/State_Machine' */
            if (*rtu_StateRequest != 1.0F) {
              BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_Init_Mode;
              *rty_ChargeCurrentReq = 0.0F;
            } else if (*rtu_Min_Max_Cells_MaxCellVolt >= 4.2F) {
              BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_CV_Mode;
            } else {
              *rty_ChargeCurrentReq = std::fmin(30.0F,
                *rtu_CurrentLimits_ChargeCurrentLimit);
            }
            break;

           case BMSStateMachine_IN_CV_Mode:
            /* Chart: '<Root>/State_Machine' */
            if ((*rtu_StateRequest != 1.0F) || (*rty_ChargeCurrentReq <= 30.0F /
                 10.0F)) {
              BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_Init_Mode;
              *rty_ChargeCurrentReq = 0.0F;
            } else {
              *rty_ChargeCurrentReq -= (*rtu_Min_Max_Cells_MaxCellVolt - 4.2F) *
                0.2F;
              *rty_ChargeCurrentReq = std::fmin(*rty_ChargeCurrentReq,
                *rtu_CurrentLimits_ChargeCurrentLimit);
            }
            break;

           default:
            /* Chart: '<Root>/State_Machine' */
            /* case IN_Init_Mode: */
            e_out = ((*rtu_StateRequest == 1.0F) &&
                     (*rtu_Min_Max_Cells_MaxCellVolt < 4.1F));
            if (e_out) {
              BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_CC_Mode;
            }
            break;
          }
        }
      }
    }
    break;

   case BMSStateMachine_IN_Driving:
    if (BMSStateMachine_DW.FaultPresent) {
      BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Fault;

      /* Chart: '<Root>/State_Machine' */
      *rty_BMSState = 3.0F;
    } else {
      /* Chart: '<Root>/State_Machine' */
      e_out = ((*rtu_StateRequest == 1.0F) && (BMSStateMachine_DW.ChrgCntctState
                == Contact::Close));
      if (e_out) {
        BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Charging;

        /* Chart: '<Root>/State_Machine' */
        *rty_BMSState = 1.0F;
        BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_Init_Mode;

        /* Chart: '<Root>/State_Machine' */
        *rty_ChargeCurrentReq = 0.0F;
      } else {
        /* Chart: '<Root>/State_Machine' */
        e_out = ((*rtu_StateRequest != 2.0F) &&
                 (BMSStateMachine_DW.InvtrCntctState == Contact::Init));
        if (e_out) {
          BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Standby;

          /* Chart: '<Root>/State_Machine' */
          *rty_BMSState = 0.0F;
        }
      }
    }
    break;

   case BMSStateMachine_IN_Fault:
    /* Chart: '<Root>/State_Machine' */
    *rty_BMSState = 3.0F;
    break;

   default:
    /* case IN_Standby: */
    if (BMSStateMachine_DW.FaultPresent) {
      BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Fault;

      /* Chart: '<Root>/State_Machine' */
      *rty_BMSState = 3.0F;
    } else {
      /* Chart: '<Root>/State_Machine' */
      e_out = ((*rtu_StateRequest == 1.0F) && (BMSStateMachine_DW.ChrgCntctState
                == Contact::Close));
      if (e_out) {
        BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Charging;

        /* Chart: '<Root>/State_Machine' */
        *rty_BMSState = 1.0F;
        BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_Init_Mode;

        /* Chart: '<Root>/State_Machine' */
        *rty_ChargeCurrentReq = 0.0F;
      } else {
        /* Chart: '<Root>/State_Machine' */
        e_out = ((*rtu_StateRequest == 2.0F) &&
                 (BMSStateMachine_DW.InvtrCntctState == Contact::Close));
        if (e_out) {
          BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Driving;

          /* Chart: '<Root>/State_Machine' */
          *rty_BMSState = 2.0F;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<Root>/State_Machine' */
void BMSStateMachine::BMSStateMachine_InverterContactorState(const real32_T
  *rtu_StateRequest, const real32_T *rtu_Sensors_PackVoltage, const real32_T
  *rtu_Sensors_VoutInvtr, boolean_T *rty_ContactorsCmd_PosContactorInvtrCmd,
  boolean_T *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
  *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults)
{
  boolean_T b_out;
  if (BMSStateMachine_DW.is_InverterContactorState ==
      BMSStateMachine_IN_CloseInvtrContactors) {
    /* Chart: '<Root>/State_Machine' */
    b_out = ((*rtu_StateRequest != 2.0F) || BMSStateMachine_DW.FaultPresent);
    if (b_out) {
      BMSStateMachine_DW.is_CloseInvtrContactors =
        BMSStateMachine_IN_NO_ACTIVE_CHILD;
      BMSStateMachine_DW.is_InverterContactorState =
        BMSStateMachine_IN_OpenInvtrContactors;
      BMSStateMachine_DW.InvtrCntctState = Contact::Init;
      BMSStateMachine_DW.is_OpenInvtrContactors =
        BMSStateMachine_IN_ClosePreChrgRly_dwpa;
      BMSStateMachine_DW.temporalCounter_i3 = 0U;

      /* Chart: '<Root>/State_Machine' */
      *rty_ContactorsCmd_PreChargeRelayInvtrCmd = true;
    } else {
      switch (BMSStateMachine_DW.is_CloseInvtrContactors) {
       case BMSStateMachine_IN_CloseNegCntct:
        if (BMSStateMachine_DW.temporalCounter_i3 * 100 >= (static_cast<uint16_T>
             (200U))) {
          BMSStateMachine_DW.is_CloseInvtrContactors =
            BMSStateMachine_IN_ClosePreChrgRly;
          BMSStateMachine_DW.temporalCounter_i3 = 0U;

          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = true;
        } else {
          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_NegContactorInvtrCmd = true;
        }
        break;

       case BMSStateMachine_IN_ClosePosCntct:
        if (BMSStateMachine_DW.temporalCounter_i3 * 100 >= (static_cast<uint16_T>
             (200U))) {
          BMSStateMachine_DW.is_CloseInvtrContactors =
            BMSStateMachine_IN_OpenPreChrgRly;

          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = false;
          BMSStateMachine_DW.InvtrCntctState = Contact::Close;
        } else {
          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PosContactorInvtrCmd = true;
        }
        break;

       case BMSStateMachine_IN_ClosePreChrgRly:
        /* Chart: '<Root>/State_Machine' */
        if (*rtu_Sensors_VoutInvtr / *rtu_Sensors_PackVoltage >= 0.95F) {
          BMSStateMachine_DW.is_CloseInvtrContactors =
            BMSStateMachine_IN_ClosePosCntct;
          BMSStateMachine_DW.temporalCounter_i3 = 0U;
          *rty_ContactorsCmd_PosContactorInvtrCmd = true;
        } else if (BMSStateMachine_DW.temporalCounter_i3 >= (static_cast<uint8_T>
                    (1U)) * 10) {
          BMSStateMachine_DW.is_CloseInvtrContactors =
            BMSStateMachine_IN_PreChrgFlt;
          *rty_Faults = true;
        } else {
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = true;
        }
        break;

       case BMSStateMachine_IN_OpenPreChrgRly:
        /* Chart: '<Root>/State_Machine' */
        *rty_ContactorsCmd_PreChargeRelayInvtrCmd = false;
        BMSStateMachine_DW.InvtrCntctState = Contact::Close;
        break;

       default:
        /* Chart: '<Root>/State_Machine' */
        /* case IN_PreChrgFlt: */
        *rty_Faults = true;
        break;
      }
    }
  } else {
    /* Chart: '<Root>/State_Machine' */
    /* case IN_OpenInvtrContactors: */
    b_out = ((*rtu_StateRequest == 2.0F) && (BMSStateMachine_DW.ChrgCntctState ==
              Contact::Open) && (!BMSStateMachine_DW.FaultPresent));
    if (b_out) {
      BMSStateMachine_DW.is_OpenInvtrContactors =
        BMSStateMachine_IN_NO_ACTIVE_CHILD;
      BMSStateMachine_DW.is_InverterContactorState =
        BMSStateMachine_IN_CloseInvtrContactors;
      BMSStateMachine_DW.InvtrCntctState = Contact::Init;
      BMSStateMachine_DW.is_CloseInvtrContactors =
        BMSStateMachine_IN_CloseNegCntct;
      BMSStateMachine_DW.temporalCounter_i3 = 0U;

      /* Chart: '<Root>/State_Machine' */
      *rty_ContactorsCmd_NegContactorInvtrCmd = true;
    } else {
      switch (BMSStateMachine_DW.is_OpenInvtrContactors) {
       case BMSStateMachine_IN_ClosePreChrgRly_dwpa:
        if (BMSStateMachine_DW.temporalCounter_i3 * 100 >= (static_cast<uint16_T>
             (200U))) {
          BMSStateMachine_DW.is_OpenInvtrContactors =
            BMSStateMachine_IN_OpenPosCntct;
          BMSStateMachine_DW.temporalCounter_i3 = 0U;

          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PosContactorInvtrCmd = false;
        } else {
          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = true;
        }
        break;

       case BMSStateMachine_IN_OpenNegCntct:
        /* Chart: '<Root>/State_Machine' */
        *rty_ContactorsCmd_NegContactorInvtrCmd = false;
        BMSStateMachine_DW.InvtrCntctState = Contact::Open;

        /* Chart: '<Root>/State_Machine' */
        *rty_Faults = false;
        break;

       case BMSStateMachine_IN_OpenPosCntct:
        if (BMSStateMachine_DW.temporalCounter_i3 * 100 >= (static_cast<uint16_T>
             (200U))) {
          BMSStateMachine_DW.is_OpenInvtrContactors =
            BMSStateMachine_IN_OpenPreChrgRly;
          BMSStateMachine_DW.temporalCounter_i3 = 0U;

          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = false;
        } else {
          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PosContactorInvtrCmd = false;
        }
        break;

       default:
        /* case IN_OpenPreChrgRly: */
        if (BMSStateMachine_DW.temporalCounter_i3 * 100 >= (static_cast<uint16_T>
             (200U))) {
          BMSStateMachine_DW.is_OpenInvtrContactors =
            BMSStateMachine_IN_OpenNegCntct;

          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_NegContactorInvtrCmd = false;
          BMSStateMachine_DW.InvtrCntctState = Contact::Open;

          /* Chart: '<Root>/State_Machine' */
          *rty_Faults = false;
        } else {
          /* Chart: '<Root>/State_Machine' */
          *rty_ContactorsCmd_PreChargeRelayInvtrCmd = false;
        }
        break;
      }
    }
  }
}

/* System initialize for referenced model: 'BMSStateMachine' */
void BMSStateMachine::init(void)
{
  /* SystemInitialize for Chart: '<Root>/State_Machine' */
  BMSStateMachine_DW.ChrgCntctState = Contact::Open;
  BMSStateMachine_DW.InvtrCntctState = Contact::Open;
}

/* System reset for referenced model: 'BMSStateMachine' */
void BMSStateMachine::reset(real32_T *rty_ChargeCurrentReq, boolean_T
  *rty_ContactorsCmd_PosContactorChgrCmd, boolean_T
  *rty_ContactorsCmd_PreChargeRelayChgrCmd, boolean_T
  *rty_ContactorsCmd_NegContactorChgrCmd, boolean_T
  *rty_ContactorsCmd_PosContactorInvtrCmd, boolean_T
  *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
  *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults, real32_T
  *rty_BMSState)
{
  /* SystemReset for Chart: '<Root>/State_Machine' */
  BMSStateMachine_DW.is_ChargerContactorState =
    BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_CloseChgrContactors = BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_OpenChgrContactors = BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.temporalCounter_i2 = 0U;
  BMSStateMachine_DW.temporalCounter_i1 = 0U;
  BMSStateMachine_DW.is_InverterContactorState =
    BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_CloseInvtrContactors =
    BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_OpenInvtrContactors = BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.temporalCounter_i3 = 0U;
  BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_Charging = BMSStateMachine_IN_NO_ACTIVE_CHILD;
  BMSStateMachine_DW.is_active_c2_BMSStateMachine = 0U;
  BMSStateMachine_DW.ChrgCntctState = Contact::Open;
  BMSStateMachine_DW.InvtrCntctState = Contact::Open;
  BMSStateMachine_DW.FaultPresent = false;
  BMSStateMachine_DW.Delta = 0.0F;
  BMSStateMachine_DW.MonitorCurrLimMode = MonitorCurrLimModeType::None;
  BMSStateMachine_DW.MonitorCellVoltageMode = MonitorCellVoltageModeType::None;
  BMSStateMachine_DW.MonitorCellTempMode = MonitorCellTempModeType::None;
  *rty_ChargeCurrentReq = 0.0F;
  *rty_BMSState = 0.0F;
  *rty_ContactorsCmd_PosContactorChgrCmd = false;
  *rty_ContactorsCmd_PreChargeRelayChgrCmd = false;
  *rty_ContactorsCmd_NegContactorChgrCmd = false;
  *rty_ContactorsCmd_PosContactorInvtrCmd = false;
  *rty_ContactorsCmd_PreChargeRelayInvtrCmd = false;
  *rty_ContactorsCmd_NegContactorInvtrCmd = false;
  *rty_Faults = false;
}

/* Output and update for referenced model: 'BMSStateMachine' */
void BMSStateMachine::step(const real32_T *rtu_StateRequest, const real32_T
  rtu_Sensors_CellVoltages[96], const real32_T *rtu_Sensors_PackVoltage, const
  real32_T *rtu_Sensors_PackCurrent, const real32_T *rtu_Sensors_VoutChgr, const
  real32_T *rtu_Sensors_VoutInvtr, const real32_T
  *rtu_CurrentLimits_DischargeCurrentLimit, const real32_T
  *rtu_CurrentLimits_ChargeCurrentLimit, const real32_T
  *rtu_Min_Max_Cells_MinCellVolt, const real32_T *rtu_Min_Max_Cells_MaxCellVolt,
  const real32_T *rtu_Min_Max_Cells_MinCellTemp, const real32_T
  *rtu_Min_Max_Cells_MaxCellTemp, real32_T *rty_ChargeCurrentReq, boolean_T
  *rty_ContactorsCmd_PosContactorChgrCmd, boolean_T
  *rty_ContactorsCmd_PreChargeRelayChgrCmd, boolean_T
  *rty_ContactorsCmd_NegContactorChgrCmd, boolean_T
  *rty_ContactorsCmd_PosContactorInvtrCmd, boolean_T
  *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
  *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults, real32_T
  *rty_BMSState)
{
  int32_T k;
  real32_T y;
  boolean_T b_out;

  /* Chart: '<Root>/State_Machine' */
  if (BMSStateMachine_DW.temporalCounter_i1 < 4095U) {
    BMSStateMachine_DW.temporalCounter_i1 = static_cast<uint16_T>
      (BMSStateMachine_DW.temporalCounter_i1 + 1U);
  }

  if (BMSStateMachine_DW.temporalCounter_i2 < 4095U) {
    BMSStateMachine_DW.temporalCounter_i2 = static_cast<uint16_T>
      (BMSStateMachine_DW.temporalCounter_i2 + 1U);
  }

  if (BMSStateMachine_DW.temporalCounter_i3 < 4095U) {
    BMSStateMachine_DW.temporalCounter_i3 = static_cast<uint16_T>
      (BMSStateMachine_DW.temporalCounter_i3 + 1U);
  }

  if (BMSStateMachine_DW.is_active_c2_BMSStateMachine == 0U) {
    BMSStateMachine_DW.is_active_c2_BMSStateMachine = 1U;
    BMSStateMachine_DW.is_MainStateMachine = BMSStateMachine_IN_Standby;
    *rty_BMSState = 0.0F;
    BMSStateMachine_DW.is_ChargerContactorState =
      BMSStateMachine_IN_OpenChgrContactors;
    BMSStateMachine_DW.ChrgCntctState = Contact::Init;
    BMSStateMachine_DW.is_OpenChgrContactors =
      BMSStateMachine_IN_ClosePreChrgRly_dwpa;
    BMSStateMachine_DW.temporalCounter_i2 = 0U;
    *rty_ContactorsCmd_PreChargeRelayChgrCmd = true;
    BMSStateMachine_DW.is_InverterContactorState =
      BMSStateMachine_IN_OpenInvtrContactors;
    BMSStateMachine_DW.InvtrCntctState = Contact::Init;
    BMSStateMachine_DW.is_OpenInvtrContactors =
      BMSStateMachine_IN_ClosePreChrgRly_dwpa;
    BMSStateMachine_DW.temporalCounter_i3 = 0U;
    *rty_ContactorsCmd_PreChargeRelayInvtrCmd = true;
    BMSStateMachine_DW.MonitorCurrLimMode = MonitorCurrLimModeType::
      NoCurrLimFault;
    BMSStateMachine_DW.MonitorCellVoltageMode = MonitorCellVoltageModeType::
      NoCellVoltFault;
    y = rtu_Sensors_CellVoltages[0];
    for (k = 0; k < 95; k++) {
      y += rtu_Sensors_CellVoltages[k + 1];
    }

    BMSStateMachine_DW.Delta = std::abs(*rtu_Sensors_PackVoltage - y);
    BMSStateMachine_DW.FaultPresent = false;
    *rty_Faults = false;
    BMSStateMachine_DW.MonitorCellTempMode = MonitorCellTempModeType::
      NoCellTempFault;
  } else {
    BMSStateMachine_MainStateMachine(rtu_StateRequest,
      rtu_CurrentLimits_ChargeCurrentLimit, rtu_Min_Max_Cells_MaxCellVolt,
      rty_ChargeCurrentReq, rty_BMSState);
    if (BMSStateMachine_DW.is_ChargerContactorState ==
        BMSStateMachine_IN_CloseChgrContactors) {
      b_out = ((*rtu_StateRequest != 1.0F) || BMSStateMachine_DW.FaultPresent);
      if (b_out) {
        BMSStateMachine_DW.is_CloseChgrContactors =
          BMSStateMachine_IN_NO_ACTIVE_CHILD;
        BMSStateMachine_DW.is_ChargerContactorState =
          BMSStateMachine_IN_OpenChgrContactors;
        BMSStateMachine_DW.ChrgCntctState = Contact::Init;
        BMSStateMachine_DW.is_OpenChgrContactors =
          BMSStateMachine_IN_ClosePreChrgRly_dwpa;
        BMSStateMachine_DW.temporalCounter_i2 = 0U;
        *rty_ContactorsCmd_PreChargeRelayChgrCmd = true;
      } else {
        switch (BMSStateMachine_DW.is_CloseChgrContactors) {
         case BMSStateMachine_IN_CloseNegCntct:
          if (BMSStateMachine_DW.temporalCounter_i2 * 100 >=
              (static_cast<uint16_T>(200U))) {
            BMSStateMachine_DW.is_CloseChgrContactors =
              BMSStateMachine_IN_ClosePreChrgRly;
            BMSStateMachine_DW.temporalCounter_i2 = 0U;
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = true;
          } else {
            *rty_ContactorsCmd_NegContactorChgrCmd = true;
          }
          break;

         case BMSStateMachine_IN_ClosePosCntct:
          if (BMSStateMachine_DW.temporalCounter_i2 * 100 >=
              (static_cast<uint16_T>(200U))) {
            BMSStateMachine_DW.is_CloseChgrContactors =
              BMSStateMachine_IN_OpenPreChrgRly;
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = false;
            BMSStateMachine_DW.ChrgCntctState = Contact::Close;
          } else {
            *rty_ContactorsCmd_PosContactorChgrCmd = true;
          }
          break;

         case BMSStateMachine_IN_ClosePreChrgRly:
          if (*rtu_Sensors_VoutChgr / *rtu_Sensors_PackVoltage >= 0.95F) {
            BMSStateMachine_DW.is_CloseChgrContactors =
              BMSStateMachine_IN_ClosePosCntct;
            BMSStateMachine_DW.temporalCounter_i2 = 0U;
            *rty_ContactorsCmd_PosContactorChgrCmd = true;
          } else if (BMSStateMachine_DW.temporalCounter_i2 >= (static_cast<
                      uint8_T>(1U)) * 10) {
            BMSStateMachine_DW.is_CloseChgrContactors =
              BMSStateMachine_IN_PreChrgFlt;
            *rty_Faults = true;
          } else {
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = true;
          }
          break;

         case BMSStateMachine_IN_OpenPreChrgRly:
          *rty_ContactorsCmd_PreChargeRelayChgrCmd = false;
          BMSStateMachine_DW.ChrgCntctState = Contact::Close;
          break;

         default:
          /* case IN_PreChrgFlt: */
          *rty_Faults = true;
          break;
        }
      }
    } else {
      /* case IN_OpenChgrContactors: */
      b_out = ((*rtu_StateRequest == 1.0F) &&
               (BMSStateMachine_DW.InvtrCntctState == Contact::Open) &&
               (!BMSStateMachine_DW.FaultPresent));
      if (b_out) {
        BMSStateMachine_DW.is_OpenChgrContactors =
          BMSStateMachine_IN_NO_ACTIVE_CHILD;
        BMSStateMachine_DW.is_ChargerContactorState =
          BMSStateMachine_IN_CloseChgrContactors;
        BMSStateMachine_DW.ChrgCntctState = Contact::Init;
        BMSStateMachine_DW.is_CloseChgrContactors =
          BMSStateMachine_IN_CloseNegCntct;
        BMSStateMachine_DW.temporalCounter_i2 = 0U;
        *rty_ContactorsCmd_NegContactorChgrCmd = true;
      } else {
        switch (BMSStateMachine_DW.is_OpenChgrContactors) {
         case BMSStateMachine_IN_ClosePreChrgRly_dwpa:
          if (BMSStateMachine_DW.temporalCounter_i2 * 100 >=
              (static_cast<uint16_T>(200U))) {
            BMSStateMachine_DW.is_OpenChgrContactors =
              BMSStateMachine_IN_OpenPosCntct;
            BMSStateMachine_DW.temporalCounter_i2 = 0U;
            *rty_ContactorsCmd_PosContactorChgrCmd = false;
          } else {
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = true;
          }
          break;

         case BMSStateMachine_IN_OpenNegCntct:
          *rty_ContactorsCmd_NegContactorChgrCmd = false;
          BMSStateMachine_DW.ChrgCntctState = Contact::Open;
          *rty_Faults = false;
          break;

         case BMSStateMachine_IN_OpenPosCntct:
          if (BMSStateMachine_DW.temporalCounter_i2 * 100 >=
              (static_cast<uint16_T>(200U))) {
            BMSStateMachine_DW.is_OpenChgrContactors =
              BMSStateMachine_IN_OpenPreChrgRly;
            BMSStateMachine_DW.temporalCounter_i2 = 0U;
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = false;
          } else {
            *rty_ContactorsCmd_PosContactorChgrCmd = false;
          }
          break;

         default:
          /* case IN_OpenPreChrgRly: */
          if (BMSStateMachine_DW.temporalCounter_i2 * 100 >=
              (static_cast<uint16_T>(200U))) {
            BMSStateMachine_DW.is_OpenChgrContactors =
              BMSStateMachine_IN_OpenNegCntct;
            *rty_ContactorsCmd_NegContactorChgrCmd = false;
            BMSStateMachine_DW.ChrgCntctState = Contact::Open;
            *rty_Faults = false;
          } else {
            *rty_ContactorsCmd_PreChargeRelayChgrCmd = false;
          }
          break;
        }
      }
    }

    BMSStateMachine_InverterContactorState(rtu_StateRequest,
      rtu_Sensors_PackVoltage, rtu_Sensors_VoutInvtr,
      rty_ContactorsCmd_PosContactorInvtrCmd,
      rty_ContactorsCmd_PreChargeRelayInvtrCmd,
      rty_ContactorsCmd_NegContactorInvtrCmd, rty_Faults);
    switch (BMSStateMachine_DW.MonitorCurrLimMode) {
     case MonitorCurrLimModeType::NoCurrLimFault:
      b_out = ((*rtu_Sensors_PackCurrent <
                *rtu_CurrentLimits_DischargeCurrentLimit) ||
               (*rtu_Sensors_PackCurrent > *rtu_CurrentLimits_ChargeCurrentLimit));
      if (b_out) {
        BMSStateMachine_DW.MonitorCurrLimMode = MonitorCurrLimModeType::Wait;
        BMSStateMachine_DW.temporalCounter_i1 = 0U;
      }
      break;

     case MonitorCurrLimModeType::OverCurrentFault:
      break;

     default:
      /* State Wait */
      if (BMSStateMachine_DW.temporalCounter_i1 >= (static_cast<uint8_T>(1U)) *
          10) {
        BMSStateMachine_DW.MonitorCurrLimMode = MonitorCurrLimModeType::
          OverCurrentFault;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      } else {
        b_out = ((*rtu_Sensors_PackCurrent >=
                  *rtu_CurrentLimits_DischargeCurrentLimit) &&
                 (*rtu_Sensors_PackCurrent <=
                  *rtu_CurrentLimits_ChargeCurrentLimit));
        if (b_out) {
          BMSStateMachine_DW.MonitorCurrLimMode = MonitorCurrLimModeType::
            NoCurrLimFault;
        }
      }
      break;
    }

    switch (BMSStateMachine_DW.MonitorCellVoltageMode) {
     case MonitorCellVoltageModeType::NoCellVoltFault:
      if (*rtu_Min_Max_Cells_MaxCellVolt >= 4.2F) {
        BMSStateMachine_DW.MonitorCellVoltageMode = MonitorCellVoltageModeType::
          OverVoltageFault;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      } else if (BMSStateMachine_DW.Delta >= static_cast<real32_T>
                 (0.25200000000000006)) {
        BMSStateMachine_DW.MonitorCellVoltageMode = MonitorCellVoltageModeType::
          SensorFaut;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      } else if (*rtu_Min_Max_Cells_MinCellVolt <= 2.5F) {
        BMSStateMachine_DW.MonitorCellVoltageMode = MonitorCellVoltageModeType::
          UnderVoltageFault;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      } else {
        y = rtu_Sensors_CellVoltages[0];
        for (k = 0; k < 95; k++) {
          y += rtu_Sensors_CellVoltages[k + 1];
        }

        BMSStateMachine_DW.Delta = std::abs(*rtu_Sensors_PackVoltage - y);
      }
      break;

     case MonitorCellVoltageModeType::OverVoltageFault:
     case MonitorCellVoltageModeType::SensorFaut:
      break;

     default:
      /* State UnderVoltageFault */
      break;
    }

    switch (BMSStateMachine_DW.MonitorCellTempMode) {
     case MonitorCellTempModeType::HighTemperatureFault:
     case MonitorCellTempModeType::LowTemperatureFault:
      break;

     default:
      /* State NoCellTempFault */
      if (*rtu_Min_Max_Cells_MaxCellTemp >= 50.0F) {
        BMSStateMachine_DW.MonitorCellTempMode = MonitorCellTempModeType::
          HighTemperatureFault;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      } else if (*rtu_Min_Max_Cells_MinCellTemp <= 5.0F) {
        BMSStateMachine_DW.MonitorCellTempMode = MonitorCellTempModeType::
          LowTemperatureFault;
        BMSStateMachine_DW.FaultPresent = true;
        *rty_Faults = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/State_Machine' */
}

/* Constructor */
BMSStateMachine::BMSStateMachine() :
  BMSStateMachine_DW(),
  BMSStateMachine_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
BMSStateMachine::~BMSStateMachine() = default;

/* Real-Time Model get method */
RT_MODEL_BMSStateMachine_T * BMSStateMachine::getRTM()
{
  return (&BMSStateMachine_M);
}

/* member function to setup error status pointer */
void BMSStateMachine::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&BMSStateMachine_M), rt_errorStatus);
}
