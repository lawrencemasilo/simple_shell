#include "shell.h"

/**
 * _exit_builtin - handles the "exit" built-in with args
 * @lineptr: input line containing exit command and args
 * Return: exit status for shell
 */
int _exit_builtin(char *lineptr)
{
	char *argument = lineptr + 4;
	int exit_code = _atoi(argument);

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

/**
 * main - entry point for the shell program
 * @ac: number of argument
 * @av: command line arguments
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *prompt = "($) ", *lineptr = NULL;
	int line_got;
	size_t n = 0;

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
				_exit_builtin(lineptr);
			}
			_tokenise_and_execute(lineptr, ac, av);
		}
	}
	free(lineptr);
	return (0);
}
