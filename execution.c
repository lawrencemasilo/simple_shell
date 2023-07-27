#include "shell.h"


/**
 * _tokenise_and_execute - tokenise lineptr and pass arguments for execution
 * @lineptr: line from the stdin
 * @ac: number of argument
 * @av: command line arguments
 * Return: Nothing
 */
void _tokenise_and_execute(char *lineptr, int ac, char **av)
{
	char **argv = NULL;
	int argc = 0, i = 0;
	char *token1 = NULL, *token2 = NULL, *delim = " \n", *str_copy;
	pid_t pid = fork();

	if (pid == -1)
		perror("Fork failed");
	else if (pid == 0)
	{
		str_copy = strdup(lineptr);
		token1 = strtok(lineptr, delim);
		if (token1 != NULL)
		{
			while (token1 != NULL)
			{
				argc++;
				token1 = strtok(NULL, delim);
			}
			argv = malloc(sizeof(char *) * argc + sizeof(NULL));
			if (argv == NULL)
			{
				free(argv);
			}
			token2 = _strtok(str_copy, delim);
			for (i = 0; i < argc; i++)
			{
				argv[i] = token2;
				token2 = _strtok(NULL, delim);
			}
			argv[i] = NULL;
			_execute(argv, argc, ac, av);
		}
		free(str_copy);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * _execute_external - executes external commands
 * @argv: argument vector
 * @path: path to executable
 * @ac: number of argument
 * @av: command line arguments
 * Return: nothing
 */
void _execute_external(char **argv, char *path, int ac, char **av)
{
	int status;
	char *command = argv[0];
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	} else if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			free(argv);
			free(path);
			error(argv[0], command, ac, av);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			errno = WEXITSTATUS(status);
			free(path);
			exit(EXIT_FAILURE);
		}
		free(path);
		free(argv);
	}
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
 * _execute - executes input command
 * @argv: argument vector
 * @size: argument count
 * @ac: number of argument
 * @av: command line arguments
 * Return: Nothing
 */
void _execute(char **argv, int size, int ac, char **av)
{
	char *path;

	if (_execute_builtin(argv, size))
		return;

	if (*argv[0] == '/')
	{
		path = argv[0];
	}
	else
	{
		path = _path_name(argv);
	}
	if (path == NULL)
	{
		free(path);
		perror("path is empty\n");
		exit(EXIT_FAILURE);
	}
	_execute_external(argv, path, ac, av);
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

