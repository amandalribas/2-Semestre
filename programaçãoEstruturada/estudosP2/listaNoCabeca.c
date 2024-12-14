#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct NO{
    int dado;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElemento(lista *L, lista **pre, int elemento){
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux!=NULL)&&(aux->dado < elemento)){
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(aux->dado == elemento))
        return 1;
    return 0;
}

void insereElemento(lista **L, int elemento){
    lista *aux, *pre;
    if (!(buscaElemento((*L), &pre, elemento))){
        //nao precisa testar se a lista esta vazia
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

void print(lista *L){
    lista *aux;
    aux = L->prox;
    while (aux!=NULL){
        printf("%d \t", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    lista *L;
    int i, n, num;
    L = (lista*)malloc(sizeof(lista));
    L->prox = L;
    printf("Deseja Inserir Quantos Elementos? ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i=0;i<n;i++){
        num = rand() % 100;
        insereElemento(&L,num);
    }
    print(L);
    printf("Quer remover qual elemento?");
    scanf("%d", &num);
    removeElemento(&L, num);
    print(L);
    return 0;
}
