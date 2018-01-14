#include "ft_printf.h"

static int	get_length(uintmax_t n, int base)
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
    if (!(str = ft_strnew(get_length(n, base))))
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