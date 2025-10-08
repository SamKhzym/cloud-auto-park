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
#include "AdasPlantModel0_types.h"
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

/* Block signals for system '<S132>/Enabled Subsystem' */
struct B_EnabledSubsystem_AdasPlantM_T {
  real_T y;                            /* '<S140>/MATLAB Function' */
};

/* Block states (default storage) for system '<S132>/Enabled Subsystem' */
struct DW_EnabledSubsystem_AdasPlant_T {
  boolean_T EnabledSubsystem_MODE;     /* '<S132>/Enabled Subsystem' */
};

/* Block signals for system '<S132>/Enabled Subsystem1' */
struct B_EnabledSubsystem1_AdasPlant_T {
  real_T y;                            /* '<S141>/MATLAB Function' */
};

/* Block states (default storage) for system '<S132>/Enabled Subsystem1' */
struct DW_EnabledSubsystem1_AdasPlan_T {
  boolean_T EnabledSubsystem1_MODE;    /* '<S132>/Enabled Subsystem1' */
};

/* Block signals for system '<S132>/Triggered Subsystem' */
struct B_TriggeredSubsystem_AdasPlan_T {
  real_T In;                           /* '<S142>/In' */
  real_T y;                            /* '<S142>/MATLAB Function1' */
  real_T y_a;                          /* '<S142>/MATLAB Function' */
};

/* Zero-crossing (trigger) state for system '<S132>/Triggered Subsystem' */
struct ZCE_TriggeredSubsystem_AdasPl_T {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S132>/Triggered Subsystem' */
};

/* Block signals for system '<S154>/MATLAB Function1' */
struct B_MATLABFunction1_AdasPlantMo_T {
  real_T y;                            /* '<S154>/MATLAB Function1' */
};

/* Block signals for system '<S291>/For each track and axle combination calculate suspension forces and moments' */
struct B_CoreSubsys_AdasPlantModel_h_T {
  real_T Sum2;                         /* '<S301>/Sum2' */
  real_T Selector5;                    /* '<S308>/Selector5' */
  real_T Selector2;                    /* '<S321>/Selector2' */
  real_T SumofElements;                /* '<S326>/Sum of Elements' */
  real_T Product;                      /* '<S302>/Product' */
  real_T SumofElements_m;              /* '<S352>/Sum of Elements' */
  real_T Selector5_o;                  /* '<S354>/Selector5' */
  real_T Selector10;                   /* '<S353>/Selector10' */
  real_T Selector2_m;                  /* '<S355>/Selector2' */
  real_T Selector8;                    /* '<S320>/Selector8' */
  real_T Selector4;                    /* '<S322>/Selector4' */
  real_T Selector5_a;                  /* '<S309>/Selector5' */
  real_T Selector4_g;                  /* '<S331>/Selector4' */
  real_T SumofElements_h;              /* '<S335>/Sum of Elements' */
  real_T Sign;                         /* '<S310>/Sign' */
  real_T Selector2_e;                  /* '<S372>/Selector2' */
  real_T Selector1;                    /* '<S372>/Selector1' */
  real_T Selector6;                    /* '<S371>/Selector6' */
  real_T Selector1_n;                  /* '<S371>/Selector1' */
  real_T Selector7;                    /* '<S344>/Selector7' */
  real_T Selector6_g;                  /* '<S339>/Selector6' */
  real_T Selector4_h;                  /* '<S340>/Selector4' */
  real_T SumofElements_l;              /* '<S366>/Sum of Elements' */
  real_T Sign1;                        /* '<S360>/Sign1' */
  real_T Sign_d;                       /* '<S307>/Sign' */
};

/* Block signals for system '<S375>/Wheel to Body Transform' */
struct B_CoreSubsys_AdasPlantModel_c_T {
  real_T VectorConcatenate[9];         /* '<S381>/Vector Concatenate' */
};

/* Block signals for system '<S287>/Wheel to Body Transform' */
struct B_CoreSubsys_AdasPlantMode_ca_T {
  real_T Transpose1[9];                /* '<S383>/Transpose1' */
  real_T VectorConcatenate[9];         /* '<S387>/Vector Concatenate' */
};

/* Block signals for system '<S434>/Unwrap' */
struct B_CoreSubsys_AdasPlantModel_f_T {
  real_T Memory1;                      /* '<S439>/Memory1' */
  real_T Sum;                          /* '<S441>/Sum' */
  boolean_T Compare;                   /* '<S440>/Compare' */
};

/* Block states (default storage) for system '<S434>/Unwrap' */
struct DW_CoreSubsys_AdasPlantMode_l_T {
  real_T UnitDelay_DSTATE;             /* '<S441>/Unit Delay' */
  real_T Memory1_PreviousInput;        /* '<S439>/Memory1' */
};

/* Zero-crossing (trigger) state for system '<S434>/Unwrap' */
struct ZCE_CoreSubsys_AdasPlantMod_c_T {
  ZCSigState FunctionCallSubsystem_Trig_ZCE;/* '<S439>/Function-Call Subsystem' */
};

/* Block signals for system '<S526>/Clutch' */
struct B_Clutch_AdasPlantModel0_T {
  real_T Tout;                         /* '<S526>/Clutch' */
  real_T Tfmaxs;                       /* '<S526>/Clutch' */
  real_T Tout_p;                       /* '<S526>/Clutch' */
  real_T Tfmaxs_p;                     /* '<S526>/Clutch' */
  real_T Omega;                        /* '<S526>/Clutch' */
  real_T Omegadot;                     /* '<S526>/Clutch' */
  real_T Myb;                          /* '<S526>/Clutch' */
  real_T OutputInertia;                /* '<S529>/Output Inertia' */
  boolean_T CombinatorialLogic;        /* '<S535>/Combinatorial  Logic' */
  boolean_T RelationalOperator;        /* '<S539>/Relational Operator' */
};

/* Block states (default storage) for system '<S526>/Clutch' */
struct DW_Clutch_AdasPlantModel0_T {
  real_T lastMajorTime;                /* '<S526>/Clutch' */
  boolean_T UnitDelay_DSTATE;          /* '<S535>/Unit Delay' */
  int8_T TmpIfAtSlippingInport3_ActiveSu;/* synthesized block */
  int8_T TmpIfAtLockedInport2_ActiveSubs;/* synthesized block */
  uint8_T is_active_c8_autolibshared;  /* '<S526>/Clutch' */
  uint8_T is_c8_autolibshared;         /* '<S526>/Clutch' */
  boolean_T Slipping_entered;          /* '<S526>/Clutch' */
  boolean_T Locked_entered;            /* '<S526>/Clutch' */
};

/* Continuous states for system '<S526>/Clutch' */
struct X_Clutch_AdasPlantModel0_T {
  real_T omegaWheel;                   /* '<S529>/omega wheel' */
};

/* State derivatives for system '<S526>/Clutch' */
struct XDot_Clutch_AdasPlantModel0_T {
  real_T omegaWheel;                   /* '<S529>/omega wheel' */
};

/* State Disabled for system '<S526>/Clutch' */
struct XDis_Clutch_AdasPlantModel0_T {
  boolean_T omegaWheel;                /* '<S529>/omega wheel' */
};

