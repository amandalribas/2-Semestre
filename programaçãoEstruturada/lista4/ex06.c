#include <stdio.h>
#include <stdlib.h>

struct dma{
    int dia, mes, ano;
};
typedef struct dma tDMA;

int ehBissexto(int ano){
    if ((ano%4 == 0 && ano%100!=100)||(ano%400==100))
        return 366;
    return 365;
}

int contaDias(int dia, int mes,int ano){
    int i, dias = 0;
    int mesesN[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int mesesB[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    for (i=0;i<ano;i++){
        dias += ehBissexto(i);
    }
    if (ehBissexto(ano)==365){
        for (i=1;i<mes;i++)
            dias += mesesN[i];
    }
    else{
        for(i=1;i<mes;i++)
            dias+= mesesB[i];
    }
    dias += dia;
    return dias;
}


int main(void){
    tDMA dia1, dia2;
    int cDia1, cDia2, dif;
    printf("DIA 1(dd/mm/aa):");
    scanf("%d/%d/%d", &dia1.dia, &dia1.mes, &dia1.ano);
    printf("DIA 2(dd/mm/aa):");
    scanf("%d/%d/%d", &dia2.dia, &dia2.mes, &dia2.ano);
    cDia1 = contaDias(dia1.dia,dia1.mes,dia1.ano);
    cDia2 = contaDias(dia2.dia,dia2.mes,dia2.ano);
    dif = abs(cDia1-cDia2);
    printf("A Diferenca de Dias Decorridos eh: %d", dif);

    return 0;
}