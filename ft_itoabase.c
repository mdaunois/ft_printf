/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/13 17:08:33 by mdaunois         ###   ########.fr       */
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

char *conv_octal(va_list arg, ...)
{
	int	o;

	o = va_arg(arg, int);
	return ((ft_itoabase(o, 8)));
}

char *conv_char(va_list arg)
{
	int	c;
	char	*str;

	if (!(str = ft_strnew(1)))
		return (0);
	c = va_arg(arg, int);
	str[0] = c;
	return (str);
}

char *conv_str(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	return (s);
}

char *conv_nbr(va_list arg, ...)
{
	int	nb;

	nb = va_arg(arg, int);
	return ((ft_itoa(nb)));
}

char *conv_u_int(va_list arg, ...)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return ((ft_itoabase(nb, 10)));
}

char *conv_exa(va_list arg, ...)
{
	int	x;

	x = va_arg(arg, int);
	return ((ft_itoabase(x, 16)));
}

char *conv_adresse(va_list arg, ...)
{
	int	p;

	p = va_arg(arg, int);
	return ((ft_itoabase(p, 16)));
}

char *type_param(char str, va_list arg, ...)
{
	if (str == 'c')
		return (conv_char(arg));
	if (str == 's')
		return(conv_str(arg));
	if (str == 'd' || str == 'i')
		return (conv_nbr(arg));
	if (str == 'u')
		return (conv_u_int(arg));
	if (str == 'o')
		return (conv_octal(arg));
	if (str == 'x')
		return (conv_exa(arg));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == '%')
		return (0);
	return (0);
}


int flag_neg(char *str, char type, char *val)
{
	size_t cpt;
	int len;

	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	len = cpt - ft_strlen((str)) - 1;
	if (type == 'i' || type == 'd' || type == 'o' || type == 'x' || type == 'u')
	{
		while (cpt > 0)
		{
			ft_putchar(' ');
			cpt--;
		}
		return (len);
	}
	return (0);
}

int flag_esp(char *str, char type, char *val)
{
	size_t cpt;
	int len;

	cpt = ft_atoi(str) - ft_strlen(val);
	len = cpt - ft_strlen(str) - 1;
	if (type == 'i' || type == 'd' || type == 'o' || type == 'x' || type == 'u')
	{
		while (cpt > 0)
		{
			ft_putchar(' ');
			cpt--;
		}
		return (len);
	}
	return (0);
}

int flag_dies(char type)
{
	int len;

	len = 0;
	if (type == 'o')
	{
		ft_putchar('0');
		return (1);
	}
	if (type == 'x')
	{
		ft_putstr("0x");
		return (2);
	}
	return (0);
}

int flag_0(const char *str, char type, char *val)
{
	size_t cpt;
	int len;

	cpt = ft_atoi(str) - ft_strlen(val);
	len = cpt - ft_strlen(str);
	if (type == 'i' || type == 'd' || type == 'o' || type == 'x' || type == 'u')
	{
		while (cpt > 0)
		{
			ft_putchar('0');
			cpt--;
		}
		return (len);
	}
	return (0);
}

char	*swapto0(char *str, int i)
{
	char debut;

	debut = str[i];
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[0] = debut;
	return (str);
}

char *range_option(char *flag)
{
	int i;
	char temp;
	
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '+')
		{
			temp = flag[i];
			flag[i] = flag[0];
			flag[0] = temp;
			return (flag);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '-')
			return (swapto0(flag, i));
	   	i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0' && (flag[i - 1] < 1 && flag[i - 1] > 9))
		{
			temp = flag[i];
			flag[i] = flag[0];
			flag[0] = temp;
			return (flag);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
		{
			temp = flag[i];
			flag[i] = flag[0];
			flag[0] = temp;
			return (flag);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '#')
		{
			temp = flag[i];
			flag[i] = flag[0];
			flag[0] = temp;
			return (flag);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == ' ')
		{
			temp = flag[i];
			flag[i] = flag[0];
			flag[0] = temp;
			return (flag);
		}
		i++;
	}
	return (flag);
}
int		option(const char *str, va_list arg, ...)
{
	int		i;
	int 	j;
	int		len;
	int		cpt;
	char	*flag;
	char	type;
	char 	*val;

	flag = NULL;
	cpt = 0;
	len = 0;
	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = i;
			while (str[j] != 'c' && str[j] != 's' && str[j] != 'i' && str[j] != 'd' && str[j] != 'p' && str[j] != 'x' && str[j] != 'o' && str[j] != 'u' && str[j] != '\0')
			{
				j++;
			}
			type = str[j];
			val = type_param(type, arg);
			j++;
			flag = ft_strndup(&str[i], j - i);
			i = j;
			while (*flag != 0)
			{
				flag = range_option(flag);
				if (flag[0] == '#')
					len = len + flag_dies(type);
				if (flag[0] == '0')
				{
					len = len + flag_0(flag, type, val);
				}
				if (flag[0] == '-')
				{
					len = len + flag_neg(flag, type, val);
				}
				if ((flag[0] >= '1' && flag[0] <= '9'))
				{
					len = len + flag_esp(flag, type, val);
				}
				if (ft_strchr("idpsxou", flag[0]))
					ft_putstr(val);
		//			len = len + type_param(flag[0], arg);
//				printf("<%s>\n", flag);
				if (flag[0] >= '1' && flag[0] <= '9')
					flag = strdup(&flag[ft_strlen(ft_itoa((int)flag))]);
				else
					flag = strdup(&flag[1]);
			}
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

	printf("%d\n",printf("je suis %s j'ai |%#x| ans\n", "Mathieu", 30));
	printf("%d\n",ft_printf("je suis %s j'ai |%#x| ans\n", "Mathieu", 30));
	return 0;	
}
