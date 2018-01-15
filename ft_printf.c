/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:16:01 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 16:37:22 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*premierpartie(char *flag, char *temp, int i)
{
	while (flag[++i])
		if (flag[i] == '#')
		{
			swapton(flag, i, 0);
			free(temp);
			return ("#");
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
			free(temp);
			return ("+");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == ' ')
		{
			swapton(flag, i, 0);
			free(temp);
			return (" ");
		}
}

char	*range_option(char *flag)
{
	int		i;
	char	*temp;

	temp = ft_strnew(500);
	if (ft_strchr(flag, '#') || ft_strchr(flag, '.') ||
			ft_strchr(flag, '+') || ft_strchr(flag, ' '))
		return (premierpartie(flag, temp, -1));
	i = -1;
	while (flag[++i])
		if (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9'))
			return (if_0(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
			return (if_negatif(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] >= '1' && flag[i] <= '9')
			return (if_number(flag, i, temp));
	return (flag);
}

char	*recupval(char *val, char *flag, char type, va_list arg, ...)
{
	if (type == 'S')
		val = convparaminbig_s(arg);
	else if (type == 'C')
		val = convparaminbig_c(arg);
	else if (ft_strchr(flag, 'j'))
		val = type_param_intmax(type, arg);
	else if (ft_strchr(flag, 'z'))
		val = type_param_size_t(type, arg);
	else if (ft_strstr(flag, "ll"))
		val = type_param_long_long(type, arg);
	else if (ft_strchr(flag, 'l'))
		val = type_param_long(type, arg);
	else if (ft_strstr(flag, "hh"))
		val = type_param_char(type, arg);
	else if (ft_strchr(flag, 'h'))
		val = type_param_short(type, arg);
	else
		val = type_param(type, arg);
	if (val == NULL && !ft_strchr("CScsidDpxXoOuU", type))
	{
		val = ft_strnew(1);
		val[0] = type;
	}
	return (val);
}

int		option(const char *str, int i, int len, va_list arg, ...)
{
	int		len2;
	char	*flag;
	char	type;

	while (str[i])
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (len + i - 1);
			else if ((ft_strchr("%SCcsidDpxXoOuU0123456789-+.# hljz", str[i])))
			{
				len2 = lenflag(str, &type, i);
				flag = recupflag(str, &type, i);
				i = i + len2;
				len = len - len2 - 1;
				len = len + do_flag(flag, type, recupval(0, flag, type, arg));
			}
			else
				len--;
		}
		else
			ft_putchar(str[i++]);
	return (i + len);
}

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, str);
	len = option(str, 0, 0, arg);
	va_end(arg);
	return (len);
}
