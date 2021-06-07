#include "ft_printf.h"

int		ft_type_list(int c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

int		ft_flags_list(int c)
{
	if ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'))
		return (1);
	return (0);
}

int		ft_spec(int c, t_flags flags, va_list ap)
{
	int cnt;

	cnt = 0;
	if (c == 'c')
		cnt = ft_print_char(va_arg(ap, int), flags);
	// else if (c == 's')
	// 	cnt = ft_print_string(va_arg(ap, char *), flags);
	return (cnt);
}