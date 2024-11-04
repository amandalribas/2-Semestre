#include <stdio.h>

int main(void){
    int N, QPares = 0, QImpares = 0, MPares = 0, SImpares = 0;
    printf("Digite um Valor: ");
    scanf("%d", &N);
    while (N != 0){
        if (N % 2 == 0){
            QPares++;
            MPares += N; 
        }else{
            QImpares++;
        }


        printf("Digite um Valor: ");
        scanf("%d", &N);
    }
    MPares = MPares / QPares;
    return 0;
}