#ifndef RTW_HEADER_asbCubeSat_types_h_
#define RTW_HEADER_asbCubeSat_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_IDZab2uInNu48WAt9I3W5_
#define DEFINED_TYPEDEF_FOR_struct_IDZab2uInNu48WAt9I3W5_
typedef struct { real_T JD ; real_T dateVector [ 6 ] ; }
struct_IDZab2uInNu48WAt9I3W5 ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_rZOo7lI4XXnxZGwtsuw9nF_
#define DEFINED_TYPEDEF_FOR_struct_rZOo7lI4XXnxZGwtsuw9nF_
typedef struct { real_T semiMajorAxis ; real_T eccentricity ; real_T
inclination ; real_T RAAN ; real_T argumentOfPerigee ; real_T trueAnomoly ;
real_T trueLongitude ; real_T argumentOfLatititude ; real_T
longitudeOfPerigee ; } struct_rZOo7lI4XXnxZGwtsuw9nF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_uXBeANgAqTGhrPgOyPRa5G_
#define DEFINED_TYPEDEF_FOR_struct_uXBeANgAqTGhrPgOyPRa5G_
typedef struct { struct_IDZab2uInNu48WAt9I3W5 simStartDate ;
struct_IDZab2uInNu48WAt9I3W5 CoordEpoch ; struct_rZOo7lI4XXnxZGwtsuw9nF
OrbitalElements ; real_T r_eci [ 3 ] ; real_T v_eci [ 3 ] ; real_T r_ecef [ 3
] ; real_T v_ecef [ 3 ] ; real_T lla [ 3 ] ; real_T v_ned [ 3 ] ; real_T uvw
[ 3 ] ; real_T euler [ 3 ] ; real_T pqr [ 3 ] ; }
struct_uXBeANgAqTGhrPgOyPRa5G ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 24
#endif
#ifndef SS_INT64
#define SS_INT64 25
#endif
typedef struct jkyxiblp4k_ jkyxiblp4k ; typedef struct mft3luzpord_
mft3luzpord ;
#endif
