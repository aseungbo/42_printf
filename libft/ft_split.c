/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:25:28 by seuan             #+#    #+#             */
/*   Updated: 2020/12/30 22:30:07 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**ft_malloc_free(char **res)
{
	unsigned int	idx;

	idx = 0;
	while (res[idx])
	{
		free(res[idx]);
		idx++;
	}
	free(res);
	return (NULL);
}

static unsigned int		ft_get_len(char const *s, char c)
{
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = 0;
	if (!s)
		return (0);
	if (!s[idx])
		return (0);
	if (s[idx] != c)
	{
		idx++;
		len++;
	}
	while (s[idx])
	{
		if ((s[idx] != c && s[idx - 1] == c))
			len++;
		idx++;
	}
	return (len);
}

char					**ft_split(char const *s, char c)
{
	char				**res;
	char				*curr_str;
	unsigned int		curr_str_len;
	unsigned int		idx;
	const unsigned int	get_len = ft_get_len(s, c);

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (get_len + 1))))
		return (NULL);
	idx = 0;
	while (idx < get_len)
	{
		while (*s == c)
			s++;
		curr_str = (char *)s;
		curr_str_len = 0;
		while (*s && *s++ != c)
			curr_str_len++;
		if (!(res[idx] = (char *)malloc(sizeof(char) * (curr_str_len + 1))))
			return (ft_malloc_free(res));
		ft_strlcpy(res[idx++], curr_str, curr_str_len + 1);
	}
	res[idx] = NULL;
	return (res);
}
