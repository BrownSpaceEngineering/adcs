#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "asbCubeSatACS_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "asbCubeSatACS.h"
#include "asbCubeSatACS_capi.h"
#include "asbCubeSatACS_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static TARGET_CONST
rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "" , "" , 0 , 0 , 0 , 0 , 0 , 0 ,
0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 0 , 0 } } ; static uint_T rtDimensionArray [ ] = { 0 } ;
static rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 0 , 0 }
} ; static int_T rtContextSystems [ 6 ] ; static rtwCAPI_LoggingMetaInfo
loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 6 ,
rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL )
} , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 0 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
{ 344453608U , 402957041U , 165556593U , 502010286U } , &
mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * asbCubeSatACS_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void asbCubeSatACS_InitializeSystemRan ( dgtzqiy1yy * const fprqfujhwe
, sysRanDType * systemRan [ ] , due31ddxq5 * localDW , int_T systemTid [ ] ,
void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( fprqfujhwe ) ;
UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( sysRanDType * ) & localDW -> btx3klejj4 ;
systemRan [ 2 ] = ( NULL ) ; systemRan [ 3 ] = ( sysRanDType * ) & localDW ->
lenntvlcas ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = ( NULL ) ;
systemTid [ 1 ] = fprqfujhwe -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [
2 ] = fprqfujhwe -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 3 ] =
fprqfujhwe -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 4 ] = fprqfujhwe
-> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 5 ] = fprqfujhwe -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] =
0 ; rtContextSystems [ 1 ] = 1 ; rtContextSystems [ 2 ] = 3 ;
rtContextSystems [ 3 ] = 3 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [
5 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void asbCubeSatACS_InitializeDataMapInfo ( dgtzqiy1yy * const fprqfujhwe ,
due31ddxq5 * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( fprqfujhwe -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( fprqfujhwe -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( fprqfujhwe -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; rtwCAPI_SetPath ( fprqfujhwe -> DataMapInfo . mmi ,
( NULL ) ) ; rtwCAPI_SetFullPath ( fprqfujhwe -> DataMapInfo . mmi , ( NULL )
) ; rtwCAPI_SetInstanceLoggingInfo ( fprqfujhwe -> DataMapInfo . mmi , &
fprqfujhwe -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
fprqfujhwe -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
fprqfujhwe -> DataMapInfo . mmi , 0 ) ; asbCubeSatACS_InitializeSystemRan (
fprqfujhwe , fprqfujhwe -> DataMapInfo . systemRan , localDW , fprqfujhwe ->
DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan (
fprqfujhwe -> DataMapInfo . mmi , fprqfujhwe -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( fprqfujhwe -> DataMapInfo . mmi , fprqfujhwe ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( fprqfujhwe ->
DataMapInfo . mmi , & fprqfujhwe -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void asbCubeSatACS_host_InitializeDataMapInfo (
asbCubeSatACS_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
