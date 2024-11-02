#include <stdio.h>

int main(void){
    float salario, descontado;
    printf("Salario: ");
    scanf("%f", &salario);

    descontado = salario * 0.9;
    printf("O salario inicialmente de R$ %.2f, descontado 10 porcento sera de: R$ %.2f", salario, descontado);


    return 0;
}