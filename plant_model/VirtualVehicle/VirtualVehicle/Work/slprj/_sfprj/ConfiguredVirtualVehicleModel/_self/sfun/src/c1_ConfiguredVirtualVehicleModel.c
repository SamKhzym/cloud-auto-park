/* Include files */

#include "ConfiguredVirtualVehicleModel_sfun.h"
#include "c1_ConfiguredVirtualVehicleModel.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_NO_ACTIVE_LEAF           ((uint8_T)0U)
#define c1_IN_BalancingOFF             (1U)
#define c1_IN_BalancingON              (2U)
#define c1_IN_BalActive                (1U)
#define c1_IN_BalNotActive             (2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRTEInfo c1_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/mnt/data/Data/software/matlab/2023a-linux/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

/* Function Declarations */
static void initialize_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void initialize_params_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void mdl_start_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void mdl_terminate_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void enable_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void disable_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_set_sim_state_side_effects_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void sf_gateway_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void ext_mode_exec_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void set_sim_state_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void initSimStructsc1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void initSubchartIOPointersc1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_enter_atomic_BalActive
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static const mxArray *c1_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static const mxArray *c1_b_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static const mxArray *c1_c_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_emlrt_marshallIn(SFc1_ConfiguredVirtualVehicleModelInstanceStruct
  *chartInstance, const mxArray *c1_b_BalCmd, const char_T *c1_identifier,
  boolean_T c1_y[96]);
static void c1_b_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[96]);
static real32_T c1_c_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_DeltaCellVolt, const char_T *c1_identifier);
static real32_T c1_d_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static boolean_T c1_e_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_flgBalCompl, const char_T *c1_identifier);
static boolean_T c1_f_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_g_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_ConfiguredVirtualVehicleModel, const char_T
   *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_i_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_is_c1_ConfiguredVirtualVehicleModel, const char_T
   *c1_identifier);
static uint32_T c1_j_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint16_T c1_k_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_temporalCounter_i1, const char_T *c1_identifier);
static uint16_T c1_l_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_m_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier, boolean_T
   c1_y[1]);
static void c1_n_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[1]);
static const mxArray *c1_o_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_p_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_init_sf_message_store_memory
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void c1_chart_data_browse_helper
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, int32_T
   c1_ssIdNumber, const mxArray **c1_mxData, uint8_T *c1_isValueTooBig);
static void init_test_point_addr_map
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void **get_test_point_address_map
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void init_dsm_address_info
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  int32_T c1_i;
  int32_T c1_i1;
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_active_c1_ConfiguredVirtualVehicleModel = 0U;
  chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_flgBalCompl = false;
  chartInstance->c1_DeltaCellVolt = 0.0F;
  if (sf_get_output_port_reusable(chartInstance->S, 1) == 0) {
    for (c1_i = 0; c1_i < 96; c1_i++) {
      (*chartInstance->c1_BalCmd)[c1_i] = false;
    }
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                    chartInstance->c1_flgBalCompl);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                    chartInstance->c1_DeltaCellVolt);
  for (c1_i1 = 0; c1_i1 < 96; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)
                      (*chartInstance->c1_BalCmd)[c1_i1]);
  }
}

