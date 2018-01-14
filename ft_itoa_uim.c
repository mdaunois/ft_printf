#include "ft_printf.h"

static int	get_lengt(uintmax_t n)
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
    if (!(str = ft_strnew(get_lengt(n))))
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
