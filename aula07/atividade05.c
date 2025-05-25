/*
    (***) 5. Escreva um programa no qual o usuário digita uma quantia arbitrária de
    números inteiros positivos. Quando o usuário digitar um número menor ou igual a
    0, o programa deve indicar o tamanho da maior sequência crescente observada. Por
    exemplo, se os números digitados forem 5, 10, 3, 2, 4, 7, 9, 8, 5, a maior
    sequência crescente é 2, 4, 7, 9, então o programa deve mostrar na tela que a
    maior sequência crescente tem 4 números. Já a sequência 10, 8, 7, 5, 2 está em
    ordem decrescente,portanto a maior sequência crescente observada tem tamanho 1.
*/

#include <stdio.h>
int main (){

    int n, anterior;
    int crescente = 1;
    int maior = 1;
    
    scanf("%d", &anterior);


    while (anterior > 0) {
        
        scanf ("%d", &n);
        if (n > anterior){
            crescente++;
            if (crescente > maior)
                maior = crescente;
        }
        else
            crescente = 1;
        anterior = n;
        }
    printf("%d", maior);

    return (0);
}
