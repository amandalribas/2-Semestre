#include <stdio.h>

int main(void){
    float celsius, farenheit;
    printf("Temperatura em Celsius: ");
    scanf("%f", &celsius);
    farenheit = 1.8*celsius + 32;
    printf("%.1f o.C = %.1f F", celsius, farenheit) ;


    return 0;
}