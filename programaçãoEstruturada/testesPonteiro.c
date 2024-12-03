#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tipoPessoa{
    int idade;
    char nome[100];
    float altura;
};
typedef struct tipoPessoa tPessoa;


int copia(char *palavra1, char *palavra2){
    int i = 0; 
    while (*(palavra2 + i) != '\0'){
        *(palavra1 + i) = *(palavra2 + i); 
        i++;
    }
    *(palavra1+i) = '\0';
    return i; //tamanho da string
}

//ponteiro para struct usa ->
void imprimeInfo(tPessoa *pessoa){
    printf("\nIdade: %d\nNome: %s\nAltura: %.2f\n\n", pessoa->idade, pessoa->nome,pessoa->altura);
}

void imprimeVetor(int *vetor, int tamanho){
    int i;
    for (i=0;i<tamanho;i++)
        printf("%d\t", *(vetor+i));
    printf("\n");
}

void imprimeEndeVet(int *vetor, int tamanho){
    int i;
    for (i=0;i<tamanho;i++)
        printf("%p\t", vetor+i);
    printf("\n");
}

void alteraVetor(int *vetor, int tamanho){
    int i;
    for (i=0;i<tamanho;i++)
        vetor[i]++;
}

void troca(float *a, float *b){
    float aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


int main(void){
    tPessoa p1;
    int *p;
    int num;
    float x = 10.5, y= 13.4;
    int vetor[7] = {13,24,7,4,32,1,14};
    int A, *B, **C, ***D;
    char destino[25], origem[25] = {"Teste 123"};
    int len;
    //testando ponteiros + vetor
    imprimeVetor(vetor,7);
    imprimeEndeVet(vetor,7);
    alteraVetor(vetor,7);
    imprimeVetor(vetor,7);

    //testando ponteiros + struct 
    p1.idade = 19;
    strcpy(p1.nome,"Amanda Lemos Ribas");
    p1.altura = 1.60;

    imprimeInfo(&p1);

    //testando ponteiros
    num = 10;
    p = &num;
    printf("tamanho de *int: %d\n", sizeof(p));
    printf("tamanho de int: %d\n", sizeof(num));
    printf("Val de NUM: %d\n", *p); //valor
    printf("Endereco de NUM (que P esta apontando): %p\n", p);
    printf("Endereco de NUM: %p\n",&num);
    printf("Endereco de P: %p\n", &p);
    printf("X: %.1f\tY: %.1f\n",x,y);
    troca(&x,&y);
    printf("X: %.1f\tY: %.1f\n",x,y);

    printf("Digite o Valor de A:");
    scanf("%d", &A);
    B = &A;
    C = &B;
    D = &C;
    
    printf("A = %d\nB = %d\nC = %d\nD = %d\n", A, 2 * *B, 3 * **C, 4 * ***D);

    len = copia(&destino, &origem);
    printf("DESTINO : %s\nORIGEM: %s\n", destino, origem);
    printf("len da str: %d", len);
    return 0;
}