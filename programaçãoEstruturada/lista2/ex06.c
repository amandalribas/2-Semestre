#include <stdio.h>

int main(void){
    int N, i;
    do{
        printf("Digite o Valor de N: ");
        scanf("%d", &N);
    }while (!(0 < N && N < 10));
    for (i=1; i < 11; i++)
        printf("%d x %d = %d \n", N, i, N*i);
        
    return 0;
}