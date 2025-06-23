/*
  AUTOR: Gabriela Burgel e Vitor Henrique Rossi de Souza
  RAs: 2757044 e 2752360
  Profs. Bogdan T. Nassu, Leyza E. B. Dorini e Daniel F. Pigatto
  Universidade Tecnológica federal do Paraná
  Projeto 02 da disciplina ICSF13 - Fundamentos de Programacao 1
  Junho de 2025
*/

/*============================================================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "wavfile.h"
#include "trabalho2.h"

/*============================================================================================================= */

/* 
  FUNÇÃO 01
    Essa função tem o objetivo de modificar o ganho (volume) de um sinal, representado pelo vetor "dados", de tamanho
    representado por "n_amostras". Multiplicando cada amostra por um valor (o parametro "ganho"). Com isso, o volume
    eh alterado, e também afeta a fase - se o ganho for negativo. Por exemplo: 
    Se o ganho for 2.0, o valor dobra e o volume aumenta.
    Se o ganho for 0.0, a amostra zera e o audio silencia.
    Se o ganho for -1.0, o valor inverte o sinal e muda a fase (acontece um espelhamento).

*/

/*============================================================================================================== */

void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i;                                // criamos um contador para iniciar o loop
    for ( i = 0; i < n_amostras; i++)     // fizemos um loop que percorre todos os índices do vetor
    {
        dados [i] *= ganho;               // multiplicamos a amostra atual pelo valor ganho, afetando
                                          // diretamente o vetor original
    }
}

/*============================================================================================================== */

/* 
  FUNÇÃO 02
    Essa função tem o objetivo de simular uma subamostragem, ou seja, ela cria “degraus”, deixando o sinal com 
    valores constantes a cada trecho, isso faz com que ocorra a perca de detalhes, e simule uma alteração na 
    qualidade do som.
    Ela faz isso dividindo o vetor "dados", de tamanho "n_amostras", em blocos de tamanho "n_constantes"
    (quantidade de amostras por degrau), e substitui todas as amostras de cada bloco pelo valor da primeira 
    amostra daquele bloco. Por exemplo:
    Se n_constantes for 5, as amostras de índice 0 a 4 ficam todas com o valor de dados[0], então as 
    amostras do índice 5 a 9 ficam com o valor de dados[5], e assim por diante.
*/

/*============================================================================================================== */

void simulaSubAmostragem (double* dados, int n_amostras, int n_constantes)
{
    int i, j = 0;  // usamos 2 contadores: i para contar de bloco em bloco
                   // e j para percorrer as amostras do bloco atual 

    for(i = 0; i < n_amostras; i += n_constantes) // percorremos os blocos de n_constantes em n_constantes
    {
        for(j = i; j < i + n_constantes && j < n_amostras; j++)  
        // percorremos os blocos de tamanho n_constantes. j inicia de i e vai até i + n_constantes (ou até o fim do vetor)
        {
            dados[j] = dados[i]; // substituimos o valor do índice atual e trocamos pelo valor do primeiro índice do bloco
        }
    }
}

/*============================================================================================================== */

/* 
  FUNÇÃO 03
    Essa função coloca ruídos pontuais em um sinal, que simula um efeito de estalos. Cada estalo eh uma amostra
    (um índice do vetor isolado), que recebe um valor muito diferente dos restantes. O espaçamento ("intervalo") 
    entre esses estalos são espalhados de forma aleatória, entre 1 e "intervalo_max", assim como também sorteamos
    a posição do primeiro estalo dessa forma. Além disso, a cada novo estalo o valor eh invertido, alternando 
    entre positivo e negativo. Por exemplo:
    Um vetor de tamanho 10 com todos os valores iguais a 0: dados = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    Se intervalo_max = 3 e valor1 = 2, a função pode inserir estalos (valores aleatórios) assim:
    dados = [0, 2, 0, 0, -2, 0, 0, 2, 0, -2] (alternam entre positivo e negativo).

*/

/*============================================================================================================== */

