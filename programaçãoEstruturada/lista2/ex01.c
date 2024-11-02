#include <stdio.h>

int main(void){
    int i=1, caixa, total=0;
    for (i=1; i<=25; i++){
        printf("Peso da caixa %d: ",i);
        scanf("%d", &caixa);
        total += caixa;
    }
    printf("Total das 25 caixas eh de: %d.", total);

    return 0;
}