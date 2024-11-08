#include <stdio.h>

int main(void){
    int voto, v0 = 0,v1 = 0,v2 = 0,v3 = 0,v4 = 0;
    do{
        printf("[0]NULO\n[1] JOAO DA SILVA\n[2]JOSE RAMALHO\n[3]MARIA DE MATTOS\n[4]VOTO EM BRANCO\n[5]SAIR\nOpcao Escolhida: ");
        scanf("%d", &voto);
        if (voto == 0)
            v0++;
        else if (voto==1)
            v1++;
        else if (voto==2)
            v2++;
        else if (voto==3)
            v3++;
        else if(voto==4)
            v4++;
    }while(voto!= 5);
    printf("%d JOAO DA SILVA\n%d JOSE RAMALHO\n%d MARIA DE MATTOS\n%d BRANCOS\n%d NULOS",v1,v2,v3,v4,v0);


    return 0;

}