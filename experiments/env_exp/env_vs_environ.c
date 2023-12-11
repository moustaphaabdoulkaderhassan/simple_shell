#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *env[])
{
	printf("env addr: %p\n", env);
	printf("environ: %p\n", environ);
}
