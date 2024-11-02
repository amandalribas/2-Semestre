#include <stdio.h>

int main(void){
    float inicial, final;
    printf("Valor do Produto R$: ");
    scanf("%f", &inicial);
    if (inicial <= 50)
        final = inicial * 1.05;
    else
        if (inicial <= 100)
            final = inicial * 1.1;
        else
            if (inicial > 100)
                final = inicial * 1.15;
    
    if (final > 80)
        printf("O produto eh barato, custa R$%.2f.", final);
    else
        if (final < 120)
            printf("O produto eh normal, custa R$%.2f.", final);
        else
            if (final < 200)
                printf("O produto eh caro, custa R$%.2f.", final);
            else
                printf("O produto eh muito caro, custa R$%.2f", final);


    return 0;
}