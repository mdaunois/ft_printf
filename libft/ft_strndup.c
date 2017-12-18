/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:25:31 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/08 12:51:03 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int size)
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
    return (ret);
}
