/*
    (***) 2. Um número positivo é primo se for divisível somente por 1 e por ele
    mesmo. Escreva um programa que calcula a soma dos N primeiros números primos,
    onde N é uma constante declarada em uma macro. Por exemplo, como os 5 primeiros
    números primos são: 2, 3, 5, 7 e 11, para N = 5 a soma será 28.
*/

#include <stdio.h>
#define N 10
int main (){

    int i, n;
    int cont, primo;
    int soma = 0;
    
    n = 2;
    while (cont < N){
            
        primo = 1;
        
        for (i = 2; i <= n / 2; i++){
            if (n % i == 0){
                primo = 0;
                break;
            }
        }
        if (primo){
            soma += n;
            cont++;
        }
        n++;
    }
    
    printf ("%d", soma);

    return (0);
}
