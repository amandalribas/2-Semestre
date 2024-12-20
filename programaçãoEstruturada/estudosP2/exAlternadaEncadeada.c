#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NO{
    int elemento;
    struct NO *prox;
};
typedef struct NO lista;

void insereElemento(lista **L, int elemento){
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    aux->elemento = elemento;
    aux->prox = (*L);
    (*L) = aux;
}

void printa(lista *L){
    lista *aux;
    aux = L;
    while (aux!=NULL){
        printf(" %d \t", aux->elemento);
        aux = aux->prox;
    }
    printf("\n");
}

lista *intercala(lista **L1, lista **L2){
    lista *L,*aux1, *aux2;
    L = (*L1);
    while (aux1!=NULL && aux2!=NULL){
        aux1 = (*L1)->prox;
        aux2 =(*L2)->prox;
        (*L1)->prox = (*L2);
        (*L2)->prox = aux1;
        (*L1) = aux1;
        (*L2) = aux2;
    }
    return L;
}

int main(void){
    lista *L1, *L2, *L;
    int i, tam, num;
    L1 = NULL;
    L2 = NULL;
    L = NULL;
    srand(time(NULL));
    printf("Tamanho da LISTA: ");
    scanf("%d", &tam);
    for (i=0;i<tam;i++){
        num = rand()%100;
        printf("NUM ATUAL: %d\n", num);
        insereElemento(&L1,num);
        num = rand()%100;
        insereElemento(&L2,num);
        printf("NUM ATUAL: %d\n", num);
    }
    printf("L1: ");
    printa(L1);
    printf("L2: ");
    printa(L2);
    printf("Intercalada");
    L = intercala(&L1,&L2);
    printa(L);
    return 0;
}