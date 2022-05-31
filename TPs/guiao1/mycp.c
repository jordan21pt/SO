#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>

int main(int argc, char * argv[]){
    int ofd, dfd, n;
    char c[1024];

    ofd = open(argv[1], O_RDONLY);
    if (ofd == -1){
        perror(argv[1]);
        return 1;
    }
    
    dfd = open(argv[2], O_CREAT| O_TRUNC| O_WRONLY, 0666);
    if (dfd == -1){
        perror(argv[2]);
        return 1;
    }

    while ((n = read (ofd, c, sizeof(c))) > 0){
        write(dfd, c, n);
    }

    int close(int ofd);
    int close(int dfd);

    return 0;
}