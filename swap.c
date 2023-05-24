#include "monty.h"

/**
 * stack_swap - Swaps the top two elements of the stack.
 * @stack_head: Pointer to the stack head
 * @lineCount: line number
 * Return: No return value
*/
void stack_swap(stack_t **stack_head, unsigned int lineCount)
{
	stack_t *curr_node;
	int stack_size = 0;
	int temp;

	curr_node = *stack_head;
	while (curr_node)
	{
		curr_node = curr_node->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineCount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	curr_node = *stack_head;
	temp = curr_node->n;
	curr_node->n = curr_node->next->n;
	curr_node->next->n = temp;
}