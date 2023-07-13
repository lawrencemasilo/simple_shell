#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void _tokenise_and_execute(char *lineptr, size_t n);
void _execute(char **argv, int size);
char *_path_name(char **argv);

#endif
