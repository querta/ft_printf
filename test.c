#include <stdio.h>
#include "includes/ft_printf.h"
#include <unistd.h>
// #include "libftprintf.a"

int main ()
{
	// printf("%s", "lalala\n");
	/* 
	$ если есть перенос
	% если переноса нет
	
	Флаги, Ширина, .Точность, Тип
	*/
	// printf("\n===== 1 =====\n");
	// printf ("\n ===== length:%d\n", 	printf("first line\nsecond%-----13.12d\nthird", 123456));
	// ft_printf("first line second%-----13.12d\n third", 123456);
	// printf("\n===== 2 =====\n");
	// printf ("\n ===== length:%d\n", 	printf("flag=0 width =13, precision = 12 %000000*.*d\n", -13, 12, 12));
	// ft_printf("flag=- width =13, precision = 12 %0*.*d\n", -13, 12, 12);
	// printf ("\n===== 3 =====\n");
	// ft_printf("%00000*.-5d$\n", -12, 1);
	// ft_printf("aaa%-10.20.30.40d");
	// ft_printf("aaa%6.4d", 123456);
	// printf ("\n===== 4 =====\n");
	// int i = printf("%6.7d\n", 11111);
	// char *str1 = "%6.7d\n";
	// char str1 = "%7.7d\n";
	// char str1 = "%8.7d\n";
	
	printf("orig length =%d\n", printf("%-6.7d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%-6.7d\n", 11111));

	printf("orig length =%d\n", printf("%-7.7d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%-7.7d\n", 11111));

	printf("orig length =%d\n", printf("%-8.7d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%-8.7d\n", 11111));

	printf("orig length =%d\n", printf("%-8.4d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%-8.4d\n", 11111));

	printf("orig length =%d\n", printf("%-8.7d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%-8.7d\n", 11111));

	printf("orig length =%d\n", printf("%08d\n", 11111));
	printf("my length =%d\n\n", ft_printf("%08d\n", 11111));

	// printf("%0000d\n", 12);
	// ft_printf("%0000d\n", 12);
	// ft_printf("%-1.31j3");
	// ft_printf("%01.1");
	// ft_printf("wwww");
	// printf("%00000*.-5d$\n", -12, 1);
	// printf("\n");
	// printf("aaa%-a");
	// ft_printf("aaaaaaaaaaa");
	//   ft_printf("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
	// ft_putchar_fd('0', 1);
	// write(1, 0, 1);
	// printf("aeawdaa");

	return (0);
}
