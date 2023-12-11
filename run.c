#include "shell.h"
#include "utils.h"
#include <sys/wait.h>
#include <string.h>

/**
 * run_command - A function that executes a user's command.
 * @command: The command to run or execute.
 * @args: List of arguments for the new process.
 * @envp: List of environment variables.
 *
 * Return: 1 for errors and 0 to to ascertain success.
 */

void run_command(const char *command, char **args, char **envp)
{
	pid_t child_pid;

	if (command == NULL)
	{
		perror(args[0]);
		return;
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command, args, envp);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
