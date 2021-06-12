/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 07:49:31 by seuan             #+#    #+#             */
/*   Updated: 2021/06/12 18:33:06 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_counter(int n)
{
	int	cnt;

	cnt = 1;
	if (-2147483648 < n && n < 0)
		n *= -1;
	else if (n == -2147483648)
	{
		cnt++;
		n = 147483648;
	}
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*positive_num(int n, int n_cnt)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n_cnt + 1));
	if (!str)
		return (NULL);
	str[n_cnt] = '\0';
	while (n_cnt--)
	{
		str[n_cnt] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*pf_itoa(int n)
{
	int				n_cnt;
	unsigned int	num;
	char			*str;

	n_cnt = num_counter(n);
	if (n < 0)
	{
		str = (char *)malloc(sizeof(char) * (n_cnt + 2));
		if (!str)
			return (NULL);
		num = n * -1;
		str[n_cnt + 1] = '\0';
		while (n_cnt)
		{
			str[n_cnt] = (num % 10) + '0';
			num /= 10;
			n_cnt--;
		}
		str[0] = '-';
		return (str);
	}
	return (positive_num(n, n_cnt));
}
