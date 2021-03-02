/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 02:24:23 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 02:48:33 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		s_len;
	int		idx;
	char	*p;

	s_len = ft_strlen(s);
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
