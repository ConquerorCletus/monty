#include "monty.h"

/**
 * stack_pint - Prints the value at the top of the stack
 * @stack_head: Pointer to the stack head
 * @lineCount: Line number
 * Return: No return value
 */
void stack_pint(stack_t **stack_head, unsigned int lineCount)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineCount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}

/**
 * stack_pop - Removes the top element from the stack
 * @stack_head: Pointer to the stack head
 * @lineCount: Line number where the operation is performed
 * Return: No return value
 */
void stack_pop(stack_t **stack_head, unsigned int lineCount)
{
	stack_t *curr_node;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineCount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	curr_node = *stack_head;
	*stack_head = curr_node->next;
	free(curr_node);
}
