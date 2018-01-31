/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:16:01 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/31 12:42:56 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*premierpartie(char *flag, char *temp, int i)
{
	while (flag[++i])
		if (flag[i] == '#')
		{
			swapton(flag, i, 0);
			return (ft_strdup("#"));
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == '.')
			return (if_point(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] == '+')
		{
			swapton(flag, i, 0);
			return (ft_strdup("+"));
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == ' ')
		{
			swapton(flag, i, 0);
			return (ft_strdup(" "));
		}
	return (flag);
}

char		*range_option(char *flag)
{
	int		i;
	char	*temp;

	temp = NULL;
	if (ft_strchr(flag, '#') || ft_strchr(flag, '.') ||
			ft_strchr(flag, '+') || ft_strchr(flag, ' '))
		return (premierpartie(flag, temp, -1));
	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
			return (if_negatif(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] == '0' && (i == 0 || (flag[i - 1] < '0' ||
						flag[i - 1] > '9')))
			return (if_0(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] >= '1' && flag[i] <= '9')
			return (if_number(flag, i, temp));
	return (ft_strdup(flag));
}

static int	new_arg(const char *str, int *i, int len, va_list arg, ...)
{
	int		len2;
	char	*flag;
	char	type;

	if ((ft_strchr("%SCcsidDpxXoOuU0123456789-+.# hljz", str[*i])))
	{
		len2 = lenflag(str, &type, *i);
		flag = recupflag(str, type, *i);
		if (type == 10 || type == 0)
		{
			*i = *i + len2 - 1;
			return (-len2);
		}
		*i = *i + len2;
		len = len - len2 - 1;
		len2 = do_flag(flag, type, recupval(0, flag, type, arg), -1);
		if (len2 == -1)
			return (-500);
		return ((len + len2));
	}
	else
		return (len - 1);
}

int			option(const char *str, int i, int len, va_list arg, ...)
{
	while (str[i])
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (len + i - 1);
			else if (str[i] == '%')
			{
				ft_putchar(str[i++]);
				len--;
			}
			else
			{
				len = new_arg(str, &i, len, arg);
				if (len == -500)
					return (-1);
			}
		}
		else if (str[i] == '{')
			len = color_flag(str, &i, len);
		else
			ft_putchar(str[i++]);
	return (i + len);
}

int			ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, str);
	len = option(str, 0, 0, arg);
	va_end(arg);
	return (len);
}
