/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/10 15:38:21 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

static int	get_length(int n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoabase(long int n, int base)
{
	int	i;
	char	*str;
	char	*strbase;

	strbase = "0123456789ABCDEF";
	i = 0;
	if (!(str = ft_strnew(get_length(n, base))))
		return (0);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i++] = strbase[(n % base)];
		n /= base;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

int		option(const char *str, va_list arg, ...)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				char	*s;

				s = va_arg(arg, char *);
				ft_putstr(s);
				len = len + ft_strlen(s) - 2;
				i++;
			}
			if (str[i + 1] == 'd')
			{
				int	nb;
				
				nb = va_arg(arg, int);
				ft_putnbr(nb);
				len = len + ft_strlen(ft_itoa(nb)) - 2;
				i++;
			}
			if (str[i + 1] == 'p')
			{
				long	p;

				p = va_arg(arg, long);
				ft_putstr("0x");
				ft_putstr(ft_itoabase(p, 16));
				len = len + ft_strlen(ft_itoabase(p, 16));
				i++;
			}
		i++;
		}
		ft_putchar(str[i]);
		i++;	
	}
	return (i + len);
}

int		ft_printf(const char *str, ...)
{
	va_list arg;
	int len;

	va_start(arg, str);
	len = option(str, arg);
	va_end(arg);
	return (len);
}
int	main()
{
	int a;

	printf("%d\n",printf("je suis %s j'ai %d ans\n", "Mathieu", 30));
	ft_printf("%d\n",ft_printf("je suis %s j'ai %d ans\n", "Mathieu", 30));
	return 0;	
}
