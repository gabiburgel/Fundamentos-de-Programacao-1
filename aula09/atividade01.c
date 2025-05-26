/*
    1.
    a) Escreva um programa que mostre todos os resultados possíveis quando arremessamos
    2 dados de 6 faces. A ordem aqui é relevante, portanto 1, 2 é um resultado diferente
    de 2, 1, e ambos devem ser mostrados. Dica 1: se achar muito difícil, escreva em algum
    lugar todas as combinações e veja se existe algum padrão. Dica 2: se ainda assim achar
    muito difícil, comece mostrando somente todos os resultados possíveis quando arremessamos
    um único dado!

    b) Modifique o programa para que ele mostre todos os resultados possíveis quando
    arremessamos 3 dados de 6 faces. A ordem aqui é relevante, portanto 1, 1, 2 é um
    resultado diferente de 2, 1, 1, e ambos devem ser mostrados.

    c) Modifique novamente o programa para que ele só mostre cada combinação de números
    uma única vez. Ou seja, se ele apresentar 1, 1, 2, não deve mostrar 2, 1, 1, nem 1,
    2, 1. Dica: a modificação é muito simples. Se você não conseguir enxergar a solução
    facilmente, faça de conta que os dados têm apenas 3 faces e escreva em um papel todas
    as possibilidades possíveis para a versão a) - serão 27 possibilidades - e risque as
    possibilidades redundantes - devem restar apenas 10. Verifique então se as possibili-
    dades restantes formam algum padrão.
*/

// a) =====================================================================================

#include <stdio.h>
int main (){

    int i, j;

    for (i=1; i <= 6; i++){
        for (j=1; j <= 6; j++){
            printf ("%d %d\n", i, j);
        }
    }

    return (0);
}

// b) ====================================================================================

#include <stdio.h>
int main (){

    int i, j, k;

    for (i=1; i <= 6; i++){
        for (j=1; j <= 6; j++)
            for (k=1; k <= 6; k++)
                printf ("%d %d %d\n", i, j, k);

    }

    return (0);
}

// c) ===================================================================================
#include <stdio.h>
int main (){

    int i, j, k;

    for (i=1; i <= 6; i++){
        for (j=i; j <= 6; j++)
            for (k=j; k <= 6; k++)
                printf ("%d %d %d\n", i, j, k);

    }

    return (0);
}
