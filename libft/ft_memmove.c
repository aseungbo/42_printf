/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:36:11 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 16:00:36 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_d;
	unsigned char	*new_s;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		new_d = (unsigned char *)dest;
		new_s = (unsigned char *)src;
		while (n--)
			*new_d++ = *new_s++;
	}
	else
	{
		new_d = (unsigned char *)dest + (n - 1);
		new_s = (unsigned char *)src + (n - 1);
		while (n--)
			*new_d-- = *new_s--;
	}
	return (dest);
}
