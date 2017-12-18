/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/14 17:16:00 by mdaunois         ###   ########.fr       */
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

char	*mag(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
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
	unsigned long	p;
	char			*temp;

	p = va_arg(arg, unsigned long);
	temp = ft_strnew(nblen(p) + 2);
	return (ft_strcat(ft_strcat(temp, "0x"), ft_itoabase(p, 16)));
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
	if (str == 'X')
		return (mag(conv_exa(arg)));
	if (str == '%')
		return (0);
	return (0);
}


char *flag_neg(char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char *temp;

	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	temp = ft_strnew(ft_atoi(&str[1]) + cpt);
	debut = ft_strnew(cpt);
	if (ft_strchr("scdDioOuUxX", type))
	{
		while (cpt > 0)
		{
			debut[cpt - 1] = ' ';
			cpt--;
		}
		temp = ft_strcpy(temp, val);
		return (ft_strcat(temp, debut));
	}
	return (0);
}

char *flag_esp(char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char temp;

	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
	if (ft_strchr("scdDioOuUxX", type))
	{
		while (cpt > 0)
		{
			debut[cpt - 1] = ' ';
			cpt--;
		}
		return (ft_strcat(debut, val));
	}
	return (0);
}

char *flag_pos(char type, char *str)
{
	char *debut;

	debut = ft_strnew(ft_strlen(str) + 1);
	if (ft_strchr("id", type))
	{
		if (str[0] != '-')
		{
			return (ft_strcat(ft_strcat(debut, "+"), str));
		}
	}
	return (str);
}

char *flag_dies(char type, char *str)
{
	char *debut;

	if (ft_atoi(str) == 0)
		return("0");
	if (type == 'o')
	{
		debut = ft_strnew(ft_strlen(str) + 1);
		return (ft_strcat(ft_strcat(debut, "0"), str));
	}
	if (type == 'x')
	{
		debut = ft_strnew(ft_strlen(str) + 2);
		return (ft_strcat(ft_strcat(debut, "0x"), str));
	}
	if (type == 'X')
	{
		debut = ft_strnew(ft_strlen(str) + 2);
		return (ft_strcat(ft_strcat(debut, "0X"), str));
	}
	return (0);
}

char *flag_pres(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char temp;

	debut = ft_strnew(ft_atoi(&str[1]));
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	if (ft_strchr("dDioOuUxX", type))
	{
		while (cpt > 0)
		{
			debut[cpt - 1] = '0';
			cpt--;
		}
		if (val[1] == 'x' || val[1] == 'X')
		{
			temp = val[1];
			val[1] = debut[1];
			debut[1] = temp;	
		}
		if (val[0] == '-')
		{
			temp = val[0];
			val[0] = debut[0];
			debut[0] = temp;
		}
		
		return (ft_strcat(debut, val));
	}
	return (0);
}
char *flag_0(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char temp;

	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
	if (ft_strchr("dDioOuUxX", type))
	{
		while (cpt > 0)
		{
			debut[cpt - 1] = '0';
			cpt--;
		}
		if (val[1] == 'x' || val[1] == 'X')
		{
			temp = val[1];
			val[1] = debut[1];
			debut[1] = temp;	
		}
		if (val[0] == '-')
		{
			temp = val[0];
			val[0] = debut[0];
			debut[0] = temp;
		}
		
		return (ft_strcat(debut, val));
	}
	return (0);
}
char	*flag_espifpos(char type, char *str)
{
	
	char *debut;

	debut = ft_strnew(ft_strlen(str) + 1);
	if (ft_strchr("id", type))
	{
		if (str[0] != '-')
		{
			return (ft_strcat(ft_strcat(debut, " "), str));
		}
	}
	return (str);
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
	
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '#')
			return (swapto0(flag, i));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '+')
			return (swapto0(flag, i));
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
		if (flag[i] == '0' && (flag[i - 1] < '1' && flag[i - 1] > '9'))
			return (swapto0(flag, i));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
			return (swapto0(flag, i));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == ' ')
			return (swapto0(flag,i));
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
			if ((ft_strchr("cCsSidDpxXoOuU0123456789-+.# hljz",str[i])))
			{
				while (str[j] != 'X' && str[j] != 'c' && str[j] != 's' && str[j] != 'i' && str[j] != 'd' && str[j] != 'p' && str[j] != 'x' && str[j] != 'o' && str[j] != 'u' && str[j] != '\0')
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
						val = flag_dies(type, val);
					if (flag[0] == '0')
					{
						val = flag_0(flag, type, val);
						flag = strdup(&flag[1]);
					}
					if (flag[0] == '.')
					{
						val = flag_pres(flag, type, val);
						flag = strdup(&flag[1]);
					}
					if (flag[0] == '-')
					{
						val = flag_neg(flag, type, val);
						flag = strdup(&flag[1]);
					}
					if ((flag[0] >= '1' && flag[0] <= '9'))
						val = flag_esp(flag, type, val);
					if (flag[0] == '+')
						val = flag_pos(type, val);
					if (flag[0] == ' ')
					{
						val = flag_espifpos(type, val);
					}
					if (ft_strchr("idpsxouX", flag[0]))
						ft_putstr(val);
			//		printf("<%s>\n", flag);
					if (flag[0] >= '1' && flag[0] <= '9')
						flag = strdup(&flag[nblen(ft_atoi(flag))]);
					else
						flag = strdup(&flag[1]);
				}
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

	a = 2;

	printf("%d\n",printf("je  suis %s j'ai |%i| ans\n", "Mathieu", a + 28));
	ft_printf("%d\n",ft_printf("je  suis %s j'ai |%i| ans\n", "Mathieu", a + 28));
	return 0;	
}
