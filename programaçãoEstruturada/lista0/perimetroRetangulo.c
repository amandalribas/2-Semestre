#include <stdio.h>

int main(void){
    float base, altura, perimetro;
    printf("Digite a Largura: ");
    scanf("%f", &base);
    printf("Digite a Altura: ");
    scanf("%f", &altura);
    perimetro = (base*2) + (altura*2);
    printf("Perimetro: %.2f", perimetro);
    
    return 0;
}
