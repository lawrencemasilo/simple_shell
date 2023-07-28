#include "shell.h"

/**
 * _signal_handler - executes when specific signal is received from user
 * @signal_num: the signal number
 * Return: Nothing
 */
void _signal_handler(int signal_num)
{
	(void) signal_num;

	write(STDOUT_FILENO, "\n ", _strlen("\n "));
	write(STDOUT_FILENO, "($) ", _strlen("($) "));
	fflush(stdout);
}

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
		free(argument);
		exit(exit_code);
	}
	else
	{
		free(lineptr);
		exit(2);
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
	ssize_t line_got = 0;
	size_t n = 0;
	char **argv;
	int argc = 0;

	signal(SIGINT, _signal_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			fflush(stdout);
			write(STDOUT_FILENO, prompt, strlen(prompt));
		}
		line_got = getline(&lineptr, &n, stdin);
		if (line_got != -1)
		{
			if (_strncmp(lineptr, "exit", 4) == 0)
			{
				_exit_builtin(lineptr);
			}
			argv = _tokenise(lineptr);
			if (argv == NULL)
			{
				_doublefree(argv);
				return (-1);
			}
			argc = count(lineptr);
			if (argv != NULL)
				_execute(argv, argc, ac, av);
		}
		else
		{
			free(lineptr);
			exit(0);
		}
	}
	_doublefree(argv);
	free(lineptr);
	return (0);
}
