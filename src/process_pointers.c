/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:49:17 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 20:56:52 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*makestr(char **newstr, int len, t_struct *f)
{
	char *str;

	str = f->arg;
	ft_memset(*newstr, '0', len);
	return (str);
}

static	int		make_width(t_struct *f)
{
	char	*newstr;
	char	*tmp;
	int		len;
	char	*str;

	str = f->arg;
	len = (int)ft_strlen(f->arg);
	if (f->width > len)
	{
		if (!(newstr = ft_calloc((f->width - len + 1), sizeof(char))))
			return (-1);
		if ((f->flag == '0') && (f->dot == 0 || f->precision < 0))
			str = makestr(&newstr, f->width - len, f);
		else
			ft_memset(newstr, ' ', f->width - len);
		if (f->flag == '-')
			tmp = ft_strjoin(str, newstr);
		else
			tmp = ft_strjoin(newstr, str);
		free(f->arg);
		free(newstr);
		f->arg = tmp;
	}
	return (0);
}

static	int		make_precision(t_struct *f)
{
	char	*newstr;
	char	*tmp;
	int		len;
	char	*str;

	newstr = 0;
	str = f->arg;
	len = (int)ft_strlen(f->arg);
	if (f->precision >= len)
	{
		if (!(newstr = ft_calloc((f->precision - len + 1), sizeof(char))))
			return (-1);
		str = makestr(&newstr, f->precision - len, f);
		tmp = ft_strjoin(newstr, str);
		free(f->arg);
		free(newstr);
		f->arg = tmp;
	}
	tmp = ft_strjoin("0x", f->arg);
	free(f->arg);
	f->arg = tmp;
	return (0);
}

static	int		make_arg(va_list var, t_struct *f)
{
	size_t arg;

	arg = (size_t)va_arg(var, void*);
	if (f->dot == 1 && f->precision == 0 && arg == 0)
	{
		if (!(f->arg = (char *)ft_calloc(2, sizeof(char))))
			return (-1);
		*f->arg = (char)arg;
	}
	else
	{
		if (!(f->arg = ft_itoa_base(arg, 16)))
			return (-1);
	}
	return (arg);
}

int				process_pointers(va_list var, t_struct *f)
{
	int		len;
	size_t	arg;
	int		i;

	i = 0;
	arg = make_arg(var, f);
	make_precision(f);
	make_width(f);
	len = (int)ft_strlen(f->arg);
	f->length += len;
	while (i < len)
		ft_putchar_fd(f->arg[i++], 1);
	return (len);
}
