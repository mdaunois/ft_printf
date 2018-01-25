/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:38 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 17:41:25 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_param(char str, va_list arg, ...)
{
	if (str == 'c')
		return (conv_char(arg));
	if (str == 's')
		return (ft_strdup(va_arg(arg, char *)));
	if (str == 'd' || str == 'i')
		return (ft_itoa(va_arg(arg, int)));
	if (str == 'u')
		return ((ft_itoa_long(va_arg(arg, unsigned int))));
	if (str == 'U')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (str == 'o')
		return (ft_itoabase(va_arg(arg, unsigned int), 8));
	if (str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long), 8));
	if (str == 'x')
		return (ft_itoabase(va_arg(arg, unsigned int), 16));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == 'X')
		return (mag(ft_itoabase(va_arg(arg, unsigned int), 16)));
	if (str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	return (0);
}

char	*type_param_long(char type, va_list arg, ...)
{
	if (type == 'd' || type == 'i' || type == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (type == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long), 16));
	if (type == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, unsigned long), 16)));
	if (type == 'o')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long), 8));
	if (type == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long), 8));
	if (type == 'u')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (type == 'U')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (type == 'p')
		return (conv_adresse(arg));
	if (type == 's')
		return (convparaminbig_s(0, arg));
	if (type == 'c')
		return (convparaminbig_c(arg));
	return (0);
}

char	*type_param_long_long(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, long long), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, long long), 16)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, long long), 8));
	if (str == 'u' || str == 'U')
		return (ft_itoa_uim(va_arg(arg, unsigned long long)));
	return (0);
}

char	*type_param_short(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i')
		return ((ft_itoa((short)va_arg(arg, int))));
	if (str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (str == 'u')
		return (ft_itoa_long((unsigned short)va_arg(arg, int)));
	if (str == 'U')
		return (ft_itoa_long(va_arg(arg, long)));
	if (str == 'o')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 8));
	if (str == 'O')
		return (ft_itoabase(va_arg(arg, unsigned int), 8));
	if (str == 'x')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 16));
	if (str == 'X')
		return (mag(ft_itoabase((unsigned short)va_arg(arg, int), 16)));
	return (0);
}

char	*type_param_char(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i')
		return (ft_itoa((signed char)va_arg(arg, int)));
	if (str == 'D')
		return (ft_itoa(va_arg(arg, int)));
	if (str == 'u')
		return (ft_itoa_long((unsigned char)va_arg(arg, int)));
	if (str == 'U')
		return (ft_itoa_long(va_arg(arg, long)));
	if (str == 'o')
		return (ft_itoabase((unsigned char)va_arg(arg, int), 8));
	if (str == 'O')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 8));
	if (str == 'x')
		return (ft_itoabase((unsigned char)va_arg(arg, int), 16));
	if (str == 'X')
		return (mag(ft_itoabase((unsigned char)va_arg(arg, int), 16)));
	return (0);
}
