#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define HIST_MAX 100
#define BUF_FLUSH 0
#define HIST_FILE "history.txt"

typedef struct list_t {
    char *str;
    int num;
    struct list_t *next;
} list_t;

typedef struct info_t {
    list_t *history;
    int histcount;
    /* Add other members as needed */
} info_t;

char *_getenv(info_t *info, const char *name);
size_t _strlen(const char *str);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _putsfd(const char *str, int fd);
int _putfd(char c, int fd);
void delete_node_at_index(list_t **head, unsigned int index);
void add_node_end(list_t **head, const char *str, int num);

char *get_history_file(info_t *info) {
    char *buf, *dir;

    dir = _getenv(info, "HOME=");
    if (!dir)
        return NULL;

    buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
    if (!buf) {
        free(dir);
        return NULL;
    }

    buf[0] = 0;
    _strcpy(buf, dir);
    _strcat(buf, "/");
    _strcat(buf, HIST_FILE);

    free(dir);
    return buf;
}

int write_history(info_t *info) {
    int fd;
    char *filename = get_history_file(info);
    list_t *node = NULL;

    if (!filename)
        return -1;

    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);

    if (fd == -1)
        return -1;

    for (node = info->history; node; node = node->next) {
        if (_putsfd(node->str, fd) == -1) {
            close(fd);
            return -1;
        }

        if (_putfd('\n', fd) == -1) {
            close(fd);
            return -1;
        }
    }

    if (_putfd(BUF_FLUSH, fd) == -1) {
        close(fd);
        return -1;
    }

    close(fd);
    return 1;
}

int build_history_list(info_t *info, char *buf, int linecount);

int renumber_history(info_t *info);

int read_history(info_t *info) {
    int i, last = 0, linecount = 0;
    ssize_t fd, rdlen, fsize = 0;
    struct stat st;
    char *buf = NULL, *filename = get_history_file(info);

    if (!filename)
        return 0;

    fd = open(filename, O_RDONLY);
    free(filename);

    if (fd == -1)
        return 0;

    if (fstat(fd, &st) == -1)
        return close(fd), 0;

    fsize = st.st_size;

    if (fsize < 2)
        return close(fd), 0;

    buf = malloc(sizeof(char) * (fsize + 1));
    if (!buf)
        return close(fd), 0;

    rdlen = read(fd, buf, fsize);
    buf[fsize] = 0;

    if (rdlen <= 0) {
        free(buf);
        close(fd);
        return 0;
    }

    close(fd);

    for (i = 0; i < fsize; i++) {
        if (buf[i] == '\n') {
            buf[i] = 0;
            build_history_list(info, buf + last, linecount++);
            last = i + 1;
        }
    }

    if (last != i)
        build_history_list(info, buf + last, linecount++);

    free(buf);
    info->histcount = linecount;

    while (info->histcount-- >= HIST_MAX)
        delete_node_at_index(&(info->history), 0);

    renumber_history(info);

    return info->histcount;
}

int build_history_list(info_t *info, char *buf, int linecount) {
    list_t *node = NULL;

    if (info->history)
        node = info->history;

    add_node_end(&node, buf, linecount);

    if (!info->history)
        info->history = node;

    return 0;
}

int renumber_history(info_t *info) {
    list_t *node = info->history;
    int i = 0;

    while (node) {
        node->num = i++;
        node = node->next;
    }

    return (info->histcount = i);
}

/* Main function or entry point of your program */
int main() {
    /* Add your code here if needed */
    return 0;
}
