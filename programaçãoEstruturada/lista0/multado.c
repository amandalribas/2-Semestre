#include <stdio.h>

int main(void){
    float salario, multa1, multa2, restante;
    printf("Salario de Joao: ");
    scanf("%f", &salario);
    printf("Valor da Primeira Multa: ");
    scanf("%f", &multa1);
    printf("Valor da Segunda Multa: ");
    scanf("%f", &multa2);

    restante = salario - ((multa1*1.02) + (multa2*1.02));
    printf("O valor restante do salario de João é de R$ %.2f", restante);

}