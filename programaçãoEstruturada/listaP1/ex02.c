#include <stdio.h>

struct tipoGinasta{
    char nome[40];
    float media;
};
typedef struct tipoGinasta tGinasta;

float calculaMedia(float *n){
    int i;
    float maior=-1, menor=11, m=0;
    for(i=0;i<6;i++){
        if (n[i] < menor)
            menor = n[i];
        if(n[i] > maior)
            maior = n[i];
    }
    for(i=0;i<6;i++){
        if (n[i]!= menor && n[i]!= maior)
            m += n[i];
    }
    return m/4;
}

void printa(tGinasta *n){
    int i;
    for (i=0;i<3;i++){
        printf("\n%s MEDIA = %.2f", n[i].nome,n[i].media);
    }
}

int main(void){
    tGinasta ginastas[3];
    float notas[6];
    int i;
    for (i=0;i<3;i++){
        printf("NOME DO GINASTA: ");
        scanf(" %[^\n]s", ginastas[i].nome);
        printf("NOTAS DE %s: ",ginastas[i].nome);
        scanf("%f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5]);
        ginastas[i].media = calculaMedia(notas);
    }
    printa(ginastas);
    return 0;
}