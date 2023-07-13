#include "shell.h"

/**
 * _tokenize_and_execute - tokenise lineptr and pass arguments for execution
 * @lineptr: line from the stdin
 * @n: size of lineptr
 */

void _tokenize_and_execute(char *lineptr, size_t n)
{
	char **argv = NULL;
	int argc = 0, i = 0;
	char *token1 = NULL, *token2 = NULL, *delim = " \n", *str_copy;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		str_copy = malloc(sizeof(char *) * n);
		str_copy = strcpy(str_copy, lineptr);
		token1 = strtok(lineptr, delim);
		if (token1 != NULL)
		{
			while (token1 != NULL)
			{
				argc++;
				token1 = strtok(NULL, delim);
			}
		}
		argv = malloc(sizeof(char *) * argc);
		if (argv == NULL)
		{
			perror("Malloc failed");
		}
		token2 = strtok(str_copy, delim);
		for (i = 0; i < argc; i++)
		{
			argv[i] = token2;
			token2 = strtok(NULL, delim);
		}
		argv[i] = NULL;
		free(str_copy);
		/*placeholder for the execute()*/
	}
	else
		wait(NULL);
}
