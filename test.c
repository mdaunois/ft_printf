
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
	printf("eux%.3%\n");
	ft_printf("moi%.3%\n");
	//printf("%d\n", printf("@moulitest: %#.o %#.0o\n", 0 ,0));
	//ft_printf("%d\n", ft_printf("@moulitest: %#.o %#.0o\n",0, 0));
	//printf("%d\n", printf("eux% Zooooo"));
	//ft_printf("%d\n", ft_printf("moi% Zooooo"));
	//printf("%d\n",printf("eux = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	//ft_printf("%d\n",ft_printf("moi = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
