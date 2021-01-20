/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:33:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 20:30:51 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_char_str(t_struct *f, char c)
{
	if (f->flag == '-')
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(f->arg, 1);
	}
	else
	{
		ft_putstr_fd(f->arg, 1);
		ft_putchar_fd(c, 1);
	}
}

int				process_char(va_list var, t_struct *f)
{
	char c;

	if (f->type == '%')
		c = '%';
	else
		c = (char)va_arg(var, int);
	if (f->width > 1)
	{
		if (!(f->arg = (char *)ft_calloc(f->width, sizeof(char))))
			return (-1);
		if (f->flag == '0')
			ft_memset(f->arg, '0', f->width - 1);
		else
			ft_memset(f->arg, ' ', f->width - 1);
		print_char_str(f, c);
		f->length += f->width;
	}
	else
	{
		ft_putchar_fd(c, 1);
		f->length++;
	}
	return (f->width);
}
