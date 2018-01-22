/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:36:10 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 17:57:14 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	get_length(intmax_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoa_long(intmax_t n)
{
	int			i;
	char		*str;
	uintmax_t	nb;

	i = 0;
	if (!(str = ft_strnew(get_length(n))))
		return (0);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb == 0)
	{
		ft_strdel(&str);
		str = ft_strdup("0");
		return (str);
	}
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
