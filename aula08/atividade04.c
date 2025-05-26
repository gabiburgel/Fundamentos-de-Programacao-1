/*
    (***) 4. (Adaptado da OBI 2017)
    Um sistema de informações geográficas computadorizado está representando o perfil
    de uma montanha através de uma sequência de números inteiros, na qual não há dois
    números consecutivos iguais. Os números representam a altura da montanha ao longo
    de uma certa direção.
    O gerente do sistema de informações geográficas pesquisou e encontrou uma maneira
    de identificar se uma sequência de números inteiros representa uma montanha com
    mais de um pico, ou com apenas um pico. Ele observou que, como não há números
    consecutivos iguais, se houver três números consecutivos na sequência, tal que o
    número do meio é menor do que os outros dois números, então a montanha tem mais de
    um pico. Caso contrário, a montanha tem apenas um pico. De forma mais rigorosa, se
    a sequência é A = [A1, A2, A3, ..., AN-2, A N-1, AN], ele quer saber se há uma
    posição i, para 2 ≤ i ≤ N-1, tal que Ai-1 > Ai e Ai < Ai+1.
    Para ajudar o gerente, seu programa deve determinar, dada a sequência de números
    inteiros representando a montanha, se ela tem mais de um pico, ou se tem um pico
    apenas. O programa recebe como entrada o tamanho N da sequência, seguido por N
    inteiros, representando a sequência de alturas da montanha em cada ponto. O programa
    deve indicar então se o programa tem apenas um pico (S) ou não (N).
    Exemplos:
    Entrada                                        Saída
    8                                              S
    2 3 5 6 7 5 4 2

    8                                              N
    2 3 6 5 4 6 3 2
*/

#include <stdio.h>
int main (){

    int i, n;
    int antes, meio, prox, pico;

    scanf("%d", &n);
    scanf ("%d %d", &antes, &meio);

    pico = 0;
    i=2;
    while (i < n){

        scanf ("%d", &prox);

        if (antes > meio && meio < prox)
            pico = 1;

        antes = meio;
        meio = prox;
        i++;
    }
    if (pico)
        printf("N");
    else
        printf ("S");

    return (0);
}
