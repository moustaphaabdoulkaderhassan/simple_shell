#!/bin/bash

# Simple Shell 0.1

# Check if there are no command-line arguments
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <command> [arguments]"
    exit 1
fi

# Get the command from the first argument
command=$1
shift  # Remove the command from the argument list

# Perform actions based on the command
case $command in
    "hello")
        echo "Hello, World!"
        ;;
    "greet")
        if [ "$#" -eq 0 ]; then
            echo "Usage: $0 greet <name>"
            exit 1
        fi
        name=$1
        echo "Greetings, $name!"
        ;;
    *)
        echo "Unknown command: $command"
        exit 1
        ;;
esac

exit 0

