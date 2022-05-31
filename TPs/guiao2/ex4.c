#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>

int main(int argc, char * argv[]){

    puts("Isto é um teste.\n");

    pid_t pid ;
    int status;
    int i;

    for (i = 0; i < 10; i++){
        if(fork()== 0) { /* filho */
            printf("CODIGO FILHO(%d): filho pid: %d pai pid: %d\n", i, getpid(), getppid());
            _exit(i);
        }   
    }
    for (i = 0; i<10 ; i++){
            pid = wait(&status);
            printf("Terminou o filho %d com pid: %d\n", WEXITSTATUS(status), pid);
        }
        printf("\n\n\n");
        printf("PAI: %d", getpid());

    return 0;
}