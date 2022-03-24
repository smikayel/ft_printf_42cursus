#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

void	hex_print(unsigned int number, int fd, char upper_lower);
void	ft_print_unsigned_int(unsigned  int number);
void	ft_putnbr_base(unsigned long long int nbr, char *base);
#endif
