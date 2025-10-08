#ifndef RTW_HEADER_OpenLoopBraking_h_
#define RTW_HEADER_OpenLoopBraking_h_
#ifndef OpenLoopBraking_COMMON_INCLUDES_
#define OpenLoopBraking_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "OpenLoopBraking_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
typedef struct { boolean_T fppqpdwfds ; } cq4hrfe0rj ; struct pqlkmereof1_ {
real_T P_1 ; boolean_T P_2 ; } ; struct baz2tyrx4j { struct SimStruct_tag *
_mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; sysRanDType *
systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; struct { int_T
mdlref_GlobalTID [ 2 ] ; } Timing ; } ; typedef struct { cq4hrfe0rj rtb ;
dshwzf1s03 rtm ; } j2diisom34j ; extern real_T
rtP__CtrlBcuTrlrBrkGain2f2VirtualVehicleTemplate_sldd_ ; extern void
dl2qsu4ppj ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1
, dshwzf1s03 * const njmlsg0bqs , cq4hrfe0rj * localB , void * sysRanPtr ,
int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_OpenLoopBraking_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_OpenLoopBraking_GetDWork (
const j2diisom34j * mdlrefDW ) ; extern void mr_OpenLoopBraking_SetDWork (
j2diisom34j * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_OpenLoopBraking_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_OpenLoopBraking_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * OpenLoopBraking_GetCAPIStaticMap ( void ) ;
extern void n5x0ejbjln ( boolean_T fh0nkfle4t [ 4 ] , cq4hrfe0rj * localB ) ;
extern void hc3tptuv0o ( cq4hrfe0rj * localB ) ; extern void OpenLoopBraking
( const real_T * pkgibffjyg , real_T ch24exy52s [ 4 ] , real_T lsyrlfgmud [ 6
] ) ; extern void OpenLoopBrakingTID1 ( boolean_T fh0nkfle4t [ 4 ] ,
cq4hrfe0rj * localB ) ; extern void ese1g5rr1h ( dshwzf1s03 * const
njmlsg0bqs ) ;
#endif
