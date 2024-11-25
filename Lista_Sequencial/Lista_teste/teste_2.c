#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;  // Defina o tipo da chave conforme necessário

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO *A;
  int nroElem;
  int alocacao;
} LISTA;

// Função para inicializar a lista
void inicializarLista(LISTA *l, int tamanhoInicial) {
  l->A = (REGISTRO*) malloc(tamanhoInicial * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
  l->nroElem = 0;
  l->alocacao = tamanhoInicial;
}

// Função para inserir um elemento na lista
void inserirElemento(LISTA *l, REGISTRO reg) {
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

// Função para liberar a memória da lista
void liberarLista(LISTA *l) {
  free(l->A);
  l->nroElem = 0;
  l->alocacao = 0;
}

// Função para retornar o número de elementos na lista
int tamanho(LISTA *l) {
  return l->nroElem;
}

// Função para retornar o tamanho da lista em bytes
int tamanhoEmBytes(LISTA *l) {
  return l->nroElem * sizeof(REGISTRO);
}

int main() {
  LISTA minhaLista;
  inicializarLista(&minhaLista, 10);  // Inicializa a lista com alocação inicial de 10 elementos

  // Exemplo de inserção de elementos
  for (int i = 0; i < 15; i++) {
    REGISTRO reg;
    reg.chave = i;
    inserirElemento(&minhaLista, reg);
  }

  // Imprime os elementos da lista
  for (int i = 0; i < minhaLista.nroElem; i++) {
    printf("Elemento %d: chave = %d\n", i, minhaLista.A[i].chave);
  }

  // Imprime o número de elementos na lista e o tamanho da lista em bytes
  printf("Numero de elementos na lista: %i.\n", tamanho(&minhaLista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&minhaLista));

  // Libera a memória alocada para a lista
  liberarLista(&minhaLista);

  return 0;
}
