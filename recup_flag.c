/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:19 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 17:54:49 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lenflag(const char *str, char *type, int i)
{
	int j;

	j = i;
	while (ft_strchr("0123456789-+.# hljz", str[j]) && str[j])
	{
		j++;
	}
	*type = str[j];
	j++;
	return (j - i);
}

char	*cleandouble(char *temp, char type)
{
	int j;
	int k;

	j = -1;
	while (temp[++j])
	{
		k = -1;
		while (temp[++k])
		{
			if (j == k)
				k++;
			if ((temp[j] == ' ') && (temp[k] == ' ' || temp[k] == '+'))
			{
				temp = ft_strjoin(ft_strndup(temp, j), &temp[j + 1]);
				k--;
                //j--;
			}
			else if ((temp[j] == '+') && (temp[k] == ' ' || temp[k] == '+'))
			{
				temp = ft_strjoin(ft_strndup(temp, k), &temp[k + 1]);
				k--;
                //j--;
			}
			else if ((ft_strchr("idDoOuUxX", type)) && (temp[j] == '.') &&
					(temp[k] == '0' && (k < 0 || (temp[k - 1] < '1' || temp[k - 1] > '9'))))
			{
				temp = ft_strjoin(ft_strndup(temp, k), &temp[k + 1]);
				k--;
                j--;
			}
		}
	}
	return (temp);
}

int del_one_char(char *temp, int j, int multi)
{
	if (multi == 1)
	{
		temp = ft_strjoin(ft_strndup(temp, j), &temp[j + 1]);
		j--;
	}
	return (1);
}

char	*cleandouble_2(char *temp)
{
	int multi;
	int j;

	multi = 0;
	j = -1;
	while (temp[++j])
		if (temp[j] == '.')
			multi = del_one_char(temp, j, multi);
	multi = 0;
	j = -1;
	while (temp[++j])
		if (temp[j] == '#')
        {
            if (multi == 1)
            {
                temp = ft_strjoin(ft_strndup(temp, j), &temp[j + 1]);
                j--;
            }
        multi = 1;
        }
	multi = 0;
	j = -1;
	while (temp[++j])
		if (temp[j] == '-')
		{
			if (multi == 1)
            {
				temp = ft_strjoin(ft_strndup(temp, j), &temp[j + 1]);
                j--;
            }
			multi = 1;
		}
	return (temp);
}

char	*recupflag(const char *str, char type, int i)
{
	char	*temp;
	int		multi;

	temp = NULL;
	if (!(temp = ft_strndup(&str[i], lenflag(str, &type, i))))
		return (0);
	temp = cleandouble(temp, type);
	multi = 0;
	temp = cleandouble_2(temp);
	return (temp);
}
