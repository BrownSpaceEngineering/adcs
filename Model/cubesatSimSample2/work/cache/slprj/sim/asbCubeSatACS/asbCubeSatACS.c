#include "asbCubeSatACS.h"
#include "asbCubeSatACS_capi.h"
#include "asbCubeSatACS_private.h"
#include "rt_nonfinite.h"
int_T j5rpw4mhdf [ 1 ] ; static RegMdlInfo rtMdlInfo_asbCubeSatACS [ 37 ] = {
{ "obi5idc0yut" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "jx0nvoaj5s" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "iu4azrivv1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"m5irwxgsw5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "kfw13hcd5g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "als1g01zc0" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"ezvi2zbjy2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "jdo0zysb04" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "h12irucwjp" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"jgeuwsgdmq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "n0xjxj2ehs" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "jcboi25osc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"due31ddxq5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "ophodr0x0g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "b1dkmxrvxd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"h1ucxuq2iv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "b4vxdooov4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "ie553oink0" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"ihscoxzpvr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "asbCubeSatACS" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, 0 , ( NULL ) } , { "j5rpw4mhdf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "isesex4x31" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"dgtzqiy1yy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "mr_asbCubeSatACS_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "asbCubeSatACS" } , { "mr_asbCubeSatACS_cacheDataAsMxArray"
, MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "asbCubeSatACS" } , { "mr_asbCubeSatACS_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"mr_asbCubeSatACS_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void *
) "asbCubeSatACS" } , { "asbCubeSatACS.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1
, ( NULL ) } , { "asbCubeSatACS.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "asbCubeSatACS" } } ; void h1ucxuq2iv ( dgtzqiy1yy * const
fprqfujhwe ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( fprqfujhwe -> _mdlRefSfcnS , "asbCubeSatACS" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void b4vxdooov4 (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , dgtzqiy1yy * const fprqfujhwe
, void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI
, const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void * )
fprqfujhwe , 0 , sizeof ( dgtzqiy1yy ) ) ; j5rpw4mhdf [ 0 ] = mdlref_TID0 ;
fprqfujhwe -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( !
slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( fprqfujhwe ->
_mdlRefSfcnS , "asbCubeSatACS" , "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" )
; } asbCubeSatACS_InitializeDataMapInfo ( fprqfujhwe , sysRanPtr , contextTid
) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) {
rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & ( fprqfujhwe ->
DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( fprqfujhwe -> DataMapInfo . mmi ,
rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex ( fprqfujhwe ->
DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void mr_asbCubeSatACS_MdlInfoRegFcn
( SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal
= 0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_asbCubeSatACS , 37 ) ; * retVal = 1 ; } static void
mr_asbCubeSatACS_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_asbCubeSatACS_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_asbCubeSatACS_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_asbCubeSatACS_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_asbCubeSatACS_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_asbCubeSatACS_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T )
bitVal ) ) ; } static uint_T mr_asbCubeSatACS_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_asbCubeSatACS_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_asbCubeSatACS_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_asbCubeSatACS_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_asbCubeSatACS_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_asbCubeSatACS_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_asbCubeSatACS_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_asbCubeSatACS_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_asbCubeSatACS_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_asbCubeSatACS_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_asbCubeSatACS_GetDWork ( const
obi5idc0yut * mdlrefDW ) { ( void ) mdlrefDW ; return ( NULL ) ; } void
mr_asbCubeSatACS_SetDWork ( obi5idc0yut * mdlrefDW , const mxArray * ssDW ) {
( void ) ssDW ; ( void ) mdlrefDW ; } void
mr_asbCubeSatACS_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T
chksum [ 4 ] = { 2334799802U , 2730520904U , 1069682016U , 3497112383U , } ;
slmrModelRefRegisterSimStateChecksum ( S , "asbCubeSatACS" , & chksum [ 0 ] )
; } mxArray * mr_asbCubeSatACS_GetSimStateDisallowedBlocks ( ) { return (
NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
