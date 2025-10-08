/*
 * AdasPlantModel0_types.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "AdasPlantModel0".
 *
 * Model version              : 6.83
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Wed Oct  8 00:15:24 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AdasPlantModel0_types_h_
#define RTW_HEADER_AdasPlantModel0_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_MinCellVoltDchrgCurrentLimTable_
#define DEFINED_TYPEDEF_FOR_MinCellVoltDchrgCurrentLimTable_

struct MinCellVoltDchrgCurrentLimTable
{
  real32_T MinCellVoltage[3];
  real32_T DischargeCurrentRate[3];
};

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_struct_beekyrb3065f5ZXL7GuueB_
#define DEFINED_TYPEDEF_FOR_struct_beekyrb3065f5ZXL7GuueB_

struct struct_beekyrb3065f5ZXL7GuueB
{
  real_T CellVoltages[96];
  real_T PackVoltage;
  real_T PackCurrent;
  real_T CellTemperatures[96];
  real_T VoutChgr;
  real_T VoutInvtr;
};

#endif

/* Parameters for system: '<S132>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_AdasPlantM_T_ P_EnabledSubsystem_AdasPlantM_T;

/* Parameters for system: '<S132>/Enabled Subsystem1' */
typedef struct P_EnabledSubsystem1_AdasPlant_T_ P_EnabledSubsystem1_AdasPlant_T;

/* Parameters for system: '<S132>/Triggered Subsystem' */
typedef struct P_TriggeredSubsystem_AdasPlan_T_ P_TriggeredSubsystem_AdasPlan_T;

/* Parameters for system: '<S291>/For each track and axle combination calculate suspension forces and moments' */
typedef struct P_CoreSubsys_AdasPlantModel_o_T_ P_CoreSubsys_AdasPlantModel_o_T;

/* Parameters for system: '<S375>/Wheel to Body Transform' */
typedef struct P_CoreSubsys_AdasPlantModel_g_T_ P_CoreSubsys_AdasPlantModel_g_T;

/* Parameters for system: '<S287>/Wheel to Body Transform' */
typedef struct P_CoreSubsys_AdasPlantMode_gm_T_ P_CoreSubsys_AdasPlantMode_gm_T;

/* Parameters for system: '<S434>/Unwrap' */
typedef struct P_CoreSubsys_AdasPlantModel_l_T_ P_CoreSubsys_AdasPlantModel_l_T;

/* Parameters for system: '<S526>/Clutch' */
typedef struct P_Clutch_AdasPlantModel0_T_ P_Clutch_AdasPlantModel0_T;

/* Parameters for system: '<S522>/Clutch Partitioned Parameters' */
typedef struct P_CoreSubsys_AdasPlantMode_gp_T_ P_CoreSubsys_AdasPlantMode_gp_T;

/* Parameters for system: '<Root>/AdasPlantModel' */
typedef struct P_AdasPlantModel_AdasPlantMod_T_ P_AdasPlantModel_AdasPlantMod_T;

/* Parameters (default storage) */
typedef struct P_AdasPlantModel0_T_ P_AdasPlantModel0_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AdasPlantModel0_T RT_MODEL_AdasPlantModel0_T;

#endif                                 /* RTW_HEADER_AdasPlantModel0_types_h_ */
