#include <stdio.h>

int main(void){
    float eleitores, brancos, nulos, validos, b, n, v;
    printf("Total de Eleitores: ");
    scanf("%f", &eleitores);

    printf("Brancos, Nulos e Validos: ");
    scanf("%f %f %f", &brancos, &nulos, &validos);

    b = (brancos / eleitores) * 100;
    n = (nulos / eleitores) * 100;
    v = (validos / eleitores) * 100;

    printf("%.2f%% representam os votos Brancos; \n%.2f%% representam os votos Nulos; \n%2.f%% representam os votos validos.", b, n, v);

    return 0;
}   