#include "ft_printf.h"

int	ft_print_u(unsigned int unsn, t_flags flags)
{
    int cnt;
    char *dum;
    size_t len;

    cnt = 0;
    dum = u_itoa(unsn);
    len = pf_strlen(dum);
    unsn = (unsigned int)(4294967296 + unsn);
    if (unsn == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, 0, 0);
		return (cnt);
	}
    if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
    if (flags.minus == 1)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 1);
			cnt += print_str_prec(dum, flags.dot);
		}
		else
		{
			cnt += print_str_prec(dum, len);
		}
    }
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
    else
		cnt += ft_width(flags.width, len, flags.zero);
    if (flags.minus == 0)
	{
		if (flags.dot >= 0)
		{
			if ((size_t)flags.dot > len)
			{
				cnt += ft_width(flags.dot, len, 1);
				cnt += print_str_prec(dum, flags.dot);
			}
			else
			{
			cnt += ft_width(flags.dot, len, flags.zero);
			cnt += print_str_prec(dum, flags.dot);
			}
		}
		else
		{
			cnt += print_str_prec(dum, len);
		}
	}
	free(dum);
    return (cnt);
}