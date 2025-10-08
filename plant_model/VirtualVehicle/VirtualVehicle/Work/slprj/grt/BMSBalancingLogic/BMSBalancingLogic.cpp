/*
 * Code generation for system model 'BMSBalancingLogic'
 *
 * Model                      : BMSBalancingLogic
 * Model version              : 6.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:26:21 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "BMSBalancingLogic.h"
#include "rtwtypes.h"
#include <cstring>
#include "BMSBalancingLogic_private.h"

/* Named constants for Chart: '<Root>/Balancing' */
const uint8_T BMSBalancingLogic_IN_BalActive{ 1U };

const uint8_T BMSBalancingLogic_IN_BalNotActive{ 2U };

const uint8_T BMSBalancingLogic_IN_BalancingOFF{ 1U };

const uint8_T BMSBalancingLogic_IN_BalancingON{ 2U };

const uint8_T BMSBalancingLogic_IN_NO_ACTIVE_CHILD{ 0U };

/* System initialize for referenced model: 'BMSBalancingLogic' */
void BMSBalancingLogic::init(boolean_T rty_BalCmd[96])
{
  /* SystemInitialize for Chart: '<Root>/Balancing' */
  std::memset(&rty_BalCmd[0], 0, 96U * sizeof(boolean_T));
}

/* System reset for referenced model: 'BMSBalancingLogic' */
void BMSBalancingLogic::reset(boolean_T rty_BalCmd[96])
{
  /* SystemReset for Chart: '<Root>/Balancing' */
  BMSBalancingLogic_DW.is_BalancingON = BMSBalancingLogic_IN_NO_ACTIVE_CHILD;
  BMSBalancingLogic_DW.temporalCounter_i1 = 0U;
  BMSBalancingLogic_DW.is_active_c1_BMSBalancingLogic = 0U;
  BMSBalancingLogic_DW.is_c1_BMSBalancingLogic =
    BMSBalancingLogic_IN_NO_ACTIVE_CHILD;
  BMSBalancingLogic_DW.flgBalCompl = false;
  BMSBalancingLogic_DW.DeltaCellVolt = 0.0F;
  std::memset(&rty_BalCmd[0], 0, 96U * sizeof(boolean_T));
}

