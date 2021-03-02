/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:31:56 by seuan             #+#    #+#             */
/*   Updated: 2020/12/29 00:32:15 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	int		s1_len;
	int		s2_len;
	char	*res;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (!res)
			return (NULL);
		idx = -1;
		while (s1[++idx])
			res[idx] = s1[idx];
		idx = -1;
		while (s2[++idx])
		{
			res[s1_len] = s2[idx];
			s1_len++;
		}
		res[s1_len] = '\0';
		return (res);
	}
	return (NULL);
}
