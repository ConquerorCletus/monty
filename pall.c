#include "monty.h"

/**
 * stack_pall - prints the element of stack
 * @head: pointer to stack head
 * @lineCount: unused parameter
 * Return: void
*/
void stack_pall(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	(void)lineCount;

	tmp = *head;
	if (tmp == NULL)
		return;
	for (; tmp != NULL; tmp = tmp->next)
		printf("%d\n", tmp->n);
}
