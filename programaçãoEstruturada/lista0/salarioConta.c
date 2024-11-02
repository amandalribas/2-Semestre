#include <stdio.h>

int main(void){
    float salario, kW, total;

    printf("Salario minimo atual: ");
    scanf("%f", &salario);

    printf("Total de QuiloWatts utilizados durante o mes: ");
    scanf("%f", &kW);

    total = (0.1*salario) * kW;
    printf("Sua conta de Luz Sera de R$ %.2f.", total);
    return 0;

}