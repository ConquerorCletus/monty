#include "monty.h"
/**
 * stack_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: Pointer to stack head
 * @lineCount: lineCount
 * Return: Void
*/
void stack_mod(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int i = 0, mod;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mod = tmp->next->n % tmp->n;
	tmp->next->n = mod;
	*head = tmp->next;
	free(tmp);
}
