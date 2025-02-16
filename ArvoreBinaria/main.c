#include "completeERenomeie.c"

int main() {


    // PONT raiz;                    // ponteiro para a raiz da BST
    // inicializar(&raiz);           // deixa a árvore vazia
    // 
    // As funções a serem implementadas:
    //   - criarNo
    //   - inserir
    //   - removerUmaOcorrencia
    //   - removerTodasOcorrencias
    //   - buscar
    //   - exibirInOrder
    //   - contarNos
    //   - contarTotalElementos
    //   - kEsimoMenor
    //   - imprimirIntervalo
    //   - lowestCommonAncestor

    PONT raiz;
    inicializar(&raiz);


    // 1) Inserção com valores repetidos___________________________________________________________


    //    Esperado que:
    //      - nó 10 tenha contador=2
    //      - nó 5  tenha contador=3
    //      - nó 15 tenha contador=1
    //      - nó 18 tenha contador=1
    //
    // InOrder final esperado (antes de quaisquer remoções):
    //     "5 5 5 10 10 15 18"


    raiz = inserir(raiz, 10); 
    inserir(raiz, 5);
    inserir(raiz, 15);
    inserir(raiz, 10); // repetido => contador(10)++
    inserir(raiz, 5);  // repetido => contador(5)++
    inserir(raiz, 5);  // repetido => contador(5)++
    inserir(raiz, 18);

    printf("\n--- APÓS INSERIR (10,5,15,10,5,5,18) ---\n");
    printf("InOrder esperado: 5 5 5 10 10 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz); 
    printf("\n");


    // 2) Busca por valores_____________________________________________________________________

    PONT node5 = buscar(raiz, 5);
    if(node5) {
        printf("\nBuscar(5): encontrado com contador=%d (esperado=3)\n", node5->contador);
    } else {
        printf("\nBuscar(5): não encontrado (inesperado)\n");
    }

    PONT nodeX = buscar(raiz, 999); // valor não existente
    if(!nodeX) {
        printf("Buscar(999): não encontrado (esperado)\n");
    } else {
        printf("Buscar(999): encontrado??? (inesperado)\n");
    }


    // 3) Remover UMA ocorrência________________________________________________________________

    //    removerUmaOcorrencia(5) => contador(5) deve passar de 3 para 2
    removerUmaOcorrencia(raiz, 5);

    printf("\n--- APÓS removerUmaOcorrencia(5) ---\n");
    printf("Esperado InOrder: 5 5 10 10 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz);
    printf("\n");

    node5 = buscar(raiz, 5);
    if(node5) {
        printf("Agora contador(5)=%d (esperado=2)\n", node5->contador);
    }

    
    // 4) Remover TODAS ocorrências______________________________________________________________

    //    removerTodasOcorrencias(10) => remove nó com chave=10 por completo
    removerTodasOcorrencias(raiz, 10);

    printf("\n--- APÓS removerTodasOcorrencias(10) ---\n");
    printf("Esperado InOrder: 5 5 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz);
    printf("\n");

   
    // 5) Contagem de nós e total de elementos_______________________________________________

    //    Árvores resultante: {5(cont=2), 15(cont=1), 18(cont=1)}
    //      => contarNos=3   (chaves distintas: 5,15,18)
    //      => contarTotalElementos=4   (5,5,15,18)


    int qtdNos = contarNos(raiz);
    int totalElem = contarTotalElementos(raiz);
    printf("\ncontarNos => %d (esperado=3)\n", qtdNos);
    printf("contarTotalElementos => %d (esperado=4)\n", totalElem);

    
    // 6) k-ésimo menor (considerando contadores)____________________________________________


    //    InOrder real: [5,5,15,18]
    //       k=1 => 5
    //       k=2 => 5
    //       k=3 => 15
    //       k=4 => 18
    //       k=5 => -1 (não existe)


    printf("\n--- Teste k-ésimo menor ---\n");
    printf("k=1 => %d (esperado=5)\n", kEsimoMenor(raiz,1));
    printf("k=2 => %d (esperado=5)\n", kEsimoMenor(raiz,2));
    printf("k=3 => %d (esperado=15)\n", kEsimoMenor(raiz,3));
    printf("k=4 => %d (esperado=18)\n", kEsimoMenor(raiz,4));
    printf("k=5 => %d (esperado=-1)\n", kEsimoMenor(raiz,5));

    
    // 7) imprimirIntervalo [6..18]_________________________________________________________


    //    InOrder da árvore: 5,5,15,18
    //    Filtrando [6..18], esperamos: 15 18
    printf("\n--- Teste imprimirIntervalo [6..18] ---\n");
    printf("Esperado: 15 18\nObtido:   ");
    imprimirIntervalo(raiz, 6, 18);
    printf("\n");

    //_______________________________________________________________________________________
    // 8) Testar LCA (lowestCommonAncestor) - não é opcional
    
    //    Vamos inserir mais alguns valores para teste de LCA
    //    Situação final da árvore atual: 
    
            //5(cont=2),15(cont=1),18(cont=1)

    //    Inserir(12), Inserir(16), Inserir(3)
   

    //|||||||||||||||||||||||||||||||||||||||||||
    //    Nova BST (com contadores):
    //       
    //              5 (cont=2)
    //           /     \
    //         3(1)    15(1)                    AJUSTADA
    //                 /   \
    //               12(1)  18(1)
    //                     /
    //                   16(1)
    //||||||||||||||||||||||||||||||||||||||||||||

    inserir(raiz, 12);
    inserir(raiz, 16);
    inserir(raiz, 3);

    printf("\n--- Árvore após inserir(12,16,3) ---\n");
    printf("InOrder esperado: 3 5 5 12 15 16 18\n");
    printf("Obtido:           ");
    exibirInOrder(raiz);
    printf("\n");

    printf("\n---Nova contagem após inserção atual ---");
    int qtdNos2 = contarNos(raiz);
    int totalElem2 = contarTotalElementos(raiz);
    printf("\ncontarNos => %d (esperado=6)\n", qtdNos2);
    printf("contarTotalElementos => %d (esperado=7)\n", totalElem2);
    printf("\n");

    // LCA tests:_________________________________________________________________________________

    PONT nLCA;

    printf(" |||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||       Nova BST (com contadores):        ||\n");
    printf(" ||                                         ||\n");
    printf(" ||              5 (cont=2)                 ||\n");
    printf(" ||           /     \\                       ||\n");
    printf(" ||         3(1)    15(1)                   ||  AJUSTADA\n");
    printf(" ||                 /   \\                   ||\n");
    printf(" ||               12(1)  18(1)              ||\n");
    printf(" ||                      /                  ||\n");
    printf(" ||                     16(1)               ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||\n");

    nLCA = lowestCommonAncestor(raiz, 3, 5);
    if(nLCA) {
        printf("\nLCA(3,5) => chave=%d (esperado=5)\n", nLCA->chave);
    }

    nLCA = lowestCommonAncestor(raiz, 3, 12);
    if(nLCA) {
        printf("LCA(3,12) => chave=%d (esperado=5)\n", nLCA->chave);
    }

    nLCA = lowestCommonAncestor(raiz, 16, 18);
    if(nLCA) {
        printf("LCA(16,18) => chave=%d (esperado=18)\n", nLCA->chave);
    }

    nLCA = lowestCommonAncestor(raiz, 12, 18);
    if(nLCA) {
        printf("LCA(12,18) => chave=%d (esperado=15)\n", nLCA->chave);
    }

    // Por fim, buscar um LCA com valor inexistente
    nLCA = lowestCommonAncestor(raiz, 100, 3);
    if(!nLCA) {
        printf("LCA(100,3) => NULL (esperado=chave nao existe)\n");
    }

    printf("\n--- FIM DOS TESTES ---\n");

    return 0;
}
