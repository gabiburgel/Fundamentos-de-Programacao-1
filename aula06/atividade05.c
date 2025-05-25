/*
 (**) 5. O número 3025 possui a seguinte caracterı́stica: 30 + 25 = 55 → 55*55 = 3025. Escreva um ∗
programa que mostre todos os números de 4 algarismos com a mesma característica do número 3025.

*/
#include <stdio.h>
int main(){
    int i, n;
    int a, b, c;

    for (i=1000; i <= 9999; i++){
        a = i%100;
        b = i/100;
        c = a + b;

        if (c*c==i)
            printf("%d\n", i);
    }
    return (0);
}
