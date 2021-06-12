/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:06 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:16:09 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_base_zero(t_flags flags)
{
	int cnt;

	cnt = 0;
	cnt += ft_width(flags.width, 0, 0);
	return (cnt);
}

int			print_base_minus(char *str, t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
	{
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

int			print_base_non_minus(char *str, t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 0)
	{
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

int			print_base_width(t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
	else
		cnt += ft_width(flags.width, len, flags.zero);
	return (cnt);
}

int			ft_print_base(unsigned int unsn, t_flags flags)
{
	int		cnt;
	char	*str;
	size_t	len;

	cnt = 0;
	if (unsn == 0 && flags.dot == 0)
	{
		cnt = print_base_zero(flags);
		return (cnt);
	}
	if (!(str = ft_base(unsn, 16)))
		return (0);
	len = pf_strlen(str);
	if (flags.type == 'x')
		str = pf_str_lower(str);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	cnt += print_base_minus(str, flags, len);
	cnt += print_base_width(flags, len);
	cnt += print_base_non_minus(str, flags, len);
	free(str);
	return (cnt);
}
