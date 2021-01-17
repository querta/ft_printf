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
	// ft_printf("first line\nsecond%-----13.12d\nthird", 123456);
	// printf("\n===== 2 =====\n");
	// printf ("\n ===== length:%d\n", 	printf("flag=0 width =13, precision = 12 %000000*.*d\n", -13, 12, 12));
	// ft_printf("flag=- width =13, precision = 12 %0*.*d\n", -13, 12, 12);
	// printf("flag=- width =13, precision = 12 %0*.*d\n", -13, 12, 12);
	// printf ("\n===== 3 =====\n");
	// ft_printf("%00000*.-5d$\n", -12, 1);
	// printf("%00000*.-5d$\n", -12, 1);
	// ft_printf("aaa%-10.20.30.40d\n", 123);
	// printf("aaa%-10.20.30.40d\n", 123);
	// ft_printf("aaa%6.4d\n", 123456);
	// printf("aaa%6.4d\n", 123456);
	// printf ("\n===== 4 =====\n");


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
	// printf("%08d\n", 11111);
	// ft_printf("%08d\n", 11111);

	// printf("-8 orig length =%d\n", printf("%-8d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("%-8d\n", 11111));

	// printf("8.10 orig length =%d\n", printf("aaa%8.10d\n", 11111));
	// printf("my length =%d\n\n", ft_printf("aaa%8.10d\n", 11111));

	// printf("orig length =%d\n", printf("aaa%8.10d\n", 0));
	// printf("my length =%d\n\n", ft_printf("aaa%8.10d\n", 0));

	// printf("orig length =%d\n", printf("aaa%3d\n", 0));
	// printf("my length =%d\n\n", ft_printf("aaa%3d\n", 0));

	// printf("1orig length =%d\n", printf("aaa%-1d\n", 1));
	// printf("my length =%d\n\n", ft_printf("aaa%-1d\n", 1));

	// printf("1orig length =%d\n", printf("aaa%-1d\n", 0));
	// printf("my length =%d\n\n", ft_printf("aaa%-1d\n", 0));

	// printf("orig length =%d\n", printf("%5.d\n", 0));
	// printf("my length =%d\n\n", ft_printf("%5.d\n", 0));
	
	// ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647); //T26

	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;

	// printf("%-1i\n", d); //T26
	// ft_printf("%-1i, %-1d\n", i, i); //T26
				
// printf("--=== 42TEST ===--\n");
	ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
	//    printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
// 	ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
// 	   printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
// 	ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
// 	   printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
// 	ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
// 	   printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
// 	ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
// 	   printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
// 	ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
// 	   printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
// 	ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
// 	   printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
// 	ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
// 	   printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
// 	ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
// 	   printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
// 	ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11
// 	   printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11

	// // printf("\n---=== с - тип===---\n");
	// char typec = '\0';
	// printf("orig length =%d\n", printf("111d%cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("111d%cd\n", typec));
	// printf("orig length =%d\n", printf("a%-2cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%-2cd\n", typec));
	// printf("orig length =%d\n", printf("a%-2.cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%-2.cd\n", typec));


	// // printf("d%cd\n", typec);
	// // ft_printf("d%cd\n", typec);
	// printf("\n---=== Работает без флагов ===---\n");
	// printf("orig length =%d\n", printf("a%05.2cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%05.2cd\n", typec));
	// printf("orig length =%d\n", printf("a%2.5cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%2.5cd\n", typec));
	// printf("orig length =%d\n", printf("a%02.5cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%02.5cd\n", typec));
	// printf("orig length =%d\n", printf("a%-2.5cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%-2.5cd\n", typec));
	// printf("orig length =%d\n", printf("a%05cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%05cd\n", typec));


	// printf("\n---=== если 1 0, то не выводить, но считать как 1 ===---\n");
	// printf("orig length =%d\n", printf("a%5.2cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%5.2cd\n", typec));
	// printf("orig length =%d\n", printf("a%-5.2cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%-5.2cd\n", typec));
	// printf("orig length =%d\n", printf("a%5.0cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%5.0cd\n", typec));
	// printf("orig length =%d\n", printf("a%-5.cd\n", typec));
	// printf("my length =%d\n\n", ft_printf("a%-5.cd\n", typec));

	// printf("\n---=== процентики ===---\n");
	// ft_printf("%%");
	// printf("orig length =%d\n", printf("a%%d\n"));
	// printf("my length =%d\n\n", ft_printf("a%%d\n"));
	// printf("orig length =%d\n", printf("a%010%d\n"));
	// printf("my length =%d\n\n", ft_printf("a%010%d\n"));
	// printf("orig length =%d\n", printf("a%010.1%d\n"));
	// printf("my length =%d\n\n", ft_printf("a%010.1%d\n"));
	// printf("orig length =%d\n", printf("a%010.4%d\n"));
	// printf("my length =%d\n\n", ft_printf("a%010.4%d\n"));
	// printf("orig length =%d\n", printf("%-05%\n"));
	// printf("my length =%d\n\n", ft_printf("%-05%\n"));

	// printf("%05d\n", 1);
	// ft_printf("%05d\n", 1);
	// printf("%05c\n", '\0');
	// ft_printf("%05c\n", '\0');
	// printf("%5c\n", '\0');
	// ft_printf("%5c\n", '\0');
	// ft_printf("%5c\n", 'a');
	// ft_printf("%05d", 1);


	// printf("%5.d|\n", 0);
	// ft_printf("%5.d|\n", 0);
	// printf("%-5c|\n", '\0');
	// ft_printf("%-5c|\n", '\0');


	// while (1){};

	// printf("p = 0 orig length =%d\n", printf("%10.d\n", 0));
	// printf("my length =%d\n\n", ft_printf("%10.d\n", 0));

	return (0);
}
