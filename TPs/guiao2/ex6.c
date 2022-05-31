#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int linhas = 6;
    int colunas = 10 * linhas;

    int v[linhas][colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            v[i][j] = 10 + rand() % 90;
            printf("%d ", v[i][j]);
        }
        putchar('\n');
    }

    int escolha = 88;
    printf("Escolha = %d\n", escolha);

    pid_t pid;
    int status;

    for (int i = 0; i < linhas; i++){
        pid = fork();
        if (pid == 0){
            for (int j = 0; j < colunas; j++){
                if (v[i][j] == escolha){
                    _exit(1);
                }
            }
            _exit(0);
        }
    }


    for(int i = 0; i < linhas; i++){
        pid = wait(&status);

        if((WEXITSTATUS(status)) == 1) {
            //char str[256];
            //snprintf(str, sizeof(str), "Encontrado na linha %d\n", i);
            //write(1, str, strlen(str));
            printf("Encontrado na linha %d.\n", i+1);
        }
    
    }


    return 0;
}