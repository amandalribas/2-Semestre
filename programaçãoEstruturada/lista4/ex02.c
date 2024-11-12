#include <stdio.h>
#include <string.h>


struct tipoEstado{
    char sigla[2];
    int veiculo, acidente;
};
typedef struct tipoEstado tEstado;

int main(void){
    tEstado estados[5];
    char maiorCarro[3], menorAcidente[3];
    float indTransito, menorIndTransito = 10000000000;
    int i, valCarro = 0, acidentesTotal = 0;
    for (i=0;i<5;i++){
        printf("%da. Sigla: ",i+1);
        scanf("%s", estados[i].sigla);
        printf("%da. Qnt. de Veiculos: ", i+1);
        scanf("%d", &estados[i].veiculo);
        printf("%da. Qnt. de Acidentes: ",i+1);
        scanf("%d", &estados[i].acidente);
        
        if (estados[i].veiculo > valCarro){
            valCarro = estados[i].veiculo;
            strcpy(maiorCarro,estados[i].sigla);
        }

        acidentesTotal += estados[i].acidente;
        indTransito = estados[i].acidente*1.0 / estados[i].veiculo;
        if (indTransito < menorIndTransito){
            menorIndTransito = indTransito;
            strcpy(menorAcidente,estados[i].sigla);
        }
    }
    printf("\nEstado Com Maior Numero de Carros: %s\nEstado com Menos Acidentes: %s\nTotal de Acidentes: %d",maiorCarro,menorAcidente,acidentesTotal);

    return 0;
}