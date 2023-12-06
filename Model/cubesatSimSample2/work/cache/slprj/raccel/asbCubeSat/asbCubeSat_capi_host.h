#ifndef RTW_HEADER_asbCubeSat_cap_host_h__
#define RTW_HEADER_asbCubeSat_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
#include "asbCubeSatACS_capi_host.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMappingInfo *
childMMI [ 1 ] ; asbCubeSatACS_host_DataMapInfo_T child0 ; }
asbCubeSat_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void asbCubeSat_host_InitializeDataMapInfo ( asbCubeSat_host_DataMapInfo_T *
dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
