#include "matrizes/matriz.h"
#include "funcoes/funcionalidades.h"
#include <stdio.h>
void main(){

    //      Declaração de variaveis
    /*
     *         so    -> Variável para salvar o sistema operacional.
     *        code   -> Variável para seleção das funções na tela principal.
     *      condicao -> Variável onde será salvo o resultado de condicionais.
     * */
    int so, code, condicao;

    //      Sistema operacional é necessário para a função "limpaTela".
    printSistemaOperacional();
    scanf("%d", &so);

    do{
        //      Tela de usuário para selecionar função.
        limpaTela(so);
        printTelaA();
        scanf("%d", &code);

        //      checando se é um código válido.
        condicao = (1>=code && code>0);

        //      Caso seja de fato um código válido.
        if(condicao){
            criacaoDeMatriz(so, code);
        }else{

            //      Caso o "code" seja 0, finaliza a execução.
            condicao = (code!=0);

            //      Caso não seja um código válido.
            if(condicao){
                printf("\nDigite somente códigos válidos\n");
            }
            printf("\n<Pressione enter>\n");
            getchar();
            getchar();
        }

    }while(condicao);
}