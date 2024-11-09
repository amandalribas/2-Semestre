#include <stdio.h>

struct tipoHabitante{
    float salario;
    int idade, filho;
};
typedef struct tipoHabitante tHabitante;

int main(void){
    int i;
    tHabitante habitante[3];
    float mdSalario = 0, mdFilhos = 0, maSalario = 0;

    for (i=0;i<3;i++){
        printf("%do. Salario: ", i+1);
        scanf("%f", &habitante[i].salario);
        printf("%do. Idade: ", i+1);
        scanf("%d", &habitante[i].idade);
        printf("%do. Qnt. de Filhos: ",i+1);
        scanf("%d", &habitante[i].filho);
        mdSalario += habitante[i].salario;
        if (habitante[i].salario >= maSalario)
            maSalario = habitante[i].salario;
        mdFilhos += habitante[i].filho;

    }
    mdFilhos = (mdFilhos*1.0)/3;
    mdSalario = mdSalario/3;
    printf("Media de Salarios: R$%.2f\nMaior Salario: R$%.2f\nMedia de Filhos: %.1f", mdSalario,maSalario, mdFilhos);

    /*Printando 
    for (i=0;i<2;i++)
        printf("\n%.2f %d %d", habitante[i].salario, habitante[i].idade, habitante[i].filho);
    */

    return 0;
}