/*
  AUTOR: Gabriela Burgel
  Projeto 01 da disciplina ICSF13 - Fundamentos de Programação 1
  Profs. Bogdan T. Nassu, Leyza E. B. Dorini e Daniel F. Pigatto
  Universidade Tecnológica Federal do Paraná
  Maio de 2025
*/

#include <stdio.h>
#include <math.h>
#include "trabalho1.h"

//===============================================================================================

/* FUNÇÃO 01
calcula quanto um cliente deve pagar em um restaurante por quilo, é considerado um valor fixo
e um preço variável com desconto que pode aumentar de acordo com as faixas de peso, que vao
aumentando, até chegar no desconto maximo permitido ou calcular todo o peso da comida. */

//===============================================================================================

float calculaValorDevido (float peso, float custo_fixo, float preco_kg,
                          float largura_faixa, float desconto_faixa, float desconto_max)
{
    float valor_total = custo_fixo; //começa com o valor fixo
    float peso_sobrando = peso;     // controla o peso total que ainda falta

    int faixa; //contador das faixas de desconto

    for (faixa=0; peso_sobrando>0.0; faixa++){
    /* o loop passa pelas faixas de acordo com o peso, a cada volta, calcula o valor
    conforme a "largura_faixa", aplicando o desconto da faixa */

        float desconto;      // guarda o desconto aplicado em cada faixa, aumentando a cada volta
        float peso_da_faixa; // quanto de peso vai ser cobrado na faixa atual

        desconto = faixa * desconto_faixa; // calcula o desconto na faixa atual

        if (desconto > desconto_max) // garante que o desconto nao ultrapasse o desconto maximo
            desconto = desconto_max;

        peso_da_faixa = largura_faixa; // quantos gramas sao contados na faixa atual

        if (peso_sobrando < largura_faixa) // se o peso a ser calculado for menor que a largura da faixa é usado
            peso_da_faixa = peso_sobrando; // apenas o que sobrar, evitando calcular mais do que o cliente consumiu

        /* agora se calcula o valor da faixa atual:
        - converte de gramas pra kg (dividindo por 1000)
        - multiplica pelo preço por kg
        - aplica o desconto (100% menos o desconto) */
        valor_total += (peso_da_faixa/1000.0) * preco_kg * (1.0 - desconto);

        peso_sobrando -= peso_da_faixa; //atualiza o peso que falta ser calculado
    }
    return (valor_total);
}

//===============================================================================================

/* FUNÇÃO 02
a função recebe quatro caracteres e transforma eles em um unico numero inteiro de 32 bits, esse numero
é formado juntando o valor de cada caractere (da tabela ASCII), cada um ocupando 1 byte desse número */

//===============================================================================================

unsigned int fourcc(char c1, char c2, char c3, char c4) {
    /* cada caractere do tipo char vai ser armazenada nas variaveis "byte" para guardar seu valor
    quando convertido termporariamente em número e multiplicado por uma  potencia de 2, que vai
    deslocar seus bits, representando no fim, a posição dele dentro dos 32 bits do resultado final */
    unsigned int byte1;
    unsigned int byte2;
    unsigned int byte3;
    unsigned int byte4;
    unsigned int resultado;

    byte1 = (unsigned int)c1 * 1;
    // multiplica por 2^0, que é sua propria posição (mais da direita - bits de 0 a 7)
    byte2 = (unsigned int)c2 * 256;
    // multiplica por 2^8 para deslocar na posição dos bits de 8 a 15
    byte3 = (unsigned int)c3 * 65536;
    // multiplica por 2^16 para deslocar para o terceiro byte (de 16 a 23)
    byte4 = (unsigned int)c4 * 16777216;
    // multiplica por 2^24 para deslocar para a posição de bits de 24 a 31

    resultado = byte1 | byte2 | byte3 | byte4;
    /* usa o operador que compara bit a bit e tranforma em 1 sempre que tiver pelo menos 1 uma vez,
    combinando as 4 partes em um unico numero. Como cada um esta ocupando uma região diferente, elas
    nao passam "uma por cima da outra" */

   return (resultado);
}

//===============================================================================================

/* FUNÇÃO 03
calcula a raiz quadrada aproximada de um numero chutando valores no meio de um intervalo,
e vai ajustando esse intervalo até o chute ficar bem perto da raiz de verdade, quando esse
chute estiver perto suficiente do resultado, ele retorna para a main */

//===============================================================================================

double raizAproximada(double x, double erro_minimo){

    double limite_inicial;
    double limite_superior;
    double quadrado;
    double palpite;

    if (x >= 1){                // se o numero for maior que 1, vamos procurar a raiz dele, que
        limite_inicial = 0;    // vai ser um numero entre 0 e ele mesmo
        limite_superior = x;
    }
    if (x < 1){
        limite_inicial = 0;    // se o numero for menor que 1, a sua raiz vai estar entre 0 e 1
        limite_superior = 1;
    }

    palpite = (limite_inicial + limite_superior)/2.0;
    // calculamos a média entre o intervalo possivel, para chutarmos um numero

    quadrado = palpite * palpite;
    // calculamos o quadrado desse chute para comparar com o numero original

    while ((quadrado - x >= erro_minimo) || (x - quadrado >= erro_minimo)) {
    // loop que continua enquanto a diferença entre quadrado e x for maior ou igual ao erro_minimo

        if (quadrado > x)
            limite_superior = palpite;
            /* se o quadrado do chute for maior que o numero, significa que chutamos um numero
            muito alto, então diminuimos o limite superior para tentar um chute menor */
        else
            limite_inicial = palpite;
            /* se o quadrado do chute for menor que o numero, significa que chutamos um numero
             muito baixo, então aumentamos o limite inicial para tentar um chute maior */

        palpite = (limite_inicial + limite_superior)/2.0;
        // calcula um novo palpite, que é novamente a media entre os dois limites

        quadrado = palpite * palpite;
        // é calculado novamente o quadrado do palpite para ser usado na condiçao
    }

    return (palpite);
}
