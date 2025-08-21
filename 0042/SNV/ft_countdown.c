
#include <unistd.h>

// int	main(void)
// {
// 	write(1, "9876543210\n", 11);
// }

int	main(void)
{
	char	c;

	c = '9';
	while (c >= '0')
	{
		write(1, &c, 1);
		c--;
	}
	write(1, "\n", 1);

}
