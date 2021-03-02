/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:01:45 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 16:05:17 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*ptr;

	find = c;
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == find)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
