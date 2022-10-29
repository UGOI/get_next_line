#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 test_get_next_line.c ../get_next_line.c
# gcc -Wall -Wextra -Werror test_get_next_line.c ../get_next_line.c
./a.out 
