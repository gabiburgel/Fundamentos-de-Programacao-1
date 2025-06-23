/*
    3.
    a) Escreva um programa que lê N valores do tipo int, onde N é uma constante dada. 
    O programa deve imprimir os valores lidos na ordem inversa à fornecida. Você não 
    deve usar N variáveis para armazenar os valores!

    b) Modifique o programa para que o usuário forneça o valor de N, sabendo que N <= 1024.
*/

// a)

#include <stdio.h>
#define N 10

int main(){

    int i, v[N];

    for (i=0; i < N; i++)
    {
        scanf("%d", &(v[i]));
    }
    printf ("\n");

    for (i=N-1; i >= 0; i--)
    {   
        printf("%d", v[i]);
    }

    return 0;
}

// b)

#include <stdio.h>
#define MAX 1024

int main(){

    int i, n; 
    int v[MAX];

    scanf ("%d", &n);

    for (i=0; i < n; i++)
    {
        scanf("%d", &(v[i]));
    }

    printf ("\n");

    for (i=n-1; i >= 0; i--)
    {   
        printf("%d", v[i]);
    }

    return 0;
}
