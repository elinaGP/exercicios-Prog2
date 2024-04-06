#include <stdio.h>
#include <stdlib.h>

int main () {

    int num_livros=0;
    int rep=0, aux=0;

    scanf ("%d", &num_livros);

    int vetor[num_livros];

    for (int i=0; i<num_livros; i++) {
        scanf ("%d", &vetor[i]);
    }

    for (int i=0; i<num_livros; i++) {

        for (int cont=0; cont<num_livros; cont++) {

            if (vetor[i] == vetor[cont]) {
                rep++;
            }
        }

        if (rep == 1) {
            printf ("%d ", vetor[i]);
            aux++;
        }

        rep = 0;
    }

    if (aux == 0) {
        printf ("NENHUM");
    }

    printf ("\n");
    return 0;
}