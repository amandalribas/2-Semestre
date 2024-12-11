#include <stdio.h>
#include <stdlib.h>

struct NO{
    int valor;
    struct NO *prox;
};
typedef struct NO pilha;

void pull(pilha **topo, int elemento){
    pilha *aux;
    aux = (pilha*)malloc(sizeof(pilha));
    aux->valor = elemento;
    aux->prox = (*topo);
    (*topo) = aux;
}

void print(pilha **topo){
    pilha *aux;
    aux = (*topo);
    while (aux!=NULL){
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void imparPar(pilha **topo, pilha **par, pilha **impar){
    pilha *aux;
    aux = (*topo);
    while (aux!=NULL){
        if (aux->valor % 2 == 0)
            pull(&(*par),aux->valor);
        else
            pull(&(*impar),aux->valor);
        aux = aux->prox; 
    }
    free(aux);
}
void push(pilha **topo){
    pilha *aux;
    int elemento;
    if ((*topo) != NULL){
        aux = (*topo);
        elemento = aux->valor;
        (*topo) = aux->prox;
        free(aux);
    }
    printf("\n%d REMOVIDO!", elemento);
}

int pushRetornando(pilha **topo){
    pilha *aux;
    int elemento;
    if ((*topo) != NULL){
        elemento = (*topo)->valor;
        aux = (*topo);
        (*topo) = aux->prox;
        free(aux);
    }
    return elemento;
}

int main(void){
    pilha *topo;
    pilha *topoPar;
    pilha *topoImpar;
    int i, n, num;
    topo = NULL;
    topoPar = NULL;
    topoImpar = NULL;
    do{
        printf("Digite um Valor a Ser Inserido no Topo da Pilha: ");
        scanf("%d", &num);
        if (num!=0){
            pull(&topo, num);
        }
    }while (num!= 0);
    print(&topo);
    printf("\nQuantos Elementos Deseja Remover do Topo da Pilha?");
    scanf("%d", &n);
    for (i=0;i<n;i++)
        push(&topo);
    printf("\n");
    print(&topo);
    
    /*printf("\nQuantos Elementos Deseja Remover do Topo da Pilha?");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        num = pushRetornando(&topo);
        printf("\nREMOVIDO: %d", num);
    }
    printf("\n");
    print(&topo);*/
    imparPar(&topo, &topoPar, &topoImpar);
    printf("\nPilha de Pares:");
    print(&topoPar);
    printf("\nPilha de Impares:");
    print(&topoImpar);
    return 0;
}