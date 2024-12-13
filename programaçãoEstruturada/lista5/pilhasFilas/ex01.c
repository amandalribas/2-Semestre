#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct PILHA{
    int *elementos;
    int topo;
};
typedef struct PILHA pilha;

void printa(pilha *p){
    int i;
    for (i=p->topo; i>=0;i--)
        printf("%d\t",p->elementos[i]);
}

int main(void){
    pilha p;
    int n,i;
    p.topo = -1;

    printf("Quantidade de Elementos na PILHA: ");
    scanf("%d", &n);
    p.elementos = (int*)malloc(n*(sizeof(int)));
    srand(time(NULL));
    for (i=0;i<n;i++){
        p.elementos[i] = rand() % 100;
        p.topo++;
    }
    printa(&p);
    free(p.elementos);
    return 0;
}