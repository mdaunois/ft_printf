/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a_appliquer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:15:32 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 16:52:43 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_point(char *flag, int i, char *temp)
{
	int j;

	j = 1;
    temp = ft_strnew(nblen(ft_atoi(&flag[i + 1])) + 1);
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
	return (temp);
}

char	*if_0(char *flag, int i, char *temp)
{
	int j;

	j = 1;
    temp = ft_strnew(nblen(ft_atoi(&flag[i + 1])) + 1);
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
	return (temp);
}

char	*if_negatif(char *flag, int i, char *temp)
{
	int j;

	j = 1;
    temp = ft_strnew(nblen(ft_atoi(&flag[i + 1])) + 1);
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
	return (temp);
}

char	*if_number(char *flag, int i, char *temp)
{
	int j;

	j = 1;
    temp = ft_strnew(nblen(ft_atoi(&flag[i])));
	flag = swapton(flag, i, 0);
	while (flag[i] >= '0' && flag[i] <= '9')
	{
		temp[j - 1] = flag[i];
		i++;
		flag = swapton(flag, i, j);
		j++;
	}
	return (temp);
}
