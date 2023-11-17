#include <stdio.h>
#include <math.h>
#include "matrizes/matriz.h"

void printDeMatriz(Matriz *matriz){
    int ordem = matriz->ordem;
    for(int i=0;i<ordem;i++){
        for(int j=0; j<ordem;j++){
            printf("%2lf ", matriz->termo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main(){
    int n = 3;
    double vetorV[3][3] = {
        {1, 2, 3},
        {2, 0, 3},
        {1, 5, 8}
    };
    double **vetor = criarVetor(n);
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            vetor[i][j]=vetorV[i][j];
        }
    }

    Matriz *matriz = criaMatrizQuadrada(n, vetor);
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