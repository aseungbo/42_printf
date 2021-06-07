#include "ft_printf.h"

int ft_print_char(char c, t_flags flags)
{
	int	cnt;
	
	cnt = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	cnt = ft_width(flags.width, 1, 0);
    if (flags.minus == 0)
		ft_putchar(c);
    return (cnt);
}