#include <stdio.h>

int main(void){
    float min, salario, dif;
    printf("Salario Minimo Atual: ");
    scanf("%f", &min);
    printf("Salario do Usuario: ");
    scanf("%f", &salario);
    dif = salario / min;
    printf("Recebe %.1f salarios minimos.", dif);


    return 0;
}