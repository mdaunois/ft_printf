/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/11 13:39:13 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>
static int	get_length_uintmax(uintmax_t n, int base)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoabase_uintmax(uintmax_t n, int base)
{
	int		i;
	char	*str;
	char	*base_str;

	base_str = "0123456789abcdef";
	i = 0;
	if (!(str = ft_strnew(get_length_uintmax(n, base))))
		return (0);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (n != 0)
	{
		str[i++] = base_str[(n % base)];
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
long	get_lengthl(intmax_t n)
{

	int	len;

	len = 0;
	//	if (n < 0)
	//		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoa_long(intmax_t n)
{
	int			i;
	char		*str;
	uintmax_t	nb;

	i = 0;
	if (!(str = ft_strnew(get_lengthl(n))))
		return (0);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

static int	get_lengthui(uintmax_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoa_uim(uintmax_t n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(get_lengthui(n))))
		return (0);
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int	get_length_base_long(intmax_t n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
		if (base == 16)
			return (8);
	if (base == 8)
		return (11);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoabase_long(intmax_t n, int base)
{
	int	i;
	char	*str;
	char	*strbase;
	char	*strbasen;

	strbase = "0123456789abcdef";
	strbasen = "fedcba9876543210";
	if (base == 8)
		strbasen = "76543210";
	i = 0;
	if (!(str = ft_strnew(get_length_base_long(n, base))))
		return (0);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n < 0)
	{
		n = -n;
		str[i++] = strbasen[(n % base) - 1];
		n /= base;
		while (i < 8)
		{
			str[i++] = strbasen[(n % base)];
			n /= base;
		}
		str[i] = '\0';
		return (ft_strrev(str));
	}
	while (n != 0)
	{
		str[i++] = strbase[(n % base)];
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
int	get_length(long n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
		if (base == 16)
			return (8);
	if (base == 8)
		return (11);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	if (len <= 0)
		len = 1;
	return (len);
}

char		*ft_itoabase(long n, int base)
{
	int	i;
	char	*str;
	char	*strbase;
	char	*strbasen;

	strbase = "0123456789abcdef";
	strbasen = "fedcba9876543210";
	if (base == 8)
		strbasen = "76543210";
	i = 0;
	if (!(str = ft_strnew(get_length(n, base))))
		return (0);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n < 0)
	{
		n = -n;
		str[i++] = strbasen[(n % base) - 1];
		n /= base;
		while (i < 8)
		{
			str[i++] = strbasen[(n % base)];
			n /= base;
		}
		str[i] = '\0';
		return (ft_strrev(str));
	}
	while (n != 0)
	{
		str[i++] = strbase[(n % base)];
		n /= base;
	}
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

long		nblen(long nb)
{
	long i;

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
	unsigned int	o;

	o = va_arg(arg,unsigned int);
	return ((ft_itoabase(o, 8)));
}

char *conv_long_octal(va_list arg, ...)
{
	unsigned long	o;

	o = va_arg(arg, unsigned long);
	return ((ft_itoabase_uintmax(o, 8)));
}

char *conv_octal_uintmax(va_list arg, ...)
{
	uintmax_t	o;

	o = va_arg(arg, uintmax_t);
	return ((ft_itoabase_uintmax(o, 8)));
}

char *conv_char(va_list arg)
{
	int	c;
	char	*str;

	if (!(str = ft_strnew(1)))
		return (0);
	c = va_arg(arg, int);
	if (c != 0)
	{
		str[0] = c;
		return (str);
	}
	else
		return ("^@");
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

char *conv_long(va_list arg, ...)
{
	long long	nb;

	nb = va_arg(arg, long long);
	return ((ft_itoa_long(nb)));
}

char *conv_intmax(va_list arg, ...)
{
	intmax_t	nb;

	nb = va_arg(arg, intmax_t);
	return ((ft_itoa_long(nb)));
}

char *conv_short(va_list arg, ...)
{
	short	nb;

	nb = va_arg(arg, short);
	return ((ft_itoa(nb)));
}

char *conv_u_int(va_list arg, ...)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return ((ft_itoa_long(nb)));
}

char *conv_u_long(va_list arg, ...)
{
	unsigned long	nb;

	nb = va_arg(arg, unsigned long);
	return (ft_itoa_uim(nb));
}

char *conv_uintmax(va_list arg, ...)
{
	uintmax_t	nb;

	nb = va_arg(arg, uintmax_t);
	return (ft_itoa_uim(nb));
}

char *conv_exa(va_list arg, ...)
{
	int	x;

	x = va_arg(arg, int);
	return ((ft_itoabase(x, 16)));
}

char *conv_exa_long(va_list arg, ...)
{
	unsigned long	x;

	x = va_arg(arg, unsigned long);
	return ((ft_itoabase_uintmax(x, 16)));
}

char *conv_exa_uintmax(va_list arg, ...)
{
	uintmax_t	x;

	x = va_arg(arg, uintmax_t);
	return ((ft_itoabase_uintmax(x, 16)));
}

char *conv_exa_short(va_list arg, ...)
{
	unsigned short	x;

	x = va_arg(arg, unsigned short);
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
	if (str == 'U')
		return (conv_u_long(arg));
	if (str == 'o')
		return (conv_octal(arg));
	if (str == 'O')
		return (conv_long_octal(arg));
	if (str == 'x')
		return (conv_exa(arg));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == 'X')
		return (mag(conv_exa(arg)));
	if (str == 'D')
		return (conv_long(arg));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_long(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (conv_long(arg));
	if (str == 'x')
		return (conv_exa_long(arg));
	if (str == 'X')
		return (mag(conv_exa_long(arg)));
	if (str == 'o')
		return (conv_long_octal(arg));
	if (str == 'u')
		return (conv_u_long(arg));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_long_long(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, long long), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, long long), 16)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, long long), 8));
	if (str == 'u'|| str == 'U')
		return (ft_itoa_uim(va_arg(arg,unsigned long long)));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_short(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i')
		return (conv_short(arg));
	if (str == 'D')
		return (conv_long(arg));
	if (str == 'u')
		return (ft_itoa_long((unsigned short)va_arg(arg, int)));
	if (str == 'U')
		return (ft_itoa_long(va_arg(arg, long)));
	if (str == 'o')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 8));
	if (str == 'O')
		return (conv_octal(arg));
	if (str == 'x')
		return (conv_exa_short(arg));
	if (str == 'X')
		return (mag(conv_exa_short(arg)));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_char(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i')
		return (ft_itoa((signed char)va_arg(arg, int)));
	if (str == 'D')
		return (ft_itoa(va_arg(arg, int)));
	if (str == 'u')
		return (ft_itoa_long((unsigned char)va_arg(arg, int)));
	if (str == 'U')
		return (ft_itoa_long(va_arg(arg, long)));
	if (str == 'o')
		return (ft_itoabase((unsigned char)va_arg(arg, int), 8));
	if (str == 'O')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 8));
	if (str == 'x')
		return (ft_itoabase((unsigned char)va_arg(arg, int), 16));
	if (str == 'X')
		return (mag(ft_itoabase((unsigned char)va_arg(arg, int), 16)));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_intmax(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (conv_intmax(arg));
	if (str == 'u' || str == 'U' )
		return (conv_uintmax(arg));
	if (str == 'o' || str == 'O')
		return (conv_octal_uintmax(arg));
	if (str == 'x')
		return (conv_exa_uintmax(arg));
	if (str == 'X')
		return (mag(conv_exa_uintmax(arg)));
	if (str == '%')
		return ("%");
	return (0);
}

