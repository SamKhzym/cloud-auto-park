/*
 * Code generation for system system '<Root>/AdasPlantModel'
 * For more details, see corresponding source file AdasPlantModel.c
 *
 */

#ifndef RTW_HEADER_AdasPlantModel_h_
#define RTW_HEADER_AdasPlantModel_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ConfiguredVirtualVehicleModel_types.h"
#include "rt_zcfcn.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include "zero_crossing_types.h"

/* Block signals for system '<S133>/Enabled Subsystem' */
struct B_EnabledSubsystem_Configured_T {
  real_T y;                            /* '<S141>/MATLAB Function' */
};

/* Block states (default storage) for system '<S133>/Enabled Subsystem' */
struct DW_EnabledSubsystem_Configure_T {
  boolean_T EnabledSubsystem_MODE;     /* '<S133>/Enabled Subsystem' */
};

/* Block signals for system '<S133>/Enabled Subsystem1' */
struct B_EnabledSubsystem1_Configure_T {
  real_T y;                            /* '<S142>/MATLAB Function' */
};

/* Block states (default storage) for system '<S133>/Enabled Subsystem1' */
struct DW_EnabledSubsystem1_Configur_T {
  boolean_T EnabledSubsystem1_MODE;    /* '<S133>/Enabled Subsystem1' */
};

/* Block signals for system '<S133>/Triggered Subsystem' */
struct B_TriggeredSubsystem_Configur_T {
  real_T In;                           /* '<S143>/In' */
  real_T y;                            /* '<S143>/MATLAB Function1' */
  real_T y_i;                          /* '<S143>/MATLAB Function' */
};

/* Zero-crossing (trigger) state for system '<S133>/Triggered Subsystem' */
struct ZCE_TriggeredSubsystem_Config_T {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S133>/Triggered Subsystem' */
};

/* Block signals for system '<S155>/MATLAB Function1' */
struct B_MATLABFunction1_ConfiguredV_T {
  real_T y;                            /* '<S155>/MATLAB Function1' */
};

/* Block signals for system '<S292>/For each track and axle combination calculate suspension forces and moments' */
struct B_CoreSubsys_ConfiguredVirt_g_T {
  real_T Sum2;                         /* '<S302>/Sum2' */
  real_T Selector5;                    /* '<S309>/Selector5' */
  real_T Selector2;                    /* '<S322>/Selector2' */
  real_T SumofElements;                /* '<S327>/Sum of Elements' */
  real_T Product;                      /* '<S303>/Product' */
  real_T SumofElements_j;              /* '<S353>/Sum of Elements' */
  real_T Selector5_j;                  /* '<S355>/Selector5' */
  real_T Selector10;                   /* '<S354>/Selector10' */
  real_T Selector2_c;                  /* '<S356>/Selector2' */
  real_T Selector8;                    /* '<S321>/Selector8' */
  real_T Selector4;                    /* '<S323>/Selector4' */
  real_T Selector5_o;                  /* '<S310>/Selector5' */
  real_T Selector4_d;                  /* '<S332>/Selector4' */
  real_T SumofElements_d;              /* '<S336>/Sum of Elements' */
  real_T Sign;                         /* '<S311>/Sign' */
  real_T Selector2_l;                  /* '<S373>/Selector2' */
  real_T Selector1;                    /* '<S373>/Selector1' */
  real_T Selector6;                    /* '<S372>/Selector6' */
  real_T Selector1_k;                  /* '<S372>/Selector1' */
  real_T Selector7;                    /* '<S345>/Selector7' */
  real_T Selector6_m;                  /* '<S340>/Selector6' */
  real_T Selector4_p;                  /* '<S341>/Selector4' */
  real_T SumofElements_g;              /* '<S367>/Sum of Elements' */
  real_T Sign1;                        /* '<S361>/Sign1' */
  real_T Sign_e;                       /* '<S308>/Sign' */
};

/* Block signals for system '<S376>/Wheel to Body Transform' */
struct B_CoreSubsys_ConfiguredVir_gc_T {
  real_T VectorConcatenate[9];         /* '<S382>/Vector Concatenate' */
};

/* Block signals for system '<S288>/Wheel to Body Transform' */
struct B_CoreSubsys_ConfiguredVi_gc4_T {
  real_T Transpose1[9];                /* '<S384>/Transpose1' */
  real_T VectorConcatenate[9];         /* '<S388>/Vector Concatenate' */
};

/* Block signals for system '<S435>/Unwrap' */
struct B_CoreSubsys_ConfiguredVirt_c_T {
  real_T Memory1;                      /* '<S440>/Memory1' */
  real_T Sum;                          /* '<S442>/Sum' */
  boolean_T Compare;                   /* '<S441>/Compare' */
};

/* Block states (default storage) for system '<S435>/Unwrap' */
struct DW_CoreSubsys_ConfiguredVi_mj_T {
  real_T UnitDelay_DSTATE;             /* '<S442>/Unit Delay' */
  real_T Memory1_PreviousInput;        /* '<S440>/Memory1' */
};

/* Zero-crossing (trigger) state for system '<S435>/Unwrap' */
struct ZCE_CoreSubsys_ConfiguredV_a5_T {
  ZCSigState FunctionCallSubsystem_Trig_ZCE;/* '<S440>/Function-Call Subsystem' */
};

/* Block signals for system '<S527>/Clutch' */
struct B_Clutch_ConfiguredVirtualVeh_T {
  real_T Tout;                         /* '<S527>/Clutch' */
  real_T Tfmaxs;                       /* '<S527>/Clutch' */
  real_T Tout_l;                       /* '<S527>/Clutch' */
  real_T Tfmaxs_g;                     /* '<S527>/Clutch' */
  real_T Omega;                        /* '<S527>/Clutch' */
  real_T Omegadot;                     /* '<S527>/Clutch' */
  real_T Myb;                          /* '<S527>/Clutch' */
  real_T OutputInertia;                /* '<S530>/Output Inertia' */
  boolean_T CombinatorialLogic;        /* '<S536>/Combinatorial  Logic' */
  boolean_T RelationalOperator;        /* '<S540>/Relational Operator' */
};

/* Block states (default storage) for system '<S527>/Clutch' */
struct DW_Clutch_ConfiguredVirtualVe_T {
  real_T lastMajorTime;                /* '<S527>/Clutch' */
  boolean_T UnitDelay_DSTATE;          /* '<S536>/Unit Delay' */
  int8_T TmpIfAtSlippingInport3_ActiveSu;/* synthesized block */
  int8_T TmpIfAtLockedInport2_ActiveSubs;/* synthesized block */
  uint8_T is_active_c8_autolibshared;  /* '<S527>/Clutch' */
  uint8_T is_c8_autolibshared;         /* '<S527>/Clutch' */
  boolean_T Slipping_entered;          /* '<S527>/Clutch' */
  boolean_T Locked_entered;            /* '<S527>/Clutch' */
};

/* Continuous states for system '<S527>/Clutch' */
struct X_Clutch_ConfiguredVirtualVeh_T {
  real_T omegaWheel;                   /* '<S530>/omega wheel' */
};

/* State derivatives for system '<S527>/Clutch' */
struct XDot_Clutch_ConfiguredVirtual_T {
  real_T omegaWheel;                   /* '<S530>/omega wheel' */
};

/* State Disabled for system '<S527>/Clutch' */
struct XDis_Clutch_ConfiguredVirtual_T {
  boolean_T omegaWheel;                /* '<S530>/omega wheel' */
};

/* Block signals for system '<S523>/Clutch Partitioned Parameters' */
struct B_CoreSubsys_ConfiguredVirt_b_T {
  B_Clutch_ConfiguredVirtualVeh_T sf_Clutch;/* '<S527>/Clutch' */
};

/* Block states (default storage) for system '<S523>/Clutch Partitioned Parameters' */
struct DW_CoreSubsys_ConfiguredVi_dp_T {
  DW_Clutch_ConfiguredVirtualVe_T sf_Clutch;/* '<S527>/Clutch' */
};

/* Continuous states for system '<S523>/Clutch Partitioned Parameters' */
struct X_CoreSubsys_ConfiguredVirt_i_T {
  X_Clutch_ConfiguredVirtualVeh_T sf_Clutch;/* '<S527>/Clutch' */
};

/* State derivatives for system '<S523>/Clutch Partitioned Parameters' */
struct XDot_CoreSubsys_Configured_ej_T {
  XDot_Clutch_ConfiguredVirtual_T sf_Clutch;/* '<S527>/Clutch' */
};

/* State Disabled for system '<S523>/Clutch Partitioned Parameters' */
struct XDis_CoreSubsys_ConfiguredV_k_T {
  XDis_Clutch_ConfiguredVirtual_T sf_Clutch;/* '<S527>/Clutch' */
};

