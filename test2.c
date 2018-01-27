/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/25 16:18:17 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int		a;
	long	c;
	short	b;
	size_t	t;

//	setlocale(LC_ALL, "");
	t = 420000000;
	a = -1;
	c = -2147483649;
	b = 12345;
    wchar_t    s[4];
    
    s[0] = 0x53;
    s[1] = 0x3abc;
    s[2] = 0x81000;
    s[3] = '\0';
    //  	while(1)
	//   {
    //ft_printf("%-33..12..+d\n", 256);
    //printf("%-33..12..+d\n", 256);
    ft_printf("%###-#0000 33...12..#0+0d\n", 256);
    printf("%###-#0000 33...12..#0+0d\n", 256);
    //printf(" %d\n", ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));
    //printf(" %d\n", printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));
	//printf(" %d\n", printf("%4.1S", L"Jambon"));
	//printf(" %d\n", ft_printf("%4.1S", L"Jambon"));
	/*printf("%8.4d\n", 424242424);
	ft_printf("%8.4d\n", 424242424);
	printf("%hhd\n", CHAR_MIN - 42);
	ft_printf("%hhd\n", CHAR_MIN - 42);
	ft_printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	printf("coco et %-#-#24O titi%#012o\n", 12, -874);
	ft_printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
	printf("%#X\n", 0xff7744);
	ft_printf("%#X\n", 0xff7744);
	ft_printf("%C\n", 0x11ffff);
	printf("%C\n", 0x11ffff);
	printf(" %d\n", ft_printf("%d", 0));
	printf(" %d\n", printf("%d", 0));
	printf("%.2s\n", NULL);
	ft_printf("%.2s\n", NULL);
	printf(" %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
	printf(" %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
	printf(" %d\n", ft_printf("test %-7C %007d|%-10.2S!!", 0xd777, 0x45, L"〻"));
	printf(" %d\n", printf("test %-7C %007d|%-10.2S!!", 0xd777, 0x45, L"〻"));
	ft_printf("%C\n", 0x11ffff);
	printf("%C\n", 0x11ffff);
	printf(" %d\n", ft_printf("%C", 256));
	printf(" %d\n", printf("%C", 256));
	printf("%.5ls\n", s);
	ft_printf("%.5S\n", s);
	ft_printf("{%0-3d}\n", 0);
	printf("{%0-3d}\n", 0);
	ft_printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
	ft_printf("%+  d\n", 42);
	ft_printf("% ++d\n", 42);*/
	//}
	//	while(1);
	return (0);
}
