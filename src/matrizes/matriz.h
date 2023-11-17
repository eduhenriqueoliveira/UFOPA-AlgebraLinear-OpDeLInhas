#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz_de_ordem_N{
    int ordem;
    double **termo;
} Matriz;

/*
 *  Código se baseia somente em matrizes quadradas
 *  Funções para realizar as operações que existem de matrizes
 !  Principal função do código: 
 !           Cálculo de matriz inversa usando matriz identidade e operações de linha
 */

double **criarVetor(int ordemDaMatriz); // f

Matriz *criaMatrizQuadrada(int ordemDaMatriz, double **termos); // f

Matriz *criaMatrizIdentidade(int ordemDaMatriz); // f

Matriz *copiarMatriz(Matriz *matriz);

//  Funções de operações de linha
void moveLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB); // f
void multiplicaLinha(Matriz *matriz, double escalar, int idxLinha); // f
void somaLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB, double escalar); // f

Matriz *criarMatrizInversa(Matriz *matriz);

void liberaMatriz(Matriz *matriz); // f

#endif