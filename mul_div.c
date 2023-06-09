#include "monty.h"
/**
 * stack_mul - multiplies the top two elements of the stack.
 * @head: pointer to stack head
 * @lineCount: lineCount
 * Return: void
*/
void stack_mul(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int i = 0, mul;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineCount);
		fclose(top.file);
		free(top.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	mul = tmp->next->n * tmp->n;
	tmp->next->n = mul;
	*head = tmp->next;
	free(tmp);
}
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
	div = tmp->next->n / tmp->n;
	tmp->next->n = div;
	*head = tmp->next;
	free(tmp);
}
