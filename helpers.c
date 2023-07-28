#include "shell.h"

/**
 * _strncmp - compares first n characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to be compared
 * Return: 0 on success
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		else if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _cd - changes directories
 * @path: address of directory to change
 * @argc: number of arguments
 * Return: Nothing
 */
void _cd(const char *path, int argc)
{
	char *home_path = getenv("HOME");
	char current_directory[1024];
	int previous, cd_i;
	char *cwd;

	/*cd with no arguments changes dir to home/root dir*/
	if (argc == 1)
	{
		chdir(home_path);
	}
	if (path != NULL)
	{
		/**
		 * checks if command cd with argument '-',
		 * then handles it by changing to the previous dir
		 */
		if (_strcmp(path, "-") == 0)
		{
			previous = chdir(getenv("OLDPWD"));
			if (previous == -1)
			{
				perror("chdir");
			}
		}
		else /*change directory using path*/
		{
			cd_i = chdir(path);
			if (cd_i == -1)
			{
				perror("chdir");
			}
		}
	}
	cwd = getcwd(current_directory, sizeof(current_directory));
	if (cwd != NULL)
	{
		setenv("PWD", current_directory, 1);
	}
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: the difference of the first and second string
 */
int _strcmp(const char *str1, const char *str2)
{
	int i;
	int result;

	if ((str1 == NULL) || (str2 == NULL))
	{
		return (-1);
	}
	for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		if (str1[i] != str2[i])
		{
			result = *str1 - *str2;
			return (result);
		}
	}
	result = *str1 - *str2;
	return (result);
}

/**
 * _doublefree - frees a double pointer
 * @str: the double pointer to be freed
 * Return: Nothing
 */
void _doublefree(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to duplicate string on success,otherwise NULL
 */
char *_strdup(char *str)
{
	size_t len = _strlen(str) + 1;
	char *ptr;

	if (str == NULL)
		return (NULL);

	ptr = (char *)malloc(len);

	if (ptr != NULL)
		_strcpy(ptr, str);

	return (ptr);
}
