#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Fazer um programa que crie duas listas simplesmente encadeadas L1 e L2 que guardem números inteiros. Tais listas representarão dois conjuntos distintos. Implementar as operações de interseção, união, diferença e pertinência.*/

#define TAM 20

struct NO{
    int valor;
    struct NO *prox;
};
typedef struct NO lista;

int menu(void){
    int op;
    printf("\n{  MENU  }\n[1]Intersecao;\n[2]Uniao;\n[3]Diferenca;\n[4]Pertinencia;\n[0]Sair.\nDigite a Opcao Desejada: ");
    scanf("%d", &op);
    return op;
}

int pertinencia(lista *L, int num){
    if (L == NULL)
        return 0;
    if (L->valor == num)
        return 1;
    return pertinencia(L->prox, num);
}

lista *intersecao(lista *L1, lista *L2){
    lista *aux, *inter;
    aux = L1;
    inter = NULL;
    while (aux != NULL){
        if (pertinencia(L2, aux->valor))
            insere(&inter, aux->valor);
        aux = aux->prox;
    }
    return inter;
}

lista *uniao(lista *L1, lista *L2){
    lista *aux, *uni;
    aux = L1;
    uni = NULL;
    while (aux != NULL){
        insere(&uni,aux->valor);
        aux = aux->prox;
    }
    aux = L2;
    while (aux != NULL){
        if (!(pertinencia(uni,aux->valor)))
            insere(&uni,aux->valor);
        aux = aux->prox;
    }
    return uni;
}

lista *diferenca(lista *L1, lista*L2){
    lista *aux, *dif;
    aux = L1;
    dif = NULL;
    while (aux!=NULL){
        if (!(pertinencia(L2,aux->valor)))
            insere(&dif, aux->valor);
        aux = aux->prox;
    }
    return dif;
}


int seek(lista *L, lista **pre, int num){
    lista *aux, *preS;
    aux = L;
    preS = NULL;
    while ((aux!=NULL)&&(aux->valor < num)){
        preS = aux;
        aux = aux->prox;
    }
    (*pre) = preS;
    if ((aux!=NULL)&&(aux->valor == num))
        return 1;
    return 0;
}


void insere(lista **L, int num){
    lista *pre, *aux;
    pre = NULL;
    if (!(seek((*L),&pre,num))){ //se nao achou
        aux = (lista*)malloc(sizeof(lista));
        aux->valor = num;
        if (((*L)==NULL)||(pre==NULL)){
            aux->prox = (*L);
            (*L) = aux;
        }else{
            aux->prox = pre->prox;
            pre->prox = aux;
        }
    }
}

void print(lista *L){
    lista *aux;
    aux = L;
    while (aux!=NULL){
        printf(" %d \t", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    lista *L1, *L2, *inter, *uni, *dif;
    int opcao, i, n;
    L1 = NULL;
    L2 = NULL;
    inter = NULL;
    uni = NULL;
    dif= NULL;
    opcao = menu();
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        n = rand() % 25;
        insere(&L1,n);
        n = rand() % 25;
        insere(&L2, n);
    }

    while (opcao != 0){
        printf("L1 Atual: ");
        print(L1);
        printf("L2 Atual: ");
        print(L2);
        switch (opcao){
        case 1:
            inter = intersecao(L1,L2);
            printf("\nLista de Intersecao: \n");
            print(inter);
            break;
        case 2:
            uni = uniao(L1,L2);
            printf("\nLista de Uniao: \n");
            print(uni);
            break;
        case 3:
            dif = diferenca(L1,L2);
            printf("\nLista de Diferenca L1-L2: \n");
            print(dif);
            dif = diferenca(L2,L1);
            printf("\nLista de Diferenca L2-L1: \n");
            print(dif);
            break;
        case 4:
            printf("\nDigite o Valor que deseja Saber se Pertence aos Conjuntos: ");
            scanf("%d", &n);
            if (pertinencia(L1, n))
                printf("\n%d Pertence ao Conjunto L1.", n);
            else
                printf("\n%d Nao Pertence ao Conjunto L1.", n);
            if (pertinencia(L2,n))
                printf("\n%d Pertence ao Conjunto L2.", n);
            else
                printf("\n%d Nao Pertence ao Conjunto L2.", n);
            break;
        default:
            printf("\nOpcao Inválida... Tente Novamente!");
            break;
        }
        opcao = menu();
    }
    printf("\n<Fechando Programa...>");
    return 0;
}