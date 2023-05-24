#include "monty.h"
#include "monty.h"
#include <stdio.h>

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * Return: 0 on success
 */
int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Stack contents:\n");
    stack_pall(stack);

    free_stack(stack);

    return 0;
}
