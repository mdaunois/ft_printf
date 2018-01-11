
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int     main()
{
	int a;
	long c;
	short b;
	size_t t = 42000000000;

//	setlocale(LC_ALL, "");
	a = -1;
	c = -2147483649;
	b = 12345;
	printf("%d\n", printf("eux|%3c|", 0));
	ft_printf("%d\n", ft_printf("moi|%3c|", 0));
//	printf("%d\n", printf("eux%4.15d\n", -42));
//	ft_printf("%d\n", ft_printf("moi%4.15d\n", -42));
//	printf("%C\n", L'我');
//	ft_printf("%C\n", L'我');
//	ft_putchar(0);
	//printf("%d\n", printf("eux%-15Z"));
	//ft_printf("%d\n", ft_printf("moi%-15Z"));
	//printf("%d\n",printf("eux = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	//ft_printf("%d\n",ft_printf("moi = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
