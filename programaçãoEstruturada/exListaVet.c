#include <stdio.h>
#include <stdlib.h>

struct LISTA{
    int *elementos;
    int tamanho;
};

typedef struct LISTA tLista;

int menu(void){
    int resposta;
    printf("\nMENU -----\n");
    printf("[1]INSERE;\n[2]REMOVE;\n[3]MOSTRA;\n[4]SAIR;\nOpcao Escolhida:");
    scanf("%d", &resposta);
    return resposta;
}

void mostra(tLista *lista){
    int i;
    printf("LISTA: ");
    for (i=0;i<lista->tamanho;i++)
        printf("%d\t",lista->elementos[i]);
}


int buscaBinaria(int elemento, tLista *lista, int *pos){
    int posInicio = 0, posMeio, posFim = lista->tamanho-1;
    while (posInicio <= posFim){
        posMeio = (posInicio + posFim)/2;
        if (elemento == lista->elementos[posMeio]){
            *pos = posMeio;
            return 1; //retorna 0 se ja existe;
        }
        else{
            if (elemento < lista->elementos[posMeio])
                posFim = posMeio - 1;
            else
                posInicio = posMeio + 1;
        }
    }
    *pos = posInicio;
    return 0; //retorna 0 se nao existe;
}

int insere(int elemento, tLista *lista){
    int i, pos;
    if (buscaBinaria(elemento, lista, &pos)){ //Se elemento ja Existe
        printf("%d JA EXISTENTE!Impossivel Adicionar\n", elemento);
        return 0;
    }
    else{
        lista->elementos = (int *)realloc(lista->elementos, (lista->tamanho + 1) * sizeof(int));
        printf("O elemento sera colocado na posicao %d\n", pos);
        for (i=lista->tamanho;i>pos;i--)
            lista->elementos[i] = lista->elementos[i-1];
        lista->elementos[pos] = elemento;
        lista->tamanho++;
    }
    return 1;
}

int apaga(int elemento, tLista *lista){
    int i, pos;
    if (buscaBinaria(elemento, lista, &pos)){ //Se elemento ja Existe
        for (i=pos;i<lista->tamanho;i++)
            lista->elementos[i] = lista->elementos[i+1];
        //lista->elementos[pos] = lista->(tamanho-1);

        lista->elementos = (int *)realloc(lista->elementos, (lista->tamanho - 1) * sizeof(int));
        lista->tamanho--;
        return 1;
    }else
        printf("NAO EXISTENTE! Impossivel Remover da Lista...\n");
    return 0;
}

int main(void){
    tLista lista;
    int opcao, i, num, quant;
    //criando lista
    lista.tamanho = 0;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &quant);
    lista.elementos = (int *)malloc(lista.tamanho * (sizeof(int)));
    if (lista.elementos != NULL){
        for (i=0;i<quant;i++){
            printf("\nDIGITE O %do. ELEMENTO:", i+1);
            scanf("%d", &num);
            if (!(insere(num,&lista))){
                printf("\nNUMERO JA EXISTENTE! Tente Novamente...");
                i--;
            }
        }
        mostra(&lista);
        do{
            opcao = menu();
            
            switch (opcao){
                case 1:
                    printf("\nDIGITE UM VALOR: ");
                    scanf("%d", &num);
                    insere(num,&lista);
                    printf("\nTamanho da LISTA: %d", lista.tamanho);
                    break;
                case 2:
                    printf("DIGITE UM VALOR: ");
                    scanf("%d", &num);
                    apaga(num,&lista);
                    break;
                case 3:
                    mostra(&lista);
                    break;
                case 4:
                    printf("FIM DA EXECUCAO DO PROGRAMA! Saindo...\n");
                    break;
                default:
                    printf("OPCAO INVALIDA! Tente Novamente...\n");
            }
        }while (opcao!=4);
    }else{
        printf("ERRO AO ALOCAR MEMORIA!");
        return 1;
    }

    return 0;
}