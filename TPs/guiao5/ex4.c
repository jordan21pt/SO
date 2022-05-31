#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    // ls /etc | wc -l

    int fd[2];
    if (pipe(fd) == -1){
        return 1;
    }

    int pid1 = fork();
    if (pid1 == -1){
        return 2;
    }

    if (pid1 == 0){
        //child process 1 (ls)
        dup2(fd[1], STDOUT_FILENO); //o que ia ser enviador para o stdout vai ser enviado para o fd[1]
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", "/etc", NULL);
    }

    int pid2 = fork();
    if (pid2 == -1){
        return 3;
    }

    if (pid2 == 0){
        //child process 2 (wc)
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", "-l", NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;

}