/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:20:07 by mdaunois          #+#    #+#             */
/*   Updated: 2018/01/15 17:10:17 by mdaunois         ###   ########.fr       */
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
	printf("%d\n", printf("eux|%#.O|", 0));
	printf("%d\n", ft_printf("moi|%#.O|", 0));
	printf("%d\n", printf("eux{%.4s}\n", "bonjour") - 6);
	printf("%d\n", ft_printf("moi{%.4s}\n", "bonjour") - 6);
	printf("%d\n", printf("eux%.4S\n", L"ಖ") - 4);
	printf("%d\n", ft_printf("moi%.4S\n", L"ಖ") - 4);
	ft_putchar(0);
	printf("%d\n", printf("eux%-15Z"));
	ft_printf("%d\n", ft_printf("moi%-15Z"));
	while (a == -1)
	{}
	return (0);
}
