
#include "ft_printf.h"
#include <limits.h>

int     main()
{
	int a;
	long c;
	short b;
	size_t t = 42000000000;

//	setlocale(LC_ALL, "en_US.UTF-8");
	a = -1;
	c = -2147483649;
	b = 12345;
//	printf("%d\n", printf("eux%#o, %0d\n", 42, -42));
//	ft_printf("%d\n", ft_printf("moi%#o, %0d\n", 42, -42));
	printf("%d\n", printf("eux%#.d\n", 0));
	ft_printf("%d\n", ft_printf("moi%#.d\n", 0));
//	ft_putchar(0);
	//printf("%d\n", printf("eux%-15Z"));
	//ft_printf("%d\n", ft_printf("moi%-15Z"));
	//printf("%d\n",printf("eux = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	//ft_printf("%d\n",ft_printf("moi = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
