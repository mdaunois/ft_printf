/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aplication_des_flag_suite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:14:33 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 17:15:19 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	exeption(char *val, char *debut)
{
	char	temp;

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
}

static char	*presition_num(char *val, char *debut, size_t cpt, const char *str)
{
	if (ft_atoi(&str[1]) < ft_strlen(val))
	{
		ft_strdel(&debut);
		return (val);
	}
	if (ft_atoi(&str[1]) == 0)
	{
		ft_strdel(&debut);
		ft_strdel(&val);
		return (NULL);
	}
	debut = ft_strnew(ft_atoi(&str[1]));
	while (cpt > 0)
	{
		debut[cpt - 1] = '0';
		cpt--;
	}
	exeption(val, debut);
	ft_strcat(debut, val);
	ft_strdel(&val);
	return (debut);
}

static char	*presition_str(char *val, char *temp, const char *str, char type)
{
	int i;

	i = 0;
	if (ft_atoi(&str[1]) < (int)ft_strlen(val))
	{
		if (type == 'S')
		{
			while ((unsigned char)val[ft_atoi(&str[1]) - i] < 192)
				i++;
			if (i > 3)
				i = 0;
			else
				i = i % 3;
		}
		temp = ft_strndup(val, ft_atoi(&str[1]) - (i));
		if (ft_strlen(val) > 0)
			ft_strdel(&val);
		return (temp);
	}
	return (val);
}

char		*flag_pres(const char *str, char type, char *val)
{
	size_t	cpt;
	char	*temp;
	int		i;

	i = 0;
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	if (val[0] == '-')
		cpt++;
	if ((type == 'x' || type == 'X' || type == 'p') &&
			(val[1] == 'x' || val[1] == 'X'))
		cpt = cpt + 2;
	if (ft_strchr("pdDioOuUxX", type))
		return (presition_num(val, NULL, cpt, str));
	if (ft_strchr("sS", type))
		return (presition_str(val, NULL, str, type));
	return (val);
}

char		*flag_espifpos(char type, char *str)
{
	char	*debut;

	debut = ft_strnew(ft_strlen(str) + 1);
	if (ft_strchr("id", type))
	{
		if (str[0] != '-')
		{
			ft_strcat(ft_strcat(debut, " "), str);
			ft_strdel(&str);
			return (debut);
		}
	}
	return (str);
}
