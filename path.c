#include "shell.h"

/**
 * list_path - Lists the dirs in the
 * PATH variable
 * Return: Always (0)
 */

void list_path(void)
{
    extern char **environ;
    info_t info; /* Assuming info_t is a structure containing environment information */
    char *PATH;
    char *dir;
    pid_t pid;
    char *args[] = {"/bin/ls", NULL, "-1", NULL};

    PATH = _getenv(&info, "PATH");
    printf("%s\n", PATH);
    dir = strtok(PATH, ":");
    while (dir)
    {
        args[1] = dir;
        if ((pid = fork()) == 0)
            pid = execve("/bin/ls", args, environ);

        if (pid == -1)
            printf("\nfailure\n");
        dir = strtok(NULL, ":");
    }
}

