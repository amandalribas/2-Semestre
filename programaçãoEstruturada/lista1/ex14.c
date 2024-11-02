#include <stdio.h>

int main(void){
    float ita, cp, taxa, taxa2;
    printf("Taxa Condominial: R$");
    scanf("%f", &taxa);

    cp = 24 * taxa + 4 * 0.01 * taxa;
    taxa2 = 1.1 * taxa;
    ita = 24 * taxa2 + 4 * 0.01 * taxa2;

    printf("Os Condominios de Camboinhas e Piratiniga pagam a Taxa de R$%.2f, totalizando R$%.2f.\nEnquanto os Condominios de Itaipu e Itacoatiara pagam a Taxa de R$%.2f, totalizando R$%.2f.",taxa,cp,taxa2,ita);


    return 0;
}