/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:05:40 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 17:51:36 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const	void *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	int				idx;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	idx = 0;
	while (n--)
	{
		if (u1[idx] != u2[idx])
			return (u1[idx] - u2[idx]);
		idx++;
	}
	return (0);
}
