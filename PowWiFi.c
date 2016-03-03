#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    pid_t pid;
    int device = 1;
    while(device){
        pid = fork();
        if (pid == 0 ){
            char* exec[] = {"curl", "192.168.0.1/txt.txt", NULL};
            execvp(exec[0], exec);
        }
        else 
            waitpid(pid,NULL,0);
    }
}
