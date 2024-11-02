#include <stdio.h>

int main(void){
    int A, B, i, total = 0;
    printf("Digite os Valores de A e B: ");
    scanf("%d %d", &A, &B);

    if (A<B){
        for (i=++A; i<B; i++)
            total += i;
        printf("Total de %d.", total);
    }else{
        printf("Soma Impossivel, B eh menor que A.");
        return 1;
    }

    return 0;
}