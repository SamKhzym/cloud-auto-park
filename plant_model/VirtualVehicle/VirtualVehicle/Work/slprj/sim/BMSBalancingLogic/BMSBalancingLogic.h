#ifndef RTW_HEADER_BMSBalancingLogic_h_
#define RTW_HEADER_BMSBalancingLogic_h_
#ifndef BMSBalancingLogic_COMMON_INCLUDES_
#define BMSBalancingLogic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "BMSBalancingLogic_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
typedef struct { real32_T nfefv0sb3a ; uint16_T hfa2glihpg ; uint8_T
gznrnfzza5 ; uint8_T hgm0sy2frr ; uint8_T ax043zijvk ; boolean_T omvz1ve3rk ;
} hse03z0axoy ;
#endif
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
struct pi3h4ymvb42_ { real32_T P_0 ; int16_T P_1 ; int16_T P_2 ; int16_T P_3
; boolean_T P_4 ; } ;
#endif
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
struct arovgo0wao { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 1 ] ; int32_T * vardimsAddress [ 1
] ; RTWLoggingFcnPtr loggingPtrs [ 1 ] ; sysRanDType * systemRan [ 3 ] ;
int_T systemTid [ 3 ] ; } DataMapInfo ; } ;
#endif
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
typedef struct { jtvn52kzgd rtm ; } nxoas2gjfbm ;
#endif
extern void okbayvkvs0 ( boolean_T n4byhwdk3h [ 96 ] ) ; extern void
l0kmnlkf5y ( boolean_T n4byhwdk3h [ 96 ] ) ; extern void BMSBalancingLogic (
const real32_T * kzzpi5g2pn , const real32_T kecw5f4uup [ 96 ] , const
real32_T * h2x23ryqoh , const real32_T * erx1den1g5 , boolean_T n4byhwdk3h [
96 ] ) ; extern void jozn1uvmvd ( void ) ; extern void bjd0wkxsam ( SimStruct
* _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSBalancingLogic_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_BMSBalancingLogic_GetDWork
( ) ; extern void mr_BMSBalancingLogic_SetDWork ( const mxArray * ssDW ) ;
extern void mr_BMSBalancingLogic_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_BMSBalancingLogic_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo *
BMSBalancingLogic_GetCAPIStaticMap ( void ) ; void
mr_BMSBalancingLogic_CreateInitRestoreData ( ) ; void
mr_BMSBalancingLogic_CopyFromInitRestoreData ( ) ; void
mr_BMSBalancingLogic_DestroyInitRestoreData ( ) ;
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
extern nxoas2gjfbm nxoas2gjfb ;
#endif
#ifndef BMSBalancingLogic_MDLREF_HIDE_CHILD_
extern hse03z0axoy j30rwafp5zl ;
#endif
#endif
