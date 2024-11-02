#include <stdio.h>

int main(void){
    float saldo, imposto;
    printf("Digite o seu saldo: ");
    scanf("%f", &saldo);
    if (saldo<100)
        imposto = 0;
    else if (saldo < 1000)
        imposto = 0.01 * saldo;
    else if (saldo<10000)
        imposto = 0.02 * saldo;
    else if (saldo < 100000)
        imposto = 0.03 * saldo;
    else
        imposto = 0.05 * saldo;
    
    
    if (imposto != 0)
        printf("O ISSS devido eh de R$%.2f", imposto);
    else
        printf("Insento de Imposto");



    return 0;
}