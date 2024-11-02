#include <stdio.h>

int main(void){
    char sexo;
    float altura, peso;
    
    
    printf("Altura: ");
    scanf("%f", &altura);

    printf("Sexo [M/F]: ");
    scanf(" %c", &sexo);

    if (sexo == 'M' || sexo == 'm')
        peso = (72.7 * altura) - 58.0;
    else if (sexo == 'F' || sexo == 'f')
        peso = (62.1 * altura) - 44.7;
    else{
        printf("Sexo invalido! \n");
        return 1;
    }
    
    printf("O peso ideal eh: %.2f", peso);
    
    return 0;
}