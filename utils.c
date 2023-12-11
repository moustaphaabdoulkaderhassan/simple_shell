#include "utils.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_args - Tokenize an input string and create an array of arguments.
 * @input: The input string to tokenize.
 *
 * This function tokenizes the input string based on spaces and stores each
 * token as a separate element in an array of strings. The memory for the
 * array and each argument is dynamically allocated.
 *
 * Return: A dynamically allocated array of argument strings, terminated
 * with NULL. If memory allocation fails, returns NULL.
 */

char **get_args(char *input)
{
	char **args = malloc(MAX_ARGS_LEN * sizeof(char *));
	char *current = strtok(input, " ");

	int i = 0;

	while (current != NULL && i < MAX_ARGS_LEN)
	{
		args[i] = strdup(current);
		current = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;

	return (args);
}


/**
 * _printstr - Print a string to stdout.
 * @str: The string.
 *
 * Return: 0
 */

void _printstr(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

/**
 * read_input - A function that receives and reads user's input.
 * @command: The string input from the user.
 * @size: The size allocated to input received.
 * Return: Using the exit MACRO in place of returns.
 */

void read_input(char *command, size_t size)
{
	if (isatty(STDIN_FILENO))
		_printstr("$ ");

	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			/* _printstr("\n"); */
			exit(EXIT_SUCCESS);
		}
		else
		{
			_printstr("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}

	if (strncmp(command, "exit", 4) == 0)
	{
		errno = 2;
		exit(EXIT_SUCCESS);
	}

	command[strcspn(command, "\n")] = '\0';
}

/**
* prepare - Prepares a command for execution by
* prepending its path
*
* @command: The command.
*
* Return: void
*/
char *prepare(char *command)
{
	char *path = get_path();
	char *token = malloc(strlen(path));
	char *file = malloc(strlen(path) + strlen(command) + 1);
	char *path_cpy = strdup(path);
	int found = 0;

	token = strtok(path_cpy, ":");

	while (token != NULL)
	{
		char buffer[MAX_CMD_LEN];

		if (strncmp(token, command, strlen(token)) == 0)
		{
			/* in this case, we just use the command directly */
			strcpy(file, command);
		}
		else
		{
			strcpy(buffer, token);
			strcat(buffer, "/");


			strcpy(file, buffer);
			strcat(file, command);
		}

		if (access(file, F_OK) == 0)
		{
			return (file);
			found = 1;
		}

		token = strtok(NULL, ":");
	}

	free(token);
	free(file);
	free(path_cpy);

	if (found == 1)
		return (command);
	else
		return (NULL);
}


/**
 * get_path - Returns the PATH.
 *
 * Return: The PATH environment variable as a string.
 */
char *get_path(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}

	exit(EXIT_FAILURE);
}
