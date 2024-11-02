#include <stdio.h>

char menu(){
    char opcao;
    printf("MENU: \n[+]SOMA\n[-]SUBTRACAO\n[/]DIVISAO\n[*]MULTIPLICACAO\n[!]SAIR\nDigite a opcao desejada: ");
    scanf("%c", &opcao);
    return opcao;
}

int verifica(char opcao){
    if ((opcao == '+')||(opcao == '-')||(opcao == '/')||(opcao == '*'))
        return 1;
    return 0;
}

void opera(char opcao, float A, float B){
    switch (opcao)
    {
    case '+':
        printf("%.2f + %.2f = %.2f\n", A, B, A+B);   
        break;
    case '-':
        printf("%.2f - %.2f = %.2f\n", A, B, A-B);
        break;
    case '/':
        printf("%.2f / %.2f = %.2f\n", A, B, A/B);
        break;
    case '*':
        printf("%.2f * %.2f = %.2f\n", A,B, A*B);
        break;
    }
}

int main(void){
    char op;
    float A,B;
    op = menu();
    while(op != '!'){
        if (verifica(op)&& op != '!'){
            printf("Digite o 1o. Valor: ");
            scanf(" %f", &A);
            printf("Digite o 2o. Valor: ");
            scanf(" %f", &B);
            opera(op, A, B);
        }else{
            printf("Resposta Invalida! Por favor, tente novamente.\n");
        }
        op = menu();

    }


    return 0;
}