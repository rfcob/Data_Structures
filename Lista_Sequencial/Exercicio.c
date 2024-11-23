#include <stdio.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

int resize_array(LISTA* lista);

int main(){

    LISTA lista;
    REGISTRO reg;


    int tamanho_lista=3, i=0;
    inicializarLista(&lista);

    for(i; i<tamanho_lista;i++){
        scanf("%d", &reg.chave);
        inserirElemListaOrd(&lista, reg);
    }

    exibirLista(&lista);


    return 0;
}
