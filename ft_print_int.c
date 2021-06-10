/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:05:53 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 15:12:07 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int n, t_flags flags)
{
    char *dum;
    int cnt;
	int dum_n;
    size_t len;
   
    cnt = 0;
	dum_n = n;

	// prec이 음수로 나오는 경우 해결
	if (flags.dot < 0)
		flags.dot = -1;
	if (n == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, 0, 0);
		return (cnt);
	}
	if (n < 0 && (flags.zero == 1 || flags.dot >= 0))
	{
		// prec off
		if (flags.dot == -1 && flags.zero == 1)
			cnt += pf_putchar('-');
		n *= -1;
		flags.width--;
	}
	dum = pf_itoa(n);
	len = pf_strlen(dum);
    // 2. prec
    if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
    // 왼쪽 정렬
    if (flags.minus == 1)
	{
		if (dum_n < 0 && flags.dot >= 0)
			cnt += pf_putchar('-');
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
    // width로 공백 출력
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
    else
		cnt += ft_width(flags.width, len, flags.zero);
    if (flags.minus == 0)
	{
		if (dum_n < 0 && flags.dot >= 0)
			cnt += pf_putchar('-');
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
	free(dum);
    return (cnt);
}
