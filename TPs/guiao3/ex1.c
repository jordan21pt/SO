#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>

int main(int argc, char * argv[]){
    
    execlp("ls", "ls", "-l", NULL);
    printf("ola");
    return 1; // se esta linha correr, da erro
}

