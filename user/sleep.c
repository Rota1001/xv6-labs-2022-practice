#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(2, "sleep: argument error");
        exit(1);;
    }
    int t = atoi(argv[1]);
    if(sleep(t) != 0){
        fprintf(2, "sleep: execution error");
    }
    exit(0);
}