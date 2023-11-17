#include <stdio.h>
#include <stdlib.h>
#include "funcionalidades.h"

//      Função definida para limpar a tela do terminal.
void limpaTela(int so){

    //      Checa o sistema operacional a partir da entrada do usuário.
    if(so==1) {
        system("cls");
    }else{
        system("clear");
    }
}

//      Função definida para imprimir uma matriz.
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

//      Função definida para imprimir a tela de seleção de sistema operacional.
void printSistemaOperacional(){
    printf("\nInforme o sistema operacional: \n");
    printf("(1) -> Windows \n");
    printf("(2) -> Linux \n");
    printf("Código do sistema: ");
}

//      Função definida para imprimir tela principal;
void printTelaA(){
    printf("\nInforme a ação desejada: \n");
    printf("(0) -> Finalizar execução\n");
    printf("(1) -> Cálcular matriz inversa\n");
    printf("(2) -> Cálcular determinante\n");
    printf("Digite aqui a operação: ");
}

//      Função definida para o processo de criação de matriz e do cálculo desejado.
void criacaoDeMatriz(int so){

    limpaTela(so);

    int ordem;
    double inpt;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    Matriz *matriz = criaMatrizNula(ordem);

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            limpaTela(so);
            printDeMatriz(matriz);
            printf("\nDigite o valor do termo A%d%d: ", i+1, j+1);
            scanf("%lf", &inpt);
            matriz->termo[i][j] = inpt;

        }
    }

    limpaTela(so);

    printf("\nMatriz original: \n");
    printDeMatriz(matriz);

    double det = calcularDeterminante(matriz);
    printf("\nDeterminante: %.3lf", det);

    if(det!=0){
        Matriz *matrizInversa = criarMatrizInversa(matriz);
        printf("\nMatriz Inversa: \n");
        printDeMatriz(matrizInversa);
        liberaMatriz(matrizInversa);
    }else{
        printf("\nMatriz não é invertivel\n");
    }

    printf("\n\n<Pressione enter>\n");
    getchar();
    getchar();

    liberaMatriz(matriz);


}