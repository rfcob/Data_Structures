#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

int resize_array(LISTA* lista, int tamanho_lista){

    int tl=sizeof(LISTA);

    if(tamanho_lista<= tl/2){
        return tamanho_lista;
    }else{
        lista = (LISTA *) realloc(lista,2* sizeof(LISTA));
    }

}//precisa-se testar quantos elementos tem na lista e quantos cabem ainda. Assim, podemos criar condicionais ou usar um contador que parte do valor da lista. quando 
//chegar a zero, resize a lista 

int main(){

    int tamanho_lista;
    //int *tam=tamanho_lista;
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA)); //inicializando a Lista dinamicamente.
    REGISTRO reg;


    inicializarLista(lista);

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamanho_lista);
    
    resize_array(lista, tamanho_lista);

    for(int i=0; i<tamanho_lista;i++){
                printf("Digite o valor: ", i);
        scanf("%d", &reg.chave);
        inserirElemListaOrd(lista, reg);
    }

    exibirLista(lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(lista));
    printf("Tamanho da lista (em bytes): %i.\n", (sizeof(LISTA) / sizeof(REGISTRO))-2);


    return 0;
}