void estalos (double* dados, int n_amostras, int intervalo_max, double valor1)
{
    int intervalo, estalo = 0;     // "estalo" guarda a posição onde será inserido o próximo estalo 
                                   // "intervalo" define o espaçamento entre esses estalos
    double valor_estalo;           // "valor_estalo" armazena o valor do estalo

    srand(time(0));                // inicializamos a geração de números aleatórios 

    intervalo = rand()%intervalo_max;  // sortemos o primeiro intervalo, entre 0 e "intervalo_max"
    estalo += intervalo;               // defimos a posição do primeiro estalo
    valor_estalo = valor1;             // definimos o valor do primeiro estalo

    while(estalo<n_amostras)
    // iniciamos um loop que "gira" enquanto ainda não acabarem os espaços do vetor, para receber os estalos
    {
        dados [estalo] = valor_estalo;          // aqui inserimos os estalos na posição sorteada
        valor_estalo = -valor_estalo;           // invertemos o valor para o proximo estalo 
        intervalo = (rand()%intervalo_max)+1;   // sorteamos novamento o espaçamento para o próximo estalo
        estalo += intervalo;                    // atualizamos a posição do próximo estalo
    }
}

/*============================================================================================================== */

/* 
  FUNÇÃO 04
    Essa função tem como objetivo remover os "estalos" de um sinal. Como esses estalos são valores muito diferentes
    dos valores vizinhos do vetor, podemos fazer isso achando a mediana a cada 3 casas do vetor - para cada índice
    (exceto o primeiro e o último), ele analisa tambem os índices vizinhos (o anterior e o próximo), em seguida, 
    substituimos o índice central pela mediana desses 3 valores. Por exemplo:
    Podemos imaginar o vetor: dados [1, 50, 2]
    No índice 1, o valor 50 representa um estalo, a mediana deles, é igual a 2. Então, o 50 será substituido por 2,
    eliminando o estalo.
*/

/*============================================================================================================== */

void removeEstalos (double* dados, int n_amostras)
{
    int i;                             // criamos um contador i
    double anterior, meio, proximo;    // criamos 3 variáves para fazer a janela deslizante entre as amostras do vetor
    double mediana, aux;               // criamos uma variável para guardar a mediana  e uma auxiliar para usarmos  
                                       // na janela deslizante

    anterior = dados [0];              // atribuimos o valor da posição anterior
    meio = dados [1];                  // atribuimos o valor da posição atual
    proximo = dados [2];               // atribuimos o valor da proxima posição

    for (i = 1; i < n_amostras - 1; i++) 
    // o loop percorre o vetor "dados", a partir do índice 1 até o penúltimo índice 
    {
        if ((meio>=anterior && meio<=proximo) || (meio>=proximo && meio<=anterior)) 
        // verificamos se o valor do meio está entre os outros dois 
           mediana = meio;
           // se estiver, ele eh a mediana

        else if ((anterior>=meio && anterior<=proximo) || (anterior<=meio && anterior>=proximo))
        // caso não seja o valor do meio, verificamos se o valor anterior está estre os outros dois
            mediana = anterior;
            // se estiver, o anterior eh a mediana

        else
            mediana = proximo;  // caso não seja nenhum dos dois, o próximo eh a mediana

        dados [i] = mediana;    // substituimos o valor da posição atual pela mediana 
        
        // agora atualizamos os valores para a próxima interação do loop
        aux = meio;               // "aux" guarda valor do antigo "meio"
        meio = proximo;           // o "meio" vira o novo anterior
        proximo = dados[i+1];     // guardamos o próximo valor 
        anterior = aux;           // move o "meio" anterior para a variável "anterior"
    }
}

/*============================================================================================================== */

/* 
  FUNÇÃO 05
    Essa função tem como objetivo gerar uma onda quadrada dentro do vetor "dados" de tamanho n_amostras, esas onda
    é como um sinal sonoro que alterna entre os valores fixos: 1 e -1. Isso significa que, a cada ciclo completo, a 
    onda fica um tempo com valor 1 (meio ciclo), e depois de um tempo com o valor -1 (outro meio ciclo). A frequência 
    indica quantos ciclos ocorrem por segundo, e por fim, a taxa de amostragem indica quantas amostras sao geradas 
    a cada segundo. A função calcula o "período" de um ciclo (número de amostras) e divide ele ao meio para formar
    os blocos de 1 e -1. Como esse meio período pode ser um número decimal, usamos apenas a parte inteira dele, e o
    valor decimal que sobrar dele se torna o "erro_aculumado", que, como o nome já diz, eh acumulado para que seja 
    compensado nos próximos ciclos, ajudando a manter a precisão ao longo do tempo, e não deixando a onda "atrasada".
    Por exemplo:
    Se a frequência for 10.7 Hz e a taxa de amostragem for 44100, o meio-período será de aproximadamente 2060.75 amostras.
    Dessa forma, no primeiro ciclo, o sinal terá 2060 amostras com valor 1, e 2061 com valor -1.
    Então, no segundo ciclo, essa diferença será compensada: o próximo bloco pode ter 2061 com valor 1 e 2060 com valor -1.
*/