/* Output and update for referenced model: 'BMSBalancingLogic' */
void BMSBalancingLogic::step(const real32_T *rtu_BMSState, const real32_T
  rtu_CellVoltages[96], const real32_T *rtu_MaxCellVolt, const real32_T
  *rtu_MinCellVolt, boolean_T rty_BalCmd[96])
{
  int32_T i;
  real32_T DeltaCellVolt_tmp;
  boolean_T b_out;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;

  /* Chart: '<Root>/Balancing' */
  if (BMSBalancingLogic_DW.temporalCounter_i1 < 8191U) {
    BMSBalancingLogic_DW.temporalCounter_i1 = static_cast<uint16_T>
      (BMSBalancingLogic_DW.temporalCounter_i1 + 1U);
  }

  if (BMSBalancingLogic_DW.is_active_c1_BMSBalancingLogic == 0U) {
    BMSBalancingLogic_DW.is_active_c1_BMSBalancingLogic = 1U;
    BMSBalancingLogic_DW.flgBalCompl = true;
    BMSBalancingLogic_DW.is_c1_BMSBalancingLogic =
      BMSBalancingLogic_IN_BalancingOFF;
    BMSBalancingLogic_DW.temporalCounter_i1 = 0U;
    std::memset(&rty_BalCmd[0], 0, 96U * sizeof(boolean_T));
    BMSBalancingLogic_DW.DeltaCellVolt = *rtu_MaxCellVolt - *rtu_MinCellVolt;
  } else if (BMSBalancingLogic_DW.is_c1_BMSBalancingLogic ==
             BMSBalancingLogic_IN_BalancingOFF) {
    b_out = (true && (*rtu_BMSState != 2.0F) &&
             (BMSBalancingLogic_DW.temporalCounter_i1 * 5 >= 20) &&
             (BMSBalancingLogic_DW.DeltaCellVolt > 0.01F));
    if (b_out) {
      BMSBalancingLogic_DW.is_c1_BMSBalancingLogic =
        BMSBalancingLogic_IN_BalancingON;
      BMSBalancingLogic_DW.DeltaCellVolt = *rtu_MaxCellVolt - *rtu_MinCellVolt;
      BMSBalancingLogic_DW.is_BalancingON = BMSBalancingLogic_IN_BalActive;
      DeltaCellVolt_tmp = 0.01F / 2.0F;
      for (i = 0; i < 96; i++) {
        rty_BalCmd[i] = (rtu_CellVoltages[i] - *rtu_MinCellVolt >
                         DeltaCellVolt_tmp);
      }

      BMSBalancingLogic_DW.flgBalCompl = true;
      i = 0;
      exitg3 = false;
      while ((!exitg3) && (i < 96)) {
        if (rty_BalCmd[i]) {
          BMSBalancingLogic_DW.flgBalCompl = false;
          exitg3 = true;
        } else {
          i++;
        }
      }
    } else {
      BMSBalancingLogic_DW.DeltaCellVolt = *rtu_MaxCellVolt - *rtu_MinCellVolt;
    }

    /* case IN_BalancingON: */
  } else if (*rtu_BMSState == 2.0F) {
    BMSBalancingLogic_DW.is_BalancingON = BMSBalancingLogic_IN_NO_ACTIVE_CHILD;
    BMSBalancingLogic_DW.is_c1_BMSBalancingLogic =
      BMSBalancingLogic_IN_BalancingOFF;
    BMSBalancingLogic_DW.temporalCounter_i1 = 0U;
    std::memset(&rty_BalCmd[0], 0, 96U * sizeof(boolean_T));
    BMSBalancingLogic_DW.DeltaCellVolt = *rtu_MaxCellVolt - *rtu_MinCellVolt;
  } else {
    DeltaCellVolt_tmp = *rtu_MaxCellVolt - *rtu_MinCellVolt;
    BMSBalancingLogic_DW.DeltaCellVolt = DeltaCellVolt_tmp;
    switch (BMSBalancingLogic_DW.is_BalancingON) {
     case BMSBalancingLogic_IN_BalActive:
      if (BMSBalancingLogic_DW.flgBalCompl) {
        BMSBalancingLogic_DW.is_BalancingON = BMSBalancingLogic_IN_BalNotActive;
        BMSBalancingLogic_DW.temporalCounter_i1 = 0U;
      } else {
        DeltaCellVolt_tmp = 0.01F / 2.0F;
        for (i = 0; i < 96; i++) {
          rty_BalCmd[i] = (rtu_CellVoltages[i] - *rtu_MinCellVolt >
                           DeltaCellVolt_tmp);
        }

        BMSBalancingLogic_DW.flgBalCompl = true;
        i = 0;
        exitg2 = false;
        while ((!exitg2) && (i < 96)) {
          if (rty_BalCmd[i]) {
            BMSBalancingLogic_DW.flgBalCompl = false;
            exitg2 = true;
          } else {
            i++;
          }
        }
      }
      break;

     default:
      /* case IN_BalNotActive: */
      i = BMSBalancingLogic_DW.temporalCounter_i1 * 5;
      b_out = ((i >= 30) && (BMSBalancingLogic_DW.DeltaCellVolt > 0.01F));
      if (b_out) {
        BMSBalancingLogic_DW.is_BalancingON = BMSBalancingLogic_IN_BalActive;
        DeltaCellVolt_tmp = 0.01F / 2.0F;
        for (i = 0; i < 96; i++) {
          rty_BalCmd[i] = (rtu_CellVoltages[i] - *rtu_MinCellVolt >
                           DeltaCellVolt_tmp);
        }

        BMSBalancingLogic_DW.flgBalCompl = true;
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 96)) {
          if (rty_BalCmd[i]) {
            BMSBalancingLogic_DW.flgBalCompl = false;
            exitg1 = true;
          } else {
            i++;
          }
        }
      } else if (i >= 60) {
        BMSBalancingLogic_DW.is_BalancingON =
          BMSBalancingLogic_IN_NO_ACTIVE_CHILD;
        BMSBalancingLogic_DW.is_c1_BMSBalancingLogic =
          BMSBalancingLogic_IN_BalancingOFF;
        BMSBalancingLogic_DW.temporalCounter_i1 = 0U;
        std::memset(&rty_BalCmd[0], 0, 96U * sizeof(boolean_T));
        BMSBalancingLogic_DW.DeltaCellVolt = DeltaCellVolt_tmp;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Balancing' */
}

/* Constructor */
BMSBalancingLogic::BMSBalancingLogic() :
  BMSBalancingLogic_DW(),
  BMSBalancingLogic_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
BMSBalancingLogic::~BMSBalancingLogic() = default;

/* Real-Time Model get method */
RT_MODEL_BMSBalancingLogic_T * BMSBalancingLogic::getRTM()
{
  return (&BMSBalancingLogic_M);
}

/* member function to setup error status pointer */
void BMSBalancingLogic::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&BMSBalancingLogic_M), rt_errorStatus);
}
