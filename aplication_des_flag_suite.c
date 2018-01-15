/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aplication_des_flag_suite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:14:33 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 17:29:50 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*presition_for_num(char *val, char *debut, size_t cpt, const char *str)
{
	char	temp;

	if (ft_atoi(&str[1]) < ft_strlen(val))
		return (val);
	if (ft_atoi(&str[1]) == 0)
		return (0);
	while (cpt > 0)
	{
		debut[cpt - 1] = '0';
		cpt--;
	}
	if (val[1] == 'x' || val[1] == 'X')
	{
		temp = val[1];
		val[1] = debut[1];
		debut[1] = temp;
	}
	if (val[0] == '-')
	{
		temp = val[0];
		val[0] = debut[0];
		debut[0] = temp;
	}
	return (ft_strcat(debut, val));
}

char	*flag_pres(const char *str, char type, char *val)
{
	size_t	cpt;
	char	*debut;
	int		i;

	i = 0;
	debut = ft_strnew(ft_atoi(&str[1]));
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	if (val[0] == '-')
		cpt++;
	if ((type == 'x' || type == 'X' || type == 'p') &&
				(val[1] == 'x' || val[1] == 'X'))
		cpt = cpt + 2;
	if (ft_strchr("pdDioOuUxX", type))
		return (presition_for_num(val, debut, cpt, str));
	if (ft_strchr("sS", type))
		if (ft_atoi(&str[1]) < ft_strlen(val))
		{
			while ((unsigned char)val[ft_atoi(&str[1]) - i] < 192)
				i++;
			if (i > 3)
				i = 0;
			return (ft_strndup(val, ft_atoi(&str[1]) - (i)));
		}
	return (val);
}

char	*flag_espifpos(char type, char *str)
{
	char	*debut;

	debut = ft_strnew(ft_strlen(str) + 1);
	if (ft_strchr("id", type))
	{
		if (str[0] != '-')
		{
			return (ft_strcat(ft_strcat(debut, " "), str));
		}
	}
	return (str);
}
