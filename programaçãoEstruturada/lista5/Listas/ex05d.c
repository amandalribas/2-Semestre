#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//L1 e L2 são simplesmente encadeadas, não circulares e com nós cabeça;
#define TAM 10

struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

lista *concatena(lista *L1, lista * L2){
    lista *aux;
    if (L1 == NULL)
        return L2;
    aux = L1;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = L2->prox;
    return L1;
}

int buscaElemento(lista *L, lista **pre, int dado){
    lista *preL,*aux;
    aux = L->prox;
    preL = L;
    while ((aux!=NULL)&&(aux->dado < dado)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado==dado))
        return 1;
    return 0;
}

void insereElemento(lista **L, int dado){
    lista *aux,*pre;
    if (!(buscaElemento((*L),&pre,dado))){
        aux = (lista*)malloc(sizeof(lista));
        aux->dado = dado;
        aux->prox = pre->prox;
        pre->prox = aux; 
    }
}

void print(lista *L){
    lista *aux;
    aux = L->prox;
    while (aux!=NULL){
        printf(" %d \t", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    lista *L1, *L2, *L;
    int i, num;
    L1 = (lista*)malloc(sizeof(lista));
    L2 = (lista*)malloc(sizeof(lista));
    L = (lista*)malloc(sizeof(lista));
    L1->prox = NULL;
    L2->prox = NULL;
    L->prox = NULL;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        num = rand()%100;
        insereElemento(&L1,num);
        num = rand()%100;
        insereElemento(&L2,num);
    }
    printf("L1: ");
    print(L1);
    printf("L2: ");
    print(L2);
    L = concatena(L1,L2);
    printf("Concatenada: ");
    print(L);
    return 0;
}