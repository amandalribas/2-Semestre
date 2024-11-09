#include <stdio.h>

int main(void){
    int matriz[5][5], transposta[5][5],i,j, simetrica = 1, diagonalPrincipal = 0, diagonalSecundaria = 0;
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("M[%d][%d]",i,j);
            scanf("%d", &matriz[i][j]);
            transposta[j][i] = matriz[i][j];
        }
    }


    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d ", matriz[i][j]);
            if (i==j)
                diagonalPrincipal += matriz[i][j];
            if (matriz[i][j] != simetrica)
                simetrica = 0;
        }
        printf("\n");
    }
    
    for (i=0;i<5;i++){
        j = 4 - i;
        diagonalSecundaria += matriz[i][j];
    }

    if(simetrica)
        printf("A Matriz eh Simetrica!");
    else
        printf("A Matriz nao eh Simetrica!");
    printf("\nSoma da Diagonal Principal = %d", diagonalPrincipal);
    printf("\nSoma da Diagonal Secundaria = %d", diagonalSecundaria);    


    return 0;
}