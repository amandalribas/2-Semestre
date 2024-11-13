#include <stdio.h>

int main(void){
    int i, N, maior = 0, menor = 100000, estoque, media = 0;
    printf("Digite a Quantidade de DIAS: ");
    scanf("%d", &N);
    for (i=0;i<N;i++){
        printf("Digite o %do. DIA do Estoque: ", i+1);
        scanf("%d", &estoque);
        media += estoque;
        if (estoque > maior)
            maior = estoque;
        if (estoque < menor)
            menor = estoque;
    }
    media /= N;
    printf("\nMAIOR ESTOQUE: %d", maior);
    printf("\nMENOR ESTOQUE: %d", menor);
    printf("\nMEDIA DE ESTOQUE: %d", media);
    return 0;
}