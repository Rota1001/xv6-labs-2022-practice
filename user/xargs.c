#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

int main(int argc, char *argv[]){
    char buf;
    if(argc < 2){
        fprintf(2, "xargs: too few args");
        exit(1);
    }
    while(1){
        char* command = argv[1];
        char args[MAXARG][100];
        int cnti = 0;
        int cntj = 0;
        for(int i = 1; i < argc; i++){
            strcpy(args[cnti++], argv[i]);
        }
        int res;
        int b = 0;
        while((res = read(0, &buf, 1)) > 0 && buf != '\n'){
            if(buf == ' ' && b == 1){
                args[cnti][cntj] = 0;
                cntj = 0;
                cnti++;
                b = 0;
                continue;
            }
            b = 1;
            args[cnti][cntj++] = buf;
        }
        if(res <= 0)
            break;
        args[cnti][cntj] = 0;
        cnti++;
        char* input[MAXARG];
        for(int i = 0; i < cnti; i++){
            input[i] = args[i];
        }
        input[cnti] = 0;
        if(fork() == 0){
            exec(command, input);
            exit(0);
        }
        wait(0);
        
    }
    exit(0);
}