#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main(int argc, char * argv[]){

    pid_t pid;
    int status = 0;

    for (int i = 1; i < argc; i++){
        if((pid = fork()) == 0){
            execlp(argv[i], argv[i], NULL);
            _exit(-1);
        }
    }
    for (int i = 1; i < argc; i++){
        pid = wait(&status);
        //printf("pid do filho: %d e ppid: %d", pid, getpid());
        printf("Executado no processo %d com status %d\n", pid, WEXITSTATUS(status));
    }
    
    return 1;
}