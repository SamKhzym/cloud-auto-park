#include "BMSController.h"
#include "rtwtypes.h"
#include "BMSController_private.h"
#include <string.h>
#include "BMSController_capi.h"
#include "rt_nonfinite.h"
#ifndef BMSController_MDLREF_HIDE_CHILD_
#define BMSBalancingLogic_MDLREF_HIDE_CHILD_
#endif
#include "BMSBalancingLogic.h"
#ifndef BMSController_MDLREF_HIDE_CHILD_
#define BMSOut_MDLREF_HIDE_CHILD_
#endif
#include "BMSOut.h"
#ifndef BMSController_MDLREF_HIDE_CHILD_
#define BMSCurrPowerLimCalc_MDLREF_HIDE_CHILD_
#endif
#include "BMSCurrPowerLimCalc.h"
#ifndef BMSController_MDLREF_HIDE_CHILD_
#define BMSSOCEstimation_MDLREF_HIDE_CHILD_
#endif
#include "BMSSOCEstimation.h"
#ifndef BMSController_MDLREF_HIDE_CHILD_
#define BMSStateMachine_MDLREF_HIDE_CHILD_
#endif
#include "BMSStateMachine.h"
int_T el1bl3dvlu [ 2 ] ; static RegMdlInfo rtMdlInfo_BMSController [ 62 ] = {
{ "prqjzwjjc0p" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"BMSController" } , { "prqjzwjjc0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "acitudgwjth" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"poeycoiqx2v" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "fpo3onxf5uy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "BMSController" } , { "ok3fv4t15vd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"jrticzz4uew" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "e2h3i2esib1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "BMSController" } , { "gv5ropfa2ys" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"owyh0ax5rb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "ffclwn2k3bt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "BMSController" } , { "e02yj4yvwug" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"gjtwacvis25" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "g0d32wfvf1s" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "BMSController" } , { "l5yy0qtgsji" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"acitudgwjt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "poeycoiqx2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "fpo3onxf5u" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"ok3fv4t15v" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "jrticzz4ue" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "e2h3i2esib" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"gv5ropfa2y" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "ffclwn2k3b" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "e02yj4yvwu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"gjtwacvis2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "g0d32wfvf1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "l5yy0qtgsj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"k1rkqqlwx4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "g10dj1kimi" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "dolsr1ry0j" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"dhe0j1g5mv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "n3ldsg2m4a" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "p2t1vykwji" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"lftbpoqxym" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "fron4u4vty" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "ah533pbmux" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"BMSController" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , {
"bz2c24td3ue" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "el1bl3dvlu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "hwyycww1n0f" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"m5iv0kvulag" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"BMSController" } , { "i4zyr2rvdz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "BMSController" } , { "jhg5ifokiz" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "BMSController" } , {
"struct_beekyrb3065f5ZXL7GuueB" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL )
} , { "int64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , { "cint64" ,
MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "int64" } , { "uint64" ,
MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , { "cuint64" ,
MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void * ) "uint64" } , {
"mr_BMSController_GetSimStateDisallowedBlocks" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "BMSController" } , {
"mr_BMSController_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "BMSController" } , { "mr_BMSController_cacheDataAsMxArray"
, MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "BMSController" } , { "mr_BMSController_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "BMSController" } , {
"mr_BMSController_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void *
) "BMSController" } , { "BMSController.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1
, ( NULL ) } , { "BMSController.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "BMSController" } } ; dkgtpceyogp gjtwacvis2 = { { 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F ,
3.6F , 3.6F , 3.6F , 3.6F , 3.6F , 3.6F } , { 25.0F , 25.0F , 25.0F , 25.0F ,
25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F
, 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F ,
25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F
, 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F ,
25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F
, 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F ,
25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F
, 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F ,
25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F
, 25.0F , 25.0F , 25.0F , 25.0F , 25.0F , 25.0F } , 2.0F , 345.6F , 0.0F ,
0.0F , 0.0F } ; prqjzwjjc0p prqjzwjjc0 ; l5yy0qtgsji m5iv0kvulag ;
g0d32wfvf1s hwyycww1n0f ; void ah533pbmux ( void ) {
mr_BMSStateMachine_CreateInitRestoreData ( ) ;
mr_BMSSOCEstimation_CreateInitRestoreData ( ) ;
mr_BMSBalancingLogic_CreateInitRestoreData ( ) ; } void p2t1vykwji ( void ) {
memcpy ( & hwyycww1n0f . dz4c4vv4e1 [ 0 ] , & gjtwacvis2 . P_2 [ 0 ] , 96U *
sizeof ( real32_T ) ) ; memcpy ( & hwyycww1n0f . phucyyn21j [ 0 ] , &
gjtwacvis2 . P_3 [ 0 ] , 96U * sizeof ( real32_T ) ) ; hwyycww1n0f .
ku0cdxjs3l = gjtwacvis2 . P_5 ; hwyycww1n0f . iqzga4pj3l = gjtwacvis2 . P_6 ;
hwyycww1n0f . hdl0hgqmi0 = gjtwacvis2 . P_7 ; hwyycww1n0f . hmm5af0r2l =
gjtwacvis2 . P_8 ; c4qsdumjq2 ( & m5iv0kvulag . jiylicxfpw , & m5iv0kvulag .
hqgravc0zq , & m5iv0kvulag . cx1favx45s , & m5iv0kvulag . ak2z1fsy2a , &
m5iv0kvulag . ptmoeurf21 , & m5iv0kvulag . o52oy3hcmh , & m5iv0kvulag .
bermrxiuhz , & m5iv0kvulag . f2mxcxswac , & m5iv0kvulag . ddjfgylpbb ) ;
bbzyccyfe5 ( ) ; okbayvkvs0 ( & m5iv0kvulag . c1nq0xqyh1 [ 0 ] ) ; } void
n3ldsg2m4a ( void ) { memcpy ( & hwyycww1n0f . dz4c4vv4e1 [ 0 ] , &
gjtwacvis2 . P_2 [ 0 ] , 96U * sizeof ( real32_T ) ) ; memcpy ( & hwyycww1n0f
. phucyyn21j [ 0 ] , & gjtwacvis2 . P_3 [ 0 ] , 96U * sizeof ( real32_T ) ) ;
hwyycww1n0f . ku0cdxjs3l = gjtwacvis2 . P_5 ; hwyycww1n0f . iqzga4pj3l =
gjtwacvis2 . P_6 ; hwyycww1n0f . hdl0hgqmi0 = gjtwacvis2 . P_7 ; hwyycww1n0f
. hmm5af0r2l = gjtwacvis2 . P_8 ; b24n3fhfdi ( & m5iv0kvulag . jiylicxfpw , &
m5iv0kvulag . hqgravc0zq , & m5iv0kvulag . cx1favx45s , & m5iv0kvulag .
ak2z1fsy2a , & m5iv0kvulag . ptmoeurf21 , & m5iv0kvulag . o52oy3hcmh , &
m5iv0kvulag . bermrxiuhz , & m5iv0kvulag . f2mxcxswac , & m5iv0kvulag .
ddjfgylpbb ) ; hue3c0yakn ( ) ; l0kmnlkf5y ( & m5iv0kvulag . c1nq0xqyh1 [ 0 ]
) ; } void BMSController ( boolean_T * e4kvz4supm , real32_T * a3l2j3y4lx ,
real32_T * niiizijeve , real32_T * kvl2ul33en , real32_T * e2rd4hsap2 ,
real32_T * oqx2ehimcf , real32_T * nhnyktxrfk , real32_T * h4i5vc02af ,
boolean_T * chullyjun0 , boolean_T * gamv4ws2w2 , boolean_T * lxuopn21da ,
boolean_T * jcpgvzmuwo , boolean_T * jqswid45re , boolean_T * amy4ujr4ow ,
boolean_T kv4f4pyu01 [ 96 ] ) { jhg5ifokiz * const lynqqvz3ra = & (
prqjzwjjc0 . rtm ) ; memcpy ( & m5iv0kvulag . fm55o01te2 [ 0 ] , &
hwyycww1n0f . dz4c4vv4e1 [ 0 ] , 96U * sizeof ( real32_T ) ) ; memcpy ( &
m5iv0kvulag . ochexbavmj [ 0 ] , & hwyycww1n0f . phucyyn21j [ 0 ] , 96U *
sizeof ( real32_T ) ) ; BMSCurrPowerLimCalc ( & m5iv0kvulag . fm55o01te2 [ 0
] , & m5iv0kvulag . ochexbavmj [ 0 ] , & m5iv0kvulag . naz14vswl4 , &
m5iv0kvulag . fpmd2bpykz , & m5iv0kvulag . idni5bub1a , & m5iv0kvulag .
fcyzlyudv4 , & m5iv0kvulag . aqhr4jyxka , & m5iv0kvulag . obpivodrhe ) ;
m5iv0kvulag . ofsd5tege5 = hwyycww1n0f . ku0cdxjs3l ; m5iv0kvulag .
j0j04ul1wd = hwyycww1n0f . iqzga4pj3l ; m5iv0kvulag . citku4fcqi =
hwyycww1n0f . hdl0hgqmi0 ; m5iv0kvulag . fykqayal22 = hwyycww1n0f .
hmm5af0r2l ; BMSStateMachine ( & gjtwacvis2 . P_4 , & m5iv0kvulag .
fm55o01te2 [ 0 ] , & m5iv0kvulag . ofsd5tege5 , & m5iv0kvulag . j0j04ul1wd ,
& m5iv0kvulag . citku4fcqi , & m5iv0kvulag . fykqayal22 , & m5iv0kvulag .
naz14vswl4 , & m5iv0kvulag . fpmd2bpykz , & m5iv0kvulag . idni5bub1a , &
m5iv0kvulag . fcyzlyudv4 , & m5iv0kvulag . aqhr4jyxka , & m5iv0kvulag .
obpivodrhe , & m5iv0kvulag . jiylicxfpw , & m5iv0kvulag . hqgravc0zq , &
m5iv0kvulag . cx1favx45s , & m5iv0kvulag . ak2z1fsy2a , & m5iv0kvulag .
ptmoeurf21 , & m5iv0kvulag . o52oy3hcmh , & m5iv0kvulag . bermrxiuhz , &
m5iv0kvulag . f2mxcxswac , & m5iv0kvulag . ddjfgylpbb ) ; BMSSOCEstimation (
& m5iv0kvulag . j0j04ul1wd , & m5iv0kvulag . jbdnp5lsqc , & m5iv0kvulag .
d2znwfvjz5 , & m5iv0kvulag . o5lorxl1t2 ) ; if ( rtmIsSampleHit ( lynqqvz3ra
, 1 , 0 ) ) { hwyycww1n0f . kxvz5gfvp4 = m5iv0kvulag . ddjfgylpbb ;
m5iv0kvulag . jscb4sqqxg = hwyycww1n0f . kxvz5gfvp4 ; memcpy ( & hwyycww1n0f
. m3mj3jyjio [ 0 ] , & m5iv0kvulag . fm55o01te2 [ 0 ] , 96U * sizeof (
real32_T ) ) ; memcpy ( & m5iv0kvulag . j02uwajpkc [ 0 ] , & hwyycww1n0f .
m3mj3jyjio [ 0 ] , 96U * sizeof ( real32_T ) ) ; hwyycww1n0f . lizezojaqr =
m5iv0kvulag . fcyzlyudv4 ; m5iv0kvulag . dpehvequ4b = hwyycww1n0f .
lizezojaqr ; hwyycww1n0f . ldt520oxg4 = m5iv0kvulag . idni5bub1a ;
m5iv0kvulag . mdxoqaymv2 = hwyycww1n0f . ldt520oxg4 ; BMSBalancingLogic ( &
m5iv0kvulag . jscb4sqqxg , & m5iv0kvulag . j02uwajpkc [ 0 ] , & m5iv0kvulag .
dpehvequ4b , & m5iv0kvulag . mdxoqaymv2 , & m5iv0kvulag . c1nq0xqyh1 [ 0 ] )
; } BMSOut ( & m5iv0kvulag . naz14vswl4 , & m5iv0kvulag . fpmd2bpykz , &
m5iv0kvulag . jiylicxfpw , & m5iv0kvulag . hqgravc0zq , & m5iv0kvulag .
cx1favx45s , & m5iv0kvulag . ak2z1fsy2a , & m5iv0kvulag . ptmoeurf21 , &
m5iv0kvulag . o52oy3hcmh , & m5iv0kvulag . bermrxiuhz , & m5iv0kvulag .
f2mxcxswac , & m5iv0kvulag . ddjfgylpbb , & m5iv0kvulag . jbdnp5lsqc , &
m5iv0kvulag . d2znwfvjz5 , & m5iv0kvulag . o5lorxl1t2 , & m5iv0kvulag .
c1nq0xqyh1 [ 0 ] , oqx2ehimcf , nhnyktxrfk , h4i5vc02af , chullyjun0 ,
gamv4ws2w2 , lxuopn21da , jcpgvzmuwo , jqswid45re , amy4ujr4ow , & kv4f4pyu01
[ 0 ] , e4kvz4supm , a3l2j3y4lx , niiizijeve , kvl2ul33en , e2rd4hsap2 ) ; }
void dhe0j1g5mv ( const real32_T adxekd5tio [ 96 ] , const real32_T
j3wvkhbfe4 [ 96 ] , const real32_T * alolnomync , const real32_T * gr0s1ny5og
, const real32_T * cne0zycowu , const real32_T * lvjqgkdjmc ) { memcpy ( &
hwyycww1n0f . dz4c4vv4e1 [ 0 ] , & adxekd5tio [ 0 ] , 96U * sizeof ( real32_T
) ) ; memcpy ( & hwyycww1n0f . phucyyn21j [ 0 ] , & j3wvkhbfe4 [ 0 ] , 96U *
sizeof ( real32_T ) ) ; hwyycww1n0f . ku0cdxjs3l = * alolnomync ; hwyycww1n0f
. iqzga4pj3l = * lvjqgkdjmc ; hwyycww1n0f . hdl0hgqmi0 = * gr0s1ny5og ;
hwyycww1n0f . hmm5af0r2l = * cne0zycowu ; ioolb10wj0 ( ) ; } void dolsr1ry0j
( void ) { mr_BMSStateMachine_DestroyInitRestoreData ( ) ;
mr_BMSSOCEstimation_DestroyInitRestoreData ( ) ;
mr_BMSBalancingLogic_DestroyInitRestoreData ( ) ; } void g10dj1kimi ( void )
{ jhg5ifokiz * const lynqqvz3ra = & ( prqjzwjjc0 . rtm ) ; du2aze3q0u ( ) ;
jqgqne15uw ( ) ; kcczw4j51s ( ) ; jozn1uvmvd ( ) ; jhgahwtvq0 ( ) ; if ( !
slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( lynqqvz3ra ->
_mdlRefSfcnS , "BMSController" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT"
) ; } } void lftbpoqxym ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 ,
int_T mdlref_TID1 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { jhg5ifokiz * const lynqqvz3ra = & (
prqjzwjjc0 . rtm ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset
( ( void * ) lynqqvz3ra , 0 , sizeof ( jhg5ifokiz ) ) ; el1bl3dvlu [ 0 ] =
mdlref_TID0 ; el1bl3dvlu [ 1 ] = mdlref_TID1 ; lynqqvz3ra -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( lynqqvz3ra -> _mdlRefSfcnS , "BMSController" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } ( void ) memset ( ( ( void *
) & m5iv0kvulag ) , 0 , sizeof ( l5yy0qtgsji ) ) ; { int32_T i ; for ( i = 0
; i < 96 ; i ++ ) { m5iv0kvulag . fm55o01te2 [ i ] = 0.0F ; } for ( i = 0 ; i
< 96 ; i ++ ) { m5iv0kvulag . ochexbavmj [ i ] = 0.0F ; } for ( i = 0 ; i <
96 ; i ++ ) { m5iv0kvulag . j02uwajpkc [ i ] = 0.0F ; } m5iv0kvulag .
naz14vswl4 = 0.0F ; m5iv0kvulag . fpmd2bpykz = 0.0F ; m5iv0kvulag .
idni5bub1a = 0.0F ; m5iv0kvulag . fcyzlyudv4 = 0.0F ; m5iv0kvulag .
aqhr4jyxka = 0.0F ; m5iv0kvulag . obpivodrhe = 0.0F ; m5iv0kvulag .
ofsd5tege5 = 0.0F ; m5iv0kvulag . j0j04ul1wd = 0.0F ; m5iv0kvulag .
citku4fcqi = 0.0F ; m5iv0kvulag . fykqayal22 = 0.0F ; m5iv0kvulag .
jiylicxfpw = 0.0F ; m5iv0kvulag . ddjfgylpbb = 0.0F ; m5iv0kvulag .
jbdnp5lsqc = 0.0F ; m5iv0kvulag . d2znwfvjz5 = 0.0F ; m5iv0kvulag .
o5lorxl1t2 = 0.0F ; m5iv0kvulag . jscb4sqqxg = 0.0F ; m5iv0kvulag .
dpehvequ4b = 0.0F ; m5iv0kvulag . mdxoqaymv2 = 0.0F ; } { int32_T i ; for ( i
= 0 ; i < 96 ; i ++ ) { hwyycww1n0f . dz4c4vv4e1 [ i ] = 0.0F ; } } { int32_T
i ; for ( i = 0 ; i < 96 ; i ++ ) { hwyycww1n0f . phucyyn21j [ i ] = 0.0F ; }
} hwyycww1n0f . ku0cdxjs3l = 0.0F ; hwyycww1n0f . iqzga4pj3l = 0.0F ;
hwyycww1n0f . hdl0hgqmi0 = 0.0F ; hwyycww1n0f . hmm5af0r2l = 0.0F ;
hwyycww1n0f . kxvz5gfvp4 = 0.0F ; { int32_T i ; for ( i = 0 ; i < 96 ; i ++ )
{ hwyycww1n0f . m3mj3jyjio [ i ] = 0.0F ; } } hwyycww1n0f . lizezojaqr = 0.0F
; hwyycww1n0f . ldt520oxg4 = 0.0F ; BMSController_InitializeDataMapInfo (
lynqqvz3ra , sysRanPtr , contextTid ) ; bjd0wkxsam ( _mdlRefSfcnS ,
mdlref_TID1 , lynqqvz3ra -> DataMapInfo . systemRan [ 0 ] , lynqqvz3ra ->
DataMapInfo . systemTid [ 0 ] , & ( lynqqvz3ra -> DataMapInfo . mmi ) ,
"BMSController/Balancing Logic" , 0 , - 1 ) ; gzneizzges ( _mdlRefSfcnS ,
mdlref_TID0 , mdlref_TID1 , lynqqvz3ra -> DataMapInfo . systemRan [ 0 ] ,
lynqqvz3ra -> DataMapInfo . systemTid [ 0 ] , & ( lynqqvz3ra -> DataMapInfo .
mmi ) , "BMSController/BMS Out" , 1 , - 1 ) ; mmipgl5oaa ( _mdlRefSfcnS ,
mdlref_TID0 , lynqqvz3ra -> DataMapInfo . systemRan [ 0 ] , lynqqvz3ra ->
DataMapInfo . systemTid [ 0 ] , & ( lynqqvz3ra -> DataMapInfo . mmi ) ,
"BMSController/Current Power Limits Calc" , 2 , - 1 ) ; dllaarzzct (
_mdlRefSfcnS , mdlref_TID0 , lynqqvz3ra -> DataMapInfo . systemRan [ 0 ] ,
lynqqvz3ra -> DataMapInfo . systemTid [ 0 ] , & ( lynqqvz3ra -> DataMapInfo .
mmi ) , "BMSController/SOC Estimation" , 3 , - 1 ) ; n2eo0cythm (
_mdlRefSfcnS , mdlref_TID0 , lynqqvz3ra -> DataMapInfo . systemRan [ 0 ] ,
lynqqvz3ra -> DataMapInfo . systemTid [ 0 ] , & ( lynqqvz3ra -> DataMapInfo .
mmi ) , "BMSController/State Machine" , 4 , - 1 ) ; if ( ( rt_ParentMMI != (
NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( *
rt_ParentMMI , rt_ChildMMIIdx , & ( lynqqvz3ra -> DataMapInfo . mmi ) ) ;
rtwCAPI_SetPath ( lynqqvz3ra -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( lynqqvz3ra -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_BMSController_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) {
mr_BMSBalancingLogic_MdlInfoRegFcn ( mdlRefSfcnS , "BMSBalancingLogic" ,
retVal ) ; if ( * retVal == 0 ) return ; * retVal = 0 ;
mr_BMSOut_MdlInfoRegFcn ( mdlRefSfcnS , "BMSOut" , retVal ) ; if ( * retVal
== 0 ) return ; * retVal = 0 ; mr_BMSCurrPowerLimCalc_MdlInfoRegFcn (
mdlRefSfcnS , "BMSCurrPowerLimCalc" , retVal ) ; if ( * retVal == 0 ) return
; * retVal = 0 ; mr_BMSSOCEstimation_MdlInfoRegFcn ( mdlRefSfcnS ,
"BMSSOCEstimation" , retVal ) ; if ( * retVal == 0 ) return ; * retVal = 0 ;
mr_BMSStateMachine_MdlInfoRegFcn ( mdlRefSfcnS , "BMSStateMachine" , retVal )
; if ( * retVal == 0 ) return ; * retVal = 0 ; } } * retVal = 0 ;
ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName , rtMdlInfo_BMSController , 62
) ; * retVal = 1 ; } static void mr_BMSController_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_BMSController_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) {
mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_BMSController_restoreDataFromMxArray ( void
* destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes )
; static void mr_BMSController_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_BMSController_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_BMSController_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T )
bitVal ) ) ; } static uint_T mr_BMSController_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_BMSController_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_BMSController_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_BMSController_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_BMSController_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_BMSController_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_BMSController_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_BMSController_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_BMSController_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_BMSController_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_BMSController_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "m5iv0kvulag" , "hwyycww1n0f" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_BMSController_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( m5iv0kvulag ) , sizeof ( m5iv0kvulag ) ) ; { static const
char_T * rtdwDataFieldNames [ 15 ] = { "BMSBalancingLogic" , "BMSOut" ,
"BMSCurrPowerLimCalc" , "BMSSOCEstimation" , "BMSStateMachine" ,
"hwyycww1n0f.dz4c4vv4e1" , "hwyycww1n0f.phucyyn21j" ,
"hwyycww1n0f.ku0cdxjs3l" , "hwyycww1n0f.iqzga4pj3l" ,
"hwyycww1n0f.hdl0hgqmi0" , "hwyycww1n0f.hmm5af0r2l" ,
"hwyycww1n0f.kxvz5gfvp4" , "hwyycww1n0f.m3mj3jyjio" ,
"hwyycww1n0f.lizezojaqr" , "hwyycww1n0f.ldt520oxg4" , } ; mxArray * rtdwData
= mxCreateStructMatrix ( 1 , 1 , 15 , rtdwDataFieldNames ) ; { mxArray *
varData = mr_BMSBalancingLogic_GetDWork ( ) ; mxSetFieldByNumber ( rtdwData ,
0 , 0 , varData ) ; } { mxArray * varData = mr_BMSOut_GetDWork ( ) ;
mxSetFieldByNumber ( rtdwData , 0 , 1 , varData ) ; } { mxArray * varData =
mr_BMSCurrPowerLimCalc_GetDWork ( ) ; mxSetFieldByNumber ( rtdwData , 0 , 2 ,
varData ) ; } { mxArray * varData = mr_BMSSOCEstimation_GetDWork ( ) ;
mxSetFieldByNumber ( rtdwData , 0 , 3 , varData ) ; } { mxArray * varData =
mr_BMSStateMachine_GetDWork ( ) ; mxSetFieldByNumber ( rtdwData , 0 , 4 ,
varData ) ; } mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 5 , (
const void * ) & ( hwyycww1n0f . dz4c4vv4e1 ) , sizeof ( hwyycww1n0f .
dz4c4vv4e1 ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 6 , (
const void * ) & ( hwyycww1n0f . phucyyn21j ) , sizeof ( hwyycww1n0f .
phucyyn21j ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 7 , (
const void * ) & ( hwyycww1n0f . ku0cdxjs3l ) , sizeof ( hwyycww1n0f .
ku0cdxjs3l ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 8 , (
const void * ) & ( hwyycww1n0f . iqzga4pj3l ) , sizeof ( hwyycww1n0f .
iqzga4pj3l ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 9 , (
const void * ) & ( hwyycww1n0f . hdl0hgqmi0 ) , sizeof ( hwyycww1n0f .
hdl0hgqmi0 ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 10 , (
const void * ) & ( hwyycww1n0f . hmm5af0r2l ) , sizeof ( hwyycww1n0f .
hmm5af0r2l ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 11 , (
const void * ) & ( hwyycww1n0f . kxvz5gfvp4 ) , sizeof ( hwyycww1n0f .
kxvz5gfvp4 ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 12 , (
const void * ) & ( hwyycww1n0f . m3mj3jyjio ) , sizeof ( hwyycww1n0f .
m3mj3jyjio ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 13 , (
const void * ) & ( hwyycww1n0f . lizezojaqr ) , sizeof ( hwyycww1n0f .
lizezojaqr ) ) ; mr_BMSController_cacheDataAsMxArray ( rtdwData , 0 , 14 , (
const void * ) & ( hwyycww1n0f . ldt520oxg4 ) , sizeof ( hwyycww1n0f .
ldt520oxg4 ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return
ssDW ; } void mr_BMSController_SetDWork ( const mxArray * ssDW ) { ( void )
ssDW ; mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( m5iv0kvulag )
, ssDW , 0 , 0 , sizeof ( m5iv0kvulag ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_BMSBalancingLogic_SetDWork (
mxGetFieldByNumber ( rtdwData , 0 , 0 ) ) ; mr_BMSOut_SetDWork (
mxGetFieldByNumber ( rtdwData , 0 , 1 ) ) ; mr_BMSCurrPowerLimCalc_SetDWork (
mxGetFieldByNumber ( rtdwData , 0 , 2 ) ) ; mr_BMSSOCEstimation_SetDWork (
mxGetFieldByNumber ( rtdwData , 0 , 3 ) ) ; mr_BMSStateMachine_SetDWork (
mxGetFieldByNumber ( rtdwData , 0 , 4 ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
dz4c4vv4e1 ) , rtdwData , 0 , 5 , sizeof ( hwyycww1n0f . dz4c4vv4e1 ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
phucyyn21j ) , rtdwData , 0 , 6 , sizeof ( hwyycww1n0f . phucyyn21j ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
ku0cdxjs3l ) , rtdwData , 0 , 7 , sizeof ( hwyycww1n0f . ku0cdxjs3l ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
iqzga4pj3l ) , rtdwData , 0 , 8 , sizeof ( hwyycww1n0f . iqzga4pj3l ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
hdl0hgqmi0 ) , rtdwData , 0 , 9 , sizeof ( hwyycww1n0f . hdl0hgqmi0 ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
hmm5af0r2l ) , rtdwData , 0 , 10 , sizeof ( hwyycww1n0f . hmm5af0r2l ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
kxvz5gfvp4 ) , rtdwData , 0 , 11 , sizeof ( hwyycww1n0f . kxvz5gfvp4 ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
m3mj3jyjio ) , rtdwData , 0 , 12 , sizeof ( hwyycww1n0f . m3mj3jyjio ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
lizezojaqr ) , rtdwData , 0 , 13 , sizeof ( hwyycww1n0f . lizezojaqr ) ) ;
mr_BMSController_restoreDataFromMxArray ( ( void * ) & ( hwyycww1n0f .
ldt520oxg4 ) , rtdwData , 0 , 14 , sizeof ( hwyycww1n0f . ldt520oxg4 ) ) ; }
} void mr_BMSController_RegisterSimStateChecksum ( SimStruct * S ) { const
uint32_T chksum [ 4 ] = { 839254791U , 3471683030U , 510246563U , 1074645254U
, } ; slmrModelRefRegisterSimStateChecksum ( S , "BMSController" , & chksum [
0 ] ) ; mr_BMSBalancingLogic_RegisterSimStateChecksum ( S ) ;
mr_BMSCurrPowerLimCalc_RegisterSimStateChecksum ( S ) ;
mr_BMSOut_RegisterSimStateChecksum ( S ) ;
mr_BMSSOCEstimation_RegisterSimStateChecksum ( S ) ;
mr_BMSStateMachine_RegisterSimStateChecksum ( S ) ; } mxArray *
mr_BMSController_GetSimStateDisallowedBlocks ( ) { mxArray * data = NULL ;
size_t numChildrenWithDisallowedBlocks = 0 ; size_t numBlocks = 0 ; mxArray *
disallowedBlocksInChild [ 5 ] ; disallowedBlocksInChild [ 0 ] =
mr_BMSBalancingLogic_GetSimStateDisallowedBlocks ( ) ;
disallowedBlocksInChild [ 1 ] =
mr_BMSCurrPowerLimCalc_GetSimStateDisallowedBlocks ( ) ;
disallowedBlocksInChild [ 2 ] = mr_BMSOut_GetSimStateDisallowedBlocks ( ) ;
disallowedBlocksInChild [ 3 ] =
mr_BMSSOCEstimation_GetSimStateDisallowedBlocks ( ) ; disallowedBlocksInChild
[ 4 ] = mr_BMSStateMachine_GetSimStateDisallowedBlocks ( ) ; { size_t i ; for
( i = 0 ; i < 5 ; ++ i ) { mxArray * data_i = disallowedBlocksInChild [ i ] ;
if ( ( NULL ) != data_i ) { if ( 0 == numChildrenWithDisallowedBlocks ++ ) {
data = data_i ; } numBlocks += mxGetM ( data_i ) ; } } } if (
numChildrenWithDisallowedBlocks > 1 ) { mwIndex subs [ 2 ] , offset ; data =
mxCreateCellMatrix ( numBlocks , 3 ) ; subs [ 0 ] = 0 ; { size_t i ; for ( i
= 0 ; i < 5 ; ++ i ) { mxArray * data_i = disallowedBlocksInChild [ i ] ; if
( ( NULL ) != data_i ) { mwIndex subs_i [ 2 ] , offset_i ; const mwIndex
numRows_i = ( mwIndex ) mxGetM ( data_i ) ; for ( subs_i [ 0 ] = 0 ; subs_i [
0 ] < numRows_i ; ++ ( subs_i [ 0 ] ) ) { mwIndex j ; for ( j = 0 ; j < 3 ;
++ j ) { mxArray * data_ij ; subs_i [ 1 ] = j ; offset_i =
mxCalcSingleSubscript ( data_i , 2 , subs_i ) ; data_ij = mxGetCell ( data_i
, offset_i ) ; data_ij = mxDuplicateArray ( data_ij ) ; subs [ 1 ] = j ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , data_ij ) ; } ++ ( subs [ 0 ] ) ; } mxDestroyArray ( data_i ) ; } }
} } return data ; } static void * BMSController_InitRestoreDataPtr = ( NULL )
; void mr_BMSController_CreateInitRestoreData ( ) {
BMSController_InitRestoreDataPtr = utMalloc ( sizeof ( hwyycww1n0f ) ) ;
memcpy ( BMSController_InitRestoreDataPtr , ( void * ) & ( hwyycww1n0f ) ,
sizeof ( hwyycww1n0f ) ) ; } void mr_BMSController_CopyFromInitRestoreData (
) { memcpy ( ( void * ) & ( hwyycww1n0f ) , BMSController_InitRestoreDataPtr
, sizeof ( hwyycww1n0f ) ) ; } void mr_BMSController_DestroyInitRestoreData (
) { utFree ( BMSController_InitRestoreDataPtr ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
