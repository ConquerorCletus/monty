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

/**
 * stack_push - inserts into the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void stack_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}