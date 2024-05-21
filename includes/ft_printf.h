/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:45:13 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/22 02:17:09 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Common functions include write, read
# include <unistd.h>
// Provides facilities for handling functions with a variable number of arguments (varargs). Commonly used macros include va_list, va_start, va_arg, va_end, which are used for accessing variable arguments passed to functions like printf.
# include <stdarg.h>
// includes size_t type, which represents the size of objects in bytes. Also provides NULL macro, which represents a null pointer constant.
# include <stddef.h>
// Common functions include memory management functions like malloc, calloc, realloc, free and string conversion functions like atoi.
# include <stdlib.h>

// Put prototypes here 

int ft_printchar(char c);
int ft_printstr(char *str);
int ft_printnbr(int n);
int ft_printhex(unsigned int n, char format);
int ft_printf(const char *string, ...);

#endif
