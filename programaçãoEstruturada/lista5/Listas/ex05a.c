#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//L1 e L2 são simplesmente encadeadas, não circulares e sem nós cabeça
#define TAM 10

struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

lista *concatena(lista *L1, lista *L2){
    lista *aux;
    if (L1 == NULL){
        return L2;
    }else{
        aux = L1;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = L2;
    }
    return L1;
}

//funcoes basicas para testar o funciuonamento:
int buscaElemento(lista *L, lista **pre, int dado){
    lista *aux, *preL;
    preL = NULL;
    aux = L;
    while ((aux!=NULL)&&(aux->dado<dado)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado==dado))
        return 1;
    return 0;
}

void insereElemento(lista **L, int dado){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,dado))){
        aux = (lista*)malloc(sizeof(lista));
        aux->dado = dado;
        if (((*L)==NULL)||(pre==NULL)){
            aux->prox = (*L);
            (*L) = aux;
        }else{
            aux->prox = pre->prox;
            pre->prox = aux;
        }
    }
}

void print(lista *L){
    lista *aux;
    aux = L;
    while (aux!=NULL){
        printf(" %d \t", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    lista *L1, *L2, *L;
    int i, n;
    L1 = NULL;
    L2 = NULL;
    L = NULL;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        n = rand() % 100;
        insereElemento(&L1, n);
        n = rand() % 100;
        insereElemento(&L2,n);
    } 
    print(L1);
    print(L2);
    printf("Concatenadas:\n");
    L = concatena(L1,L2);
    print(L);
    return 0;
}