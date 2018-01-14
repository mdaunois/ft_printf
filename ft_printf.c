/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:34 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/12 16:39:13 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char		*ft_itoabase(long n, int base)
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
		return(va_arg(arg, char *));
	if (str == 'd' || str == 'i')
		return (ft_itoa(va_arg(arg, int)));
	if (str == 'u')
		return ((ft_itoa_long(va_arg(arg, unsigned int))));
	if (str == 'U')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (str == 'o')
		return (ft_itoabase(va_arg(arg,unsigned int), 8));
	if (str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long),8));
	if (str == 'x')
		return (ft_itoabase(va_arg(arg, unsigned int), 16));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == 'X')
		return (mag(ft_itoabase(va_arg(arg, unsigned int), 16)));
	if (str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	return (0);
}

char *type_param_long(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, unsigned long), 16)));
	if (str == 'o')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long),8));
	if (str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, unsigned long),8));
	if (str == 'u')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (str == 'U')
		return (ft_itoa_uim(va_arg(arg, unsigned long)));
	if (str == 'p')
		return (conv_adresse(arg));
	if (str == 's')
		return (convparaminS(arg));
	if (str == 'c')
		return (convparaminC(arg));
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
	return (0);
}

char *type_param_short(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i')
		return ((ft_itoa(va_arg(arg, short))));
	if (str == 'D')
		return (ft_itoa_long(va_arg(arg, long long)));
	if (str == 'u')
		return (ft_itoa_long((unsigned short)va_arg(arg, int)));
	if (str == 'U')
		return (ft_itoa_long(va_arg(arg, long)));
	if (str == 'o')
		return (ft_itoabase((unsigned short)va_arg(arg, int), 8));
	if (str == 'O')
		return (ft_itoabase(va_arg(arg,unsigned int), 8));
	if (str == 'x')
		return (ft_itoabase(va_arg(arg, unsigned short), 16));
	if (str == 'X')
		return (mag(ft_itoabase(va_arg(arg, unsigned short), 16)));
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
	return (0);
}

char *type_param_intmax(char str, va_list arg, ...)
{
	if (str == 'd' || str == 'i' || str == 'D')
		return (ft_itoa_long(va_arg(arg, intmax_t)));
	if (str == 'u' || str == 'U' )
		return (ft_itoa_uim(va_arg(arg, uintmax_t)));
	if (str == 'o' || str == 'O')
		return (ft_itoabase_uintmax(va_arg(arg, uintmax_t), 8));
	if (str == 'x')
		return (ft_itoabase_uintmax(va_arg(arg, uintmax_t), 16));
	if (str == 'X')
		return (mag(ft_itoabase_uintmax(va_arg(arg, uintmax_t), 16)));
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
	return (0);
}

char *between12and16(unsigned int v)
{
    char *octet;
    
    octet = ft_strnew(3);
    octet[0] = (14712960 >> 16) | ((v >> 12) << 28) >> 28;
    octet[1] = ((14712960 << 16) >> 24) | ((v >> 6) << 26) >> 26;
    octet[2] = ((14712960 << 24) >> 24) | (v << 26) >> 26;
    return ((char *)octet);
}

char *for_more_16(unsigned int v)
{
    char *octet;
    
    octet = ft_strnew(4);
    octet[0] = (4034953344 >> 24) | ((v >> 18) << 29) >> 29;
    octet[1] = ((4034953344 << 8) >> 24) | ((v >> 12) << 26) >> 26;
    octet[2] = ((4034953344 << 16) >> 24) | ((v >> 6) << 26) >> 26;
    octet[3] = ((4034953344 << 24) >> 24) | (v << 26) >> 26;
    return ((char *)octet);
}
char *flagC(wchar_t value)
{
    unsigned int v;
    long size;
	char *octet;

    v = value;
    size = ft_strlen((ft_itoabase((unsigned int) value, 2)));

	if (size <= 7)
	{
		octet = ft_strnew(1);
		octet[0] = value;
		return ((char *)octet);
	}
	else  if (size <= 11)
	{
		octet = ft_strnew(2);
		octet[0] = (49280 >> 8) | ((v >> 6) << 27) >> 27;
		octet[1] = ((49280 << 24) >> 24) | (v << 26) >> 26;
        return ((char *)octet);
	}
	else  if (size <= 16)
        return (between12and16(v));
	else
        return (for_more_16(v));
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
	while (cpt > 0)
	{
		debut[cpt - 1] = ' ';
		cpt--;
	}
	temp = ft_strcpy(temp, val);
	return (ft_strcat(temp, debut));
}

