#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10


struct FILA{
    int elementos[MAX];
    int inicio,fim,total;
};
typedef struct FILA fila;

void insert(fila *f, int n){
    if (f->total < MAX){
        f->elementos[f->fim] = n; 
        f->fim++;
        f->fim = f->fim%MAX;
        f->total++; 
   }
}

void printa(fila *f){
    int i;
    for (i=0; i<f->total; i++)
        printf("%d\t", f->elementos[(f->inicio+i)%MAX]);
}


int main(void){
    fila f;
    int i, num;
    f.inicio = 0;
    f.fim = 0;
    f.total = 0;


    srand(time(NULL));
    for (i=0;i<MAX;i++){
        num = rand() % 100;
        insert(&f,num);
    }
    printf("\nMATRIZ PADRAO:\n");
    printa(&f);
    if (f.elementos[f.inicio] % 2 == 0)
        printf("\n%d eh par!", f.elementos[f.inicio]);
    else
        printf("\n%d eh impar!", f.elementos[f.inicio]);
    return 0;
}