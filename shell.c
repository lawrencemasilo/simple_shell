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
	char *lineptr;

	while(1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			/*clear output buffer and diplay prompt*/
			fflush(stdout);
			write(STDOUT_FILENO, prompt, strlen(prompt));
		}
		line_got = getline(&lineptr, &n, stdin);
		if (line_got == -1)
		{
			exit(0);
		}
		if (line_got != -1)
		{
			/*tokenize and execute function*/
		}
	}
	/*free memory if necessary*/
	return(0);
}
