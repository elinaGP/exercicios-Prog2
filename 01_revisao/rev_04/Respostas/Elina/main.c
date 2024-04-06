#include <stdio.h>
#include <stdlib.h>

int tamanhoNum (int num) {

    int cont=0;
    int div=1;
    while (div != 0) {
        div = num/8;
        num = div;
        cont++;
    }

    return cont;
}

void inverteVetor (int vetor[], int TAM) {

    int box=0, aux=0;

    for (int cont=TAM-1; cont >= TAM/2; cont--) {

        box = vetor[aux];
        vetor[aux] = vetor[cont];
        vetor[cont] = box;

        aux++;
    }
}

int main () {

    int num_decimal=0;
    int TAM=0;

    scanf ("%d", &num_decimal);

    TAM = tamanhoNum(num_decimal);
    int vetor[TAM];

    for (int cont=0; cont<TAM; cont++) {
        vetor[cont] = num_decimal%8;
        num_decimal = num_decimal/8;
    }

    inverteVetor(vetor, TAM);

    for (int cont=0; cont<TAM; cont++) {
        printf ("%d", vetor[cont]);
    }

    printf ("\n");
    return 0;
}