#include "funcoes/funcionalidades.h"
#include <stdio.h>
void main(){
    int so, code, condicao;

    //      Sistema operacional é necessário para a função "limpaTela".
    printSistemaOperacional();
    scanf("%d", &so);
    do{
        limpaTela(so);
        printTelaA();
        scanf("%d", &code);
        condicao = (1>=code && code>0);
        if(condicao){
            criacaoDeMatriz(so);
        }else{
            condicao = (code!=0);
            if(condicao){
                printf("\nDigite somente códigos válidos\n");
            }
        }

    }while(condicao);
}