#!/bin/bash

make re > /dev/null
# printf "\e[32myour program output: \e[0m\n"
if $1
then
gcc -Wall -Wextra -Werror test.c libftprintf.a && ./a.out
else
gcc test.c libftprintf.a && ./a.out
fi