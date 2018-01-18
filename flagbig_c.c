/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:15:18 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 15:13:57 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*between12and16(unsigned int v)
{
	char	*octet;

	octet = ft_strnew(3);
	octet[0] = ((long)14712960 >> 16) | ((v >> 12) << 28) >> 28;
	octet[1] = (((long)14712960 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	octet[2] = (((long)14712960 << 24) >> 24) | (v << 26) >> 26;
	return ((char *)octet);
}

char	*for_more_16(unsigned int v)
{
	char	*octet;

	octet = ft_strnew(4);
	octet[0] = ((long)4034953344 >> 24) | ((v >> 18) << 29) >> 29;
	octet[1] = (((long)4034953344 << 8) >> 24) | ((v >> 12) << 26) >> 26;
	octet[2] = (((long)4034953344 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	octet[3] = (((long)4034953344 << 24) >> 24) | (v << 26) >> 26;
	return ((char *)octet);
}

char	*flagbig_c(wchar_t value)
{
	unsigned int	v;
	long			size;
	char			*octet;
    char            *bin;

	v = value;
    bin = (ft_itoabase((unsigned int)value, 2));
	size = ft_strlen(bin);
    ft_strdel(&bin);
	if (size <= 7)
	{
		octet = ft_strnew(1);
		octet[0] = value;
		return ((char *)octet);
	}
	else if (size <= 11)
	{
		octet = ft_strnew(2);
		octet[0] = ((long)49280 >> 8) | ((v >> 6) << 27) >> 27;
		octet[1] = (((long)49280 << 24) >> 24) | (v << 26) >> 26;
		return ((char *)octet);
	}
	else if (size <= 16)
		return (between12and16(v));
	else
		return (for_more_16(v));
}
