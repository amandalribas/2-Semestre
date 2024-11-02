#include <stdio.h>


int main(void){
    int A, B, aux;
    printf("A = ");
    scanf("%d", &A);
    printf("B = ");
    scanf("%d", &B);
    printf("A = %d B = %d \n", A, B);

    aux = B;
    B = A;
    A = aux;
    
    printf("A = %d B = %d", A, B);
    return 0;
}