/*
    1. Desenvolva uma função que recebe um número de segundos e converte para o tempo
    correspondente no formato de horas, minutos e segundos. Por exemplo, 10000 segundos
    corresponde a 2 horas, 46 minutos e 40 segundos. O protótipo da função deve ser:

    void segundosParaHMS (int total_segundos, int *h, int *m, int *s);

    Inclua na sua resposta uma função main simples, que invoque a função acima e
    mostre os valores retornados, no formato hh:mm:ss.
*/
#include <stdio.h>

void segundosParaHMS(int total_segundos, int *h, int *m, int *s);

int main (){

    int h, m, s;
    int tseg;

    scanf ("%d", &tseg);

    segundosParaHMS(tseg, &h, &m, &s);

    printf("%d : %d : %d", h, m, s);

    return (0);
}
void segundosParaHMS(int total_segundos, int *h, int *m, int *s){

    *h = total_segundos/3600;
    total_segundos -= (*h * 3600);
    *m = total_segundos/60;
    *s = total_segundos%60;
}
