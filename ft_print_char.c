/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:00:03 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 11:42:14 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags flags)
{
	int	cnt;

	cnt = 0;
	if (flags.minus == 1)
		cnt += ft_putchar(c);
	cnt += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		cnt += ft_putchar(c);
	return (cnt);
}
