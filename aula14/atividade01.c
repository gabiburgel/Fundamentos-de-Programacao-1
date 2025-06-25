/*
    1. A maioria das universidades brasileiras usa o vestibular para selecionar seus alunos. 
    O vestibular consiste de uma ou mais provas sobre as matérias do Ensino Médio, visando 
    avaliar os conhecimentos dos candidatos. Um formato popular de prova de vestibular é a 
    prova objetiva. Neste formato de prova, cada candidato deve escolher uma das cinco alter-
    nativas apresentadas pela questão como sendo a correta. Durante a correção dos cartões, 
    cada questão onde a alternativa escolhida pelo candidato é a mesma do gabarito, ele ganha 
    um ponto. Alguns dos vestibulares mais concorridos do Brasil são disputados por dezenas de
    milhares de candidatos, e, por isso, geralmente usa-se uma folha de leitura óptica e um 
    programa de computador para corrigir as provas de todos os candidatos e gerar a lista com 
    suas pontuações. Você trabalha no comitê responsável pelo vestibular em uma faculdade e 
    deve escrever um programa que, dado o gabarito e as respostas de um dos candidatos, determina 
    o número de acertos daquele candidato.
    
    Entrada:
    A entrada contém um único conjunto de testes, que deve ser lido do dispositivo de entrada 
    padrão. O primeiro valor da entrada é um inteiro N (1 ≤ N ≤ 80), que indica o número de 
    questões da prova. A segunda entrada é uma cadeia de N caracteres, que indica o gabarito 
    da prova. A terceira entrada contém outra cadeia de N caracteres, que indica as opções 
    marcadas pelo candidato. Ambas as cadeias contêm apenas os caracteres A, B, C, D e E 
    (sempre em letra maiúscula).
    
    Saída:
    Seu programa deve imprimir na saída padrão uma única linha contendo um único inteiro, 
    indicando o número de acertos do candidato.
    
    Exemplos:
    entrada                     saida
    7                           4
    AEDBCCE
    ADDCCBE

    6                           5
    ABCDE
    ABCDE
    
    10                          0
    ABCDEABCDE
    BCDEABCDEA
        
*/

#include <stdio.h>
#define MAX_N 81

int main(){

    int n, i, acertos=0;
    char respostas [MAX_N];
    char prova [MAX_N];

    scanf("%d", &n);
    scanf("%s", respostas);
    scanf("%s", prova);

   for (i=0; i < n; i++)
   {
        if (prova[i] == respostas[i])
            acertos++;
   }
   printf ("%d", acertos);
   
    return 0;
}
