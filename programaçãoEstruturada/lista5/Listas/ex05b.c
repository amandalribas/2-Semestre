#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//L1 e L2 são simplesmente encadeadas, circulares e sem nós cabeça;
#define TAM 10

struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElemento(lista *L, lista **pre, int dado){
    lista *aux, *preL;
    aux = L;
    preL = NULL;
    do{
        preL = aux;
        aux = aux->prox;
    }while ((aux->prox!=L)&&(aux->dado < dado));
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado == dado))
        return 1;
    return 0;
}

void insereElemento(lista **L, int dado){
    lista *elemento, *aux, *pre;
    if (!(buscaElemento((*L),&pre,dado))){
        elemento = (lista*)malloc(sizeof(lista));
        elemento->dado = dado;
        if ((*L)==NULL){
            (*L) = elemento;
            elemento->prox = (*L);

        } else{
            aux = (*L);
            while (aux->prox != (*L))
                aux = aux->prox;
            elemento->prox = (*L);
            aux->prox = elemento;
        }
    }
}

void printa(lista *L){
    lista *aux;
    aux = L;
    do{
        printf("%d", aux->dado);
        aux = aux->prox;
    }while(aux!=L);
    printf("\n");
}


int main(void){
    lista *L1, *L2;
    int i, num;
    L1 = NULL;
    L2 = NULL;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        num = rand() % 100;
        insereElemento(&L1,num);
        num = rand() % 100;
        insereElemento(&L2,num);
    }
    printa(L1);
    printa(L2);
    return 0;

}