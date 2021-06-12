/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 07:38:25 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:46:16 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_point_zero(t_flags flags)
{
	int		cnt;

	cnt = 0;
	if (flags.minus == 0)
	{
		cnt += ft_width(flags.width, 2, flags.zero);
		cnt += print_str_prec("0x", 2);
	}
	else
	{
		cnt += print_str_prec("0x", 2);
		cnt += ft_width(flags.width, 2, flags.zero);
	}
	return (cnt);
}

int			print_point_width(t_flags flags, size_t len)
{
	int		cnt;

	cnt = 0;
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot + 2, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot + 2, flags.zero);
	else
		cnt += ft_width(flags.width, len + 2, flags.zero);
	return (cnt);
}

int			print_point_minus(char *str, t_flags flags, size_t len)
{
	int		cnt;

	cnt = 0;
	if (flags.minus == 1)
	{
		cnt += print_str_prec("0x", 2);
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 1);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	return (cnt);
}

int			print_point_non_minus(char *str, t_flags flags, size_t len)
{
	int		cnt;

	cnt = 0;
	if (flags.minus == 0)
	{
		cnt += print_str_prec("0x", 2);
		if (flags.dot >= 0)
		{
			if ((size_t)flags.dot > len)
			{
				cnt += ft_width(flags.dot, len, 1);
				cnt += print_str_prec(str, flags.dot);
			}
			else
			{
				cnt += ft_width(flags.dot, len, flags.zero);
				cnt += print_str_prec(str, flags.dot);
			}
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	return (cnt);
}

int			ft_print_pointer(unsigned long long ull,
t_flags flags)
{
	int		cnt;
	char	*str;
	size_t	len;

	cnt = 0;
	if (ull == 0 && flags.dot == 0)
	{
		cnt = print_point_zero(flags);
		return (cnt);
	}
	if (!(str = ft_base(ull, 16)))
		return (0);
	str = pf_str_lower(str);
	len = pf_strlen(str);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	cnt += print_point_minus(str, flags, len);
	cnt += print_point_width(flags, len);
	cnt += print_point_non_minus(str, flags, len);
	free(str);
	return (cnt);
}
