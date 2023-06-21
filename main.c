#include "monty.h"

holder_t global_holder;
/**
 * main - reads a monty file and calls the respective function
 * @argc: number of main arguments
 * @argv: string arguments with argv[1] being a file name
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	FILE *monty_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		monty_file = fopen(argv[1], "r");

		if (!monty_file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit (EXIT_FAILURE);
		}
		else{
			global_holder.file = monty_file;
			global_holder.buffer = NULL;
			execute(monty_file);
			fclose(monty_file);
		}
	}
	return (0);
}
