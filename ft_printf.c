// Includes the header file which will have the function declarations, and gives access to various libraries
#include "./ft_printf.h"

// Handle various conversions -
// %c: Print a single character.
// %s: Print a string.
// %p: Print the void pointer argument in hexadecimal format.
// %d, %i: Print integers in base 10.
// %u: Print unsigned decimal numbers.
// %x: Print numbers in hexadecimal (lowercase) format.
// %X: Print numbers in hexadecimal (uppercase) format.
// %%: Print a percent sign.

static int	ft_check_format_specifier(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_printint(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_printunsignedint(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (specifier == 'x')
		count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'X')
		count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_printchar('%');
	else
		return (-1);
	return (count);
}

// This function will check the format specifer to determine what the return should equal whilst keeping track of the overall count of values in the string now. This is  important as the value will change the count depending on which specifer is used. The return will be the count total.

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_check_format_specifier(args, str[i]);
		}
		else
		{
			count += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// This will take a string and the 'args' given by the user. It will then check to make sure that there is a string to start off with. It will then initialise the 'args' by using va_start function, this basically gives the program ability to use the args. It will then iterate through the string by index starting at str[0],it will check if there is a % sign and if there is another character present the index following. Once will then iterate up one position check what character it is and what fromat specifier it will be to determine the function needed, and it will also add to the of the string the value of that specific return. otherwise it will continue alongg the string and the count, once this is determined it will use va_end function to end the uuse of the args and return the count. 
