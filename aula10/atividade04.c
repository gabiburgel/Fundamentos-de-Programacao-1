/* 
  Escreva uma função que receba uma base b e um expoente e, e calcule o valor de b^e.
  Considere que todos os valores envolvidos são inteiros positivos. O protótipo da função deve ser:
      unsigned long long potencia (unsigned int base, unsigned int expoente);
*/

#include <stdio.h>

unsigned long long potencia (unsigned int base, unsigned int expoente);
int main (){

  int b, e;

  scanf ("%u", &b);
  scanf ("%u", &e);

  printf ("resultado: %llu", potencia(b, e));

  return 0;
}
unsigned long long potencia (unsigned int base, unsigned int expoente){

  int i;
  unsigned long long pot = 1;

   for (i=0; i < expoente; i++)
     pot *= base;  

  return pot;
}
