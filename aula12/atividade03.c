/*
    3. Dizemos que uma sequência de n inteiros positivos é k-alternante se for composta
    alternadamente por segmentos de números pares de tamanho k e segmentos de números ímpares de
    tamanho k. Exemplos:
    A sequência 1 3 6 8 9 11 2 4 1 7 6 8 é 2-alternante.
    A sequência 2 1 4 7 8 9 12 é 1-alternante.
    A sequência 4 2 3 1 6 4 2 9 3 não é alternante.
    A sequência 1 3 5 é 3-alternante.
    
    Escreva uma função que recebe como parâmetro um valor n, e lê (através da função scanf) até n
    números inteiros, verificando se a sequência dada é k-alternante. Você pode considerar que o n 
    dado é maior que 1. A função deve retornar 1 caso a função seja k-alternante, e 0 do contrário; 
    e deve retornar imediatamente, sem ler os n valores, caso detecte que a sequência não é 
    k-alternante.
    Adicionalmente, caso ela seja k-alternante, o valor encontrado para k deve ser inserido em uma
    variável passada por referência à função.
*/
#include <stdio.h>

int kAlternante (int num, int* k);
int main (){
    
    int num, k;
    
    scanf("%d", &num);
    
    if (kAlternante(num, &k))
        printf("eh %d-alternante", k);
    else
        printf("nao eh k-alternante");
    
    return (0);
}
int kAlternante(int num, int* k){
    
    int i, n;
    int tam, eh_par;
    
    scanf("%d", &n);
    
    i = 1;
    tam = 1;
    k = -1;
    
    if (n%2)
        eh_par = 0;
    else 
        eh_par = 1;
    
    while (i < num)
    {
        scanf("%d", &n);
        
        if ((n%2 && !eh_par)|| (num%2==0 && eh_par))
            tam++;
        else 
        {
            if (*k < 0)
            {
                *k = tam;
                if (n % *k != 0)
                    return (0);
                else if (*k != tam)
                    return (0);
                tam = 1;
                eh_par = !ehpar;
            }
        }
    i++;
    }
    
    if (*k < 0)
        *k = n;
    
    return (1);
}

        
