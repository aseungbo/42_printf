/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:01:42 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 16:39:23 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_prec(char *str, int prec)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && cnt < prec)
		cnt += pf_putchar(str[cnt]);
	return (cnt);
}

int	ft_print_string(char *str, t_flags flags)
{
	int cnt;
	size_t len;

	cnt = 0;
	len = pf_strlen(str);
	if (!str)
		str = "(null)";
	len = pf_strlen(str);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 0);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, 0);
	else
		cnt += ft_width(flags.width, len, 0);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 0);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	return (cnt);
}
