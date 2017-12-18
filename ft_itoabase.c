/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/18 16:54:41 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>

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

void flagC(wchar_t value)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	//wchar_t value = L'猫';
	//我是一只猫。
	unsigned int mask0 = 0;
	unsigned int mask1 = 49280;
	unsigned int mask2= 14712960;
	unsigned int mask3= 4034953344;

	unsigned int v = value;
	int size = ft_strlen((ft_itoabase((unsigned int) value, 2)));
	unsigned char octet;

	if (size <= 7)
	{
		octet = value;
		write(1, &octet, 1);
	}
	else  if (size <= 11)
	{
		unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
		unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx

		octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
		write(1, &octet, 1);
		octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
		write(1, &octet, 1);
	}
	else  if (size <= 16)
	{
		unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
		unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
		unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx

		octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
		write(1, &octet, 1);
		octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
		write(1, &octet, 1);
		octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
		write(1, &octet, 1);
	}
	else
	{
		unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
		unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
		unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
		unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

		octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
		write(1, &octet, 1);
		octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
		write(1, &octet, 1);
		octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
		write(1, &octet, 1);
		octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
		write(1, &octet, 1);
	}
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
char	*swapton(char *str, int i, int n)
{
	char debut;

	debut = str[i];
	while (i > n)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[n] = debut;
	return (str);
}

char *range_option(char *flag)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (flag[i])
	{
		if (flag[i] == '#')
			return (swapton(flag, i, 0));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '+')
			return (swapton(flag, i, 0));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == ' ')
			return (swapton(flag,i, 0));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
		{
			flag = swapton(flag, i, 0);
			i++;
			while (flag[i] >= '1' && flag[i] <= '9')
			{
				flag = swapton(flag, i, j);
				j++;
				i++;
			} 
			while (flag[i])
			{
				if (flag[i] == '0')
				{
					flag = ft_strcat(strndup(flag, i), &flag[i]);
				}
				i++;
			}
			printf("<%s>\n", flag);
			return (flag);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '-')
			return (swapton(flag, i, 0));
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0' && (flag[i - 1] < '1' && flag[i - 1] > '9'))
			return (swapton(flag, i, 0));
		i++;
	}
	return (flag);
}

void	convparaminC(va_list arg, ...)
{
	wchar_t val;

	val = va_arg(arg, wchar_t);
	flagC(val);
}

void	convparaminS(va_list arg, ...)
{
	wchar_t *val;
	int i;

	i = 0;
	val = va_arg(arg, wchar_t*);
	while (val[i])
	{
		flagC(val[i]);
		i++;
	}
}
char *recupflag(const char *str, char *type, int i)
{
	int j;
	char *flag;

	j = i;
	while (str[j] != 'X' && str[j] != 'c' && str[j] != 's' && str[j] != 'i' && str[j] != 'd' && str[j] != 'p' && str[j] != 'x' && str[j] != 'o' && str[j] != 'u' && str[j] != '\0')
	{
		j++;
	}
	*type = str[j];
	j++;
	return (ft_strndup(&str[i], j - i));

}

int	do_flag(char *flag, char type, char *val)
{
				while (*flag != 0)
				{
					//				printf("<%s>\n", flag);
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
						if ((flag[1] >= '1' && flag[1] <= '9'))
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
					if (ft_strchr("cidpsxouX", flag[0]))
						ft_putstr(val);
					if (flag[0] >= '1' && flag[0] <= '9')
						flag = strdup(&flag[nblen(ft_atoi(flag))]);
					else
						flag = strdup(&flag[1]);
				}
		return (ft_strlen(val));
}

int		option(const char *str, va_list arg, ...)
{
	int		i;
	int		len;
	char	*flag;
	char	type;
	char 	*val;

	flag = NULL;
	len = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if ((ft_strchr("csidDpxXoOuU0123456789-+.# hljz",str[i])))
			{
				flag = recupflag(str, &type, i);
				val = type_param(type, arg);
				i = i + ft_strlen(flag);
				len = len - ft_strlen(flag) - 1;
				len = len + do_flag(flag, type, val);
			}
			if (str[i] == 'C' || str[i] == 'S')
			{
				if (str[i] == 'S')
					convparaminS(arg);
				else
					convparaminC(arg);
				i++;
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

	printf("%d\n",printf("je  suis %s j'ai |%s| ans\n", "Mathieu", "⾷"));
	ft_printf("%d\n",ft_printf("je  suis %s j'ai |%s| ans\n", "Mathieu", "⾷"));
	return 0;	
}
