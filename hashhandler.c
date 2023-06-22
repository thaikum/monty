/**
 *hashtag_handle - a function that removes everything after "#".
 *@line: input string.
 *Return: void;
 */
void hashhandler(char *line)
{
	int i;
		for (i = 0; line[i]; i++)
		{
			if (line[i] == '#')
			{
				line[i] = '\0';
				break;
			}
		}
}
