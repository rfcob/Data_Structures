#include "listaLigadaEstatica.h"
#include "ListaLigadaEstatica.c"

int main() {
    LISTA l;
    inicializarLista(&l);

    REGISTRO reg1 = {10};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {30};

    inserirElemListaOrd(&l, reg1);
    inserirElemListaOrd(&l, reg2);
    inserirElemListaOrd(&l, reg3);

    printf("Lista inicial:\n");
    exibirLista(&l);

    printf("Tamanho da lista: %d\n", tamanho(&l));
    printf("Tamanho em bytes da lista: %d\n", tamanhoEmBytes(&l));

    printf("Excluindo o elemento com chave 20...\n");
    excluirElemLista(&l, 20);

    printf("Lista após exclusão:\n");
    exibirLista(&l);

    reinicializarLista(&l);
    printf("Lista após reinicialização:\n");
    exibirLista(&l);

    return 0;
}