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
