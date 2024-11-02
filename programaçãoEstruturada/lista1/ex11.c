#include <stdio.h>

int main(void){
    float min, venda, salario;
    int func;

    printf("Digite o Numero de Empregados, o valor do Salario Minimo e as Vendas do mes:");
    scanf("%d %f %f", &func, &min, &venda);

    salario = ((venda * 0.05)/func) + 2*min;
    printf("O valor de cada salario eh de R$%.2f.", salario);
    return 0;
}