static void initialize_params_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  real_T c1_d6;
  real_T c1_d7;
  int16_T c1_i;
  int16_T c1_i1;
  int16_T c1_i2;
  sf_mex_import_named("TargetDeltaV", sf_mex_get_sfun_param(chartInstance->S, 3U,
    0U), &c1_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_TargetDeltaV = (real32_T)c1_d;
  sf_mex_import_named("BalNotActWait", sf_mex_get_sfun_param(chartInstance->S,
    0U, 0U), &c1_d1, 0, 0, 0U, 0, 0U, 0);
  c1_d2 = c1_d1;
  if (c1_d2 < 32768.0) {
    if (c1_d2 >= -32768.0) {
      c1_i = (int16_T)c1_d2;
    } else {
      c1_i = MIN_int16_T;
    }
  } else if (c1_d2 >= 32768.0) {
    c1_i = MAX_int16_T;
  } else {
    c1_i = 0;
  }

  chartInstance->c1_BalNotActWait = c1_i;
  sf_mex_import_named("BalOffWait", sf_mex_get_sfun_param(chartInstance->S, 1U,
    0U), &c1_d3, 0, 0, 0U, 0, 0U, 0);
  c1_d4 = c1_d3;
  if (c1_d4 < 32768.0) {
    if (c1_d4 >= -32768.0) {
      c1_i1 = (int16_T)c1_d4;
    } else {
      c1_i1 = MIN_int16_T;
    }
  } else if (c1_d4 >= 32768.0) {
    c1_i1 = MAX_int16_T;
  } else {
    c1_i1 = 0;
  }

  chartInstance->c1_BalOffWait = c1_i1;
  sf_mex_import_named("BalOnWait", sf_mex_get_sfun_param(chartInstance->S, 2U,
    0U), &c1_d5, 0, 0, 0U, 0, 0U, 0);
  c1_d6 = c1_d5;
  if (c1_d6 < 32768.0) {
    if (c1_d6 >= -32768.0) {
      c1_i2 = (int16_T)c1_d6;
    } else {
      c1_i2 = MIN_int16_T;
    }
  } else if (c1_d6 >= 32768.0) {
    c1_i2 = MAX_int16_T;
  } else {
    c1_i2 = 0;
  }

  chartInstance->c1_BalOnWait = c1_i2;
  sf_mex_import_named("flgEnBalancing", sf_mex_get_sfun_param(chartInstance->S,
    4U, 0U), &c1_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_flgEnBalancing = (c1_d7 != 0.0);
}

static void mdl_start_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  static const int32_T c1_b_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c1_b_condTxtEndIdx[4] = { 15, 37, 66, 102 };

  static const int32_T c1_b_condTxtStartIdx[4] = { 1, 23, 45, 74 };

  static const int32_T c1_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_condTxtEndIdx[2] = { 25, 61 };

  static const int32_T c1_condTxtStartIdx[2] = { 1, 33 };

  static const uint32_T c1_b_decisionTxtEndIdx = 0U;
  static const uint32_T c1_b_decisionTxtStartIdx = 0U;
  static const uint32_T c1_c_decisionTxtEndIdx = 0U;
  static const uint32_T c1_c_decisionTxtStartIdx = 0U;
  static const uint32_T c1_d_decisionTxtEndIdx = 0U;
  static const uint32_T c1_d_decisionTxtStartIdx = 0U;
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sfListenerRegisterHover(chartInstance->c1_RuntimeVar, (void *)
    &sf_c1_ConfiguredVirtualVehicleModel_getDebuggerHoverDataFor);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 4U, 0U, 7U,
    76U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 2U, true, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 1U, 2U, true, true, false,
                    0U, &c1_b_decisionTxtStartIdx, &c1_b_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 2U, 0U, false, false, false,
                    0U, &c1_c_decisionTxtStartIdx, &c1_c_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 3U, 0U, false, false, false,
                    0U, &c1_d_decisionTxtStartIdx, &c1_d_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 1U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 5U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 2U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 3U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 4U, 0, NULL, NULL, 0U, NULL);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 6U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 1U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 2U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 4U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 2U, 1U);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 5U, 4U, 0U, 1, 61, -1, 61,
                    false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 5U, 4U, 0U, 1, 61, 2U, 0U,
                      c1_condTxtStartIdx, c1_condTxtEndIdx, 3U,
                      c1_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 5U, 4U, 0U, 33, 61,
    -3, 4U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 6U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 5U, 6U, 0U, 1, 12, -1, 12,
                    false);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 0U, 0U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 1U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 4U, 1U);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 5U, 1U, 0U, 1, 102, -1, 102,
                    false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 5U, 1U, 0U, 1, 102, 4U,
                      0U, c1_b_condTxtStartIdx, c1_b_condTxtEndIdx, 7U,
                      c1_b_postfixPredicateTree, false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 5U, 1U, 0U, 23, 37,
    -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 5U, 1U, 1U, 74, 102,
    -3, 4U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 5U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 5U, 5U, 0U, 1, 15, -1, 15,
                    false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 5U, 5U, 0U, 1, 15,
    -1, 0U);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 5U, 2U, 0U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 5U, 2U, 0U, 1, 21, -1, 21,
                    false);
}

