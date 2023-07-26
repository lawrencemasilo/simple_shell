#include "shell.h"

/**
 * _tokenise_and_execute - tokenise lineptr and pass arguments for execution
 * @lineptr: line from the stdin
 * Return: Nothing
 */
void _tokenise_and_execute(char *lineptr)
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
			argv = malloc(sizeof(char *) * argc + 1);
			if (argv == NULL)
			{
				perror("Malloc failed");
			}
			token2 = _strtok(str_copy, delim);
			for (i = 0; i < argc; i++)
			{
				argv[i] = token2;
				token2 = _strtok(NULL, delim);
			}
			argv[i] = NULL;
			_execute(argv, argc);
		}
		else
			free(lineptr);
		free(argv);
		free(str_copy);
	}
	else
		wait(NULL);
}

/**
 * _execute - executes input command
 * @argv: argument vector
 * @size: argument count
 * Return: Nothing
 */
void _execute(char **argv, int size)
{
	char *path;
	int execute;
	pid_t pid;

	if (strcmp(argv[0], "cd") == 0)
	{
		_cd(argv[1], size);
	}
	else if (strcmp(argv[0], "cd") != 0)
	{
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
		}
		pid = fork();
		if (pid == -1)
			perror("fork");
		if (kill(pid, SIGINT) == 0)
		{
			execute = execve(path, argv, environ);
			if (execute == -1)
				perror("Error ");
		}
		free(path);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * _path_name - provides path for input commands
 * @argv: argument vector
 * Return: path name
 */
char *_path_name(char **argv)
{
	int i = 0, j = 0;
	char *part_path = "/bin/";
	char *complete_path = NULL;
	char *command = strdup(argv[0]);

	complete_path = malloc((sizeof(command) + 1) + (sizeof(part_path) + 1));
	if (complete_path == NULL)
	{
		free(complete_path);
		perror("memory allocation failed");
	}
	while (part_path[i] != '\0')
	{
		complete_path[i] = part_path[i];
		i++;
	}
	while (command[j] != '\0')
	{
		complete_path[i] = command[j];
		i++;
		j++;
	}
	free(command);
	return (complete_path);
}

