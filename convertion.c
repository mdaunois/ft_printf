/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:14:59 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/31 11:44:57 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convparaminbig_c(va_list arg, ...)
{
	wchar_t	val;

	val = va_arg(arg, wchar_t);
	return (flagbig_c(val));
}

char	*convparaminbig_s(int i, va_list arg, ...)
{
	wchar_t		*val;
	char		*temp;
	char		*lettre;

	lettre = NULL;
	val = va_arg(arg, wchar_t*);
	if (val == NULL)
		return (NULL);
	while (val[i++])
		i++;
	temp = ft_strnew(i * 3);
	i = -1;
	while (val[++i])
	{
		lettre = flagbig_c(val[i]);
		temp = ft_strcat(temp, lettre);
		ft_strdel(&lettre);
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
	char			*val;

	p = va_arg(arg, unsigned long);
	temp = ft_itoabase(p, 16);
	val = ft_strjoin("0x", temp);
	ft_strdel(&temp);
	return (val);
}
