#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]) {

    for (int contR=0; contR<rows; contR++) {
        for (int contC=0; contC<cols; contC++) {
            scanf ("%d", &matrix[contR][contC]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]) {

    for (int contR=0; contR<rows; contR++) {
        printf("|");
        for (int contC=0; contC<cols; contC++) {
            printf ("%d", matrix[contR][contC]);
            if (contC < cols-1) {
                printf (" ");
            }
        }
        printf ("|\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2) {

    if (rows1 == rows2 && cols1 == cols2) {
        return 1;
    }

    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2) {

    if (rows1 == rows2 && cols1 == cols2) {
        return 1;
    }

    return 0;
}

int possible_matrix_multiply(int cols1, int rows2) {

    if (cols1 == rows2) {
        return 1;
    }

    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {

    for (int contR=0; contR<rows1; contR++) {
        for (int contC=0; contC<cols1; contC++) {
            result[contR][contC] = matrix1[contR][contC] + matrix2[contR][contC];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {

    for (int contR=0; contR<rows1; contR++) {
        for (int contC=0; contC<cols1; contC++) {
            result[contR][contC] = matrix1[contR][contC] - matrix2[contR][contC];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {

    for (int contR=0; contR<rows1; contR++) {
        for (int contC=0; contC<cols2; contC++) {
            result[contR][contC] = 0;
            for (int k = 0; k < rows2; k++) {
                result[contR][contC] += matrix1[contR][k] * matrix2[k][contC];
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {

    for (int contR=0; contR<rows; contR++) {
        for (int contC=0; contC<cols; contC++) {
            result[contC][contR] = matrix[contR][contC];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar) {

    for (int contR=0; contR<rows; contR++) {
        for (int contC=0; contC<cols; contC++) {
            matrix[contR][contC] = scalar * matrix[contR][contC];
        }
    }
}