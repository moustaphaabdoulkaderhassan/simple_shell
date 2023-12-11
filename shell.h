#ifndef SHELL_H
#define SHELL_H

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void run_command(const char *command, char **args, char **envp);
void read_input(char *command, size_t size);

#endif /* SHELL_H */
