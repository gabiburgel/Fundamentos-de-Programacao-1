/*
    2. Escreva um programa que imprima a tabuada de um número n dado (1 x n até 10 x n). Faça
    duas versões do programa, uma usando while e a outra for.
*/

int main (){

    int n, i;
    int tabuada;

    scanf ("%d", &n);

    i = 0;
    while (i<=10){

        tabuada = i * n;
        printf ("%d x %d = %d\n", i, n, tabuada);
        i++;
}
    for (i=0; i<=10; i++){

        tabuada = i * n;
        printf ("%d x %d = %d\n", i, n, tabuada);
    }
    return (0);
}