static void mdl_cleanup_runtime_resources_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_set_sim_state_side_effects_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if ((chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel ==
         c1_IN_BalancingOFF) && (sf_mex_sub
         (chartInstance->c1_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 2) == 0.0)) {
      chartInstance->c1_temporalCounter_i1 = 0U;
    }

    if ((chartInstance->c1_is_BalancingON == c1_IN_BalNotActive) && (sf_mex_sub
         (chartInstance->c1_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 5) == 0.0)) {
      chartInstance->c1_temporalCounter_i1 = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void sf_gateway_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  real_T c1_b_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_k;
  real32_T c1_b_x;
  real32_T c1_x;
  real32_T c1_z;
  boolean_T c1_c_x[96];
  boolean_T c1_x_data[96];
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  boolean_T c1_out;
  c1_set_sim_state_side_effects_c1_ConfiguredVirtualVehicleModel(chartInstance);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_JITTransitionAnimation[1] = 0U;
  chartInstance->c1_JITTransitionAnimation[2] = 0U;
  chartInstance->c1_JITTransitionAnimation[3] = 0U;
  chartInstance->c1_JITTransitionAnimation[4] = 0U;
  chartInstance->c1_JITTransitionAnimation[5] = 0U;
  chartInstance->c1_JITTransitionAnimation[6] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_temporalCounter_i1 < 8191U) {
    chartInstance->c1_temporalCounter_i1 = (uint16_T)((uint32_T)
      chartInstance->c1_temporalCounter_i1 + 1U);
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 5U, (real_T)
                    *chartInstance->c1_MinCellVolt);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U, (real_T)
                    *chartInstance->c1_MaxCellVolt);
  for (c1_i = 0; c1_i < 96; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, (real_T)
                      (*chartInstance->c1_CellVoltages)[c1_i]);
  }

  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U, (real_T)
                    *chartInstance->c1_BMS_State);
  chartInstance->c1_sfEvent = CALL_EVENT;
  if (chartInstance->c1_is_active_c1_ConfiguredVirtualVehicleModel == 0U) {
    chartInstance->c1_is_active_c1_ConfiguredVirtualVehicleModel = 1U;
    chartInstance->c1_JITTransitionAnimation[0U] = 1U;
    chartInstance->c1_flgBalCompl = true;
    chartInstance->c1_dataWrittenToVector[0U] = true;
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      chartInstance->c1_flgBalCompl);
    chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel = c1_IN_BalancingOFF;
    chartInstance->c1_temporalCounter_i1 = 0U;
    for (c1_i1 = 0; c1_i1 < 96; c1_i1++) {
      (*chartInstance->c1_BalCmd)[c1_i1] = false;
    }

    for (c1_i2 = 0; c1_i2 < 96; c1_i2++) {
      covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)
                        (*chartInstance->c1_BalCmd)[c1_i2]);
    }

    chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
      *chartInstance->c1_MinCellVolt;
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      chartInstance->c1_DeltaCellVolt);
  } else {
    switch (chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel) {
     case c1_IN_BalancingOFF:
      covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 1U, 0, 0,
                        c1_IN_BalancingOFF);
      c1_guard1 = false;
      if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 5U, 1, 0,
                           chartInstance->c1_flgEnBalancing) && covrtEmlCondEval
          (chartInstance->c1_covrtInstance, 5U, 1, 1, covrtRelationalopUpdateFcn
           (chartInstance->c1_covrtInstance, 5U, 1U, 0U, (real_T)
            *chartInstance->c1_BMS_State, 2.0, -1, 1U,
            *chartInstance->c1_BMS_State != 2.0F))) {
        sf_temporal_value_range_check_min(chartInstance->S, 464U, (real_T)
          chartInstance->c1_BalOffWait, 0.0);
        if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 5U, 1, 2,
                             chartInstance->c1_temporalCounter_i1 * 5 >=
                             chartInstance->c1_BalOffWait) && covrtEmlCondEval
            (chartInstance->c1_covrtInstance, 5U, 1, 3,
             covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 5U, 1U,
              1U, (real_T)chartInstance->c1_DeltaCellVolt, (real_T)
              chartInstance->c1_TargetDeltaV, -3, 4U,
              chartInstance->c1_DeltaCellVolt > chartInstance->c1_TargetDeltaV)))
        {
          covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 5U, 1, 0, true);
          covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 1, 0, true);
          c1_b_out = true;
        } else {
          c1_guard1 = true;
        }
      } else {
        c1_guard1 = true;
      }

      if (c1_guard1) {
        covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 5U, 1, 0, false);
        covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 1, 0, false);
        c1_b_out = false;
      }

      if (c1_b_out) {
        chartInstance->c1_JITTransitionAnimation[1U] = 1U;
        chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
          c1_IN_NO_ACTIVE_CHILD;
        chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
          c1_IN_BalancingON;
        chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
          *chartInstance->c1_MinCellVolt;
        covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                          chartInstance->c1_DeltaCellVolt);
        chartInstance->c1_JITTransitionAnimation[3U] = 1U;
        chartInstance->c1_is_BalancingON = c1_IN_BalActive;
        c1_enter_atomic_BalActive(chartInstance);
      } else {
        chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
          *chartInstance->c1_MinCellVolt;
        covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                          chartInstance->c1_DeltaCellVolt);
      }
      break;

     case c1_IN_BalancingON:
      covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 1U, 0, 0,
                        c1_IN_BalancingON);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 5, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 5U, 5U, 0U, (real_T)
                          *chartInstance->c1_BMS_State, 2.0, -1, 0U,
                          *chartInstance->c1_BMS_State == 2.0F))) {
        c1_out = true;
      } else {
        c1_out = false;
      }

      if (c1_out) {
        chartInstance->c1_JITTransitionAnimation[5U] = 1U;
        switch (chartInstance->c1_is_BalancingON) {
         case c1_IN_BalActive:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 1,
                            c1_IN_BalActive);
          chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
          break;

         case c1_IN_BalNotActive:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 1,
                            c1_IN_BalNotActive);
          chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
          break;

         default:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 1, 0);
          chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
          break;
        }

        chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
          c1_IN_NO_ACTIVE_CHILD;
        chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
          c1_IN_BalancingOFF;
        chartInstance->c1_temporalCounter_i1 = 0U;
        for (c1_i3 = 0; c1_i3 < 96; c1_i3++) {
          (*chartInstance->c1_BalCmd)[c1_i3] = false;
        }

        for (c1_i4 = 0; c1_i4 < 96; c1_i4++) {
          covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)
                            (*chartInstance->c1_BalCmd)[c1_i4]);
        }

        chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
          *chartInstance->c1_MinCellVolt;
        covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                          chartInstance->c1_DeltaCellVolt);
      } else {
        chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
          *chartInstance->c1_MinCellVolt;
        covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                          chartInstance->c1_DeltaCellVolt);
        switch (chartInstance->c1_is_BalancingON) {
         case c1_IN_BalActive:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 0,
                            c1_IN_BalActive);
          if (!chartInstance->c1_dataWrittenToVector[0U]) {
            sf_read_before_write_error(chartInstance->S, 1U, 482U, 1, 11);
          }

          if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 6, 0,
                             chartInstance->c1_flgBalCompl)) {
            c1_c_out = true;
          } else {
            c1_c_out = false;
          }

          if (c1_c_out) {
            chartInstance->c1_JITTransitionAnimation[6U] = 1U;
            chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
            chartInstance->c1_is_BalancingON = c1_IN_BalNotActive;
            chartInstance->c1_temporalCounter_i1 = 0U;
          } else {
            c1_x = chartInstance->c1_TargetDeltaV;
            c1_b_x = c1_x;
            c1_z = c1_b_x / 2.0F;
            for (c1_i5 = 0; c1_i5 < 96; c1_i5++) {
              (*chartInstance->c1_BalCmd)[c1_i5] =
                ((*chartInstance->c1_CellVoltages)[c1_i5] -
                 *chartInstance->c1_MinCellVolt > c1_z);
            }

            for (c1_i6 = 0; c1_i6 < 96; c1_i6++) {
              covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)
                                (*chartInstance->c1_BalCmd)[c1_i6]);
            }

            for (c1_i7 = 0; c1_i7 < 96; c1_i7++) {
              c1_c_x[c1_i7] = !(*chartInstance->c1_BalCmd)[c1_i7];
            }

            for (c1_i8 = 0; c1_i8 < 96; c1_i8++) {
              c1_x_data[c1_i8] = c1_c_x[c1_i8];
            }

            chartInstance->c1_flgBalCompl = true;
            c1_k = 0;
            c1_exitg1 = false;
            while ((!c1_exitg1) && (c1_k < 96)) {
              c1_b_k = (real_T)c1_k + 1.0;
              if (!c1_x_data[(int32_T)c1_b_k - 1]) {
                chartInstance->c1_flgBalCompl = false;
                c1_exitg1 = true;
              } else {
                c1_k++;
              }
            }

            chartInstance->c1_dataWrittenToVector[0U] = true;
            covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                              chartInstance->c1_flgBalCompl);
          }
          break;

         case c1_IN_BalNotActive:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 0,
                            c1_IN_BalNotActive);
          sf_temporal_value_range_check_min(chartInstance->S, 480U, (real_T)
            chartInstance->c1_BalNotActWait, 0.0);
          if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 5U, 4, 0,
                               chartInstance->c1_temporalCounter_i1 * 5 >=
                               chartInstance->c1_BalNotActWait) &&
              covrtEmlCondEval(chartInstance->c1_covrtInstance, 5U, 4, 1,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c1_covrtInstance, 5U, 4U, 0U,
                                (real_T)chartInstance->c1_DeltaCellVolt, (real_T)
                                chartInstance->c1_TargetDeltaV, -3, 4U,
                                chartInstance->c1_DeltaCellVolt >
                                chartInstance->c1_TargetDeltaV))) {
            covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 5U, 4, 0, true);
            covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 4, 0, true);
            c1_d_out = true;
          } else {
            covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 5U, 4, 0, false);
            covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 4, 0, false);
            c1_d_out = false;
          }

          if (c1_d_out) {
            chartInstance->c1_JITTransitionAnimation[4U] = 1U;
            chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
            chartInstance->c1_is_BalancingON = c1_IN_BalActive;
            c1_enter_atomic_BalActive(chartInstance);
          } else {
            sf_temporal_value_range_check_min(chartInstance->S, 466U, (real_T)
              chartInstance->c1_BalOnWait, 0.0);
            if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 5U, 2, 0,
                               chartInstance->c1_temporalCounter_i1 * 5 >=
                               chartInstance->c1_BalOnWait)) {
              c1_e_out = true;
            } else {
              c1_e_out = false;
            }

            if (c1_e_out) {
              chartInstance->c1_JITTransitionAnimation[2U] = 1U;
              chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
              chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
                c1_IN_NO_ACTIVE_CHILD;
              chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
                c1_IN_BalancingOFF;
              chartInstance->c1_temporalCounter_i1 = 0U;
              for (c1_i9 = 0; c1_i9 < 96; c1_i9++) {
                (*chartInstance->c1_BalCmd)[c1_i9] = false;
              }

              for (c1_i10 = 0; c1_i10 < 96; c1_i10++) {
                covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)(*
                  chartInstance->c1_BalCmd)[c1_i10]);
              }

              chartInstance->c1_DeltaCellVolt = *chartInstance->c1_MaxCellVolt -
                *chartInstance->c1_MinCellVolt;
              covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                                chartInstance->c1_DeltaCellVolt);
            }
          }
          break;

         default:
          covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 4U, 1, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c1_is_BalancingON = c1_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
      break;

     default:
      covrtDecUpdateFcn(chartInstance->c1_covrtInstance, 1U, 0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel =
        c1_IN_NO_ACTIVE_CHILD;
      break;
    }
  }

  c1_update_jit_animation_c1_ConfiguredVirtualVehicleModel(chartInstance);
  c1_do_animation_call_c1_ConfiguredVirtualVehicleModel(chartInstance);
}

