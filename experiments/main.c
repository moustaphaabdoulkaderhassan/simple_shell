#include "shell.h"
#include "utils.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	int status;
	/*
	
	char *raw_user_input = malloc(MAX_CMD_LEN);
	char *command = malloc(MAX_CMD_LEN);
	char **args;
	int status;

	 just the malloc check 
	if (raw_user_input == NULL || command == NULL)
		exit(EXIT_FAILURE);
	
	*/
	
	while (1)
	{
		status = read_input();
		
		if (status == SHELL_FAILURE)
			break;
		/*
		else if (status == CMD_FAILURE)
			continue;
		*/

		/* args = get_args(raw_user_input);

		command = prepare(args[0]);

		run_command(args); */
	}

	/*
	free(raw_user_input);
	free(command);
	*/

	return (0);
}

