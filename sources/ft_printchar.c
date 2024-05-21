// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}
