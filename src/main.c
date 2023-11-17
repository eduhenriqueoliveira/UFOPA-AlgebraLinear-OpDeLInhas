#include <stdio.h>

#define N 3

void imprimirMatriz(double matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatrizInversa(double matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(double matriz[N][N]) {
    int i, j, k;
    double pivo;

    // Fase de eliminação
    for (i = 0; i < N; i++) {
        pivo = matriz[i][i];

        // Normalizar a linha atual
        for (j = 0; j < N; j++) {
            matriz[i][j] /= pivo;
        }

        // Eliminar outras linhas
        for (k = 0; k < N; k++) {
            if (k != i) {
                pivo = matriz[k][i];
                for (j = 0; j < N; j++) {
                    matriz[k][j] -= pivo * matriz[i][j];
                }
            }
        }
    }
}

int main() {
    double matriz[N][N] = {
        {1, 2, 3},
        {2, 5, 3},
        {1, 0, 0}
    };

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    gaussJordan(matriz);

    printf("Matriz inversa:\n");
    imprimirMatrizInversa(matriz + 0*N);

    return 0;
}
