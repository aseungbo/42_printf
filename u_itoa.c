#include "ft_printf.h"

int		u_num_counter(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*u_itoa(unsigned int n)
{
	int				n_cnt;
	char			*str;

	n_cnt = u_num_counter(n);
    str = (char *)malloc(sizeof(char) * (n_cnt + 1));
	if (!str)
		return (NULL);
	str[n_cnt] = '\0';
	while (n_cnt--)
	{
		str[n_cnt] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
