#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// L1 e L2 são listas circulares simplesmente encadeadas e sem nós cabeça
#define TAM 10

struct NO {
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

// Função para buscar elemento na lista circular
int buscaElemento(lista *L, lista **pre, int dado) {
    if (L == NULL) return 0; // Lista vazia, não encontrou o elemento
    lista *aux = L;
    lista *preL = NULL; // Ponteiro para o anterior

    do {
        if (aux->dado == dado) return 1; // Elemento encontrado
        preL = aux;
        aux = aux->prox;
    } while (aux != L);
    
    *pre = preL;
    return 0; // Não encontrou o elemento
}

// Função para inserir elemento na lista circular
void insereElemento(lista **L, int dado) {
    lista *elemento, *aux, *pre;
    
    // Verifica se o elemento já existe na lista
    if (!buscaElemento((*L), &pre, dado)) {
        elemento = (lista*)malloc(sizeof(lista));
        elemento->dado = dado;
        
        if (*L == NULL) { // Caso a lista esteja vazia
            *L = elemento;
            elemento->prox = elemento; // Aponta para si mesmo
        } else {
            aux = *L;
            while (aux->prox != *L) { 
                aux = aux->prox; // Encontra o último nó
            }
            elemento->prox = *L; // Novo elemento aponta para o primeiro nó
            aux->prox = elemento; // Último nó aponta para o novo elemento
        }
    }
}

// Função para imprimir a lista circular
void printa(lista *L) {
    if (L == NULL) return; // Lista vazia, não imprime nada
    
    lista *aux = L;
    do {
        printf("%d ", aux->dado);
        aux = aux->prox;
    } while (aux != L); // Continua até voltar ao primeiro nó
    
    printf("\n");
}

int main(void) {
    lista *L1 = NULL;
    lista *L2 = NULL;
    int i, num;

    srand(time(NULL));

    for (i = 0; i < TAM; i++) {
        num = rand() % 100;
        insereElemento(&L1, num);
        
        num = rand() % 100;
        insereElemento(&L2, num);
    }

    printf("Lista L1: ");
    printa(L1);
    
    printf("Lista L2: ");
    printa(L2);

    return 0;
}
