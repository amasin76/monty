#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void push(stack_t **stack, uint line_number)
{
	int n;
	char *arg;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	add_node(stack, n);
}

/**
 * pall - prints all the values on stack, starting from the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pall(stack_t **stack, uint line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
