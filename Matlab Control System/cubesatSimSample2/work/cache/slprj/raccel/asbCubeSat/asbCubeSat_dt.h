#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_IDZab2uInNu48WAt9I3W5" , 17 , 56 } , {
"struct_rZOo7lI4XXnxZGwtsuw9nF" , 18 , 72 } , {
"struct_uXBeANgAqTGhrPgOyPRa5G" , 19 , 400 } , { "StatesOutBus" , 20 , 232 }
, { "struct_eYFdmadaAEbmfNbyeiZ4KH" , 21 , 396808 } , { "obi5idc0yut" , 22 ,
472 } , { "struct_xjm5GaruTmSt2dTUHHAtVB" , 23 , 80 } , { "uint64_T" , 24 , 8
} , { "int64_T" , 25 , 8 } , { "uint_T" , 26 , 32 } , { "char_T" , 27 , 8 } ,
{ "uchar_T" , 28 , 8 } , { "time_T" , 29 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_IDZab2uInNu48WAt9I3W5 ) , sizeof (
struct_rZOo7lI4XXnxZGwtsuw9nF ) , sizeof ( struct_uXBeANgAqTGhrPgOyPRa5G ) ,
sizeof ( int32_T ) , sizeof ( int32_T ) , sizeof ( obi5idc0yut ) , sizeof (
int32_T ) , sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( uint_T ) ,
sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"physical_connection" , "int64_T" , "uint64_T" ,
"struct_IDZab2uInNu48WAt9I3W5" , "struct_rZOo7lI4XXnxZGwtsuw9nF" ,
"struct_uXBeANgAqTGhrPgOyPRa5G" , "StatesOutBus" ,
"struct_eYFdmadaAEbmfNbyeiZ4KH" , "obi5idc0yut" ,
"struct_xjm5GaruTmSt2dTUHHAtVB" , "uint64_T" , "int64_T" , "uint_T" ,
"char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & ktuiv5qnvo2 . guuurijbhk [ 0 ] ) , 0 , 0 , 65910 }
, { ( char_T * ) ( & ktuiv5qnvo2 . a45gkht3ip ) , 4 , 0 , 6 } , { ( char_T *
) ( & ktuiv5qnvo2 . e2i0xale0b ) , 8 , 0 , 11 } , { ( char_T * ) ( &
dzu2rlzxmw1 . gwyrl50tya [ 0 ] ) , 0 , 0 , 10 } , { ( char_T * ) ( &
dzu2rlzxmw1 . pdfdeemjq4 . LoggedData [ 0 ] ) , 11 , 0 , 8 } , { ( char_T * )
( & dzu2rlzxmw1 . dtie3bzjg2 ) , 7 , 0 , 1 } , { ( char_T * ) ( & dzu2rlzxmw1
. j2dtrztjsi . PrevIndex ) , 10 , 0 , 8 } , { ( char_T * ) ( & dzu2rlzxmw1 .
gzwsybef1l ) , 2 , 0 , 29 } , { ( char_T * ) ( & dzu2rlzxmw1 . jici0zznxs ) ,
8 , 0 , 10 } , { ( char_T * ) ( & dzu2rlzxmw1 . aus50sqkr0 ) , 22 , 0 , 1 } ,
{ ( char_T * ) ( & dzu2rlzxmw1 . cjccm1bbjg . mshrctujti ) , 2 , 0 , 1 } , {
( char_T * ) ( & dzu2rlzxmw1 . p52hhsg2cj . mshrctujti ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . dtyvlyi1u0 . mzkry3c5o5 ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . dmj10vcnymf . mzkry3c5o5 ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . fhdycuvak1o . mshrctujti ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . ckm0lumt30 . ibsclnmq4a ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . pookmfxkbnb . ibsclnmq4a ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . lanzmspcia . bvo4sqc1xt ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . k1md1brudn . hu5jjqenrx ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . enr11s3r13x . bvo4sqc1xt ) , 2 , 0 , 1 } , { (
char_T * ) ( & dzu2rlzxmw1 . atygzznv2xe . hu5jjqenrx ) , 2 , 0 , 1 } } ;
static DataTypeTransitionTable rtBTransTable = { 21U , rtBTransitions } ;
static DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( &
mft3luzpor . JulianDateConversion_day ) , 0 , 0 , 18 } , { ( char_T * ) ( &
mft3luzpor . DirectionCosineMatrixtoQuaternions_action ) , 3 , 0 , 1 } , { (
char_T * ) ( & mft3luzpor . Gain_Gain ) , 0 , 0 , 52963 } , { ( char_T * ) (
& mft3luzpor . InternationalGeomagneticReferenceField_month ) , 6 , 0 , 2 } ,
{ ( char_T * ) ( & mft3luzpor . Enablecustomgravitycalculation_CurrentSetting
) , 3 , 0 , 1 } , { ( char_T * ) ( & mft3luzpor . k1md1brudn . Bias1_Bias ) ,
0 , 0 , 2 } , { ( char_T * ) ( & mft3luzpor . atygzznv2xe . Bias1_Bias ) , 0
, 0 , 2 } , { ( char_T * ) ( & rtP__initCond2f2asbCubeSatModelData_sldd_ ) ,
19 , 0 , 1 } } ; static DataTypeTransitionTable rtPTransTable = { 8U ,
rtPTransitions } ;
