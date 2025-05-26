/*
    (***) 3. A sequência de Fibonacci é uma sequência de números naturais na qual os primeiros
    termos são 0 e 1, e cada termo subsequente é a soma dos dois termos anteriores. Desta forma,
    o terceiro termo é 0+1=1, o quarto termo é 1+1=2, o quinto termo é 1+2=3, o sexto termo é
    2+3=5 e assim por diante. Os 10 primeiros números da sequência são:
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34
    Os números da sequência de Fibonacci são usados em certos algoritmos para codificação,
    compressão e ordenamento de dados. Eles também podem ser usados em computação gráfica,
    na geração de transições suaves de cores e de objetos com aspecto natural (por exemplo,
    em animações cinematográficas).
    Escreva um programa que mostra os n primeiros números de Fibonacci, com n dado pelo usuário.
    Pressuponha que n será sempre maior ou igual a 3, mas nunca grande o suficiente para causar
    overflow em variáveis do tipo int.
*/

#include <stdio.h>
int main (){

    int i, n;
    int a, b, c;

    scanf("%d", &n);

    a=0;
    b=1;
    printf ("%d %d ", a, b);

    for (i=0; i < n-2; i++){
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
    return (0);
}
