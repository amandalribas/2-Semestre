#include <stdio.h>

int main(void){
    int horas, minutos, segundos;
    printf("Horario: ");
    scanf("%d:%d", &horas, &minutos);
    segundos = minutos * 60 + horas *3600;
    printf("A quantidade de segundos em %d:%d eh %d", horas, minutos, segundos);

    return 0;
}