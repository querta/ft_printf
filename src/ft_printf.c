/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 19:10:29 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// #include <string.h>

static	int	parsestr(va_list var, t_struct *f)
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
			printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ndot:%d\ntype:%c\nlength:%d\e[0m\n", f->str, f->a, f->flag, f->width, f->precision, f->dot, f->type, f->length);
			processor(var, f);
		}
		else
		{
			f->a = ft_strchr(f->str, '\0');
			just_print_str(f);
			break ;
		}
		str_clear(f, f->str);
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list		var;
	int			length;
	t_struct	format;

	va_start(var, str);
	str_clear(&format, (char*)str);
	format.length = 0;
	// printf("\e[1m\e[2;32m \nf->str:%s\nf->a:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\narg:%s\n\e[0m\n", format.str, format.a, format.flag, format.width, format.precision, format.type, format.length, format.arg);
	parsestr(var, &format);
	length = format.length;
	va_end(var);
	return (length);
}
