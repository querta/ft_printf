/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:58:35 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/19 08:16:22 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int		make_width(t_struct *f)
{
	int len;
	char *newstr;
	char *tmp;

	len = 0;
	len = ft_strlen(f->arg);
	if (f->width > len)
	{
		if (!(newstr = (char *)ft_calloc((f->width - len + 1), sizeof(char))))
			return (-1);
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
	int len;
	len = 0;
	char *tmp;

	len = ft_strlen(f->arg);
	if (f->precision < len && f->dot == 1)
	{
		tmp = ft_substr(f->arg, 0, f->precision);
		free(f->arg);
		f->arg = tmp;
	}
	
	return (0);
}

int	process_string(va_list var, t_struct *f)
{
	int len;
	char *str;
	len = 0;

	(void)f;
	str = va_arg(var, char*);
	if (!str)
		f->arg = ft_strdup("(null)");
	else
		f->arg = ft_strdup(str);
	len = ft_strlen(f->arg);
	make_precision(f);
	make_width(f);
	ft_putstr_fd(f->arg, 1);
	f->length += ft_strlen(f->arg);

	// printf("\n=== f->arg=%s\n", f->arg);
	// if (f->precision > len)
	// {
	// 	if (f->flag == '-')
	// 	{
			
	// 	}
	// }
	
	// printf("\nstr:%s f-arg:%s\n", str, f->arg);

	return (len);
}