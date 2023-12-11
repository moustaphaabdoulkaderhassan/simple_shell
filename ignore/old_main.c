#include <stdio.h>
#include <unistd.h>
#include "lib.h"

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
char *line = NULL;
size_t line_cap = 0;
size_t line_len;

_putchar('$');
_putchar(' ');

while ((line_len = getline(&line, &line_cap, stdin)) > 0)
{
_putchar('$');
_putchar(' ');

}

return (0);
}
