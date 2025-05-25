/*
   (**) 3. Escreva um programa que calcule o quociente e o resto da divisão de dois
   números inteiros positivos dados, usando apenas as operações de soma e/ou subtração.
*/

#include <stdio.h>
int main (){

    int n1, n2;
    int quociente, resto=1;

    scanf ("%d %d", &n1, &n2);

    for (quociente = 0; n1 >= n2; quociente++)
        n1 -= n2;

    resto = n1;
    printf ("quociente: %d\nresto: %d", quociente, resto);

    return (0);
}
