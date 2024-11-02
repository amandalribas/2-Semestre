#include <stdio.h>

int main(void){
    char nome[100];
    float kW, preco, custo;

    printf("Nome:");
    scanf("%s", nome);
    
    printf("Quantidade de quilowatts mensais: ");
    scanf("%f", &kW);

    printf("Preco por QuiloWatts: ");
    scanf("%f", &preco);

    custo = kW * preco;
    printf("Custo da conta de %s sera de R$%.2f.", nome, custo);

    return 0;
}