#include <stdio.h>

int main(void){
    int ih, im, is, ch, cm, cs, fh, fm, fs;
    printf("Horario de IDA: ");
    scanf("%d:%d:%d", &ih, &im, &is);

    printf("Horario de CHEGADA: ");
    scanf("%d:%d:%d", &ch, &cm, &cs);

    if (cm < im) //minutos
        fm = (60-im)+cm;
    else
        fm = cm - im;

    if (cs <is)//segundos
        fs = 60-is+cs;
    else
        fs = cs-is;
    
    if (fm && fs != 0)//hora
        fh = ch - ih -1;
    else
        fh = ch - ih;
    printf("Tempo de Viagem: %d:%d:%d", fh, fm, fs);
    return 0;
}