#ifndef RTW_HEADER_asbCubeSat_h_
#define RTW_HEADER_asbCubeSat_h_
#ifndef asbCubeSat_COMMON_INCLUDES_
#define asbCubeSat_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "asbCubeSat_types.h"
#include "asbCubeSatACS.h"
#include "mwmathutil.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#define MODEL_NAME asbCubeSat
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (726) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (13)   
#elif NCSTATES != 13
#error Invalid specification of NCSTATES defined in compiler command
#endif
#define UseMMIDataLogging
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int8_T hu5jjqenrx ; } m01oraoqyl ; typedef struct { int8_T
bvo4sqc1xt ; } gqrvh5msdq ; typedef struct { int8_T ibsclnmq4a ; } ocsi4aqxck
; typedef struct { int8_T mshrctujti ; } ascfnyzufk ; typedef struct { int8_T
mzkry3c5o5 ; } fr5y2wf3lr ; typedef struct { real_T P [ 15129 ] ; real_T
scaleFactor [ 15129 ] ; real_T ut1utcData [ 11715 ] ; int32_T idx_data [
11715 ] ; int32_T ii_data [ 11715 ] ; uint16_T mjdData [ 11715 ] ; real_T
factor_dX [ 1600 ] ; real_T factor_dX_mbvzarwird [ 1600 ] ; real_T
factor_dX_cl54gopm0x [ 1600 ] ; real_T factor_dX_kkiq3xxxve [ 1600 ] ; real_T
factor_dX_cxarnvbvui [ 1600 ] ; real_T factor_dX_bhxxfovxdy [ 1600 ] ; real_T
factor_dX_pbm3vprmfu [ 1600 ] ; boolean_T x [ 11715 ] ; real_T factor_dY [
1275 ] ; real_T factor_dY_cv5hdgrwft [ 1275 ] ; real_T factor_dY_fqdqrf4qbc [
1275 ] ; real_T factor_dY_g2mlkqadfk [ 1275 ] ; real_T factor_dY_g1smspu5ke [
1275 ] ; real_T factor_dY_merlcviukg [ 1275 ] ; real_T factor_dY_nz4o0shxby [
1275 ] ; real_T P_ppxrqq0gsf [ 529 ] ; real_T scaleFactor_llw0u2ae0v [ 529 ]
; real_T guuurijbhk [ 3 ] ; real_T iw0ifexhed [ 3 ] ; real_T pk5pkkw0ge [ 3 ]
; real_T hvyvygfz3h [ 3 ] ; real_T n4ai4ankzt [ 4 ] ; real_T n2legnbe3a ;
real_T nvup532gka [ 3 ] ; real_T gxxp0akd1l [ 3 ] ; real_T mioxsex0pl [ 3 ] ;
real_T nhhs1xeelz [ 9 ] ; real_T euuuevzxu5 [ 2 ] ; real_T extyfnt5r4 ;
real_T lcgibqnh5g [ 2 ] ; real_T j3x2kcuvfg [ 2 ] ; real_T lc1qx0elmn [ 2 ] ;
real_T gtwk3uafg1 ; real_T c11sdyy513 ; real_T mgqrjcv3gu ; real_T pofk10xeiv
; real_T cmhjoy30bk [ 9 ] ; real_T gdkoorrli3 [ 9 ] ; real_T infjo0hum0 ;
real_T a00doxjmna [ 4 ] ; real_T kzthoypyfy ; real_T hpuxcnuzaa ; real_T
hd2dqvsd3u ; real_T mqmoqkmixy ; real_T izi4w1efrd ; real_T hawoeqewmt ;
real_T nbmpqfv3te ; real_T k01szwz0sd ; real_T b2t2ucrbqo ; real_T kprsuxjlkv
; real_T bkgdni0vs2 ; real_T oufamoptix ; real_T hln50glzm1 ; real_T
pkhyyiawo2 ; real_T j4xtq5uhje ; real_T bab0rzjaev ; real_T dct2vwvlfw ;
real_T jgmwsx5y2l ; real_T ncpar45x4z ; real_T eabf5aklr1 ; real_T afdctvqatp
; real_T k0z040j0oz ; real_T ia4upotdij ; real_T nsfv12l3dt ; real_T
ksy2pcysyk ; real_T cepina2nyg ; real_T gvpgirihtw ; real_T ovvmurfsaq ;
real_T m3bhbs1fa2 ; real_T gfsly2jia4 ; real_T dfvrnjcz5k ; real_T gjbwirhme4
; real_T c4tmgxlhnh ; real_T agxyleorkl ; real_T dv2ba0xord ; real_T
lqdhbmjcnm ; real_T ppg2zfkz0x ; real_T hlt0cv524e ; real_T isafnyqg0q ;
real_T a150xack5u ; real_T gfn5qrl5pb ; real_T bgjz1vfomo ; real_T myx23yxhrh
; real_T iam5uafwpa ; real_T dzthcn1wjg ; real_T chuo3pdrrf ; real_T
khjb1lzc3g ; real_T fkvz1tw0cw ; real_T nodzf3zrs2 ; real_T awoxnmunon ;
real_T esedhnksok ; real_T d1ysrf0jrg ; real_T cjifgbmgh0 ; real_T atfgouoj3g
; real_T etkebj5cmv ; real_T j5hofhpeka ; real_T nj0qlzedft ; real_T
ls20kpkblq ; real_T nxitzjetmq ; real_T lxgczxprn2 ; real_T fb0v3hz3e3 ;
real_T dqxlivmoxs ; real_T gdecrfy4kp ; real_T cziglt5t3s ; real_T lxxbmf041h
; real_T ktqosrh3zx ; real_T lexj5xb1d4 ; real_T jacbl00iqg ; real_T
iy05lorne0 ; real_T ajg3dd3tmu ; real_T nfejjrfhdf ; real_T ppbycepey1 ;
real_T galxbz2xat ; real_T aw52wilktz ; real_T kzriaemvsy ; real_T hhznph12jh
; real_T pisipdgfuq ; real_T jn4t22nxok ; real_T jbddial024 ; real_T
fu3dhzs41o ; real_T eukm53jhwa ; real_T fryjv0qxbi ; real_T jgsgm51lm5 ;
real_T k0pwhokbjt ; real_T hhvhsmangz ; real_T pyjdw3211j ; real_T iw4gbpvkdp
; real_T mtdvdamkon ; real_T fae5n01ceb ; real_T jaz1uak3es ; real_T
ndm0m0oljw ; real_T lykm3mcxms ; real_T had4bkutvu ; real_T gel0qyoah0 ;
real_T ggnxutlwel ; real_T c2iif4aenj ; real_T btqhvi0ygn ; real_T hlye1geqey
; real_T kgt0qg4i0g ; real_T k1wih2iynr ; real_T ndxk0spgnn ; real_T
pvi11xpomq ; real_T m52y0pbkhe ; real_T jghik0d3tt ; real_T mvts2te2oa ;
real_T dtkhu2gp4q ; real_T dxjlpsmvfh ; real_T lefbsry4cr ; real_T dv31rj3vt5
; real_T o1orqvdlht ; real_T fxiuucrzzu ; real_T dveqj35m3t ; real_T
e44ijoewrz ; real_T ibhcs1b0ys ; real_T l4al30u5xg ; real_T chfyn30zyc ;
real_T bevhn0hnn5 ; real_T foveoyt3bh ; real_T nyfyi1po2v ; real_T mvhg1hb02f
; real_T aqadx2kdsn ; real_T l5udaaonvx ; real_T oo4wqiovqp ; real_T
dgrmk1yj2v ; real_T jpiapr2i45 ; real_T lnnr33kong ; real_T dxqpi2ppre ;
real_T nut2bbebyd ; real_T jmae3vhll1 ; real_T jnufyxgesq ; real_T jrgpwtsoju
; real_T ocnlhjfajv ; real_T ltdwm2nrvm ; real_T g4tbvqwmfw ; real_T
ap3gwnqx55 ; real_T pnnwnshzst ; real_T ktzugj3udp ; real_T djtuslxuxc ;
real_T i10bjj25xa ; real_T arp2cmr55e ; real_T dutvkmgsu2 ; real_T fafugmo3o1
; real_T epvd4xespe ; real_T avw0sxxpz4 ; real_T kcrtyw1ecd ; real_T
a5b50ycgvb ; real_T i1woe2gasz ; real_T lh0pxykxv0 ; real_T fqmvs1kydl [ 3 ]
; real_T b1sg2wevzs ; real_T k1axjv32l5 ; real_T jebuiiyfm0 ; real_T
f5axynk1k1 ; real_T etenygrufq ; real_T bsokl54oyr ; real_T bjtlghns5v [ 3 ]
; real_T a1jfo0c50t [ 3 ] ; real_T an4mliak10 ; real_T no0t3owav4 ; real_T
hyrkysp5kv ; real_T ggwdsbftl1 ; real_T fqir5xepdw ; real_T i0svbnzy4j ;
real_T gl3ebmofmq ; real_T d5muwiotlj ; real_T cj2ufcde4r ; real_T fvsfh5ny3v
; real_T dvy0zvcjag ; real_T lgkkgugimm ; real_T gsnqjouwse ; real_T
lsb3444kqj ; real_T l53rgn1vuw ; real_T jp033ysdaq ; real_T mqw1fxwaqf ;
real_T cthjylqeas ; real_T cbv4r3n2jt ; real_T o2rlgvql0b ; real_T gzedii3fd0
; real_T b201yqxpf5 ; real_T nup42f4f5w ; real_T ieuxnl3l4m ; real_T
fwelgawilj ; real_T lxy5c0oyhi ; real_T allgskwdwr ; real_T gu0bhu5ekq ;
real_T alacemrwem ; real_T hyoqr1igfx ; real_T ntptjutfbb ; real_T mrstv0cc1h
; real_T gpc3fsqa52 ; real_T a340lroalg ; real_T dyaqmlumwa ; real_T
b35wfutgqv ; real_T defomigebg ; real_T mv2jvcbpyv ; real_T fce4wysngq ;
real_T atwsjpcxcq ; real_T p5yonj5h5h ; real_T mjaj2ek0mp ; real_T eb2x1dpi3m
; real_T comgelvvhg ; real_T hckecbbmqe ; real_T a002qypzu0 ; real_T
c2k14s2424 ; real_T oueymw4wvz ; real_T dadt5obkh1 ; real_T idju011353 ;
real_T pokyc3exr3 ; real_T p3rfmumhbo ; real_T fh3ieysyif ; real_T nchvgfc1al
; real_T majluymelm ; real_T cadtzkbpom ; real_T avabojjtx2 ; real_T
hwnrwqpx1a ; real_T ik3l5f2yje ; real_T lms5ne2ijm ; real_T o5fdiulo13 ;
real_T gi03yhvhsy ; real_T dcrmvbhlwm ; real_T c1i35j1mas ; real_T hhmut4d3la
; real_T ab5ksjosua ; real_T egocnhz0ug ; real_T bqxuel1uy2 ; real_T
bj1p2fltdu ; real_T px0zqflxiw ; real_T jlb1g4gpls ; real_T ibmsgpbshx ;
real_T jxernodmqy ; real_T li4jon012y ; real_T aclvi2v5as ; real_T e3xm2541zt
; real_T nbom3hefm0 ; real_T lis1vjyxhj ; real_T lfodx5soib ; real_T
kblju3o4ap ; real_T gphtptmt5y ; real_T ijwkugcwun ; real_T hd22pxqoou ;
real_T kj3og0k4ne ; real_T fuff1s2nnq ; real_T h3qm3v3kdc ; real_T nhjyxzcwvy
; real_T efslxoardo ; real_T mi5o0muvrd ; real_T inn42nttii ; real_T
amlqonwru0 ; real_T m3vfhq2t3e ; real_T fn5q5hzp43 ; real_T d5l1kmmjg4 ;
real_T lkqjvpunta ; real_T drotfsdu2r ; real_T oex1icohpm ; real_T opbzje0cwj
; real_T p3lcjzrr20 ; real_T lgpt3p1h1d ; real_T cowusezqeo ; real_T
czvuwbuqut ; real_T h3zwuehtqh ; real_T py33ocs3ce ; real_T evbayfkepm ;
real_T drj0geatsk ; real_T ipku2fiw30 ; real_T d5na5p3azt ; real_T nr1h5ejvy5
; real_T fjg3wjxf3x ; real_T o1mupuqp1e ; real_T llxwydk5iw ; real_T
kynmrkf1di ; real_T ifgocibqsf ; real_T clsz04duxv ; real_T p2iga5lmqb ;
real_T chzxvzvw43 [ 3 ] ; real_T jun30tq2ki [ 3 ] ; real_T m1netkfzs1 [ 3 ] ;
real_T ps5m0r21kg ; real_T k5pyx4h34r [ 3 ] ; real_T oihj4tgj5b ; real_T
nzcogw5ypb ; real_T eogfn30uhr [ 3 ] ; real_T bfzhqsof2q ; real_T cjqdelmxrd
[ 3 ] ; real_T mnpqjp0stq [ 3 ] ; real_T p4lna1nfxn ; real_T hpgqjxggx1 ;
real_T cfirve12h4 ; real_T li3bsu2uqd [ 3 ] ; real_T fl1b20eneb [ 3 ] ;
real_T keljnw1iuf [ 3 ] ; real_T dd3adydc20 ; real_T hip05s4lsp [ 3 ] ;
real_T pu1qvimjlb [ 3 ] ; real_T emcmo2itk4 [ 3 ] ; real_T o3vg4u1otb ;
real_T c2vpep2nf2 ; real_T axyhwxrae3 ; real_T lz1iecck43 ; real_T jfwmsfzmy1
[ 3 ] ; real_T kws1v4jbaz [ 3 ] ; real_T b42boggr34 [ 3 ] ; real_T eg2nwjupjn
[ 3 ] ; real_T laxhuern1z ; real_T clykpcfnle ; real_T ecn0q2aeyu ; real_T
k0vvpdpb3g ; real_T pevfk14gnn ; real_T cvkzhxufux ; real_T jreget2sby ;
real_T mxntl5l5zp ; real_T mz244epi31 ; real_T iacvnraxwc ; real_T h4lwxnjnfe
; real_T iknqyqdg5m ; real_T gf4sz4jpyh ; real_T e2q1yb1cny ; real_T
pketce0yqm ; real_T e5tugucka2 ; real_T kiqq0vxclb ; real_T equry0lijb ;
real_T ofxbkolojn ; real_T hoxa52rmkx ; real_T na4npuoxtw ; real_T msltwrouud
; real_T gl1pcje40q ; real_T ookkrq0bwz ; real_T an5wnuizma ; real_T
fubc014fpq ; real_T joj1p3fqco [ 3 ] ; real_T oez3as5rov ; real_T mutkmkrpen
; real_T olchw5efl0 ; real_T lzk2zvyr3r ; real_T f5fp3bdv0p ; real_T
n1rbnovt01 ; real_T eq2nd4gpi1 ; real_T cs54wpnzop ; real_T hucgk3gqvy ;
real_T fkas4nkukq ; real_T fjxczpptw3 ; real_T lzzfdjfedq ; real_T h15oj4xasw
; real_T n0byspgsuh ; real_T iuslarcsey ; real_T mcx1dshozd ; real_T
b5iwfqjhgb ; real_T fs5jcqm1tx ; real_T c4onuqqvwo ; real_T guoiqxtrov ;
real_T peide24gpx ; real_T cgvfdi1wuf ; real_T akpd3kkidu ; real_T g0ln0zu3ei
; real_T ozudgknpiv ; real_T dhee2zyc3e ; real_T awttvy1p5u ; real_T
fkkq5nfb50 ; real_T o4t3s5vqb1 ; real_T exwxv3a2au ; real_T p0abggakyi ;
real_T gsskf4mkc3 ; real_T dson0bo4t3 ; real_T bmlwl34vfi ; real_T ljaovy31vw
; real_T eoiz5qj4y5 ; real_T arexm4bnfq ; real_T g3xiaqp4s0 ; real_T
jvrvzi5ckh ; real_T pxw02tdykw ; real_T mmocesmebd ; real_T immh3g3gem ;
real_T nvdtttd1ax ; real_T ne5zkzytxo [ 2 ] ; real_T mdl4epmwtp [ 2 ] ;
real_T kz1e5xt1mi [ 2 ] ; real_T aoli5ykwre ; real_T hmkcj2scq1 [ 3 ] ;
real_T dohvz5kjpb [ 3 ] ; real_T kgkakkzugv [ 3 ] ; real_T pq31ryxzkt [ 9 ] ;
real_T pvxhwu0umn ; real_T n43tinwxb0 ; real_T ateb3o4u3o ; real_T injhyqql3b
; real_T isfjpv1njr ; real_T aabsnhj2kd ; real_T ckzly5qc25 ; real_T
oeljweklyi ; real_T mndkwluuum ; real_T jar5eedtpz ; real_T hdywpwyat1 ;
real_T aanx350f2q ; real_T d30ygafl5i ; real_T ndm1yr2ohb ; real_T hg513vryww
; real_T du2jbzkyit ; real_T ixxvmodmwy [ 4 ] ; real_T a1ypqmp2wu [ 4 ] ;
real_T dli03zz0kf ; real_T fqiqsnkhxo ; real_T b53wt3rpmh ; real_T gds5tz5hph
; real_T iqoxfz51na ; real_T oys1hwbynr ; real_T dyolame53c ; real_T
n3z0fhzszq ; real_T ebnkj40kc0 ; real_T g2wnwmqohu ; real_T jvpxa45rtv ;
real_T gble2pognr ; real_T h15kicorrm ; real_T grw2wbkr35 ; real_T pkeh4asimq
; real_T esdvrfmq34 ; real_T gye3zdzzsu [ 5 ] ; real_T inbwuleyhj [ 5 ] ;
real_T c4gs33l0bz ; real_T lfk1tgewfe ; real_T hx5yffvmat ; real_T awnvltps30
; real_T klz40gzlgp ; real_T chemccfpzw ; real_T cijeab3mw0 ; real_T
iric5v3rnp ; real_T de2lgrp2su ; real_T k0pntt5pgt [ 14 ] ; real_T mu3afvwcb4
[ 14 ] ; real_T kgnza0c5un ; real_T cbvffsu30w [ 3 ] ; real_T hp21yfyq2j ;
real_T hut4f1akqa [ 25 ] ; real_T ifgcvd4kzb ; real_T cxhnicelj1 [ 4 ] ;
real_T lgd2xwsrbp ; real_T c34upcggqx [ 8 ] ; real_T bwey3kb1kg [ 66 ] ;
real_T dwwehfjmtf [ 66 ] ; real_T pnnfavymrs [ 66 ] ; real_T ht523alpob [ 66
] ; real_T iwxrcpdt2p [ 66 ] ; real_T asfoggplk4 [ 66 ] ; real_T aody5bgqpu ;
real_T ljvvh5awvq ; real_T gewhm55nlp ; real_T ite3qzvp3a ; real_T frwm532a3n
; real_T mdqamsmzry [ 253 ] ; real_T nqaue0bnvh ; real_T lg0gz0rm3f [ 36 ] ;
real_T dik3mkp3hm ; real_T dg2ek1ol0k [ 4 ] ; real_T ehagrzqqgc ; real_T
eilcjfbk45 [ 1600 ] ; real_T dgz3gxz05z [ 1600 ] ; real_T fdlt3xdnwg [ 1600 ]
; real_T myjcwege0k [ 1600 ] ; real_T jwbpxx3f4u [ 1600 ] ; real_T ot2bqmwuyx
[ 1600 ] ; real_T hostrd2e0i ; real_T hbw2jfawaw ; real_T gx0r33wsso ; real_T
nvtz2zfpvr ; real_T gipt4cbgbq ; real_T gkss0ptds3 [ 277 ] ; real_T
bn2pou2bl0 ; real_T nn1ie5jzbi [ 30 ] ; real_T lvgpbiskyx ; real_T nd3llek0ox
[ 5 ] ; real_T noess5iroi ; real_T nrz2gwljsv [ 1275 ] ; real_T niub2neuf4 [
1275 ] ; real_T oysjl0kttm [ 1275 ] ; real_T pdh5gegjty [ 1275 ] ; real_T
mmbjzckezy [ 1275 ] ; real_T m0ms3ljo3u [ 1275 ] ; real_T fj5yi3ykxy ; real_T
da5f2ylq4n ; real_T kx2c0u3u5n ; real_T oeyk1akhkr ; real_T aer0w543iw ;
real_T mujdahqjlj ; real_T avz20b2egn ; real_T egw3tu4xp3 ; real_T mteampxllo
; real_T gzinpvw3xt ; real_T gstbhhqdxh ; real_T alhpwogw2p ; real_T
drevvy0hct ; real_T ktintt0f0x ; real_T nb3gksrzpz ; real_T nnv3evx02h ;
real_T ectnbtmdkd ; real_T dmjyiarwph ; real_T lql0rbltn5 ; real_T evj3vswqvm
[ 3 ] ; real_T dg12adjixq [ 3 ] ; real_T bn0dfuohf1 [ 3 ] ; real_T lfjfbysi2q
[ 9 ] ; real_T lgwwge3abs ; real_T apgcf2rwum ; real_T ct0bps315h [ 3 ] ;
real_T ha0zi0ujfq [ 3 ] ; real_T kv2f1twl2r [ 3 ] ; real_T erzxlkf332 [ 9 ] ;
real_T a42svilqaa ; real_T pg5rsevnri ; real_T jmfzldcsac ; real_T muwfyxa4lb
; real_T o0lomudnwk ; real_T g4srhdnxm2 ; real_T as5avcknou ; real_T
luisq3j2si ; real_T ekrmx3x14w ; real_T ah4yqzis13 ; real_T dp53v5vqvc ;
real_T pnpnlaosgu ; real_T eq5cbnbfn5 ; real_T diz2cu3xvr ; real_T axgf5whju1
; real_T dd1f5v0pfb ; real_T haemxf10vm [ 4 ] ; real_T lyhi5gapnt [ 4 ] ;
real_T mpyd1hnuzl ; real_T f41bu0m2oq ; real_T gkzlhndvve ; real_T lhjx0yl1li
; real_T b0x351o12f ; real_T p2ww5n3hvf ; real_T l5dvzw5lgj ; real_T
g5g2cujog2 ; real_T p54t25i5cc ; real_T lbelsssv0l ; real_T jgpm4tz1vs ;
real_T hf2yvik2vz ; real_T ajsu0ao51n ; real_T n4bunn5aez ; real_T jpy1v4n0ss
; real_T hg4ica1ipm ; real_T p00wdzmb30 [ 3 ] ; real_T l43axsmmhk [ 3 ] ;
real_T efnxscvqak [ 3 ] ; real_T f5tlon0xoe [ 9 ] ; real_T pznqhrc4sj [ 3 ] ;
real_T mbmcpuzyml [ 3 ] ; real_T f3chg3oisf ; real_T lxpokjgc3x ; real_T
ato3bl1cmc ; real_T lsqs5la1d0 ; real_T pkwqvlilt4 ; real_T nheuokxcdh ;
real_T hp3oxzavtd ; real_T d3lw34jrjn ; real_T nexcukqpgj ; real_T bqhfhwqxpt
; real_T f2kimgo4bl ; real_T gxw0kiaxko ; real_T ljqc4nfb5k ; real_T
hr4e1xbe0b ; real_T gbjky3dp1b ; real_T atwsbea2j3 ; real_T ka5lkmpcx1 ;
real_T faxfchhj03 ; real_T jx1iscr5ja ; real_T ghf4vueaqn ; real_T dozd5vzzyf
; real_T p0rfqushhs ; real_T ndnyv1dxqo ; real_T cswa4mm2ib ; real_T
b422d1lyww ; real_T axuxvrq0v2 ; real_T imzvswpzjs ; real_T lshog2b4ym ;
real_T avvlv4kyvw ; real_T l3hsk551mn ; real_T jzzmpc4yga ; real_T jvwes4xfyt
; real_T d4cgytsdfi ; real_T p21qefwtvn ; real_T bw2hjzbmyf ; real_T
i4eqs14wzu ; real_T pnoqynnphw ; real_T oyki30k1aj ; real_T arogtszhs5 ;
real_T jqgugleprs ; real_T o5ndifgoks ; real_T frmmeddqv5 ; real_T oa1getq115
; real_T fzlt0ijh4o ; real_T cvvt4jf4qb ; real_T ohucyuywpl ; real_T
inb5ttb3jj ; real_T d2rkdr4kkv ; real_T cae1hemhpe ; real_T f351shx3do ;
real_T fslaxrtroo ; real_T nk3orwpupw ; real_T e1rejqlme4 ; real_T mcltshjpun
; real_T m1acjmrbru ; real_T p3ejj2yywg ; real_T hpnuoon2c2 ; real_T
apu1suwoo4 ; real_T dpo23ndn3u ; real_T cxhavlioi0 ; real_T nalz3opatz ;
real_T cmvds0woye [ 3 ] ; real_T hgkeqywwxt ; real_T iuqhwuhkca ; real_T
osh34hsw40 ; real_T h1l0p5yhcd ; real_T mtcu1gi2bm ; real_T a1oscqdt3n ;
real_T nkts1zw0nd [ 3 ] ; real_T gn4ifeeyqu [ 3 ] ; real_T ovwjazpwxg ;
real_T mcbegoyojd ; real_T dgzllg0vkk ; real_T elfpckikpf ; real_T h3ma3ezsd2
; real_T a3xsdbwusr [ 528 ] ; real_T ewxmxolsjd [ 66 ] ; real_T khxt0zslsh [
66 ] ; real_T j25fvdirci [ 22400 ] ; real_T fxt4d3dyo3 [ 1600 ] ; real_T
egtxigpxs2 [ 1600 ] ; real_T g0lkbwhl0q [ 17850 ] ; real_T pft4zg43cd [ 1275
] ; real_T bwfvokrayn [ 1275 ] ; real_T dnp3mvdsnk [ 2 ] ; real_T cv1nz3ipi2
[ 3 ] ; real_T hcq55v0ypr [ 9 ] ; real_T hld5r4mpcx ; real_T lfe4kp3d0k ;
real_T lwdhbbp10z ; real_T i4slsncpux ; real_T dscvoea02i ; real_T mjxvb543yv
; real_T b0k23yli23 ; real_T ia4km4unew ; real_T bri4rma4s3 ; real_T
g5deafji42 [ 9 ] ; real_T bf2gkvzvhk [ 9 ] ; real_T hlgtmfsum4 [ 9 ] ; real_T
n1ulhizcn4 [ 9 ] ; real_T ftha5wn4i2 ; real_T h0ayrtgqgn ; real_T gdo3us25os
; real_T jeigdppz1w [ 2 ] ; real_T kxte1ugnh3 ; real_T hsnto1sbqz [ 3 ] ;
real_T g32x15bn3h [ 3 ] ; real_T erwyczxcim [ 3 ] ; real_T mby2zpgi0o ;
real_T f4snyiph1p ; real_T ld3sypiost ; real_T lqajvqev2l [ 2 ] ; real_T
dlvlrswtgl ; real_T fhmj2yfrou [ 3 ] ; real_T ktrwvilfzc [ 3 ] ; real_T
jkubctpv3f ; real_T bl1ublhpfw ; real_T ngusxfvfg2 ; real_T jdysjfbsej [ 2 ]
; real_T bsvcitorkd ; real_T bck5z40k1v [ 3 ] ; real_T e2fhpl4uaz ; real_T
kj5xpjkk2m ; real_T plsuigbxqp ; real_T bmy1igiqpp [ 3 ] ; real_T iflmhxihtj
; real_T ppk3axevfl ; real_T phbnlihjtt ; real_T mwkb1bzcoz ; real_T
mxcssvp11l ; real_T pctbxfhefd ; real_T cgxi35wofk [ 3 ] ; real_T mm5ncen4fe
[ 3 ] ; real_T dosr5adono ; real_T dgfuaiwrj0 ; real_T fvjnqoeq5i ; real_T
grs2452co2 ; real_T j1uoheqohs ; real_T lejvewwogv ; real_T h3dfililq4 [ 3 ]
; real_T hri4unluzl ; real_T jml3fwaq4d ; real_T majp0azwla ; real_T
kdjio4xbjs ; real_T ohgoypiays ; real_T cite3hkote ; real_T lsi2pw5qup [ 3 ]
; real_T palvaexdep [ 3 ] ; real_T oahfmv23w2 [ 3 ] ; real_T cvsz0qnfzh [ 3 ]
; int16_T a45gkht3ip ; int16_T cyyo2qtv2q ; int16_T af0lwj33ym ; int16_T
ejhhbtmhu4 ; int16_T gcm4xk3lvn ; int16_T cqhzk1dyri ; boolean_T e2i0xale0b ;
boolean_T i5yf34r0pc [ 9 ] ; boolean_T cbjg4akslo ; } ktuiv5qnvo ; typedef
struct { real_T gwyrl50tya [ 3 ] ; real_T du2milvecl [ 3 ] ; real_T
iqedkgi5kk [ 3 ] ; real_T hawwsxl4jq ; struct { void * LoggedData [ 2 ] ; }
pdfdeemjq4 ; struct { void * LoggedData [ 2 ] ; } aj5t0gg2hd ; struct { void
* LoggedData [ 2 ] ; } mnn0jyia2d ; struct { void * TimePtr ; void * DataPtr
; void * RSimInfoPtr ; } hfhy23msiy ; struct { void * AQHandles ; }
ll4fbyoldn ; uint32_T dtie3bzjg2 ; struct { int_T PrevIndex ; } j2dtrztjsi ;
int_T anodop3bfa ; int_T fg4e4z0egr [ 3 ] ; int_T bhnkfapntu ; int_T
nwaltvddtq ; int_T hoejundm1l ; int8_T gzwsybef1l ; int8_T glq4slztmz ;
int8_T c5sjcg22th ; int8_T h3dnvjagyt ; int8_T mmdaege3a4 ; int8_T dg2zdvbf30
; int8_T np350cmfgt ; int8_T oep1m0ng2h ; int8_T pq1kuxnyvo ; int8_T
lfr0buot3d ; int8_T nkmv45wa3j ; int8_T gqb3wumnnb ; int8_T g54ohlxfz0 ;
int8_T j4vy4l4h0i ; int8_T o2jni4uypc ; int8_T a3qoyxgbtd ; int8_T c3ovqbbxtp
; int8_T n4rxz4dznf ; int8_T nhnftpzwqv ; int8_T i5gew0eykk ; int8_T
jwmfebhkdp ; int8_T c1r2s0jhqc ; int8_T nggkabx0mf ; int8_T jopax3kg4g ;
int8_T cqhfzkqvew ; int8_T fkef5z4gjh ; int8_T jnmhg3kfyb ; int8_T gv5etq1ziu
; int8_T hehcr1ojvh ; boolean_T jici0zznxs ; boolean_T cklzsbe4ur ; boolean_T
ehgalwj0ga ; boolean_T p1hrhogcsi ; boolean_T jh5c3dhyui ; boolean_T
p1bzomtpcv ; boolean_T db3flg0lbt ; boolean_T oovk1t0bug ; boolean_T
f3qlbdflbf ; boolean_T ct5m3lxryd ; obi5idc0yut aus50sqkr0 ; ascfnyzufk
cjccm1bbjg ; ascfnyzufk p52hhsg2cj ; fr5y2wf3lr dtyvlyi1u0 ; fr5y2wf3lr
dmj10vcnymf ; ascfnyzufk fhdycuvak1o ; ocsi4aqxck ckm0lumt30 ; ocsi4aqxck
pookmfxkbnb ; gqrvh5msdq lanzmspcia ; m01oraoqyl k1md1brudn ; gqrvh5msdq
enr11s3r13x ; m01oraoqyl atygzznv2xe ; } dzu2rlzxmw ; typedef struct { real_T
mhexdtzhzk [ 13 ] ; } e0vrfmpfmv ; typedef struct { real_T mhexdtzhzk [ 13 ]
; } inbmaj2xsz ; typedef struct { boolean_T mhexdtzhzk [ 13 ] ; } jfg10rquyj
; typedef struct { real_T mhexdtzhzk [ 13 ] ; } dkvt4sgawi ; typedef struct {
real_T mhexdtzhzk [ 13 ] ; } lerezfmokg ; typedef struct { real_T mhexdtzhzk
[ 13 ] ; } oaixwpiuad ; typedef struct { real_T cwpuhcrgpi ; real_T
kifixhef2v ; real_T nlevwdgdtq ; real_T itquqs5fu3 ; real_T c5tnygmrha ;
real_T p1daz2c5wj ; real_T mtdj10k4d1 ; real_T flp13ut5c1 ; real_T jb41bpfar1
[ 3 ] ; real_T bk305wltlm [ 2 ] ; real_T nwrzutk0eq ; real_T gidzmbwww0 ;
real_T j2v3drh55m ; real_T bstbqwqb4y ; real_T gv3engnv2x ; real_T gogagl0ey4
; } ko5zfiqifu ; typedef struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMappingInfo * childMMI [ 1 ] ; } DataMapInfo ; struct
jkyxiblp4k_ { real_T Bias1_Bias ; real_T Bias_Bias ; } ; struct mft3luzpord_
{ real_T JulianDateConversion_day ; real_T
JulianDateConversion_day_jfiplnwspy ; real_T R_woPM_hour ; real_T R_woPM_min
; real_T CheckdeltaT_minmax [ 2 ] ; real_T CheckdeltaT_minmax_g0fnktg5hy [ 2
] ; real_T CheckdeltaT_minmax_kymaumun3y [ 2 ] ; real_T
JulianDateConversion_month ; real_T JulianDateConversion_month_apao5pt3qs ;
real_T R_woPM_sec ; real_T JulianDateConversion_sec ; real_T
JulianDateConversion_sec_c3x0bnrbfj ; real_T BandLimitedWhiteNoise_seed ;
real_T DirectionCosineMatrixtoQuaternions_tolerance ; real_T R_woPM_year ;
uint8_T DirectionCosineMatrixtoQuaternions_action ; real_T Gain_Gain ; real_T
Gain1_Gain ; real_T Gain_Gain_kivbr5qcsu ; real_T Gain1_Gain_moqth4txth ;
real_T Constant_Value ; real_T Switch_Threshold ; real_T Gain_Gain_izphj4ykdx
; real_T Constant1_Value ; real_T Constant2_Value [ 2 ] ; real_T
Constant_Value_ow0d0ucmo4 ; real_T Switch_Threshold_gw2gwghagz ; real_T
Gain_Gain_evf1m0norx ; real_T Constant1_Value_i1g2sgu4pn ; real_T
Constant2_Value_g1l3jouubp [ 2 ] ; real_T Constant_Value_hx1erq5der ; real_T
Switch_Threshold_aq5bmfyfby ; real_T Gain_Gain_fr1kekirc0 ; real_T
Constant1_Value_iunxkpjmrj ; real_T Constant2_Value_kutdpfvzpu [ 2 ] ; real_T
Constant_Value_ddxk042hnl ; real_T Bias_Bias ; real_T Bias1_Bias [ 9 ] ;
real_T SpacecraftDynamics_startDate ; real_T SpacecraftDynamics_mass ; real_T
SpacecraftDynamics_emptyMass ; real_T SpacecraftDynamics_fullMass ; real_T
SpacecraftDynamics_inertia [ 9 ] ; real_T SpacecraftDynamics_emptyInertia [ 9
] ; real_T SpacecraftDynamics_fullInertia [ 9 ] ; real_T
SpacecraftDynamics_semiMajorAxis ; real_T SpacecraftDynamics_eccentricity ;
real_T SpacecraftDynamics_inclination ; real_T SpacecraftDynamics_raan ;
real_T SpacecraftDynamics_argPeriapsis ; real_T
SpacecraftDynamics_trueAnomaly ; real_T SpacecraftDynamics_trueLon ; real_T
SpacecraftDynamics_argLat ; real_T SpacecraftDynamics_lonPeriapsis ; real_T
SpacecraftDynamics_inertialPosition [ 3 ] ; real_T
SpacecraftDynamics_inertialVelocity [ 3 ] ; real_T
SpacecraftDynamics_fixedPosition [ 3 ] ; real_T
SpacecraftDynamics_fixedVelocity [ 3 ] ; real_T SpacecraftDynamics_attitude [
3 ] ; real_T SpacecraftDynamics_attitudeRate [ 3 ] ; real_T
SpacecraftDynamics_customR ; real_T SpacecraftDynamics_customF ; real_T
SpacecraftDynamics_customMu ; real_T SpacecraftDynamics_customJ2 ; real_T
SpacecraftDynamics_customOmega ; real_T SpacecraftDynamics_cbRA ; real_T
SpacecraftDynamics_cbRARate ; real_T SpacecraftDynamics_cbDec ; real_T
SpacecraftDynamics_cbDecRate ; real_T SpacecraftDynamics_cbRotAngle ; real_T
SpacecraftDynamics_cbRotRate ; real_T SpacecraftDynamics_F107ExtrapValue ;
real_T SpacecraftDynamics_MagneticIndexExtrapValue ; real_T
SpacecraftDynamics_fluxFlags [ 23 ] ; real_T SpacecraftDynamics_dragCoeff ;
real_T SpacecraftDynamics_dragArea ; real_T
SpacecraftDynamics_customThirdBodyMu ; real_T
SpacecraftDynamics_reflectivityCoeff ; real_T SpacecraftDynamics_srpArea ;
real_T SpacecraftDynamics_fluxPressure ; real_T Gain1_Gain_orieqgtt02 ;
real_T ECEFPositiontoLLA_F ; real_T ECEFPositiontoLLA_R ; real_T
Merge_InitialOutput [ 4 ] ; real_T Gain2_Gain ; real_T Gain_Gain_aeurxbr2xa ;
real_T Gain1_Gain_pedhjk3l0w ; real_T Gain2_Gain_knwh4jjhgm ; real_T
Gain_Gain_mp1avifkbq ; real_T Gain_Gain_escty4bikv ; real_T
Gain2_Gain_lysqvltbwk ; real_T Gain1_Gain_gmw4nonk31 ; real_T
Gain1_Gain_nmosenzgoi ; real_T Gain_Gain_clt0oe2jcc ; real_T
Gain1_Gain_jo1dgknebu ; real_T Gain2_Gain_pnmfylbi0q ; real_T
Gain_Gain_czwfhdqf0f ; real_T Gain2_Gain_prbzq5j2se ; real_T
Gain1_Gain_ev0uizkmtz ; real_T Gain_Gain_me1vwitrjg ; real_T
Gain1_Gain_dzsbbhvgtv ; real_T Gain2_Gain_pgjyltyift ; real_T
Gain2_Gain_m4uopcslb2 ; real_T Gain_Gain_a1oq04fhso ; real_T
Gain1_Gain_j3lqal51r3 ; real_T Gain2_Gain_f5gfa2xbo3 ; real_T
Gain_Gain_ewunwjmrjj ; real_T Gain_Gain_ivl4caakzk ; real_T
Gain2_Gain_mtveb5vwbi ; real_T Gain1_Gain_igj42gvjw0 ; real_T
Gain1_Gain_lcgtpue1h3 ; real_T Gain_Gain_olpgkopvk2 ; real_T
Gain1_Gain_na1zdvwene ; real_T Gain2_Gain_fvkshagg3a ; real_T
Gain_Gain_lsieffoi0o ; real_T Gain2_Gain_jewrat51px ; real_T
Gain1_Gain_erscuwjloz ; real_T Gain_Gain_duxhfrawi3 ; real_T
Gain1_Gain_e4odrydyif ; real_T Gain2_Gain_pzdgx2rnht ; real_T Mode_Value ;
real_T fromWS_Signal1_Time0 [ 23 ] ; real_T fromWS_Signal1_Data0 [ 23 ] ;
real_T UnitDelay_InitialCondition ; real_T Gain_Gain_at23p32wum ; real_T
WhiteNoise_Mean ; real_T WhiteNoise_StdDev ; real_T Output_Gain [ 3 ] ;
real_T Gain1_Gain_igngtbiok1 ; real_T
InternationalGeomagneticReferenceField_year ; real_T Multiply_Gain ; real_T
u2_Gain ; real_T Gain_Gain_b4kz03smvc ; real_T Gain1_Gain_jyrvy3oq3i ; real_T
Gain2_Gain_j2fcwmf3ic ; real_T Gain_Gain_fbha4wgaqf ; real_T
Gain1_Gain_aa5dlx5byr ; real_T Gain2_Gain_ed3repcl3l ; real_T
Gain_Gain_fabcrkyzjm ; real_T Gain1_Gain_fzi0iddve2 ; real_T
Gain2_Gain_kyrvvabcr5 ; real_T JDtoMJD_Bias ; real_T Bias1_Bias_n4pesdjpoq ;
real_T Gain_Gain_e1lml00aw5 ; real_T Gain1_Gain_p1otunaeie ; real_T
BiasYear_Bias ; real_T Gain_Gain_axnikwuifz ; real_T Bias1_Bias_hy5y5oev5q ;
real_T Gain1_Gain_glxd1bjwm2 ; real_T Bias2_Bias ; real_T
Gain2_Gain_pbmlqtpwak ; real_T Gain3_Gain ; real_T BiasDay_Bias ; real_T
Gain5_Gain ; real_T Gain6_Gain ; real_T Gain4_Gain ; real_T
Bias1_Bias_ouqlaypeza ; real_T Gain_Gain_chvwhbhhfb ; real_T mMoon_Coefs [ 5
] ; real_T mSun_Coefs [ 5 ] ; real_T umMoon_Coefs [ 5 ] ; real_T dSun_Coefs [
5 ] ; real_T omegaMoon_Coefs [ 5 ] ; real_T Gain_Gain_cpeyq2kt4r ; real_T
lMercury_Coefs [ 2 ] ; real_T lVenus_Coefs [ 2 ] ; real_T lEarth_Coefs [ 2 ]
; real_T lMars_Coefs [ 2 ] ; real_T lJupiter_Coefs [ 2 ] ; real_T
lSaturn_Coefs [ 2 ] ; real_T lUranus_Coefs [ 2 ] ; real_T lNeptune_Coefs [ 2
] ; real_T pa_Coefs [ 3 ] ; real_T S0_Coefs [ 6 ] ; real_T
Gain2_Gain_n5g25zmhpr ; real_T X0_Coefs [ 6 ] ; real_T Gain3_Gain_gr5zfo0fso
; real_T Y0_Coefs [ 6 ] ; real_T Gain4_Gain_lam1ry24pn ; real_T
Gain5_Gain_blke3ewpwn ; real_T Gain1_Gain_nsj0bxjlmo ; real_T
Gain_Gain_df5argzxes ; real_T BiasYear_Bias_ghpkwahlsd ; real_T
Gain_Gain_oejzcz04jv ; real_T Bias1_Bias_duf30x5aqp ; real_T
Gain1_Gain_e2kkyoyee3 ; real_T Bias2_Bias_g3uaetf0tk ; real_T
Gain2_Gain_knsbj52ux0 ; real_T Gain3_Gain_ci5kwcqg3o ; real_T
BiasDay_Bias_nvtsg4axzf ; real_T Gain5_Gain_dtm3ugqzx3 ; real_T
Gain6_Gain_gt43g54iiv ; real_T Gain4_Gain_afda5l01ro ; real_T gainVal_Gain ;
real_T Bias_Bias_ht3nqo3215 ; real_T Bias1_Bias_mg5rk1exfd ; real_T
Gain_Gain_aidnlesuhh ; real_T Gain1_Gain_c3rulevhri ; real_T
Constant_Value_l5ckikavo3 [ 3 ] ; real_T Gain2_Gain_a1syec2s31 ; real_T
Gain_Gain_pqmdh5vchy ; real_T Gain1_Gain_nbsdyosk31 ; real_T
Gain_Gain_mpffh2nq4u ; real_T Gain2_Gain_pqei0he1km ; real_T
Gain1_Gain_lpavq11n4s ; real_T Gain_Gain_o3sxaj3ene ; real_T
Gain1_Gain_orrcgn1tbv ; real_T Gain2_Gain_phscpgr5dh ; real_T
Gain_Gain_pfj5uh0yxl ; real_T Constant4_Value [ 3 ] ; real_T
Constant_Value_mlyvhryvl4 ; real_T Constant_Value_b2hs15ndbn ; real_T
Constant_Value_phd5yzqylt ; real_T Constant_Value_owwiycbby1 ; real_T
Constant_Value_gmigjdfjuw ; real_T Constant_Value_pmy1l35byt ; real_T
Constant_Value_biutajyugl ; real_T Constant_Value_m1oonqfthg ; real_T
Constant_Value_hn5ydqy3jt ; real_T Constant_Value_f0bfrhfyac ; real_T
Constant_Value_flvobjxhc0 ; real_T Constant_Value_ax5bexr1pq ; real_T
Constant_Value_h3m33ozfdb ; real_T Constant2_Value_ivjjl1g2hc [ 3 ] ; real_T
Constant4_Value_j1w1qwfq14 [ 3 ] ; real_T Forces_Body_Value [ 3 ] ; real_T
Torques_Body_Value [ 3 ] ; real_T Constant_Value_eiwjhyz04e [ 3 ] ; real_T
Constant_Value_dkahyu4aso ; real_T Constant_Value_dof0b35akk ; real_T
Constant_Value_jy0mtl1wa1 ; real_T Constant1_Value_ky0zm1vdu3 ; real_T
Bias_Bias_f4lfrmc2xj ; real_T Constant2_Value_p54gbuogdj [ 2 ] ; real_T
dayFrac_Value ; real_T Bias_Bias_fjuplsuwzh ; real_T Index_Value ; real_T
sec2_Value [ 4 ] ; real_T secGain_Gain ; real_T Constant_Value_ks2rtaqm2w ;
real_T Constant_Value_ngx3b40ddb ; real_T Constant_Value_ka0pbbhorg [ 726 ] ;
real_T Constant1_Value_irkdi15zer [ 33 ] ; real_T Constant2_Value_cx3x515qe0
[ 3 ] ; real_T Constant3_Value [ 25 ] ; real_T Constant4_Value_j3b3aeoial [ 4
] ; real_T Constant_Value_cww0o13hsc [ 27200 ] ; real_T
Constant1_Value_bwchvceojl [ 1306 ] ; real_T Constant2_Value_gx522e5n1j [ 253
] ; real_T Constant3_Value_d5tvlckvat [ 36 ] ; real_T
Constant4_Value_pmgolxbdck [ 4 ] ; real_T Constant_Value_bsb1eyrosh [ 21675 ]
; real_T Constant1_Value_koj4fsl1yw [ 962 ] ; real_T
Constant2_Value_kfa1fs22lj [ 277 ] ; real_T Constant3_Value_enixzxza2u [ 30 ]
; real_T Constant4_Value_g2xufcdbgx [ 5 ] ; real_T Gain1_Gain_jnadjjzdgl ;
real_T Constant_Value_mecuslcgq2 ; real_T Index_Value_flbipmhhsx ; real_T
sec2_Value_oqaeuutie2 [ 4 ] ; real_T Constant_Value_axzjsxmzbr ; real_T
Constant1_Value_pr5ujgrsn1 [ 2 ] ; real_T const1_Value ; real_T const5_Value
; real_T Constant_Value_ma0t3mpr24 ; real_T Constant1_Value_lj35wik0h0 ;
real_T Constant_Value_infl2wzd2x ; real_T Constant_Value_ae5xsg5zwg ; real_T
Constant_Value_gno3p02nfv ; real_T Constant_Value_f1uqwlg30t ; int32_T
InternationalGeomagneticReferenceField_month ; int32_T
InternationalGeomagneticReferenceField_day ; uint8_T
Enablecustomgravitycalculation_CurrentSetting ; jkyxiblp4k k1md1brudn ;
jkyxiblp4k atygzznv2xe ; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR
; extern ktuiv5qnvo ktuiv5qnvo2 ; extern e0vrfmpfmv e0vrfmpfmv0 ; extern
dzu2rlzxmw dzu2rlzxmw1 ; extern mft3luzpord mft3luzpor ; extern
struct_uXBeANgAqTGhrPgOyPRa5G rtP__initCond2f2asbCubeSatModelData_sldd_ ;
extern mxArray * mr_asbCubeSat_GetDWork ( ) ; extern void
mr_asbCubeSat_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_asbCubeSat_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * asbCubeSat_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
