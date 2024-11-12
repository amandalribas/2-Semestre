#include <stdio.h>

struct tipoFuncionario{
    float salarioInicial,vendas,salarioFinal;
};
typedef struct tipoFuncionario tFuncionario;

int main(void){
    int i, N;
    printf("Quantidade de Funcionarios: ");
    scanf("%d", &N);
    tFuncionario funcionario[N];
    for (i=0;i<N;i++){
        printf("%do. Salario Inicial: R$",i+1);
        scanf("%f", &funcionario[i].salarioInicial);
        printf("%da. Qnt. de Vendas: R$", i+1);
        scanf("%f", &funcionario[i].vendas);
        funcionario[i].salarioFinal = funcionario[i].salarioInicial + (0.06 *funcionario[i].vendas);
        printf("Salario Final: R$%.2f\n", funcionario[i].salarioFinal);
    }
    return 0;

}