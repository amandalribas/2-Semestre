#include <stdio.h>

int main(void){
    int N = 0, fat = 1, i;
    printf("DIGITE UM VALOR: ");
    scanf("%d",&N);
    for (i = N; i >= 1;i--)
        fat *=  i;
    printf("%d! =  %d", N, fat);

    return 0;
}