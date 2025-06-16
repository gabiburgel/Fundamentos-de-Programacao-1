/*
  3. A sequência de Fibonacci é uma sequência de números naturais na qual os primeiros termos são 0 e 1, e cada 
  termo subsequente é a soma dos dois termos anteriores. Desta forma, o terceiro termo é 0+1=1, o quarto termo é
  1+1=2, o quinto termo é 1+2=3, o sexto termo é 2+3=5 e assim por diante. Os 10 primeiros números da sequência são:
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34
  Escreva uma função que recebe um número inteiro n passado por parâmetro e devolve o primeiro número da série de 
  Fibonacci que é maior ou igual a n. Por exemplo, para n=7, a função retorna 8, pois 8 é o primeiro termo que
  pertence à sequência de Fibonacci que é maior ou igual a 7. Da mesma forma, para n=15, a função retorna 21.
    int proxFibonacci (int n); 
*/

#include <stdio.h>

int proxFibonacci(int n);
int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", proxFibonacci(n));

    return 0;
}

int proxFibonacci(int n) {
    int a = 0
    int b = 1
    int c = 0;

    if (n <= 0)
        return 0;

    while (c < n) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
