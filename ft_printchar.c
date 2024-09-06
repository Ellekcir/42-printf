#include "./ft_printf.h"

int	ft_printchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}

// This will take a single character if the write function does not fail, it will return 1.