/* Block signals for system '<Root>/AdasPlantModel' */
struct B_AdasPlantModel_ConfiguredVi_T {
  real_T Product;                      /* '<S631>/Product' */
  real_T DataTypeConversion1;          /* '<S22>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S22>/Data Type Conversion' */
  real_T DataTypeConversion2;          /* '<S22>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<S22>/Data Type Conversion3' */
  real_T Spd;                          /* '<S610>/Integrator' */
  real_T UnitConversion[3];            /* '<S417>/Unit Conversion' */
  real_T Switch2;                      /* '<S67>/Switch2' */
  real_T Wind[3];                      /* '<S5>/Vector Concatenate' */
  real_T VectorConcatenate1[4];        /* '<S76>/Vector Concatenate1' */
  real_T EMTrqCmd;                     /* '<S80>/First Order Hold' */
  real_T DeadZone[4];                  /* '<S105>/Dead Zone' */
  real_T Divide[4];                    /* '<S106>/Divide' */
  real_T Integrator[4];                /* '<S517>/Integrator' */
  real_T Integrator_h[4];              /* '<S518>/Integrator' */
  real_T MathFunction[12];             /* '<S288>/Math Function' */
  real_T Memory;                       /* '<S580>/Memory' */
  real_T domega_o;                     /* '<S579>/domega_o' */
  real_T Memory_h;                     /* '<S588>/Memory' */
  real_T domega_o_o;                   /* '<S587>/domega_o' */
  real_T VectorConcatenate1_f[4];      /* '<S541>/Vector Concatenate1' */
  real_T Add1[4];                      /* '<S516>/Add1' */
  real_T TorqueConversion1[4];         /* '<S526>/Torque Conversion1' */
  real_T Ratioofstatictokinetic[4];    /* '<S524>/Ratio of static to kinetic' */
  real_T Ratioofstatictokinetic1[4];  /* '<S524>/Ratio of static to kinetic1' */
  real_T Selector1[3];                 /* '<S451>/Selector1' */
  real_T Selector1_f[3];               /* '<S452>/Selector1' */
  real_T Selector1_f2[3];              /* '<S455>/Selector1' */
  real_T Selector1_n[3];               /* '<S456>/Selector1' */
  real_T MatrixConcatenate[12];        /* '<S287>/Matrix Concatenate' */
  real_T VectorConcatenate3[12];       /* '<S377>/Vector Concatenate3' */
  real_T MatrixConcatenate1[12];       /* '<S293>/Matrix Concatenate1' */
  real_T FrontPressure[2];             /* '<S509>/Front Pressure' */
  real_T RearPressure[2];              /* '<S509>/Rear Pressure' */
  real_T VectorConcatenate[108];       /* '<S511>/Vector Concatenate' */
  real_T MathFunction1[12];            /* '<S288>/Math Function1' */
  real_T phithetapsi[3];               /* '<S413>/phi theta psi' */
  real_T Product_k[3];                 /* '<S420>/Product' */
  real_T Add3;                         /* '<S174>/Add3' */
  real_T Divide_e;                     /* '<S158>/Divide' */
  real_T UnaryMinus1;                  /* '<S169>/Unary Minus1' */
  real_T MathFunction1_e;              /* '<S172>/Math Function1' */
  real_T MathFunction2;                /* '<S172>/Math Function2' */
  real_T MathFunction3;                /* '<S172>/Math Function3' */
  real_T MathFunction1_o;              /* '<S173>/Math Function1' */
  real_T MathFunction2_l;              /* '<S173>/Math Function2' */
  real_T MathFunction3_j;              /* '<S173>/Math Function3' */
  real_T Gain5;                        /* '<S158>/Gain5' */
  real_T Add1_a;                       /* '<S158>/Add1' */
  real_T Switch;                       /* '<S111>/Switch' */
  real_T Switch1;                      /* '<S111>/Switch1' */
  real_T Backlash;                     /* '<S118>/Backlash' */
  real_T Gain2;                        /* '<S132>/Gain2' */
  real_T UnaryMinus;                   /* '<S128>/Unary Minus' */
  real_T Divide_p;                     /* '<S127>/Divide' */
  real_T Subtract2;                    /* '<S132>/Subtract2' */
  real_T Add;                          /* '<S133>/Add' */
  real_T Add1_m;                       /* '<S133>/Add1' */
  real_T Sign;                         /* '<S133>/Sign' */
  real_T HiddenBuf_InsertedFor_EnabledSu;/* '<S133>/Sign' */
  real_T Gain;                         /* '<S133>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_h;/* '<S133>/Gain' */
  real_T Add_k;                        /* '<S134>/Add' */
  real_T Add1_c;                       /* '<S134>/Add1' */
  real_T Sign_l;                       /* '<S134>/Sign' */
  real_T HiddenBuf_InsertedFor_Enabled_a;/* '<S134>/Sign' */
  real_T Gain_o;                       /* '<S134>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_g;/* '<S134>/Gain' */
  real_T Memory_j;                     /* '<S133>/Memory' */
  real_T Memory1;                      /* '<S133>/Memory1' */
  real_T Memory_hm;                    /* '<S134>/Memory' */
  real_T Memory1_k;                    /* '<S134>/Memory1' */
  real_T Gain3;                        /* '<S158>/Gain3' */
  real_T Gain_n;                       /* '<S139>/Gain' */
  real_T Gain_a;                       /* '<S140>/Gain' */
  real_T Add3_m;                       /* '<S261>/Add3' */
  real_T Divide_j;                     /* '<S245>/Divide' */
  real_T UnaryMinus1_l;                /* '<S256>/Unary Minus1' */
  real_T MathFunction1_k;              /* '<S259>/Math Function1' */
  real_T MathFunction2_m;              /* '<S259>/Math Function2' */
  real_T MathFunction3_d;              /* '<S259>/Math Function3' */
  real_T MathFunction1_a;              /* '<S260>/Math Function1' */
  real_T MathFunction2_b;              /* '<S260>/Math Function2' */
  real_T MathFunction3_m;              /* '<S260>/Math Function3' */
  real_T Gain5_c;                      /* '<S245>/Gain5' */
  real_T Add1_m4;                      /* '<S245>/Add1' */
  real_T RL;                           /* '<S108>/Gain' */
  real_T RR;                           /* '<S108>/Gain1' */
  real_T Backlash_a;                   /* '<S205>/Backlash' */
  real_T Saturation;                   /* '<S205>/Saturation' */
  real_T Gain2_j;                      /* '<S219>/Gain2' */
  real_T UnaryMinus_l;                 /* '<S215>/Unary Minus' */
  real_T Divide_jz;                    /* '<S214>/Divide' */
  real_T Subtract2_c;                  /* '<S219>/Subtract2' */
  real_T Add_o;                        /* '<S220>/Add' */
  real_T Add1_mi;                      /* '<S220>/Add1' */
  real_T Sign_f;                       /* '<S220>/Sign' */
  real_T HiddenBuf_InsertedFor_Enabled_e;/* '<S220>/Sign' */
  real_T Gain_p;                       /* '<S220>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_j;/* '<S220>/Gain' */
  real_T Add_h;                        /* '<S221>/Add' */
  real_T Add1_k;                       /* '<S221>/Add1' */
  real_T Sign_d;                       /* '<S221>/Sign' */
  real_T HiddenBuf_InsertedFor_Enabled_f;/* '<S221>/Sign' */
  real_T Gain_l;                       /* '<S221>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_n;/* '<S221>/Gain' */
  real_T Memory_e;                     /* '<S220>/Memory' */
  real_T Memory1_c;                    /* '<S220>/Memory1' */
  real_T Memory_g;                     /* '<S221>/Memory' */
  real_T Memory1_j;                    /* '<S221>/Memory1' */
  real_T Gain3_n;                      /* '<S245>/Gain3' */
  real_T Gain_b;                       /* '<S226>/Gain' */
  real_T Gain_m;                       /* '<S227>/Gain' */
  real_T Divide_c[4];                  /* '<S290>/Divide' */
  real_T Divide_k[4];                  /* '<S291>/Divide' */
  real_T Divide_c3[4];                 /* '<S374>/Divide' */
  real_T Divide_b[12];                 /* '<S375>/Divide' */
  real_T Constant1[3];                 /* '<S390>/Constant1' */
  real_T VectorConcatenate_l[3];       /* '<S391>/Vector Concatenate' */
  real_T Fg_I[3];                      /* '<S409>/Product' */
  real_T VectorConcatenate_k[6];       /* '<S434>/Vector Concatenate' */
  real_T Subtract[3];                  /* '<S453>/Subtract' */
  real_T Add_n[3];                     /* '<S473>/Add' */
  real_T Hitch[6];                     /* '<S697>/Constant' */
  real_T SumofElements[3];             /* '<S429>/Sum of Elements' */
  real_T Sum[3];                       /* '<S407>/Sum' */
  real_T Divide_d[2];                  /* '<S393>/Divide' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S413>/phidot thetadot psidot' */
  real_T Selector[9];                  /* '<S414>/Selector' */
  real_T Selector1_nm[9];              /* '<S414>/Selector1' */
  real_T Mx;                           /* '<S448>/Mx' */
  real_T My;                           /* '<S448>/My' */
  real_T Mz;                           /* '<S448>/Mz' */
  real_T Selector2[9];                 /* '<S414>/Selector2' */
  real_T Product2[3];                  /* '<S414>/Product2' */
  real_T V_wb[3];                      /* '<S473>/Add4' */
  real_T VectorConcatenate_p[3];       /* '<S454>/Vector Concatenate' */
  real_T Product1[4];                  /* '<S517>/Product1' */
  real_T Product1_i[4];                /* '<S518>/Product1' */
  real_T Product1_j[4];                /* '<S520>/Product1' */
  real_T Gain1[4];                     /* '<S521>/Gain1' */
  real_T Memory_m;                     /* '<S602>/Memory' */
  real_T domega_o_n;                   /* '<S601>/domega_o' */
  real_T diffDir;                      /* '<S557>/Switch' */
  real_T VectorConcatenate_n[2];       /* '<S553>/Vector Concatenate' */
  real_T diffDir_p;                    /* '<S560>/Switch1' */
  real_T Subtract_m;                   /* '<S579>/Subtract' */
  real_T Product_n;                    /* '<S580>/Product' */
  real_T Subtract_g;                   /* '<S587>/Subtract' */
  real_T Product_a;                    /* '<S588>/Product' */
  real_T TransGear;                    /* '<S621>/Constant' */
  real_T Subtract_gw;                  /* '<S601>/Subtract' */
  real_T Product_m;                    /* '<S602>/Product' */
  real_T Switch_g;                     /* '<S612>/Switch' */
  real_T Divide_h;                     /* '<S610>/Divide' */
  real_T Gain2_c;                      /* '<S644>/Gain2' */
  real_T Divide2;                      /* '<S666>/Divide2' */
  real_T Divide_jj;                    /* '<S646>/Divide' */
  real_T Divide1;                      /* '<S646>/Divide1' */
  real_T UnaryMinus_d;                 /* '<S651>/Unary Minus' */
  real_T Gain1_o;                      /* '<S633>/Gain1' */
  real_T Switch_g4;                    /* '<S633>/Switch' */
  real_T Sum_l;                        /* '<S631>/Sum' */
  real_T Switch_e;                     /* '<S644>/Switch' */
  real_T Sum_o;                        /* '<S644>/Sum' */
  real_T Sum_d;                        /* '<S666>/Sum' */
  real_T BattPwr;                      /* '<S622>/Product2' */
  real_T Product2_o;                   /* '<S671>/Product2' */
  real_T TPCO;                         /* '<S671>/TPCO' */
  real_T TPCO2;                        /* '<S671>/TPCO2' */
  real_T TPHC;                         /* '<S671>/TPHC' */
  real_T TPNOx;                        /* '<S671>/TPNOx' */
  real_T ZeroOrderHold2[3];            /* '<S677>/Zero-Order Hold2' */
  real_T Gain_bd[3];                   /* '<S677>/Gain' */
  real_T Sum2[3];                      /* '<S684>/Sum2' */
  real_T Sum2_c[3];                    /* '<S696>/Sum2' */
  real_T xdot[2];                      /* '<S553>/Open Differential' */
  real_T Re[4];                        /* '<S514>/Magic Tire Const Input' */
  real_T Mbar;                         /* '<S392>/vehdyncginert' */
  real_T Rbar[3];                      /* '<S392>/vehdyncginert' */
  real_T Xbar[3];                      /* '<S392>/vehdyncginert' */
  real_T Wbar[4];                      /* '<S392>/vehdyncginert' */
  real_T HPbar[12];                    /* '<S392>/vehdyncginert' */
  real_T GearCmd;                      /* '<S4>/Switch' */
  real32_T CellVoltages[96];           /* '<S26>/Unit Delay' */
  real32_T MinCellVolt;                /* '<S33>/MinMax' */
  real32_T Np_Module;                  /* '<S35>/Np_Module' */
  real32_T MaxCellVolt;                /* '<S33>/MinMax2' */
  real32_T ChargeCurrentLimit;         /* '<S34>/Np_Module' */
  real32_T PackVoltage;                /* '<S26>/Unit Delay' */
  real32_T VoutInvtr;                  /* '<S26>/Unit Delay' */
  real32_T PackCurrent;                /* '<S26>/Unit Delay' */
  real32_T SOC_CC;                     /* '<S38>/Discrete-Time Integrator' */
  real32_T Divide_pf;                  /* '<S38>/Divide' */
  real32_T PackVoltage_h;              /* '<S628>/Data Type Conversion1' */
  real32_T PackVoltage_l;              /* '<S628>/Rate Transition' */
  real32_T PackCurrent_e;              /* '<S628>/Data Type Conversion2' */
  real32_T VoutInvtr_p;                /* '<S628>/Data Type Conversion5' */
  real32_T CellVoltages_g[96];         /* '<S628>/Data Type Conversion6' */
  real32_T CellVoltages_m[96];         /* '<S628>/Rate Transition' */
  real32_T PackCurrent_c;              /* '<S628>/Rate Transition' */
  real32_T CellTemperatures[96];       /* '<S628>/Rate Transition' */
  real32_T VoutChgr_i;                 /* '<S628>/Rate Transition' */
  real32_T VoutInvtr_pm;               /* '<S628>/Rate Transition' */
  real32_T ChargeCurrentReq;           /* '<S31>/State_Machine' */
  real32_T BMSState;                   /* '<S31>/State_Machine' */
  B_CoreSubsys_ConfiguredVirt_b_T CoreSubsys_l[4];
                                    /* '<S523>/Clutch Partitioned Parameters' */
  B_CoreSubsys_ConfiguredVirt_c_T CoreSubsys_n[3];/* '<S435>/Unwrap' */
  B_CoreSubsys_ConfiguredVi_gc4_T CoreSubsys_dk[4];/* '<S288>/Wheel to Body Transform' */
  B_CoreSubsys_ConfiguredVir_gc_T CoreSubsys_d[4];/* '<S376>/Wheel to Body Transform' */
  B_CoreSubsys_ConfiguredVirt_g_T CoreSubsys[4];
  /* '<S292>/For each track and axle combination calculate suspension forces and moments' */
  B_MATLABFunction1_ConfiguredV_T sf_MATLABFunction1_i;/* '<S242>/MATLAB Function1' */
  B_TriggeredSubsystem_Configur_T TriggeredSubsystem_l;/* '<S221>/Triggered Subsystem' */
  B_EnabledSubsystem1_Configure_T EnabledSubsystem1_j;/* '<S221>/Enabled Subsystem1' */
  B_EnabledSubsystem_Configured_T EnabledSubsystem_n;/* '<S221>/Enabled Subsystem' */
  B_TriggeredSubsystem_Configur_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  B_EnabledSubsystem1_Configure_T EnabledSubsystem1_i;/* '<S220>/Enabled Subsystem1' */
  B_EnabledSubsystem_Configured_T EnabledSubsystem_g;/* '<S220>/Enabled Subsystem' */
  B_MATLABFunction1_ConfiguredV_T sf_MATLABFunction1;/* '<S155>/MATLAB Function1' */
  B_TriggeredSubsystem_Configur_T TriggeredSubsystem_k;/* '<S134>/Triggered Subsystem' */
  B_EnabledSubsystem1_Configure_T EnabledSubsystem1_d;/* '<S134>/Enabled Subsystem1' */
  B_EnabledSubsystem_Configured_T EnabledSubsystem_h;/* '<S134>/Enabled Subsystem' */
  B_TriggeredSubsystem_Configur_T TriggeredSubsystem;/* '<S133>/Triggered Subsystem' */
  B_EnabledSubsystem1_Configure_T EnabledSubsystem1;/* '<S133>/Enabled Subsystem1' */
  B_EnabledSubsystem_Configured_T EnabledSubsystem;/* '<S133>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>/AdasPlantModel' */
struct DW_AdasPlantModel_ConfiguredV_T {
  volatile real_T RateTransition18_Buffer[2];/* '<S22>/Rate Transition18' */
  volatile real_T RateTransition19_Buffer[2];/* '<S22>/Rate Transition19' */
  volatile real_T RateTransition20_Buffer[2];/* '<S22>/Rate Transition20' */
  volatile real_T RateTransition21_Buffer[2];/* '<S22>/Rate Transition21' */
  real_T Tk;                           /* '<S80>/First Order Hold' */
  real_T Ck;                           /* '<S80>/First Order Hold' */
  real_T Mk;                           /* '<S80>/First Order Hold' */
  real_T Uk;                           /* '<S80>/First Order Hold' */
  real_T Memory_PreviousInput;         /* '<S580>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S588>/Memory' */
  real_T PrevY;                        /* '<S118>/Backlash' */
  real_T TimeStampA;                   /* '<S132>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S132>/Derivative' */
  real_T TimeStampB;                   /* '<S132>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S132>/Derivative' */
  real_T TmpLatchAtTriggeredSubsystemInp;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_l;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_n;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_k;/* synthesized block */
  real_T Memory_PreviousInput_p;       /* '<S133>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S133>/Memory1' */
  real_T Memory_PreviousInput_g;       /* '<S134>/Memory' */
  real_T Memory1_PreviousInput_n;      /* '<S134>/Memory1' */
  real_T PrevY_g;                      /* '<S205>/Backlash' */
  real_T TimeStampA_g;                 /* '<S219>/Derivative' */
  real_T LastUAtTimeA_j;               /* '<S219>/Derivative' */
  real_T TimeStampB_a;                 /* '<S219>/Derivative' */
  real_T LastUAtTimeB_l;               /* '<S219>/Derivative' */
  real_T TmpLatchAtTriggeredSubsystemI_c;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_g;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_a;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_i;/* synthesized block */
  real_T Memory_PreviousInput_o;       /* '<S220>/Memory' */
  real_T Memory1_PreviousInput_f;      /* '<S220>/Memory1' */
  real_T Memory_PreviousInput_h;       /* '<S221>/Memory' */
  real_T Memory1_PreviousInput_m;      /* '<S221>/Memory1' */
  real_T Product2_DWORK4[9];           /* '<S414>/Product2' */
  real_T Memory_PreviousInput_l;       /* '<S602>/Memory' */
  real32_T UnitDelay_1_DSTATE[96];     /* '<S26>/Unit Delay' */
  real32_T UnitDelay_4_DSTATE[96];     /* '<S26>/Unit Delay' */
  real32_T UnitDelay_2_DSTATE;         /* '<S26>/Unit Delay' */
  real32_T UnitDelay_5_DSTATE;         /* '<S26>/Unit Delay' */
  real32_T UnitDelay_6_DSTATE;         /* '<S26>/Unit Delay' */
  real32_T UnitDelay_3_DSTATE;         /* '<S26>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S38>/Discrete-Time Integrator' */
  real32_T RT_Buffer[96];              /* '<S26>/RT' */
  real32_T RT1_Buffer;                 /* '<S26>/RT1' */
  real32_T RT2_Buffer;                 /* '<S26>/RT2' */
  real32_T RT3_Buffer;                 /* '<S26>/RT3' */
  real32_T RateTransition_2_Buffer;    /* '<S628>/Rate Transition' */
  real32_T RateTransition_1_Buffer[96];/* '<S628>/Rate Transition' */
  real32_T RateTransition_3_Buffer;    /* '<S628>/Rate Transition' */
  real32_T RateTransition_4_Buffer[96];/* '<S628>/Rate Transition' */
  real32_T RateTransition_5_Buffer;    /* '<S628>/Rate Transition' */
  real32_T RateTransition_6_Buffer;    /* '<S628>/Rate Transition' */
  real32_T Delta;                      /* '<S31>/State_Machine' */
  real32_T DeltaCellVolt;              /* '<S27>/Balancing' */
  MonitorCellTempModeType MonitorCellTempMode;/* '<S31>/State_Machine' */
  MonitorCellVoltageModeType MonitorCellVoltageMode;/* '<S31>/State_Machine' */
  MonitorCurrLimModeType MonitorCurrLimMode;/* '<S31>/State_Machine' */
  int_T Integrator_IWORK;              /* '<S631>/Integrator' */
  int_T Integrator_IWORK_n;            /* '<S580>/Integrator' */
  int_T Integrator_IWORK_m;            /* '<S588>/Integrator' */
  int_T Integrator_IWORK_g;            /* '<S602>/Integrator' */
  int_T Integrator_IWORK_d;            /* '<S553>/Integrator' */
  int_T Integrator_IWORK_a;            /* '<S644>/Integrator' */
  int_T IntegratorLimited_IWORK;       /* '<S633>/Integrator Limited' */
  int_T IntegratorSecondOrder_MODE[4]; /* '<S521>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_o;  /* '<S158>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_j;  /* '<S140>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_i;  /* '<S139>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_f;  /* '<S245>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_k;  /* '<S227>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_io; /* '<S226>/Integrator, Second-Order' */
  int_T IntegratorSecondOrderLimited_MO[3];
                                 /* '<S684>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited__k[3];
                                 /* '<S696>/Integrator, Second-Order Limited' */
  uint16_T temporalCounter_i1;         /* '<S31>/State_Machine' */
  uint16_T temporalCounter_i2;         /* '<S31>/State_Machine' */
  uint16_T temporalCounter_i3;         /* '<S31>/State_Machine' */
  uint16_T temporalCounter_i1_g;       /* '<S27>/Balancing' */
  volatile int8_T RateTransition18_ActiveBufIdx;/* '<S22>/Rate Transition18' */
  volatile int8_T RateTransition19_ActiveBufIdx;/* '<S22>/Rate Transition19' */
  volatile int8_T RateTransition20_ActiveBufIdx;/* '<S22>/Rate Transition20' */
  volatile int8_T RateTransition21_ActiveBufIdx;/* '<S22>/Rate Transition21' */
  uint8_T is_active_c2_ConfiguredVirtualV;/* '<S31>/State_Machine' */
  uint8_T is_MainStateMachine;         /* '<S31>/State_Machine' */
  uint8_T is_Charging;                 /* '<S31>/State_Machine' */
  uint8_T is_ChargerContactorState;    /* '<S31>/State_Machine' */
  uint8_T is_CloseChgrContactors;      /* '<S31>/State_Machine' */
  uint8_T is_OpenChgrContactors;       /* '<S31>/State_Machine' */
  uint8_T is_InverterContactorState;   /* '<S31>/State_Machine' */
  uint8_T is_CloseInvtrContactors;     /* '<S31>/State_Machine' */
  uint8_T is_OpenInvtrContactors;      /* '<S31>/State_Machine' */
  uint8_T is_active_c1_ConfiguredVirtualV;/* '<S27>/Balancing' */
  uint8_T is_c1_ConfiguredVirtualVehicleM;/* '<S27>/Balancing' */
  uint8_T is_BalancingON;              /* '<S27>/Balancing' */
  boolean_T IntegratorSecondOrder_DWORK1;/* '<S521>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_k;/* '<S158>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_a;/* '<S140>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_e;/* '<S139>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_n;/* '<S245>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_kp;/* '<S227>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_kx;/* '<S226>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrderLimited_DW;
                                 /* '<S684>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited__d;
                                 /* '<S696>/Integrator, Second-Order Limited' */
  boolean_T FaultPresent;              /* '<S31>/State_Machine' */
  boolean_T flgBalCompl;               /* '<S27>/Balancing' */
  Contact ChrgCntctState;              /* '<S31>/State_Machine' */
  Contact InvtrCntctState;             /* '<S31>/State_Machine' */
  DW_CoreSubsys_ConfiguredVi_dp_T CoreSubsys_l[4];
                                    /* '<S523>/Clutch Partitioned Parameters' */
  DW_CoreSubsys_ConfiguredVi_mj_T CoreSubsys_n[3];/* '<S435>/Unwrap' */
  DW_EnabledSubsystem1_Configur_T EnabledSubsystem1_j;/* '<S221>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Configure_T EnabledSubsystem_n;/* '<S221>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Configur_T EnabledSubsystem1_i;/* '<S220>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Configure_T EnabledSubsystem_g;/* '<S220>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Configur_T EnabledSubsystem1_d;/* '<S134>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Configure_T EnabledSubsystem_h;/* '<S134>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Configur_T EnabledSubsystem1;/* '<S133>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Configure_T EnabledSubsystem;/* '<S133>/Enabled Subsystem' */
};

/* Continuous states for system '<Root>/AdasPlantModel' */
struct X_AdasPlantModel_ConfiguredVi_T {
  real_T Integrator_CSTATE_p;          /* '<S631>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S610>/Integrator' */
  real_T ubvbwb_CSTATE[3];             /* '<S407>/ub,vb,wb' */
  real_T Integrator1_CSTATE_h[4];      /* '<S106>/Integrator1' */
  real_T Integrator_CSTATE_e[4];       /* '<S517>/Integrator' */
  real_T Integrator_CSTATE_c[4];       /* '<S518>/Integrator' */
  real_T Integrator1_CSTATE_n[4];      /* '<S374>/Integrator1' */
  real_T Integrator_CSTATE_m;          /* '<S580>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S579>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S588>/Integrator' */
  real_T Integrator_CSTATE_cw;         /* '<S587>/Integrator' */
  real_T Integrator_CSTATE_cf[4];      /* '<S520>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE[8];/* '<S521>/Integrator, Second-Order' */
  real_T pqr_CSTATE[3];                /* '<S407>/p,q,r ' */
  real_T Integrator1_CSTATE_e[12];     /* '<S375>/Integrator1' */
  real_T xeyeze_CSTATE[3];             /* '<S407>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S413>/phi theta psi' */
  real_T IntegratorSecondOrder_CSTATE_e[2];/* '<S158>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_d[4];      /* '<S290>/Integrator1' */
  real_T Integrator1_CSTATE_nd[4];     /* '<S291>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_a[2];/* '<S140>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_id;         /* '<S132>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_d[2];/* '<S139>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_nx;        /* '<S127>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_k[2];/* '<S245>/Integrator, Second-Order' */
  real_T IntegratorSecondOrder_CSTATE_ak[2];/* '<S227>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_jz;         /* '<S219>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_l[2];/* '<S226>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_dc;        /* '<S214>/Integrator1' */
  real_T Integrator1_CSTATE_a[2];      /* '<S393>/Integrator1' */
  real_T Integrator_CSTATE_ez[3];      /* '<S411>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S602>/Integrator' */
  real_T Integrator_CSTATE_e0;         /* '<S601>/Integrator' */
  real_T Integrator_CSTATE_d[2];       /* '<S553>/Integrator' */
  real_T MotorCouplingDynamics_CSTATE; /* '<S658>/Motor Coupling Dynamics' */
  real_T Integrator_CSTATE_a;          /* '<S644>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S666>/Integrator' */
  real_T IntegratorLimited_CSTATE;     /* '<S633>/Integrator Limited' */
  real_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S684>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited__i[6];
                                 /* '<S696>/Integrator, Second-Order Limited' */
  X_CoreSubsys_ConfiguredVirt_i_T CoreSubsys_l[4];/* '<S527>/CoreSubsys' */
};

/* State derivatives for system '<Root>/AdasPlantModel' */
struct XDot_AdasPlantModel_Configure_T {
  real_T Integrator_CSTATE_p;          /* '<S631>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S610>/Integrator' */
  real_T ubvbwb_CSTATE[3];             /* '<S407>/ub,vb,wb' */
  real_T Integrator1_CSTATE_h[4];      /* '<S106>/Integrator1' */
  real_T Integrator_CSTATE_e[4];       /* '<S517>/Integrator' */
  real_T Integrator_CSTATE_c[4];       /* '<S518>/Integrator' */
  real_T Integrator1_CSTATE_n[4];      /* '<S374>/Integrator1' */
  real_T Integrator_CSTATE_m;          /* '<S580>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S579>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S588>/Integrator' */
  real_T Integrator_CSTATE_cw;         /* '<S587>/Integrator' */
  real_T Integrator_CSTATE_cf[4];      /* '<S520>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE[8];/* '<S521>/Integrator, Second-Order' */
  real_T pqr_CSTATE[3];                /* '<S407>/p,q,r ' */
  real_T Integrator1_CSTATE_e[12];     /* '<S375>/Integrator1' */
  real_T xeyeze_CSTATE[3];             /* '<S407>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S413>/phi theta psi' */
  real_T IntegratorSecondOrder_CSTATE_e[2];/* '<S158>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_d[4];      /* '<S290>/Integrator1' */
  real_T Integrator1_CSTATE_nd[4];     /* '<S291>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_a[2];/* '<S140>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_id;         /* '<S132>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_d[2];/* '<S139>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_nx;        /* '<S127>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_k[2];/* '<S245>/Integrator, Second-Order' */
  real_T IntegratorSecondOrder_CSTATE_ak[2];/* '<S227>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_jz;         /* '<S219>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_l[2];/* '<S226>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_dc;        /* '<S214>/Integrator1' */
  real_T Integrator1_CSTATE_a[2];      /* '<S393>/Integrator1' */
  real_T Integrator_CSTATE_ez[3];      /* '<S411>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S602>/Integrator' */
  real_T Integrator_CSTATE_e0;         /* '<S601>/Integrator' */
  real_T Integrator_CSTATE_d[2];       /* '<S553>/Integrator' */
  real_T MotorCouplingDynamics_CSTATE; /* '<S658>/Motor Coupling Dynamics' */
  real_T Integrator_CSTATE_a;          /* '<S644>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S666>/Integrator' */
  real_T IntegratorLimited_CSTATE;     /* '<S633>/Integrator Limited' */
  real_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S684>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited__i[6];
                                 /* '<S696>/Integrator, Second-Order Limited' */
  XDot_CoreSubsys_Configured_ej_T CoreSubsys_l[4];/* '<S527>/CoreSubsys' */
};

/* State Disabled for system '<Root>/AdasPlantModel' */
struct XDis_AdasPlantModel_Configure_T {
  boolean_T Integrator_CSTATE_p;       /* '<S631>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S610>/Integrator' */
  boolean_T ubvbwb_CSTATE[3];          /* '<S407>/ub,vb,wb' */
  boolean_T Integrator1_CSTATE_h[4];   /* '<S106>/Integrator1' */
  boolean_T Integrator_CSTATE_e[4];    /* '<S517>/Integrator' */
  boolean_T Integrator_CSTATE_c[4];    /* '<S518>/Integrator' */
  boolean_T Integrator1_CSTATE_n[4];   /* '<S374>/Integrator1' */
  boolean_T Integrator_CSTATE_m;       /* '<S580>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S579>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S588>/Integrator' */
  boolean_T Integrator_CSTATE_cw;      /* '<S587>/Integrator' */
  boolean_T Integrator_CSTATE_cf[4];   /* '<S520>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE[8];/* '<S521>/Integrator, Second-Order' */
  boolean_T pqr_CSTATE[3];             /* '<S407>/p,q,r ' */
  boolean_T Integrator1_CSTATE_e[12];  /* '<S375>/Integrator1' */
  boolean_T xeyeze_CSTATE[3];          /* '<S407>/xe,ye,ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S413>/phi theta psi' */
  boolean_T IntegratorSecondOrder_CSTATE_e[2];/* '<S158>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_d[4];   /* '<S290>/Integrator1' */
  boolean_T Integrator1_CSTATE_nd[4];  /* '<S291>/Integrator1' */
  boolean_T IntegratorSecondOrder_CSTATE_a[2];/* '<S140>/Integrator, Second-Order' */
  boolean_T Integrator_CSTATE_id;      /* '<S132>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE_d[2];/* '<S139>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_nx;     /* '<S127>/Integrator1' */
  boolean_T IntegratorSecondOrder_CSTATE_k[2];/* '<S245>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_CSTATE_ak[2];/* '<S227>/Integrator, Second-Order' */
  boolean_T Integrator_CSTATE_jz;      /* '<S219>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE_l[2];/* '<S226>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_dc;     /* '<S214>/Integrator1' */
  boolean_T Integrator1_CSTATE_a[2];   /* '<S393>/Integrator1' */
  boolean_T Integrator_CSTATE_ez[3];   /* '<S411>/Integrator' */
  boolean_T Integrator_CSTATE_n;       /* '<S602>/Integrator' */
  boolean_T Integrator_CSTATE_e0;      /* '<S601>/Integrator' */
  boolean_T Integrator_CSTATE_d[2];    /* '<S553>/Integrator' */
  boolean_T MotorCouplingDynamics_CSTATE;/* '<S658>/Motor Coupling Dynamics' */
  boolean_T Integrator_CSTATE_a;       /* '<S644>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S666>/Integrator' */
  boolean_T IntegratorLimited_CSTATE;  /* '<S633>/Integrator Limited' */
  boolean_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S684>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited__i[6];
                                 /* '<S696>/Integrator, Second-Order Limited' */
  XDis_CoreSubsys_ConfiguredV_k_T CoreSubsys_l[4];/* '<S527>/CoreSubsys' */
};

/* Zero-crossing (trigger) state for system '<Root>/AdasPlantModel' */
struct ZCE_AdasPlantModel_Configured_T {
  ZCSigState Integrator_Reset_ZCE;     /* '<S580>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_j;   /* '<S588>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S602>/Integrator' */
  ZCE_CoreSubsys_ConfiguredV_a5_T CoreSubsys_n[3];/* '<S435>/Unwrap' */
  ZCE_TriggeredSubsystem_Config_T TriggeredSubsystem_l;/* '<S221>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_Config_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_Config_T TriggeredSubsystem_k;/* '<S134>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_Config_T TriggeredSubsystem;/* '<S133>/Triggered Subsystem' */
};

/* Parameters for system: '<S133>/Enabled Subsystem' */
struct P_EnabledSubsystem_Configured_T_ {
  real_T Fright_Y0;                    /* Computed Parameter: Fright_Y0
                                        * Referenced by: '<S141>/Fright'
                                        */
};

/* Parameters for system: '<S133>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_Configure_T_ {
  real_T Fleft_Y0;                     /* Computed Parameter: Fleft_Y0
                                        * Referenced by: '<S142>/Fleft'
                                        */
};

