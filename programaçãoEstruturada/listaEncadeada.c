#include <stdio.h>
#include <stdlib.h>

/*Lista Encadeada -- STRUCT - NO;
Insere em Ordem Numerica, s/ numeros Repetidos;
Funcao de Busca;
Funcao de Inserir;
Remover;*/

struct NO{
    int valor;
    struct NO *prox;
};
typedef struct NO lista;

int seek(lista *L, lista **pre, int elemento){
    lista *aux, *preSeek;
    aux = L;
    preSeek = NULL;
    while ((aux!=NULL)&&(aux->valor < elemento)){
        preSeek = aux;
        aux = aux->prox;
    }
    (*pre) = preSeek;
    if ((aux!=NULL)&&(aux->valor == elemento))
        return 1;
    return 0;
}

void insert(lista **L, int elemento){
    lista *aux, *pre;
    if (!(seek((*L), &pre, elemento))){
        aux = (lista*)malloc(sizeof(lista));
        aux->valor = elemento;
        if ((*L)==NULL || pre == NULL){ //lista vazia ou inserir no comeco
            aux->prox = (*L);
            (*L) = aux;
        }else{ //inserindo no meio ou fim
            aux->prox = pre->prox;
            pre->prox = aux;
        }
    }
}

int remov(lista **L, int elemento){
    lista *lixo, *pre;
    if (((*L)!=NULL)&&(seek(*L, &pre, elemento))){
        if ((*L)->valor==elemento){ //primeiro elemento deve ser removido  
            lixo = (*L);
            (*L) = lixo->prox;    
        }else{
            lixo = pre->prox; 
            pre->prox = lixo->prox;
        }
        free(lixo);
        return elemento;
    }
    return 0;
}

void print(lista *L){
    lista *aux;
    aux = L;
    while (aux!= NULL){
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
}

int main(void){
    lista *L;
    int i, t, num;
    L = NULL;
    //inserindo positivos
    do{
        printf("Digite um Valor para Inserir na Lista: ");
        scanf("%d", &num);
        if (num>0)
            insert(&L, num);
    }while (num > 0);
    print(L);
    printf("\nDeseja Remover Quantos Elementos?");
    scanf("%d", &t);
    for (i=0;i<t;i++){
        printf("\nDigite o valor que quer remover:");
        scanf("%d", &num);
        remov(&L, num);
        printf("Lista Atual: ");
        print(L);
    }
    return 0;

}