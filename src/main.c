#include <stdio.h>
#include "matrizes/matriz.h"

void printDeMatriz(Matriz *matriz){
    int ordem = matriz->ordem;
    for(int i=0;i<ordem;i++){
        for(int j=0; j<ordem;j++){
            printf("%.2lf ", matriz->termo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main(){
    double vetorV[2][2] = {
        {3, -1},
        {2, -1}
    };
    double **vetor = criarVetor(2);
    
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            vetor[i][j]=vetorV[i][j];
        }
    }

    Matriz *matriz = criaMatrizQuadrada(2, vetor);
    Matriz *matrizInversa = criarMatrizInversa(matriz);
    printf("\n");
    printDeMatriz(matriz);
    printf("\n");
    printf("\n");
    printDeMatriz(matrizInversa);
    printf("\n");

    liberaMatriz(matriz);
    liberaMatriz(matrizInversa);

}