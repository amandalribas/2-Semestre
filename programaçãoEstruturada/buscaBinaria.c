#include <stdio.h>
#include <stdlib.h>

struct LISTA{
    int *elementos;
    int tamanho;
};

typedef struct LISTA tLista;

int buscaBinaria(int elemento, tLista lista){
    int i, posMeio;
    posMeio = lista.tamanho/2;
    if (elemento == lista.elementos[posMeio])
        return 1;
    else{
        if (elemento > lista.elementos[posMeio]){ //maior que meio
            for (i=posMeio+1; i<lista.tamanho;i ++){
                if (lista.elementos[i] == elemento)
                    return 1;
            }
        }else{ //menor que meio
            for (i=0; i<posMeio; i++){
                if (lista.elementos[i] == elemento)
                    return 1;
            }
        }
    }
    return 0;
}

int buscaBinariaOptimizada(int elemento, tLista *lista){
    int posInicio = 0, posMeio, posFim = lista->tamanho-1;
    while (posInicio <= posFim){
        posMeio = (posInicio + posFim)/2;
        if (elemento == lista->elementos[posMeio])
            return 1;
        else{
            if (elemento < lista->elementos[posMeio])
                posFim = posMeio - 1;
            else
                posInicio = posMeio + 1;

        }
    }
    return 0;
}

int main(void){
    tLista teste;
    teste.tamanho = 5;

    teste.elementos = (int *)malloc(teste.tamanho * (sizeof(int)));
    teste.elementos[0] = 1;
    teste.elementos[1] = 2;
    teste.elementos[2] = 3;
    teste.elementos[3] = 4;
    teste.elementos[4] = 5;

    if (buscaBinariaOptimizada(41,&teste))
            printf("sim");
    else
        printf("nao");
    
    return 0;
}