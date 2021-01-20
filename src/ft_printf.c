/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 20:44:09 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	parsestr(var, &format);
	length = format.length;
	va_end(var);
	return (length);
}
