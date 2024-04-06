#include <stdio.h>
#include <stdlib.h>

int main () {

    int n=0;
    int cont=1, i=1, j=1;

    scanf ("%d", &n);

    for (cont=1; cont<=n; cont++) {
        
        for (i=1; i<=cont; i++) {
            printf ("%d ", j);
            j++;
        }
        printf ("\n");
    }

    return 0;
}