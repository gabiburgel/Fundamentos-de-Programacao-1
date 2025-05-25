/*
   (**) 1. Escreva um programa que calcule o fatorial de um número dado.
*/

#include <stdio.h>

int main() {

    int n, i;
    long long int fatorial=1;
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        fatorial *= i;
    }
    printf ("%d", fatorial);
    return (0);
}
