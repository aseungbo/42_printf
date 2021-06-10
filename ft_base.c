#include "ft_printf.h"

char	*ft_base(unsigned long long n, int base)
{
	char    *str;
    unsigned long long dum_n;
    int     cnt;
 
    dum_n = n;
    cnt = 0;
    if (n == 0)
        return((pf_strdup("0")));
    while (n != 0)
    {
		n /= base;
		cnt++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	str[cnt] = '\0';
	while (cnt--)
	{
        if ((dum_n % base) < 10)
            str[cnt] = (dum_n % base) + 48;
        else
            str[cnt] = (dum_n % base) + 55;
        dum_n /= base;
	}
	return (str);
}