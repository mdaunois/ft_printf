/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:19 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 11:52:18 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			lenflag(const char *str, char *type, int i)
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

static char	*in_loop(char *temp, char type, int *j, int *k)
{
	if (*j == *k)
		*k = *k + 1;
	if ((temp[*j] == ' ') && (temp[*k] == ' ' || temp[*k] == '+'))
	{
		temp = ft_strjoin(ft_strndup(temp, *j), &temp[*j + 1]);
		*k = *k - 1;
	}
	else if ((temp[*j] == '+') && (temp[*k] == ' ' || temp[*k] == '+'))
	{
		temp = ft_strjoin(ft_strndup(temp, *k), &temp[*k + 1]);
		*k = *k - 1;
	}
	else if ((ft_strchr("idDoOuUxX", type)) && (temp[*j] == '.') &&
	(temp[*k] == '0' && (*k < 0 || (temp[*k - 1] < '1' || temp[*k - 1] > '9'))))
	{
		temp = ft_strjoin(ft_strndup(temp, *k), &temp[*k + 1]);
		*k = *k - 1;
		*j = *j - 1;
	}
	return (temp);
}

char		*cleandouble(char *temp, char type)
{
	int j;
	int k;

	j = -1;
	while (temp[++j])
	{
		k = -1;
		while (temp[++k])
			temp = in_loop(temp, type, &j, &k);
	}
	return (temp);
}

char		*cleandouble_2(char *temp, int multi, int multi2)
{
	int j;

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
        else if (temp[j] == '-')
        {
            if (multi2 == 1)
            {
                temp = ft_strjoin(ft_strndup(temp, j), &temp[j + 1]);
                j--;
            }
            multi2 = 1;
        }
        else if (temp[j] == '.' && temp[j + 1] == '0' && temp[j + 2])
            temp = ft_strjoin(ft_strndup(temp, j + 1), &temp[j + 2]);
	return (temp);
}

char		*recupflag(const char *str, char type, int i)
{
	char	*temp;
    int j;
    int k;
    
    j = -1;
	temp = NULL;
	if (!(temp = ft_strndup(&str[i], lenflag(str, &type, i))))
		return (0);
	temp = cleandouble(temp, type);
	temp = cleandouble_2(temp, 0, 0);
    while (temp[++j])
    {
        if (temp[j] == '.')
        {
            k = j + 1;
            while (temp[k] >'0' && temp[k] <'9')
                k++;
            if (temp[k] == '.')
                temp = ft_strjoin(ft_strndup(temp, j), &temp[k]);
        }
    }
	return (temp);
}
