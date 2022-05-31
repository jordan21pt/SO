#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

int segundos = 0;
int control_c = 0;

void handler(int signum){
    switch (signum){
    case SIGALRM:
        segundos++;
        alarm(1);
        break;
    case SIGINT:
        printf("segundos = %d\n", segundos);
        control_c++;
        break;
    case SIGQUIT:
        printf("control_c = %d\n", control_c);
        _exit(1);
        break;
    }
}

int main(int argc, char * argv[]){
    
    signal(SIGINT, handler);
    signal(SIGALRM, handler);
    alarm(1);

    while(1)
        pause();

    return 0;
}