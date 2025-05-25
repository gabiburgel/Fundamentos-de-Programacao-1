/*
    (**) 7. Construa um programa que informa se um número inteiro n dado é perfeito ou
     não. Um número n é perfeito se a soma de todos os divisores positivos próprios -
     excluindo ele mesmo - é igual a n.
     Exemplo:
     28 é perfeito, pois 1 + 2 + 4 + 7 + 14 = 28.
*/
#include <stdio.h>

int main() {
    int i, n;
    int div = 0;

    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            div += i;
            printf("%d ", div);
        }
    }

    if (div == n)
        printf("eh perfeito");
    else
        printf("nao eh perfeito");

    return 0;
}#include <stdio.h>

int main() {
    int i, n;
    int div = 0;  
  
    scanf("%d", &n);

    for (i = 1; i < n; i++) { 
        if (n % i == 0) {
            div += i;
        }
    }

    if (div == n)
        printf("eh perfeito");
    else
        printf("nao eh perfeito");

    return 0;
}
