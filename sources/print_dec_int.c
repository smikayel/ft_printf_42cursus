#include "../ft_printf.h"

int print_dec_int(int nbr)
{
	int len;

	len = 0;
	ft_putnbr_fd(nbr, 1);
	while(nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}	
