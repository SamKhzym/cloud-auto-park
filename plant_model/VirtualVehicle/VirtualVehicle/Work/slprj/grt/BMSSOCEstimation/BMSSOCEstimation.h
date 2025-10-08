/*
 * Code generation for system model 'BMSSOCEstimation'
 * For more details, see corresponding source file BMSSOCEstimation.c
 *
 */

#ifndef RTW_HEADER_BMSSOCEstimation_h_
#define RTW_HEADER_BMSSOCEstimation_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "BMSSOCEstimation_types.h"
#include <cstring>

/* Block signals for model 'BMSSOCEstimation' */
struct B_BMSSOCEstimation_T {
  real32_T SOC_CC;                     /* '<S3>/Discrete-Time Integrator' */
  real32_T Gain;                       /* '<S3>/Gain' */
  real32_T Divide;                     /* '<S3>/Divide' */
  real32_T PackCurrent;                /* '<Root>/PackCurrent' */
};

/* Block states (default storage) for model 'BMSSOCEstimation' */
struct DW_BMSSOCEstimation_T {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BMSSOCEstimation_T {
  const char_T **errorStatus;
};

/* Class declaration for model BMSSOCEstimation */
class BMSSOCEstimation final
{
  /* public data and function members */
 public:
  /* Initial conditions function */
  void init();

  /* Copy Constructor */
  BMSSOCEstimation(BMSSOCEstimation const&) = delete;

  /* Assignment Operator */
  BMSSOCEstimation& operator= (BMSSOCEstimation const&) & = delete;

  /* Move Constructor */
  BMSSOCEstimation(BMSSOCEstimation &&) = delete;

  /* Move Assignment Operator */
  BMSSOCEstimation& operator= (BMSSOCEstimation &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_BMSSOCEstimation_T * getRTM();

  /*member function to setup error status pointer */
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  /* model step function */
  void step(const real32_T *rtu_Sensors_PackCurrent, real32_T *rty_SOC_SOC_CC,
            real32_T *rty_SOC_SOC_UKF, real32_T *rty_SOC_SOC_EKF);

  /* Reset function */
  void reset();

  /* Constructor */
  BMSSOCEstimation();

  /* Destructor */
  ~BMSSOCEstimation();

  /* private data and function members */
 private:
  /* Block signals */
  B_BMSSOCEstimation_T BMSSOCEstimation_B;

  /* Block states */
  DW_BMSSOCEstimation_T BMSSOCEstimation_DW;

  /* Real-Time Model */
  RT_MODEL_BMSSOCEstimation_T BMSSOCEstimation_M;
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
 * '<Root>' : 'BMSSOCEstimation'
 * '<S1>'   : 'BMSSOCEstimation/Coulomb Counting'
 * '<S2>'   : 'BMSSOCEstimation/SOC Kalman Filters'
 * '<S3>'   : 'BMSSOCEstimation/Coulomb Counting/Constant Capacity'
 * '<S4>'   : 'BMSSOCEstimation/SOC Kalman Filters/No Kalman Filters'
 */
#endif                                 /* RTW_HEADER_BMSSOCEstimation_h_ */
