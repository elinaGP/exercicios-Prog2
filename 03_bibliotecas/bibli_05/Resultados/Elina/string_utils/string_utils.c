#include <stdio.h>
#include "string_utils.h"

int string_length(char *str) {

    int tam=0;

    while (str[tam] != '\0') {
        tam++;
    }

    return tam;
}

void string_copy(char *src, char *dest) {

    for (int cont=0; src[cont] != '\0'; cont++) {
        dest[cont] = src[cont];
    }
}

void string_upper(char *str) {

    int cont=0;

    while (str[cont] != '\0') {

        if (str[cont] >= 97 && str[cont] <= 122) {
            str[cont] -= 32;
        }

        cont++;
    }
}

void string_lower(char *str) {

    for (int cont=0; str[cont] != '\0'; cont++) {

        if (str[cont] >= 65 && str[cont] <= 90) {
            str[cont] += 32;
        }
    }
}

void string_reverse(char *str) {

    char aux='0';
    int tam=0;
    tam = string_length(str) - 1;

    for (int cont=0; cont <= tam; cont++) {
        aux = str[cont];
        str[cont] = str[tam];
        str[tam] = aux;
        tam--;
    }
}