/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 07:45:15 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 15:45:39 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u_minus(char *dum, t_flags flags, size_t len)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 1);
			cnt += print_str_prec(dum, flags.dot);
		}
		else
		{
			cnt += print_str_prec(dum, len);
		}
	}
	return (cnt);
}

int			print_u_non_minus(char *dum, t_flags flags, size_t len)
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
	}
	return (cnt);
}

int			print_u_width(t_flags flags, size_t len)
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

int			ft_print_u(unsigned int unsn, t_flags flags)
{
	int		cnt;
	char	*dum;
	size_t	len;

	cnt = 0;
	if (!(dum = u_itoa(unsn)))
		return (0);
	len = pf_strlen(dum);
	unsn = (unsigned int)(4294967296 + unsn);
	if (unsn == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, 0, 0);
		return (cnt);
	}
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	cnt += print_u_minus(dum, flags, len);
	cnt += print_u_width(flags, len);
	cnt += print_u_non_minus(dum, flags, len);
	free(dum);
	return (cnt);
}
