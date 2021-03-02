/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:13:26 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 15:35:14 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		find;

	d = dest;
	s = src;
	find = c;
	while (n--)
	{
		*d = *s;
		if (*s == find)
			return (d + 1);
		d++;
		s++;
	}
	return (NULL);
}
