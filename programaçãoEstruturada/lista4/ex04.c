#include <stdio.h>
#include <string.h>

struct tipoServico{
    int os;
    float valor;
    char tipo[30], cliente[30];
};
typedef struct tipoServico tServico;

int main(void){
    int i,N;
    float media = 0, maisCaro = 0;
    char pessoaCara[30];
    printf("Quantidade de Servicos: ");
    scanf("%d", &N);
    tServico servico[N];
    for (i=0;i<N;i++){
        printf("%da. OS: ",i+1);
        scanf("%d", &servico[i].os);
        printf("%do. Valor: R$",i+1);
        scanf("%f", &servico[i].valor);
        printf("%do. Tipo: ",i+1);
        scanf("%s", servico[i].tipo);
        printf("%do. Nome: ",i+1);
        scanf("%s", servico[i].cliente);

        media += servico[i].valor;
        if (servico[i].valor > maisCaro){
            maisCaro = servico[i].valor;
            strcpy(pessoaCara,servico[i].cliente);
        }
    }

    media = media / N;
    printf("\nMedia de Preco R$%.2f\nFoi %s a Pessoa que pagou mais Caro", media, pessoaCara);
    for (i=0;i<N;i++){
        if (servico[i].valor > media)
            printf("\n%s pagou mais caro que a media.", servico[i].cliente);
    }

    return 0;
}