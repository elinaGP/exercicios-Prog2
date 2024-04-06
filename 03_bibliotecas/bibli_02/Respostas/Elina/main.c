#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () {

    int rows1=0, cols1=0, rows2=0, cols2=0;
    int op=0, num_mat=0, scalar=0;

    scanf ("%d %d", &rows1, &cols1);

    int mat1[rows1][cols1];

    matrix_read(rows1, cols1, mat1);

    scanf ("%d %d", &rows2, &cols2);

    int mat2[rows2][cols2];

    matrix_read(rows2, cols2, mat2);

    while (op!=6) {

        printf ("1 - Somar matrizes\n"
            "2 - Subtrair matrizes\n"
            "3 - Multiplicar matrizes\n"
            "4 - Multiplicacao de uma matriz por escalar\n"
            "5 - Transposta de uma matriz\n"
            "6 - Encerrar o programa\n"
            "Opcao escolhida:\n");

        scanf("%d", &op);

        if (op==1) {

            if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, mat1, rows2, cols2, mat2, result);
                matrix_print(rows1, cols1, result);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }

        if (op==2) {

            if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, mat1, rows2, cols2, mat2, result);
                matrix_print(rows1, cols1, result);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }

        if (op==3) {

            if (possible_matrix_multiply(cols1, rows2)) {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, mat1, rows2, cols2, mat2, result);
                matrix_print(rows1, cols2, result);
            }
            else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }

        if (op==4) {

            scanf ("%d %d", &scalar, &num_mat);

            if (num_mat==1) {
                scalar_multiply(rows1, cols1, mat1, scalar);
                matrix_print(rows1, cols1, mat1);
            }
            else {
                scalar_multiply(rows2, cols2, mat2, scalar);
                matrix_print(rows2, cols2, mat2);
            }
        }

        if (op==5) {

            int result1[cols1][rows1], result2[cols2][rows2];
            transpose_matrix(rows1, cols1, mat1, result1);
            transpose_matrix(rows2, cols2, mat2, result2);
            matrix_print(cols1, rows1, result1);
            printf("\n");
            matrix_print(cols2, rows2, result2);
        }

        printf("\n");
    }

    return 0;    
}