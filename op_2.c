#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void nop(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void sub(stack_t **stack, uint line_number)
{
	int diff;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = diff;
	free(temp);
}

/**
 * _div - divides the second top element of the stack from the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void _div(stack_t **stack, uint line_number)
{
	int quotient;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	free(temp);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mul(stack_t **stack, uint line_number)
{
	int product;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	free(temp);
}

/**
 * mod - Computes the remainder of the second top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mod(stack_t **stack, uint line_number)
{
	int remainder;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remainder;
	free(temp);
}
