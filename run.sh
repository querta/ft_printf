#!/bin/bash

make re > /dev/null
# printf "\e[32myour program output: \e[0m\n"
gcc -Wall -Wextra -Werror test.c libftprintf.a && ./a.out