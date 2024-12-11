#include <stdio.h>
#include <stdlib.h>

// insere no topo, remove do topo

struct PILHA{
    int *elemento;
    int topo;
};
typedef struct PILHA pilha;

void push(pilha *p, int num){
    p->topo++;
    p->elemento = realloc(p->elemento, (p->topo+1) * sizeof(int));
    p->elemento[p->topo] = num;
}

int pull(pilha *p){
    int num;
    if (p != NULL){
        num = p->elemento[p->topo];
        p->topo--;
        return num;
    }
    return -1;
}

//ex 1 lista 5
void printa(pilha *p){
    int i;
    for (i=p->topo; i>=0;i--)
        printf("%d\t",p->elemento[i]);
}

//ex 2 lista 5
int main(void){
    pilha p;
    int i, n, num;
    p.topo = -1;
    p.elemento = NULL;

    /*if (p.elemento == NULL){
        printf("Erro ao Alocar Memoria");
        return 1;
    }*/
        
    printf("Digite Um Valor a ser adicionado a Pilha: ");
    scanf("%d", &n);
    while (n > 0){
        push(&p,n);
        printf("Digite Um Valor a ser adicionado a Pilha: ");
        scanf("%d", &n);
    }
    printf("Quantos Valores Quer Remover do topo?");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        num = pull(&p);
        printf("%d REMOVIDO!\n", num);
    }

    printf("PRINTANDO PILHA:\n"); //ex01 lista5
    printa(&p);



    free(p.elemento);

    return 0;
}