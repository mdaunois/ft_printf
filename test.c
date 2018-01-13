
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
//	printf("%d\n", printf("eux{%.4s}\n", "bonjour") - 6);
//	printf("%d\n", ft_printf("moi{%.4s}\n", "bonjour") - 6);
	printf("%d\n", printf("eux%.4S\n", L"ಖ" ) - 4);
	printf("%d\n", ft_printf("moi%.4S\n", L"ಖ" ) - 4);
//	ft_putchar(0);
	//printf("%d\n", printf("eux%-15Z"));
	//ft_printf("%d\n", ft_printf("moi%-15Z"));
//	printf("%d\n",printf("eux = je  suis %05.s j'ai |%X| ans\n", "Mathieu", a));
//	printf("%d\n",ft_printf("moi = je  suis %05.s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
