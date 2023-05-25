#include "monty.h"

/**
 * stack_pchar - Prints the character at the top of the stack,
 * followed by a new line.
 * @head: stack head
 * @lineCount: line Count
 * Return: nothing
*/
void stack_pchar(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;

	tmp = *head;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * stack_pstr - prints the string starting at the top of the stack,
 * followed by new line
 * @head: stack head
 * @lineCount: line Count
 * Return: nothing
*/
void stack_pstr(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	(void)lineCount;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
