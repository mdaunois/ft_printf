/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aplication_des_flag_suite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:14:33 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/01 12:07:51 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	exeption(char *val, char *debut)
{
	char	temp;

	if (val[1] == 'x' || val[1] == 'X')
	{
		if (ft_strlen(debut) > 1)
		{
			temp = val[1];
			val[1] = debut[1];
			debut[1] = temp;
		}
		else
		{
			temp = val[1];
			val[1] = val[0];
			val[0] = temp;
		}
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
	if (cpt > 600000 || cpt == 0)
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
	if (!(debut = ft_strnew(ft_atoi(&str[1]))))
		return (0);
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
		if (type == 'S' && MB_CUR_MAX > 1)
		{
			while ((unsigned char)val[ft_atoi(&str[1]) - i] < 191)
				i++;
			if (i > 3)
				i = 0;
			else
				i = i % 3;
		}
		if (!(temp = ft_strndup(val, ft_atoi(&str[1]) - (i))))
			return (0);
		if (ft_strlen(val) > 0)
			ft_strdel(&val);
		return (temp);
	}
	return (val);
}

char		*flag_pres(const char *str, char type, char *val)
{
	size_t	cpt;
	int		i;

	i = 0;
	if ((type == 'x' || type == 'X' || type == 'p') &&
			(val[1] == 'x' || val[1] == 'X'))
		cpt = ft_atoi(&str[1]) - (ft_strlen(val) - 2);
	else if (val[0] == '-')
		cpt = ft_atoi(&str[1]) - (ft_strlen(val) - 1);
	else
		cpt = ft_atoi(&str[1]) - ft_strlen(val);
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
	if (ft_strchr("idD", type))
	{
		if (!str)
		{
			ft_strdel(&debut);
			ft_strdel(&str);
			return (ft_strdup(" "));
		}
		if (str[0] != '-')
		{
			ft_strcat(ft_strcat(debut, " "), str);
			ft_strdel(&str);
			return (debut);
		}
	}
	ft_strdel(&debut);
	return (str);
}
