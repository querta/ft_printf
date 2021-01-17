/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:54:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/17 18:04:08 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // printf

// Ширина - максимальная длина строки, если мы выводим меньше ширины, то добавляются пробелы или нули слева
// Точность - минимальная. Если точномть больше знакчения, то добавиет нулями слева


int		process_string(va_list var, t_struct *f)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (f->type == 'd' || f->type == 'i')
		len = process_ints(var, f);
	// if (f->type == 'c' || f->type == '%')
	// 	len = process_char(var, f);

	while (i <= len)
		ft_putchar_fd(f->arg[i++], 1);

	free(f->arg);
	return (1);
}
