/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:45:13 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/21 19:05:32 by rgriffit         ###   ########.fr       */
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
// void	ft_string(char *arggs, int *length);
// int		ft_printf(const char *string, ...)

#endif
