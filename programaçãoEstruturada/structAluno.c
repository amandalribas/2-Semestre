#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno{
    char mat[8];
    char nome[40];
    float CR;
};
typedef struct aluno tAluno;

void preenche(tAluno *vetor, int num){
    int i;
    for (i=0;i<num;i++){
        printf("Digite a %da. MATRICULA: ",i+1);
        scanf("%s",vetor[i].mat);
        printf("Digite o %do. NOME:", i+1);
        scanf(" %[^\n]s", vetor[i].nome);
        printf("Digite o %do. CR:", i+1);
        scanf("%f", &vetor[i].CR);
    } 
}

int semestre201(tAluno *vetor, int num){
    int i, cont = 0;
    for (i=0;i<num;i++){
        if (strncmp(vetor[i].mat,"120", 3) == 0)
            cont += 1;
    }
    return cont;
}

void acimaMedia(tAluno *vetor, int num){
    int i;
    float media = 0;
    for (i=0;i<num;i++)
        media += vetor[i].CR;
    media = media/num;
    for (i=0;i<num;i++){
        if (vetor[i].CR > media)
            printf("\n%s acima da MEDIA!", vetor[i].nome);
    }
}

int main(void){
    int N, total = 0;
    tAluno *vet;
    printf("Digite a quantidade de alunos: ");
    scanf("%d",&N);
    vet = (tAluno*)malloc(N*sizeof(tAluno));
    preenche(vet,N);
    total = semestre201(vet,N);
    printf("O total de Alunos do 20.1 eh: %d", total);
    acimaMedia(vet,N);
    return 0;
}