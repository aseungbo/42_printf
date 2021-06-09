/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/09 17:56:45 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*strdup(const char *s)
{
	int		s_len;
	int		idx;
	char	*p;

	s_len = strlen(s);
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!p)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		p[idx] = s[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}

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
		if (!ft_isdigit(format[i]) && !ft_type_list(format[i])
		&& !ft_flags_list(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
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
			{
				flags->dot = va_arg(ap, int);
				i++;
			}
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

int	ft_printf(const char *input, ...)
{
	int		i;
	int		cnt;
	const char	*format;
	va_list	ap;
	t_flags	flags;

	i = 0;
	cnt = 0;
	format = strdup(input);
	va_start(ap, input);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			init_flags(&flags);
			i = ft_flag_parse(format, ++i, &flags, ap);
			if (ft_type_list(format[i]))
				cnt += ft_spec((char)flags.type, flags, ap);
		}
		else if (format[i] != '%')
			cnt += ft_putchar(format[i]);
		i++;
	}
	free((char *)format);
	va_end(ap);
	return (cnt);
}

// test
// int	main()
// {
// 	printf("------------------\n");
// 	printf("%08.5d\n", 34);
// 	ft_printf("%08.5d\n", 34);
// 	printf("\n");
// 	printf("%05d\n", 43);
// 	ft_printf("%05d", 43);
// 	printf("\n");
// }
