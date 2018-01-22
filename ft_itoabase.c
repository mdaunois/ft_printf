/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:37:33 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 18:03:39 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(long n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
		if (base == 16)
			return (8);
	if (base == 8)
		return (11);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoabase(long n, int base)
{
	int		i;
	char	*str;
	char	*strbase;

	strbase = "0123456789abcdef";
	i = 0;
	if (!(str = ft_strnew(get_length(n, base))))
		return (0);
	if (n == 0)
	{
		ft_strdel(&str);
		str = ft_strdup("0");
		return (str);
	}
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i++] = strbase[(n % base)];
		n /= base;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