/* Parameters for system: '<S133>/Triggered Subsystem' */
struct P_TriggeredSubsystem_Configur_T_ {
  real_T Out_Y0;                       /* Computed Parameter: Out_Y0
                                        * Referenced by: '<S143>/Out'
                                        */
  real_T xleft_Y0;                     /* Computed Parameter: xleft_Y0
                                        * Referenced by: '<S143>/xleft'
                                        */
  real_T xright_Y0;                    /* Computed Parameter: xright_Y0
                                        * Referenced by: '<S143>/xright'
                                        */
};

/* Parameters for system: '<S292>/For each track and axle combination calculate suspension forces and moments' */
struct P_CoreSubsys_ConfiguredVirt_o_T_ {
  real_T SelectSteerCamberSlope_AxleNums;
                              /* Mask Parameter: SelectSteerCamberSlope_AxleNums
                               * Referenced by: '<S327>/Axle Numbers'
                               */
  real_T SelectStaticToeSetting_AxleNums[2];
                              /* Mask Parameter: SelectStaticToeSetting_AxleNums
                               * Referenced by: '<S353>/Axle Numbers'
                               */
  real_T SelectSteerCasterSlope_AxleNums;
                              /* Mask Parameter: SelectSteerCasterSlope_AxleNums
                               * Referenced by: '<S336>/Axle Numbers'
                               */
  real_T Constrainedspringdampercombinat[2];
                              /* Mask Parameter: Constrainedspringdampercombinat
                               * Referenced by: '<S367>/Axle Numbers'
                               */
  real_T Constant1_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S366>/Constant1'
                                        */
  real_T VehicleVehicleWheelOffset3_Valu[3];/* Expression: [0 cumsum(NumWhlsByAxl)]
                                             * Referenced by: '<S302>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T HeightSignConvention_Gain;    /* Expression: -1
                                        * Referenced by: '<S360>/Height Sign Convention'
                                        */
  real_T SignConvention_Gain;          /* Expression: -1
                                        * Referenced by: '<S307>/Sign Convention'
                                        */
  real_T Gain5_Gain;                   /* Expression: VerticalSign
                                        * Referenced by: '<S309>/Gain5'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S303>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset1_Valu[2];/* Expression: StrgEnByAxl
                                             * Referenced by: '<S303>/Vehicle Vehicle Wheel Offset1'
                                             */
  real_T VehicleVehicleWheelOffset3_Va_i[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S347>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S347>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S347>/Gain'
                                        */
  real_T Gain5_Gain_b;                 /* Expression: VerticalSign
                                        * Referenced by: '<S314>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: WhlMzSign
                                        * Referenced by: '<S314>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: LateralSign
                                        * Referenced by: '<S314>/Gain3'
                                        */
  real_T Constant6_Value[4];           /* Expression: LngSteerCompl(2,:)
                                        * Referenced by: '<S357>/Constant6'
                                        */
  real_T Gain1_Gain;                   /* Expression: LongitudinalSign
                                        * Referenced by: '<S314>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: LongitudinalSign
                                        * Referenced by: '<S357>/Gain2'
                                        */
  real_T Constant3_Value[4];           /* Expression: LngSteerCompl(1,:)
                                        * Referenced by: '<S357>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S357>/Switch'
                                        */
  real_T Gain_Gain_h;                  /* Expression: SteerSign
                                        * Referenced by: '<S314>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: SteerSign
                                        * Referenced by: '<S309>/Gain'
                                        */
  real_T Gain4_Gain_e;                 /* Expression: WhlMzSign
                                        * Referenced by: '<S309>/Gain4'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: LateralSign
                                        * Referenced by: '<S309>/Gain3'
                                        */
  real_T Constant6_Value_d[4];         /* Expression: LngCambCompl(2,:)
                                        * Referenced by: '<S324>/Constant6'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S309>/Gain1'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S324>/Gain2'
                                        */
  real_T Constant1_Value_d[4];         /* Expression: LngCambCompl(1,:)
                                        * Referenced by: '<S324>/Constant1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0
                                        * Referenced by: '<S324>/Switch'
                                        */
  real_T Gain4_Gain_h;                 /* Expression: VerticalSign
                                        * Referenced by: '<S310>/Gain4'
                                        */
  real_T Gain_Gain_p;                  /* Expression: SteerSign
                                        * Referenced by: '<S310>/Gain'
                                        */
  real_T Constant4_Value[4];           /* Expression: LngCastCompl(2,:)
                                        * Referenced by: '<S333>/Constant4'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S310>/Gain2'
                                        */
  real_T Gain2_Gain_d2;                /* Expression: LongitudinalSign
                                        * Referenced by: '<S333>/Gain2'
                                        */
  real_T Constant2_Value[4];           /* Expression: LngCastCompl(1,:)
                                        * Referenced by: '<S333>/Constant2'
                                        */
  real_T Switch_Threshold_d2;          /* Expression: 0
                                        * Referenced by: '<S333>/Switch'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_c[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S311>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S311>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1/2
                                        * Referenced by: '<S311>/Gain'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: VerticalSign
                                        * Referenced by: '<S360>/Gain2'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: VerticalSign
                                        * Referenced by: '<S313>/Gain4'
                                        */
  real_T Constant2_Value_i[4];         /* Expression: LngWhlCtrCompl(2,:)
                                        * Referenced by: '<S346>/Constant2'
                                        */
  real_T Gain_Gain_n;                  /* Expression: LongitudinalSign
                                        * Referenced by: '<S313>/Gain'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S346>/Gain2'
                                        */
  real_T Constant1_Value_i[4];         /* Expression: LngWhlCtrCompl(1,:)
                                        * Referenced by: '<S346>/Constant1'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S346>/Switch'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S313>/Gain1'
                                        */
  real_T Gain4_Gain_ep;                /* Expression: VerticalSign
                                        * Referenced by: '<S312>/Gain4'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: LateralSign
                                        * Referenced by: '<S312>/Gain3'
                                        */
  real_T Constant3_Value_p[4];         /* Expression: LatWhlCtrComplLngBrk(2,:)
                                        * Referenced by: '<S342>/Constant3'
                                        */
  real_T Gain_Gain_ia;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S312>/Gain'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S342>/Gain2'
                                        */
  real_T Constant1_Value_p[4];         /* Expression: LatWhlCtrComplLngBrk(1,:)
                                        * Referenced by: '<S342>/Constant1'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S342>/Switch'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: LateralSign
                                        * Referenced by: '<S312>/Gain1'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S371>/Constant'
                                        */
  real_T Constant_Value_l[2];          /* Expression: AntiSwayEnByAxl
                                        * Referenced by: '<S366>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_h[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S361>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_l1;            /* Expression: 1
                                        * Referenced by: '<S361>/Constant'
                                        */
  real_T Gain_Gain_ih;                 /* Expression: 1/2
                                        * Referenced by: '<S361>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S361>/Gain1'
                                        */
  real_T Gain4_Gain_b;                 /* Expression: VerticalSign
                                        * Referenced by: '<S360>/Gain4'
                                        */
  real_T VehicleForceSign_Gain;        /* Expression: -1
                                        * Referenced by: '<S359>/Vehicle Force Sign'
                                        */
  real_T Signconvention_Gain;          /* Expression: -1
                                        * Referenced by: '<S359>/Sign convention'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S305>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_e[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S308>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_cm;            /* Expression: 1
                                        * Referenced by: '<S308>/Constant'
                                        */
  real_T Gain_Gain_dx;                 /* Expression: 1/2
                                        * Referenced by: '<S308>/Gain'
                                        */
};

/* Parameters for system: '<S376>/Wheel to Body Transform' */
struct P_CoreSubsys_ConfiguredVirt_c_T_ {
  real_T Constant_Value[3];            /* Expression: [pi;0;0]
                                        * Referenced by: '<S378>/Constant'
                                        */
};

/* Parameters for system: '<S288>/Wheel to Body Transform' */
struct P_CoreSubsys_ConfiguredVir_cd_T_ {
  real_T Constant1_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S384>/Constant1'
                                        */
  real_T Constant_Value[3];            /* Expression: [pi;0;0]
                                        * Referenced by: '<S384>/Constant'
                                        */
};

/* Parameters for system: '<S435>/Unwrap' */
struct P_CoreSubsys_ConfiguredVirt_a_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S441>/Constant'
                                       */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S442>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S442>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S442>/Unit Delay'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S440>/Memory1'
                                        */
};

