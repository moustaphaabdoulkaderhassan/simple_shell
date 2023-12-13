#include "shell.h"
#include "utils.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char *raw_user_input = malloc(MAX_CMD_LEN);
	char *command = malloc(MAX_CMD_LEN);
	char **args;

	if (raw_user_input == NULL || command == NULL)
		exit(EXIT_FAILURE);

	while (1)
	{
		size_t i = 0;

		read_input(raw_user_input, MAX_CMD_LEN);
		args = get_args(raw_user_input);

		command = prepare(args[0]);

		run_command(command, args, environ);

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);

	free(args);
}

	free(command);
	free(raw_user_input);

	return (0);
}
