/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:22:24 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 07:41:12 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(char c, t_flags flags)
{
	int	cnt;

	cnt = 0;
	if (flags.minus == 1)
		cnt += pf_putchar(c);
	cnt += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		cnt += pf_putchar(c);
	return (cnt);
}
