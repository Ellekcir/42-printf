#include "./ft_printf.h"

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
	{
		count += ft_printstr("(null)");
		return (count);
	}
	while (str[count] != '\0')
	{
		ft_printchar(str[count]);
		count++;
	}
	return (count);
}
