#include <stdio.h>

int main(void){
    int N, i, acima = 0;
    float salarios[N], media;
    printf("Quantos Funcionarios? ");
    scanf("%d", &N);
    for (i = 0; i<N;i++){ //Lendo Os Salarios
        printf("Salario do %do. Funcionario(a): R$", i+1);
        scanf("%f", &salarios[i]);
    }
    for (i= 0;i<N;i++){
        media += salarios[i];
    }
    media = media/N;

    for (i=0;i<N;i++){
        if (salarios[i]>media)
            acima++;
    }
    printf("Media Salarial de R$%.2f com %d funcionarios acima da media.", media, acima);
    
    return 0;
}

