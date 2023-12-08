#ifndef RTW_HEADER_asbCubeSatACS_h_
#define RTW_HEADER_asbCubeSatACS_h_
#ifndef asbCubeSatACS_COMMON_INCLUDES_
#define asbCubeSatACS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "asbCubeSatACS_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
struct isesex4x31 { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; struct { int_T mdlref_GlobalTID [ 1 ] ; } Timing ; } ;
typedef struct { dgtzqiy1yy rtm ; } obi5idc0yut ; extern void b4vxdooov4 (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , dgtzqiy1yy * const fprqfujhwe
, void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI
, const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ;
extern void mr_asbCubeSatACS_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T
* modelName , int_T * retVal ) ; extern mxArray * mr_asbCubeSatACS_GetDWork (
const obi5idc0yut * mdlrefDW ) ; extern void mr_asbCubeSatACS_SetDWork (
obi5idc0yut * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_asbCubeSatACS_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_asbCubeSatACS_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * asbCubeSatACS_GetCAPIStaticMap ( void ) ;
extern void h1ucxuq2iv ( dgtzqiy1yy * const fprqfujhwe ) ;
#endif
