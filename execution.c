#include "shell.h"

/**
 * _tokenise - tokenise lineptr
 * @lineptr: line from the stdin
 * Return: An array of tokens
 */
char **_tokenise(char *lineptr)
{
	char **argv = NULL;
	int argc = 0, j = 0, i = 0;
	char *token1 = NULL, *token2 = NULL, *delim = " \n", *str_copy;

	str_copy = _strdup(lineptr);
	token1 = _strtok(str_copy, delim);
	if (token1 == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	while (token1 != NULL)
	{
		argc++;
		token1 = _strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * argc + sizeof(NULL));
	token2 = _strtok(lineptr, delim);
	if (token2 == NULL)
		return (NULL);
	for (j = 0; j < argc; j++)
	{
		argv[j] = token2;
		token2 = _strtok(NULL, delim);
	}
	argv[j] = NULL;
	if (argv == NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		return (NULL);
	}
	free(str_copy);
	return (argv);
}
/**
 * _execute - executes commands
 * @argv: argument vector
 * @size: number of arguments
 * @ac: number of argument
 * @av: command line arguments
 * Return: nothing
 */
int _execute(char **argv, int size, int ac, char **av)
{
	int status;
	char *command = argv[0], *path;
	pid_t pid;

	if (_execute_builtin(argv, size))
		return (0);
	if (*argv[0] == '/')
		path = argv[0];
	else
		path = _path_name(argv);
	if (path == NULL)
	{
		free(path);
		exit(EXIT_FAILURE);
	}
	pid = fork();

	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			if (*argv[0] != '/')
				free(path);
			error(command, ac, av);
			return (-1);
			/*exit(EXIT_FAILURE);*/
		}
	}
	else
	{
		if (*argv[0] != '/')
			free(path);
		free(argv);
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * _execute_builtin - executes built-in commands
 * @argv: argument vector
 * @size: argument count
 * Return: 1 if built-in is executed, otherwise 0
 */
int _execute_builtin(char **argv, int size)
{
	if (_strcmp(argv[0], "cd") == 0)
	{
		_cd(argv[1], size);
			return (1);
	}
	return (0);
}

/**
 * _path_name - provides path for input commands
 * @argv: argument vector
 * Return: path name
 */
char *_path_name(char **argv)
{
	int i = 0, j = 0;
	char *part = "/bin/";
	char *complete_path = NULL;
	char *command = strdup(argv[0]);

	complete_path = malloc(sizeof(char) *
			(_strlen(argv[0])) + (_strlen(part) + 2));
	if (complete_path == NULL)
	{
		free(command);
		free(complete_path);
		perror("memory allocation failed");
	}
	else
	{
		while (part[i] != '\0')
		{
			complete_path[i] = part[i];
			i++;
		}
		while (command[j] != '\0')
		{
			complete_path[i] = command[j];
			i++;
			j++;
		}
		complete_path[i] = '\0';
	}
	free(command);
	return (complete_path);
}
