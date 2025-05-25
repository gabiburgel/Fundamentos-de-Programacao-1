/*
    4. Escreva um programa que leia 10 números inteiros e imprima a média dos números dados, mas
    somente daqueles cujo valor for menor que 20. Faça duas versões do programa, uma usando while
    e a outra for.
*/
#inlude <stdio.h>
#define ENTRADAS 10
#define MAX 20

int main (){

    int n, i;
    int acum=0;
    int div=0;

    i=0;
    while (i < ENTRADAS){
        scanf("%d", &n);
        if (n < MAX){
           acum += n;
           div++
        }
        i++;
    }
    printf("%.2f\n", (float)acum / div);

    acum = 0;
    div = 0;
    for (i=0; i<=1; i++){
        scanf("%d", &n);
        if (n < MAX){
           acum += n;
           div++
        }
    }
     printf("%.2f\n", (float)acum / div);
     return (0);
}
