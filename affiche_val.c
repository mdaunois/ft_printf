/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:05:35 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/31 17:53:27 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	affiche_val_suit(char *val, int valc, char type, int len)
{
	int i;

	i = 0;
	if (ft_strchr("SC", type))
		while (val[i])
		{
			if (val[i] == '-' && val[i + 1] == '1')
			{
				ft_strdel(&val);
				return (-1);
			}
			i++;
		}
	if (ft_strlen(val) > 0)
	{
		len = (int)ft_strlen(val);
		ft_putstr(val);
		ft_strdel(&val);
		return (len);
	}
	ft_putstr(val);
	return (len);
}

int			affiche_val(char *val, int valc, char type, int len)
{
	if (valc == 0)
	{
		if (ft_strlen(val) > 0)
			val[ft_strlen(val) - 1] = 0;
		ft_putstr(val);
		ft_putchar(0);
		len = (int)ft_strlen(val) + 1;
		ft_strdel(&val);
		return (len);
	}
	else if ((ft_strchr("cC", type) && val[0] == 0))
	{
		ft_putchar(0);
		return (1);
	}
	else
	{
		return (affiche_val_suit(val, valc, type, len));
	}
}
