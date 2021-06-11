/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 07:46:51 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 07:47:10 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(int width, int minus, int zero)
{
	int cnt;

	cnt = 0;
	while (width - minus > 0)
	{
		if (zero)
			pf_putchar('0');
		else
			pf_putchar(' ');
		width -= 1;
		cnt++;
	}
	return (cnt);
}
