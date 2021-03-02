/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:20:00 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 02:12:59 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	find;
	int		idx;
	int		s_len;

	s_len = ft_strlen(s);
	find = c;
	idx = s_len - 1;
	if (s[idx + 1] == find)
		return ((char *)s + idx + 1);
	while (s_len--)
	{
		if (s[idx] == find)
			return ((char *)s + idx);
		idx--;
	}
	return (0);
}
