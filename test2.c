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
    while(1)
    {
    printf("%4.1S\n", L"Jambon");
    ft_printf("%4.1S\n", L"Jambon");
    printf("%8.4d\n", 424242424);
    ft_printf("%8.4d\n", 424242424);
    printf("%hhd\n", CHAR_MIN - 42);
    ft_printf("%hhd\n", CHAR_MIN - 42);
    }
//	while(1);
	return (0);
}
