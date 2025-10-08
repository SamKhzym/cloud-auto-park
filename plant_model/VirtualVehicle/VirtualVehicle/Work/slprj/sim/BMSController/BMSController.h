#ifndef RTW_HEADER_BMSController_h_
#define RTW_HEADER_BMSController_h_
#ifndef BMSController_COMMON_INCLUDES_
#define BMSController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSController_types.h"
#include "model_reference_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#ifndef BMSController_MDLREF_HIDE_CHILD_
typedef struct { real32_T fm55o01te2 [ 96 ] ; real32_T ochexbavmj [ 96 ] ;
real32_T naz14vswl4 ; real32_T fpmd2bpykz ; real32_T idni5bub1a ; real32_T
fcyzlyudv4 ; real32_T aqhr4jyxka ; real32_T obpivodrhe ; real32_T ofsd5tege5
; real32_T j0j04ul1wd ; real32_T citku4fcqi ; real32_T fykqayal22 ; real32_T
jiylicxfpw ; real32_T ddjfgylpbb ; real32_T jbdnp5lsqc ; real32_T d2znwfvjz5
; real32_T o5lorxl1t2 ; real32_T jscb4sqqxg ; real32_T j02uwajpkc [ 96 ] ;
real32_T dpehvequ4b ; real32_T mdxoqaymv2 ; boolean_T hqgravc0zq ; boolean_T
cx1favx45s ; boolean_T ak2z1fsy2a ; boolean_T ptmoeurf21 ; boolean_T
o52oy3hcmh ; boolean_T bermrxiuhz ; boolean_T f2mxcxswac ; boolean_T
c1nq0xqyh1 [ 96 ] ; } l5yy0qtgsji ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
typedef struct { real32_T dz4c4vv4e1 [ 96 ] ; real32_T phucyyn21j [ 96 ] ;
real32_T ku0cdxjs3l ; real32_T iqzga4pj3l ; real32_T hdl0hgqmi0 ; real32_T
hmm5af0r2l ; real32_T kxvz5gfvp4 ; real32_T m3mj3jyjio [ 96 ] ; real32_T
lizezojaqr ; real32_T ldt520oxg4 ; } g0d32wfvf1s ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
struct dkgtpceyogp_ { real32_T P_2 [ 96 ] ; real32_T P_3 [ 96 ] ; real32_T
P_4 ; real32_T P_5 ; real32_T P_6 ; real32_T P_7 ; real32_T P_8 ; } ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
struct i4zyr2rvdz { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 6 ] ; int32_T * vardimsAddress [ 6
] ; RTWLoggingFcnPtr loggingPtrs [ 6 ] ; rtwCAPI_ModelMappingInfo * childMMI
[ 5 ] ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo
; } ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
typedef struct { jhg5ifokiz rtm ; } prqjzwjjc0p ;
#endif
extern real_T rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; extern void ah533pbmux ( void ) ;
extern void p2t1vykwji ( void ) ; extern void n3ldsg2m4a ( void ) ; extern
void dolsr1ry0j ( void ) ; extern void dhe0j1g5mv ( const real32_T adxekd5tio
[ 96 ] , const real32_T j3wvkhbfe4 [ 96 ] , const real32_T * alolnomync ,
const real32_T * gr0s1ny5og , const real32_T * cne0zycowu , const real32_T *
lvjqgkdjmc ) ; extern void BMSController ( boolean_T * e4kvz4supm , real32_T
* a3l2j3y4lx , real32_T * niiizijeve , real32_T * kvl2ul33en , real32_T *
e2rd4hsap2 , real32_T * oqx2ehimcf , real32_T * nhnyktxrfk , real32_T *
h4i5vc02af , boolean_T * chullyjun0 , boolean_T * gamv4ws2w2 , boolean_T *
lxuopn21da , boolean_T * jcpgvzmuwo , boolean_T * jqswid45re , boolean_T *
amy4ujr4ow , boolean_T kv4f4pyu01 [ 96 ] ) ; extern void g10dj1kimi ( void )
; extern void lftbpoqxym ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 ,
int_T mdlref_TID1 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSController_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName
, int_T * retVal ) ; extern mxArray * mr_BMSController_GetDWork ( ) ; extern
void mr_BMSController_SetDWork ( const mxArray * ssDW ) ; extern void
mr_BMSController_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_BMSController_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSController_GetCAPIStaticMap ( void ) ;
void mr_BMSController_CreateInitRestoreData ( ) ; void
mr_BMSController_CopyFromInitRestoreData ( ) ; void
mr_BMSController_DestroyInitRestoreData ( ) ;
#ifndef BMSController_MDLREF_HIDE_CHILD_
extern prqjzwjjc0p prqjzwjjc0 ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
extern l5yy0qtgsji m5iv0kvulag ;
#endif
#ifndef BMSController_MDLREF_HIDE_CHILD_
extern g0d32wfvf1s hwyycww1n0f ;
#endif
#endif
