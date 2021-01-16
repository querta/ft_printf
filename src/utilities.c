/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:48:46 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/16 09:55:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	str_clear(t_struct *format, char *str)
{
	// format->flag = 'n';
	// format->width = 0;
	// format->precision = 0; 
	// format->type = '0';
	// format->length = 0;
	// format->argstart = NULL;
	// format->argend = NULL;
	ft_bzero(format, sizeof(*format));
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

void	just_print_str(t_struct *f)
{
	while (f->str < f->a)
	{
		ft_putchar_fd(*f->str, 1);
		f->str++;
		f->length++;
	}
}