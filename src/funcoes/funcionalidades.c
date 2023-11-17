#include <stdio.h>
#include "funcionalidades.h"


void printDeMatriz(Matriz *matriz){
    int ordem = matriz->ordem;

    printf("\n---");
    for(int i=0;i<(ordem*7)-4;i++) printf(" ");
    printf("---\n");

    for(int i=0;i<ordem;i++){
        printf("|");
        for(int j=0; j<ordem;j++){
            printf("%7.2lf", matriz->termo[i][j]);
        }
        printf("|");
        if(i!=ordem-1) printf("\n");
    }
    printf("\n");

    printf("---");
    for(int i=0;i<(ordem*7)-4;i++) printf(" ");
    printf("---\n");
}

void criacaoDeMatriz(){
    return;
}