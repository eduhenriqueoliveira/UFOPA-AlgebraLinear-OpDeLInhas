#include "matriz.h"
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

//      Função para copiar uma matriz
Matriz *copiarMatriz(Matriz *matriz){
    
    //      Copia os termos
    double **termosCopiados = criarVetor(matriz->ordem);
    for(int i=0; i<matriz->ordem; i++){
        for(int j=0; j<matriz->ordem; j++){
            termosCopiados[i][j] = matriz->termo[i][j];
        }
    }

    return criaMatrizQuadrada(matriz->ordem, termosCopiados);
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
    
    /*
        Dividido em x partes
            1- Criar a matriz identidade
    
    */

    Matriz *matrizTemporaria = copiarMatriz(matriz);
    Matriz *matrizIdentidade = criaMatrizIdentidade(matriz->ordem);
    
    double pivo, temp;
    int i, j, k;

    // ! LEMBRETE: AO USAR OPERAÇÃO DE LINHA, USA-SE NA MATRIZTEMPORARIA E NA MATRIZ IDENTIDADE UMA DEPOIS DA OUTRA

    //      Normalização dos pivôs e de suas linhas
    for(i=0; i<matriz->ordem; i++){
        
        //      Seleciona o pivô da linha
        pivo = matrizTemporaria->termo[i][i];

        //      Verifica se o pivô é 0, 
        //      se for: procura por outra linha na coluna com um valor diferente de 0 e depois soma-se essas linhas
        if(pivo==0){
            temp = pivo;
            for(j=0; j<matriz->ordem && temp==0; j++){
                temp = matrizTemporaria->termo[j][i];
            }
            
            //      Verifica se há realmente outro valor não-nulo naquela coluna
            if(temp!=0){
                somaLinha(matrizTemporaria, i, j, 1);
                somaLinha(matrizIdentidade, i, j, 1);
            }
            //      Se for uma coluna com valores nulos, ele simplesmente passa para a próxima iteração
            else{
                continue;
            }

        }

        //      Divide a linha inteira pelo pivô
        multiplicaLinha(matrizTemporaria, 1/pivo, i);
        multiplicaLinha(matrizIdentidade, 1/pivo, i);

        //      Eliminação das linhas inferiores e superiores
        for(j=0; j<matriz->ordem; j++){
            if(j!=i){
                somaLinha(matrizTemporaria,j, i, matrizTemporaria->termo[j][i]);
                somaLinha(matrizIdentidade,j, i, matrizIdentidade->termo[j][i]);
            }
        }

    }

    liberaMatriz(matrizTemporaria);
    return matrizIdentidade;
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

