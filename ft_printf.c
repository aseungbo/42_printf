/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:13:45 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
	flags->type = 0;
	flags->star = 0;
}

int				ft_flag_parse(const char *format, int i,
								t_flags *flags, va_list ap)
{
	while (format[i])
	{
		if (!pf_isdigit(format[i]) && !ft_type_list(format[i])
		&& !ft_flags_list(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			*flags = flags_zero(*flags);
		if (format[i] == '-')
			*flags = flags_minus(*flags);
		if (format[i] == '*')
			*flags = flags_width(ap, *flags);
		if (format[i] == '.')
			i = flags_dot(ap, flags, format, i);
		if (pf_isdigit(format[i]))
			*flags = flags_digit(format[i], *flags);
		if (ft_type_list(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				process(const char *format, va_list ap)
{
	int			cnt;
	int			i;
	t_flags		flags;

	cnt = 0;
	i = 0;
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
			cnt += pf_putchar(format[i]);
		i++;
	}
	return (cnt);
}

int				ft_printf(const char *input, ...)
{
	int			cnt;
	const char	*format;
	va_list		ap;

	cnt = 0;
	if (!(format = pf_strdup(input)))
		return (0);
	va_start(ap, input);
	cnt += process(format, ap);
	free((char *)format);
	va_end(ap);
	return (cnt);
}
