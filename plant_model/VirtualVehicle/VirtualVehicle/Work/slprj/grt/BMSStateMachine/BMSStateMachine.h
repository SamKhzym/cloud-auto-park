/*
 * Code generation for system model 'BMSStateMachine'
 * For more details, see corresponding source file BMSStateMachine.c
 *
 */

#ifndef RTW_HEADER_BMSStateMachine_h_
#define RTW_HEADER_BMSStateMachine_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "BMSStateMachine_types.h"
#include <cstring>

/* Block states (default storage) for model 'BMSStateMachine' */
struct DW_BMSStateMachine_T {
  real32_T Delta;                      /* '<Root>/State_Machine' */
  MonitorCellTempModeType MonitorCellTempMode;/* '<Root>/State_Machine' */
  MonitorCellVoltageModeType MonitorCellVoltageMode;/* '<Root>/State_Machine' */
  MonitorCurrLimModeType MonitorCurrLimMode;/* '<Root>/State_Machine' */
  uint16_T temporalCounter_i1;         /* '<Root>/State_Machine' */
  uint16_T temporalCounter_i2;         /* '<Root>/State_Machine' */
  uint16_T temporalCounter_i3;         /* '<Root>/State_Machine' */
  uint8_T is_active_c2_BMSStateMachine;/* '<Root>/State_Machine' */
  uint8_T is_MainStateMachine;         /* '<Root>/State_Machine' */
  uint8_T is_Charging;                 /* '<Root>/State_Machine' */
  uint8_T is_ChargerContactorState;    /* '<Root>/State_Machine' */
  uint8_T is_CloseChgrContactors;      /* '<Root>/State_Machine' */
  uint8_T is_OpenChgrContactors;       /* '<Root>/State_Machine' */
  uint8_T is_InverterContactorState;   /* '<Root>/State_Machine' */
  uint8_T is_CloseInvtrContactors;     /* '<Root>/State_Machine' */
  uint8_T is_OpenInvtrContactors;      /* '<Root>/State_Machine' */
  boolean_T FaultPresent;              /* '<Root>/State_Machine' */
  Contact ChrgCntctState;              /* '<Root>/State_Machine' */
  Contact InvtrCntctState;             /* '<Root>/State_Machine' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BMSStateMachine_T {
  const char_T **errorStatus;
};

/* Class declaration for model BMSStateMachine */
class BMSStateMachine final
{
  /* public data and function members */
 public:
  /* Initial conditions function */
  void init();

  /* Copy Constructor */
  BMSStateMachine(BMSStateMachine const&) = delete;

  /* Assignment Operator */
  BMSStateMachine& operator= (BMSStateMachine const&) & = delete;

  /* Move Constructor */
  BMSStateMachine(BMSStateMachine &&) = delete;

  /* Move Assignment Operator */
  BMSStateMachine& operator= (BMSStateMachine &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_BMSStateMachine_T * getRTM();

  /*member function to setup error status pointer */
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  /* Reset function */
  void reset(real32_T *rty_ChargeCurrentReq, boolean_T
             *rty_ContactorsCmd_PosContactorChgrCmd, boolean_T
             *rty_ContactorsCmd_PreChargeRelayChgrCmd, boolean_T
             *rty_ContactorsCmd_NegContactorChgrCmd, boolean_T
             *rty_ContactorsCmd_PosContactorInvtrCmd, boolean_T
             *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
             *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults,
             real32_T *rty_BMSState);

  /* model step function */
  void step(const real32_T *rtu_StateRequest, const real32_T
            rtu_Sensors_CellVoltages[96], const real32_T
            *rtu_Sensors_PackVoltage, const real32_T *rtu_Sensors_PackCurrent,
            const real32_T *rtu_Sensors_VoutChgr, const real32_T
            *rtu_Sensors_VoutInvtr, const real32_T
            *rtu_CurrentLimits_DischargeCurrentLimit, const real32_T
            *rtu_CurrentLimits_ChargeCurrentLimit, const real32_T
            *rtu_Min_Max_Cells_MinCellVolt, const real32_T
            *rtu_Min_Max_Cells_MaxCellVolt, const real32_T
            *rtu_Min_Max_Cells_MinCellTemp, const real32_T
            *rtu_Min_Max_Cells_MaxCellTemp, real32_T *rty_ChargeCurrentReq,
            boolean_T *rty_ContactorsCmd_PosContactorChgrCmd, boolean_T
            *rty_ContactorsCmd_PreChargeRelayChgrCmd, boolean_T
            *rty_ContactorsCmd_NegContactorChgrCmd, boolean_T
            *rty_ContactorsCmd_PosContactorInvtrCmd, boolean_T
            *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
            *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults,
            real32_T *rty_BMSState);

  /* Constructor */
  BMSStateMachine();

  /* Destructor */
  ~BMSStateMachine();

  /* private data and function members */
 private:
  /* Block states */
  DW_BMSStateMachine_T BMSStateMachine_DW;

  /* private member function(s) for subsystem '<Root>/TmpModelReferenceSubsystem'*/
  void BMSStateMachine_MainStateMachine(const real32_T *rtu_StateRequest, const
    real32_T *rtu_CurrentLimits_ChargeCurrentLimit, const real32_T
    *rtu_Min_Max_Cells_MaxCellVolt, real32_T *rty_ChargeCurrentReq, real32_T
    *rty_BMSState);
  void BMSStateMachine_InverterContactorState(const real32_T *rtu_StateRequest,
    const real32_T *rtu_Sensors_PackVoltage, const real32_T
    *rtu_Sensors_VoutInvtr, boolean_T *rty_ContactorsCmd_PosContactorInvtrCmd,
    boolean_T *rty_ContactorsCmd_PreChargeRelayInvtrCmd, boolean_T
    *rty_ContactorsCmd_NegContactorInvtrCmd, boolean_T *rty_Faults);

  /* Real-Time Model */
  RT_MODEL_BMSStateMachine_T BMSStateMachine_M;
};

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
 * '<Root>' : 'BMSStateMachine'
 * '<S1>'   : 'BMSStateMachine/State_Machine'
 */
#endif                                 /* RTW_HEADER_BMSStateMachine_h_ */
