
// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

int ft_printnbr(int n)
{
	unsigned int num;
	int char_count = 0;

	if (n < 0)
	{
		ft_printchar('-');
		num = -n;
		char_count++;
	}
	else
		num = n;
	if (num >= 10)
	{
		char_count += ft_printnbr(num / 10);
		char_count += ft_printchar(num % 10 + '0');
	}
	else
		char_count += ft_printchar(num + '0');
	return (char_count);
}