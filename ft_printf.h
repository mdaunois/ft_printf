#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <stdint.h>
# include "libft/includes/libft.h"

int	get_length(long n, int base);
char		*ft_itoabase(long n, int base);
char	*mag(char *str);
long		nblen(long nb);
char *conv_octal(va_list arg, ...);
char *conv_long_octal(va_list arg, ...);
char *conv_char(va_list arg);
char *conv_str(va_list arg);
char *conv_nbr(va_list arg, ...);
char *conv_long(va_list arg, ...);
char *conv_u_int(va_list arg, ...);
char *conv_u_long(va_list arg, ...);
char *conv_exa(va_list arg, ...);
char *conv_adresse(va_list arg, ...);
char *type_param(char str, va_list arg, ...);
void flagC(wchar_t value);
char *flag_neg(char *str, char type, char *val);
char *flag_esp(char *str, char type, char *val);
char *flag_pos(char type, char *str);
char *flag_dies(char type, char *str);
char *flag_pres(const char *str, char type, char *val);
char *flag_0(const char *str, char type, char *val);
char	*flag_espifpos(char type, char *str);
char	*swapton(char *str, int i, int n);
char *range_option(char *flag);
void	convparaminC(va_list arg, ...);
void	convparaminS(va_list arg, ...);
char *recupflag(const char *str, char *type, int i);
int	do_flag(char *flag, char type, char *val);
int		option(const char *str, va_list arg, ...);
int		ft_printf(const char *str, ...);

#endif
