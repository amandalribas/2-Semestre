#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Faça uma função recursiva que escreva se um determinado elemento pertence ou não a uma lista. Considere que L é simplesmente encadeada, sem nó cabeça e não circular.*/

struct NO{
    int elemento;
    struct NO *prox;
};
typedef struct NO lista;

int busca(lista *L, int elemento){
    if (L == NULL)
        return 0;
    if (L->elemento == elemento)
        return 1;
    return busca(L->prox, elemento);
}

int buscaElemento(lista *L, lista **pre, int elemento){
    lista *preL, *aux;
    aux = L;
    preL = NULL;
    while ((aux!=NULL)&&(aux->elemento<elemento)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->elemento == elemento))
        return 1;
    return 0;
}


void insert(lista **L, int elemento){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->elemento = elemento;
        if ((*L==NULL)||(pre==NULL)){
            aux->prox = (*L); // == NULL
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
        printf(" %d \t", aux->elemento);
        aux = aux->prox;
    }
}

int main(void){
    lista *L;
    int num, total, i;
    L = NULL;
    printf("Quantos Numeros deseja na Lista? ");
    scanf("%d", &total);
    srand(time(NULL));
    for (i=0;i<total;i++){
        num = rand()%10;
        insert(&L,num);
    }
    printf("\nLista: \n");
    print(L);
    printf("\nDeseja verificar se qual numero esta na lista?");
    scanf("%d", &num);
    if (busca(L,num))
        printf("\n%d Esta na Lista", num);
    else
        printf("\n%d Nao esta na Lista", num);
    return 0;
}