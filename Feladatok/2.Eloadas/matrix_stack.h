#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#define MAX_STACK_SIZE 100

typedef struct {
    float data[MAX_STACK_SIZE][3][3];
    int top;
} MatrixStack;

// +++ inicializálás
void init_stack(MatrixStack* stack);

// +++ push
void push_matrix(MatrixStack* stack, const float matrix[3][3]);

// +++ pop
void pop_matrix(MatrixStack* stack, float matrix[3][3]);

#endif