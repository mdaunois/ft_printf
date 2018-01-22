/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aplication_des_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:13:37 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 17:16:33 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_neg(char *str, char type, char *val)
{
	size_t	cpt;
	char	*debut;
	char	*temp;

	debut = NULL;
	temp = NULL;
	if (ft_atoi(&str[1]) < ft_strlen(val))
		return (val);
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	temp = ft_strnew(ft_atoi(&str[1]) + cpt);
	debut = ft_strnew(cpt);
	while (cpt > 0)
	{
		debut[cpt - 1] = ' ';
		cpt--;
	}
	temp = ft_strcpy(temp, val);
	if (ft_strlen(val) > 0)
		ft_strdel(&val);
	ft_strcat(temp, debut);
	if (ft_strlen(debut) > 0)
		ft_strdel(&debut);
	return (temp);
}

char	*flag_esp(char *str, char type, char *val)
{
	size_t	cpt;
	char	*debut;

	debut = NULL;
	if (ft_atoi(str) < ft_strlen(val))
		return (val);
	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
	while (cpt-- > 0)
		debut[cpt] = ' ';
	if (val != NULL)
	{
		ft_strcat(debut, val);
		if (ft_strlen(val) > 0)
			ft_strdel(&val);
		return (debut);
	}
	else
	{
		ft_strdel(&val);
		return (debut);
	}
	return (val);
}

char	*flag_pos(char type, char *str)
{
	char	*debut;

	debut = NULL;
	if (ft_strchr("idD", type))
	{
		debut = ft_strnew(ft_strlen(str) + 1);
		if (str[0] != '-')
		{
			ft_strcat(ft_strcat(debut, "+"), str);
			ft_strdel(&str);
			return (debut);
		}
	}
	return (str);
}

char	*flag_dies(char type, char *str)
{
	char	*debut;

	debut = NULL;
	if (ft_atoi(str) == 0 && (type == 'x' || type == 'X'))
		return (ft_strdup("0"));
	if (type == 'o' || type == 'O')
	{
		if (ft_atoi(str) == 0)
			return (ft_strdup("0"));
		debut = ft_strnew(ft_strlen(str) + 1);
		ft_strcat(ft_strcat(debut, "0"), str);
		ft_strdel(&str);
		return (debut);
	}
	if (type == 'x' || type == 'X')
	{
		debut = ft_strnew(ft_strlen(str) + 2);
		if (type == 'X')
			ft_strcat(ft_strcat(debut, "0X"), str);
		else
			ft_strcat(ft_strcat(debut, "0x"), str);
		ft_strdel(&str);
		return (debut);
	}
	return (str);
}

char	*flag_0(const char *str, char type, char *val)
{
	size_t	cpt;
	char	*debut;

	debut = NULL;
	if (ft_atoi(str) <= ft_strlen(val))
		return (val);
	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
	while (cpt > 0)
	{
		debut[cpt - 1] = '0';
		cpt--;
	}
	if (type == 's' && val == NULL)
		return (debut);
	val = swap_if(val, debut);
	ft_strcat(debut, val);
	if (ft_strlen(val) > 0)
		ft_strdel(&val);
	return (debut);
}
