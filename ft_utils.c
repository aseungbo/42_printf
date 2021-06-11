/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:31:22 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 07:44:31 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	pf_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*pf_strdup(const char *s)
{
	int		s_len;
	int		idx;
	char	*p;

	s_len = pf_strlen(s);
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!p)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		p[idx] = s[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}

int		pf_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
