/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:48 by seuan             #+#    #+#             */
/*   Updated: 2021/06/08 07:36:40 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_flags
{
	int minus;
	int zero;
	int width;
	int prec;
	int type;
	int star;
} t_flags;

int ft_putchar(char c);
int ft_printf(const char *args, ...);
int	ft_print_char(char c, t_flags flags);
int	ft_print_string(char *str, t_flags flag);
int	ft_spec(int c, t_flags flags, va_list ap);
int	ft_type_list(int c);
int	ft_flags_list(int c);
int	ft_width(int width, int minus, int zero);
int	ft_isdigit(int c);
#endif