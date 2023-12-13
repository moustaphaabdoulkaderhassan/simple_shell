#include "shell.h"

/**
 * _getenv - Custom implementation of
 * the getenv() function
 * @var: String containing the name
 * of the environment variable
 * Return: Pointer to the value of the
 * variable, NULL if there's no match
 */

char *_getenv(const char *var)
{
    extern char **environ;
    size_t n;

    if (!var)
        return NULL;

    n = strlen(var);

    while (*environ)
    {
        if (strncmp(*environ, var, n) == 0)
            return *environ;
        environ++;
    }

    return NULL;
}

