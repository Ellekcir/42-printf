/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:12:25 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/22 02:15:28 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Include the header file which will have the function declarations and gives access to varous libraries
#include "../includes/ft_printf.h"

// Handle various conversions -
// %c: Print a single character.
// %s: Print a string according to the common C convention.
// %p: Print the void pointer argument in hexadecimal format.
// %d, %i: Print integers in base 10.
// %u: Print unsigned decimal numbers.
// %x: Print numbers in hexadecimal (lowercase) format.
// %X: Print numbers in hexadecimal (uppercase) format.
// %%: Print a percent sign.

static int ft_check_format_specifier(va_list args, char specifier)
{
	int char_count;

	char_count = 0;
	if (specifier == 'c')
		char_count += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		char_count += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		char_count += ft_printnbr(va_arg(args, int));
	else if (specifier == 'u')
		char_count += ft_printnbr(va_arg(args, unsigned int));
	else if (specifier == 'p')
		char_count += ft_printhex(va_arg(args, unsigned int), 'x');
	else if (specifier == 'x')
		char_count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'X')
		char_count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		char_count += ft_printchar('%');
	return (char_count);
}

int ft_printf(const char *str, ...)
{
	int i;
	int char_count;
	va_list args;

	i = 0;
	char_count = 0;
	if (str == 0)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			//function to check if it is any of the format specifers
			char_count += ft_check_format_specifier(args, str[i]);
		}
		else
		{
			char_count += ft_printchar(str[i]);
			//prints the character and add to the overall character count
		}
		i++;
	}
	va_end(args);
	return (char_count);
}
