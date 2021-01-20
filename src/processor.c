/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:54:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 15:31:43 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		processor(va_list var, t_struct *f)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (f->type == 'd' || f->type == 'i')
		len = process_ints(var, f);
	if (f->type == 'c' || f->type == '%')
		len = process_char(var, f);
	if (f->type == 's')
		len = process_string(var, f);

	if (f->arg)
		free(f->arg);
	return (1);
}
