# Simple shell

An attempt at developing a minimal shell using C as part of the ALX software engineering program.


## Instructions
The easiest way of using the shell is via the shell script.

    ./run.sh

To build it manually, compile using `gcc`.

    gcc *.c -o hsh

You can also use the exact flags used by the checker in ALX.

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## Features (still WIP)
- Running commands using their complete paths.
```
$ /usr/bin/echo "Bazinga!"
"Bazinga!"
$
```

- Running commands directly.
```
$ echo "Bazinga"
"Bazinga"
$
```
- One built-in command – `exit`

## More coming... maybe
- Piping
- Redirection
- More built-ins like cd and help
- Running in non-interactive mode

<br />
<small>Written in C by Jahtomini Ogunderu and Moustapha Abdoulkader Hassan.<small/>
