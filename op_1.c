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

	if (data.format == STACK)
		add_node(stack, n);
	else
		add_node_end(stack, n);
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

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pint(stack_t **stack, uint line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pop(stack_t **stack, uint line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void add(stack_t **stack, uint line_number)
{
	int sum;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;

	free(temp);
}
