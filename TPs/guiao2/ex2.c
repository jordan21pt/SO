#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>

int main(int argc, char * argv[]){

    puts("Isto é um teste.\n");
    
    pid_t pid = fork();
    
    if(pid == 0) { /* filho */
        printf("CODIGO FILHO: \n\nfilho pid: %d\npai pid: %d\n", getpid(), getppid());
        _exit(0);
    }   
    else{ /*codigo pai*/
        sleep(2);
        printf("CODIGO PAI: \n\npai pid: %d\nfilho pid: %d\n", getpid(), pid);
    }
    
    
    return 0;

}