#include "monty.h"
/**
 * addnode - Add a node to the head of the stack
 * @head: head of the stack
 * @n: Value to be stored in the new node
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *ptr;

	ptr = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (ptr)
		ptr->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
