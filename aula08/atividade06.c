/*
    6. (Adaptado da OBI 2012)
    Num sorteio que distribui prêmios, um participante inicialmente sorteia um inteiro N e
    depois N valores inteiros. O número de pontos do participante é o tamanho da maior
    sequência de valores consecutivos iguais. Por exemplo, suponhamos que um participante
    sorteia N = 11 e, nesta ordem, os valores:
    30 30 30 30 40 40 40 40 40 30 30
    Então, o participante ganha 5 pontos, correspondentes aos 5 valores 40 consecutivos.
    Note que o participante sorteou 6 valores iguais a 30, mas nem todos são consecutivos.
    Sua tarefa é ajudar a organização do evento, escrevendo um programa que determina o número
    de pontos de um participante. A entrada é um número inteiro N, que representa o número de
    valores sorteados. Depois, o programa deve ler N valores inteiros, na ordem do sorteio.
    Note que os valores são simplesmente informados, não são sorteados pelo programa! O
    programa então deve mostrar o número de pontos do participante.
    Exemplos:
    Entrada                                             Saída
    9                                                   4
    30 30 30 20 20 20 20 30 30

    14                                                  7
    1 1 1 20 20 20 20 3 3 3 3 3 3 3

    5                                                   5
    2 2 2 2 2
*/

#include <stdio.h>
int main (){

    int i, n, prox, ant;
    int seq = 1;
    int maior = 1;

    scanf("%d", &n);
    scanf ("%d", &ant);

    for (i=1; i < n; i++){

        scanf ("%d", &prox);

        if (prox == ant){
            seq++;
        else 
            seq = 1;
        }
        if (seq > maior)
            maior = seq;
        
        ant = prox;
    }
    printf ("%d", maior);

    return (0);
}
