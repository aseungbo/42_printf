#include "ft_printf.h"

int ft_print_pointer(unsigned long long ull, t_flags flags)
{
    // 주소 앞에 0x 붙일 것
    // 진수 변환 시 대문자이므로 소문자로 변환
    int cnt;
    char *str;
    size_t len;

    cnt = 0;
    if (ull == 0 && flags.dot == 0)
	{   
        if (flags.minus == 0)
        {
            cnt += ft_width(flags.width, 2, flags.zero);
            cnt += print_str_prec("0x", 2);
        }
        else
        {
            cnt += print_str_prec("0x", 2);
		    cnt += ft_width(flags.width, 2, flags.zero);
        }
        return (cnt);
	}
    str = ft_base(ull, 16);
    str = pf_str_lower(str);
    len = pf_strlen(str);
    if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
    if (flags.minus == 1)
	{   
        cnt += print_str_prec("0x", 2);
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 1);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
    }
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot + 2, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot + 2, flags.zero);
    else
		cnt += ft_width(flags.width, len + 2, flags.zero);
    if (flags.minus == 0)
	{
        cnt += print_str_prec("0x", 2);
		if (flags.dot >= 0)
		{
			if ((size_t)flags.dot > len)
			{
				cnt += ft_width(flags.dot, len, 1);
				cnt += print_str_prec(str, flags.dot);
			}
			else
			{
                cnt += ft_width(flags.dot, len, flags.zero);
                cnt += print_str_prec(str, flags.dot);
			}
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	free(str);
    return (cnt);
}