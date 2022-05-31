#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h> /* perror */

int main(int argc, char * argv[]){
    int n; 
    char c[1024];

    while ((n = read(0, c, sizeof(c))) > 0){
        write(1, c, n); // em vez de usar o 'STDOUT_FILENO' pode-se usar o '1'
    }

    return 0;
}