#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @head: double pointer to the top of the stack
 * @n: value of new node
 *
 * Return: address of new element or NULL if it failed
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * free_stack - Frees a stack from memory
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
