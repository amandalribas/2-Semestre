
#include <stdio.h>

int main(void){
    int N, a1, r, i;
    printf("Quantidade N Termos: ");
    scanf("%d", &N);
    printf("A1 e Razao: ");
    scanf("%d %d", &a1, &r);
    
    for (i = 0; i<N; i++){
        printf("%d \t", a1);
        a1 += r;
    }
    return 0;
