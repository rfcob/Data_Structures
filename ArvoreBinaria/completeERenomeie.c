#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct no {
    int chave;
    int contador;           // número de cópias (frequência) dessa chave
    struct no* esq;         // ponteiro para subárvore esquerda
    struct no* dir;         // ponteiro para subárvore direita
} NO, *PONT;

// Protótipos das funções
void inicializar(PONT* raiz);
PONT criarNo(int valor);
PONT inserir(PONT raiz, int valor);
PONT removerUmaOcorrencia(PONT raiz, int valor);
PONT removerTodasOcorrencias(PONT raiz, int valor);
PONT buscar(PONT raiz, int valor);
void exibirInOrder(PONT raiz);
int contarNos(PONT raiz);
int contarTotalElementos(PONT raiz);
int kEsimoMenor(PONT raiz, int k);
void imprimirIntervalo(PONT raiz, int min, int max);
PONT lowestCommonAncestor(PONT raiz, int val1, int val2);


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// 1) Inicializar_______________________________________________________________________________________________________________
//Inicialiar a árvore vazia, totalmente vazia, apenas alocando memória

void inicializar(PONT* raiz) {
    *raiz = NULL;
}


// 2) Criar nó___________________________________________________________________________________________________________________
//Cria o primiero nó com algum valor, a raiz receberá esse valor, caso esteja nula.

