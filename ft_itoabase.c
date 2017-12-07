/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/07 17:30:59 by mdaunois         ###   ########.fr       */
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

	strbase = "0123456789abcdef";
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

int		nblen(int nb)
{
	int i;
	
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;	
	}
	return (i);
}

int conv_octal(int *i, va_list arg, ...)
{
	long	o;

	o = va_arg(arg, long);
	ft_putstr(ft_itoabase(o, 8));
	(*i)++;
	return (ft_strlen(ft_itoabase(o, 8) - 2));
}

int conv_char(int *i, va_list arg, ...)
{
	char	c;

	c = va_arg(arg, int);
	ft_putchar(c);
	(*i)++;
	return (-1);
}

int conv_str(int *i, va_list arg, ...)
{
	char	*s;

	s = va_arg(arg, char *);
	ft_putstr(s);
	(*i)++;
	return (ft_strlen(s) - 2);
}

int conv_nbr(int *i, va_list arg, ...)
{
	int	nb;

	nb = va_arg(arg, int);
	ft_putnbr(nb);
	(*i)++;
	return (ft_strlen(ft_itoa(nb)) - 2);
}

int conv_u_int(int *i, va_list arg, ...)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	ft_putstr(ft_itoabase(nb, 10));
	(*i)++;
	return (ft_strlen(ft_itoabase(nb, 10)) - 2);
}

int conv_exa(int *i, va_list arg, ...)
{
	long	x;

	x = va_arg(arg, long);
	ft_putstr(ft_itoabase(x, 16));
	(*i)++;
	return (ft_strlen(ft_itoabase(x, 16) - 2));
}

int conv_adresse(int *i, va_list arg, ...)
{
		long	p;

		p = va_arg(arg, long);
		ft_putstr("0x");
		ft_putstr(ft_itoabase(p, 16));
		(*i)++;
		return (ft_strlen(ft_itoabase(p, 16)));
}

int type_param(const char *str, int *i, va_list arg, ...)
{
	if (str[*i] == 'c')
		return (conv_char(i, arg));
	if (str[*i] == 's')
		return(conv_str(i, arg));
	if (str[*i] == 'd' || str[*i] == 'i')
		return (conv_nbr(i, arg));
	if (str[*i] == 'u')
		return (conv_u_int(i, arg));
	if (str[*i] == 'o')
		return (conv_octal(i,arg));
	if (str[*i] == 'x')
		return (conv_exa(i, arg));
	if (str[*i] == 'p')
		return (conv_adresse(i, arg));
	if (str[*i] == '%')
		return (-1);
	return (0);
}

int flag_dies(const char *str, int *i, va_list arg, ...)
{
	if (str[*i + 1] == 'o')
	{
		ft_putchar('0');
		(*i)++;
		return (conv_octal(i, arg));
	}
	if (str[*i + 1] == 'x')
	{
		(*i)++;
		return (conv_adresse(i, arg));
	}
	return (0);
}

int flag_0(const char *str, int *i, va_list arg, ...)
{
	int cpt;
	int nb;
	int len;
	int base;

	base = 10;
	cpt = 0;
	len = 0;
	nb = va_arg(arg, int);
	if(nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		cpt--;
		len++;
	}
	else if (str[*i] == '+')
	{
		ft_putchar('+');
		(*i)++;
		cpt--;
	}
	else if (str[*i - 2] == '+')
	{
		ft_putchar('+');
		cpt--;
	}
	cpt = cpt + ft_atoi(&str[*i]) - ft_strlen(ft_itoa(nb));
	len =len + cpt - nblen(ft_atoi(&str[*i])) - 1;
	*i = *i + nblen(ft_atoi(&str[*i]));
	if (str[*i] == 'i' || str[*i] == 'd' ||str[*i] == 'o' || str[*i] == 'x' || str[*i] == 'u')
	{
		if (str[*i] == 'o')
			base = 8;
		if (str[*i] == 'x')
			base = 16;
		while (cpt > 0)
		{
			ft_putchar('0');
			cpt--;
		}
		ft_putstr(ft_itoabase(nb, base));
		(*i)++;
		return (len);
	}
	return (0);
}

int		option(const char *str, va_list arg, ...)
{
	int i;
	int len;
	int cpt;

	cpt = 0;
	len = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '#')
				len = len + flag_dies(str, &i, arg);
			if (str[i] == '0')
			{
				i++;
				len = len + flag_0(str, &i, arg);
			}
			if (str[i] == '+')
			{
				i++;
				if (str[i] == '0')
				{
					i++;
					len = len + flag_0(str, &i, arg);
				}
			}
			len = len + type_param(str, &i, arg);
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

	printf("%d\n",printf("je suis %s j'ai %0+10i ans\n", "Mathieu", 30));
	ft_printf("%d\n",ft_printf("je suis %s j'ai %0+10i ans\n", "Mathieu", 30));
	return 0;	
}
