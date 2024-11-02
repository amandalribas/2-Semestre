#include <stdio.h>

int main(void){
    int i=1, quant, preco, total=0;
    for (i=1;i<=50;i++){
        printf("Quantidade e Preco do Produto %d: ", i);
        scanf("%d %d", &quant, &preco);
        total += quant*preco;
    }
    printf("O total eh de R$:%d.");
    return 0;
}