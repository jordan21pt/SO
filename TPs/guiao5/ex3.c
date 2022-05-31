#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h>

#define SIZE 100
char buffer[SIZE];


int main(int argc, char const *argv[]){
    
    int n;
    int fd[2];
    pipe(fd);
    if (pipe(fd) == -1){
        return 1;
    }
    
    int pid = fork();
    if (pid == -1){
        return 2;
    }

    if (pid == 0){
        //processo filho
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", NULL);
        _exit(-1);        
    }
    else{
        //codigo pai
        close(fd[0]);
        
        while ((n = readln(0, ))))
        {
            /* code */
        }
        
        

    }
    
    


    return 0;
}
