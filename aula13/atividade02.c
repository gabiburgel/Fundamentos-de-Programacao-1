/*
    2. Escreva um programa que gera N valores aleatórios do tipo float no intervalo [-40,+40], 
    onde N é uma constante dada. O programa deve calcular e imprimir a média dos positivos, e 
    depois mostrar cada um dos valores positivos, dizendo se o valor é maior, menor ou igual 
    à média. Já os valores negativos não devem ser armazenados em um vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_FAIXA -40
#define MAX_FAIXA 40
#define N 10

int main(){

    float v[N];
    float valor, media=0;
    int i, positivos=0;

    srand (time (NULL));

    for (i=0; i < N; i++)
    {
        valor = (rand() / (float) MAX_FAIXA) *(MAX_FAIXA - MIN_FAIXA) + MIN_FAIXA;

        if (valor > 0)
        {
            v[positivos] = valor;
            media += v[positivos];
            positivos++;
        }
    }

    media /= positivos;
    printf ("media: %.2f\n", media);

    for (i=0; i < positivos; i++)
    {   
        printf ("%.2f ", v[i]);

        if (v[i] > media)
        {
            printf ("maior\n");
        }
        else if (v[i] < media)
        {
            printf ("menor\n");
        }
        else 
            printf ("igual\n");
    }

    return 0;
}
