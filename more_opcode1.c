#include "monty.h"
/**
 *
 *
 *
 *
 */
void pchar(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	char c;

	if (*top)
	{
		c = (*top)->n;
		if (isalpha(c) == 0)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free_global_holder();
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", c);
	}
	else
	{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			free_global_holder();
			free_stack(*top);
			exit(EXIT_FAILURE);
	}
}
/**
 *
 *
 *
 */
void pstr(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	char c;
	stack_t *temp = *top;

	for (; temp; temp = temp->next)
	{
		if (!temp->n)
			break;
		if (!isalpha(temp->n))
			break;
		c = temp->n;	
		printf("%c", c);
	}
	printf("\n");
}
/**
 *
 *
 *
 */
void rotl(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *top;
	int i;

	if (!(*top) || !top || !(*top)->next)
		return;

	i = temp->n;
	while (temp->next)
	{
		temp = temp->next;
		temp->prev->n = temp->n;
	}
	temp->n = i;
}
/**
 *
 *
 *
 */
void rotr(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *top;
	int i;

	if (!(*top) || !top || !(*top)->next)
		return;

	for (; temp->next; temp = temp->next)
		;
	i = temp->n;

	while (temp->prev)
	{
		temp = temp->prev;
		temp->next->n = temp->n;
	}
	(*top)->n = i;
}	
