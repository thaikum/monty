#include "monty.h"

/**
 * add - swaps the head and the next to head
 * @top: the current head
 * @iine_number: the current line
 */
void add(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	if ((*top) && (*top)->next)
	{
		(*top)->next->n += (*top)->n;
		pop(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_global_holder();
		exit(EXIT_FAILURE);
	}
}
