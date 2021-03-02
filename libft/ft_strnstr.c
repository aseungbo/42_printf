/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:22:03 by seuan             #+#    #+#             */
/*   Updated: 2021/03/02 17:34:57 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	while (*big && l_len <= len--)
	{
		if (!ft_strncmp(big, little, l_len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
