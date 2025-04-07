#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

//sprintf(char *str, const char *format, ...)
//mkdir(const char *path, mode_t mode) //mode 0700 frwx
//chmod(const char *path, mode_t mode)
//clock_t clock()
//usleep(useconds_t microseconds) //useconds_t ∈ [0, 1e6]


int main(int argc, char *argv[]) {
    
    char dirName[20];
    
    if(argc <= 1) return 1;
    
    for(int argn = 1; argn < argc; argn+=1){
        if(!strcmp(argv[argn], "makedirectorytest")){
            if(argc == ++argn) return 1;
            char *end;
            int value = strtol(argv[argn], &end, 10);
            if( *end != '\0' ) return 2;
            for(int i = 1; i <= value; i+=1){
                sprintf(dirName, "parent_dir_%i", i);
                mkdir(dirName, 0700);
                for(int j = 1; j <= value; j+=1){
                    sprintf(dirName, "parent_dir_%i/dir_%i",i , j);
                    mkdir(dirName, 0700);
                }
            }
        } else if(!strcmp(argv[argn], "test") || !strcmp(argv[argn], "aaaa")) {
            printf("works!");
        }
    }
    return 0;
    
}
