#include <stdio.h>
#include <stdlib.h>

struct NO{
    int valor;
    struct NO *prox;
};
typedef struct NO fila;
//insert no final da fila
void insert (fila **inicio, fila **final, int elemento){
    fila *aux;
    aux = (fila*)malloc(sizeof(fila));
    aux->valor = elemento;
    aux->prox = NULL;
    if ((*inicio) == NULL) //insere no comeco (fila vazia)
        (*inicio) = aux;
    else //insere no final
        (*final)->prox = aux;
    (*final) = aux; 
}

void print(fila **inicio){
    fila *aux;
    aux = (*inicio);
    while (aux!=NULL){
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

//pop no inicio da fila
void pop(fila **inicio){
    fila *aux;
    if ((*inicio)!=NULL){
        aux = (*inicio);
        (*inicio) = (*inicio)->prox;
    }
    printf("%d REMOVIDO!\n", aux->valor);
    free(aux);
}

int main(void){
    fila *inicio;
    fila *final;
    inicio = NULL;
    final = NULL;
    int n, i;
    do{
        printf("Digite Valor a Ser Inserido na Fila: ");
        scanf("%d", &n);
        if (n>0)
            insert(&inicio,&final,n);
    }while (n>0);
    print(&inicio);
    printf("Quantos Valores Devem Sair da Fila? ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        pop(&inicio);
    }
    printf("\n");
    print(&inicio);
}