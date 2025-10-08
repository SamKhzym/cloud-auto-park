/*
 * Code generation for system model 'BMSSOCEstimation'
 *
 * Model                      : BMSSOCEstimation
 * Model version              : 6.8
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:34:13 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "BMSSOCEstimation.h"
#include "rtwtypes.h"
#include "BMSSOCEstimation_private.h"

/* System initialize for referenced model: 'BMSSOCEstimation' */
void BMSSOCEstimation::init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE = 0.6F;
}

/* System reset for referenced model: 'BMSSOCEstimation' */
void BMSSOCEstimation::reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE = 0.6F;
}

/* Output and update for referenced model: 'BMSSOCEstimation' */
void BMSSOCEstimation::step(const real32_T *rtu_Sensors_PackCurrent, real32_T
  *rty_SOC_SOC_CC, real32_T *rty_SOC_SOC_UKF, real32_T *rty_SOC_SOC_EKF)
{
  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  BMSSOCEstimation_B.SOC_CC = BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion generated from: '<Root>/SOC_Outport_1' */
  *rty_SOC_SOC_CC = BMSSOCEstimation_B.SOC_CC;

  /* Gain: '<S3>/Gain' */
  BMSSOCEstimation_B.Gain = 0.000277777785F * *rtu_Sensors_PackCurrent;

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant'
   */
  BMSSOCEstimation_B.Divide = BMSSOCEstimation_B.Gain / 97.743F;

  /* Gain: '<Root>/PackCurrent' */
  BMSSOCEstimation_B.PackCurrent = (-1.0F) * *rtu_Sensors_PackCurrent;

  /* Constant: '<S4>/Constant' */
  *rty_SOC_SOC_UKF = 0.0F;

  /* Constant: '<S4>/Constant1' */
  *rty_SOC_SOC_EKF = 0.0F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE += 0.1F *
    BMSSOCEstimation_B.Divide;
  if (BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else if (BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
    BMSSOCEstimation_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
}

/* Constructor */
BMSSOCEstimation::BMSSOCEstimation() :
  BMSSOCEstimation_B(),
  BMSSOCEstimation_DW(),
  BMSSOCEstimation_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
BMSSOCEstimation::~BMSSOCEstimation() = default;

/* Real-Time Model get method */
RT_MODEL_BMSSOCEstimation_T * BMSSOCEstimation::getRTM()
{
  return (&BMSSOCEstimation_M);
}

/* member function to setup error status pointer */
void BMSSOCEstimation::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&BMSSOCEstimation_M), rt_errorStatus);
}
