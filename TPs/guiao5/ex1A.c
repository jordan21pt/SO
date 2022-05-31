#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
    int fd[2];
    if(pipe(fd) == -1){
        return 4;
    }

    char mensagem[] = "Ola mundo!"; 

    int pid = fork();
    if(pid == -1){
        return 1;
    }

    sleep(5);
    if (write(fd[1], &mensagem, sizeof(mensagem)) == -1){
        return 3;
    }
    

    if (pid == 0){
        /* child process*/
        char str[30]; 
        close(fd[1]);
        if (read(fd[0], &str, 30) == -1){
            return 2;
        }
        close(fd[0]);
        printf("Sou o filho\n%s\n", str);
        _exit(1);
    }

    close(fd[1]);
    wait(pid);
    return 0;
}
