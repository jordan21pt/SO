#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>


ssize_t readln(int fd, char *line, size_t size){
    int n, nb = 0;
    while(nb < size && (n = read(fd, line + nb, 1)) > 0 && line[nb] != '\n') 
        nb++;

    if (n == -1) return -1;

    return nb > 0 && line[nb] == '\n' ? nb + 1 : nb;

}

ssize_t readln(int fd, char *line, size_t size){
    
}

int main(){
    char buffer[3];
    printf("%ld\n", readln(0, buffer, sizeof(buffer)));
}