char *flag_esp(char *str, char type, char *val)
{
	size_t cpt;
	char *debut;

	debut = ft_strnew(ft_atoi(str));
	if (ft_atoi(str) < ft_strlen(val))
		return (val);
	cpt = ft_atoi(str) - ft_strlen(val);
	while (cpt > 0)
	{
		debut[cpt - 1] = ' ';
		cpt--;
	}
	if (val != NULL)
		return (ft_strcat(debut, val));
	else
		return (debut);
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

char *presition_for_numeric_type(char *val, char *debut, size_t cpt,const char *str)
{
    char temp;
    
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
char *flag_pres(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;
    int i;
	
    i = 0;
	debut = ft_strnew(ft_atoi(&str[1]));
	cpt = ft_atoi(&str[1]) - ft_strlen(val);
	if (val[0] == '-')
		cpt++;
	if ((type == 'x' || type == 'X' || type == 'p') && (val[1] == 'x' || val [1] == 'X'))
		cpt = cpt + 2;
	if (ft_strchr("pdDioOuUxX", type))
		return (presition_for_numeric_type(val, debut, cpt, str));
	if (ft_strchr("sS", type))
	{
		if (ft_atoi(&str[1]) < ft_strlen(val))
		{
			while ((unsigned char)val[ft_atoi(&str[1]) - i] < 192)
				i++;
			if (i > 3)
				i = 0;
			return (ft_strndup(val, ft_atoi(&str[1]) - (i)));
		}
	}
	return (val);
}

char *swap_if(char *val, char *debut)
{
    char temp;
    
    if (val[1] == 'x' || val[1] == 'X')
    {
        temp = val[1];
        val[1] = debut[1];
        debut[1] = temp;
    }
    if (val[0] == '-' || val[0] == '+' || val[0] == ' ')
    {
        temp = val[0];
        val[0] = debut[0];
        debut[0] = temp;
    }
    return(val);
}

char *flag_0(const char *str, char type, char *val)
{
	size_t cpt;
	char *debut;

	if (ft_atoi(str) <= ft_strlen(val))
		return (val);
	debut = ft_strnew(ft_atoi(str));
	cpt = ft_atoi(str) - ft_strlen(val);
    while (cpt > 0)
    {
        debut[cpt - 1] = '0';
        cpt--;
    }
    if (type == 's' && val == NULL)
        return debut;
    val = swap_if(val, debut);
    return (ft_strcat(debut, val));
	return (val);
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

char *if_point(char *flag, int i, char *temp)
{
    int j;
    
    j = 1;
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

char *if_0(char *flag, int i, char *temp)
{
    int j;
    
    j = 1;
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

char *if_negatif(char *flag, int i, char *temp)
{
    int j;
    
    j = 1;
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

char *if_number(char *flag, int i, char *temp)
{
    int j;
    
    j = 1;
    flag = swapton(flag, i, 0);
    while (flag[i] >= '0' && flag[i] <= '9')
    {
        temp[j - 1] = flag[i];
        i++;
        flag = swapton(flag, i, j);
        j++;
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
// trop long
char *range_option(char *flag)
{
    int i;
	char *temp;

	temp = ft_strnew(1000);
	i = -1;
	while (flag[++i])
		if (flag[i] == '#')
		{
			swapton(flag, i, 0);
			return ("#");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == '.')
			return (if_point(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] == '+')
		{
			swapton(flag, i, 0);
			return ("+");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == ' ')
		{
			swapton(flag, i, 0);
			return (" ");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9'))
                return (if_0(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
			return (if_negatif(flag, i, temp));
	i = -1;
	while (flag[++i])
		if (flag[i] >= '1' && flag[i] <= '9')
			return (if_number(flag, i, temp));
	return (flag);
}

char	*convparaminC(va_list arg, ...)
{
	wchar_t val;

	val = va_arg(arg, wchar_t);
	return (flagC(val));

}

char	*convparaminS(va_list arg, ...)
{
	wchar_t *val;
	int i;
	char *temp;

	temp = ft_strnew(1000);
	i = 0;
	val = va_arg(arg, wchar_t*);
	if (val == NULL)
		return (NULL);
	while (val[i])
	{
		temp =  ft_strcat(temp, flagC(val[i]));
		i++;
	}
	return (temp);
}

int lenflag(const char *str, char *type, int i)
{
	int j;

	j = i;
	while (ft_strchr("0123456789-+.# hljz",str[j]))
	{
		j++;
	}
	*type = str[j];
	j++;
	return ((int)ft_strlen(ft_strndup(&str[i], j - i)));
}

char *cleandouble(char *temp, char *type)
{
    int j;
    int k;
    
    j = -1;
    while (temp[++j])
    {
        k = -1;
        while (temp[++k])
        {
            if (j == k)
                k++;
            if ((temp[j] == ' ') && (temp[k] == ' ' || temp[k] == '+'))
            {
                temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
                k--;
            }
            else if ((temp[j] == '+' ) && (temp[k] == ' ' || temp[k] == '+'))
                temp = ft_strcat(ft_strndup(temp, k), &temp[k-- + 1]);
            else if ((ft_strchr("idDoOuUxX", *type)) && (temp[j] == '.') && (temp[k] == '0' && (temp[k - 1] < '1' || temp[k - 1] > '9')))
                temp = ft_strcat(ft_strndup(temp, k), &temp[k-- + 1]);
        }
    }
    return (temp);
}
char *cleandouble_2(char *temp)
{
    int multi;
    int j;
    
    multi = 0;
    j = -1;
    while (temp[++j])
        if (temp[j] == '.')
        {
            if (multi == 1)
            {
                temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
                j--;
            }
            multi = 1;
        }
    multi = 0;
    j = -1;
    while (temp[++j])
        if (temp[j] == '-' || (temp[j] == '0' && (temp[j - 1] < '0' || temp[j - 1] > '9') && multi == 1))
        {
            if (multi == 1)
                temp = ft_strcat(ft_strndup(temp, j), &temp[j + 1]);
            multi = 1;
        }
    return (temp);
}

char *recupflag(const char *str, char *type, int i)
{
	int j;
	char *temp;
	int multi;

	temp = ft_strndup(&str[i], lenflag(str, type, i));
    temp = cleandouble(temp, type);
	multi = 0;
	temp = cleandouble_2(temp);
    return (temp);

}

int affiche_val(char *val, int valc, char *flag)
{
    if (valc == 0)
    {
        val[ft_strlen(val) - 1] = 0;
        ft_putstr(val);
        ft_putchar(0);
        return ((int)ft_strlen(val) + 1);
    }
    if ((ft_strchr("cC", flag[0]) && val[0] == 0))
    {
        ft_putchar(0);
        return (1);
    }
    else if (ft_strchr("sS", flag[0]) && val == NULL)
    {
        ft_putstr("(null)");
        return (6);
    }
    else
    {
        ft_putstr(val);
        return ((int)ft_strlen(val));
    }
}

char *flag_presition(char *todo, char type, char *val)
{
    if (todo[1]  && (todo[1] >= '1' && todo[1] <= '9'))
        return flag_pres(todo, type, val);
    if (type == 'p' && ft_strstr(val,"0x0") && !val[3])
        return "0x";
    if (val == "0" && (type == 'o' || type =='O'))
        return "0";
    if (ft_atoi(&todo[1]) == 0 && (type == 's'|| type == 'S'))
        return "";
    if (val && val[0] == '0' && !val[1])
        return NULL;
    return (val);
}

char *change_val(char *val, char *todo, char type, char *flag)
{
    if (todo[0] == '#')
        val = flag_dies(type, val);
    if (todo[0] == '0')
        val = flag_0(flag, type, val);
    if ((todo[0] >= '1' && todo[0] <= '9'))
        val = flag_esp(flag, type, val);
    if (todo[0] == '.')
        val = flag_presition(todo, type, val);
    if (todo[0] == '-')
        val = flag_neg(flag, type, val);
    if (todo[0] == '+')
        val = flag_pos(type, val);
    if (todo[0] == ' ')
        val = flag_espifpos(type, val);
    return (val);
}

int	do_flag(char *flag, char type, char *val)
{
	char *todo;
	int dies;
	int valc;

	valc = -1;
	dies = 0;
	if (flag == 0)
		return (0);
	if (type == 'c' && !ft_strcmp(val, ""))
		valc = 0;
	while (*flag != 0)
	{
		todo = range_option(flag);
        val = change_val(val, todo, type, flag);
		if (ft_strchr("SCcidDpsxoOuUX%", flag[0]))
            return (affiche_val(val, valc, flag));
		if (ft_strchr("sScCidDoOuUxX", type) && ft_strchr("lhjz", flag[0]))
			flag = ft_strdup(&flag[ft_strlen(todo) - 1]);
		else if (ft_strstr(flag, ".154d"))
			flag = &flag[ft_strlen(todo) + 1];
		else
			flag = &flag[ft_strlen(todo)];
	}
		ft_putstr(val);
	return ((int)ft_strlen(val));
}


char *recupval(char *val, char *flag, char type, va_list arg, ...)
{
    if (type == 'S')
        val = convparaminS(arg);
    else if (type == 'C')
        val = convparaminC(arg);
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
	if (val == NULL && !ft_strchr("CScsidDpxXoOuU", type))
    {
        val = ft_strnew(1);
        val[0] = type;
    }
    return (val);
}

// trop long
int		option(const char *str, va_list arg, ...)
{
	int		i;
	int		len;
	int     len2;
	char	*flag;
	char	type;

	len = 0;
	i = 0;
	while(str[i])
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (len + i - 1);
			else if ((ft_strchr("%SCcsidDpxXoOuU0123456789-+.# hljz",str[i])))
			{
				len2 = lenflag(str, &type, i);
				flag = recupflag(str, &type, i);
				i = i + len2;
				len = len - len2 - 1;
				len = len + do_flag(flag, type, recupval(NULL, flag, type, arg));
			}
			else
				len--;
		}
		else
			ft_putchar(str[i++]);
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
