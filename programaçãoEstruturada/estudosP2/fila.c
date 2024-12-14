#include <stdio.h>
#include <stdlib.h>

// insert {insere no comeco se fila vazia, se nao, insere no final};
// remove {tira sempre do comeco da fila};

struct FILA{
    int *elemento;
    int inicio, fim;
};
typedef struct FILA fila;

void insert(fila *f, int n){
    f->fim++;
    f->elemento = realloc(f->elemento, (f->fim+1) * sizeof(int));
    f->elemento[f->fim] = n;
}

int remover(fila *f){
    int num;
    if ((f->fim)>0){
        f->inicio++;
        num = f->elemento[f->inicio];
        return num;
    }
    return -1;
}

void printa(fila *f){
    int i;
    for (i=f->inicio;i<=f->fim;i++)
        printf("%d\t", f->elemento[i]);
}

int main(void){
    fila f;
    int i, num, n;
    f.elemento = NULL;
    f.inicio = 0;
    f.fim = 0;

    printf("Digite um Inteiro para Inserir na Fila: ");
    scanf("%d", &num);
    while (num > 0){
        insert(&f, num);
        printf("Digite um Inteiro para Inserir na Fila: ");
        scanf("%d", &num);
    }
    printf("Quantos Digitos deseja remover da Fila? ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        num = remover(&f);
        printf("%d Removido!\n", num);
    }
    f.inicio++;

    printa(&f);

    free(f.elemento);
    return 0;
}