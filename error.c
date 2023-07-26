#include "shell.h"
/**
 * error - print an error message
 * @file: filename
 * @command: input command
 * Return: nothing
 */
void error(char *file, char *command)
{
	char *error = ": not found\n";
	int i;

	for (i = 0; file[i] != '\0'; i++)
	{
		_putchar(file[i]);
	}
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
