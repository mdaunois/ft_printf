/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:13:55 by mdaunois          #+#    #+#             */
/*   Updated: 2017/12/12 11:17:20 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	size_t		i;
	size_t		len;
	char		*ret;

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
	return (ret);
}
