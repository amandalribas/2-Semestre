#include <stdio.h>

int main(void){
    float larg, comp, total = 0;
    do{
        printf("Digite a Largura e Comprimento: ");
        scanf("%f %f", &larg, &comp);
        total += larg * comp;
    }while (larg != 0 && comp != 0);

    printf("Area Total da casa eh de %.2f", total);
    return 0;
}