#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name) {
    int i = 0;
    while (environ[i] != NULL) {
        if (strncmp(environ[i], name, strlen(name)) == 0) {
            return environ[i] + strlen(name) + 1; // +1 to skip the '=' character
        }
        i++;
    }
    return NULL;
}

