/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:19:03 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 17:29:02 by seuan            ###   ########.fr       */
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
		cnt = ft_print_percent('%', flags);
	else if (c == 's')
		cnt = ft_print_string(va_arg(ap, char *), flags);
	else if (c == 'd' || c == 'i')
		cnt = ft_print_int(va_arg(ap, int), flags);
	else if (c == 'u')
		cnt = ft_print_u(va_arg(ap, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		cnt = ft_print_base(va_arg(ap, unsigned int), flags);
	else if (c == 'p')
		cnt = ft_print_pointer(va_arg(ap, unsigned long long), flags);
	return (cnt);
}
