/*
   (**) 1. Em 1937, o matemático Lothar Collatz propôs a seguinte conjetura, ainda não provada:
    dado um número natural arbitrário a0, a sequência gerada por:
    ai = ai-1/2, se ai-1 for par ou
    ai = 3·ai-1+1, se ai-1 for ímpar,
    em que ai-1 e ai representam o último elemento produzido para a sequência e o próximo valor
    a ser gerado, respectivamente, sempre chegará ao valor 1, independente do valor inicial
    escolhido para a0. Por exemplo, a sequência de Collatz para a0 = 7 é: 7, 22, 11, 34, 17, 52,
    26, 13, 40, 20, 10, 5, 16, 8, 4, 2 e 1.
    Escreva um programa que leia o primeiro elemento de uma sequência de Collatz e imprima na
    tela a sequência a partir do elemento dado, até que se alcance o valor 1. O programa deve
    também mostrar o número de elementos da sequência gerada. Se o programa receber o valor 7,
    por exemplo, deve mostrar os 17 elementos listados acima, e dizer que gerou 17 elementos.
*/

#include <stdio.h>
int main (){

    int a0, ai;
    int i, elementos;

    scanf("%d", &a0);

    ai = a0;
    elementos = 1;
    printf ("%d, ", a0);
    while (ai != 1){

        if (ai%2==0){
            ai = ai/2;
    }
        else
            ai = 3 * ai+1;

        printf ("%d, ", ai);
        elementos++;
    }

    printf ("elementos: %d", elementos);
    return (0);
}
