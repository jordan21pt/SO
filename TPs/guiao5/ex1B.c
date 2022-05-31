#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]){
    
    int fd[2];
    char mensagem[30];

    pipe(fd);
    if (pipe(fd) == -1){
        return 1;
    }

    int pid = fork();
    if (pid == -1){
        return 2;
    }
    
    if (pid == 0){
        //processo filho...
        char str[] = "Ola mundo!";
        close(fd[0]);
        if (write(fd[1], &str, sizeof(str))){
            return 3;
        }
        close(fd[1]);
        _exit(1);  
    }
    else{
        //processo pai...
        if (read(fd[0], &mensagem, 30) == -1){
            return 5;
        }
        
        close(fd[0]);
        close(fd[1]);
        wait(pid);
        printf("%s\n", mensagem);
    }

    return 0;
}
