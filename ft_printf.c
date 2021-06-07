/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/07 17:09:45 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void			init_flags(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->type = 0;
}

void			set_flags(char format, t_flag flags)
{
	if (format == '-')
		flags->minus = 1;
	else if (format == '0')
		flags->zero = 1;

	else if ()
}

int				print_char(char c, t_flag flags)
{
	int	cnt;
	
	cnt = 0;
	if (flags.minus == 0)
		ft_putchar(c);
	return (cnt);
}

// int				print_string(char *str, t_flag flag)
// {
// 	int	cnt;

// 	cnt = 0;
// 	while()
// 	return (cnt);
// }

int				ft_printf(const char *format, ...)
{
    int		i;
	int		cnt;~
    va_list	ap;
	t_flag	flags;

    i = 0;
	cnt = 0;
	init_flags(&flags);
    va_start(ap, format);
    while (format[i] != '\0')
    {
		if (format[i] == '%' && format[i + 1])
		{	
			// flags 검사 함수 필요.
			// flags type도 구분할 함수 구현. 
			if (format[i + 1] == 'c')
				cnt = print_char(va_arg(ap, int), flags);
			// else if (format[i + 1] == 's')
			// 	cnt = print_string(va_arg(ap, char *), flags);
		}
		else if (format[i] != '%')
			cnt += ft_putchar(format[i]);
		i++;
    }
    va_end(ap);
	return (cnt);
}

// test
// int			main()
// {
// 	printf("----------- BASIC -----------\n");
// 	printf("printf: \n");
// 	printf("%c", 'a');
// 	printf("\n");
// 	printf("a");
// 	printf("\n");
// 	printf("\n");
// 	printf("ft_printf: \n");
// 	ft_printf("%c", 'a');
// 	printf("\n");
// 	ft_printf("a");
// 	printf("\n");
// 	printf("-----------------------------\n");

// 	printf("------- width ---------------\n");
// 	printf("printf: \n");
// 	printf("%2c", 'a');
// 	printf("\n");
// 	printf("%-2c", 'a');
// 	printf("\n");
// 	printf("\n");
// 	printf("ft_printf: \n");
// 	ft_printf("%2c", 'a');
// 	printf("\n");
// 	ft_printf("%-2c", 'a');
// 	printf("\n");
// 	printf("-----------------------------\n");

// 	printf("------------ minus ----------\n");
// 	printf("printf: \n");
// 	printf("%*c", -2, 'a');
// 	printf("\n");
// 	printf("%-*c", -2, 'a');
// 	printf("\n");
// 	printf("\n");
// 	printf("ft_printf: \n");
// 	ft_printf("%*c", -2, 'a');
// 	printf("\n");
// 	ft_printf("%-*c", -2, 'a');
// 	printf("\n");
// 	printf("-----------------------------\n");
// }
