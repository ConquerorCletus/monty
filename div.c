#include "monty.h"
/**
 * stack_div - divides the top two elements of the stack.
 * @head: pointer to stack head
 * @lineCount: lineCount
 * Return: Void
*/
void stack_div(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int i = 0, div;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineCount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	div = tmp->next->n / tmp->n;
	tmp->next->n = div;
	*head = tmp->next;
	free(tmp);
}
