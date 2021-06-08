/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:01:42 by seuan             #+#    #+#             */
/*   Updated: 2021/06/08 12:55:06 by seuan            ###   ########.fr       */
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
// 1. 문자열의 길이 측정 strlen
// 2. dot
// 3. width

#include "ft_printf.h"

int	print_str_dot(char *str, t_flags flags)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && cnt < flags.dot)
		cnt += ft_putchar(str[cnt]);
	return (cnt);
}

int ft_print_string(char *str, t_flags flags)
{
	int cnt;
	int len;

	cnt = 0;
	len = ft_strlen(str);
	if (flags.dot > len)
	{
		printf("dot: %d \n", flags.dot);
		print_str_dot(str, flags);
	}
	if (flags.dot < len)
	{
		printf("dot: %d \n", flags.dot);
		print_str_dot(str, flags);
	}
	return (cnt);
}
