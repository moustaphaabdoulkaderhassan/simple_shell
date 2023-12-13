#include "shell.h"

/**
 * custom_strcpy - copies a string
 * @custom_dest: the destination
 * @custom_src: the source
 *
 * Return: pointer to destination
 */
char *custom_strcpy(char *custom_dest, char *custom_src)
{
	int custom_i = 0;

	if (custom_dest == custom_src || custom_src == NULL)
		return (custom_dest);

	while (custom_src[custom_i])
	{
		custom_dest[custom_i] = custom_src[custom_i];
		custom_i++;
	}

	custom_dest[custom_i] = '\0';
	return (custom_dest);
}

/**
 * custom_strdup - duplicates a string
 * @custom_str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *custom_strdup(const char *custom_str)
{
	int custom_length = 0;
	char *custom_ret;

	if (custom_str == NULL)
		return (NULL);

	while (*custom_str++)
		custom_length++;

	custom_ret = malloc(sizeof(char) * (custom_length + 1));
	if (!custom_ret)
		return (NULL);

	for (custom_length++; custom_length--;)
		custom_ret[custom_length] = *--custom_str;

	return (custom_ret);
}

/**
 * custom_puts - prints an input string
 * @custom_str: the string to be printed
 *
 * Return: Nothing
 */
void custom_puts(char *custom_str)
{
	int custom_i = 0;

	while (custom_str[custom_i])
	{
		putchar(custom_str[custom_i]);
		custom_i++;
	}

	putchar('\n');
}
