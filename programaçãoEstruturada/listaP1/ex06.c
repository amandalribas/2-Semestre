#include <stdio.h>

int caracteres(char*frase){
    if (*frase!='\0')
        return 1 + caracteres(frase+1);
    return 0;
}

/*int caracteres(char *frase, int val){
    if (frase[val]!='\0')
        return caracteres(frase,val+1);
    return val;
}*/

int main(void){
    char frase[100];
    int len;
    printf("Digite a STRING: ");
    scanf(" %[^\n]s", frase);
    len = caracteres(frase);
    printf("Tamanho da STRING: %d",len);
    return 0;
}