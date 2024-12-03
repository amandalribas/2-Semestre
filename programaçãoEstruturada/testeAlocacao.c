#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int tam,i;
    int *p;
    int *vetor;
    //
    p = malloc(sizeof(int)); //aloca memoria;retorna NULL se nao conseguiu;
    if (p)
        printf("MEMORIA ALOCADA COM SUCESSO!\n");
    else
        printf("ERRO AO ALOCAR!\n");

    
    //alocacao de memoria em vetores;
    printf("DIGITE O TAMANHO DO VETOR: ");
    scanf("%d", &tam);
    
    vetor = malloc(tam * sizeof(malloc));
    if (vetor){
        printf("MEMORIA ALOCADA COM SUCESSO! (VETOR)!\n");
        srand(time(NULL));
        for (i=0;i<tam;i++){
            vetor[i] = rand() % 100;
        }
        for (i=0;i<tam;i++){
            printf("%d\t", vetor[i]);
        }
        //realocacao de memoria;
        printf("\nDIGITE O NOVO TAMANHO DO VETOR: ");
        scanf("%d", &tam);
        //vetor = realloc(vetor, tamanho)
        printf("NOVO VETOR: \n");
        vetor = realloc(vetor, tam);
        for (i=0;i<tam;i++){
            printf("%d\t", vetor[i]);
        }
        free(vetor); //free
    }else
        printf("ERRO AO ALOCAR!\n");
    


}