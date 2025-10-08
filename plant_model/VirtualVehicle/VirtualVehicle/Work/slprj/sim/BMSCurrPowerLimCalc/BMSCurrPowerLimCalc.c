#include "BMSCurrPowerLimCalc.h"
#include "rtwtypes.h"
#include "BMSCurrPowerLimCalc_private.h"
#include "mwmathutil.h"
#include "BMSCurrPowerLimCalc_capi.h"
#include "look1_iflf_binlcpw.h"
#include "rt_nonfinite.h"
int_T fiuo2fvsaw [ 1 ] ; static RegMdlInfo rtMdlInfo_BMSCurrPowerLimCalc [ 58
] = { { "ozx2hltu2vi" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "ozx2hltu2v" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "nmbd3k1hcqd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "jqacrkovtgj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "kiyn2oqhw5t" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "l1pzasquykl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "no0rimu42g3" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "e3peyfr5rur" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "idaqzyvejii" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "iyfkxzcwei" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "jqopypj5klf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "hg1vudkp1ra" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "ex3wbp43ezq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "nqqhrasv32q" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "civiuhml2am" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "nmbd3k1hcq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "jqacrkovtg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "kiyn2oqhw5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "l1pzasquyk" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "no0rimu42g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "e3peyfr5ru" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "idaqzyveji" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "jqopypj5kl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "hg1vudkp1r" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "ex3wbp43ez" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "nqqhrasv32" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "civiuhml2a" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "dvtlb0ngqi" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "du2aze3q0u" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "j4krnruoer" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "mmipgl5oaa" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "osess5f5ln" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "kdkufhgnej" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "BMSCurrPowerLimCalc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , (
NULL ) } , { "d15eg0y2siy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "BMSCurrPowerLimCalc" } , { "fiuo2fvsaw" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "h4j4xwequgc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } , { "nnj3wcguse" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , { "fff1on5pla" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc"
} , { "MinCellVoltDchrgCurrentLimTable" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , (
NULL ) } , { "cuint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * )
"uint64" } , { "uint64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"cint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "int64" } , {
"int64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_BMSCurrPowerLimCalc_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"mr_BMSCurrPowerLimCalc_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , (
void * ) "BMSCurrPowerLimCalc" } , { "mr_BMSCurrPowerLimCalc_GetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSCurrPowerLimCalc" } , {
"BMSCurrPowerLimCalc.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , {
"BMSCurrPowerLimCalc.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"BMSCurrPowerLimCalc" } } ; c4f4hs3f30w ex3wbp43ez = { { 1.0F , 0.8F , 0.5F ,
0.3F , 0.0F } , { 40.0F , 45.0F , 50.0F , 55.0F , 60.0F } , { 0.1F , 0.2F ,
0.3F , 0.3F , 0.5F , 1.0F , 1.0F } , { - 15.0F , - 10.0F , - 5.0F , 0.0F ,
5.0F , 10.0F , 15.0F } , { 1.0F , 0.8F , 0.3F , 0.3F } , { 3.9F , 4.0F ,
4.15F , 4.2F } , 6.36F , { 1.0F , 0.5F , 0.3F , 0.0F } , { 40.0F , 45.0F ,
50.0F , 60.0F } , { 0.0F , 0.2F , 0.3F , 0.5F , 0.75F , 1.0F , 1.0F } , { -
10.0F , - 5.0F , 0.0F , 5.0F , 10.0F , 15.0F , 20.0F } , { 0.0F , 0.5F , 1.0F
} , { 2.5F , 2.75F , 3.0F } , - 20.0F } ; ozx2hltu2vi ozx2hltu2v ;
civiuhml2am h4j4xwequgc ; void BMSCurrPowerLimCalc ( const real32_T
d51msl4tbc [ 96 ] , const real32_T noulgqqcoo [ 96 ] , real32_T * oqmgsset2u
, real32_T * kouqt1hzal , real32_T * kv5an1dmb2 , real32_T * ii5nemx5k0 ,
real32_T * bnkpia5wne , real32_T * jqa42ursw1 ) { int32_T sigIdx ; real32_T
minV ; minV = d51msl4tbc [ 0 ] ; for ( sigIdx = 0 ; sigIdx < 95 ; sigIdx ++ )
{ minV = muSingleScalarMin ( minV , d51msl4tbc [ sigIdx + 1 ] ) ; } *
kv5an1dmb2 = minV ; minV = noulgqqcoo [ 0 ] ; for ( sigIdx = 0 ; sigIdx < 95
; sigIdx ++ ) { minV = muSingleScalarMin ( minV , noulgqqcoo [ sigIdx + 1 ] )
; } * bnkpia5wne = minV ; minV = d51msl4tbc [ 0 ] ; for ( sigIdx = 0 ; sigIdx
< 95 ; sigIdx ++ ) { minV = muSingleScalarMax ( minV , d51msl4tbc [ sigIdx +
1 ] ) ; } * ii5nemx5k0 = minV ; minV = noulgqqcoo [ 0 ] ; for ( sigIdx = 0 ;
sigIdx < 95 ; sigIdx ++ ) { minV = muSingleScalarMax ( minV , noulgqqcoo [
sigIdx + 1 ] ) ; } * jqa42ursw1 = minV ; h4j4xwequgc . kzwd3zcngx =
look1_iflf_binlcpw ( * jqa42ursw1 , ex3wbp43ez . P_2 , ex3wbp43ez . P_1 , 4U
) ; h4j4xwequgc . aeprfjl3kx = look1_iflf_binlcpw ( * bnkpia5wne , ex3wbp43ez
. P_4 , ex3wbp43ez . P_3 , 6U ) ; h4j4xwequgc . mk2iwpm1fg =
look1_iflf_binlcpw ( * ii5nemx5k0 , ex3wbp43ez . P_6 , ex3wbp43ez . P_5 , 3U
) ; minV = muSingleScalarMin ( h4j4xwequgc . mk2iwpm1fg , h4j4xwequgc .
aeprfjl3kx ) ; minV = muSingleScalarMin ( minV , h4j4xwequgc . kzwd3zcngx ) ;
h4j4xwequgc . duxxagti3l = minV ; h4j4xwequgc . b5d3twimrf = ex3wbp43ez . P_7
* h4j4xwequgc . duxxagti3l ; * kouqt1hzal = ( real32_T )
rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ * h4j4xwequgc . b5d3twimrf ;
h4j4xwequgc . nku4mutalv = look1_iflf_binlcpw ( * jqa42ursw1 , ex3wbp43ez .
P_9 , ex3wbp43ez . P_8 , 3U ) ; h4j4xwequgc . ohynwgzz3h = look1_iflf_binlcpw
( * bnkpia5wne , ex3wbp43ez . P_11 , ex3wbp43ez . P_10 , 6U ) ; h4j4xwequgc .
fpy5pmxjjs = look1_iflf_binlcpw ( * kv5an1dmb2 , ex3wbp43ez . P_13 ,
ex3wbp43ez . P_12 , 2U ) ; minV = muSingleScalarMin ( h4j4xwequgc .
fpy5pmxjjs , h4j4xwequgc . ohynwgzz3h ) ; minV = muSingleScalarMin ( minV ,
h4j4xwequgc . nku4mutalv ) ; h4j4xwequgc . aals4xubwl = minV ; h4j4xwequgc .
hbskhuqry0 = ex3wbp43ez . P_14 * h4j4xwequgc . aals4xubwl ; * oqmgsset2u = (
real32_T ) rtP__PlntBattModNumCellPar2f2BatteryDCDC_sldd_ * h4j4xwequgc .
hbskhuqry0 ; } void du2aze3q0u ( void ) { fff1on5pla * const jhq13jgrxf = & (
ozx2hltu2v . rtm ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( jhq13jgrxf -> _mdlRefSfcnS , "BMSCurrPowerLimCalc" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void mmipgl5oaa (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { fff1on5pla *
const jhq13jgrxf = & ( ozx2hltu2v . rtm ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( void ) memset ( ( void * ) jhq13jgrxf , 0 , sizeof (
fff1on5pla ) ) ; fiuo2fvsaw [ 0 ] = mdlref_TID0 ; jhq13jgrxf -> _mdlRefSfcnS
= ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( jhq13jgrxf -> _mdlRefSfcnS , "BMSCurrPowerLimCalc" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { h4j4xwequgc . kzwd3zcngx =
0.0F ; h4j4xwequgc . aeprfjl3kx = 0.0F ; h4j4xwequgc . mk2iwpm1fg = 0.0F ;
h4j4xwequgc . duxxagti3l = 0.0F ; h4j4xwequgc . b5d3twimrf = 0.0F ;
h4j4xwequgc . nku4mutalv = 0.0F ; h4j4xwequgc . ohynwgzz3h = 0.0F ;
h4j4xwequgc . fpy5pmxjjs = 0.0F ; h4j4xwequgc . aals4xubwl = 0.0F ;
h4j4xwequgc . hbskhuqry0 = 0.0F ; } BMSCurrPowerLimCalc_InitializeDataMapInfo
( jhq13jgrxf , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) )
&& ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI ,
rt_ChildMMIIdx , & ( jhq13jgrxf -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath (
jhq13jgrxf -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( jhq13jgrxf -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_BMSCurrPowerLimCalc_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_BMSCurrPowerLimCalc , 58 ) ; * retVal = 1 ; } static void
mr_BMSCurrPowerLimCalc_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_BMSCurrPowerLimCalc_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_BMSCurrPowerLimCalc_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_BMSCurrPowerLimCalc_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_BMSCurrPowerLimCalc_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) ; static void
mr_BMSCurrPowerLimCalc_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_BMSCurrPowerLimCalc_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_BMSCurrPowerLimCalc_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_BMSCurrPowerLimCalc_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_BMSCurrPowerLimCalc_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_BMSCurrPowerLimCalc_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_BMSCurrPowerLimCalc_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_BMSCurrPowerLimCalc_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_BMSCurrPowerLimCalc_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_BMSCurrPowerLimCalc_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_BMSCurrPowerLimCalc_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_BMSCurrPowerLimCalc_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "h4j4xwequgc" , "NULL_DW" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_BMSCurrPowerLimCalc_cacheDataAsMxArray ( ssDW , 0 , 0 ,
( const void * ) & ( h4j4xwequgc ) , sizeof ( h4j4xwequgc ) ) ; return ssDW ;
} void mr_BMSCurrPowerLimCalc_SetDWork ( const mxArray * ssDW ) { ( void )
ssDW ; mr_BMSCurrPowerLimCalc_restoreDataFromMxArray ( ( void * ) & (
h4j4xwequgc ) , ssDW , 0 , 0 , sizeof ( h4j4xwequgc ) ) ; } void
mr_BMSCurrPowerLimCalc_RegisterSimStateChecksum ( SimStruct * S ) { const
uint32_T chksum [ 4 ] = { 154579251U , 2932336312U , 2278885593U ,
4289362699U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"BMSCurrPowerLimCalc" , & chksum [ 0 ] ) ; } mxArray *
mr_BMSCurrPowerLimCalc_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
