#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

extern char **environ;
void _tokenise_and_execute(char *lineptr, size_t n);
void _execute(char **argv, int size);
char *_path_name(char **argv);
char *_strcpy(char *dest, char *src);
ssize_t _strlen(const char *str);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *delim);
int _atoi(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
void _cd(const char *path, int argc);
int _strcmp(const char *str1, const char *str2);

#endif
