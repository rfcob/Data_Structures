#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"


// Função para inserir um elemento na lista
/*void inserirElemento(LISTA *l, REGISTRO reg) {
  if (l->nroElem >= l->alocacao) {
    l->alocacao *= 2;  // Dobra o tamanho da alocação
    l->A = (REGISTRO*) realloc(l->A, l->alocacao * sizeof(REGISTRO));
    if (l->A == NULL) {
      printf("Erro ao alocar memória\n");
      exit(1);
    }
  }
  l->A[l->nroElem] = reg;
  l->nroElem++;
}

// Função para inicializar a lista
void inicializarLista(LISTA *l, int tamInformado) {
  l->A = (REGISTRO*) malloc(tamInformado * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  l->nroElem = 0;
  l->alocacao = tamInformado;
}*/

void inicializarLista(LISTA *l, int tamanhoInicial) {
  l->alocacao = tamanhoInicial;
  l->nroElem = 0;
  l->A = (REGISTRO*) malloc(l->alocacao * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
}

void redimensionarLista(LISTA *l) {
  l->alocacao *= 2;  // Dobra o tamanho da alocação
  l->A = (REGISTRO*) realloc(l->A, l->alocacao * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
}



int main(){

    int tamListUser, tamAtual = MAX;

    LISTA lista;
    REGISTRO reg;
    
    inicializarLista(&lista);

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamListUser);
    
  //  lista = resize_array(lista, tamListUser, tamAtual);
       
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
