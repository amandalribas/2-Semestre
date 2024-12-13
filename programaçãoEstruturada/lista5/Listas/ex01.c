#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct NO{
    int valor;
    struct NO *prox;
};
typedef struct NO lista;

void insert(lista **L, int elemento){
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    aux->valor = elemento;
    if ((*L)== NULL){ //inserindo 1o. elemento
        (*L) = aux;
        aux->prox = NULL;

    } else{
        aux->prox = (*L);
        (*L) = aux;
    }
    printf("\nINSERIDO %d", elemento);
}

void print (lista *L){
    lista *aux;
    aux = L;
    while (aux != NULL){
        printf(" %d \t", aux->valor);
        aux = aux->prox;
    }
}

int nos(lista *L){
    if (L !=NULL){
        return (1+ nos(L->prox));
    }
    else
        return 0;
}

int main(void){
    lista *L;
    int i, tam, num;
    L = NULL;
    printf("Tamanho da Lista: ");
    scanf("%d", &tam);
    srand(time(NULL));
    for (i=0;i<tam;i++){
        num = rand() % 100;
        insert(&L, num);
    }
    printf("\nLISTA ATUAL: ");
    print(L);
    num = nos(L);
    printf("\nNOS: %d", num);
    return 0;
}