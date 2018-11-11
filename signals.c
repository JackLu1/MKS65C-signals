#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static void stop(int signo){
    char * msg = "Program exited because of SIGINT\n";
    printf("%s", msg);
    int file = open("log.txt", O_WRONLY | O_APPEND);
    write(file, msg, strlen(msg) );
    exit(0); 
}
static void parent(int signo){
    printf("Parent = %d\n", getppid());
}
int main(){
    signal(SIGINT, stop);
    signal(SIGUSR1, parent);
    while(1){
        printf("Process ID = %d\n", getpid());
        sleep(1);
    }

    return 0;
}
