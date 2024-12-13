#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct PILHA{
    int *elementos;
    int topo;
};
typedef struct PILHA pilha;

void parImpar(pilha *p, pilha *impar, pilha *par){
    int i;
    for (i=0;i<p->topo;i++){
        if (p->elementos[i]%2 == 0){
            par->topo++;
            par->elementos = realloc(par->elementos, (par->topo+1)*sizeof(int));
            par->elementos[par->topo] = p->elementos[i];
        } else{
            impar->topo++;
            impar->elementos = realloc(impar->elementos,(impar->topo+1)*sizeof(int));
            impar->elementos[impar->topo] = p->elementos[i];
        }
    }
}


void printa(pilha *p){
    int i;
    for (i=p->topo; i>=0;i--)
        printf("%d\t",p->elementos[i]);
}


int main(void){
    pilha p, impar, par;
    int i, n;
    p.topo = -1;
    par.topo = -1;
    impar.topo = -1;

    par.elementos = NULL;
    impar.elementos = NULL;

    printf("Quantidade de Elementos na Pilha: ");
    scanf("%d", &n);
    p.elementos = (int*)malloc(n*sizeof(int));

    srand(time(NULL));
    for (i=0;i<n;i++){
        p.elementos[i] = rand()%100;
        p.topo++;
    }
    printf("\nLISTA ORIGINAL:");
    printa(&p);

    parImpar(&p,&impar,&par);
    printf("\nPAR: ");
    printa(&par);
    printf("\nIMPAR: ");
    printa(&impar);


    free(p.elementos);
    free(par.elementos);
    free(impar.elementos);
    return 0;
}