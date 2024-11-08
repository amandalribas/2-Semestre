#include <stdio.h>

int main(void){
    int total = 0, entradaH, entradaM, saidaH, saidaM, tempoH, tempoM, i = 0;
    for (i=0; i<3; i++){
        printf("Hora de Entrada: ");
        scanf("%d:%d", &entradaH, &entradaM);
        printf("Hora de Saida: ");
        scanf("%d:%d", &saidaH, &saidaM);
        tempoH = entradaH - saidaH;
        tempoM = entradaM - saidaM;
        if (tempoH >= 2 && tempoM != 0)
            total += 4 + 1 *(tempoH - 2) + 1;
        else if (tempoH > 2 && tempoM == 0)
            total += 4 + 1 * (tempoH-2);
        else
            total += 4;
    }
    printf("TOTAL = R$ %d", total);
    return 0;
