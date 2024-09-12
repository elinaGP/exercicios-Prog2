#include "ponto.h"

int main () {

    float x1=0, y1=0, x2=0, y2=0, dist_float=0;
    int dist_int=0; 
    Ponto pto1, pto2;

    scanf ("%f %f %f %f", &x1, &y1, &x2, &y2);

    pto1 = pto_cria(x1, y1);
    pto2 = pto_cria(x2, y2);

    dist_float = pto_distancia(pto1, pto2);
    dist_int = pto_distancia(pto1, pto2);

    if (dist_float - dist_int == 0) {
        printf ("%d", dist_int);
    }
    else {
        printf ("%.3f", dist_float);
    }

    return 0;
}