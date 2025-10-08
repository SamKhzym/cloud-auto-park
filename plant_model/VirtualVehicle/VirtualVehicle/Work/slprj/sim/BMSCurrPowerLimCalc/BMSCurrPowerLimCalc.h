#ifndef RTW_HEADER_BMSCurrPowerLimCalc_h_
#define RTW_HEADER_BMSCurrPowerLimCalc_h_
#ifndef BMSCurrPowerLimCalc_COMMON_INCLUDES_
#define BMSCurrPowerLimCalc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSCurrPowerLimCalc_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
typedef struct { real32_T kzwd3zcngx ; real32_T aeprfjl3kx ; real32_T
mk2iwpm1fg ; real32_T duxxagti3l ; real32_T b5d3twimrf ; real32_T nku4mutalv
; real32_T ohynwgzz3h ; real32_T fpy5pmxjjs ; real32_T aals4xubwl ; real32_T
hbskhuqry0 ; } civiuhml2am ;
#endif
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
struct c4f4hs3f30w_ { real32_T P_1 [ 5 ] ; real32_T P_2 [ 5 ] ; real32_T P_3
[ 7 ] ; real32_T P_4 [ 7 ] ; real32_T P_5 [ 4 ] ; real32_T P_6 [ 4 ] ;
real32_T P_7 ; real32_T P_8 [ 4 ] ; real32_T P_9 [ 4 ] ; real32_T P_10 [ 7 ]
; real32_T P_11 [ 7 ] ; real32_T P_12 [ 3 ] ; real32_T P_13 [ 3 ] ; real32_T
P_14 ; } ;
#endif
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
struct nnj3wcguse { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ;
#endif
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
typedef struct { fff1on5pla rtm ; } ozx2hltu2vi ;
#endif
extern real_T rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ ; extern void
BMSCurrPowerLimCalc ( const real32_T d51msl4tbc [ 96 ] , const real32_T
noulgqqcoo [ 96 ] , real32_T * oqmgsset2u , real32_T * kouqt1hzal , real32_T
* kv5an1dmb2 , real32_T * ii5nemx5k0 , real32_T * bnkpia5wne , real32_T *
jqa42ursw1 ) ; extern void du2aze3q0u ( void ) ; extern void mmipgl5oaa (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSCurrPowerLimCalc_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray *
mr_BMSCurrPowerLimCalc_GetDWork ( ) ; extern void
mr_BMSCurrPowerLimCalc_SetDWork ( const mxArray * ssDW ) ; extern void
mr_BMSCurrPowerLimCalc_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_BMSCurrPowerLimCalc_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * BMSCurrPowerLimCalc_GetCAPIStaticMap (
void ) ;
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
extern ozx2hltu2vi ozx2hltu2v ;
#endif
#ifndef BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
extern civiuhml2am h4j4xwequgc ;
#endif
#endif
