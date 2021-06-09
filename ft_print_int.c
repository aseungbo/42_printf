// 숫자 출력은 크게 3단계로 이루어져있다.

// printf("%9.5d", 123);

// 1. itoa 적용: 숫자 123 → 문자열 "123"

// 2. precision 적용: [123] → [00123] 

// precision과 len의 차이만큼 0을 패딩해서 출력한다.

// 위 숫자 전체와 width 비교: [00123] → [    00123]

// width와 (len+패딩)의 차이만큼 blank를 출력한다.

// 2와 3에서 출력한 글자 수(cnt) 리턴

// '-' 옵션 / '0' 옵션 / 출력 숫자가 음수일 때 / 특수한 예외(NULL, 0값 처리) 등의 처리를 추가해주어야 한다.

#include "ft_printf.h"

int ft_print_int(int n, t_flags flags)
{
    char *dum;
    int cnt;
	int dum_n;
    size_t len;
   
    cnt = 0;
	dum_n = n;

	if (n == 0 && flags.dot == 0)
	{
		cnt += ft_width(flags.width, flags.dot, flags.zero);
		return (cnt);
	}
	if (n < 0 && (flags.zero == 1 || flags.dot >= 0))
	{
		// prec off
		if (flags.dot == -1 && flags.zero == 1)
			ft_putchar('-');
		n *= -1;
		flags.width--;
	}
	dum = itoa(n);
	len = strlen(dum);
    // 2. prec
    if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
    // 왼쪽 정렬
    if (flags.minus == 1)
	{
		if (dum_n < 0 && flags.dot >= 0)
			ft_putchar('-');
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
    // width로 공백 출력
	if (flags.dot >= 0 && flags.zero == 1)
		cnt += ft_width(flags.width, flags.dot, 0);
	else if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, flags.zero);
    else
		cnt += ft_width(flags.width, len, flags.zero);
    if (flags.minus == 0)
	{
		if (dum_n < 0 && flags.dot >= 0)
			ft_putchar('-');
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
