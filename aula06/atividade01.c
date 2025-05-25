/*
    1. Escreva um programa que mostra todos os números no intervalo [0, N), onde N é uma constante
    definida com o uso da diretiva de pré-processamento #define. Faça a sequência ser mostrada duas
    vezes, uma usando a estrutura de repetição while, a outra o for.
*/

#define N 10
int main(){

    int i = 0;

    while (i < N){
        printf ("%d ", i);
        i++;
    }
    printf ("\n");

    for (i=0; i < N; i++)
        printf ("%d ", i);

    return (0);
}
