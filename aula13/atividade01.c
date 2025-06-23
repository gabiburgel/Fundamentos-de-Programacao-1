/*
    1. Escreva um programa que gera N valores aleatórios do tipo int no intervalo [20, 80], 
    onde N é uma constante dada. O programa deve calcular e imprimir a média (não se preocupe
    com o arredondamento), e depois mostrar cada um dos valores, dizendo se ele é maior, 
    menor ou igual à média. Por fim, o programa deve mostrar quantos dos valores eram maiores 
    e quantos eram menores do que a média.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_FAIXA 20
#define MAX_FAIXA 80
#define N 10

int main(){

    int v[N];
    int i, media=0;
    int maiores, menores;

    srand (time (NULL));

    for (i=0; i < N; i++)
    {
        v[i] = MIN_FAIXA + (rand() % (MAX_FAIXA - MIN_FAIXA +1));
        media += v[i];
    }

    media /= N;
    printf ("media: %d", media);

    maiores = 0;
    menores = 0;

    for (i=0; i < N; i++)
    {   
        printf ("%d ", v[i]);

        if (v[i] > media)
        {
            maiores++;
            printf ("maior\n");
        }
        else if (v[i] < media)
        {
            menores++;
            printf ("menor\n");
        }
        else 
            printf ("igual\n");
    }

    printf ("maiores: %d, menores: %d", maiores, menores);

    return 0;
}
