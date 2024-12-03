#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int **matriz, i, j, nLinha, nColuna;
    printf("DIGITE NUMERO DE LINHAS: ");
    scanf("%d", &nLinha);
    printf("DIGITE O NUMERO DE COLUNAS: ");
    scanf("%d", &nColuna);

    matriz = malloc(nLinha * sizeof(int));
    for (i=0;i<nLinha;i++)
        matriz[i] = malloc(nColuna*sizeof(int));
    
    if (matriz){
        srand(time(NULL));
        printf("ALOCACAO REALIZADA COM SUCESSO!\n");
        for (i=0;i<nLinha;i++){
            for (j=0;j<nColuna;j++)
                matriz[i][j] = rand() % 100;
                //*(*(matriz +i)+j) = rand() % 100;

        }
        for (i=0;i<nLinha;i++){
            for (j=0;j<nColuna;j++)
                printf("%d   ", matriz[i][j]);
            printf("\n");
        }
    }else
        printf("ALOCACAO NAO REALIZADA!\n");
    
    for (i=0;i<nLinha;i++)
        free(matriz[i]);
    free(matriz);
}