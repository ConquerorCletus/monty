#include "monty.h"

/**
 * stack_queue - sets the stack to queue mode
 * @head: stack head
 * @lineCount: lineCount
 * Return: nothing
*/
void stack_queue(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	bus.lifi = 1;
}

/**
 * addqueue - adds a node to the tail of the stack
 * @head: stack head
 * @n: new value to be added
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *cell, *ptr;

	ptr = *head;
	cell = malloc(sizeof(stack_t));
	if (cell == NULL)
	{
		printf("Error\n");
	}
	cell->n = n;
	cell->next = NULL;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
	}
	if (!ptr)
	{
		*head = cell;
		cell->prev = NULL;
	}
	else
	{
		ptr->next = cell;
		cell->prev = ptr;
	}
}
