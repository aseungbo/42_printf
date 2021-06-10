/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:06 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 15:06:08 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

char *pf_str_lower(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        str[i] = pf_tolower(str[i]);
    return(str);
}

int	ft_print_base(unsigned int unsn, t_flags flags)
{
    int cnt;
    char *str;
    size_t len;

    cnt = 0;
    unsn = (unsigned int)(4294967296 + unsn);
    if (unsn == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, 0, 0);
		return (cnt);
	}
    str = ft_base(unsn, 16);
    len = pf_strlen(str);
    if (flags.type == 'x')
        str = pf_str_lower(str);
    if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
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
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
    else
		cnt += ft_width(flags.width, len, flags.zero);
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
	free(str);
    return (cnt);
}