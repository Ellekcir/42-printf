// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

// This function will take an unsigned integer yo a hexidecimal and print it
// Check if the format specifier is uppercase ('X') or lowercase ('x') to determine hexadecimal characters 
// Sets hex_values to a string of only hexadecimal characters
    // Recursive function to convert and print hexadecimal digits by going through each number, getting the remainder and dividing by 16 then prints
    // else if the number is less than 16 it will print directly
    // returns the total character count printed
int	ft_printhex(size_t number, char specifier)
{
	int		count;
	char	*hex_values;

	if (specifier == 'X')
		hex_values = "0123456789ABCDEF";
	else if (specifier == 'x')
		hex_values = "0123456789abcdef";
	else
		return (0);
	count = 0;
	if (number >= 16)
	{
		count += ft_printhex(number / 16, specifier);
		count += ft_printchar(hex_values[number % 16]);
	}
	else
		count += ft_printchar(hex_values[number]);
	return (count);
}
