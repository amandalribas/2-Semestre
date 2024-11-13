#include <stdio.h>


int divisao(int X,int Y){
    if (X > Y)
        return 1 + divisao(X-Y,Y);
    return 0;

}

int main(void){
    int A,B, C;
    printf("DIGITE 2 VALORES: ");
    scanf("%d %d", &A, &B);
    C = divisao(A,B);
    printf("%d / %d = %d", A, B, C);
    return 0;
}


/*int divisao(int X,int Y,int val){
    if (X > Y)
        return divisao(X-Y,Y,val+1);
    return val;

}

int main(void){
    int A,B, C = 0;
    printf("DIGITE 2 VALORES: ");
    scanf("%d %d", &A, &B);
    C = divisao(A,B, C);
    printf("%d / %d = %d", A, B, C);
    return 0;
}*/