static void ext_mode_exec_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  chartInstance->c1_JITStateAnimation[0U] = (uint8_T)
    (chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel == c1_IN_BalancingON);
  chartInstance->c1_JITStateAnimation[1U] = (uint8_T)
    (chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel == c1_IN_BalancingOFF);
  chartInstance->c1_JITStateAnimation[2U] = (uint8_T)
    (chartInstance->c1_is_BalancingON == c1_IN_BalActive);
  chartInstance->c1_JITStateAnimation[3U] = (uint8_T)
    (chartInstance->c1_is_BalancingON == c1_IN_BalNotActive);
}

static void c1_do_animation_call_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(8, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_BalCmd, 11, 0U,
    1U, 0U, 2, 1, 96), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &chartInstance->c1_DeltaCellVolt, 1,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &chartInstance->c1_flgBalCompl, 11,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_ConfiguredVirtualVehicleModel, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y",
    &chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel, 7, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &chartInstance->c1_is_BalancingON, 7,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y",
    &chartInstance->c1_temporalCounter_i1, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y",
    chartInstance->c1_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 1), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  int32_T c1_i;
  boolean_T c1_bv[96];
  boolean_T c1_bv1[1];
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "BalCmd", c1_bv);
  for (c1_i = 0; c1_i < 96; c1_i++) {
    (*chartInstance->c1_BalCmd)[c1_i] = c1_bv[c1_i];
  }

  chartInstance->c1_DeltaCellVolt = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "DeltaCellVolt");
  chartInstance->c1_flgBalCompl = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "flgBalCompl");
  chartInstance->c1_is_active_c1_ConfiguredVirtualVehicleModel =
    c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "is_active_c1_ConfiguredVirtualVehicleModel");
  chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
     "is_c1_ConfiguredVirtualVehicleModel");
  chartInstance->c1_is_BalancingON = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "is_BalancingON");
  chartInstance->c1_temporalCounter_i1 = c1_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "temporalCounter_i1");
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "dataWrittenToVector", c1_bv1);
  chartInstance->c1_dataWrittenToVector[0] = c1_bv1[0];
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_jit_animation_c1_ConfiguredVirtualVehicleModel(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void initSimStructsc1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc1_ConfiguredVirtualVehicleModel
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_enter_atomic_BalActive
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  real_T c1_b_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_k;
  real32_T c1_b_x;
  real32_T c1_x;
  real32_T c1_z;
  boolean_T c1_c_x[96];
  boolean_T c1_x_data[96];
  boolean_T c1_exitg1;
  c1_x = chartInstance->c1_TargetDeltaV;
  c1_b_x = c1_x;
  c1_z = c1_b_x / 2.0F;
  for (c1_i = 0; c1_i < 96; c1_i++) {
    (*chartInstance->c1_BalCmd)[c1_i] = ((*chartInstance->c1_CellVoltages)[c1_i]
      - *chartInstance->c1_MinCellVolt > c1_z);
  }

  for (c1_i1 = 0; c1_i1 < 96; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U, (real_T)
                      (*chartInstance->c1_BalCmd)[c1_i1]);
  }

  for (c1_i2 = 0; c1_i2 < 96; c1_i2++) {
    c1_c_x[c1_i2] = !(*chartInstance->c1_BalCmd)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 96; c1_i3++) {
    c1_x_data[c1_i3] = c1_c_x[c1_i3];
  }

  chartInstance->c1_flgBalCompl = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 96)) {
    c1_b_k = (real_T)c1_k + 1.0;
    if (!c1_x_data[(int32_T)c1_b_k - 1]) {
      chartInstance->c1_flgBalCompl = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  chartInstance->c1_dataWrittenToVector[0U] = true;
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                    chartInstance->c1_flgBalCompl);
}

