/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:08:40 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/15 13:36:25 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	parse_width(t_struct *f, va_list var)
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
	// f->length += f->width;
	}
}

static	void parse_precision(t_struct *f, va_list var)
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
}

int		parseformat(t_struct *f, va_list var)
{
	while (!ft_istype(*f->a) && (*f->a != '\0'))
	{
		while (*f->a == '-' || *f->a == '0')
			f->flag = *f->a++;
		parse_width(f, var);
		parse_precision(f, var);		
	}
	f->type = *f->a;
	if (ft_istype(f->type))
	{ 
		f->a++;
		f->str = f->a;
	}
	else
		return (0);
	return (1);
}
