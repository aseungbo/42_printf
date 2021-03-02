/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:26:24 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 02:13:19 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	int				idx;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	idx = 0;
	while (n--)
	{
		if (u1[idx] != u2[idx] || u1[idx] == 0 || u2[idx] == 0)
			return (u1[idx] - u2[idx]);
		idx++;
	}
	return (0);
}
