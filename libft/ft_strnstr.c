/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:22:03 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 02:06:07 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;

	l_len = ft_strlen(little);
	if (*big == '\0')
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (len-- >= l_len && *big != '\0')
	{
		if (*big == *little && ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
