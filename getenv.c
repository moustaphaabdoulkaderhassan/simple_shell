#include "shell.h"

/**
 * _getenv - Custom implementation of
 * the getenv() function
 * @var: String containing the name
 * of the environment variable
 * Return: Pointer to the value of the
 * variable, NULL if there's no match
 */

char *_getenv(info_t *, const char *)
{
    extern char **environ;
    size_t n = strlen(var);

    if (!var)
        return NULL;

    while (*environ)
    {
        if (strncmp(*environ, var, n) == 0)
            return *environ;
        environ++;
    }

    return NULL;
}
