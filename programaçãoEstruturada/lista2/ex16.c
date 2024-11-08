#include <stdio.h>

int main(void){
    int N, E = 0, e, i, j;
    printf("Digite um Valor: ");
    scanf("%d", &N);
    for (i = 1; i<=N; i++){
        e = 1;
        for (j = 1; j<=i ;j++)
            e *= 2;
        E += e;
    }
    printf("E = %d", E);
    return 0;
}
