#include <stdio.h>

int main(void){
    float lado1, lado2, lado3;
    printf("Digite os valores reais do lado do triangulo: ");
    scanf("%f %f %f", &lado1, &lado2, &lado3);

    if ((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3 ) && (lado3 < lado2 + lado1)){
        if (lado1 == lado2 && lado2 == lado3)
            printf("Triangulo Equilatero");
        else
            if ((lado1 == lado2 && lado1 != lado3) || (lado2 == lado3 && lado3 != lado1) || (lado1 == lado3 && lado3 != lado2))
                printf("Triangulo Isosceles");
            else
                printf("Triangulo Escaleno.");
    }else
        printf("Nao eh triangulo.");
    return 0;
}