#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * get_environment - returns the string array copy of our environ
 * Return: Always 0
 */
char **get_environment(void)
{
    extern char **environ; /* Declare environ if not declared elsewhere */
    char **env_copy;
    int env_changed = 0;

    if (!environ || env_changed)
    {
        /* Assuming env is a global variable or declared elsewhere in your code */
        extern list_t *env;
        environ = list_to_strings(env);
        env_changed = 0;
    }

    /* Assuming env is a global variable or declared elsewhere in your code */
    env_copy = environ;
    return env_copy;
}

