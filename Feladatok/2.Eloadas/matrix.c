#include "matrix.h"

#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

void multiply_matrix_scalar(float matrix[3][3], float scalar)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] *= scalar;
}

void multiply_matrices(const float a[3][3], const float b[3][3], float result[3][3])
{
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0.0f;
            for (k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transform_point(const float matrix[3][3], float* x, float* y)
{
    float new_x = matrix[0][0] * (*x) + matrix[0][1] * (*y) + matrix[0][2];
    float new_y = matrix[1][0] * (*x) + matrix[1][1] * (*y) + matrix[1][2];

    *x = new_x;
    *y = new_y;
}

void scale(float matrix[3][3], float sx, float sy)
{
    float s[3][3];
    init_identity_matrix(s);

    s[0][0] = sx;
    s[1][1] = sy;

    float temp[3][3];
    multiply_matrices(matrix, s, temp);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = temp[i][j];
}

void shift(float matrix[3][3], float tx, float ty)
{
    float t[3][3];
    init_identity_matrix(t);

    t[0][2] = tx;
    t[1][2] = ty;

    float temp[3][3];
    multiply_matrices(matrix, t, temp);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = temp[i][j];
}

void rotate(float matrix[3][3], float angle)
{
    float r[3][3];
    init_identity_matrix(r);

    float rad = angle * M_PI / 180.0f;

    r[0][0] = cos(rad);
    r[0][1] = -sin(rad);
    r[1][0] = sin(rad);
    r[1][1] = cos(rad);

    float temp[3][3];
    multiply_matrices(matrix, r, temp);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = temp[i][j];
}