const mxArray
  *sf_c1_ConfiguredVirtualVehicleModel_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  const mxArray *c1_m = NULL;
  real_T c1_d;
  real_T c1_d1;
  c1_m = NULL;
  if (chartInstance->c1_is_BalancingON == c1_IN_BalNotActive) {
    c1_d1 = 5.0 * (real_T)chartInstance->c1_temporalCounter_i1;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d1, 0, 0U, 0U, 0U, 0),
                  false);
  } else {
    c1_d = -1.0;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d, 0, 0U, 0U, 0U, 0),
                  false);
  }

  return c1_m;
}

static const mxArray *c1_b_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  const mxArray *c1_m = NULL;
  real_T c1_d;
  real_T c1_d1;
  c1_m = NULL;
  if (chartInstance->c1_is_c1_ConfiguredVirtualVehicleModel ==
      c1_IN_BalancingOFF) {
    c1_d1 = 5.0 * (real_T)chartInstance->c1_temporalCounter_i1;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d1, 0, 0U, 0U, 0U, 0),
                  false);
  } else {
    c1_d = -1.0;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d, 0, 0U, 0U, 0U, 0),
                  false);
  }

  return c1_m;
}

static const mxArray *c1_c_sfAfterOrElapsed
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  const mxArray *c1_m = NULL;
  real_T c1_d;
  real_T c1_d1;
  c1_m = NULL;
  if (chartInstance->c1_is_BalancingON == c1_IN_BalNotActive) {
    c1_d1 = 5.0 * (real_T)chartInstance->c1_temporalCounter_i1;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d1, 0, 0U, 0U, 0U, 0),
                  false);
  } else {
    c1_d = -1.0;
    sf_mex_assign(&c1_m, sf_mex_create("unnamed temp", &c1_d, 0, 0U, 0U, 0U, 0),
                  false);
  }

  return c1_m;
}

