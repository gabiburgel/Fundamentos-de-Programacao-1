/*
    (**) 6. Em uma competição de saltos ornamentais, 6 juízes dão suas notas, que podem variar 
    entre 0 e 10 (incluindo valores “quebrados”). A nota final do atleta deve excluir a maior e 
    a menor nota dos juízes e é composta pela média das quatro notas restantes - esta é uma 
    variação simples de um conceito conhecido como “média truncada”. Faça um programa que lê
    do usuário as seis notas dos juízes e informa a nota final do atleta.
*/
#include <stdio.h>
int main(){
    
    int i;
    float nota;
    float media;
    float acum=0;
    float maior=0.0, menor=10.0;
    
    for (i=0; i<6; i++){
        scanf("%f", &nota);
        acum += nota;
        
        if (maior<nota)
            maior = nota;
        if (menor>nota)
            menor = nota;
    }
    
    media = (acum - maior - menor) / 4;
    printf("Nota final: %.2f\n", media);
    
    return (0);
}
