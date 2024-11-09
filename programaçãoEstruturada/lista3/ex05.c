#include <stdio.h>

int main(void){
    int i,j, matriz[3][5], transposta[5][3];
    for (i = 0; i<3;i++){
        for(j = 0; j<5; j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%d", &matriz[i][j]);
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz Transposta:\n");
    for (i = 0; i<5; i++){
        for (j = 0; j<3; j++){
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
    return 0;
}