/*
    4. Suponha que dois números formam um par de Foolano se ambos têm os mesmos dígitos, na
    mesma quantidade, desconsiderando-se os zeros à esquerda. Por exemplo, os pares abaixo 
    são pares de Foolano:
    1234 e 4321; 1122 e 1212; 101 e 101; 344 e 443.
    Já os pares abaixo não são pares de Foolano:
    123 e 124; 221 e 112; 022 e 220.
    
    a) Escreva uma função que retorna 1 se 2 números dados formam um par de Foolano, ou 0 do
    contrário. O protótipo da função deve ser:
    
    int ehParDeFoolano (unsigned int n1, unsigned int n2);
*/

// a)

#include <stdio.h>

int ehParDeFoolano (unsigned int n1, unsigned int n2);
int main(){

    unsigned int num1, num2;

    scanf("%u %u", &num1, &num2);

    if (ehParDeFoolano(n1, n2)) {
        printf("formam um par de Foolano");
    } else {
        printf("não formam um par de Foolano");
    }
    
    return 0;
}
int ehParDeFoolano (unsigned int n1, unsigned int n2){

    int i;
    int contagem1[10] = {0};
    int contagem2[10] = {0};

    while (n1 > 0)
    {
        digitos[n1%10]++;
        n1 /= 10;
    }
    while (n2 > 0)
    {
        digitos[n2%10]++;
        n1 /= 10;
    }

    for (int i = 0; i < 10; i++) 
    {
        if (contagem1[i] != contagem2[i]) 
            return 0;
    }

    return (1);
}
