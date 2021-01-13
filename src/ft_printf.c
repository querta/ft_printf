/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/13 20:35:57 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

#include <string.h>

void	str_clear(t_struct *format, char *str)
{
	format->flag = 'n';
	format->width = 0;
	format->precision = 0; 
	format->type = '0';
	format->length = 0;
	format->str = str;
	format->a = str;
}

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
		c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void	parse_width(t_struct *f, va_list var)
{
	if (ft_isdigit((int)*f->a) || *f->a == '*')
	{
		f->width = 0;
		while (ft_isdigit((int)*f->a))
			f->width = (int)(f->width * 10 + *f->a++ - '0');
		if (*f->a == '*')
		{
			f->width = va_arg(var, int);
			if (f->width < 0)
			{
				f->flag = '-';
				f->width *= -1;
			}
			f->a++;
		}
	f->length += f->width;
	}
}

void parse_precision(t_struct *f, va_list var)
{
	if (*f->a++ == '.')
	{
		f->precision = 0;
		while (ft_isdigit((int)*f->a))
			f->precision = (int)(f->precision * 10 + *f->a++ - '0');
		if (*f->a == '*')
		{
			f->precision = va_arg(var, int);
			f->a++;
		}
	}
	// printf("tochnost f->a:%s\n", f->a);
}

int		parseformat(t_struct *f, va_list var)
{
	// f->a++;
	while (!ft_istype(*f->a) && (*f->a != '\0'))
	{
		while (*f->a == '-' || *f->a == '0')
			f->flag = *f->a++;
		parse_width(f, var);
		parse_precision(f, var);
		// printf("width:%d precision:%d a:%s\n", f->width, f->precision, f->a);
		// if (*f->a == '\0')
		// 	break;
		// if (ft_istype(*f->a))
		// 	break;
		
	}
	// if (ft_istype(*f->a))
	// 	{
			// printf("\nbefore save type f->a: %s\n", f->a);

	f->type = *f->a;
	if (ft_istype(f->type))
	{ 
		// printf("bbb\n");
		f->a++;
		f->str = f->a;
	}
	else
	{
		return (0);
		// printf("aaa\n");
		// f->a = ft_strchr(f->str, '\0');
		// f->str = f->a;
	}
	
			// printf("\nafter save type f->str:%s f->a:%s\n", f->str, f->a);
			// break;
			// f->str = f->a;
		// }
		// else
		// {
		// 	str_clear(f, f->str);
		// 	f->a = ft_strchr(f->str, '\0');
		// 	// break;
		// 	// printf("\nbo type f->str: %s f->a: %s\n", f->str, f->a);
		// }
		// f->a++;
	// if (ft_istype(*f->a))
		// printf("1111");
	return (1);
}

void	just_print_str(t_struct *f)
{
	// 
	while (f->str < f->a)
	{
		ft_putchar_fd(*f->str, 1);
		f->str++;
		f->length++;
	}
}
/* 
Изменить как-то parsestr 
Принцип такой: парсер возвращает str = a, если спарсил параметры
Если параметров нет, он вернет структуру, где a и str на месте %
Можно в a записывать позицию конца строки, тогда после парсинга можно будет изи вывести

 */

// int		processor_string(va_list var, t_struct *f)
// {
	
// }


int		parsestr(va_list var, t_struct *f)
{
	while (f->a != '\0')
	{
		f->a = ft_strchr(f->str, '%');
		if (f->a)
		{
			just_print_str(f);
			f->a++;
			if (!parseformat(f, var))
				just_print_str(f);
			// just_print_str(f);
			// process_string(var, f);
		}
		else
		{
			f->a = ft_strchr(f->str, '\0');
			just_print_str(f);
			break;
		}
	}
	// just_print_str(f);



	// if ((f->a = ft_strchr(f->str, '%')))
	// {
	// 	just_print_str(f);
	// 	parseformat(f, var);
	// 	// va_list
	// 	s = f->str;
	// }
	// else 
	// {
	// 	f->a = ft_strchr(f->str, '\0');
	// 	just_print_str(f);
	// }

	// f->str = s;


	// f->str += 1;
	// format->str = s;
	// printf("\nformat->str: %s\n", f->str);
	// printf("\ns:%c a:%c |\n", *f->str, *f->a);
	printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\e[0m\n", f->str, f->a, f->flag, f->width, f->precision, f->type, f->length);
	// printf("gogogogog\n\n\n\n%s\n%s\n%s\n%s\n", format->str++, format->str++, format->str++, format->str);

	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list var;  // переменный аргумент
	int length;
	t_struct *format;

	va_start(var, str);   // инициализирует var после аргумента str
  // s = (char *)str;
  // char *par = NULL;
  // par = va_arg(var, char *); // запишет в par текущий аргумент и итерирует аргумент

	if (!(format = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	str_clear(format, (char*)str);
	parsestr(var, format);
	length = format->length;
	
  //Достаём следующий, указывая тип аргумента
  // testsum += va_arg(args, unsigned);

  // printf("%s %s", par, (par = va_arg(var, char *)));

  // while(*s)
  // {
  //   if (*s != '%')
  //   {
  //     ft_putchar_fd(*s, 1);
  //     s++;
  //   }
  //   if (*s == 'd')
    
  //   s++;
  // }

	va_end(var);
	
	return (length);
}
