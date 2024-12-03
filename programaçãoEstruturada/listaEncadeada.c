#include <stdio.h>
#include <stdlib.h>


struct NO{
    int info;
    struct NO *prox;
};
typedef struct NO listaEncadeada;

int buscaElemento(listaEncadeada *lista, int elemento, listaEncadeada **pre){
    //1 se achou elemento; 0 se nao achou;
    listaEncadeada *aux, *preLista;
    aux = lista;
    preLista = NULL;
    while ((aux!=NULL)&&(aux->info < elemento)){
        preLista = aux;
        aux = aux->prox;
    }
    *(pre) = preLista;
    if ((aux!=NULL)&&(aux->info == elemento))
        return 1;
    return 0;
}

listaEncadeada *insereElemento(listaEncadeada *lista, int elemento){
    listaEncadeada *elem, *pre;
    if (!buscaElemento){ //Nao Encontrou Elemento na Lista, pode adicionar;
        elem = (listaEncadeada*)malloc(sizeof(listaEncadeada));
        elem->info = elemento;
        if ((*pre != NULL))
    }
}


int main(void){
    listaEncadeada *lista, *aux;
    lista = NULL;

    aux = (listaEncadeada*)malloc(sizeof(listaEncadeada));

    return 0;
}