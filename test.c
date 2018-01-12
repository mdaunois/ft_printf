
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int     main()
{
	int a;
	long c;
	short b;
	size_t t = 42000000000;

	setlocale(LC_ALL, "");
	a = -1;
	c = -2147483649;
	b = 12345;
//	printf("%d\n", printf("eux|%010x|", 542));
//	ft_printf("%d\n", ft_printf("moi|%010x|", 542));
	printf("%d\n", printf("eux{%05.s}\n", 0));
	printf("%d\n", ft_printf("moi{%05s}\n", 0));
//	printf("%d\n", printf("eux%.S\n", L"我是一只猫。" ) - 4);
//	printf("%d\n", ft_printf("moi%.S\n", L"我是一只猫。" ) - 4);
//	ft_putchar(0);
	//printf("%d\n", printf("eux%-15Z"));
	//ft_printf("%d\n", ft_printf("moi%-15Z"));
//	printf("%d\n",printf("eux = je  suis %05.s j'ai |%X| ans\n", "Mathieu", a));
//	printf("%d\n",ft_printf("moi = je  suis %05.s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
