/*
 * Code generation for system model 'BMSBalancingLogic'
 * For more details, see corresponding source file BMSBalancingLogic.c
 *
 */

#ifndef RTW_HEADER_BMSBalancingLogic_h_
#define RTW_HEADER_BMSBalancingLogic_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "BMSBalancingLogic_types.h"
#include <cstring>

/* Block states (default storage) for model 'BMSBalancingLogic' */
struct DW_BMSBalancingLogic_T {
  real32_T DeltaCellVolt;              /* '<Root>/Balancing' */
  uint16_T temporalCounter_i1;         /* '<Root>/Balancing' */
  uint8_T is_active_c1_BMSBalancingLogic;/* '<Root>/Balancing' */
  uint8_T is_c1_BMSBalancingLogic;     /* '<Root>/Balancing' */
  uint8_T is_BalancingON;              /* '<Root>/Balancing' */
  boolean_T flgBalCompl;               /* '<Root>/Balancing' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BMSBalancingLogic_T {
  const char_T **errorStatus;
};

/* Class declaration for model BMSBalancingLogic */
class BMSBalancingLogic final
{
  /* public data and function members */
 public:
  /* Initial conditions function */
  void init(boolean_T rty_BalCmd[96]);

  /* Copy Constructor */
  BMSBalancingLogic(BMSBalancingLogic const&) = delete;

  /* Assignment Operator */
  BMSBalancingLogic& operator= (BMSBalancingLogic const&) & = delete;

  /* Move Constructor */
  BMSBalancingLogic(BMSBalancingLogic &&) = delete;

  /* Move Assignment Operator */
  BMSBalancingLogic& operator= (BMSBalancingLogic &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_BMSBalancingLogic_T * getRTM();

  /*member function to setup error status pointer */
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  /* Reset function */
  void reset(boolean_T rty_BalCmd[96]);

  /* model step function */
  void step(const real32_T *rtu_BMSState, const real32_T rtu_CellVoltages[96],
            const real32_T *rtu_MaxCellVolt, const real32_T *rtu_MinCellVolt,
            boolean_T rty_BalCmd[96]);

  /* Constructor */
  BMSBalancingLogic();

  /* Destructor */
  ~BMSBalancingLogic();

  /* private data and function members */
 private:
  /* Block states */
  DW_BMSBalancingLogic_T BMSBalancingLogic_DW;

  /* Real-Time Model */
  RT_MODEL_BMSBalancingLogic_T BMSBalancingLogic_M;
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
 * '<Root>' : 'BMSBalancingLogic'
 * '<S1>'   : 'BMSBalancingLogic/Balancing'
 */
#endif                                 /* RTW_HEADER_BMSBalancingLogic_h_ */