PONT criarNo(int valor) {
    PONT novo = (PONT) malloc(sizeof(NO));
    if(novo) {
        novo->chave = valor;
        novo->contador = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// 3) Buscar______________________________________________________________________________________________________________________
//Buscar um elemento caso a raiz não seja nula. Percorre à direita caso o valor seja menor que a raiz e à esquerda do contrário

PONT buscar(PONT raiz, int valor) {

    if(raiz == NULL){
        return NULL;
    }

    //- se valor == raiz->chave => retorna raiz    
    if(valor == raiz->chave){
        return raiz;

     //  - se valor < raiz->chave => buscar à esquerda
    }else if(valor < raiz->chave){
        return buscar(raiz->esq, valor);

    //  - se valor > raiz->chave => buscar à direita
    }else if (valor > raiz->chave){
        return buscar(raiz->dir, valor);
    
    
    }
    
}

// 4) Inserir_____________________________________________________________________________________________________________________
//Inserir ordenado. Caso menor que a raiz a esquerda e maior a direita. A raiz, recursivamente é  o nó

PONT inserir(PONT raiz, int valor) {

    // COMPLETAR

    // Se raiz == NULL => cria nó
    if(raiz == NULL){
        return criarNo(valor);
    }

    // Se valor < raiz->chave => raiz->esq = inserir(raiz->esq, valor)
    if(valor < raiz->chave){
         raiz->esq  = inserir(raiz->esq, valor);

    // Se valor > raiz->chave => raiz->dir = inserir(raiz->dir, valor)
    }else if (valor > raiz->chave){
         raiz->dir = inserir(raiz->dir, valor);
    
    // Se valor == raiz->chave => incrementa raiz->contador
    }else{
        raiz->contador++;
    }
     
    return raiz;
}

// 5) Remover UMA ocorrência________________________________________________________________________________
//Função auxiiar para remoção - busca o pai de um nó


PONT buscaNo(PONT raiz, int valor, PONT *pai){
    PONT atual = raiz;

    *pai = NULL;
    while (atual) {
        if(atual->chave == valor) return(atual);
        *pai = atual;
        if(valor < atual->chave){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    return(NULL);
}

//Remoção

PONT removerUmaOcorrencia(PONT raiz, int chave) {
    if (raiz == NULL) return NULL; 

    if (chave < raiz->chave) {
        raiz->esq = removerUmaOcorrencia(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        raiz->dir = removerUmaOcorrencia(raiz->dir, chave);
    } else { 
        //Se o valor é duplicado decrementa o contador
        if (raiz->contador > 1) { 
            raiz->contador--; 
        } else { 
            // se não a duplicação, removemos o nó
            //1 filho a direita
            if (raiz->esq == NULL) { 
                PONT temp = raiz->dir;
                free(raiz);
                return temp;
            //1 filho a esquerda
            } else if (raiz->dir == NULL) {
                PONT temp = raiz->esq;
                free(raiz);
                return temp;
            } else {
                // 2 filhos: 
                PONT temp = raiz->dir;
                while (temp->esq != NULL) {
                    temp = temp->esq;
                }
                raiz->chave = temp->chave;
                raiz->contador = temp->contador;

                raiz->dir = removerUmaOcorrencia(raiz->dir, temp->chave);
            }
        }
    }
    return raiz;
}


//6) Remover todos___________________________________________________________________________________________
// Remover é uma N- chamada da função anterior


PONT removerTodasOcorrencias(PONT raiz, int valor) {
    while (buscar(raiz, valor) != NULL) {
        raiz = removerUmaOcorrencia(raiz, valor);
    }
    return raiz;
}


//7) Exibir InOrder__________________________________________________________________________________________

void exibirInOrder(PONT raiz) {

    if (raiz == NULL) return;

    exibirInOrder(raiz->esq);
    
    for(int i=0;  i < raiz->contador; i++){
        printf("%i ",raiz->chave);
    }
    exibirInOrder(raiz->dir);

}


// 8) Contar nós distintos__________________________________________________________________________________

int contarNos(PONT raiz) {

    //se raiz == null => 0
    if(raiz==NULL){
        return 0;
    }else{
    // Senao => 1 + contarNos(esq) + contarNos(dir)
      return  contarNos(raiz->esq) + 1 + contarNos(raiz->dir);
    }
    
}

//9) Contar total de elementos (somando contadores)________________________________________________________

int contarTotalElementos(PONT raiz) {

    //se raiz == null => 0
    if(raiz==NULL){
        return 0;
    }else{
    // soma = raiz->contador + subárvores
      return  contarNos(raiz->esq) + 1 + contarNos(raiz->dir) + raiz->contador;
    }
}

//10) Os K menores elementos ______________________________________________________________________________

int kEsimoMenor(PONT raiz, int k) {

    if (raiz == NULL) return -1; 

    int numEsquerda;
    if (raiz->esq != NULL) {
        numEsquerda = raiz->esq->contador;
    } else {
        numEsquerda = 0;
    }

    //  k-ésimo menor  - esquerda
    if (k <= numEsquerda) {
        return kEsimoMenor(raiz->esq, k);
    }
    //k-esimo é o no
    else if (k > numEsquerda && k <= numEsquerda + raiz->contador) {
        return raiz->chave;
    }
    //k-esimo na direita
    else{
        return kEsimoMenor(raiz->dir, k - numEsquerda - raiz->contador);
    }
}


//11) Imprimir Intervalo [min, max]______________________________________________________________________

void imprimirIntervalo(PONT raiz, int min, int max) {
    if (raiz == NULL) return; // Se a árvore está vazia, não faz nada

    // navegando esquerda
    if (min < raiz->chave) {
        imprimirIntervalo(raiz->esq, min, max);
    }


    // explorando subárvore direita
    if (max > raiz->chave) {
        imprimirIntervalo(raiz->dir, min, max);
    }


    // dentro do intervalo
    if (raiz->chave >= min && raiz->chave <= max) {
        printf("%i ", raiz->chave);
    }


}

//12) Encontrar o menor ancestral em comum________________________________________________________________

PONT lowestCommonAncestor(PONT raiz, int val1, int val2) {
    if (raiz == NULL) return NULL;

    // Se ambos menores que - LCA está na subárvore esquerda
    if (val1 < raiz->chave && val2 < raiz->chave) {
        return lowestCommonAncestor(raiz->esq, val1, val2);
    }

    // alores são maiores  -  o LCA  direita
    if (val1 > raiz->chave && val2 > raiz->chave) {
        return lowestCommonAncestor(raiz->dir, val1, val2);
    }

    return raiz; //se o LCA é a raiz (a proprio nó a prória raiz->chave)
}





//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// main() para testes com expectativas de resultado


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



