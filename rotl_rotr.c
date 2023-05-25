#include "monty.h"

/**
  *stack_rotl- flips the stack to the top
  *@head: stack head
  *@lineCount: line Count
  *Return: no return
 */
void stack_rotl(stack_t **head, __attribute__((unused)) unsigned int lineCount)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	aux = (*head)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *head;

	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;

}


/**
  *stack_rotr- flips the stack to the bottom
  *@head: stack head
  *@lineCount: lineCount
  *Return: no return
 */
void stack_rotr(stack_t **head, __attribute__((unused)) unsigned int lineCount)
{
	stack_t *clone;

	clone = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (clone->next)
	{
		clone = clone->next;
	}

	clone->next = *head;
	clone->prev->next = NULL;
	clone->prev = NULL;
	(*head)->prev = clone;
	(*head) = clone;

}
