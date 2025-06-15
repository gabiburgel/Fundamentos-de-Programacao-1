/* 5. Escreva um programa que imprima losangos formados por caracteres ASCII. O usuário deve especificar o 
caractere que será usado, e fornecer um número n. A largura do losango no centro deve ser igual a 2n+1 
caracteres. A cada linha acima ou abaixo do centro, a largura é reduzida em 2 caracteres. Para manter o 
formato do losango, use espaços antes dos caracteres visíveis. 
Por exemplo, se o caractere é '#' e n é igual a 2, a saída do programa é:
  #
 ###
#####
 ###
  #
Se o caractere é '@' e n é igual a 5, a saída do programa é:
     @
    @@@
   @@@@@
  @@@@@@@
 @@@@@@@@@
@@@@@@@@@@@
 @@@@@@@@@
  @@@@@@@
   @@@@@
    @@@
     @
*/

#include <stdio.h>

int main(){
  char simbolo;
  int n, i, j;
  int caracteres, espacos;

  scanf ("%c", &simbolo);
  scanf ("%d", &n);

  for (i=0; i <= n; i++){

      espacos = n - i;
      caracteres = 2 * i + 1;

      for (j=0; j < espacos; j++)
          printf (" ");

      for (j=0; j < caracteres; j++)
          printf ("%c", simbolo);

      printf ("\n");
  }

  for (i = n-1; i >= 0; i--){

      espacos = n - i;
      caracteres = 2 * i + 1;

      for (j=0; j < espacos; j++)
          printf (" ");

      for (j=0; j < caracteres; j++)
          printf ("%c", simbolo);

      printf ("\n");
  }
  return 0;
}
