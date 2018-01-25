/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_val_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:56 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 12:04:21 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_param_intmax(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, intmax_t)));
	if (str == 'u' || str == 'U')
		return (ft_itoa_uim(va_arg(arg, uintmax_t)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, uintmax_t), 8));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, uintmax_t), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, uintmax_t), 16)));
	return (0);
}

char	*type_param_size_t(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, size_t)));
	if (str == 'u' || str == 'U')
		return (ft_itoa_uim(va_arg(arg, size_t)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, size_t), 8));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, size_t), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, size_t), 16)));
	return (0);
}
