#include <stdio.h>

int main(void){
    int idade;
    char sexo;
    float salario, maior = 0, mediaM = 0, mediaF = 0, iM = 0, iF = 0;

    do{
        printf("Idade: ");
        scanf("%d", &idade);
        if (idade > 0){
            printf("Sexo [M/F]: ");
            scanf(" %c", sexo);

            printf("Salario: ");
            scanf("%f", &salario);

            if (idade < 30 && salario > maior)
                maior = salario;

            if (sexo == 'M'){
                mediaM += salario;
                iM++;
            }else{
                mediaF += salario;
                iF++;
            }
        }
    }while (idade > 0);
    printf("Maior Salario Abaixo de 30 Anos: R$%.2f\nMedia Salarial Feminina: R$%.2f\nMedia Salarial Masculina: R$%.2f", maior, mediaF/iF,mediaM/iM);
    return 0;
}
