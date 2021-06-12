/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:52:47 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:16:18 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flags_dot(va_list ap, t_flags *flags,
			const char *format, int idx)
{
	int i;

	i = idx;
	if (format[i + 1] == '*')
	{
		flags->dot = va_arg(ap, int);
		if (flags->minus == 1)
			flags->zero = 0;
		i++;
	}
	else
	{
		flags->dot = 0;
		while (pf_isdigit(format[++i]))
			flags->dot = (flags->dot * 10) + (format[i] - '0');
	}
	return (i);
}

t_flags		flags_zero(t_flags flags)
{
	flags.zero = 1;
	return (flags);
}

t_flags		flags_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		flags_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		flags_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}
