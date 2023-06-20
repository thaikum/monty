#include "monty.h"

/**
 * free_stack - frees the stack
 * @top: the stack head
 */
void free_stack(stack_t *top)
{
	stack_t *temp_head;

	while (top)
	{
		temp_head = top;
		top = top->next;
		free(temp_head);
	}
}
