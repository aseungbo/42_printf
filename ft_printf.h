/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:07:48 by seuan             #+#    #+#             */
/*   Updated: 2021/06/11 14:24:19 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				dot;
	int				type;
	int				star;
}					t_flags;

int					pf_putchar(char c);
int					ft_printf(const char *args, ...);
int					ft_print_char(char c, t_flags flags);
int					ft_print_string(char *str, t_flags flag);
int					ft_print_int(int n, t_flags flags);
int					ft_print_u(unsigned int unsn, t_flags flags);
int					ft_print_base(unsigned int unsn, t_flags flags);
int					ft_print_pointer(unsigned long long ull, t_flags flags);
int					ft_print_percent(char c, t_flags flags);
int					print_str_prec(char *str, int prec);
int					ft_spec(int c, t_flags flags, va_list ap);
int					ft_type_list(int c);
int					ft_flags_list(int c);
int					ft_width(int width, int minus, int zero);
int					pf_isdigit(int c);
int					flags_dot(va_list ap, t_flags *flags,
						const char *format, int i);
int					pf_tolower(int c);

char				*pf_itoa(int n);
char				*u_itoa(unsigned int n);
char				*ft_base(unsigned long long n, int base);
char				*pf_strdup(const char *s);
char				*pf_str_lower(char *str);

size_t				pf_strlen(const char *s);

t_flags				flags_zero(t_flags flags);
t_flags				flags_minus(t_flags flags);
t_flags				flags_width(va_list ap, t_flags flags);
t_flags				flags_digit(char c, t_flags flags);

#endif
