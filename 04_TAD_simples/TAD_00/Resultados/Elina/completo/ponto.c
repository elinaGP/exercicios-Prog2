#include "ponto.h"
#include <stdio.h>
#include <math.h>

Ponto pto_cria (float x, float y) {

    Ponto pto;
    pto.x = x;
    pto.y = y;
    return pto;
}

float pto_acessa_x (Ponto p) {

    return p.x;
}

float pto_acessa_y (Ponto p) {

    return p.y;
}

Ponto pto_atribui_x (Ponto p, float x) {

    p.x = x;
    return p;
}

Ponto pto_atribui_y (Ponto p, float y) {

    p.y = y;
    return p;
}

float pto_distancia (Ponto p1, Ponto p2) {

    float dist=0;
    dist = sqrt(pow(p2.x - p1.x, 2.0) + pow(p2.y - p1.y, 2.0));
    return dist;
}