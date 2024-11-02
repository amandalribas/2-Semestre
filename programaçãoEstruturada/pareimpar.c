#include <stdio.h>

int main(void){
    int num, impar = 0, par = 0;
    printf("Digite um valor: ");
    scanf("%d", &num);
    while (num != 0){
        if (num % 2 == 0)
            par++;
        else
            impar++;
        printf("Digite um valor: ");
        scanf("%d", &num);
    }
    printf("%d Valores impares \n%d Valores Pares", impar, par);
    return 0;
}