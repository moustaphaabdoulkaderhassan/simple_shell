#include "shell.h"

int main(int ac, char **av) {
    info_t info = INFO_INIT;

    if (ac != 1) {
        fprintf(stderr, "Usage: %s\n", av[0]);
        return EXIT_FAILURE;
    }

    populate_env_list(&info);
    read_history(&info);
    hsh(&info, av);
    write_history(&info);
    free_info(&info, 1);

    return EXIT_SUCCESS;
}

