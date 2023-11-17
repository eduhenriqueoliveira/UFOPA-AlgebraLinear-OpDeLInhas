#include <matriz.h>
#include <stdlib.h>

//      Função para alocar dinamicamente o vetor dos termos da matriz.
double **criarVetor(int ordemDaMatriz){

    //      Declara a variavel "termos", e aloca as linhas da mesma.
    double **termos = (double**) malloc(sizeof(double*)*ordemDaMatriz);

    //      Aloca as colunas da matriz.
    for(int i=0; i<ordemDaMatriz; i++){
        termos[i] = (double*) malloc(sizeof(double)*ordemDaMatriz);
    }

    return termos;
}

//      Função definida para a criação de uma matriz quadrada.
Matriz *criaMatrizQuadrada(int ordemDaMatriz, double **termos){

    //      Aloca dinamicamente a matriz.
    Matriz *matrizCriada = (Matriz*) malloc(sizeof(Matriz));
    
    //      Passa os valores de entrada para ela.
    matrizCriada->ordem=ordemDaMatriz;
    matrizCriada->termo=termos;

    return matrizCriada;
}

//      Função definida para a criação de uma matriz identidade.
Matriz *criaMatrizIdentidade(int ordemDaMatriz){

    //      Aloca na memória a variavel dos termos da matriz.
    double **termos = criarVetor(ordemDaMatriz);

    //      Preenche os termos.
    for(int i=0; i<ordemDaMatriz; i++){
        for(int j=0; j<ordemDaMatriz; j++){
            termos[i][j] = (i==j)? 1:0;
        }
    }

    //      Retorna usando a função de criar uma matriz quadrada.
    return criaMatrizQuadrada(ordemDaMatriz, termos);

}

//      Função para substituir entre si os valores de duas linhas.
void moveLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB){
    
    /*  
        Efetua substituição
        Lógica padrão de substituição
     !      temporario = a
     !               a = b
     !               b = temporario
     */
    double *vetorTemporario = matriz->termo[idxLinhaA];
    matriz->termo[idxLinhaA] = matriz->termo[idxLinhaB];
    matriz->termo[idxLinhaB] = vetorTemporario;
}

//      Função para realizar a operação de linha de multiplicar uma linha por um escalar.
void multiplicaLinha(Matriz *matriz, double escalar, int idxLinha){
    
    //      Laço de repetição para multiplicar uma linha inteira da matriz.
    for(int j=0; j<matriz->ordem; j++){
        matriz->termo[idxLinha][j] *= escalar;
    }

}

//      Função para realizar a operação de linha de somar uma linha "B" com uma linha "A".
//      A linha "A" será onde ficará o resultado da soma.
void somaLinha(Matriz *matriz, int idxLinhaA, int idxLinhaB, double escalar){

    //      Laço de repetição para a soma
    for(int j=0; j<matriz->ordem; j++){
        matriz->termo[idxLinhaA][j] += (matriz->termo[idxLinhaB][j]*escalar);
    }

}

// todo: Função para calcular a matriz inversa de uma dada matriz, utilizando operações de linha
Matriz *criarMatrizInversa(Matriz *matriz){
    return NULL;
}

//      Função para liberar os valores alocados dinamicamente na memória
void liberaMatriz(Matriz *matriz){
    
    //      Liberação do vetor de termos
    for(int i=0; i<matriz->ordem; i++){
        free(matriz->termo[i]);
    }
    free(matriz->termo);

    //      Liberação da struct matriz
    free(matriz);
}

