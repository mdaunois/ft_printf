/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:36:34 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/31 18:02:26 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	ft_strdel(&s1);
	return (str);
}
