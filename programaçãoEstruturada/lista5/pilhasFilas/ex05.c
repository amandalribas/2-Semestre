#include <stdio.h>
#include <stdlib.h>

#define LIM 2
struct NO{
    int processo, tempo;
    struct NO *prox;
};
typedef struct NO fila;

void insert(fila **inicio, fila **fim, int n, int t){
    fila *aux;
    aux = (fila*)malloc(sizeof(fila));
    aux->processo = n;
    aux->tempo = t;
    aux->prox = NULL;
    if ((*inicio) == NULL)
        (*inicio) = aux;
    else
        (*fim)->prox = aux;
    (*fim) = aux; 
}

void pop(fila **inicio){
    fila *aux;
    if ((*inicio)!=NULL){
        aux = (*inicio);
        (*inicio) = (*inicio)->prox;
    }
    free(aux);
}

void print(fila **inicio){ //printa a fila sem corresponder ao limite de tempo
    fila *aux;
    aux = (*inicio);
    while (aux!= NULL){
        printf("P%d Tempo: %du.t\t\n",aux->processo, aux->tempo);
        aux = aux->prox;
    }
    free(aux);
}

int main(void){
    fila *inicio;
    fila *fim;
    int n,t;
    inicio = NULL;
    fim = NULL;
    do{
        printf("No. DO PROCESSO: ");
        scanf("%d", &n);
        if (n > 0){
            printf("Tempo do Processo %d:", n);
            scanf("%d", &t);
            insert(&inicio,&fim,n,t);
        }else
            printf("Fim da Insercao...\n");
    }while (n > 0);
    print(&inicio);

    //execucao dos processos;
    do{
        if (inicio->tempo >= LIM){
            printf("#executando P%d <tempo de Execucao: %d>\n", inicio->processo, LIM);
            insert(&inicio,&fim,inicio->processo,inicio->tempo-LIM);
            pop(&inicio);
        }else{
            printf("#executando P%d <tempo de Execucao: %d>\n", inicio->processo, inicio->tempo);
            pop(&inicio);
        }
    }while (inicio != NULL);

    return 0;
}