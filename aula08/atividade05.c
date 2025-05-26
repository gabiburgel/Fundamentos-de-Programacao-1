/*
    (***) 5. Escreva um programa que recebe um número inteiro positivo digitado pelo
    usuário e verifica e informa se ele é um número palíndromo ou não. Um número é
    palíndromo se puder ser lido igualmente na ordem normal e de trás para a frente.
    Alguns exemplos de números palíndromos:
    12321, 123321, 101, 2, 9, 99.
*/

#include <stdio.h>
int main (){

    int n, aux, resto;
    int inv = 0;

    scanf("%d", &n);

    aux = n;
    while (aux > 0){
        resto = aux%10;
        inv = inv * 10 + resto;
        aux = aux/10;
    }
    if (inv == n)
        printf ("eh palindromo");
    else
        printf ("nao eh palindromo");

    return (0);
}
