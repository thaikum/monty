#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: the string to check
 *
 * Return: 1 if true 0 if false
 */
int is_number(char *str)
{
	int x = 0;

	for (; str && str[x]; x++)
	{
		if (str[x] == '0')
			continue;
		if (str[0] == '-')
			x++;
		if (str[x] > '9' || str[x] < '0')
			return (0);
	}
	return (1);
}
