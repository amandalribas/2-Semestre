#include <stdio.h>

int main(void){
    int A, B, soma, multiplicacao, divisao, subtracao;
    printf("A = ");
    scanf("%d", &A);
    printf("B = ");
    scanf("%d", &B);
    soma = A + B;
    multiplicacao = A * B;
    divisao = A / B;
    subtracao = A - B;
    printf("%d + %d = %d \n", A, B, soma);
    printf("%d * %d = %d \n", A, B, multiplicacao);
    printf("%d / %d = %d \n", A, B, divisao);
    printf("%d - %d = %d \n", A, B, subtracao);

    return 0;
}