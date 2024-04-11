#include <stdio.h>
#include "string_utils.h"

int main () {

    char str[50];
    int op = 0;

    scanf ("%[^\n]", str);

    while (op != 6) {

        printf ("1 - Tamanho da string\n"
                "2 - Copiar string\n"
                "3 - Converter string para letras maiusculas\n"
                "4 - Converter string para letras minusculas\n"
                "5 - Imprimir string ao contrario\n"
                "6 - Encerrar o programa\n"
                "Opcao escolhida:\n");

        scanf ("%d", &op);

        if (op == 1) {
            printf ("Tamanho da string: %d\n\n", string_length(str)+2);
        }
        else if (op == 2) {
            char dest[50];
            string_copy(str, dest);
            printf ("String copiada: %s\n\n", dest);
        }
        else if (op == 3) {
            string_upper(str);
            printf ("String convertida para maiusculas: %s\n\n", str);
        }
        else if (op == 4) {
            string_lower(str);
            printf ("String convertida para minusculas: %s\n\n", str);
        }
        else if (op == 5) {
            string_reverse(str);
            printf ("String invertida: %s\n\n", str);
        }

    }

    return 0;
}