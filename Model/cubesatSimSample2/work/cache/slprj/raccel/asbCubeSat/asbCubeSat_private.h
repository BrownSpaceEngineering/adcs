#ifndef RTW_HEADER_asbCubeSat_private_h_
#define RTW_HEADER_asbCubeSat_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "asbCubeSat.h"
#include "asbCubeSat_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)     (((v1)==(v2))?((double)(v1)):    (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?     muDoubleScalarFloor((v) + 0.5) :     muDoubleScalarCeil((v) - 0.5) )
#endif
extern void l152oexjzd ( SimStruct * rtS_e ) ; extern void p0jh2umvpc (
SimStruct * rtS_p ) ; extern void atygzznv2x ( real_T jcc1jqmswh , real_T
j3ndygrnba , real_T * opokattcr4 , real_T * mkjpz3onuj , jkyxiblp4k * localP
) ; extern void drjcdi2dvf ( SimStruct * rtS_i ) ; extern void coytytvmiv (
SimStruct * rtS_m ) ; extern void enr11s3r13 ( real_T gohcenjyrw , real_T
nepsfibfq0 , real_T * mvr2cth2sd , real_T * kgycvxynrs ) ; extern void
olzoabygng ( SimStruct * rtS_p ) ; extern void cqvdyxqb5g ( SimStruct * rtS_g
) ; extern void fie4zq14tn ( SimStruct * rtS_m ) ; extern void d4jlh1svjg (
SimStruct * rtS_f ) ; extern void ddjc5j5g3h ( SimStruct * rtS_c ) ; extern
void nvjygc22lj ( SimStruct * rtS_k ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
