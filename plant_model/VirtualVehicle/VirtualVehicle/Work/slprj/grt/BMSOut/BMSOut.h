/*
 * Code generation for system model 'BMSOut'
 * For more details, see corresponding source file BMSOut.c
 *
 */

#ifndef RTW_HEADER_BMSOut_h_
#define RTW_HEADER_BMSOut_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "BMSOut_types.h"
#include <cstring>

/* Real-time Model Data Structure */
struct tag_RTM_BMSOut_T {
  const char_T **errorStatus;
};

/* Class declaration for model BMSOut */
class BMSOut final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  BMSOut(BMSOut const&) = delete;

  /* Assignment Operator */
  BMSOut& operator= (BMSOut const&) & = delete;

  /* Move Constructor */
  BMSOut(BMSOut &&) = delete;

  /* Move Assignment Operator */
  BMSOut& operator= (BMSOut &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_BMSOut_T * getRTM();

  /*member function to setup error status pointer */
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  /* model step function */
  void step(const real32_T *rtu_CurrentLimits_DischargeCurrentLimit, const
            real32_T *rtu_CurrentLimits_ChargeCurrentLimit, const real32_T
            *rtu_ChargeCurrentReq, const boolean_T
            *rtu_Contactors_Cmd_PosContactorChgrCmd, const boolean_T
            *rtu_Contactors_Cmd_PreChargeRelayChgrCmd, const boolean_T
            *rtu_Contactors_Cmd_NegContactorChgrCmd, const boolean_T
            *rtu_Contactors_Cmd_PosContactorInvtrCmd, const boolean_T
            *rtu_Contactors_Cmd_PreChargeRelayInvtrCmd, const boolean_T
            *rtu_Contactors_Cmd_NegContactorInvtrCmd, const boolean_T
            *rtu_Faults, const real32_T *rtu_BMSState, const real32_T
            *rtu_SOC_SOC_CC, const real32_T *rtu_SOC_SOC_UKF, const real32_T
            *rtu_SOC_SOC_EKF, const boolean_T rtu_BalCmd[96], real32_T
            *rty_BMSCommands_CurrentLimitsBus_DischargeCurrentLi, real32_T
            *rty_BMSCommands_CurrentLimitsBus_ChargeCurrentLimit, real32_T
            *rty_BMSCommands_ChargeCurrentReq, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_PosContactorChgrCm, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayChgr, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_NegContactorChgrCm, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_PosContactorInvtrC, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_PreChargeRelayInvt, boolean_T
            *rty_BMSCommands_ContactorsCmdBus_NegContactorInvtrC, boolean_T
            rty_BMSCommands_BalCmd[96], boolean_T *rty_BMSInfo_Faults, real32_T *
            rty_BMSInfo_BMSState, real32_T *rty_BMSInfo_SOC_SOC_CC, real32_T
            *rty_BMSInfo_SOC_SOC_UKF, real32_T *rty_BMSInfo_SOC_SOC_EKF);

  /* Constructor */
  BMSOut();

  /* Destructor */
  ~BMSOut();

  /* private data and function members */
 private:
  /* Real-Time Model */
  RT_MODEL_BMSOut_T BMSOut_M;
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
 * '<Root>' : 'BMSOut'
 */
#endif                                 /* RTW_HEADER_BMSOut_h_ */
