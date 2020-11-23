/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:03:41 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/23 18:32:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  

int		ft_printf(char *apFormat, ...)
{
	va_list ap;             /* point on next unnamed argument */

	va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
	for (char *p = apFormat; *p; p++)
	{
	if (*p !='%')
	{
		putchar(*p);
		continue;
	}
	switch(* (++p))
	{
      case 'd':
      {
        int ival = 0;
        ival = va_arg(ap, int);
        printf ("%d", ival);
        break;
      }
      case 'f':
      {
        double  dval = 0.;
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      }
      case 's':
      {
        for(char *sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      }
      default:
      {
        putchar(*p);
        break;
      }
    }
  }
  va_end(ap); /* clean all */
  return (0);
}

void example_b()
{
  ft_printf("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
}

