#include "types.h"
#include "defs.h"
#include "sysinfo.h"



uint64 systeminfo(uint64 addr){
    struct proc *p = myproc();
    struct sysinfo info;
    info.freemem = memorycount();
    info.nproc = proc_count();
    if(copyout(p->pagetable, addr, (char *)&info, sizeof(info)) < 0)
        return -1;
    return 0;
}