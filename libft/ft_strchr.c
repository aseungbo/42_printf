/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:51:22 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 02:13:46 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	find;
	int		idx;

	find = c;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == find)
			return ((char *)s + idx);
		idx++;
	}
	if (s[idx] == find)
		return ((char *)s + idx);
	return (0);
}
