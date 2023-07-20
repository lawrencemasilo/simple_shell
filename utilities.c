#include "shell.h"

/**
 * _strlen - counts the number of characters in a string
 * @str: string to be counted
 * Return: number of characters
 */
ssize_t _strlen(const char *str)
{
	ssize_t count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * _strcpy - copy a string from source to destination
 * @dest: where the copy of the source string is stored
 * @src: the source string to be copied
 * Return: the copy of the source string
 */
char *_strcpy(char *dest, char *src)
{
	ssize_t i = 0, strlen = 0;

	strlen = _strlen(src);
	while ((src[i] != '\0') && (i < strlen))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: string in which char c will be located
 * @c: character to be located
 * Return: pointer to s or NULL if c is not found
 */
char *_strchr(char *s, char c)
{
	char *ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
	}
	if (*ptr == c)
	{
		return (ptr);
	}
	return (0);
}

/**
 * _strtok - tokenise string by splitting it into smaller parts
 * @str: string to tokenise
 * @delim: delimiting character
 * Return: pointer to next token in str
 */
char *_strtok(char *str, char *delim)
{
	/* static variable to keep track of the position */
	static char *next_token = NULL;
	char *token_start;

	if (str == NULL)
	{
		str = next_token;
	}
	/* skip leading delimiters */
	while (*str != '\0' && _strchr(delim, *str) != NULL)
	{
		str++;
	}
	/* on end of string, return NULL */
	if (*str == '\0')
	{
		return (NULL);
	}
	/* find end of current token */
	token_start = str;
	while (*str != '\0' && _strchr(delim, *str) == NULL)
	{
		str++;
	}
	/* if end of string, set next_token to NULL */
	if (*str == '\0')
	{
		next_token = NULL;
	}
	else /* replace delim with null terminator */
	{
		*str = '\0';
		next_token = str + 1;
	}
	return (token_start);
}

/**
 * _atoi - converts character string to int
 * @str: string to be converted to integer
 * Return: converted integer
 */
int _atoi(const char *str)
{
	int result = 0, i = 0, sign = 1;

	/* handle leading whitespaces */
	while (str[i] == ' ')
		i++;
	/* handle optional sign */
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	/* convert digits to an int until non-digit char is encountered */
	while (str[i] >= '0' && str[i] <= '9')
	{
		/* check for int overflow */
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
		{
			if (sign == 1)
			{
				return (INT_MAX);
			}
			else
			{
				return (INT_MIN);
			}
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/**
 * _cd - changes directories
 * @path - address of directory to change to
 * @argc - number of arguments
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
		/* *
		 * checks if command cd with argument '-',
		 * then handles it by changing to the previous dir
		 */
		if (strcmp(path, "-") == 0)
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