static void c1_emlrt_marshallIn(SFc1_ConfiguredVirtualVehicleModelInstanceStruct
  *chartInstance, const mxArray *c1_b_BalCmd, const char_T *c1_identifier,
  boolean_T c1_y[96])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_BalCmd), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_BalCmd);
}

static void c1_b_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[96])
{
  int32_T c1_i;
  boolean_T c1_bv[96];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 1, 96);
  for (c1_i = 0; c1_i < 96; c1_i++) {
    c1_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static real32_T c1_c_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_DeltaCellVolt, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_DeltaCellVolt),
    &c1_thisId);
  sf_mex_destroy(&c1_b_DeltaCellVolt);
  return c1_y;
}

static real32_T c1_d_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real32_T c1_f;
  real32_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_f, 0, 1, 0U, 0, 0U, 0);
  c1_y = c1_f;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static boolean_T c1_e_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_flgBalCompl, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_flgBalCompl),
    &c1_thisId);
  sf_mex_destroy(&c1_b_flgBalCompl);
  return c1_y;
}

static boolean_T c1_f_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_b;
  boolean_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_ConfiguredVirtualVehicleModel, const char_T
   *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_ConfiguredVirtualVehicleModel), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ConfiguredVirtualVehicleModel);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_u;
  uint8_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_i_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_is_c1_ConfiguredVirtualVehicleModel, const char_T
   *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_c1_ConfiguredVirtualVehicleModel), &c1_thisId);
  sf_mex_destroy(&c1_b_is_c1_ConfiguredVirtualVehicleModel);
  return c1_y;
}

static uint32_T c1_j_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_b_u;
  uint32_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint16_T c1_k_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_temporalCounter_i1, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint16_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_temporalCounter_i1),
    &c1_thisId);
  sf_mex_destroy(&c1_b_temporalCounter_i1);
  return c1_y;
}

static uint16_T c1_l_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint16_T c1_b_u;
  uint16_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 5, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_m_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier, boolean_T
   c1_y[1])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_dataWrittenToVector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_dataWrittenToVector);
}

static void c1_n_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[1])
{
  boolean_T c1_bv[1];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv, 1, 11, 0U, 1, 0U, 1, 1);
  c1_y[0] = c1_bv[0];
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_o_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), true);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_p_emlrt_marshallIn
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), true);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_init_sf_message_store_memory
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

mxArray *sf_c1_ConfiguredVirtualVehicleModel_getDebuggerHoverDataFor
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, uint32_T
   c1_u)
{
  const mxArray *c1_m = NULL;
  const mxArray *c1_m1 = NULL;
  const mxArray *c1_m2 = NULL;
  mxArray *c1_m3 = NULL;
  c1_m3 = NULL;
  switch (c1_u) {
   case 480U:
    sf_mex_assign(&c1_m, c1_sfAfterOrElapsed(chartInstance), false);
    sfAppendHoverData(&c1_m3, sf_mex_dup(c1_m), 480U, "afterOrElapsed", "", 477U,
                      -1, -1, -1, -1);
    break;

   case 466U:
    sf_mex_assign(&c1_m1, c1_c_sfAfterOrElapsed(chartInstance), false);
    sfAppendHoverData(&c1_m3, sf_mex_dup(c1_m1), 466U, "afterOrElapsed", "",
                      477U, -1, -1, -1, -1);
    break;

   case 464U:
    sf_mex_assign(&c1_m2, c1_b_sfAfterOrElapsed(chartInstance), false);
    sfAppendHoverData(&c1_m3, sf_mex_dup(c1_m2), 464U, "afterOrElapsed", "",
                      463U, -1, -1, -1, -1);
    break;
  }

  sf_mex_destroy(&c1_m);
  sf_mex_destroy(&c1_m1);
  sf_mex_destroy(&c1_m2);
  return c1_m3;
}

static void c1_chart_data_browse_helper
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance, int32_T
   c1_ssIdNumber, const mxArray **c1_mxData, uint8_T *c1_isValueTooBig)
{
  real32_T c1_f;
  real32_T c1_f1;
  real32_T c1_f2;
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 469U:
    c1_f = *chartInstance->c1_BMS_State;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_f, 1, 0U, 0U, 0U, 0),
                  false);
    break;

   case 453U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      *chartInstance->c1_CellVoltages, 1, 0U, 1U, 0U, 1, 96), false);
    break;

   case 191U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_TargetDeltaV, 1, 0U, 0U, 0U, 0), false);
    break;

   case 451U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_BalCmd,
      11, 0U, 1U, 0U, 2, 1, 96), false);
    break;

   case 474U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_flgBalCompl, 11, 0U, 0U, 0U, 0), false);
    break;

   case 430U:
    c1_f1 = *chartInstance->c1_MaxCellVolt;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_f1, 1, 0U, 0U, 0U, 0),
                  false);
    break;

   case 443U:
    c1_f2 = *chartInstance->c1_MinCellVolt;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_f2, 1, 0U, 0U, 0U, 0),
                  false);
    break;

   case 485U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_BalNotActWait, 4, 0U, 0U, 0U, 0), false);
    break;

   case 486U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_BalOffWait, 4, 0U, 0U, 0U, 0), false);
    break;

   case 487U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_BalOnWait, 4, 0U, 0U, 0U, 0), false);
    break;

   case 492U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_flgEnBalancing, 11, 0U, 0U, 0U, 0), false);
    break;

   case 465U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData",
      &chartInstance->c1_DeltaCellVolt, 1, 0U, 0U, 0U, 0), false);
    break;
  }
}

