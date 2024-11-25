#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"


LISTA resize_array(LISTA lista, int tamListUser, int tamAtual) {
    if (tamListUser >= tamAtual) {
        REGISTRO *temp = (REGISTRO *) realloc(lista.A, ((tamAtual * 2) * sizeof(REGISTRO)));
        if (temp == NULL) {
            lista.A = NULL; // Indicador de erro
            return lista;
        }
        lista.A = temp;
        lista.alocacao = tamAtual * 2;
    }
    lista.alocacao=MAX;
    return lista; // Indicador de sucesso
}

int inicializaLista(LISTA *lista, int capacidadeInicial) {
    lista->A = (REGISTRO *) malloc(capacidadeInicial * sizeof(REGISTRO));
    if (lista->A == NULL) {
        return ERRO; // Indicador de erro
    }
    lista->nroElem = 0;
    lista->alocacao = capacidadeInicial;
    return 0; // Indicador de sucesso
}


int main(){

    int tamListUser, tamAtual = MAX;

    LISTA lista;
    REGISTRO reg;
    
    //lista.A = (REGISTRO *) malloc(tamAtual * sizeof(REGISTRO)); //inicializando a Lista dinamicamente.
    //if (lista.A == NULL) { 
    //    printf("Erro ao alocar memória inicial\n"); 
    //    return ERRO;
   // }

   // Inicializar a lista com a capacidade inicial
    if (inicializaLista(&lista, tamAtual) == ERRO) {
        printf("Erro ao alocar memória inicial\n");
        return ERRO;
    }


    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamListUser);
    
    lista = resize_array(lista, tamListUser, tamAtual);
   
    
    for(int i=0; i<tamListUser;i++){
        printf("Digite o valor: ", i);
        scanf("%d", &reg.chave);
        inserirElemListaOrd(&lista, reg);
    }

    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
 //   printf("Tamanho da lista (em bytes): %i.\n", ((sizeof(LISTA) -8)- (tamListUser*4))); //Calculando o tamanho restante da lista supondo o alinhamento de 8bytes para o processador.


    free(lista.A);
    return 0;
}
