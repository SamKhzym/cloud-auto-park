/*
 * BMSStateMachine_types.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "BMSStateMachine".
 *
 * Model version              : 6.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Tue Oct  7 23:34:59 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BMSStateMachine_types_h_
#define RTW_HEADER_BMSStateMachine_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Contact_
#define DEFINED_TYPEDEF_FOR_Contact_

enum class Contact
  : int8_T {
  Init = 0,
  Open,                                /* Default value */
  Close
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MonitorCellTempModeType_
#define DEFINED_TYPEDEF_FOR_MonitorCellTempModeType_

enum class MonitorCellTempModeType
  : int32_T {
  None = 0,                            /* Default value */
  NoCellTempFault,
  HighTemperatureFault,
  LowTemperatureFault
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MonitorCellVoltageModeType_
#define DEFINED_TYPEDEF_FOR_MonitorCellVoltageModeType_

enum class MonitorCellVoltageModeType
  : int32_T {
  None = 0,                            /* Default value */
  NoCellVoltFault,
  OverVoltageFault,
  SensorFaut,
  UnderVoltageFault
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MonitorCurrLimModeType_
#define DEFINED_TYPEDEF_FOR_MonitorCurrLimModeType_

enum class MonitorCurrLimModeType
  : int32_T {
  None = 0,                            /* Default value */
  NoCurrLimFault,
  Wait,
  OverCurrentFault
};

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_BMSStateMachine_T RT_MODEL_BMSStateMachine_T;

#endif                                 /* RTW_HEADER_BMSStateMachine_types_h_ */
