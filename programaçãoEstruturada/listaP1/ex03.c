#include <stdio.h>
#include <string.h>

int main(void){
    char frase[100], palavra[20];
    int i, cont = 0;
    printf("Digite a PALAVRA:");
    scanf("%s", palavra);
    printf("Digite a FRASE: ");
    scanf(" %[^\n]s", frase);

    for (i=0;i<strlen(frase);i++){
        if (palavra[cont] == frase[i])
            cont++;
    }
    if (cont == strlen(palavra))
        printf("A palavra %s esta dentro da Frase.", palavra);
    else
        printf("A palavra %s NAO esta dentro da Frase. ", palavra);
    return 0;
}