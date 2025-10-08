/*
 * Code generation for system model 'BMSCurrPowerLimCalc'
 *
 * Model                      : BMSCurrPowerLimCalc
 * Model version              : 6.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:27:52 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "BMSCurrPowerLimCalc.h"
#include "rtwtypes.h"
#include <cmath>
#include "look1_iflf_binlc.h"
#include "BMSCurrPowerLimCalc_private.h"

/* Output and update for referenced model: 'BMSCurrPowerLimCalc' */
void BMSCurrPowerLimCalc::step(const real32_T rtu_Sensors_CellVoltages[96],
  const real32_T rtu_Sensors_CellTemperatures[96], real32_T
  *rty_CurrentLimits_DischargeCurrentLimit, real32_T
  *rty_CurrentLimits_ChargeCurrentLimit, real32_T *rty_MinMaxCells_MinCellVolt,
  real32_T *rty_MinMaxCells_MaxCellVolt, real32_T *rty_MinMaxCells_MinCellTemp,
  real32_T *rty_MinMaxCells_MaxCellTemp)
{
  int32_T sigIdx;
  real32_T minV;

  /* MinMax: '<S1>/MinMax' */
  minV = rtu_Sensors_CellVoltages[0];
  for (sigIdx = 0; sigIdx < 95; sigIdx++) {
    minV = std::fmin(minV, rtu_Sensors_CellVoltages[sigIdx + 1]);
  }

  *rty_MinMaxCells_MinCellVolt = minV;

  /* End of MinMax: '<S1>/MinMax' */

  /* Lookup_n-D: '<S3>/MinCellVoltDchrgCurrentLim' */
  BMSCurrPowerLimCalc_B.MinCellVoltDchrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MinCellVolt, rtCP_MinCellVoltDchrgCurrentLim_bp01Data,
     rtCP_MinCellVoltDchrgCurrentLim_tableData, 2U);

  /* MinMax: '<S1>/MinMax4' */
  minV = rtu_Sensors_CellTemperatures[0];
  for (sigIdx = 0; sigIdx < 95; sigIdx++) {
    minV = std::fmax(minV, rtu_Sensors_CellTemperatures[sigIdx + 1]);
  }

  *rty_MinMaxCells_MaxCellTemp = minV;

  /* End of MinMax: '<S1>/MinMax4' */

  /* Lookup_n-D: '<S3>/HighTempDchrgCurrentLim' */
  BMSCurrPowerLimCalc_B.HighTempDchrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MaxCellTemp, rtCP_HighTempDchrgCurrentLim_bp01Data,
     rtCP_HighTempDchrgCurrentLim_tableData, 3U);

  /* MinMax: '<S1>/MinMax1' */
  minV = rtu_Sensors_CellTemperatures[0];
  for (sigIdx = 0; sigIdx < 95; sigIdx++) {
    minV = std::fmin(minV, rtu_Sensors_CellTemperatures[sigIdx + 1]);
  }

  *rty_MinMaxCells_MinCellTemp = minV;

  /* End of MinMax: '<S1>/MinMax1' */

  /* Lookup_n-D: '<S3>/LowTempDchrgCurrentLim' */
  BMSCurrPowerLimCalc_B.LowTempDchrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MinCellTemp, rtCP_LowTempDchrgCurrentLim_bp01Data,
     rtCP_LowTempDchrgCurrentLim_tableData, 6U);

  /* MinMax: '<S3>/MinMax2' */
  minV = std::fmin(BMSCurrPowerLimCalc_B.MinCellVoltDchrgCurrentLim,
                   BMSCurrPowerLimCalc_B.LowTempDchrgCurrentLim);
  minV = std::fmin(minV, BMSCurrPowerLimCalc_B.HighTempDchrgCurrentLim);

  /* MinMax: '<S3>/MinMax2' */
  BMSCurrPowerLimCalc_B.MinMax2 = minV;

  /* Gain: '<S3>/MaxDchrgCurrLim' */
  BMSCurrPowerLimCalc_B.MaxDchrgCurrLim = (-20.0F) *
    BMSCurrPowerLimCalc_B.MinMax2;

  /* Gain: '<S3>/Np_Module' */
  *rty_CurrentLimits_DischargeCurrentLimit = 31.0F *
    BMSCurrPowerLimCalc_B.MaxDchrgCurrLim;

  /* Lookup_n-D: '<S2>/LowTempChrgCurrentLim' */
  BMSCurrPowerLimCalc_B.LowTempChrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MinCellTemp, rtCP_LowTempChrgCurrentLim_bp01Data,
     rtCP_LowTempChrgCurrentLim_tableData, 6U);

  /* Lookup_n-D: '<S2>/HighTempChrgCurrentLim' */
  BMSCurrPowerLimCalc_B.HighTempChrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MaxCellTemp, rtCP_HighTempChrgCurrentLim_bp01Data,
     rtCP_HighTempChrgCurrentLim_tableData, 4U);

  /* MinMax: '<S1>/MinMax2' */
  minV = rtu_Sensors_CellVoltages[0];
  for (sigIdx = 0; sigIdx < 95; sigIdx++) {
    minV = std::fmax(minV, rtu_Sensors_CellVoltages[sigIdx + 1]);
  }

  *rty_MinMaxCells_MaxCellVolt = minV;

  /* End of MinMax: '<S1>/MinMax2' */

  /* Lookup_n-D: '<S2>/MaxCellVoltChrgCurrentLim' */
  BMSCurrPowerLimCalc_B.MaxCellVoltChrgCurrentLim = look1_iflf_binlc
    (*rty_MinMaxCells_MaxCellVolt, rtCP_MaxCellVoltChrgCurrentLim_bp01Data,
     rtCP_MaxCellVoltChrgCurrentLim_tableData, 3U);

  /* MinMax: '<S2>/MinMax2' */
  minV = std::fmin(BMSCurrPowerLimCalc_B.MaxCellVoltChrgCurrentLim,
                   BMSCurrPowerLimCalc_B.LowTempChrgCurrentLim);
  minV = std::fmin(minV, BMSCurrPowerLimCalc_B.HighTempChrgCurrentLim);

  /* MinMax: '<S2>/MinMax2' */
  BMSCurrPowerLimCalc_B.MinMax2_f2dm = minV;

  /* Gain: '<S2>/MaxChrgCurrLim' */
  BMSCurrPowerLimCalc_B.MaxChrgCurrLim = 6.36F *
    BMSCurrPowerLimCalc_B.MinMax2_f2dm;

  /* Gain: '<S2>/Np_Module' */
  *rty_CurrentLimits_ChargeCurrentLimit = 31.0F *
    BMSCurrPowerLimCalc_B.MaxChrgCurrLim;
}

/* Constructor */
BMSCurrPowerLimCalc::BMSCurrPowerLimCalc() :
  BMSCurrPowerLimCalc_B(),
  BMSCurrPowerLimCalc_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
BMSCurrPowerLimCalc::~BMSCurrPowerLimCalc() = default;

/* Real-Time Model get method */
RT_MODEL_BMSCurrPowerLimCalc_T * BMSCurrPowerLimCalc::getRTM()
{
  return (&BMSCurrPowerLimCalc_M);
}

/* member function to setup error status pointer */
void BMSCurrPowerLimCalc::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&BMSCurrPowerLimCalc_M), rt_errorStatus);
}
