#include <stdio.h>

int serie(int i, int j,int k){
    if (j>=i){
        printf("%d\t", i);
        return serie(i+k,j,k);
    }
}


int main(void){
    int i,j,k;
    printf("Digite I e J: ");
    scanf("%d %d", &i, &j);
    printf("Digite o Intervalo K:");
    scanf("%d", &k);
    serie(i,j,k);
    return 0;
}