// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

int ft_printstr(char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		ft_printchar(str[len]);
		len++;
	}
	return (len);
}