static void init_test_point_addr_map
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  chartInstance->c1_testPointAddrMap[0] = &chartInstance->c1_DeltaCellVolt;
}

static void **get_test_point_address_map
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointMappingInfo;
}

static void init_dsm_address_info
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_BMS_State = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_CellVoltages = (real32_T (*)[96])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_BalCmd = (boolean_T (*)[96])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_MaxCellVolt = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_MinCellVolt = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_ConfiguredVirtualVehicleModel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4121755685U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3868822619U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2695124433U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2486062646U);
}

mxArray *sf_c1_ConfiguredVirtualVehicleModel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ConfiguredVirtualVehicleModel_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("testpoint");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("DeltaCellVolt");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_ConfiguredVirtualVehicleModel_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_ConfiguredVirtualVehicleModel
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrNlcFKAzEQhrNrLRWxFH2BYsGDp/bmzcV6sIfqRVZva8imNZBNynZWLLTv4iP5CH0EH8Gk2bb"
    "bUNziLtpAGP7ATOabSRjk9PpIrbrazRpCVWWVQS4y6zDVTsaa88pKN9WGyYjq83FMeqGyAkcLjZ"
    "P3nhjIRfwrtI5f3RLfycQ/Ss/N+rou5N+eerZ/ZYt/NePfSPUN5t0oNPVZ1un3HDWvkH9jtvD3c"
    "jhOLA6tbykH3KWc+5ID2hOej914ji0erQd8qFsjoxFfcRTnaRbjSe9/yeG5tHi0ZuMAE2BvNCCd"
    "oCvFgA2TmIY+iyHB3KevjHDalyHlqETe81J4n3N4WxZvy/DuBLoXnPPJTu+0bnHWDad6p1gQJoY"
    "P92XxXJTSt7scnlOLR2ug0UjG+uclAmgcsM46Xs35eX441vw4SLXOjQKSY0Qgm187Jz93Iz8XYT"
    "B+Xk5dXKsujeWlnzPPjJup96/zCrX/pL9nVn+1DjHgp5gBUPEofUpAxhv/8BtN1mcW"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ConfiguredVirtualVehicleModel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sDBt9ORNYmZJ5OmILDqnolF";
}

