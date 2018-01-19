/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:37:22 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 11:39:45 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_lengt(uintmax_t n)
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

char		*ft_itoa_uim(uintmax_t n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(get_lengt(n))))
		return (0);
	if (n == 0)
    {
        ft_strdel(&str);
        str = ft_strdup("0");
		return (str);
    }
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
