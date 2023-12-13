#!/bin/bash

betty *.h *.c
if [ $? -eq 0 ]; then
    clear
    printf "\nBetty: No errors found.\n\n"
else
    clear
    printf "\nBetty: Errors found with code style. Run with --check to list all errors.\n\n"
fi



printf "simple_shell v0.3\n"

if [ "$1" = "--debug" ]; then
    gcc -Wall -Werror -Wextra -g -pedantic -std=gnu89 -fsanitize=address *.c -o hsh
    if [ $? -eq 0 ]; then
        ./hsh
    fi
elif [ "$1" = "--check" ]; then
    betty *.h *.c
else
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    if [ $? -eq 0 ]; then
        ./hsh
    fi
fi
