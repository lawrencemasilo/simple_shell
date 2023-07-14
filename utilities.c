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
 * _strdup - returns pointer to new string which is a copy of str
 * @str: string to be duplicated
 * Return: pointer to duplicate string on success, NULL on failure
 */
char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (str[j] != '\0')
	{
		j++;
	}
	ptr = malloc(j + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < j)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}


