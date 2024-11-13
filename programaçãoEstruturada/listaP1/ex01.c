#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverso(int num){
    char numChar[7],i;
    int len;
    sprintf(numChar,"%d",num );
    len = strlen(numChar);
    for(i=0;i<len/2 ;i++){
        if (numChar[i] != numChar[len-1-i])
            return 0;
    }
    return 1;
}

int main(void){
    int n = 0;
    do{
        printf("Digite um Valor: ");
        scanf("%d", &n);
        if (inverso(n))
            printf("%d PALINDROMO!\n", n);
        else
            printf("%d NAO PALINDROMO!\n", n);
    }while (n>0);
}