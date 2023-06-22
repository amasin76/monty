#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * get_op_func - pointer to the function corresponding to the given opcode
 * @opcode: opcode string
 * Return: pointer to the corresponding function or NULL if not found
 */
void (*get_op_func(char *opcode))(stack_t **stack, uint line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
		};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}
	return (NULL);
}

/**
 * parse_line - parses a line of input from a Monty bytecode file
 */
void parse_line(void)
{
	char *opcode;
	void (*op_func)(stack_t **stack, uint line_number);

	opcode = strtok(data.line, " \n\t");

	if (opcode == NULL || opcode[0] == '#')
		return;

	op_func = get_op_func(opcode);
	if (op_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				data.line_number, opcode);
		exit(EXIT_FAILURE);
	}
	op_func(&data.stack, data.line_number);
}
