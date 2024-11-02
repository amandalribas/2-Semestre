#include <stdio.h>

int main(void){
    int idade;
    char opiniao;
    float otimo = 0, bom = 0, regular = 0, pessimo = 0, media= 0, total = 0;
    printf("O = OTIMO \nB = BOM\nR = REGULAR\nP = PESSIMO\n");
    do{
        printf("Idade e Nota: ");
        scanf("%d %c", &idade, &opiniao);
        if (idade > 0){
            total++;
            media += idade;
            switch (opiniao){
            case 'O':
                otimo++;
                break;
            case 'B':
                bom++;
                break;
            case 'R':
                regular++;
                break;
            case 'P':
                pessimo++;
            }
        }
    }while (idade>0);
    printf("MEDIA DE IDADES = %.2f\n", media/total);
    printf("TOTAL: %0.f\nOTIMO: %2.f%%\nBOM: %.2f%%\nREGULAR: %.2f%%\nPESSIMO: %.2f%%", total, (otimo/total)*100,(bom/total)*100,(regular/total)*100,(pessimo/total)*100);

    return 0;
}