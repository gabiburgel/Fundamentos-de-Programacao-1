/*
  5. Escreva uma função que recebe um número com uma quantidade arbitrária de dígitos, e retorna o 
  número com os dígitos invertidos. Por exemplo, se a função receber o valor 1234, deve retornar 4321. 
  Zeros à esquerda devem ser ignorados – portanto, se a função receber o valor 1400, deve retornar 41. 
  O protótipo da função deve ser:
    unsigned int inverteNum (unsigned int n);
*/

#include <stdio.h>

unsigned int inverteNum (unsigned int n);
int main(){

  int n;

  scanf ("%u", &n);

  printf ("invertido: %u", inverteNum(n));

  return 0;
}
unsigned int inverteNum (unsigned int n){

  int invertido = 0;
  
  while (num > 0)
  {
    
    invertido = invertido*10 + n%10;
    n /= 10;
    
  }
  return invertido;
}
