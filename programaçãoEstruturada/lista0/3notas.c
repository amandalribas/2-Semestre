#include <stdio.h>

int main(void){
    float nota1, nota2, nota3, media;
    printf("Nota 1: ");
    scanf("%f",&nota1);

    printf("Nota 2: ");
    scanf("%f", &nota2);

    printf("Nota 3: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("A media entre %.2f, %.2f, %.2f eh de %.2f", nota1, nota2, nota3, media);

    return 0;
}