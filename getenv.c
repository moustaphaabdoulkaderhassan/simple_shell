#include "shell.h"

/**
 * _getenv - Custom implementation of
 * the getenv() function
 * @var: String containing the name
 * of the environment variable
 * Return: Pointer to the value of the
 * variable, NULL if there's no match
 */

char *_getenv(info_t *info, const char *var)
{
    /* Move extern declaration to the top */
    extern char **environ;
    size_t n;

    (void)info; /* Silence the unused parameter warning */

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

