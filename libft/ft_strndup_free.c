/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:25:31 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/31 18:02:42 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup_free(char *s1, int size)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (size > len)
		return (0);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	ft_strdel(&s1);
	return (ret);
}
