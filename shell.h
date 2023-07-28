#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>

int ctrl_signal;
extern char **environ;

char **_tokenise(char *lineptr);
int count(char *lineptr);
void _execute(char **argv, int size, int ac, char **av);
char *_path_name(char **argv);
char *_strcpy(char *dest, char *src);
ssize_t _strlen(const char *str);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *delim);
int _atoi(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
void _cd(const char *path, int argc);
int _strcmp(const char *str1, const char *str2);
void _doublefree(char **str);
void _execute_external(char **argv, int ac, char **av);
int _exit_builtin(char *lineptr);
void error(char *file, char *command, int ac, char **av);
int _execute_builtin(char **argv, int size);
int _putchar(char c);
void signal_handler(int signal_num);
char *_strdup(char *str);

#endif
