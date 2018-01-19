/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/17 16:23:45 by mdaunois         ###   ########.fr       */
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

	setlocale(LC_ALL, "");
	t = 420000000;
	a = -1;
	c = -2147483649;
	b = 12345;
    //ft_printf("\n");
    //ft_printf("%S", L"我是一只猫。n");
    ft_printf("%S\n", L"我是一只猫。");
   /* ft_printf("%d\n", 42);
    ft_printf("%d%d\n", 42, 41);
    ft_printf("%d%d%d\n", 42, 43, 44);
    ft_printf("%ld\n", 2147483647);
    ft_printf("%lld\n", 9223372036854775807);
    ft_printf("%x\n", 505);
    ft_printf("%X\n", 505);
    ft_printf("%p\n", &ft_printf);
    ft_printf("%20.15d\n", 54321);
    ft_printf("%-10d\n", 3);
    ft_printf("% d\n", 3);*/
    //ft_printf("%+d\n", 3);
    //ft_printf("%010d\n", 1);
    //ft_printf("%hhd\n", 0);
    //ft_printf("%jd\n", 9223372036854775807);
    //ft_printf("%zd\n", 4294967295);
    //ft_printf("%\n");
    //ft_printf("%U\n", 4294967295);
    //ft_printf("%u\n", 4294967295);
   // ft_printf("%o\n", 40);
    //ft_printf("%%#08x\n", 42);
    //ft_printf("%x\n", 1000);
    //ft_printf("%#X\n", 1000);
    //ft_printf("%s\n", NULL);
    /*ft_printf("%S\n", L"ݗݜशব");
    ft_printf("%s%s\n", "test", "test");
    ft_printf("%s%s%s\n", "test", "test", "test");
    ft_printf("%C\n", 15000);*/
   // while (1);
//    printf("  %d\n", printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//	printf("%d\n", printf("eux|%#.O|", 0));
//	printf("%d\n", ft_printf("{red}moi|%#.O|", 0));
//	printf("%d\n", printf("eux{%.4s}\n", "bonjour") - 6);
//	printf("%d\n", ft_printf("{white}moi{%.4s}\n", "bonjour") - 6);
//	printf("%d\n", printf("eux%.4S\n", L"ಖ") - 4);
//	printf("%d\n", ft_printf("moi%.4S\n", L"ಖ") - 4);
//	printf("%d\n", printf("eux%-15Z"));
//	ft_printf("%d\n", ft_printf("moi%-15Z"));
//	while(1);
	return (0);
}
