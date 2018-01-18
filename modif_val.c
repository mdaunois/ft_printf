/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:16:40 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 15:08:37 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		affiche_val(char *val, int valc, char *flag)
{
	if (valc == 0)
	{
		val[ft_strlen(val) - 1] = 0;
		ft_putstr(val);
		ft_putchar(0);
		return ((int)ft_strlen(val) + 1);
	}
	if ((ft_strchr("cC", flag[0]) && val[0] == 0))
	{
		ft_putchar(0);
		return (1);
	}
	else if (ft_strchr("sS", flag[0]) && val == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		ft_putstr(val);
		return ((int)ft_strlen(val));
	}
}

char	*flag_presition(char *todo, char type, char *val, int *dies)
{
	if (todo[1] && (todo[1] >= '1' && todo[1] <= '9'))
		return (flag_pres(todo, type, val));
    if (type == 'p' && ft_strstr(val, "0x0") && !val[3])
		return ("0x");
    if (*dies == 1 && !ft_strcmp(val, "0") && (type == 'o' || type == 'O'))
		return ("0");
	if (ft_atoi(&todo[1]) == 0 && (type == 's' || type == 'S'))
		return ("");
	if (val && val[0] == '0' && !val[1])
		return (NULL);
	return (val);
}

char	*change_val(char *val, char *todo, char type, char *flag, int *dies)
{
	if (todo[0] == '#')
    {
		val = flag_dies(type, val);
        *dies = 1;
    }
	if (todo[0] == '0')
		val = flag_0(flag, type, val);
	if ((todo[0] >= '1' && todo[0] <= '9'))
		val = flag_esp(flag, type, val);
	if (todo[0] == '.')
		val = flag_presition(todo, type, val, dies);
	if (todo[0] == '-')
		val = flag_neg(flag, type, val);
	if (todo[0] == '+')
		val = flag_pos(type, val);
	if (todo[0] == ' ')
		val = flag_espifpos(type, val);
	return (val);
}

int		do_flag(char *flag, char type, char *val)
{
	char	*todo;
	int		dies;
	int		valc;
    
    todo = NULL;
	valc = -1;
	dies = 0;
	if (flag == 0)
		return (0);
	if (type == 'c' && !ft_strcmp(val, ""))
		valc = 0;
	while (*flag != 0)
	{
		todo = range_option(flag);
		val = change_val(val, todo, type, flag, &dies);
		if (ft_strchr("SCcidDpsxoOuUX%", flag[0]))
			return (affiche_val(val, valc, flag));
		if (ft_strchr("sScCidDoOuUxX", type) && ft_strchr("lhjz", flag[0]))
			flag = ft_strdup(&flag[ft_strlen(todo) - 1]);
		else if (ft_strstr(flag, ".154d"))
			flag = &flag[ft_strlen(todo) + 1];
		else
        {
			flag = &flag[ft_strlen(todo)];
          //  if (ft_strlen(todo) > 0)
          //      ft_strdel(&todo);
        }
        
	}
    ft_putstr(val);
	return ((int)ft_strlen(val));
}
