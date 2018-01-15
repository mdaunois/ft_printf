/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:14:59 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 15:10:25 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convparaminbig_c(va_list arg, ...)
{
	wchar_t	val;

	val = va_arg(arg, wchar_t);
	return (flagbig_c(val));
}

char	*convparaminbig_s(va_list arg, ...)
{
	wchar_t	*val;
	int		i;
	char	*temp;

	temp = ft_strnew(1000);
	i = 0;
	val = va_arg(arg, wchar_t*);
	if (val == NULL)
		return (NULL);
	while (val[i])
	{
		temp = ft_strcat(temp, flagbig_c(val[i]));
		i++;
	}
	return (temp);
}

char	*conv_char(va_list arg)
{
	int		c;
	char	*str;

	if (!(str = ft_strnew(1)))
		return (0);
	c = va_arg(arg, int);
	str[0] = c;
	return (str);
}

char	*conv_adresse(va_list arg, ...)
{
	unsigned long	p;
	char			*temp;

	p = va_arg(arg, unsigned long);
	temp = ft_strnew(nblen(p) + 2);
	return (ft_strcat(ft_strcat(temp, "0x"), ft_itoabase(p, 16)));
}
