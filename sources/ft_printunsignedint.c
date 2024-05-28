#include "../includes/ft_printf.h"

int	ft_printunsignedint(unsigned int number)
{
	int	count;

	count = 0;
	if (number >= 10)
	{
		count += ft_printunsignedint(number / 10);
		count += ft_printchar((number % 10) + '0');
	}
	else
		count += ft_printchar(number + '0');
	return (count);
}
