#include <stdio.h>

int main(void){
    float prefeito1, prefeito2, prefeito3, total;
    printf("Digite a quantidade de votos de Capitao Gancho, Peter Pan e Wendy, respectivamente:: ");
    scanf("%f %f %f", &prefeito1, &prefeito2, &prefeito3);
    total = prefeito1 + prefeito2 + prefeito3;
    prefeito1 = prefeito1 / total * 100;
    prefeito2 = prefeito2 / total * 100;
    prefeito3 = prefeito3 / total * 100;

    if (prefeito1 > 50)
        printf("Capitao Gancho Eleito no 1 Turno.");
    else if (prefeito2 > 50)
        printf("Peter Pan Eleito no 1 Turno.");
    else if (prefeito3 > 50)
        printf("Wendy Eleito no 1 Turno.");
    else
        printf("Tera Segundo Turno.");
    return 0;
}