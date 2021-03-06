/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:15:18 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 17:39:45 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*between7and11(unsigned int v)
{
	char	*octet;

	octet = ft_strnew(2);
	octet[0] = ((long)49280 >> 8) | ((v >> 6) << 27) >> 27;
	octet[1] = (((long)49280 << 24) >> 24) | (v << 26) >> 26;
	return ((char *)octet);
}

char	*between12and16(unsigned int v)
{
	char	*octet;

	octet = ft_strnew(3);
	octet[0] = ((long)14712960 >> 16) | ((v >> 12) << 28) >> 28;
	octet[1] = (((long)14712960 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	octet[2] = (((long)14712960 << 24) >> 24) | (v << 26) >> 26;
	return (octet);
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

char	*less7(wchar_t value)
{
	char	*octet;

	octet = ft_strnew(1);
	octet[0] = value;
	return ((char *)octet);
}

char	*flagbig_c(wchar_t value)
{
	unsigned int	v;
	long			size;
	char			*bin;

	v = value;
	bin = (ft_itoabase((unsigned int)value, 2));
	size = ft_strlen(bin);
	ft_strdel(&bin);
	if (size <= 7)
		return (less7(v));
	else if ((v >= 0xd800 && v <= 0xdb7f) || (v >= 0xdc00 && v <= 0xdfff))
		return (ft_strdup("-1"));
	else if (size <= 8 && MB_CUR_MAX == 1)
		return (less7(v));
	else if (size <= 11 && MB_CUR_MAX > 1)
		return (between7and11(v));
	else if (size <= 16 && MB_CUR_MAX > 2)
		return (between12and16(v));
	else if (size <= 20 && MB_CUR_MAX > 3)
		return (for_more_16(v));
	else
		return (ft_strdup("-1"));
}
