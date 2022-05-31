#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main(int argc, char * argv[]){

    pid_t pid = fork();
    int status = 0;

    
    if(pid == 0){
        //printf("O meu pid é: %d e o do pai : %d", getpid(), getppid());
        //putchar('\n');
        execlp("ls", "ls", "-l", NULL);
        _exit(0);
    }
    else{
        pid = wait(&status);
        //printf("pid do filho: %d e ppid: %d", pid, getpid());
        printf("status = %d.\nChegou aqui?\n", status);
    }
    
    return 1;
}