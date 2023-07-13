#include "shell.h"

/**
 * main - entry point for the shell program
 * Return: 0 on success
 */

int main(void)
{
	/*Feel free to change the prompt*/
	char *prompt = ";) ";
	int line_got;
	size_t n = 0;
	char *lineptr = NULL;

	lineptr = malloc(sizeof(char *));
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			/*clear output buffer and diplay prompt*/
			fflush(stdout);
			write(STDOUT_FILENO, prompt, strlen(prompt));
		}
		/*getline will resize lineptr to acommodate the linne gotten*/
		line_got = getline(&lineptr, &n, stdin);
		if (line_got == -1)
		{
			free(lineptr);
			exit(0);
		}
		if (line_got != -1)
		{
			_tokenise_and_execute(lineptr, n);
		}
	}
	free(lineptr);
	return (0);
}
