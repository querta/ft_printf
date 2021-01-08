/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/08 17:40:48 by mmonte           ###   ########.fr       */
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

char	*parseformat(char *a, t_struct *format, va_list var)
{

// typedef struct		s_pftlist
// {
// 	char	flag;
// 	char	width;
// 	int		precision;
// 	int		size;
// 	char	type;
// }					t_struct;
  // formstruct->flag = f;
  // printf("flag = %s\n", formstruct->flag);
	char *s;
	int i;

	i = 0;
	s = ++a;
	while (1)
	{
		if (*s == '-' || *s == '0')
			format->flag = *s++;
		printf("\nwidth s=%c\n", *s);
		if (ft_isdigit((int)*s) || *s == '*' || *s == '-')
		{
			if (*s == '-')
				format->flag = *s++;
			while (ft_isdigit((int)*s))
				format->width = (int)(format->width * 10 + *s++ - '0');
			printf("\n after while width s=%c\n", *s);
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
		}
		printf("\nprecision s=%c\n", *s);
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
		printf("\ntype s=%c\n", *s);
		if (ft_istype(*s))
			format->type = *s++;
		break;
	}

	printf("\e[32m \na:%c\nflag:%c\nwidth:%d\nprecision:%d\ntype:%c\nlength:%d\n \e[0m", *s, format->flag, format->width, format->precision, format->type, format->length);
	(void)format;
	return (s);
}

void	strinit(t_struct *format)
{
	format->flag = 'n';
	format->width = 0;
	format->precision = 0; 
	format->type = '0';
	format->length = 0;
	// (*format)->flag = 0;
	// (*format)->width = 0;
	// (*format)->precision = 0; 
	// (*format)->type = '0';
	// (*format)->length = 0;
	// return (format);
}

int		parsestr(const char *str, va_list var, t_struct *form)
{
	// size_t i;
	char *a;
	char *s;
	// t_struct *form;

	s = ft_strdup((char *)str);
	strinit(form);
	// if (!(form = (t_struct*)ft_calloc(sizeof(t_struct), 1)))
	// 	return (0);
	a = s;

	if ((a = ft_strchr(s, '%')))
		parseformat(a, form, var);
	else 
		a = ft_strchr(s, '\0');
	while (s < a)
		ft_putchar_fd(*s++, 1);
	printf("\ns:%c a:%c |\n", *s, *a);
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
	t_struct *form;

	va_start(var, str);   // инициализирует var после аргумента str
  // s = (char *)str;
  // char *par = NULL;
  // par = va_arg(var, char *); // запишет в par текущий аргумент и итерирует аргумент

	if (!(form = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	res = parsestr(str, var, form);
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
