#include "monty.h"
/**
  *stack_sub- substration of two top elements
  *@head: pointer to stack head
  *@lineCount: lineCount
  *Return: Void
 */
void stack_sub(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int sub, i;

	tmp = *head;
	for (i = 0; tmp != NULL; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	*head = tmp->next;
	free(tmp);
}
#include "monty.h"

/**
 * stack_add - Adds the top two elements of the stack.
 * @head: Pointer to the stack head
 * @lineCount: Line number
 * Return: void
 */
void stack_add(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int len = 0, sum;

	top_t top;

	top.file = NULL;

	top.content = NULL;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineCount);
		if (top.file != NULL)
			fclose(top.file);
		if (top.content != NULL)
			free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*head = tmp->next;
	free(tmp);
}
