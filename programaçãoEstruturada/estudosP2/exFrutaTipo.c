#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FRUTA{
    char info[30];
    struct FRUTA *proxF;
    struct TIPOFRUTA *proxT;
};
typedef struct FRUTA fruta;

struct TIPOFRUTA{
    char info[30];
    struct TFRUTA *proxT;
};
typedef struct TIPOFRUTA tipoFruta;

int menu(void){
    int op;
    printf("\n(((MENU)))\n[1]Insere Fruta;\n[2]Insere Tipo de Fruta;\n[3]Remove Elemento;\n[4]Remove Tipo da Fruta;\n[5]Mostra Lista;\n[6]SAIR\nDigite Opcao Desejada: ");
    scanf("%d", &op);
    return op;
}

int buscaTipo(tipoFruta *L, tipoFruta **pre, char frutinha[30]){
    tipoFruta *auxTipo, *preT;
    auxTipo = (*L);
    preT = NULL;
    while ((auxTipo!=NULL)&&(strcmp(auxTipo->info,frutinha)<0)){
            auxTipo = auxTipo->proxT;
            preT = auxTipo;
    }
    (*pre) = preT;
    if ((preT->proxT != NULL)&&(strcmp(preT->info,frutinha)))
        return 1;
    return 0;
}

int buscaFruta(fruta *L, fruta **pre, char frutinha[30]){
    fruta *aux, *preF;
    aux = L;
    preF = NULL;
    while ((aux != NULL)&&(strcmp(aux->info,frutinha))<0){
        preF = aux;
        aux = aux->proxF;
    }
    (*pre) = preF;
    if ((aux!=NULL)&&(strcmp(aux->info,frutinha)>= 0))
        return 1;
    return 0;
}

void insereTipo(fruta **L)
void insereFruta(fruta **L, char frutinha[30]){
    fruta *pre, *aux;
    if ((!buscaFruta((*L),&pre,frutinha))){
        aux = (fruta*)malloc(sizeof(fruta));
        strcpy(aux->info,frutinha);
        if ((*L)==NULL){
            aux->proxF = (*L);
            (*L) = aux;
        }else{
            aux->proxF = pre->proxF;
            pre->proxF = aux;
        }
    }
}

void removeFruta(fruta **L, char frutinha[30]){
    fruta *lixo, *pre;
    if (buscaFruta((*L),&pre,frutinha)){
        lixo = pre->proxF;
        pre->proxF = lixo->proxF;
        free(lixo);
    }
}

void mostraLista(fruta *L){
    fruta *aux;
    aux = L;
    while (aux!=NULL){
        printf("  %s \t ", aux->info);
        aux = aux->proxF;
    }
    printf("\n");
}


int main(void){
    int opcao;
    fruta *L;
    char frutinha[30], aux[30];
    opcao = menu();
    while (opcao != 6){
        switch (opcao){
            case 1:
                printf("\nDigite uma Fruta para Inserir: ");
                scanf("%s", frutinha);
                insereFruta(&L,frutinha);
                break;
            case 2:
                printf("\nDigite um tipo de Fruta para Inserir: ");
                scanf("%s", frutinha);
                printf("")
            case 3:
                printf("\nDigite uma Fruta para Remover: ");
                scanf("%s", frutinha);
                removeFruta(&L, frutinha);
            case 5:
                mostraLista(L);
                break;
        }
        opcao = menu();
    }
    printf("\n<Saindo do Programa...>");
    return 0;   
}