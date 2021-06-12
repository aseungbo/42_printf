/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:01:42 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:14:15 by seuan            ###   ########.fr       */
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

int	print_put_str(char *str, t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.dot >= 0)
	{
		cnt += ft_width(flags.dot, len, 0);
		cnt += print_str_prec(str, flags.dot);
	}
	else
	{
		cnt += print_str_prec(str, len);
	}
	return (cnt);
}

int	ft_print_string(char *str, t_flags flags)
{
	int		cnt;
	size_t	len;

	cnt = 0;
	if (!str)
		str = "(null)";
	len = pf_strlen(str);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
		cnt += print_put_str(str, flags, len);
	if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, 0);
	else
		cnt += ft_width(flags.width, len, 0);
	if (flags.minus == 0)
		cnt += print_put_str(str, flags, len);
	return (cnt);
}
