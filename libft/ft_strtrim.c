/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:41:41 by seuan             #+#    #+#             */
/*   Updated: 2020/12/30 00:41:53 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	len;
	char			*start;
	char			*end;
	char			*new;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	len = ft_strlen(s1);
	end = (char *)s1 + len;
	i = 0;
	while (*start && ft_strchr(set, *start))
	{
		start++;
		len--;
	}
	while (len >= 0 && *start && ft_strchr(set, *--end))
		len--;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		new[i++] = *start++;
	new[i] = '\0';
	return (new);
}
