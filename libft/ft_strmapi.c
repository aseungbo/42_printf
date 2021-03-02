/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:36:57 by seuan             #+#    #+#             */
/*   Updated: 2020/12/30 18:37:17 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	str = ft_strdup((const char *)s);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		str[idx] = f((unsigned int)idx, str[idx]);
		idx++;
	}
	return (str);
}
