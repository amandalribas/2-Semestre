#include <stdio.h>

int main(void){
    int valor, div1, div2, div3, div4;
    printf("Digite um valor: ");
    scanf("%d", &valor);

    div1 = valor / 100;
    div2 = valor % 100;
    div3 = div1 + div2;
    div4 = div3 * div3;

    if (div4 == valor)
        printf("O valor %d obdece a regra.", valor);
    else
        printf("O valor %d nao obdece a regra.", valor);

    return 0;
}