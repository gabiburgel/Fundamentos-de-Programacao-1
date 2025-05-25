/*
    (***) 8. Escreva um programa que lê duas entradas no formato “hora:minuto:segundo”
    e as soma. O número de segundos e minutos deve ficar sempre entre 0 e 59. O programa
    deve testar as entradas, para conferir se elas não são inválidas.
*/

#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    int ht, mt, st;

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    int entrada_valida = 1;
    if ((h1 < 0 || h1 > 23) || (m1 < 0 || m1 > 59) || (s1 < 0 || s1 > 59)) {
        printf("entrada inválida");
        entrada_valida = 0;
    }
    if ((h2 < 0 || h2 > 23) || (m2 < 0 || m2 > 59) || (s2 < 0 || s2 > 59)) {
        printf("entrada inválida");
        entrada_valida = 0;
    }

    if (entrada_valida == 1) {
        st = s1 + s2;
        mt = 0;
        if (st >= 60) {
            st -= 60;
            mt = 1;
        }
        mt = mt + m1 + m2;
        ht = 0;
        if (mt >= 60) {
            mt -= 60;
            ht = 1;
        }

        ht = ht + h1 + h2;
        if (ht >= 24) {
            ht -= 24;
        }
        printf("%d:%d:%d\n", ht, mt, st);
    }
    return 0;
}
