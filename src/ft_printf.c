/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/15 13:19:30 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

#include <string.h>



void	just_print_str(t_struct *f)
{
	while (f->str < f->a)
	{
		ft_putchar_fd(*f->str, 1);
		f->str++;
		f->length++;
	}
}

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
			process_string(var, f);
		}
		else
		{
			f->a = ft_strchr(f->str, '\0');
			just_print_str(f);
			break;
		}
	}
	printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\e[0m\n", f->str, f->a, f->flag, f->width, f->precision, f->type, f->length);

	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list var;  // переменный аргумент
	int length;
	t_struct format;

	va_start(var, str);   // инициализирует var после аргумента str
  // s = (char *)str;
  // char *par = NULL;
  // par = va_arg(var, char *); // запишет в par текущий аргумент и итерирует аргумент

	// if (!(format = (t_struct*)malloc(sizeof(t_struct))))
	// 	return (0);
	// printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\e[0m\n", format.str, format.a, format.flag, format.width, format.precision, format.type, format.length);

	// ft_bzero(&format, sizeof(format));

	str_clear(&format, (char*)str);
	// printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\e[0m\n", format.str, format.a, format.flag, format.width, format.precision, format.type, format.length);
	parsestr(var, &format);
	length = format.length;
	
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
