#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct LISTA{
    int *numeros;
    int total;
};
typedef struct LISTA lista;

void insereElemento(lista *L, int elemento){
    L->numeros[L->total] = elemento;
    L->total++;
}

void printa(lista *L){
    int i;
    for (i=0;i<L->total;i++)
        printf(" %d \t", L->numeros[i]);
    printf("\n");
}

lista intercala(lista *L1, lista *L2){
    int i;
    lista *L;
    L = (lista*)malloc(sizeof(lista));
    L->total = 0;
    L->numeros = (int*)malloc( 2 * L1->total * sizeof(int));
    for (i = 0;i<L1->total;i++){
        insereElemento(L,L1->numeros[i]);
        insereElemento(L,L2->numeros[i]);
    }
    return *L;
}

int main(void){
    lista L1;
    lista L2;
    lista L;
    int tam, num;
    L1.total = 0;
    L2.total = 0;
    srand(time(NULL));
    printf("Qual os tamanho das Listas?");
    scanf("%d",&tam);
    L1.numeros = (int*)malloc(tam * sizeof(int));
    L2.numeros = (int*)malloc(tam * sizeof(int));
    for (int i = 0;i<tam;i++){
        num = rand()%100;
        insereElemento(&L1,num);
        num = rand()%100;
        insereElemento(&L2,num);
    }
    printf("L1: ");
    printa(&L1);
    printf("L2: ");
    printa(&L2);
    L = intercala(&L1,&L2);
    printf("Intercalada: ");
    printa(&L);
    free(L1.numeros);
    free(L2.numeros);
    free(L.numeros);
    return 0;
}