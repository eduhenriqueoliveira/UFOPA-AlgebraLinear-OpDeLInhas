#ifndef MATRIZ_H
#define MATRIZ_H

//      Definição da struct da matriz
/*
 *       ordem  -> Dado para guardar a ordem da matriz
 *      **termo -> Vetor de duas dimensões para guardar os termos
 * */
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

double **criarVetor(int ordemDaMatriz);

Matriz *criaMatrizQuadrada(int ordemDaMatriz, double **termos);

Matriz *criaMatrizNula(int ordemDaMatriz);

Matriz *criaMatrizIdentidade(int ordemDaMatriz);

Matriz *copiarMatriz(Matriz *matriz);

//  Funções de operações de linha
void moveLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB);
void multiplicaLinha(Matriz *matriz, double escalar, int idxLinha);
void somaLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB, double escalar);

Matriz *criarMatrizInversa(Matriz *matriz);

void liberaMatriz(Matriz *matriz);

#endif