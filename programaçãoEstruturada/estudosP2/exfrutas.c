#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STRCOMP(STR1,STR2): == 0 STRINGS IGUAIS
>0 STR1 > STR2 no ASCII
<0 STR2 > STR1 no ASCII*/

#define TAM 30

struct NO{
    char fruta[TAM];
    struct NO *prox;
};
typedef struct NO lista;


int buscaElemento(lista *L, lista **pre, char fruta[TAM]){
    lista *aux, *preL;
    aux = L->prox;
    preL = L;
    while ((aux!=NULL)&&(strcmp(aux->fruta,fruta) < 0)){
        preL= aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux!=NULL)&&(strcmp(aux->fruta,fruta) == 0))
        return 1;
    return 0;
}

void insereElemento(lista **L, char fruta[TAM]){
    lista *aux, *pre;
    if (!(buscaElemento((*L),&pre,fruta))){
        aux = (lista*)malloc(sizeof(lista));
        strcpy(aux->fruta,fruta);
        aux->prox = pre->prox;
        pre->prox = aux;
    }
}

void removeElemento(lista **L, char fruta[TAM]){
    lista *lixo, *pre;
    pre = L;
    if (buscaElemento((*L),&pre,fruta)){
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    }
}


void mostra(lista *L){
    lista *aux;
    aux = L->prox;
    while (aux!=NULL){
        printf("\n%s", aux->fruta);
        aux = aux->prox;
    }
    printf("\n");
}

int quantNos(lista *L){
    if (L == NULL)
        return 0;
    else
        return (1+ quantNos(L->prox));
}

int menu(void){
    int op;
    printf("\n{MENU}\n[1]Insere Elemento;\n[2]Remove Elemento;\n[3]Mostra Lista;\n[4]Quantidade de Nos;\n[5]Sair.\nDigite a Opcao Desejada: ");
    scanf("%d", &op);
    return op;
}

int main(void){
    lista *L;
    char fruta[TAM];
    int opcao, num;
    L = (lista*)malloc(sizeof(lista));
    L->prox = NULL;
    opcao = menu();
    while (opcao != 5){
        switch (opcao){
            case 1:
                printf("Digite o nome de uma fruta: ");
                scanf("%s", fruta);
                insereElemento(&L,fruta);
                break;
            case 2:
                printf("Digite a fruta a ser removida: ");
                scanf("%s", fruta);
                removeElemento(&L,fruta);
                break;
            case 3:
                mostra(L);
                break;
            case 4:
                num = quantNos(L);
                printf("\nQuantidade de Nos: %d", num);
                break;
            default:
                printf("\nOpcao Invalida... Tente Novamente!");
                break;
        }
        opcao = menu();
    }
    printf("\n<ENCERRANDO o Programa...>");
    return 0;
}