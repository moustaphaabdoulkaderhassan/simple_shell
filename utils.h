#ifndef UTILS_H
#define UTILS_H

#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_args(char *input);
void _printstr(const char *user_input);
char *prepare(char *command);
char *get_path(void);

#endif
