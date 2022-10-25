#!/bin/bash

cd ..
make
cd my_printf_tester
gcc -o test_$1 test_$1.c -L ../ -lftprintf
./test_$1
