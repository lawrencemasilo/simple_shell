#include "shell.h"
/**
 * error - print an error message
 * @file: filename
 * @command: input command
 * @ac: number of argument
 * @av: command line arguments
 * Return: nothing
 */
void error(char *file, char *command, int ac, char **av)
{
	char *error = ": not found\n";
	int i;

	(void) file;

	write(STDERR_FILENO, av[ac - 1], _strlen(av[ac - 1]));
	_putchar(':');
	_putchar(' ');
	_putchar('1');
	_putchar(':');
	_putchar(' ');

	for (i = 0; command[i] != '\0'; i++)
	{
		_putchar(command[i]);
	}
	for (i = 0; error[i] != '\0'; i++)
	{
		_putchar(error[i]);
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
