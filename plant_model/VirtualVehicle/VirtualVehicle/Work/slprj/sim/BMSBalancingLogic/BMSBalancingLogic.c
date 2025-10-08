#include "BMSBalancingLogic.h"
#include "rtwtypes.h"
#include "BMSBalancingLogic_private.h"
#include <string.h>
#include "BMSBalancingLogic_capi.h"
#include "rt_nonfinite.h"
#define bn20zwunui ((uint8_T)0U)
#define eg1kbrcnid ((uint8_T)2U)
#define holkket5nz ((uint8_T)1U)
#define kcprf3gtgl ((uint8_T)2U)
#define lomoaugsn3 ((uint8_T)1U)
int_T hy4a30rjzn [ 1 ] ; static RegMdlInfo rtMdlInfo_BMSBalancingLogic [ 61 ]
= { { "nxoas2gjfbm" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "nxoas2gjfb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "jstvhowtcns" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "g5xty3lupdb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "juhxm4nacod" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , { "mrmn34imhv2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "jsb02kmnfff" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "gszquorpt1n" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , { "ewonr4vammg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "bl2niwctsp" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "j4z3yailpqe" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , { "jgzu1z1fxog" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "mls2ojfpfxr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "hse03z0axoy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , { "oghtrigrl0n" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "jstvhowtcn" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "g5xty3lupd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "juhxm4naco" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "mrmn34imhv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "jsb02kmnff" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "gszquorpt1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "ewonr4vamm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "j4z3yailpq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "jgzu1z1fxo" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "mls2ojfpfx" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "hse03z0axo" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "oghtrigrl0" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "nqnuxuemn0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "jozn1uvmvd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "eouphsgcbg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "jvumnon2rl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "dnz245ggmu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "l0kmnlkf5y" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "okbayvkvs0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "bjd0wkxsam" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSBalancingLogic" } , { "crcml3exdv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "bcsjconw2e" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "BMSBalancingLogic" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "icflmv052kv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "hy4a30rjzn" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "j30rwafp5zl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , { "arovgo0wao" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSBalancingLogic" }
, { "jtvn52kzgd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSBalancingLogic" } , { "cuint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 ,
( void * ) "uint64" } , { "uint64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL
) } , { "cint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "int64"
} , { "int64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_BMSBalancingLogic_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"mr_BMSBalancingLogic_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , (
void * ) "BMSBalancingLogic" } , { "mr_BMSBalancingLogic_GetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSBalancingLogic" } , {
"BMSBalancingLogic.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , {
"BMSBalancingLogic.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"BMSBalancingLogic" } } ; pi3h4ymvb42 mls2ojfpfx = { 0.01F , 30 , 20 , 60 ,
true } ; nxoas2gjfbm nxoas2gjfb ; hse03z0axoy j30rwafp5zl ; void okbayvkvs0 (
boolean_T n4byhwdk3h [ 96 ] ) { j30rwafp5zl . ax043zijvk = bn20zwunui ;
j30rwafp5zl . hfa2glihpg = 0U ; j30rwafp5zl . gznrnfzza5 = 0U ; j30rwafp5zl .
hgm0sy2frr = bn20zwunui ; j30rwafp5zl . omvz1ve3rk = false ; j30rwafp5zl .
nfefv0sb3a = 0.0F ; memset ( & n4byhwdk3h [ 0 ] , 0 , 96U * sizeof (
boolean_T ) ) ; } void l0kmnlkf5y ( boolean_T n4byhwdk3h [ 96 ] ) {
j30rwafp5zl . ax043zijvk = bn20zwunui ; j30rwafp5zl . hfa2glihpg = 0U ;
j30rwafp5zl . gznrnfzza5 = 0U ; j30rwafp5zl . hgm0sy2frr = bn20zwunui ;
j30rwafp5zl . omvz1ve3rk = false ; j30rwafp5zl . nfefv0sb3a = 0.0F ; memset (
& n4byhwdk3h [ 0 ] , 0 , 96U * sizeof ( boolean_T ) ) ; } void
BMSBalancingLogic ( const real32_T * kzzpi5g2pn , const real32_T kecw5f4uup [
96 ] , const real32_T * h2x23ryqoh , const real32_T * erx1den1g5 , boolean_T
n4byhwdk3h [ 96 ] ) { int32_T i ; real32_T nfefv0sb3a_tmp ; boolean_T b_out ;
boolean_T exitg1 ; boolean_T exitg2 ; boolean_T exitg3 ; if ( j30rwafp5zl .
hfa2glihpg < 8191U ) { j30rwafp5zl . hfa2glihpg ++ ; } if ( j30rwafp5zl .
gznrnfzza5 == 0U ) { j30rwafp5zl . gznrnfzza5 = 1U ; j30rwafp5zl . omvz1ve3rk
= true ; j30rwafp5zl . hgm0sy2frr = lomoaugsn3 ; j30rwafp5zl . hfa2glihpg =
0U ; memset ( & n4byhwdk3h [ 0 ] , 0 , 96U * sizeof ( boolean_T ) ) ;
j30rwafp5zl . nfefv0sb3a = * h2x23ryqoh - * erx1den1g5 ; } else if (
j30rwafp5zl . hgm0sy2frr == lomoaugsn3 ) { b_out = ( mls2ojfpfx . P_4 && ( *
kzzpi5g2pn != 2.0F ) && ( j30rwafp5zl . hfa2glihpg * 5 >= mls2ojfpfx . P_2 )
&& ( j30rwafp5zl . nfefv0sb3a > mls2ojfpfx . P_0 ) ) ; if ( b_out ) {
j30rwafp5zl . hgm0sy2frr = kcprf3gtgl ; j30rwafp5zl . nfefv0sb3a = *
h2x23ryqoh - * erx1den1g5 ; j30rwafp5zl . ax043zijvk = holkket5nz ;
nfefv0sb3a_tmp = mls2ojfpfx . P_0 / 2.0F ; for ( i = 0 ; i < 96 ; i ++ ) {
n4byhwdk3h [ i ] = ( kecw5f4uup [ i ] - * erx1den1g5 > nfefv0sb3a_tmp ) ; }
j30rwafp5zl . omvz1ve3rk = true ; i = 0 ; exitg3 = false ; while ( ( ! exitg3
) && ( i < 96 ) ) { if ( n4byhwdk3h [ i ] ) { j30rwafp5zl . omvz1ve3rk =
false ; exitg3 = true ; } else { i ++ ; } } } else { j30rwafp5zl . nfefv0sb3a
= * h2x23ryqoh - * erx1den1g5 ; } } else if ( * kzzpi5g2pn == 2.0F ) {
j30rwafp5zl . ax043zijvk = bn20zwunui ; j30rwafp5zl . hgm0sy2frr = lomoaugsn3
; j30rwafp5zl . hfa2glihpg = 0U ; memset ( & n4byhwdk3h [ 0 ] , 0 , 96U *
sizeof ( boolean_T ) ) ; j30rwafp5zl . nfefv0sb3a = * h2x23ryqoh - *
erx1den1g5 ; } else { nfefv0sb3a_tmp = * h2x23ryqoh - * erx1den1g5 ;
j30rwafp5zl . nfefv0sb3a = nfefv0sb3a_tmp ; switch ( j30rwafp5zl . ax043zijvk
) { case holkket5nz : if ( j30rwafp5zl . omvz1ve3rk ) { j30rwafp5zl .
ax043zijvk = eg1kbrcnid ; j30rwafp5zl . hfa2glihpg = 0U ; } else {
nfefv0sb3a_tmp = mls2ojfpfx . P_0 / 2.0F ; for ( i = 0 ; i < 96 ; i ++ ) {
n4byhwdk3h [ i ] = ( kecw5f4uup [ i ] - * erx1den1g5 > nfefv0sb3a_tmp ) ; }
j30rwafp5zl . omvz1ve3rk = true ; i = 0 ; exitg2 = false ; while ( ( ! exitg2
) && ( i < 96 ) ) { if ( n4byhwdk3h [ i ] ) { j30rwafp5zl . omvz1ve3rk =
false ; exitg2 = true ; } else { i ++ ; } } } break ; default : i =
j30rwafp5zl . hfa2glihpg * 5 ; b_out = ( ( i >= mls2ojfpfx . P_1 ) && (
j30rwafp5zl . nfefv0sb3a > mls2ojfpfx . P_0 ) ) ; if ( b_out ) { j30rwafp5zl
. ax043zijvk = holkket5nz ; nfefv0sb3a_tmp = mls2ojfpfx . P_0 / 2.0F ; for (
i = 0 ; i < 96 ; i ++ ) { n4byhwdk3h [ i ] = ( kecw5f4uup [ i ] - *
erx1den1g5 > nfefv0sb3a_tmp ) ; } j30rwafp5zl . omvz1ve3rk = true ; i = 0 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( i < 96 ) ) { if ( n4byhwdk3h [ i ]
) { j30rwafp5zl . omvz1ve3rk = false ; exitg1 = true ; } else { i ++ ; } } }
else if ( i >= mls2ojfpfx . P_3 ) { j30rwafp5zl . ax043zijvk = bn20zwunui ;
j30rwafp5zl . hgm0sy2frr = lomoaugsn3 ; j30rwafp5zl . hfa2glihpg = 0U ;
memset ( & n4byhwdk3h [ 0 ] , 0 , 96U * sizeof ( boolean_T ) ) ; j30rwafp5zl
. nfefv0sb3a = nfefv0sb3a_tmp ; } break ; } } } void jozn1uvmvd ( void ) {
jtvn52kzgd * const d0hda010hq = & ( nxoas2gjfb . rtm ) ; if ( !
slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( d0hda010hq ->
_mdlRefSfcnS , "BMSBalancingLogic" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void bjd0wkxsam (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { jtvn52kzgd *
const d0hda010hq = & ( nxoas2gjfb . rtm ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( void ) memset ( ( void * ) d0hda010hq , 0 , sizeof (
jtvn52kzgd ) ) ; hy4a30rjzn [ 0 ] = mdlref_TID0 ; d0hda010hq -> _mdlRefSfcnS
= ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( d0hda010hq -> _mdlRefSfcnS , "BMSBalancingLogic" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } ( void ) memset ( ( void * )
& j30rwafp5zl , 0 , sizeof ( hse03z0axoy ) ) ; j30rwafp5zl . nfefv0sb3a =
0.0F ; BMSBalancingLogic_InitializeDataMapInfo ( d0hda010hq , sysRanPtr ,
contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL
) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
d0hda010hq -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( d0hda010hq ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
d0hda010hq -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void
mr_BMSBalancingLogic_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo
= false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ;
if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo (
mdlRefSfcnS , modelName , rtMdlInfo_BMSBalancingLogic , 61 ) ; * retVal = 1 ;
} static void mr_BMSBalancingLogic_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_BMSBalancingLogic_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_BMSBalancingLogic_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_BMSBalancingLogic_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_BMSBalancingLogic_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_BMSBalancingLogic_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_BMSBalancingLogic_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_BMSBalancingLogic_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_BMSBalancingLogic_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_BMSBalancingLogic_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_BMSBalancingLogic_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_BMSBalancingLogic_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_BMSBalancingLogic_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_BMSBalancingLogic_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_BMSBalancingLogic_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_BMSBalancingLogic_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_BMSBalancingLogic_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "NULL_B" , "j30rwafp5zl" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; { static const char_T * rtdwDataFieldNames [ 6 ] = {
"j30rwafp5zl.nfefv0sb3a" , "j30rwafp5zl.hfa2glihpg" ,
"j30rwafp5zl.gznrnfzza5" , "j30rwafp5zl.hgm0sy2frr" ,
"j30rwafp5zl.ax043zijvk" , "j30rwafp5zl.omvz1ve3rk" , } ; mxArray * rtdwData
= mxCreateStructMatrix ( 1 , 1 , 6 , rtdwDataFieldNames ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( j30rwafp5zl . nfefv0sb3a ) , sizeof ( j30rwafp5zl . nfefv0sb3a ) ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * )
& ( j30rwafp5zl . hfa2glihpg ) , sizeof ( j30rwafp5zl . hfa2glihpg ) ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( j30rwafp5zl . gznrnfzza5 ) , sizeof ( j30rwafp5zl . gznrnfzza5 ) ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( j30rwafp5zl . hgm0sy2frr ) , sizeof ( j30rwafp5zl . hgm0sy2frr ) ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( j30rwafp5zl . ax043zijvk ) , sizeof ( j30rwafp5zl . ax043zijvk ) ) ;
mr_BMSBalancingLogic_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( j30rwafp5zl . omvz1ve3rk ) , sizeof ( j30rwafp5zl . omvz1ve3rk ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_BMSBalancingLogic_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ; {
const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
nfefv0sb3a ) , rtdwData , 0 , 0 , sizeof ( j30rwafp5zl . nfefv0sb3a ) ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
hfa2glihpg ) , rtdwData , 0 , 1 , sizeof ( j30rwafp5zl . hfa2glihpg ) ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
gznrnfzza5 ) , rtdwData , 0 , 2 , sizeof ( j30rwafp5zl . gznrnfzza5 ) ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
hgm0sy2frr ) , rtdwData , 0 , 3 , sizeof ( j30rwafp5zl . hgm0sy2frr ) ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
ax043zijvk ) , rtdwData , 0 , 4 , sizeof ( j30rwafp5zl . ax043zijvk ) ) ;
mr_BMSBalancingLogic_restoreDataFromMxArray ( ( void * ) & ( j30rwafp5zl .
omvz1ve3rk ) , rtdwData , 0 , 5 , sizeof ( j30rwafp5zl . omvz1ve3rk ) ) ; } }
void mr_BMSBalancingLogic_RegisterSimStateChecksum ( SimStruct * S ) { const
uint32_T chksum [ 4 ] = { 163507796U , 2508374630U , 3431398346U ,
3271104259U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"BMSBalancingLogic" , & chksum [ 0 ] ) ; } mxArray *
mr_BMSBalancingLogic_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
static void * BMSBalancingLogic_InitRestoreDataPtr = ( NULL ) ; void
mr_BMSBalancingLogic_CreateInitRestoreData ( ) {
BMSBalancingLogic_InitRestoreDataPtr = utMalloc ( sizeof ( j30rwafp5zl ) ) ;
memcpy ( BMSBalancingLogic_InitRestoreDataPtr , ( void * ) & ( j30rwafp5zl )
, sizeof ( j30rwafp5zl ) ) ; } void
mr_BMSBalancingLogic_CopyFromInitRestoreData ( ) { memcpy ( ( void * ) & (
j30rwafp5zl ) , BMSBalancingLogic_InitRestoreDataPtr , sizeof ( j30rwafp5zl )
) ; } void mr_BMSBalancingLogic_DestroyInitRestoreData ( ) { utFree (
BMSBalancingLogic_InitRestoreDataPtr ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
