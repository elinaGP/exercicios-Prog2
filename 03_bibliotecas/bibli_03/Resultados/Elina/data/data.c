#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano) {

    if (ano > 0) {
        if (mes > 0 && mes <= 12) {
            if (dia > 0 && dia <= numeroDiasMes(mes, ano)) {
                return 1;
            }
        }
    }
    return 0;
}

void imprimeMesExtenso(int mes) {

    switch (mes)
    {
    case 1:
        printf ("Janeiro");
        break;

    case 2:
        printf ("Fevereiro");
        break;

    case 3:
        printf ("Marco");
        break;

    case 4:
        printf ("Abril");
        break;

    case 5:
        printf ("Maio");
        break;

    case 6:
        printf ("Junho");
        break;

    case 7:
        printf ("Julho");
        break;

    case 8:
        printf ("Agosto");
        break;

    case 9:
        printf ("Setembro");
        break;

    case 10:
        printf ("Outubro");
        break;

    case 11:
        printf ("Novembro");
        break;

    case 12:
        printf ("Dezembro");
        break;
    
    default:
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {

    printf ("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf (" de %04d\n", ano);
}

int verificaBissexto(int ano) {

    if (ano % 4 == 0) {
        if (ano % 100 == 0) {
            if (ano % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int numeroDiasMes(int mes, int ano) {

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    else if (mes == 2) {
        if (verificaBissexto(ano)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {

    if (ano1 > ano2) {
        return 1;
    }
    else if (ano1 < ano2) {
        return -1;
    }
    else {
        if (mes1 > mes2) {
            return 1;
        }
        else if (mes1 < mes2) {
            return -1;
        }
        else {
            if (dia1 > dia2) {
                return 1;
            }
            else if (dia1 < dia2) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano) {

    int dias = 0;

    if (mes == 1) {
        dias = 0;
    } else if (mes == 2) {
        dias = 31;
    } else if (mes == 3) {
        dias = 59;
    } else if (mes == 4) {
        dias = 90;
    } else if (mes == 5) {
        dias = 120;
    } else if (mes == 6) {
        dias = 151;
    } else if (mes == 7) {
        dias = 181;
    } else if (mes == 8) {
        dias = 212;
    } else if (mes == 9) {
        dias = 243;
    } else if (mes == 10) {
        dias = 273;
    } else if (mes == 11) {
        dias = 304;
    } else if (mes == 12) {
        dias = 334;
    }
    if (mes >= 3 && verificaBissexto(ano))
        dias++;

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {

    int dias = 0;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) { // data1 > data2
        for (int i = ano2; i < ano1; i++) {
            if (verificaBissexto(i)) {
                dias += 366;
            } else {
                dias += 365;
            }
        }

        // somar até a d1
        dias += calculaDiasAteMes(mes1, ano1);
        dias += dia1;

        // subtrair os d2
        dias -= calculaDiasAteMes(mes2, ano2);
        dias -= dia2;
    }

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) { // data1 < data2
        for (int i = ano1; i < ano2; i++) {
            if (verificaBissexto(i)) {
                dias += 366;
            } else {
                dias += 365;
            }
        }

        // somar até a d2
        dias += calculaDiasAteMes(mes2, ano2);
        dias += dia2;
        
        // subtrair os d1
        dias -= calculaDiasAteMes(mes1, ano1);
        dias -= dia1;
    }
        
    return dias;
}