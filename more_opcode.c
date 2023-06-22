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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_global_holder();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}
/**
 *
 *
 *
 *
 */
void sub(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *top;

	if ((*top) && (*top)->next)
	{
		(*top)->next->n -= (*top)->n;
		*top = (*top)->next;
		free(temp);
		(*top)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_global_holder();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}
/**
 *
 *
 *
 *
 */
void _div(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	if ((*top) && (*top)->next)
	{
		if ((*top)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_global_holder();
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		(*top)->next->n /= (*top)->n;
		pop(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_global_holder();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}
/**
 *
 *
 */
void mul(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	if ((*top) && (*top)->next)
	{
		(*top)->next->n *= (*top)->n;
		pop(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_global_holder();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}

void mod(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	if ((*top) && (*top)->next)
	{
		if ((*top)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_global_holder();
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		(*top)->next->n %= (*top)->n;
		pop(top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_global_holder();
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
}


