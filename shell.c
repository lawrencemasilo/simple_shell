#include "shell.h"

/**
 * main - entry point for the shell program
 * Return: 0 on success
 */

int main(void)
{
	char *prompt = ";) ", *lineptr = NULL, *argument;
	int line_got, exit_code;
	size_t n = 0;

	lineptr = malloc(sizeof(char *));
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			fflush(stdout);
			write(STDOUT_FILENO, prompt, strlen(prompt));
		}
		line_got = getline(&lineptr, &n, stdin);
		if (line_got == -1)
		{
			free(lineptr);
			exit(0);
		}
		if (line_got != -1)
		{
			if (_strncmp(lineptr, "exit", 4) == 0)
			{
				argument = lineptr + 4;
				exit_code = _atoi(argument);
				if (*argument == ' ')
				{
					argument++;
					free(lineptr);
					exit(exit_code);
				}
				else
				{
					free(lineptr);
					exit(EXIT_SUCCESS);
				}
			}
			_tokenise_and_execute(lineptr, n);
		}
	}
	free(lineptr);
	return (0);
}
