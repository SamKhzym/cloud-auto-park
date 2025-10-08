/*
 * Code generation for system model 'BMSCurrPowerLimCalc'
 * For more details, see corresponding source file BMSCurrPowerLimCalc.c
 *
 */

#ifndef RTW_HEADER_BMSCurrPowerLimCalc_h_
#define RTW_HEADER_BMSCurrPowerLimCalc_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "BMSCurrPowerLimCalc_types.h"
#include <cstring>

/* Block signals for model 'BMSCurrPowerLimCalc' */
struct B_BMSCurrPowerLimCalc_T {
  real32_T MinCellVoltDchrgCurrentLim; /* '<S3>/MinCellVoltDchrgCurrentLim' */
  real32_T HighTempDchrgCurrentLim;    /* '<S3>/HighTempDchrgCurrentLim' */
  real32_T LowTempDchrgCurrentLim;     /* '<S3>/LowTempDchrgCurrentLim' */
  real32_T MinMax2;                    /* '<S3>/MinMax2' */
  real32_T MaxDchrgCurrLim;            /* '<S3>/MaxDchrgCurrLim' */
  real32_T LowTempChrgCurrentLim;      /* '<S2>/LowTempChrgCurrentLim' */
  real32_T HighTempChrgCurrentLim;     /* '<S2>/HighTempChrgCurrentLim' */
  real32_T MaxCellVoltChrgCurrentLim;  /* '<S2>/MaxCellVoltChrgCurrentLim' */
  real32_T MinMax2_f2dm;               /* '<S2>/MinMax2' */
  real32_T MaxChrgCurrLim;             /* '<S2>/MaxChrgCurrLim' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BMSCurrPowerLimCalc_T {
  const char_T **errorStatus;
};

/* Class declaration for model BMSCurrPowerLimCalc */
class BMSCurrPowerLimCalc final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  BMSCurrPowerLimCalc(BMSCurrPowerLimCalc const&) = delete;

  /* Assignment Operator */
  BMSCurrPowerLimCalc& operator= (BMSCurrPowerLimCalc const&) & = delete;

  /* Move Constructor */
  BMSCurrPowerLimCalc(BMSCurrPowerLimCalc &&) = delete;

  /* Move Assignment Operator */
  BMSCurrPowerLimCalc& operator= (BMSCurrPowerLimCalc &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_BMSCurrPowerLimCalc_T * getRTM();

  /*member function to setup error status pointer */
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  /* model step function */
  void step(const real32_T rtu_Sensors_CellVoltages[96], const real32_T
            rtu_Sensors_CellTemperatures[96], real32_T
            *rty_CurrentLimits_DischargeCurrentLimit, real32_T
            *rty_CurrentLimits_ChargeCurrentLimit, real32_T
            *rty_MinMaxCells_MinCellVolt, real32_T *rty_MinMaxCells_MaxCellVolt,
            real32_T *rty_MinMaxCells_MinCellTemp, real32_T
            *rty_MinMaxCells_MaxCellTemp);

  /* Constructor */
  BMSCurrPowerLimCalc();

  /* Destructor */
  ~BMSCurrPowerLimCalc();

  /* private data and function members */
 private:
  /* Block signals */
  B_BMSCurrPowerLimCalc_T BMSCurrPowerLimCalc_B;

  /* Real-Time Model */
  RT_MODEL_BMSCurrPowerLimCalc_T BMSCurrPowerLimCalc_M;
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
 * '<Root>' : 'BMSCurrPowerLimCalc'
 * '<S1>'   : 'BMSCurrPowerLimCalc/CalculateMinMaxCells'
 * '<S2>'   : 'BMSCurrPowerLimCalc/ChargeCurrentLimitCalc'
 * '<S3>'   : 'BMSCurrPowerLimCalc/DischargeCurrentLimitCalc'
 */
#endif                                 /* RTW_HEADER_BMSCurrPowerLimCalc_h_ */
