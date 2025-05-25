/*
   (**) 2. Escreva um programa que leia n números (com n informado pelo usuário)
    e diga se eles formam uma sequência crescente, decrescente, ou nenhum dos casos.
*/

#include <stdio.h>
int main (){

    int i, n, a, b;
    int crescente, decrescente;

    scanf ("%d", &n);
    scanf ("%d", &a);

    crescente = 1;
    decrescente = 1;
    i = 1;
    while (i < n){

        scanf ("%d", &b);

        if (b <= a)
            crescente = 0;
        if (b >= a)
            decrescente = 0;

        a = b;
        i++;
    }
    if (crescente)
        printf ("crescente\n");
    else if (decrescente)
        printf ("decrescente\n");
    else
        printf ("nenhum\n");
    return (0);
}
