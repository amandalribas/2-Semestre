#include <stdlib.h>
#include <stdio.h>
/*Considerando uma lista simplesmente encadeada dinâmica, faça a declaração desta estrutura e uma função que calcule e retorne a média de preços.*/

struct NO{
    int codigo;
    float valor;
    char nome[30];
    struct NO *prox;
};
typedef struct NO lista;

int mediaPrecos(lista *L){

}

int main(void){
    return 0;
}