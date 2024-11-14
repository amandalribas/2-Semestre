#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipoAluno{
    char nome[40];
    float media;
    int anoIngresso;
};
typedef struct tipoAluno tAluno;


int main(void){
    int N, i, cont = 0;
    float notas[4];
    float maior = 0;
    char **maiorNotas;
    tAluno *alunos;
    printf("Quantidade de Alunos: ");
    scanf("%d", &N);
    
    alunos = (tAluno*)malloc(N*sizeof(tAluno));
    maiorNotas = (char**)malloc(N*sizeof(char));
    for (i=0;i<N;i++){
        printf("Digite o %do. NOME: ", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite as 4 NOTAS de %s:",alunos[i].nome);
        scanf("%f %f %f %f", &notas[0],&notas[1], &notas[2],&notas[3]);
        printf("Digite o ANO DE INGRESSO: ");
        scanf("%d", &alunos[i].anoIngresso);
        alunos[i].media = (notas[0]+notas[1]+notas[2]+notas[3])/4;    
        if (alunos[i].media >= maior)
            maior = alunos[i].media;
    }

    for (i=0;i<N;i++){ //preenchendo vetor de maioresNotas
        if (alunos[i].media == maior){
            maiorNotas[cont] = (char*)malloc((strlen(alunos[i].nome)+1)*sizeof(char));
            strcpy(maiorNotas[cont],alunos[i].nome);
            cont++;
        }
    }

    for (i=0;i<N;i++){
        printf("\nNOME: %s\nMEDIA: %.2f\nANO DE INGRESSO: %d\n", alunos[i].nome,alunos[i].media,alunos[i].anoIngresso);
    }
    
    for (i=0;i<cont;i++)
        printf("\nMAIORES NOTAS: %s\n", maiorNotas[i]);
    return 0;
}