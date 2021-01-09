/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:06:49 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/09 19:07:49 by mmonte           ###   ########.fr       */
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
	// int		size;
	char	type;
	int		length;
	char	*str;
	char	*a;
}					t_struct;

int		ft_printf(const char *str, ...);

#endif