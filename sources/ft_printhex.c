// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

// This function will take an unsigned integer yo a hexidecimal and print it
int ft_printhex(unsigned int number, char specifier)
{
	int char_count = 0;
    char *hex_values;

// Check if the format specifier is uppercase ('X') or lowercase ('x') to determine hexadecimal characters 
// Sets hex_values to a string of only hexadecimal characters
    if (specifier == 'X')
    {
        hex_values = "0123456789ABCDEF";
    }      
    else 
    {
        hex_values = "0123456789abcdef";
    }
    // Recursive function to convert and print hexadecimal digits by going through each number, getting the remainder and dividing by 16 then prints
    // else if the number is less than 16 it will print directly
    // returns the total character count printed
	if (number >= 16)
	{
		char_count += ft_printhex(number / 16, specifier);
		char_count += ft_printchar(hex_values[number % 16]);
	}
	else
		char_count += ft_printchar(hex_values[number]);
	return (char_count);
}