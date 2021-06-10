/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:01:42 by seuan             #+#    #+#             */
/*   Updated: 2021/06/10 15:09:46 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Type s 구현 전 로직에 대해 고민하기
// flag
// - : 왼쪽 정렬하기
// 0 : 너비 옵션에 맞춰 빈자리에 0 추가. -옵션이 우선순위

// width
// 너비 설정 값 <  주어진 값의 길이 width를 무시하고 주어진 값 모두 출력
// 너비 설정 값 >= 주어진 값의 길이 len 출력 후 남는 공간 공백으로 채웁니다. - 옵션이 있으면 왼쪽정렬, 없으면 오른쪽 정렬)

// 숫자 n 혹은 *로 세팅

// .dotision
// dot < 주어진 값의 길이 dot만큼 자른 후 출력
// dot >= 주어진 값의 길이 
// 1. 문자열의 길이 측정 pf_strlen
// 2. dot
// 3. width

#include "ft_printf.h"

size_t	pf_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	print_str_prec(char *str, int prec)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && cnt < prec)
		cnt += pf_putchar(str[cnt]);
	return (cnt);
}

int	ft_print_string(char *str, t_flags flags)
{
	int cnt;
	size_t len;

	cnt = 0;
	len = pf_strlen(str);
	if (!str)
		str = "(null)";
	len = pf_strlen(str);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 0);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	if (flags.dot >= 0)
		cnt += ft_width(flags.width, flags.dot, 0);
	else
		cnt += ft_width(flags.width, len, 0);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
		{
			cnt += ft_width(flags.dot, len, 0);
			cnt += print_str_prec(str, flags.dot);
		}
		else
		{
			cnt += print_str_prec(str, len);
		}
	}
	return (cnt);
}
