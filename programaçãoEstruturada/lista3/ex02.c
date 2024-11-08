#include <stdio.h>

void multiImpares(int *vetor){
    int i;
    for (i=0;i<10;i++){
        if (vetor[i] % 2 == 1)
            vetor[i] = vetor[i] * 3;
    }
}

void divPares(int *vetor){
    int i;
    for (i=0;i<10;i++){
        if (vetor[i] % 2 == 0)
            vetor[i] = vetor[i]/2;
    }
}

void printaVetor(int *vetor){
    int i;
    for (i=0;i<10;i++){
        printf("%d \t", vetor[i]);
    }
}

int main(void){
    int num[10];
    int i;
    for (i=0;i<10;i++){
        printf("Digite o %do. Valor: ", i+1);
        scanf("%d", &num[i]);
    }    
    num[10] = '\0';
    multiImpares(num);
    divPares(num);
    printaVetor(num);
    return 0;
}