#include <stdio.h>

int main(void){
    int val;

    printf("Digite um valor: ");
    scanf("%d", &val);

    if (val % 2 == 0)
        printf("%d eh par.", val);
    else
        printf("%d eh impar.", val);

    return 0;
}