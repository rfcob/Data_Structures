#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

// Função para inicializar a lista
LISTA* inicializarLista(int capacidade_inicial) {
    LISTA* lista = (LISTA*)malloc(capacidade_inicial * sizeof(LISTA));
    if (lista == NULL) {
        printf("Erro ao alocar memória inicial.\n");
        return NULL;
    }
    return lista;
}

// Função para realocar a lista
LISTA* resize_array(LISTA* lista, int tamanho_lista, int* capacidade_atual) {
    printf("Realocando... Tamanho atual da lista: %d, Capacidade: %d\n", tamanho_lista, *capacidade_atual);
    if (tamanho_lista >= *capacidade_atual) {
        int nova_capacidade = (*capacidade_atual) * 2;
        LISTA* temp = (LISTA*)realloc(lista, nova_capacidade * sizeof(LISTA));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            return NULL; // Retorna NULL em caso de falha
        }
        lista = temp;
        *capacidade_atual = nova_capacidade; // Atualiza a capacidade
        printf("Realocação bem-sucedida. Nova capacidade: %d elementos\n", *capacidade_atual);
    } else {
        printf("Não foi necessário realocar.\n");
    }
    return lista;
}

int main() {
    int capacidade_atual = MAX; // Capacidade inicial
    int tamanho_lista = 0;      // Tamanho real da lista
    LISTA* lista = inicializarLista(capacidade_atual);
    if (lista == NULL) {
        return ERRO;
    }

    REGISTRO reg;

    printf("Digite a quantidade de itens a inserir:\n");
    scanf("%d", &tamanho_lista);

    // Realocar lista, se necessário
    printf("Endereço do ponteiro antes da realocação: %p\n", (void*)lista);
    lista = resize_array(lista, tamanho_lista, &capacidade_atual);
    printf("Endereço do ponteiro após a realocação: %p\n", (void*)lista);
   // lista = resize_array(lista, tamanho_lista, &capacidade_atual);
    if (lista == NULL) {
        free(lista);
        return ERRO;
    }

    

    // Inserir elementos na lista
    for (int i = 0; i < tamanho_lista; i++) {
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &reg.chave);
        inserirElemListaOrd(lista, reg);
    }

    // Exibir lista e informações
    exibirLista(lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(lista));
    printf("Capacidade da lista (em bytes): %lu.\n", capacidade_atual * sizeof(LISTA));

    free(lista);
    return 0;
}