/* Block signals for system '<S522>/Clutch Partitioned Parameters' */
struct B_CoreSubsys_AdasPlantModel_e_T {
  B_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* Block states (default storage) for system '<S522>/Clutch Partitioned Parameters' */
struct DW_CoreSubsys_AdasPlantMod_lq_T {
  DW_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* Continuous states for system '<S522>/Clutch Partitioned Parameters' */
struct X_CoreSubsys_AdasPlantModel_c_T {
  X_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* State derivatives for system '<S522>/Clutch Partitioned Parameters' */
struct XDot_CoreSubsys_AdasPlantMo_a_T {
  XDot_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* State Disabled for system '<S522>/Clutch Partitioned Parameters' */
struct XDis_CoreSubsys_AdasPlantMo_i_T {
  XDis_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* Block signals for system '<Root>/AdasPlantModel' */
struct B_AdasPlantModel_AdasPlantMod_T {
  real_T Product;                      /* '<S630>/Product' */
  real_T Gain1;                        /* '<S630>/Gain1' */
  real_T DataTypeConversion1;          /* '<S21>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S21>/Data Type Conversion' */
  real_T DataTypeConversion2;          /* '<S21>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<S21>/Data Type Conversion3' */
  real_T DeadZone1;                    /* '<S671>/Dead Zone1' */
  real_T DeadZone2;                    /* '<S95>/Dead Zone2' */
  real_T Spd;                          /* '<S609>/Integrator' */
  real_T GearCmd;                      /* '<S3>/Switch' */
  real_T UnitConversion[3];            /* '<S416>/Unit Conversion' */
  real_T Switch2;                      /* '<S66>/Switch2' */
  real_T IgnSwtch;                     /* '<S3>/Constant' */
  real_T DCM[36];                      /* '<S73>/Constant2' */
  real_T Wind[3];                      /* '<S4>/Vector Concatenate' */
  real_T VectorConcatenate[4];         /* '<S75>/Vector Concatenate' */
  real_T VectorConcatenate1[4];        /* '<S75>/Vector Concatenate1' */
  real_T EMTrqCmd;                     /* '<S79>/First Order Hold' */
  real_T DeadZone[4];                  /* '<S104>/Dead Zone' */
  real_T Gain4[4];                     /* '<S104>/Gain4' */
  real_T Divide[4];                    /* '<S105>/Divide' */
  real_T Integrator[4];                /* '<S516>/Integrator' */
  real_T Integrator_i[4];              /* '<S517>/Integrator' */
  real_T Saturation[4];                /* '<S286>/Saturation' */
  real_T MathFunction[12];             /* '<S287>/Math Function' */
  real_T Memory;                       /* '<S579>/Memory' */
  real_T domega_o;                     /* '<S578>/domega_o' */
  real_T Memory_a;                     /* '<S587>/Memory' */
  real_T domega_o_o;                   /* '<S586>/domega_o' */
  real_T VectorConcatenate1_h[4];      /* '<S540>/Vector Concatenate1' */
  real_T Integrator_e[4];              /* '<S519>/Integrator' */
  real_T IntegratorSecondOrder_o1[4];  /* '<S520>/Integrator, Second-Order' */
  real_T IntegratorSecondOrder_o2[4];  /* '<S520>/Integrator, Second-Order' */
  real_T Add1[4];                      /* '<S515>/Add1' */
  real_T TorqueConversion1[4];         /* '<S525>/Torque Conversion1' */
  real_T TorqueConversion[4];          /* '<S525>/Torque Conversion' */
  real_T Ratioofstatictokinetic[4];    /* '<S523>/Ratio of static to kinetic' */
  real_T Ratioofstatictokinetic1[4];  /* '<S523>/Ratio of static to kinetic1' */
  real_T pqr[3];                       /* '<S406>/p,q,r ' */
  real_T Selector1[3];                 /* '<S450>/Selector1' */
  real_T Add1_h[3];                    /* '<S456>/Add1' */
  real_T Selector1_h[3];               /* '<S451>/Selector1' */
  real_T Add1_d[3];                    /* '<S464>/Add1' */
  real_T Selector1_p[3];               /* '<S454>/Selector1' */
  real_T Add1_b[3];                    /* '<S492>/Add1' */
  real_T Selector1_f[3];               /* '<S455>/Selector1' */
  real_T Add1_j[3];                    /* '<S500>/Add1' */
  real_T xdot[4];                      /* '<S285>/Selector1' */
  real_T ydot[4];                      /* '<S285>/Selector2' */
  real_T MatrixConcatenate[12];        /* '<S286>/Matrix Concatenate' */
  real_T VectorConcatenate3[12];       /* '<S376>/Vector Concatenate3' */
  real_T Reshape1[4];                  /* '<S375>/Reshape1' */
  real_T Reshape2[4];                  /* '<S375>/Reshape2' */
  real_T MatrixConcatenate1[12];       /* '<S292>/Matrix Concatenate1' */
  real_T AngVel[12];                   /* '<S292>/Add' */
  real_T UnaryMinus[4];                /* '<S375>/Unary Minus' */
  real_T Reshape[4];                   /* '<S508>/Reshape' */
  real_T FrontPressure[2];             /* '<S508>/Front Pressure' */
  real_T RearPressure[2];              /* '<S508>/Rear Pressure' */
  real_T VectorConcatenate_e[108];     /* '<S510>/Vector Concatenate' */
  real_T MathFunction1[12];            /* '<S287>/Math Function1' */
  real_T z[4];                         /* '<S382>/Unary Minus1' */
  real_T xeyeze[3];                    /* '<S406>/xe,ye,ze' */
  real_T phithetapsi[3];               /* '<S412>/phi theta psi' */
  real_T Add[3];                       /* '<S456>/Add' */
  real_T Add_n[3];                     /* '<S464>/Add' */
  real_T Add_b[3];                     /* '<S492>/Add' */
  real_T Add_a[3];                     /* '<S500>/Add' */
  real_T Reshape9to3x3columnmajor[9];
                                /* '<S422>/Reshape (9) to [3x3] column-major' */
  real_T Product_d[3];                 /* '<S419>/Product' */
  real_T UnitConversion_i[3];          /* '<S417>/Unit Conversion' */
  real_T V_wb[3];                      /* '<S456>/Add4' */
  real_T V_wb_d[3];                    /* '<S464>/Add4' */
  real_T V_wb_h[3];                    /* '<S492>/Add4' */
  real_T V_wb_j[3];                    /* '<S500>/Add4' */
  real_T Add3;                         /* '<S173>/Add3' */
  real_T Divide_l;                     /* '<S157>/Divide' */
  real_T UnaryMinus1;                  /* '<S168>/Unary Minus1' */
  real_T MathFunction1_e;              /* '<S171>/Math Function1' */
  real_T MathFunction2;                /* '<S171>/Math Function2' */
  real_T MathFunction3;                /* '<S171>/Math Function3' */
  real_T MathFunction1_m;              /* '<S172>/Math Function1' */
  real_T MathFunction2_n;              /* '<S172>/Math Function2' */
  real_T MathFunction3_h;              /* '<S172>/Math Function3' */
  real_T Gain5;                        /* '<S157>/Gain5' */
  real_T Add1_o;                       /* '<S157>/Add1' */
  real_T Switch;                       /* '<S110>/Switch' */
  real_T Switch1;                      /* '<S110>/Switch1' */
  real_T Reshape5[12];                 /* '<S291>/Reshape5' */
  real_T Backlash;                     /* '<S117>/Backlash' */
  real_T Gain2;                        /* '<S131>/Gain2' */
  real_T UnaryMinus_n;                 /* '<S127>/Unary Minus' */
  real_T Divide_b;                     /* '<S126>/Divide' */
  real_T Subtract2;                    /* '<S131>/Subtract2' */
  real_T Add_p;                        /* '<S132>/Add' */
  real_T Add1_a;                       /* '<S132>/Add1' */
  real_T Sign;                         /* '<S132>/Sign' */
  real_T HiddenBuf_InsertedFor_EnabledSu;/* '<S132>/Sign' */
  real_T Gain;                         /* '<S132>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_n;/* '<S132>/Gain' */
  real_T Add_c;                        /* '<S133>/Add' */
  real_T Add1_h5;                      /* '<S133>/Add1' */
  real_T Sign_e;                       /* '<S133>/Sign' */
  real_T HiddenBuf_InsertedFor_Enabled_l;/* '<S133>/Sign' */
  real_T Gain_k;                       /* '<S133>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_b;/* '<S133>/Gain' */
  real_T Memory_d;                     /* '<S132>/Memory' */
  real_T Memory1;                      /* '<S132>/Memory1' */
  real_T Memory_e;                     /* '<S133>/Memory' */
  real_T Memory1_d;                    /* '<S133>/Memory1' */
  real_T Gain3;                        /* '<S157>/Gain3' */
  real_T Gain_e;                       /* '<S138>/Gain' */
  real_T Gain_m;                       /* '<S139>/Gain' */
  real_T Add3_c;                       /* '<S260>/Add3' */
  real_T Divide_n;                     /* '<S244>/Divide' */
  real_T UnaryMinus1_f;                /* '<S255>/Unary Minus1' */
  real_T MathFunction1_my;             /* '<S258>/Math Function1' */
  real_T MathFunction2_d;              /* '<S258>/Math Function2' */
  real_T MathFunction3_g;              /* '<S258>/Math Function3' */
  real_T MathFunction1_n;              /* '<S259>/Math Function1' */
  real_T MathFunction2_ds;             /* '<S259>/Math Function2' */
  real_T MathFunction3_n;              /* '<S259>/Math Function3' */
  real_T Gain5_n;                      /* '<S244>/Gain5' */
  real_T Add1_i;                       /* '<S244>/Add1' */
  real_T RL;                           /* '<S107>/Gain' */
  real_T RR;                           /* '<S107>/Gain1' */
  real_T Backlash_i;                   /* '<S204>/Backlash' */
  real_T Saturation_f;                 /* '<S204>/Saturation' */
  real_T Gain2_b;                      /* '<S218>/Gain2' */
  real_T UnaryMinus_f;                 /* '<S214>/Unary Minus' */
  real_T Divide_h;                     /* '<S213>/Divide' */
  real_T Subtract2_p;                  /* '<S218>/Subtract2' */
  real_T Add_c0;                       /* '<S219>/Add' */
  real_T Add1_c;                       /* '<S219>/Add1' */
  real_T Sign_p;                       /* '<S219>/Sign' */
  real_T HiddenBuf_InsertedFor_Enable_b1;/* '<S219>/Sign' */
  real_T Gain_p;                       /* '<S219>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_i;/* '<S219>/Gain' */
  real_T Add_nb;                       /* '<S220>/Add' */
  real_T Add1_jo;                      /* '<S220>/Add1' */
  real_T Sign_c;                       /* '<S220>/Sign' */
  real_T HiddenBuf_InsertedFor_Enabled_a;/* '<S220>/Sign' */
  real_T Gain_g;                       /* '<S220>/Gain' */
  real_T HiddenBuf_InsertedFor_Enabled_d;/* '<S220>/Gain' */
  real_T Memory_e0;                    /* '<S219>/Memory' */
  real_T Memory1_c;                    /* '<S219>/Memory1' */
  real_T Memory_h;                     /* '<S220>/Memory' */
  real_T Memory1_h;                    /* '<S220>/Memory1' */
  real_T Gain3_o;                      /* '<S244>/Gain3' */
  real_T Gain_o;                       /* '<S225>/Gain' */
  real_T Gain_o5;                      /* '<S226>/Gain' */
  real_T Divide_c[4];                  /* '<S289>/Divide' */
  real_T Divide_p[4];                  /* '<S290>/Divide' */
  real_T MatrixConcatenate_f[12];      /* '<S291>/Matrix Concatenate' */
  real_T MatrixConcatenate1_p[12];     /* '<S291>/Matrix Concatenate1' */
  real_T Reshape14[12];                /* '<S291>/Reshape14' */
  real_T Divide_f[4];                  /* '<S373>/Divide' */
  real_T Divide_pz[12];                /* '<S374>/Divide' */
  real_T Reshape5_d[4];                /* '<S375>/Reshape5' */
  real_T dz[4];                        /* '<S382>/Subtract' */
  real_T Constant1[3];                 /* '<S389>/Constant1' */
  real_T VectorConcatenate_b[3];       /* '<S390>/Vector Concatenate' */
  real_T UnaryMinus_j[3];              /* '<S390>/Unary Minus' */
  real_T Fg_I[3];                      /* '<S408>/Product' */
  real_T Fg_B[3];                      /* '<S408>/Inertial to Body' */
  real_T VectorConcatenate_bb[6];      /* '<S433>/Vector Concatenate' */
  real_T Subtract[3];                  /* '<S452>/Subtract' */
  real_T Add_o[3];                     /* '<S472>/Add' */
  real_T Hitch[6];                     /* '<S696>/Constant' */
  real_T Sum[3];                       /* '<S399>/Sum' */
  real_T SumofElements[3];             /* '<S428>/Sum of Elements' */
  real_T Sum_l[3];                     /* '<S406>/Sum' */
  real_T UnitConversion1[3];           /* '<S410>/Unit Conversion1' */
  real_T Divide_e[2];                  /* '<S392>/Divide' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S412>/phidot thetadot psidot' */
  real_T Selector[9];                  /* '<S413>/Selector' */
  real_T Selector1_j[9];               /* '<S413>/Selector1' */
  real_T Mx;                           /* '<S447>/Mx' */
  real_T My;                           /* '<S447>/My' */
  real_T Mz;                           /* '<S447>/Mz' */
  real_T Add_np[3];                    /* '<S399>/Add' */
  real_T Selector2[9];                 /* '<S413>/Selector2' */
  real_T Product2[3];                  /* '<S413>/Product2' */
  real_T UnaryMinus_k[3];              /* '<S399>/Unary Minus' */
  real_T SumofElements_o;              /* '<S409>/Sum of Elements' */
  real_T SumofElements1;               /* '<S409>/Sum of Elements1' */
  real_T Beta;                         /* '<S435>/Trigonometric Function' */
  real_T UnitConversion2[3];           /* '<S410>/Unit Conversion2' */
  real_T UnitConversion3[3];           /* '<S410>/Unit Conversion3' */
  real_T UnaryMinus1_o[3];             /* '<S399>/Unary Minus1' */
  real_T Constant[12];                 /* '<S391>/Constant' */
  real_T Add1_f[3];                    /* '<S472>/Add1' */
  real_T V_wb_k[3];                    /* '<S472>/Add4' */
  real_T Beta_b;                       /* '<S473>/Trigonometric Function' */
  real_T VectorConcatenate_o[3];       /* '<S453>/Vector Concatenate' */
  real_T Add_k[3];                     /* '<S484>/Add' */
  real_T Add1_k[3];                    /* '<S484>/Add1' */
  real_T V_wb_jq[3];                   /* '<S484>/Add4' */
  real_T VectorConcatenate2[12];       /* '<S404>/Vector Concatenate2' */
  real_T SignalCopy[4];                /* '<S512>/Signal Copy' */
  real_T Product1[4];                  /* '<S516>/Product1' */
  real_T Product1_p[4];                /* '<S517>/Product1' */
  real_T Product1_l[4];                /* '<S519>/Product1' */
  real_T Gain1_d[4];                   /* '<S520>/Gain1' */
  real_T Memory_l;                     /* '<S601>/Memory' */
  real_T domega_o_b;                   /* '<S600>/domega_o' */
  real_T diffDir;                      /* '<S556>/Switch' */
  real_T VectorConcatenate_c[2];       /* '<S552>/Vector Concatenate' */
  real_T SumofElements_m;              /* '<S556>/Sum of Elements' */
  real_T diffDir_h;                    /* '<S559>/Switch1' */
  real_T Subtract_p;                   /* '<S578>/Subtract' */
  real_T Product_f;                    /* '<S579>/Product' */
  real_T Subtract_f;                   /* '<S586>/Subtract' */
  real_T Product_e;                    /* '<S587>/Product' */
  real_T Cltch1State;                  /* '<S599>/Constant1' */
  real_T Cltch2State;                  /* '<S599>/Constant2' */
  real_T TransGear;                    /* '<S620>/Constant' */
  real_T EngTrq;                       /* '<S620>/Constant1' */
  real_T PwrEffLoss;                   /* '<S620>/Constant10' */
  real_T PwrDampLoss;                  /* '<S620>/Constant11' */
  real_T PwrStoredTrans;               /* '<S620>/Constant12' */
  real_T EngSpd;                       /* '<S620>/Constant2' */
  real_T DiffTrq;                      /* '<S620>/Constant3' */
  real_T DiffSpd;                      /* '<S620>/Constant4' */
  real_T TransSpdRatio;                /* '<S620>/Constant5' */
  real_T TransEta;                     /* '<S620>/Constant6' */
  real_T TransGearCmd;                 /* '<S620>/Constant7' */
  real_T PwrEng;                       /* '<S620>/Constant8' */
  real_T PwrDiffrntl;                  /* '<S620>/Constant9' */
  real_T Subtract_d;                   /* '<S600>/Subtract' */
  real_T Product_p;                    /* '<S601>/Product' */
  real_T EMTrq;                        /* '<S657>/Motor Coupling Dynamics' */
  real_T Switch_k;                     /* '<S611>/Switch' */
  real_T Divide_fp;                    /* '<S609>/Divide' */
  real_T Gain2_c;                      /* '<S643>/Gain2' */
  real_T Divide2;                      /* '<S665>/Divide2' */
  real_T Divide_o;                     /* '<S645>/Divide' */
  real_T Divide1;                      /* '<S645>/Divide1' */
  real_T UnaryMinus_g;                 /* '<S650>/Unary Minus' */
  real_T Divide_pf;                    /* '<S644>/Divide' */
  real_T Gain1_g;                      /* '<S632>/Gain1' */
  real_T Switch_d;                     /* '<S632>/Switch' */
  real_T Sum_f;                        /* '<S630>/Sum' */
  real_T SOCRatioto;                   /* '<S625>/SOC Ratio to %' */
  real_T Switch_m;                     /* '<S643>/Switch' */
  real_T Sum_m;                        /* '<S643>/Sum' */
  real_T Sum_e;                        /* '<S665>/Sum' */
  real_T EMPwrElec;                    /* '<S657>/Product' */
  real_T BattPwr;                      /* '<S621>/Product2' */
  real_T FuelCellVolt;                 /* '<S621>/Constant' */
  real_T FuelCellCurr;                 /* '<S621>/Constant1' */
  real_T H2Flw;                        /* '<S621>/Constant2' */
  real_T Bsfc;                         /* '<S670>/Bsfc' */
  real_T CrkAng;                       /* '<S670>/CrkAng' */
  real_T CylPrs;                       /* '<S670>/CylPrs' */
  real_T EgrVlvAreaPct;                /* '<S670>/EgrVlvAreaPct' */
  real_T EngSpd_b;                     /* '<S670>/EngSpd' */
  real_T EngTrq_c;                     /* '<S670>/EngTrq' */
  real_T EngTrqCrk;                    /* '<S670>/EngTrqCrk' */
  real_T ExhCamPhase;                  /* '<S670>/ExhCamPhase' */
  real_T ExhManGasTemp;                /* '<S670>/ExhManGasTemp' */
  real_T IntkCamPhase;                 /* '<S670>/IntkCamPhase' */
  real_T IntkGasMassFlw;               /* '<S670>/IntkGasMassFlw' */
  real_T IntkSwirlVlvPos;              /* '<S670>/IntkSwirlVlvPos' */
  real_T IntkVlvLift;                  /* '<S670>/IntkVlvLift' */
  real_T Map;                          /* '<S670>/Map' */
  real_T Map1;                         /* '<S670>/Map1' */
  real_T Map2;                         /* '<S670>/Map2' */
  real_T Map3;                         /* '<S670>/Map3' */
  real_T Map4;                         /* '<S670>/Map4' */
  real_T Map5;                         /* '<S670>/Map5' */
  real_T Map6;                         /* '<S670>/Map6' */
  real_T Mat;                          /* '<S670>/Mat' */
  real_T Mat1;                         /* '<S670>/Mat1' */
  real_T Mat2;                         /* '<S670>/Mat2' */
  real_T Mat3;                         /* '<S670>/Mat3' */
  real_T NrmlzdAirChrg;                /* '<S670>/NrmlzdAirChrg' */
  real_T Product_a;                    /* '<S670>/Product' */
  real_T Product1_a;                   /* '<S670>/Product1' */
  real_T Product2_e;                   /* '<S670>/Product2' */
  real_T TPCO;                         /* '<S670>/TPCO' */
  real_T TPCO2;                        /* '<S670>/TPCO2' */
  real_T TPHC;                         /* '<S670>/TPHC' */
  real_T TPNOx;                        /* '<S670>/TPNOx' */
  real_T ThrPosPct;                    /* '<S670>/ThrPosPct' */
  real_T TurboRackPos;                 /* '<S670>/TurboRackPos' */
  real_T TurboSpd;                     /* '<S670>/TurboSpd' */
  real_T TurboSpd1;                    /* '<S670>/TurboSpd1' */
  real_T TurboSpd2;                    /* '<S670>/TurboSpd2' */
  real_T TurboSpd3;                    /* '<S670>/TurboSpd3' */
  real_T VarCompRatioPos;              /* '<S670>/VarCompRatioPos' */
  real_T VarIntkRunLen;                /* '<S670>/VarIntkRunLen' */
  real_T WgAreaPct;                    /* '<S670>/WgAreaPct' */
  real_T DeadZone3;                    /* '<S95>/Dead Zone3' */
  real_T ZeroOrderHold2[3];            /* '<S676>/Zero-Order Hold2' */
  real_T Gain_d[3];                    /* '<S676>/Gain' */
  real_T Sum2[3];                      /* '<S683>/Sum2' */
  real_T Sum2_k[3];                    /* '<S695>/Sum2' */
  real_T Wheels;                       /* '<S696>/Constant15' */
  real_T X;                            /* '<S696>/Constant1' */
  real_T Y;                            /* '<S696>/Constant10' */
  real_T X_c;                          /* '<S696>/Constant11' */
  real_T Y_a;                          /* '<S696>/Constant12' */
  real_T X_j;                          /* '<S696>/Constant13' */
  real_T Y_h;                          /* '<S696>/Constant14' */
  real_T Y_j;                          /* '<S696>/Constant2' */
  real_T X_o;                          /* '<S696>/Constant3' */
  real_T Y_l;                          /* '<S696>/Constant4' */
  real_T X_f;                          /* '<S696>/Constant5' */
  real_T Y_e;                          /* '<S696>/Constant6' */
  real_T X_k;                          /* '<S696>/Constant7' */
  real_T Y_d;                          /* '<S696>/Constant8' */
  real_T X_e;                          /* '<S696>/Constant9' */
  real_T xdot_m[2];                    /* '<S552>/Open Differential' */
  real_T Mx_c[4];                      /* '<S513>/Magic Tire Const Input' */
  real_T Mz_j[4];                      /* '<S513>/Magic Tire Const Input' */
  real_T Re[4];                        /* '<S513>/Magic Tire Const Input' */
  real_T Kappa[4];                     /* '<S513>/Magic Tire Const Input' */
  real_T Alpha[4];                     /* '<S513>/Magic Tire Const Input' */
  real_T a[4];                         /* '<S513>/Magic Tire Const Input' */
  real_T b[4];                         /* '<S513>/Magic Tire Const Input' */
  real_T Mbar;                         /* '<S391>/vehdyncginert' */
  real_T Rbar[3];                      /* '<S391>/vehdyncginert' */
  real_T Xbar[3];                      /* '<S391>/vehdyncginert' */
  real_T Wbar[4];                      /* '<S391>/vehdyncginert' */
  real_T HPbar[12];                    /* '<S391>/vehdyncginert' */
  real32_T CellVoltages[96];           /* '<S25>/Unit Delay' */
  real32_T MinCellVolt;                /* '<S32>/MinMax' */
  real32_T Np_Module;                  /* '<S34>/Np_Module' */
  real32_T MaxCellVolt;                /* '<S32>/MinMax2' */
  real32_T ChargeCurrentLimit;         /* '<S33>/Np_Module' */
  real32_T PackVoltage;                /* '<S25>/Unit Delay' */
  real32_T VoutInvtr;                  /* '<S25>/Unit Delay' */
  real32_T PackCurrent;                /* '<S25>/Unit Delay' */
  real32_T SOC_CC;                     /* '<S37>/Discrete-Time Integrator' */
  real32_T Divide_cf;                  /* '<S37>/Divide' */
  real32_T PackVoltage_d;              /* '<S627>/Data Type Conversion1' */
  real32_T PackVoltage_i;              /* '<S627>/Rate Transition' */
  real32_T PackCurrent_i;              /* '<S627>/Data Type Conversion2' */
  real32_T VoutInvtr_k;                /* '<S627>/Data Type Conversion5' */
  real32_T CellVoltages_j[96];         /* '<S627>/Data Type Conversion6' */
  real32_T CellVoltages_e[96];         /* '<S627>/Rate Transition' */
  real32_T PackCurrent_j;              /* '<S627>/Rate Transition' */
  real32_T CellTemperatures[96];       /* '<S627>/Rate Transition' */
  real32_T VoutChgr_k;                 /* '<S627>/Rate Transition' */
  real32_T VoutInvtr_km;               /* '<S627>/Rate Transition' */
  real32_T ChargeCurrentReq;           /* '<S30>/State_Machine' */
  real32_T BMSState;                   /* '<S30>/State_Machine' */
  B_CoreSubsys_AdasPlantModel_e_T CoreSubsys_k[4];
                                    /* '<S522>/Clutch Partitioned Parameters' */
  B_CoreSubsys_AdasPlantModel_f_T CoreSubsys_b[3];/* '<S434>/Unwrap' */
  B_CoreSubsys_AdasPlantMode_ca_T CoreSubsys_pn[4];/* '<S287>/Wheel to Body Transform' */
  B_CoreSubsys_AdasPlantModel_c_T CoreSubsys_p[4];/* '<S375>/Wheel to Body Transform' */
  B_CoreSubsys_AdasPlantModel_h_T CoreSubsys[4];
  /* '<S291>/For each track and axle combination calculate suspension forces and moments' */
  B_MATLABFunction1_AdasPlantMo_T sf_MATLABFunction1_n;/* '<S241>/MATLAB Function1' */
  B_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  B_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_l;/* '<S220>/Enabled Subsystem1' */
  B_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_o;/* '<S220>/Enabled Subsystem' */
  B_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_f;/* '<S219>/Triggered Subsystem' */
  B_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_c;/* '<S219>/Enabled Subsystem1' */
  B_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_l;/* '<S219>/Enabled Subsystem' */
  B_MATLABFunction1_AdasPlantMo_T sf_MATLABFunction1;/* '<S154>/MATLAB Function1' */
  B_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_d;/* '<S133>/Triggered Subsystem' */
  B_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  B_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_i;/* '<S133>/Enabled Subsystem' */
  B_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem;/* '<S132>/Triggered Subsystem' */
  B_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1;/* '<S132>/Enabled Subsystem1' */
  B_EnabledSubsystem_AdasPlantM_T EnabledSubsystem;/* '<S132>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>/AdasPlantModel' */
struct DW_AdasPlantModel_AdasPlantMo_T {
  volatile real_T RateTransition18_Buffer[2];/* '<S21>/Rate Transition18' */
  volatile real_T RateTransition19_Buffer[2];/* '<S21>/Rate Transition19' */
  volatile real_T RateTransition20_Buffer[2];/* '<S21>/Rate Transition20' */
  volatile real_T RateTransition21_Buffer[2];/* '<S21>/Rate Transition21' */
  real_T Tk;                           /* '<S79>/First Order Hold' */
  real_T Ck;                           /* '<S79>/First Order Hold' */
  real_T Mk;                           /* '<S79>/First Order Hold' */
  real_T Uk;                           /* '<S79>/First Order Hold' */
  real_T Memory_PreviousInput;         /* '<S579>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S587>/Memory' */
  real_T PrevY;                        /* '<S117>/Backlash' */
  real_T TimeStampA;                   /* '<S131>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S131>/Derivative' */
  real_T TimeStampB;                   /* '<S131>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S131>/Derivative' */
  real_T TmpLatchAtTriggeredSubsystemInp;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_e;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_l;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_d;/* synthesized block */
  real_T Memory_PreviousInput_i;       /* '<S132>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S132>/Memory1' */
  real_T Memory_PreviousInput_e;       /* '<S133>/Memory' */
  real_T Memory1_PreviousInput_f;      /* '<S133>/Memory1' */
  real_T PrevY_f;                      /* '<S204>/Backlash' */
  real_T TimeStampA_g;                 /* '<S218>/Derivative' */
  real_T LastUAtTimeA_k;               /* '<S218>/Derivative' */
  real_T TimeStampB_h;                 /* '<S218>/Derivative' */
  real_T LastUAtTimeB_g;               /* '<S218>/Derivative' */
  real_T TmpLatchAtTriggeredSubsystemI_a;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_c;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_k;/* synthesized block */
  real_T TmpLatchAtTriggeredSubsystemI_m;/* synthesized block */
  real_T Memory_PreviousInput_m;       /* '<S219>/Memory' */
  real_T Memory1_PreviousInput_d;      /* '<S219>/Memory1' */
  real_T Memory_PreviousInput_mf;      /* '<S220>/Memory' */
  real_T Memory1_PreviousInput_k;      /* '<S220>/Memory1' */
  real_T Product2_DWORK4[9];           /* '<S413>/Product2' */
  real_T Memory_PreviousInput_l;       /* '<S601>/Memory' */
  real32_T UnitDelay_1_DSTATE[96];     /* '<S25>/Unit Delay' */
  real32_T UnitDelay_4_DSTATE[96];     /* '<S25>/Unit Delay' */
  real32_T UnitDelay_2_DSTATE;         /* '<S25>/Unit Delay' */
  real32_T UnitDelay_5_DSTATE;         /* '<S25>/Unit Delay' */
  real32_T UnitDelay_6_DSTATE;         /* '<S25>/Unit Delay' */
  real32_T UnitDelay_3_DSTATE;         /* '<S25>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S37>/Discrete-Time Integrator' */
  real32_T RT_Buffer[96];              /* '<S25>/RT' */
  real32_T RT1_Buffer;                 /* '<S25>/RT1' */
  real32_T RT2_Buffer;                 /* '<S25>/RT2' */
  real32_T RT3_Buffer;                 /* '<S25>/RT3' */
  real32_T RateTransition_2_Buffer;    /* '<S627>/Rate Transition' */
  real32_T RateTransition_1_Buffer[96];/* '<S627>/Rate Transition' */
  real32_T RateTransition_3_Buffer;    /* '<S627>/Rate Transition' */
  real32_T RateTransition_4_Buffer[96];/* '<S627>/Rate Transition' */
  real32_T RateTransition_5_Buffer;    /* '<S627>/Rate Transition' */
  real32_T RateTransition_6_Buffer;    /* '<S627>/Rate Transition' */
  real32_T Delta;                      /* '<S30>/State_Machine' */
  real32_T DeltaCellVolt;              /* '<S26>/Balancing' */
  MonitorCellTempModeType MonitorCellTempMode;/* '<S30>/State_Machine' */
  MonitorCellVoltageModeType MonitorCellVoltageMode;/* '<S30>/State_Machine' */
  MonitorCurrLimModeType MonitorCurrLimMode;/* '<S30>/State_Machine' */
  int_T Integrator_IWORK;              /* '<S630>/Integrator' */
  int_T Integrator_IWORK_a;            /* '<S579>/Integrator' */
  int_T Integrator_IWORK_c;            /* '<S587>/Integrator' */
  int_T Integrator_IWORK_c3;           /* '<S601>/Integrator' */
  int_T Integrator_IWORK_f;            /* '<S552>/Integrator' */
  int_T Integrator_IWORK_fi;           /* '<S643>/Integrator' */
  int_T IntegratorLimited_IWORK;       /* '<S632>/Integrator Limited' */
  int_T IntegratorSecondOrder_MODE[4]; /* '<S520>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_h;  /* '<S157>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_b;  /* '<S139>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_i;  /* '<S138>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_e;  /* '<S244>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_d;  /* '<S226>/Integrator, Second-Order' */
  int_T IntegratorSecondOrder_MODE_ex; /* '<S225>/Integrator, Second-Order' */
  int_T IntegratorSecondOrderLimited_MO[3];
                                 /* '<S683>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited__m[3];
                                 /* '<S695>/Integrator, Second-Order Limited' */
  uint16_T temporalCounter_i1;         /* '<S30>/State_Machine' */
  uint16_T temporalCounter_i2;         /* '<S30>/State_Machine' */
  uint16_T temporalCounter_i3;         /* '<S30>/State_Machine' */
  uint16_T temporalCounter_i1_i;       /* '<S26>/Balancing' */
  volatile int8_T RateTransition18_ActiveBufIdx;/* '<S21>/Rate Transition18' */
  volatile int8_T RateTransition19_ActiveBufIdx;/* '<S21>/Rate Transition19' */
  volatile int8_T RateTransition20_ActiveBufIdx;/* '<S21>/Rate Transition20' */
  volatile int8_T RateTransition21_ActiveBufIdx;/* '<S21>/Rate Transition21' */
  uint8_T is_active_c2_AdasPlantModel0;/* '<S30>/State_Machine' */
  uint8_T is_MainStateMachine;         /* '<S30>/State_Machine' */
  uint8_T is_Charging;                 /* '<S30>/State_Machine' */
  uint8_T is_ChargerContactorState;    /* '<S30>/State_Machine' */
  uint8_T is_CloseChgrContactors;      /* '<S30>/State_Machine' */
  uint8_T is_OpenChgrContactors;       /* '<S30>/State_Machine' */
  uint8_T is_InverterContactorState;   /* '<S30>/State_Machine' */
  uint8_T is_CloseInvtrContactors;     /* '<S30>/State_Machine' */
  uint8_T is_OpenInvtrContactors;      /* '<S30>/State_Machine' */
  uint8_T is_active_c1_AdasPlantModel0;/* '<S26>/Balancing' */
  uint8_T is_c1_AdasPlantModel0;       /* '<S26>/Balancing' */
  uint8_T is_BalancingON;              /* '<S26>/Balancing' */
  boolean_T IntegratorSecondOrder_DWORK1;/* '<S520>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_e;/* '<S157>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_a;/* '<S139>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_c;/* '<S138>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_m;/* '<S244>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_h;/* '<S226>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_DWORK1_o;/* '<S225>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrderLimited_DW;
                                 /* '<S683>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited__k;
                                 /* '<S695>/Integrator, Second-Order Limited' */
  boolean_T FaultPresent;              /* '<S30>/State_Machine' */
  boolean_T flgBalCompl;               /* '<S26>/Balancing' */
  Contact ChrgCntctState;              /* '<S30>/State_Machine' */
  Contact InvtrCntctState;             /* '<S30>/State_Machine' */
  DW_CoreSubsys_AdasPlantMod_lq_T CoreSubsys_k[4];
                                    /* '<S522>/Clutch Partitioned Parameters' */
  DW_CoreSubsys_AdasPlantMode_l_T CoreSubsys_b[3];/* '<S434>/Unwrap' */
  DW_EnabledSubsystem1_AdasPlan_T EnabledSubsystem1_l;/* '<S220>/Enabled Subsystem1' */
  DW_EnabledSubsystem_AdasPlant_T EnabledSubsystem_o;/* '<S220>/Enabled Subsystem' */
  DW_EnabledSubsystem1_AdasPlan_T EnabledSubsystem1_c;/* '<S219>/Enabled Subsystem1' */
  DW_EnabledSubsystem_AdasPlant_T EnabledSubsystem_l;/* '<S219>/Enabled Subsystem' */
  DW_EnabledSubsystem1_AdasPlan_T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  DW_EnabledSubsystem_AdasPlant_T EnabledSubsystem_i;/* '<S133>/Enabled Subsystem' */
  DW_EnabledSubsystem1_AdasPlan_T EnabledSubsystem1;/* '<S132>/Enabled Subsystem1' */
  DW_EnabledSubsystem_AdasPlant_T EnabledSubsystem;/* '<S132>/Enabled Subsystem' */
};

/* Continuous states for system '<Root>/AdasPlantModel' */
struct X_AdasPlantModel_AdasPlantMod_T {
  real_T Integrator_CSTATE;            /* '<S630>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S609>/Integrator' */
  real_T ubvbwb_CSTATE[3];             /* '<S406>/ub,vb,wb' */
  real_T Integrator1_CSTATE[4];        /* '<S105>/Integrator1' */
  real_T Integrator_CSTATE_f[4];       /* '<S516>/Integrator' */
  real_T Integrator_CSTATE_p[4];       /* '<S517>/Integrator' */
  real_T Integrator1_CSTATE_c[4];      /* '<S373>/Integrator1' */
  real_T Integrator_CSTATE_i;          /* '<S579>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S578>/Integrator' */
  real_T Integrator_CSTATE_fd;         /* '<S587>/Integrator' */
  real_T Integrator_CSTATE_jc;         /* '<S586>/Integrator' */
  real_T Integrator_CSTATE_m1[4];      /* '<S519>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE[8];/* '<S520>/Integrator, Second-Order' */
  real_T pqr_CSTATE[3];                /* '<S406>/p,q,r ' */
  real_T Integrator1_CSTATE_n[12];     /* '<S374>/Integrator1' */
  real_T xeyeze_CSTATE[3];             /* '<S406>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S412>/phi theta psi' */
  real_T IntegratorSecondOrder_CSTATE_h[2];/* '<S157>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_no[4];     /* '<S289>/Integrator1' */
  real_T Integrator1_CSTATE_b[4];      /* '<S290>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_a[2];/* '<S139>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_e;          /* '<S131>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_m[2];/* '<S138>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_c1;        /* '<S126>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_b[2];/* '<S244>/Integrator, Second-Order' */
  real_T IntegratorSecondOrder_CSTATE_f[2];/* '<S226>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_n;          /* '<S218>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_j[2];/* '<S225>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_j;         /* '<S213>/Integrator1' */
  real_T Integrator1_CSTATE_m[2];      /* '<S392>/Integrator1' */
  real_T Integrator_CSTATE_k[3];       /* '<S410>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S601>/Integrator' */
  real_T Integrator_CSTATE_jcw;        /* '<S600>/Integrator' */
  real_T Integrator_CSTATE_a[2];       /* '<S552>/Integrator' */
  real_T MotorCouplingDynamics_CSTATE; /* '<S657>/Motor Coupling Dynamics' */
  real_T Integrator_CSTATE_o;          /* '<S643>/Integrator' */
  real_T Integrator_CSTATE_ky;         /* '<S665>/Integrator' */
  real_T IntegratorLimited_CSTATE;     /* '<S632>/Integrator Limited' */
  real_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S683>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited__f[6];
                                 /* '<S695>/Integrator, Second-Order Limited' */
  X_CoreSubsys_AdasPlantModel_c_T CoreSubsys_k[4];/* '<S526>/CoreSubsys' */
};

/* State derivatives for system '<Root>/AdasPlantModel' */
struct XDot_AdasPlantModel_AdasPlant_T {
  real_T Integrator_CSTATE;            /* '<S630>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S609>/Integrator' */
  real_T ubvbwb_CSTATE[3];             /* '<S406>/ub,vb,wb' */
  real_T Integrator1_CSTATE[4];        /* '<S105>/Integrator1' */
  real_T Integrator_CSTATE_f[4];       /* '<S516>/Integrator' */
  real_T Integrator_CSTATE_p[4];       /* '<S517>/Integrator' */
  real_T Integrator1_CSTATE_c[4];      /* '<S373>/Integrator1' */
  real_T Integrator_CSTATE_i;          /* '<S579>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S578>/Integrator' */
  real_T Integrator_CSTATE_fd;         /* '<S587>/Integrator' */
  real_T Integrator_CSTATE_jc;         /* '<S586>/Integrator' */
  real_T Integrator_CSTATE_m1[4];      /* '<S519>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE[8];/* '<S520>/Integrator, Second-Order' */
  real_T pqr_CSTATE[3];                /* '<S406>/p,q,r ' */
  real_T Integrator1_CSTATE_n[12];     /* '<S374>/Integrator1' */
  real_T xeyeze_CSTATE[3];             /* '<S406>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S412>/phi theta psi' */
  real_T IntegratorSecondOrder_CSTATE_h[2];/* '<S157>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_no[4];     /* '<S289>/Integrator1' */
  real_T Integrator1_CSTATE_b[4];      /* '<S290>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_a[2];/* '<S139>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_e;          /* '<S131>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_m[2];/* '<S138>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_c1;        /* '<S126>/Integrator1' */
  real_T IntegratorSecondOrder_CSTATE_b[2];/* '<S244>/Integrator, Second-Order' */
  real_T IntegratorSecondOrder_CSTATE_f[2];/* '<S226>/Integrator, Second-Order' */
  real_T Integrator_CSTATE_n;          /* '<S218>/Integrator' */
  real_T IntegratorSecondOrder_CSTATE_j[2];/* '<S225>/Integrator, Second-Order' */
  real_T Integrator1_CSTATE_j;         /* '<S213>/Integrator1' */
  real_T Integrator1_CSTATE_m[2];      /* '<S392>/Integrator1' */
  real_T Integrator_CSTATE_k[3];       /* '<S410>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S601>/Integrator' */
  real_T Integrator_CSTATE_jcw;        /* '<S600>/Integrator' */
  real_T Integrator_CSTATE_a[2];       /* '<S552>/Integrator' */
  real_T MotorCouplingDynamics_CSTATE; /* '<S657>/Motor Coupling Dynamics' */
  real_T Integrator_CSTATE_o;          /* '<S643>/Integrator' */
  real_T Integrator_CSTATE_ky;         /* '<S665>/Integrator' */
  real_T IntegratorLimited_CSTATE;     /* '<S632>/Integrator Limited' */
  real_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S683>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited__f[6];
                                 /* '<S695>/Integrator, Second-Order Limited' */
  XDot_CoreSubsys_AdasPlantMo_a_T CoreSubsys_k[4];/* '<S526>/CoreSubsys' */
};

/* State Disabled for system '<Root>/AdasPlantModel' */
struct XDis_AdasPlantModel_AdasPlant_T {
  boolean_T Integrator_CSTATE;         /* '<S630>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S609>/Integrator' */
  boolean_T ubvbwb_CSTATE[3];          /* '<S406>/ub,vb,wb' */
  boolean_T Integrator1_CSTATE[4];     /* '<S105>/Integrator1' */
  boolean_T Integrator_CSTATE_f[4];    /* '<S516>/Integrator' */
  boolean_T Integrator_CSTATE_p[4];    /* '<S517>/Integrator' */
  boolean_T Integrator1_CSTATE_c[4];   /* '<S373>/Integrator1' */
  boolean_T Integrator_CSTATE_i;       /* '<S579>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S578>/Integrator' */
  boolean_T Integrator_CSTATE_fd;      /* '<S587>/Integrator' */
  boolean_T Integrator_CSTATE_jc;      /* '<S586>/Integrator' */
  boolean_T Integrator_CSTATE_m1[4];   /* '<S519>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE[8];/* '<S520>/Integrator, Second-Order' */
  boolean_T pqr_CSTATE[3];             /* '<S406>/p,q,r ' */
  boolean_T Integrator1_CSTATE_n[12];  /* '<S374>/Integrator1' */
  boolean_T xeyeze_CSTATE[3];          /* '<S406>/xe,ye,ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S412>/phi theta psi' */
  boolean_T IntegratorSecondOrder_CSTATE_h[2];/* '<S157>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_no[4];  /* '<S289>/Integrator1' */
  boolean_T Integrator1_CSTATE_b[4];   /* '<S290>/Integrator1' */
  boolean_T IntegratorSecondOrder_CSTATE_a[2];/* '<S139>/Integrator, Second-Order' */
  boolean_T Integrator_CSTATE_e;       /* '<S131>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE_m[2];/* '<S138>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_c1;     /* '<S126>/Integrator1' */
  boolean_T IntegratorSecondOrder_CSTATE_b[2];/* '<S244>/Integrator, Second-Order' */
  boolean_T IntegratorSecondOrder_CSTATE_f[2];/* '<S226>/Integrator, Second-Order' */
  boolean_T Integrator_CSTATE_n;       /* '<S218>/Integrator' */
  boolean_T IntegratorSecondOrder_CSTATE_j[2];/* '<S225>/Integrator, Second-Order' */
  boolean_T Integrator1_CSTATE_j;      /* '<S213>/Integrator1' */
  boolean_T Integrator1_CSTATE_m[2];   /* '<S392>/Integrator1' */
  boolean_T Integrator_CSTATE_k[3];    /* '<S410>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S601>/Integrator' */
  boolean_T Integrator_CSTATE_jcw;     /* '<S600>/Integrator' */
  boolean_T Integrator_CSTATE_a[2];    /* '<S552>/Integrator' */
  boolean_T MotorCouplingDynamics_CSTATE;/* '<S657>/Motor Coupling Dynamics' */
  boolean_T Integrator_CSTATE_o;       /* '<S643>/Integrator' */
  boolean_T Integrator_CSTATE_ky;      /* '<S665>/Integrator' */
  boolean_T IntegratorLimited_CSTATE;  /* '<S632>/Integrator Limited' */
  boolean_T IntegratorSecondOrderLimited_CS[6];
                                 /* '<S683>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited__f[6];
                                 /* '<S695>/Integrator, Second-Order Limited' */
  XDis_CoreSubsys_AdasPlantMo_i_T CoreSubsys_k[4];/* '<S526>/CoreSubsys' */
};

/* Zero-crossing (trigger) state for system '<Root>/AdasPlantModel' */
struct ZCE_AdasPlantModel_AdasPlantM_T {
  ZCSigState Integrator_Reset_ZCE;     /* '<S579>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S587>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S601>/Integrator' */
  ZCE_CoreSubsys_AdasPlantMod_c_T CoreSubsys_b[3];/* '<S434>/Unwrap' */
  ZCE_TriggeredSubsystem_AdasPl_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_AdasPl_T TriggeredSubsystem_f;/* '<S219>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_AdasPl_T TriggeredSubsystem_d;/* '<S133>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_AdasPl_T TriggeredSubsystem;/* '<S132>/Triggered Subsystem' */
};

/* Parameters for system: '<S132>/Enabled Subsystem' */
struct P_EnabledSubsystem_AdasPlantM_T_ {
  real_T Fright_Y0;                    /* Computed Parameter: Fright_Y0
                                        * Referenced by: '<S140>/Fright'
                                        */
};

/* Parameters for system: '<S132>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_AdasPlant_T_ {
  real_T Fleft_Y0;                     /* Computed Parameter: Fleft_Y0
                                        * Referenced by: '<S141>/Fleft'
                                        */
};

/* Parameters for system: '<S132>/Triggered Subsystem' */
struct P_TriggeredSubsystem_AdasPlan_T_ {
  real_T Out_Y0;                       /* Computed Parameter: Out_Y0
                                        * Referenced by: '<S142>/Out'
                                        */
  real_T xleft_Y0;                     /* Computed Parameter: xleft_Y0
                                        * Referenced by: '<S142>/xleft'
                                        */
  real_T xright_Y0;                    /* Computed Parameter: xright_Y0
                                        * Referenced by: '<S142>/xright'
                                        */
};

/* Parameters for system: '<S291>/For each track and axle combination calculate suspension forces and moments' */
struct P_CoreSubsys_AdasPlantModel_o_T_ {
  real_T SelectSteerCamberSlope_AxleNums;
                              /* Mask Parameter: SelectSteerCamberSlope_AxleNums
                               * Referenced by: '<S326>/Axle Numbers'
                               */
  real_T SelectStaticToeSetting_AxleNums[2];
                              /* Mask Parameter: SelectStaticToeSetting_AxleNums
                               * Referenced by: '<S352>/Axle Numbers'
                               */
  real_T SelectSteerCasterSlope_AxleNums;
                              /* Mask Parameter: SelectSteerCasterSlope_AxleNums
                               * Referenced by: '<S335>/Axle Numbers'
                               */
  real_T Constrainedspringdampercombinat[2];
                              /* Mask Parameter: Constrainedspringdampercombinat
                               * Referenced by: '<S366>/Axle Numbers'
                               */
  real_T Constant1_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S365>/Constant1'
                                        */
  real_T VehicleVehicleWheelOffset3_Valu[3];/* Expression: [0 cumsum(NumWhlsByAxl)]
                                             * Referenced by: '<S301>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T HeightSignConvention_Gain;    /* Expression: -1
                                        * Referenced by: '<S359>/Height Sign Convention'
                                        */
  real_T SignConvention_Gain;          /* Expression: -1
                                        * Referenced by: '<S306>/Sign Convention'
                                        */
  real_T Gain5_Gain;                   /* Expression: VerticalSign
                                        * Referenced by: '<S308>/Gain5'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S302>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset1_Valu[2];/* Expression: StrgEnByAxl
                                             * Referenced by: '<S302>/Vehicle Vehicle Wheel Offset1'
                                             */
  real_T VehicleVehicleWheelOffset3_Va_d[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S346>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S346>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S346>/Gain'
                                        */
  real_T Gain5_Gain_m;                 /* Expression: VerticalSign
                                        * Referenced by: '<S313>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: WhlMzSign
                                        * Referenced by: '<S313>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: LateralSign
                                        * Referenced by: '<S313>/Gain3'
                                        */
  real_T Constant6_Value[4];           /* Expression: LngSteerCompl(2,:)
                                        * Referenced by: '<S356>/Constant6'
                                        */
  real_T Gain1_Gain;                   /* Expression: LongitudinalSign
                                        * Referenced by: '<S313>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: LongitudinalSign
                                        * Referenced by: '<S356>/Gain2'
                                        */
  real_T Constant3_Value[4];           /* Expression: LngSteerCompl(1,:)
                                        * Referenced by: '<S356>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S356>/Switch'
                                        */
  real_T Gain_Gain_l;                  /* Expression: SteerSign
                                        * Referenced by: '<S313>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: SteerSign
                                        * Referenced by: '<S308>/Gain'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: WhlMzSign
                                        * Referenced by: '<S308>/Gain4'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: LateralSign
                                        * Referenced by: '<S308>/Gain3'
                                        */
  real_T Constant6_Value_i[4];         /* Expression: LngCambCompl(2,:)
                                        * Referenced by: '<S323>/Constant6'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S308>/Gain1'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S323>/Gain2'
                                        */
  real_T Constant1_Value_i[4];         /* Expression: LngCambCompl(1,:)
                                        * Referenced by: '<S323>/Constant1'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S323>/Switch'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: VerticalSign
                                        * Referenced by: '<S309>/Gain4'
                                        */
  real_T Gain_Gain_b;                  /* Expression: SteerSign
                                        * Referenced by: '<S309>/Gain'
                                        */
  real_T Constant4_Value[4];           /* Expression: LngCastCompl(2,:)
                                        * Referenced by: '<S332>/Constant4'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S309>/Gain2'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S332>/Gain2'
                                        */
  real_T Constant2_Value[4];           /* Expression: LngCastCompl(1,:)
                                        * Referenced by: '<S332>/Constant2'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S332>/Switch'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_a[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S310>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S310>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/2
                                        * Referenced by: '<S310>/Gain'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: VerticalSign
                                        * Referenced by: '<S359>/Gain2'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: VerticalSign
                                        * Referenced by: '<S312>/Gain4'
                                        */
  real_T Constant2_Value_k[4];         /* Expression: LngWhlCtrCompl(2,:)
                                        * Referenced by: '<S345>/Constant2'
                                        */
  real_T Gain_Gain_c;                  /* Expression: LongitudinalSign
                                        * Referenced by: '<S312>/Gain'
                                        */
  real_T Gain2_Gain_kb;                /* Expression: LongitudinalSign
                                        * Referenced by: '<S345>/Gain2'
                                        */
  real_T Constant1_Value_k[4];         /* Expression: LngWhlCtrCompl(1,:)
                                        * Referenced by: '<S345>/Constant1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S345>/Switch'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S312>/Gain1'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: VerticalSign
                                        * Referenced by: '<S311>/Gain4'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: LateralSign
                                        * Referenced by: '<S311>/Gain3'
                                        */
  real_T Constant3_Value_a[4];         /* Expression: LatWhlCtrComplLngBrk(2,:)
                                        * Referenced by: '<S341>/Constant3'
                                        */
  real_T Gain_Gain_k;                  /* Expression: LongitudinalSign
                                        * Referenced by: '<S311>/Gain'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: LongitudinalSign
                                        * Referenced by: '<S341>/Gain2'
                                        */
  real_T Constant1_Value_a[4];         /* Expression: LatWhlCtrComplLngBrk(1,:)
                                        * Referenced by: '<S341>/Constant1'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S341>/Switch'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: LateralSign
                                        * Referenced by: '<S311>/Gain1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S370>/Constant'
                                        */
  real_T Constant_Value_k[2];          /* Expression: AntiSwayEnByAxl
                                        * Referenced by: '<S365>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_m[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S360>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S360>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1/2
                                        * Referenced by: '<S360>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S360>/Gain1'
                                        */
  real_T Gain4_Gain_od;                /* Expression: VerticalSign
                                        * Referenced by: '<S359>/Gain4'
                                        */
  real_T VehicleForceSign_Gain;        /* Expression: -1
                                        * Referenced by: '<S358>/Vehicle Force Sign'
                                        */
  real_T Signconvention_Gain;          /* Expression: -1
                                        * Referenced by: '<S358>/Sign convention'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S304>/Constant'
                                        */
  real_T VehicleVehicleWheelOffset3_Va_b[2];/* Expression: NumWhlsByAxl
                                             * Referenced by: '<S307>/Vehicle Vehicle Wheel Offset3'
                                             */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S307>/Constant'
                                        */
  real_T Gain_Gain_le;                 /* Expression: 1/2
                                        * Referenced by: '<S307>/Gain'
                                        */
};

/* Parameters for system: '<S375>/Wheel to Body Transform' */
struct P_CoreSubsys_AdasPlantModel_g_T_ {
  real_T Constant_Value[3];            /* Expression: [pi;0;0]
                                        * Referenced by: '<S377>/Constant'
                                        */
};

/* Parameters for system: '<S287>/Wheel to Body Transform' */
struct P_CoreSubsys_AdasPlantMode_gm_T_ {
  real_T Constant1_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S383>/Constant1'
                                        */
  real_T Constant_Value[3];            /* Expression: [pi;0;0]
                                        * Referenced by: '<S383>/Constant'
                                        */
};

/* Parameters for system: '<S434>/Unwrap' */
struct P_CoreSubsys_AdasPlantModel_l_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S440>/Constant'
                                       */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S441>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S441>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S441>/Unit Delay'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S439>/Memory1'
                                        */
};

/* Parameters for system: '<S526>/Clutch' */
struct P_Clutch_AdasPlantModel0_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S530>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S528>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S528>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S528>/Constant2'
                                        */
  real_T u_Gain;                       /* Expression: -4
                                        * Referenced by: '<S529>/-4'
                                        */
  boolean_T yn_Y0;                     /* Computed Parameter: yn_Y0
                                        * Referenced by: '<S531>/yn'
                                        */
  boolean_T yn_Y0_o;                   /* Computed Parameter: yn_Y0_o
                                        * Referenced by: '<S530>/yn'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S535>/Unit Delay'
                                */
  boolean_T CombinatorialLogic_table[8];
                                 /* Computed Parameter: CombinatorialLogic_table
                                  * Referenced by: '<S535>/Combinatorial  Logic'
                                  */
};

/* Parameters for system: '<S522>/Clutch Partitioned Parameters' */
struct P_CoreSubsys_AdasPlantMode_gp_T_ {
  real_T Clutch_OmegaTol;              /* Mask Parameter: Clutch_OmegaTol
                                        * Referenced by: '<S526>/Clutch'
                                        */
  P_Clutch_AdasPlantModel0_T sf_Clutch;/* '<S526>/Clutch' */
};

/* Parameters for system: '<Root>/AdasPlantModel' */
struct P_AdasPlantModel_AdasPlantMod_T_ {
  real_T SteerTorqueControl_A;         /* Mask Parameter: SteerTorqueControl_A
                                        * Referenced by: '<S131>/Gain3'
                                        */
  real_T SteerTorqueControl_A_o;       /* Mask Parameter: SteerTorqueControl_A_o
                                        * Referenced by: '<S218>/Gain3'
                                        */
  real_T IndependentKandCSuspension_Axle[4];
                              /* Mask Parameter: IndependentKandCSuspension_Axle
                               * Referenced by: '<S291>/Axle Number'
                               */
  real_T CombinedSlipWheel2DOF_BOTTOM_OF;
                              /* Mask Parameter: CombinedSlipWheel2DOF_BOTTOM_OF
                               * Referenced by: '<S513>/Magic Tire Const Input'
                               */
  real_T CombinedSlipWheel2DOF_BOTTOM_ST;
                              /* Mask Parameter: CombinedSlipWheel2DOF_BOTTOM_ST
                               * Referenced by: '<S513>/Magic Tire Const Input'
                               */
  real_T CombinedSlipWheel2DOF_BREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_BREFF
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T VehicleBody6DOF_Cs[31];       /* Mask Parameter: VehicleBody6DOF_Cs
                                        * Referenced by: '<S433>/Cs'
                                        */
  real_T VehicleBody6DOF_Cym[31];      /* Mask Parameter: VehicleBody6DOF_Cym
                                        * Referenced by: '<S433>/Cym'
                                        */
  real_T SteerTorqueControl_D;         /* Mask Parameter: SteerTorqueControl_D
                                        * Referenced by: '<S131>/Gain2'
                                        */
  real_T SteerTorqueControl_D_f;       /* Mask Parameter: SteerTorqueControl_D_f
                                        * Referenced by: '<S218>/Gain2'
                                        */
  real_T CombinedSlipWheel2DOF_DREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_DREFF
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T FrontSteering_DbWdth;         /* Mask Parameter: FrontSteering_DbWdth
                                        * Referenced by: '<S117>/Backlash'
                                        */
  real_T RearSteering_DbWdth;          /* Mask Parameter: RearSteering_DbWdth
                                        * Referenced by: '<S204>/Backlash'
                                        */
  real_T FrontSteering_Eta;            /* Mask Parameter: FrontSteering_Eta
                                        * Referenced by: '<S125>/Gain1'
                                        */
  real_T RearSteering_Eta;             /* Mask Parameter: RearSteering_Eta
                                        * Referenced by: '<S212>/Gain1'
                                        */
  real_T CombinedSlipWheel2DOF_FREFF;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_FREFF
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_GRAVITY;
                                /* Mask Parameter: CombinedSlipWheel2DOF_GRAVITY
                                 * Referenced by: '<S520>/Fg'
                                 */
  real_T SteerTorqueControl_I;         /* Mask Parameter: SteerTorqueControl_I
                                        * Referenced by: '<S131>/Gain1'
                                        */
  real_T SteerTorqueControl_I_e;       /* Mask Parameter: SteerTorqueControl_I_e
                                        * Referenced by: '<S218>/Gain1'
                                        */
  real_T VehicleBody6DOF_Iveh[9];      /* Mask Parameter: VehicleBody6DOF_Iveh
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T ClutchPartitionedParameters_Iyy[4];
                              /* Mask Parameter: ClutchPartitionedParameters_Iyy
                               * Referenced by: '<S522>/Clutch Partitioned Parameters'
                               */
  real_T SteerTorqueControl_OutSatLowLmt;
                              /* Mask Parameter: SteerTorqueControl_OutSatLowLmt
                               * Referenced by: '<S131>/Saturation'
                               */
  real_T SteerTorqueControl_OutSatLowL_g;
                              /* Mask Parameter: SteerTorqueControl_OutSatLowL_g
                               * Referenced by: '<S218>/Saturation'
                               */
  real_T SteerTorqueControl_OutSatUpLmt;
                               /* Mask Parameter: SteerTorqueControl_OutSatUpLmt
                                * Referenced by: '<S131>/Saturation'
                                */
  real_T SteerTorqueControl_OutSatUpLm_k;
                              /* Mask Parameter: SteerTorqueControl_OutSatUpLm_k
                               * Referenced by: '<S218>/Saturation'
                               */
  real_T SteerTorqueControl_P;         /* Mask Parameter: SteerTorqueControl_P
                                        * Referenced by: '<S131>/Gain'
                                        */
  real_T SteerTorqueControl_P_d;       /* Mask Parameter: SteerTorqueControl_P_d
                                        * Referenced by: '<S218>/Gain'
                                        */
  real_T CombinedSlipWheel2DOF_PFZ1;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_PFZ1
                                    * Referenced by: '<S513>/Magic Tire Const Input'
                                    */
  real_T CombinedSlipWheel2DOF_Q_FCX;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCX
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FCY;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCY
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FCY2;
                                 /* Mask Parameter: CombinedSlipWheel2DOF_Q_FCY2
                                  * Referenced by: '<S513>/Magic Tire Const Input'
                                  */
  real_T CombinedSlipWheel2DOF_Q_FZ1;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ1
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FZ2;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ2
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_FZ3;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_FZ3
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_RE0;
                                  /* Mask Parameter: CombinedSlipWheel2DOF_Q_RE0
                                   * Referenced by: '<S513>/Magic Tire Const Input'
                                   */
  real_T CombinedSlipWheel2DOF_Q_V1;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_Q_V1
                                    * Referenced by: '<S513>/Magic Tire Const Input'
                                    */
  real_T CombinedSlipWheel2DOF_Q_V2;
                                   /* Mask Parameter: CombinedSlipWheel2DOF_Q_V2
                                    * Referenced by: '<S513>/Magic Tire Const Input'
                                    */
  real_T DragForce_R;                  /* Mask Parameter: DragForce_R
                                        * Referenced by: '<S433>/.5.*A.*Pabs.//R.//T'
                                        */
  real_T CombinedSlipWheel2DOF_Rm[4];/* Mask Parameter: CombinedSlipWheel2DOF_Rm
                                      * Referenced by: '<S525>/Torque Conversion'
                                      */
  real_T FrontSteering_SptlAng;        /* Mask Parameter: FrontSteering_SptlAng
                                        * Referenced by:
                                        *   '<S154>/MATLAB Function'
                                        *   '<S154>/MATLAB Function1'
                                        */
  real_T RearSteering_SptlAng;         /* Mask Parameter: RearSteering_SptlAng
                                        * Referenced by:
                                        *   '<S241>/MATLAB Function'
                                        *   '<S241>/MATLAB Function1'
                                        */
  real_T CombinedSlipWheel2DOF_VERTICAL_;
                              /* Mask Parameter: CombinedSlipWheel2DOF_VERTICAL_
                               * Referenced by: '<S513>/Magic Tire Const Input'
                               */
  real_T FrontSteering_VehSpdBpts[2];/* Mask Parameter: FrontSteering_VehSpdBpts
                                      * Referenced by: '<S125>/TrqAssistTbl'
                                      */
  real_T RearSteering_VehSpdBpts[2];  /* Mask Parameter: RearSteering_VehSpdBpts
                                       * Referenced by: '<S212>/TrqAssistTbl'
                                       */
  real_T IndependentKandCSuspension_WhlN[4];
                              /* Mask Parameter: IndependentKandCSuspension_WhlN
                               * Referenced by: '<S291>/Wheel Number'
                               */
  real_T VehicleBody6DOF_Xe_o[3];      /* Mask Parameter: VehicleBody6DOF_Xe_o
                                        * Referenced by: '<S406>/xe,ye,ze'
                                        */
  real_T ThreeaxisInertialMeasurementUni[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementUni
                               * Referenced by: '<S676>/Measurement bias'
                               */
  real_T ThreeaxisInertialMeasurementU_j[9];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_j
                               * Referenced by: '<S676>/Scale factors & Cross-coupling  errors'
                               */
  real_T VehicleBody6DOF_beta_w[31];   /* Mask Parameter: VehicleBody6DOF_beta_w
                                        * Referenced by:
                                        *   '<S433>/Cs'
                                        *   '<S433>/Cym'
                                        */
  real_T ClutchPartitionedParameters_br[4];
                               /* Mask Parameter: ClutchPartitionedParameters_br
                                * Referenced by: '<S522>/Clutch Partitioned Parameters'
                                */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S54>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S55>/Constant'
                                      */
  real_T CompareToConstant_const_k; /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S58>/Constant'
                                     */
  real_T CompareToConstant_const_ke;
                                   /* Mask Parameter: CompareToConstant_const_ke
                                    * Referenced by: '<S65>/Constant'
                                    */
  real_T VehicleBody6DOF_d;            /* Mask Parameter: VehicleBody6DOF_d
                                        * Referenced by:
                                        *   '<S391>/vehdyncginert'
                                        *   '<S447>/Constant'
                                        */
  real_T RackandPinforDynStr_d;        /* Mask Parameter: RackandPinforDynStr_d
                                        * Referenced by:
                                        *   '<S171>/Constant2'
                                        *   '<S171>/Constant3'
                                        *   '<S172>/Constant2'
                                        *   '<S172>/Constant3'
                                        *   '<S173>/Constant2'
                                        *   '<S173>/Constant3'
                                        */
  real_T RackandPinforDynStr_d_c;     /* Mask Parameter: RackandPinforDynStr_d_c
                                       * Referenced by:
                                       *   '<S258>/Constant2'
                                       *   '<S258>/Constant3'
                                       *   '<S259>/Constant2'
                                       *   '<S259>/Constant3'
                                       *   '<S260>/Constant2'
                                       *   '<S260>/Constant3'
                                       */
  real_T CombinedSlipWheel2DOF_disk_abor[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_disk_abor
                               * Referenced by: '<S525>/Disk brake actuator bore'
                               */
  real_T VehicleBody6DOF_eul_o[3];     /* Mask Parameter: VehicleBody6DOF_eul_o
                                        * Referenced by: '<S412>/phi theta psi'
                                        */
  real_T ThreeaxisInertialMeasurementU_n[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_n
                               * Referenced by: '<S677>/Measurement bias'
                               */
  real_T ThreeaxisInertialMeasurementU_m[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_m
                               * Referenced by: '<S677>/g-sensitive bias'
                               */
  real_T ThreeaxisInertialMeasurementU_f[9];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_f
                               * Referenced by: '<S677>/Scale factors & Cross-coupling  errors '
                               */
  real_T VehicleBody6DOF_hl;           /* Mask Parameter: VehicleBody6DOF_hl
                                        * Referenced by: '<S449>/Constant2'
                                        */
  real_T ThreeaxisInertialMeasurementU_h[3];
                              /* Mask Parameter: ThreeaxisInertialMeasurementU_h
                               * Referenced by: '<S676>/wl_ins'
                               */
  real_T VehicleBody6DOF_latOff;       /* Mask Parameter: VehicleBody6DOF_latOff
                                        * Referenced by: '<S452>/latOff'
                                        */
  real_T VehicleBody6DOF_longOff;     /* Mask Parameter: VehicleBody6DOF_longOff
                                       * Referenced by: '<S452>/longOff'
                                       */
  real_T CombinedSlipWheel2DOF_mu_kineti[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_mu_kineti
                               * Referenced by:
                               *   '<S523>/Ratio of static to kinetic'
                               *   '<S523>/Ratio of static to kinetic1'
                               *   '<S525>/Torque Conversion'
                               */
  real_T CombinedSlipWheel2DOF_mu_static[4];
                              /* Mask Parameter: CombinedSlipWheel2DOF_mu_static
                               * Referenced by: '<S523>/Ratio of static to kinetic'
                               */
  real_T CombinedSlipWheel2DOF_num_pads[4];
                               /* Mask Parameter: CombinedSlipWheel2DOF_num_pads
                                * Referenced by: '<S525>/Number of brake pads'
                                */
  real_T ClutchPartitionedParameters_ome[4];
                              /* Mask Parameter: ClutchPartitionedParameters_ome
                               * Referenced by: '<S522>/Clutch Partitioned Parameters'
                               */
  real_T VehicleBody6DOF_p_o[3];       /* Mask Parameter: VehicleBody6DOF_p_o
                                        * Referenced by: '<S406>/p,q,r '
                                        */
  real_T div0protectpoly_thresh;       /* Mask Parameter: div0protectpoly_thresh
                                        * Referenced by:
                                        *   '<S67>/Constant'
                                        *   '<S68>/Constant'
                                        */
  real_T div0protectpoly_thresh_i;   /* Mask Parameter: div0protectpoly_thresh_i
                                      * Referenced by:
                                      *   '<S128>/Constant'
                                      *   '<S129>/Constant'
                                      */
  real_T div0protectpoly_thresh_n;   /* Mask Parameter: div0protectpoly_thresh_n
                                      * Referenced by:
                                      *   '<S215>/Constant'
                                      *   '<S216>/Constant'
                                      */
  real_T div0protectabspoly_thresh; /* Mask Parameter: div0protectabspoly_thresh
                                     * Referenced by:
                                     *   '<S618>/Constant'
                                     *   '<S619>/Constant'
                                     */
  real_T div0protectpoly_thresh_g;   /* Mask Parameter: div0protectpoly_thresh_g
                                      * Referenced by:
                                      *   '<S651>/Constant'
                                      *   '<S652>/Constant'
                                      */
  real_T div0protectabspoly_thresh_o;
                                  /* Mask Parameter: div0protectabspoly_thresh_o
                                   * Referenced by:
                                   *   '<S648>/Constant'
                                   *   '<S649>/Constant'
                                   */
  real_T CombinedSlipWheel2DOF_turnslip;
                               /* Mask Parameter: CombinedSlipWheel2DOF_turnslip
                                * Referenced by: '<S513>/Magic Tire Const Input'
                                */
  real_T VehicleBody6DOF_vertOff;     /* Mask Parameter: VehicleBody6DOF_vertOff
                                       * Referenced by: '<S452>/vertOff '
                                       */
  real_T ContLPF_wc;                   /* Mask Parameter: ContLPF_wc
                                        * Referenced by: '<S289>/Constant'
                                        */
  real_T ContLPF2_wc;                  /* Mask Parameter: ContLPF2_wc
                                        * Referenced by: '<S290>/Constant'
                                        */
  real_T ContLPF_wc_f;                 /* Mask Parameter: ContLPF_wc_f
                                        * Referenced by: '<S373>/Constant'
                                        */
  real_T ContLPF1_wc;                  /* Mask Parameter: ContLPF1_wc
                                        * Referenced by: '<S374>/Constant'
                                        */
  real_T Bushings_wc[2];               /* Mask Parameter: Bushings_wc
                                        * Referenced by: '<S392>/Constant'
                                        */
  real_T SecondorderDynamics_wn;       /* Mask Parameter: SecondorderDynamics_wn
                                        * Referenced by:
                                        *   '<S683>/2*zeta * wn'
                                        *   '<S683>/wn^2'
                                        */
  real_T SecondorderDynamics_wn_e;   /* Mask Parameter: SecondorderDynamics_wn_e
                                      * Referenced by:
                                      *   '<S695>/2*zeta * wn'
                                      *   '<S695>/wn^2'
                                      */
  real_T VehicleBody6DOF_xbdot_o[3];  /* Mask Parameter: VehicleBody6DOF_xbdot_o
                                       * Referenced by: '<S406>/ub,vb,wb'
                                       */
  real_T VehicleBody6DOF_xdot_tol;   /* Mask Parameter: VehicleBody6DOF_xdot_tol
                                      * Referenced by:
                                      *   '<S443>/Constant'
                                      *   '<S444>/Constant'
                                      *   '<S479>/Constant'
                                      *   '<S480>/Constant'
                                      */
  real_T VehicleBody6DOF_z1I[9];       /* Mask Parameter: VehicleBody6DOF_z1I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z1R[3];       /* Mask Parameter: VehicleBody6DOF_z1R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z1m;          /* Mask Parameter: VehicleBody6DOF_z1m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2I[9];       /* Mask Parameter: VehicleBody6DOF_z2I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2R[3];       /* Mask Parameter: VehicleBody6DOF_z2R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z2m;          /* Mask Parameter: VehicleBody6DOF_z2m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3I[9];       /* Mask Parameter: VehicleBody6DOF_z3I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3R[3];       /* Mask Parameter: VehicleBody6DOF_z3R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z3m;          /* Mask Parameter: VehicleBody6DOF_z3m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4I[9];       /* Mask Parameter: VehicleBody6DOF_z4I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4R[3];       /* Mask Parameter: VehicleBody6DOF_z4R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z4m;          /* Mask Parameter: VehicleBody6DOF_z4m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5I[9];       /* Mask Parameter: VehicleBody6DOF_z5I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5R[3];       /* Mask Parameter: VehicleBody6DOF_z5R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z5m;          /* Mask Parameter: VehicleBody6DOF_z5m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6I[9];       /* Mask Parameter: VehicleBody6DOF_z6I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6R[3];       /* Mask Parameter: VehicleBody6DOF_z6R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z6m;          /* Mask Parameter: VehicleBody6DOF_z6m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7I[9];       /* Mask Parameter: VehicleBody6DOF_z7I
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7R[3];       /* Mask Parameter: VehicleBody6DOF_z7R
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T VehicleBody6DOF_z7m;          /* Mask Parameter: VehicleBody6DOF_z7m
                                        * Referenced by: '<S391>/vehdyncginert'
                                        */
  real_T CombinedSlipWheel2DOF_zdoto[4];
                                  /* Mask Parameter: CombinedSlipWheel2DOF_zdoto
                                   * Referenced by: '<S520>/Integrator, Second-Order'
                                   */
  real_T SecondorderDynamics_zn;       /* Mask Parameter: SecondorderDynamics_zn
                                        * Referenced by: '<S683>/2*zeta * wn'
                                        */
  real_T SecondorderDynamics_zn_e;   /* Mask Parameter: SecondorderDynamics_zn_e
                                      * Referenced by: '<S695>/2*zeta * wn'
                                      */
  real_T State_Machine_SnsrFltThld;    /* Expression: SnsrFltThld
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -inf
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S59>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S59>/Constant2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S61>/Switch1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S50>/Gain1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S59>/Switch2'
                                        */
  real_T rads_to_rpm_Gain;             /* Expression: 30/pi
                                        * Referenced by: '<S59>/rads_to_rpm'
                                        */
  real_T EffMap_bp01Data[14];          /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S59>/Eff Map'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1/100
                                        * Referenced by: '<S59>/Gain1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S50>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S60>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T rads_to_rpm_Gain_c;           /* Expression: 30/pi
                                        * Referenced by: '<S47>/rads_to_rpm'
                                        */
  real_T MaxEMTrqVsSpd_bp01Data[14];   /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S47>/MaxEMTrqVsSpd'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S46>/Switch'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S69>/Gain'
                                        */
  real_T Switch1_Threshold_h;          /* Expression: 0
                                        * Referenced by: '<S127>/Switch1'
                                        */
  real_T Switch1_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<S214>/Switch1'
                                        */
  real_T MagicTireConstInput_LATERAL_STI;/* Expression: LATERAL_STIFFNESS
                                          * Referenced by: '<S513>/Magic Tire Const Input'
                                          */
  real_T MagicTireConstInput_LONGITUDINA;/* Expression: LONGITUDINAL_STIFFNESS
                                          * Referenced by: '<S513>/Magic Tire Const Input'
                                          */
  real_T MagicTireConstInput_PCFX1;    /* Expression: PCFX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFX2;    /* Expression: PCFX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFX3;    /* Expression: PCFX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY1;    /* Expression: PCFY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY2;    /* Expression: PCFY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCFY3;    /* Expression: PCFY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCX1;     /* Expression: PCX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PCY1;     /* Expression: PCY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX1;     /* Expression: PDX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX2;     /* Expression: PDX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDX3;     /* Expression: PDX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP1;    /* Expression: PDXP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP2;    /* Expression: PDXP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDXP3;    /* Expression: PDXP3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY1;     /* Expression: PDY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY2;     /* Expression: PDY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDY3;     /* Expression: PDY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP1;    /* Expression: PDYP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP2;    /* Expression: PDYP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP3;    /* Expression: PDYP3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PDYP4;    /* Expression: PDYP4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PECP1;    /* Expression: PECP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PECP2;    /* Expression: PECP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX1;     /* Expression: PEX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX2;     /* Expression: PEX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX3;     /* Expression: PEX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEX4;     /* Expression: PEX4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY1;     /* Expression: PEY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY2;     /* Expression: PEY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY3;     /* Expression: PEY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY4;     /* Expression: PEY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PEY5;     /* Expression: PEY5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHX1;     /* Expression: PHX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHX2;     /* Expression: PHX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHY1;     /* Expression: PHY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHY2;     /* Expression: PHY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP1;    /* Expression: PHYP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP2;    /* Expression: PHYP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP3;    /* Expression: PHYP3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PHYP4;    /* Expression: PHYP4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX1;     /* Expression: PKX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX2;     /* Expression: PKX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKX3;     /* Expression: PKX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY1;     /* Expression: PKY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY2;     /* Expression: PKY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY3;     /* Expression: PKY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY4;     /* Expression: PKY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY5;     /* Expression: PKY5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY6;     /* Expression: PKY6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKY7;     /* Expression: PKY7
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PKYP1;    /* Expression: PKYP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPMX1;    /* Expression: PPMX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX1;     /* Expression: PPX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX2;     /* Expression: PPX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX3;     /* Expression: PPX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPX4;     /* Expression: PPX4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY1;     /* Expression: PPY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY2;     /* Expression: PPY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY3;     /* Expression: PPY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY4;     /* Expression: PPY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPY5;     /* Expression: PPY5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPZ1;     /* Expression: PPZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PPZ2;     /* Expression: PPZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVX1;     /* Expression: PVX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVX2;     /* Expression: PVX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY1;     /* Expression: PVY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY2;     /* Expression: PVY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY3;     /* Expression: PVY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_PVY4;     /* Expression: PVY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBRP1;    /* Expression: QBRP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ1;     /* Expression: QBZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ10;    /* Expression: QBZ10
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ2;     /* Expression: QBZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ3;     /* Expression: QBZ3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ4;     /* Expression: QBZ4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ5;     /* Expression: QBZ5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ6;     /* Expression: QBZ6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QBZ9;     /* Expression: QBZ9
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCRP1;    /* Expression: QCRP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCRP2;    /* Expression: QCRP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QCZ1;     /* Expression: QCZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDRP1;    /* Expression: QDRP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDRP2;    /* Expression: QDRP2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDTP1;    /* Expression: QDTP1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ1;     /* Expression: QDZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ10;    /* Expression: QDZ10
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ11;    /* Expression: QDZ11
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ2;     /* Expression: QDZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ3;     /* Expression: QDZ3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ4;     /* Expression: QDZ4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ6;     /* Expression: QDZ6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ7;     /* Expression: QDZ7
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ8;     /* Expression: QDZ8
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QDZ9;     /* Expression: QDZ9
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ1;     /* Expression: QEZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ2;     /* Expression: QEZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ3;     /* Expression: QEZ3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ4;     /* Expression: QEZ4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QEZ5;     /* Expression: QEZ5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ1;     /* Expression: QHZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ2;     /* Expression: QHZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ3;     /* Expression: QHZ3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QHZ4;     /* Expression: QHZ4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX1;     /* Expression: QSX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX10;    /* Expression: QSX10
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX11;    /* Expression: QSX11
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX12;    /* Expression: QSX12
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX13;    /* Expression: QSX13
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX14;    /* Expression: QSX14
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX2;     /* Expression: QSX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX3;     /* Expression: QSX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX4;     /* Expression: QSX4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX5;     /* Expression: QSX5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX6;     /* Expression: QSX6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX7;     /* Expression: QSX7
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX8;     /* Expression: QSX8
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSX9;     /* Expression: QSX9
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY1;     /* Expression: QSY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY2;     /* Expression: QSY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY3;     /* Expression: QSY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY4;     /* Expression: QSY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY5;     /* Expression: QSY5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY6;     /* Expression: QSY6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY7;     /* Expression: QSY7
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_QSY8;     /* Expression: QSY8
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RA1;    /* Expression: Q_RA1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RA2;    /* Expression: Q_RA2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RB1;    /* Expression: Q_RB1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_Q_RB2;    /* Expression: Q_RB2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX1;     /* Expression: RBX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX2;     /* Expression: RBX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBX3;     /* Expression: RBX3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY1;     /* Expression: RBY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY2;     /* Expression: RBY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY3;     /* Expression: RBY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RBY4;     /* Expression: RBY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RCX1;     /* Expression: RCX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RCY1;     /* Expression: RCY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REX1;     /* Expression: REX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REX2;     /* Expression: REX2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REY1;     /* Expression: REY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_REY2;     /* Expression: REY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHX1;     /* Expression: RHX1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHY1;     /* Expression: RHY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RHY2;     /* Expression: RHY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY1;     /* Expression: RVY1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY2;     /* Expression: RVY2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY3;     /* Expression: RVY3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY4;     /* Expression: RVY4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY5;     /* Expression: RVY5
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_RVY6;     /* Expression: RVY6
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ1;     /* Expression: SSZ1
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ2;     /* Expression: SSZ2
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ3;     /* Expression: SSZ3
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_SSZ4;     /* Expression: SSZ4
                                        * Referenced by: '<S513>/Magic Tire Const Input'
                                        */
  real_T MagicTireConstInput_vdynMF[279];/* Expression: vdynMF
                                          * Referenced by: '<S513>/Magic Tire Const Input'
                                          */
  real_T OpenDifferential_shaftSwitchMas;/* Expression: shaftSwitchMask
                                          * Referenced by: '<S552>/Open Differential'
                                          */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S643>/Constant'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S650>/Switch1'
                                        */
  real_T ZeroOrderHold3_Gain;          /* Expression: 1
                                        * Referenced by: '<S676>/Zero-Order Hold3'
                                        */
  real_T ZeroOrderHold_Gain;           /* Expression: 1
                                        * Referenced by: '<S676>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold1_Gain;          /* Expression: 1
                                        * Referenced by: '<S676>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold1_Gain_d;        /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold_Gain_i;         /* Expression: 1
                                        * Referenced by: '<S677>/Zero-Order Hold'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T RateTransition18_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition18'
                                          */
  real_T RateTransition19_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition19'
                                          */
  real_T RateTransition20_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition20'
                                          */
  real_T RateTransition21_InitialConditi;/* Expression: 0
                                          * Referenced by: '<S21>/Rate Transition21'
                                          */
  real_T DeadZone1_Start;              /* Expression: 0
                                        * Referenced by: '<S671>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: .01
                                        * Referenced by: '<S671>/Dead Zone1'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S45>/Switch'
                                        */
  real_T DeadZone2_Start;              /* Expression: 0
                                        * Referenced by: '<S95>/Dead Zone2'
                                        */
  real_T DeadZone2_End;                /* Expression: .01
                                        * Referenced by: '<S95>/Dead Zone2'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Switch_Threshold_au;          /* Expression: 0
                                        * Referenced by: '<S49>/Switch'
                                        */
  real_T rads_to_rpm_Gain_h;           /* Expression: 30/pi
                                        * Referenced by: '<S69>/rads_to_rpm'
                                        */
  real_T MaxMotTrqVsSpd_bp01Data[14];  /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S69>/MaxMotTrqVsSpd'
                                        */
  real_T convert2percent_Gain;         /* Expression: 100
                                        * Referenced by: '<S52>/convert2percent'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T rads_to_rpm_Gain_a;           /* Expression: 30/pi
                                        * Referenced by: '<S60>/rads_to_rpm'
                                        */
  real_T MaxEMTrqVsSpd_bp01Data_k[14]; /* Expression: PlntEM1Spd*30/pi
                                        * Referenced by: '<S60>/MaxEMTrqVsSpd'
                                        */
  real_T Negative5_UpperSat;           /* Expression: inf
                                        * Referenced by: '<S69>/Negative 5'
                                        */
  real_T Negative5_LowerSat;           /* Expression: 0
                                        * Referenced by: '<S69>/Negative 5'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Switch1_Threshold_hp;         /* Expression: 0
                                        * Referenced by: '<S3>/Switch1'
                                        */
  real_T Constant1_Value_k[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S73>/Constant1'
                                        */
  real_T Constant2_Value_p[36];        /* Expression: repmat(eye(3),1,1,4)
                                        * Referenced by: '<S73>/Constant2'
                                        */
  real_T FirstOrderHold_IniOut;        /* Expression: 0
                                        * Referenced by: '<S79>/First Order Hold'
                                        */
  real_T FirstOrderHold_ErrTol;        /* Expression: inf
                                        * Referenced by: '<S79>/First Order Hold'
                                        */
  real_T DeadZone_Start;               /* Expression: -inf
                                        * Referenced by: '<S104>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 1e-3
                                        * Referenced by: '<S104>/Dead Zone'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S105>/Integrator1'
                                        */
  real_T Constant_Value_ba;            /* Expression: 0
                                        * Referenced by: '<S107>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S516>/Integrator'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S517>/Integrator'
                                        */
  real_T Integrator1_IC_b;             /* Expression: 0
                                        * Referenced by: '<S373>/Integrator1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: inf
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -10*9.81*2000
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S579>/Memory'
                                        */
  real_T Memory_InitialCondition_e;    /* Expression: 0
                                        * Referenced by: '<S587>/Memory'
                                        */
  real_T Constant1_Value_ky;           /* Expression: 0
                                        * Referenced by: '<S595>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S595>/Constant3'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S519>/Integrator'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: inf
                                        * Referenced by: '<S520>/Saturation'
                                        */
  real_T Saturation_LowerSat_mx;       /* Expression: 0
                                        * Referenced by: '<S520>/Saturation'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: inf
                                        * Referenced by: '<S515>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: 0
                                        * Referenced by: '<S515>/Saturation'
                                        */
  real_T TorqueConversion1_Gain;       /* Expression: pi/4
                                        * Referenced by: '<S525>/Torque Conversion1'
                                        */
  real_T DisallowNegativeBrakeTorque_Upp;/* Expression: inf
                                          * Referenced by: '<S525>/Disallow Negative Brake Torque'
                                          */
  real_T DisallowNegativeBrakeTorque_Low;/* Expression: eps
                                          * Referenced by: '<S525>/Disallow Negative Brake Torque'
                                          */
  real_T Integrator1_IC_m;             /* Expression: 0
                                        * Referenced by: '<S374>/Integrator1'
                                        */
  real_T Constant3_Value_n[4];         /* Expression: ones(1,4).*0
                                        * Referenced by: '<S376>/Constant3'
                                        */
  real_T SteerRates_Value[4];          /* Expression: zeros(1,4)
                                        * Referenced by: '<S292>/SteerRates'
                                        */
  real_T Constant_Value_bk[4];         /* Expression: zeros(1,4)
                                        * Referenced by: '<S292>/Constant'
                                        */
  real_T ones2_Value[4];               /* Expression: ones(1,numWheels)
                                        * Referenced by: '<S510>/ones2'
                                        */
  real_T u_Value[4];                   /* Expression: [zeros(1,numWheels)]
                                        * Referenced by: '<S510>/0'
                                        */
  real_T ones1_Value[36];              /* Expression: [ones(9,numWheels)]
                                        * Referenced by: '<S510>/ones1'
                                        */
  real_T u_Value_h[4];                 /* Expression: [zeros(1,numWheels)]+1
                                        * Referenced by: '<S510>/2'
                                        */
  real_T ones3_Value[20];              /* Expression: [ones(5,numWheels)]
                                        * Referenced by: '<S510>/ones3'
                                        */
  real_T u_Value_c[8];                 /* Expression: [zeros(2,numWheels)]+1
                                        * Referenced by: '<S510>/1'
                                        */
  real_T ones_Value[24];               /* Expression: [ones(6,numWheels)]
                                        * Referenced by: '<S510>/ones'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S520>/Constant1'
                                        */
  real_T vertType_Value;               /* Expression: vertType
                                        * Referenced by: '<S511>/vertType'
                                        */
  real_T Constant_Value_eb[36];        /* Expression: repmat(eye(3),[1,1,4])
                                        * Referenced by: '<S287>/Constant'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S412>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S412>/phi theta psi'
                                          */
  real_T InertialFrameCGtoAxleOffset_Val[12];
                           /* Expression: [zeros(2,4);PlntVehCGHgtAxl*ones(1,4)]
                            * Referenced by: '<S294>/Inertial Frame CG to Axle Offset'
                            */
  real_T Constant8_Value;              /* Expression: pi/2
                                        * Referenced by: '<S173>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 2
                                        * Referenced by: '<S173>/Constant6'
                                        */
  real_T Constant8_Value_d;            /* Expression: pi/2
                                        * Referenced by: '<S171>/Constant8'
                                        */
  real_T Constant_Value_h;             /* Expression: 2*pi
                                        * Referenced by: '<S157>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX;    /* Expression: 0.0
                                        * Referenced by: '<S157>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT; /* Expression: 0.0
                                        * Referenced by: '<S157>/Integrator, Second-Order'
                                        */
  real_T Constant6_Value_n;            /* Expression: 2
                                        * Referenced by: '<S171>/Constant6'
                                        */
  real_T AckermanFlagConstant_Value;   /* Expression: 0
                                        * Referenced by: '<S157>/AckermanFlagConstant'
                                        */
  real_T Constant8_Value_n;            /* Expression: pi/2
                                        * Referenced by: '<S172>/Constant8'
                                        */
  real_T Constant6_Value_j;            /* Expression: 2
                                        * Referenced by: '<S172>/Constant6'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S157>/Switch'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S157>/Constant1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<S157>/Gain5'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 0
                                        * Referenced by: '<S157>/Switch1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S157>/Switch4'
                                        */
  real_T LocFlagConstant_Value;        /* Expression: 1
                                        * Referenced by: '<S108>/LocFlagConstant'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S110>/Switch'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S157>/Switch5'
                                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S110>/Switch1'
                                        */
  real_T FrontTrack_Value;             /* Expression: w(1)
                                        * Referenced by: '<S296>/Front Track'
                                        */
  real_T Integrator1_IC_g;             /* Expression: 0
                                        * Referenced by: '<S289>/Integrator1'
                                        */
  real_T Integrator1_IC_gh;            /* Expression: 0
                                        * Referenced by: '<S290>/Integrator1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S288>/Gain'
                                        */
  real_T RearTrack_Value;              /* Expression: w(2)
                                        * Referenced by: '<S297>/Rear Track'
                                        */
  real_T SteerInputFlagConstant_Value; /* Expression: 0
                                        * Referenced by: '<S108>/SteerInputFlagConstant'
                                        */
  real_T Backlash_InitialOutput;       /* Expression: 0
                                        * Referenced by: '<S117>/Backlash'
                                        */
  real_T IntegratorSecondOrder_ICX_i;  /* Expression: 0.0
                                        * Referenced by: '<S139>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_l;/* Expression: 0.0
                                         * Referenced by: '<S139>/Integrator, Second-Order'
                                         */
  real_T Integrator_IC_c2;             /* Expression: 0
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 50
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -50
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0
                                        * Referenced by: '<S108>/Switch'
                                        */
  real_T Constant_Value_dn;            /* Expression: 1
                                        * Referenced by: '<S127>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_k;  /* Expression: 0.0
                                        * Referenced by: '<S138>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_a;/* Expression: 0.0
                                         * Referenced by: '<S138>/Integrator, Second-Order'
                                         */
  real_T Integrator1_IC_e;             /* Expression: 0
                                        * Referenced by: '<S126>/Integrator1'
                                        */
  real_T Constant1_Value_fu[2];        /* Expression: [0 0]
                                        * Referenced by: '<S119>/Constant1'
                                        */
  real_T TmpLatchAtTriggeredSubsystemInp;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_f;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S132>/Gain'
                                        */
  real_T Constant2_Value_g[2];         /* Expression: [0 0]
                                        * Referenced by: '<S119>/Constant2'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_m;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_n;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S133>/Gain'
                                        */
  real_T Memory_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S132>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S132>/Memory1'
                                        */
  real_T Memory_InitialCondition_i;    /* Expression: 0
                                        * Referenced by: '<S133>/Memory'
                                        */
  real_T Memory1_InitialCondition_k;   /* Expression: 0
                                        * Referenced by: '<S133>/Memory1'
                                        */
  real_T Constant8_Value_l;            /* Expression: pi/2
                                        * Referenced by: '<S260>/Constant8'
                                        */
  real_T Constant6_Value_c;            /* Expression: 2
                                        * Referenced by: '<S260>/Constant6'
                                        */
  real_T Constant8_Value_g;            /* Expression: pi/2
                                        * Referenced by: '<S258>/Constant8'
                                        */
  real_T Constant_Value_ge;            /* Expression: 2*pi
                                        * Referenced by: '<S244>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_o;  /* Expression: 0.0
                                        * Referenced by: '<S244>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_c;/* Expression: 0.0
                                         * Referenced by: '<S244>/Integrator, Second-Order'
                                         */
  real_T Constant6_Value_nq;           /* Expression: 2
                                        * Referenced by: '<S258>/Constant6'
                                        */
  real_T AckermanFlagConstant_Value_n; /* Expression: 0
                                        * Referenced by: '<S244>/AckermanFlagConstant'
                                        */
  real_T Constant8_Value_nr;           /* Expression: pi/2
                                        * Referenced by: '<S259>/Constant8'
                                        */
  real_T Constant6_Value_l;            /* Expression: 2
                                        * Referenced by: '<S259>/Constant6'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S244>/Switch'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S244>/Constant1'
                                        */
  real_T Gain5_Gain_h;                 /* Expression: 0.01
                                        * Referenced by: '<S244>/Gain5'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S244>/Switch1'
                                        */
  real_T Switch4_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S244>/Switch4'
                                        */
  real_T LocFlagConstant_Value_e;      /* Expression: 0
                                        * Referenced by: '<S109>/LocFlagConstant'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S197>/Switch'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0
                                        * Referenced by: '<S107>/Gain'
                                        */
  real_T Switch5_Threshold_c;          /* Expression: 0
                                        * Referenced by: '<S244>/Switch5'
                                        */
  real_T Switch1_Threshold_m1;         /* Expression: 0
                                        * Referenced by: '<S197>/Switch1'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 0
                                        * Referenced by: '<S107>/Gain1'
                                        */
  real_T SteerInputFlagConstant_Value_j;/* Expression: 0
                                         * Referenced by: '<S109>/SteerInputFlagConstant'
                                         */
  real_T Backlash_InitialOutput_h;     /* Expression: 0
                                        * Referenced by: '<S204>/Backlash'
                                        */
  real_T IntegratorSecondOrder_ICX_c;  /* Expression: 0.0
                                        * Referenced by: '<S226>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_h;/* Expression: 0.0
                                         * Referenced by: '<S226>/Integrator, Second-Order'
                                         */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S218>/Integrator'
                                        */
  real_T Integrator_UpperSat_i;        /* Expression: 50
                                        * Referenced by: '<S218>/Integrator'
                                        */
  real_T Integrator_LowerSat_h;        /* Expression: -50
                                        * Referenced by: '<S218>/Integrator'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S109>/Switch'
                                        */
  real_T Constant_Value_b4;            /* Expression: 1
                                        * Referenced by: '<S214>/Constant'
                                        */
  real_T IntegratorSecondOrder_ICX_n;  /* Expression: 0.0
                                        * Referenced by: '<S225>/Integrator, Second-Order'
                                        */
  real_T IntegratorSecondOrder_ICDXDT_i;/* Expression: 0.0
                                         * Referenced by: '<S225>/Integrator, Second-Order'
                                         */
  real_T Integrator1_IC_gd;            /* Expression: 0
                                        * Referenced by: '<S213>/Integrator1'
                                        */
  real_T Constant1_Value_e[2];         /* Expression: [0 0]
                                        * Referenced by: '<S206>/Constant1'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_e;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystem_fy;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S219>/Gain'
                                        */
  real_T Constant2_Value_e[2];         /* Expression: [0 0]
                                        * Referenced by: '<S206>/Constant2'
                                        */
  real_T TmpLatchAtTriggeredSubsystemI_a;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpLatchAtTriggeredSubsystemI_p;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S220>/Gain'
                                        */
  real_T Memory_InitialCondition_pm;   /* Expression: 0
                                        * Referenced by: '<S219>/Memory'
                                        */
  real_T Memory1_InitialCondition_j;   /* Expression: 0
                                        * Referenced by: '<S219>/Memory1'
                                        */
  real_T Memory_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S220>/Memory'
                                        */
  real_T Memory1_InitialCondition_o;   /* Expression: 0
                                        * Referenced by: '<S220>/Memory1'
                                        */
  real_T Constant1_Value_kj[3];        /* Expression: [0;0;0]
                                        * Referenced by: '<S389>/Constant1'
                                        */
  real_T Integrator1_IC_gq;            /* Expression: 0
                                        * Referenced by: '<S392>/Integrator1'
                                        */
  real_T UnsprungMassessumVEHUnsprungMas;
               /* Expression: sum([PlntVehFrntUnsprgMass PlntVehRearUnsprgMass])
                * Referenced by: '<S390>/Unsprung Masses sum([VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassFrontAxle//2 VEH.UnsprungMassRearAxle//2 VEH.UnsprungMassRearAxle//2])'
                */
  real_T Vertical_Value;               /* Expression: 0
                                        * Referenced by: '<S390>/Vertical'
                                        */
  real_T u_Value_n;                    /* Expression: 0
                                        * Referenced by: '<S408>/0'
                                        */
  real_T u_Gain[3];                    /* Expression: [4.*ones(2,1); 0]
                                        * Referenced by: '<S433>/4'
                                        */
  real_T Constant4_Value[3];           /* Expression: [0; 0; 1]
                                        * Referenced by: '<S433>/Constant4'
                                        */
  real_T Crm_tableData[2];             /* Expression: [0 0]
                                        * Referenced by: '<S433>/Crm'
                                        */
  real_T Crm_bp01Data[2];              /* Expression: [-1 1]
                                        * Referenced by: '<S433>/Crm'
                                        */
  real_T Constant_Value_e3[6];         /* Expression: zeros(6 ,1)
                                        * Referenced by: '<S696>/Constant'
                                        */
  real_T Constant1_Value_m[9];         /* Expression: zeros(3,3)
                                        * Referenced by: '<S399>/Constant1'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S410>/Integrator'
                                        */
  real_T Constant_Value_j[12];         /* Expression: zeros(12,1)
                                        * Referenced by: '<S391>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S516>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 1e-2
                                        * Referenced by: '<S516>/Saturation1'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: inf
                                        * Referenced by: '<S516>/Saturation'
                                        */
  real_T Saturation_LowerSat_mf;       /* Expression: FxRelFreqLwrLim
                                        * Referenced by: '<S516>/Saturation'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: inf
                                        * Referenced by: '<S517>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_f;       /* Expression: 1e-2
                                        * Referenced by: '<S517>/Saturation1'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: inf
                                        * Referenced by: '<S517>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: FyRelFreqLwrLim
                                        * Referenced by: '<S517>/Saturation'
                                        */
  real_T Saturation1_UpperSat_f;       /* Expression: inf
                                        * Referenced by: '<S519>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: 1e-2
                                        * Referenced by: '<S519>/Saturation1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S519>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: MyRelFreqLwrLim
                                        * Referenced by: '<S519>/Saturation'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S520>/Constant'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S520>/Switch'
                                        */
  real_T Memory_InitialCondition_f;    /* Expression: 0
                                        * Referenced by: '<S601>/Memory'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S556>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: shaftSwitchMask
                                        * Referenced by: '<S556>/Constant'
                                        */
  real_T Switch_Threshold_ao;          /* Expression: 1
                                        * Referenced by: '<S556>/Switch'
                                        */
  real_T Integrator_UpperSat_k;        /* Expression: maxAbsSpd
                                        * Referenced by: '<S552>/Integrator'
                                        */
  real_T Integrator_LowerSat_j;        /* Expression: -maxAbsSpd
                                        * Referenced by: '<S552>/Integrator'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1/2
                                        * Referenced by: '<S556>/Gain1'
                                        */
  real_T Constant_Value_fl;            /* Expression: 1
                                        * Referenced by: '<S566>/Constant'
                                        */
  real_T Switch_Threshold_i2;          /* Expression: 0
                                        * Referenced by: '<S566>/Switch'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 20
                                        * Referenced by: '<S573>/Gain1'
                                        */
  real_T Constant1_Value_lx;           /* Expression: 1
                                        * Referenced by: '<S573>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4
                                        * Referenced by: '<S573>/Gain2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: .5
                                        * Referenced by: '<S573>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S572>/Constant'
                                        */
  real_T Constant_Value_fq;            /* Expression: 1
                                        * Referenced by: '<S564>/Constant'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S564>/Switch'
                                        */
  real_T Gain1_Gain_a2;                /* Expression: 20
                                        * Referenced by: '<S569>/Gain1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S569>/Constant1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 4
                                        * Referenced by: '<S569>/Gain2'
                                        */
  real_T Gain_Gain_ja;                 /* Expression: .5
                                        * Referenced by: '<S569>/Gain'
                                        */
  real_T Constant_Value_lo;            /* Expression: 1
                                        * Referenced by: '<S568>/Constant'
                                        */
  real_T Constant_Value_f4;            /* Expression: 1
                                        * Referenced by: '<S565>/Constant'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0
                                        * Referenced by: '<S565>/Switch'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 20
                                        * Referenced by: '<S571>/Gain1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S571>/Constant1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 4
                                        * Referenced by: '<S571>/Gain2'
                                        */
  real_T Gain_Gain_lj;                 /* Expression: .5
                                        * Referenced by: '<S571>/Gain'
                                        */
  real_T Constant_Value_bf;            /* Expression: 1
                                        * Referenced by: '<S570>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: shaftSwitchMask
                                        * Referenced by: '<S559>/Constant'
                                        */
  real_T Constant6_Value_cd;           /* Expression: 1
                                        * Referenced by: '<S559>/Constant6'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 1
                                        * Referenced by: '<S559>/Switch1'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<S579>/Reset'
                                        */
  real_T Reset_Value_l;                /* Expression: 1
                                        * Referenced by: '<S587>/Reset'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S599>/Constant1'
                                        */
  real_T Constant2_Value_p2;           /* Expression: 0
                                        * Referenced by: '<S599>/Constant2'
                                        */
  real_T Constant_Value_d5;            /* Expression: 1
                                        * Referenced by: '<S620>/Constant'
                                        */
  real_T Constant1_Value_em;           /* Expression: 0
                                        * Referenced by: '<S620>/Constant1'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S620>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S620>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S620>/Constant12'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S620>/Constant2'
                                        */
  real_T Constant3_Value_h;            /* Expression: 0
                                        * Referenced by: '<S620>/Constant3'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S620>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S620>/Constant5'
                                        */
  real_T Constant6_Value_d;            /* Expression: 0
                                        * Referenced by: '<S620>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S620>/Constant7'
                                        */
  real_T Constant8_Value_e;            /* Expression: 0
                                        * Referenced by: '<S620>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S620>/Constant9'
                                        */
  real_T Reset_Value_e;                /* Expression: 1
                                        * Referenced by: '<S601>/Reset'
                                        */
  real_T MotorCouplingDynamics_A; /* Computed Parameter: MotorCouplingDynamics_A
                                   * Referenced by: '<S657>/Motor Coupling Dynamics'
                                   */
  real_T MotorCouplingDynamics_C; /* Computed Parameter: MotorCouplingDynamics_C
                                   * Referenced by: '<S657>/Motor Coupling Dynamics'
                                   */
  real_T MaxTorqueLimit_tableData[27]; /* Expression: T_t_extended
                                        * Referenced by: '<S665>/Max Torque Limit'
                                        */
  real_T MaxTorqueLimit_bp01Data[27];  /* Expression: w_t_extended
                                        * Referenced by: '<S665>/Max Torque Limit'
                                        */
  real_T Integrator_IC_i;              /* Expression: 0
                                        * Referenced by: '<S665>/Integrator'
                                        */
  real_T Interpolatedzerocrossing_tableD[2];/* Expression: [-1 1]
                                             * Referenced by: '<S665>/Interpolated zero-crossing'
                                             */
  real_T Interpolatedzerocrossing_bp01Da[2];/* Expression: [-1 1]
                                             * Referenced by: '<S665>/Interpolated zero-crossing'
                                             */
  real_T uDLookupTable_tableData[567]; /* Expression: x_losses_mat
                                        * Referenced by: '<S664>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[27];   /* Expression: x_w_eff_vec
                                        * Referenced by: '<S664>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp02Data[21];   /* Expression: x_T_eff_vec
                                        * Referenced by: '<S664>/2-D Lookup Table'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: Inf
                                        * Referenced by: '<S662>/Saturation'
                                        */
  real_T Saturation_LowerSat_d3;       /* Expression: 0.0001
                                        * Referenced by: '<S662>/Saturation'
                                        */
  real_T Constant1_Value_b;            /* Expression: 100
                                        * Referenced by: '<S645>/Constant1'
                                        */
  real_T Constant2_Value_n1;           /* Expression: 100
                                        * Referenced by: '<S645>/Constant2'
                                        */
  real_T Switch_Threshold_g2;          /* Expression: 0
                                        * Referenced by: '<S645>/Switch'
                                        */
  real_T Constant_Value_cg;            /* Expression: 1
                                        * Referenced by: '<S650>/Constant'
                                        */
  real_T IntegratorLimited_LowerSat;   /* Expression: 0
                                        * Referenced by: '<S632>/Integrator Limited'
                                        */
  real_T SOCRatioto_Gain;              /* Expression: 100
                                        * Referenced by: '<S625>/SOC Ratio to %'
                                        */
  real_T Constant1_Value_l1;           /* Expression: 0
                                        * Referenced by: '<S627>/Constant1'
                                        */
  real_T Constant1_Value_lb;           /* Expression: 273.15
                                        * Referenced by: '<S639>/Constant1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S627>/Gain2'
                                        */
  real_T Gain1_Gain_a3[96];            /* Expression: ones(PlntBattNumCellSer,1)
                                        * Referenced by: '<S627>/Gain1'
                                        */
  real_T Switch_Threshold_kz;          /* Expression: 0
                                        * Referenced by: '<S643>/Switch'
                                        */
  real_T Constant_Value_kc;            /* Expression: 0
                                        * Referenced by: '<S621>/Constant'
                                        */
  real_T Constant1_Value_en;           /* Expression: 0
                                        * Referenced by: '<S621>/Constant1'
                                        */
  real_T Constant2_Value_n13;          /* Expression: 0
                                        * Referenced by: '<S621>/Constant2'
                                        */
  real_T Afr_Value;                    /* Expression: 0
                                        * Referenced by: '<S670>/Afr'
                                        */
  real_T Bsfc_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Bsfc'
                                        */
  real_T ClsdLpFuelMult_Value;         /* Expression: 1
                                        * Referenced by: '<S670>/ClsdLpFuelMult'
                                        */
  real_T CrkAng_Value;                 /* Expression: 0
                                        * Referenced by: '<S670>/CrkAng'
                                        */
  real_T CylPrs_Value;                 /* Expression: 0
                                        * Referenced by: '<S670>/CylPrs'
                                        */
  real_T EgrVlvAreaPct_Value;          /* Expression: 0
                                        * Referenced by: '<S670>/EgrVlvAreaPct'
                                        */
  real_T EngSpd_Value;                 /* Expression: 0
                                        * Referenced by: '<S670>/EngSpd'
                                        */
  real_T EngTrq_Value;                 /* Expression: 0
                                        * Referenced by: '<S670>/EngTrq'
                                        */
  real_T EngTrqCrk_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/EngTrqCrk'
                                        */
  real_T ExhCamPhase_Value;            /* Expression: 0
                                        * Referenced by: '<S670>/ExhCamPhase'
                                        */
  real_T ExhManGasTemp_Value;          /* Expression: 0
                                        * Referenced by: '<S670>/ExhManGasTemp'
                                        */
  real_T FuelMassFlw_Value;            /* Expression: 0
                                        * Referenced by: '<S670>/FuelMassFlw'
                                        */
  real_T FuelVolFlw_Value;             /* Expression: 0
                                        * Referenced by: '<S670>/FuelVolFlw'
                                        */
  real_T IntkCamPhase_Value;           /* Expression: 0
                                        * Referenced by: '<S670>/IntkCamPhase'
                                        */
  real_T IntkGasMassFlw_Value;         /* Expression: 0
                                        * Referenced by: '<S670>/IntkGasMassFlw'
                                        */
  real_T IntkSwirlVlvPos_Value;        /* Expression: 0
                                        * Referenced by: '<S670>/IntkSwirlVlvPos'
                                        */
  real_T IntkVlvLift_Value;            /* Expression: 0
                                        * Referenced by: '<S670>/IntkVlvLift'
                                        */
  real_T Map_Value;                    /* Expression: 0
                                        * Referenced by: '<S670>/Map'
                                        */
  real_T Map1_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map1'
                                        */
  real_T Map2_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map2'
                                        */
  real_T Map3_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map3'
                                        */
  real_T Map4_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map4'
                                        */
  real_T Map5_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map5'
                                        */
  real_T Map6_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Map6'
                                        */
  real_T Mat_Value;                    /* Expression: 0
                                        * Referenced by: '<S670>/Mat'
                                        */
  real_T Mat1_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Mat1'
                                        */
  real_T Mat2_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Mat2'
                                        */
  real_T Mat3_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/Mat3'
                                        */
  real_T NrmlzdAirChrg_Value;          /* Expression: 0
                                        * Referenced by: '<S670>/NrmlzdAirChrg'
                                        */
  real_T TPCO_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/TPCO'
                                        */
  real_T TPCO2_Value;                  /* Expression: 0
                                        * Referenced by: '<S670>/TPCO2'
                                        */
  real_T TPHC_Value;                   /* Expression: 0
                                        * Referenced by: '<S670>/TPHC'
                                        */
  real_T TPNOx_Value;                  /* Expression: 0
                                        * Referenced by: '<S670>/TPNOx'
                                        */
  real_T ThrPosPct_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/ThrPosPct'
                                        */
  real_T TurboRackPos_Value;           /* Expression: 0
                                        * Referenced by: '<S670>/TurboRackPos'
                                        */
  real_T TurboSpd_Value;               /* Expression: 0
                                        * Referenced by: '<S670>/TurboSpd'
                                        */
  real_T TurboSpd1_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/TurboSpd1'
                                        */
  real_T TurboSpd2_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/TurboSpd2'
                                        */
  real_T TurboSpd3_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/TurboSpd3'
                                        */
  real_T VarCompRatioPos_Value;        /* Expression: 0
                                        * Referenced by: '<S670>/VarCompRatioPos'
                                        */
  real_T VarIntkRunLen_Value;          /* Expression: 0
                                        * Referenced by: '<S670>/VarIntkRunLen'
                                        */
  real_T WgAreaPct_Value;              /* Expression: 0
                                        * Referenced by: '<S670>/WgAreaPct'
                                        */
  real_T DeadZone3_Start;              /* Expression: -.01
                                        * Referenced by: '<S95>/Dead Zone3'
                                        */
  real_T DeadZone3_End;                /* Expression: .01
                                        * Referenced by: '<S95>/Dead Zone3'
                                        */
  real_T Constant_Value_ha[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S673>/Constant'
                                        */
  real_T Constant1_Value_kq[3];        /* Expression: [0,0,9.81]
                                        * Referenced by: '<S673>/Constant1'
                                        */
  real_T u_Value_g[3];                 /* Expression: zeros(3,1)
                                        * Referenced by: '<S678>/0'
                                        */
  real_T Constant_Value_k1;            /* Expression: dtype_a
                                        * Referenced by: '<S678>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited_IC;/* Expression: 0
                                          * Referenced by: '<S683>/Integrator, Second-Order Limited'
                                          */
  real_T IntegratorSecondOrderLimited__m;/* Expression: 0
                                          * Referenced by: '<S683>/Integrator, Second-Order Limited'
                                          */
  real_T ZeroOrderHold2_Gain;          /* Expression: 1
                                        * Referenced by: '<S676>/Zero-Order Hold2'
                                        */
  real_T ZeroOrderHold4_Gain;          /* Expression: 1
                                        * Referenced by: '<S676>/Zero-Order Hold4'
                                        */
  real_T Gain_Gain_ij[3];              /* Expression: [1 -1 1]
                                        * Referenced by: '<S676>/Gain'
                                        */
  real_T Switch1_Threshold_a;          /* Expression: 0.5
                                        * Referenced by: '<S678>/Switch1'
                                        */
  real_T u_Value_h2[3];                /* Expression: zeros(3,1)
                                        * Referenced by: '<S692>/0'
                                        */
  real_T Constant_Value_bj;            /* Expression: dtype_g
                                        * Referenced by: '<S692>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited__o;/* Expression: 0
                                          * Referenced by: '<S695>/Integrator, Second-Order Limited'
                                          */
  real_T IntegratorSecondOrderLimited__e;/* Expression: 0
                                          * Referenced by: '<S695>/Integrator, Second-Order Limited'
                                          */
  real_T Switch1_Threshold_ds;         /* Expression: 0.5
                                        * Referenced by: '<S692>/Switch1'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S696>/Constant15'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant1'
                                        */
  real_T Constant10_Value_b;           /* Expression: 0
                                        * Referenced by: '<S696>/Constant10'
                                        */
  real_T Constant11_Value_i;           /* Expression: 0
                                        * Referenced by: '<S696>/Constant11'
                                        */
  real_T Constant12_Value_c;           /* Expression: 0
                                        * Referenced by: '<S696>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S696>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S696>/Constant14'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant2'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant3'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant4'
                                        */
  real_T Constant5_Value_a;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant5'
                                        */
  real_T Constant6_Value_nc;           /* Expression: 0
                                        * Referenced by: '<S696>/Constant6'
                                        */
  real_T Constant7_Value_i;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant7'
                                        */
  real_T Constant8_Value_b;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant8'
                                        */
  real_T Constant9_Value_p;            /* Expression: 0
                                        * Referenced by: '<S696>/Constant9'
                                        */
  real32_T Balancing_TargetDeltaV;     /* Expression: TargetDeltaV
                                        * Referenced by: '<S26>/Balancing'
                                        */
  real32_T State_Machine_CV_Gain;      /* Expression: CV_Gain
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_HighTempLimit;/* Expression: HighTempLimit
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_I_cc;         /* Expression: I_cc
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_LowTempLimit; /* Expression: LowTempLimit
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_MaxCellVoltThrsld;/* Expression: MaxCellVoltThrsld
                                            * Referenced by: '<S30>/State_Machine'
                                            */
  real32_T State_Machine_OverCellVoltageLi;/* Expression: OverCellVoltageLimit
                                            * Referenced by: '<S30>/State_Machine'
                                            */
  real32_T State_Machine_UnderCellVoltageL;/* Expression: UnderCellVoltageLimit
                                            * Referenced by: '<S30>/State_Machine'
                                            */
  real32_T State_Machine_currentFactor;/* Expression: currentFactor
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_noCurrent;    /* Expression: noCurrent
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_vRatio;       /* Expression: vRatio
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T State_Machine_voltThreshold;/* Expression: voltThreshold
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  real32_T Constant_Value_c2;          /* Computed Parameter: Constant_Value_c2
                                        * Referenced by: '<S25>/Constant'
                                        */
  real32_T UnitDelay_1_InitialCondition[96];
                                    /* Expression: InitialCondition.CellVoltages
                                     * Referenced by: '<S25>/Unit Delay'
                                     */
  real32_T MinCellVoltDchrgCurrentLim_tabl[3];
                            /* Expression: MinCellVoltDchrgCurrentLimTable.Table
                             * Referenced by: '<S34>/MinCellVoltDchrgCurrentLim'
                             */
  real32_T MinCellVoltDchrgCurrentLim_bp01[3];
                   /* Expression: MinCellVoltDchrgCurrentLimTable.Breakpoints(0)
                    * Referenced by: '<S34>/MinCellVoltDchrgCurrentLim'
                    */
  real32_T UnitDelay_4_InitialCondition[96];
                                /* Expression: InitialCondition.CellTemperatures
                                 * Referenced by: '<S25>/Unit Delay'
                                 */
  real32_T LowTempDchrgCurrentLim_tableDat[7];
                          /* Expression: single([0,  0.2, 0.3, 0.5, 0.75, 1, 1])
                           * Referenced by: '<S34>/LowTempDchrgCurrentLim'
                           */
  real32_T LowTempDchrgCurrentLim_bp01Data[7];
                         /* Expression: single([-10, -5,    0,   5, 10, 15, 20])
                          * Referenced by: '<S34>/LowTempDchrgCurrentLim'
                          */
  real32_T HighTempDchrgCurrentLim_tableDa[4];/* Expression: single([1, 0.5, 0.3, 0])
                                               * Referenced by: '<S34>/HighTempDchrgCurrentLim'
                                               */
  real32_T HighTempDchrgCurrentLim_bp01Dat[4];/* Expression: single([40, 45, 50, 60])
                                               * Referenced by: '<S34>/HighTempDchrgCurrentLim'
                                               */
  real32_T MaxDchrgCurrLim_Gain;       /* Expression: MaxDchrgCurrLim
                                        * Referenced by: '<S34>/MaxDchrgCurrLim'
                                        */
  real32_T MaxCellVoltChrgCurrentLim_table[4];/* Expression: single([1.0 0.8 0.3  0.3])
                                               * Referenced by: '<S33>/MaxCellVoltChrgCurrentLim'
                                               */
  real32_T MaxCellVoltChrgCurrentLim_bp01D[4];/* Expression: single([3.9 4.0 4.15 4.2])
                                               * Referenced by: '<S33>/MaxCellVoltChrgCurrentLim'
                                               */
  real32_T LowTempChrgCurrentLim_tableData[7];
                           /* Expression: single([0.1 0.2  0.3 0.3 0.5 1.0 1.0])
                            * Referenced by: '<S33>/LowTempChrgCurrentLim'
                            */
  real32_T LowTempChrgCurrentLim_bp01Data[7];
                           /* Expression: single([-15 -10 -5.0 0.0 5.0 10 15.0])
                            * Referenced by: '<S33>/LowTempChrgCurrentLim'
                            */
  real32_T HighTempChrgCurrentLim_tableDat[5];
                                      /* Expression: single([1.0 0.8 0.5 0.3 0])
                                       * Referenced by: '<S33>/HighTempChrgCurrentLim'
                                       */
  real32_T HighTempChrgCurrentLim_bp01Data[5];
                                      /* Expression: single([40  45  50  55 60])
                                       * Referenced by: '<S33>/HighTempChrgCurrentLim'
                                       */
  real32_T MaxChrgCurrLim_Gain;        /* Expression: MaxChrgCurrLim
                                        * Referenced by: '<S33>/MaxChrgCurrLim'
                                        */
  real32_T UnitDelay_2_InitialCondition;
                                     /* Expression: InitialCondition.PackVoltage
                                      * Referenced by: '<S25>/Unit Delay'
                                      */
  real32_T UnitDelay_5_InitialCondition;/* Expression: InitialCondition.VoutChgr
                                         * Referenced by: '<S25>/Unit Delay'
                                         */
  real32_T UnitDelay_6_InitialCondition;/* Expression: InitialCondition.VoutInvtr
                                         * Referenced by: '<S25>/Unit Delay'
                                         */
  real32_T UnitDelay_3_InitialCondition;
                                     /* Expression: InitialCondition.PackCurrent
                                      * Referenced by: '<S25>/Unit Delay'
                                      */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S37>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S37>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S37>/Discrete-Time Integrator'
                           */
  real32_T Gain_Gain_em;               /* Expression: single(1/3600)
                                        * Referenced by: '<S37>/Gain'
                                        */
  uint32_T EffMap_maxIndex[2];         /* Computed Parameter: EffMap_maxIndex
                                        * Referenced by: '<S59>/Eff Map'
                                        */
  uint32_T TrqAssistTbl_maxIndex[2];/* Computed Parameter: TrqAssistTbl_maxIndex
                                     * Referenced by: '<S125>/TrqAssistTbl'
                                     */
  uint32_T TrqAssistTbl_maxIndex_c[2];
                                  /* Computed Parameter: TrqAssistTbl_maxIndex_c
                                   * Referenced by: '<S212>/TrqAssistTbl'
                                   */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S664>/2-D Lookup Table'
                                    */
  uint32_T R_maxIndex[2];              /* Computed Parameter: R_maxIndex
                                        * Referenced by: '<S634>/R'
                                        */
  int16_T Balancing_BalNotActWait;     /* Expression: BalNotActWait
                                        * Referenced by: '<S26>/Balancing'
                                        */
  int16_T Balancing_BalOffWait;        /* Expression: BalOffWait
                                        * Referenced by: '<S26>/Balancing'
                                        */
  int16_T Balancing_BalOnWait;         /* Expression: BalOnWait
                                        * Referenced by: '<S26>/Balancing'
                                        */
  uint16_T State_Machine_contactorTime;/* Expression: contactorTime
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  boolean_T Balancing_flgEnBalancing;  /* Expression: flgEnBalancing
                                        * Referenced by: '<S26>/Balancing'
                                        */
  uint8_T State_Machine_timeoutContactor;/* Expression: timeoutContactor
                                          * Referenced by: '<S30>/State_Machine'
                                          */
  uint8_T State_Machine_timeoutCurrent;/* Expression: timeoutCurrent
                                        * Referenced by: '<S30>/State_Machine'
                                        */
  P_CoreSubsys_AdasPlantMode_gp_T CoreSubsys_k;
                                    /* '<S522>/Clutch Partitioned Parameters' */
  P_CoreSubsys_AdasPlantModel_l_T CoreSubsys_b;/* '<S434>/Unwrap' */
  P_CoreSubsys_AdasPlantMode_gm_T CoreSubsys_pn;/* '<S287>/Wheel to Body Transform' */
  P_CoreSubsys_AdasPlantModel_g_T CoreSubsys_p;/* '<S375>/Wheel to Body Transform' */
  P_CoreSubsys_AdasPlantModel_o_T CoreSubsys;
  /* '<S291>/For each track and axle combination calculate suspension forces and moments' */
  P_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_e;/* '<S220>/Triggered Subsystem' */
  P_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_l;/* '<S220>/Enabled Subsystem1' */
  P_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_o;/* '<S220>/Enabled Subsystem' */
  P_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_f;/* '<S219>/Triggered Subsystem' */
  P_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_c;/* '<S219>/Enabled Subsystem1' */
  P_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_l;/* '<S219>/Enabled Subsystem' */
  P_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem_d;/* '<S133>/Triggered Subsystem' */
  P_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  P_EnabledSubsystem_AdasPlantM_T EnabledSubsystem_i;/* '<S133>/Enabled Subsystem' */
  P_TriggeredSubsystem_AdasPlan_T TriggeredSubsystem;/* '<S132>/Triggered Subsystem' */
  P_EnabledSubsystem1_AdasPlant_T EnabledSubsystem1;/* '<S132>/Enabled Subsystem1' */
  P_EnabledSubsystem_AdasPlantM_T EnabledSubsystem;/* '<S132>/Enabled Subsystem' */
};

#endif                                 /* RTW_HEADER_AdasPlantModel_h_ */
