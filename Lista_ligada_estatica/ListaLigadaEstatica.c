#include "listaLigadaEstatica.h"

void inicializarLista(LISTA* l) {
    l->inicio = INVALIDO;
    l->dispo = 0;
    for (int i = 0; i < MAX - 1; i++)
        l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = INVALIDO;
}

void exibirLista(LISTA* l) {
    int i = l->inicio;
    printf("Lista: \" ");
    while (i != INVALIDO) {
        printf("%d ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

int tamanho(LISTA* l) {
    int i = l->inicio;
    int tam = 0;
    while (i != INVALIDO) {
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}

int tamanhoEmBytes(LISTA* l) {
    return sizeof(LISTA);
}

int buscaSeq(LISTA* l, TIPOCHAVE ch) {
    int i = l->inicio;
    while (i != INVALIDO) {
        if (l->A[i].reg.chave == ch)
            return i;
        i = l->A[i].prox;
    }
    return INVALIDO;
}

int buscaSeqExc(TIPOCHAVE ch, LISTA* l, int* ant) {
    *ant = INVALIDO;
    int i = l->inicio;
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
        *ant = i;
        i = l->A[i].prox;
    }
    if ((i != INVALIDO) && (l->A[i].reg.chave == ch))
        return i;
    return INVALIDO;
}

int obterNo(LISTA* l) {
    int resultado = l->dispo;
    if (l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    return resultado;
}

void devolverNo(LISTA* l, int j) {
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    int ant = INVALIDO;
    int i = l->inicio;
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
        ant = i;
        i = l->A[i].prox;
    }
    if (i == INVALIDO || l->A[i].reg.chave != ch)
        return false;
    if (ant == INVALIDO)
        l->inicio = l->A[i].prox;
    else
        l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);
    return true;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    if (l->dispo == INVALIDO)
        return false;
    int ant, i;
    i = buscaSeqExc(reg.chave, l, &ant);
    if (i != INVALIDO)
        return false;
    i = obterNo(l);
    l->A[i].reg = reg;
    if (ant == INVALIDO) {
        l->A[i].prox = l->inicio;
        l->inicio = i;
    } else {
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return true;
}

void reinicializarLista(LISTA* l) {
    inicializarLista(l);
}