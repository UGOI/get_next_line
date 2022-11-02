#!/bin/bash

buf_size=2

if [[ $# -eq 0 ]]
then
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$buf_size -o run test_get_next_line.c ../get_next_line.c
    ./run
    exit 0
fi
if [ $1 = "debug" ]
then
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$buf_size -g -o debug test_get_next_line.c ../get_next_line.c
    gdb debug
elif [ $1 = "run" ]
then
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$buf_size -g -o run test_get_next_line.c ../get_next_line.c
    ./run
else
    echo "Invalid argument. Use [debug], nothing []."
fi

