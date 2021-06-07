/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/08 07:49:30 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->type = 0;
	flags->star = 0;
}

int				ft_flag_parse(const char *format, int i, t_flags *flags, va_list ap)
{
	while (format[i])
	{
		if (format[i] == '-')
			flags->minus = 1;
		if (format[i] == '*')
		{
			flags->star = 1;
			flags->width = va_arg(ap, int);
			if (flags->width < 0)
			{
				flags->minus = 1;
				flags->width *= -1;
			}
		}
		if (ft_isdigit(format[i]))
		{
			if (flags->star == 1)
				flags->width = 0;
			flags->width = (flags->width * 10) + (format[i] - '0');
		}
		if (ft_type_list(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
    int		i;
	int		cnt;
    va_list	ap;
	t_flags	flags;

    i = 0;
	cnt = 0;
	init_flags(&flags);
    va_start(ap, format);
    while (format[i] != '0')
    {
		// 서식 지정자 출력
		if (format[i] == '%' && format[i + 1])
		{	
			i = ft_flag_parse(format, ++i, &flags, ap);
			if (ft_type_list(format[i]))
				cnt += ft_spec((char)flags.type, flags, ap);
			else if (format[i])
				cnt += ft_putchar(format[i]);
			i++;
		}

		// 문자열 출력
		if (format[i] != '%')
			cnt += ft_putchar(format[i]);
		i++;
    }
    va_end(ap);
	return (cnt);
}

//  test
int			main()
{
	printf("----------- TEST -----------\n");
	printf("printf: \n");
	printf("abbcade");
	printf("\n");
	printf("ft_printf: \n");
	ft_printf("abcdefef");
	printf("\n");
	printf("-----------------------------\n");
}
