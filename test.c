
#include "ft_printf.h"

int     main()
{
	int a;
	long c;
	short b;

	a = -1;
	c = -2147483649;
	b = 12345;
	printf("eux|%  ++d|\n", 42);
	ft_printf("moi|%  ++d|\n", 42);
	//printf("%d\n",printf("eux = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	//ft_printf("%d\n",ft_printf("moi = je  suis %s j'ai |%X| ans\n", "Mathieu", a));
	return 0;
}
