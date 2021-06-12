/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:05:53 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:15:43 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_int_width(t_flags flags, size_t len)
{
	int		cnt;

	cnt = 0;
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
	else
		cnt += ft_width(flags.width, len, flags.zero);
	return (cnt);
}

int			print_int_minus(char *dum, t_flags flags, size_t len)
{
	int		cnt;

	cnt = 0;
	if (flags.dot >= 0)
	{
		cnt += ft_width(flags.dot, len, 1);
		cnt += print_str_prec(dum, flags.dot);
	}
	else
	{
		cnt += print_str_prec(dum, len);
	}
	return (cnt);
}

int			print_int_non_minus(char *dum, t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.dot >= 0)
	{
		if ((size_t)flags.dot > len)
		{
			cnt += ft_width(flags.dot, len, 1);
			cnt += print_str_prec(dum, flags.dot);
		}
		else
		{
			cnt += ft_width(flags.dot, len, flags.zero);
			cnt += print_str_prec(dum, flags.dot);
		}
	}
	else
	{
		cnt += print_str_prec(dum, len);
	}
	return (cnt);
}

int			print_int_itoa(char *dum, t_flags flags, int dum_n, int n)
{
	int		cnt;

	cnt = 0;
	if (flags.dot >= 0 && (size_t)flags.dot < pf_strlen(dum))
		flags.dot = pf_strlen(dum);
	if (flags.minus == 1)
	{
		if (dum_n < 0 && flags.dot >= 0 && n != -2147483648)
			cnt += pf_putchar('-');
		cnt += print_int_minus(dum, flags, pf_strlen(dum));
	}
	cnt += print_int_width(flags, pf_strlen(dum));
	if (flags.minus == 0)
	{
		if (dum_n < 0 && flags.dot >= 0 && n != -2147483648)
			cnt += pf_putchar('-');
		cnt += print_int_non_minus(dum, flags, pf_strlen(dum));
	}
	return (cnt);
}

int			ft_print_int(int n, t_flags flags)
{
	char	*dum;
	int		cnt;
	int		dum_n;

	cnt = 0;
	dum_n = n;
	if (flags.dot < 0)
		flags.dot = -1;
	if (n == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, 0, 0);
		return (cnt);
	}
	if (n < 0 && (flags.zero == 1 || flags.dot >= 0))
	{
		if (flags.dot == -1 && flags.zero == 1 && n != -2147483648)
			cnt += pf_putchar('-');
		n *= -1;
		flags.width--;
	}
	if (!(dum = pf_itoa(n)))
		return (0);
	cnt += print_int_itoa(dum, flags, dum_n, n);
	free(dum);
	return (cnt);
}
