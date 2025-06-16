/* 
 1. Escreva uma função que arredonda um valor dado. O número deve ser arredondado para o
 inteiro mais próximo. Se o número for equidistante de dois inteiros, deve ser arredondado para
 o valor de maior magnitude. Ou seja, 1.5 é arredondado para 2, e -1.5 é arredondado para -2. 
 O protótipo da função deve ser:
   int arredonda (double x);
*/

#include <stdio.h>
int arredonda (double x);
int main (){

  double num;
  scanf ("%lf", &num);

  printf ("%d", arredonda(num);

  return 0;
}

int arredonda (double x)
{
  if (x >= 0)
  return ((int) (x + 0.5));
  
  return ((int) (x - 0.5));
}
  
