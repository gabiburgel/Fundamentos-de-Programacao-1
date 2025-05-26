/*
   (***) 2. (Adaptado da OBI 2015) Alice e Bia criaram uma página na Internet com informações
    sobre o Macaco-prego-de-peito-amarelo, uma espécie em extinção. A página mostra como todos
    podem ajudar a manter o habitat natural para evitar que a espécie seja extinta. Uma empresa
    gostou tanto da iniciativa de Alice e Bia que prometeu doar um prêmio para que as duas amigas
    possam realizar outras iniciativas semelhantes. A empresa decidiu que o prêmio seria dado
    quando a soma do número de acessos à página chegasse a 1 milhão.
    Dada a lista de acessos diários que ocorreram à página de Alice e Bia, escreva um programa
    para determinar quantos dias foram necessários para a soma dos acessos chegar a 1 milhão e
    as amigas ganharem o prêmio. O programa recebe como entrada um número inteiro N, que indica
    o número de dias que a lista contém. Ele deve então ler N valores, correspondentes ao número
    de acessos de cada dia: o primeiro número dado indica o número de acessos no primeiro dia, o
    segundo número dado indica o número de acessos no segundo dia, e assim por diante. O programa
    deve então mostrar na saída o número de dias que foram necessários para a soma dos acessos à
    página de Alice e Bia chegar a 1.000.000. Se a meta não for atingida, o programa deve mostrar
    o valor de erro -1.
    Exemplos:
    Entrada                                         Saída
    5                                               4
    100 99900 400000 500000 600000

    1                                               1
    1000000
*/

#include <stdio.h>
int main (){

    int n, i, dia;
    int acessos, achou, soma;

    scanf("%d", &n);

    soma=0;
    achou=0;
    for (i=0; i< n; i++){

        scanf("%d", &acessos);
        soma += acessos;
        if(acessos>=1000000){
            achou=1;
            dia=i+1;
            break;
        }
    }
    if (achou)
        printf ("%d", dia);
    else
        printf ("-1");

    return (0);
}
