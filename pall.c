#include "monty.h"
/**
 * stack_pall - prints the stack.
 * @head: stack head pointer
 * Return: void
*/
void stack_pall(stack_t *head)
{
	stack_t *tmp;

	for (tmp = head; tmp != NULL; tmp = tmp->next)
		printf("%d\n", tmp->n);




}
