#include "funcoes/funcionalidades.h"
#include "matrizes/matriz.h"
#include <stdio.h>
void main(){
    int n = 2;
    double vetorV[2][2] = {
        {7, 4},
        {9, -5}
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