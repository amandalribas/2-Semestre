#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*Considerando uma lista simplesmente encadeada dinâmica, faça a declaração desta estrutura e uma função que calcule e retorne a média de preços.*/

struct NO{
    int codigo;
    float valor;
    char nome[30];
    struct NO *prox;
};
typedef struct NO lista;

float mediaPrecos(lista *L){
    lista *aux;
    float valorTotal = 0, media;
    int contador = 0;
    aux = L;
    while (aux!=NULL){
        valorTotal += aux->valor;
        aux = aux->prox;
        contador++;
    }
    media = valorTotal/contador;
    return media;
}

void preenche(lista **L, int codigo, float valor, char nome[30]){
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    aux->codigo = codigo;
    aux->valor = valor;
    //aux->nome = nome;
    strcpy(aux->nome, nome);
    if ((*L) == NULL){
        aux->prox = (*L);
        (*L) = aux;
    }else{
        aux->prox = (*L);
        (*L) = aux;
    }
}

void print(lista *L){
    lista *aux;
    aux = L;
    while (aux!=NULL){
        printf("\nCODIGO: %d\nVALOR: %.2f\nNOME: %s\n", aux->codigo, aux->valor, aux->nome);
        aux= aux->prox;
    }
}

int main(void){
    lista *L;
    int n, i ,cod;
    float val, media;
    char nom[30];
    L = NULL;
    printf("Quantos Produtos deseja Registrar?");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        printf("Digite o %do. Codigo: ", i+1);
        scanf("%d", &cod);
        printf("Digite o Valor de %d:", cod);
        scanf("%f", &val);
        printf("Digite o nome de %d: ", cod);
        scanf("%s", nom);
        preenche(&L,cod,val,nom);
    }
    printf("\nLISTA PREENCHIDA:\n");
    print(L);
    media = mediaPrecos(L);
    printf("\nMedia de PRECOS: %.2f", media);
    return 0;
}