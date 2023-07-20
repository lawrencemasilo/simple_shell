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
