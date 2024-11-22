#include <stdio.h>
#include <stdlib.h>


void preencheVetor(float *vetor, int tam){
    int i;
    for (i=0;i<tam;i++){
        printf("POSICAO %d: ", i);
        scanf("%f", &vetor[i]);
    }
}

int menu(void){
    int escolha;
    printf("\nMENU-----\n[1]SOMAR X E Y\n[2]SUBTRAIR X E Y\n[3]BUSCAR ELEMENTO\n[4]MOSTRAR X E Y\n[0]SAIR\n");
    printf("Opcao Escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

void soma(float *vetor1, float *vetor2, int tam){
    int i;
    for (i=0;i<tam;i++)
        printf("\n%.2f + %.2f = %.2f", vetor1[i], vetor2[i], vetor1[i]+vetor2[i]);
}

void subtrai(float *vetor1, float*vetor2, int tam){
    int i;
    for (i=0;i<tam;i++)
        printf("\n%.2f - %.2f = %.2f", vetor1[i], vetor2[i], vetor1[i]-vetor2[i]);
}

int busca(float *vetor, float num, int tam){
    int i;
    for (i=0;i<tam;i++){
        if (num == vetor[i])
            return 1;
    return 0;
    }
}

void mostra(float *vetor, int tam){
    int i;
    for (i=0;i<tam;i++)
        printf("%f \t", vetor[i]);
}

int main(void){
    int n, opcao;
    float val;
    float *x;
    float *y;
    printf("Tamanho do Vetor: ");
    scanf("%d", &n);
    x = (float*)malloc(n*sizeof(float));
    y = (float*)malloc(n*sizeof(float));
    preencheVetor(x,n);
    preencheVetor(y,n);
    opcao = menu();
    while (opcao != 0){
        switch (opcao){
            case 1:
                soma(x,y,n);
                break;
            case 2:
                subtrai(x,y,n);
                break;
            case 3:
                printf("Digite o valor da Busca: ");
                scanf("%f", &val);
                if (busca(x,val,n))
                    printf("\n%f pertence ao Primeiro Vetor!", val);
                else
                    printf("\n%f NAO pertence ao Primeiro Vetor!", val);
                if (busca(y,val,n))
                    printf("\n%f pertence ao Segundo Vetor!", val);
                else
                    printf("\n%f NAO pertence ao Segundo Vetor!", val);
                break;
            case 4:
                mostra(x,n);
                printf("\n");
                mostra(y,n);
                break;
        }
        opcao = menu();
    }
    return 0;

}

