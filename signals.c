#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void stop(int signo){
    printf("got signal SIGINT\n");
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
