/* 
  4. A prefeitura de Curitiba está desenvolvendo um projeto-piloto para avaliar o uso do transporte
  público e testar melhorias no sistema. Um sistema de visão computacional analisa periodicamente as
  imagens enviadas por câmeras instaladas em estações tubo, contando quantos passageiros
  aguardam um ônibus. O gráfico abaixo exemplifica a ocupação de uma estação durante um dia.
  A ideia do projeto é, com base em informações sobre a ocupação das estações, otimizar o uso da frota
  e estimular o uso do transporte público. Por exemplo, é possível avaliar o impacto de um aumento do
  número de ônibus em circulação, ou mesmo de uma mudança no preço da passagem.
  
  Como parte do seu trabalho no projeto, você deve criar um pequeno programa em C para identificar
  certos padrões de comportamento na ocupação de uma estação tubo, que servirão para análises
  futuras. Os valores de entrada se referem ao número de passageiros em uma estação. Um padrão
  pode ser identificado agrupando-se esses valores 3 a 3, na ordem em que são gerados, e observando
  o segundo valor do grupo. Os padrões que devem ser identificados são:
  
  - Pico: o valor é maior que ambos os vizinhos.
  - Vale: o valor é menor que ambos os vizinhos.
  - Subida: o valor é maior que o anterior, mas menor que o próximo.
  - Descida: o valor é menor que o anterior, mas maior que o próximo.

  Por exemplo, se a sequência de valores for 0, 5, 4, 3, 3, 1, 3, 3, 4, 6, temos:
  - Um pico no segundo valor (0, 5, 4).
  - Uma descida do terceiro valor (5, 4, 3).
  - Um vale no sexto valor (3, 1, 3).
  - Uma subida no nono valor (3, 4, 6).

  O número total de valores é arbitrário. Para fornecer os valores (coletados em tempo real), outra
  pessoa da equipe escreveu a função leProximoDado, que deve ser chamada pelo seu programa
  para ler cada valor. A cada chamada, a função retorna o próximo dado, ou -1 se não existirem mais
  dados disponíveis. O protótipo da função é o seguinte:  
    int leProximoDado ();

  Para registrar os padrões, você deve usar a função registraPadrao:
    void registraPadrao (int posicao, int tipo);
  
  Essa função recebe como parâmetros a posição do valor na série e um valor que indica o tipo de
  padrão observado. Os tipos de padrão são identificados pelas macros PICO, VALE, SUBIDA e
  DESCIDA, que têm valores inteiros. No exemplo acima, a função registraPadrao seria chamada 4
  vezes, sendo que na primeira chamada teria como parâmetros 2 e PICO, e na última chamada teria 9
  e SUBIDA. Pressuponha que as duas funções, assim como as macros, já estão definidas. Ou seja,
  você deve escrever apenas a função main que recebe os dados e registra os padrões.
  
  Atenção: a função main não deve chamar as funções scanf e printf, ela deve usar as funções
  leProximoDado e registraPadrao. Você pode usar printf e scanf para simular o
  comportamento interno destas funções, já que não é possível criá-las como seriam na realidade.
  Também não use vetores, matrizes ou outras estruturas de dados que não foram vistas em aula.
*/ 

#include <stdio.h>
#define PICO
#define VALE
#define SUBIDA
#define DESCIDA

int leProxDado();
void registraPadrao(int posição, int tipo);

int main (){
    
    int ant, atual, prox;
    int i=2;
    
    ant = leProxDado();
    atual = leProxDado();
    prox = leProxDado();
        
    while (prox >= 0)
    {
        if (atual > ant && atual > prox)
            registraPadrao(i, PICO);
        else if (atual < ant && atual < prox)
            registraPadrao(i, VALE);
        else if (atual > ant && atual < prox)
            registraPadrao(i, SUBIDA);
        else if (atual > ant && atual < prox)
            registraPadrao(i, DESCIDA);
        
        ant = atual;
        atual = prox;
        prox = leProxDado();
        i++;
    }
    return (0);
}
