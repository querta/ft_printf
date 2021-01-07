#include <stdio.h>
#include "src/ft_printf.h"
#include <unistd.h>
// #include "libftprintf.a"

int main ()
{
	// printf("%s", "lalala\n");
	/* 
	$ если есть перенос
	% если переноса нет
	*/
	printf ("\n===== 1 =====\n");
	ft_printf("first line\nsecond%-333.12d\nthird", 123456);
	printf ("\n===== 2 =====\n");
	ft_printf("flag=0 width =333, precision = 12 %0*.*d\n", 333, 12);
	// printf("\n");
	// printf("aaa%-a");
	// ft_printf("aaaaaaaaaaa");
	//   ft_printf("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
	// ft_putchar_fd('0', 1);
	// write(1, 0, 1);
	// printf("aeawdaa");

	return (0);
}