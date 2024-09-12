#include <stdio.h>
#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG) {

    tEleitor eleitor;

    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;

    return eleitor;
}

tEleitor LeEleitor() {

    tEleitor eleitor;
    int id=-1, votoP=-1, votoG=-1;

    scanf ("%d %d %d", &id, &votoP, &votoG);
    eleitor = CriaEleitor(id, votoP, votoG);

    return eleitor;
}

int ObtemVotoPresidente(tEleitor eleitor) {

    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor) {

    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2) {

    if (eleitor1.id == eleitor2.id) {
        return 1;
    }
    return 0;
}