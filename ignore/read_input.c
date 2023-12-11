#include "utils.h"

/**
 * read_input - A function that receives and reads user's input.
 * @command: The string input from the user.
 * @size: The size allocated to input received.
 * Return: Using the exit MACRO in place of returns.
 */

void read_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_printf("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
