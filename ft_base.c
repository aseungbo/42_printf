/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:15 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 11:23:26 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

char	*pf_str_lower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = pf_tolower(str[i]);
	return (str);
}

char	*ft_base(unsigned long long n, int base)
{
	char				*str;
	unsigned long long	dum_n;
	int					cnt;

	dum_n = n;
	cnt = 0;
	if (n == 0)
		return ((pf_strdup("0")));
	while (n != 0)
	{
		n /= base;
		cnt++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	str[cnt] = '\0';
	while (cnt--)
	{
		if ((dum_n % base) < 10)
			str[cnt] = (dum_n % base) + 48;
		else
			str[cnt] = (dum_n % base) + 55;
		dum_n /= base;
	}
	return (str);
}
