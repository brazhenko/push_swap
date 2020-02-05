#include <stdlib.h>

static int	myabs(int x)
{
	return (((x) < 0) ? (-(x)) : (x));
}

int			ft_numlen(int n, int minus)
{
	int numlen;

	numlen = 1;
	while ((n /= 10))
		numlen++;
	return (numlen + minus);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = (n < 0) ? 1 : 0;
	numlen = ft_numlen(n, minus);
	if ((str = malloc(numlen + 1)))
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = myabs(digit) + '0';
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}