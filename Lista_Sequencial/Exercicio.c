#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"


/* int resize_array(LISTA* lista, int tamanho_lista){

    if(tamanho_lista == MAX) {
        LISTA* lista = (LISTA *) realloc(lista,2* sizeof(LISTA));
    }
    return lista;
} */

int resize_array(LISTA** lista, int tamanho_lista) {
    if (tamanho_lista >= MAX) { // Usar operador de igualdade '=='
        LISTA *temp = (LISTA*)realloc(*lista, ((MAX*2) * sizeof(LISTA)));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            return ERRO; // Indicador de erro
        }
        *lista=temp;
    }
    return 0; // Indicador de sucesso
}


int main(){

    int tamanho_lista;
    //int *tam=tamanho_lista;
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA)); //inicializando a Lista dinamicamente.
    REGISTRO reg;


    inicializarLista(lista);

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamanho_lista);
    
    resize_array(&lista, tamanho_lista);

    for(int i=0; i<tamanho_lista;i++){
        printf("Digite o valor: ", i);
        scanf("%d", &reg.chave);
        inserirElemListaOrd(lista, reg);
    }

    exibirLista(lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(lista));
 //   printf("Tamanho da lista (em bytes): %i.\n", ((sizeof(LISTA) -8)- (tamanho_lista*4))); //Calculando o tamanho restante da lista supondo o alinhamento de 8bytes para o processador.


    free(lista);
    return 0;
}
