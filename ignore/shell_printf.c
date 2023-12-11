#include "shell.h"

/**
 * shell_printf - The custom made function for our shell
 * that works just like the standard printf.
 * @user_input: Input received from user.
 *
 * Return: 0
 */

void shell_printf(const char *user_input)
{
	write(STDOUT_FILENO, user_input, strlen(user_input));
}
