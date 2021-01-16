/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/16 15:20:29 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

#include <string.h>

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
	// printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ndot:%d\ntype:%c\nlength:%d\e[0m\n", f->str, f->a, f->flag, f->width, f->precision, f->dot, f->type, f->length);

	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list var;  // переменный аргумент
	int length;
	t_struct format;

	va_start(var, str);   // инициализирует var после аргумента str
	str_clear(&format, (char*)str);
	// printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\nargstart:%s\nargend:%s\e[0m\n", format.str, format.a, format.flag, format.width, format.precision, format.type, format.length, format.arg, format.argend);
	parsestr(var, &format);
	length = format.length;
	va_end(var);
	
	return (length);
}
