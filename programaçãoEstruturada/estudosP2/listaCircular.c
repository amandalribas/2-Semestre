#include <stdlib.h>
#include <stdio.h>
#include <time.h>



#define TAM 10

struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElemento(lista *L, lista **pre, int elemento){
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux!=L) && (aux->dado < elemento)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado == elemento))
        return 1;
    return 0;
}

void preencheLista(lista **L, int elemento){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->dado = elemento;
        aux->prox = pre->prox;
        pre->prox = aux;
    }
}

void removeElemento(lista **L, int elemento){
    lista *lixo, *pre;
    if (buscaElemento((*L),&pre,elemento)){
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
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
    lista *L;
    int i, num;
    L = (lista*)malloc(sizeof(lista));
    L->prox = L;

    srand(time(NULL));
    for (i=0;i<TAM;i++){
        num = rand() % 10;
        preencheLista(&L,num);
    }

    printa(L);

    printf("Que numero deseja remover? ");
    scanf("%d", &num);
    removeElemento(&L, num);
    printa(L);
    return 0;
}