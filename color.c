/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:01:10 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/31 13:11:31 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	debut_color(char *flag, int len)
{
	if (!ft_strcmp(flag, "red"))
	{
		ft_putstr("\033[31m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	else if (!ft_strcmp(flag, "green"))
	{
		ft_putstr("\033[32m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	else if (!ft_strcmp(flag, "yellow"))
	{
		ft_putstr("\033[33m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	else if (!ft_strcmp(flag, "blue"))
	{
		ft_putstr("\033[34m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	return (0);
}

static int	fin_color(char *flag, int len)
{
	if (!ft_strcmp(flag, "magenta"))
	{
		ft_putstr("\033[35m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	else if (!ft_strcmp(flag, "cyan"))
	{
		ft_putstr("\033[36m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	else if (!ft_strcmp(flag, "white") || !ft_strcmp(flag, "eoc"))
	{
		ft_putstr("\033[37m");
		return (len - ((int)ft_strlen(flag) + 2));
	}
	return (0);
}

int			color_flag(const char *str, int *i, int len)
{
	int		j;
	char	*flag;
	int		len2;

	len2 = 0;
	j = *i + 1;
	while (str[j] != '}' && str[j])
		j++;
	flag = ft_strndup(&str[*i + 1], j - *i - 1);
	if (debut_color(flag, len) != 0)
	{
		*i = j + 1;
		len2 = (debut_color(flag, len));
	}
	else if (fin_color(flag, len) != 0)
	{
		*i = j + 1;
		len2 = (fin_color(flag, len));
	}
	ft_putchar(str[*i]);
	*i = *i + 1;
	ft_strdel(&flag);
	return (len2);
}
