#include <stdio.h>
#include <stdlib.h>

void printaTabuada(int **matriz, int n, int val){
    int i;
    for (i=1;i=<n;i++)
        printf("%d", matriz[i][val]);
}

int main(void){
    int i,j,n,num;
    int **matriz;
    printf("MATRIZ QUADRADA NXN. N=");
    scanf("%d", &n);
    matriz = (int**)malloc((n+1)*sizeof(int));

    for (i=0;i<=n;i++){
        matriz[i] = (int**)malloc((n+1)*sizeof(int));
        for (j=0;j<=n;j++){
            matriz[i][j] = i*j;
        }
    }
    
    for(i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    do{
        printf("\nQual Valor quer saber a Tabuada: ");
        scanf("%d",&num);
        printaTabuada(matriz,n,num);
    }while(num>0);

    return 0;
}