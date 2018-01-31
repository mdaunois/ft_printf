/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:16:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/31 14:43:44 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_presition(char *todo, char type, char *val, int *dies)
{
	if (todo[1] && (todo[1] >= '1' && todo[1] <= '9'))
		return (flag_pres(todo, type, val));
	if (type == 'p' && ft_strstr(val, "0x0") && !val[3])
		return (ft_strdup("0x"));
	if (*dies == 1 && !ft_strcmp(val, "0") && (type == 'o' || type == 'O'))
		return (val);
	if (ft_atoi(&todo[1]) == 0 && (type == 's' || type == 'S'))
		return (ft_strdup(""));
	if (val && val[0] == '0' && !val[1])
		return (NULL);
	return (val);
}

static char	*new_flag(char *flag, char *todo, int i)
{
	char	*temp;

	temp = ft_strdup(&flag[ft_strlen(todo)] - i);
	ft_strdel(&flag);
	flag = ft_strdup(temp);
	ft_strdel(&temp);
	ft_strdel(&todo);
	return (flag);
}

static int	loop_todo(char *flag, char type, char **val, int valc)
{
	char	*todo;
	int		dies;

	todo = NULL;
	dies = 0;
	while (*flag != 0)
	{
		todo = range_option(flag);
		*val = change_val(*val, todo, type, &dies);
		if (ft_strchr("SCcidDpsxoOuUX", flag[0]))
		{
			ft_strdel(&flag);
			ft_strdel(&todo);
			return (1);
		}
		if (ft_strchr("sScCidDoOuUxX", type) && ft_strchr("lhjz", flag[0]))
			flag = new_flag(flag, todo, 1);
		else
			flag = new_flag(flag, todo, 0);
	}
	ft_strdel(&flag);
	return (0);
}

int			do_flag(char *flag, char type, char *val, int valc)
{
	if (flag == 0)
		return (0);
	if ((ft_strchr(flag, 'l') && type == 'c'))
		type = 'C';
	if ((ft_strchr(flag, 'l') && type == 's'))
		type = 'S';
	if (val)
		if ((type == 'S' || type == 'C') && !ft_strcmp(val, "-1"))
		{
			ft_strdel(&val);
			ft_strdel(&flag);
			return (-1);
		}
	if ((type == 's' || type == 'S') && !val)
		val = ft_strdup("(null)");
	if (type == 'c' && !ft_strcmp(val, ""))
		valc = 0;
	if (loop_todo(flag, type, &val, valc) == 1)
		return (affiche_val(val, valc, type, 0));
	ft_putstr(val);
	valc = (int)ft_strlen(val);
	if (valc > 0)
		ft_strdel(&val);
	return (valc);
}