/*============================================================================================================== */

void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq)
{
    int meio_periodo_int;        // declaramos a variável para a parte inteira das amostras do meio período
    int tamanho_bloco;           // variável com o número de amostras que vão ser preenchidas a cada ciclo
    double meio_periodo_orig;    // variável que guarda o número exato de amostras (com decimal)

    double valor = 1, erro_acumulado = 0.0; 
    // declaramos e inicializamos a variável que guarda o valor do sinal (1 ou -1) e outra para armazenar o erro acumulado

    int i = 0, j = 0; 
    // usaremos 2 contadores para loops diferentes: i para percorrer o vetor "dados" e j para preencher cada bloco

    meio_periodo_orig = taxa / (freq * 2.0); 
    // calculamos o meio período original (o qual pode ter a parte decimal) 
    // um período tem duração de taxa/freq, então dividimos por 2 para obter o meio período

    meio_periodo_int = (int) meio_periodo_orig;
    // guardamos a parte inteira do meio período 

    while (i < n_amostras)
    // fizemos um loop para percorrer todas as amostras do vetor "dados"

    {
        tamanho_bloco = meio_periodo_int;
        // inicializamos toda volta do loop a variável de tamanho do bloco com o valor inteiro do meio período

        erro_acumulado += meio_periodo_orig - meio_periodo_int;
        // acumulamos o erro, somando a ele apenas a parte decimal do meio período

        if (erro_acumulado >= 1.0)
        // aqui usamos um if para verificar se o erro acumulado já chegou a 1.0, se sim, significa que podemos compensar ele
        {
            tamanho_bloco += 1;      // aumentamos o bloco atual em 1 amostra
            erro_acumulado -= 1.0;   // e removemos o 1.0 do erro acumulado que já compensamos
        }
    
        for(j = 0; j < tamanho_bloco && i < n_amostras; j++)
        // o loop preenche "j" até o tamanho do bloco ou o final do vetor "dados"
        {
            dados [i] = valor;  // preenchemos o vetor "dados" na posição "i" com o valor atual (1 ou -1)  
            i++;             
        }

        valor = -valor; // após preencher um ciclo de meio período, invertemos o valor (de 1 para -1 ou vice-versa)   
    }
}

/*============================================================================================================== */

/* 
  FUNÇÃO EXTRA
    Essa função gera uma senoide, que é uma onda suave e periódica, usando a função seno (sin). Para isso, ela calcula
    o ângulo inicial (fase) e um incremento de ângulo para cada amostra, baseado na frequência e na taxa de amostragem. 
    Assim, ela preenche o vetor "dados" com valores que descrevem uma senoide ao longo do tempo, formando uma onda contínua.
    Para gerar essa onda, calculamos um aumento do ângulo que deve ser somado a cada amostra para simular a passagem do tempo),
    depois, para cada posição do vetor, calculamos o seno do ângulo atual e armazenamos no próprio vetor, assim, ao final
    temos um sinal sonoro com o formato da onda senoide. 
*/

/*============================================================================================================== */

void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase)
{
    double angulo;   // declaramos variável para o ângulo atual, que será usado na função seno
    double aumento;  // declaramos a variável que representa o aumento do ângulo a cada amostra
    int i;

    angulo = fase;   // inicializamos o ângulo com a fase inicial fornecida

    // agora calculamos quanto o ângulo deve crescer entre uma amostra e outra
    aumento = (freq / taxa) * 2 * TRAB_PI; 
    // (freq / taxa) resulta em quantos ciclos completos acontecem por amostra 
    // multiplicamos por 2π (TRAB_PI*2) para converter em radianos

    for (i = 0; i < n_amostras; i++)
    // fizemos um loop que percorre o vetor "dados"
    {
        dados [i] = sin(angulo); // preenchemos o vetor com o cálculo do seno no ângulo atual
        angulo += aumento;       // incrementamos o ângulo com o aumento para a próxima passagem no loop
    }
}
