#include "types.h"
#include "info.c"
// #include "sysinfo.h"




uint64 sys_sysinfo(void){
    uint64 st;
    argaddr(0, &st);
    // return systeminfo(st);
    // return 0;
    return systeminfo(st);
}