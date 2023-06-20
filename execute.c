#include "monty.h"

int global_n;

/**
 * command_exists - checks in opcode is valid
 * @opcode: the opcode to check;
 *
 * Return: function to execute the opcode or null if not found
 */
opcodeFunction command_exists(char *opcode)
{
	instruction_t ins[] = {{"push", push},{"pall", pall},{"pint", pint},
			       {"pop", pop}, {"swap", swap}, {"add", add},
			       {"\0", NULL}};
	int x = 0;

	for(; ins[x].f; x++)
		if (strcmp(opcode, ins[x].opcode) == 0)
			return (ins[x].f);
	return (NULL);
}

/**
 * execute - executes monty bytecodes line by line
 * @file: monty file
 */
void execute(FILE *file)
{
	unsigned int line_number = 1;
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *opcode;
	char *str_val;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *head = NULL;

	while(getline(&buffer, &buffer_size, file) != -1)
	{
		opcode = strtok(buffer, " \n");
		if (opcode)
		{
			if (strcmp(opcode, "nop") == 0)
				continue;

			f = command_exists(opcode);
			if (!f)
			{
				free_stack(head);
				fprintf(stderr, "L %d unknown instruction %s\n",
					line_number, opcode);
				exit (EXIT_FAILURE);
			}

			if (strcmp(opcode, "push") == 0)
			{
				str_val = strtok(NULL, " \n");
				if (!str_val)
				{
				exiter:
					fprintf(stderr,
					       "L%d: usage: push integer\n",
					       line_number);
					exit(EXIT_FAILURE);
				}

				global_n = atoi(str_val);
				if (global_n == 0 && str_val[0] != '0')
					goto exiter;
			}

			f(&head, line_number);
		}
		line_number++;
	}
	free_stack(head);
}
