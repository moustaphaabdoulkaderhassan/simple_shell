#include "shell.h"

/* Implement or include other missing functions if needed */

/**
 * write_history_file - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history_file(info_t *info)
{
    ssize_t fd;
    char *filename = get_history_file(info);  /* Use the updated function name */
    list_t *node = NULL;

    if (!filename)
        return -1;

    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);

    if (fd == -1)
        return -1;

    for (node = info->history; node; node = node->next)
    {
        _putsfd(node->str, fd);
        _putfd('\n', fd);
    }

    _putfd(BUF_FLUSH, fd);
    close(fd);

    return 1;
}

/**
 * read_history_file - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history_file(info_t *info)
{
    int i, last = 0, linecount = 0;
    ssize_t fd, rdlen, fsize = 0;
    struct stat st;
    char *buf = NULL, *filename;

    /* Use the updated function name */
    filename = get_history_file(info);

    if (!filename)
        return 0;

    fd = open(filename, O_RDONLY);
    free(filename);

    if (fd == -1)
        return 0;

    if (!fstat(fd, &st))
        fsize = st.st_size;

    if (fsize < 2)
        return 0;

    buf = malloc(sizeof(char) * (fsize + 1));
    if (!buf)
        return 0;

    rdlen = read(fd, buf, fsize);
    buf[fsize] = 0;

    if (rdlen <= 0)
        return free(buf), 0;

    close(fd);

    for (i = 0; i < fsize; i++)
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            /* Omitted add_to_history_list here */
            last = i + 1;
        }

    if (last != i)
        /* Omitted add_to_history_list here */

    free(buf);
    info->histcount = linecount;

    /* Omitted update_history_numbers here */

    return info->histcount;
}

