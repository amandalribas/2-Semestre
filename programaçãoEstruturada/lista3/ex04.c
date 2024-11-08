#include <stdio.h>

int main(void){
    int i, N, val, resp = 0, a1 = 0, a2 = 1, aux;
    printf("Quantos Termos de Fibonacci? ");
    scanf("%d", &N);
    printf("Qual Numero Quer saber se esta na Sequencia? ");
    scanf("%d", &val);
    if (val==a1 || val==a2)
        resp = 1;
    else{
        for (i=0;i<N;i++){
            aux = a2;
            a2 = aux + a1;
            a1 = aux;
            if (val == aux)
                resp = 1;
        }
    }
    if (resp)
        printf("O numero %d esta dentro de fibonnaci.", val);
    else
        printf("O numero %d nao esta dentro de fibonnaci.", val);
}
