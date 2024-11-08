#include <stdio.h>

int main(void){
    int N = 1, QPares = 0, QImpares = 0, SPares = 0, SImpares = 0, MPares, div = 0;
    printf("Digite um Valor: ");
    scanf("%d", &N);
    
    do{
        printf("Digite um Valor: ");
        scanf("%d", &N);
        if (N!= 0){
            if (N % 2 == 0){
                QPares++;
                SPares += N; 
            }else{
                QImpares++;
                SImpares += N;
            }}
    
    }while (N != 0);
    
    MPares = SPares / QPares;
    div = SPares / SImpares;

    printf("Quantidade de Pares:  %d\nQuantidade de Impares: %d\nMedia de Pares: %d\nSomatorio Dividido: %d",QPares,QImpares, MPares,div);

    return 0;

