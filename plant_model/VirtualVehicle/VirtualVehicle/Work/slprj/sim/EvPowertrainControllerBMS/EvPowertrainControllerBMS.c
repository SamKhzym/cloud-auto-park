#include "EvPowertrainControllerBMS.h"
#include "rtwtypes.h"
#include "EvPowertrainControllerBMS_private.h"
#include "mwmathutil.h"
#include "EvPowertrainControllerBMS_capi.h"
#include "look1_binlcapw.h"
#include "look2_binlcapw.h"
#include "rt_nonfinite.h"
static RegMdlInfo rtMdlInfo_EvPowertrainControllerBMS [ 43 ] = { {
"ngz2pfeakpt" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "gyajxgdclx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "o3rn2hxtju" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "ctsaghyzop" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "g20grabgda" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "cvxbj1nfpu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "blkvh0pnud" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "dczz10nv5n" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "ewhlpgmju5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "mha1vmsaor" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "hveluuzkmw" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "elpuusdl0x" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "ab4o0w050u" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "lsoeg0nito" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "nfhm0izzpq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "b3eofzzeql" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "nar4n4keem" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "cdlti3213i" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "aqzgcfjqsf" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "f5tbg1pt2m" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "a4hfskmsh4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "EvPowertrainControllerBMS" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "bhvhtz1xwv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "nfq1kx1roz" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "obv4iumo0b" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainControllerBMS" } , { "cuint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0
, - 1 , ( void * ) "uint64" } , { "uint64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1
, ( NULL ) } , { "cint64" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 , ( void *
) "int64" } , { "int64" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_EvPowertrainControllerBMS_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_cacheDataAsMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainControllerBMS"
} , { "mr_EvPowertrainControllerBMS_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "EvPowertrainControllerBMS" } , {
"mr_EvPowertrainControllerBMS_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "EvPowertrainControllerBMS" } , {
"EvPowertrainControllerBMS.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL )
} , { "EvPowertrainControllerBMS.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "EvPowertrainControllerBMS" } } ; c5hhynsofi4 c5hhynsofi = { 0.0 ,
0.0 , 2.0 , 1.0 , 2.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0
, 9.5492965855137211 , { 0.0 , 1333.3333333333333 , 2666.6666666666665 ,
3999.9999999999995 , 4477.5590656519889 , 5333.333333333333 ,
6666.6666666666661 , 7999.9999999999991 , 9333.3333333333339 ,
10666.666666666666 , 12000.0 , 13333.333333333332 , 14666.666666666666 ,
15999.999999999998 } , 0.0 , 0.0 , 9.5492965855137211 , { 0.0 ,
1333.3333333333333 , 2666.6666666666665 , 3999.9999999999995 ,
4477.5590656519889 , 5333.333333333333 , 6666.6666666666661 ,
7999.9999999999991 , 9333.3333333333339 , 10666.666666666666 , 12000.0 ,
13333.333333333332 , 14666.666666666666 , 15999.999999999998 } , 100.0 , -
1.0 , - 1.0 , 9.5492965855137211 , { 0.0 , 1333.3333333333333 ,
2666.6666666666665 , 3999.9999999999995 , 4477.5590656519889 ,
5333.333333333333 , 6666.6666666666661 , 7999.9999999999991 ,
9333.3333333333339 , 10666.666666666666 , 12000.0 , 13333.333333333332 ,
14666.666666666666 , 15999.999999999998 } , 0.01 , - 1.0 , 1.0 , 0.0 , - 1.0
, 0.0 , 9.5492965855137211 , { 0.0 , 1333.3333333333333 , 2666.6666666666665
, 3999.9999999999995 , 4477.5590656519889 , 5333.333333333333 ,
6666.6666666666661 , 7999.9999999999991 , 9333.3333333333339 ,
10666.666666666666 , 12000.0 , 13333.333333333332 , 14666.666666666666 ,
15999.999999999998 } , - 1.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 1.0 , { 13U , 10U } } ; void cdlti3213i ( real_T * i2aqjuli5s ,
real_T * f5q1lumvzg , real_T * j2naykddwm , real_T * ea4r4f3bwk , real_T *
cewk4ryfod ) { * i2aqjuli5s = c5hhynsofi . P_22 ; * f5q1lumvzg = c5hhynsofi .
P_53 ; * j2naykddwm = c5hhynsofi . P_54 ; * ea4r4f3bwk = c5hhynsofi . P_55 ;
* cewk4ryfod = c5hhynsofi . P_56 ; } void f5tbg1pt2m ( real_T * i2aqjuli5s ,
real_T * f5q1lumvzg , real_T * j2naykddwm , real_T * ea4r4f3bwk , real_T *
cewk4ryfod , lsoeg0nito * localB ) { * i2aqjuli5s = c5hhynsofi . P_22 ;
localB -> ibqm4fsfc5 = 4.0 ; * f5q1lumvzg = c5hhynsofi . P_53 ; * j2naykddwm
= c5hhynsofi . P_54 ; * ea4r4f3bwk = c5hhynsofi . P_55 ; * cewk4ryfod =
c5hhynsofi . P_56 ; } void EvPowertrainControllerBMS ( const real_T *
ot1unth1hd , const real_T fju13otua5 [ 4 ] , const real_T * gam2gozpi4 ,
const real_T * givymazxjb , const real_T * k443icl0sn , const real_T *
iodoakv4fh , const real_T * k0pcor1dt1 , const real_T * nirwbhd0cx , const
real_T * fk0g32hxsg , const real_T * iatkkfawdg , const real_T * dyj0glinq3 ,
real_T * i2aqjuli5s , real_T * ou3e1khm3v , real_T gpmtm1hqzh [ 4 ] , real_T
maa0jy4xlg [ 6 ] , real_T * f5q1lumvzg , real_T * j2naykddwm , real_T *
ea4r4f3bwk , real_T * cewk4ryfod , real_T * fzi32imnif , lsoeg0nito * localB
) { real_T aspaurntja ; real_T bktcdb1pdp_idx_0 ; real_T bktcdb1pdp_idx_1 ;
real_T bktcdb1pdp_idx_2 ; real_T bktcdb1pdp_idx_3 ; real_T c5jaspnl2f ;
real_T csq1wubnsb ; real_T dbxy3js3sj ; real_T ddba0mkjqi ; real_T efxkwvmhix
; real_T gptjemzqq5 ; real_T hjaqh05ixl ; real_T lrypofdl5m ; real_T
miqahzeneq ; boolean_T bwpy50cww4 ; boolean_T lz1surwzy4 ; * i2aqjuli5s =
c5hhynsofi . P_22 ; efxkwvmhix = * dyj0glinq3 ; if ( efxkwvmhix > c5hhynsofi
. P_23 ) { efxkwvmhix = c5hhynsofi . P_23 ; } else if ( efxkwvmhix <
c5hhynsofi . P_24 ) { efxkwvmhix = c5hhynsofi . P_24 ; } ddba0mkjqi =
rtP__PlntBrkKinFricCffFrnt2f2PassVeh_sldd_ * 3.1415926535897931 *
0.0025000000000000005 * rtP__PlntBrkPadMeanRadiusFrnt2f2PassVeh_sldd_ *
rtP__PlntBrkNumPadsFrnt2f2PassVeh_sldd_ / 4.0 ; gptjemzqq5 = c5hhynsofi .
P_25 * efxkwvmhix / ddba0mkjqi ; efxkwvmhix =
rtP__PlntBrkFrntBias2f2PassVeh_sldd_ * gptjemzqq5 ; gptjemzqq5 *=
rtP__PlntBrkRearBias2f2PassVeh_sldd_ ; bktcdb1pdp_idx_0 =
rtP__PlntBrkFrntBias2f2PassVeh_sldd_ * fju13otua5 [ 0 ] ; bktcdb1pdp_idx_1 =
rtP__PlntBrkFrntBias2f2PassVeh_sldd_ * fju13otua5 [ 1 ] ; bktcdb1pdp_idx_2 =
rtP__PlntBrkRearBias2f2PassVeh_sldd_ * fju13otua5 [ 2 ] ; bktcdb1pdp_idx_3 =
rtP__PlntBrkRearBias2f2PassVeh_sldd_ * fju13otua5 [ 3 ] ; bwpy50cww4 = ( *
iatkkfawdg > c5hhynsofi . P_26 ) ; bktcdb1pdp_idx_0 *=
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; bktcdb1pdp_idx_1 *=
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; if ( bwpy50cww4 ) { bktcdb1pdp_idx_0 =
efxkwvmhix ; } bktcdb1pdp_idx_2 *= rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; if (
bwpy50cww4 ) { bktcdb1pdp_idx_1 = efxkwvmhix ; } bktcdb1pdp_idx_3 *=
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; if ( bwpy50cww4 ) { bktcdb1pdp_idx_2 =
gptjemzqq5 ; bktcdb1pdp_idx_3 = gptjemzqq5 ; } efxkwvmhix = * dyj0glinq3 ; if
( efxkwvmhix > c5hhynsofi . P_27 ) { efxkwvmhix = c5hhynsofi . P_27 ; } else
if ( efxkwvmhix < c5hhynsofi . P_28 ) { efxkwvmhix = c5hhynsofi . P_28 ; }
gptjemzqq5 = c5hhynsofi . P_29 * * givymazxjb ; gptjemzqq5 = * ot1unth1hd *
look1_binlcapw ( gptjemzqq5 , c5hhynsofi . P_30 ,
rtP__PlntEM1Trq2f2ElectricMachine1_sldd_ , 13U ) ; if ( ! ( * iatkkfawdg >
c5hhynsofi . P_31 ) ) { efxkwvmhix = gptjemzqq5 ; } dbxy3js3sj = * fk0g32hxsg
* efxkwvmhix ; bwpy50cww4 = ( * dyj0glinq3 > c5hhynsofi . P_15 ) ; lz1surwzy4
= ( * ot1unth1hd > c5hhynsofi . P_16 ) ; if ( ! ( * iatkkfawdg > c5hhynsofi .
P_32 ) ) { bwpy50cww4 = lz1surwzy4 ; } efxkwvmhix = ddba0mkjqi *
bktcdb1pdp_idx_0 + ddba0mkjqi * bktcdb1pdp_idx_1 ; bktcdb1pdp_idx_0 =
c5hhynsofi . P_33 * * givymazxjb ; bktcdb1pdp_idx_1 = look1_binlcapw ( *
gam2gozpi4 , rtP__CtrlVcuEvRegenBrkSpdBpt2f2EvVCU_sldd_ ,
rtP__CtrlVcuEvRegenBrkCutOff2f2EvVCU_sldd_ , 1U ) ; gptjemzqq5 = c5hhynsofi .
P_35 * * k443icl0sn ; bktcdb1pdp_idx_0 = muDoubleScalarMin ( efxkwvmhix ,
rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ * look1_binlcapw ( bktcdb1pdp_idx_0
, c5hhynsofi . P_34 , rtP__PlntEM1Trq2f2ElectricMachine1_sldd_ , 13U ) ) * (
bktcdb1pdp_idx_1 * look1_binlcapw ( gptjemzqq5 ,
rtP__CtrlVcuEvSocBpt2f2EvVCU_sldd_ , rtP__CtrlVcuEvChrgLmtBpt2f2EvVCU_sldd_ ,
10U ) ) ; * fzi32imnif = 1.0 / rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ *
bktcdb1pdp_idx_0 * c5hhynsofi . P_36 ; if ( ! bwpy50cww4 ) { dbxy3js3sj = *
fzi32imnif ; } bktcdb1pdp_idx_1 = muDoubleScalarAbs ( * givymazxjb ) ;
aspaurntja = c5hhynsofi . P_37 * * k0pcor1dt1 ; aspaurntja *= * iodoakv4fh ;
hjaqh05ixl = * givymazxjb * dbxy3js3sj ; miqahzeneq = c5hhynsofi . P_38 * *
givymazxjb ; miqahzeneq = c5hhynsofi . P_40 * look2_binlcapw (
muDoubleScalarAbs ( miqahzeneq ) , muDoubleScalarAbs ( dbxy3js3sj ) ,
c5hhynsofi . P_39 , rtP__PlntEM1TrqEff2f2ElectricMachine1_sldd_ ,
rtP__PlntEM1EffTbl2f2ElectricMachine1_sldd_ , c5hhynsofi . P_59 , 14U ) ; if
( hjaqh05ixl >= c5hhynsofi . P_43 ) { lrypofdl5m = c5hhynsofi . P_41 ; } else
{ lrypofdl5m = c5hhynsofi . P_42 ; } if ( ( miqahzeneq < 0.0 ) && (
lrypofdl5m > muDoubleScalarFloor ( lrypofdl5m ) ) ) { miqahzeneq = -
muDoubleScalarPower ( - miqahzeneq , lrypofdl5m ) ; } else { miqahzeneq =
muDoubleScalarPower ( miqahzeneq , lrypofdl5m ) ; } csq1wubnsb = hjaqh05ixl *
miqahzeneq ; lrypofdl5m = c5hhynsofi . P_44 * * nirwbhd0cx ; lrypofdl5m *= *
iodoakv4fh ; if ( * givymazxjb >= c5hhynsofi . P_45 ) { c5jaspnl2f =
c5hhynsofi . P_58 ; } else { c5jaspnl2f = localB -> e5d3ouqstz ; } hjaqh05ixl
= * givymazxjb / 2.0 ; bwpy50cww4 = ( * givymazxjb >= - c5hhynsofi . P_19 ) ;
lz1surwzy4 = ( * givymazxjb <= c5hhynsofi . P_19 ) ; if ( bwpy50cww4 &&
lz1surwzy4 ) { hjaqh05ixl = 4.0 / ( 3.0 - muDoubleScalarPower ( hjaqh05ixl ,
2.0 ) ) * c5jaspnl2f ; } else { hjaqh05ixl = * givymazxjb ; } if ( ( ! (
bktcdb1pdp_idx_1 < c5hhynsofi . P_17 ) ) && ( ( ! ( aspaurntja - csq1wubnsb
>= c5hhynsofi . P_20 ) ) || ( ! ( lrypofdl5m - csq1wubnsb <= c5hhynsofi .
P_21 ) ) ) ) { if ( csq1wubnsb > aspaurntja ) { csq1wubnsb = aspaurntja ; }
else if ( csq1wubnsb < lrypofdl5m ) { csq1wubnsb = lrypofdl5m ; } dbxy3js3sj
= csq1wubnsb / miqahzeneq / hjaqh05ixl ; } bktcdb1pdp_idx_1 = c5hhynsofi .
P_46 * * givymazxjb ; aspaurntja = look1_binlcapw ( bktcdb1pdp_idx_1 ,
c5hhynsofi . P_47 , rtP__PlntEM1Trq2f2ElectricMachine1_sldd_ , 13U ) ;
bktcdb1pdp_idx_1 = c5hhynsofi . P_48 * aspaurntja ; if ( gptjemzqq5 >
c5hhynsofi . P_18 ) { gptjemzqq5 = aspaurntja ; } else { gptjemzqq5 =
c5hhynsofi . P_57 ; } if ( dbxy3js3sj > gptjemzqq5 ) { * ou3e1khm3v =
gptjemzqq5 ; } else if ( dbxy3js3sj < bktcdb1pdp_idx_1 ) { * ou3e1khm3v =
bktcdb1pdp_idx_1 ; } else { * ou3e1khm3v = dbxy3js3sj ; } efxkwvmhix -=
bktcdb1pdp_idx_0 ; if ( efxkwvmhix > c5hhynsofi . P_49 ) { efxkwvmhix =
c5hhynsofi . P_49 ; } else if ( efxkwvmhix < c5hhynsofi . P_50 ) { efxkwvmhix
= c5hhynsofi . P_50 ; } efxkwvmhix = efxkwvmhix / ( ddba0mkjqi * 2.0 ) * (
1.0 / rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ) ; if ( efxkwvmhix > c5hhynsofi .
P_51 ) { efxkwvmhix = c5hhynsofi . P_51 ; } else if ( efxkwvmhix < c5hhynsofi
. P_52 ) { efxkwvmhix = c5hhynsofi . P_52 ; } gpmtm1hqzh [ 0 ] = efxkwvmhix ;
gpmtm1hqzh [ 1 ] = efxkwvmhix ; hjaqh05ixl = 1.0 /
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; gpmtm1hqzh [ 2 ] = hjaqh05ixl *
bktcdb1pdp_idx_2 ; gpmtm1hqzh [ 3 ] = hjaqh05ixl * bktcdb1pdp_idx_3 ;
ddba0mkjqi = gpmtm1hqzh [ 0 ] ; ddba0mkjqi += gpmtm1hqzh [ 1 ] ; ddba0mkjqi
+= gpmtm1hqzh [ 2 ] ; ddba0mkjqi += gpmtm1hqzh [ 3 ] ; ddba0mkjqi =
ddba0mkjqi / localB -> ibqm4fsfc5 *
rtP__CtrlBcuTrlrBrkGain2f2VirtualVehicleTemplate_sldd_ ; maa0jy4xlg [ 0 ] =
ddba0mkjqi ; maa0jy4xlg [ 1 ] = ddba0mkjqi ; maa0jy4xlg [ 2 ] = ddba0mkjqi ;
maa0jy4xlg [ 3 ] = ddba0mkjqi ; maa0jy4xlg [ 4 ] = ddba0mkjqi ; maa0jy4xlg [
5 ] = ddba0mkjqi ; * f5q1lumvzg = c5hhynsofi . P_53 ; * j2naykddwm =
c5hhynsofi . P_54 ; * ea4r4f3bwk = c5hhynsofi . P_55 ; * cewk4ryfod =
c5hhynsofi . P_56 ; } void EvPowertrainControllerBMSTID1 ( lsoeg0nito *
localB ) { localB -> e5d3ouqstz = - c5hhynsofi . P_58 ; } void b3eofzzeql (
obv4iumo0b * const ftj5mqhdtx ) { if ( ! slIsRapidAcceleratorSimulating ( ) )
{ slmrRunPluginEvent ( ftj5mqhdtx -> _mdlRefSfcnS ,
"EvPowertrainControllerBMS" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" )
; } } void aqzgcfjqsf ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , obv4iumo0b * const ftj5mqhdtx , lsoeg0nito * localB , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; c5hhynsofi . P_24 = rtMinusInf ;
c5hhynsofi . P_27 = rtInf ; c5hhynsofi . P_49 = rtInf ; ( void ) memset ( (
void * ) ftj5mqhdtx , 0 , sizeof ( obv4iumo0b ) ) ; ftj5mqhdtx -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; ftj5mqhdtx -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; ftj5mqhdtx -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( ftj5mqhdtx -> _mdlRefSfcnS , "EvPowertrainControllerBMS"
, "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> ibqm4fsfc5 =
0.0 ; localB -> e5d3ouqstz = 0.0 ; }
EvPowertrainControllerBMS_InitializeDataMapInfo ( ftj5mqhdtx , sysRanPtr ,
contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL
) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
ftj5mqhdtx -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( ftj5mqhdtx ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
ftj5mqhdtx -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void
mr_EvPowertrainControllerBMS_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T
* modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T
regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , &
regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ;
ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_EvPowertrainControllerBMS , 43 ) ; * retVal = 1 ; } static void
mr_EvPowertrainControllerBMS_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_EvPowertrainControllerBMS_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void
mr_EvPowertrainControllerBMS_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_EvPowertrainControllerBMS_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_EvPowertrainControllerBMS_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) ; static void
mr_EvPowertrainControllerBMS_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j
, mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_EvPowertrainControllerBMS_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_EvPowertrainControllerBMS_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = (
uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return
varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_EvPowertrainControllerBMS_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void
mr_EvPowertrainControllerBMS_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_EvPowertrainControllerBMS_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_EvPowertrainControllerBMS_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_EvPowertrainControllerBMS_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_EvPowertrainControllerBMS_cacheBitFieldToCellArrayWithOffset
( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal
) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_EvPowertrainControllerBMS_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T
mr_EvPowertrainControllerBMS_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_EvPowertrainControllerBMS_GetDWork (
const ngz2pfeakpt * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] =
{ "rtb" , "NULL->rtdw" , "NULL->rtzce" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_EvPowertrainControllerBMS_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void
* ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; ( void ) mdlrefDW
; return ssDW ; } void mr_EvPowertrainControllerBMS_SetDWork ( ngz2pfeakpt *
mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ;
mr_EvPowertrainControllerBMS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; } void
mr_EvPowertrainControllerBMS_RegisterSimStateChecksum ( SimStruct * S ) {
const uint32_T chksum [ 4 ] = { 3621521391U , 2500562369U , 641190287U ,
744673735U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"EvPowertrainControllerBMS" , & chksum [ 0 ] ) ; } mxArray *
mr_EvPowertrainControllerBMS_GetSimStateDisallowedBlocks ( ) { return ( NULL
) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
