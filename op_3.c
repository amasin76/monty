#include "monty.h"

/**
 * swap - swaps the top two elements of a stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void swap(stack_t **stack, uint line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pchar(stack_t **stack, uint line_number)
{
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pstr(stack_t **stack, uint line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the left
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */
void rotl(stack_t **stack, uint line_number)
{
	stack_t *temp, *last;

	(void)(line_number);

	if (!*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}

/**
 * rotr - Rotates the stack to the right
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */
void rotr(stack_t **stack, uint line_number)
{
	stack_t *temp, *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}