char *type_param_size_t(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, size_t)));
	if (str == 'u' || str == 'U')	
		return (ft_itoa_uim(va_arg(arg, size_t)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, size_t), 8));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, size_t), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, size_t), 16)));
	if (str == '%')
		return ("%");
	return (0);
}
void flagC(wchar_t value)
{


	//wchar_t value = L'猫';
	//我是一只猫。
	unsigned int mask0 = 0;
	unsigned int mask1 = 49280;
	unsigned int mask2= 14712960;
	unsigned int mask3= 4034953344;

	unsigned int v = value;
	long size = ft_strlen((ft_itoabase((unsigned int) value, 2)));
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

	if (ft_atoi(&str[1]) < ft_strlen(val))
		return (val);
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	temp = ft_strnew(ft_atoi(&str[1]) + cpt);
	debut = ft_strnew(cpt);
//	if (ft_strchr("scdDioOuUxX%Z", type))
//	{
		while (cpt > 0)
		{
			debut[cpt - 1] = ' ';
			cpt--;
		}
		temp = ft_strcpy(temp, val);
		return (ft_strcat(temp, debut));
//	}
//	return (val);
}

char *flag_esp(char *str, char type, char *val)
{
	size_t cpt;
	char *debut;

	debut = ft_strnew(ft_atoi(str));
	if (ft_atoi(str) < ft_strlen(val))
		return (val);
	cpt = ft_atoi(str) - ft_strlen(val);
	if (type == 'c' && val[0] == '^' && val[1] == '@')
		cpt++;
	if (ft_strchr("pscdDioOuUxX%", type))
	{
		while (cpt > 0)
		{
			debut[cpt - 1] = ' ';
			cpt--;
		}
		if (val != NULL)
			return (ft_strcat(debut, val));
		else
			return (debut);
	}
	return (val);
}

