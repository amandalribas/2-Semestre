#include <stdio.h>

int main(void){
    int h1, h2;
    float val1, val2, sal1, sal2;

    printf("Quantidade de Horas e Preco por Hora do Professor 1: ");
    scanf("%d %f", &h1, &val1);
    sal1 = h1 * val1;

    printf("Quantidade de Holras e Preco por Hora do Professor 2: ");
    scanf("%d %f", &h2, &val2);
    sal2 = h2 * val2;

    if (sal1 > sal2)
        printf("O Primeiro professor recebe mais, com um total de R$%.2f.", sal1);
    else if (sal2 > sal1)
        printf("O Segundo professor recebe mais, com um total de R$%.2f.", sal2);
    else
        printf("Ambos recebem o mesmo salario de R$%.2f", sal1);


    return 0;
}