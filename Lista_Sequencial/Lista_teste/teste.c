//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



#include <stdio.h>
#include <stdlib.h>
//#include "ListaOrdenada.h"

typedef int TIPOCHAVE;
#define MAX 10
#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO *A;
  int nroElem;
  int alocacao;
} LISTA;

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


/* Inicialização da lista sequencial (a lista já está criada e é apontada pelo endereço em l) */
void inicializarLista(LISTA* l){
  l->nroElem = 0;
} /* inicializarLista */

/* Exibição da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
  
} /* exibirLista */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */


/* Inserção em lista ordenada usando busca binária permitindo duplicação */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */

int tamanhoEmBytes(LISTA* l) {
   return sizeof(LISTA);
} /* tamanhoEmBytes */


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


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



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
