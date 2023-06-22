#include "monty.h"
/**
 *
 *
 *
 */
void _stack(stack_t **top __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	global_holder.mode = 0;
}

/**
 *
 *
 *
 */
void _queue(stack_t **top __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	global_holder.mode = 1;
}
/**
 *
 *
 *
 *
 */
stack_t *get_tail(stack_t *top)
{
	stack_t *tail = top;

	if (!top)
		return (NULL);

	for (; tail->next; tail = tail->next)
		;
	return (tail);
}
