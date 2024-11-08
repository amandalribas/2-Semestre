#include <stdio.h>

int main(void){
    float notas[3];
    char nomes[3][20];
    int i, j;
    for (i=0;i<3;i++){
        printf("Digite o NOME: ");
        scanf("%s", nomes[i]);
        printf("Nota de %s: ", nomes[i]);
        scanf("%f", &notas[i]);
    }
    notas[3] = '\0';

    for (j=0;j<3;j++){
        if (notas[j]>= 6.0)
            printf("\nAPROVADO! %s NOTA: %.2f", nomes[j],notas[j]);
    }
    return 0;
}