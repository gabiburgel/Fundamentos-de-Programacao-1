/*
    3. Escreva um programa que imprima os 10 primeiros números inteiros maiores que um n dado.
    Faça duas versões do programa, uma usando while e a outra for.
*/

/int main () {

     int n, i;
     scanf ("%d", &n);

    i = n+1;
    while (i <= n+10) {
        printf ("%d ", i);
        i++;
    }
    printf ("\n");

    for (i = n+1; i <= n+10; i++)
    printf ("%d ", i);

    return (0);
}
