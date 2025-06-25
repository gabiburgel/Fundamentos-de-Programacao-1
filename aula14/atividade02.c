/*
    2. Escreva um programa que gera e mostra um vetor contendo N elementos aleatórios. O usuário
    deve informar uma posição do vetor. O programa deve então remover o elemento na posição
    informada, “puxando” todos os elementos das posições posteriores uma posição para “trás”. Por
    exemplo, se o vetor contém os números 1, 3, 6, 2 e 10 e o usuário digita 2, o programa deve 
    remover o elemento na posição número 2 do vetor – o 6 (lembre-se que a contagem inicia em 0) 
    – ficando com os números 1, 3, 2 e 10. Após a remoção, o programa deve mostrar como o vetor 
    ficou e pedir uma nova entrada ao usuário. O programa termina quando o vetor ficar vazio ou 
    se o usuário selecionar uma posição que estaria fora do vetor. Note que, após uma ou mais 
    remoções, o vetor terá posições inutilizadas, o conteúdo destas posições é indeterminado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main(){

    int vetor[N];
    int i, n;
    int tamanho;

    srand(time(NULL));

    for (i=0; i < N; i++)
        vetor[i] = rand()%10;

    tamanho = N;
    while (tamanho < 0);

    for (i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    scanf("%d", &n);

    for (i = posicao; i < tamanho - 1; i++) 
    {
        vetor[i] = vetor[i + 1];
    }
    tamanho--; q    

    return 0;
}
