#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//L1 e L2 são simplesmente encadeadas, circulares e com nós cabeça;

#define TAM 10;
struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

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

int main(void){
    lista *L1, *L2, *L;
    int i, num;
    L1 = (lista*)malloc(sizeof(lista));
    L1->prox = L;
    L2 = (lista*)malloc(sizeof(lista));
    L2->prox = L;
    L = (lista*)malloc(sizeof(lista));
    L->prox = L;

    srand(time(NULL));
    for (i=0;i<TAM,i++){
        num = rand()%100;
        insere(&L1,num);
        num = rand()%100;
        insere(&L2,num);
    }

    return 0;
}