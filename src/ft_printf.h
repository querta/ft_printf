/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:06:49 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/15 14:05:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINF_H
# define FT_PRINF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_pftlist
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		length;
	char	*str;
	char	*a;
}					t_struct;

int		parseformat(t_struct *f, va_list var);
int		ft_istype(char c);
void	str_clear(t_struct *format, char *str);
int		ft_istype(char c);
int		process_string(va_list var, t_struct *f);
int		ft_printf(const char *str, ...);

#endif