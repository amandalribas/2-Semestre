#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//L1 e L2 são duplamente encadeadas, circulares e com nós cabeça;
#define TAM 10
struct NO{
    int dado;
    struct NO *prox, *ant;
};
typedef struct NO lista;

lista *concatenada(lista *L1, lista *L2){
    lista *aux, *aux2;
    if (L1->prox == NULL)
        return L2;
    aux = L1->prox;
    while (aux->prox != L1)
        aux = aux->prox;
    aux->prox = L2->prox;
    aux2 = L2->prox;
    while (aux2->prox != L2)
        aux2 = aux2->prox;
    aux2->prox = L1;
    return L1;
}

int buscaElemento(lista *L, lista **pre, int elemento){
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux!=L)&&(aux->dado<elemento)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=L)&&(aux->dado == elemento))
        return 1;
    return 0;
}

void insereElemento(lista **L, int elemento){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->dado = elemento;
        aux->prox = pre->prox;
        aux->ant = pre;
        pre->prox->ant = aux;
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
    L2 = (lista*)malloc(sizeof(lista));
    L = (lista*)malloc(sizeof(lista));
    L1->prox = L1;
    L1->ant = L1;
    L2->prox = L2;
    L2->ant = L2;
    L1->prox = L;
    L->ant = L;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        num = rand() % 100;
        insereElemento(&L1, num);
        num = rand() % 100;
        insereElemento(&L2,num);
    }
    printf("L1: ");
    printa(L1);
    printf("L2: ");
    printa(L2);
    L =concatenada(L1,L2);
    printa(L);
    return 0;
}