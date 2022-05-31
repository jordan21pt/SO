#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>

int main(int argc, char * argv[]){

    puts("Isto é um teste.\n");
    
    int i;

    for (i = 0; i < 10; i++){
        pid_t pid = fork();
        int status;

        if(pid == 0) { /* filho */
            printf("CODIGO FILHO(%d): filho pid: %d pai pid: %d\n",i, getpid(), getppid());
            _exit(i);
        }   
        else{ /*codigo pai*/
            pid = wait(&status);
            printf("CODIGO PAI: pai pid: %d pid: %d\n", getpid(), pid);
        }
        printf("\n\n\n");
    }
    
    return 0;
}