#ifndef LISTALIGADAESTATICA_H
#define LISTALIGADAESTATICA_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int tamanhoEmBytes(LISTA* l);
int buscaSeq(LISTA* l, TIPOCHAVE ch);
int buscaSeqExc(TIPOCHAVE ch, LISTA* l, int* ant);
int obterNo(LISTA* l);
void devolverNo(LISTA* l, int j);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
void reinicializarLista(LISTA* l);

#endif