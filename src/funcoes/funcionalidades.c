#include <stdio.h>
#include <stdlib.h>
#include "funcionalidades.h"

void limpaTela(int so){
    if(so==1) {
        system("cls");
    }else{
        system("clear");
    }
}

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

void printSistemaOperacional(){
    printf("\nInforme o sistema operacional: \n");
    printf("(1) -> Windows \n");
    printf("(2) -> Linux \n");
    printf("Código do sistema: ");
}

void printTelaA(){
    printf("\nInforme a ação desejada: \n");
    printf("(0) -> Finalizar execução\n");
    printf("(1) -> Cálcular matriz inversa\n");
    printf("Digite aqui a operação: ");
}


void criacaoDeMatriz(int so){
    limpaTela(so);
    int ordem;
    double inpt;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    Matriz *matriz = criaMatrizNula(ordem);
    Matriz *matrizInversa;

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            limpaTela(so);
            printDeMatriz(matriz);
            printf("\nDigite o valor do termo A%d%d: ", i+1, j+1);
            scanf("%lf", &inpt);
            matriz->termo[i][j] = inpt;

        }
    }

    matrizInversa = criarMatrizInversa(matriz);

    limpaTela(so);
    printf("\nMatriz original: \n");
    printDeMatriz(matriz);

    printf("\nMatriz Inversa: \n");
    printDeMatriz(matrizInversa);

    printf("\n\n<Pressione enter>\n");
    getchar();
    getchar();
    liberaMatriz(matriz);
    liberaMatriz(matrizInversa);

}