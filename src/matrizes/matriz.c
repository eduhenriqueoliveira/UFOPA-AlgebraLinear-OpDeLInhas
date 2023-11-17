#include "matriz.h"
#include <stdlib.h>
#include <math.h>

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

//      Função definida para a criação de uma matriz nula (com todos os termos 0).
Matriz *criaMatrizNula(int ordemDaMatriz){

    //      Aloca na memória a variavel dos termos da matriz.
    double **termos = criarVetor(ordemDaMatriz);

    //      Preenche os termos.
    for(int i=0; i<ordemDaMatriz; i++){
        for(int j=0; j<ordemDaMatriz; j++){
            termos[i][j] = 0;
        }
    }

    //      Retorna usando a função de criar uma matriz quadrada.
    return criaMatrizQuadrada(ordemDaMatriz, termos);

}

//      Função definida para a criação de uma matriz identidade.
Matriz *criaMatrizIdentidade(int ordemDaMatriz){

    //      Cria uma matriz nula.
    Matriz *matrizIdentidade = criaMatrizNula(ordemDaMatriz);

    //      Coloca os valores 1 na diagonal principal.
    for(int i=0; i<ordemDaMatriz; i++){
        matrizIdentidade->termo[i][i] = 1;
    }

    return matrizIdentidade;
    
}

//      Função para copiar uma matriz.
Matriz *copiarMatriz(Matriz *matriz){
    
    //      Copia os termos.
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
     *       Efetua substituição.
     *   Lógica padrão de substituição:
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

    //      Laço de repetição para a soma.
    for(int j=0; j<matriz->ordem; j++){
        matriz->termo[idxLinhaA][j] += (matriz->termo[idxLinhaB][j]*escalar);
    }

}

//      Função para calcular o determinante de uma dada matriz.
//          Feito de forma recursiva pelo método de coeficiente expandido, até ter matrizes menores de ordem 2
double determinante(Matriz *matrizCopiada){

    //      Declarando a variavel do determinante.
    double det = 0.0;

    //      Checa se a matriz é de ordem 2, e faz a conta de seu determinante
    //!     Importante: Aqui é o ponto onde a função sairá da recursividade
    if(matrizCopiada->ordem==2) {
        det += matrizCopiada->termo[0][0] * matrizCopiada->termo[1][1];
        det -= matrizCopiada->termo[1][0] * matrizCopiada->termo[0][1];
    }else{

        //      Caso a matriz informada seja maior que 2, usa-se o método
        int m, n;
        double cof, **termos;

        //      A linha selecionada para o método SEMPRE será a primeira.
        //      A partir dela cria-se matrizes menores, recursivamente encontrando seus determinantes.
        for(int k=0; k<matrizCopiada->ordem; k++) {

            /*
             *      m -> Linhas da submatriz
             *      n -> Coluna da submatriz
             * */
            m=1;
            n=0;

            //      Cria-se um subvetor com ordem-1
            termos = criarVetor((matrizCopiada->ordem)-1);

            //      Copia os termos corretos no subvetor
            for(int i=0; i<(matrizCopiada->ordem)-1; i++){
                for(int j=0; j<(matrizCopiada->ordem)-1; j++){
                    if(n==k) n++;
                    termos[i][j] = matrizCopiada->termo[m][n];
                    n++;
                }
                m++;
                n=0;
            }

            //      Cria uma outra matriz, chamada "auxMatriz" com os novos valores
            Matriz *auxMatriz = criaMatrizQuadrada(matrizCopiada->ordem-1, termos);

            //      Calcula o cofator
            //      O cálculo do determinante da "auxMatriz" é feito de forma recursiva, até chegar em uma matriz de ordem 2
            cof = determinante(auxMatriz);
            cof *= pow(-1, 2+k);

            //      Soma-se o determinante com o produto entre o termo e o cofator
            det += cof*matrizCopiada->termo[0][k];

        }
    }

    //      Libera na memória a matriz
    //      Não há a necessidade de liberar o "auxMatriz", visto que ele mesmo se libera na ultima iteração
    liberaMatriz(matrizCopiada);
    return det;
}

double calcularDeterminante(Matriz *matriz){
    Matriz *matrizCopiada = copiarMatriz(matriz);
    return determinante(matrizCopiada);
}

//      Função para calcular a matriz inversa de uma dada matriz, utilizando operações de linha.
Matriz *criarMatrizInversa(Matriz *matriz){

    //      Checar se o determinante da matriz é igual a 0, se for, retorna null pois a matriz é invertivel
    if(calcularDeterminante(matriz)==0)
        return NULL;

    /*
     *  Pela fórmular:
     *      [A|I]
     *        |
     *        v
     *      [I|A⁻¹]
     *  Código cálcula esse processo por operações de linha.
     */

    Matriz *matrizTemporaria = copiarMatriz(matriz);
    Matriz *matrizIdentidade = criaMatrizIdentidade(matriz->ordem);
    
    double pivo, temp;
    int i, j;

    //      Normalização dos pivôs e de suas linhas.
    for(i=0; i<matriz->ordem; i++){
        
        //      Seleciona o pivô da linha.
        pivo = matrizTemporaria->termo[i][i];

        //      Verifica se o pivô é 0, 
        //      se for: procura por outra linha na coluna com um valor diferente de 0 e depois soma-se essas linhas.
        if(pivo==0){
            temp = pivo;
            for(j=0; j<matriz->ordem && temp==0; j++){
                temp = matrizTemporaria->termo[j][i];
            }
            
            //      Verifica se há realmente outro valor não nulo naquela coluna.
            if(temp!=0){
                somaLinha(matrizTemporaria, i, j, 1);
                somaLinha(matrizIdentidade, i, j, 1);
            }
            //      Se for uma coluna com valores nulos, ele simplesmente passa para a próxima iteração.
            else{
                continue;
            }

        }

        //      Divide a linha inteira pelo pivô.
        multiplicaLinha(matrizTemporaria, 1/pivo, i);
        multiplicaLinha(matrizIdentidade, 1/pivo, i);

        //      Eliminação das linhas inferiores e superiores.
        for(j=0; j<matriz->ordem; j++){
            if(j!=i){
                pivo=-matrizTemporaria->termo[j][i];
                somaLinha(matrizTemporaria,j, i, pivo);
                somaLinha(matrizIdentidade,j, i, pivo);
            }
        }

    }

    liberaMatriz(matrizTemporaria);

    //      Retorna o que inicialmente era a matriz identidade, pois ela "se torna" a matriz inversa.
    return matrizIdentidade;
}

//      Função para liberar os valores alocados dinamicamente na memória.
void liberaMatriz(Matriz *matriz){
    
    //      Liberação do vetor de termos.
    for(int i=0; i<matriz->ordem; i++){
        free(matriz->termo[i]);
    }
    free(matriz->termo);

    //      Liberação da struct matriz.
    free(matriz);
}

