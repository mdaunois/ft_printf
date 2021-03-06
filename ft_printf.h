/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:55:50 by mdaunois          #+#    #+#             */
/*   Updated: 2018/02/01 14:10:18 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include "libft/includes/libft.h"

char	*ft_itoa_long(intmax_t n);
char	*ft_itoa_uim(uintmax_t n);
char	*ft_itoabase_uintmax(uintmax_t n, int base);
char	*ft_itoabase(long n, int base);
char	*ft_itoabase_long(intmax_t n, int base);
char	*mag(char *str);
long	nblen(long nb);
char	*swap_if(char *val, char *debut);
char	*swapton(char *str, int i, int n);
char	*conv_char(va_list arg);
char	*conv_adresse(va_list arg, ...);
char	*convparaminbig_s(int i, va_list arg, ...);
char	*convparaminbig_c(va_list arg, ...);
char	*type_param(char str, va_list arg, ...);
char	*type_param_long(char str, va_list arg, ...);
char	*type_param_long_long(char str, va_list arg, ...);
char	*type_param_short(char str, va_list arg, ...);
char	*type_param_char(char str, va_list arg, ...);
char	*type_param_intmax(char str, va_list arg, ...);
char	*type_param_size_t(char str, va_list arg, ...);
char	*flagbig_c(wchar_t value);
char	*flag_neg(char *str, char type, char *val);
char	*flag_esp(char *str, char type, char *val);
char	*flag_pos(char type, char *str);
char	*flag_dies(char type, char *str);
char	*flag_pres(const char *str, char type, char *val);
char	*flag_0(const char *str, char type, char *val);
char	*flag_espifpos(char type, char *str);
int		lenflag(const char *str, char *type, int i);
char	*cleandouble(char *temp, char type);
char	*cleandouble_2(char *temp, int multi, int multi2);
char	*recupflag(const char *str, char type, int i);
char	*recupval(char *val, char *flag, char type, va_list arg, ...);
int		affiche_val(char *val, int valc, char type, int len);
char	*flag_presition(char *todo, char type, char *val, int *dies);
char	*change_val(char *val, char *todo, char type, int *dies);
int		do_flag(char *flag, char type, char *val, int valc);
char	*if_point(char *flag, int i, char *temp);
char	*if_0(char *flag, int i, char *temp);
char	*if_negatif(char *flag, int i, char *temp);
char	*if_number(char *flag, int i, char *temp);
char	*premierpartie(char *flag, char *temp, int i);
char	*range_option(char *flag);
char	*between12and16(unsigned int v);
char	*for_more_16(unsigned int v);
char	*flagbig_c(wchar_t value);
int		color_flag(const char *str, int *i, int len);
int		option(const char *str, int i, int len, va_list arg, ...);
int		ft_printf(const char *str, ...);
char	*remove_one_char(char *temp, int j, char *temp2, int i);

#endif
