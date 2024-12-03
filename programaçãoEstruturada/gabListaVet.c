#include <stdio.h>
# define MAX 100

struct LISTA {
    int num[MAX];
    int total;
};
typedef struct LISTA lista;

void mostra(lista L){
    int i;
    for (i=0; i< L.total;i++)
        printf("\n%d - ",L.num[i]);
}

int busca(lista *L, int elem, int *pos){
    int i=0;
    while (i < L->total && elem > L->num[i])
        i++;
    (*pos) = i;
    
    if (L->total == i) //foi até o fim e não achou
        return 0;
    else
        if (elem == L->num[i])
            return 1;
        else
            return 0;
}


void insere(lista *L, int elem){
    int existe, pos,i;
    
    existe = busca(L,elem,&pos);
    if (existe)
        printf("\n Elemento já existe!");
    else {
        for (i=L->total;i>pos;i--)
            L->num[i] = L->num[i-1];
        L->num[pos] = elem;
        L->total++;
    }
}

void removeL(lista *L, int elem){
    int existe, pos,i;
    
    existe = busca(L,elem,&pos);
    if (!existe)
        printf("\n Elemento não existe!");
    else {
        for (i=pos;i<L->total-1;i++)
            L->num[i] = L->num[i+1];
        L->total--;
    }
    
}

int main(void) {
    int elem, op;
    lista L;
    L.total = 0;

    //inserindo elementos
    printf("Digite um número: ");
    scanf("%d", &elem);
    while (elem>0) {
        insere(&L,elem);
        printf("Digite um número: ");
        scanf("%d", &elem);
    }
    mostra(L);
    do {
        printf("\n\nMENU");
        printf("\n(1) Insere");
        printf("\n(2) Remove");
        printf("\n(3) Mostra");
        printf("\n(4) FIM");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite um número para ser inserido: ");
                scanf("%d", &elem);
                insere(&L, elem);
                break;
            case 2:
                printf("Digite um número para ser removido: ");
                scanf("%d", &elem);
                removeL(&L, elem);
                break;
            case 3:
                mostra(L);
                break;
            case 4:
                printf("\n\nFIM do PROGRAMA!");
                break;
            default:
                printf("\n\nOpção inválida!");
        }
    } while (op != 4);
    
    return 0;
}