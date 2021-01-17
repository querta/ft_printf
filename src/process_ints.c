/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:49:17 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/17 18:03:18 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		make_width(t_struct *f)
{
	char *newstr;
	char *tmp;
	int len;

	newstr = 0;
	len = (int)ft_strlen(f->arg);
	if (f->width > len)
	{
		if (!(newstr = ft_calloc((f->width - len + 1), sizeof(char))))
			return (0);
		if (f->flag == '0')
			ft_memset(newstr, '0', f->width - len);
		else
			ft_memset(newstr, ' ', f->width - len);
		if (f->flag == '-')
			tmp = ft_strjoin(f->arg, newstr);
		else 
			tmp = ft_strjoin(newstr, f->arg);
		free(f->arg);
		free(newstr);
		f->arg = tmp;
	}
	return (0);
}

static	int		make_precision(t_struct *f)
{
	char *newstr;
	char *tmp;
	int	len;

	newstr = 0;
	len = (int)ft_strlen(f->arg);
	if (f->precision > len)
	{
		if (!(newstr = ft_calloc((f->precision - len + 1), sizeof(char))))
			return (0);
		if ((f->type != 'c'))
			ft_memset(newstr, '0', f->precision - len);
		tmp = ft_strjoin(newstr, f->arg);
		free(f->arg);
		free(newstr);
		f->arg = tmp;
	}
	return (0);
}

int make_arg(va_list var, t_struct *f)
{
	int arg;

	arg = va_arg(var, int);
	if (f->dot && !f->precision && arg == 0)
	{
		if (!(f->arg = (char *)ft_calloc(2, sizeof(char))))
			return (-1);
		*f->arg = arg;
	}
	else
	{
		if (!(f->arg = ft_itoa(arg)))
			return (-1);
	}
	return (arg);
}

int		process_ints(va_list var, t_struct *f)
{
	int	len;
	int	arg;

	arg = make_arg(var, f);
	make_precision(f);
	make_width(f);
	len = (int)ft_strlen(f->arg);
	f->length += len;
	return (len);
}