/*
  (***) 3. Reescreva o código da máquina para que ela costure um padrão de triângulos intercalados,
  como mostrado abaixo:
  |aaaaaavvvvvvaaaaaavvvvvvaaaaaavvvvvvaaaaaavvvvvvaaaaaavvvvvvaaaaaa |(...)
  | aaaaa vvvvv aaaaa vvvvv aaaaa vvvvv aaaaa vvvvv aaaaa vvvvv aaaaa |(...)
  |  aaaa  vvvv  aaaa  vvvv  aaaa  vvvv  aaaa  vvvv  aaaa  vvvv  aaaa |(...)
  |   aaa   vvv   aaa   vvv   aaa   vvv   aaa   vvv   aaa   vvv   aaa |(...)
  |    aa    vv    aa    vv    aa    vv    aa    vv    aa    vv    aa |(...)
  |     a     v     a     v     a     v     a     v     a     v     a |(...)
*/
#include <stdio.h>
#define LARGURA 6

int main(){

    int i, j, k=0;


    while (k != 10){

    for (i = 0; i <= LARGURA; i++){

         for (j = 0; j < i; j++)
            moveAgulha();
         for (j = LARGURA; j >= i; j--)
         {
            if (k%2==0)
                pontoRolo1();
            else
                pontoRolo2();
         }
        rolaTecido();
    }
        k++;
    }

    return (0);
}
