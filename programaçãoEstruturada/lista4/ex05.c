#include <stdio.h>

struct tipoPessoa{
    float altura;
    int idade;
    char olhos[2];
};
typedef struct tipoPessoa tPessoa;

int main(void){
    tPessoa pessoa[5];
    int i, castanhosVelhos = 0;
    float mediaIdade = 0, maiorAltura = 0, menorAltura= 10000;
    for (i=0;i<5;i++){
        printf("%da. Altura: ",i+1);
        scanf("%f", &pessoa[i].altura);
        printf("%da. Idade: ",i+1);
        scanf("%d", &pessoa[i].idade);
        printf("%da. Cor Dos Olhos ([A] - Azul, [C] - Castanho, [V] - Verde):",i+1);
        scanf(" %c", &pessoa[i].olhos[0]);
        mediaIdade += pessoa[i].idade;
        if (pessoa[i].altura < menorAltura)
            menorAltura = pessoa[i].altura;
        if (pessoa[i].altura > maiorAltura)
            maiorAltura = pessoa[i].altura;
    }
    mediaIdade = (mediaIdade*1.0)/5;
    for(i=0;i<5;i++){
        if (pessoa[i].idade>mediaIdade && pessoa[i].olhos[0] == 'C')
            castanhosVelhos++;
    }

    printf("Media de Idade: %.1f\nMaior Altura: %.2f\nMenor Altura: %.2f\nQuantidade de Pessoas Acima da Media de Idade com os Olhos Castanhos: %d", mediaIdade, maiorAltura, menorAltura, castanhosVelhos);
    return 0;   
}