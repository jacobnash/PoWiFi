#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    pid_t pid;
    int device = 1;
    int fd2;														//redirect output flag

    fd2 = open("/dev/null", O_WRONLY);	//open file2, return new descriptor
    if(fd2 == -1) {												//descriptor error check if file is already created
        perror("/dev/null");
        exit(1);
    }
    int chfd = dup2(fd2, STDOUT_FILENO);							//duplicate file descriptor2 to stdout
    if (chfd == -1) {
        perror("/dev/null");
        exit(1);
    }
    int chfd2 = dup2(fd2, STDERR_FILENO);							//duplicate file descriptor2 to stdout
    if (chfd2 == -1) {
        perror("/dev/null");
        exit(1);
    }
    close(fd2);													//close file descripto
    while(device){
        pid = fork();
        if (pid == 0 ){

            // char* exec[] = {"curl", "192.168.0.1/txt.txt", NULL};
            char* exec[] = {"curl", "https://www.cs.cmu.edu/afs/cs/academic/class/15213-f99/www/class26/udpserver.c", NULL};
            execvp(exec[0], exec);
        }
        else 
            waitpid(pid,NULL,0);
    }
}
