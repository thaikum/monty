#include "monty.h"

/**
 * push - adds a node at the top
 * @top: the current head;
 * @line_number: the line number to use incase of failure
 *
 * Return: newly created node
 */
void push(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	new_node->n = global_n;
	new_node->next = *top;
	new_node->prev = NULL;
	if (*top)
		(*top)->prev = new_node;
	*top = new_node;
}
/**
 * pall - prints all elements in the stack
 * @top: the current head
 * @line_number: the current line
 */
void pall(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp_head = *top;

	for (; temp_head; temp_head = temp_head->next)
		printf("%d\n", temp_head->n);
}
/**
 * pint - prints the first element of the stack
 * @top: the current head
 * @iine_number: the current line
 */
void pint(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	if (*top)
		printf("%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - prints the first element of the stack
 * @top: the current head
 * @iine_number: the current line
 */
void pop(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp_head;
	if (*top)
	{
		temp_head = *top;
		*top = (*top)->next;
		if (*top)
			(*top)->prev = NULL;
		free(temp_head);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - swaps the head and the next to head
 * @top: the current head
 * @iine_number: the current line
 */
void swap(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	int temp_int;

	if ((*top) && (*top)->next)
	{
		temp_int = (*top)->n;
		(*top)->n = (*top)->next->n;
		(*top)->next->n = temp_int;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
