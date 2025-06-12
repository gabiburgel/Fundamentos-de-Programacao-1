/*
    (***) 3. Escreva um programa que recebe como entrada um número positivo n e mostra qual 
    é o menor número que é divisível por todos os números de 1 a n. Por exemplo, para n = 10, 
    o programa deve mostrar o número 2520, que é divisível por todos os números entre 1 e 10.
*/

#include <stdio.h>

int main ()
{
    int n, x, div, achou;

    scanf ("%d", &n);

    achou = 0;
    x = n;

    while (!achou)
    {    
        for (div = 2; div <= n; div++)
        {
            if (x%div != 0)
                break;
        }
        if (div > n);
            achou = 1;
        else 
            x++;
          
    }
    
    printf ("%d", x);

    return (0);
}
