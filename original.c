#include <stdio.h>
#include <unistd.h>
// #include "libftprintf.a"

int main ()
{
// printf("%d\n", 11111);
// printf("%3d\n", 11111);

// printf("\n%10d\n", 11111);
// printf("%010d\n", 11111);
// printf("%-10d\n", 11111);

// printf("\n%10.2d\n", 11111);
// printf("%10.6d\n", 11111);
// printf("%10.11d\n", 11111);
// printf("%010.2d\n", 11111);
// printf("%-10.6d\n", 11111);

// printf("\n%10.15d\n", 11111);
// printf("%010.15d\n", 11111);
// printf("%-10.15d\n", 11111);
// printf("%-10.10d\n", 11111);

// printf("\n%.3d\n", 11111);
// printf("%-15.10d\n", 11111);

// printf("\n%20.15d\n", 11111);

char c = 'c';
printf("%c\n", c);
printf("%5c\n", c);
printf("%-5c\n", c);
printf("%1c\n", c);
printf("%05c\n", c);
printf("%.2c\n", c);
printf("%5.2c\n", c);
printf("%2.5c\n", c);
printf("%-2.5c\n", c);
printf("%02.5c\n", c);


	return (0);
}


/* 
gcc -Wall -Wextra -Werror original.c && ./a.out
*/