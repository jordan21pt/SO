#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int criaPipes(int fd[][2], int n){
    for (int i = 0; i < n; i++) {
        if (pipe(fd[i]) == -1) return -1;
    }
    return 0;
}

void closePipes(int pipes[][2], int n){
    for (int i = 0; i < n; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
}

int main() {
    //grep -v ˆ# /etc/passwd  |  cut -f7 -d:  |  uniq  |  wc -l

    int fd[3][2];
    if (criaPipes(fd, 3) == -1){
        return 1;
    }
    
    //if (pipe(fd[0]) == -1) return 1;
    //if (pipe(fd[1]) == -1) return 3;
    //if (pipe(fd[2]) == -1) return 5;


    int pid1 = fork();
    if (pid1 == -1) return 2;

    if (pid1 == 0){
        //child process 1 (grep)
        dup2(fd[0][1], STDOUT_FILENO);
        closePipes(fd, 3);
        execlp("grep", "grep", "-v", "ˆ#", "/etc/passwd", NULL);
    }


    int pid2 = fork();
    if (pid2 == -1) return 4;

    if (pid2 == 0){
        //child process 2 (cut)
        dup2(fd[0][0], STDIN_FILENO);
        dup2(fd[1][1], STDOUT_FILENO);
        closePipes(fd, 3);
        execlp("cut", "cut", "-f7", "-d:", NULL);
    }


    int pid3 = fork();
    if (pid3 == -1) return 6;

    if (pid3 == 0){
        //child process 3 (uniq)
        dup2(fd[1][0], STDIN_FILENO);
        dup2(fd[2][1], STDOUT_FILENO);
        closePipes(fd, 3);
        execlp("uniq", "uniq", NULL);
    }

    int pid4 = fork();
    if (pid4 == -1) return 7;

    if (pid4 == 0){
        //child process 4 (wc)
        dup2(fd[2][0], STDIN_FILENO);
        closePipes(fd, 3);
        execlp("wc", "wc", "-l", NULL);

    }

    closePipes(fd, 3);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);

    return 0;
}
