/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 07:47:29 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 14:20:25 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_num_counter(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*u_itoa(unsigned int n)
{
	int				n_cnt;
	char			*str;

	n_cnt = u_num_counter(n);
	if (!(str = (char *)malloc(sizeof(char) * (n_cnt + 1))))
		return (NULL);
	str[n_cnt] = '\0';
	while (n_cnt--)
	{
		str[n_cnt] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
