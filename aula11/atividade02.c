/*
  2. A pedido do seu amigo, reescreva o código da máquina para que ela costure o padrão abaixo:
  |avvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavvvvvvavv|(...)
  |aavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaavvvvvaav|(...)
  |aaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaavvvvaaa|(...)
  |aaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaaavvvaaa|(...)
  |aaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaaaavvaaa|(...)
  |aaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaaaaavaaa|(...)
*/
#include <stdio.h>
#define LARGURA 6

int main (){

  int i, j, k=0;

  while (k != 10)
  {
      for (i=0; i < LARGURA; i++)
      {
        for (j = 0; j <= i; j++)
            pontoRolo1();
        for (j = LARGURA; j >= i; j--)
            pontoRolo2();
        rolaTecido();  
      }
      k++;
  }
  return (0);
}
