/*
  6. Escreva uma função que recebe um caractere e retorna 1 se o caractere for uma vogal maiúscula, 
  2 se for uma vogal minúscula, 3 se for uma consoante maiúscula, 4 se for uma consoante minúscula, 
  5 se for um dígito, e 0 do contrário. O protótipo da função deve ser:
        int testaTipoChar (char c);
    Dica: observe atentamente como é a tabela ASCII. Você não precisa usar NENHUM valor dela, mas
    entender a forma como os caracteres estão dispostos pode ajudar.
  */

#include <stdio.h>

int testaTipoChar (char c);
int main(){

  char caractere;
  scanf ("%c", &caractere);

  printf ("%d", testaTipoChar(caractere));
  
  return 0;
}
int testaTipoChar (char c){

  if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    return (1);
      
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return (2);
  
  if (c > 'A' && c <= 'Z')
    return (3);
  
  if (c > 'a' && c <= 'z')
    return (4);
  
  if (c >= '0' && c <= '9')
    return (5);
  
  return (0);
}
