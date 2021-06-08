/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/08 17:09:30 by seuan            ###   ########.fr       */
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
int	main()
{
	char *s = "42seoul";

	printf("--------------- printf TEST -----------------\n");
	printf("Case 1: len > width, no dot: 가변인자 모두 출력 \n");
	printf("%3s", s);
	printf("\n");
	printf("Case 2: len < width, no dot: len 출력 후 남는 공간 공백 \n");
	printf("%10s", s); // - 옵션은 c에서 구현했으니 s에서도 동일하다.
	printf("\n");
	printf("Case 3: len > dot, no width: dot만큼 자른 disp를 출력\n");
	printf("%.4s", s);
	printf("\n");
	printf("Case 4: len > dot, width < disp_len: case1과 같이 width가 무시 \n");
	printf("%3.4s", s);
	printf("\n");
	printf("Case 5: len > dot, width > disp_len 2만큼의 공백 \n");
	printf("%7.4s", s);
	printf("\n");
	printf("Case 6: len < dot, no width dot이 없는 것 처럼 생각\n");
	printf("%.9s", s);
	printf("\n");
	printf("Case 7: len < dot, width < len no dot, no width\n");
	printf("%7.9s", s);
	printf("\n");
	printf("Case 8:  len < dot, width > len 3만큼의 공백 \n");
	printf("%10.9s", s);
	printf("\n");
	printf("Case 9:  *\n");
	printf("%*s", 5, s);
	printf("\n");
	printf("Case 10:  *\n");
	printf("%*s", 10, s);
	printf("\n");

	printf("------------- ft_ printf TEST ---------------\n");
	printf("Case 1: len > width, no dot: 가변인자 모두 출력 \n");
	ft_printf("%3s", s);
	printf("\n");
	printf("Case 2: len < width, no dot: len 출력 후 남는 공간 공백 \n");
	ft_printf("%10s", s); // - 옵션은 c에서 구현했으니 s에서도 동일하다.
	printf("\n");
	printf("Case 3: len > dot, no width: dot만큼 자른 disp를 출력\n");
	ft_printf("%.4s", s);
	printf("\n");
	printf("Case 4: len > dot, width < disp_len: case1과 같이 width가 무시 \n");
	ft_printf("%3.4s", s);
	printf("\n");
	printf("Case 5: len > dot, width > disp_len 2만큼의 공백 \n");
	ft_printf("%7.4s", s);
	printf("\n");
	printf("Case 6: len < dot, no width dot이 없는 것 처럼 생각\n");
	ft_printf("%.9s", s);
	printf("\n");
	printf("Case 7: len < dot, width < len no dot, no width\n");
	ft_printf("%7.9s", s);
	printf("\n");
	printf("Case 8:  len < dot, width > len 3만큼의 공백 \n");
	ft_printf("%10.9s", s);
	printf("\n");
	printf("Case 9:  *\n");
	ft_printf("%*s", 5, s);
	printf("\n");
	printf("Case 10:  *\n");
	ft_printf("%*s", 10, s);
	printf("\n");
}
