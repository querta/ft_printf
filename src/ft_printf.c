/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/09 20:04:49 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

#include <string.h>


// int		ft_printf(char *apFormat, ...)
// {
// 	va_list ap;             /* point on next unnamed argument */

// 	va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
// 	for (char *p = apFormat; *p; p++)
// 	{
// 	if (*p !='%')
// 	{
// 		putchar(*p);
// 		continue;
// 	}
// 	switch(* (++p))
// 	{
//       case 'd':
//       {
//         int ival = 0;
//         ival = va_arg(ap, int);
//         printf ("%d", ival);
//         break;
//       }
//       case 'f':
//       {
//         double  dval = 0.;
//         dval = va_arg(ap, double);
//         printf("%f", dval);
//         break;
//       }
//       case 's':
//       {
//         for(char *sval = va_arg(ap, char *); *sval; sval++)
//           putchar(*sval);
//         break;
//       }
//       default:
//       {
//         putchar(*p);
//         break;
//       }
//     }
//   }
//   va_end(ap); /* clean all */
//   return (0);
// }

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void parceprecision()
{
	
}

char	*parseformat(char *a, t_struct *format, va_list var)
{
	char *s;
	int i;

	i = 0;
	s = ++a;
	while (1)
	{
		while (*s == '-' || *s == '0')
			format->flag = *s++;
		if (ft_isdigit((int)*s) || *s == '*')
		{
			while (ft_isdigit((int)*s))
				format->width = (int)(format->width * 10 + *s++ - '0');
			if (*s == '*')
			{
				format->width = va_arg(var, int);
				if (format->width < 0)
				{
					format->flag = '-';
					format->width *= -1;
				}
				s++;
			}
		format->length += format->width;
		}
		if (*s++ == '.')
		{
			while (ft_isdigit((int)*s))
				format->precision = (int)(format->precision * 10 + *s++ - '0');
			if (*s == '*')
			{
				format->precision = va_arg(var, int);
				s++;
			}
		}
		if (ft_istype(*s))
			format->type = *s++;
		format->str = ++s;
		break;
	}
	return (s);
}

void	strinit(t_struct *format, char *str)
{
	format->flag = 'n';
	format->width = 0;
	format->precision = 0; 
	format->type = '0';
	format->length = 0;
	format->str = str;
	format->a = str;
}

// int		parsestr(char *s, va_list var, t_struct *format)
int		parsestr(va_list var, t_struct *f)
{
	// size_t i;
	// char *a;
	char *s;
	// t_struct *form;

	// s = ft_strdup((char *)str);
	// strinit(format, s);
	// if (!(form = (t_struct*)ft_calloc(sizeof(t_struct), 1)))
	// 	return (0);
	// a = s;
	// a = f->str;
	s = f->str;

	if ((f->a = ft_strchr(f->str, '%')))
		parseformat(f->a, f, var);
	else 
		f->a = ft_strchr(f->str, '\0');
	while (s < f->a)
	{
		ft_putchar_fd(*s++, 1);
		f->length++;
	}
	// f->str += 1;
	// format->str = s;
	// printf("\nformat->str: %s\n", f->str);
	printf("\ns:%c a:%c |\n", *f->str, *f->a);
	printf("\e[1m\e[2;32m \nf->str:%s\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\e[0m\n", f->str, f->flag, f->width, f->precision, f->type, f->length);
	// printf("gogogogog\n\n\n\n%s\n%s\n%s\n%s\n", format->str++, format->str++, format->str++, format->str);
  // }
  // while (s[i])
  // {
  //   if (s[i] == '')
  //   i++;
  // }
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list var;  // переменный аргумент
	int res;
	t_struct *format;

	va_start(var, str);   // инициализирует var после аргумента str
  // s = (char *)str;
  // char *par = NULL;
  // par = va_arg(var, char *); // запишет в par текущий аргумент и итерирует аргумент

	if (!(format = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	strinit(format, (char*)str);
	res = parsestr(var, format);
  //Достаём следующий, указывая тип аргумента
  // testsum += va_arg(args, unsigned);

  // printf("%s %s", par, (par = va_arg(var, char *)));

  // while(*s)
  // {
  //   if (*s != '%')
  //   {
  //     ft_putchar_fd(*s, 1);
  //     s++;
  //   }
  //   if (*s == 'd')
    
  //   s++;
  // }

	va_end(var);
	
	return (res);
}
