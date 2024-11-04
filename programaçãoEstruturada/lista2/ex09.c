#include <stdio.h>

int main(void){
    int K, i, a1 = 0, a2 = 1, aux;
    printf("Digite o valor de K: ");
    scanf("%d", &K);

    if (K > a1){
        for (i = 0; i<K; i++){
            aux = a1;
            a1 = a2;
            a2 = aux + a1;
            if (a1 < K && a1 > 0)
                printf("%d \t", a1);
        }
    }else
        printf("IMPOSSIVEL! K < 0!");
    return 0;
}