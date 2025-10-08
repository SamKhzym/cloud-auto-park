#ifndef RTW_HEADER_BMSSOCEstimation_h_
#define RTW_HEADER_BMSSOCEstimation_h_
#ifndef BMSSOCEstimation_COMMON_INCLUDES_
#define BMSSOCEstimation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSSOCEstimation_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
typedef struct { real32_T on0gv4bqfi ; real32_T n2l4swgxts ; real32_T
lhesvjhzjs ; real32_T divtw2wenk ; real32_T o0t0us2gqo ; } pbiqgdx5zan ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
typedef struct { real32_T myrqiep04m ; } izjsvhfdpsu ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
struct aisrboyg3zp_ { real32_T P_2 ; real32_T P_3 ; real32_T P_4 ; real32_T
P_5 ; real32_T P_6 ; real32_T P_7 ; real32_T P_8 ; } ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
struct hpenwvdsgo { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 3 ] ; int32_T * vardimsAddress [ 3
] ; RTWLoggingFcnPtr loggingPtrs [ 3 ] ; sysRanDType * systemRan [ 2 ] ;
int_T systemTid [ 2 ] ; } DataMapInfo ; } ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
typedef struct { fcomfl1sgs rtm ; } pe5hyd5e5ea ;
#endif
extern real_T rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; extern void bbzyccyfe5 ( void ) ;
extern void hue3c0yakn ( void ) ; extern void ioolb10wj0 ( void ) ; extern
void BMSSOCEstimation ( const real32_T * e4051bwwkz , real32_T * bjpjid5gap ,
real32_T * g1ypzcddoc , real32_T * hyfhu3uvbm ) ; extern void kcczw4j51s (
void ) ; extern void dllaarzzct ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_BMSSOCEstimation_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_BMSSOCEstimation_GetDWork ( ) ; extern void mr_BMSSOCEstimation_SetDWork (
const mxArray * ssDW ) ; extern void
mr_BMSSOCEstimation_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_BMSSOCEstimation_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSSOCEstimation_GetCAPIStaticMap ( void ) ;
void mr_BMSSOCEstimation_CreateInitRestoreData ( ) ; void
mr_BMSSOCEstimation_CopyFromInitRestoreData ( ) ; void
mr_BMSSOCEstimation_DestroyInitRestoreData ( ) ;
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
extern pe5hyd5e5ea pe5hyd5e5e ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
extern pbiqgdx5zan lqti3bxlc5b ;
#endif
#ifndef BMSSOCEstimation_MDLREF_HIDE_CHILD_
extern izjsvhfdpsu elgpnmgrvh5 ;
#endif
#endif
