/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:49:17 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/16 21:06:39 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // printf


// Если dot = 1 и precision = 0, то при n = 0 выводим только пробел  */


static	int		make_width(t_struct *f)
{
	char *newstr;
	char *tmp;
	int len;

	newstr = 0;
	len = ft_strlen(f->arg);
	// printf("\nlen:%d\n", len);
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
	len = ft_strlen(f->arg);
	if (f->precision > len)
	{
		if (!(newstr = ft_calloc((f->precision - len + 1), sizeof(char))))
			return (0);
		ft_memset(newstr, '0', f->precision - len);
		tmp = ft_strjoin(newstr, f->arg);
		free(f->arg);
		free(newstr);
		f->arg = tmp;
	}
	return (0);
}

int		process_ints(va_list var, t_struct *f)
{
	int		arg;
	int		zero;

	zero = 0;
	arg = 0;
	arg = va_arg(var, int);
	if (!(f->arg = ft_itoa(arg)))
		return (0);
	make_precision(f);
	make_width(f);
	if (f->type == 'c')
		f->length++;
	else
		f->length = ft_strlen(f->arg);
	return (f->length);
}