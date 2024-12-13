#include <stdio.h>
#include <stdlib.h>

/*Considerando alocação sequencial estática, faça a declaração desta estrutura e uma função que receba esta lista como parâmetro e que escreva os dados de todos os produtos contidos na lista.*/

#define MAX 3

struct LISTA{
    int codigo[MAX];
    float valor[MAX];
    char nome[MAX][30];
    int total;
};
typedef struct LISTA lista;

void mostra(lista L){
    int i;
    printf("\nDADOS DA LISTA:");
    for (i=0;i<MAX;i++)
        printf("\n%do. CODIGO: %d\nVALOR DE %d: %.2f\nNOME DE %d: %s\n",i+1,L.codigo[i],L.codigo[i], L.valor[i], L.codigo[i], L.nome[i]);
}

int main(void){
    lista L;
    int i;
    L.total = 0;
    for (i=0;i<MAX;i++){
        printf("Codigo do %do. Elemento: ", i+1);
        scanf("%d", &L.codigo[L.total]);
        printf("Valor de %d: ", L.codigo[L.total]);
        scanf("%f", &L.valor[L.total]);
        printf("Nome de %d: ", L.codigo[L.total]);
        scanf("%s", L.nome[L.total]);
        (L.total)++;
    }
    mostra(L);
    return 0;
}