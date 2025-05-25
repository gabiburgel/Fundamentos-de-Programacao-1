/*
   (**) 4. Escreva um programa que lê um inteiro positivo e um dígito. O programa deve
   verificar se o número dado contém o dígito em qualquer posição. Não é preciso dizer
   qual a posição, apenas indicar se o dígito está ou não presente.
*/

#include <stdio.h>
int main (){

    int n, digito;
    int aux, achou;

    scanf ("%d %d", &n, &digito);

    achou=0;
    while (n!=0){

        aux=n%10;
        n=n/10;
        if (aux == digito){
            achou=1;
            break;
        }
    }
    if (achou)
        printf("esta presente");
    else
        printf("nao esta presente");

    return (0);
}
