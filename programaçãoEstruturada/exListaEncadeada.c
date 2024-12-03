#include <stdio.h>
#include <stdlib.h>

struct NO{
    int elemento;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElemento(lista *encadeada, int elem){
    lista *aux;
    aux = encadeada;
    while (aux != NULL){
        if (aux->elemento == elem)
        return 1;
        aux = aux->prox;
    }
    return 0;
}

void insereElemento(lista **encadeada, int elem){
    lista *aux;
    if (!(buscaElemento(*encadeada,elem))){
        aux = (lista *)malloc(sizeof(lista));
        aux->elemento = elem;
        aux->prox = *encadeada;
        *encadeada = aux;
    }
}

void imprimeLista(lista *encadeada){
    lista *aux;
    aux = encadeada;
    if (aux == NULL)
        printf("A lista está vazia.\n");
    while (aux != NULL){
            printf(" %d\t", aux->elemento);
            aux = aux->prox;
    }
}

void intersecao(lista *lista1, lista *lista2){
    lista *aux;
    while (lista1 != NULL){
        aux = lista2;
        while (aux!=NULL){
            if (lista1->elemento == aux->elemento){
                printf("%d --", lista1->elemento);
                break;
            }
            aux = aux->prox;
        }
    }   
}

int main(void){
    lista *A, *B;
    int n;
    A = NULL;
    B = NULL;

    printf("PREENCHENDO A...\n");
    do{
        printf("Digite um valor: ");
        scanf("%d", &n);
        if (n > 0)
            insereElemento(&A, n);
    }while(n>0); 
    

    printf("\nPREENCHENDO B...\n");
    do{
        printf("Digite um valor: ");
        scanf("%d", &n);
        if (n > 0)
            insereElemento(&B, n);
    }while(n>0);
    
    printf("\nLISTA A:");
    imprimeLista(A);

    printf("\nLISTA B:");
    imprimeLista(B);
    
    printf("\nIntersecao de A e B:");
    intersecao(A, B);

    return 0;
}

/*void imprimeLista(lista *L){
    if (L!=NULL){
        printf("%d - ", L->elemento);
        imprimeLista(L->prox);
    }
}

void intersecao(lista *lista1, lista *lista2){
    lista *aux;
    while (lista1 != NULL){
        if (lista1->elemento){
            printf("%d --", lista1->elemento);
            break;
        }
        aux = aux->prox;
    }
}

*/