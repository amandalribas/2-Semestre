#include <stdio.h>

int main(void){
    float salario, vendas, total;

    printf("Salario Inicial: ");
    scanf("%f", &salario);
    printf("Vendas Totais: ");
    scanf("%f", &vendas);
    total = vendas*0.04 + salario;
    printf("O salario total eh de: R$%.2f.", total);

    return 0;
}