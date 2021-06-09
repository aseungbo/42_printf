/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:19:03 by seuan             #+#    #+#             */
/*   Updated: 2021/06/09 21:39:38 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_spec(int c, t_flags flags, va_list ap)
{
	int cnt;

	cnt = 0;
	if (c == 'c')
		cnt = ft_print_char(va_arg(ap, int), flags);
	else if (c == '%')
		cnt = ft_print_char('%', flags);
	else if (c == 's')
		cnt = ft_print_string(va_arg(ap, char *), flags);
	else if (c == 'd' || c == 'i')
		cnt = ft_print_int(va_arg(ap, int), flags);
	// else if (c == 'x' || c == 'X' || c == 'u')
	// 	cnt = ft_print_something(va_arg(ap, unsigned int), info);
	// else if (type == 'p')
	// 	cnt = ft_print_pointer(va_arg(ap, unsigned long long), info);
	return (cnt);
}
