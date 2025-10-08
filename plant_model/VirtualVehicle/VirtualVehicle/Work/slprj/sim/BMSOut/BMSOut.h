#ifndef RTW_HEADER_BMSOut_h_
#define RTW_HEADER_BMSOut_h_
#ifndef BMSOut_COMMON_INCLUDES_
#define BMSOut_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSOut_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#ifndef BMSOut_MDLREF_HIDE_CHILD_
struct nvcht4hdfj { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ;
#endif
#ifndef BMSOut_MDLREF_HIDE_CHILD_
typedef struct { oq5eurmbom rtm ; } pcu03dvoe3p ;
#endif
extern void BMSOut ( const real32_T * ngqqgeopwf , const real32_T *
ofi1ry3gym , const real32_T * cl54a1v5j1 , const boolean_T * igduxa2y4s ,
const boolean_T * oehacmojhw , const boolean_T * jmyo3p1phq , const boolean_T
* me5w1zdj4s , const boolean_T * exmqopawg1 , const boolean_T * ft2knzkk30 ,
const boolean_T * kayb1jvrcn , const real32_T * omlrkjg2do , const real32_T *
itudpoovv0 , const real32_T * npvwet3kfk , const real32_T * cnc0bruz1d ,
const boolean_T grasxpgjgs [ 96 ] , real32_T * hi0qupfrcg , real32_T *
krol0fx55z , real32_T * dta12jj3zo , boolean_T * odhgxmj2dl , boolean_T *
dcsfmzdxue , boolean_T * jl2a3vykez , boolean_T * pqqx3guvq4 , boolean_T *
lriczkjol4 , boolean_T * jrr1nevuvk , boolean_T es1tn1nplx [ 96 ] , boolean_T
* nlua31zfcy , real32_T * ebajk0lef4 , real32_T * be44hofuvo , real32_T *
mviynrcflk , real32_T * osikg3zy0j ) ; extern void jhgahwtvq0 ( void ) ;
extern void gzneizzges ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_BMSOut_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_BMSOut_GetDWork ( ) ; extern void mr_BMSOut_SetDWork ( const mxArray *
ssDW ) ; extern void mr_BMSOut_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_BMSOut_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSOut_GetCAPIStaticMap ( void ) ;
#ifndef BMSOut_MDLREF_HIDE_CHILD_
extern pcu03dvoe3p pcu03dvoe3 ;
#endif
#endif
