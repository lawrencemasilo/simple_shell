#include "shell.h"

ssize_t _strlen(const char *str)
{
	ssize_t count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

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
 * _strtok -
 * @str:
 * @delim:
 * Return:
 */
char *_strtok(char *str, const char *delim)
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
	*token_start = str;
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
