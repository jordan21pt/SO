#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){

    int nBytes;
    int fd[2];
    pipe(fd);
    if (pipe(fd) == -1){ return 2; }
    
    int pid = fork();
    if(pid == -1){ return 1; }

    if (pid == 0){
        // processo filho...
        close(fd[1]);
        char str[50];
        while ((nBytes = read(fd[0], &str, 50)) > 0);
        printf("%s\n", str);
        close(fd[0]);
        _exit(1);
    }
    else{
        //pai
        close(fd[0]);
        char mensagem[] = "Ola mundo...";
        write(fd[1], &mensagem, sizeof(mensagem));
        close(fd[1]);
        wait(pid);
    }

    return 0;
}
