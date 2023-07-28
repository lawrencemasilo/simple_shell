#include "shell.h"

/**
 * count - counts the number of arguments
 * @lineptr: the line from stdin
 * Return: Number of arguments
 */
int count(char *lineptr)
{
	char *delim = " \n", *token1 = NULL;
	int argc = 0;

	token1 = strtok(lineptr, delim);
	if (token1 != NULL)
	{
		while (token1 != NULL)
		{
			argc++;
			token1 = strtok(NULL, delim);
		}
	}
	return (argc);
}
