/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:05:35 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 16:17:20 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*type_param_bigc_bigs(char type, va_list arg, ...)
{
	if (type == 'S')
		return (convparaminbig_s(0, arg));
	else
		return (convparaminbig_c(arg));
}

char		*recupval(char *val, char *flag, char type, va_list arg, ...)
{
	if (flag == NULL)
		return (val);
	if (type == 'S' || type == 'C')
		val = type_param_bigc_bigs(type, arg);
	else if (ft_strchr(flag, 'j'))
		val = type_param_intmax(type, arg);
	else if (ft_strchr(flag, 'z'))
		val = type_param_size_t(type, arg);
	else if (ft_strstr(flag, "ll"))
		val = type_param_long_long(type, arg);
	else if (ft_strchr(flag, 'l'))
		val = type_param_long(&type, arg);
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

char		*change_val(char *val, char *todo, char type, int *dies)
{
	if (todo[0] == '#')
	{
		val = flag_dies(type, val);
		*dies = 1;
	}
	if (todo[0] == '0')
		val = flag_0(todo, type, val);
	if ((todo[0] >= '1' && todo[0] <= '9'))
		val = flag_esp(todo, type, val);
	if (todo[0] == '.')
		val = flag_presition(todo, type, val, dies);
	if (todo[0] == '-')
		val = flag_neg(todo, type, val);
	if (todo[0] == '+')
		val = flag_pos(type, val);
	if (todo[0] == ' ')
		val = flag_espifpos(type, val);
	return (val);
}
