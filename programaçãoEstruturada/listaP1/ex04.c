#include <stdio.h>

int calculaMDC(x,y){
    if ((y <= x) && (x % y == 0))
        return y;
    else if (x < y)
        return calculaMDC(y,x);
    else 
        return calculaMDC(y,x%y);

}

int main(void){
    int val1,val2, mdc;
    printf("DIGITE O 1o. VALOR: ");
    scanf("%d", &val1);
    printf("DIGITE O 2o. VALOR: ");
    scanf("%d", &val2);
    mdc = calculaMDC(val1,val2);
    printf("O MDC ENTRE %d e %d = %d", val1,val2,mdc);
}