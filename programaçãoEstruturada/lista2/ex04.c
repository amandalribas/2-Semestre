#include <stdio.h>

int main(void){
    int A, B, i, total=0;
    printf("Digite A e B: ");
    scanf("%d %d", &A, &B);

    if (A<B){
        for (i=++A; i < B; i++){
            if (i%4 == 0)
                total += i;
        }
        printf("SOMA = %d", total);
    }else{
        printf("Soma IMPOSSIVEL, pois A > B.");
        return 1;
    }


    return 0;
}