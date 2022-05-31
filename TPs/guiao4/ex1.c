#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char * argv[]){

    int x = STDOUT_FILENO;
    printf("x = %d\n", x);

    int entradaFd = open("/etc/passwd", O_RDONLY, 0666); // --> standar input
    int saidaFd = open("saida.txt", O_WRONLY | O_CREAT, 0666); // --> standard output
    int errosFd = open("erros.txt", O_WRONLY | O_CREAT, 0666); // --> error

    dup2(entradaFd, STDIN_FILENO);
    dup2(saidaFd, STDOUT_FILENO);
    dup2(errosFd, STDERR_FILENO);

    printf("out = %d\nx= %d\n", saidaFd, x);

    close(entradaFd);
    close(saidaFd);
    close(errosFd);

    printf("x = %d\nout = %d\n", x, saidaFd);

    write(x, "Terminei!\n", sizeof("Terminei!\n"));

    return 0;
}