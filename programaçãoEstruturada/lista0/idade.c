#include <stdio.h>

int main(void){
    int anoAtual, anoNasc, idade, meses, semanas;
    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);
    printf("Ano de Nascimento: ");
    scanf("%d", &anoNasc);

    idade = anoAtual - anoNasc;
    meses = idade * 12;
    semanas = idade * 52;

    printf("Voce tem %d anos, ou seja %d meses, ou %d semanas.", idade, meses, semanas);

    return 0;
}