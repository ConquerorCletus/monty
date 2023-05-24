#include "monty.h"

/**
 * stack_add - adds the top two elements of the stack.
 * @head: pointer to stack head
 * @lineCount: lineCount
 * Return: Void.
 */
void stack_add(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int len = 0, sum;

	bus_t bus;

	bus.file = NULL;

	bus.content = NULL;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineCount);
		if (bus.file != NULL)
			fclose(bus.file);
		if (bus.content != NULL)
			free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*head = tmp->next;
	free(tmp);
}
