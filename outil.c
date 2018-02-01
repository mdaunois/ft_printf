/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:03 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/01 14:09:47 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mag(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*swap_if(char *val, char *debut)
{
	char	temp;

	if (val[1] == 'x' || val[1] == 'X')
	{
		temp = val[1];
		val[1] = debut[1];
		debut[1] = temp;
	}
	if (val[0] == '-' || val[0] == '+' || val[0] == ' ')
	{
		temp = val[0];
		val[0] = debut[0];
		debut[0] = temp;
	}
	return (val);
}

char	*swapton(char *str, int i, int n)
{
	char	debut;

	debut = str[i];
	while (i > n)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[n] = debut;
	return (str);
}

long	nblen(long nb)
{
	long	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*remove_one_char(char *temp, int j, char *temp2, int i)
{
	temp2 = ft_strjoin_free(ft_strndup(temp, j), &temp[j + i]);
	ft_strdel(&temp);
	temp = ft_strdup(temp2);
	ft_strdel(&temp2);
	return (temp);
}
