/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:54:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/16 11:22:04 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // printf
/* 
Ширина - максимальная длина строки, если мы выводим меньше ширины, то добавляются пробелы или нули слева
Точность - минимальная. Если точномть больше знакчения, то добавиет нулями слева
 */

void	process_print(t_struct *f)
{
	while (f->argstart < f->argend)
	{
		ft_putchar_fd(*f->argstart, 1);
		f->argstart++;
		f->length++;
	}
}

void	print_symb(char *c, int amount, t_struct *f)
{
	int n;

	n = amount;
	if (n > 0)
	{
		while (n)
		{
			ft_putchar_fd(*c, 1);
			f->length++;
			n--;
		}
	}
}

int		process_symb(va_list var, t_struct *f)
{
	int n;
	int len;
	char *s;
	int	i;

	n = va_arg(var, int);
	f->argstart = ft_itoa(n); // не забудь зафришить плиз
	s = f->argstart;
	len = ft_strlen(s);
	f->argend = f->argstart + len;
	// printf("\nf->aegstart:%s\n f->argend:%s\n", f->argstart, f->argend);
	if (len > f->precision)
		i = len;
	else
		i = f->precision;
	// printf("\ni1 =%d", i);
	if (len >= f->width && len >= f->precision)
		process_print(f);
	else
	{
		i = f->width - i;
		// printf("\ni2 =%d\n", i);
		print_symb(" ", i, f);
		i = f->precision - len;
		print_symb("0", i, f);
		process_print(f);
		// if (f->precision > f->width)

		// ft_putchar_fd(n, 1);
		// if (f->precision == 0)
		// 	f->length += f->width;
	}
		
	free(s);
	return (0);
}

int		process_string(va_list var, t_struct *f)
{
	// t_struct	p;

	// ft_bzero(&p, sizeof(p));
	if (f->type == 'd' || f->type == 'i' || f->type == 'c')
		process_symb(var, f);

	return (1);
}
