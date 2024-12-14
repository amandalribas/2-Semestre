#include <stdio.h>
#include <stdlib.h>

//LISTAS DUPLAMENTE ENCADEADAS CIRCULARES COM NÓ CABEÇA
struct NO{
    int elemento;
    struct NO *prox, *ant;
};
typedef struct NO lista;

int buscaElemento(lista *L, lista **pre, int elemento){
    lista *aux, *preL;
    preL = L;
    aux = L->prox;
    while ((aux!=L)&&(aux->elemento <elemento)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=L)&&(aux->elemento == elemento))
        return 1;
    return 0;
}

void insereElemento(lista **L, int elemento){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->elemento = elemento;
        aux->prox = pre->prox;
        aux->ant = pre;
        pre->prox = aux;
        pre->prox->ant= aux;

    }
}

void removeElemento(lista **L, int elemento){
    lista *lixo, *pre;
    if (buscaElemento((*L),&pre,elemento)){
        lixo = pre->prox;
        lixo->ant->prox = lixo->prox;
        lixo->prox->ant = lixo->ant;
        free(lixo);
    }
}

int main(void){
    lista *L;
    L = (lista*)malloc(sizeof(lista));
    L->prox = L;
    L->ant = L;

    return 0;
}