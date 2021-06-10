#include "ft_printf.h"

int		ft_width(int width, int minus, int zero)
{
	int cnt;

	cnt = 0;
	while (width - minus > 0)
	{
		if (zero)
			pf_putchar('0');
		else
			pf_putchar(' ');
		width -= 1;
		cnt++;
	}
	return (cnt);
}
