/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:53:29 by seuan             #+#    #+#             */
/*   Updated: 2020/12/27 22:53:39 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return ;
	while (s[idx])
	{
		ft_putchar_fd(s[idx], fd);
		idx++;
	}
}
