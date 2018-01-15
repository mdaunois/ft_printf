/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a_appliquer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:15:32 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 15:09:15 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_point(char *flag, int i, char *temp)
{
	int j;

	j = 1;
	flag = swapton(flag, i, 0);
	temp[j - 1] = '.';
	i++;
	while (flag[i] >= '0' && flag[i] <= '9')
	{
		temp[j] = flag[i];
		flag = swapton(flag, i, j);
		j++;
		i++;
	}
	while (flag[i])
	{
		if (flag[i] == '0')
		{
			flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
		}
		i++;
	}
	return (temp);
}

char	*if_0(char *flag, int i, char *temp)
{
	int j;

	j = 1;
	flag = swapton(flag, i, 0);
	temp[j - 1] = '0';
	i++;
	while (flag[i] >= '0' && flag[i] <= '9')
	{
		temp[j] = flag[i];
		flag = swapton(flag, i, j);
		j++;
		i++;
	}
	while (flag[i])
	{
		if (flag[i] == '0')
		{
			flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
		}
		i++;
	}
	return (temp);
}

char	*if_negatif(char *flag, int i, char *temp)
{
	int j;

	j = 1;
	flag = swapton(flag, i, 0);
	temp[j - 1] = '-';
	i++;
	while (flag[i] >= '0' && flag[i] <= '9')
	{
		temp[j] = flag[i];
		flag = swapton(flag, i, j);
		j++;
		i++;
	}
	while (flag[i])
	{
		if (flag[i] == '0')
		{
			flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
		}
		i++;
	}
	return (temp);
}

char	*if_number(char *flag, int i, char *temp)
{
	int j;

	j = 1;
	flag = swapton(flag, i, 0);
	while (flag[i] >= '0' && flag[i] <= '9')
	{
		temp[j - 1] = flag[i];
		i++;
		flag = swapton(flag, i, j);
		j++;
	}
	while (flag[i])
	{
		if (flag[i] == '0')
		{
			flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
		}
		i++;
	}
	return (temp);
}
