#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @lineCount: line Count
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int lineCount, FILE *file)
{
	instruction_t opst[] = {
				{"push", stack_push}, {"pall", stack_pall}, {"pint", stack_pint},
				{"pop", stack_pop},
				{"swap", stack_swap},
				{"add", stack_add},
				{"nop", stack_nop},
				{"sub", stack_sub},
				{"div", stack_div},
				{"mul", stack_mul},
				{"mod", stack_mod},
				{"pchar", stack_pchar},
				{"pstr", stack_pstr},
				{"rotl", stack_rotl},
				{"rotr", stack_rotr},
				{"queue", stack_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op_code;

	op_code = strtok(content, " \n\t");
	if (op_code && op_code[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op_code)
	{
		if (strcmp(op_code, opst[i].opcode) == 0)
		{	opst[i].f(stack, lineCount);
			return (0);
		}
		i++;
	}
	if (op_code && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lineCount, op_code);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
