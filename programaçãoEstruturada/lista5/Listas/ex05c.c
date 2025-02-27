#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//L1 e L2 são simplesmente encadeadas, circulares e com nós cabeça;

#define TAM 6
struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

lista *concatena(lista *L1, lista *L2){
    lista *aux,*aux2;
    if (L1->prox == L1)
        return L2;
    aux = L1;
    while (aux->prox!=L1){
        aux = aux->prox;
    }
    aux->prox = L2->prox;
    aux2 = L2;
    while (aux2->prox!=L2)
        aux2 = aux2->prox;
    aux2->prox = L1;
    return L1;
}

int busca(lista *L, lista **pre, int num){
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux!=L)&&(aux->dado<num)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado == num))
        return 1;
    return 0;
}

void insere(lista **L, int elemento){
    lista *aux, *pre;
    if (!(busca((*L),&pre,elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->dado = elemento;
        aux->prox = pre->prox;
        pre->prox = aux;
    }
}

void printa(lista *L){
    lista *aux;
    aux = L->prox;
    while (aux!=L){
        printf(" %d \t", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    lista *L1, *L2, *L;
    int i, num;
    L1 = (lista*)malloc(sizeof(lista));
    L1->prox = L1;
    L2 = (lista*)malloc(sizeof(lista));
    L2->prox = L2;
    L = (lista*)malloc(sizeof(lista));
    L->prox = L;

    srand(time(NULL));
    for (i=0;i<TAM;i++){
        num = rand()%100;
        insere(&L1,num);
        num = rand()%100;
        insere(&L2,num);
    }
    printf("L1: ");
    printa(L1);
    printf("L2: ");
    printa(L2);
    printf("Concatenada: ");
    L = concatena(L1,L2);
    printa(L);
    return 0;
}