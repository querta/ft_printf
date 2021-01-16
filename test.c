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
	// ft_printf("first line second%-----13.12d\n third\n", 123456);
	// printf("first line second%-----13.12d\n third\n", 123456);
	// printf("\n===== 2 =====\n");
	// printf ("\n ===== length:%d\n", 	printf("flag=0 width =13, precision = 12 %000000*.*d\n", -13, 12, 12));
	// ft_printf("flag=- width =13, precision = 12 %0*.*d\n", -13, 12, 12);
	// printf("flag=- width =13, precision = 12 %0*.*d\n", -13, 12, 12);
	// printf ("\n===== 3 =====\n");
	// ft_printf("%00000*.-5d$\n", -12, 1);
	// ft_printf("aaa%-10.20.30.40d\n");
	// ft_printf("aaa%6.4d\n", 123456);
	// printf("%00000*.-5d$\n", -12, 1);
	// printf("aaa%-10.20.30.40d");
	// printf("aaa%6.4d", 123456);
	// printf ("\n===== 4 =====\n");
	// int i = printf("%6.7d\n", 11111);
	// char *str1 = "%6.7d\n";
	// char str1 = "%7.7d\n";
	// char str1 = "%8.7d\n";	

	// printf("-6.7 orig length =%d\n", printf("%-6.7d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-6.7d\n", 11111));

	// printf("-7.7 orig length =%d\n", printf("%-7.7d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-7.7d\n", 11111));

	// printf("-8.7 orig length =%d\n", printf("%-8.7d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-8.7d\n", 11111));

	// printf("-8.4 orig length =%d\n", printf("%-8.4d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-8.4d\n", 11111));

	// printf("-8.7 orig length =%d\n", printf("%-8.7d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-8.7d\n", 11111));

	// printf("08 orig length =%d\n", printf("%08d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%08d\n", 11111));

	// printf("-8 orig length =%d\n", printf("%-8d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-8d\n", 11111));

	// printf("8.10 orig length =%d\n", printf("%8.10d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%8.10d\n", 11111));

	// printf("orig length =%d\n", printf("%8.10d\n", 0));
	// printf("my length =%d\n\n", ft_printf("%8.10d\n", 0	));
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;

	ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d); //T26
	printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d); //T26
	ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d); //T3
	printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d); //T3
	ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4
	printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4
	ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d); //T5
	printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d); //T5
	ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d); //T6
	printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d); //T6
	ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d); //T7
	printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d); //T7
	ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d); //T8
	printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d); //T8
	ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d); //T9
	printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d); //T9
	ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d); //T10
	printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d); //T10
	ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d); //T11
	printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d); //T11


	// printf("orig length =%d\n", printf("111%c\n", 'a'));
	// printf("my length =%d\n\n", ft_printf("111%c\n", 'a'));

	// printf("orig length =%d\n", printf("1%5c\n", 'a'));
	// printf("my length =%d\n\n", ft_printf("1%5c\n", 'a'));


	// printf("orig length =%d\n", printf("1%5c\n", 'a'));
	// printf("my length =%d\n\n", ft_printf("1%5c\n", 'a'));


	// printf("%10c", '\0');

	// while (1){};

	// printf("p = 0 orig length =%d\n", printf("%0.d\n", 0));
	// printf("my length =%d\n\n", ft_printf("%0.d\n", 0));


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
