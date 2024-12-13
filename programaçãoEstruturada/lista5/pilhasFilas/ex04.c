#include <stdio.h>
#include <stdlib.h>

#define N 10

struct DEQUE{
    int elementos[N];
    int inicio, fim, total;
}; 
typedef struct DEQUE deque; 

void insere(deque *d, char pos, int elemento){
    if ((pos == 'F') || (pos == 'f')){//insere no final
        if (d->total < N){
            d->elementos[d->fim] = elemento;
            d->fim++;
            d->fim = d->fim % N;
            d->total++;
        }else
            printf("Lista Cheia Impossivel Adicionar no Final!\n");
    }else if ((pos == 'I') || (pos == 'i')){//insere no inicio
        if (d->total < N){
            d->inicio = (d->inicio - 1 + N)%N;
            d->elementos[d->inicio] = elemento;
            d->total++;
        }else
            printf("Lista Cheia Impossivel Adicionar no Inicio!\n");
    }else
        printf("OPCAO INVALIDA!\n");
}

int remover(deque *d, char pos){
    int num;
    if ((pos == 'F') || (pos == 'f')){
        if (d->total > 0){
            num = d->fim;
            d->fim--;
            d->fim = d->fim % N;
            d->total--;
            return num;
        }else{
            printf("Lista Vazia! Impossivel Remover no Final!\n");
            return -1;
        }
    }else if ((pos == 'I')||(pos == 'i')){
        if (d->total>0){
            num = d->inicio;
            d->inicio++;
            d->inicio = d->inicio % N; //manter circular
            d->total--;
            return num;
        }else{
            printf("Lista Vazia! Impossivel Remover no Inicio!\n");
            return -1;
        }
    }
    printf("OPCAO INVALIDA!\n");
    return -1;
}

void printa(deque *d){
    int i;
    for (i=0; i<d->total; i++)
        printf("%d\t", d->elementos[(d->inicio+i)%N]);
}


int main(void){
    deque d;
    char pos;
    int n;
    d.inicio = 0;
    d.fim = 0;
    d.total = 0;
    //chamando inserir
    printf("Digite um Valor para Inserir: ");
    scanf("%d", &n);
    while (n>0){
        printf("Digite...\n[I] Para Inserir no Inicio;\n[F] Para Inserir no Final: ");
        scanf(" %c", &pos);
        insere(&d,pos,n);
        printf("Digite um Valor para Inserir: ");
        scanf("%d", &n);
    }
    printf("\nDeque apos Insercao: ");
    printa(&d);

    //chamando remover
    printf("\nDigite...\n[I] Para Remover um Valor no Inicio;\n[F] Para Remover no Final: ");
    scanf(" %c", &pos);
    while ((pos=='i')||(pos=='I')||(pos=='F')||(pos=='f')){
        remover(&d,pos);
        printf("Digite...\n[I] Para Remover no Inicio;\n[F] Para Remover no Final: ");
        scanf(" %c", &pos);
    }

    printf("\nDeque apos Remocao: ");
    printa(&d);
    return 0;
}