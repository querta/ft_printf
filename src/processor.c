/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:54:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/15 16:19:31 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
Ширина - максимальная длина строки, если мы выводим меньше ширины, то добавляются пробелы или нули слева
Точность - минимальная. Если точномть больше знакчения, то добавиет нулями слева
 */



int		process_symb(va_list var, t_struct *f)
{
	int n;
	int len;
	char *s;

	n = va_arg(var, int);
	s = ft_itoa(n); // не забудь зфришить плиз
	len = ft_strlen(s);
	if (len <= f->width || len <= f->precision)
	{
		if (f->precision > f->width)

		ft_putchar_fd(n, 1);
		if (f->precision = 0)
			f->length += f->width;
	}
	free(s);
	return (0);
}

int		process_string(va_list var, t_struct *f)
{
	if (f->type == 'd' || f->type == 'i' || f->type == 'c')
		process_symb(var, f);
	
	return (1);
}