/* Parameters for system: '<S527>/Clutch' */
struct P_Clutch_ConfiguredVirtualVeh_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S531>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S529>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S529>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S529>/Constant2'
                                        */
  real_T u_Gain;                       /* Expression: -4
                                        * Referenced by: '<S530>/-4'
                                        */
  boolean_T yn_Y0;                     /* Computed Parameter: yn_Y0
                                        * Referenced by: '<S532>/yn'
                                        */
  boolean_T yn_Y0_n;                   /* Computed Parameter: yn_Y0_n
                                        * Referenced by: '<S531>/yn'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S536>/Unit Delay'
                                */
  boolean_T CombinatorialLogic_table[8];
                                 /* Computed Parameter: CombinatorialLogic_table
                                  * Referenced by: '<S536>/Combinatorial  Logic'
                                  */
};

/* Parameters for system: '<S523>/Clutch Partitioned Parameters' */
struct P_CoreSubsys_ConfiguredVirt_l_T_ {
  real_T Clutch_OmegaTol;              /* Mask Parameter: Clutch_OmegaTol
                                        * Referenced by: '<S527>/Clutch'
                                        */
  P_Clutch_ConfiguredVirtualVeh_T sf_Clutch;/* '<S527>/Clutch' */
};

/* Parameters for system: '<Root>/AdasPlantModel' */
struct P_AdasPlantModel_ConfiguredVi_T_ {
  real_T SteerTorqueControl_A;         /* Mask Parameter: SteerTorqueControl_A
                                        * Referenced by: '<S132>/Gain3'
                                        */
  real_T SteerTorqueControl_A_i;       /* Mask Parameter: SteerTorqueControl_A_i
                                        * Referenced by: '<S219>/Gain3'
                                        */
  real_T IndependentKandCSuspension_Axle[4];
                              /* Mask Parameter: IndependentKandCSuspension_Axle
                               * Referenced by: '<S292>/Axle Number'
                               */
  real_T CombinedSlipWheel2DOF_BOTTOM_OF;
                              /* Mask Parameter: CombinedSlipWheel2DOF_BOTTOM_OF
                               * Referenced by: '<S514>/Magic Tire Const Input'
                               */
  real_T CombinedSlipWheel2DOF_BOTTOM_ST;
                              /* Mask Parameter: CombinedSlipWheel2DOF_BOTTOM_ST
                               * Referenced by: '<S514>/Magic Tire Const Input'
                               */
  real_T CombinedSlipWheel2DOF_BREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_BREFF
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T VehicleBody6DOF_Cs[31];       /* Mask Parameter: VehicleBody6DOF_Cs
                                        * Referenced by: '<S434>/Cs'
                                        */
  real_T VehicleBody6DOF_Cym[31];      /* Mask Parameter: VehicleBody6DOF_Cym
                                        * Referenced by: '<S434>/Cym'
                                        */
  real_T SteerTorqueControl_D;         /* Mask Parameter: SteerTorqueControl_D
                                        * Referenced by: '<S132>/Gain2'
                                        */
  real_T SteerTorqueControl_D_c;       /* Mask Parameter: SteerTorqueControl_D_c
                                        * Referenced by: '<S219>/Gain2'
                                        */
  real_T CombinedSlipWheel2DOF_DREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_DREFF
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T FrontSteering_DbWdth;         /* Mask Parameter: FrontSteering_DbWdth
                                        * Referenced by: '<S118>/Backlash'
                                        */
  real_T RearSteering_DbWdth;          /* Mask Parameter: RearSteering_DbWdth
                                        * Referenced by: '<S205>/Backlash'
                                        */
  real_T FrontSteering_Eta;            /* Mask Parameter: FrontSteering_Eta
                                        * Referenced by: '<S126>/Gain1'
                                        */
  real_T RearSteering_Eta;             /* Mask Parameter: RearSteering_Eta
                                        * Referenced by: '<S213>/Gain1'
                                        */
  real_T CombinedSlipWheel2DOF_FREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_FREFF
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_GRAVITY;
                                /* Mask Parameter: CombinedSlipWheel2DOF_GRAVITY
                                 * Referenced by: '<S521>/Fg'
                                 */
  real_T SteerTorqueControl_I;         /* Mask Parameter: SteerTorqueControl_I
                                        * Referenced by: '<S132>/Gain1'
                                        */
  real_T SteerTorqueControl_I_f;       /* Mask Parameter: SteerTorqueControl_I_f
                                        * Referenced by: '<S219>/Gain1'
                                        */
  real_T VehicleBody6DOF_Iveh[9];      /* Mask Parameter: VehicleBody6DOF_Iveh
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T ClutchPartitionedParameters_Iyy[4];
                              /* Mask Parameter: ClutchPartitionedParameters_Iyy
                               * Referenced by: '<S523>/Clutch Partitioned Parameters'
                               */
  real_T SteerTorqueControl_OutSatLowLmt;
                              /* Mask Parameter: SteerTorqueControl_OutSatLowLmt
                               * Referenced by: '<S132>/Saturation'
                               */
  real_T SteerTorqueControl_OutSatLowL_b;
                              /* Mask Parameter: SteerTorqueControl_OutSatLowL_b
                               * Referenced by: '<S219>/Saturation'
                               */
  real_T SteerTorqueControl_OutSatUpLmt;
                               /* Mask Parameter: SteerTorqueControl_OutSatUpLmt
                                * Referenced by: '<S132>/Saturation'
                                */
  real_T SteerTorqueControl_OutSatUpLm_l;
                              /* Mask Parameter: SteerTorqueControl_OutSatUpLm_l
                               * Referenced by: '<S219>/Saturation'
                               */
  real_T SteerTorqueControl_P;         /* Mask Parameter: SteerTorqueControl_P
                                        * Referenced by: '<S132>/Gain'
                                        */
  real_T SteerTorqueControl_P_p;       /* Mask Parameter: SteerTorqueControl_P_p
                                        * Referenced by: '<S219>/Gain'
                                        */
  real_T CombinedSlipWheel2DOF_PFZ1;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_PFZ1
                                    * Referenced by: '<S514>/Magic Tire Const Input'
                                    */
  real_T CombinedSlipWheel2DOF_Q_FCX;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCX
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FCY;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCY
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FCY2;
                                 /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCY2
                                  * Referenced by: '<S514>/Magic Tire Const Input'
                                  */
  real_T CombinedSlipWheel2DOF_Q_FZ1;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ1
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FZ2;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ2
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FZ3;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ3
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_RE0;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_RE0
                                   * Referenced by: '<S514>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_V1;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_Q_V1
                                    * Referenced by: '<S514>/Magic Tire Const Input'
                                    */
  real_T CombinedSlipWheel2DOF_Q_V2;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_Q_V2
                                    * Referenced by: '<S514>/Magic Tire Const Input'
                                    */
  real_T DragForce_R;                  /* Mask Parameter: DragForce_R
                                        * Referenced by: '<S434>/.5.*A.*Pabs.//R.//T'
                                        */
  real_T CombinedSlipWheel2DOF_Rm[4];/* Mask Parameter: CombinedSlipWheel2DOF_Rm
                                      * Referenced by: '<S526>/Torque Conversion'
                                      */
  real_T FrontSteering_SptlAng;        /* Mask Parameter: FrontSteering_SptlAng
                                        * Referenced by:
                                        *   '<S155>/MATLAB Function'
                                        *   '<S155>/MATLAB Function1'
                                        */
  real_T RearSteering_SptlAng;         /* Mask Parameter: RearSteering_SptlAng
                                        * Referenced by:
                                        *   '<S242>/MATLAB Function'
                                        *   '<S242>/MATLAB Function1'
                                        */
  real_T CombinedSlipWheel2DOF_VERTICAL_;
                              /* Mask Parameter: CombinedSlipWheel2DOF_VERTICAL_
                               * Referenced by: '<S514>/Magic Tire Const Input'
                               */
  real_T FrontSteering_VehSpdBpts[2];/* Mask Parameter: FrontSteering_VehSpdBpts
                                      * Referenced by: '<S126>/TrqAssistTbl'
                                      */
  real_T RearSteering_VehSpdBpts[2];  /* Mask Parameter: RearSteering_VehSpdBpts
                                       * Referenced by: '<S213>/TrqAssistTbl'
                                       */
  real_T IndependentKandCSuspension_WhlN[4];
                              /* Mask Parameter: IndependentKandCSuspension_WhlN
                               * Referenced by: '<S292>/Wheel Number'
                               */
  real_T VehicleBody6DOF_Xe_o[3];      /* Mask Parameter: VehicleBody6DOF_Xe_o
                                        * Referenced by: '<S407>/xe,ye,ze'
                                        */
  real_T ThreeaxisInertialMeasurementUni[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementUni
                               * Referenced by: '<S677>/Measurement bias'
                               */
  real_T ThreeaxisInertialMeasurementU_f[9];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_f
                               * Referenced by: '<S677>/Scale factors & Cross-coupling  errors'
                               */
  real_T VehicleBody6DOF_beta_w[31];   /* Mask Parameter: VehicleBody6DOF_beta_w
                                        * Referenced by:
                                        *   '<S434>/Cs'
                                        *   '<S434>/Cym'
                                        */
  real_T ClutchPartitionedParameters_br[4];
                               /* Mask Parameter: ClutchPartitionedParameters_br
                                * Referenced by: '<S523>/Clutch Partitioned Parameters'
                                */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S55>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S56>/Constant'
                                      */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S59>/Constant'
                                     */
  real_T CompareToConstant_const_l; /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S66>/Constant'
                                     */
  real_T VehicleBody6DOF_d;            /* Mask Parameter: VehicleBody6DOF_d
                                        * Referenced by:
                                        *   '<S392>/vehdyncginert'
                                        *   '<S448>/Constant'
                                        */
  real_T RackandPinforDynStr_d;        /* Mask Parameter: RackandPinforDynStr_d
                                        * Referenced by:
                                        *   '<S172>/Constant2'
                                        *   '<S172>/Constant3'
                                        *   '<S173>/Constant2'
                                        *   '<S173>/Constant3'
                                        *   '<S174>/Constant2'
                                        *   '<S174>/Constant3'
                                        */
  real_T RackandPinforDynStr_d_o;     /* Mask Parameter: RackandPinforDynStr_d_o
                                       * Referenced by:
                                       *   '<S259>/Constant2'
                                       *   '<S259>/Constant3'
                                       *   '<S260>/Constant2'
                                       *   '<S260>/Constant3'
                                       *   '<S261>/Constant2'
                                       *   '<S261>/Constant3'
                                       */
  real_T CombinedSlipWheel2DOF_disk_abor[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_disk_abor
                               * Referenced by: '<S526>/Disk brake actuator bore'
                               */
  real_T VehicleBody6DOF_eul_o[3];     /* Mask Parameter: VehicleBody6DOF_eul_o
                                        * Referenced by: '<S413>/phi theta psi'
                                        */
  real_T ThreeaxisInertialMeasurementU_c[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_c
                               * Referenced by: '<S678>/Measurement bias'
                               */
  real_T ThreeaxisInertialMeasurementU_p[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_p
                               * Referenced by: '<S678>/g-sensitive bias'
                               */
  real_T ThreeaxisInertialMeasurementU_k[9];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_k
                               * Referenced by: '<S678>/Scale factors & Cross-coupling  errors '
                               */
  real_T VehicleBody6DOF_hl;           /* Mask Parameter: VehicleBody6DOF_hl
                                        * Referenced by: '<S450>/Constant2'
                                        */
  real_T ThreeaxisInertialMeasurementU_d[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_d
                               * Referenced by: '<S677>/wl_ins'
                               */
  real_T VehicleBody6DOF_latOff;       /* Mask Parameter: VehicleBody6DOF_latOff
                                        * Referenced by: '<S453>/latOff'
                                        */
  real_T VehicleBody6DOF_longOff;     /* Mask Parameter: VehicleBody6DOF_longOff
                                       * Referenced by: '<S453>/longOff'
                                       */
  real_T CombinedSlipWheel2DOF_mu_kineti[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_mu_kineti
                               * Referenced by:
                               *   '<S524>/Ratio of static to kinetic'
                               *   '<S524>/Ratio of static to kinetic1'
                               *   '<S526>/Torque Conversion'
                               */
  real_T CombinedSlipWheel2DOF_mu_static[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_mu_static
                               * Referenced by: '<S524>/Ratio of static to kinetic'
                               */
  real_T CombinedSlipWheel2DOF_num_pads[4];
                               /* Mask Parameter: CombinedSlipWheel2DOF_num_pads
                                * Referenced by: '<S526>/Number of brake pads'
                                */
  real_T ClutchPartitionedParameters_ome[4];
                              /* Mask Parameter: ClutchPartitionedParameters_ome
                               * Referenced by: '<S523>/Clutch Partitioned Parameters'
                               */
  real_T VehicleBody6DOF_p_o[3];       /* Mask Parameter: VehicleBody6DOF_p_o
                                        * Referenced by: '<S407>/p,q,r '
                                        */
  real_T div0protectpoly_thresh;       /* Mask Parameter: div0protectpoly_thresh
                                        * Referenced by:
                                        *   '<S68>/Constant'
                                        *   '<S69>/Constant'
                                        */
  real_T div0protectpoly_thresh_b;   /* Mask Parameter: div0protectpoly_thresh_b
                                      * Referenced by:
                                      *   '<S129>/Constant'
                                      *   '<S130>/Constant'
                                      */
  real_T div0protectpoly_thresh_a;   /* Mask Parameter: div0protectpoly_thresh_a
                                      * Referenced by:
                                      *   '<S216>/Constant'
                                      *   '<S217>/Constant'
                                      */
  real_T div0protectabspoly_thresh; /* Mask Parameter: div0protectabspoly_thresh
                                     * Referenced by:
                                     *   '<S619>/Constant'
                                     *   '<S620>/Constant'
                                     */
  real_T div0protectpoly_thresh_p;   /* Mask Parameter: div0protectpoly_thresh_p
                                      * Referenced by:
                                      *   '<S652>/Constant'
                                      *   '<S653>/Constant'
                                      */
  real_T div0protectabspoly_thresh_f;
                                  /* Mask Parameter: div0protectabspoly_thresh_f
                                   * Referenced by:
                                   *   '<S649>/Constant'
                                   *   '<S650>/Constant'
                                   */
  real_T CombinedSlipWheel2DOF_turnslip;
                               /* Mask Parameter: CombinedSlipWheel2DOF_turnslip
                                * Referenced by: '<S514>/Magic Tire Const Input'
                                */
  real_T VehicleBody6DOF_vertOff;     /* Mask Parameter: VehicleBody6DOF_vertOff
                                       * Referenced by: '<S453>/vertOff '
                                       */
  real_T ContLPF_wc;                   /* Mask Parameter: ContLPF_wc
                                        * Referenced by: '<S290>/Constant'
                                        */
  real_T ContLPF2_wc;                  /* Mask Parameter: ContLPF2_wc
                                        * Referenced by: '<S291>/Constant'
                                        */
  real_T ContLPF_wc_p;                 /* Mask Parameter: ContLPF_wc_p
                                        * Referenced by: '<S374>/Constant'
                                        */
  real_T ContLPF1_wc;                  /* Mask Parameter: ContLPF1_wc
                                        * Referenced by: '<S375>/Constant'
                                        */
  real_T Bushings_wc[2];               /* Mask Parameter: Bushings_wc
                                        * Referenced by: '<S393>/Constant'
                                        */
  real_T SecondorderDynamics_wn;       /* Mask Parameter: SecondorderDynamics_wn
                                        * Referenced by:
                                        *   '<S684>/2*zeta * wn'
                                        *   '<S684>/wn^2'
                                        */
  real_T SecondorderDynamics_wn_p;   /* Mask Parameter: SecondorderDynamics_wn_p
                                      * Referenced by:
                                      *   '<S696>/2*zeta * wn'
                                      *   '<S696>/wn^2'
                                      */
  real_T VehicleBody6DOF_xbdot_o[3];  /* Mask Parameter: VehicleBody6DOF_xbdot_o
                                       * Referenced by: '<S407>/ub,vb,wb'
                                       */
  real_T VehicleBody6DOF_xdot_tol;   /* Mask Parameter: VehicleBody6DOF_xdot_tol
                                      * Referenced by:
                                      *   '<S444>/Constant'
                                      *   '<S445>/Constant'
                                      *   '<S480>/Constant'
                                      *   '<S481>/Constant'
                                      */
  real_T VehicleBody6DOF_z1I[9];       /* Mask Parameter: VehicleBody6DOF_z1I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z1R[3];       /* Mask Parameter: VehicleBody6DOF_z1R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z1m;          /* Mask Parameter: VehicleBody6DOF_z1m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2I[9];       /* Mask Parameter: VehicleBody6DOF_z2I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2R[3];       /* Mask Parameter: VehicleBody6DOF_z2R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2m;          /* Mask Parameter: VehicleBody6DOF_z2m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3I[9];       /* Mask Parameter: VehicleBody6DOF_z3I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3R[3];       /* Mask Parameter: VehicleBody6DOF_z3R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3m;          /* Mask Parameter: VehicleBody6DOF_z3m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4I[9];       /* Mask Parameter: VehicleBody6DOF_z4I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4R[3];       /* Mask Parameter: VehicleBody6DOF_z4R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4m;          /* Mask Parameter: VehicleBody6DOF_z4m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5I[9];       /* Mask Parameter: VehicleBody6DOF_z5I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5R[3];       /* Mask Parameter: VehicleBody6DOF_z5R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5m;          /* Mask Parameter: VehicleBody6DOF_z5m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6I[9];       /* Mask Parameter: VehicleBody6DOF_z6I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6R[3];       /* Mask Parameter: VehicleBody6DOF_z6R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6m;          /* Mask Parameter: VehicleBody6DOF_z6m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7I[9];       /* Mask Parameter: VehicleBody6DOF_z7I
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7R[3];       /* Mask Parameter: VehicleBody6DOF_z7R
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7m;          /* Mask Parameter: VehicleBody6DOF_z7m
                                        * Referenced by: '<S392>/vehdyncginert'
                                        */
  real_T CombinedSlipWheel2DOF_zdoto[4];
                                  /* Mask Parameter: CombinedSlipWheel2DOF_zdoto
                                   * Referenced by: '<S521>/Integrator, Second-Order'
                                   */
  real_T SecondorderDynamics_zn;       /* Mask Parameter: SecondorderDynamics_zn
                                        * Referenced by: '<S684>/2*zeta * wn'
                                        */
  real_T SecondorderDynamics_zn_o;   /* Mask Parameter: SecondorderDynamics_zn_o
                                      * Referenced by: '<S696>/2*zeta * wn'
                                      */
  real_T State_Machine_SnsrFltThld;    /* Expression: SnsrFltThld
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -inf
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T DeadZone1_Start;              /* Expression: 0
                                        * Referenced by: '<S672>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: .01
                                        * Referenced by: '<S672>/Dead Zone1'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S60>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S60>/Constant2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S62>/Switch1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S60>/Switch2'
                                        */
  real_T rads_to_rpm_Gain;             /* Expression: 30/pi
                                        * Referenced by: '<S60>/rads_to_rpm'
                                        */
  real_T EffMap_bp01Data[14];          /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S60>/Eff Map'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1/100
                                        * Referenced by: '<S60>/Gain1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S51>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S47>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S47>/Saturation'
                                        */
  real_T rads_to_rpm_Gain_b;           /* Expression: 30/pi
                                        * Referenced by: '<S48>/rads_to_rpm'
                                        */
  real_T MaxEMTrqVsSpd_bp01Data[14];   /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S48>/MaxEMTrqVsSpd'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S47>/Switch'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S70>/Gain'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 0
                                        * Referenced by: '<S128>/Switch1'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: 0
                                        * Referenced by: '<S215>/Switch1'
                                        */
  real_T MagicTireConstInput_LATERAL_STI;/* Expression: LATERAL_STIFFNESS
                                          * Referenced by: '<S514>/Magic Tire Const Input'
                                          */
  real_T MagicTireConstInput_LONGITUDINA;/* Expression: LONGITUDINAL_STIFFNESS
                                          * Referenced by: '<S514>/Magic Tire Const Input'
                                          */
  real_T MagicTireConstInput_PCFX1;    /* Expression: PCFX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFX2;    /* Expression: PCFX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFX3;    /* Expression: PCFX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY1;    /* Expression: PCFY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY2;    /* Expression: PCFY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY3;    /* Expression: PCFY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCX1;     /* Expression: PCX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCY1;     /* Expression: PCY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX1;     /* Expression: PDX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX2;     /* Expression: PDX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX3;     /* Expression: PDX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP1;    /* Expression: PDXP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP2;    /* Expression: PDXP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP3;    /* Expression: PDXP3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY1;     /* Expression: PDY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY2;     /* Expression: PDY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY3;     /* Expression: PDY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP1;    /* Expression: PDYP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP2;    /* Expression: PDYP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP3;    /* Expression: PDYP3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP4;    /* Expression: PDYP4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PECP1;    /* Expression: PECP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PECP2;    /* Expression: PECP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX1;     /* Expression: PEX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX2;     /* Expression: PEX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX3;     /* Expression: PEX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX4;     /* Expression: PEX4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY1;     /* Expression: PEY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY2;     /* Expression: PEY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY3;     /* Expression: PEY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY4;     /* Expression: PEY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY5;     /* Expression: PEY5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHX1;     /* Expression: PHX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHX2;     /* Expression: PHX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHY1;     /* Expression: PHY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHY2;     /* Expression: PHY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP1;    /* Expression: PHYP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP2;    /* Expression: PHYP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP3;    /* Expression: PHYP3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP4;    /* Expression: PHYP4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX1;     /* Expression: PKX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX2;     /* Expression: PKX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX3;     /* Expression: PKX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY1;     /* Expression: PKY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY2;     /* Expression: PKY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY3;     /* Expression: PKY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY4;     /* Expression: PKY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY5;     /* Expression: PKY5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY6;     /* Expression: PKY6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY7;     /* Expression: PKY7
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKYP1;    /* Expression: PKYP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPMX1;    /* Expression: PPMX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX1;     /* Expression: PPX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX2;     /* Expression: PPX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX3;     /* Expression: PPX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX4;     /* Expression: PPX4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY1;     /* Expression: PPY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY2;     /* Expression: PPY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY3;     /* Expression: PPY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY4;     /* Expression: PPY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY5;     /* Expression: PPY5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPZ1;     /* Expression: PPZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPZ2;     /* Expression: PPZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVX1;     /* Expression: PVX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVX2;     /* Expression: PVX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY1;     /* Expression: PVY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY2;     /* Expression: PVY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY3;     /* Expression: PVY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY4;     /* Expression: PVY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBRP1;    /* Expression: QBRP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ1;     /* Expression: QBZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ10;    /* Expression: QBZ10
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ2;     /* Expression: QBZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ3;     /* Expression: QBZ3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ4;     /* Expression: QBZ4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ5;     /* Expression: QBZ5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ6;     /* Expression: QBZ6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ9;     /* Expression: QBZ9
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCRP1;    /* Expression: QCRP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCRP2;    /* Expression: QCRP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCZ1;     /* Expression: QCZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDRP1;    /* Expression: QDRP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDRP2;    /* Expression: QDRP2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDTP1;    /* Expression: QDTP1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ1;     /* Expression: QDZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ10;    /* Expression: QDZ10
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ11;    /* Expression: QDZ11
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ2;     /* Expression: QDZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ3;     /* Expression: QDZ3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ4;     /* Expression: QDZ4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ6;     /* Expression: QDZ6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ7;     /* Expression: QDZ7
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ8;     /* Expression: QDZ8
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ9;     /* Expression: QDZ9
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ1;     /* Expression: QEZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ2;     /* Expression: QEZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ3;     /* Expression: QEZ3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ4;     /* Expression: QEZ4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ5;     /* Expression: QEZ5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ1;     /* Expression: QHZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ2;     /* Expression: QHZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ3;     /* Expression: QHZ3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ4;     /* Expression: QHZ4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX1;     /* Expression: QSX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX10;    /* Expression: QSX10
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX11;    /* Expression: QSX11
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX12;    /* Expression: QSX12
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX13;    /* Expression: QSX13
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX14;    /* Expression: QSX14
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX2;     /* Expression: QSX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX3;     /* Expression: QSX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX4;     /* Expression: QSX4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX5;     /* Expression: QSX5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX6;     /* Expression: QSX6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX7;     /* Expression: QSX7
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX8;     /* Expression: QSX8
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX9;     /* Expression: QSX9
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY1;     /* Expression: QSY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY2;     /* Expression: QSY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY3;     /* Expression: QSY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY4;     /* Expression: QSY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY5;     /* Expression: QSY5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY6;     /* Expression: QSY6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY7;     /* Expression: QSY7
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY8;     /* Expression: QSY8
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RA1;    /* Expression: Q_RA1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RA2;    /* Expression: Q_RA2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RB1;    /* Expression: Q_RB1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RB2;    /* Expression: Q_RB2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX1;     /* Expression: RBX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX2;     /* Expression: RBX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX3;     /* Expression: RBX3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY1;     /* Expression: RBY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY2;     /* Expression: RBY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY3;     /* Expression: RBY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY4;     /* Expression: RBY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RCX1;     /* Expression: RCX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RCY1;     /* Expression: RCY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REX1;     /* Expression: REX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REX2;     /* Expression: REX2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REY1;     /* Expression: REY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REY2;     /* Expression: REY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHX1;     /* Expression: RHX1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHY1;     /* Expression: RHY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHY2;     /* Expression: RHY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY1;     /* Expression: RVY1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY2;     /* Expression: RVY2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY3;     /* Expression: RVY3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY4;     /* Expression: RVY4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY5;     /* Expression: RVY5
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY6;     /* Expression: RVY6
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ1;     /* Expression: SSZ1
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ2;     /* Expression: SSZ2
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ3;     /* Expression: SSZ3
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ4;     /* Expression: SSZ4
                                        * Referenced by: '<S514>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_vdynMF[279];/* Expression: vdynMF
                                          * Referenced by: '<S514>/Magic Tire Const Input'
                                          */
  real_T OpenDifferential_shaftSwitchMas;/* Expression: shaftSwitchMask
                                          * Referenced by: '<S553>/Open Differential'
                                          */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S644>/Constant'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S651>/Switch1'
                                        */
  real_T ZeroOrderHold3_Gain;          /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold3'
                                        */
  real_T ZeroOrderHold_Gain;           /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold1_Gain;          /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold1_Gain_a;        /* Expression: 1
                                        * Referenced by: '<S678>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold_Gain_k;         /* Expression: 1
                                        * Referenced by: '<S678>/Zero-Order Hold'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T Constant_Value_pe;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T RateTransition18_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S22>/Rate Transition18'
                                          */
  real_T RateTransition19_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S22>/Rate Transition19'
                                          */
  real_T RateTransition20_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S22>/Rate Transition20'
                                          */
  real_T RateTransition21_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S22>/Rate Transition21'
                                          */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S46>/Switch'
                                        */
  real_T DeadZone2_Start;              /* Expression: 0
                                        * Referenced by: '<S96>/Dead Zone2'
                                        */
  real_T DeadZone2_End;                /* Expression: .01
                                        * Referenced by: '<S96>/Dead Zone2'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S50>/Switch'
                                        */
  real_T rads_to_rpm_Gain_g;           /* Expression: 30/pi
                                        * Referenced by: '<S70>/rads_to_rpm'
                                        */
  real_T MaxMotTrqVsSpd_bp01Data[14];  /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S70>/MaxMotTrqVsSpd'
                                        */
  real_T convert2percent_Gain;         /* Expression: 100
                                        * Referenced by: '<S53>/convert2percent'
                                        */
  real_T Constant_Value_pc;            /* Expression: 1
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T rads_to_rpm_Gain_a;           /* Expression: 30/pi
                                        * Referenced by: '<S61>/rads_to_rpm'
                                        */
  real_T MaxEMTrqVsSpd_bp01Data_o[14]; /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S61>/MaxEMTrqVsSpd'
                                        */
  real_T Negative5_UpperSat;           /* Expression: inf
                                        * Referenced by: '<S70>/Negative 5'
                                        */
  real_T Negative5_LowerSat;           /* Expression: 0
                                        * Referenced by: '<S70>/Negative 5'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T Constant1_Value_f[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T Constant2_Value_e[36];        /* Expression: repmat(eye(3),1,1,4)
                                        * Referenced by: '<S74>/Constant2'
                                        */
  real_T FirstOrderHold_IniOut;        /* Expression: 0
                                        * Referenced by: '<S80>/First Order Hold'
                                        */
  real_T FirstOrderHold_ErrTol;        /* Expression: inf
                                        * Referenced by: '<S80>/First Order Hold'
                                        */
  real_T DeadZone_Start;               /* Expression: -inf
                                        * Referenced by: '<S105>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 1e-3
                                        * Referenced by: '<S105>/Dead Zone'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S106>/Integrator1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S517>/Integrator'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S518>/Integrator'
                                        */
  real_T Integrator1_IC_o;             /* Expression: 0
                                        * Referenced by: '<S374>/Integrator1'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S287>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -10*9.81*2000
                                        * Referenced by: '<S287>/Saturation'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S580>/Memory'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S588>/Memory'
                                        */
  real_T Constant1_Value_fm;           /* Expression: 0
                                        * Referenced by: '<S596>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S596>/Constant3'
                                        */
  real_T Integrator_IC_p3;             /* Expression: 0
                                        * Referenced by: '<S520>/Integrator'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: inf
                                        * Referenced by: '<S521>/Saturation'
                                        */
  real_T Saturation_LowerSat_ln;       /* Expression: 0
                                        * Referenced by: '<S521>/Saturation'
                                        */
  real_T Saturation_UpperSat_do;       /* Expression: inf
                                        * Referenced by: '<S516>/Saturation'
                                        */
  real_T Saturation_LowerSat_dz;       /* Expression: 0
                                        * Referenced by: '<S516>/Saturation'
                                        */
  real_T TorqueConversion1_Gain;       /* Expression: pi/4
                                        * Referenced by: '<S526>/Torque Conversion1'
                                        */
  real_T DisallowNegativeBrakeTorque_Upp;/* Expression: inf
                                          * Referenced by: '<S526>/Disallow Negative Brake Torque'
                                          */
  real_T DisallowNegativeBrakeTorque_Low;/* Expression: eps
                                          * Referenced by: '<S526>/Disallow Negative Brake Torque'
                                          */
  real_T Integrator1_IC_c;             /* Expression: 0
                                        * Referenced by: '<S375>/Integrator1'
                                        */
  real_T Constant3_Value_d[4];         /* Expression: ones(1,4).*0
                                        * Referenced by: '<S377>/Constant3'
                                        */
  real_T SteerRates_Value[4];          /* Expression: zeros(1,4)
                                        * Referenced by: '<S293>/SteerRates'
                                        */
  real_T Constant_Value_j[4];          /* Expression: zeros(1,4)
                                        * Referenced by: '<S293>/Constant'
                                        */
  real_T ones2_Value[4];               /* Expression: ones(1,numWheels)
                                        * Referenced by: '<S511>/ones2'
                                        */
  real_T u_Value[4];                   /* Expression: [zeros(1,numWheels)]
                                        * Referenced by: '<S511>/0'
                                        */
  real_T ones1_Value[36];              /* Expression: [ones(9,numWheels)]
                                        * Referenced by: '<S511>/ones1'
                                        */
  real_T u_Value_l[4];                 /* Expression: [zeros(1,numWheels)]+1
                                        * Referenced by: '<S511>/2'
                                        */
  real_T ones3_Value[20];              /* Expression: [ones(5,numWheels)]
                                        * Referenced by: '<S511>/ones3'
                                        */
  real_T u_Value_f[8];                 /* Expression: [zeros(2,numWheels)]+1
                                        * Referenced by: '<S511>/1'
                                        */
  real_T ones_Value[24];               /* Expression: [ones(6,numWheels)]
                                        * Referenced by: '<S511>/ones'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S521>/Constant1'
                                        */
  real_T vertType_Value;               /* Expression: vertType
                                        * Referenced by: '<S512>/vertType'
                                        */
  real_T Constant_Value_e[36];         /* Expression: repmat(eye(3),[1,1,4])
                                        * Referenced by: '<S288>/Constant'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S413>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S413>/phi theta psi'
                                          */
  real_T InertialFrameCGtoAxleOffset_Val[12];
                           /* Expression: [zeros(2,4);PlntVehCGHgtAxl*ones(1,4)]
                            * Referenced by: '<S295>/Inertial Frame CG to Axle Offset'
                            */
  real_T Constant8_Value;              /* Expression: pi/2
                                        * Referenced by: '<S174>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 2
                                        * Referenced by: '<S174>/Constant6'
                                        */
  real_T Constant8_Value_o;            /* Expression: pi/2
                                        * Referenced by: '<S172>/Constant8'
                                        */
  real_T Constant_Value_b;             /* Expression: 2*pi
                                        * Referenced by: '<S158>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX;    /* Expression: 0.0
                                        * Referenced by: '<S158>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT; /* Expression: 0.0
                                        * Referenced by: '<S158>/Integrator, Second-Order'
                                        */
  real_T Constant6_Value_i;            /* Expression: 2
                                        * Referenced by: '<S172>/Constant6'
                                        */
  real_T AckermanFlagConstant_Value;   /* Expression: 0
                                        * Referenced by: '<S158>/AckermanFlagConstant'
                                        */
  real_T Constant8_Value_a;            /* Expression: pi/2
                                        * Referenced by: '<S173>/Constant8'
                                        */
  real_T Constant6_Value_f;            /* Expression: 2
                                        * Referenced by: '<S173>/Constant6'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S158>/Switch'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S158>/Constant1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S158>/Gain5'
                                        */
  real_T Switch1_Threshold_h;          /* Expression: 0
                                        * Referenced by: '<S158>/Switch1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S158>/Switch4'
                                        */
  real_T LocFlagConstant_Value;        /* Expression: 1
                                        * Referenced by: '<S109>/LocFlagConstant'
                                        */
  real_T Switch_Threshold_ik;          /* Expression: 0
                                        * Referenced by: '<S111>/Switch'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S158>/Switch5'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 0
                                        * Referenced by: '<S111>/Switch1'
                                        */
  real_T FrontTrack_Value;             /* Expression: w(1)
                                        * Referenced by: '<S297>/Front Track'
                                        */
  real_T Integrator1_IC_m;             /* Expression: 0
                                        * Referenced by: '<S290>/Integrator1'
                                        */
  real_T Integrator1_IC_h;             /* Expression: 0
                                        * Referenced by: '<S291>/Integrator1'
                                        */
  real_T Gain_Gain_dp;                 /* Expression: -1
                                        * Referenced by: '<S289>/Gain'
                                        */
  real_T RearTrack_Value;              /* Expression: w(2)
                                        * Referenced by: '<S298>/Rear Track'
                                        */
  real_T SteerInputFlagConstant_Value; /* Expression: 0
                                        * Referenced by: '<S109>/SteerInputFlagConstant'
                                        */
  real_T Backlash_InitialOutput;       /* Expression: 0
                                        * Referenced by: '<S118>/Backlash'
                                        */
  real_T IntegratorSecondOrder_ICX_b;  /* Expression: 0.0
                                        * Referenced by: '<S140>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_g;/* Expression: 0.0
                                         * Referenced by: '<S140>/Integrator, Second-Order'
                                         */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S132>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 50
                                        * Referenced by: '<S132>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -50
                                        * Referenced by: '<S132>/Integrator'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S109>/Switch'
                                        */
  real_T Constant_Value_ka;            /* Expression: 1
                                        * Referenced by: '<S128>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_b4; /* Expression: 0.0
                                        * Referenced by: '<S139>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_k;/* Expression: 0.0
                                         * Referenced by: '<S139>/Integrator, Second-Order'
                                         */
  real_T Integrator1_IC_j;             /* Expression: 0
                                        * Referenced by: '<S127>/Integrator1'
                                        */
  real_T Constant1_Value_c1[2];        /* Expression: [0 0]
                                        * Referenced by: '<S120>/Constant1'
                                        */
  real_T TmpLatchAtTriggeredSubsystemInp;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_o;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S133>/Gain'
                                        */
  real_T Constant2_Value_o[2];         /* Expression: [0 0]
                                        * Referenced by: '<S120>/Constant2'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_g;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_l;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T Memory_InitialCondition_h;    /* Expression: 0
                                        * Referenced by: '<S133>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S133>/Memory1'
                                        */
  real_T Memory_InitialCondition_ag;   /* Expression: 0
                                        * Referenced by: '<S134>/Memory'
                                        */
  real_T Memory1_InitialCondition_c;   /* Expression: 0
                                        * Referenced by: '<S134>/Memory1'
                                        */
  real_T Constant8_Value_i;            /* Expression: pi/2
                                        * Referenced by: '<S261>/Constant8'
                                        */
  real_T Constant6_Value_c;            /* Expression: 2
                                        * Referenced by: '<S261>/Constant6'
                                        */
  real_T Constant8_Value_p;            /* Expression: pi/2
                                        * Referenced by: '<S259>/Constant8'
                                        */
  real_T Constant_Value_cq;            /* Expression: 2*pi
                                        * Referenced by: '<S245>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_i;  /* Expression: 0.0
                                        * Referenced by: '<S245>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_p;/* Expression: 0.0
                                         * Referenced by: '<S245>/Integrator, Second-Order'
                                         */
  real_T Constant6_Value_e;            /* Expression: 2
                                        * Referenced by: '<S259>/Constant6'
                                        */
  real_T AckermanFlagConstant_Value_m; /* Expression: 0
                                        * Referenced by: '<S245>/AckermanFlagConstant'
                                        */
  real_T Constant8_Value_j;            /* Expression: pi/2
                                        * Referenced by: '<S260>/Constant8'
                                        */
  real_T Constant6_Value_n;            /* Expression: 2
                                        * Referenced by: '<S260>/Constant6'
                                        */
  real_T Switch_Threshold_gp;          /* Expression: 0
                                        * Referenced by: '<S245>/Switch'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S245>/Constant1'
                                        */
  real_T Gain5_Gain_h;                 /* Expression: 0.01
                                        * Referenced by: '<S245>/Gain5'
                                        */
  real_T Switch1_Threshold_p4;         /* Expression: 0
                                        * Referenced by: '<S245>/Switch1'
                                        */
  real_T Switch4_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S245>/Switch4'
                                        */
  real_T LocFlagConstant_Value_e;      /* Expression: 0
                                        * Referenced by: '<S110>/LocFlagConstant'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S198>/Switch'
                                        */
  real_T Gain_Gain_pi;                 /* Expression: 0
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T Switch5_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S245>/Switch5'
                                        */
  real_T Switch1_Threshold_hf;         /* Expression: 0
                                        * Referenced by: '<S198>/Switch1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0
                                        * Referenced by: '<S108>/Gain1'
                                        */
  real_T SteerInputFlagConstant_Value_c;/* Expression: 0
                                         * Referenced by: '<S110>/SteerInputFlagConstant'
                                         */
  real_T Backlash_InitialOutput_d;     /* Expression: 0
                                        * Referenced by: '<S205>/Backlash'
                                        */
  real_T IntegratorSecondOrder_ICX_f;  /* Expression: 0.0
                                        * Referenced by: '<S227>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_d;/* Expression: 0.0
                                         * Referenced by: '<S227>/Integrator, Second-Order'
                                         */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S219>/Integrator'
                                        */
  real_T Integrator_UpperSat_p;        /* Expression: 50
                                        * Referenced by: '<S219>/Integrator'
                                        */
  real_T Integrator_LowerSat_l;        /* Expression: -50
                                        * Referenced by: '<S219>/Integrator'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S110>/Switch'
                                        */
  real_T Constant_Value_kw;            /* Expression: 1
                                        * Referenced by: '<S215>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_l;  /* Expression: 0.0
                                        * Referenced by: '<S226>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_f;/* Expression: 0.0
                                         * Referenced by: '<S226>/Integrator, Second-Order'
                                         */
  real_T Integrator1_IC_a;             /* Expression: 0
                                        * Referenced by: '<S214>/Integrator1'
                                        */
  real_T Constant1_Value_e[2];         /* Expression: [0 0]
                                        * Referenced by: '<S207>/Constant1'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_b;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_m;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S220>/Gain'
                                        */
  real_T Constant2_Value_p[2];         /* Expression: [0 0]
                                        * Referenced by: '<S207>/Constant2'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_e;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_h;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_p2;                 /* Expression: -1
                                        * Referenced by: '<S221>/Gain'
                                        */
  real_T Memory_InitialCondition_m;    /* Expression: 0
                                        * Referenced by: '<S220>/Memory'
                                        */
  real_T Memory1_InitialCondition_e;   /* Expression: 0
                                        * Referenced by: '<S220>/Memory1'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S221>/Memory'
                                        */
  real_T Memory1_InitialCondition_o;   /* Expression: 0
                                        * Referenced by: '<S221>/Memory1'
                                        */
  real_T Constant1_Value_o[3];         /* Expression: [0;0;0]
                                        * Referenced by: '<S390>/Constant1'
                                        */
  real_T Integrator1_IC_g;             /* Expression: 0
                                        * Referenced by: '<S393>/Integrator1'
                                        */
  real_T UnsprungMassessumVEHUnsprungMas;
               /* Expression: sum([PlntVehFrntUnsprgMass PlntVehRearUnsprgMass])
                * Referenced by: '<S391>/Unsprung Masses sum([VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassRearAxle//2 VEH.UnsprungMassRearAxle//2])'
                */
  real_T Vertical_Value;               /* Expression: 0
                                        * Referenced by: '<S391>/Vertical'
                                        */
  real_T u_Value_d;                    /* Expression: 0
                                        * Referenced by: '<S409>/0'
                                        */
  real_T u_Gain[3];                    /* Expression: [4.*ones(2,1); 0]
                                        * Referenced by: '<S434>/4'
                                        */
  real_T Constant4_Value[3];           /* Expression: [0; 0; 1]
                                        * Referenced by: '<S434>/Constant4'
                                        */
  real_T Crm_tableData[2];             /* Expression: [0 0]
                                        * Referenced by: '<S434>/Crm'
                                        */
  real_T Crm_bp01Data[2];              /* Expression: [-1 1]
                                        * Referenced by: '<S434>/Crm'
                                        */
  real_T Constant_Value_bj[6];         /* Expression: zeros(6 ,1)
                                        * Referenced by: '<S697>/Constant'
                                        */
  real_T Constant1_Value_p[9];         /* Expression: zeros(3,3)
                                        * Referenced by: '<S400>/Constant1'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S411>/Integrator'
                                        */
  real_T Constant_Value_lz[12];        /* Expression: zeros(12,1)
                                        * Referenced by: '<S392>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S517>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 1e-2
                                        * Referenced by: '<S517>/Saturation1'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: inf
                                        * Referenced by: '<S517>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: FxRelFreqLwrLim
                                        * Referenced by: '<S517>/Saturation'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: inf
                                        * Referenced by: '<S518>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_h;       /* Expression: 1e-2
                                        * Referenced by: '<S518>/Saturation1'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: inf
                                        * Referenced by: '<S518>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: FyRelFreqLwrLim
                                        * Referenced by: '<S518>/Saturation'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: inf
                                        * Referenced by: '<S520>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_i;       /* Expression: 1e-2
                                        * Referenced by: '<S520>/Saturation1'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: inf
                                        * Referenced by: '<S520>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: MyRelFreqLwrLim
                                        * Referenced by: '<S520>/Saturation'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S521>/Constant'
                                        */
  real_T Switch_Threshold_bz;          /* Expression: 0
                                        * Referenced by: '<S521>/Switch'
                                        */
  real_T Memory_InitialCondition_b;    /* Expression: 0
                                        * Referenced by: '<S602>/Memory'
                                        */
  real_T Constant1_Value_fd;           /* Expression: 1
                                        * Referenced by: '<S557>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: shaftSwitchMask
                                        * Referenced by: '<S557>/Constant'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 1
                                        * Referenced by: '<S557>/Switch'
                                        */
  real_T Integrator_UpperSat_i;        /* Expression: maxAbsSpd
                                        * Referenced by: '<S553>/Integrator'
                                        */
  real_T Integrator_LowerSat_h;        /* Expression: -maxAbsSpd
                                        * Referenced by: '<S553>/Integrator'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/2
                                        * Referenced by: '<S557>/Gain1'
                                        */
  real_T Constant_Value_l3;            /* Expression: 1
                                        * Referenced by: '<S567>/Constant'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S567>/Switch'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 20
                                        * Referenced by: '<S574>/Gain1'
                                        */
  real_T Constant1_Value_cj;           /* Expression: 1
                                        * Referenced by: '<S574>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4
                                        * Referenced by: '<S574>/Gain2'
                                        */
  real_T Gain_Gain_du;                 /* Expression: .5
                                        * Referenced by: '<S574>/Gain'
                                        */
  real_T Constant_Value_e0;            /* Expression: 1
                                        * Referenced by: '<S573>/Constant'
                                        */
  real_T Constant_Value_pp;            /* Expression: 1
                                        * Referenced by: '<S565>/Constant'
                                        */
  real_T Switch_Threshold_ez;          /* Expression: 0
                                        * Referenced by: '<S565>/Switch'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 20
                                        * Referenced by: '<S570>/Gain1'
                                        */
  real_T Constant1_Value_f2;           /* Expression: 1
                                        * Referenced by: '<S570>/Constant1'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 4
                                        * Referenced by: '<S570>/Gain2'
                                        */
  real_T Gain_Gain_pl;                 /* Expression: .5
                                        * Referenced by: '<S570>/Gain'
                                        */
  real_T Constant_Value_po;            /* Expression: 1
                                        * Referenced by: '<S569>/Constant'
                                        */
  real_T Constant_Value_p1;            /* Expression: 1
                                        * Referenced by: '<S566>/Constant'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S566>/Switch'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 20
                                        * Referenced by: '<S572>/Gain1'
                                        */
  real_T Constant1_Value_oo;           /* Expression: 1
                                        * Referenced by: '<S572>/Constant1'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 4
                                        * Referenced by: '<S572>/Gain2'
                                        */
  real_T Gain_Gain_fo;                 /* Expression: .5
                                        * Referenced by: '<S572>/Gain'
                                        */
  real_T Constant_Value_nn;            /* Expression: 1
                                        * Referenced by: '<S571>/Constant'
                                        */
  real_T Constant_Value_pk;            /* Expression: shaftSwitchMask
                                        * Referenced by: '<S560>/Constant'
                                        */
  real_T Constant6_Value_d;            /* Expression: 1
                                        * Referenced by: '<S560>/Constant6'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 1
                                        * Referenced by: '<S560>/Switch1'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<S580>/Reset'
                                        */
  real_T Reset_Value_e;                /* Expression: 1
                                        * Referenced by: '<S588>/Reset'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S600>/Constant1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S600>/Constant2'
                                        */
  real_T Constant_Value_jt;            /* Expression: 1
                                        * Referenced by: '<S621>/Constant'
                                        */
  real_T Constant1_Value_oe;           /* Expression: 0
                                        * Referenced by: '<S621>/Constant1'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S621>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S621>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S621>/Constant12'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant3'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S621>/Constant5'
                                        */
  real_T Constant6_Value_j;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S621>/Constant7'
                                        */
  real_T Constant8_Value_k;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S621>/Constant9'
                                        */
  real_T Reset_Value_d;                /* Expression: 1
                                        * Referenced by: '<S602>/Reset'
                                        */
  real_T MotorCouplingDynamics_A; /* Computed Parameter: MotorCouplingDynamics_A
                                   * Referenced by: '<S658>/Motor Coupling Dynamics'
                                   */
  real_T MotorCouplingDynamics_C; /* Computed Parameter: MotorCouplingDynamics_C
                                   * Referenced by: '<S658>/Motor Coupling Dynamics'
                                   */
  real_T MaxTorqueLimit_tableData[27]; /* Expression: T_t_extended
                                        * Referenced by: '<S666>/Max Torque Limit'
                                        */
  real_T MaxTorqueLimit_bp01Data[27];  /* Expression: w_t_extended
                                        * Referenced by: '<S666>/Max Torque Limit'
                                        */
  real_T Integrator_IC_jd;             /* Expression: 0
                                        * Referenced by: '<S666>/Integrator'
                                        */
  real_T Interpolatedzerocrossing_tableD[2];/* Expression: [-1 1]
                                             * Referenced by: '<S666>/Interpolated zero-crossing'
                                             */
  real_T Interpolatedzerocrossing_bp01Da[2];/* Expression: [-1 1]
                                             * Referenced by: '<S666>/Interpolated zero-crossing'
                                             */
  real_T uDLookupTable_tableData[567]; /* Expression: x_losses_mat
                                        * Referenced by: '<S665>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[27];   /* Expression: x_w_eff_vec
                                        * Referenced by: '<S665>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp02Data[21];   /* Expression: x_T_eff_vec
                                        * Referenced by: '<S665>/2-D Lookup Table'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: Inf
                                        * Referenced by: '<S663>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: 0.0001
                                        * Referenced by: '<S663>/Saturation'
                                        */
  real_T Constant1_Value_d;            /* Expression: 100
                                        * Referenced by: '<S646>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 100
                                        * Referenced by: '<S646>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S646>/Switch'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S651>/Constant'
                                        */
  real_T IntegratorLimited_LowerSat;   /* Expression: 0
                                        * Referenced by: '<S633>/Integrator Limited'
                                        */
  real_T SOCRatioto_Gain;              /* Expression: 100
                                        * Referenced by: '<S626>/SOC Ratio to %'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S628>/Constant1'
                                        */
  real_T Constant1_Value_eg;           /* Expression: 273.15
                                        * Referenced by: '<S640>/Constant1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S628>/Gain2'
                                        */
  real_T Gain1_Gain_b[96];             /* Expression: ones(PlntBattNumCellSer,1)
                                        * Referenced by: '<S628>/Gain1'
                                        */
  real_T Switch_Threshold_ae;          /* Expression: 0
                                        * Referenced by: '<S644>/Switch'
                                        */
  real_T Constant_Value_kk;            /* Expression: 0
                                        * Referenced by: '<S622>/Constant'
                                        */
  real_T Constant1_Value_eb;           /* Expression: 0
                                        * Referenced by: '<S622>/Constant1'
                                        */
  real_T Constant2_Value_p5;           /* Expression: 0
                                        * Referenced by: '<S622>/Constant2'
                                        */
  real_T Afr_Value;                    /* Expression: 0
                                        * Referenced by: '<S671>/Afr'
                                        */
  real_T Bsfc_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Bsfc'
                                        */
  real_T ClsdLpFuelMult_Value;         /* Expression: 1
                                        * Referenced by: '<S671>/ClsdLpFuelMult'
                                        */
  real_T CrkAng_Value;                 /* Expression: 0
                                        * Referenced by: '<S671>/CrkAng'
                                        */
  real_T CylPrs_Value;                 /* Expression: 0
                                        * Referenced by: '<S671>/CylPrs'
                                        */
  real_T EgrVlvAreaPct_Value;          /* Expression: 0
                                        * Referenced by: '<S671>/EgrVlvAreaPct'
                                        */
  real_T EngSpd_Value;                 /* Expression: 0
                                        * Referenced by: '<S671>/EngSpd'
                                        */
  real_T EngTrq_Value;                 /* Expression: 0
                                        * Referenced by: '<S671>/EngTrq'
                                        */
  real_T EngTrqCrk_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/EngTrqCrk'
                                        */
  real_T ExhCamPhase_Value;            /* Expression: 0
                                        * Referenced by: '<S671>/ExhCamPhase'
                                        */
  real_T ExhManGasTemp_Value;          /* Expression: 0
                                        * Referenced by: '<S671>/ExhManGasTemp'
                                        */
  real_T FuelMassFlw_Value;            /* Expression: 0
                                        * Referenced by: '<S671>/FuelMassFlw'
                                        */
  real_T FuelVolFlw_Value;             /* Expression: 0
                                        * Referenced by: '<S671>/FuelVolFlw'
                                        */
  real_T IntkCamPhase_Value;           /* Expression: 0
                                        * Referenced by: '<S671>/IntkCamPhase'
                                        */
  real_T IntkGasMassFlw_Value;         /* Expression: 0
                                        * Referenced by: '<S671>/IntkGasMassFlw'
                                        */
  real_T IntkSwirlVlvPos_Value;        /* Expression: 0
                                        * Referenced by: '<S671>/IntkSwirlVlvPos'
                                        */
  real_T IntkVlvLift_Value;            /* Expression: 0
                                        * Referenced by: '<S671>/IntkVlvLift'
                                        */
  real_T Map_Value;                    /* Expression: 0
                                        * Referenced by: '<S671>/Map'
                                        */
  real_T Map1_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map1'
                                        */
  real_T Map2_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map2'
                                        */
  real_T Map3_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map3'
                                        */
  real_T Map4_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map4'
                                        */
  real_T Map5_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map5'
                                        */
  real_T Map6_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Map6'
                                        */
  real_T Mat_Value;                    /* Expression: 0
                                        * Referenced by: '<S671>/Mat'
                                        */
  real_T Mat1_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Mat1'
                                        */
  real_T Mat2_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Mat2'
                                        */
  real_T Mat3_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/Mat3'
                                        */
  real_T NrmlzdAirChrg_Value;          /* Expression: 0
                                        * Referenced by: '<S671>/NrmlzdAirChrg'
                                        */
  real_T TPCO_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/TPCO'
                                        */
  real_T TPCO2_Value;                  /* Expression: 0
                                        * Referenced by: '<S671>/TPCO2'
                                        */
  real_T TPHC_Value;                   /* Expression: 0
                                        * Referenced by: '<S671>/TPHC'
                                        */
  real_T TPNOx_Value;                  /* Expression: 0
                                        * Referenced by: '<S671>/TPNOx'
                                        */
  real_T ThrPosPct_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/ThrPosPct'
                                        */
  real_T TurboRackPos_Value;           /* Expression: 0
                                        * Referenced by: '<S671>/TurboRackPos'
                                        */
  real_T TurboSpd_Value;               /* Expression: 0
                                        * Referenced by: '<S671>/TurboSpd'
                                        */
  real_T TurboSpd1_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/TurboSpd1'
                                        */
  real_T TurboSpd2_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/TurboSpd2'
                                        */
  real_T TurboSpd3_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/TurboSpd3'
                                        */
  real_T VarCompRatioPos_Value;        /* Expression: 0
                                        * Referenced by: '<S671>/VarCompRatioPos'
                                        */
  real_T VarIntkRunLen_Value;          /* Expression: 0
                                        * Referenced by: '<S671>/VarIntkRunLen'
                                        */
  real_T WgAreaPct_Value;              /* Expression: 0
                                        * Referenced by: '<S671>/WgAreaPct'
                                        */
  real_T DeadZone3_Start;              /* Expression: -.01
                                        * Referenced by: '<S96>/Dead Zone3'
                                        */
  real_T DeadZone3_End;                /* Expression: .01
                                        * Referenced by: '<S96>/Dead Zone3'
                                        */
  real_T Constant_Value_o[3];          /* Expression: [0,0,0]
                                        * Referenced by: '<S674>/Constant'
                                        */
  real_T Constant1_Value_kn[3];        /* Expression: [0,0,9.81]
                                        * Referenced by: '<S674>/Constant1'
                                        */
  real_T u_Value_g[3];                 /* Expression: zeros(3,1)
                                        * Referenced by: '<S679>/0'
                                        */
  real_T Constant_Value_i;             /* Expression: dtype_a
                                        * Referenced by: '<S679>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited_IC;/* Expression: 0
                                          * Referenced by: '<S684>/Integrator, Second-Order Limited'
                                          */
  real_T IntegratorSecondOrderLimited__i;/* Expression: 0
                                          * Referenced by: '<S684>/Integrator, Second-Order Limited'
                                          */
  real_T ZeroOrderHold2_Gain;          /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold2'
                                        */
  real_T ZeroOrderHold4_Gain;          /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold4'
                                        */
  real_T Gain_Gain_a[3];               /* Expression: [1 -1 1]
                                        * Referenced by: '<S677>/Gain'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S679>/Switch1'
                                        */
  real_T u_Value_g4[3];                /* Expression: zeros(3,1)
                                        * Referenced by: '<S693>/0'
                                        */
  real_T Constant_Value_bq;            /* Expression: dtype_g
                                        * Referenced by: '<S693>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited__e;/* Expression: 0
                                          * Referenced by: '<S696>/Integrator, Second-Order Limited'
                                          */
  real_T IntegratorSecondOrderLimited__a;/* Expression: 0
                                          * Referenced by: '<S696>/Integrator, Second-Order Limited'
                                          */
  real_T Switch1_Threshold_g;          /* Expression: 0.5
                                        * Referenced by: '<S693>/Switch1'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S697>/Constant15'
                                        */
  real_T Constant1_Value_nw;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant1'
                                        */
  real_T Constant10_Value_n;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant10'
                                        */
  real_T Constant11_Value_a;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant11'
                                        */
  real_T Constant12_Value_l;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S697>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S697>/Constant14'
                                        */
  real_T Constant2_Value_fs;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant2'
                                        */
  real_T Constant3_Value_i2;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant3'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0
                                        * Referenced by: '<S697>/Constant4'
                                        */
  real_T Constant5_Value_b;            /* Expression: 0
                                        * Referenced by: '<S697>/Constant5'
                                        */
  real_T Constant6_Value_j3;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant6'
                                        */
  real_T Constant7_Value_k;            /* Expression: 0
                                        * Referenced by: '<S697>/Constant7'
                                        */
  real_T Constant8_Value_pe;           /* Expression: 0
                                        * Referenced by: '<S697>/Constant8'
                                        */
  real_T Constant9_Value_p;            /* Expression: 0
                                        * Referenced by: '<S697>/Constant9'
                                        */
  real32_T Balancing_TargetDeltaV;     /* Expression: TargetDeltaV
                                        * Referenced by: '<S27>/Balancing'
                                        */
  real32_T State_Machine_CV_Gain;      /* Expression: CV_Gain
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_HighTempLimit;/* Expression: HighTempLimit
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_I_cc;         /* Expression: I_cc
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_LowTempLimit; /* Expression: LowTempLimit
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_MaxCellVoltThrsld;/* Expression: MaxCellVoltThrsld
                                            * Referenced by: '<S31>/State_Machine'
                                            */
  real32_T State_Machine_OverCellVoltageLi;/* Expression: OverCellVoltageLimit
                                            * Referenced by: '<S31>/State_Machine'
                                            */
  real32_T State_Machine_UnderCellVoltageL;/* Expression: UnderCellVoltageLimit
                                            * Referenced by: '<S31>/State_Machine'
                                            */
  real32_T State_Machine_currentFactor;/* Expression: currentFactor
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_noCurrent;    /* Expression: noCurrent
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_vRatio;       /* Expression: vRatio
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T State_Machine_voltThreshold;/* Expression: voltThreshold
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  real32_T Constant_Value_nt;          /* Computed Parameter: Constant_Value_nt
                                        * Referenced by: '<S26>/Constant'
                                        */
  real32_T UnitDelay_1_InitialCondition[96];
                                    /* Expression: InitialCondition.CellVoltages
                                     * Referenced by: '<S26>/Unit Delay'
                                     */
  real32_T MinCellVoltDchrgCurrentLim_tabl[3];
                            /* Expression: MinCellVoltDchrgCurrentLimTable.Table
                             * Referenced by: '<S35>/MinCellVoltDchrgCurrentLim'
                             */
  real32_T MinCellVoltDchrgCurrentLim_bp01[3];
                   /* Expression: MinCellVoltDchrgCurrentLimTable.Breakpoints(0)
                    * Referenced by: '<S35>/MinCellVoltDchrgCurrentLim'
                    */
  real32_T UnitDelay_4_InitialCondition[96];
                                /* Expression: InitialCondition.CellTemperatures
                                 * Referenced by: '<S26>/Unit Delay'
                                 */
  real32_T LowTempDchrgCurrentLim_tableDat[7];
                          /* Expression: single([0,  0.2, 0.3, 0.5, 0.75, 1, 1])
                           * Referenced by: '<S35>/LowTempDchrgCurrentLim'
                           */
  real32_T LowTempDchrgCurrentLim_bp01Data[7];
                         /* Expression: single([-10, -5,    0,   5, 10, 15, 20])
                          * Referenced by: '<S35>/LowTempDchrgCurrentLim'
                          */
  real32_T HighTempDchrgCurrentLim_tableDa[4];/* Expression: single([1, 0.5, 0.3, 0])
                                               * Referenced by: '<S35>/HighTempDchrgCurrentLim'
                                               */
  real32_T HighTempDchrgCurrentLim_bp01Dat[4];/* Expression: single([40, 45, 50, 60])
                                               * Referenced by: '<S35>/HighTempDchrgCurrentLim'
                                               */
  real32_T MaxDchrgCurrLim_Gain;       /* Expression: MaxDchrgCurrLim
                                        * Referenced by: '<S35>/MaxDchrgCurrLim'
                                        */
  real32_T MaxCellVoltChrgCurrentLim_table[4];/* Expression: single([1.0 0.8 0.3  0.3])
                                               * Referenced by: '<S34>/MaxCellVoltChrgCurrentLim'
                                               */
  real32_T MaxCellVoltChrgCurrentLim_bp01D[4];/* Expression: single([3.9 4.0 4.15 4.2])
                                               * Referenced by: '<S34>/MaxCellVoltChrgCurrentLim'
                                               */
  real32_T LowTempChrgCurrentLim_tableData[7];
                           /* Expression: single([0.1 0.2  0.3 0.3 0.5 1.0 1.0])
                            * Referenced by: '<S34>/LowTempChrgCurrentLim'
                            */
  real32_T LowTempChrgCurrentLim_bp01Data[7];
                           /* Expression: single([-15 -10 -5.0 0.0 5.0 10 15.0])
                            * Referenced by: '<S34>/LowTempChrgCurrentLim'
                            */
  real32_T HighTempChrgCurrentLim_tableDat[5];
                                      /* Expression: single([1.0 0.8 0.5 0.3 0])
                                       * Referenced by: '<S34>/HighTempChrgCurrentLim'
                                       */
  real32_T HighTempChrgCurrentLim_bp01Data[5];
                                      /* Expression: single([40  45  50  55 60])
                                       * Referenced by: '<S34>/HighTempChrgCurrentLim'
                                       */
  real32_T MaxChrgCurrLim_Gain;        /* Expression: MaxChrgCurrLim
                                        * Referenced by: '<S34>/MaxChrgCurrLim'
                                        */
  real32_T UnitDelay_2_InitialCondition;
                                     /* Expression: InitialCondition.PackVoltage
                                      * Referenced by: '<S26>/Unit Delay'
                                      */
  real32_T UnitDelay_5_InitialCondition;/* Expression: InitialCondition.VoutChgr
                                         * Referenced by: '<S26>/Unit Delay'
                                         */
  real32_T UnitDelay_6_InitialCondition;/* Expression: InitialCondition.VoutInvtr
                                         * Referenced by: '<S26>/Unit Delay'
                                         */
  real32_T UnitDelay_3_InitialCondition;
                                     /* Expression: InitialCondition.PackCurrent
                                      * Referenced by: '<S26>/Unit Delay'
                                      */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S38>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S38>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S38>/Discrete-Time Integrator'
                           */
  real32_T Gain_Gain_bp;               /* Expression: single(1/3600)
                                        * Referenced by: '<S38>/Gain'
                                        */
  uint32_T EffMap_maxIndex[2];         /* Computed Parameter: EffMap_maxIndex
                                        * Referenced by: '<S60>/Eff Map'
                                        */
  uint32_T TrqAssistTbl_maxIndex[2];/* Computed Parameter: TrqAssistTbl_maxIndex
                                     * Referenced by: '<S126>/TrqAssistTbl'
                                     */
  uint32_T TrqAssistTbl_maxIndex_f[2];
                                  /* Computed Parameter: TrqAssistTbl_maxIndex_f
                                   * Referenced by: '<S213>/TrqAssistTbl'
                                   */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S665>/2-D Lookup Table'
                                    */
  uint32_T R_maxIndex[2];              /* Computed Parameter: R_maxIndex
                                        * Referenced by: '<S635>/R'
                                        */
  int16_T Balancing_BalNotActWait;     /* Expression: BalNotActWait
                                        * Referenced by: '<S27>/Balancing'
                                        */
  int16_T Balancing_BalOffWait;        /* Expression: BalOffWait
                                        * Referenced by: '<S27>/Balancing'
                                        */
  int16_T Balancing_BalOnWait;         /* Expression: BalOnWait
                                        * Referenced by: '<S27>/Balancing'
                                        */
  uint16_T State_Machine_contactorTime;/* Expression: contactorTime
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  boolean_T Balancing_flgEnBalancing;  /* Expression: flgEnBalancing
                                        * Referenced by: '<S27>/Balancing'
                                        */
  uint8_T State_Machine_timeoutContactor;/* Expression: timeoutContactor
                                          * Referenced by: '<S31>/State_Machine'
                                          */
  uint8_T State_Machine_timeoutCurrent;/* Expression: timeoutCurrent
                                        * Referenced by: '<S31>/State_Machine'
                                        */
  P_CoreSubsys_ConfiguredVirt_l_T CoreSubsys_l;
                                    /* '<S523>/Clutch Partitioned Parameters' */
  P_CoreSubsys_ConfiguredVirt_a_T CoreSubsys_n;/* '<S435>/Unwrap' */
  P_CoreSubsys_ConfiguredVir_cd_T CoreSubsys_dk;/* '<S288>/Wheel to Body Transform' */
  P_CoreSubsys_ConfiguredVirt_c_T CoreSubsys_d;/* '<S376>/Wheel to Body Transform' */
  P_CoreSubsys_ConfiguredVirt_o_T CoreSubsys;
  /* '<S292>/For each track and axle combination calculate suspension forces and moments' */
  P_TriggeredSubsystem_Configur_T TriggeredSubsystem_l;/* '<S221>/Triggered Subsystem' */
  P_EnabledSubsystem1_Configure_T EnabledSubsystem1_j;/* '<S221>/Enabled Subsystem1' */
  P_EnabledSubsystem_Configured_T EnabledSubsystem_n;/* '<S221>/Enabled Subsystem' */
  P_TriggeredSubsystem_Configur_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  P_EnabledSubsystem1_Configure_T EnabledSubsystem1_i;/* '<S220>/Enabled Subsystem1' */
  P_EnabledSubsystem_Configured_T EnabledSubsystem_g;/* '<S220>/Enabled Subsystem' */
  P_TriggeredSubsystem_Configur_T TriggeredSubsystem_k;/* '<S134>/Triggered Subsystem' */
  P_EnabledSubsystem1_Configure_T EnabledSubsystem1_d;/* '<S134>/Enabled Subsystem1' */
  P_EnabledSubsystem_Configured_T EnabledSubsystem_h;/* '<S134>/Enabled Subsystem' */
  P_TriggeredSubsystem_Configur_T TriggeredSubsystem;/* '<S133>/Triggered Subsystem' */
  P_EnabledSubsystem1_Configure_T EnabledSubsystem1;/* '<S133>/Enabled Subsystem1' */
  P_EnabledSubsystem_Configured_T EnabledSubsystem;/* '<S133>/Enabled Subsystem' */
};

#endif                                 /* RTW_HEADER_AdasPlantModel_h_ */
