#include "BMSSOCEstimation.h"
#include "rtwtypes.h"
#include "BMSSOCEstimation_private.h"
#include "BMSSOCEstimation_capi.h"
#include "rt_nonfinite.h"
int_T gtoacagi4d [ 1 ] ; static RegMdlInfo rtMdlInfo_BMSSOCEstimation [ 61 ]
= { { "pe5hyd5e5ea" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "pe5hyd5e5e" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "c1vnk4bz5ql" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "j3dscajw3tw" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "bjcz3zxgfkr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "nrhlzznkhrh" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "h3puzbdfgf2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "hjckfmofj52" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "e3awe0thaz3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "d3rumsr0qz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "jboicjttrgb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "ippvh32ghjp" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "iwvfcolfgwq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "izjsvhfdpsu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "pbiqgdx5zan" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "c1vnk4bz5q" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "j3dscajw3t" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "bjcz3zxgfk" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "nrhlzznkhr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "h3puzbdfgf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "hjckfmofj5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "e3awe0thaz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "jboicjttrg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "ippvh32ghj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "iwvfcolfgw" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "izjsvhfdps" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "pbiqgdx5za" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "fnots123ka" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "kcczw4j51s" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "oypyoif5rn" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "ioolb10wj0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "hue3c0yakn" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "bbzyccyfe5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "dllaarzzct" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "edlegkvm3f" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "juw2ywacbx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "BMSSOCEstimation" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL )
} , { "lfunyrnkklt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "gtoacagi4d" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "elgpnmgrvh5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "lqti3bxlc5b" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSSOCEstimation" } , { "hpenwvdsgo" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , { "fcomfl1sgs" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSSOCEstimation" }
, { "cuint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "uint64" }
, { "uint64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , { "cint64" ,
MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "int64" } , { "int64" ,
MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_BMSSOCEstimation_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "BMSSOCEstimation" } , { "mr_BMSSOCEstimation_SetDWork"
, MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } , {
"mr_BMSSOCEstimation_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , (
void * ) "BMSSOCEstimation" } , { "BMSSOCEstimation.h" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , { "BMSSOCEstimation.c" ,
MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * ) "BMSSOCEstimation" } } ;
aisrboyg3zp iwvfcolfgw = { 0.1F , 1.0F , 0.0F , 0.000277777785F , - 1.0F ,
0.0F , 0.0F } ; pe5hyd5e5ea pe5hyd5e5e ; pbiqgdx5zan lqti3bxlc5b ;
izjsvhfdpsu elgpnmgrvh5 ; void bbzyccyfe5 ( void ) { elgpnmgrvh5 . myrqiep04m
= ( real32_T ) rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; } void hue3c0yakn (
void ) { elgpnmgrvh5 . myrqiep04m = ( real32_T )
rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; } void BMSSOCEstimation ( const
real32_T * e4051bwwkz , real32_T * bjpjid5gap , real32_T * g1ypzcddoc ,
real32_T * hyfhu3uvbm ) { real_T y ; lqti3bxlc5b . on0gv4bqfi = elgpnmgrvh5 .
myrqiep04m ; * bjpjid5gap = lqti3bxlc5b . on0gv4bqfi ; y = 3.153 *
rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ ; lqti3bxlc5b . n2l4swgxts = (
real32_T ) y ; lqti3bxlc5b . lhesvjhzjs = iwvfcolfgw . P_5 * * e4051bwwkz ;
lqti3bxlc5b . divtw2wenk = lqti3bxlc5b . lhesvjhzjs / lqti3bxlc5b .
n2l4swgxts ; lqti3bxlc5b . o0t0us2gqo = iwvfcolfgw . P_6 * * e4051bwwkz ; *
g1ypzcddoc = iwvfcolfgw . P_7 ; * hyfhu3uvbm = iwvfcolfgw . P_8 ; } void
ioolb10wj0 ( void ) { elgpnmgrvh5 . myrqiep04m += iwvfcolfgw . P_2 *
lqti3bxlc5b . divtw2wenk ; if ( elgpnmgrvh5 . myrqiep04m >= iwvfcolfgw . P_3
) { elgpnmgrvh5 . myrqiep04m = iwvfcolfgw . P_3 ; } else if ( elgpnmgrvh5 .
myrqiep04m <= iwvfcolfgw . P_4 ) { elgpnmgrvh5 . myrqiep04m = iwvfcolfgw .
P_4 ; } } void kcczw4j51s ( void ) { fcomfl1sgs * const ileo0mwgm0 = & (
pe5hyd5e5e . rtm ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( ileo0mwgm0 -> _mdlRefSfcnS , "BMSSOCEstimation" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void dllaarzzct (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { fcomfl1sgs *
const ileo0mwgm0 = & ( pe5hyd5e5e . rtm ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( void ) memset ( ( void * ) ileo0mwgm0 , 0 , sizeof (
fcomfl1sgs ) ) ; gtoacagi4d [ 0 ] = mdlref_TID0 ; ileo0mwgm0 -> _mdlRefSfcnS
= ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( ileo0mwgm0 -> _mdlRefSfcnS , "BMSSOCEstimation" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { lqti3bxlc5b . on0gv4bqfi =
0.0F ; lqti3bxlc5b . n2l4swgxts = 0.0F ; lqti3bxlc5b . lhesvjhzjs = 0.0F ;
lqti3bxlc5b . divtw2wenk = 0.0F ; lqti3bxlc5b . o0t0us2gqo = 0.0F ; }
elgpnmgrvh5 . myrqiep04m = 0.0F ; BMSSOCEstimation_InitializeDataMapInfo (
ileo0mwgm0 , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) &&
( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI ,
rt_ChildMMIIdx , & ( ileo0mwgm0 -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath (
ileo0mwgm0 -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( ileo0mwgm0 -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_BMSSOCEstimation_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_BMSSOCEstimation , 61 ) ; * retVal = 1 ; } static void
mr_BMSSOCEstimation_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_BMSSOCEstimation_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_BMSSOCEstimation_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_BMSSOCEstimation_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_BMSSOCEstimation_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_BMSSOCEstimation_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_BMSSOCEstimation_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_BMSSOCEstimation_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_BMSSOCEstimation_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_BMSSOCEstimation_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_BMSSOCEstimation_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_BMSSOCEstimation_restoreDataFromMxArrayWithOffset
( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_BMSSOCEstimation_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_BMSSOCEstimation_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
{ mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_BMSSOCEstimation_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_BMSSOCEstimation_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_BMSSOCEstimation_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "lqti3bxlc5b" , "elgpnmgrvh5"
, "NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_BMSSOCEstimation_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( lqti3bxlc5b ) , sizeof ( lqti3bxlc5b ) ) ; { static const
char_T * rtdwDataFieldNames [ 1 ] = { "elgpnmgrvh5.myrqiep04m" , } ; mxArray
* rtdwData = mxCreateStructMatrix ( 1 , 1 , 1 , rtdwDataFieldNames ) ;
mr_BMSSOCEstimation_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( elgpnmgrvh5 . myrqiep04m ) , sizeof ( elgpnmgrvh5 . myrqiep04m ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_BMSSOCEstimation_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_BMSSOCEstimation_restoreDataFromMxArray ( ( void * ) & ( lqti3bxlc5b ) ,
ssDW , 0 , 0 , sizeof ( lqti3bxlc5b ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_BMSSOCEstimation_restoreDataFromMxArray ( ( void * ) & ( elgpnmgrvh5 .
myrqiep04m ) , rtdwData , 0 , 0 , sizeof ( elgpnmgrvh5 . myrqiep04m ) ) ; } }
void mr_BMSSOCEstimation_RegisterSimStateChecksum ( SimStruct * S ) { const
uint32_T chksum [ 4 ] = { 2541750799U , 1738969178U , 229873484U ,
2832401694U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"BMSSOCEstimation" , & chksum [ 0 ] ) ; } mxArray *
mr_BMSSOCEstimation_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
static void * BMSSOCEstimation_InitRestoreDataPtr = ( NULL ) ; void
mr_BMSSOCEstimation_CreateInitRestoreData ( ) {
BMSSOCEstimation_InitRestoreDataPtr = utMalloc ( sizeof ( elgpnmgrvh5 ) ) ;
memcpy ( BMSSOCEstimation_InitRestoreDataPtr , ( void * ) & ( elgpnmgrvh5 ) ,
sizeof ( elgpnmgrvh5 ) ) ; } void mr_BMSSOCEstimation_CopyFromInitRestoreData
( ) { memcpy ( ( void * ) & ( elgpnmgrvh5 ) ,
BMSSOCEstimation_InitRestoreDataPtr , sizeof ( elgpnmgrvh5 ) ) ; } void
mr_BMSSOCEstimation_DestroyInitRestoreData ( ) { utFree (
BMSSOCEstimation_InitRestoreDataPtr ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
