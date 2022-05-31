#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]){
    
    execl("/Users/ruigoncalves/Desktop/SO/TPs/guiao3/hello",
    "/Users/ruigoncalves/Desktop/SO/TPs/guiao3/hello",
    NULL);
    
    printf("ERRO: %s\n", strerror(errno));
    return 1;
}