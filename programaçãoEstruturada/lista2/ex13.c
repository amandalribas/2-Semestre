#include <stdio.h>
#include <string.h>

int main(void){
    char produto[100], prodmaior[100];
    float preco, precomaior = 0.0;

    do{
        printf("DIGITE O NOME DO PRODUTO: ");
        scanf("%s", produto);
        if (strcmp(produto,"XXX")){
            printf("DIGITE O PRECO DE %s: ", &produto);
            scanf("%f", &preco);
            if (preco >= precomaior){
                strcpy(prodmaior,produto);
                precomaior = preco;
            }
        }
    }while(strcmp(produto,"XXX"));

    printf("PRODUTO MAIS CARO: %s por R$%.2f", prodmaior, precomaior);

    return 0;
}