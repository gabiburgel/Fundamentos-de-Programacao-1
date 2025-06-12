/*
    (***) 4.
     a) Faça um programa que, dado um valor n informado pelo usuário, imprima uma pirâmide de
     caracteres com n linhas seguindo o padrão abaixo. Considere que 1 ≤ n ≤ 26 (o programa 
     não precisa testar isso!).     
     Exemplo para n = 5:
     A B C D E
     A B C D 
     A B C
     A B
     A
*/

#include <stdio.h>
#define N 5

int main ()
{
    int i, j;

    for (i = N; i >= 1; i--)
    {    
        for (j = 0; j < i; j++)
        {
            printf ("%c", 65 + j);

            if (j < i - 1)
                printf (" ");
        }
        printf ("\n");
    }
    return (0);
}
/*
    b) Modifique o seu programa para imprimir o padrão como exemplificado abaixo. Dica: se 
    a sua solução para a questão anterior for eficiente, a mudança é muito simples!
    Exemplo para n = 5:
    A B C D E
    B C D E
    C D E
    D E
    E
*/
#include <stdio.h>
#define N 5

int main ()
{
    int i, j;

    for (i = 0; i < N; i++)
    {    
        for (j = i; j < N; j++)
        {
            printf ("%c", 65 + j);
            
            if (j < N - 1)
                printf (" ");
        }
        printf ("\n");
    }
    return (0);
}
/*
    c) Modifique o seu programa para imprimir o padrão como nos exemplos abaixo. Dica: se a 
    sua solução para a questão anterior for eficiente, a mudança é muito simples!
    Exemplo para n = 5:
    E E E E E
    D D D D
    C C C
    B B
    A
*/
#include <stdio.h>
#define N 5

int main ()
{
    int i, j;
    char letra;

    for (i = 0; i > N; i++)
    {   
        letras = 65 + (N - 1 - i);

        for (j = 0; j < N; j++)
        {
            printf ("%c", letra);
            
            if (j < N - 1)
                printf (" ");
        }
        printf ("\n");
    }
    return (0);
