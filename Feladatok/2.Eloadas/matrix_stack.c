#include "matrix_stack.h"

#include <stdio.h>

// +++ verem inicializálás
void init_stack(MatrixStack* stack)
{
    stack->top = -1;
}

// +++ push
void push_matrix(MatrixStack* stack, const float matrix[3][3])
{
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }

    stack->top++;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            stack->data[stack->top][i][j] = matrix[i][j];
}

// +++ pop
void pop_matrix(MatrixStack* stack, float matrix[3][3])
{
    if (stack->top < 0) {
        printf("Stack underflow!\n");
        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = stack->data[stack->top][i][j];

    stack->top--;
}