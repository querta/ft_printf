/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/25 21:22:45 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  

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

char *parseformat(char *f, t_struct *formstruct)
{

  // formstruct->flag = f;
  // printf("flag = %s\n", formstruct->flag);

  while 
  return (formstruct);
}

int   parsestr(const char *str, va_list par)
{
  // size_t i;
  char *a;
  char *s;
  t_struct *form;
  
  (void) par;
  s = ft_strdup((char *)str);
  form = (t_struct*)ft_calloc(sizeof(t_struct), 1);

  a = ft_strchr(s, '%');
	*a++ = '\0';
  parseformat(a, form);  
  ft_putstr_fd(s, 1);
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

  va_start(var, str);   // инициализирует var после аргумента str
  // s = (char *)str;
  // char *par = NULL;
  // par = va_arg(var, char *); // запишет в par текущий аргумент и итерирует аргумент
  
  res = parsestr(str, var);
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

// void example_b()
// {
//   ft_printf("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
// }

// int main()
// {
//   example_b();
//   return (0);
// }