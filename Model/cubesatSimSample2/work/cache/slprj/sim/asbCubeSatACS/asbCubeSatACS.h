#ifndef RTW_HEADER_asbCubeSatACS_h_
#define RTW_HEADER_asbCubeSatACS_h_
#ifndef asbCubeSatACS_COMMON_INCLUDES_
#define asbCubeSatACS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "asbCubeSatACS_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
typedef struct { real_T ilr5a13pqb [ 3 ] ; } ophodr0x0g ; typedef struct {
lwxnfhftw5 ej4biwwl1p ; lwxnfhftw5 bw5bzzfeim ; havmohmchh n5brd01s3a ;
real_T dl3y14pa2l [ 3 ] ; int8_T lenntvlcas ; int8_T btx3klejj4 ; uint8_T
ezd4ommdk4 ; uint8_T dlvrorsycy ; uint8_T e2hi1swaky ; boolean_T gga3givnjk ;
boolean_T jdqttnjpvx ; boolean_T icbjmh5s3b ; boolean_T ozqest1euh ; }
due31ddxq5 ; struct abopqckbgqo_ { real_T P_0 [ 3 ] ; } ; struct isesex4x31 {
struct SimStruct_tag * _mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; sysRanDType *
systemRan [ 6 ] ; int_T systemTid [ 6 ] ; } DataMapInfo ; struct { int_T
mdlref_GlobalTID [ 2 ] ; } Timing ; } ; typedef struct { ophodr0x0g rtb ;
due31ddxq5 rtdw ; dgtzqiy1yy rtm ; } obi5idc0yut ; extern void b4vxdooov4 (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , dgtzqiy1yy
* const fprqfujhwe , ophodr0x0g * localB , due31ddxq5 * localDW , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern
void mr_asbCubeSatACS_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_asbCubeSatACS_GetDWork (
const obi5idc0yut * mdlrefDW ) ; extern void mr_asbCubeSatACS_SetDWork (
obi5idc0yut * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_asbCubeSatACS_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_asbCubeSatACS_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * asbCubeSatACS_GetCAPIStaticMap ( void ) ;
extern void pm1oeto4u5 ( real_T a5dz0igc5a [ 3 ] , due31ddxq5 * localDW ) ;
extern void m1mdmrcg1e ( real_T a5dz0igc5a [ 3 ] , due31ddxq5 * localDW ) ;
extern void asbCubeSatACS ( const real_T * hjsiku24fs , const real_T
etvtuzdyht [ 3 ] , real_T a5dz0igc5a [ 3 ] , ophodr0x0g * localB , due31ddxq5
* localDW ) ; extern void h1ucxuq2iv ( dgtzqiy1yy * const fprqfujhwe ) ;
#endif
