/*
    2. Suponha a seguinte função, a qual retorna o primeiro e o último dígito de um número:
        void removeExtremos (int *n, int *pri, int *ult)
        {
        int tn, pot = 1;
        tn = *n;
        while(tn >= 10)
        {
            tn = tn/10;
            pot *= 10;
        }
        *pri = *n / pot;
        *ult = *n % 10;
        *n = *n % pot;
        *n = *n / 10;
        }
    Escreva um programa que utilize esta função para determinar se um dado inteiro positivo n é um
    número palíndromo (i.e. se pode ser lido igualmente da esquerda para a direita e da direita para a
    esquerda). Suponha que n não contém o dígito 0. Atenção: você não deve modicar a função dada no
    enunciado! Apenas invoque-a de forma adequada. (E também ignore o fato de que usar uma função
    assim não é a forma mais eficiente de testar se um número é palíndromo, se você se lembra!)
*/
#include <stdio.h>

int removeExtremos (int *n, int *pri, int *ult)
{
    int tn, pot = 1;
    tn = *n;
        
    while(tn >= 10)
    {
        tn = tn/10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
    }
    return (eh_primo);
}
int main (){

    int n, i, comeco, fim;
    int eh_palindromo = 1;
    
    while (n && eh_palindromo)
    {
        removeExtremos(&n, &comeco, &fim);
        if (comeco != fim)
            eh_palindromo = 0;
    }
    if (eh_palindromo)
        printf("eh palindromo");
    else 
        printf("nao eh palindromo");
    
    return (0);
}