char *flag_pos(char type, char *str)
{
	char *debut;

	debut = ft_strnew(ft_strlen(str) + 1);
	if (ft_strchr("idD", type))
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

	if (ft_atoi(str) == 0 && (type == 'x' || type == 'X'))
		return("0");
	if (type == 'o' || type == 'O')
	{
		if (ft_atoi(str) == 0)
			return ("0");
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
	return (str);
}

char *flag_pres(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char temp;

	debut = ft_strnew(ft_atoi(&str[1]));
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	if (val[0] == '-')
		cpt++;
	if (ft_strcmp(str, "0x") && type == 'p')
		cpt = cpt + 2;
	if (ft_strchr("pdDioOuUxX", type))
	{
		if (ft_atoi(&str[1]) < ft_strlen(val))
			return (val);
		if (ft_atoi(&str[1]) == 0)
			return (0);
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
	if (ft_strchr("s", type))
	{
		if (ft_atoi(&str[1]) < ft_strlen(val))
			return (ft_strndup(val, ft_atoi(&str[1])));
	}
	return (val);
}
char *flag_0(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
	char temp;

	if (ft_atoi(str) <= ft_strlen(val))
		return (val);
	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
	if (ft_strchr("dDioOuUxX%", type))
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
		if (val[0] == '+')
		{
			temp = val[0];
			val[0] = debut[0];
			debut[0] = temp;
		}
		if (val[0] == ' ')
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
	char *temp;

	temp = ft_strnew(1000);
	i = 0;
	j = 1;
	while (flag[i])
	{
		if (flag[i] == '#')
		{
			swapton(flag, i, 0);
			return ("#");
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
		{
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
			while (flag[i])
			{
				if (flag[i] == '0')
				{
					flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
				}
				i++;
			}
			return (temp);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '+')
		{
			swapton(flag, i, 0);
			return ("+");
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == ' ')
		{
			swapton(flag, i, 0);
			return (" ");
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9'))
		{
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
			while (flag[i])
			{
				if (flag[i] == '0')
				{
					flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
				}
				i++;
			}
			return (temp);
		}
		i++;
	}

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '-')
		{
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
			while (flag[i])
			{
				if (flag[i] == '0')
				{
					flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
				}
				i++;
			}
			return (temp);
		}
		i++;
	}
	i = 0;
	while (flag[i])
	{
		if (flag[i] >= '1' && flag[i] <= '9')
		{
			flag = swapton(flag, i, 0);
			//temp[j - 1] = '0';
			// i++;
			while (flag[i] >= '0' && flag[i] <= '9')
			{
				temp[j - 1] = flag[i];
				i++;
				flag = swapton(flag, i, j);
				j++;
				//i++;
			}
			while (flag[i])
			{
				if (flag[i] == '0')
				{
					flag = ft_strcat(ft_strndup(flag, i), &flag[i]);
				}
				i++;
			}
			return (temp);
		}
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

int lenflag(const char *str, char *type, int i)
{
	int j;

	j = i;
	while (ft_strchr("0123456789-+.# hljz",str[j]))
	{
		j++;
	}
//	j++;
	*type = str[j];
	j++;
	return ((int)ft_strlen(ft_strndup(&str[i], j - i)));
}

char *recupflag(const char *str, char *type, int i)
{
	int j;
	int k;
	char *temp;
	int multi;


	multi = 0;
	j = i;
	while (ft_strchr("0123456789-+.# hljz",str[j]))
	{
		j++;
	}
//	j++;
	*type = str[j];
	j++;
	temp = ft_strndup(&str[i], j - i);
	j = 0;
	while (temp[j])
	{
		k = 0;
		while (temp[k])
		{
			if (j == k)
				k++;
			if ((temp[j] == ' ') && (temp[k] == ' ' || temp[k] == '+'))
			{
				temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
				//j--;
				k--;
			}
			else if ((temp[j] == '+' ) && (temp[k] == ' ' || temp[k] == '+'))
			{
				temp = ft_strcat(ft_strndup(temp, k), &temp[k + 1]);
				//j--;
				k--;
			}
			multi = 1;
			k++;
		}
		j++;
	}
	k = 0;
	multi = 0;
	j = 0;
	while (temp[j])
	{
		if (temp[j] == '.')
		{
			if (multi == 1)
			{
				temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
				j--;
			}
			multi = 1;
		}
		j++;

	}
	multi = 0;
	j = 0;
	while (temp[j])
	{
		k = 0;
		while (temp[k])
		{
			if (j == k)
				k++;
			if ((temp[j] == '.') && (temp[k] == '0' && (temp[k - 1] < '1' || temp[k - 1] > '9')))
			{
				temp = ft_strcat(ft_strndup(temp, k), &temp[k + 1]);
				k--;
			}
			k++;
		}
		j++;
	}
	j = 0;
	while (temp[j])
	{
		if (temp[j] == '-' || (temp[j] == '0' && (temp[j - 1] < '0' || temp[j - 1] > '9') && multi == 1))
		{
			if (multi == 1)
				temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
			multi = 1;
		}
		j++;
	}
	return (temp);

}

int	do_flag(char *flag, char type, char *val)
{
	char *todo;
	int dies;

	dies = 0;
	if (flag == 0)
		return (0);
	while (*flag != 0)
	{
		todo = range_option(flag);

	//	printf("todo = |%s|\n", todo);
		if (todo[0] == '#')
		{
			val = flag_dies(type, val);
			dies = 1;
		}
		if (todo[0] == '0')
		{
			val = flag_0(flag, type, val);
		}
		if ((todo[0] >= '1' && todo[0] <= '9'))
			val = flag_esp(flag, type, val);
		if (todo[0] == '.')
		{
			if ((todo[1] >= '1' && todo[1] <= '9'))
				val = flag_pres(todo, type, val);
			if (val[0] == '0' && !val[1])
				val = NULL;
			if (type == 'p' && ft_strstr(val,"0x0") && !val[3])
				val = "0x";
			if (val == NULL && (type == 'o' || type =='O') && dies == 1)
				val = "0";
			if (ft_atoi(&todo[1]) == 0 && type == 's')
				val = 0;
		}
		if (todo[0] == '-')
		{
			val = flag_neg(flag, type, val);

		}
		if (todo[0] == '+')
			val = flag_pos(type, val);
		if (todo[0] == ' ')
		{
			val = flag_espifpos(type, val);
		}
	//	printf("<%s>\n", val);
		if (ft_strchr("cidDpsxoOuUX%", flag[0]))
		{
			if (val == NULL && ft_strchr("sScC", flag[0]))
			{
				ft_putstr("(null)");
				return (6);
			}
			else
			{
				ft_putstr(val);
				if ((flag[0] == 'c') && ft_strstr(val, "^@"))
					return  ((int)ft_strlen(val) - 1);
				return ((int)ft_strlen(val));
			}
		}
		if (ft_strchr("lhjz", flag[0]))
		{
			flag = ft_strdup(&flag[ft_strlen(todo) - 1]);
		}
		else
		{
	//		printf("val = <%s>\n", val);
			flag = ft_strdup(&flag[ft_strlen(todo)]);
		//	printf("<%s>\n", val);
		}
	//	printf("<%s>\n", val);
	}
	ft_putstr(val);
	return ((int)ft_strlen(val));
}

int		option(const char *str, va_list arg, ...)
{
	int		i;
	int		len;
	int     len2;
	char	*flag;
	char	type;
	char 	*val;

	flag = NULL;
	val = NULL;
	type = 'Z';
	len = 0;
	len2 = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (len + i - 1);
			else if ((ft_strchr("%csidDpxXoOuU0123456789-+.# hljz",str[i])))
			{
				len2 = lenflag(str, &type, i);
				flag = recupflag(str, &type, i);
				if (type == '%')
					val = "%";
				else if (ft_strchr(flag, 'j'))
					val = type_param_intmax(type, arg);
				else if (ft_strchr(flag, 'z'))
					val = type_param_size_t(type, arg);
				else if (ft_strstr(flag, "ll"))
					val = type_param_long_long(type, arg);
				else if (ft_strchr(flag, 'l'))
					val = type_param_long(type, arg);

				else if (ft_strstr(flag, "hh"))
					val = type_param_char(type, arg);
				else if (ft_strchr(flag, 'h'))
					val = type_param_short(type, arg);
				else
					val = type_param(type, arg);
				if (val == NULL && !ft_strchr("csidDpxXoOuU", type))
				{
					val = ft_strnew(1);
					val[0] = type;
				}
				i = i + len2;
				len = len - len2 - 1;
				len = len + do_flag(flag, type, val);
			}
			else if (str[i] == 'C' || str[i] == 'S')
			{
				if (str[i] == 'S')
					convparaminS(arg);
				else
					convparaminC(arg);
				i++;
			}
			else
				len--;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
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
