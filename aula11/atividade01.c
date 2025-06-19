/*
    O texto abaixo se refere às questões 1, 2, 3 e 4:

    Um amigo seu, dono de uma tecelagem, tem uma máquina muito antiga, que é usada para 
    costurar padrões vermelhos e azuis em faixas de tecido com 6 cm de largura. Prestes a
    se desfazer da máquina, seu amigo lembrou-se que ela continha um antigo disquete de 3.5”.
    Com a ajuda de um velho computador, vocês conseguiram analisar o conteúdo do disquete, 
    e para sua surpresa, ali estava a programação do padrão que a máquina deveria costurar 
    – em uma versão interpretada da linguagem C! Este é o programa encontrado:

    #define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. 

    void main ()

    {

        int i;
        
        Funciona até desligar ou o tecido acabar. 
        While (1)
        {
            for (i = 0; i < LARGURA_FAIXA; i++)
            {
                if (i == 1)
                pontoRolo1 ();
                
                else if (i == LARGURA_FAIXA-2)
                pontoRolo2 ();

                else
                moveAgulha ();
            }

            rolaTecido ();
        }
    }

    Analisando o código, você inferiu que o sistema tem algumas funções embutidas:
    - pontoRolo1: a máquina faz um ponto de 1cm usando a linha do rolo 1 (vermelha).
    - pontoRolo2: a máquina faz um ponto de 1cm usando a linha do rolo 2 (azul).
    - moveAgulha: a máquina move a agulha 1cm para baixo, sem dar ponto.
    - rolaTecido: a máquina leva a agulha novamente ao topo da faixa, sem dar ponto, 
    e move a faixa de tecido 1 cm para a esquerda.

    O padrão desenhado por este código pode ser descrito da seguinte forma (v indica um 
    ponto com a linha vermelha, a um ponto com a linha azul, (...) que o padrão se repete 
    indefinidamente):

    |
    |vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv|(...)
    |
    |
    |aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa|(...)
    |

    (**) 1. Seu amigo resolveu que pode ser interessante, em vez de se desfazer da máquina, 
    modificar a sua programação. Mas como você não vai ficar desperdiçando material, resolveu 
    analisar o comportamento do código que já estava lá no seu computador. Isso gera um problema:
    como fazer um teste se o código tem funções embutidas da máquina?
    Seu primeiro objetivo é criar funções que possam simular no seu computador o comportamento 
    da máquina. Para isso, você deve implementar “substitutas” para as funções pontoRolo1,
    pontoRolo2, moveAgulha, e rolaTecido. Você deve ser capaz de executar o programa original 
    da máquina sem modificações, de forma que através das funções “substitutas” ele gere algo 
    análogo ao padrão costurado.
*/

#include <stdio.h>

    void pontoRolo1()
    {
        printf ("v");
    }
     void pontoRolo2()
     {
        printf ("a");
     }
     void moveAgulha()
     {
        printf (" ");
     }
     void rolaTecido()
     {
        printf ("\n");
     }
