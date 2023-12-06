#include "asbCubeSatACS.h"
#include "rtwtypes.h"
#include "asbCubeSatACS_types.h"
#include "asbCubeSatACS_private.h"
#include "mwmathutil.h"
#include "asbCubeSatACS_capi.h"
#include <string.h>
#include "rt_nonfinite.h"
#define jdtssvm3jq ((uint8_T)2U)
#define jlm5zsrnni ((uint8_T)2U)
#define lrd4kh2yi1 ((uint8_T)1U)
#define lwohznd1fi ((uint8_T)1U)
#define mqabjprb5v ((uint8_T)0U)
static RegMdlInfo rtMdlInfo_asbCubeSatACS [ 44 ] = { { "obi5idc0yut" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"jx0nvoaj5s" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "iu4azrivv1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "m5irwxgsw5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"kfw13hcd5g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "als1g01zc0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "ezvi2zbjy2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"jdo0zysb04" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "h12irucwjp" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "jgeuwsgdmq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"n0xjxj2ehs" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "jcboi25osc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "due31ddxq5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"ophodr0x0g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "b1dkmxrvxd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "h1ucxuq2iv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"nkfjiqfgvd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "m1mdmrcg1e" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "pm1oeto4u5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"b4vxdooov4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "ie553oink0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "ihscoxzpvr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"asbCubeSatACS" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , {
"j5rpw4mhdf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"asbCubeSatACS" } , { "isesex4x31" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "asbCubeSatACS" } , { "dgtzqiy1yy" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"_c3_AirMagnetorquer" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"_c3_CoreMagnetorquer" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_asbCubeSatACS_GetSimStateDisallowedBlocks" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "asbCubeSatACS" } , {
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
) "asbCubeSatACS" } , { "lwxnfhftw5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "asbCubeSatACS" } , { "havmohmchh" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "asbCubeSatACS" } , {
"asbCubeSatACS.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , {
"asbCubeSatACS.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"asbCubeSatACS" } } ; abopqckbgqo abopqckbgq = { { 0.0 , 0.0 , 0.0 } } ;
static lwxnfhftw5 * cixw1djtkl ( lwxnfhftw5 * obj , real_T core_radius ,
real_T core_length , real_T layers ) ; static lwxnfhftw5 * cixw1djtkl (
lwxnfhftw5 * obj , real_T core_radius , real_T core_length , real_T layers )
{ lwxnfhftw5 * b_obj ; real_T L ; real_T core_volume ; real_T r_turn ; real_T
tmp ; int32_T c ; int32_T i ; b_obj = obj ; b_obj -> core_radius = 0.0 ;
b_obj -> wire_length = 0.0 ; b_obj -> core_length = core_length ; b_obj ->
layers = layers ; b_obj -> turns_per_layer = muDoubleScalarFloor (
core_length / 0.000254 ) ; b_obj -> turns = b_obj -> turns_per_layer * layers
; b_obj -> wire_height = ( ( layers - 1.0 ) * 1.7320508075688772 + 1.0 ) *
0.000254 ; b_obj -> core_radius = core_radius ; core_volume = 0.0 ; r_turn =
b_obj -> layers ; c = ( int32_T ) r_turn ; for ( i = 0 ; i < c ; i ++ ) {
r_turn = ( ( ( ( real_T ) i + 1.0 ) - 1.0 ) * 1.7320508075688772 + 0.5 ) *
0.000254 + b_obj -> core_radius ; core_volume += 6.2831853071795862 * r_turn
* b_obj -> turns_per_layer ; } b_obj -> wire_length = core_volume ;
core_volume = b_obj -> core_radius ; core_volume = core_volume * core_volume
* b_obj -> core_length * 3.1415926535897931 ; b_obj -> core_mass =
core_volume * 8700.0 ; core_volume = b_obj -> core_radius ; r_turn = b_obj ->
turns ; L = b_obj -> core_length ; L /= core_volume ; tmp = muDoubleScalarLog
( L ) ; b_obj -> max_dipole = ( 99999.0 / ( ( tmp - 1.0 ) * 4.0 / ( L * L -
tmp * 4.0 ) * 99999.0 + 1.0 ) + 1.0 ) * ( core_volume * core_volume *
3.1415926535897931 * r_turn * 0.1 ) ; return b_obj ; } void pm1oeto4u5 (
real_T a5dz0igc5a [ 3 ] , due31ddxq5 * localDW ) { localDW -> ezd4ommdk4 = 0U
; localDW -> dlvrorsycy = mqabjprb5v ; localDW -> e2hi1swaky = mqabjprb5v ;
a5dz0igc5a [ 0 ] = 0.0 ; a5dz0igc5a [ 1 ] = 0.0 ; a5dz0igc5a [ 2 ] = 0.0 ;
localDW -> gga3givnjk = false ; localDW -> jdqttnjpvx = false ; localDW ->
icbjmh5s3b = false ; localDW -> ozqest1euh = false ; } void m1mdmrcg1e (
real_T a5dz0igc5a [ 3 ] , due31ddxq5 * localDW ) { localDW -> ezd4ommdk4 = 0U
; localDW -> dlvrorsycy = mqabjprb5v ; localDW -> e2hi1swaky = mqabjprb5v ;
a5dz0igc5a [ 0 ] = 0.0 ; a5dz0igc5a [ 1 ] = 0.0 ; a5dz0igc5a [ 2 ] = 0.0 ; }
void asbCubeSatACS ( const real_T * hjsiku24fs , const real_T etvtuzdyht [ 3
] , real_T a5dz0igc5a [ 3 ] , ophodr0x0g * localB , due31ddxq5 * localDW ) {
real_T length ; real_T m_idx_0 ; real_T m_idx_1 ; real_T m_idx_2 ; real_T
magnetometer_measurements_idx_0 ; real_T magnetometer_measurements_idx_1 ;
real_T magnetometer_measurements_idx_2 ; int32_T i ; if ( localDW ->
ezd4ommdk4 == 0U ) { localDW -> ezd4ommdk4 = 1U ; localDW -> dlvrorsycy =
lwohznd1fi ; a5dz0igc5a [ 0 ] = abopqckbgq . P_0 [ 0 ] ; a5dz0igc5a [ 1 ] =
abopqckbgq . P_0 [ 1 ] ; a5dz0igc5a [ 2 ] = abopqckbgq . P_0 [ 2 ] ; } else
if ( localDW -> dlvrorsycy == lwohznd1fi ) { if ( * hjsiku24fs != 0.0 ) {
localDW -> dlvrorsycy = jlm5zsrnni ; localDW -> e2hi1swaky = jdtssvm3jq ; }
else { a5dz0igc5a [ 0 ] = abopqckbgq . P_0 [ 0 ] ; a5dz0igc5a [ 1 ] =
abopqckbgq . P_0 [ 1 ] ; a5dz0igc5a [ 2 ] = abopqckbgq . P_0 [ 2 ] ; } } else
if ( * hjsiku24fs == 0.0 ) { localDW -> e2hi1swaky = mqabjprb5v ; localDW ->
dlvrorsycy = lwohznd1fi ; a5dz0igc5a [ 0 ] = abopqckbgq . P_0 [ 0 ] ;
a5dz0igc5a [ 1 ] = abopqckbgq . P_0 [ 1 ] ; a5dz0igc5a [ 2 ] = abopqckbgq .
P_0 [ 2 ] ; } else if ( localDW -> e2hi1swaky == lrd4kh2yi1 ) { if ( *
hjsiku24fs == 2.0 ) { localDW -> e2hi1swaky = jdtssvm3jq ; } else { if ( ( !
localDW -> gga3givnjk ) || ( ! localDW -> jdqttnjpvx ) || ( ! localDW ->
icbjmh5s3b ) ) { cixw1djtkl ( & localDW -> ej4biwwl1p , 0.005 , 0.045 , 6.0 )
; localDW -> gga3givnjk = true ; cixw1djtkl ( & localDW -> bw5bzzfeim , 0.005
, 0.045 , 6.0 ) ; localDW -> jdqttnjpvx = true ; localDW -> n5brd01s3a .
layers = 5.0 ; localDW -> n5brd01s3a . turns_per_layer = 98.0 ; localDW ->
n5brd01s3a . turns = 490.0 ; localDW -> n5brd01s3a . wire_height =
0.0020137636204899793 ; localDW -> n5brd01s3a . side_length = 0.045 ; length
= 0.0 ; for ( i = 0 ; i < 5 ; i ++ ) { length += ( ( ( ( ( real_T ) i + 1.0 )
- 1.0 ) * 1.7320508075688772 + 0.5 ) * 0.000254 * 2.0 + 0.045 ) * 4.0 * 98.0
; } localDW -> n5brd01s3a . wire_length = length ; localDW -> n5brd01s3a .
core_mass = 0.0 ; localDW -> n5brd01s3a . max_dipole = 0.099225000000000008 ;
localDW -> icbjmh5s3b = true ; } magnetometer_measurements_idx_0 = etvtuzdyht
[ 0 ] ; magnetometer_measurements_idx_1 = etvtuzdyht [ 1 ] ;
magnetometer_measurements_idx_2 = etvtuzdyht [ 2 ] ; if ( ! localDW ->
ozqest1euh ) { localDW -> dl3y14pa2l [ 0 ] = magnetometer_measurements_idx_0
; localDW -> dl3y14pa2l [ 1 ] = magnetometer_measurements_idx_1 ; localDW ->
dl3y14pa2l [ 2 ] = magnetometer_measurements_idx_2 ; localDW -> ozqest1euh =
true ; } m_idx_0 = - ( magnetometer_measurements_idx_0 - localDW ->
dl3y14pa2l [ 0 ] ) * 1.0E+9 ; m_idx_1 = - ( magnetometer_measurements_idx_1 -
localDW -> dl3y14pa2l [ 1 ] ) * 1.0E+9 ; m_idx_2 = - (
magnetometer_measurements_idx_2 - localDW -> dl3y14pa2l [ 2 ] ) * 1.0E+9 ;
length = muDoubleScalarAbs ( m_idx_0 ) ; if ( length > localDW -> ej4biwwl1p
. max_dipole ) { m_idx_0 = m_idx_0 * localDW -> ej4biwwl1p . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> ej4biwwl1p . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> ej4biwwl1p . max_dipole / length ; } length =
muDoubleScalarAbs ( m_idx_1 ) ; if ( length > localDW -> bw5bzzfeim .
max_dipole ) { m_idx_0 = m_idx_0 * localDW -> bw5bzzfeim . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> bw5bzzfeim . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> bw5bzzfeim . max_dipole / length ; } length =
muDoubleScalarAbs ( m_idx_2 ) ; if ( length > localDW -> n5brd01s3a .
max_dipole ) { m_idx_0 = m_idx_0 * localDW -> n5brd01s3a . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> n5brd01s3a . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> n5brd01s3a . max_dipole / length ; } localB ->
ilr5a13pqb [ 0 ] = m_idx_1 * magnetometer_measurements_idx_2 -
magnetometer_measurements_idx_1 * m_idx_2 ; localB -> ilr5a13pqb [ 1 ] =
magnetometer_measurements_idx_0 * m_idx_2 - m_idx_0 *
magnetometer_measurements_idx_2 ; localB -> ilr5a13pqb [ 2 ] = m_idx_0 *
magnetometer_measurements_idx_1 - magnetometer_measurements_idx_0 * m_idx_1 ;
localDW -> dl3y14pa2l [ 0 ] = magnetometer_measurements_idx_0 ; a5dz0igc5a [
0 ] = localB -> ilr5a13pqb [ 0 ] ; localDW -> dl3y14pa2l [ 1 ] =
magnetometer_measurements_idx_1 ; a5dz0igc5a [ 1 ] = localB -> ilr5a13pqb [ 1
] ; localDW -> dl3y14pa2l [ 2 ] = magnetometer_measurements_idx_2 ;
a5dz0igc5a [ 2 ] = localB -> ilr5a13pqb [ 2 ] ; } } else if ( * hjsiku24fs ==
1.0 ) { localDW -> e2hi1swaky = lrd4kh2yi1 ; if ( ( ! localDW -> gga3givnjk )
|| ( ! localDW -> jdqttnjpvx ) || ( ! localDW -> icbjmh5s3b ) ) { cixw1djtkl
( & localDW -> ej4biwwl1p , 0.005 , 0.045 , 6.0 ) ; localDW -> gga3givnjk =
true ; cixw1djtkl ( & localDW -> bw5bzzfeim , 0.005 , 0.045 , 6.0 ) ; localDW
-> jdqttnjpvx = true ; localDW -> n5brd01s3a . layers = 5.0 ; localDW ->
n5brd01s3a . turns_per_layer = 98.0 ; localDW -> n5brd01s3a . turns = 490.0 ;
localDW -> n5brd01s3a . wire_height = 0.0020137636204899793 ; localDW ->
n5brd01s3a . side_length = 0.045 ; length = 0.0 ; for ( i = 0 ; i < 5 ; i ++
) { length += ( ( ( ( ( real_T ) i + 1.0 ) - 1.0 ) * 1.7320508075688772 + 0.5
) * 0.000254 * 2.0 + 0.045 ) * 4.0 * 98.0 ; } localDW -> n5brd01s3a .
wire_length = length ; localDW -> n5brd01s3a . core_mass = 0.0 ; localDW ->
n5brd01s3a . max_dipole = 0.099225000000000008 ; localDW -> icbjmh5s3b = true
; } magnetometer_measurements_idx_0 = etvtuzdyht [ 0 ] ;
magnetometer_measurements_idx_1 = etvtuzdyht [ 1 ] ;
magnetometer_measurements_idx_2 = etvtuzdyht [ 2 ] ; if ( ! localDW ->
ozqest1euh ) { localDW -> dl3y14pa2l [ 0 ] = magnetometer_measurements_idx_0
; localDW -> dl3y14pa2l [ 1 ] = magnetometer_measurements_idx_1 ; localDW ->
dl3y14pa2l [ 2 ] = magnetometer_measurements_idx_2 ; localDW -> ozqest1euh =
true ; } m_idx_0 = - ( magnetometer_measurements_idx_0 - localDW ->
dl3y14pa2l [ 0 ] ) * 1.0E+9 ; m_idx_1 = - ( magnetometer_measurements_idx_1 -
localDW -> dl3y14pa2l [ 1 ] ) * 1.0E+9 ; m_idx_2 = - (
magnetometer_measurements_idx_2 - localDW -> dl3y14pa2l [ 2 ] ) * 1.0E+9 ;
length = muDoubleScalarAbs ( m_idx_0 ) ; if ( length > localDW -> ej4biwwl1p
. max_dipole ) { m_idx_0 = m_idx_0 * localDW -> ej4biwwl1p . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> ej4biwwl1p . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> ej4biwwl1p . max_dipole / length ; } length =
muDoubleScalarAbs ( m_idx_1 ) ; if ( length > localDW -> bw5bzzfeim .
max_dipole ) { m_idx_0 = m_idx_0 * localDW -> bw5bzzfeim . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> bw5bzzfeim . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> bw5bzzfeim . max_dipole / length ; } length =
muDoubleScalarAbs ( m_idx_2 ) ; if ( length > localDW -> n5brd01s3a .
max_dipole ) { m_idx_0 = m_idx_0 * localDW -> n5brd01s3a . max_dipole /
length ; m_idx_1 = m_idx_1 * localDW -> n5brd01s3a . max_dipole / length ;
m_idx_2 = m_idx_2 * localDW -> n5brd01s3a . max_dipole / length ; } localB ->
ilr5a13pqb [ 0 ] = m_idx_1 * magnetometer_measurements_idx_2 -
magnetometer_measurements_idx_1 * m_idx_2 ; localB -> ilr5a13pqb [ 1 ] =
magnetometer_measurements_idx_0 * m_idx_2 - m_idx_0 *
magnetometer_measurements_idx_2 ; localB -> ilr5a13pqb [ 2 ] = m_idx_0 *
magnetometer_measurements_idx_1 - magnetometer_measurements_idx_0 * m_idx_1 ;
localDW -> dl3y14pa2l [ 0 ] = magnetometer_measurements_idx_0 ; a5dz0igc5a [
0 ] = localB -> ilr5a13pqb [ 0 ] ; localDW -> dl3y14pa2l [ 1 ] =
magnetometer_measurements_idx_1 ; a5dz0igc5a [ 1 ] = localB -> ilr5a13pqb [ 1
] ; localDW -> dl3y14pa2l [ 2 ] = magnetometer_measurements_idx_2 ;
a5dz0igc5a [ 2 ] = localB -> ilr5a13pqb [ 2 ] ; } } void h1ucxuq2iv (
dgtzqiy1yy * const fprqfujhwe ) { if ( ! slIsRapidAcceleratorSimulating ( ) )
{ slmrRunPluginEvent ( fprqfujhwe -> _mdlRefSfcnS , "asbCubeSatACS" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void b4vxdooov4 (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , dgtzqiy1yy
* const fprqfujhwe , ophodr0x0g * localB , due31ddxq5 * localDW , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void * )
fprqfujhwe , 0 , sizeof ( dgtzqiy1yy ) ) ; fprqfujhwe -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; fprqfujhwe -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; fprqfujhwe -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( fprqfujhwe -> _mdlRefSfcnS , "asbCubeSatACS" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> ilr5a13pqb [ 0 ]
= 0.0 ; localB -> ilr5a13pqb [ 1 ] = 0.0 ; localB -> ilr5a13pqb [ 2 ] = 0.0 ;
} ( void ) memset ( ( void * ) localDW , 0 , sizeof ( due31ddxq5 ) ) ;
localDW -> dl3y14pa2l [ 0 ] = 0.0 ; localDW -> dl3y14pa2l [ 1 ] = 0.0 ;
localDW -> dl3y14pa2l [ 2 ] = 0.0 ; asbCubeSatACS_InitializeDataMapInfo (
fprqfujhwe , localDW , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != (
NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( *
rt_ParentMMI , rt_ChildMMIIdx , & ( fprqfujhwe -> DataMapInfo . mmi ) ) ;
rtwCAPI_SetPath ( fprqfujhwe -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( fprqfujhwe -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_asbCubeSatACS_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_asbCubeSatACS , 44 ) ; * retVal = 1 ; } static void
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
obi5idc0yut * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] = {
"rtb" , "rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix (
1 , 1 , 3 , ssDWFieldNames ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( ssDW , 0
, 0 , ( const void * ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ;
{ static const char_T * rtdwDataFieldNames [ 13 ] = {
"mdlrefDW->rtdw.ej4biwwl1p" , "mdlrefDW->rtdw.bw5bzzfeim" ,
"mdlrefDW->rtdw.n5brd01s3a" , "mdlrefDW->rtdw.dl3y14pa2l" ,
"mdlrefDW->rtdw.lenntvlcas" , "mdlrefDW->rtdw.btx3klejj4" ,
"mdlrefDW->rtdw.ezd4ommdk4" , "mdlrefDW->rtdw.dlvrorsycy" ,
"mdlrefDW->rtdw.e2hi1swaky" , "mdlrefDW->rtdw.gga3givnjk" ,
"mdlrefDW->rtdw.jdqttnjpvx" , "mdlrefDW->rtdw.icbjmh5s3b" ,
"mdlrefDW->rtdw.ozqest1euh" , } ; mxArray * rtdwData = mxCreateStructMatrix (
1 , 1 , 13 , rtdwDataFieldNames ) ; mr_asbCubeSatACS_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( mdlrefDW -> rtdw . ej4biwwl1p ) ,
sizeof ( mdlrefDW -> rtdw . ej4biwwl1p ) ) ;
mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
mdlrefDW -> rtdw . bw5bzzfeim ) , sizeof ( mdlrefDW -> rtdw . bw5bzzfeim ) )
; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) &
( mdlrefDW -> rtdw . n5brd01s3a ) , sizeof ( mdlrefDW -> rtdw . n5brd01s3a )
) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( mdlrefDW -> rtdw . dl3y14pa2l ) , sizeof ( mdlrefDW -> rtdw . dl3y14pa2l
) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void *
) & ( mdlrefDW -> rtdw . lenntvlcas ) , sizeof ( mdlrefDW -> rtdw .
lenntvlcas ) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 5 , (
const void * ) & ( mdlrefDW -> rtdw . btx3klejj4 ) , sizeof ( mdlrefDW ->
rtdw . btx3klejj4 ) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 ,
6 , ( const void * ) & ( mdlrefDW -> rtdw . ezd4ommdk4 ) , sizeof ( mdlrefDW
-> rtdw . ezd4ommdk4 ) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0
, 7 , ( const void * ) & ( mdlrefDW -> rtdw . dlvrorsycy ) , sizeof (
mdlrefDW -> rtdw . dlvrorsycy ) ) ; mr_asbCubeSatACS_cacheDataAsMxArray (
rtdwData , 0 , 8 , ( const void * ) & ( mdlrefDW -> rtdw . e2hi1swaky ) ,
sizeof ( mdlrefDW -> rtdw . e2hi1swaky ) ) ;
mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
mdlrefDW -> rtdw . gga3givnjk ) , sizeof ( mdlrefDW -> rtdw . gga3givnjk ) )
; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * )
& ( mdlrefDW -> rtdw . jdqttnjpvx ) , sizeof ( mdlrefDW -> rtdw . jdqttnjpvx
) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void
* ) & ( mdlrefDW -> rtdw . icbjmh5s3b ) , sizeof ( mdlrefDW -> rtdw .
icbjmh5s3b ) ) ; mr_asbCubeSatACS_cacheDataAsMxArray ( rtdwData , 0 , 12 , (
const void * ) & ( mdlrefDW -> rtdw . ozqest1euh ) , sizeof ( mdlrefDW ->
rtdw . ozqest1euh ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } (
void ) mdlrefDW ; return ssDW ; } void mr_asbCubeSatACS_SetDWork (
obi5idc0yut * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void )
mdlrefDW ; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
ej4biwwl1p ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw . ej4biwwl1p ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
bw5bzzfeim ) , rtdwData , 0 , 1 , sizeof ( mdlrefDW -> rtdw . bw5bzzfeim ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
n5brd01s3a ) , rtdwData , 0 , 2 , sizeof ( mdlrefDW -> rtdw . n5brd01s3a ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
dl3y14pa2l ) , rtdwData , 0 , 3 , sizeof ( mdlrefDW -> rtdw . dl3y14pa2l ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
lenntvlcas ) , rtdwData , 0 , 4 , sizeof ( mdlrefDW -> rtdw . lenntvlcas ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
btx3klejj4 ) , rtdwData , 0 , 5 , sizeof ( mdlrefDW -> rtdw . btx3klejj4 ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
ezd4ommdk4 ) , rtdwData , 0 , 6 , sizeof ( mdlrefDW -> rtdw . ezd4ommdk4 ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
dlvrorsycy ) , rtdwData , 0 , 7 , sizeof ( mdlrefDW -> rtdw . dlvrorsycy ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
e2hi1swaky ) , rtdwData , 0 , 8 , sizeof ( mdlrefDW -> rtdw . e2hi1swaky ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
gga3givnjk ) , rtdwData , 0 , 9 , sizeof ( mdlrefDW -> rtdw . gga3givnjk ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
jdqttnjpvx ) , rtdwData , 0 , 10 , sizeof ( mdlrefDW -> rtdw . jdqttnjpvx ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
icbjmh5s3b ) , rtdwData , 0 , 11 , sizeof ( mdlrefDW -> rtdw . icbjmh5s3b ) )
; mr_asbCubeSatACS_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
ozqest1euh ) , rtdwData , 0 , 12 , sizeof ( mdlrefDW -> rtdw . ozqest1euh ) )
; } } void mr_asbCubeSatACS_RegisterSimStateChecksum ( SimStruct * S ) {
const uint32_T chksum [ 4 ] = { 1998818789U , 4101566430U , 816471465U ,
816958334U , } ; slmrModelRefRegisterSimStateChecksum ( S , "asbCubeSatACS" ,
& chksum [ 0 ] ) ; } mxArray * mr_asbCubeSatACS_GetSimStateDisallowedBlocks (
) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
