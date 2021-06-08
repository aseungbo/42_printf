/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/08 17:44:10 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
	flags->type = 0;
	flags->star = 0;
}

int	ft_flag_parse(const char *format, int i, t_flags *flags, va_list ap)
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
		if (format[i] == '.')
		{
			if (format[i + 1] == '*')
				flags->dot = va_arg(ap, int);
			else
			{
				flags->dot = 0;
				while (ft_isdigit(format[++i]))
				{
					flags->dot = (flags->dot * 10) + (format[i] - '0');
				}
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

int	ft_printf(const char *format, ...)
{
	int		i;
	int		cnt;
	va_list	ap;
	t_flags	flags;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			init_flags(&flags);
			i = ft_flag_parse(format, ++i, &flags, ap);
			if (ft_type_list(format[i]))
				cnt += ft_spec((char)flags.type, flags, ap);
			i++;
		}
		else if (format[i] != '%')
			cnt += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}

// test
// int	main()
// {
// 	char c = 'a';

// 	printf("------------printf------------------\n");
// 	printf("-->|%-4.c|<--\n", c);
// 	printf("-->|%-4c|<--\n", c);
// 	printf("-->|%-3.c|<--\n", c);
// 	printf("-->|%-3c|<--\n", c);
// 	printf("-->|%-2.c|<--\n", c);
// 	printf("-->|%-2c|<--\n", c);
// 	printf("-->|%-3.c|<--\n", c);
// 	printf("-->|%-3c|<--\n", c);
// 	printf("-->|%-4.c|<--\n", c);
// 	printf("-->|%-4c|<--\n", c);
// 	printf("------------ft_printf------------------\n");
// 	ft_printf("-->|%-4.c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-4c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-3.c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-3c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-2.c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-2c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-3.c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-3c|<--", c);
// 	printf("\n");
// 	ft_printf("-->|%-4.c|<--\n", c);
// 	printf("\n");
// 	ft_printf("-->|%-4c|<--\n", c);
// 	printf("\n");
// }
