/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/22 18:00:02 by mdaunois         ###   ########.fr       */
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
	ft_printf("\n");
	printf("%d\n", ft_printf("%S", NULL));
	printf("%d\n", printf("%S", NULL));
	printf("%d\n", ft_printf("%S", L"我是一只猫。n"));
	printf("%d\n", printf("%S", L"我是一只猫。n"));
	printf("{%010d}\n", 42);
	ft_printf("{%010d}{red}\n", 42);
	printf("{%010d}\n", -42);
	ft_printf("{%010d}{white}\n", -42);
	printf("{%04d}\n", 10000);
	ft_printf("{%04d}{red}\n", 10000);
	printf("{%030d}\n", 10000);
	ft_printf("{%030d}{white}\n", 10000);
	printf("{%030x}\n", 0xFFFF);
	ft_printf("{%030x}{red}\n", 0xFFFF);
	printf("{%030X}\n", 0xFFFF);
	ft_printf("{%030X}{white}\n", 0xFFFF);
	printf("{%03c}\n", 0);
	ft_printf("{%03c}{red}\n", 0);
	printf("{%05s}\n", "abc");
	ft_printf("{%05s}{white}\n", "abc");
	printf("{%030S}\n", L"我是一只猫。");
	ft_printf("{%030S}{red}\n", L"我是一只猫。");
	printf("{%05p}\n", 0);
	ft_printf("{%05p}{white}\n", 0);
	printf("%-5.2s is a string\n", "this");
	ft_printf("%-5.2s is a string{magenta}\n", "this");
	printf("|% ++4.5i|\n", 42);
	ft_printf("|% ++4.5i|\n", 42);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	printf("  %d\n", printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
	printf("%d\n", printf("eux|%#.O|", 0));
	printf("%d\n", ft_printf("{red}moi|%#.O|", 0));
	printf("%d\n", printf("eux{%.4s}\n", "bonjour") - 6);
	printf("%d\n", ft_printf("{white}moi{%.4s}\n", "bonjour") - 6);
	printf("%d\n", printf("eux%.4S\n", L"ಖ") - 4);
	printf("%d\n", ft_printf("moi%.4S\n", L"ಖ") - 4);
	printf("%d\n", printf("eux%-15Z"));
	ft_printf("%d\n", ft_printf("moi%-15Z"));
	ft_printf("%9.2p\n", 1234);
	printf("%9.2p\n", 1234);
	printf("  %d\n", ft_printf("%15.4S", L"我是一只猫。"));
	printf("  %d\n", printf("%15.4S", L"我是一只猫。"));
	printf("  %d\n", ft_printf("%4.15d", 42));
	printf("  %d\n", printf("%4.15d", 42));
	printf("{%-30d}\n", 10000);
	ft_printf("%4.1S\n", L"Jambon");
	printf("%4.1S\n", L"Jambon");

	//	while(1);
	return (0);
}
