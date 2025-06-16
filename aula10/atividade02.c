/*
  2. Escreva uma função que retorna apenas a parte não-inteira de um número dado. Por exemplo,
  se a função receber o valor 1.43, deve retornar 0.43. O protótipo da função deve ser:
  double casasDecimais (double x); 
*/

#include <stdio.h>

double casasDecimais (double x); 
int main(){
  
  double num;
  scanf ("%lf", &num);

  printf ("parte decimal: %lf", casasDecimais(num));

  return 0;
}
double casasDecimais (double x){

  return (x - (int) x);
}