static void sf_opaque_initialize_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  initialize_params_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
  initialize_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  enable_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  disable_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  sf_gateway_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_ConfiguredVirtualVehicleModel
  (SimStruct* S)
{
  return get_sim_state_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_ConfiguredVirtualVehicleModel(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_ConfiguredVirtualVehicleModel
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ConfiguredVirtualVehicleModel_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_ConfiguredVirtualVehicleModel
      ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  mdl_start_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo
      (((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*)chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_ConfiguredVirtualVehicleModel(void
  *chartInstanceVar)
{
  mdl_terminate_c1_ConfiguredVirtualVehicleModel
    ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ConfiguredVirtualVehicleModel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ConfiguredVirtualVehicleModel
      ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*)
       sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc1_ConfiguredVirtualVehicleModel
      ((SFc1_ConfiguredVirtualVehicleModelInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_ConfiguredVirtualVehicleModel_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [27] = {
    "eNrtWt1uG0UUHrtplKhNFJULJIREoBKCSkipEFKREDjxDxjyp9pJS2/CZPfYHmV2xpmZdWKUSoh",
    "n4BIhLnkDnoD7PgK33HHJDRJndteOs3G9O3Zog8pKjjP2fnPOd+b8bkIK9S2C1zK+HtwlZB7fF/",
    "BVJPF1M1kXRl7x53Pkk2R9dosQT/rQBtEIWy12StwuEQa7VNFAE/dL0AAegpY8NEyKumjJ/FgmW",
    "qBAeLhBVyrjJFezIORMHNVC4VnJ+lGHeZ1GR4bc38ANqb8jeP95cruh2UWJFabAMzUA33SUDNud",
    "GqftyVZQ5qTcAe9Ih4GzrTSYRti1VPVWyA3rcqieglcX2lC0gs7g2zDUQNmcuhnZ8tWNAVoGXc6",
    "oyG/rDtUN6KJ3GNjr+vhzJzRovVxYr0OV2YAO7YHeZEeRdCkgl3Sm8e5DJqiRilFeDXjZ7paT7y",
    "5HjlsYEtz1jJDvhgJ61JVMGMeAaNTQzlVBDzlU4DBsO8ptwHFoo2GfwQkot/NtlWUPFG3DjnDTO",
    "Tqj6mnklMNYyok1LIB9qtY99F0NvlvewKDTDYruCE3cxgkLkYnruqlYD33DNdfVbfhPlevCIPZ+",
    "PRU2klvtgbNfDeXWPFGmnGs3bFN2N6EHPJJfoYZOgY3lO4C1Zn5TonfYbOOYsULBMBISbFkKn+X",
    "3yl4KFRW2bSxSOeAssGEAPpp5qPpwo6w4CrWRQRlTTmVzM6e8y9i6MKBa1IPcNUZRpgEVjvzKUa",
    "7PtA0kRKOVTMQy9w5xDE4FJboVisqJVEdoY9didm4rGwluaPDbmJgNREmuit69T3mYU+dAtzF+0",
    "D32NGZZN7mItfEzFdijXgd8WzkZhy3Ms7hB3iPWtuSvI9seM/0KaE+xbt5ICjGhY9G1Vmr2u7An",
    "joQ8ETUlg0bSeU3wKwDMGlQJJtobWMJVv4bK59NawXEzyu6uTY61MzWcHlrf+BwEVkPL1XYN1MO",
    "oqgpskVGhWbAN9i02MUIzbbBQ9+NSH9c927/vkvP+fW5M/7460r+vJGvv/gHu2GLtUIG/z5QJKd",
    "8H7GXxtG3/YvddG9n3do654GaizyQcuYQjQx6D9/dG8IUxcsnIe1reYvHi/XMpeUX8pICXxZVGc",
    "EtkMm4+sd2dX/9Y++qH73/rLP399hvv//g0S37hkvxC9LvFPVtwm7uWk/Wbg/5pmK17lxKavfeL",
    "DL94PeUXdq0rG+bjnYfbXwdPvvxoJ6hvVo6F5LVov9UMfRdS+o76n8FgjnKD8up+Mr/ZNQ3juSK",
    "aQ0f0nc+wx+KIPxHy52cz4dfOSmn8OHvNp+xl1xuUlwP/ov9Oz2OhNBN+5Wkp7dfjeCyleNh1Bb",
    "ihZeB8X3JDrgmfn/PxuZXiY9ct3rZHY+fOS/llej6rs/FJ5H+Twedeis+9aNY6oLaiwkFW5iZXy",
    "PedK+H7OIPv3RTfuzHfXESvBc/f+7n8dDnFcznmiX5KhYdlfmf7qvi8eyXnllU/7qT42LUBO8zY",
    "yAvtTHHA7p/vt1Bwq3c3krXVDQyRmniGPKfuj9OveEG/IqEmxpUy7FJM2WVlIPTZ01Jcbs5KL7V",
    "ekbUXcr6vpc7Xrn0cxR8pZrARxVkVRxqpLsXhtP2QK478j7sWuMIrqGeeeWhuSlxhShx5wbhZ+b",
    "nOef/1+yfVK5K6f+Ua85iU713m/evG6/GcW3/yVrL+dPjcudxh3B/z5Cv5ehNoa9y3ifxfbkzWd",
    "26CPy1l6Ds/EuffOfZhd0b6Pc8yrPunTWmfu27R7qi9C/+u/oO8kdVn307F0e14Tk+a7FptWvnF",
    "nPLHzaMXmvwp5f9UeDXObzFlv8XYflHkwAzyi7P5z7Y05ypcx/z1F3Hzi8Hzv6rNX8k/CDz5cF1",
    "Q3tcsfmw++HhX2b/zDr9SQPX45/kvow8cNy+PO9ebqXO1671m7YMHM/ST/wBOZ479",
    ""
  };

  static char newstr [1941] = "";
  newstr[0] = '\0';
  for (i = 0; i < 27; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_ConfiguredVirtualVehicleModel(SimStruct *S)
{
  const char* newstr = sf_c1_ConfiguredVirtualVehicleModel_get_post_codegen_info
    ();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(820623122U));
  ssSetChecksum1(S,(3313669195U));
  ssSetChecksum2(S,(570232168U));
  ssSetChecksum3(S,(2107386138U));
}

static void mdlRTW_c1_ConfiguredVirtualVehicleModel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlSetupRuntimeResources_c1_ConfiguredVirtualVehicleModel(SimStruct *
  S)
{
  SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *)utMalloc
    (sizeof(SFc1_ConfiguredVirtualVehicleModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc1_ConfiguredVirtualVehicleModelInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ConfiguredVirtualVehicleModel;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  mdl_setup_runtime_resources_c1_ConfiguredVirtualVehicleModel(chartInstance);
}

void c1_ConfiguredVirtualVehicleModel_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_ConfiguredVirtualVehicleModel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ConfiguredVirtualVehicleModel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ConfiguredVirtualVehicleModel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ConfiguredVirtualVehicleModel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "real32_T", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/DeltaCellVolt", "DeltaCellVolt", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    820623122U,
    3313669195U,
    570232168U,
    2107386138U
  }
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc1_ConfiguredVirtualVehicleModelInstanceStruct *chartInstance =
    (SFc1_ConfiguredVirtualVehicleModelInstanceStruct *)
    sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
