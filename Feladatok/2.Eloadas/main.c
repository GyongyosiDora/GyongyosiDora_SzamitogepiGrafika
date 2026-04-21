#include "matrix.h"
#include "matrix_stack.h"

#include <stdio.h>

int main()
{
    float m[3][3];
    float x = 1.0f, y = 1.0f;

    MatrixStack stack;

    init_identity_matrix(m);
    init_stack(&stack);

    printf("Eredeti:\n");
    print_matrix(m);

    // +++ állapot mentése
    push_matrix(&stack, m);

    // módosítás
    scale(m, 2, 2);
    shift(m, 5, 0);

    printf("\nTranszformalt:\n");
    print_matrix(m);

    transform_point(m, &x, &y);
    printf("Pont: (%f, %f)\n", x, y);

    // +++ visszavonás
    pop_matrix(&stack, m);

    printf("\nVisszaallitott:\n");
    print_matrix(m);

    x = 1.0f;
    y = 1.0f;

    transform_point(m, &x, &y);
    printf("Pont vissza: (%f, %f)\n", x, y);

    return 0;
}