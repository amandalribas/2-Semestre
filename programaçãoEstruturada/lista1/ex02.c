#include <stdio.h>

int main(void){
    int A, B, soma, sub, div = 0, mult;
    printf("Digite 2 valores: ");
    scanf("%d %d", &A, &B);
    soma = A + B;
    sub = A - B;
    mult = A * B;
    if (A == 0 || B == 0)
        printf("%d + %d = %d \n%d - %d = %d \n%d x %d = %d\n%d / %d = IMPOSSIVEL", A, B, soma, A, B, sub, A, B, mult, A, B);
    else{
        div = A / B;
        printf("%d + %d = %d \n%d - %d = %d \n%d x %d = %d\n%d / %d = %d", A, B, soma, A, B, sub, A, B, mult, A, B, div);
    }
    return 0;
}