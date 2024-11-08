#include <stdio.h>

int main(void){
    int i;
    float N, E = 0;

    printf("DIGITE UM NUMERO: ");
    scanf("%f", &N);
    for (i = 0; i<N; i++)
        E += 1 /(N-i);
    printf("E = %.2f", E);
    return 0;
}